/* Control MSI steelseries keyboard LED using USB HID
 * Compile like this:
 * x86_64-w64-mingw32-gcc hid-cli.c -I/usr/i686-w64-mingw32/include/hidapi -lhidapi -o hid-cli.exe
 * External dependencies: https://github.com/signal11/hidapi. Some distros have it packaged as e.g. mingw-w64-hidapi
 * Include libhidapi-0.dll from hidapi when deploying to Windows */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "hidapi.h"

int main(int argc, char* argv[])
{
	int res, i;
	unsigned char buf[8];
	hid_device *handle;

	char *help = \
"Usage: hid-cli <color num> <intensity num>\n"
"Color:\n"
"	off: 0,\n"
"	red: 1,\n"
"	orange: 2,\n"
"	yellow: 3,\n"
"	green: 4,\n"
"	sky: 5,\n"
"	blue: 6,\n"
"	purple: 7,\n"
"	white: 8\n"
"Intensity:\n"
"	lowest: 3,\n"
"	low: 2,\n"
"	med: 1,\n"
"	high: 0";
	
	if (argc < 2)
	{
		printf(help);
		return 0;
	}

	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x1770, 0xff00, NULL);

	// Prepare buffer with color settings
	buf[0] = 1;
	buf[1] = 2;
	buf[2] = 66;
	// Region
	buf[3] = 1;
	// Color
	buf[4] = atoi(argv[1]);
	// Intensity
	buf[5] = atoi(argv[2]);
	buf[6] = 0;
	buf[7] = 236;
	
	// Apply settings to all regions
	for (i = 1; i < 4; i++)
	{
		buf[3] = i;
		res = hid_send_feature_report(handle, buf, 8);
	}
	
	// It is required to set mode to submit color settings
	buf[0] = 1;
	buf[1] = 2;
	buf[2] = 65;
	// Always setting to 'normal' mode
	buf[3] = 1;
	buf[4] = 0;
	buf[5] = 0;
	buf[6] = 0;
	buf[7] = 236;
	res = hid_send_feature_report(handle, buf, 8);

	// Finalize the hidapi library
	res = hid_exit();

	return 0;
}
