

#include "main.h"

int main()
{
    try
    {
        RD_Array<char> list2(2,'a');
        cout << "List 2 Contents: " << list2.at(0) << " " << list2.at(1) << endl;

        RD_Array<char> list;

        cout << "List, calling pushback..." << endl;

        list.push_back('b');

        cout << "List, calling pushback..." << endl;

        list.push_back('c');

        cout << "List, calling insert at element 0..." << endl;
        list.insert(0,'a');

        cout << "List, element at index 0: " << list.at(0) << endl;
        cout << "List, element at index 1: "<< list[1] << endl;
        cout << "List, element at index 2: "<< list[2] << endl;

        cout << "List, size : " << list.size() << endl;

        cout << "List, capacity: " << list.capacity() << endl;

        cout << "List, calling popback..." << endl;
        list.pop_back();

        cout << "List, size : " << list.size() << endl;
        cout << "List, capacity: " << list.capacity() << endl;

        cout << "List, calling resize..." << endl;
        list.resize(15, 'e');

        cout << "List, size : " << list.size() << endl;
        cout << "List, capacity: " << list.capacity() << endl;

        cout << "Printing all elements of list" << endl;

        for(unsigned long i = 0; i<list.size(); i++)
        {
            cout << list[i] << endl;
        }


        cout << "Creating new list via copy constructor..." << endl;

        RD_Array<char>list3(list);

        cout << "Printing all elements of list3 (copy constructor example)" << endl;

        for(unsigned long i = 0; i<list3.size(); i++)
        {
            cout << list3[i] << endl;
        }

        cout << "Creating a new list named list4..." << endl;
        RD_Array<char> list4;

        cout << "Setting list4 equal to list via overloaded assignment operator" << endl;
        list4 = list;

        cout << "Printing all elements of list4 (overloaded assignment operator example)" << endl;

        for(unsigned long i = 0; i<list4.size(); i++)
        {
            cout << list4[i] << endl;
        }

        cout << "List, calling clear..." << endl;
        list.clear();

        cout << "List, size : " << list.size() << endl;
        cout << "List, capacity: " << list.capacity() << endl;

        cout << "calling empty function to test if it works..." << endl;
        if(list.empty())
        {
            cout << "The list is now empty" << endl;
        }
    }
    catch(no_such_object &eNsO)
    {
        cout << "Caught: no_such_object error." << endl;
        cout << eNsO.what() << endl;
    }

//    catch(bad_vehicle_code &EBvC)
//    {
//        cout << "Caught: bad_vehicle_code error in main:" << endl;
//        cout << EBvC.what() << endl;
 //   }

    catch(bad_alloc &bAError )
    {
        cout << "Caught: bad_alloc error in main:" << endl;
        cout << bAError.what() << endl;
    }
    catch(invalid_argument &iAError)
    {
        cout << "caught invalid_argument exception in main: " << endl;
        cout << iAError.what() << endl;
    }

    catch (out_of_range &orErr )
    {
        cout << "caught out_of_range exception in main:" << endl;
        cout << orErr.what() << endl;
    }

    catch (logic_error &lErr )
    {
        cout << "caught logic_error exception in functin main: " << endl;
        cout << lErr.what() << endl;
    }

    catch ( ... )
    {
        cout << "caught unknown exception in function main" << endl;
    }


}
