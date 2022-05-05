

//pre-processor directive(s)
#include "Resources.h"

/****************************************************************************
 *                    Date class default constructor                        *
 ****************************************************************************/
Date::Date(int year, int month, int day)
{

#ifdef DEBUG_DATE
    std::cout << "Entered constructor Date::Date (int, int, int)" << std::endl;
#endif

    //Call method setDate -data validation will be accomplished
    try
    {
        setDate(year, month, day);
    }

    catch(invalid_argument)
    {
        std:: cout<< "Error: Invalid argument. Please choose a date between 1000 and 2199";
    }

#ifdef DEBUG_DATE
    std::cout << "Exiting constructor Date::Date(int, int, int)" << std::endl;
#endif

} //END constructor

Date::Date(const Date & otherDate)
{
    setDate(otherDate);
}

/****************************************************************************
 *                                Date class                                *
 ***************************************************************************/

/****************************************************************************
 *                  Date class member function setDate                      *
 ****************************************************************************/

void Date::setDate(int year, int month, int day)
{
    std::ostringstream errStrm;

    //Set data to default values
    //If values pass
    // update members
    yyyy= MIN_YYYY;
    mm = MIN_MM;
    dd = MIN_DD;

    bool badArguments = false;

    if ( year < MIN_YYYY || year > MAX_YYYY || month < MIN_MM || month > MAX_MM || day < MIN_DD ||
         day > MAX_DD[month] )
    {
        badArguments = true;
    }

    if (badArguments)
    {
        errStrm << "ERROR: in Time::setTime method — " << year << ", " << month << ", "<<day<<"\n";
        errStrm << "year set to MIN_YYYY: " << MIN_YYYY << ", ";
        errStrm << "month set to MIN_MM: " << MIN_MM << ", ";
        errStrm << "day set to MIN_DD: " << MIN_DD << ", ";

        std:: string errDate = errStrm.str();
        std:: invalid_argument e(errDate);
        throw bad_date_component(" Error in year, month or date");
    }

    //Parameters valid- update  data members
    yyyy = year;
    mm = month;
    dd = day;
} //END member function

void Date::setDate(const Date &otherDate)
{
    setDate(otherDate.getYear(), otherDate.getMonth(), otherDate.getDay());
}

/****************************************************************************
 *            Date Class Overloaded Stream Insertion Operator               *
 ****************************************************************************/

//Overloaded stream operator
std::ostream& operator<<(std::ostream &os, const Date& rhsObj )
{

    std::string errOutStream = "ERROR: in Date class overloaded stream insertion operator<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place \n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }

    os << std::setfill('0');

    os << std::setw(4) << rhsObj.yyyy << "/";
    os << std::setw(2) << rhsObj.mm << "/";
    os << std::setw(2) << rhsObj.dd;

    //set fill character to blank space
    //(prevent really bad output of values)
    os << std::setfill(' ');

    //return the modified
    return os;
} //END overloaded stream

/****************************************************************************
 *            Friend function, Date class stream extraction operator        *
 ****************************************************************************/

//Extract values for a Data object
std::istream& operator>>(std::istream &is, Date& d)
{
    //divide between the year and the month
    char ch1;
    //divide between the month and the day
    char ch2;

    int year = -1;
    int month = -1;
    int day = -1;

    // if stream is originally in a failed state - throw an exception
    // handled locally
    //will immediately pass control back to calling function

    std::string errInStream = "ERROR: in Date class overloaded stream extraction operator>>\n";
    errInStream += "the stream is initially in a failed state\n";

    if (!is)
    {
        throw std::invalid_argument(errInStream);
    }

    try
    {
        bool streamFailed = false;

        //extract year
        is >> year;
        if (!is) { streamFailed = true; }

        //extract dilimiting character1
        is >> ch1;
        if (!is) { streamFailed = true; }

        //extract  month from input
        is >> month;
        if (!is) { streamFailed = true; }

        //extract dilimiting character2
        is >> ch2;
        if (!is) { streamFailed = true; }

        //extract day from input
        is >> day;
        if (!is) { streamFailed = true; }

        if(streamFailed)
        {
            std::string errInStream = "WARNING: in Date class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "date object data members not updated \n";
            throw std::runtime_error(errInStream);
        }

        //Call setDate method to perform validation testing
        d.setDate(year, month, day);
    }

    catch (std::runtime_error &e)
    {
        //allow processing to continue
        //(dont re-throw)
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Date class overloaded operator>>\n";
        std::cout << e.what() << endl;
    }

    catch (std::invalid_argument &e)
    {
        //rethrow
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Date class overloaded operator>>\n";
        std::cout << e.what() << endl;
        throw;
    }

    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Date class overloaded operator>>\n";
        throw;
    }

    //return modified input
    return is;

} //END overloaded stream extraction operator

