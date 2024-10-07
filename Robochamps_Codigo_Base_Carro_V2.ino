//Código base para competencia de Robochamps
//Copienlo y pegenlo en su Arduino IDE en caso de querer usar

//NOTA IMPORTANTE - Los carritos estaran usando un modulo bluetooth para recibir comandos(asi podran manejar su carrito)
//NOTA IMPORTANTE - Existen aplicaciones en play store que permiten mandar letras o numeros al modulo y el arduino los recibe

//Se puede modificar editar o borrar cosas 

//Seccion del código en el que se importa la libreria de Servo
#include <Servo.h>

//De esta forma se declara el servo: Servo nombre_que_le_quieras_asignar
Servo servoEnfrente;

//Variable que nos permitira guardar los valores que registra el modulo Bluetooth (Lo que se comentaba en NOTA IMPORTANTE)
char bluetoothReading;

//Variables para guardar los numeros de los pines de los motores Izquierdos
int motorIzquierdaPositivo = 13; //Este pin si lo activamos el motor girara en sentido positivo
int motorIzquierdaNegativo = 12; //Este pin si lo activamos el motor girara en sentido negativo
int motorDerechaPositivo = 11; //Este pin si lo activamos el motor girara en sentido positivo
int motorDerechaNegativo = 10; //Este pin si lo activamos el motor girara en sentido negativo


//Espacio en el que se declara todo lo que nuestro robot tendra (Que sea programable)
void setup() {

  //Se declaran los dos motores y sus respectivos puertos
  pinMode(motorIzquierdaPositivo, OUTPUT); // Lo pueden ver como (13, OUTPUT), aqui le estamos diciendo al codigo que hay un OUTPUT en este pin
  pinMode(motorIzquierdaNegativo, OUTPUT); // Lo pueden ver como (12, OUTPUT), aqui le estamos diciendo al codigo que hay un OUTPUT en este pin
  pinMode(11, OUTPUT); // Lo pueden ver como (11, OUTPUT), aqui le estamos diciendo al codigo que hay un OUTPUT en este pin
  pinMode(10, OUTPUT); // Lo pueden ver como (10, OUTPUT), aqui le estamos diciendo al codigo que hay un OUTPUT en este pin

  //Se declara el servo (Si es que van a usar) y el puerto en el que esta
  servoEnfrente.attach(3);

  //Linea necesaria para la lectura de datos del Arduino (IMPORTANTE PARA EL MODULO BLUETOOTH), esta iniciara un puerto serie (Puerto que estara recibiendo valores a 9600 baudios)
  Serial.begin(9600);

  //Lineas que nos sirven para apagar los motores desde el comienzo
  digitalWrite(motorIzquierdaPositivo,LOW); //digitalWrite es un comando que nos permite enviar voltaje al puerto indicado (13, LOW)
  digitalWrite(motorIzquierdaNegativo,LOW);//digitalWrite es un comando que nos permite enviar voltaje al puerto indicado (13, LOW)
  digitalWrite(motorDerechaPositivo,LOW);//digitalWrite es un comando que nos permite enviar voltaje al puerto indicado (13, LOW)
  digitalWrite(motorDerechaNegativo,LOW);//digitalWrite es un comando que nos permite enviar voltaje al puerto indicado (13, LOW)
  //La palabra LOW hace referencia a apagado, la palabra HIGH hace referencia a prendido

}

void loop() {
    //Condicional que nos permite conocer si el modulo esta agarrando senales de la placa bluetooth o no
    if(Serial.available()){
      bluetoothReading = Serial.read(); //Se asigna el valor leido por el puerto serial (El modulo Bluetooth) a la variable bluetoothReading
      Serial.println(t); 

      //En caso de que ningun boton este siendo presionado estas lineas se aseguran que todo motor este apagado
      digitalWrite(motorIzquierdaPositivo,LOW); //Se declara que estara apagado el motor
      digitalWrite(motorIzquierdaNegativo,LOW); //Se declara que estara apagado el motor
      digitalWrite(motorDerechaPositivo,LOW); //Se declara que estara apagado el motor
      digitalWrite(motorDerechaNegativo,LOW); //Se declara que estara apagado el motor

      servoEnfrente.write(0); //.write es un comando que nos permite posicionar el servo a un angulo fijo


    //Condicion que si el valor recibido por el modulo bluetooth es "F" (Boton de arriba) este realizara lo siguiente
    //En teoria el carro debe de avanzar
    if (bluetoothReading == 'F'){
      digitalWrite(motorIzquierdaPositivo,HIGH); //Se declara que estara PRENDIDO el motor
      digitalWrite(motorDerechaPositivo,HIGH); //Se declara que estara PRENDIDO el motor

    }

    if(bluetoothReading == '1'){
      servoEnfrente.write(180); // Se declara que queremos que nuestro servo vaya a 180 grados al presionar '1'

    }
  }
}
