![image](https://user-images.githubusercontent.com/20140969/78697360-faa06d00-7900-11ea-960d-77e91eeea3ff.png)
![image](https://user-images.githubusercontent.com/20140969/78697504-2facbf80-7901-11ea-862b-0bddbd8652e9.png)


**CALEIDUINO** es un caleidoscopio digital sonoro interactivo basado en Arduino. CALEIDUINO es un juguete, un objeto artístico y una herramienta para aprender electrónica y programación de una forma lúdica y creativa.

El  corazón del CALEIDUINO es una placa PCB a la que se conectan una Arduino nano 3.0, una pantalla TFT 1.8′, un acelerómetro analógico de 3 ejes GY-61, un piezoeléctrico, un interruptor y una batería de 9V. Como en cualquier caleidoscopio al uso, se le añaden 3 espejos en forma de prisma triangular. Una carcasa de metacrilato le da la forma externa. La idea es, como en los caleidoscopios analógicos, utilizar el movimiento del usuario (recogido mediante el acelerómetro) para generar gráficos y sonidos.

![61868f5a58708ad7c49de36b97720a94](https://user-images.githubusercontent.com/20140969/78697847-b9f52380-7901-11ea-96f8-d7b301cae019.gif)
![caleiduino](https://user-images.githubusercontent.com/20140969/78768558-64b22400-798c-11ea-9876-1b354a4aac2a.GIF)

Todo el proyecto CALEIDUINO es open source (CC-BY-NC-SA), exceptuando la marca y el logo (propiedad del autor) y ha sido diseñado por el artista José Manuel González, con la inestimable ayuda de Juan Jesús García (para la PCB), de Laura González (diseño gráfico), de Marta Verde (para el visualizador), de IKONO Instituto de Investigación Cultural (en cuyas instalaciones se ha desarrollado la parte final del proyecto) y del proyecto Itmakes de la Embajada de Italia en España. Desde aquí damos las gracias a todos aquellos que con su creatividad y generosidad, compartiendo sus creaciones, sus conocimientos y sus habilidades, han hecho posible que el CALEIDUINO sea una realidad.

![image](https://user-images.githubusercontent.com/20140969/78698059-03de0980-7902-11ea-8eb8-b0d3a8cd9590.png)

Si deseas tener uno como el que aparece en este repositorio ([Versión 1.0](http://www.caleiduino.com/) y [2.0](http://www.caleiduino.com/caleiduino-2-0/)), puedes adquirirlo y construirte uno fácilmente accediendo a la web o poniéndote en contacto con el autor en el siguiente email:

WEB: http://www.caleiduino.com/

EMAIL: caleiduino@caleiduino.com

A continuación el repositorio del sketch básico de Arduino para hacer funcionar el CALEIDUINO, con comentarios y especificaciones que permitan al no iniciado entender como funciona el programa. En breve colgaré más piezas de código con diferentes funcionalidades que permitan a quienes quieran jugar con el caleidoscopio aprender y dejar volar su creatividad.

Si tienes un CALEIDUINO o te has construido el tuyo propio siguiendo las indicaciones del [tutorial DIY](http://www.caleiduino.com/caleiduino-diy/), antes de ponernos a jugar con nuestro artilugio es importante seguir los siguientes pasos, los cuales también vienen especificados con detalle en la [WEB](http://www.caleiduino.com/software/).



**1) INSTALACIÓN DE IDE DE ARDUINO Y LAS LIBRERÍAS**

El software que hace funcionar el CALEIDUINO se basa en la IDE de Arduino y en dos librerías que permiten el uso de 
pantallas TFT (la nuestra es de 1.8′), la librería ST7735 y la librería GFX, ambas de Adafruit. 
A continuación los pasos a seguir para instalar todo lo necesario para poner tu CALEIDUINO a funcionar.

Primero abre el enlace de abajo y descarga la IDE de Arduino:

https://www.arduino.cc/en/Main/Software

Elige el software de acuerdo a tu sistema operativo (Mac o Windows) e instálalo siguiendo las instrucciones. 
Una vez instalado, ábrelo y tienes que ver abrirse una consola como esta:

![image](https://user-images.githubusercontent.com/20140969/78769742-05edaa00-798e-11ea-88fd-03e54a50afaa.png)

Después descarga la librería **Adafruit_ST7735**:

https://github.com/adafruit/Adafruit-ST7735-Library/

Y la librería **GFX**:

https://github.com/adafruit/Adafruit-GFX-Library/

Una vez descargadas, para instalarlas convenientemente, sigue las instrucciones siguientes:

https://www.arduino.cc/en/Guide/Libraries/



**2) INSTALACIÓN DEL SKETCH DE CALEIDUINO**

Una vez tengas todo a punto, sólo tienes que descargar o copiar el código [Caleiduino.ino](https://github.com/Caleiduino/Caleiduino/blob/master/Caleiduino_1.ino) de este repositorio. Una vez que lo incluyas en tu carpeta de proyectos de Arduino, sólo tendrás que abrirlo y descargarlo en tu placa.
Es un ejemplo de cómo podemos crear los gráficos y los sonidos con el CALEIDUINO de forma sencilla. Para más información sobre posibilidades creativas, librerías, etc., accede a la [WEB](http://www.caleiduino.com/software/). 

**¡ÁNIMO Y A DISFRUTAR!**
