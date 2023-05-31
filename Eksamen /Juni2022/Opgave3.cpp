#include <iostream>
#include <vector>
#include <string>

void print(std::vector<std::string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

void inputVec(std::vector<std::string> vec, std::string sentence, std::string inputLetters)
{
    for (int i = 0; i < inputLetters.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (inputLetters[i] == std::tolower(sentence[j]))
            {
                vec[j] = inputLetters[i];
            }
        }
        print(vec);
    }
}

void printHangman(std::string sentence, std::string inputLetters)
{
    std::vector<std::string> vek;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] != ' ')
        {
            vek.push_back("-");
        }
        else
        {
            vek.push_back(" ");
        }
    }
    print(vek);
    inputVec(vek, sentence, inputLetters);
}

int main(int argc, char **argv)
{
    std::string sentence = "A great day to program";
    std::string inputLetters = "aeog";
    printHangman(sentence, inputLetters);
    return 0;
}