#ifndef TECLADO_H
#define TECLADO_H

#include <Arduino.h>
#include <Tecla.h>

#define FUNCTION_BUTTON A1
#define TONE_BUTTON A2 
#define TEMPO_BUTTON A3
#define VOLUME_BUTTON A6


class Teclado
{
private:
    
    Tecla tecladoAntigo[32];
    Tecla tecladoNovo[32];
    uint8_t _linha[4];
    uint8_t _coluna[8];
    uint8_t pino_som;
    void setup();
    
public:
    Teclado();
    ~Teclado();
    void begin(uint8_t linha[4], uint8_t coluna[8], uint8_t pino);    // pinos de saida [oitavas], pinos de entrada [notas]
    void varreduraTeclado();
};


#endif