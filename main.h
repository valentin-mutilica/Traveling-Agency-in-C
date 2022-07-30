/**
* CREATED BY VALENTIN MUTILICA - 32400 & BIANCA COSTEA - 32401
*
*/
#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#define MAX200 200
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Date {
    int day;
    int month;
    int year;
} DATE;

typedef struct City_Pol {
    char polname[20];
    char description[200];
    char activity[200];
    struct City_Pol * pnext;
}CITY_POL;

typedef struct list_pol {
    CITY_POL * ppol;
    int npols;
    char citypolname[20];
} LIST_POL;

typedef struct City {
    int id;
    float latitude;
    float longitude;
    char *cityname;
    char *description;
    LIST_POL * citypol;
} CITY;

typedef struct cities_dynarray{
    int size_cities;    //Size of the dynamic array
    int current_number_cities;   //Current number of cities inside dynamic array
    char *carrayname;
    CITY *pcities;      //Pointer cities
}CITIES_DYNARRAY;

typedef struct trip {
    char tripname[30];
    char customername[30];
    CITIES_DYNARRAY * destinations;
    DATE startdate;
    DATE enddate;
} TRIP;

typedef struct trip_array {
    char triparrayname[20];
    int size_trips; //Size of the dynamic array
    int current_number_trips;
    TRIP * ptrips;
} TRIPS_ARRAY;

typedef struct customer {
    int userid;
    int vat;
    char name[20];
    DATE birthdate;
    DATE regdate; //registration date
    char phonenumber[20];
    char email[30];
    char address[100];
    TRIPS_ARRAY * TripsCustomer;
} CUSTOMER;

typedef struct customer_node {
    CUSTOMER c;
    TRIPS_ARRAY * customertrips;
    struct customer_node *pnext;
} CUSTOMER_NODE;

typedef struct customer_list {
    CUSTOMER_NODE * pcustomers;
    int ncustomers;
} CUSTOMER_LIST;

typedef struct Porto_Point {
    CUSTOMER_LIST * customers;
    int ncustomers;
}COMPANY;

typedef struct path {
    CITIES_DYNARRAY * pcd;
    double path;
} PATH;

typedef struct path_dynarray {
    PATH * ppath;
    int size_path;
    int current_path;
} PATH_DYNARRAY;

typedef struct population {
    int size_population;
    int current_population;
    CITIES_DYNARRAY *pcd;
} POPULATION;


/**
* REQUIREMENTS
* 1. a)
* i. Insert customers ordered - Fully implemented and it is functional.
* Neatly insert - not implemented.
* Remove a customer - implemented, not tested.
* Search for a customer by VAT - implemented, functional with some errors.
* Sort the list by VAT - Implemented and functional.
* Print customers - Implemented and functional.
********************************************************************************
* Functions:
*
*/


/**
* Function to insert a customer into the linked list CUSTOMER in order.
* @param cl - pointer to the CUSTOMER_LIST.
* @param userid - the user id.
* @param birthdate - the user's birthdate.
* @param regdate - the user's register date.
* @param phonenumber - the user's phone number.
* @param name - the user's full name.
* @param email - the user's email.
* @param address - the user's full address: including country, city and postal code.
*/
void insert_customer_ordered(CUSTOMER_LIST *cl, int userid, int vat, int birthday, int birthmonth, int birthyear, int regday, int regmonth, int regyear, char phonenumber[20], char name[20], char email[30], char address[100]);

/**
* Function to insert a customer into the linked list CUSTOMER in order depending on the existing list.
* @param cl - pointer to the CUSTOMER_LIST.
* @param customer - pointer to the customer to be inserted.
*/
void insert_customer(CUSTOMER_LIST *cl, CUSTOMER * customer);

/**
* Function to insert a customer into the linked list CUSTOMER in the first/head position.
* @param cl - pointer to the CUSTOMER_LIST.
* @param customer - pointer to the customer to be inserted.
*/
void insert_customer_head(CUSTOMER_LIST *cl, CUSTOMER * customer);

/**
* Function to insert a customer into the linked list CUSTOMER at the tail.
* @param cl - pointer to the CUSTOMER_LIST.
* @param customer - pointer to the customer to be inserted.
*/
void insert_customer_tail(CUSTOMER_LIST *cl, CUSTOMER * customer);

