

//play code - using pointers to point TO structure; page 262-263
//****** 3 DIFFERENT WAYS TO REFERENCE A STRUCTURE USING POINTERS...
//****** EXPANDED CODE TO MAKE THE STRUCTURE ITSELF INTO AN
//****** ARRAY[3] AND THEN REFERENCE EACH "ELEMENT"... BUT NOT THIS EXAMPLE... MAYBE NEXT ONE
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sale {
    char *p_customer;
    char *p_item;
    char name[10];
    float amount;
} mysale[3];

int count = 0;

int main(void)
{
    FILE *fp;
    fp = fopen("kamfile4.txt","w");
    if(fp!=NULL)
    {
        fputs("\n\n",fp);
        fputs("fopen OK\n\n",fp);
    }
    else
    {
        fprintf(stderr,"Error opening file %s",fp);
        exit(1);
    }
    //declare pointer to structure
    struct sale *p_sale;

    //instance mysale was already declared for structure above
    //...now the pointer to the structure must be initialized
    //p_sale = &mysale[0];  //next line also works to assign address to pointer
                            // because an array without [] indicates the address
                            // of the first element of said array
    p_sale = mysale;


    //*************  Element [0]
    strcpy(mysale[0].name,"Karen");   // must use strcpy because mysale.name is defined as array
                                      // mysale.name = "karen" does NOT work
                                      // mysale[0].name = "karen" does NOT work either

    mysale[0].p_customer = "Crazy Town Supplies";
    mysale[0].p_item = "Highlighters with Pizzazz";
    mysale[0].amount = 34.12;
    printf("Info by str.mem is: %s, %s, %f, %s", mysale[0].p_customer, mysale[0].p_item, mysale[0].amount, mysale[0].name);
    printf("\n");
    fprintf(fp,"Info by str.mem is: %s, %s, %f, %s", mysale[0].p_customer, mysale[0].p_item, mysale[0].amount, mysale[0].name);
    fprintf(fp,"\n");

    //*************  Element [1]
    p_sale++; //increment to point to second element in structure

    strcpy((*p_sale).name,"Erik");
    (*p_sale).p_customer = "2nd Try Robotics";
    (*p_sale).p_item = "Geres for Geeks";
    (*p_sale).amount = 77.13;
    printf("Info by (*ptr).mem is: %s, %s, %f, %s", (*p_sale).p_customer,(*p_sale).p_item, (*p_sale).amount, (*p_sale).name);
    printf("\n");
    fprintf(fp,"Info by (*ptr).mem is: %s, %s, %f, %s", (*p_sale).p_customer,(*p_sale).p_item, (*p_sale).amount, (*p_sale).name);
    fprintf(fp,"\n");

    //*************  Element [2]
    p_sale++; //increment to point to third element in structure

    strcpy(p_sale->name,"Kelly");
    p_sale->p_customer = "Art for Nerds";
    p_sale->p_item = "Monet Pictures";
    p_sale->amount = 99.15;
    printf("Info by ptr->mem is: %s, %s, %f, %s", p_sale->p_customer, p_sale->p_item, p_sale->amount, p_sale->name);
    printf("\n\n");
    fprintf(fp,"Info by ptr->mem is: %s, %s, %f, %s", p_sale->p_customer, p_sale->p_item, p_sale->amount, p_sale->name);
    fprintf(fp,"\n\n");

    //loop to print out full contents of structure array all at once
    p_sale = &mysale[0];
    printf("\n**** Printing out entire array - should be same as previous data ****\n\n");
    fprintf(fp,"\n**** Printing out entire array - should be same as previous data ****\n\n");
    for (count=0; count<3; count++)
    {
        printf("Info is: %s, %s, %f, %s", p_sale->p_customer, p_sale->p_item, p_sale->amount, p_sale->name);
        printf("\n");
        fprintf(fp,"Info is: %s, %s, %f, %s", p_sale->p_customer, p_sale->p_item, p_sale->amount, p_sale->name);
        fprintf(fp,"\n");
        p_sale++;
    }
    printf("\n\n");
    fprintf(fp,"\n\n");

    return 0;
}
