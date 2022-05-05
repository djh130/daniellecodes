

#include "Exceptions.h"

no_such_object::no_such_object(string msg):logic_error(msg) {}

bad_date_component::bad_date_component(string msg):invalid_argument(msg){}

file_open_error::file_open_error(string msg):invalid_argument(msg){}

missing_arguments::missing_arguments(string msg):logic_error(msg){}
