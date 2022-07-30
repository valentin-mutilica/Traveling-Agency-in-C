//
// Created by valen on 30-Dec-21.
//
#include "main.h"


void insert_customer_ordered(CUSTOMER_LIST *cl, int userid, int vat, int birthday, int birthmonth, int birthyear, int regday, int regmonth, int regyear, char phonenumber[20], char name[20], char email[30], char address[100]){
    CUSTOMER_NODE *cn = (CUSTOMER_NODE *) malloc(sizeof(CUSTOMER_NODE));
    TRIPS_ARRAY * tripsarray = (TRIPS_ARRAY *) malloc(sizeof(TRIPS_ARRAY));
    cn->c.userid = userid;
    cn->c.vat = vat;
    cn->c.birthdate.day = birthday;
    cn->c.birthdate.month = birthmonth;
    cn->c.birthdate.year = birthyear;
    cn->c.regdate.day = regday;
    cn->c.regdate.month = regmonth;
    cn->c.regdate.year = regyear;
    strcpy(cn->c.phonenumber, phonenumber);
    strcpy(cn->c.name, name);
    strcpy(cn->c.email, email);
    strcpy(cn->c.address, address);
    cn->pnext = NULL;


    //...................................FIRST........
    if (cl->ncustomers == 0 || cl->pcustomers == NULL) {
        cl->pcustomers = cn;
        cl->ncustomers++;
        return;
    }

    //...................................HEAD INSERTION........

    /*Looking for the next head*/
    CUSTOMER_NODE *pcurrent = cl->pcustomers, *pprev=NULL;
    while (pcurrent != NULL && pcurrent->c.userid != 0) {
        pprev = pcurrent;
        pcurrent = pcurrent->pnext;
    }
    //Insertion at the head found previously
    if (pcurrent == cl->pcustomers) {
        cn->pnext = cl->pcustomers;
        cl->pcustomers = cn;
        cl->ncustomers++;
        return;
    }

    //...................................TAIL INSERTION.............

    //Tail insertion
    if (pcurrent == NULL){
        pprev->pnext = cn;
        cn->pnext= NULL;
        cl->ncustomers++;
        return;
    }

        //Middle insertion (Between First and Tail, not middle)
    else {
        cn->pnext = pcurrent;
        pprev->pnext = cn;
        cl->ncustomers++;
        return;
    }
}

void insert_customer(CUSTOMER_LIST *cl, CUSTOMER * customer){
    CUSTOMER_NODE *cn = (CUSTOMER_NODE *) malloc(sizeof(CUSTOMER_NODE));
    TRIPS_ARRAY * tripsarray = (TRIPS_ARRAY *) malloc(sizeof(TRIPS_ARRAY));
    cn->c.userid = customer->userid;
    cn->c.vat = customer->vat;
    cn->c.birthdate.day = customer->birthdate.day;
    cn->c.birthdate.month = customer->birthdate.month;
    cn->c.birthdate.year = customer->birthdate.year;
    cn->c.regdate.day = customer->regdate.day;
    cn->c.regdate.month = customer->regdate.month;
    cn->c.regdate.year = customer->regdate.year;
    strcpy(cn->c.phonenumber, customer->phonenumber);
    strcpy(cn->c.name, customer->name);
    strcpy(cn->c.email, customer->email);
    strcpy(cn->c.address, customer->address);
    cn->pnext = NULL;

    //...................................FIRST........
    if (cl->ncustomers == 0 || cl->pcustomers == NULL) {
        cl->pcustomers = cn;
        cl->ncustomers++;
        return;
    }

    //...................................HEAD INSERTION........

    /*Looking for the next head*/
    CUSTOMER_NODE *pcurrent = cl->pcustomers, *pprev=NULL;
    while (pcurrent != NULL && pcurrent->c.userid != 0) {
        pprev = pcurrent;
        pcurrent = pcurrent->pnext;
    }
    //Insertion at the head found previously
    if (pcurrent == cl->pcustomers) {
        cn->pnext = cl->pcustomers;
        cl->pcustomers = cn;
        cl->ncustomers++;
        return;
    }

    //...................................TAIL INSERTION.............

    //Tail insertion
    if (pcurrent == NULL){
        pprev->pnext = cn;
        cn->pnext= NULL;
        cl->ncustomers++;
        return;
    }

        //Middle insertion (Between First and Tail, not middle)
    else {
        cn->pnext = pcurrent;
        pprev->pnext = cn;
        cl->ncustomers++;
        return;
    }
}

