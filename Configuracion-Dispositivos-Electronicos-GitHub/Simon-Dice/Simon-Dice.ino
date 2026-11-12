// C++ code
//
int ALEATORIO1 = 0;

int ALEATORIO2 = 0;

int ALEATORIO3 = 0;

int ALEATORIO4 = 0;

int BOTON2 = 0;

int BOTON3 = 0;

int BOTON4 = 0;

int BOTON1 = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
}

void loop()
{
  // SI LOS UMEROS ALEATORIOS SON 0
  if ((ALEATORIO1 == 0 && ALEATORIO2 == 0) && (ALEATORIO3 == 0 && ALEATORIO4 == 0)) {
    ALEATORIO1 = random(2, 5 + 1);
    ALEATORIO2 = random(2, 5 + 1);
    ALEATORIO3 = random(2, 5 + 1);
    ALEATORIO4 = random(2, 5 + 1);
    delay(100); // Wait for 100 millisecond(s)
    // ENCENDEMOS EL LED QUE CORRESPONDAN DEPENDIENDO
    // DEL ALEATORIO
    if (ALEATORIO1 == 2) {
      digitalWrite(2, HIGH);
    }
    if (ALEATORIO1 == 3) {
      digitalWrite(3, HIGH);
    }
    if (ALEATORIO1 == 4) {
      digitalWrite(4, HIGH);
    }
    if (ALEATORIO1 == 5) {
      digitalWrite(5, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    // APAGAMOS TODOS LOS LEDS
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println(ALEATORIO1);
    if (ALEATORIO2 == 2) {
      digitalWrite(2, HIGH);
    }
    if (ALEATORIO2 == 3) {
      digitalWrite(3, HIGH);
    }
    if (ALEATORIO2 == 4) {
      digitalWrite(4, HIGH);
    }
    if (ALEATORIO2 == 5) {
      digitalWrite(5, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println(ALEATORIO2);
    if (ALEATORIO3 == 2) {
      digitalWrite(2, HIGH);
    }
    if (ALEATORIO3 == 3) {
      digitalWrite(3, HIGH);
    }
    if (ALEATORIO3 == 4) {
      digitalWrite(4, HIGH);
    }
    if (ALEATORIO3 == 5) {
      digitalWrite(5, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println(ALEATORIO3);
    if (ALEATORIO4 == 2) {
      digitalWrite(2, HIGH);
    }
    if (ALEATORIO4 == 3) {
      digitalWrite(3, HIGH);
    }
    if (ALEATORIO4 == 4) {
      digitalWrite(4, HIGH);
    }
    if (ALEATORIO4 == 5) {
      digitalWrite(5, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    Serial.println(ALEATORIO4);
  }
  // CLICK LOS BOTONES Y SE GUARDA EN ALATORIO 1
  if (digitalRead(9) == HIGH && BOTON1 == 0) {
    tone(10, 92, 500); // play tone 30 (F#2 = 92 Hz)
    BOTON1 = 5;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(8) == HIGH && BOTON1 == 0) {
    tone(10, 165, 500); // play tone 40 (E3 = 165 Hz)
    BOTON1 = 4;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(7) == HIGH && BOTON1 == 0) {
    tone(10, 294, 500); // play tone 50 (D4 = 294 Hz)
    BOTON1 = 3;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(6) == HIGH && BOTON1 == 0) {
    tone(10, 523, 500); // play tone 60 (C5 = 523 Hz)
    BOTON1 = 2;
    delay(500); // Wait for 500 millisecond(s)
  }
  // CLICK LOS BOTONES Y SE GUARDA EN ALATORIO 2
  if (digitalRead(9) == HIGH && BOTON2 == 0) {
    tone(10, 92, 500); // play tone 30 (F#2 = 92 Hz)
    BOTON2 = 5;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(8) == HIGH && ALEATORIO2 == 0) {
    tone(10, 165, 500); // play tone 40 (E3 = 165 Hz)
    BOTON2 = 4;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(7) == HIGH && BOTON2 == 0) {
    tone(10, 294, 500); // play tone 50 (D4 = 294 Hz)
    BOTON2 = 3;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(6) == HIGH && BOTON2 == 0) {
    tone(10, 523, 500); // play tone 60 (C5 = 523 Hz)
    BOTON2 = 2;
    delay(500); // Wait for 500 millisecond(s)
  }
  // CLICK LOS BOTONES Y SE GUARDA EN ALATORIO 3
  if (digitalRead(9) == HIGH && BOTON3 == 0) {
    tone(10, 92, 500); // play tone 30 (F#2 = 92 Hz)
    BOTON3 = 5;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(8) == HIGH && BOTON3 == 0) {
    tone(10, 165, 500); // play tone 40 (E3 = 165 Hz)
    BOTON3 = 4;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(7) == HIGH && BOTON3 == 0) {
    tone(10, 294, 500); // play tone 50 (D4 = 294 Hz)
    BOTON3 = 3;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(6) == HIGH && BOTON3 == 0) {
    tone(10, 523, 500); // play tone 60 (C5 = 523 Hz)
    BOTON3 = 2;
    delay(500); // Wait for 500 millisecond(s)
  }
  // CLICK LOS BOTONES Y SE GUARDA EN ALATORIO 4
  if (digitalRead(9) == HIGH && BOTON4 == 0) {
    tone(10, 92, 500); // play tone 30 (F#2 = 92 Hz)
    BOTON4 = 5;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(8) == HIGH && BOTON4 == 0) {
    tone(10, 165, 500); // play tone 40 (E3 = 165 Hz)
    BOTON4 = 4;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(7) == HIGH && BOTON4 == 0) {
    tone(10, 294, 500); // play tone 50 (D4 = 294 Hz)
    BOTON4 = 3;
    delay(500); // Wait for 500 millisecond(s)
  }
  if (digitalRead(6) == HIGH && BOTON4 == 0) {
    tone(10, 523, 500); // play tone 60 (C5 = 523 Hz)
    BOTON4 = 2;
    delay(500); // Wait for 500 millisecond(s)
  }
  // IMPRIMIMOS LOS BOTONES PRECIONADOS
  if (BOTON1 != 0) {
    Serial.print("BOTON1: ");
    Serial.println(BOTON1);
  }
  if (BOTON2 != 0) {
    Serial.print("BOTON2: ");
    Serial.println(BOTON2);
  }
  if (BOTON3 != 0) {
    Serial.print("BOTON3: ");
    Serial.println(BOTON3);
  }
  if (BOTON4 != 0) {
    Serial.print("BOTON4: ");
    Serial.println(BOTON4);
  }
  // SOLO ENTRA SI TODOS LOS BOTONES SE HAN
  // PRECIONADO
  if ((BOTON1 != 0 && BOTON2 != 0) && (BOTON3 != 0 && BOTON4 != 0)) {
    // SI EL ORDEN DE LOS BOTONES COINCIDE CON LOS
    // ALATORIOS GANO
    if ((ALEATORIO1 == BOTON1 && ALEATORIO2 == BOTON2) && (ALEATORIO3 == BOTON3 && ALEATORIO4 == BOTON4)) {
      Serial.println("GANO");
      tone(10, 5274, 1000); // play tone 100 (E8 = 5274 Hz)
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      ALEATORIO1 = 0;
      ALEATORIO2 = 0;
      ALEATORIO3 = 0;
      ALEATORIO4 = 0;
      BOTON1 = 0;
      BOTON2 = 0;
      BOTON3 = 0;
      BOTON4 = 0;
      delay(1000); // Wait for 1000 millisecond(s)
    } else {
      Serial.println("PERDIO");
      tone(10, 39, 1000); // play tone 15 (D#1 = 39 Hz)
      ALEATORIO1 = 0;
      ALEATORIO2 = 0;
      ALEATORIO3 = 0;
      ALEATORIO4 = 0;
      BOTON1 = 0;
      BOTON2 = 0;
      BOTON3 = 0;
      BOTON4 = 0;
      delay(2000); // Wait for 2000 millisecond(s)
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}