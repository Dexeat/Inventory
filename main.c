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
typedef struct Items inventory;

void affichage(objet liste[6]){

    printf("-------------------------------------------------------------------------------\nListe des objet!\n");
    for (int i = 0; i <  sizeof(liste) ; i++)
    {
        printf("L'objet : %s est en %d d'exmplaire(s) au prix de %d gold\n",liste[i].nom,liste[i].nombre,liste[i].prix);
    }
     printf("-------------------------------------------------------------------------------\n");
    

}

int menu(int choix,inventory inv[999],objet liste[6],int*gold){
    if (choix == 1)
    {
        affichage(liste);
    }
    
    if (choix == 2)
    {
        achat(*gold,liste,inv);
    }
    if (choix == 3)
    {
        inventaire(inv);
    }
    
}

void achat(int *gold,objet liste[6],inventory inv[999]){}

void inventaire(inventory inv[999]){}


int main(void){
    //liste d'objet
    int achat = 1;
    int nb_base = 999;
    int gold = 100000000;
    int choix;
    

    objet carte = {"carte",nb_base,10};
    objet potion = {"potion",nb_base,50};
    objet pomme = {"pomme",50,5};
    objet epee = {"epee",1,500};
    objet bouclier = {"bouclier",1,500};
    objet talisment = {"talisment",1,6000};
    
    objet liste_objet[6] = {carte,potion,pomme,epee,bouclier,talisment};
    inventory inv[999];


    while (achat)
    {
        printf("Menu: 1 Magasin, 2 Achat, 3 Inventaire ");
        scanf("%d\n",&choix);
        menu(choix,inv,liste_objet,gold);
    }
    

    return 0;
}