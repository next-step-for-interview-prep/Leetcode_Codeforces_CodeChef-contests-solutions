#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int purchaseAmount = 0;
    cin >> purchaseAmount;
    if ((purchaseAmount % 10) >= 5)
        purchaseAmount = purchaseAmount - purchaseAmount % 10 + 10;

    else
        purchaseAmount = purchaseAmount - (purchaseAmount % 10);

    cout << 100 - purchaseAmount << endl;
    return 0;
}