void insert_customer_head(CUSTOMER_LIST *cl, CUSTOMER * customer){
    CUSTOMER_NODE *cn = (CUSTOMER_NODE *) malloc(sizeof(CUSTOMER_NODE));
    TRIPS_ARRAY * tripsarray = (TRIPS_ARRAY *) malloc(sizeof(TRIPS_ARRAY));
    cn->c.userid = customer->userid;
    cn->c.vat = customer->vat;
    cn->c.birthdate.day = customer->birthdate.day;
    cn->c.birthdate.month = customer->birthdate.month;
    cn->c.birthdate.year = customer->birthdate.year;
    cn->c.regdate.day = customer->regdate.day;
    cn->c.regdate.month = customer->regdate.month;
    cn->c.regdate.year = customer->regdate.year;
    strcpy(cn->c.phonenumber, customer->phonenumber);
    strcpy(cn->c.name, customer->name);
    strcpy(cn->c.email, customer->email);
    strcpy(cn->c.address, customer->address);
    cn->pnext = NULL;

    //...................................FIRST........
    if (cl->ncustomers == 0 || cl->pcustomers == NULL) {
        cl->pcustomers = cn;
        cl->ncustomers++;
        return;
    }
}

void insert_customer_tail(CUSTOMER_LIST *cl, CUSTOMER * customer){
    CUSTOMER_NODE *cn = (CUSTOMER_NODE *) malloc(sizeof(CUSTOMER_NODE));
    TRIPS_ARRAY * tripsarray = (TRIPS_ARRAY *) malloc(sizeof(TRIPS_ARRAY));
    cn->c.userid = customer->userid;
    cn->c.vat = customer->vat;
    cn->c.birthdate.day = customer->birthdate.day;
    cn->c.birthdate.month = customer->birthdate.month;
    cn->c.birthdate.year = customer->birthdate.year;
    cn->c.regdate.day = customer->regdate.day;
    cn->c.regdate.month = customer->regdate.month;
    cn->c.regdate.year = customer->regdate.year;
    strcpy(cn->c.phonenumber, customer->phonenumber);
    strcpy(cn->c.name, customer->name);
    strcpy(cn->c.email, customer->email);
    strcpy(cn->c.address, customer->address);
    cn->pnext = NULL;

    //...................................TAIL INSERTION.............
    /*Looking for the next head*/
    CUSTOMER_NODE *pcurrent = cl->pcustomers, *pprev=NULL;
    while (pcurrent != NULL && pcurrent->c.userid != 0) {
        pprev = pcurrent;
        pcurrent = pcurrent->pnext;
    }

    //Tail insertion
    if (pcurrent == NULL){
        pprev->pnext = cn;
        cn->pnext= NULL;
        cl->ncustomers++;
        return;
    }
}

void printCustomers(CUSTOMER_LIST * customerlist)
{
    CUSTOMER_NODE * node = customerlist->pcustomers;
    while (node != NULL) {
        printf("\nUser ID: %d\n", node->c.userid);
        printf("Name: %s\n",node->c.name);
        printf("VAT: %d\n", node->c.vat);
        printf("Birthdate: %d %d %d\n", node->c.birthdate.day, node->c.birthdate.month, node->c.birthdate.year);
        printf("Date of registration: %d %d %d\n", node->c.regdate.day, node->c.regdate.month, node->c.regdate.year);
        printf("Phone Number: %s\n", node->c.phonenumber);
        printf("E-Mail: %s\n", node->c.email);
        printf("Address: %s\n", node->c.address);
        node = node->pnext;
    }
    printf("\n");
}

