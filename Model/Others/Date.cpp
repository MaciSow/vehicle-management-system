#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date() {
    setCurrentDate();
}

Date::~Date() {

}

Date::Date(string date) {
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

string Date::getStringDate(string separator) {
    string stringMonth = to_string(month);
    string stringDay = to_string(day);

    if (month <= 9) {
        stringMonth = "0" + to_string(month);
    }
    if (day <= 9) {
        stringDay = "0" + to_string(day);
    }

    return stringDay + separator + stringMonth + separator + to_string(year);
}

void Date::addDays(int days) {
    days += day;
    int addMonth = floor(days / 28);
    day = days % 28;
    addMonth += month - 1;
    year += floor(addMonth / 12);
    month = addMonth;
}

int Date::getDay() const {
    return day;
}

void Date::setCurrentDate() {
    struct tm newtime;
    __time64_t long_time;
    _time64(&long_time);
    _localtime64_s(&newtime, &long_time);

    year = newtime.tm_year + 1900;
    month = newtime.tm_mon + 1;
    day = newtime.tm_mday;
}
