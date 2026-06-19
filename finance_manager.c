#include <stdio.h>

int main()
{
    int choice;
    float balance = 0.0, income, expense;

    // ✅ Welcome message (correct place)
    printf("Welcome to Personal Finance Manager!\n");

    while (1)
    {
        printf("\n===== PERSONAL FINANCE MANAGER =====\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter income amount: ");
                scanf("%f", &income);
                balance += income;
                printf("Income added successfully!\n");
                break;

            case 2:
                printf("Enter expense amount: ");
                scanf("%f", &expense);
                balance -= expense;
                printf("Expense added successfully!\n");
                break;

            case 3:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;

            case 4:
                printf("Thank you for using Personal Finance Manager!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}