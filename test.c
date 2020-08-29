#include <stdio.h>
#include <unistd.h>
#include "mcp4822.h"
#include <math.h>

int main(void)
{
	printf("MCP4822 Linux Test\n");

	if(!mcp4822_initialize()) {
		printf("Failed to initialize MCP4822.\n");
		return -1;
	}

	uint16_t voltage = 0;
	const double sine_step = 2 * M_PI / 4095.0;
	double sine_val = 0.0;
	double sine_res;

	for(;;) {
		/* channel A: sawtooth */
		mcp4822_set_voltage(MCP_4822_CHANNEL_A, voltage);
		++voltage;
		if (voltage >= 4095)
			voltage = 0;

		/* channel B: sine */
		sine_res = sin(sine_val);
		sine_res += 1.0;
		mcp4822_set_voltage(MCP_4822_CHANNEL_B, (uint16_t)((4095.0  / 2.0) * sine_res));


		sine_val += sine_step;
		if(sine_val >= (2 * M_PI))
			sine_val = 0.0;

		usleep(1000);
	}

	mcp4822_deinitialize();
	return 0;
}
