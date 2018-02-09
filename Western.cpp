#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define HAS_ARG(x,y) (!strcmp(argv[i], x) && (i + y) < argc) // Yes this isn't mine but this is also my first program so cut me some slack

/*

Now we're telling main that if there is less than 4 given arguments (calling the program itself is the first[aka 0 in the array])
   to then call print out the programs main functions and useable arguments...
*/






int main(int argc, char* argv[]) {

int ret = 0;

if(argc < 3) {

  printf("Usage: %s <file in> <file out> [args]\n", argv[0]); // argv[0] is basically calling the printf functions in the first array: [0] which is "./Western-osx."
      printf("\t-i create a custom ipsw\n");
      printf("\t-p pwn dfu \n");
      printf("\t-k install 24kpwn to NOR\n");
      printf("\t-a install allco8 to NOR\n");
      printf("\t-v install verbose boot to NOR\n");
      printf("\t-c prints out the credits\n");
  return -1;

}

/*

We then create a for loop which checks "i" array, which treats the arguments as an array number (example: '-c' should be [5]).
 Later we can  use the array 5 to represent the argument for other functions, for example, argument '-p' is used in 'k, a, and v'

*/

for(int i = 1; i < argc; i++) {

  if(HAS_ARG("-i", 3)) {
    customIPSW = (char*) argv[i+1];
  }

  if(HAS_ARG("-p", 1)) {
    pwnDFU = (char*) argv[i];
  }

  if(HAS_ARG("-k", 1)) {
    installKpwn = (char*) argv[i];
  }

  if(HAS_ARG("-a", 1)) {
    installAlloc8 = (char*) argv[i];
  }

  if(HAS_ARG("-v", 1)) {
    installVerbose = (char*) argv[i];
  }

  if(HAS_ARG("-c", 1)) {
    printCredits = (char*) argv[i];
  }

}

if (printCredits) {
  ret = cout << "Made by @Vyce_Merculous, @32Bites, and Dingdongding30 on reddit. Original code made by @32bites. Refactored by @Vyce_Merculous into a C++ file." << endl;
  if(!ret) {
      printf("%s: Invalid Argument Given\n");
      return -1;
}

if (installVerbose) {

string dump = "";

cout << "Input a NOR dump file..." << endl;

getline(cin, dump);

ret = system(("cd resources/bin/ && ./ipwndfu --flash-nor=" + dump).c_str());

if(!ret) {
    printf("%s: Invalid Argument Given\n");
    return -1;
}

if (customIPSW) {

  string ipsw = "";

  cout << "Input the file patch of the original ipsw..." << endl;

  getline(cin, ipsw);

  ret = system(("cd resources/bin/ && ./ipsw " + ipsw).c_str());
  if(!ret) {
      printf("%s: Invalid Arguments Given\n");
      return -1;
}

if (pwnDFU) {

ret = system("cd resources/bin/ && ./ipwndfu -p");
if(!ret) {
    printf("%s: Invalid Argument Given\n");
    return -1;
}

if (installKpwn) {

ret = system("cd resources/bin/ && ./ipwndfu --24kpwn");
if(!ret) {
    printf("%s: Invalid Argument Given\n");
    return -1;
}

if (installAlloc8) {

ret = system("cd resources/bin/ && ./ipwndfu -x");
if(!ret) {
    printf("%s: Invalid Argument Given\n");
    return -1;
}

}

}

}

}

}

}

}
