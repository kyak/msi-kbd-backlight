msi-kbd-backlight
=================

Control MSI laptop steelseries keyboard backlight using USB HID

Compile like this:
  x86_64-w64-mingw32-gcc hid-cli.c -I/usr/i686-w64-mingw32/include/hidapi -lhidapi -o hid-cli.exe

External dependencies: https://github.com/signal11/hidapi. Some distros have it packaged as e.g. mingw-w64-hidapi

Include libhidapi-0.dll from hidapi when deploying to Windows

Usage: hid-cli <color num> <intensity num>
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
	