/**
* Function to print all the customers using the list passed to it.
* @param customerlist - customer list.
*/
void printCustomers(CUSTOMER_LIST * customerlist);

/**
 * Function to swap the data of two nodes a and b
 * @param a - Customer node A.
 * @param b - Customer node B.
 */
void swap_customers(CUSTOMER_NODE *a, CUSTOMER_NODE *b);

/**
 *  Sorting algorithm to sort the linked list of customers by VAT helped by the function swap that swaps data between nodes.
 *  @param customerlist - To itterate and sort the nodes of the list
 */
void vatSort(CUSTOMER_LIST * customerlist);

/**
 *  Sorting algorithm to sort the linked list of customers by user id helped by the function swap that swaps data between nodes.
 *  @param customerlist - To itterate and sort the nodes of the list
 */
void useridSort(CUSTOMER_LIST * customerlist);

/**
 * The function has a pointer to the CUSTOMER_LIST linked list and it is used to search a customer by its vat.
 * @param CUSTOMER_LIST - pointer to the linked list.
 * @param vat - the customer's vat.
 */
int search_by_vat(CUSTOMER_LIST * customers, int vat);

/**
 * The function has a pointer to the CUSTOMER_LIST linked list and it is used to search a customer by its userid.
 * @param CUSTOMER_LIST - pointer to the linked list.
 * @param id- the customer's user id.
 */
int search_by_userid(CUSTOMER_LIST * customers, int id);

/**
 * The function has a pointer to the CUSTOMER_LIST linked list and it is used to remove a customer by its name.
 * @param CUSTOMER_LIST - pointer to the linked list.
 * @param name - the customer's name.
 */
void delete_customer(CUSTOMER_LIST * cl, char name[]);





/**
* REQUIREMENTS
* 1. b)*
* i. Create a dynamic array with a given dimension and resize the dynamic array in case it is needed - Fully implemented and it is functional.
* Insert - Implemented and functional.
* Edit - implemented, not tested.
* Remove trips - implemented, not tested.
* Edit trip data - Implemented, not tested.
* Find trip - Implemented, not tested.
*
********************************************************************************
* Functions:
*
*/

/**
 * The function has a pointer to the trips array and it is used to create a dynamic array of trips.
 * @param tripsarray - pointer to TRIPS_ARRAY.
 */
void create_dynarray_trips(TRIPS_ARRAY *tripsarray, int initsize);

/**
 * Insert a new trip into the dynamic array Trips.
 * The dynamic array will resize itself based on the number of trips already present in the array.
 * @param triparray - pointer to TRIPS_ARRAY.
 * @param tripname - trip name.
 * @param customername - customer name.
 * @param cities - a pointer to the CITIES_DYNARRAY for the cities inside the trip.
 * @param startday - start day of the trip.
 * @param startmonth - start month of the trip.
 * @param startyear - start year of the trip.
 * @param enddday - end day of the trip.
 * @param enddmonth - end month of the trip.
 * @param endyear - end year of the trip.
 *
 */
void insert_trip_dynarray_trips(TRIPS_ARRAY *tripsarray, char tripname[], char customername[], CITIES_DYNARRAY * cities, int startday, int startmonth, int startyear, int endday, int endmonth, int endyear);


/**
 * The function has a pointer to the trips array and it is used to find a trip already existent in the trips array.
 * @param tripsarray - pointer to TRIPS_ARRAY.
 * @param name - the name of the trip.
 */
TRIP * find_trip (TRIPS_ARRAY * tripsarray, char name[]);

/**
 * The function has a pointer to the trips array and it is used to remove a trip already existent in the trips array.
 * @param tripsarray - pointer to TRIPS_ARRAY.
 * @param name - the name of the trip.
 */
TRIP remove_trip(TRIPS_ARRAY * tripsarray, char name[]);

/**
 * Edit a trip from the dynamic array Trips.
 * @param triparray - pointer to TRIPS_ARRAY.
 * @param name - name used to find the trip.
 * @param newcustomername - new customer name.
 * @param newtripname - new trip name.
 * @param newdestination - a new pointer to the CITIES_DYNARRAY.
 * @param newstartdate - new start date of the trip.
 * @param newenddate - new end date of the trip.
 */
void edit_trip(TRIPS_ARRAY *tripsArray, char name[], char newcustomername[], char newtripname[], DATE newstartdate, DATE newenddate, CITIES_DYNARRAY * newdestination);



