/*==========================================================================================================*\
 * author: Pawel Kusinski
 * email:  pawel.kusinski@gmail.com
\*==========================================================================================================*/

#include <stdint.h>
#include <stdbool.h>

typedef enum _mcp4822_channel_t {
	MCP_4822_CHANNEL_A,
	MCP_4822_CHANNEL_B,
} mcp4822_channel_t;

bool mcp4822_initialize(void);
bool mcp4822_set_voltage(mcp4822_channel_t channel, uint16_t value_mV);
void mcp4822_deinitialize(void);
