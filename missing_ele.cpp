//
// Created by babayega on 12/2/15.
//

#include "missing_ele.h"
#include <vector>
#include <iostream>


namespace miss
{

    void missing(int arr[], int n)
    {
        std::vector<int > arr1(n+1, 0);
        for (int i = 0; i <= n; ++i)
            ++arr1[arr[i]];
        for (int j = 1; j <= n; ++j)
        {
            std::cout<<" "<<arr1[j];
            if (arr1[j] == 0)
                std::cout<<"The missing element is "<<j<<"\n";
            if (arr1[j] == 2)
                std::cout<<"The repeated element is "<<j<<"\n";

        }

    }

    void execute()
    {
        int arr[] = {1, 2, 4, 5, 7, 6, 2};
        int  n = sizeof(arr)/sizeof(arr[0]);
        missing(arr, n);
    }
}