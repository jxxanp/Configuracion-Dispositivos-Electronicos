/*
 * ============================================================
 *  KILL THE BIT  -  Arduino UNO
 *  Mismo montaje físico de Simon Dice (solo cambia el código)
 * ============================================================
 *
 *  CÓMO SE JUEGA
 *  - Un LED encendido recorre la secuencia AZUL -> ROJO -> VERDE
 *    -> AMARILLO -> AZUL... Cada pulsador es del color de su LED.
 *  - ACIERTO: pulsas el color que está encendido -> ese LED se
 *    APAGA para siempre y la secuencia sigue con los LEDs que quedan.
 *  - FALLO: pulsas otro color -> se vuelve a ENCENDER un solo LED
 *    de los que ya habías apagado (el último que apagaste).
 *    Si todavía no has apagado ninguno, el fallo solo suena.
 *  - TOLERANCIA: si el LED acaba de pasar (menos de GRACIA_MS),
 *    la pulsación también cuenta, para compensar la reacción humana.
 *  - GANAS cuando se apagan los 4 LEDs. Luego pulsa un botón
 *    para jugar de nuevo.
 *
 *  CONEXIONES (leídas del montaje de Simon Dice)
 *  LEDs (activos en HIGH, resistencia de 470 ohm a GND):
 *     AZUL = D2 | ROJO = D3 | VERDE = D4 | AMARILLO = D5
 *  Pulsadores (un lado a 5V, el otro al pin + resistencia
 *  pull-down de 470 ohm a GND, por eso al pulsar leen HIGH):
 *     AZUL = D6 | ROJO = D7 | VERDE = D8 | AMARILLO = D9
 *  Buzzer: positivo a D10, negativo a GND.
 */

// ---------------- PINES ----------------
const byte NUM_LEDS = 4;

// Orden físico de izquierda a derecha: AZUL, ROJO, VERDE, AMARILLO
const byte PIN_LED[NUM_LEDS]    = {2, 3, 4, 5};
const byte PIN_BOTON[NUM_LEDS]  = {6, 7, 8, 9};
const byte PIN_BUZZER = 10;

// ---------------- AJUSTES DEL JUEGO ----------------
const unsigned int PASO_MS   = 450;  // tiempo que dura el LED encendido (menor = más difícil)
const unsigned int GRACIA_MS = 200;  // tolerancia para pulsar justo después de que el LED se movió
const unsigned int REBOTE_MS = 20;   // filtro anti-rebote de los pulsadores

// ---------------- VARIABLES DE ESTADO ----------------
byte vivos;                          // bit i = 1 -> el LED i sigue en juego (no se ha apagado)
byte apagados[NUM_LEDS];             // orden en que se fueron apagando (para reencender el último)
byte numApagados;                    // cuántos LEDs llevas apagados
byte cursor;                         // LED que está encendido ahora
int  cursorAnterior;                 // LED que estuvo encendido en el paso anterior (-1 = ninguno)
unsigned long ultimoPaso = 0;        // momento del último avance de la secuencia

bool estadoBoton[NUM_LEDS];          // estado estable de cada pulsador
bool lecturaPrevia[NUM_LEDS];        // última lectura cruda
unsigned long tCambio[NUM_LEDS];     // momento del último cambio de lectura

// ---------------- PROTOTIPOS ----------------
void golpear(byte i);
void avanzarCursor();
void matarLed(byte i);
void reavivarLed();
void mostrarCursor();
void nuevaPartida();
void victoria();
void esperarPulsacion();
bool botonPresionado(byte i);

// ============================================================
//  SETUP
// ============================================================
void setup() {
  for (byte i = 0; i < NUM_LEDS; i++) {
    pinMode(PIN_LED[i], OUTPUT);
    pinMode(PIN_BOTON[i], INPUT);    // INPUT (no PULLUP): el montaje ya trae pull-down externa
  }
  pinMode(PIN_BUZZER, OUTPUT);

  randomSeed(analogRead(A0));        // A0 sin conectar: ruido para la semilla aleatoria
  nuevaPartida();
}

// ============================================================
//  LOOP PRINCIPAL
// ============================================================
void loop() {
  // 1) Revisar pulsadores
  for (byte i = 0; i < NUM_LEDS; i++) {
    if (botonPresionado(i)) {
      golpear(i);
    }
  }

  // 2) Avanzar la secuencia cuando se cumple el tiempo
  if (vivos != 0 && millis() - ultimoPaso >= PASO_MS) {
    ultimoPaso = millis();
    avanzarCursor();
    mostrarCursor();
  }

  // 3) ¿Ganó? (se apagaron los 4 LEDs)
  if (vivos == 0) {
    delay(600);                      // se ve claro que el último LED se apagó
    victoria();
    esperarPulsacion();              // todos apagados hasta que pulses un botón
    nuevaPartida();
  }
}

// ============================================================
//  LÓGICA DEL JUEGO
// ============================================================

