
#include "utilisateur.h"
#include  <stdio.h>
int ajouter(char * filename, utilisateur u)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    { fprintf(f,"%s %s %d %d %d %d %d %d %d %d %d %d",u.nom,u.prenom,u.sexe,u.role,u.nationalite,u.id,u.d.j,u.d.m,u.d.a,u.idbur,u.vote,u.apr);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, utilisateur nouv )
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d%d",u.nom,u.prenom,&u.sexe,&u.role,&u.nationalite,&u.id,&u.d.j,&u.d.m,&u.d.a,&u.idbur,&u.vote,&u.apr)!=EOF)
        {
            if(u.id== id)
            {
                fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d%d",nouv.nom,nouv.prenom,nouv.sexe,nouv.role,nouv.nationalite,nouv.id,nouv.d.j,nouv.d.m,nouv.d.a,nouv.idbur,nouv.vote,nouv.apr);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d%d",u.nom,u.prenom,u.sexe,u.role,u.nationalite,u.id,u.d.j,u.d.m,u.d.a,u.idbur,u.vote,u.apr);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
int supprimer(char * filename, int id)
{
    int tr=0;
    utilisateur u ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d%d",u.nom,u.prenom,&u.sexe,&u.role,&u.nationalite,&u.id,&u.d.j,&u.d.m,&u.d.a,&u.idbur,&u.vote,&u.apr)!=EOF)
        {
            if(u.id== id)
                tr=1;
            else
            fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d%d",u.nom,u.prenom,u.sexe,u.role,u.nationalite,u.id,u.d.j,u.d.m,u.d.a,u.idbur,u.vote,u.apr);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercher(char * filename, int id)
{
    utilisateur u ;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d%d",u.nom,u.prenom,&u.sexe,&u.role,&u.nationalite,&u.id,&u.d.j,&u.d.m,&u.d.a,&u.idbur,&u.vote,&u.apr)!=EOF)
        {
            if(u.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.id=-1;
    return u ;
}
