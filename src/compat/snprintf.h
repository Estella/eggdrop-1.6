/*
 * snprintf.h
 *   header file for snprintf.c
 *
 * $Id: snprintf.h,v 1.1 2000/03/22 00:42:57 fabian Exp $
 */
/* 
 * Copyright (C) 2000  Eggheads
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _COMPAT_SNPRINTF_H_
#define _COMPAT_SNPRINTF_H_

#include "src/main.h"
#include <stdio.h>

/* Use the system libraries version of vsnprintf() if available. Otherwise
 * use our own.
 */
#ifndef HAVE_VSNPRINTF
int egg_vsnprintf(char *str, size_t str_m, const char *fmt, va_list ap);
#else
#  define egg_vsnprintf	vsnprintf
#endif

/* Use the system libraries version of snprintf() if available. Otherwise
 * use our own.
 */
#ifndef HAVE_SNPRINTF
/* int egg_snprintf(char *str, size_t str_m, const char *fmt, ...); */
int egg_snprintf EGG_VARARGS(char *, str);
#else
#  define egg_snprintf	snprintf
#endif

#endif
