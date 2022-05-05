

#ifndef COSC052P5_EXCEPTIONS_H
#define COSC052P5_EXCEPTIONS_H


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

using std::string;
using std::logic_error;

/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                    derived exception classes                           **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Spring 2021 to use in                      **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

/****************************************************************************
 *                         Missing Argument Class                           *
 ****************************************************************************/
class missing_arguments : public logic_error
{
public:
    missing_arguments(std::string = "ERROR: missing_arguments");
};  // END exception

/****************************************************************************
 *                         File Open Error Class                            *
 ****************************************************************************/
class file_open_error : public std::invalid_argument
{
public:
    file_open_error(std::string = "ERROR: file_open_error");
}; // END file_open_error

/****************************************************************************
 *                         Bad Date Component Class                         *
 ****************************************************************************/
class bad_date_component : public std::invalid_argument
{
public:
    bad_date_component(std::string = "ERROR: bad_date_component");
}; // END bad_date_component

/****************************************************************************
 *                         No Such Object Class                             *
 ****************************************************************************/
class no_such_object : public std::logic_error
{
public:
    no_such_object(std::string = "ERROR: no_such_object");
}; // END 


#endif //COSC052P5_EXCEPTIONS_H
