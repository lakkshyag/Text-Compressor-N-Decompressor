#include <vector>
using namespace std;

class charFreq
{
    public:
    char c;
    int freq;

    charFreq(char c, int freq)
    {
        (*this).c = c;
        (*this).freq = freq; 
    }

    charFreq(int freq)
    {
        c = '\0';
        (*this).freq = freq;
    }

    charFreq()
    {
        c = '\0';
        freq = 0;
    }

    bool operator < (charFreq &curr)
    {
        return freq < curr.freq;
    }

    bool operator > (charFreq &curr)
    {
        return freq > curr.freq;
    }

    bool operator == (charFreq &curr)
    {
        return freq == curr.freq;
    }

    bool operator >= (charFreq &curr)
    {
        return freq >= curr.freq;
    }

    bool operator <= (charFreq &curr)
    {
        return freq <= curr.freq;
    }
};

template <typename T>
class priorityQueue                                                                  
{
    vector<T> pq;    

    public:

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    charFreq getMin()
    {
        if ( isEmpty() )
        {
            return 0;
        }
        else
        {
            return pq.at(0);
        }
    }

    void insert(T element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while ( childIndex > 0 )
        {
            int parentIndex = (childIndex - 1)/2;

            if ( pq[childIndex] < pq[parentIndex] )
            {
                T temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    T removeMin()
    {
        if ( isEmpty() )
        {
            return 0;
        }

        T ans = pq[0];
        int lastIndex = pq.size() - 1;
        pq[0] = pq[lastIndex];
        pq.pop_back();
        lastIndex--;

        int i = 0;            
        while ( i <= lastIndex )
        {
    
            int minIndex = i;
            int leftChildI = 2*i + 1;
            int rightChildI = 2*(i + 1);

            if ( (leftChildI <= lastIndex) && ( pq[leftChildI] < pq[minIndex] ) )
            {
                minIndex = leftChildI;
            }
            if ( (rightChildI <= lastIndex) && ( pq[rightChildI] < pq[minIndex] ) ) 
            {
                minIndex = rightChildI;
            }   
            if ( minIndex == i )
            {
                break;
            }

            T temp = pq[i];
            pq[i] = pq[minIndex];
            pq[minIndex] = temp;
            
            i = minIndex;
        }

        return ans;
    }
};