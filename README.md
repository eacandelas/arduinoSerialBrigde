#README.md

Este sketch recibe datos a traves del Serial de Arduino, y los reenvia hacia el Software Serial en caso del Arduino UNO o al Serial1 en caso del Arduino MEGA.

Tambien monitorea por datos desde los Software Serial y Serial1, reenviandolos a Serial.

El cambion entre UNO y MEGA se logra descomentando la linea #define UNO o #define MEGA segun sea el caso.

Notas:

Una mejora seria hacer una funcion a la que se le pase un buffer como argumento con los datos a enviar y un puntero a un objeto serial por el que los envirara.


