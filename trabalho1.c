/*============================================================================*/
/* CSF13 - 2022-2 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Funções pedidas e auxiliares para o 1o trabalho da disciplina CSF13
 * (Fundamentos de Programação 1), 2022-2, prof. Bogdan T. Nassu, Universidade
 * Tecnológica Federal do Paraná. */
/*============================================================================*/

#include <stdlib.h>

#include "trabalho1.h"

/*============================================================================*/
/* Tipos internos. */

typedef struct
{
    float x;
    float y;
    float raio;
} Circulo;

typedef struct
{
    unsigned int tipo;
    unsigned int disparo;
    unsigned int alvo;
} Acerto;

/* Estas variáveis são globais somente para isolar parte do trabalho dos alunos. */
int n_alvos;
Circulo* alvos;
int n_disparos;
Circulo* disparos;
int n_acertos;
Acerto* acertos;

/*----------------------------------------------------------------------------*/
/** Funções para manipular os dados sobre alvos, disparos e acertos. Tudo muito simples e sem testes adicionais.*/

void inicializaBuffersInternos (int max_alvos, int max_disparos)
{
    n_alvos = 0;
    alvos = (Circulo*) malloc (sizeof (Circulo) * max_alvos);
    n_disparos = 0;
    disparos = (Circulo*) malloc (sizeof (Circulo) * max_disparos);
    n_acertos = 0;
    acertos = (Acerto*) malloc (sizeof (Acerto) * max_alvos * max_disparos);
}

void finalizaBuffersInternos ()
{
    free (alvos);
    free (disparos);
    free (acertos);
}

void limpaBuffersInternos ()
{
    n_alvos = 0;
    n_disparos = 0;
    n_acertos = 0;
}

void adicionaAlvo (float x, float y, float raio)
{
    alvos [n_alvos].x = x;
    alvos [n_alvos].y = y;
    alvos [n_alvos].raio = raio;
    n_alvos++;
}

void adicionaDisparo (float x, float y, float raio)
{
    disparos [n_disparos].x = x;
    disparos [n_disparos].y = y;
    disparos [n_disparos].raio = raio;
    n_disparos++;
}

void pegaAcerto (int acerto, int* tipo, int* disparo, int* alvo)
{
    *tipo = acertos [acerto].tipo;
    *disparo = acertos [acerto].disparo;
    *alvo = acertos [acerto].alvo;
}

/*----------------------------------------------------------------------------*/

unsigned int pegaNAlvos ()
{
    return (n_alvos);
}

float pegaXAlvo (unsigned int alvo)
{
    return (alvos [alvo].x);
}

float pegaYAlvo (unsigned int alvo)
{
    return (alvos [alvo].y);
}

float pegaRaioAlvo (unsigned int alvo)
{
    return (alvos [alvo].raio);
}

unsigned int pegaNDisparos ()
{
    return (n_disparos);
}

float pegaXDisparo (unsigned int disparo)
{
    return (disparos [disparo].x);
}

float pegaYDisparo (unsigned int disparo)
{
    return (disparos [disparo].y);
}

float pegaRaioDisparo (unsigned int disparo)
{
    return (disparos [disparo].raio);
}

void registraAcerto (int tipo, int disparo, int alvo)
{
    acertos [n_acertos].tipo = tipo;
    acertos [n_acertos].disparo = disparo;
    acertos [n_acertos].alvo = alvo;
    n_acertos++;
}

/*============================================================================*/
