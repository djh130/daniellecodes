

#ifndef COSC052P5_RD_ARRAY_H
#define COSC052P5_RD_ARRAY_H

#include <new>
#include <stdexcept>
#include "Exceptions.h"

using std::bad_alloc;
using std::out_of_range;
using std::exception;
using std::vector;
using std::cout;
using std::endl;


template <typename T>
class RD_Array {

public:
    RD_Array();
    RD_Array( const unsigned long, const T& = T() );
    RD_Array( const RD_Array<T> & );
    ~RD_Array();

    const RD_Array<T> &operator=( const RD_Array<T>& );

    T& at( const unsigned long ) const;
    T& operator[]( const unsigned long ) const;

    unsigned long size() const { return currentSize; }
    unsigned long capacity() const { return currentCapacity; }

    void insert( const unsigned long, const T& );
    void push_back( const T& );
    void pop_back();

    void resize( const unsigned long, const T& = T() );
    void clear();
    bool empty() const;

private:
    T* contents;
    unsigned long currentSize;
    unsigned long currentCapacity;

    void increaseCapacity();

}; // END RD_Array<T>
/*****************************************************************************************
*          Implementation Code for Public Methods of the rd_array class                 *
******************************************************************************************/

/*****************************************************************************************
*                                   Default Constructor                                  *
******************************************************************************************/

template <typename T>
RD_Array<T>::RD_Array()
{
    currentCapacity=0;
    currentSize=0;
    contents=NULL;

}


/*****************************************************************************************
*          Implementation Code for Private Methods of the rd_array class                 *
******************************************************************************************/

/*****************************************************************************************
*                               increaseCapacity method                                  *
******************************************************************************************/

template <typename T>
void RD_Array<T> ::increaseCapacity()
{
    try
    {
        if(currentCapacity==0)
        {
            //if currentCapacity is 0 dynamically allocate memory
            T *currentArray= new T[1];
            contents=currentArray;
            currentCapacity=1;

            
        }
        else
        {
            //If currentCapacity doesnt = 0, call the resize method
            // reset the size of the array back to the original size
            unsigned long oldSize= currentSize;
            resize(2 *currentCapacity, 0);
            currentSize= oldSize;

        }
    }
    catch (bad_alloc)
    {
        throw;
    }
    catch (...)
    {
        throw;
    }
}

/*****************************************************************************************
*                   Implementation Code for Constructor of RD_Array Class                *
******************************************************************************************/