/****************************************************************************
 *                     Date class overloaded assignment operator            *
 ****************************************************************************/
Date Date::operator=(const Date &rhsObj)
{
    if (this != &rhsObj)
    {
        // calls setDate method to perform validation testing
        setDate(rhsObj.yyyy, rhsObj.mm, rhsObj.dd);
    }
    return *this;
} //END overloaded assignment operator

/****************************************************************************
 *                 Date class overloaded equality operator                  *
 ****************************************************************************/
bool Date::operator==( const Date &rhsObj ) const
{
    // return true if  Date object = Date object passed as parameter
    return ( (this->yyyy == rhsObj.yyyy) && (this->mm == rhsObj.mm )&& (this->dd == rhsObj.dd));
} // END overloaded equality operator

/****************************************************************************
 *                Date class overloaded inequality operator                 *
 ****************************************************************************/
bool Date::operator!=( const Date &rhsObj ) const
{
    
    return !( *this == rhsObj );
} // END overloaded inequality operator

/****************************************************************************
 *               Date class overloaded greater than operator                *
 ****************************************************************************/
bool Date::operator>( const Date &rhsObj ) const
{
    bool answer = false;
    // return true if  Date object > Date object passed as param
    if ( this->yyyy > rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }

    else if( (this->mm == rhsObj.mm)&& (this->dd > rhsObj.dd))
    {
        answer = true ;
    }
    return answer;

} // END overloaded > operator

/****************************************************************************
 *               Date class overloaded greater than or equal to operator     *
 ****************************************************************************/
bool Date::operator>=( const Date &rhsObj ) const
{
    bool answer = false;

    // return true if Date object > Date object passed as param
    

    if ( this->yyyy >= rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm >= rhsObj.mm) )
    {
        answer = true;
    }

    else if( (this->mm == rhsObj.mm)&& (this->dd >= rhsObj.dd))
    {
        answer = true ;
    }

    return answer;

} // END overloaded greater than or equal to operator

/****************************************************************************
 *                 Date class overloaded less than operator                 *
 ****************************************************************************/

bool Date::operator<( const Date &rhsObj ) const
{
    bool answer = false;

    // return true if Date object < Date object passed as the param
    if ( this->yyyy < rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }

    else if( (this->mm == rhsObj.mm)&& (this->dd < rhsObj.dd))
    {
        answer = true ;
    }

    return answer;

} // END overloaded > operator

/****************************************************************************
 *                 Date class overloaded less than or equal to operator      *
 ****************************************************************************/

bool Date::operator<=( const Date &rhsObj ) const
{
    bool answer = false;

    // return true if  Date object < Date object passed as the param
    if ( this->yyyy <= rhsObj.yyyy )
    {
        answer = true;
    }
    else if ( (this->yyyy == rhsObj.yyyy) && (this->mm <= rhsObj.mm) )
    {
        answer = true;
    }

    else if( (this->mm == rhsObj.mm)&& (this->dd <= rhsObj.dd))
    {
        answer = true ;
    }

    return answer;

} // END overloaded > Date class

/****************************************************************************
 *                    Time class default constructor                        *
 ****************************************************************************/

/**
 * <P>Constructor with parameters, also default constructor since all
 * parameters have default values.</P>
 * <P>Sets the hh and mm data members to values passed to parameters.</P>
 * <P>Uses 24-hour format so 24:00 is midnight
 * 12:00 is noon, 13:00 is 1:00 pm, etc.</P>
 * <P>Note that 00:00 is also accepted as midnight but will be converted to 24:00</P>
 * <P>In addition to the range of valid values below, if the hour value is 24, then
 * the minute value must be 00.</P>
 * <P>Shall call the setTime method with integer parameters
 * to perform validation testing and actually initialize hh and mm
 * if all values pass validation.</P>
 *
 * @param  hour an int value in [0, 24]
 * @param  minute an int value in [0, 59] (must be 0 if hour is 24)
 * @throws invalid_argument if any parameter fails validation
 */

Time::Time(int hour, int minute)
{
#ifdef DEBUG_DATE
    std::cout << "Entered constructor Time::Time(int, int)" << std::endl;
#endif

    // call method setTime
    setTime(hour, minute);

#ifdef DEBUG_DATE
    std::cout << "Exiting constructor Time::Time(int, int)" << std::endl;
#endif

} //END constructor for Time class



