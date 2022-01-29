#include "Tecla.h"

Tecla::Tecla()
{
   
}

Tecla::~Tecla()
{
}

void Tecla::setPress(int press)
{
    pressionada = press;
}

void Tecla::setTecla(byte key)
{
    tecla = key;
}

void Tecla::setNota(unsigned int note){
    nota = note;
}

int Tecla::getPress()
{
    return pressionada;
}

byte Tecla::getTecla()
{
    return tecla;
}

unsigned int Tecla::getNota(){
    return nota;
}