#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int inc, emi, rent, util, ins, rem, debt;
void budget();
int savings();
void lifestyle();
void score();
void balanced();
void debtratio();
void warning();

int main()
{
    printf("=====================================================\n");
    printf("              ** PERSONAL FINANCE TOOL **\n");
    printf("=====================================================\n\n\n");
    int choice;
    printf("Enter your Monthly Income:\nRs.");
    scanf("%d", &inc);
    if (inc <= 0)
    {
        printf("invalid:your income is zero");
        return 0;
    }
    printf("We need to Know your fixed Expenses : \n");
    printf("Enter your monthly expense on  EMI's if any  ");
    scanf("%d", &emi);
    printf("\nEnter your monthly expense on Rent if any  ");
    scanf("%d", &rent);
    printf("\nEnter your monthly expense on utilities  ");
    scanf("%d", &util);
    printf("\nEnter your monthly expense on insurances if any  ");
    scanf("%d", &ins);
    rem = inc - emi - rent - util - ins;

    warning();

    if (rem <= inc * 0.05)
    {
        printf("invalid:your Disposable amount is too low");
        return 0;
    }
    printf("Choose the function you want to access:\n1.Build a Budget\n2.Financial score\n3.Debt Ratio\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        budget();
        break;
    case 2:
        score();
        break;
    case 3:
        debtratio();
        break;
    }
}
void budget()
{
    int choice;
    system("clear");
    printf("--------------------------------------------\n");
    printf("            BUILD A BUDGET\n");
    printf("--------------------------------------------\n\n");
    printf("Choose the function you want to access:\n1.Savings Oriented\n2.Lifestyle Oriented\n3.Balanced\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        savings();
        break;
    case 2:
        lifestyle();
        break;
    case 3:
        balanced();
        break;
    }
}

int savings()
{
    int save, time, per, a;
    float permon;

    printf("How much money are you trying to save:\n");
    scanf("%d", &save);
    printf("What percent of your disposable income are you willing to save (Recommended 50%% or more)\n");
    scanf("%d", &per);
    if (per <= 45)
    {
        printf("you will need to save more than that\n");
        return 0;
    }
    permon = (per / 100.0) * rem;
    printf("\nYou will need to save %0.1f every month", permon);
    printf("\nAt this rate you will reach your goal in %.1f months ", save / permon);
    float months = save / permon;
    float inves = 0.60 * (rem - permon);
    float other = 0.40 * (rem - permon);
    printf("\nEnter 1 to get the final budget\n");
    if (scanf("%d", &a) == 1)
    {
        system("clear");
        printf("--------------------------------------------\n");
        printf("            MONTHLY BUDGET SUMMARY\n");
        printf("--------------------------------------------\n");

        printf("%-25s : Rs. %d\n", "Total Income", inc);

        printf("\nFIXED EXPENSES\n");
        printf("--------------------------------------------\n");
        printf("%-25s : Rs. %d\n", "EMI Payments", emi);
        printf("%-25s : Rs. %d\n", "Rent", rent);
        printf("%-25s : Rs. %d\n", "Utilities", util);
        printf("%-25s : Rs. %d\n", "Insurance", ins);

        printf("--------------------------------------------\n");
        printf("%-25s : Rs. %d\n", "Total Fixed Expenses", emi + rent + util + ins);

        printf("\n%-25s : Rs. %d\n", "Disposable Income", rem);

        printf("\nSAVINGS ORIENTED\n");
        printf("--------------------------------------------\n");

        printf("%-25s : Rs. %8.1f\n", "Investment", inves);
        printf("%-25s : Rs. %8.1f\n", "Monthly Savings ", permon);
        printf("%-25s : Rs. %8.1f\n", "Miscellaneous", other);
        printf("--------------------------------------------\n");
        printf("%-25s : Rs. %8d\n\n", "Saving Goal", save);
        printf("%-25s  %8.1f Months\n", "Time to Achieve", months);
        printf("--------------------------------------------\n");
    }
    return 0;
}

