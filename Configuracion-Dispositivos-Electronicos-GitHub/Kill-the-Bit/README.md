# Kill the Bit

Juego de reflejos: un LED encendido recorre los cuatro colores y el jugador debe pulsar el botón del color que está encendido para apagarlo.

Usa el [montaje electrónico compartido](../Montaje-Electronico/README.md). Código: [`Kill-the-Bit.ino`](Kill-the-Bit.ino).

## Dinámica del juego

- Un solo LED está encendido a la vez y recorre la secuencia azul, rojo, verde y amarillo, y de nuevo azul. Cada pulsador es del color de su LED.
- **Acierto:** si pulsas el color que está encendido, ese LED se apaga para siempre y la secuencia sigue con los LED que quedan.
- **Fallo:** si pulsas otro color, se vuelve a encender el último LED que habías apagado. Si todavía no has apagado ninguno, el fallo solo suena.
- **Tolerancia:** si el LED acaba de pasar, la pulsación también cuenta (hasta 200 ms después).
- **Victoria:** ganas cuando se apagan los 4 LED. Suena una melodía y, al pulsar cualquier botón, empieza otra partida.

## Ajustes

Al inicio del código hay constantes para cambiar la dificultad:

| Constante | Valor | Función |
|---|---|---|
| `PASO_MS` | 450 | Tiempo que dura cada LED encendido (menor = más difícil). |
| `GRACIA_MS` | 200 | Tolerancia para pulsar justo después de que el LED se movió. |
| `REBOTE_MS` | 20 | Filtro anti-rebote de los pulsadores. |

## Cómo ejecutarlo

1. Arma el circuito según [Montaje-Electronico](../Montaje-Electronico/README.md).
2. Abre `Kill-the-Bit.ino` en el Arduino IDE.
3. Selecciona la placa **Arduino Uno** y el puerto.
4. Pulsa **Subir**.

Para jugar [Simón Dice](../Simon-Dice/README.md) con el mismo montaje, carga su programa en lugar de este.
