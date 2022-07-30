//
// Created by valen on 30-Dec-21.
//
#include "main.h"

//...................B........Trips Dynamic array........

void create_dynarray_trips(TRIPS_ARRAY * tripsarray, int initsize) {
    tripsarray->ptrips = (TRIP *) calloc(initsize, sizeof(TRIP));
    tripsarray->size_trips = initsize;
    tripsarray->current_number_trips = 0;
}

void insert_trip_dynarray_trips(TRIPS_ARRAY *tripsarray, char tripname[], char customername[], CITIES_DYNARRAY * cities, int startday, int startmonth, int startyear, int endday, int endmonth, int endyear) {

    TRIP *ptrip = NULL; //aux variable
    TRIP trip0 = {" ", " ", NULL, 0, 0, 0, 0, 0, 0};

    int oldsize = tripsarray->size_trips;
    int newsize = tripsarray->size_trips + 10;

    if (tripsarray->current_number_trips == tripsarray->size_trips) {

        tripsarray->ptrips = (TRIP *) realloc(tripsarray->ptrips, newsize * sizeof(TRIP));
        tripsarray->size_trips = newsize;

        for (int i = oldsize + 1; i < newsize; i++) {
            *(tripsarray->ptrips + i) = trip0;
        }
    }

    ptrip = tripsarray->ptrips + tripsarray->current_number_trips;
    //ptrip is pointing to one of the free elements in the array tripsarray

        strcpy(ptrip->tripname, tripname); //Put name into ptrip->tripname
        strcpy(ptrip->customername, customername); //Put name into ptrip->customername
        ptrip->startdate.day = startday;
        ptrip->startdate.month = startmonth;
        ptrip->startdate.year = startyear;
        ptrip->enddate.day = endday;
        ptrip->enddate.month = endmonth;
        ptrip->enddate.year = endyear;

        tripsarray->current_number_trips++;

}

TRIP * find_trip (TRIPS_ARRAY * tripsarray, char name[]){
    TRIP * trip1 = tripsarray->ptrips;
    while(trip1 != NULL){
        if(strcmp(trip1->tripname, name)){
            printf("The trip %s exists in the database~", trip1->tripname);
            return trip1;
        }
    }
    return NULL;
}

//Does not work
TRIP remove_trip(TRIPS_ARRAY * tripsarray, char name[]){
    TRIP trip = {" ", " ", NULL, 0, 0, 0, 0, 0, 0};
    TRIP * ptrip = find_trip(tripsarray, name);

    if (ptrip != NULL) {
        trip = * ptrip;
        while (ptrip < tripsarray -> ptrips + tripsarray -> current_number_trips-1){
            *ptrip = *(ptrip+1);
            ptrip++;
        }
    }

    if(ptrip == (tripsarray -> ptrips + tripsarray -> size_trips -1)){
        strcpy(ptrip->customername, NULL); //Put name into ptrip->tripname
        strcpy(ptrip->tripname, NULL); //Put name into ptrip->tripname
        ptrip->startdate.day = 0;
        ptrip->startdate.month = 0;
        ptrip->startdate.year = 0;
        ptrip->enddate.day = 0;
        ptrip->enddate.month = 0;
        ptrip->enddate.year = 0;
        ptrip->destinations = NULL;
    }
    printf("The trip has been deleted successfully\n");
    return trip;
}

//Does not work
void edit_trip(TRIPS_ARRAY *tripsArray, char name[], char newcustomername[], char newtripname[], DATE newstartdate, DATE newenddate, CITIES_DYNARRAY * newdestination) {
    TRIP * ptrip = find_trip(tripsArray, name);

    if(ptrip == NULL)
        printf("The city does not exist");

    strcpy(ptrip->tripname, newtripname); //Put name into ptrip->tripname
    strcpy(ptrip->customername, newcustomername); //Put name into ptrip->customername
    ptrip->startdate = newstartdate;
    ptrip->enddate= newenddate;
    ptrip->destinations = newdestination;
}

//Does not work, file error
void write_in_file_trip(TRIPS_ARRAY * ta, char fn[]){
    FILE *fptr;
    fptr = (fopen("C:\\trips.txt", "w"));

    if(fptr==NULL){
        printf("ERROR...%s\n", fn);
        return;
    }
    fprintf(fptr, "Number of trips: %d", ta->current_number_trips);

    for(int i=0; i<ta->current_number_trips; i++) {
        fprintf(fptr, "Trip Name: %s\n", ta->ptrips->tripname);
        fprintf(fptr, "Customer Name: %s\n", ta->ptrips->customername);
        fprintf(fptr, "Start Date: %d%d%d\n", ta->ptrips->startdate.day, ta->ptrips->startdate.month,
                ta->ptrips->startdate.year);
        fprintf(fptr, "End Date: %d%d%d \n", ta->ptrips->enddate.day, ta->ptrips->enddate.month,
                ta->ptrips->enddate.year);
    }
    fclose(fptr);
}