/**
* REQUIREMENTS
* 1. C)
* i.
visit on the trip; search cities by name;
* Create a dynamic array with a given dimension; resize the dynamic array; - fully implemented, functional.
* insert - implemented, functional.
* Remove cities - Implemented, not tested.
* Print cities - Implemented and functional.
********************************************************************************
* Functions:
*
*/

/**
* Function to create the dynamic array cities.
* @param citiesarray - CITIES_DYNARRAY pointer.
* @param initsize - the initial size of the dynamic array.
* @param name - the dynamic array's name.
*/
void create_dynarray_cities(CITIES_DYNARRAY *citiesarray, int initsize, char name[]);

/**
 * Insert a new city into the dynamic array cities.
 * The dynamic array will resize itself based on the number of cities already present in the array.
 * @param citiesarray - pointer to CITIES_DYNARRAY.
 * @param name - city name.
 * @param description - city description.
 * @param id - city id.
 * @param longitude - city location : longitude.
 * @param latitude - city location : latitude.
 */
void insert_city_dynarray_cities(CITIES_DYNARRAY * citiesarray, char name[], char description[], int id, float longitude, float latitude);

/**
 * The function has a pointer to the structure CITY to find a specific city in the CITIES_DYNARRAY entered by the user.
 * The dynamic array will resize itself based on the number of cities already present in the array.
 * @param citiesarray - pointer to CITIES_DYNARRAY.
 * @param name - city name.
 */
CITY * find_city (CITIES_DYNARRAY * citiesarray, char name[]);

/**
 * Remove a city from the dynamic array Cities.
 * @param citiesarray - pointer to CITIES_DYNARRAY.
 * @param name - name used to find the city to be removed.
 */
CITY remove_city(CITIES_DYNARRAY * citiesarray, char name[]);


/**
* REQUIREMENTS
* 1. D)
* i.
* Search in description of a city - Implemented and functional.
* Edit city - Implemented, not tested.
* Edit description - Implemented, not fully functional.
* ii.;
* Creating a city's PoI list - implemented, functional.
* Insert - Implemented, functional.
* Remove - Implemented, not tested.
* Search - Implemented and functional.
* Print - Implemented, not tested.
********************************************************************************
* Functions:
*
*/

/**
* Function to check if a string is found inside the description of a city.
* @param city - CITIES_DYNARRAY pointer.
* @param search - the string you want to search inside the description.
*/
void searchDescription(CITIES_DYNARRAY *city, char search[]);

/**
 * Edit a city from the dynamic array Cities.
 * @param citiesarray - pointer to CITIES_DYNARRAY.
 * @param name - name used to find the city.
 * @param newcityname - new city name.
 * @param newid - new id for the city.
 * @param newdescription - new city description.
 * @param newlongitude - new city location : longitude.
 * @param newlatitude - new city location : latitude.
 */
CITY edit_city(CITIES_DYNARRAY * citiesarray, char name[], char newcityname[], int newid, float newlatitude, float newlongitude, char newdescription[]);


/**
* Function to edit the description of a city.
* @param cd - CITIES_DYNARRAY pointer.
* @param name - the name of the city
* @param replacement_string - the string that will replace the city's description.
*/
void editDescription(CITIES_DYNARRAY *cd, char name[], char replacement_string[]);

/**
* Function to insert a city pol into the linked list LIST_POL in order.
* @param pl - pointer to the LIST_POL.
* @param polname - the pol's name.
* @param description - the pol's description.
* @param activity - the pol's activity.
*/
void insert_pols_ordered(LIST_POL *pl, char polname[], char description[], char activity[]);

/**
* Function to print all the city pols.
* @param node - pointer to the CITY_POL list.
*/
void printcitypols(CITY_POL * node);

/**
 * The function has a pointer to the trips array and it is used to remove a city pol already existent in the city pol list.
 * @param tripsarray - pointer to CITY_POL linked list.
 * @param position - the position of the citypol.
 */
void deletecitypol(CITY_POL * pol, int position);

/**
 * Function to write in file the content of each pol structure in the pol linked list.
 * @param lp - Pointer to your pol linked list.
 * @param fn - the path of the filename where you want to write the content.
 */

/**
* REQUIREMENTS
* 1. E)
* i.
* Query travel history - All the functions implemented, but not working.
********************************************************************************
* Functions:
*
*/


