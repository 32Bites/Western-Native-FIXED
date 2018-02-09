#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*

Now we're telling main that if there is less than 4 given arguments (calling the program itself is the first[aka 0 in the array])
   to then call print out the programs main functions and useable arguments...
*/

void printCredits() {

   cout << "\nMade by @Vyce_Merculous, @32Bites, and Dingdongding30 on reddit. Original code made by @32bites. Refactored by @Vyce_Merculous into a C++ file.\n" << endl;

}

void installVerbose() {

string dump = "";

cout << "Input a NOR dump file..." << endl;

getline(cin, dump);

system(("cd resources/bin/ipwndfu && ./ipwndfu --flash-nor=" + dump).c_str());

}


void customIPSW() {

  string ipsw = "";

  string custom = "*"; // ipsw will create a custom ipsw, leaving it in the source directory..

  cout << "Input the file path of the original ipsw..." << endl;

  getline(cin, ipsw);
    
  system(("cd resources/bin/ && ./ipsw " + ipsw + custom).c_str());

}

void pwnDFU() {
    
    system("cd resources/bin/ipwndfu && ./ipwndfu -p");

}

void installKpwn() {
    
    pwnDFU();

    system("cd resources/bin/ipwndfu && ./ipwndfu --24kpwn");

}

void installAlloc8() {
    
    pwnDFU();

    system("cd resources/bin/ipwndfu && ./ipwndfu -x");

}

int main(int argc, char* argv[]) {

if ( argc < 2 || argc >= 4 ) {

  printf("Usage: %s <file in> <file out> [args]\n", argv[0]); // argv[0] is basically calling the printf functions in the first array: [0] which is "./Western-osx."
      printf("\t-i create a custom ipsw\n");
      printf("\t-p pwn dfu \n");
      printf("\t-k install 24kpwn to NOR\n");
      printf("\t-a install allco8 to NOR\n");
      printf("\t-v install verbose boot to NOR\n");
      printf("\t-c prints out the credits and info about the program\n");
  return -1;

}

/*

 Checks if argv[1] (the argument passed) is equal to the valid options.
 If it is valid, it runs the correct funtion. If it is not a valid option, it prints a error message, then it exits.

*/

for(int i = 1; i < argc; i++) {

if (strcmp(argv[i], "-i") == 0)
  customIPSW();
if (strcmp(argv[i], "-p") == 0)
  pwnDFU();
if (strcmp(argv[i], "-k") == 0)
  installKpwn();
if (strcmp(argv[i], "-a") == 0)
  installAlloc8();
if (strcmp(argv[i], "-v") == 0)
  installVerbose();
if (strcmp(argv[i], "-c") == 0)
  printCredits();

}

}
