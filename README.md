# Western
A project? I guess. Will include 3GS 3.0 and 3.0.1 bundles soon.
A wrapper for OUTDATED ipwndfu.
For license info, check the LICENSE file.

## Compiling

`cd` into the Western source code directory, then type `g++ Western.cpp -o Western` or `clang++ Western.cpp -o Western`

## Usage

Just `cd` into the Western folder with the compiled binary, then just type:  `./Western -h` for help

## Credit
* 32Bites for making the original script, and doing a bit of patching up stuff.
* Merculous for compiling and refactoring original script into a C++ file.
* Axi0mX for ipwndfu.
* planetbeing for XPwn.
* Dingdongding30 on Reddit for some tips :P.
* 0xFF for making this suck less

## Using verbose NOR dumps..

Since certain versions of the NOR dumps are not all compatible with specific iOS versions, when flashing the custom NOR dump, ipwndfu backs up your original NOR.
This is because not all dumps are cross-compatible which means if you're stuck in a boot-loop, just flash your backed up NOR dump to get rid of the boot-loop.

This is VERY useful if your using other people's NOR.
