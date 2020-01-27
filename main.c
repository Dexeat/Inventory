#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Items
{
    char nom[40];
    int nombre;
    int prix;
};


typedef struct Items objet;

void affichage(objet liste[6]){

    printf("-------------------------------------------------------------------------------\nListe des objet!\n");
    for (int i = 0; i <  sizeof(liste) ; i++)
    {
        printf("L'objet : %s est en %d d'exmplaire(s) au prix de %d gold\n",liste[i].nom,liste[i].nombre,liste[i].prix);
    }
     printf("-------------------------------------------------------------------------------\n");
    

}


int main(void){
    //liste d'objet
    int nb_base = 999;
    

    objet carte = {"carte",nb_base,10};
    objet potion = {"potion",nb_base,50};
    objet pomme = {"pomme",50,5};
    objet epee = {"epee",1,500};
    objet bouclier = {"bouclier",1,500};
    objet talisment = {"talisment",1,6000};
    
    objet liste_objet[6] = {carte,potion,pomme,epee,bouclier,talisment};

    affichage(liste_objet);

    return 0;
}