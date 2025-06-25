// sys_null.h -- null system driver to aid porting efforts

#include <nds.h>
#include "quakedef.h"
#include "errno.h"

/*
================
filelength
================
*/
int filelength (FILE *f)
{
	int		pos;
	int		end;

	pos = ftell (f);
	fseek (f, 0, SEEK_END);
	end = ftell (f);
	fseek (f, pos, SEEK_SET);

	return end;
}


int	Sys_FileTime (char *path)
{
	FILE	*f;
	
	f = fopen(path, "rb");
	if (f)
	{
		fclose(f);
		return 1;
	}
	
	return -1;
}

void Sys_mkdir (char *path)
{
}


/*
===============================================================================

SYSTEM IO

===============================================================================
*/

void Sys_MakeCodeWriteable (unsigned long startaddr, unsigned long length)
{
}


void Sys_DebugLog(char *file, char *fmt, ...)
{
}

void Sys_Error (char *error, ...)
{
	va_list		argptr;

	printf ("I_Error: ");	
	va_start (argptr,error);
	vprintf (error,argptr);
	va_end (argptr);
	printf ("\n");
  while (1)
    swiWaitForVBlank(); // Wait for VBlank to avoid freezing the system

	exit (1);
}

void Sys_Printf (char *fmt, ...)
{
	va_list		argptr;
	
	va_start (argptr,fmt);
	vprintf (fmt,argptr);
	va_end (argptr);
}

void Sys_Quit (void)
{
	exit (0);
}

double Sys_DoubleTime (void)
{
	static double t;
	
	t += 0.1;
	
	return t;
}

char *Sys_ConsoleInput (void)
{
	return NULL;
}

void Sys_Sleep (void)
{
}

void Sys_SendKeyEvents (void)
{
}

void Sys_HighFPPrecision (void)
{
}

void Sys_LowFPPrecision (void)
{
}

//=============================================================================

void quake_main (int argc, char **argv)
{
	quakeparms_t	parms;

  int remaining_memory = MINIMUM_MEMORY; // 4MB

  // we don't know how much memory is available, so we just allocate
  // until we run out of memory or reach the minimum required size.
  parms.membase = (char *) malloc (remaining_memory);
  while (!parms.membase || !remaining_memory) {
    remaining_memory -= 1024;
    parms.membase = (char *) malloc (remaining_memory);
  }

	parms.memsize = remaining_memory;
	
  // printf("Setting memory base to %p, size: %d\n", parms.membase, parms.memsize);
	parms.basedir = "nitro:";

	COM_InitArgv (argc, argv);

	parms.argc = com_argc;
	parms.argv = com_argv;

	//printf ("Host_Init\n");
	Host_Init (&parms);
  //printf ("Entering Host_Frame...\n");
	while (1)
	{
		Host_Frame (0.1);
	}
}


