#ifndef __FILEGEN_H__
#define __FILEGEN_H__

#include <stdio.h>

/*
 * Copyright 1993-2002 Christopher Seiwald and Perforce Software, Inc.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * filegen.h - generic file routines 
 *
 */

FILE*
file_open( char const * const filename, char const * const mode );

#endif