void lifestyle()
{
    int per, a;
    printf("What percent of Your disposible income do you wanna spend:  ");
    scanf("%d", &per);
    float R = (per / 100.0) * rem;
    float vacation = 0.30 * R;
    float dineout = 0.10 * R;
    float movies = 0.05 * R;
    float other = 0.05 * R;
    float recreation = R - vacation - dineout - movies - other;
    float left = rem - R;

    float investment = 0.60 * left;
    float savings = 0.40 * left;
    printf("\nEnter 1 to get the final budget\n");
    if (scanf("%d", &a) == 1)
    {
        system("clear");
        printf("--------------------------------------------\n");
        printf("            MONTHLY BUDGET SUMMARY\n");
        printf("--------------------------------------------\n");

        printf("%-30s : Rs. %8d\n", "Total Income", inc);

        printf("\nFIXED EXPENSES\n");
        printf("--------------------------------------------\n");
        printf("%-30s : Rs. %8d\n", "EMI Payments", emi);
        printf("%-30s : Rs. %8d\n", "Rent", rent);
        printf("%-30s : Rs. %8d\n", "Utilities", util);
        printf("%-30s : Rs. %8d\n", "Insurance", ins);

        printf("--------------------------------------------\n");
        printf("%-30s : Rs. %8d\n", "Total Fixed Expenses", emi + rent + util + ins);

        printf("\n%-30s : Rs. %8d\n", "Disposable Income", rem);

        printf("\nLIFESTYLE-ORIENTED BUDGET\n");
        printf("--------------------------------------------\n");

        printf("%-30s : Rs. %8.1f\n", "Vacation", vacation);
        printf("%-30s : Rs. %8.1f\n", "Dineout", dineout);
        printf("%-30s : Rs. %8.1f\n", "Movies", movies);
        printf("%-30s : Rs. %8.1f\n", "Recreation", recreation);

        printf("--------------------------------------------\n");

        printf("%-30s : Rs. %8.1f\n", "Investment", investment);
        printf("%-30s : Rs. %8.1f\n", "Savings", savings);
        printf("%-30s : Rs. %8.1f\n", "Miscellaneous", other);

        printf("--------------------------------------------\n");
    }
}

void balanced()
{
    int a;

    float needs = 0.50 * rem;
    float reception = 0.30 * rem;

    float totalSavings = 0.20 * rem;
    float investment = 0.60 * totalSavings;
    float savings = 0.40 * totalSavings;
    printf("A Balanced Budget follows the 50-30-20 rule\n50%% on Needs and Essentials\n30%% on Recreation\n20%% on Savings and Investment");

    printf("\nEnter 1 to get the final budget\n");
    if (scanf("%d", &a) == 1)
    {
        system("clear");

        printf("--------------------------------------------\n");
        printf("            MONTHLY BUDGET SUMMARY\n");
        printf("--------------------------------------------\n");

        printf("%-30s : Rs. %8d\n", "Total Income", inc);

        printf("\nFIXED EXPENSES\n");
        printf("--------------------------------------------\n");
        printf("%-30s : Rs. %8d\n", "EMI Payments", emi);
        printf("%-30s : Rs. %8d\n", "Rent", rent);
        printf("%-30s : Rs. %8d\n", "Utilities", util);
        printf("%-30s : Rs. %8d\n", "Insurance", ins);

        printf("--------------------------------------------\n");
        printf("%-30s : Rs. %8d\n", "Total Fixed Expenses", emi + rent + util + ins);

        printf("\n%-30s : Rs. %8d\n", "Disposable Income", rem);

        printf("\nBALANCED BUDGET (50-30-20 RULE)\n");
        printf("--------------------------------------------\n");

        printf("%-30s : Rs. %8.1f\n", "Needs", needs);
        printf("%-30s : Rs. %8.1f\n", "Recreation", reception);
        printf("%-30s : Rs. %8.1f\n", "Savings", savings);
        printf("%-30s : Rs. %8.1f\n", "Investment", investment);

        printf("--------------------------------------------\n");
    }
}

void warning()
{
    if (emi >= inc * 0.3)
    {
        int idealemi = inc * 0.29;
        float percentemi = ((float)emi / (float)inc) * 100;
        printf("\nyour E.M.I is %0.2f%% of your Total Income which is not ideal.\n", percentemi);
        printf("ideally your emi should not exceed 30 to 35%% of your total income\n");
        printf("your maximum emi should be %d\n\n", idealemi);
    }
    if (rent >= inc * 0.4)
    {
        int idealrent = inc * 0.39;
        float percentrent = ((float)rent / inc) * 100;
        printf("\nyour rent is %0.2f%% of your Total Income which is not ideal.\n", percentrent);
        printf("ideally your rent should not exceed 40%% of your total income.\n");
        printf("your maximum rent should be %d\n\n", idealrent);
    }
    if (util >= inc * 0.15)
    {
        int idealutil = inc * 0.15;
        float percentutil = ((float)util / inc) * 100;
        printf("\nyour utilities are %0.2f%% of your Total Income which is not ideal.\n", percentutil);
        printf("ideally your utilities should not exceed 15%% of your total income.\n");
        printf("your maximum utilities should be %d\n\n", idealutil);
    }
}

