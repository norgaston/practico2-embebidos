/* EJERCICIO 2 - Automatización del hogar */

// Definiciones de pines
const int plantaBajaLed = 13;  // Pin para el LED de la planta baja
const int plantaAltaLed = 12;  // Pin para el LED de la planta alta
const int patioLed = 11;       // Pin para el LED del patio
const int alarmaLed = 8;       // Pin para el LED de la alarma
const int motorCochera = 10;   // Pin para el motor de la cochera
const int motorPorton = 9;     // Pin para el motor del portón

void setup() {
  // Inicialización de pines como salidas
  pinMode(plantaBajaLed, OUTPUT);
  pinMode(plantaAltaLed, OUTPUT);
  pinMode(patioLed, OUTPUT);
  pinMode(alarmaLed, OUTPUT);
  pinMode(motorCochera, OUTPUT);
  pinMode(motorPorton, OUTPUT);

  // Configuración del Bluetooth
  Serial.begin(9600);

  // Inicialización de LEDs y motores apagados al inicio
  digitalWrite(plantaBajaLed, LOW);
  digitalWrite(plantaAltaLed, LOW);
  digitalWrite(patioLed, LOW);
  digitalWrite(alarmaLed, LOW);
  digitalWrite(motorCochera, LOW);
  digitalWrite(motorPorton, LOW);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Lee el comando enviado por Bluetooth
    char command = Serial.read();
    // Ejecuta la función correspondiente al comando recibido
    executeCommand(command);
  }
}

void executeCommand(char command) {
  // Realiza acciones según el comando recibido
  switch (command) {
    case 'a':
    case 'A':
      digitalWrite(plantaBajaLed, HIGH);  // Enciende el LED de la planta baja
      break;

    case 'b':
    case 'B':
      digitalWrite(plantaBajaLed, LOW);  // Apaga el LED de la planta baja
      break;

    case 'c':
    case 'C':
      digitalWrite(plantaAltaLed, HIGH);  // Enciende el LED de la planta alta
      break;

    case 'd':
    case 'D':
      digitalWrite(plantaAltaLed, LOW);  // Apaga el LED de la planta alta
      break;

    case 'e':
    case 'E':
      digitalWrite(patioLed, HIGH);  // Enciende el LED del patio
      break;

    case 'f':
    case 'F':
      digitalWrite(patioLed, LOW);  // Apaga el LED del patio
      break;

    case '1':
      digitalWrite(alarmaLed, HIGH);  // Enciende el LED de la alarma
      break;

    case '0':
      digitalWrite(alarmaLed, LOW);  // Apaga el LED de la alarma
      break;

    case '2':
      digitalWrite(motorCochera, HIGH);  // Enciende el motor de la cochera
      break;

    case '3':
      digitalWrite(motorCochera, LOW);  // Apaga el motor de la cochera
      break;

    case '4':
      digitalWrite(motorPorton, HIGH);  // Enciende el motor del portón
      break;

    case '5':
      digitalWrite(motorPorton, LOW);  // Apaga el motor del portón
      break;

    default:
      // Comando no reconocido
      break;
  }
}
