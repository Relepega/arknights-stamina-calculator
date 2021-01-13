#include <time.h>

// Print current date and time in C
static int fullDateTime(int datetime_pick) {
    // variables to store date and time components
    // int hours, minutes, seconds, day, month, year;
    int DateTime[6];

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

    DateTime[0] = local->tm_hour;          // get hours since midnight (0-23)
    DateTime[1] = local->tm_min;         // get minutes passed after the hour (0-59)
    DateTime[2] = local->tm_sec;         // get seconds passed after minute (0-59)

    DateTime[3] = local->tm_mday;            // get day of month (1 to 31)
    DateTime[4] = local->tm_mon + 1;       // get month of year (0 to 11)
    DateTime[5] = local->tm_year + 1900;    // get year since 1900

    // // print local time
    // if (hours < 12)    // before midday
    //     printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);

    // else    // after midday
    //     printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);

    // // print current date
    // printf("Date is : %02d/%02d/%d\n", day, month, year);

    return DateTime[datetime_pick];
}

int getHours() {
    return fullDateTime(0);
}

int getMinutes() {
    return fullDateTime(1);
}

int getSeconds() {
    return fullDateTime(2);
}

int getDay() {
    return fullDateTime(3);
}

int getMonth() {
    return fullDateTime(4);
}

int getYear() {
    return fullDateTime(5);
}