/****************************************************************************
 *                  Time class member function setTime                      *
 ****************************************************************************/

/**
 * <P>Time class member function to set the hh and mm data members to
 * to the values passed in to the two integer parameters.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  hour an int value
 * @param  minute an int value
 * @throws invalid_argument if any parameter fails validation
 */

void Time::setTime(int hour, int minute)
{
    // use string stream to generate message
    std::ostringstream errStrm;

    // set data members to default values
    hh = MIN_HOUR;
    mm = MIN_MINUTE;

    bool badArguments = false;

    if ( hour < MIN_HOUR || minute < MIN_MINUTE || hour > MAX_HOUR || minute > MAX_MINUTE )
    {
        
        badArguments = true;
    }
    else if ( hour == MAX_HOUR && minute != 0 )
    {
       
        badArguments = true;
    }

    // accept 00:00 as midnight
    //(convert to 24:00)
    if ( hour == 0 && minute == 0)
    {
        hour = 24;
    }

    if (badArguments)
    {
        

        errStrm << "ERROR: in method Time::setTime( " << hour << ", " << minute << " )\n";
        errStrm << "hour set to MIN_HOUR (" << MIN_HOUR << "), ";
        errStrm << "minute set to MIN_MINUTE (" << MIN_MINUTE << ")\n";
        std::string errTime = errStrm.str();

        std::invalid_argument e(errTime);
        throw e;
    }

    // both parameters valid

    hh = hour;
    mm = minute;

} //END member function



/****************************************************************************
 *                 Time class stream extraction operator                    *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream extraction operator, Time class</P>
 * <P>Extracts values for a Time object's data members
 * from the input stream.</P>
 * <P>The input format is assumed to hh:mm, be aware that
 * the minute will always be a 2-digit number, right padded with
 * a 0 if necessary, hour values could be either 2-digit or 1-digit numbers.</P>
 * <P>After the values are extracted, the modified input stream is returned.</P>
 * <P>Shall call the setTime method with integer parameters
 * to perform validation testing and actually update hh and mm
 * if all values pass validation.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  in  the input stream for extraction
 * @param  t  the Time object for storing the extracted information
 * @return  the modified input stream
 * @throws invalid_argument if the input stream is initially in a failed state
 * @throws invalid_argument (via Time::setTime method) if any parameter fails validation
 *
 */

std::istream& operator>>(std::istream &in, Time &t)
{
    // input format is expected to be hh:mm
    // 24:00 for midnight
    // 12:00 for noon
    // 2:45 45 minutes past 2 am
    // etc.

    char ch;
    int hour = -1;
    int minute = -1;

    // if stream is originally in a failed throw an exception
    std::string errInStream = "ERROR: in Time class overloaded operator>>\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";
    if (!in)
    {
        throw std::invalid_argument(errInStream);
    }

    try
    {
        bool streamFailed = false;

        in >> hour; //extract the hours
        //store them in local variable
        if (!in) { streamFailed = true; }

        in >> ch; //extract & discard dilimiting character
        if (!in) { streamFailed = true; }

        in >> minute; //extract minutes
        //store them in local variable
        if (!in) { streamFailed = true; }

       //throw exception if in failed state

        if(streamFailed)
        {
            std::string errInStream = "WARNING: in Time class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "time object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }

        // call setTime method
        t.setTime(hour, minute);
    }
    catch (std::runtime_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in Time class overloaded operator>>\n";
        std::cout << e.what() << endl;
        // allow processing to continue
        //(dont rethrow)
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in Time class overloaded operator>>\n";
        std::cout << e.what() << endl;
        // rethrow
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Time class overloaded operator>>\n";
        throw;
    }

    return in;

} //END overloaded stream extraction operator



/****************************************************************************
 *                 Time class stream insertion operator                     *
 ****************************************************************************/

/**
 * <P>friend function, overloaded stream insertion operator of Time class.</P>
 * <P>Inserts a Time object into the output stream
 * and returns the modified output stream.</P>
 * <P>The output format is the same as the input format expected
 * by the overloaded stream extraction operator: hh:mm, unlike
 * the stream extraction operator, the stream insertion operator
 * shall always output hours and minutes having 2-digits (use left
 * padding with a 0 for hours and minutes less than 10)</P>
 *
 * @param  os  the output stream for insertion
 * @param  t   the Time object for insertion
 * @return  the modified output stream
 * @throws invalid_argument if the output stream is initially in a failed state
 */

