#include <iostream>
#include <vector>
#include <string>

int left(int brik)
{
    return brik / 10;
}
int right(int brik)
{
    return brik % 10;
}
int rotate(int brik)
{
    return 10 * right(brik) + left(brik);
}

std::vector<int> makeValid(std::vector<int> numbers)
{
    std::vector<int> output;
    output.push_back(numbers[0]);
    int curnum = right(numbers[0]);
    for (int i = 1; i < numbers.size(); i++)
    {
        if (curnum == left(numbers[i]))
        {
            output.push_back(numbers[i]);
            curnum = right(numbers[i]);
        }
        else if (curnum == right(numbers[i]))
        {
            output.push_back(rotate(numbers[i]));
            curnum = left(numbers[i]);
        }
        else
        {
            std::vector<int> noValid;
            return noValid;
        }
    }
    return output;
}

int main()
{
    std::vector<int> a = {11, 13, 53, 52};
    std::vector<int> b = {11, 13, 52, 22};
    std::vector<int> c = {66, 56, 45, 46, 62};
    a = makeValid(a);
    std::cout << "a: ";
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    b = makeValid(b);
    std::cout << "b: ";
    for (int i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    c = makeValid(c);
    std::cout << "c: ";
    for (int i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}