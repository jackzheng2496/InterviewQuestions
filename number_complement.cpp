#include <iostream>
#include <bitset>

/*
    Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
*/
 
int findComplement(int num)
{
    int i, j = 0;

    for (int k = 0; num; k++) {
        i = 1 << k;
        j |= i ^ (i & num);
        num &= ~i;
    }

    return j;
}

int main()
{
    int i;

    std::cout << "Enter a number: ";
    std::cin >> i;

    int j = findComplement(i);
    std::cout << "j: " << j << "\n";
}


