#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int pinButton = 3;

//Set button increment value
int x = 0; 

//Define LCD text
const char* str = "PRESS THE BUTTON";
const char* str2 = "COMMUNISM WINS!!";


void setup() {  
    pinMode(pinButton,INPUT);

    //Initialize LCD format
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD
    lcd.print(str);

}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(7, 1);
    if(digitalRead(pinButton))
    {
        x++;
        lcd.print(x);
        delay(150);
    }

    if(x >= 69){
      lcd.setCursor(0, 0);
      delay(200);
      lcd.print(str2);
      //Blink display
      lcd.noDisplay();
      delay(300);
      lcd.display();
      delay(200);
    }
}

