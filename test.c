#include <stdio.h>
#include "liste.h"

int main(void)
{
    T_liste l = creer_liste();

    ajout_entete_liste(&l, 3);
    ajout_entete_liste(&l, 2);
    ajout_entete_liste(&l, 1);

    printf("Liste (iteratif) : ");
    afficher_liste(l);

    printf("Affichage direct recursif : ");
    fafficher_dir_liste(l);
    printf("\n");

    printf("Affichage inverse recursif : ");
    fafficher_inv_liste(l);
    printf("\n");

    printf("Longueur (env) : %d\n", long_env(l));
    printf("Longueur (ter) : %d\n", long_ter(l, 0));

    T_liste l_inv_f = inv_fonc_liste(l);
    printf("Inverse fonctionnelle (iteratif) : ");
    afficher_liste(l_inv_f);

    inv_mis_liste(&l);
    printf("Inverse MIS : ");
    afficher_liste(l);

    T_liste l_rec_env = inversion_rec_env(l_inv_f);
    printf("Inverse rec env : ");
    afficher_liste(l_rec_env);
    
    T_liste l_rec_term = inversion_rec_term(l_inv_f, NULL);
    printf("Inverse rec term : ");
    afficher_liste(l_rec_term);
    
    liberer_liste(l);
    liberer_liste(l_inv_f);
    liberer_liste(l_rec_env);
    liberer_liste(l_rec_term);
    return 0;
}