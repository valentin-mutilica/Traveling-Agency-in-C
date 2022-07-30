//
// Created by valen on 30-Dec-21.
//
#include "main.h"

//.......Dynamic array Cities...........

void create_dynarray_cities(CITIES_DYNARRAY *citiesarray, int initsize, char name[]) {
    citiesarray->pcities= (CITY *) calloc(1, sizeof(CITY));
    citiesarray->carrayname = (char *) malloc(strlen(name)+1);
    citiesarray->size_cities = initsize;
    citiesarray->current_number_cities = 0;
}

void insert_city_dynarray_cities(CITIES_DYNARRAY * citiesarray, char name[], char description[], int id, float longitude, float latitude) {

    CITY * pcity = NULL; //aux variable ps
    CITY city0 = {0, 0.0f, 0.0f, " ", " "};

    int oldsize = citiesarray->size_cities;
    int newsize = citiesarray->size_cities + 10;

    if (citiesarray->current_number_cities == citiesarray->size_cities) {

        citiesarray->pcities = (CITY *) realloc(citiesarray->pcities, newsize * sizeof(CITY));
        citiesarray->size_cities = newsize;

        for (int i = oldsize + 1; i < newsize; i++) {
            *(citiesarray->pcities + i) = city0;
        }
    }

    pcity = citiesarray->pcities + citiesarray->current_number_cities;

    pcity->cityname = (char *) malloc(strlen(name)+1);
    strcpy(pcity->cityname, name);
    pcity->id = id;
    pcity->latitude = latitude;
    pcity->longitude = longitude;
    pcity->description = (char *) malloc(strlen(description)+1);
    strcpy(pcity->description, description);

    citiesarray->current_number_cities++;

}

CITY * find_city (CITIES_DYNARRAY * citiesarray, char name[]){
    CITY * city1 = citiesarray->pcities;
    for(int i=0; i<citiesarray->current_number_cities; i++) {
        if (strcmp(city1->cityname, name)) {
            printf("The city has been found\n");
        }
    }
    return &(*city1);
}

//Does not work
CITY remove_city(CITIES_DYNARRAY * citiesarray, char name[]){
    CITY city = {0, 0.0f, 0.0f, " ", " "};
    CITY * pcity = find_city(&(*citiesarray), name);

    if (pcity != NULL) {
        city = * pcity;
        while (pcity < citiesarray->pcities + citiesarray->current_number_cities-1){
            *pcity = *(pcity+1);
            pcity++;
        }
    }

    if(pcity == (citiesarray->pcities + citiesarray->size_cities -1)){
        pcity->cityname = NULL;
        pcity->id = 0;
        pcity->latitude = 0.0f;
        pcity->longitude = 0.0f;
        pcity->description = NULL;
    }

    return *pcity;
}

//Does not work
CITY edit_city(CITIES_DYNARRAY * citiesarray, char name[], char newcityname[], int newid, float newlatitude, float newlongitude, char newdescription[]){
        CITY * pcity = find_city(citiesarray, name);

        if(pcity->id == 0)
            printf("The city does not exist");

        pcity->cityname = (char *) malloc(strlen(newcityname)+1);
        pcity->id = newid;
        pcity->latitude = newlatitude;
        pcity->longitude = newlongitude;
        pcity->description = (char *) malloc(strlen(newdescription)+1);

        return *pcity;
}

void searchDescription(CITIES_DYNARRAY *cities, char search[]) {

        char *ptr = strstr(cities->pcities->description, search);
        if (ptr != NULL) /* Substring found */
        {
            printf("We could find '%s' in %s's description \n", search, cities->pcities->cityname);
        } else /* Substring not found */
        {
            printf("%s's description does not contain '%s'\n", cities->pcities->cityname, search);
        }
}

//Does not work
void editDescription(CITIES_DYNARRAY *cd, char name[], char replacement_string[]) {
    for(int i=0; i<cd->current_number_cities; i++){
        if(strcmp(cd->pcities->cityname, name)==1) {
            cd->pcities->description = strcpy(cd->pcities->description, replacement_string);
        }
    }
}

