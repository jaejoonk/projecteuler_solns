#include <iostream>
#include <map>

using namespace std;

bool is_leap_year(int year) {
    if (year % 100 == 0) {
        return (year % 400 == 0);
    }
    return (year % 4 == 0);
}

// sunday = 0, monday = 1, ..., saturday = 6
// return number of sundays at the first of the month for that year
int sundays_per_year(int first_day_of_year, int year) {
    map<int, int> days_in_month = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30},
        {5, 31}, {6, 30}, {7, 31}, {8, 31},
        {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };
    
    int day_of_week = first_day_of_year;
    int num_of_sundays = 0;
    if (is_leap_year(year)) { days_in_month[2] = 29; }
    
    for (int month = 1; month <= 12; month++) {
        for (int day = 1; day <= days_in_month[month]; day++) {
            if (day_of_week == 0 && day == 1) {
                num_of_sundays++;
            }
            
            day_of_week++;
            day_of_week %= 7;
        }
    }
    
    return num_of_sundays;
}

int main() {
    int num_of_sundays = 0;
    int first_day_of_year = 2; // Jan 1, 1901
    for (int yr = 1901; yr <= 2000; yr++) {
        num_of_sundays += sundays_per_year(first_day_of_year, yr);
        
        if (is_leap_year(yr)) {
            first_day_of_year += 2;
        } else {
            first_day_of_year += 1;
        }
        first_day_of_year %= 7;
    }

    cout << "Number of total Sundays on the 1st of month: " << num_of_sundays << endl;
    return 0;
}