#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;


void FindSubSet(int n)
{
    stack<int> res;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            res.push(j);
            int next = j + 1, count = i;
            while (res.size() <= i)
            {                
                for(int k = next; k < n; k++)
                {
                    if((k - 2) != res.top())
                    {
                        res.push(k);
                    }
                }
            }
            
        }
    }
}

int main()
{
    FindSubSet(10);

}