//Does not work
void delete_customer(CUSTOMER_LIST * cl, char name[]){
    CUSTOMER_NODE * cnode = cl->pcustomers;

    // If linked list is empty
    if (cl->pcustomers == NULL) {
        printf("No customers in this list");
        return;
    }
    // If the customer does not exist
    if (strcmp(cnode->c.name, name)==0){
        printf("Customer %s does not exist!\n", name);
        return;
    }

    CUSTOMER_NODE *ccurrent = cl->pcustomers, *pprev=NULL;
    for(int i=0; i<cl->ncustomers; i++) {
        if (strcmp(ccurrent->c.name, name) == 1) {
            pprev->pnext = ccurrent->pnext;
            free(ccurrent);
            cl->pcustomers = cl->pcustomers->pnext;
            printf("The customer has been deleted successfully");
            return;
        }
    }
    free(ccurrent); // Free memory
}

int search_by_vat(CUSTOMER_LIST * customers, int vat)
{
    CUSTOMER_NODE * pcurrent = customers->pcustomers;  // Initialize current
    while (pcurrent != NULL) {
        if (pcurrent->c.vat == vat) {
            printf("We have successfully found the vat in the database and the user has the following data: \n");
            printf("User ID: %d\n", customers->pcustomers->c.userid);
            printf("Name: %s\n",customers->pcustomers->c.name);
            printf("VAT: %d\n", customers->pcustomers->c.vat);
            printf("Birthdate: %d %d %d\n", customers->pcustomers->c.birthdate.day, customers->pcustomers->c.birthdate.month, customers->pcustomers->c.birthdate.year);
            printf("Date of registration: %d %d %d\n", customers->pcustomers->c.regdate.day, customers->pcustomers->c.regdate.month, customers->pcustomers->c.regdate.year);
            printf("Phone Number: %s\n", customers->pcustomers->c.phonenumber);
            printf("E-Mail: %s\n", customers->pcustomers->c.email);
            printf("Address: %s\n \n", customers->pcustomers->c.address);
            return 1;
        }
        pcurrent = pcurrent->pnext;
    }
    printf("We could not find the vat in the database~\n \n");
    return 0;
}

int search_by_userid(CUSTOMER_LIST * customers, int id)
{
    CUSTOMER_NODE * pcurrent = customers->pcustomers;  // Initialize current
    while (pcurrent != NULL) {
        if (pcurrent->c.userid == id) {
            printf("We have successfully found the ID number in the database and the user has the following details~\n");
            printf("User ID: %d\n", customers->pcustomers->c.userid);
            printf("Name: %s\n",customers->pcustomers->c.name);
            printf("VAT: %d\n", customers->pcustomers->c.vat);
            printf("Birthdate: %d %d %d\n", customers->pcustomers->c.birthdate.day, customers->pcustomers->c.birthdate.month, customers->pcustomers->c.birthdate.year);
            printf("Date of registration: %d %d %d\n", customers->pcustomers->c.regdate.day, customers->pcustomers->c.regdate.month, customers->pcustomers->c.regdate.year);
            printf("Phone Number: %s\n", customers->pcustomers->c.phonenumber);
            printf("E-Mail: %s\n", customers->pcustomers->c.email);
            printf("Address: %s\n \n", customers->pcustomers->c.address);
            return 1;
        }
        pcurrent = pcurrent->pnext;
    }
    printf("We could not find the ID number in the database~\n \n");
    return 0;
}

