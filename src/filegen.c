/*
 * Copyright 1993-2002 Christopher Seiwald and Perforce Software, Inc.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * filegen.c - scan directories and archives on NT
 *
 * External routines:
 *
 *	file_open() - opens a file, same as fopen, apart from file handle will
 *	              not be inherited by spawned processes.
 */

# include "jam.h"
# include <stdio.h>
# include <io.h>
# include <fcntl.h>
# include <share.h>
# include <sys/stat.h>

/*
 * file_open() - opens a file, same as fopen, apart from file handle will
 *               not be inherited by spawned processes.
 */
FILE*
file_open( char const * const filename, char const * const mode )
{
	int		fileNo	= -1;
	// Open flags should prevent this file handle being inheritable (by other processes).
	int		openFlags = 0;//_O_NOINHERIT;
	int		shareFlags = 0;
	// Once file is closed, it's permission mode should be read/write (not read only).
	int		permissionMode = _S_IREAD | _S_IWRITE;
	size_t	strLen = strlen( filename );
	size_t	i = 0;

	for ( i = 0; i < strLen; ++i )
	{
		switch ( mode[ i ] )
		{
			case 'b':
			{
				openFlags |= _O_BINARY;
			}
			break;

			case 'r':
			{
				openFlags	|= _O_RDONLY;
				shareFlags	|= _SH_DENYNO;
			}
			break;

			case 'w':
			{
				openFlags	|= _O_CREAT | _O_WRONLY;
				shareFlags	|= _SH_DENYWR;
			}
			break;

			case 'a':
			{
				openFlags |= _O_CREAT | _O_WRONLY | _O_APPEND;
				shareFlags	|= _SH_DENYWR;
			}
			break;

			default:
			{
				return fopen( filename, mode );
			}
		}
	}

	_sopen_s(
		&fileNo,
		filename,
		openFlags,
		shareFlags,
		permissionMode
	);

	if ( fileNo != -1 )
	{
		return _fdopen( fileNo, mode );
	}
	else
	{
		return NULL;
	}
}