//Does not work, file error
void read_from_file_trip(TRIPS_ARRAY * ta, char filename[]){
    FILE *fptr;
    fptr = (fopen("C:\\trips.txt", "r"));

    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    int trips = 0;
    fscanf(fptr, "%*s%d", &trips);

    char tripname[30];
    char customername[30];
    int sday = 0;
    int smonth = 0;
    int syear = 0;
    int eday = 0;
    int emonth = 0;
    int eyear = 0;

    for(int i=0; i<trips; i++) {
        fscanf(fptr, "%*s%s, %*s%s, %*s%d %d %d, %*s%d %d %d",
               tripname, customername, &sday, &smonth, &syear, &eday, &emonth, &eyear);
        insert_trip_dynarray_trips(&(*ta), tripname, customername, NULL, sday, smonth, syear, eday, emonth, eyear);
    }
    fclose(fptr);
}

//Does not work, file error
void write_in_file_trip_binary(TRIPS_ARRAY * ta, char fn[]) {
    FILE *fptr;
    TRIP * pt = ta->ptrips;
    fptr = (fopen("C:\\tripsbinary.txt", "bw"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    int sizetrip = strlen(pt->tripname + 1);
    fwrite(&sizetrip, sizeof(int), 1, fptr);
    fwrite(pt->tripname, sizeof(char), sizetrip, fptr);
    int sizecustomer = strlen(pt->customername + 1);
    fwrite(&sizecustomer, sizeof(int), 1, fptr);
    fwrite(pt->customername, sizeof(char), sizecustomer, fptr);

    fwrite(&ta->size_trips, sizeof(int), 1, fptr);

    for (int i = 0; i < ta->size_trips; i++) {
        fwrite(pt->tripname, sizeof(char), sizetrip, fptr);
        fwrite(pt->customername, sizeof(char), sizecustomer, fptr);
        fwrite(&pt->startdate.day, sizeof(int), 1, fptr);
        fwrite(&pt->startdate.month, sizeof(int), 1, fptr);
        fwrite(&pt->startdate.year, sizeof(int), 1, fptr);
        fwrite(&pt->enddate.day, sizeof(int), 1, fptr);
        fwrite(&pt->enddate.month, sizeof(int), 1, fptr);
        fwrite(&pt->enddate.year, sizeof(int), 1, fptr);
        pt = pt + 1;
    }
    fclose(fptr);

}

//Does not work, file error
void read_from_file_trip_binary(TRIPS_ARRAY * ta, char fn[]){
    FILE *fptr;
    fptr = (fopen("C:\\tripsbinary.txt", "br"));
    TRIP *pt = ta->ptrips;
    if(fptr==NULL){
        printf("ERROR...%s\n", fn);
        return;
    }

    int sizetrip = strlen(pt->tripname + 1);
    fread(&sizetrip, sizeof(int), 1, fptr);
    fread(pt->tripname, sizeof(char), sizetrip, fptr);
    int sizecustomer = strlen(pt->customername + 1);
    fread(&sizecustomer, sizeof(int), 1, fptr);
    fread(pt->customername, sizeof(char), sizecustomer, fptr);

    fread(&ta->size_trips, sizeof(int), 1, fptr);

    for(int i=0; i<ta->size_trips; i++){
        fread(pt->tripname, sizeof(char), sizetrip, fptr);
        fread(pt->customername, sizeof(char), sizecustomer, fptr);
        fread(&pt->startdate.day, sizeof(int), 1, fptr);
        fread(&pt->startdate.month, sizeof(int), 1, fptr);
        fread(&pt->startdate.year, sizeof(int), 1, fptr);
        fread(&pt->enddate.day, sizeof(int), 1, fptr);
        fread(&pt->enddate.month, sizeof(int), 1, fptr);
        fread(&pt->enddate.year, sizeof(int), 1, fptr);
        pt=pt+1;
    }
    fclose(fptr);
}


void query_travel_history(TRIPS_ARRAY *tripsArray, char scustomer[]) {
    TRIP *trip = tripsArray->ptrips;
    while (tripsArray->current_number_trips <= tripsArray->size_trips) {
        if (strcmp(trip->customername, scustomer))
            printf("The name of the trip: %s", trip->tripname);
        tripsArray->current_number_trips++;
    }
}

void query_trip_city (TRIP * cp, char city[]){
    CITIES_DYNARRAY * p = cp->destinations;
    while (p->current_number_cities <= p->size_cities){
        if(strcmp(p->pcities->cityname, city) == 1)
            printf("The name of the trip is: %s", cp->tripname);
        p->current_number_cities++;
    }
}

void query_trip_pol (TRIP * trip, char pol[]){
    LIST_POL * lp = trip->destinations->pcities->citypol;
    while (lp->ppol !=NULL){
        if(strcmp(lp->ppol->polname, pol) == 1) {
            printf("The name of the trip is: %s", trip->tripname);
            lp->ppol->pnext;
        }
    }
}


int testfunctionstrip(){
    TRIPS_ARRAY trips1 = {"Customer X", 0, 0, NULL};
    create_dynarray_trips(&trips1, 10);
    insert_trip_dynarray_trips(&trips1, "Lisbon", "Alex", NULL, 20, 9, 2020, 25, 10, 2020);
    insert_trip_dynarray_trips(&trips1, "Porto", "Henrique", NULL, 20, 9, 2020, 25, 10, 2020);
    insert_trip_dynarray_trips(&trips1, "Lisbon", "Maia", NULL, 20, 9, 2020, 25, 10, 2020);
    find_trip(&trips1, "Lisbon");


    return 0;
}