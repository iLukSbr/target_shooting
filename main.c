/*============================================================================*/
/* CSF13 - 2022-2 - TRABALHO 1                                                */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Teste automático para as funções pedidas para o 1o trabalho da disciplina
 * CSF13 (Fundamentos de Programação 1), 2022-2, Universidade Tecnológica
 * Federal do Paraná. */
/*============================================================================*/

#include <stdio.h>
#include <float.h>
#include <math.h>

#include "trabalho1.h"

/*============================================================================*/

#define ARQUIVO_TESTE_TINTA "teste_tinta1.txt" /* Arquivo contendo dados para teste. */
#define ARQUIVO_TESTE_CAMPOS "teste_campos0.txt" /* Arquivo contendo dados para teste. */

#define MAX_ALVOS 1000
#define MAX_DISPAROS 200

/*============================================================================*/

void testaTinta ()
{
    int n_testes, n_erros = 0; /* Número de testes, número total de erros. */
    int i, i_teste; /* Contadores de iterações, um genérico e um para o número de testes. */
    int n_alvos, n_disparos, n_acertos; /* Número de alvos, disparos e acertos lidos de um arquivo. */
    int erro_teste; /* Flag usada para verificar se UM teste apresentou erros. */
    int n_acertos_teste; /* Número de acertos retornado pela função do aluno. */
    FILE* in_file; /* Arquivo de entrada. */

    printf ("\n========================================\n");
    printf ("TINTA\n\n");
    inicializaBuffersInternos (MAX_ALVOS, MAX_DISPAROS);

    /* Abre o arquivo contendo os dados. */
    in_file = fopen (ARQUIVO_TESTE_TINTA, "r");
    if (!in_file)
        printf ("Nao foi possivel abrir o arquivo %s!\n", ARQUIVO_TESTE_TINTA);

    fscanf (in_file, "%d", &n_testes);

    /* Para cada teste... */
    for (i_teste = 0; i_teste < n_testes; i_teste++)
    {
        limpaBuffersInternos ();
        erro_teste = 0;

        /* Carrega a lista de alvos... */
        fscanf (in_file, "%d", &n_alvos);
        for (i = 0; i < n_alvos; i++)
        {
            float x, y, raio;
            fscanf (in_file, "%f%f%f", &x, &y, &raio);
            adicionaAlvo (x, y, raio);
        }

        /* Carrega a lista de disparos... */
        fscanf (in_file, "%d", &n_disparos);
        for (i = 0; i < n_disparos; i++)
        {
            float x, y, raio;
            fscanf (in_file, "%f%f%f", &x, &y, &raio);
            adicionaDisparo (x, y, raio);
        }

        /* Agora vai carregando os acertos e comparando com a função do aluno... */
        fscanf (in_file, "%d", &n_acertos);
        n_acertos_teste = testaDisparos ();
        if (n_acertos_teste != n_acertos)
        {
            erro_teste = 1;
            n_erros++;
            printf ("Erro no teste %d. Esperava %d acertos, calculou %d.\n", i_teste, n_acertos, n_acertos_teste);
        }

        for (i = 0; i < n_acertos; i++)
        {
            int tipo, disparo, alvo, tipo_teste, disparo_teste, alvo_teste;
            fscanf (in_file, "%d%d%d", &tipo, &disparo, &alvo);
            if (!erro_teste)
            {
                /* Só compara se o número de acertos for igual. (Não posso simplesmente pular tudo porque ainda preciso terminar de ler este teste). */
                pegaAcerto (i, &tipo_teste, &disparo_teste, &alvo_teste);
                if (tipo != tipo_teste || disparo != disparo_teste || alvo != alvo_teste)
                {
                    erro_teste = 1;
                    n_erros++;
                    printf ("Erro no teste %d. Acerto %d: esperava tipo %d, disparo %d, alvo %d; recebeu tipo %d, disparo %d, alvo %d.\n", i_teste, i, tipo, disparo, alvo, tipo_teste, disparo_teste, alvo_teste);
                }
            }
        }
    }

    if (!n_erros)
        printf ("%d testes realizados sem erro.\n", n_testes);
    else
        printf ("%d erros encontrados em %d testes.\n", n_erros, n_testes);

    fclose (in_file);

    finalizaBuffersInternos ();
}

/*============================================================================*/

void testaCampos ()
{
    int n_testes, n_erros = 0; /* Número de testes, número total de erros. */
    int i_teste; /* Contador de iterações. */
    FILE* in_file; /* Arquivo de entrada. */

    printf ("\n========================================\n");
    printf ("CAMPOS\n\n");

    /* Abre o arquivo contendo os dados. */
    in_file = fopen (ARQUIVO_TESTE_CAMPOS, "r");
    if (!in_file)
        printf ("Nao foi possivel abrir o arquivo %s!\n", ARQUIVO_TESTE_CAMPOS);

    fscanf (in_file, "%d", &n_testes);

    /* Para cada teste... */
    for (i_teste = 0; i_teste < n_testes; i_teste++)
    {
        unsigned short seq, esperado, obtido;
        int pos, n_bits;

        /* Carrega os parâmetros e o resultado esperado... */
        fscanf (in_file, "%hu", &seq);
        fscanf (in_file, "%d", &pos);
        fscanf (in_file, "%d", &n_bits);
        fscanf (in_file, "%hu", &esperado);

        /* Compara com o resultado obtido pelo aluno. */
        obtido = pegaCampo (seq, pos, n_bits);

        if (obtido != esperado)
        {
            n_erros++;
            printf ("Erro no teste %d.\nEsperava %X\nCalculou %X\nseq = %X, pos = %d, n_bits = %d\n", i_teste, esperado, obtido, seq, pos, n_bits);
        }
    }

    if (!n_erros)
        printf ("%d testes realizados sem erro.\n", n_testes);
    else
        printf ("%d erros encontrados em %d testes.\n", n_erros, n_testes);

    fclose (in_file);
}

/*============================================================================*/

int main()
{
    testaTinta ();
    testaCampos ();
    return 0;
}

/*============================================================================*/