// Se pulsó el botón del LED i
void golpear(byte i) {
  bool acierto = false;

  if (i == cursor) {
    // ACIERTO: el color pulsado es el que está encendido
    matarLed(i);
    acierto = true;
    if (vivos != 0) {
      avanzarCursor();               // la secuencia sigue con los LEDs que quedan
      ultimoPaso = millis();
    }
    cursorAnterior = -1;
  } else if (i == cursorAnterior && (vivos & (1 << i)) &&
             (millis() - ultimoPaso) <= GRACIA_MS) {
    // ACIERTO TARDÍO: el LED acaba de pasar de ese color
    matarLed(i);
    acierto = true;
    cursorAnterior = -1;
  } else {
    // FALLO: vuelve a encenderse uno de los que ya se habían apagado
    if (numApagados > 0) {
      reavivarLed();
    }
  }

  mostrarCursor();

  if (acierto) {
    tone(PIN_BUZZER, 1500, 60);      // acierto
  } else {
    tone(PIN_BUZZER, 200, 150);      // fallo
  }
}

// Saca el LED i del juego (queda apagado)
void matarLed(byte i) {
  vivos &= ~(1 << i);
  apagados[numApagados] = i;
  numApagados++;
}

// Devuelve al juego el último LED que se había apagado
void reavivarLed() {
  numApagados--;
  byte i = apagados[numApagados];
  vivos |= (1 << i);
  digitalWrite(PIN_LED[i], HIGH);    // destello para que se note cuál vuelve
  delay(150);
}

// Pasa al siguiente LED que siga en juego (salta los apagados)
void avanzarCursor() {
  cursorAnterior = cursor;
  for (byte k = 1; k <= NUM_LEDS; k++) {
    byte candidato = (cursor + k) % NUM_LEDS;
    if (vivos & (1 << candidato)) {
      cursor = candidato;
      return;
    }
  }
}

// Enciende solo el LED del cursor; los apagados nunca se encienden
void mostrarCursor() {
  for (byte i = 0; i < NUM_LEDS; i++) {
    digitalWrite(PIN_LED[i], LOW);
  }
  if (vivos != 0) {
    digitalWrite(PIN_LED[cursor], HIGH);
  }
}

// Inicia una partida: barrido de LEDs y los 4 LEDs en juego
void nuevaPartida() {
  for (byte i = 0; i < NUM_LEDS; i++) {
    digitalWrite(PIN_LED[i], LOW);
  }
  delay(300);

  for (byte i = 0; i < NUM_LEDS; i++) {          // barrido de inicio
    digitalWrite(PIN_LED[i], HIGH);
    tone(PIN_BUZZER, 400 + i * 200, 80);
    delay(120);
    digitalWrite(PIN_LED[i], LOW);
  }
  delay(300);

  vivos = 0x0F;                                  // los 4 LEDs en juego
  numApagados = 0;
  cursor = random(NUM_LEDS);                     // empieza en un color al azar
  cursorAnterior = -1;
  mostrarCursor();

  // Sincronizar pulsadores para no registrar pulsaciones viejas
  for (byte i = 0; i < NUM_LEDS; i++) {
    estadoBoton[i]   = digitalRead(PIN_BOTON[i]) == HIGH;
    lecturaPrevia[i] = estadoBoton[i];
    tCambio[i]       = millis();
  }
  ultimoPaso = millis();
}

// Animación y sonido de victoria
void victoria() {
  const int melodia[] = {523, 659, 784, 1047};   // Do, Mi, Sol, Do agudo

  for (byte i = 0; i < NUM_LEDS; i++) {
    tone(PIN_BUZZER, melodia[i], 150);
    for (byte j = 0; j < NUM_LEDS; j++) digitalWrite(PIN_LED[j], HIGH);
    delay(150);
    for (byte j = 0; j < NUM_LEDS; j++) digitalWrite(PIN_LED[j], LOW);
    delay(100);
  }
  delay(500);
}

// Con todos los LEDs apagados, espera a que se pulse cualquier botón
void esperarPulsacion() {
  bool alguno = false;
  while (!alguno) {                              // esperar pulsación
    for (byte i = 0; i < NUM_LEDS; i++) {
      if (digitalRead(PIN_BOTON[i]) == HIGH) alguno = true;
    }
  }
  delay(50);
  while (alguno) {                               // esperar a que suelte
    alguno = false;
    for (byte i = 0; i < NUM_LEDS; i++) {
      if (digitalRead(PIN_BOTON[i]) == HIGH) alguno = true;
    }
  }
  delay(50);
}

// ============================================================
//  ENTRADA: pulsador con anti-rebote
//  Devuelve true SOLO en el instante en que se presiona
//  (mantenerlo apretado no cuenta como pulsaciones repetidas).
// ============================================================
bool botonPresionado(byte i) {
  bool lectura = (digitalRead(PIN_BOTON[i]) == HIGH);   // HIGH = pulsado

  if (lectura != lecturaPrevia[i]) {
    lecturaPrevia[i] = lectura;
    tCambio[i] = millis();
  }

  if ((millis() - tCambio[i]) >= REBOTE_MS && lectura != estadoBoton[i]) {
    estadoBoton[i] = lectura;
    return lectura;                      // true solo si pasó a pulsado
  }
  return false;
}
