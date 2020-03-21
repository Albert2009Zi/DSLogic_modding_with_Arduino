# DSLogic_modding_with_Arduino
How to upgrade logic analyzer DSLogic U2Basic to DSLogic Plus with Arduino

Для тех у кого есть Arduino и паяльник ;)

Описание процедуры модификации на русском:
1. После манипуляций описанных в https://habr.com/ru/post/483496/ выпаиваем EEPROM с прошивкой
2. Ноги микрухи (в моем случае это была M24128-BW от фирмы ST) 1,2,3,4 и 7 соединяем вместе и паяем на GND 
   прошивающей схемы, в данном случае Arduino. Остальные пины к соответствующим пинам ины I2C.
3. Должно получится, как на фотке EEPROM connected to Arduino.jpg
4. Льем в Arduino скетч I2C_Flasher.ino, открываем терминал (я пользуюсь COM Port Toolkit 4.0), настраиваем на порт,
   куда подключен Arduino и стартуем наш скетч.

