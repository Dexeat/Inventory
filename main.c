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

void affichage(objet liste[10]){

    printf("-------------------------------------------------------------------------------\nListe des objet!\n");
    for (int i = 0; i <  10 ; i++)
    {
        printf("L'objet : %s est en %d d'exmplaire(s) au prix de %d gold\n",liste[i].nom,liste[i].nombre,liste[i].prix);
    }
     printf("-------------------------------------------------------------------------------\n");
    

}

void achat(objet liste[10],objet inv[999],int gold){
    int objetn,number_of_item;
    printf("vous avez %d Gold !\nQuel objets voulez vous acheter ? et en quel quantiter ?\n",gold);
    scanf("%d",&objetn);
    scanf("%d",&number_of_item);

    if (gold>(liste[objetn].prix*number_of_item)/* argent > prix * quantiter */)
    {
        for (int i = 0; i < sizeof(inv); i++)
        {
            if (inv[i].nombre == 0)
            {
                inv[i] = liste[objetn];
                liste[objetn].nombre -= number_of_item;
                inv[i].nombre -= liste[objetn].nombre;
                gold -= liste[objetn].prix * number_of_item;
                return 0;
            }
            
        }
        
        /* 
            ajoute objet > inventaire 
            retir la quantiter d'objet
            retir les gold
        */
    }
    else
    {
        printf("pas assez de Gold ! :c\n");
    }
    
    
}

void inventaire(objet inv[999]){
    
        for (int i = 0; i <  10 ; i++){
            printf("L'objet : %s est en %d d'exmplaire(s)\n", inv[i].nom, inv[i].nombre);
        }
}

void create(objet liste[10]){
    char nomobjet;int prixobejt;
    printf("Pour crée votre objet renseignez un nom et sont prix\n");
    scanf("%s",&nomobjet);
    scanf("%d",&prixobejt);
    for (int i = 6; i < 10; i++)
    {
        if (liste[i].nombre == 0)
        {
            objet objetc = {nomobjet, 999, prixobejt};
            printf("L'objet : %s est en %d d'exmplaire(s) au prix de %d gold\n",nomobjet,999,prixobejt);
            liste[i] = objetc;
            return 0;
        }
        
    }
    


}

int menu(objet inv[999],objet liste[10],int * pointergold){
    int choix;
    printf("\nMenu: 1 Magasin, 2 Achat, 3 Inventaire, 4 Cree votre objet: ");
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
    if (choix == 4)
    {
        create(liste);
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
    
    objet liste_objet[10] = {carte,potion,pomme,epee,bouclier,talisment};
    objet inv[999];

    for (int i = 0; i < 999; i++)
    {
        inv[i].nombre = 0;
    }

    for (int i = 6; i < 10; i++)
    {
        liste_objet[i].nombre =0;
    }
    
    

    while (achat)
    {
        menu(inv,liste_objet,&gold);
    }
    

    return 0;
}