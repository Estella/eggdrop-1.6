/*
 * transfer.h
 */
/*
 * This file is part of the eggdrop source code.
 *
 * Copyright (C) 1999  Eggheads
 * Copyright (C) 1997  Robey Pointer
 *
 * Distributed according to the GNU General Public License. For full
 * details, read the top of 'main.c' or the file called COPYING that
 * was distributed with this code.
 */

#define DCCSEND_OK     0
#define DCCSEND_FULL   1	/* DCC table is full			*/
#define DCCSEND_NOSOCK 2	/* Can not open a listening socket	*/
#define DCCSEND_BADFN  3	/* No such file				*/

#ifndef MAKING_TRANSFER
/* 4 - 7 */
#define DCC_FORK_SEND (*(struct dcc_table *)(transfer_funcs[4]))
#define at_limit(a) (((int (*) (char *))transfer_funcs[5])(a))
#define copy_to_tmp (*(int *)(transfer_funcs[6]))
#define fileq_cancel(a,b) (((void (*) (int,char *))transfer_funcs[7])(a,b))
/* 8 - 11 */
#define queue_file(a,b,c,d) (((void (*)(char *,char *,char *,char *))transfer_funcs[8])(a,b,c,d))
#define raw_dcc_send(a,b,c,d) (((int (*) (char *,char *,char *,char *))transfer_funcs[9])(a,b,c,d))
#define show_queued_files(a) (((void (*) (int))transfer_funcs[10])(a))
#define wild_match_file(a,b) (((int (*)(register unsigned char * m, register unsigned char * n))transfer_funcs[11])(a,b))
/* 12 - 15 */
#define wipe_tmp_filename(a,b) (((void (*) (char *,int))transfer_funcs[12])(a,b))
#define DCC_GET (*(struct dcc_table *)(transfer_funcs[13]))
#define H_rcvd (*(p_tcl_bind_list*)(transfer_funcs[14]))
#define H_sent (*(p_tcl_bind_list*)(transfer_funcs[15]))
/* 16 - 19 */
#define USERENTRY_FSTAT (*(struct user_entry_type *)(transfer_funcs[16]))
#define quiet_reject (*(int *)(transfer_funcs[17]))
#define raw_dcc_resend(a,b,c,d) (((int (*) (char *,char *,char *,char *))transfer_funcs[18])(a,b,c,d))

#else	/* MAKING_TRANSFER */

static int raw_dcc_resend(char *, char *, char *, char *);
static int raw_dcc_send(char *, char *, char *, char *);

#define TRANSFER_REGET_PACKETID 0xfeab

typedef struct {
  u_16bit_t packet_id;		/* Identification ID, should be equal
	 			   to TRANSFER_REGET_PACKETID		*/
  u_8bit_t  byte_order;		/* Byte ordering, see byte_order_test()	*/
  u_32bit_t byte_offset;	/* Number of bytes to skip relative to
				   the file beginning			*/
} transfer_reget;

typedef struct zarrf {
  char *dir;			/* Absolute dir if it starts with '*',
				   otherwise dcc dir.			*/
  char *file;
  char nick[NICKLEN];		/* Who queued this file			*/
  char to[NICKLEN];		/* Who will it be sent to		*/
  struct zarrf *next;
} fileq_t;

#endif	/* MAKING_TRANSFER */
