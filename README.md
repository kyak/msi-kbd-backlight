msi-kbd-backlight
=================

** Description **

Control MSI laptop steelseries keyboard backlight using USB HID. I didn't want to use Steelseries bloatware, just needed something simple like this. There is NO error/input checking in this program.

** Prerequisites **

- Linux host is used for building.
- mingw compiler. Most distros have it packaged.
- hidapi library from https://github.com/signal11/hidapi. Some distros have it packaged as e.g. mingw-w64-hidapi.

** Compilation **

Compile like this:

    x86_64-w64-mingw32-gcc hid-cli.c -I/usr/i686-w64-mingw32/include/hidapi -lhidapi -o hid-cli.exe

** Acknowledgement **

Inspired by https://github.com/wearefractal/msi-keyboard. Seems very nice, but also an overkill.

** Deployment **

Include libhidapi-0.dll from hidapi when deploying to Windows. You might want to create a scheduled task to run this utility at logon/resume to maintain your backlight preferences (those are reset after reboot or sleep).

** Usage **

    hid-cli <color num> <intensity num>
    
    Color:
	    off: 0
	    red: 1
	    orange: 2
	    yellow: 3
	    green: 4
	    sky: 5
	    blue: 6
	    purple: 7
	    white: 8
    Intensity:
	    lowest: 3
	    low: 2
	    med: 1
	    high: 0

** Example **

White color, lowest intensity:
    
    hid_cli 8 3

Blue color, highest intensity:

    hid_cli 6 0

** Binary release **

