#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void printHangman(string sentence, string input)
{
    vector<char> word;
    vector<char> output;
    for (int i = 0; i < sentence.length(); i++)
    {
        word.push_back(sentence[i]);
        if (sentence[i] == ' ')
        {
            output.push_back(' ');
        }
        else
        {
            output.push_back('-');
        }
    }
    for (int k = 0; k < sentence.length(); k++)
    {
        cout << output[k];
    }
    cout << endl;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < sentence.length(); j++)
        {
            if (tolower(sentence[j]) == input[i])
            {
                char newChar = input[i];
                output[j] = input[i];
            }
        }
        for (int k = 0; k < sentence.length(); k++)
        {
            cout << output[k];
        }
        cout << endl;
    }
    cout << endl;
}
// Opgave 2:
vector<int> merge(vector<int> a, vector<int> b, vector<int> c)
{
    vector<int> total;

    for (int i = 0; i < a.size(); i++)
    {
        total.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        total.push_back(b[i]);
    }
    for (int i = 0; i < c.size(); i++)
    {
        total.push_back(c[i]);
    }

    int min;
    int temp;
    int length = total.size();
    for (int i = 0; i < length - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (total[j] < total[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = total[i];
            total[i] = total[min];
            total[min] = temp;
        }
    }
    return total;
}

int main(int argc, char **argv)
{
    string sentence = "A great day to program";
    string inputLetters = "aeog";
    printHangman(sentence, inputLetters);

    vector<int> a = {3, 4, 10, 23, 147};
    vector<int> b = {1, 5, 6, 27, 34, 68, 72};
    vector<int> c = {8, 10, 19, 45, 47, 60};
    vector<int> output = merge(a, b, c);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << " ";
    }
    
    std::cout << std::endl;
    return 0;
}