//Does not work, file error
void write_in_file_city(CITIES_DYNARRAY cd, char fn[]){
    FILE *fptr;
    CITY * pc = cd.pcities;
    fptr = (fopen("C:\\cities.txt", "w"));

    if(fptr==NULL){
        printf("ERROR...%s\n", fn);
        return;
    }
    fprintf(fptr, "Number of cities: %d", cd.current_number_cities);

    for(int i=0; i<cd.current_number_cities; i++) {
        fprintf(fptr, "City ID: %d\n", pc->id);
        fprintf(fptr, "Latitude: %f\n", pc->latitude);
        fprintf(fptr, "Longitude: %f\n", pc->longitude);
        fprintf(fptr, "City name: %s\n", pc->cityname);
        fprintf(fptr, "Description: %s\n", pc->description);
        pc=pc+1;
    }
    fclose(fptr);
}

//Does not work, file error
void read_from_file_city(CITIES_DYNARRAY * cd, char filename[]) {
    FILE *fptr;
    fptr = (fopen("C:\\cities.txt", "r"));
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    int cities = 0;
    fscanf(fptr, "%*s%d", &cities);

    int id = 0;
    float clatitude = 0;
    float clongitude = 0;
    char cityname[25];
    char description[250];

    for (int i = 0; i < cities; i++){
        fscanf(fptr, "%*s%d, %*s%f, %*s%f, %*s%s, %*s%s", &id, &clatitude, &clongitude, cityname, description);
    insert_city_dynarray_cities(&(*cd), cityname, description, id, clongitude, clatitude);
}
    fclose(fptr);
}

//Does not work, file error
void write_in_file_city_binary(CITIES_DYNARRAY * cities, char fn[]){
    FILE *fptr;
    CITY * c = cities->pcities;
    fptr = (fopen("C:\\citiesbinary.txt", "bw"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    int sizename = strlen(c->cityname + 1);
    fwrite(&sizename, sizeof(int), 1, fptr);
    fwrite(c->cityname, sizeof(char), sizename, fptr);

    int sizedescription = strlen(c->description + 1);
    fwrite(&sizedescription, sizeof(int), 1, fptr);
    fwrite(c->description, sizeof(char), sizedescription, fptr);

    fwrite(&(cities->size_cities), sizeof(int), 1, fptr);

    for (int i = 0; i < cities->size_cities; i++) {
        fwrite(&(c->id), sizeof(int), 1, fptr);
        fwrite(&(c->latitude), sizeof(int), 1, fptr);
        fwrite(&(c->longitude), sizeof(int), 1, fptr);
        fwrite(&(c->cityname), sizeof(char), sizename, fptr);
        fwrite(&(c->description), sizeof(char), sizedescription, fptr);

        cities->size_cities++;
    }
    fclose(fptr);
}

//Does not work, file error
void read_from_file_city_binary(CITIES_DYNARRAY * cd, char fn[]){
    FILE *fptr;
    CITY * pc = cd->pcities;
    fptr = (fopen("C:\\citiesbinary.txt", "br"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    int sizename=0;
    int sizedescription=0;

    fread(&sizename, sizeof(int), 1, fptr);
    fread(&sizedescription, sizeof(int), 1, fptr);

    fread(&cd->size_cities, sizeof(int), 1, fptr);

    for(int i = 0; i < cd->size_cities; i++) {
        fread(&(pc->id), sizeof(int), 1, fptr);
        fread(&(pc->latitude), sizeof(float), 1, fptr);
        fread(&(pc->longitude), sizeof(float), 1, fptr);
        fread(pc->cityname, sizeof(char), sizename, fptr);
        fread(pc->description, sizeof(char), sizedescription, fptr);
        pc++;
    }
    fclose(fptr);
}

int testcitiesfunctions(){

   CITIES_DYNARRAY cities = {0, 0, "", NULL};
   create_dynarray_cities(&cities, 5, "FIRST");
   insert_city_dynarray_cities(&cities, "Lisbon", "No description", 1, 1.0, 2.0);
   insert_city_dynarray_cities(&cities, "Porto", "X", 2, 3.0, 5.0);
   insert_city_dynarray_cities(&cities, "Braga", "Y", 3, 16.0, 1.0);
   //find_city(&cities, "Porto");
   searchDescription(&cities, "No description");
   //editDescription(&cities, "Porto", "Beautiful city to visit");
   //printf("After description editing");
   //printCities(cities);

   return 0;
}