/*RAINFALL TRACKING.
Write a program to track rainfall data for 3 cities over 4 months.
Using a 2D array, we can store the data, calculate the average rainfall for each city, and display the rainfall data in a tabular format.*/

#include<stdio.h>
int main(){
	float rainfall[3][4];
	float total=0;
	float avg;
	int c,m;
	printf("Name: Ishwari Mulye  PRN: B24CE1107\n");
	printf("\nEnter rainfall data for 3 cities:\n");
	for(c=0;c<3;c++){
		printf("\n  Enter data for city %d",c+1);
		for(m=0;m<4;m++){
			printf("\n Month %d :",m+1);
			scanf("%f",&rainfall[c][m]);
			
		}
		
	}
	printf("\t\t\t\t\t\t\tRainfall Tracking(in mm)");
	printf("\nSr.No \tCityname \tmonth1 \t\tmonth2 \t\tmonth3 \t\tmonth4 \t\tAvg Rainfall\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	

	for(c=0;c<3;c++){
		total=0;
		printf("%d\t",c+1);
		printf("City %d\t",c+1);
		for(m=0;m<4;m++){
			printf("\t%f",rainfall[c][m]);
			total+=rainfall[c][m];
		}
		avg=total/4;
		printf("\t\t %f",avg);
		printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	return 0;
}
		
			






