//following code is taken from geeksforgeeks
#pragma once
// A date has day 'd', month 'm' and year 'y'
struct Date {
    int d, m, y;
};
int countLeapYears(Date d);
int getDifference(Date dt1, Date dt2);