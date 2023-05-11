/**
 * @file file.c
 * @brief fichier d'implementation pour la gestion de file
 */
#include <stdlib.h>
#include "file.h"
#include <stdio.h>

/**
 * @brief Initialiser une file du type eltType
 *   - allocation de memoire pour une structure file_t et un tableau de taille elements
 * @param [in] taille taille de la file
 * @return l'adresse de la structure file_t
 */
file_t* initFile(int taille)
{
    file_t *file = NULL;
    if (taille > 0)
    {
        file = (file_t*) malloc(sizeof(file_t));
        file->taille = taille;
        file->nbElts = 0;
        file->base   = (eltType *) malloc(sizeof(int) * taille);
        file->deb    = file->base;
        file->fin    = file->base + taille - 1;
    }
    return file;
}


/**
 * @brief Verifier si la file est vide (aucun element dans la file)
 * @param [in] ptFile l'adresse de la structure file_t
 * @return 1 - vide, ou 0 - non vide
 */
int estVideFile(file_t* ptFile)
{
    return ptFile->nbElts == 0;
}


/**
 * @brief Verifier si la file est pleine
 * @param [in] ptFile l'adresse de la structure file_t
 * @return 1 - pleine, ou 0 - pas pleine
 */
int estPleineFile(file_t *ptFile)
{
    return (ptFile->nbElts == ptFile->taille);
}


/**
 * @brief Liberer les memoires occupees par la file
 * @param [in, out] adrPtFile l'adresse du pointeur de la structure file_t
 */
void libererFile(file_t **adrPtFile)
{
    if (*adrPtFile != NULL)
    {
        // libérer le tableau d'éléments de la file
        free((*adrPtFile)->base);
        // libérer la structure de la file
        free(*adrPtFile);
        // pointer le pointeur vers NULL pour éviter un usage après libération
        *adrPtFile = NULL;
    }
}


/**
 * @brief Entrer un element dans la file
 * @param [in] ptFile le pointeur de tete de la file
 * @param [in] ptVal l'adresse de la valeur a empiler
 * @param [out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void entrerFile(file_t *ptFile, eltType *ptVal, int *code)
{
    // File pleine : impossible d'ajouter un element
    if (estPleineFile(ptFile))
    {
        *code = 1;
    }
    else
    {
        if (!estVideFile(ptFile))
        {
            ptFile->fin++;
        }
        // Ajout de l'element dans la file
        ptFile->fin = ptFile->base + ptFile->nbElts;
        *ptFile->fin = *ptVal;

        // Incrementation du nombre d'elements dans la file
        ptFile->nbElts++;

        // Ajout reussi
        *code = 0;
    }
}


/**
 * @brief Sortir un element de la file
 * @param [in] ptFile le pointeur de tete d'une file
 * @param [out] ptRes l'adresse de l'element sorti
 * @param [out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void sortirFile(file_t* ptFile, eltType* ptRes, int* code)
{
    if (estVideFile(ptFile))
    {
        // erreur : file vide
        *code = 1;
    }
    else
    {
        // succès
        *ptRes = *ptFile->deb;

        // Déplacement du pointeur deb
        ptFile->deb++;

        // Retour au début de la file si nécessaire
        if (ptFile->deb == ptFile->base + ptFile->taille)
        {
            ptFile->deb = ptFile->base;
        }

        ptFile->nbElts--;

        // Déplacement du pointeur fin si la file était vide
        if (estVideFile(ptFile))
        {
            ptFile->fin = ptFile->base;
        }

        // succès
        *code = 0;
    }
}