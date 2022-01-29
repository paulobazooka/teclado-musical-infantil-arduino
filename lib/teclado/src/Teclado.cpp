#include "Teclado.h"

Teclado::Teclado()
{
    byte indice = 0;
    for (byte i = 0; i < 4; i++)
    {
        for (byte j = 0; j < 8; j++)
        {
            Tecla key;
            key.setPress(false);
            key.setTecla(indice);
            tecladoAntigo[indice] = tecladoNovo[indice] = key;
            indice++;
        }
    }
}

Teclado::~Teclado()
{
}

void Teclado::begin(uint8_t linha[4], uint8_t coluna[8], uint8_t pino)
{
    pino_som = pino;
    setup();

    for (byte i = 0; i < 4; i++)
    {
        _linha[i] = linha[i];
        pinMode(linha[i], OUTPUT);
        digitalWrite(linha[i], HIGH);
    }

    for (byte i = 0; i < 8; i++)
    {
        _coluna[i] = coluna[i];
        pinMode(coluna[i], INPUT_PULLUP);
    }
}

void Teclado::setup()
{
    tecladoAntigo[0].setNota(87);
    tecladoAntigo[1].setNota(92);
    tecladoAntigo[2].setNota(98);
    tecladoAntigo[3].setNota(104);
    tecladoAntigo[4].setNota(110);
    tecladoAntigo[5].setNota(116);
    tecladoAntigo[6].setNota(123);
    tecladoAntigo[7].setNota(131);
    tecladoAntigo[8].setNota(138);
    tecladoAntigo[9].setNota(147);
    tecladoAntigo[10].setNota(155);
    tecladoAntigo[11].setNota(165);
    tecladoAntigo[12].setNota(175);
    tecladoAntigo[13].setNota(185);
    tecladoAntigo[14].setNota(196);
    tecladoAntigo[15].setNota(208);
    tecladoAntigo[16].setNota(220);
    tecladoAntigo[17].setNota(233);
    tecladoAntigo[18].setNota(247);
    tecladoAntigo[19].setNota(262);
    tecladoAntigo[20].setNota(277);
    tecladoAntigo[21].setNota(294);
    tecladoAntigo[22].setNota(311);
    tecladoAntigo[23].setNota(330);
    tecladoAntigo[24].setNota(349);
    tecladoAntigo[25].setNota(370);
    tecladoAntigo[26].setNota(392);
    tecladoAntigo[27].setNota(415);
    tecladoAntigo[28].setNota(440);
    tecladoAntigo[29].setNota(466);
    tecladoAntigo[30].setNota(494);
    tecladoAntigo[31].setNota(523);

    for (byte i = 0; i < 32; i++)
    {
        tecladoNovo[i].setNota(tecladoAntigo[i].getNota());
        tecladoNovo[i].setPress(HIGH);
        tecladoNovo[i].setTecla(tecladoAntigo[i].getTecla());
        tecladoAntigo[i].setPress(HIGH);
    }
}

void Teclado::varreduraTeclado()
{
    byte indice = 0;

    for (byte i = 0; i < 4; i++)
    {
        digitalWrite(_linha[i], LOW);

        for (byte j = 0; j < 8; j++)
        {
            tecladoNovo[indice].setPress(digitalRead(_coluna[j]));

            if (tecladoNovo[indice].getPress() != tecladoAntigo[indice].getPress())
            {
                tecladoAntigo[indice].setPress(tecladoNovo[indice].getPress());

                if (tecladoAntigo[indice].getPress() == LOW)
                    tone(pino_som, tecladoAntigo[indice].getNota());
                else
                    noTone(pino_som);
            }

            indice++;
        }
        digitalWrite(_linha[i], HIGH);
    }
}