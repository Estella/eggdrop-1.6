/*
 * compress.h -- part of src/mod/compress.mod
 *   header file for the zlib compression module
 *
 * $Id: compress.h,v 1.1 2000/03/01 17:54:37 fabian Exp $
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

#ifndef _EGG_MOD_COMPRESS_COMPRESS_H
#define _EGG_MOD_COMPRESS_COMPRESS_H

typedef enum {
  COMPF_ERROR,		/* Compression failed.			*/
  COMPF_SUCCESS		/* Compression succeeded.		*/
} compf_result;


#ifndef MAKING_COMPRESS
/* 4 - 7 */
# define compress_to_file   ((int (char *, char *, char *))(compress_funcs[4]))
# define compress_file	    ((int (char *, char *))(compress_funcs[5]))
# define uncompress_to_file ((int (char *, char *))(uncompress_funcs[6]))
# define uncompress_file    ((int (char *))(uncompress_funcs[7]))
/* 8 - 11 */
# define compress_userfile   ((int (char *))(compress_funcs[8]))
# define uncompress_userfile ((int (char *))(uncompress_funcs[9]))
#endif /* !MAKING_COMPRESS */

#endif /* !_EGG_MOD_COMPRESS_COMPRESS_H */
