/*-------------------------------------------------------------------------
 *
 * bgwriter.h
 *		Routines for background writer process.
 *
 * Copyright (c) 2021-2022, Oriole DB Inc.
 *
 * IDENTIFICATION
 *	  contrib/orioledb/include/utils/bgwriter.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef __BGWRITER_H__
#define __BGWRITER_H__

extern bool IsBGWriter;

extern void register_bgwriter(void);
extern void bgwriter_main(Datum main_arg);

#endif							/* __BGWRITER_H__ */
