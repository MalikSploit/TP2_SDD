/**
 * @file truc.h
 * @brief fichier d'entete du module de derecursification de la fonction truc (donne la liste de combinaisons de n elements)
 */
#ifndef __TRUC_H__
#define __TRUC_H__


/**
 * @brief initialiser n caracteres dans un tableau de l'indice deb a l'indice fin
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in, out] T : un tableau de caracteres
 */
void initTab(int deb, int fin, char T[]);

/**
 * @brief afficher les caracteres d'un tableau de l'indice deb a l'indice fin
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in] T : un tableau de caracteres
*/
void printTab(int deb, int fin, char T[]);

/**
 * @brief echanger les valeurs de 2 variables de type caractere
 * @param [in, out] a l'adresse de la 1ere variable 
 * @param [in, out] b l'adresse de la 2eme variable 
 */
void echangerChar(char* a, char* b);

/**
 * @brief afficher les combinations d'un ensemble d'elements - version recursive 1
 *        cette fonction permet de garder l'algo. de l'enonce du TP sans modification
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n caractere de l'indice 1 a l'indice n 
 */
void truc_rec1(int i, int n, char T[]);

/** TO DO
 * @brief afficher les combinations d'un ensemble d'elements - version recursive 0
 * @param [in] i l'indice du 1er element (i=0 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n+1 caracteres de l'indice 0 a l'indice n 
 */
void truc_rec0(int i, int n, char T[]);

/** TO DO
 * @brief afficher les combinations d'un ensemble d'elements - version iterative
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n+1 caracteres de l'indice 0 a l'indice n 
 */
void truc_iter1(int i, int n, char T[]);

#endif