std::ostream& operator<<(std::ostream &os, const Time &t)
{

    std::string errOutStream = "ERROR: in Time class overloaded operator<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }

   
    os << std::setfill('0');

    os << std::setw(2) << t.hh << ":";
    os << std::setw(2) << t.mm;

    // set the fill character back to a blank space
    os << std::setfill(' ');

    return os;

} //END overloaded stream insertion operator



/****************************************************************************
 *                     Time class assignment operator                       *
 ****************************************************************************/

/**
 * <P>Overloaded assignment operator.</P>
 * <P>Sets the hh amd mm data members to values of the corresponding
 * data members of the Time object passed in as a parameter.</P>
 * <P>Should test for self assignment (not an issue with this class, but
 * good habit nevertheless).</P>
 * <P>Should call the setTime method with integer parameters
 * to perform validation testing and actually update hh and mm
 * if all values pass validation.</P>
 * <P>NOTE: see default constructor for valid values.</P>
 *
 * @param  rhsObj a Time object
 * @throws invalid_argument (via setTime method) if any parameter fails validation
 */

Time Time::operator=(const Time &rhsObj)
{
    if (this != &rhsObj)
    {
        

        setTime(rhsObj.hh, rhsObj.mm);
    }

    return *this;

} //END overloaded assignment operator



/****************************************************************************
 *                 Time class overloaded equality operator                  *
 ****************************************************************************/

/**
 * <P>Overloaded equality operator, Time class.</P>
 * <P>Returns true if the left side Time object is equal to the right side Time object.</P>
 *
 * @param  rhsObj a Time object
 * @return true if both objects have the same hour value and minute value, false otherwise
 *
 */

bool Time::operator==( const Time &rhsObj ) const
{
    return ( this->hh == rhsObj.hh && this->mm == rhsObj.mm );

} // END overloaded equality operator



/****************************************************************************
 *                Time class overloaded inequality operator                 *
 ****************************************************************************/

/**
 * <P>Overloaded inequality operator, Time class.</P>
 * <P>Returns true if the left side Time object is NOT equal to the right side Time object.</P>
 *
 * @param  rhsObj a Time object
 * @return true if objects have either different hour value or minute value, false otherwise
 *
 */

bool Time::operator!=( const Time &rhsObj ) const
{
    return !( *this == rhsObj );

} // END overloaded inequality operator



/****************************************************************************
 *               Time class overloaded greater than operator                *
 ****************************************************************************/

/**
 * <P>Overloaded greater than operator, Time class.</P>
 * <P>Returns true if the left side Time object is greater than the right side Time object.</P>
 *
 * @param  rhsObj a Time object
 * @return true if left side object is greater than the right side object, false otherwise
 *
 */

bool Time::operator>( const Time &rhsObj ) const
{
    bool answer = false;

    if ( this->hh > rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm > rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded greater than operator



/****************************************************************************
 *                 Time class overloaded less than operator                 *
 ****************************************************************************/

/**
 * <P>Overloaded less than operator, Time class.</P>
 * <P>Returns true if the left side Time object is less than the right side Time object.</P>
 *
 * @param  rhsObj a Time object
 * @return true if left side object is less than the right side object, false otherwise
 *
 */

bool Time::operator<( const Time &rhsObj ) const
{
    bool answer = false;

    if ( this->hh < rhsObj.hh )
    {
        answer = true;
    }
    else if ( (this->hh == rhsObj.hh) && (this->mm < rhsObj.mm) )
    {
        answer = true;
    }

    return answer;

} // END overloaded greater than operator

/****************************************************************************
 *                readDoubleQuotedString Stand-alone function               *
 ****************************************************************************/

string readDoubleQuotedString (std:: istream & in)
{
    string doubleQuotedString = " ";
    char doubleQuote;
    std:: string errObjStream = "ERROR: in readDoubleQuotedString function\n";
    errObjStream += "the stream object is initially in a failed state \n";

    //throws invalid argument
    if (!in)
    {
        throw std::invalid_argument(errObjStream);
    }

    std:: string errLogic= "ERROR: opening quotation mark was not the first character in stream\n";

   //logic error
    in >> doubleQuote;
    if (doubleQuote != '"')
    {
        throw std::logic_error(errLogic);
    }

    getline(in, doubleQuotedString, '"');

    // Returns the text between a pair of double quotes
    return doubleQuotedString;


}
