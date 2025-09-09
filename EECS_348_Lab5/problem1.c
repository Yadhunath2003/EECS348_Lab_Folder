#include <stdio.h>
#include <string.h>

#define NO_OF_MONTHS 12
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(){
    float sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    salesReport(sales);
    salesSummary(sales);
    sixMonthAvg(sales, months);
    descendingSalesReport(sales);
}

void salesReport(float sales[]){
    printf("Monthly sales report 2022: \n");
    printf("%-15s%-15s\n","Month","Sales");
    for (int i = 0; i < NO_OF_MONTHS; i++){
        printf("%-15s$%.2f\n", months[i], sales[i]);
    }
}

void salesSummary(float sales[]){
    float minSales = sales[0];
    float maxSales = sales[0];
    char *minMonth = months[0];
    char *maxMonth = months[0];
    float total = sales[0];

    for (int i = 0; i < NO_OF_MONTHS; i++){
        if (sales[i] < minSales){
            minSales = sales[i];
            minMonth = months[i];
        }
        else if (sales[i] > maxSales){
            maxSales = sales[i];
            maxMonth = months[i];
        }

        total += sales[i];
    }

    float average = total / NO_OF_MONTHS;
    
    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, minMonth);
    printf("Maximum Sales: $%.2f (%s)\n", maxSales, maxMonth);
    printf("Average sales: $%.2f\n", average);

}

void sixMonthAvg(float sales[0], char *months[]){

    printf("\n Six-Month Moving Average Report:\n");

    for (int i = 0; i <= NO_OF_MONTHS - 6; ++i){
        float total = 0;
        for (int j = i; j < i + 6; ++j){
            total += sales[j];
        }
        float average = total / 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], average);
    }
}

void descendingSalesReport(float sales[]) {
    
    printf("\nSales Report (Highest to Lowest):\n");

    int sortedIndices[NO_OF_MONTHS];

    for (int i = 0; i < NO_OF_MONTHS; i++) {
        sortedIndices[i] = i;
    }

    for (int i = 0; i < NO_OF_MONTHS - 1; i++) {
        for (int j = i + 1; j < NO_OF_MONTHS; j++) {
            if (sales[sortedIndices[i]] < sales[sortedIndices[j]]) {
                int temp = sortedIndices[i];
                sortedIndices[i] = sortedIndices[j];
                sortedIndices[j] = temp;
            }
        }
    }

    for (int i = 0; i < NO_OF_MONTHS; i++) {
        printf("%s - $%.2f\n", months[sortedIndices[i]], sales[sortedIndices[i]]);
    }
}


