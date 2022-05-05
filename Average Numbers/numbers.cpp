

#include "numbers.h"




void Numbers::read( istream & in )
{
    double n;
    while ( in >> n )
    {
        numbers.push_back( n );
    
    }

}



double Numbers::average()
{
    double sum = 0.0;
    
    for ( unsigned i = 0; i < numbers.size(); i++ )
    {
        sum += numbers.at(i);
    }

    return sum / numbers.size();

} 

