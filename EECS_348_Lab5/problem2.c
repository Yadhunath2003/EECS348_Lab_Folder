#include <stdio.h>

void scoreCombinations(int score) {
    const int tdPlus2 = 8;
    const int tdPlus1 = 7;
    const int td = 6;
    const int fg = 3;
    const int safety = 2;

    for (int i1 = 0; i1 < (score / tdPlus2); i1++)
    {
        for (int i2 = 0; i2 < (score / tdPlus2); i2++)
        {
            for (int i3 = 0; i3 < (score / td); i3++)
            {
                for (int i4 = 0; i4 < (score / fg); i4++)
                {
                    for (int i5 = 0; i5 < (score / safety); i5++)
                    {
                        if (((8 * i1) + (7 * i2) + (6 * i3) + (3 * i4) + (2 * i5)) == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", i1, i2, i3, i4, i5);
                        }
                    }
                }
            }
        }
    }
}


int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score == 1 || score == 0) {
            printf("Program terminated.\n");
            break;
        } else if (score < 0){
            printf("Enter values 0 or above.\n");
        }
        else {
            printf("possible combinations of scoring plays:\n");
            scoreCombinations(score);
        }
    }

    return 0;
}
