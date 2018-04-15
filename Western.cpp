#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int printCredits() {
   cout << "Made by @Vyce_Merculous, @32Bites, and Dingdongding30 from reddit." << endl;
   cout << "Original code made by @32bites. Refactored by @Vyce_Merculous into a C++ file." << endl;
   cout << "Made less suck-y by 0xFF" << endl;
   exit 0;
}

int installVerbose() {
   string dump = "";
   cout << "Input a NOR dump file..." << endl;
   getline(cin, dump);
   system(("cd resources/bin/ipwndfu && ./ipwndfu --flash-nor=" + dump).c_str());
}

int customIPSW() {
  string ipsw = "";
  string custom = "*"; // ipsw will create a custom ipsw, leaving it in the source directory..
  cout << "Input the file path of the original ipsw..." << endl;
  getline(cin, ipsw);
  system(("cd resources/bin/ && ./ipsw " + ipsw + custom).c_str());
}

int pwnDFU() {
    string waitDFU;
    cout << "Put your device into DFU mode, then hit Enter when done." << endl;
    getline(cin, waitDFU);
    system("cd resources/bin/ipwndfu && ./ipwndfu -p");
}

int install24KPWN() {
    pwnDFU();
    system("cd resources/bin/ipwndfu && ./ipwndfu --24kpwn");
}

int installAlloc8() {
    pwnDFU();
    system("cd resources/bin/ipwndfu && ./ipwndfu -x");
}

int main(int argc, char* argv[]) {
   /*
   * Now we're telling main that if there is less than 4 given arguments (calling the program itself is the first [aka 0 in the array] )
   * to then call print out the programs main functions and useable arguments...
   */
   if ( argc < 2 || argc >= 4 ) {
      cout << "Usage: " << argv[0] << " [args]" << endl;
      cout << "-h: Prints this help menu" << endl;
      cout << "-i: Creates a custom IPSW" << endl;
      cout << "-p: Enter Pwned DFU for restoration of a custom firmware" << endl;
      cout << "-k: Install 24kpwn to the NOR" << endl;
      cout << "-a: Install alloc8 to the NOR" << endl;
      cout << "-v: Flashes NOR with verbose boot-args to device" << endl;
      cout << "-c: Prints Credits" << endl;
   }
/*
* Checks if argv[1] (the argument passed) is equal to the valid options.
* If it is valid, it runs the correct funtion. If it is not a valid option, it prints a error message, then it exits.
*/
   for(int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-i") == 0) { customIPSW(); }
      if (strcmp(argv[i], "-p") == 0) { pwnDFU(); }
      if (strcmp(argv[i], "-k") == 0) { install24KPWN(); }
      if (strcmp(argv[i], "-a") == 0) { installAlloc8(); }
      if (strcmp(argv[i], "-v") == 0) { installVerbose(); }
      if (strcmp(argv[i], "-c") == 0) { printCredits(); }
   }
}
