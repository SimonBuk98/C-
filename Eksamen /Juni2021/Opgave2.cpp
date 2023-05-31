#include <vector>
#include <iostream>
#include <cmath>

bool chechTriplet(int a, int b, int c)
{
    if (a * a + b * b == c * c)
        return true;
    if (b * b + c * c == a * a)
        return true;
    if (c * c + a * a == b * b)
        return true;
    return false;
}

bool PythagorasTriplet(std::vector<int> &pyt)
{
    for (int i = 0; i < pyt.size() - 2; i++)
    {
        for (int j = i + 1; j < pyt.size(); j++)
        {
            for (int k = j + 1; k < pyt.size(); k++)
            {
                if (chechTriplet(pyt[i], pyt[j], pyt[k]))
                {
                    for (int l = pyt.size() - 1; l >= 0; l--)
                    {
                        if (l == i || l == j || l == k)
                        {
                            pyt.erase(pyt.begin() + l);
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false; 
}

std::vector<int> removeTriplets(std::vector<int> vec){
    while(PythagorasTriplet(vec)){
        std::cout << "Removed a triplet" << std::endl;
    }
    return vec;
}


int main(int argc, char** argv){
    std::vector<int> myVec{6, 25, 5, 3, 7, 24, 4, 23};
    std::vector<int> result = removeTriplets(myVec);
    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << std::endl;
    }
}