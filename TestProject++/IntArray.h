#include <assert.h>


#ifndef INT_ARRAY_H
#define INT_ARRAY_H
class IntArray{

private:
    //used to define length
    int m_nLength;
    //pointer to the array (* points to the value, not the reference)
    int *m_pnData;

public:
    //constructor without parameter
    IntArray()
    {
        m_nLength = 0;
        m_pnData = 0;
        //ctor
    }
    //constructor with length-parameter
    IntArray(int length)
    {
        //Allocate memory
        m_pnData = new int[length];
        m_nLength = length;
    }

    ~IntArray()
    {
        //deletes pointer
        delete[] m_pnData;
    }

    void eraseArray()
    {
        //deallocate pointer
        delete[] m_pnData;
        //ensures that the pointer does not point to deallocated memory
        m_pnData = 0;
        m_nLength = 0;
    }

    //use operator [] to get element at index [index]
    int& operator[](int nIndex)
        {
            //check if index is > 0 and inside the array
            assert(nIndex >= 0 && nIndex < m_nLength);
            return m_pnData[nIndex];
        }


    int getLength(){ return m_nLength; }

    //deletes elements and creates new array (faster than resize)
    void reallocate(int newLength )
    {
        //erase old array
        eraseArray();

        //if newly defined length not long enough abort
        if(newLength <= 0){return;}

        //reallocate pnData to new memory
        m_pnData = new int[newLength];
        m_nLength = newLength;
    }

    //copies elements in newly defined array (slower than reallocate)
    void resizeArray(int newLength)
    {
        //if new array would be empty...
        if(newLength <= 0)
        {
            //...just erase its elements
            eraseArray();
            return;
        }

        //create new pointer (allocates new memory)
        int *newPnData = new int[newLength];

        //check if length is at least 1
        if(m_nLength > 0)
        {
            //create temporary value to iterate through old array
            int elementsToCopy = (newLength > m_nLength) ? m_nLength : newLength;

            //for each value: copy it into the new array
            for (int index = 0; index < elementsToCopy; index++)
            {
                newPnData[index] = m_pnData[index];
            }
        }

        //delete old pointer
        delete[] m_pnData;

        //redefine values
        m_pnData = newPnData;
        m_nLength = newLength;

    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_nLength);

        //allocate new memory for the array, 1 longer for the new element
        int *pnData = new int[m_nLength+1];

        //copy old array into new one (elements before index)
        for(int before = 0; before < index; before++)
        {
            pnData[before] = m_pnData[before];
        }

        //insert new element at position index
        pnData[index] = value;

        //copy old array into new one (elements after index)
        for(int after = index; after < m_nLength; after++)
        {
            pnData[after+1] = m_pnData[after];
        }

        //delete old pointer and set 0 to avoid adressing deallocated memory
        delete[] m_pnData;
        m_pnData = 0;
        m_nLength += 1;
    }

    void removeElement(int index)
    {
        assert(index <= 0 && index < m_nLength);

        //create new pointer, one element longer
        int *pnData = new int[m_nLength-1];

        //copy old array into new one (elements before index)
        for(int before = 0; before < index; before++)
        {
            pnData[before] = m_pnData[before];
        }

        //copy old array into new one (elements after index)
        for(int after = index + 1; after < m_nLength; after++)
        {
            pnData[after-1] = m_pnData[after];
        }
        //delete old pointer and set 0 to avoid adressing deallocated memory
        delete[] m_pnData;
        m_pnData = pnData;
        m_nLength -= 1;
    }

    void insertAtBeginning(int value){ insertBefore(value, 0);}
    void insertAtEnd(int value){ insertBefore(value,m_nLength);}
};
#endif // INT_ARRAY_H