//Does not work, file error
void write_in_file_customer(CUSTOMER_LIST * pc, char fn[]){
    FILE *fptr;
    fptr = fopen(fn, "w");

    if(fptr==NULL){
        printf("ERROR OPENING FILE...%s\n", fn);
        return;
    }
    fprintf(fptr, "VOila");
    fprintf(fptr, "Number of customers: %d \n", pc->ncustomers);

    /*for (int i=0; i<pc->ncustomers; i++) {
        fprintf(fptr, "User ID: %d\n", pc->pcustomers->c.userid);
        fprintf(fptr, "VAT: %d\n", pc->pcustomers->c.vat);
        fprintf(fptr, "Customer Name: %s\n", pc->pcustomers->c.name);
        fprintf(fptr, "Birth Date: %d %d %d\n", pc->pcustomers->c.birthdate.day, pc->pcustomers->c.birthdate.month, pc->pcustomers->c.birthdate.year);
        fprintf(fptr, "Registration Date: %d %d %d\n", pc->pcustomers->c.birthdate.day, pc->pcustomers->c.birthdate.month, pc->pcustomers->c.birthdate.year);
        fprintf(fptr, "Phone number: %s\n", pc->pcustomers->c.phonenumber);
        fprintf(fptr, "Email address: %s\n", pc->pcustomers->c.email);
        fprintf(fptr, "Address: %s\n", pc->pcustomers->c.address);
        fprintf(fptr, "Trips: %s", pc->pcustomers->c.TripsCustomer->ptrips->tripname);
        pc->pcustomers = pc->pcustomers->pnext;
    }*/
    fclose(fptr);
}

//Does not work, file error
void read_from_file_customer(CUSTOMER_LIST * currentlist, char filename[]){
    FILE *fptr;
    fptr = (fopen("C:\\customers.txt", "r"));
    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    int customers = 0;
    fscanf(fptr, "%*s%d", &customers);
    int userid = 0;
    int vat = 0;
    char name[25];
    DATE birthdate;
    DATE regdate;
    char phonenumber[20];
    char email[30];
    char address[100];

    for(int i=0; i<customers; i++) {
        fscanf(fptr, "%*s%d, %*s%d, %*s%s %*s%d %d %d, %*s%d %d %d, %*s%s, %*s%s, %*s%s",
               &userid, &vat, name, &birthdate.day, &birthdate.month, &birthdate.year, &regdate.day, &regdate.month,
               &regdate.year, phonenumber, email, address);
        insert_customer_ordered(&(*currentlist), userid, vat, birthdate.day, birthdate.month, birthdate.year, regdate.day, regdate.month, regdate.year, phonenumber, name, email, address);
        customers++;
    }
    fclose(fptr);
}

//Does not work, file error
void write_in_file_customer_binary(CUSTOMER_LIST * cl, char fn[]){
    FILE *fptr;
    CUSTOMER_NODE * customer = cl->pcustomers;
    fptr = (fopen("C:\\customersbinary.txt", "bw"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }

    int sizename = strlen(customer->c.name+1);
    fwrite(&sizename, sizeof(int), 1, fptr);
    fwrite(customer->c.name, sizeof(char), sizename, fptr);

    int sizeemail = strlen(customer->c.email + 1);
    fwrite(&sizeemail, sizeof(int), 1, fptr);
    fwrite(customer->c.name, sizeof(char), sizeemail, fptr);

    int sizeaddress = strlen(customer->c.address + 1);
    fwrite(&sizeaddress, sizeof(int), 1, fptr);
    fwrite(customer->c.name, sizeof(char), sizeaddress, fptr);

    int sizepnumber = strlen(customer->c.phonenumber + 1);
    fwrite(&sizepnumber, sizeof(int), 1, fptr);
    fwrite(customer->c.phonenumber, sizeof(char), sizepnumber, fptr);

    fwrite(&cl->ncustomers, sizeof(int), 1, fptr);

    for (int i = 0; i < cl->ncustomers; i++) {
        fwrite(&(cl->pcustomers->c.userid), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.vat), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.name), sizeof(char), sizename, fptr);
        fwrite(&(cl->pcustomers->c.birthdate.day), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.birthdate.month), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.birthdate.year), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.regdate.day), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.regdate.month), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.regdate.year), sizeof(int), 1, fptr);
        fwrite(&(cl->pcustomers->c.phonenumber), sizeof(char), sizepnumber, fptr);
        fwrite(cl->pcustomers->c.email, sizeof(char), sizeemail, fptr);
        fwrite(cl->pcustomers->c.address, sizeof(char), sizeaddress, fptr);
        cl->pcustomers = cl->pcustomers->pnext;
    }

    fclose(fptr);
}

