#include <iostream>
#include <vector>
#include <string>

std::string translate(std::string sentence, std::vector<std::vector<std::string>> dictionary)
{
    std::vector<std::string> word;
    std::string s;

    for (int i = 0; i <=sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            word.push_back(s);
            s = "";
        }
        else if (i == sentence.size())
        {
            word.push_back(s);
            s = "";
        }
        else
        {
            s += sentence[i];
        }
    }

    for (int i = 0; i <=dictionary.size()-1; i++)
    {
        for (int j = 0; j <=dictionary.size()-1; j++)
        {
            if (word[i] == dictionary[j][0])
            {
                s += dictionary[j][1] + ' ';
            }
        }
    }
    return s;
}

int main(int argc, char **argv)
{
    std::string sentence = "det er en god dag at programmere";
    std::vector<std::vector<std::string>> dictionary;
    dictionary.push_back(std::vector<std::string>{"at", "to"});
    dictionary.push_back(std::vector<std::string>{"dag", "day"});
    dictionary.push_back(std::vector<std::string>{"det", "it"});
    dictionary.push_back(std::vector<std::string>{"en", "a"});
    dictionary.push_back(std::vector<std::string>{"er", "is"});
    dictionary.push_back(std::vector<std::string>{"god", "good"});
    dictionary.push_back(std::vector<std::string>{"programmere", "program"});
    std::cout << sentence << std::endl;
    std::cout << translate(sentence, dictionary) << std::endl;
    return 0;
}