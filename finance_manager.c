#include <stdio.h>
#include<string.h>
struct Transaction
{
    float amount;
    char type[10];
    char category[20];
};
int main() {

   float income[100];
float expense[100];
char category[100][20];
int incomeCount = 0;
int expenseCount = 0;
int choice;

FILE *fp = fopen("transactions.txt", "r");

    if(fp != NULL)
{
    char type[20];
    char cat[20];
    float amount;

    while(fscanf(fp, "%s %f", type, &amount) == 2)
    {
        if(type[0] == 'I')
        {
            income[incomeCount++] = amount;
        }
        else if(type[0] == 'E')
        {
            fscanf(fp, "%s", cat);

            expense[expenseCount] = amount;

            strcpy(category[expenseCount], cat);

            expenseCount++;
        }
    }

    fclose(fp);
}


    // ✅ Welcome message (correct place)
    printf("Welcome to Personal Finance Manager!\n");

    while (1)
    {
        printf("\n===== PERSONAL FINANCE MANAGER =====\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. View History\n");
        printf("5. Clear History\n");
        printf("6. Search By Category\n");
        printf("7. Search By Amount\n");
        printf("8. Exit\n");   
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
    int catChoice;

    FILE *fp = fopen("transactions.txt", "a");

    printf("Enter expense: ");
    scanf("%f", &expense[expenseCount]);

    printf("\nChoose Category:\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Shopping\n");
    printf("4. Education\n");
    printf("5. Medicine\n");
    printf("6. Entertainment\n");
    printf("7. Other\n");

    printf("Enter category choice: ");
    scanf("%d", &catChoice);

    switch(catChoice)
    {
        case 1:
            strcpy(category[expenseCount], "Food");
            break;

        case 2:
            strcpy(category[expenseCount], "Travel");
            break;

        case 3:
            strcpy(category[expenseCount], "Shopping");
            break;

        case 4:
            strcpy(category[expenseCount], "Education");
            break;

        case 5:
            strcpy(category[expenseCount], "Medicine");
            break;

        case 6:
            strcpy(category[expenseCount], "Entertainment");
            break;

        default:
            strcpy(category[expenseCount], "Other");
    }

    fprintf(fp, "Expense %.2f %s\n",
            expense[expenseCount],
            category[expenseCount]);

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
        printf("- %.2f (%s)\n",
               expense[i],
               category[i]);

    break;
    case 5:
{
    FILE *fp = fopen("transactions.txt", "w");

    fclose(fp);

    incomeCount = 0;
    expenseCount = 0;

    printf("Transaction history cleared successfully!\n");
    break;
}
    case 6:
{
    char search[20];
    int found = 0;

    printf("Enter category: ");
    scanf("%s", search);

    printf("\nMatching Transactions:\n");

    for(int i = 0; i < expenseCount; i++)
    {
        if(strcmp(category[i], search) == 0)
        {
            printf("- %.2f (%s)\n",
                   expense[i],
                   category[i]);
            found = 1;
        }
    }

    if(found == 0)
        printf("No transactions found!\n");

    break;

}
case 7:
{
    float searchAmount;
    int found = 0;

    printf("Enter amount to search: ");
    scanf("%f", &searchAmount);

    printf("\nMatching Transactions:\n");

    for(int i = 0; i < incomeCount; i++)
    {
        if(income[i] == searchAmount)
        {
            printf("+ %.2f\n", income[i]);
            found = 1;
        }
    }

    for(int i = 0; i < expenseCount; i++)
    {
        if(expense[i] == searchAmount)
        {
            printf("- %.2f (%s)\n",
                   expense[i],
                   category[i]);
            found = 1;
        }
    }

    if(found == 0)
        printf("No transactions found!\n");

    break;
}
case 8:
    printf("Exiting...\n");
    return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
