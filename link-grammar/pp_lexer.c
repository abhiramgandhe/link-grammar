/*************************************************************************/
/* Copyright (c) 2004                                                    */
/* Daniel Sleator, David Temperley, and John Lafferty                    */
/* All rights reserved                                                   */
/*                                                                       */
/* Use of the link grammar parsing system is subject to the terms of the */
/* license set forth in the LICENSE file included with this software,    */ 
/* and also available at http://www.link.cs.cmu.edu/link/license.html    */
/* This license allows free redistribution and use in source and binary  */
/* forms, with or without modification, subject to certain conditions.   */
/*                                                                       */
/*************************************************************************/

/* XXX the original flex source for this file is missing !! */

#include <string.h>
#include "error.h"

/* I edited this file to eliminate compiler warnings.  I've documented here
   all the changes.  The .fl file from which this is derived is in
   pp_lexer-flex-file.  Here are all the warnings I got:

     pp_lexer.c: In function `pp_lexer_lex':
     pp_lexer.c:841: warning: implicit declaration of function `yywrap'
     pp_lexer.c:689: warning: label `find_rule' defined but not used
     pp_lexer.c: At top level:
     pp_lexer.c:1590: warning: `yy_flex_realloc' defined but not used
     pp_lexer.c:1099: warning: `yyunput' defined but not used
     pp_lexer.c:1814: warning: `show_bindings' defined but not used


   Here are the changes I made.  All of them are labeled with "--DS" in
   the code.

     Got rid of #line directives.
     Added the prototype of yywrap() right below this comment.
     Commented out code and prototype declarations for the unused functions
 */

/* If YY_ALWAYS_INTERACTIVE is set, then input is read as wide-char,
 * instead of multi-byte. This perhaps fixes MS windows bugs ...
 */

#ifdef _MSC_VER
#define YY_ALWAYS_INTERACTIVE 1
#endif

int yywrap(void);  /* --DS */

#define yy_create_buffer pp_lexer__create_buffer
#define yy_delete_buffer pp_lexer__delete_buffer
#define yy_flex_debug pp_lexer__flex_debug
#define yy_init_buffer pp_lexer__init_buffer
#define yy_flush_buffer pp_lexer__flush_buffer
#define yy_load_buffer_state pp_lexer__load_buffer_state
#define yy_switch_to_buffer pp_lexer__switch_to_buffer
#define yyin pp_lexer_in
#define yyleng pp_lexer_leng
#define yylex pp_lexer_lex
#define yyout pp_lexer_out
#define yyrestart pp_lexer_restart
#define yytext pp_lexer_text
#define yylineno pp_lexer_lineno
#define yywrap pp_lexer_wrap

/* A lexical scanner generated by flex */

#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 2
#define YY_FLEX_MINOR_VERSION 5

#include <stdio.h>
#include <wchar.h>
#include <unistd.h>


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif

#include <stdlib.h>

#ifdef __TURBOC__
 #pragma warn -rch
 #pragma warn -use
 #include <io.h>
#endif


#define YY_PROTO(proto) proto

/* Returned upon end-of-file. */
#define YY_NULL 0

/* Promotes a possibly negative, possibly signed char to an unsigned
 * integer for use as an array index.  If the signed char is negative,
 * we want to instead treat it as an 8-bit unsigned char, hence the
 * double cast.
 */
#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)

/* Enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN.
 */
#define BEGIN yy_start = 1 + 2 *

/* Translate the current start state into a value that can be later handed
 * to BEGIN to return to the state.  The YYSTATE alias is for lex
 * compatibility.
 */
#define YY_START ((yy_start - 1) / 2)
#define YYSTATE YY_START

/* Action number for EOF rule of a given start state. */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* Special action meaning "start processing a new file". */
#define YY_NEW_FILE yyrestart( yyin )

#define YY_END_OF_BUFFER_CHAR 0

