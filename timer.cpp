#include <iostream>

using namespace std;

int initialTime, elapsedTimeA, elapsedTimeB = 0;

int main()
{
  cout << "Press 'ENTER' to start timer, 'CTRL + C' to exit." << endl;
  getchar();
  initialTime = time(0);

  while(1){
    elapsedTimeA = time(0);
    if (elapsedTimeA != elapsedTimeB){
      cout << elapsedTimeA - initialTime << " second(s) elapsed." << endl;
      elapsedTimeB = elapsedTimeA;
    }
  }
}
