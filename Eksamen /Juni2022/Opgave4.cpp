#include <iostream>
#include <vector>
#include <string>

std::vector<int> total(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::vector<int> vec;

    for (int i = 0; i < a.size(); i++)
    {
        vec.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        vec.push_back(b[i]);
    }
    for (int i = 0; i < c.size(); i++)
    {
        vec.push_back(c[i]);
    }
    return vec;
}

std::vector<int> sort(std::vector<int> vec)
{
    int min;
    int temp;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = vec[i];
            vec[i] = vec[min];
            vec[min] = temp;
        }
    }
    return vec;
}


std::vector<int> merge(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::vector<int> one = total(a, b, c);
    return sort(one);
    
}

int main()
{
    std::vector<int> a = {3, 4, 10, 23, 147};
    std::vector<int> b = {1, 5, 6, 27, 34, 68, 72};
    std::vector<int> c = {8, 10, 19, 45, 47, 60};
    std::vector<int> output = merge(a, b, c);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}