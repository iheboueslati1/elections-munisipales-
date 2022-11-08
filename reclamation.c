#include "reclamation.h"

int ajouter(char * filename, reclamation r )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s %s %s \n",r.id,r.num_bv,r.type_reclamation,r.text_reclamation,r.liste_electoral);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, reclamation nouv )
{
    int tr=0;
    reclamation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s \n",&r.id,&r.num_bv,r.type_reclamation,r.text_reclamation,r.liste_electoral)!=EOF)
        {
            if(r.id== id)
            {
                fprintf(f2,"%d %d %s %s %s \n",nouv.id,nouv.num_bv,nouv.type_reclamation,nouv.text_reclamation,nouv.liste_electoral);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %s %s \n",r.id,r.num_bv,r.type_reclamation,r.text_reclamation,r.liste_electoral);

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
    reclamation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %s \n",&r.id,&r.num_bv,r.type_reclamation,r.text_reclamation,r.liste_electoral)!=EOF)
        {
            if(r.id== id)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %s \n",r.id,r.num_bv,r.type_reclamation,r.text_reclamation,r.liste_electoral);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

