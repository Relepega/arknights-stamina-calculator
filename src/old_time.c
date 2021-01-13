#include <time.h>

// Print current date and time in C
void fullDateTime(int* arr) {
    // variables to store date and time components
    int hours, minutes, seconds, day, month, year;

    // time_t is arithmetic time type
    time_t now;

    // Obtain current time
    // time() returns the current time of the system as a time_t value
    time(&now);

    // Convert to local time format and print to stdout
    // printf("Today is : %s", ctime(&now));

    // localtime converts a time_t value to calendar time and
    // returns a pointer to a tm structure with its members
    // filled with the corresponding values
    struct tm* local = localtime(&now);

    hours = local->tm_hour;          // get hours since midnight (0-23)
    minutes = local->tm_min;         // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;         // get seconds passed after minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;       // get month of year (0 to 11)
    year = local->tm_year + 1900;    // get year since 1900

    // // print local time
    // if (hours < 12)    // before midday
    //     printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);

    // else    // after midday
    //     printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);

    // // print current date
    // printf("Date is : %02d/%02d/%d\n", day, month, year);

    * (arr + 0) = hours;
    *(arr + 1) = minutes;
    *(arr + 2) = seconds;
    *(arr + 3) = day;
    *(arr + 4) = month;
    *(arr + 5) = year;
}

int getHours() {
    int d[6];
    fullDateTime(d);
    return d[0];
}

int getMinutes() {
    int d[6];
    fullDateTime(d);
    return d[1];
}

int getSeconds() {
    int d[6];
    fullDateTime(d);
    return d[2];
}

int getDay() {
    int d[6];
    fullDateTime(d);
    return d[3];
}

int getMonth() {
    int d[6];
    fullDateTime(d);
    return d[4];
}

int getYear() {
    int d[6];
    fullDateTime(d);
    return d[5];
}