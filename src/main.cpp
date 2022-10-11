#include <Arduino.h>
#include <BH1750.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <iostream>
#include <unordered_map>

using namespace std;

BH1750 lightMeter(0x23);
LiquidCrystal_I2C lcd(0x27, 16, 2);

string roomType = "stairway";

unordered_map<string, int> room_type;

void balanceLUX(int recom, float current) {
  lcd.setCursor(0, 1);
  if (recom >= current) {
    lcd.print("UP");
  } else {
    lcd.print("DOWN");
  }
}

void setup() {
  room_type["kitchen"] = 400;
  room_type["office"] = 400;
  room_type["parking"] = 125;
  room_type["restroom"] = 200;
  room_type["stairway"] = 125;
  room_type["bedroomC"] = 350;
  room_type["bedroomA"] = 200;
  room_type["livingroom"] = 300;

  Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin(D2, D1);

  // lcd.begin(16, 2);
  lcd.init();

  lcd.backlight();

  lcd.setCursor(0, 0);
  // lcd.print("HELLO");
  /*

    BH1750 has six different measurement modes. They are divided in two groups;
    continuous and one-time measurements. In continuous mode, sensor
    continuously measures lightness value. In one-time mode the sensor makes
    only one measurement and then goes into Power Down mode.

    Each mode, has three different precisions:

      - Low Resolution Mode - (4 lx precision, 16ms measurement time)
      - High Resolution Mode - (1 lx precision, 120ms measurement time)
      - High Resolution Mode 2 - (0.5 lx precision, 120ms measurement time)

    By default, the library uses Continuous High Resolution Mode, but you can
    set any other mode, by passing it to BH1750.begin() or BH1750.configure()
    functions.

    [!] Remember, if you use One-Time mode, your sensor will go to Power Down
    mode each time, when it completes a measurement and you've read it.

    Full mode list:

      BH1750_CONTINUOUS_LOW_RES_MODE
      BH1750_CONTINUOUS_HIGH_RES_MODE (default)
      BH1750_CONTINUOUS_HIGH_RES_MODE_2

      BH1750_ONE_TIME_LOW_RES_MODE
      BH1750_ONE_TIME_HIGH_RES_MODE
      BH1750_ONE_TIME_HIGH_RES_MODE_2

  */

  // balanceLUX(roomType);

  // begin returns a boolean that can be used to detect setup problems.
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  } else {
    Serial.println(F("Error initialising BH1750"));
  }
}

void loop() {
  if (lightMeter.measurementReady()) {
    float lux = lightMeter.readLightLevel();
    int balanceV = room_type.at(roomType);

    lcd.print("Light: ");
    lcd.print(lux);
    lcd.println(" lx");

    lcd.setCursor(0, 1);
    lcd.print(balanceV);

    balanceLUX(balanceV, lux);
  }

  delay(1000);
  lcd.clear();
}