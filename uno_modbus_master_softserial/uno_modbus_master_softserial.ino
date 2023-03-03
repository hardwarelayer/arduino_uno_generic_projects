#include <ModbusMaster.h>
#include <SoftwareSerial.h>

#include <Wire.h>
#include <hd44780.h>
#undef hd44780_h // undefine this so the example sketch does not think hd44780 is being used.
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

SoftwareSerial mySerial(10, 11); // RX, TX

//https://circuitdigest.com/microcontroller-projects/rs-485-modbus-serial-communication-with-arduino-as-master
//but the library in the article is old and cannot build (error)
//so I modified everything
//  to use the ModBusMaster lib from standard Libraries Manager (https://github.com/4-20ma/ModbusMaster)
//
// Note: USB-RS485 must be removed during flashing Uno

ModbusMaster node;

void setup() 
{
  lcd.init();

  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Modbus Master");
  lcd.setCursor(0,1);
  lcd.print("by TienTN");

  //pinMode(4,INPUT);
  //pinMode(5,INPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
  node.begin(1, mySerial);

  delay(2000);
  lcd.clear();
}

bool isOdd = false;
void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("Modbus Master");

  lcd.setCursor(0,1);
  if (isOdd)
    lcd.print("SWR: 0x40000=01");
  else
    lcd.print("SWR: 0x40000=00");

  if (isOdd)
    node.writeSingleRegister(0x40000,1);               //Writes 1 to 0x40000 holding register
   else
     node.writeSingleRegister(0x40000,0);

  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("WSR: 0x40001");
  if (isOdd)
    node.writeSingleRegister(0x40001,1);               //Writes 1 to 0x40001 holding register
   else
     node.writeSingleRegister(0x40001,0);

  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("WSR: 0x40003");
  if (isOdd)
    node.writeSingleRegister(0x40003,1);               //Writes 1 to 0x40001 holding register
   else
     node.writeSingleRegister(0x40003,0);

  isOdd = !isOdd;

  delay(2000);
  lcd.clear();

}
