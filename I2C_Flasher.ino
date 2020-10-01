#include "Wire.h"

int init_address = 0x50; //адрес I2C устройства, по даташиту на I2C EEPROM, если соединить 1,2,3 выводы с GND, т.е. их состояния будут 0 и
                         //девайс будет иметь 7-мибитный адрес равный 0x50, см. также оффициальный datasheet стр. 13 
unsigned int address = 0x00;//начальный адрес памяти микросхемы EEPROM

void setup() {
Serial.begin(115200); //инициализация COM порта со скоростью 115200 бод
Wire.begin(); //
//  while (!Serial);
//  if (readEEPROM(init_address, address))
//    Serial.println("Chip OK!");
//  else
//    Serial.println("Chip FAIL!");


 
}

void loop() {
    if (address < 16384)
   {
    Serial.print(char(readEEPROM(init_address, address))); //передаем считанные данные в com порт, потом можно их сравнить с оригинальным firmware, редактировать и т.п.
    address=address+1;
    }
    if (readEEPROM(init_address, 0x1999)!=0x20) //сразу же патчим наш firmware под 256Mbit оперативку
    {
      writeEEPROM (init_address, 0x1999, 0x20);
    }
}


//собственно функции записи и чтения по I2C во флеш, взяты прямо, без переделки из http://www.hobbytronics.co.uk/arduino-external-eeprom
void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) 
{
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
 
  delay(5);
}
 
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) 
{
  byte rdata = 0xFF;
 
 Wire.beginTransmission(deviceaddress);
 Wire.write((int)(eeaddress >> 8));   // MSB
 Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,1);
 
  if (Wire.available()) rdata = Wire.read();
 
  return rdata;
}