//Does not work, file error
void read_from_file_customer_binary(CUSTOMER_LIST * pc, char fn[]) {
    FILE *fptr;
    CUSTOMER_NODE * customer = pc->pcustomers;
    fptr = (fopen("C:\\customersbinary.txt", "br"));

    if (fptr == NULL) {
        printf("ERROR...%s\n", fn);
        return;
    }
    int sizename = 0;
    int sizeemail= 0;
    int sizeaddress = 0;
    int sizepnumber = 0;
    fread(&sizename, sizeof(int), 1, fptr);
    fread(&sizeemail, sizeof(int), 1, fptr);
    fread(&sizeaddress, sizeof(int), 1, fptr);
    fread(&sizepnumber, sizeof(int), 1, fptr);
    int ncustomers = 0;

    fread(&ncustomers, sizeof(int), 1, fptr);
    fread(&pc->ncustomers, sizeof(int), ncustomers, fptr);


    for (int i = 0; i < ncustomers; i++) {
        fread(&(customer->c.userid), sizeof(int), 1, fptr);
        fread(&(customer->c.vat), sizeof(int), 1, fptr);
        fread(customer->c.name, sizeof(char), sizename, fptr);
        fread(&(customer->c.birthdate.day), sizeof(int), 1, fptr);
        fread(&(customer->c.birthdate.month), sizeof(int), 1, fptr);
        fread(&(customer->c.birthdate.year), sizeof(int), 1, fptr);
        fread(&(customer->c.regdate.day), sizeof(int), 1, fptr);
        fread(&(customer->c.regdate.month), sizeof(int), 1, fptr);
        fread(&(customer->c.regdate.year), sizeof(int), 1, fptr);
        fread(customer->c.phonenumber, sizeof(long long), sizepnumber, fptr);
        fread(customer->c.email, sizeof(char), sizeemail, fptr);
        fread(customer->c.address, sizeof(char), sizeaddress, fptr);
        ncustomers++;
    }
    fclose(fptr);
}

//Does not work, file error
void generate_report_customer_(CUSTOMER_LIST * cl, const char customer[], char fn[]){
    TRIPS_ARRAY * customertrips = cl->pcustomers->customertrips;
    FILE *fptr;
    fptr = (fopen("C:\\customers.txt", "w"));

    if(fptr==NULL){
        printf("ERROR...%s\n", fn);
        return;
    }

    if (cl->pcustomers->c.name == customer) {
        fprintf(fptr, "The customer %s has the following details in the data base: \n", cl->pcustomers->c.name);
        fprintf(fptr, "User ID: %d\n", cl->pcustomers->c.userid);
        fprintf(fptr, "VAT: %d\n", cl->pcustomers->c.vat);
        fprintf(fptr, "Birth Date: %d.%d.%d\n", cl->pcustomers->c.birthdate.day, cl->pcustomers->c.birthdate.month, cl->pcustomers->c.birthdate.year);
        fprintf(fptr, "Registration Date: %d.%d.%d\n", cl->pcustomers->c.regdate.day, cl->pcustomers->c.regdate.month, cl->pcustomers->c.regdate.year);
        fprintf(fptr, "Phone number: %s\n", cl->pcustomers->c.phonenumber);
        fprintf(fptr, "Email address: %s\n", cl->pcustomers->c.email);
        fprintf(fptr, "Address: %s\n", cl->pcustomers->c.address);
    }

    if(customertrips->ptrips->customername == customer){
    }
        fprintf(fptr, "Trips: %d\n", customertrips->current_number_trips);
        for(int i = 0; i<= customertrips->current_number_trips; i++){
            fprintf(fptr, "Trip name %s\n", customertrips->ptrips->tripname);
            for(int j = 0; j<=customertrips->ptrips->destinations->size_cities; j++){
                fprintf(fptr, "City: %s\n", customertrips->ptrips->destinations->pcities->cityname);
                fprintf(fptr, "Description: %s\n", customertrips->ptrips->destinations->pcities->description);
                for(int k = 0; k<= j<=customertrips->ptrips->destinations->pcities->citypol->npols; k++){
                    fprintf(fptr, "Point of interest: %s\n", customertrips->ptrips->destinations->pcities->citypol->ppol->polname);
                    fprintf(fptr, "POI Description: %s\n", customertrips->ptrips->destinations->pcities->citypol->ppol->description);
                }
            }
        }

    fclose(fptr);
}

