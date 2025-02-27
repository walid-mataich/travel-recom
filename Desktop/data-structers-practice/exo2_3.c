#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct assiette assiette;
struct assiette
{
    int code;
    char couleur[30];
    assiette *next;
};

typedef struct pile pile;
struct pile
{
   assiette *tete;
   pile *next;
};

typedef struct file file;
struct file
{
    pile *queue;
    pile * tete;
};


pile *initialiser_pile(){

    pile *p = malloc(sizeof(pile));
    p->tete = NULL;
    return p;
}

pile *empiler(pile *p,assiette *a){
    if (p->tete == NULL)
    {
        a->next = NULL;
        
    }

    else
    {
        a->next = p->tete;
        
    }

    p->tete = a;

    return p;
}

pile *depiler(pile *p){
    assiette *temp = p->tete;
    
    if(p->tete == NULL){
        printf("la pile est vide");
    }

    else
    {
        p->tete = p->tete->next;
        free(temp);
    }

    return p;
    
}



void afficher(assiette *top){
    
    if (top != NULL)
    {
        printf("\nassiette: \n");
        printf("code : %d\n",top->code);
        printf("couleur : %s\n",top->couleur);

        
    
        afficher(top->next);
    }
     
}



file *initialiser_file(){

    file *f = malloc(sizeof(file));
    f->queue = NULL;
    f->tete = NULL;

    return f;
}


file *enfiler(file *f,pile *p){
    if (f->queue == NULL)
    {
        f->queue = p;
        f->tete = p;
    }

    else{
       f->queue->next = p;
       f->queue = p;
        
    }
    p->next = NULL;
    return f;
}

file *defiler(file *f){

    if (f->queue == NULL)
    {
        printf("la file est vide");

    }
    else
    {
        pile *temp = f->tete;
        f->tete = temp->next;
        free(temp);
    }
    return f;
}

file *plonger(file *f){
    pile *temp = f->tete;
    if (temp == NULL)
    {
        printf("la file est vide");
    }

    else
    {
        if (temp->tete == NULL)
        {
            f->tete = temp->next;
            printf("on retire l'assiette de code %d et couleur %s",f->tete->tete->code,f->tete->tete->couleur);
            f->tete = depiler(f->tete);
            return f;

        }
        else
        {
            printf("on retire l'assiette de code %d et couleur %s",f->tete->tete->code,f->tete->tete->couleur);
            f->tete = depiler(f->tete);
            return f;
        }
        
    }
    
    /*else if (f->tete->tete == NULL)
    {
        printf("on retire l'assiette de code %d et couleur %s",temp->next->tete->code,temp->next->tete->couleur);
        temp->next = depiler(temp->next);
        return f;
    }
    
    else{
        printf("on retire l'assiette de code %d et couleur %s",f->tete->tete->code,f->tete->tete->couleur);
        f->tete = depiler(f->tete);
        return f;
    }
    */
}


void afficher_file(file *f){
    pile *temp = f->tete;

    if (f->tete == NULL)
    {
        printf("la fille est vide");
    }

    else{
        while (temp != NULL)
        {
            afficher(temp->tete);
            temp = temp->next;
        }
        
    }
}


int main(){



    file *f;
    pile *p;
    char cou[30];
    
    
    f = initialiser_file();
    

    int nf;
    int np;

    printf("entrer le nombre de pile d'assiette que vous vouller remplir : ");
    scanf("%d",&nf);

    for (int i = 0; i < nf; i++)
    {
        p = initialiser_pile();
        printf("combien d'assiette va etre ajoute ? : ");
        scanf("%d",&np);
        getchar();

        for (int i = 0; i < np; i++)
        {
            assiette *ass = malloc(sizeof(assiette));
            ass->next =NULL;    
            printf("assiette :\n ");

            printf("code : \n");
            scanf("%d",&ass->code);
            getchar();

            

            printf("coulleur : \n");

            fgets(cou,30,stdin);
            strcpy(ass->couleur,cou);

            p = empiler(p,ass);


        }

        f = enfiler(f,p);
        
    }


    afficher_file(f);


    f = plonger(f);
    f = plonger(f);
    f = plonger(f);
    f = plonger(f);
    f = plonger(f);
    
    afficher_file(f);
    


    return 0;
}