/**
 * @file eltType.h
 * @brief fichier d'entete pour la gestion du type des elements
 *        Ce module contient le type de donnees et les fonctions de gestion de piles/file
 *        L'utilisant du type 'eltType' permet aux piles/files de stocker des elements de different type
 */
#ifndef __ELTTYPE_H__
#define __ELTTYPE_H__

/* ------------------------- Type de donnees des elements de la pile/file  ------------------------- */
/**
 * @typedef eltType
 * @brief redefinir 'int' en 'eltType' (pour les elements de type 'int')
 */
typedef int eltType;


/**
 * @struct eltType
 * @brief Definir le type de donnees des elements (pour les elements de type struct)
 * 2 champs :
 *      - 'lettre' : un caractere
 *      - 'num' : un entier
 */
//typedef struct
//{
//    char lettre;
//    int num;
//} eltType;


/* ------------------------- Prototype des fonctions de gestion des elements  ------------------------- */
/**
 * @brief Ecrire une fonction de comparaison de 2 elements
 * @param [in] elt1 l'adresse du 1er element du type 'eltType'
 * @param [in] elt2 l'adresse du 2eme element du type 'eltType'
 * @return 1 si les 2 elements sont egaux; 0 s'ils sont differents
 */
int compareElt(const eltType *elt1, const eltType *elt2);

/**
 * @brief Copier la valeur d'un element dans un autre emplacement
 * @param [in] source l'adresse de l'element a copier
 * @param [in] destination l'adresse de la destination
 */
void copyElt(const eltType *source, eltType *destination);

#endif