//
// Created by valen on 05-Jan-22.
//
#include "main.h"

void insert_pols_ordered(LIST_POL *pl, char polname[], char description[], char activity[]){
    CITY_POL *cp = (CITY_POL *) malloc(sizeof(CITY_POL));
    strcpy(cp->polname, polname);
    strcpy(cp->description, description);
    strcpy(cp->activity, activity);
    cp->pnext = NULL;
    //.............FIRST........
    if (pl->npols == 0 || pl->ppol == NULL) {
        pl->ppol = cp;
        pl->npols++;
        return;
    }
    //...................................HEAD INSERTION........
    //Looking for the next head
    CITY_POL *pcurrent = pl->ppol;
    CITY_POL *pprev= NULL;
    while (pcurrent != NULL) {
        pprev = pcurrent;
        pcurrent = pcurrent->pnext;
    }
    //Insertion at the head found previously
    if (pcurrent == pl->ppol) {
        cp->pnext = pl->ppol;
        pl->ppol = cp;
        pl->npols++;
        return;
    }
    //...................................TAIL INSERTION.............
    if (pcurrent == NULL){
        pprev->pnext = cp;
        cp->pnext= NULL;
        pl->npols++;
        return;
    }
    //Middle insertion
    else {
        cp->pnext = pcurrent;
        pprev->pnext = cp;
        pl->npols++;
        return;
    }
}

void printcitypols(CITY_POL * node)
{
    CITY_POL * temp = node;
    while (node != NULL) {
        printf("Point of interest name: %s\n", node->polname);
        printf("Description:  %s\n",node->description);
        node = node->pnext;
    }
}

//Does not work
void deletecitypol(CITY_POL * pol, int position)
{
    // If the pol node is empty
    if (pol == NULL)
        return;

    // Store head node
    CITY_POL * temp = pol;

    // If head needs to be removed
    if (position == 0) {
        pol = temp->pnext; // Change head
        free(temp); // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->pnext;

    // If position is more than number of nodes
    if (temp == NULL || temp->pnext == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    CITY_POL * next = temp->pnext;

    // Unlink the node from linked list
    free(temp->pnext); // Free memory

    temp->pnext = next; // Unlink the deleted node from list
}

//Does not work, file error
void write_in_file_pol(LIST_POL * lp, char fn[]){
    FILE *fptr;
    CITY_POL * cp = lp->ppol;
    fptr = (fopen("C:\\citypol.txt", "w"));

    if(fptr==NULL){
        printf("ERROR...%s\n", fn);
        return;
    }

    fprintf(fptr, "Number of pols: %d", lp->npols);

    for(int i=0; i<lp->npols; i++) {
        fprintf(fptr, "Point of interest: %s\n", cp->polname);
        fprintf(fptr, "Description: %s", cp->description);
        fprintf(fptr, "Activity: %s", cp->activity);
        cp++;
    }
    fclose(fptr);
}

//Does not work, file error
void read_from_file_pol(LIST_POL * lp, char filename[]){
    FILE *fptr;
    CITY_POL * cp = lp->ppol;

    fptr = (fopen("C:\\citypol.txt", "r"));
    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    int polsnumber = 0;

    fscanf(fptr, "%*s%d", &polsnumber);

    char polname[25];
    char description[250];
    char activity[25];

    for(int i=0; i<polsnumber; i++) {
        fscanf(fptr, "%*s%s, %*s%s, %*s%s", polname, description, activity);
        insert_pols_ordered(&(*lp), polname, description, activity);
        cp->pnext++;
    }
    fclose(fptr);
}

//Does not work, file error
void write_in_file_pol_binary(LIST_POL * lp, char fn[]){
    FILE *fptr;
    CITY_POL * cp = lp->ppol;
    fptr = (fopen("C:\\polbinary.txt", "bw"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    fwrite(&lp->npols, sizeof(int), 1, fptr);

    int sizename = strlen(cp->polname + 1);
    fwrite(&sizename, sizeof(int), 1, fptr);

    int sizedescription= strlen(cp->description+ 1);
    fwrite(&sizedescription, sizeof(int), 1, fptr);

    int sizeactivity = strlen(cp->activity + 1);
    fwrite(&sizeactivity, sizeof(int), 1, fptr);


    for (int i = 0; i < lp->npols; i++) {
        fwrite(cp->polname, sizeof(char), sizename, fptr);
        fwrite(cp->description, sizeof(char), sizedescription, fptr);
        fwrite(cp->activity, sizeof(char), sizeactivity, fptr);
        lp->ppol->pnext++;
    }
    fclose(fptr);
}

//Does not work, file error
void read_from_file_pol_binary(LIST_POL * lp, char fn[]){
    FILE *fptr;
    CITY_POL * cp = lp->ppol;
    fptr = (fopen("C:\\polbinary.txt", "br"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    int npols = 0;
    fread(&npols, sizeof(int), 1, fptr);
    fread(&lp->npols, sizeof(int), npols, fptr);

    int sizename = strlen(cp->polname + 1);
    fread(&sizename, sizeof(int), 1, fptr);

    int sizedescription = strlen(cp->description + 1);
    fread(&sizedescription, sizeof(int), 1, fptr);

    int sizeactivity = strlen(cp->activity + 1);
    fread(&sizeactivity, sizeof(int), 1, fptr);

    for (int i = 0; i < npols; i++) {
        fread(cp->polname, sizeof(char), sizename, fptr);
        fread(cp->description, sizeof(char), sizedescription, fptr);
        fread(cp->activity, sizeof(char), sizeactivity, fptr);
        npols++;
    }
    fclose(fptr);
}

int testfunctionspols(){
    LIST_POL pol = {NULL, 0, "Lisbon"};
    insert_pols_ordered(&pol, "Fountain", "Wonderful", "We have visited the Fountain");
    insert_pols_ordered(&pol, "Castle", "Worth to see", "We have visited the castle");
    CITY_POL * head = pol.ppol;
    printcitypols(head);
    return 0;
}


