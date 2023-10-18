/* EJERCICIO 1 - Lectura de temperatura y humedad */

#include <DHT.h>            // Librería DHT (Adafruit)
#include <LiquidCrystal.h>  // Librería LCD

// Definiciones de pines y tipo de sensor
#define DHTPIN 13      // Pin al que está conectado el sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT que utilizado

#define GREEN_LED_PIN 11  // Pin al que está conectado el LED verde
#define RED_LED_PIN 12    // Pin al que está conectado el LED rojo

// Variable de referencia para temperatura y humedad
const float TEMP_REF = 25.0;  // Temperatura de referencia en grados Celsius
const float HUMD_REF = 40.0;  // Humedad de referencia en porcentaje

// Inicialización del objeto LCD
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);  // RS, RW, E, D4, D5, D6, D7

DHT dht(DHTPIN, DHTTYPE);  // Creación de una instancia del objeto DHT

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial

  lcd.begin(16, 2);  // Inicializa el LCD de 16x2

  // Configuración de pines como salidas
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Apaga ambos LEDs al inicio
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  dht.begin();  // Inicializa el sensor DHT11

  // Muestra la primera pantalla en el LCD
  lcd.setCursor(2, 0);
  lcd.print("TriARG Ltda.");
  lcd.setCursor(2, 1);
  lcd.print("Bahia Blanca");
  delay(1000);

  // Muestra la segunda pantalla en el LCD
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Automatizacion");
  lcd.setCursor(3, 1);
  lcd.print("Temp/Humd");
  delay(1000);

  // Muestra los títulos en el LCD al inicio
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humedad:     ");
  lcd.setCursor(14, 0);  // Coloca el cursor después de "Temp: "
  lcd.write(223);        // Código para el símbolo de grados Celsius (°C)
  lcd.write("C");        // Muestra el símbolo de grados Celsius
  lcd.setCursor(14, 1);  // Coloca el cursor después de "Humedad: "
  lcd.print("%");        // Muestra el símbolo de porcentaje
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Actualiza solo los valores de temperatura y humedad en el LCD
  lcd.setCursor(9, 0);        // Posición para la temperatura
  lcd.print(temperature, 1);  // Mostrar un decimal para la temperatura
  lcd.setCursor(9, 1);        // Posición para la humedad
  lcd.print(humidity, 1);     // Mostrar un decimal para la humedad

  // Calcula las diferencias con respecto a las referencias
  float tempDiff = temperature - TEMP_REF;
  float humdDiff = humidity - HUMD_REF;

  // Control de LEDs según las condiciones
  if (temperature >= TEMP_REF) {
    digitalWrite(GREEN_LED_PIN, HIGH);  // Enciende el LED verde
    Serial.println("LED 1 (verde) encendido ");
  } else {
    digitalWrite(GREEN_LED_PIN, LOW);  // Apaga el LED verde
    Serial.println("LED 1 (verde) apagado ");
  }

  if (humidity <= HUMD_REF) {
    digitalWrite(RED_LED_PIN, HIGH);  // Enciende el LED rojo
    Serial.println("LED 2 (rojo) encendido ");
  } else {
    digitalWrite(RED_LED_PIN, LOW);  // Apaga el LED rojo
    Serial.println("LED 2 (rojo) apagado ");
  }

  // Muestra las diferencias en el puerto serial
  Serial.print("La diferencia de temperatura es: ");
  Serial.println(tempDiff, 2);  // Mostrar dos decimales para la diferencia de temperatura
  Serial.print("La diferencia de humedad es: ");
  Serial.println(humdDiff, 2);  // Mostrar dos decimales para la diferencia de humedad

  delay(1000);  // Pausa de 1 segundo entre cada ciclo de lectura y control
}
