# Simón Dice

Juego de memoria: el Arduino muestra una secuencia de colores con los LED y el jugador debe repetirla con los pulsadores.

Usa el [montaje electrónico compartido](../Montaje-Electronico/README.md). Código: [`Simon-Dice.ino`](Simon-Dice.ino).

## Dinámica del juego

1. El programa genera al azar una secuencia de **4 colores**.
2. Muestra la secuencia: cada LED se enciende 1 segundo y se apaga 1 segundo.
3. El jugador pulsa **4 botones**, en el orden en que vio los colores. Cada botón emite un tono distinto.
4. Al completar las 4 pulsaciones, el programa compara:
   - **Acierto:** suena un tono agudo y se encienden los 4 LED durante 1 segundo.
   - **Fallo:** suena un tono grave.
5. Se genera una nueva secuencia y se vuelve a empezar.

Por el Monitor Serie (9600 baudios) el programa también imprime la secuencia generada, las pulsaciones y el resultado (`GANO` o `PERDIO`).

## Cómo ejecutarlo

1. Arma el circuito según [Montaje-Electronico](../Montaje-Electronico/README.md).
2. Abre `Simon-Dice.ino` en el Arduino IDE.
3. Selecciona la placa **Arduino Uno** y el puerto.
4. Pulsa **Subir**.

Para jugar [Kill the Bit](../Kill-the-Bit/README.md) con el mismo montaje, carga su programa en lugar de este.
