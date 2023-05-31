#include <iostream>
#include <vector>
#include <string>

void cleanPhoneBook(std::vector<std::vector<std::string>> &phoneBook)
{
    // Saml alle navne
    for (int i = 0; i < phoneBook.size() - 1; i++)
    {
        int j = i + 1;
        while (j < phoneBook.size())
        {
            /* if the name in i and j are the same, copy all numbers
            and remove j'th entry in the phonebook */
            if (phoneBook[i][0] == phoneBook[j][0])
            {
                for (int k = 1; k < phoneBook[j].size(); k++)
                {
                    phoneBook[i].push_back(phoneBook[j][k]);
                }
                phoneBook.erase(phoneBook.begin() + j);
            }
            else
            {
                j++;
            }
        }
    }

    // Fjern dublicates
    for (int i = 0; i < phoneBook.size(); i++)
    {
        for (int j = 1; j < phoneBook[i].size() - 1; j++)
        {
            int k = j + 1;
            while (k < phoneBook[i].size())
            {
                /* if the j'th and k'th number are the same,
                remove the k'th number */
                if (phoneBook[i][j] == phoneBook[i][k])
                {
                    phoneBook[i].erase(phoneBook[i].begin() + k);
                }
                else
                {
                    k++;
                }
            }
        }
    }
}

int main()
{
    std::vector<std::string> cardOne{"mor", "20202020", "12345678"};
    std::vector<std::string> cardTwo{"mor", "87654321", "20202020"};
    std::vector<std::string> cardThree{"far", "01010101", "33344455"};
    std::vector<std::string> cardFour{"mor", "24682468"};
    std::vector<std::string> cardFive{"mormor", "11112222"};
    std::vector<std::string> cardSix{"far", "01010101"};
    std::vector<std::vector<std::string>> phoneBook{cardOne,
                                                    cardTwo,
                                                    cardThree,
                                                    cardFour,
                                                    cardFive,
                                                    cardSix};

    cleanPhoneBook(phoneBook);

    for (std::vector<std::string> v : phoneBook)
    {
        for (std::string s : v)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}