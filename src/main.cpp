#include <Arduino.h>

#include <Teclado.h>

uint8_t linha[4] = {A0, 12, 11, 10};
uint8_t coluna[8] = {2, 3, 4, 5, 6, 7, 8, 9};

Teclado teclado;

void setup()
{
  Serial.begin(9600);
  Serial.println("Tecladinho da Ju!");
  teclado.begin(linha, coluna, 13);
  delay(1000);
}

void loop()
{
  teclado.varreduraTeclado();
  delay(10);
}
