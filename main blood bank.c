#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void newdata();
void list_of_donor();
void search_donor();

struct
{
  char d_name[25] ;
  int d_age;
  char d_bgrp[10];
  char d_contactinfo[25];
  char d_address[500];
  char d_recentbd[20];
}donor_data;

//initializing the files used in the program

FILE *Donor_data_record;
int main()
{
    int choice=0;

    printf("\n\t\t---BLOOD BANK MANAGEMENT SYSTEM---\n");
    printf("\n\t\t---DONATE BLOOD SAVE LIFE---\n");
    do{
    printf("\n\t--MENU--\n \n 1. To add new data\n 2. To view list of donor\n 3. To search donor\n 4.Exit the program\n\n\t Enter your choice <1-4>: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            newdata();
            break;
        case 2:
            list_of_donor();
            break;
        case 3:
            search_donor();
            break;
        case 4:
            exit(0);
        default:
            printf(" ! Invalid Input...\n");
    }
}while(choice!=4);
 return (0);
}

void newdata()
{
//	printf("please enter the donor info if age is only between (18-50) and minimum gap period of 3 months of recent Blood Donation ")
    Donor_data_record = fopen("Donor_data_record.txt","a+");
    printf("Enter The Name : ");
        scanf("%s",donor_data.d_name);
    printf("Enter The Age : ");
        scanf("%d",&donor_data.d_age);
    printf("Enter The Blood group : ");
        scanf("%s",donor_data.d_bgrp);
    printf("Contact info: ");
        scanf("%s",donor_data.d_contactinfo);
    printf("Enter the Address: ");
        scanf("%s",donor_data.d_address);
    printf("Recent Blood donation date: ");
        scanf("%s",donor_data.d_recentbd);
    fprintf(Donor_data_record,"\n%s\t%d\t%s\t%s\t%s\t%s",donor_data.d_name,donor_data.d_age,donor_data.d_bgrp,donor_data.d_contactinfo,donor_data.d_address,donor_data.d_recentbd);
    fclose(Donor_data_record);
    printf("New Donor data has been Added Successfully...\n");

}

void list_of_donor()
{
	Donor_data_record = fopen("Donor_data_record.txt","a+");
    printf("\nName\tAge\tBlood group\tContact info\tAddress\t\tRececnt Blood Donation Date\n");
    while(!feof(Donor_data_record))
    {
    	fscanf(Donor_data_record,"%s%d%s%s%s%s",donor_data.d_name,&donor_data.d_age,donor_data.d_bgrp,donor_data.d_contactinfo,donor_data.d_address,donor_data.d_recentbd);
    	printf("%s\t%d\t%s\t\t%s\t\t%s\t\t%s\n",donor_data.d_name,donor_data.d_age,donor_data.d_bgrp,donor_data.d_contactinfo,donor_data.d_address,donor_data.d_recentbd);
    }+
    fclose(Donor_data_record);
}

void search_donor(char *bgrp)
{
	int i;
    int Found=0;
    Donor_data_record=fopen("Donor_data_record.txt","r");
        while(!feof(Donor_data_record))
        {
            fscanf(Donor_data_record,"%s%d%s%s%s%s",donor_data.d_name,&donor_data.d_age,donor_data.d_bgrp,donor_data.d_contactinfo,donor_data.d_address,donor_data.d_recentbd);
            if(strcmp(bgrp,donor_data.d_bgrp)==0)
            {
            	Found=1;
            }
        }
        fclose(Donor_data_record);
        if(!Found)
        return 0;
        else
        return 1;
}
