/*
 * fclose.c
 */

#include "stdioint.h"

int fclose(FILE *file)
{
	struct _IO_file_pvt *f = stdio_pvt(file);
	int rv;

	fflush(file);

	rv = f->funcs.close(f->cookie);

	/* Remove from linked list */
	f->next->prev = f->prev;
	f->prev->next = f->next;

	free(f);
	return rv;
}
