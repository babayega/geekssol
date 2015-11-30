//
// Created by babayega on 11/30/15.
//

#include <iostream>
#include "equilibrium_index.h"

namespace index
{

    void equilibrium_index(int arr[], int n)
    {
        int sum = 0, left_sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i];
        for (int j = 0; j < n; ++j)
        {
            sum -= arr[j];
            if (left_sum == sum)
                std::cout << " " << j;
            else
                left_sum += arr[j];
        }
    }

    void execute()
    {
        int arr[] = {-7, 1, 5, 2, -4, 3, 0};
        int arr_size = sizeof(arr)/sizeof(arr[0]);
        equilibrium_index(arr, arr_size);
    }

}