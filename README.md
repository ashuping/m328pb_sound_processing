# ATmega328pb sound processing experiments

I am using this repository to test out some DSP operations on the Atmel [ATmega328pb microcontroller](https://www.microchip.com/wwwproducts/en/atmega328pb). The project assumes an 8MHz clock (this comes stock on the 328pb, as long as you make sure to **unprogram the CKDIV8 fuse** - `write lfuse 0 0xe2` in the avrdude terminal will set up the fuses as appropriate).

## Instructions for getting the command-line toolchain working

**This requires Linux, avr-gcc, avr-objcopy, avr-size (for compiling and linking), and avrdude (for uploading).** These tools are available in the standard repositories for most linux distributions (on Ubuntu, the packages are `binutils-avr`, `avr-libc`, and `avrdude`). At the time of writing, it also requires several additional steps to add support for the 328pb. 

1. Download the [Device Family Pack](http://packs.download.atmel.com/) for the ATmega device family.
1. Change the `.atpack` file extension to `.zip` and unzip the file.
1. In your local copy of this repository, set the path to the directory extracted from the zip-file in `config.makerules.example`, then rename `config.makerules.example` to `config.makerules`
1. You'll need a programmer to program the ATmega328pb - if you have an ATMEL-ICE programmer, it should work out of the box (there is a target in the makefile for this, so you can just type `make upload` to compile and upload). If you don't have an ICE, you'll have to edit the flags passed to avrdude as appropriate - these are stored as $UF in the makefile. If you don't have a programmer, and you don't want to spend an unreasonable amount of money buying Atmel's programmer, you can make a bootleg one out of an Arduino board - see [this page](https://www.instructables.com/id/Turn-Your-Arduino-Into-an-ISP/). Note that, for programming, the 328pb uses PB3/4/5 as MOSI/MISO/SCK, along with VCC/GND/RESET (PC6).
1. Don't forget to unprogram CLKDIV8 to make your chip's internal clock run at 8MHz. `make term` with your device appropriately connected will open an avrdude terminal for you; type `write lfuse 0 0xe2` to set your lower-fuse byte to an appropriate value (the default, but with CLKDIV8 unprogrammed).