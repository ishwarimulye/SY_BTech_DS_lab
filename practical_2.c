/* Write a program for tracking daily temperatures of 3 cities for a week . 
The program calculates the average temperature for each day and for the week. */

#include <stdio.h>
int main() {
    float temp[3][7];
    int c, d;
    float cityAverage[3], dayAverage[7];
   
    printf("Name: Ishwari Mulye   PRN: B24CE1107\n");
    printf("\nTemperature data for 3 cities over 7 days:\n");
    for (c = 0; c<3; c++) {
        printf("\nEnter temperatures for City %d for 7 days:\n", c + 1);
        for (d = 0; d<7; d++) {
            printf(" Day %d: ", d + 1);
            scanf("%f", &temp[c][d]);
        }
    }

    for (c = 0; c<3; c++) {
        float sum = 0;
        for (d = 0; d<7; d++) {
            sum += temp[c][d];
        }
        cityAverage[c] = sum / 7.0;
    }

    for (d = 0; d<7; d++) {
        float sum = 0;
        for (c = 0; c<3; c++) {
            sum += temp[c][d];
        }
        dayAverage[d] = sum / 3.0;
    }
   
    printf("\n\t\t\t\t\t\t\tTemperature Tracker (in Celsius)");
    printf("\n----------------------------------------------------------------------------");
    printf("\nSr.No\t Day1\tDay2\tDay3\tDay4\tDay5\tDay6\tDay7\tCity Average\n");
    printf("----------------------------------------------------------------------------\n");
    for (c = 0; c<3; c++) {
        printf("%d\t", c + 1);
        for (d = 0; d<7; d++) {
            printf("%.2f\t", temp[c][d]);
        }
        printf("%.2f\n", cityAverage[c]);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("Day Avg\t");
    for (d = 0; d<7; d++) {
        printf("%.2f\t", dayAverage[d]);
    }
    printf("\n");

    return 0;
}