/* Size of default input buffer. */
#define YY_BUF_SIZE 16384

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* The funky do-while in the following #define is used to turn the definition
 * int a single C statement (which needs a semi-colon terminator).  This
 * avoids problems with code like:
 *
 * 	if ( condition_holds )
 *		yyless( 5 );
 *	else
 *		do_something_else();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the yyless() call.
 */

/* Return all but the first 'n' matched characters back to the input stream. */

#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

/* The following is because we cannot portably get our hands on size_t
 * (without autoconf's help, which isn't available because we want
 * flex-generated scanners to compile on their own).
 */
typedef unsigned int yy_size_t;


struct yy_buffer_state
	{
	FILE *yy_input_file;

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	yy_size_t yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getwc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;
#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
#define YY_BUFFER_EOF_PENDING 2
	};

static YY_BUFFER_STATE yy_current_buffer = 0;

/* We provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state".
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */


int yyleng;

/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

void yyrestart YY_PROTO(( FILE *input_file ));

void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
void yy_load_buffer_state YY_PROTO(( void ));
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));
void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));
#define YY_FLUSH_BUFFER yy_flush_buffer( yy_current_buffer )

static void *yy_flex_alloc YY_PROTO(( yy_size_t ));
/* static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t )); --DS */
static void yy_flex_free YY_PROTO(( void * ));

#define yy_new_buffer yy_create_buffer

#define yy_set_bol(at_bol) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_at_bol = at_bol; \
	}

#define YY_AT_BOL() (yy_current_buffer->yy_at_bol)


#define YY_USES_REJECT
typedef unsigned char YY_CHAR;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
typedef int yy_state_type;
extern int yylineno;
int yylineno = 1;
extern char *yytext;
#define yytext_ptr yytext

extern int yywrap YY_PROTO(( void ));

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( mbstate_t * ));
static void yy_fatal_error YY_PROTO(( const char msg[] ));

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	yytext_ptr = yy_bp; \
	yyleng = (int) (yy_cp - yy_bp); \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define YY_NUM_RULES 8
#define YY_END_OF_BUFFER 9
static const short int yy_acclist[39] =
    {   0,
        2,    2,    2,    2,    9,    5,    7,    8,    2,    7,
        8,    2,    8,    7,    8,    7,    8,    5,    7,    8,
        2,    7,    8,    5,    7,    8,    7,    8,    5,    3,
        2,    4,    5,    2,    5,    1,    3,    6
    } ;

static const short int yy_accept[29] =
    {   0,
        1,    2,    3,    4,    5,    6,    9,   12,   14,   16,
       18,   21,   24,   27,   29,   30,   31,   32,   32,   34,
       35,   35,   36,   36,   37,   38,   39,   39
    } ;

static const int yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    4,    1,    5,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    6,    7,    1,
        1,    1,    1,    8,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static const int yy_meta[9] =
    {   0,
        1,    2,    2,    3,    4,    5,    1,    1
    } ;

static const short int yy_base[32] =
    {   0,
        0,    7,   14,   21,   18,   11,    0,    0,    0,   66,
       10,   27,   34,   42,    7,   66,    0,    7,    4,    0,
        0,    0,    0,   66,    0,   66,   66,   50,   54,   57,
       60
    } ;

static const short int yy_def[32] =
    {   0,
       27,    1,    1,    3,   27,   28,   29,   29,   30,   27,
       31,   27,   27,   13,   28,   27,   29,   30,   31,   12,
       14,   13,   14,   27,   14,   27,    0,   27,   27,   27,
       27
    } ;

static const short int yy_nxt[75] =
    {   0,
        6,    7,    8,    7,    9,   10,    6,   11,   12,   16,
       12,   26,   16,   13,   10,   16,   16,   27,   10,   27,
       10,   10,   12,   27,   12,   27,   27,   14,   20,   17,
       20,   27,   27,   21,   22,   23,   24,   23,   23,   25,
       22,   22,   23,   27,   27,   27,   27,   23,   23,   23,
       15,   27,   27,   27,   15,   17,   17,   18,   27,   18,
       19,   27,   27,   27,   19,    5,   27,   27,   27,   27,
       27,   27,   27,   27
    } ;

