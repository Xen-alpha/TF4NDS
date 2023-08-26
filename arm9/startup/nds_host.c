/*---------------------------------------------------------------------------------

	QWTF Lite Port host code
	-- generated by Maniac Xena
	-- QWTF is Team Fortress Software's property
	-- based on cquake project source code
---------------------------------------------------------------------------------*/

#include <host.h>
#include <sys.h>


int Host_Exit(void) {
	// ask if player want to exit the game and turn off NDS

	return 0;
}

void Host_Init(quakeparms_t* parms)
{
	// Initialize game system
	return;
}

void Host_Frame(float time) {
	double	time1, time2;
	static double	timetotal;
	static int		timecount;
	int		i, c, m;

	time1 = Sys_FloatTime();
	_Host_Frame(time);
	time2 = Sys_FloatTime();

	timetotal += time2 - time1;
	timecount++;

	if (timecount < 1000)
		return;

	m = timetotal * 1000 / timecount;
	timecount = 0;
	timetotal = 0;

	// TODO: Check if the game need the loop code below
	/*
	c = 0;
	for (i = 0; i < svs.maxclients; i++)
	{
		if (svs.clients[i].active)
			c++;
	}
	*/
	return;
}

void _Host_Frame(float time) {
	// In-game Main Loop
	return;
}