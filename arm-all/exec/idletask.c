#include <exec/types.h>
#include <asm/registers.h>

#include <proto/exec.h>

#define DEBUG 0
#include <easyos/debug.h>

void idleTask(void)
{
	ULONG i = 0;
	while (1) {
		if (0 == (i % 5000000)) {	
			D(bug("idle Task tick!\n"));
		}
		i ++;
	}
}
Footer
