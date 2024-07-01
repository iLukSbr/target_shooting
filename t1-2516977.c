/* Aluno: Lucas Yukio Fukuda Matsumoto - Matricula: 2516977                                     */
/*============================================================================*/
/* CSF13 - 2022-2 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/* Funcoes pedidas para o 1o trabalho da disciplina CSF13                     */
/* (Fundamentos de Programacao 1), 2022-2, prof. Bogdan T. Nassu, Universidade*/
/* Tecnologica Federal do Parana.                                             */
/*============================================================================*/

#include <math.h>

#include "trabalho1.h"

unsigned int testaDisparo (int disparo, float x, float y, float raio)
{
    unsigned int alvo, n_alvos, n_atingidos=0;
    float x_alvo, y_alvo, raio_alvo, distancia;
    n_alvos = pegaNAlvos();// total de M alvos, identificados de 0 a M-1
    for(alvo=0; alvo<n_alvos; alvo++)// analise do que ocorreu com cada alvo "alvo", do 0 ao M-1, para o disparo "disparo"
    {
        x_alvo = pegaXAlvo(alvo);
        y_alvo = pegaYAlvo(alvo);
        raio_alvo = pegaRaioAlvo(alvo);
        distancia = sqrtf((x-x_alvo)*(x-x_alvo) + (y-y_alvo)*(y-y_alvo));// distancia linear entre o centro do alvo e o centro do disparo
        if(distancia <= raio+raio_alvo)// se a distancia medir ate alvo e disparo ficarem lado a lado com pelo menos apenas um ponto sobreposto nas bordas ou se coincidirem em mais do que isso
        {
            n_atingidos++;// armazena que atingiu o alvo e prossegue para registrar qual tipo de acerto
            if(distancia+raio <= raio_alvo)// se o disparo ficar totalmente dentro do alvo
                registraAcerto(DISPARO_COBERTO, disparo, alvo);
            else if(distancia+raio_alvo <= raio)// se o alvo ficar totalmente dentro do disparo
                registraAcerto(ALVO_COBERTO, disparo, alvo);
            else// se nao foram os casos anteriores
                registraAcerto(ACERTO_COMUM, disparo, alvo);
        }
    }
    return n_atingidos;// retorna o total de alvos atingidos para o disparo "disparo"
}

unsigned int testaDisparos ()
{
    unsigned int disparo, n_disparos, total_acertos=0;
    n_disparos = pegaNDisparos();// total de N disparos, identificados de 0 a N-1
    for(disparo=0; disparo<n_disparos; disparo++)// quantos alvos foram atingidos por cada disparo "disparo", do 0 ao N-1, adicionando ao total de acertos
        total_acertos += testaDisparo(disparo, pegaXDisparo(disparo), pegaYDisparo(disparo), pegaRaioDisparo(disparo));
    return total_acertos;// retorna o total de alvos atingidos somando os de todos os disparos
}

unsigned short pegaCampo (unsigned short seq, int pos, int nbits)
{
    unsigned short copia_seq, pot2, decimal=0;
    int i, bits_seq, exp;
    bits_seq = 8*sizeof(unsigned short);// quantidade de bits de toda a sequancia
    for(i=nbits; i>=1; i--)// analise de cada bit "i" do campo desejado, enumerados em ordem decrescente da esquerda para a direita, de "nbits" a 1
    {
        pot2 = 1;// potencia de 2 elevado a 0 da conversao de binario para decimal
        copia_seq = seq;// copia toda a sequancia de bits
        copia_seq <<= pos + nbits - i;// elimina todos os bits a esquerda do bit "i"
        copia_seq >>= bits_seq - 1;// elimina todos os bits a direita do bit "i"
        if(copia_seq)// se o bit "i" nao for 0, entra na conversao de binario para decimal
        {
            for(exp=1; exp<i; exp++)// exp = expoente, com o valor maximo atingido de acordo com a posicao do bit "i"-1
                pot2 *= 2;// multiplica por 2 ate "pot2" ser equivalente a potencia de 2 elevado ao expoente "i"-1
            decimal += pot2;// soma o valor da potencia de 2 do bit "i" ao total da conversao de binario para decimal
        }
    }
    return decimal;// retorna o valor do campo em decimal
}
