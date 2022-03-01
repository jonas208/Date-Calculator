#include <stdio.h>

int leap_year(int year) {

    if (year > 1582) {
        if (year % 400 == 0) {
            return 1;
        }
        else if (year % 100 == 0) {
            return 0;
        }
        else if (year % 4 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (year % 4 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
  

int in_array(int arr[7], int x) {
    int in_array = 0;
     
    for (int i = 0; i < 7; i++) {
        if (arr[i] == x) {
            in_array = 1;
            break;
        }
    }

    return in_array;
}

int main(void) {

    int input_date;
    int input_days;
    
    printf("Bitte gib das Ausgangsdatum (TTMMJJJJ) an: ");
    scanf("%d", &input_date);
    printf("Bitte gib die Anzahl der Tage an: ");
    scanf("%d", &input_days);

    int day = input_date / 1000000;
    int month = input_date / 10000 - day * 100;
    int year = input_date - (day * 100 + month) * 10000;

    int result_day = day;
    int result_month = month;
    int result_year = year;

    printf("Das eingegebene Datum: %d.%d.%d\n", day, month, year);

    int thirtee_one_months[] = {1, 3, 5, 7, 8, 10, 12};
    int month_days;
    int finishied = 0;
    while (finishied == 0) {
        
        if (in_array(thirtee_one_months, result_month) == 1) { // 31 day month
            month_days = 31;
        }
        else if (result_month == 2) { // february
            if (leap_year(result_year) == 1) {
                month_days = 29;
            }
            else {
                month_days = 28;
            }
        }
        else { // 30 day month
            month_days = 30;
        }
            
        int days_to_next_month = month_days - (day + input_days);
        if (days_to_next_month >= 0) {
            result_day = day + input_days;
            finishied = 1;
        }
        else if (days_to_next_month < 0) {
            if (input_days < month_days - 1) {
                result_day = input_days - month_days + day;
                if (result_month == 12) {
                    result_month = 1;
                    result_year += 1;
                }
                else {
                    result_month += 1;
                }
                finishied = 1;
            }
            else {
                input_days -= month_days - day + 1;
                day = 1;
                if (result_month == 12) {
                    result_month = 1;
                    result_year += 1;
                }
                else {
                    result_month += 1;
                }
            }
        }

    }

    printf("Ausgabedatum: %d.%d.%d\n", result_day, result_month, result_year);
    
    return 0;

}