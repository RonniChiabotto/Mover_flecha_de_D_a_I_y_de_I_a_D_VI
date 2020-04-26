//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                      //
//  Skecht que imprime un caracter en el inicio de la patalla lcd y sigue imprimindo en la columna seguinte y apagando  //
//  la anterior dando la ilusion de desplazamito hase a l derecha y despues a la izquierda                              //                                                                                                                
//                                                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 
#include<Wire.h>                                            //inclusion de livreria
#include<LiquidCrystal_I2C.h>                               //inclusion de livreria
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);       //configuracion de direcion y del lcd

byte seta_dirt[8]  = {0x0,0x8,0xc,0xe,0x1f,0xe,0xc,0x8};    //criando caracter en exadecimal "seta para derecha"
byte seta_esqd[8]  = {0x0,0x2,0x6,0xe,0x1f,0xe,0x6,0x2};    //criando caracter en exadecimal "seta para esquerda"
int i = 0;                                                  //variable global para el blucle for

void setup()
{
  lcd.begin(16,4);                                          //declara el tipo de lcd
  lcd.setBacklight(LOW);                                    //prendemos el led del lcd
  lcd.createChar(1, seta_dirt);                             //nomenclaturamos el caracter como "3"
  lcd.createChar(2, seta_esqd);                             //nomenclaturamos el caracter como "4"
  lcd.clear();                                              //limpiar pantalla
}

void loop()
{
  for (i = 0; i <= 15;)                                     //Buble para umicar, imprimir, limpia y sumar en la varibla de control
    {
      lcd.setCursor(i, 2);
      lcd.print((char)1); 
      delay(150);
      lcd.clear();
      i++;
    }
  lcd.clear();
    for (i = 16; i >= 0;)                                   //Buble para umicar, imprimir, limpia y sumar en la varibla de control
      {
        lcd.setCursor(i, 2);
        lcd.print((char)2);
        delay(150);
        lcd.clear();
        i--;
      }
}