/**
 * Function to query the travel history of a certain customer - searched by name.
 * @param tripsArray - Pointer to the TRIPS_ARRAY.
 * @param scustomer - .
 */
void query_travel_history(TRIPS_ARRAY *tripsArray, char scustomer[]);

/**
 * Function to find out the trip with the city X.
 * @param tripsArray - Pointer to the TRIP.
 * @param city - The name of the city.
 */
void query_trip_city (TRIP * cp, char city[]);

/**
 * Function to find out the trip with the city X.
 * @param trip - Pointer to the TRIP.
 * @param pol - The name of the pol.
 */
void query_trip_pol (TRIP * trip, char pol[]);
/**
* REQUIREMENTS
* 1. F)
* i.
* All the writing and reading functions implemented - Not working properly - Won't open the file.
********************************************************************************
* Functions:
*
*/

/**
 * Function to write in file the content of each Customer structure in the linked list.
 * @param pc - Pointer to your customer list.
 * @param fn - the path of the filename where you want to write the content.
 */
void write_in_file_customer(CUSTOMER_LIST * pc, char fn[]);

/**
 * Function to read from file the content of each Customer structure in the linked list.
 * @param currentlist - Pointer to your customer list.
 * @param filename - the path of the filename from where you want to read the content.
 */
void read_from_file_customer(CUSTOMER_LIST * currentlist, char filename[]);

/**
 * Function to write in file the binary content of each Customer structure in the linked list.
 * @param cl - Pointer to your customer list.
 * @param fn - the path of the filename where you want to write the content.
 */
void write_in_file_customer_binary(CUSTOMER_LIST * cl, char fn[]);

/**
 * Function to read from file the binary content of each Customer structure in the linked list.
 * @param pc - Pointer to your customer list.
 * @param fn - the path of the filename from where you want to read the content.
 */
void read_from_file_customer_binary(CUSTOMER_LIST * pc, char fn[]);

/**
 * Function to write in file the content of each city structure in the dynamic array.
 * @param cd - Pointer to your cities dynamic array.
 * @param fn - the path of the filename where you want to write the content.
 */
void write_in_file_city(CITIES_DYNARRAY cd, char fn[]);

/**
 * Function to read from file the content of each city structure in the dynamic array.
 * @param cd - Pointer to your cities dynamic array.
 * @param filename - the path of the filename from where you want to read the content.
 */
void read_from_file_city(CITIES_DYNARRAY * cd, char filename[]);

/**
 * Function to write in file the binary content of each city structure in the dynamic array.
 * @param cities - Pointer to your cities dynamic array.
 * @param fn - the path of the filename where you want to write the content in binary.
 */
void write_in_file_city_binary(CITIES_DYNARRAY * cities, char fn[]);

/**
 * Function to read from file the binary content of each city structure in the dynamic array.
 * @param cd - Pointer to your cities dynamic array.
 * @param fn - the path of the filename from where you want to read the content.
 */
void read_from_file_city_binary(CITIES_DYNARRAY * cd, char fn[]);

/**
 * Function to write in file the content of each trip structure in the dynamic array.
 * @param ta - Pointer to the trips dynamic array.
 * @param fn - the path of the filename where you want to write the content.
 */
void write_in_file_trip(TRIPS_ARRAY * ta, char fn[]);

/**
 * Function to read from file the content of each trip structure in the dynamic array.
 * @param ta - Pointer to the trips dynamic array.
 * @param filename - the path of the filename from where you want to read the content.
 */
void read_from_file_trip(TRIPS_ARRAY * ta, char filename[]);

/**
 * Function to write in file the binary content of each trip structure in the dynamic array.
 * @param ta - Pointer to the trips dynamic array.
 * @param fn - the path of the filename where you want to write the binary content.
 */
void write_in_file_trip_binary(TRIPS_ARRAY * ta, char fn[]);

/**
 * Function to read from file the binary content of each trip structure in the dynamic array.
 * @param ta - Pointer to the trips dynamic array.
 * @param fn - the path of the filename from where you want to read the binary content.
 */
void read_from_file_trip_binary(TRIPS_ARRAY * ta, char fn[]);

/**
 * Function to write in file the content of each pol.
 * @param lp - Pointer to the pol list.
 * @param fn - the path of the filename where you want to write the content.
 */
