#ifndef TECLA_H
#define TECLA_H

#include <Arduino.h>

class Tecla
{
private:
    byte tecla;
    int pressionada;
    unsigned int nota;

public:
    Tecla();
    ~Tecla();
    void setTecla(byte key);
    void setPress(int press);
    void setNota(unsigned int note);
    byte getTecla();
    int getPress();
    unsigned int getNota();

};
#endif