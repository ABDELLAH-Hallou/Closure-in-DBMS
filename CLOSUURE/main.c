#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char PD[30];
    char PG[30];

} DFs;

int main()
{

    char  *TT,T[30],t[30], All_Attr[5000],Ferm[3000],cle[30],Relation[30];

    int s,i=0,a=0,nbDF=0,f=0,x=0,y=0,j;

    DFs DF[20];


    printf (" \tENTER THE ATTRIBUTES : \n" );
    do {
        do {
            for(i=0; i<strlen(t); i++)
                t[i]=NULL;
            strcpy(t," ");
            scanf("%s",T);
            strcat(T," ");
            strcat(t,T);


            if(strstr(All_Attr,t)!=NULL) {
                printf("\t!!! THIS ATTRIBUTES ALREADY EXIST IN THIS RELATION !!! \n");
            }

        } while(strstr(All_Attr,t)!=NULL);
        if((strcmp(t," 0 "))==0)
            break;

        strcat(All_Attr,t);
        strcat(All_Attr,",");
        x++;
    } while(1);


    printf("\n\n\tENTER YOUR FUNCTIONAL DEPENDENCES :\n ");

    i=0;
    do {

        do {
            printf("\nENTER LEFT :");
            for(j=0; j<strlen(t); j++)
                t[j]=NULL;
            strcpy(t," ");
            scanf("%s",T);
            strcat(T," ");
            strcat(t,T);
            if((strcmp(t," 00 "))==0)
                break;
            if((strcmp(t," -> "))==0  ) {
                break;
            }
            if(strstr(All_Attr,t)==NULL)
                printf("!! ATTENTION !! THIS ATTRIBUTES DOES NOT EXIST IN THIS RELATION !! TRY AGAIN!!\n");
            else {

                strcat(DF[i].PG,t);
                strcat(DF[i].PG,",");
            }
        } while(1);

        if((strcmp(t," 00 "))==0)
            break;
        do {
            printf("\nENTER RIGHT :");
            for(j=0; j<strlen(t); j++)
                t[j]=NULL;
            strcpy(t," ");
            scanf("%s",T);
            strcat(T," ");
            strcat(t,T);
            if((strcmp(t," 00 "))==0) {
                nbDF++;
                break;

            }
            if((strcmp(t," 0 "))==0) {
                nbDF++;
                break;

            }
            if(strstr(All_Attr,t)==NULL)
                printf("!! ATTENTION !! THIS ATTRIBUTES DOES NOT EXIST IN THIS RELATION !! TRY AGAIN!!\n");
            else {

                strcat(DF[i].PD,t);
                strcat(DF[i].PD,",");

            }
        } while(1);
        if((strcmp(t," 00 "))==0)
            break;
        i++;

    } while(1);

    printf("\n\n\t YOUR FUNCTIONAL DEPENDENCES ARE:\n ");
    for(i=0; i<nbDF; i++) {
        printf("\t  %s --> %s \n",DF[i].PG,DF[i].PD);
    }

    printf("\t\nENTER THE KEY THAT YOU WANNA TEST : \n");

    do {
            taha:
        for(j=0; j<strlen(t); j++)
            t[j]=NULL;
        strcpy(t," ");

        scanf("%s",T);

        strcat(T," ");
        strcat(t,T);

        if((strcmp(t," 0 "))==0)
            break;


        if(strstr(All_Attr,t)==NULL)
                printf("!! ATTENTION !! THIS ATTRIBUTES DOES NOT EXIST IN THIS RELATION !! TRY AGAIN!!\n");
        else {


            strcat(Ferm,t);

            strcat(cle,t);

            strcat(Ferm,",");

            y++;
        }
    } while(1);

if(strlen(Ferm)==0){
    printf("\t!!! ERROR !!!\n");
    goto taha;
}
    do {


        s=a;
        for(i=0; i<nbDF; i++) {
            f=0;
            TT=strtok(DF[i].PG,",");
            if(strstr(Ferm,TT)==NULL)
                f=50;
            else {

                do {
                    TT=strtok(NULL,",");
                    if(TT==NULL)
                        break;
                    if(strstr(Ferm,TT)==NULL)
                        f=50;
                } while(1);
            }

            if(f==0) {
                TT=strtok(DF[i].PD,",");

                if(strstr(Ferm,TT)==NULL) {

                    strcat(Ferm,TT);
                    strcat(Ferm,",");
                    a++;
                    y++;
                }
                do {
                    TT=strtok(NULL,",");

                    if(TT==NULL)
                        break;

                   if(strstr(Ferm,TT)==NULL) {
                        strcat(Ferm," ");
                        strcat(Ferm,TT);
                        strcat(Ferm,",");

                        a++;
                        y++;
                    }
                } while(1);
            }
        }
        if(s==a)
            break;
    } while(1);
    Ferm[strlen(Ferm)-1]='}';

    printf("\t\tTHE CLOSURE IS  : { %s \n\n",Ferm);

    (x==y)? printf("\t\tSO (%s) IS A BEAUTIFUL KEY\n\n",cle) : printf("\t\tSO (%s) IS NOT A KEY\n\n",cle);

    return 0;
}



