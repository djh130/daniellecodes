

//preprocessor directive(s)
#include "main.h"


//driver program
int main()
{
    Numbers numbers;

    cout << "Enter a list of numbers to average (CTRL-D to stop):\n";

    numbers.read( cin );
    cout << "Average: " << numbers.average() << endl;

    return 0;

} // END function main
