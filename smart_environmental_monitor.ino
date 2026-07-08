#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN,HTTYPE);

int lightSensor = A0;
int pirSensor = 8;
int led = 9;

int lightThreshold = 800;

void setup() {
  lcd.begin(16, 2);
  dht.begin();

  pinMode(pirSensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int lightValue = analogRead(lightSensor);
  int motion = digitalRead(pirSensor);


  // Smart night light:
  // Dark + motion = LED ON
  if (lightValue < lightThreshold && motion == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }


  // Temperature + humidity screen
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity);
  lcd.print("%");

  delay(3000);


  // Light + motion screen
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Light:");

  if (lightValue < lightThreshold) {
    lcd.print("Dark");
  }
  else {
    lcd.print("Bright");
  }


  lcd.setCursor(0, 1);
  lcd.print("Motion:");

  if (motion == HIGH) {
    lcd.print("YES");
  }
  else {
    lcd.print("NO");
  }

  delay(3000);
}