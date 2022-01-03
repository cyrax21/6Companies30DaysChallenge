#include <iostream>
using namespace std;
int main() {
   int size;
   cin>>size;

   // according to formula
   // sum of square in chessboard is 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + .... + n^2
   // Approach 1 : o(n)
   // Approach 2 : sum of squares formula
   cout<<((size)*(size+1)*(2*size+1))/6;
}
