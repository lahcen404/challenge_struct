#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char rue[100];
    char ville[30];
    int code_postal;
} Adresse;

typedef struct {
    char nom[50];
    int age;
    Adresse adresse;
} Personne;

void creer(Personne *personne) {
    printf("Nom : ");
    scanf("%s", personne->nom);
    printf("Age : ");
    scanf("%d", &personne->age);
    printf("Rue : ");
    scanf("%s", personne->adresse.rue);
    printf("Ville : ");
    scanf("%s", personne->adresse.ville);
    printf("Code Postal : ");
    scanf("%d", &personne->adresse.code_postal);
}

void Afficher(Personne personne) {
    printf("Nom : %s \n", personne.nom);
    printf("Age : %d \n", personne.age);
    printf("Rue : %s \n", personne.adresse.rue);
    printf("Ville : %s \n", personne.adresse.ville);
    printf("Code Postal : %d \n", personne.adresse.code_postal);
}

void Supprimer(Personne personne[], int indice, int *nbrper) {
    for (int i = indice; i < *nbrper - 1; i++) {
        personne[i] = personne[i + 1];
    }
    (*nbrper)--;
}


void Modifier(Personne *personne) {
    int choix;

    do {
        printf("Que voulez vous modifier?\n");
        printf("1- Nom\n");
        printf("2- Age\n");
        printf("3- Rue\n");
        printf("4- Ville\n");
        printf("5- Code Postal\n");
        printf("6- Terminer la modification\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Nouveau nom: ");
                scanf("%s", personne->nom);
                break;
            case 2:
                printf("Nouvel age: ");
                scanf("%d", &personne->age);
                break;
            case 3:
                printf("Nouvelle rue: ");
                scanf("%s", personne->adresse.rue);
                break;
            case 4:
                printf("Nouvelle ville: ");
                scanf("%s", personne->adresse.ville);
                break;
            case 5:
                printf("Nouveau code postal: ");
                scanf("%d", &personne->adresse.code_postal);
                break;
            case 6:
                printf("Modification terminee.\n");
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 6);
}

int main() {
    Personne p1[50];
    int doo;
    int i;
    int nbrper = 0;

    do {
        printf("what do you want to do?:\n");
        printf("1- Ajouter \n");
        printf("2- Afficher \n");
        printf("3- Modifier \n");
        printf("4-Supprimer \n");
        printf("5-Quitter \n");
        scanf("%d", &doo);

        switch (doo) {
            case 1:
                if (nbrper < 50) {
                    creer(&p1[nbrper]);
                    nbrper++;
                }
                break;

            case 2:
                if (nbrper == 0) {
                    printf("Aucun \n");
                } else {
                    for (i = 0; i < nbrper; i++) {
                        printf("-------------Information %d ------------\n", i + 1);
                        Afficher(p1[i]);
                    }
                }
                break;

            case 3:
               if (nbrper == 0) {
                    printf("Aucune personne enregistree\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la personne a modifier (1 To %d) : ", nbrper);
                    scanf("%d", &indice);
                    if (indice >= 1 && indice <= nbrper) {
                        Modifier(&p1[indice-1]);
                        printf("Personne Modifier.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 4:
                if (nbrper == 0) {
                    printf("Aucune personne enregistree\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la personne a supprimer (1 To %d) : ", nbrper);
                    scanf("%d", &indice);
                    if (indice >= 1 && indice <= nbrper) {
                        Supprimer(p1, indice - 1, &nbrper);
                        printf("Personne supprimee.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;
            case 5:
                printf("Bye!!");
        }
    } while (doo != 5);

    return 0;
}