void write_in_file_pol(LIST_POL * lp, char fn[]);

/**
 * Function to read from file the content of each pol structure in the linked list.
 * @param lp - Pointer to your pol linked list.
 * @param filename - the path of the filename from where you want to read the content.
 */
void read_from_file_pol(LIST_POL * lp, char filename[]);

/**
 * Function to write in file the binary content of each pol structure in the pol linked list.
 * @param lp - Pointer to your pol linked list.
 * @param fn - the path of the filename where you want to write the content in binary.
 */
void write_in_file_pol_binary(LIST_POL * lp, char fn[]);

/**
 * Function to read from file the binary content of each pol structure in the linked list.
 * @param lp - Pointer to your pol linked list.
 * @param filename - the path of the filename from where you want to read the binary content.
 */
void read_from_file_pol_binary(LIST_POL * lp, char fn[]);


/**
* REQUIREMENTS
* 1. G)
* i.
* Function for generating reports - Implemented, not working.
********************************************************************************
* Functions:
*
*/
/**
* Function to generate a report with all the details of a certain customer.
* @param cl - pointer to the customer linked list.
* @param customer - the customer's name.
* @param fn - the path of the filename where you want to write the content.
*/
void generate_report_customer_(CUSTOMER_LIST * cl, const char customer[], char fn[]);


/**
* REQUIREMENTS
 * 2. a) i.not implemented.
 *  ii. not implemented.
* 2. b)
* i. Function to manage matrices of Population - Partially implemented, not tested.
* ii. Function for random generation of initial population - Implemented, not tested.
* iii. Function to quantify the fitness of each individual within a Population - Implemented, not tested.
* iv. Not implemented.
* v. Not implemented.

********************************************************************************
* Functions:
*
*/

/**
 * Function to create a dynamic array for the population of the genetic algorithm.
 * @param ppl - pointer to the structure POPULATION.
 * @param popsize - the size of the dynamic array.
 */
void create_population_array(POPULATION *ppl, int popsize);

/**
 * Function to calculate the distance between 2 cities for the genetic algorithm.
 * @param c1long - pointer to the first city's longitude.
 * @param c1lat - pointer to the first city's latitude.
 * @param c2long - pointer to the second city's longitude.
 * @param c2lat - pointer to the second city's latitude.
 * @param ncities - the number of cities.
 */
int distance(float *c1long, float *c1lat, float *c2long, float *c2lat, int ncities);

/**
 * Function to create the square matrix containing the calculated euclidian distances.
 * @param d - pointer to the structure PATH_DYNARRAY.
 * @param cn - number of cities.
 */
void create_array_distances(PATH_DYNARRAY *d, int cn);

/**
 * Function to insert the distances into the matrix.
 * @param d - pointer to the structure PATH_DYNARRAY.
 * @param cn - number of cities.
 */
void insert_into_distances(PATH_DYNARRAY *d, double distances[][200], int cn);

/**
 * Function to shuffle the city id and create random individuals.
 * @param population - array containing an individual.
 * @param n - size of population.
 * @return population.
 */
int shuffleRandom (int population[], int n);

/**
 * Function to insert the paths into the double array.
 * @param population - pointer to the array to be filled with individuals.
 * @param popsize - size of the population.
 * @param cn - size of the individuals.
 * @param ppl - pointer to struct POPULATION.
 */
void insert_population_array(int * population[][200], int popsize, int cn, POPULATION *ppl);

/**
 * @param ppd - pointer to the PATH_DYNARRAY struct.
 * @param population - population.
 * @param popsize - size of the population.
 * @param cn - size of the individuals.
 * @return
 */
int determine_fitness(PATH_DYNARRAY *ppd, int population[][200], int popsize, int cn);


/**
 * Function to test the functions for the customers.
 * @return
 */
int testcustomerfunctions();

/**
 * Function to test the functions for the trips.
 * @return
 */
int testfunctionstrip();

/**
 * Function to test the functions for the cities.
 * @return
 */
int testcitiesfunctions();

/**
 * Function to test the functions for the city pols.
 * @return
 */
int testfunctionspols();


/**
 * Main function.
 * @param argc - Number of arguments passed.
 * @param argv - Array with the content of the arguments.
 * @return
 */
int main(int argc, char * argv[]);


#endif //PROJECT_MAIN_H