static const short int yy_chk[75] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,   19,
        2,   18,   15,    2,    3,   11,    6,    5,    3,    0,
        3,    3,    4,    0,    4,    0,    0,    4,   12,   12,
       12,    0,    0,   12,   13,   13,   13,   13,   13,   13,
       13,   13,   14,    0,    0,    0,    0,   14,   14,   14,
       28,    0,    0,    0,   28,   29,   29,   30,    0,   30,
       31,    0,    0,    0,   31,   27,   27,   27,   27,   27,
       27,   27,   27,   27
    } ;

static yy_state_type yy_state_buf[YY_BUF_SIZE + 2], *yy_state_ptr;
static char *yy_full_match;
static int yy_lp;
#define REJECT \
{ \
*yy_cp = yy_hold_char; /* undo effects of setting up yytext */ \
yy_cp = yy_full_match; /* restore poss. backed-over text */ \
++yy_lp; \
goto find_rule; \
}
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
char *yytext;
#define INITIAL 0
/**************************************************************************
    Lex specification for post-process knowledge file 
    6/96 ALB
    Updated 8/97 to allow multiple instances
    Compile with either  
      1) flex pp_lexer.fl (on systems which support %option prefix) OR
      2) flex pp_lexer.fl
         mv lex.yy.c pp_lexer.tmp.c
         cat pp_lexer.tmp.c | sed "s/yy/pp_lexer_/g" > pp_lexer.c
         rm -f pp_lexer.tmp.c
             (on systems which do not)

 In the case of (1), uncomment the three %option lines below. 
**************************************************************************/

#include <stdarg.h>
#include "api.h"

#undef yywrap

/* forward references for non-exported functions (and static variable) */
static void check_string(const char *str);
static void setup(PPLexTable *lt);
static void set_label(PPLexTable *lt, const char *label);
static void add_string_to_label(PPLexTable *lt, const char *str);
static void add_set_of_strings_to_label(PPLexTable *lt,const char *label_of_set);
static int  get_index_of_label(PPLexTable *lt, const char *label);
static PPLexTable *clt=NULL; /* ptr to lex table we're currently filling in */
/* see above */
#define INCLUDE 1

/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */
#include <stdlib.h>

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* Copy whatever the last rule matched to the standard output. */

