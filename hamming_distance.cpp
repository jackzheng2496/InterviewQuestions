#include <iostream>

/*
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.
*/
int hammingDistance(int x, int y)
{
    int hd;

    x ^= y;

    for (hd = 0; x; x &= (x-1), hd++)
        ;

    return hd;
}

int main()
{
    int x, y;

    //std::cout << "Hamming Distance: " << hammingDistance(x, y) << "\n";

    std::cout << "Enter First Number: ";
    std::cin >> x;

    std::cout << "Enter Second Number: ";
    std::cin >> y;
    
    std::cout << "X: " << x << "\n";
    std::cout << "Y: " << y << "\n";
    std::cout << "Calculating Hamming Distance\n";
    std::cout << hammingDistance(x, y) << "\n";
}
