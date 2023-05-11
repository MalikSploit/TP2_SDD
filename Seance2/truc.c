/**
 * @file truc.c
 * @brief fichier d'implementation du module de derecursification de la fonction truc (donne la liste de combinaisons de n elements)
 */
#include <stdio.h>
#include <stdlib.h> 

#include "../pile.h"

/**
 * @brief initialiser n caracteres dans un tableau de l'indice deb a l'indice fin
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in, out] T : un tableau de caracteres
 */
void initTab(int deb, int fin, char T[])
{
    int i;
    int compteur = 0;
    char valeur  = 'A';

    for (i = deb; i <= fin; i++)
    {
        T[i] = valeur + compteur;
        compteur++;
    }
}

/**
 * @brief afficher les caracteres d'un tableau de l'indice deb a l'indice fin a l'ecran
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in] T : un tableau de caracteres
*/
void printTab(int deb, int fin, char T[])
{
    int i;
    for (i = deb; i <= fin; i++)
    {
        printf("%c", T[i]);
    }
    printf("\n");
}

/**
 * @brief echanger les valeurs de 2 variables de type caractere
 * @param [in, out] a l'adresse de la 1ere variable 
 * @param [in, out] b l'adresse de la 2eme variable 
 */
void echangerChar(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief l'algorithme recursive
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n caractere de l'indice 1 a l'indice n 
 */
void truc_rec1(int i, int n, char T[])
{
    int j;
    if (i == n)
    {
        printTab(1, n, T);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            echangerChar(&T[i], &T[j]);
            truc_rec1(i+1, n, T);
            echangerChar(&T[i], &T[j]);
        }
    }
}

/**
 * @brief afficher les combinations d'un ensemble d'elements - version recursive 0
 * @param [in] i l'indice du 1er element (i=0 avec ce TP)
 * @param [in] n l'indice du dernier element
 * @param [in] T tableau de n+1 caracteres de l'indice 0 a l'indice n
 */
void truc_rec0(int i, int n, char T[])
{
    if (i == n)
    {
        printTab(1, n, T);
    }
    else
    {
        for (int j = i; j < n; j++)
        {
            echangerChar(&T[i], &T[j]);
            truc_rec0(i+1, n, T);
            echangerChar(&T[i], &T[j]);
        }
    }
}


/**
 * @brief l'algorithme iterative
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element
 * @param [in] T tableau de n+1 caracteres de l'indice 1 a l'indice n
 */
void truc_iter1(int i, int n, char *T)
{
    int     fin  = 0;
    int     j    = 1;
    int     code1 = 1;
    int     code2 = 1;
    pile_t  *pile   = initPile(PILE_SZ);


    while(!fin)
    {
        fin = 1;

        if (i == n)
        {
            printTab(1, n, T);

            if (!estVidePile(pile))
            {
                fin = 0;
                depiler(pile, &j, &code1);
                depiler(pile, &i, &code2);

                if (code1 || code2)
                {
                    printf("Erreur : Pile pleine\n");
                    exit(EXIT_FAILURE);
                }

                echangerChar(&T[i], &T[j]);
                j++;
            }
        }

        else
        {
            if (j <= n)
            {
                fin = 0;
                echangerChar(&T[i], &T[j]);

                empiler(pile, &i, &code1);
                empiler(pile, &j, &code2);

                if (code1 || code2)
                {
                    printf("Erreur : Pile pleine\n");
                    exit(EXIT_FAILURE);
                }

                i++;
                j = i;
            }

            else if (!estVidePile(pile))
            {
                fin = 0;
                depiler(pile, &j, &code1);
                depiler(pile, &i, &code2);

                if (code1 || code2)
                {
                    printf("Erreur : Pile pleine\n");
                    exit(EXIT_FAILURE);
                }
                echangerChar(&T[i], &T[j]);
                j++;
            }
        }
    }
    libererPile(&pile);
}