#include <stdio.h>

int main() {

   float income[100];
float expense[100];
int incomeCount = 0;
int expenseCount = 0;
int choice;
    // ✅ Welcome message (correct place)
    printf("Welcome to Personal Finance Manager!\n");

    while (1)
    {
        printf("\n===== PERSONAL FINANCE MANAGER =====\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. View History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
{
    FILE *fp = fopen("transactions.txt", "a");

    printf("Enter income: ");
    scanf("%f", &income[incomeCount]);

    fprintf(fp, "Income %.2f\n", income[incomeCount]);

    incomeCount++;

    fclose(fp);
    break;
}

                case 2:
{
    FILE *fp = fopen("transactions.txt", "a");

    printf("Enter expense: ");
    scanf("%f", &expense[expenseCount]);

    fprintf(fp, "Expense %.2f\n", expense[expenseCount]);

    expenseCount++;

    fclose(fp);
    break;
}
            

            case 3: {
    float totalIncome = 0, totalExpense = 0;

    for (int i = 0; i < incomeCount; i++)
        totalIncome += income[i];

    for (int i = 0; i < expenseCount; i++)
        totalExpense += expense[i];

    printf("\nBalance: %.2f\n", totalIncome - totalExpense);
    break;
}

            case 4:
    printf("\n===== INCOME HISTORY =====\n");
    for (int i = 0; i < incomeCount; i++)
        printf("+ %.2f\n", income[i]);

    printf("\n===== EXPENSE HISTORY =====\n");
    for (int i = 0; i < expenseCount; i++)
        printf("- %.2f\n", expense[i]);

    break;
    case 5:
    printf("Exiting...\n");
    return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
