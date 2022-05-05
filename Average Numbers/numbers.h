


#define HW0_GIVENFILES_NUMBERS_H


#include <iostream>
#include <vector>

using namespace std;


class Numbers
{
public:
    void read( istream &in = cin );
    double average();

    
    unsigned long size() { return numbers.size(); }

private:
    vector<double> numbers;

}; // END class Numbers declaration


