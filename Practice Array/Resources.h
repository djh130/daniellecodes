
#ifndef COSC052P5_RESOURCES_H
#define COSC052P5_RESOURCES_H

#define DEBUG_FILE_OPENING
//#define DEBUG_DATE

#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <string>
#include "Exceptions.h"


using std::invalid_argument;
using std::cout;
using std::endl;
using std::string;

// use minimum values as defaults
const int MAX_LINES = 10;

// use for array indexes
enum MONTH_LIST {DUMMY, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

// array stores max day value
const int MAX_DD[] =  { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MIN_DD = 1;

const int MIN_YYYY = 1492;
const int MAX_YYYY = 2192;

const int MIN_MM = 1;
const int MAX_MM = 12;


const int MIN_HOUR = 0;
const int MAX_HOUR = 24;//24:00 is valid for midnight
const int DEFAULT_HOUR = 24;

const int MIN_MINUTE = 0;
const int MAX_MINUTE = 59;
const int DEFAULT_MINUTE = 0;

const int MAX_DD_JAN = 31;
const int MAX_DD_FEB = 29;
const int MAX_DD_MAR = 31;
const int MAX_DD_APR = 30;
const int MAX_DD_MAY = 31;
const int MAX_DD_JUN = 30;
const int MAX_DD_JUL = 31;
const int MAX_DD_AUG = 31;
const int MAX_DD_SEP = 30;
const int MAX_DD_OCT = 31;
const int MAX_DD_NOV = 30;
const int MAX_DD_DEC = 31;
const int MIN_YY = 1000;
const int MAX_YY = 2199;
const int MIN_H = 0;
const int MAX_H = 24;
const int MIN_M = 0;
const int MAX_M = 59;


const int DEFAULT_YY = MIN_YYYY;
const int DEFAULT_MM = MIN_MM;
const int DEFAULT_DD = MIN_DD;
const int DEFAULT_H = MIN_H;
const int DEFAULT_M = MIN_M;


std::string readDoubleQuotedString( std::istream& in ); // required
std::string trimSpaces( std::string s ); // optional 



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Date declaration                             **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Spring 2021 to use in                      **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Date
{
    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);

public:
    Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD); //yyyy, mm, dd
    Date(const Date&);
    void setDate(int, int, int);  //yyyy, mm, dd
    void setDate(const Date&);
    Date operator=(const Date&);
    int getYear() const {return yyyy;}
    int getMonth() const {return mm;}
    int getDay() const{return dd;}
    bool operator ==(const Date&) const;
    bool operator !=(const Date&) const;
    bool operator <=(const Date&) const;
    bool operator <(const Date&) const;
    bool operator >=(const Date&) const;
    bool operator >(const Date&) const;

private:

    int yyyy;
    int mm;
    int dd;
}; //end class Date



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class Time declaration                                 **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Spring 2021 to use in                      **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class Time
{
    friend std::istream& operator>>(std::istream &in, Time &t);
    //Overloaded stream extraction operator
    //Postcondition: Extracts values for each data member from
    //the input stream.  Format of the data in the stream
    //is assumed to be:  hh:mm
    //The delimiting character is read and discarded.

    friend std::ostream& operator<<(std::ostream &os, const Time &t);
    //Overloaded stream insertion operator.
    //Postcondition: The time is output to the steam.  Delimiting
    //character is replaced.  The result is a time value
    //output in the same format as was read in (except values less than
    //10 shall be right padded with a 0 which may not have been
    //what was read in).

private:

    int hh;
    int mm;
public:
    Time(int = DEFAULT_HOUR, int = DEFAULT_MINUTE);
    //constructor with parameters, with default values
    //This constructor calls the member function setTime()
    //and passes the same arguments as were passed in to
    //the constructor, function setTime() updates the data members.
    //Postcondition: Sets the values of hh and mm
    //according to the values of the arguments passed in.
    //If no values are passed, this acts as the default constructor
    //all integer data members are set to values in dafault constants

    void setTime(int, int);
    //Function to set the values of the object data members,
    //can be called directly or by a constructor.
    //Postcondition: Data members are set to the values
    //of the respective arguments passed in.

    int getHour() const {return hh;}
    //In-line function to return the hour value.
    //Postcondtion: The value of data member hh is retured.

    int getMinute() const {return mm;}
    //In-line function to return the minute value.
    //Postcondtion: The value of data member mm is retured.

    Time operator=(const Time&);
    //Overloaded assignment operator.
    //Postcondtion: The values of right hand side object's
    //data members are copied to the respective data
    //members of the left hand side object.

    bool operator==( const Time& ) const;

    bool operator!=( const Time& ) const;

    bool operator>( const Time& ) const;

    bool operator<( const Time& ) const;

}; //END class Time declaration

#endif //COSC052P5_RESOURCES_H