#ifndef ECHO
/* This used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite().
 */
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size,pmbss) \
	if ( yy_current_buffer->yy_is_interactive ) \
		{ \
		wint_t c = '*'; \
		int n; \
		for ( n = 0; n < max_size && \
			     (c = fgetwc( yyin )) != WEOF && c != '\n'; ) \
			n += wcrtomb(&buf[n], c, pmbss); \
		if ( c == '\n' ) \
			buf[n++] = '\n'; \
		if ( c == WEOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
		  && ferror( yyin ) ) \
		YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/* No semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

/* Number of entries by which start-condition stack grows. */
#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif

/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
 */
#ifndef YY_DECL
#define YY_DECL int yylex YY_PROTO(( void ))
#endif

/* Code executed at the beginning of each rule, after yytext and yyleng
 * have been set up.
 */
#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

/* Code executed at the end of each rule. */
#ifndef YY_BREAK
#define YY_BREAK break;
#endif

#define YY_RULE_SETUP \
	if ( yyleng > 0 ) \
		yy_current_buffer->yy_at_bol = \
				(yytext[yyleng - 1] == '\n'); \
	YY_USER_ACTION

YY_DECL;
YY_DECL
{
	yy_state_type yy_current_state;
	char *yy_cp, *yy_bp;
	int yy_act;

	/* Reset multi-byte shift state */
	mbstate_t mbss;
	memset(&mbss, 0, sizeof(mbss));

	/* #line 56 "pp_lexer.fl" --DS */

	if ( yy_init )
		{
		yy_init = 0;

#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! yy_start )
			yy_start = 1;	/* first start state */

		if ( ! yyin )
			yyin = stdin;

		if ( ! yyout )
			yyout = stdout;

		if ( ! yy_current_buffer )
			yy_current_buffer =
				yy_create_buffer( yyin, YY_BUF_SIZE );

		yy_load_buffer_state();
		}

	while ( 1 )		/* loops until end-of-file is reached */
		{
		yy_cp = yy_c_buf_p;

		/* Support of yytext. */
		*yy_cp = yy_hold_char;

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

		yy_current_state = yy_start;
		yy_current_state += YY_AT_BOL();
		yy_state_ptr = yy_state_buf;
		*yy_state_ptr++ = yy_current_state;
yy_match:
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 28 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			*yy_state_ptr++ = yy_current_state;
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 66 );

yy_find_action:
		yy_current_state = *--yy_state_ptr;
		yy_lp = yy_accept[yy_current_state];
/* find_rule: --DS */ /* we branch to this label when backing up */
		for ( ; ; ) /* until we find what rule we matched */
			{
			if ( yy_lp && yy_lp < yy_accept[yy_current_state + 1] )
				{
				yy_act = yy_acclist[yy_lp];
					{
					yy_full_match = yy_cp;
					break;
					}
				}
			--yy_cp;
			yy_current_state = *--yy_state_ptr;
			yy_lp = yy_accept[yy_current_state];
			}

		YY_DO_BEFORE_ACTION;

		if ( yy_act != YY_END_OF_BUFFER )
			{
			int yyl;
			for ( yyl = 0; yyl < yyleng; ++yyl )
				if ( yytext[yyl] == '\n' )
					++yylineno;
			}

do_action:	/* This label is used only to access EOF actions. */


		switch ( yy_act )
	{ /* beginning of action switch */
case 1:
*yy_cp = yy_hold_char; /* undo effects of setting up yytext */
yy_cp -= 1;
YY_DO_BEFORE_ACTION; /* set up yytext again */
YY_RULE_SETUP
    /* #line 58 "pp_lexer.fl" --DS */
; 
	YY_BREAK
case 2:
YY_RULE_SETUP
	    /* #line 59 "pp_lexer.fl" --DS */
; 
	YY_BREAK
case 3:
YY_RULE_SETUP
	    /* #line 61 "pp_lexer.fl" --DS */
{ set_label(clt, yytext); }
	YY_BREAK
case 4:
YY_RULE_SETUP
	    /* #line 62 "pp_lexer.fl" --DS */
{ add_set_of_strings_to_label(clt, &(yytext[1])); }
	YY_BREAK
case 5:
YY_RULE_SETUP
	/* #line 63 "pp_lexer.fl" --DS */
{ add_string_to_label(clt, yytext); }
	YY_BREAK
case 6:
YY_RULE_SETUP
	/* #line 64 "pp_lexer.fl" --DS */
{ add_string_to_label(clt, yytext); }
	YY_BREAK
case 7:
YY_RULE_SETUP
	/* #line 66 "pp_lexer.fl" --DS */
{ prt_error("Fatal Error: pp_lexer: unable to parse knowledge file (line %i).\n",yylineno); exit(1); }
	YY_BREAK
case 8:
YY_RULE_SETUP
	/* #line 68 "pp_lexer.fl" --DS */
ECHO;
	YY_BREAK
	/* #line 754 "pp_lexer.c" --DS */
			case YY_STATE_EOF(INITIAL):
			case YY_STATE_EOF(INCLUDE):
				yyterminate();

	case YY_END_OF_BUFFER:
		{
		/* Amount of text matched not including the EOB char. */
		int yy_amount_of_matched_text = (int) (yy_cp - yytext_ptr) - 1;

		/* Undo the effects of YY_DO_BEFORE_ACTION. */
		*yy_cp = yy_hold_char;

		if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_NEW )
			{
			/* We're scanning a new file or input source.  It's
			 * possible that this happened because the user
			 * just pointed yyin at a new source and called
			 * yylex().  If so, then we have to assure
			 * consistency between yy_current_buffer and our
			 * globals.  Here is the right place to do so, because
			 * this is the first action (other than possibly a
			 * back-up) that will match for the new input source.
			 */
			yy_n_chars = yy_current_buffer->yy_n_chars;
			yy_current_buffer->yy_input_file = yyin;
			yy_current_buffer->yy_buffer_status = YY_BUFFER_NORMAL;
			}

		/* Note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the
		 * end-of-buffer state).  Contrast this with the test
		 * in input().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			{ /* This was really a NUL. */
			yy_state_type yy_next_state;

			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			/* Okay, we're now positioned to make the NUL
			 * transition.  We couldn't have
			 * yy_get_previous_state() go ahead and do it
			 * for us because it doesn't know how to deal
			 * with the possibility of jamming (and we don't
			 * want to build jamming into it because then it
			 * will run more slowly).
			 */

			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = yytext_ptr + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				/* Consume the NUL. */
				yy_cp = ++yy_c_buf_p;
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
				yy_cp = yy_c_buf_p;
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer(&mbss) )
			{
			case EOB_ACT_END_OF_FILE:
				{
				yy_did_buffer_switch_on_eof = 0;

				if ( yywrap() )
					{
					/* Note: because we've taken care in
					 * yy_get_next_buffer() to have set up
					 * yytext, we can now set up
					 * yy_c_buf_p so that if some total
					 * hoser (like flex itself) wants to
					 * call the scanner after we return the
					 * YY_NULL, it'll still work - another
					 * YY_NULL will get returned.
					 */
					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				yy_c_buf_p =
					yytext_ptr + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				yy_c_buf_p =
				&yy_current_buffer->yy_ch_buf[yy_n_chars];

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of yylex */


/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer(mbstate_t *pmbss)
{
	char *dest = yy_current_buffer->yy_ch_buf;
	char *source = yytext_ptr;
	int number_to_move, i;
	int ret_val;

	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( yy_current_buffer->yy_fill_buffer == 0 )
		{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )
			{
			/* We matched a singled characater, the EOB, so
			 * treat this as a final EOF.
			 */
			return EOB_ACT_END_OF_FILE;
			}

		else
			{
			/* We matched some text prior to the EOB, first
			 * process it.
			 */
			return EOB_ACT_LAST_MATCH;
			}
		}

	/* Try to read more data. */

	/* First move last chars to start of buffer. */
	number_to_move = (int) (yy_c_buf_p - yytext_ptr) - 1;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )
		/* don't do the read, it's not guaranteed to return an EOF,
		 * just force an EOF
		 */
		yy_n_chars = 0;

	else
		{
		int num_to_read =
			yy_current_buffer->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ /* Not enough room in the buffer - grow it. */
#ifdef YY_USES_REJECT
			YY_FATAL_ERROR(
"input buffer overflow, can't enlarge buffer because scanner uses REJECT" );
#else

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;

			int yy_c_buf_p_offset =
				(int) (yy_c_buf_p - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				int new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yy_flex_realloc( (void *) b->yy_ch_buf,
							 b->yy_buf_size + 2 );
				}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = yy_current_buffer->yy_buf_size -
						number_to_move - 1;
#endif
			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		/* Read in more data. */
		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
			yy_n_chars, num_to_read, pmbss );
		}

	if ( yy_n_chars == 0 )
		{
		if ( number_to_move == YY_MORE_ADJ )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart( yyin );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			yy_current_buffer->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	yy_n_chars += number_to_move;
	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

	yytext_ptr = &yy_current_buffer->yy_ch_buf[0];

	return ret_val;
	}


/* yy_get_previous_state - get the state just before the EOB char was reached */

static yy_state_type yy_get_previous_state(void)
{
	register yy_state_type yy_current_state;
	register char *yy_cp;

	yy_current_state = yy_start;
	yy_current_state += YY_AT_BOL();
	yy_state_ptr = yy_state_buf;
	*yy_state_ptr++ = yy_current_state;

	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
		{
		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 28 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		*yy_state_ptr++ = yy_current_state;
		}

	return yy_current_state;
	}


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *	next_state = yy_try_NUL_trans( current_state );
 */

static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )
	{
	register int yy_is_jam;

	register YY_CHAR yy_c = 1;
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 28 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	*yy_state_ptr++ = yy_current_state;
	yy_is_jam = (yy_current_state == 27);

	return yy_is_jam ? 0 : yy_current_state;
	}


void yyrestart( FILE *input_file )
	{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
	}


void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
	{
	if ( yy_current_buffer == new_buffer )
		return;

	if ( yy_current_buffer )
		{
		/* Flush out information for old buffer. */
		*yy_c_buf_p = yy_hold_char;
		yy_current_buffer->yy_buf_pos = yy_c_buf_p;
		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	yy_current_buffer = new_buffer;
	yy_load_buffer_state();

	/* We don't actually know whether we did this switch during
	 * EOF (yywrap()) processing, but the only time this flag
	 * is looked at is after yywrap() is called, so it's safe
	 * to go ahead and always set it.
	 */
	yy_did_buffer_switch_on_eof = 1;
	}


void yy_load_buffer_state( void )
	{
	yy_n_chars = yy_current_buffer->yy_n_chars;
	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
	yyin = yy_current_buffer->yy_input_file;
	yy_hold_char = *yy_c_buf_p;
	}


YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
	{
	YY_BUFFER_STATE b;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = size;

	/* yy_ch_buf has to be 2 characters longer than the size given because
	 * we need to put in 2 end-of-buffer characters.
	 */
	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_is_our_buffer = 1;

	yy_init_buffer( b, file );

	return b;
	}


void yy_delete_buffer( YY_BUFFER_STATE b )
	{
	if ( b == NULL ) return;

	if ( b == yy_current_buffer )
		yy_current_buffer = (YY_BUFFER_STATE) 0;

	if ( b->yy_is_our_buffer )
		yy_flex_free( (void *) b->yy_ch_buf );

	yy_flex_free( (void *) b );
	}


void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
	{
	yy_flush_buffer( b );

	b->yy_input_file = file;
	b->yy_fill_buffer = 1;

	b->yy_is_interactive = 0;
#if YY_ALWAYS_INTERACTIVE
	b->yy_is_interactive = 1;
#endif
	}


void yy_flush_buffer( YY_BUFFER_STATE b )
	{
	b->yy_n_chars = 0;

	/* We always need two end-of-buffer characters.  The first causes
	 * a transition to the end-of-buffer state.  The second causes
	 * a jam in that state.
	 */
	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[0];

	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;

	if ( b == yy_current_buffer )
		yy_load_buffer_state();
	}


#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

static void yy_fatal_error( const char msg[] )
	{
	(void) fprintf( stderr, "%s\n", msg );
	exit( YY_EXIT_FAILURE );
	}



/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		yytext[yyleng] = yy_hold_char; \
		yy_c_buf_p = yytext + n - YY_MORE_ADJ; \
		yy_hold_char = *yy_c_buf_p; \
		*yy_c_buf_p = '\0'; \
		yyleng = n; \
		} \
	while ( 0 )


/* Internal utility routines. */

static void *yy_flex_alloc( yy_size_t size )
	{
	return (void *) malloc( size );
	}


static void yy_flex_free( void *ptr )
	{
	free( ptr );
	}

/************************ exported functions ******************************/

PPLexTable *pp_lexer_open(FILE *f)
{
  PPLexTable *lt;
  if (f == NULL)
  {
    prt_error("Fatal Error: pp_lexer_open: passed a NULL file pointer");
    exit(1);
  }
  yyin = f;            /* redirect lex to look at the specified file */
  lt = (PPLexTable*) xalloc (sizeof(PPLexTable));
  setup(lt);
  clt = lt;    /* set lt to be the current table, which yylex will fill in */
  yylex();  
  clt = NULL; 
  lt->idx_of_active_label=-1;
  return lt;
}

void pp_lexer_close(PPLexTable *lt)
{
  int i;
  pp_label_node *node,*next;
  for (i=0; i<PP_LEXER_MAX_LABELS; i++)
    {
      /* free the linked list */
      node = lt->nodes_of_label[i];
      while (node)
        {
          next = node->next;
          xfree(node, sizeof(pp_label_node));
          node=next;
        }
    }
  string_set_delete(lt->string_set);
  xfree(lt, sizeof(PPLexTable));
  yy_delete_buffer(yy_current_buffer);
}

int pp_lexer_set_label(PPLexTable *lt, const char *label) 
{
  /* set lexer state to first node of this label */
  lt->idx_of_active_label = get_index_of_label(lt, label);
  if (lt->idx_of_active_label==-1) return 0;    /* label not found */
  lt->current_node_of_active_label=lt->nodes_of_label[lt->idx_of_active_label];
  return 1;
}

int pp_lexer_count_tokens_of_label(PPLexTable *lt) 
{
  /* counts all tokens, even the commas */
  int n;
  pp_label_node *p;
  if (lt->idx_of_active_label==-1) 
  {
	 prt_error("Fatal Error: pp_lexer: current label is invalid");
    exit(1);
  }
  for (n=0, p=lt->nodes_of_label[lt->idx_of_active_label]; p;p=p->next, n++){}
  return n;
}


const char *pp_lexer_get_next_token_of_label(PPLexTable *lt) 
{
  /* retrieves next token of set label, or NULL if list exhausted */
  static const char *p;
  if (lt->current_node_of_active_label==NULL) return NULL;
  p = lt->current_node_of_active_label->str;
  lt->current_node_of_active_label=lt->current_node_of_active_label->next;
  return p;
}

int pp_lexer_count_commas_of_label(PPLexTable *lt) 
{
  int n;
  pp_label_node *p;
  if (lt->idx_of_active_label==-1)
  {
    prt_error("Fatal Error: pp_lexer: current label is invalid");
    exit(1);
  }
  for (n=0,p=lt->nodes_of_label[lt->idx_of_active_label];p!=NULL;p=p->next)
    if (!strcmp(p->str, ",")) n++;
  return n;
}

const char **pp_lexer_get_next_group_of_tokens_of_label(PPLexTable *lt, int *n_tokens)
{ 
  /* all tokens until next comma, null-terminated */
  int n;
  pp_label_node *p;
  static const char **tokens = NULL;  
  static int extents=0;

  p=lt->current_node_of_active_label;	   
  for (n=0; p!=NULL && strcmp(p->str,","); n++, p=p->next) {}
  if (n>extents) {
     extents = n;
     free (tokens);
     tokens = (const char **) malloc (extents * sizeof(const char*));
  }   

  p = lt->current_node_of_active_label;	   
  for (n=0; p!=NULL && strcmp(p->str,","); n++, p=p->next)
       tokens[n] = string_set_add(p->str, lt->string_set);
  
  /* advance "current node of label" state */
  lt->current_node_of_active_label = p;
  if (p!=NULL) lt->current_node_of_active_label = p->next;
  
  *n_tokens = n;
  return tokens;
}


int yywrap(void)
{
  /* must return 1 for end of input, 0 otherwise */
  return 1;
}

/********************** non-exported functions ************************/

static void setup(PPLexTable *lt) 
{
  int i;
  for (i=0; i<PP_LEXER_MAX_LABELS; i++)
    {
      lt->nodes_of_label[i]     = NULL;
      lt->last_node_of_label[i] = NULL;
      lt->labels[i]=NULL;
    }
  lt->string_set = string_set_create();
}

static void set_label(PPLexTable *lt, const char *label) 
{
  int i;
  char *c;
  char *label_sans_colon;

  /* check for and then slice off the trailing colon */
  label_sans_colon = strdup(label);
  c=&(label_sans_colon[strlen(label_sans_colon)-1]);
  if (*c != ':')
  {
    prt_error("Fatal Error: Label %s must end with :", label);
    exit(1);
  }
  *c = 0;

  /* have we seen this label already? If so, abort */
  for (i=0;lt->labels[i]!=NULL && strcmp(lt->labels[i],label_sans_colon);i++) {}
  if (lt->labels[i]!=NULL) 
  {
    prt_error("Fatal Error: pp_lexer: label %s multiply defined!", label_sans_colon);
    exit(1);
  }

  /* new label. Store it */
  if (i == PP_LEXER_MAX_LABELS-1) 
  {
    prt_error("Fatal Error: pp_lexer: too many labels. Raise PP_LEXER_MAX_LABELS");
    exit(1);
  }
  lt->labels[i] = string_set_add(label_sans_colon, lt->string_set);
  lt->idx_of_active_label = i;

  free(label_sans_colon);
}


static void add_string_to_label(PPLexTable *lt, const char *str) 
{
  /* add the single string str to the set of strings associated with label */
  pp_label_node *new_node;

  if (lt->idx_of_active_label == -1)
  {
    prt_error("Fatal Error: pp_lexer: invalid syntax (line %i)",yylineno);
    exit(1);
  }

  /* make sure string is legal */
  check_string(str);

  /* create a new node in (as yet to be determined) linked list of strings */
  new_node = (pp_label_node *) xalloc (sizeof(pp_label_node));
  new_node->str = string_set_add(str, lt->string_set);
  new_node->next = NULL;
  
  /* stick newly-created node at the *end* of the appropriate linked list */
  if (lt->last_node_of_label[lt->idx_of_active_label]==NULL)
    {
      /* first entry on linked list */
      lt->nodes_of_label[lt->idx_of_active_label]     = new_node;      
      lt->last_node_of_label[lt->idx_of_active_label] = new_node;
    }
  else
    {
      /* non-first entry on linked list */
      lt->last_node_of_label[lt->idx_of_active_label]->next = new_node;
      lt->last_node_of_label[lt->idx_of_active_label]       = new_node;
    }
}

static void add_set_of_strings_to_label(PPLexTable *lt,const char *label_of_set) 
{
  /* add the set of strings, defined earlier by label_of_set, to the set of 
     strings associated with the current label */
  pp_label_node *p;
  int idx_of_label_of_set;
  if (lt->idx_of_active_label==-1)
  {
    prt_error("Fatal Error: pp_lexer: invalid syntax (line %i)",yylineno);
    exit(1);
  }
  if ((idx_of_label_of_set = get_index_of_label(lt, label_of_set))==-1)
  {
    prt_error("Fatal Error: pp_lexer: label %s must be defined before it's referred to (line %i)"
	  ,label_of_set, yylineno);
    exit(1);
  }
  for (p=lt->nodes_of_label[idx_of_label_of_set]; p!=NULL; p=p->next)
    add_string_to_label(lt, p->str);
}

static int get_index_of_label(PPLexTable *lt, const char *label)
{
  int i;
  for (i=0; lt->labels[i]!=NULL; i++) 
    if (!strcmp(lt->labels[i], label)) return i;
  return -1;
}
    
static void check_string(const char *str)
{
  if (strlen(str)>1 && strchr(str, ',')!=NULL)
  {
    prt_error("Fatal Error: pp_lexer: string %s contains a comma, which is a no-no.",str);
    exit(1);
  }
}


