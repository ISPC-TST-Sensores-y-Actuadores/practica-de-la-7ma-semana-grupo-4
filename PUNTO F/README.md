
## **Ejercicio F**

### **Carpeta Simulador**
Simulación con dos placas de desarrollo Arduino Uno en Proteus, donde la primer placa(a la izquierda)
tiene conectada un sensor DHT11 de temperatura y humedad, y un módulo de radiofrecuencia, su parte
transmisora(TX). En la segunda placa( a la derecha), tiene conectada la parte receptora de módulo RF, 
junto a una terminal virtual para hacer visualizar los parámetros enviados.

### **Carpeta CodigoEmisor**
Desarrollo de la implementación con el framework de Arduino utilizando PlatformIO en VSCode.
Aquí se encuentra el código para la primer placa, donde se obtiene los datos de temperatura y
humedad del Sensor DHT11, y a través del Módulo RF transmisor se envían estos dos parámetros,
previo acondicionamiento de los mismos, hacia el Modulo RF receptor, utilizando la librería 
<RadioHead.h>, que engloba utilidades para módulos de este tipo.

### **Carpeta CodigoReceptor**
Desarrollo de la implementación con el framework de Arduino utilizando PlatformIO en VSCode.
Aquí se encuentra el código de la segunda placa, donde el Modulo RF receptor obtiene los datos
enviados desde el modulo transmisor utilizando la librería mencionada, y que son procesados en la placa Arduino y mostrados en la terminal virtual.

![ezgif-5-2afd665c4c](https://user-images.githubusercontent.com/109010330/198101564-d10427d8-ab7f-4e87-b3a4-37d344cdcaee.gif)


