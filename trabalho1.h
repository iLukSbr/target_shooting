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

#ifndef __TRABALHO1_H
#define __TRABALHO1_H

/*============================================================================*/
/* Constantes */

#define ACERTO_COMUM 1
#define ALVO_COBERTO 2
#define DISPARO_COBERTO 3

/*============================================================================*/
/* Funções do trabalho. */

unsigned int testaDisparo (int disparo, float x, float y, float raio);
unsigned int testaDisparos ();
unsigned short pegaCampo (unsigned short seq, int pos, int nbits);

/*----------------------------------------------------------------------------*/
/* Funções auxiliares que DEVEM ser chamadas pelos alunos. */

unsigned int pegaNAlvos ();
float pegaXAlvo (unsigned int alvo);
float pegaYAlvo (unsigned int alvo);
float pegaRaioAlvo (unsigned int alvo);

unsigned int pegaNDisparos ();
float pegaXDisparo (unsigned int disparo);
float pegaYDisparo (unsigned int disparo);
float pegaRaioDisparo (unsigned int disparo);

void registraAcerto (int tipo, int disparo, int alvo);

/*----------------------------------------------------------------------------*/
/* Funções auxiliares que NÃO DEVEM ser chamadas pelos alunos. */

void inicializaBuffersInternos (int max_alvos, int max_disparos);
void finalizaBuffersInternos ();
void limpaBuffersInternos ();
void adicionaAlvo (float x, float y, float raio);
void adicionaDisparo (float x, float y, float raio);
void pegaAcerto (int acerto, int* tipo, int* disparo, int* alvo);

/*============================================================================*/
#endif /* __TRABALHO1_H */
