/* ==================================== Include    =================================== */
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

/* ==================================== Functions and procedures =================================== */

T_liste creer_liste(void)
{
    return NULL;
}

void ajout_entete_liste(T_liste *liste, int element)
{
    T_liste nouv = malloc(sizeof(struct maillon));
    if (nouv == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouv->val  = element;
    nouv->suiv = *liste;
    *liste     = nouv;
}


T_liste ajouter_entete_fonc(T_liste liste, int element)
{
    T_liste nouv = malloc(sizeof(struct maillon));
    if (nouv == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouv->val  = element;
    nouv->suiv = liste;
    return nouv;
}


void afficher_liste(T_liste liste)
{
    T_liste p = liste;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->suiv;
    }
    printf("\n");
}


void fafficher_dir_liste(T_liste liste)
{
    if (liste == NULL)
        return;
    printf("%d ", liste->val);
    fafficher_dir_liste(liste->suiv);
}


void fafficher_inv_liste(T_liste liste)
{
    if (liste == NULL)
        return;
    fafficher_inv_liste(liste->suiv);
    printf("%d ", liste->val);
}


void inv_mis_liste(T_liste *liste)
{
    T_liste prec = NULL;
    T_liste courant = *liste;
    T_liste suivant;

    while (courant != NULL) {
        suivant        = courant->suiv;
        courant->suiv  = prec;
        prec           = courant;
        courant        = suivant;
    }
    *liste = prec;
}


T_liste inv_fonc_liste(T_liste liste)
{
    T_liste res = NULL;
    T_liste p   = liste;

    while (p != NULL) {
        res = ajouter_entete_fonc(res, p->val);
        p = p->suiv;
    }
    return res;
}


int long_env(T_liste liste)
{
    if (liste == NULL)
        return 0;
    return 1 + long_env(liste->suiv);
}


int long_ter(T_liste liste, int aux)
{
    if (liste == NULL)
        return aux;
    return long_ter(liste->suiv, aux + 1);
}


T_liste inversion_rec_env(T_liste liste)
{
    if (liste == NULL)
        return NULL;

    T_liste reste_inverse = inversion_rec_env(liste->suiv);
    return ajouter_entete_fonc(reste_inverse, liste->val);
}


T_liste inversion_rec_term(T_liste liste, T_liste acc)
{
    if (liste == NULL)
        return acc;

    acc = ajouter_entete_fonc(acc, liste->val);
    return inversion_rec_term(liste->suiv, acc);
}


void liberer_liste(T_liste liste)
{
    T_liste p = liste;
    while (p != NULL) {
        T_liste tmp = p;
        p = p->suiv;
        free(tmp);
    }
}
