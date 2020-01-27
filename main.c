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

void achat(objet liste[6],objet inv[999],int pointergold){
    printf("vous avez %d Gold !\nQuel objets voulez vous acheter ? et en quel quantiter ?\n",pointergold);
}

void inventaire(objet inv[999]){}


int menu(objet inv[999],objet liste[6],int * pointergold){
    int choix;
    printf("\nMenu: 1 Magasin, 2 Achat, 3 Inventaire: ");
    scanf("%d",&choix);
    printf("\n");

    if (choix == 1)
    {
        affichage(liste);
    }
    
    if (choix == 2)
    {
        achat(liste,inv,*pointergold);
    }
    if (choix == 3)
    {
        inventaire(inv);
    }
    
}




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
    objet inv[999];


    while (achat)
    {
        menu(inv,liste_objet,&gold);
    }
    

    return 0;
}