void debtratio()
{

    system("clear");
    printf("--------------------------------------------\n");
    printf("            DEBT RATIO\n");
    printf("--------------------------------------------\n\n");
    printf("A debt-to-income ratio (DTI) measures how much of your monthly income goes toward paying debt.\n");
    printf("Enter your total debt if any  \n");
    scanf("%d", &debt);
    if (debt == 0)
    {
        printf("Congratulations you have no debt!!\n\n");
    }
    else
    {
        int debtmonthly;

        printf("your debt is %d\n", debt);
        printf("Please enter your monthly payments:\n");
        scanf("%d", &debtmonthly);
        float months = (float)debt / debtmonthly;
        float ratio = (float)debtmonthly / inc * 100;
        if (ratio < 20)
        {
            printf("\nYour ratio is below 20%% excellent!!");
            printf("\nAt this payment rate, you will clear your debt in %.1f months.\n", months);
        }
        else if (ratio < 40)
        {
            printf("\nYour ratio is below 40%%, that is acceptable.");
            printf("\nAt this payment rate, you will clear your debt in %.1f months.\n", months);
        }
        else
        {
            printf("Your ratio is above 40%% which is too high, you need to work on lowering it.\n");
            printf("\nAt this payment rate, you will clear your debt in %.1f months.\n", months);
        }
    }
}
void score()
{
    system("clear");
    printf("--------------------------------------------\n");
    printf("            FINANCIAL SCORE\n");
    printf("--------------------------------------------\n\n");
    float savings, debt;
    float needs, wants;
    float savingsRate, debtRatio;
    int savingsScore = 0, debtScore = 0, expenseScore = 0;
    int totalScore;

    printf(" Monthly Income: %d\n", inc);

    printf("\nEnter Monthly Savings: ");
    scanf("%f", &savings);

    printf("Enter Monthly Debt Payment: ");
    scanf("%f", &debt);

    printf("Enter the monthly Expenses on needs: ");
    scanf("%f", &needs);

    printf("Enter monthly Expenses on wants: ");
    scanf("%f", &wants);

    savingsRate = (savings / inc) * 100;
    debtRatio = (debt / inc) * 100;

    // Savings Score
    if (savingsRate >= 30)
        savingsScore = 40;
    else if (savingsRate >= 20)
        savingsScore = 30;
    else if (savingsRate >= 10)
        savingsScore = 20;
    else
        savingsScore = 10;

    // Debt Score
    if (debtRatio <= 20)
        debtScore = 30;
    else if (debtRatio <= 35)
        debtScore = 20;
    else if (debtRatio <= 50)
        debtScore = 10;
    else
        debtScore = 5;

    // Expense Distribution Score//
    if ((needs / inc) * 100 <= 60)
        expenseScore += 10;
    if ((wants / inc) * 100 <= 30)
        expenseScore += 10;
    if ((savings / inc) * 100 >= 20)
        expenseScore += 10;

    totalScore = savingsScore + debtScore + expenseScore;

    printf("\n\n\n--------------------------------------------\n");
    printf("        FINANCIAL SCORE BREAKDOWN\n");
    printf("--------------------------------------------\n");

    printf("%-25s : %3d / 40\n", "Savings Score", savingsScore);
    printf("%-25s : %3d / 30\n", "Debt Score", debtScore);
    printf("%-25s : %3d / 30\n", "Expense Score", expenseScore);

    printf("--------------------------------------------\n");
    printf("%-25s : %3d / 100\n", "Total Score", totalScore);
    printf("--------------------------------------------\n");

    if (totalScore >= 80)
    {
        printf("Status: Excellent Financial Health\n");
        printf("\n--------------------------------------------\n");
    }
    else if (totalScore >= 60)
    {
        printf("Status: Good Financial Health\n");
        printf("\n--------------------------------------------\n");
    }
    else if (totalScore >= 40)
    {
        printf("Status: Average Financial Health\n");
        printf("\n--------------------------------------------\n");
    }
    else
    {
        printf("Status: Poor Financial Health\n");
        printf("\n--------------------------------------------\n");
    }
}
