/*****************************************************************
       xxxx  xxxx  x     xxxx  x  xxx   x  x  x  x  x  xxxx
       x     x  x  x     x     x  x  x  x  x  x  xx x  x  x
       x     xxxx  x     xxx   x  x  x  x  x  x  x xx  x  x
       x     x  x  x     x     x  x  x  x  x  x  x  x  x  x
       xxxx  x  x  xxxx  xxxx  x  xxx   xxxx  x  x  x  xxxx (1)
Este ejemplo de CALEIDUINO se basa en las librerias de Adafruit GFX 
y ST_7735, que hacen posible conectar Arduino con una pantalla TFT 
de 1.8'. Gracias a Arduino y a Adafruit por desarrollar el hardware 
y el software que hacen posible el proyecto CALEIDUINO. Este sketch 
de codigo es abierto y de dominio publico. Esta a disposicion de 
cualquiera que desee crear su propio CALEIDUINO.
¡¡Animate y crea tu propio caleidoscopio digital sonoro!!
(CC) Jose Manuel Gonzalez 2018
 
******************************************************************/

// Conexiones a la pantalla TFT
// #define sclk 13 / Usa esta linea si prefieres Opcion 1 (lento)
// #define mosi 11 / Usa esta linea si prefieres Opcion 1 (lento)
#define TFT_CS  8
#define TFT_DC  9
#define TFT_RST  10 // Se puede conectar tambien al PIN RESET (no con placa CALEIDUINO)

// #include "pitches.h" / Para el caso que quieras jugar con las notas 
// de la carpeta "pitches.h" que aparecen más abajo. Mas informacion:
// https://www.arduino.cc/en/Tutorial/ToneMelody
#include <Adafruit_GFX.h> // Libreria para programar los graficos
#include <Adafruit_ST7735.h> // Libreria que permite usar el chip 
//especifico de la pantalla TFT
#include <SPI.h> // Libreria para que la Arduino se comunique con
// la pantalla TFT mediante protocolo Serial

#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

// Opcion 1: Usa todos los PINES pero la pantalla funciona un poco 
// mas lento:
// Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);

// Opcion 2: Debe usar los PINES SPI 
// (Para Arduino UNO PINES sclk = 13 y mosi = 11). 
// Este metodo es mas rapido: 
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
// float p = 3.1415926;

// Los 3 inputs analogicos del acelerometro, que corresponden con
// los 3 ejes X, Y y Z, se conectan a los PINES de la placa 
// Arduino en A0, A1 y A2:

const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

// Generamos un mapeado de los valores del sensor. 
// El valor minimo es 260 y el maximo 420:

int minVal = 260; 
int maxVal = 420;

// Valores que entran por los PINES A0, A1 y A2:

int val1 = 0;
int val2 = 0;
int val3 = 0;
int sound = 0;

void setup(void) {
Serial.begin(115200);
 
// Inicializamos la pantalla TFT en negro:

tft.initR(INITR_BLACKTAB); 
uint16_t time = millis();
tft.fillScreen(ST7735_BLACK);

// PIN 4 de salida al borne (+) del piezoelectrico(sonido):

pinMode(4, OUTPUT);
}

// ¡¡¡En el void loop() es donde empieza la fiesta!!!

void loop() {
 
int sensorValue1 = analogRead(xPin);
int sensorValue2 = analogRead(yPin);
int sensorValue3 = analogRead(zPin);
 
// Convertimos la salida analogica (que va de 0 - 1023) a 
// voltaje (0 - 5V):

float voltage1 = sensorValue1;
float voltage2 = sensorValue2;
float voltage3 = sensorValue3;
 
// Mapeamos los valores entrantes del acelerometro para usarlos
// despues en la pantalla TFT
 
// +---------- 160px -----------+
// +                            +
// +                            +
// 128px                        +
// +                            +
// +                            +
// +----------------------------+

val1 = map(voltage1, minVal, maxVal, 1, 160); // De 0 a 160px ancho de pantalla
val2 = map(voltage2, minVal, maxVal, 1, 128); // De 0 a 128px alto de pantalla
val3 = map(voltage3, minVal, maxVal, 1, 128); // De 0 a 128px alto de pantalla

// Mapeamos los valores del sensorValue3 para crear valores sonoros: 

sound = map(voltage3, minVal, maxVal, 3520, 4978); 

// La funcion tone(PIN, Frecuencia, Duracion). Mas informacion en: 
// https://www.arduino.cc/en/Reference/Tone 
// Aqui añadimos aleatoriedad random() a la duracion de los sonidos 
// del piezoelectrico para que sean mas locos: 

tone(4, sound, val1/random(1, 10));
 
// Gracias al puerto Serial, podemos visualizar en la pantalla los 
// valores entrantes del acelerometro y en consecuencia, los valores 
// de sonido lanzados al piezoelectrico. Esto ocurrira mientras 
// tengamos la placa Arduino conectada mediante el cable USB. 
// Puede ser util para calibrar los valores en razon de nuestras 
// necesidades: 

Serial.print("valor X ="); 
Serial.print(val1); 
Serial.print("valor Y ="); 
Serial.print(val2); 
Serial.print("valor Z ="); 
Serial.print(val3); 
Serial.print("sound ="); 
Serial.println(sound); 

/* Aqui hay varios ejemplos de las funciones graficas que permite la 
libreria de Adafruit GFX. Funciona de forma parecida a las funciones  
basicas de dibujo de Processing. Nos permite dibujar triangulos,  
rectangulos, circulos, elipses, lineas verticales, horizontales,  
oblicuas, etc... Juega con las diferentes posibilidades y combinalas  
para que los graficos de tu pantalla TFT hagan formas caleidoscopicas  
interesantes y divertidas. Mas informacion en:
https://github.com/adafruit/Adafruit-GFX-Library 
A continuacion vamos a dibujar un triangulo relleno de color. Para entender
esta funcion, fijate que hay 7 valores entre parentesis. La funcion funciona asi:
tft.fillTriangle(X1, Y1, X2, Y2, X3, Y3, Color);
X1 / Y1 --> coordenadas del primer vertice del triangulo
X2 / Y2 --> coordenadas del segundo vertice del triangulo
X3 / Y3 --> coordenadas del tercer vertice del triangulo
Color ----> cifra de 16 bits, ROJO(0/31), VERDE(0/63) y AZUL(0/31)
*/ 

tft.fillTriangle(val1, val2, val3, val1, val3, random(100), random(316331)); 

// Dibuja rectangulos con los vertices redondeados: 

tft.fillRoundRect(val1, val2, random(10,80), random(10,80), random(5), 277); 

// Dibuja perimetro de circunferencia: 

tft.drawCircle(val1, val3, val2, random(316331)); 

// Dibuja circulo de un color determinado: 

tft.fillCircle(val1, val2, random(30), random(316331)); 

// Dibuja lineas verticales: 

tft.drawFastVLine(val2, 1, tft.height(), random(316331)); 

// Dibuja lineas oblicuas:

tft.drawLine(val1, val2, val2, val3, random(316331));
tft.drawLine(val2, val2, 1, 1, random(316331));

// Dibuja perimetro de un rectangulo:

tft.drawRect(val2, random(127), random(127), random(127), random(316331));

// El tiempo de refresco de los graficos nunca debe ser = 0, de lo 
// contrario la pantalla TFT se vuelve loca: 

if(val1<1){ 
val1 = 1; }
 
// El delay() permite al loop() respirar y aqui lo define el valor 
// analogico del PIN A0, con lo que controlamos la velocidad de 
// refresco de los graficos segun la posicion del CALEIDUINO: 

delay(val1); } 

// FIN
