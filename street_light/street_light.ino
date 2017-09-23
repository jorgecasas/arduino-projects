/**
 * Semaforo rojo - verde - amarillo
 * Requiere:
 *   - 3 leds (rojo, verde, amarillo... curyos pines tienen que ponerse en sentido + y - correcto)
 *   - 1 resistencia de 330 Ohm
 *   - Cables, protoboard y Arduino
 * Howto: 
 *   - Conectar pines Arduino a leds correspondientes.
 *   - Conectar salidas de los leds a entrada de la resistencia y la salida de la resistencia a tierra
 */

// Definicion de pines
int rojo = 9;
int amarillo = 11;
int verde = 10;

// 1 = rojo, 2 = amarillo, 3 = verde
int estado = 1;

// the setup routine runs once when you press reset:
void setup() {                
  // Inicializamos las salidas digitales (pines) como OUTPUTs
  pinMode( rojo, OUTPUT);
  pinMode( amarillo, OUTPUT);
  pinMode( verde, OUTPUT);
  estado = 1; // Rojo
  
  // Apagamos todos leds
  digitalWrite( rojo, LOW );
  digitalWrite( amarillo, LOW );
  digitalWrite( verde, LOW );
}

// the loop routine runs over and over again forever:
void loop() {
  // Segun el estado, encendemos led, esperamos, apagamos led e indicamos
  // cual es el siguiente estado
  if ( estado == 1 ) { // Rojo
    digitalWrite( rojo, HIGH );
    delay(5000);
    estado = 3; // Pasamos al verde
    digitalWrite( rojo, LOW );
    
  } else if ( estado == 3 ) { // Verde
    digitalWrite( verde, HIGH );
    delay(5000);
    estado = 2; // Pasamos al amarillo
    digitalWrite( verde, LOW );
    
  } else if ( estado == 2 ) { // Estado amarillo
    digitalWrite( amarillo, HIGH );
    delay(1000);
    estado = 1; // Pasamos al rojo
    digitalWrite( amarillo, LOW );
  }
  
  
}