template <typename T>
RD_Array<T> ::RD_Array(const unsigned long size, const T &obj)
{
    try
    {
        //set member variables equal to parameter
        contents= new T[size];
        currentCapacity = size;
        currentSize = size;

        //set each element in  new array to  object from  parameter
        for(int i=0; i < size; i++)
        {
            contents[i] =obj;
        }
    }
    catch(bad_alloc)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*                 Implementation Code for Copy Constructor of RD_Array Class             *
******************************************************************************************/

template <typename T>
RD_Array<T> ::RD_Array(const RD_Array<T> &otherArray)
{
    try {
        //set  size and capacity to other Array
        currentSize= otherArray.currentSize;
        currentCapacity=otherArray.currentCapacity;
        contents = new T[currentSize];

      
        for(int i=0; i< currentSize; i++)
            contents[i]= otherArray.contents[i];
    }
    catch(bad_alloc)
    {
        throw;
    }
    catch (out_of_range)
    {
        throw;
    }
    catch(no_such_object)
    {
        throw;
    }
    catch(invalid_argument)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*              Implementation Code for Destructor of the rd_array class                  *
******************************************************************************************/

template <typename T>
RD_Array<T> ::~RD_Array()
{
   
    if(contents!=NULL)
        delete[] contents; //delete array
}

/*****************************************************************************************
*      Implementation Code for Overloaded Assignment Operator of rd_array class          *
******************************************************************************************/

template <typename T>
const RD_Array<T> &RD_Array<T> ::operator=(const RD_Array<T> &otherArray)
{
    try
    {
        bool ifSame=false;

        //check for self
        if(this==&otherArray)
            ifSame=true;

        if(ifSame)
        {
            cout << "Cannot copy: Self Referential" << endl;

        }

        else
        {
            if(contents!=NULL)
            {
                //Delete if not empty
                delete [] contents;
            }
            currentSize= otherArray.currentSize;
            currentCapacity=otherArray.currentCapacity;

            if(currentCapacity==0)
            {
                contents=NULL;
            }

            else
            {
                contents = new T[currentCapacity];

            }
            for (int i=0; i< currentSize; i++)
            {
                contents[i] = otherArray.contents[i];
            }
        }
        return *this;

    }
    catch(bad_alloc)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*            Implementation Code for at method of rd_array class                         *
******************************************************************************************/

template<typename T>
T &RD_Array<T> ::at(const unsigned long ndx) const
{
    try
    {
        string errorMsg1= "Cannot return the element. Index out of range.";
        string errorMsg2= "Cannot return the element. Array empty";

        //Check if index is valid
        // else throw error
        if (ndx>currentSize-1 || ndx < 0 || currentSize==0)
        {
            if (currentSize==0)
                throw out_of_range(errorMsg2);
            else
                throw out_of_range(errorMsg1);
        }

        //Return the index
        return contents[ndx];
    }

    catch(out_of_range)
    {
        throw;
    }
    catch(no_such_object)
    {
        throw;
    }
    catch(invalid_argument)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*           Implementation Code for Overloaded [] Operator of the rd_array class          *
******************************************************************************************/

template <typename T>
T &RD_Array<T>::operator[] (const unsigned long ndx) const
{
    try
    {
        if(ndx>currentSize-1 || ndx < 0)
            throw out_of_range("Cannot return the element. Index is out of range.");
    }
    catch(out_of_range)
    {
        throw;
    }
    catch(no_such_object)
    {
        throw;
    }
    catch(invalid_argument)
    {
        throw;
    }

    catch(...)
    {
        throw;
    }

    return at(ndx);
}

/*****************************************************************************************
*           Implementation Code for insert method of the rd_array class                 *
******************************************************************************************/

template <typename T>
void RD_Array<T>::insert( const unsigned long ndx, const T &value)
{
    try
    {
        if (currentSize == currentCapacity)
            increaseCapacity();

        if (ndx < 0 || ndx > currentSize)
        {
            throw out_of_range("Cannot insert, the index value is out of range");
        }
        for (unsigned long i = currentSize; i > ndx; i--)
        {
            contents[i] = contents[i - 1];
        }
        contents[ndx] = value;
        currentSize++;

    }

    catch(bad_alloc)
    {
        throw;
    }
    catch(out_of_range)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*           Implementation Code for push_back method of the rd_array class                 *
******************************************************************************************/

template <typename T>
void RD_Array<T>::push_back(const T &value)
{
    try
    {
        if(currentSize == currentCapacity)
        {
            increaseCapacity();
        }

        contents[currentSize] = value;
        currentSize++;
    }

    catch(bad_alloc)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*           Implementation Code for pop_back method of the rd_array class                 *
******************************************************************************************/

template <typename T>
void RD_Array<T>::pop_back()
{
    try
    {

        if(currentSize == 0)
            throw no_such_object("Cannot popback, the array is empty");

        currentSize--;

    }

    catch(no_such_object)
    {
        throw;
    }
    catch(...)
    {
        throw;
    }

}

/*****************************************************************************************
*           Implementation Code for resize method of the rd_array class                 *
******************************************************************************************/

template <typename T>
void RD_Array<T>::resize(const unsigned long newSize, const T &value)
{
    try
    {
        unsigned long oldSize;

        if(newSize < currentSize)
            currentSize = newSize;

        if(newSize<=currentCapacity)
        {
            oldSize = currentSize;
            currentSize = newSize;

            for(unsigned long i = oldSize; i<= newSize-1; i++)
            {
                contents[i] = value;
            }
        }

        if(newSize > currentCapacity)
        {
            oldSize = currentSize;
            T *tempArray = new T[newSize];

            for(int unsigned long i = 0; i<=oldSize-1; i++ )
                tempArray[i] = contents[i];

            for(unsigned long i = oldSize; i<=newSize-1; i++ )
            {
                tempArray[i] = value;
            }

            delete [] contents;
            contents = tempArray;
            currentCapacity = newSize;
            currentSize = newSize;
        }
    }

    catch(bad_alloc)
    {
        throw;
    }

    catch(...)
    {
        throw;
    }
}

/*****************************************************************************************
*           Implementation Code for empty method of the rd_array class                 *
******************************************************************************************/

template <typename T>
bool RD_Array<T>::empty() const
{
    bool a = true;
    if(currentSize != 0)
        a = false;

    return a;
}

/*****************************************************************************************
*           Implementation Code for clear method of the rd_array class                   *
******************************************************************************************/

template <typename T>
void RD_Array<T>::clear()
{
    currentSize = 0;
}



#endif //COSC052P5_RD_ARRAY_H
