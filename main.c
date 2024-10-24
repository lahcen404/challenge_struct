#include <stdio.h>
#include <stdlib.h>
 //Strcuture Adresse
struct Adresse{
char rue[100];
char ville[30];
int code_postal;
};

//Strcuture Personne
struct Personne{

int nom[50];
int age;
 struct Adresse adresse; //Structure Imbriquer

};



void creer(struct Personne personne){
printf("Nom :");
scanf("%s",&personne.nom);
printf("Age :");
scanf("%d",&personne.age);
printf("Rue :");
scanf("%s",&personne.adresse.rue);
printf("Ville  :");
scanf("%s",&personne.adresse.ville);
printf("Code Postal :");
scanf("%d",&personne.adresse.code_postal);
}

void Afficher{
printf("Nom : %d",personne.nom);
printf("Age : %d",Personne.age);
printf("Rue : %d",Personne.adresse.rue);
printf("Ville : %d",Personne.adresse.ville);
printf("Code Postal : %d",Personne.adresse.code_postal);

}


int main()
{
    creer;
    Afficher;

    return 0;
}