void swap_customers(CUSTOMER_NODE *a, CUSTOMER_NODE *b)
{
    CUSTOMER temp = a->c;
    a->c = b->c;
    b->c = temp;
}

void vatSort(CUSTOMER_LIST * customerlist)
{
    CUSTOMER_NODE * start = customerlist->pcustomers;
    int changedcustomer, i;
    CUSTOMER_NODE *ptr1;
    CUSTOMER_NODE *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {   changedcustomer = 0;
        ptr1 = start;

        while (ptr1->pnext != lptr)
        {
            if (ptr1->c.vat > ptr1->pnext->c.vat)
            {   swap_customers(ptr1, ptr1->pnext);
                changedcustomer = 1;
            }
            ptr1 = ptr1->pnext;
        }
        lptr = ptr1;
    }
    while (changedcustomer);
}

void useridSort(CUSTOMER_LIST * customerlist)
{
    CUSTOMER_NODE * start = customerlist->pcustomers;
    int changedcustomer, i;
    CUSTOMER_NODE *ptr1;
    CUSTOMER_NODE *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {   changedcustomer = 0;
        ptr1 = start;

        while (ptr1->pnext != lptr)
        {
            if (ptr1->c.userid > ptr1->pnext->c.userid)
            {   swap_customers(ptr1, ptr1->pnext);
                changedcustomer = 1;
            }
            ptr1 = ptr1->pnext;
        }
        lptr = ptr1;
    }
    while (changedcustomer);
}

int testcustomerfunctions(){
    char fn[]="C:\\Project\\PROJECT\\customers.txt";
    CUSTOMER_LIST customers = {NULL, 0};
    CUSTOMER c1 = {12, 548643612, "Alex", 20, 9, 2000, 16, 8, 2019, "07464954439", " ", " "};
    CUSTOMER c2 = {11, 498643112, "Maia", 20, 9, 2000, 16, 8, 2019, "0745454439", " ", " "};
    CUSTOMER c3 = {10, 328643612, "Henrique", 20, 9, 2000, 16, 8, 2019, "07464954439", " ", " "};
    insert_customer_head(&customers, &c1);
    insert_customer(&customers, &c3);
    insert_customer_tail(&customers, &c2);
    printCustomers(&customers);
    search_by_vat(&customers, 548643612);
    search_by_vat(&customers, 548643613);
    search_by_userid(&customers, 11);
    search_by_userid(&customers, 1);
    //delete_customer(&customers, "Antonia");
    vatSort(&customers);
    printf("Customers after VAT sorting: \n");
    printCustomers(&customers);
    useridSort(&customers);
    printf("Customers after user ID sorting: \n");
    printCustomers(&customers);
    //generate_report_customer_(&customers, "Alex", fn);
    write_in_file_customer(&customers, fn);
    //read_from_file_customer(&customers, fn);
    //write_in_file_customer_binary(&customers, "C:\\Project\\PROJECT\\customers.bin");


    return 0;
}