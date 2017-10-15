/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mon_parse.y" /* yacc.c:339  */

/* -*- C -*-
 *
 * mon_parse.y - Parser for the VICE built-in monitor.
 *
 * Written by
 *  Daniel Sladic <sladic@eecg.toronto.edu>
 *  Andreas Boose <viceteam@t-online.de>
 *  Thomas Giesel <skoe@directbox.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#ifndef MINIXVMD
#ifdef __GNUC__
#undef alloca
#define        alloca(n)       __builtin_alloca (n)
#else
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#else  /* Not HAVE_ALLOCA_H.  */
#if !defined(_AIX) && !defined(WINCE)
#ifndef _MSC_VER
extern char *alloca();
#else
#define alloca(n)   _alloca(n)
#endif  /* MSVC */
#endif /* Not AIX and not WINCE.  */
#endif /* HAVE_ALLOCA_H.  */
#endif /* GCC.  */
#endif /* MINIXVMD */

/* SunOS 4.x specific stuff */
#if defined(sun) || defined(__sun)
#  if !defined(__SVR4) && !defined(__svr4__)
#    ifdef __sparc__
#      define YYFREE
#    endif
#  endif
#endif

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "asm.h"
#include "console.h"
#include "lib.h"
#include "machine.h"
#include "mon_breakpoint.h"
#include "mon_command.h"
#include "mon_disassemble.h"
#include "mon_drive.h"
#include "mon_file.h"
#include "mon_memory.h"
#include "mon_util.h"
#include "montypes.h"
#include "resources.h"
#include "types.h"
#include "uimon.h"


#define join_ints(x,y) (LO16_TO_HI16(x)|y)
#define separate_int1(x) (HI16_TO_LO16(x))
#define separate_int2(x) (LO16(x))

static int yyerror(char *s);
static int temp;
static int resolve_datatype(unsigned guess_type, const char *num);
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num);

#ifdef __IBMC__
static void __yy_memcpy (char *to, char *from, int count);
#endif

/* Defined in the lexer */
extern int new_cmd, opt_asm;
extern void free_buffer(void);
extern void make_buffer(char *str);
extern int yylex(void);
extern int cur_len, last_len;

#define ERR_ILLEGAL_INPUT 1     /* Generic error as returned by yacc.  */
#define ERR_RANGE_BAD_START 2
#define ERR_RANGE_BAD_END 3
#define ERR_BAD_CMD 4
#define ERR_EXPECT_CHECKNUM 5
#define ERR_EXPECT_END_CMD 6
#define ERR_MISSING_CLOSE_PAREN 7
#define ERR_INCOMPLETE_COMPARE_OP 8
#define ERR_EXPECT_FILENAME 9
#define ERR_ADDR_TOO_BIG 10
#define ERR_IMM_TOO_BIG 11
#define ERR_EXPECT_STRING 12
#define ERR_UNDEFINED_LABEL 13
#define ERR_EXPECT_DEVICE_NUM 14
#define ERR_EXPECT_ADDRESS 15

#define BAD_ADDR (new_addr(e_invalid_space, 0))
#define CHECK_ADDR(x) ((x) == addr_mask(x))

#define YYDEBUG 1


#line 192 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    H_NUMBER = 258,
    D_NUMBER = 259,
    O_NUMBER = 260,
    B_NUMBER = 261,
    CONVERT_OP = 262,
    B_DATA = 263,
    H_RANGE_GUESS = 264,
    D_NUMBER_GUESS = 265,
    O_NUMBER_GUESS = 266,
    B_NUMBER_GUESS = 267,
    BAD_CMD = 268,
    MEM_OP = 269,
    IF = 270,
    MEM_COMP = 271,
    MEM_DISK8 = 272,
    MEM_DISK9 = 273,
    MEM_DISK10 = 274,
    MEM_DISK11 = 275,
    EQUALS = 276,
    TRAIL = 277,
    CMD_SEP = 278,
    LABEL_ASGN_COMMENT = 279,
    CMD_SIDEFX = 280,
    CMD_RETURN = 281,
    CMD_BLOCK_READ = 282,
    CMD_BLOCK_WRITE = 283,
    CMD_UP = 284,
    CMD_DOWN = 285,
    CMD_LOAD = 286,
    CMD_SAVE = 287,
    CMD_VERIFY = 288,
    CMD_IGNORE = 289,
    CMD_HUNT = 290,
    CMD_FILL = 291,
    CMD_MOVE = 292,
    CMD_GOTO = 293,
    CMD_REGISTERS = 294,
    CMD_READSPACE = 295,
    CMD_WRITESPACE = 296,
    CMD_RADIX = 297,
    CMD_MEM_DISPLAY = 298,
    CMD_BREAK = 299,
    CMD_TRACE = 300,
    CMD_IO = 301,
    CMD_BRMON = 302,
    CMD_COMPARE = 303,
    CMD_DUMP = 304,
    CMD_UNDUMP = 305,
    CMD_EXIT = 306,
    CMD_DELETE = 307,
    CMD_CONDITION = 308,
    CMD_COMMAND = 309,
    CMD_ASSEMBLE = 310,
    CMD_DISASSEMBLE = 311,
    CMD_NEXT = 312,
    CMD_STEP = 313,
    CMD_PRINT = 314,
    CMD_DEVICE = 315,
    CMD_HELP = 316,
    CMD_WATCH = 317,
    CMD_DISK = 318,
    CMD_SYSTEM = 319,
    CMD_QUIT = 320,
    CMD_CHDIR = 321,
    CMD_BANK = 322,
    CMD_LOAD_LABELS = 323,
    CMD_SAVE_LABELS = 324,
    CMD_ADD_LABEL = 325,
    CMD_DEL_LABEL = 326,
    CMD_SHOW_LABELS = 327,
    CMD_RECORD = 328,
    CMD_MON_STOP = 329,
    CMD_PLAYBACK = 330,
    CMD_CHAR_DISPLAY = 331,
    CMD_SPRITE_DISPLAY = 332,
    CMD_TEXT_DISPLAY = 333,
    CMD_SCREENCODE_DISPLAY = 334,
    CMD_ENTER_DATA = 335,
    CMD_ENTER_BIN_DATA = 336,
    CMD_KEYBUF = 337,
    CMD_BLOAD = 338,
    CMD_BSAVE = 339,
    CMD_SCREEN = 340,
    CMD_UNTIL = 341,
    CMD_CPU = 342,
    CMD_YYDEBUG = 343,
    CMD_BACKTRACE = 344,
    CMD_SCREENSHOT = 345,
    CMD_PWD = 346,
    CMD_DIR = 347,
    CMD_RESOURCE_GET = 348,
    CMD_RESOURCE_SET = 349,
    CMD_LOAD_RESOURCES = 350,
    CMD_SAVE_RESOURCES = 351,
    CMD_ATTACH = 352,
    CMD_DETACH = 353,
    CMD_MON_RESET = 354,
    CMD_TAPECTRL = 355,
    CMD_CARTFREEZE = 356,
    CMD_CPUHISTORY = 357,
    CMD_MEMMAPZAP = 358,
    CMD_MEMMAPSHOW = 359,
    CMD_MEMMAPSAVE = 360,
    CMD_COMMENT = 361,
    CMD_LIST = 362,
    CMD_STOPWATCH = 363,
    RESET = 364,
    CMD_EXPORT = 365,
    CMD_AUTOSTART = 366,
    CMD_AUTOLOAD = 367,
    CMD_LABEL_ASGN = 368,
    L_PAREN = 369,
    R_PAREN = 370,
    ARG_IMMEDIATE = 371,
    REG_A = 372,
    REG_X = 373,
    REG_Y = 374,
    COMMA = 375,
    INST_SEP = 376,
    L_BRACKET = 377,
    R_BRACKET = 378,
    LESS_THAN = 379,
    REG_U = 380,
    REG_S = 381,
    REG_PC = 382,
    REG_PCR = 383,
    REG_B = 384,
    REG_C = 385,
    REG_D = 386,
    REG_E = 387,
    REG_H = 388,
    REG_L = 389,
    REG_AF = 390,
    REG_BC = 391,
    REG_DE = 392,
    REG_HL = 393,
    REG_IX = 394,
    REG_IY = 395,
    REG_SP = 396,
    REG_IXH = 397,
    REG_IXL = 398,
    REG_IYH = 399,
    REG_IYL = 400,
    PLUS = 401,
    MINUS = 402,
    STRING = 403,
    FILENAME = 404,
    R_O_L = 405,
    OPCODE = 406,
    LABEL = 407,
    BANKNAME = 408,
    CPUTYPE = 409,
    MON_REGISTER = 410,
    COMPARE_OP = 411,
    RADIX_TYPE = 412,
    INPUT_SPEC = 413,
    CMD_CHECKPT_ON = 414,
    CMD_CHECKPT_OFF = 415,
    TOGGLE = 416,
    MASK = 417
  };
#endif
/* Tokens.  */
#define H_NUMBER 258
#define D_NUMBER 259
#define O_NUMBER 260
#define B_NUMBER 261
#define CONVERT_OP 262
#define B_DATA 263
#define H_RANGE_GUESS 264
#define D_NUMBER_GUESS 265
#define O_NUMBER_GUESS 266
#define B_NUMBER_GUESS 267
#define BAD_CMD 268
#define MEM_OP 269
#define IF 270
#define MEM_COMP 271
#define MEM_DISK8 272
#define MEM_DISK9 273
#define MEM_DISK10 274
#define MEM_DISK11 275
#define EQUALS 276
#define TRAIL 277
#define CMD_SEP 278
#define LABEL_ASGN_COMMENT 279
#define CMD_SIDEFX 280
#define CMD_RETURN 281
#define CMD_BLOCK_READ 282
#define CMD_BLOCK_WRITE 283
#define CMD_UP 284
#define CMD_DOWN 285
#define CMD_LOAD 286
#define CMD_SAVE 287
#define CMD_VERIFY 288
#define CMD_IGNORE 289
#define CMD_HUNT 290
#define CMD_FILL 291
#define CMD_MOVE 292
#define CMD_GOTO 293
#define CMD_REGISTERS 294
#define CMD_READSPACE 295
#define CMD_WRITESPACE 296
#define CMD_RADIX 297
#define CMD_MEM_DISPLAY 298
#define CMD_BREAK 299
#define CMD_TRACE 300
#define CMD_IO 301
#define CMD_BRMON 302
#define CMD_COMPARE 303
#define CMD_DUMP 304
#define CMD_UNDUMP 305
#define CMD_EXIT 306
#define CMD_DELETE 307
#define CMD_CONDITION 308
#define CMD_COMMAND 309
#define CMD_ASSEMBLE 310
#define CMD_DISASSEMBLE 311
#define CMD_NEXT 312
#define CMD_STEP 313
#define CMD_PRINT 314
#define CMD_DEVICE 315
#define CMD_HELP 316
#define CMD_WATCH 317
#define CMD_DISK 318
#define CMD_SYSTEM 319
#define CMD_QUIT 320
#define CMD_CHDIR 321
#define CMD_BANK 322
#define CMD_LOAD_LABELS 323
#define CMD_SAVE_LABELS 324
#define CMD_ADD_LABEL 325
#define CMD_DEL_LABEL 326
#define CMD_SHOW_LABELS 327
#define CMD_RECORD 328
#define CMD_MON_STOP 329
#define CMD_PLAYBACK 330
#define CMD_CHAR_DISPLAY 331
#define CMD_SPRITE_DISPLAY 332
#define CMD_TEXT_DISPLAY 333
#define CMD_SCREENCODE_DISPLAY 334
#define CMD_ENTER_DATA 335
#define CMD_ENTER_BIN_DATA 336
#define CMD_KEYBUF 337
#define CMD_BLOAD 338
#define CMD_BSAVE 339
#define CMD_SCREEN 340
#define CMD_UNTIL 341
#define CMD_CPU 342
#define CMD_YYDEBUG 343
#define CMD_BACKTRACE 344
#define CMD_SCREENSHOT 345
#define CMD_PWD 346
#define CMD_DIR 347
#define CMD_RESOURCE_GET 348
#define CMD_RESOURCE_SET 349
#define CMD_LOAD_RESOURCES 350
#define CMD_SAVE_RESOURCES 351
#define CMD_ATTACH 352
#define CMD_DETACH 353
#define CMD_MON_RESET 354
#define CMD_TAPECTRL 355
#define CMD_CARTFREEZE 356
#define CMD_CPUHISTORY 357
#define CMD_MEMMAPZAP 358
#define CMD_MEMMAPSHOW 359
#define CMD_MEMMAPSAVE 360
#define CMD_COMMENT 361
#define CMD_LIST 362
#define CMD_STOPWATCH 363
#define RESET 364
#define CMD_EXPORT 365
#define CMD_AUTOSTART 366
#define CMD_AUTOLOAD 367
#define CMD_LABEL_ASGN 368
#define L_PAREN 369
#define R_PAREN 370
#define ARG_IMMEDIATE 371
#define REG_A 372
#define REG_X 373
#define REG_Y 374
#define COMMA 375
#define INST_SEP 376
#define L_BRACKET 377
#define R_BRACKET 378
#define LESS_THAN 379
#define REG_U 380
#define REG_S 381
#define REG_PC 382
#define REG_PCR 383
#define REG_B 384
#define REG_C 385
#define REG_D 386
#define REG_E 387
#define REG_H 388
#define REG_L 389
#define REG_AF 390
#define REG_BC 391
#define REG_DE 392
#define REG_HL 393
#define REG_IX 394
#define REG_IY 395
#define REG_SP 396
#define REG_IXH 397
#define REG_IXL 398
#define REG_IYH 399
#define REG_IYL 400
#define PLUS 401
#define MINUS 402
#define STRING 403
#define FILENAME 404
#define R_O_L 405
#define OPCODE 406
#define LABEL 407
#define BANKNAME 408
#define CPUTYPE 409
#define MON_REGISTER 410
#define COMPARE_OP 411
#define RADIX_TYPE 412
#define INPUT_SPEC 413
#define CMD_CHECKPT_ON 414
#define CMD_CHECKPT_OFF 415
#define TOGGLE 416
#define MASK 417

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 127 "mon_parse.y" /* yacc.c:355  */

    MON_ADDR a;
    MON_ADDR range[2];
    int i;
    REG_ID reg;
    CONDITIONAL cond_op;
    cond_node_t *cond_node;
    RADIXTYPE rt;
    ACTION action;
    char *str;
    asm_mode_addr_info_t mode;

#line 569 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 586 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  307
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1740

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  306
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  611

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     167,   168,   165,   163,     2,   164,     2,   166,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   192,   193,   196,   197,   200,   201,   202,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   220,   222,   224,   226,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   248,   250,   252,
     254,   256,   258,   260,   262,   264,   266,   268,   271,   273,
     275,   278,   283,   288,   290,   292,   294,   296,   298,   300,
     302,   306,   313,   312,   315,   317,   319,   323,   325,   327,
     329,   331,   333,   335,   337,   339,   341,   343,   345,   347,
     349,   351,   353,   355,   357,   359,   361,   365,   374,   377,
     381,   384,   393,   396,   405,   410,   412,   414,   416,   418,
     420,   422,   424,   426,   430,   432,   437,   439,   457,   459,
     461,   463,   467,   469,   471,   473,   475,   477,   479,   481,
     483,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   517,   519,   521,   523,
     525,   527,   529,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   557,   559,   561,   565,   567,
     571,   575,   578,   579,   582,   583,   586,   587,   590,   591,
     594,   595,   598,   599,   602,   603,   606,   610,   611,   614,
     615,   618,   619,   621,   625,   626,   629,   634,   639,   649,
     650,   653,   654,   655,   656,   657,   660,   662,   664,   665,
     666,   667,   668,   669,   670,   673,   674,   676,   681,   683,
     685,   687,   691,   697,   705,   706,   709,   710,   713,   714,
     717,   718,   719,   722,   723,   726,   727,   728,   729,   732,
     733,   734,   737,   738,   739,   740,   741,   744,   745,   746,
     749,   759,   760,   763,   770,   778,   786,   794,   800,   808,
     816,   818,   819,   820,   821,   822,   823,   824,   826,   828,
     830,   832,   833,   834,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     852,   853,   868,   872,   876,   880,   884,   888,   892,   896,
     900,   912,   927,   931,   935,   939,   943,   947,   951,   955,
     959,   971,   980,   981,   982,   986,   987
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "H_NUMBER", "D_NUMBER", "O_NUMBER",
  "B_NUMBER", "CONVERT_OP", "B_DATA", "H_RANGE_GUESS", "D_NUMBER_GUESS",
  "O_NUMBER_GUESS", "B_NUMBER_GUESS", "BAD_CMD", "MEM_OP", "IF",
  "MEM_COMP", "MEM_DISK8", "MEM_DISK9", "MEM_DISK10", "MEM_DISK11",
  "EQUALS", "TRAIL", "CMD_SEP", "LABEL_ASGN_COMMENT", "CMD_SIDEFX",
  "CMD_RETURN", "CMD_BLOCK_READ", "CMD_BLOCK_WRITE", "CMD_UP", "CMD_DOWN",
  "CMD_LOAD", "CMD_SAVE", "CMD_VERIFY", "CMD_IGNORE", "CMD_HUNT",
  "CMD_FILL", "CMD_MOVE", "CMD_GOTO", "CMD_REGISTERS", "CMD_READSPACE",
  "CMD_WRITESPACE", "CMD_RADIX", "CMD_MEM_DISPLAY", "CMD_BREAK",
  "CMD_TRACE", "CMD_IO", "CMD_BRMON", "CMD_COMPARE", "CMD_DUMP",
  "CMD_UNDUMP", "CMD_EXIT", "CMD_DELETE", "CMD_CONDITION", "CMD_COMMAND",
  "CMD_ASSEMBLE", "CMD_DISASSEMBLE", "CMD_NEXT", "CMD_STEP", "CMD_PRINT",
  "CMD_DEVICE", "CMD_HELP", "CMD_WATCH", "CMD_DISK", "CMD_SYSTEM",
  "CMD_QUIT", "CMD_CHDIR", "CMD_BANK", "CMD_LOAD_LABELS",
  "CMD_SAVE_LABELS", "CMD_ADD_LABEL", "CMD_DEL_LABEL", "CMD_SHOW_LABELS",
  "CMD_RECORD", "CMD_MON_STOP", "CMD_PLAYBACK", "CMD_CHAR_DISPLAY",
  "CMD_SPRITE_DISPLAY", "CMD_TEXT_DISPLAY", "CMD_SCREENCODE_DISPLAY",
  "CMD_ENTER_DATA", "CMD_ENTER_BIN_DATA", "CMD_KEYBUF", "CMD_BLOAD",
  "CMD_BSAVE", "CMD_SCREEN", "CMD_UNTIL", "CMD_CPU", "CMD_YYDEBUG",
  "CMD_BACKTRACE", "CMD_SCREENSHOT", "CMD_PWD", "CMD_DIR",
  "CMD_RESOURCE_GET", "CMD_RESOURCE_SET", "CMD_LOAD_RESOURCES",
  "CMD_SAVE_RESOURCES", "CMD_ATTACH", "CMD_DETACH", "CMD_MON_RESET",
  "CMD_TAPECTRL", "CMD_CARTFREEZE", "CMD_CPUHISTORY", "CMD_MEMMAPZAP",
  "CMD_MEMMAPSHOW", "CMD_MEMMAPSAVE", "CMD_COMMENT", "CMD_LIST",
  "CMD_STOPWATCH", "RESET", "CMD_EXPORT", "CMD_AUTOSTART", "CMD_AUTOLOAD",
  "CMD_LABEL_ASGN", "L_PAREN", "R_PAREN", "ARG_IMMEDIATE", "REG_A",
  "REG_X", "REG_Y", "COMMA", "INST_SEP", "L_BRACKET", "R_BRACKET",
  "LESS_THAN", "REG_U", "REG_S", "REG_PC", "REG_PCR", "REG_B", "REG_C",
  "REG_D", "REG_E", "REG_H", "REG_L", "REG_AF", "REG_BC", "REG_DE",
  "REG_HL", "REG_IX", "REG_IY", "REG_SP", "REG_IXH", "REG_IXL", "REG_IYH",
  "REG_IYL", "PLUS", "MINUS", "STRING", "FILENAME", "R_O_L", "OPCODE",
  "LABEL", "BANKNAME", "CPUTYPE", "MON_REGISTER", "COMPARE_OP",
  "RADIX_TYPE", "INPUT_SPEC", "CMD_CHECKPT_ON", "CMD_CHECKPT_OFF",
  "TOGGLE", "MASK", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "$accept",
  "top_level", "command_list", "end_cmd", "command", "machine_state_rules",
  "register_mod", "symbol_table_rules", "asm_rules", "$@1", "memory_rules",
  "checkpoint_rules", "checkpoint_control_rules", "monitor_state_rules",
  "monitor_misc_rules", "disk_rules", "cmd_file_rules", "data_entry_rules",
  "monitor_debug_rules", "rest_of_line", "opt_rest_of_line", "filename",
  "device_num", "mem_op", "opt_mem_op", "register", "reg_list", "reg_asgn",
  "checkpt_num", "address_opt_range", "address_range", "opt_address",
  "address", "opt_sep", "memspace", "memloc", "memaddr", "expression",
  "opt_if_cond_expr", "cond_expr", "compare_operand", "data_list",
  "data_element", "hunt_list", "hunt_element", "value", "d_number",
  "guess_default", "number", "assembly_instr_list", "assembly_instruction",
  "post_assemble", "asm_operand_mode", "index_reg", "index_usreg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,    43,    45,    42,    47,    40,    41
};
# endif

#define YYPACT_NINF -362

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-362)))

#define YYTABLE_NINF -191

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1180,   958,  -362,  -362,     2,   191,   958,   958,   560,   560,
      13,    13,    13,   264,  1526,  1526,  1526,  1297,    73,    19,
     978,  1068,  1068,  1297,  1526,    13,    13,   191,   592,   264,
     264,  1544,  1145,   560,   560,   958,   405,   114,  1068,  -137,
    -137,   191,  -137,   215,   138,   138,  1544,   253,   668,    13,
     191,    13,  1145,  1145,  1145,  1145,  1544,   191,  -137,    13,
      13,   191,  1145,    29,   191,   191,    13,   191,  -135,  -129,
    -108,    13,    13,    13,   958,   560,   -53,   191,   560,   191,
     560,    13,  -135,   355,   220,   191,    13,    13,    64,  1568,
     264,   264,   101,  1316,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,    90,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,   958,  -362,   -38,    46,  -362,  -362,  -362,  -362,
    -362,  -362,   191,  -362,  -362,   938,   938,  -362,  -362,   958,
    -362,   958,  -362,  -362,   767,   792,   767,  -362,  -362,  -362,
    -362,  -362,   560,  -362,  -362,  -362,   -53,   -53,   -53,  -362,
    -362,  -362,   -53,   -53,  -362,   191,   -53,  -362,   125,   110,
    -362,    34,   191,  -362,   -53,  -362,   191,  -362,   293,  -362,
    -362,   134,  1526,  -362,  1526,  -362,   191,   -53,   191,   191,
    -362,   287,  -362,   191,   136,    97,    16,  -362,   191,  -362,
     958,  -362,   958,    46,   191,  -362,  -362,   191,  -362,  1526,
     191,   191,  -362,   191,   191,  -362,   104,   191,   -53,   191,
     -53,   -53,   191,   -53,  -362,   191,   191,  -362,   191,  -362,
     191,  -362,   191,  -362,   191,  -362,   191,   396,  -362,   191,
     767,   767,  -362,  -362,   191,   191,  -362,  -362,  -362,   560,
    -362,  -362,   191,   191,     5,   191,   191,   958,    46,  -362,
     958,   958,  -362,  -362,   958,  -362,  -362,   958,   -53,   191,
     303,  -362,   191,   459,   191,  -362,  -362,  1620,  1620,  1544,
    1580,   827,    45,   -97,   521,   827,    48,  -362,    59,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,    61,  -362,   191,   191,  -362,  -362,  -362,
       6,  -362,   958,   958,   958,   958,  -362,  -362,    32,  1026,
      46,    46,  -362,   127,  1447,  1468,  1508,  -362,   958,    60,
    1544,  1105,   396,  1544,  -362,   827,   827,   281,  -362,  -362,
    -362,  1526,  -362,  -362,   172,   172,  -362,  1544,  -362,  -362,
    -362,  1427,   191,    40,  -362,    52,  -362,    46,    46,  -362,
    -362,  -362,   172,  -362,  -362,  -362,  -362,  -362,    54,  -362,
      13,  -362,    13,    66,  -362,    67,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  1011,  -362,  -362,  -362,   127,  1488,
    -362,  -362,  -362,   958,  -362,  -362,   191,  -362,  -362,    46,
    -362,    46,    46,    46,   840,   958,  -362,  -362,  -362,  -362,
     827,  -362,   827,   393,   105,   111,   126,   135,   140,   143,
     -18,  -362,   226,  -362,  -362,  -362,  -362,   244,    83,  -362,
     141,   301,   142,   158,    -7,  -362,   226,   226,  1604,  -362,
    -362,  -362,  -362,    12,    12,  -362,  -362,   191,  1544,   191,
    -362,  -362,   191,  -362,   191,  -362,   191,    46,  -362,  -362,
     119,  -362,  -362,  -362,  -362,  -362,  1011,   191,  -362,  -362,
     191,  1427,   191,   191,   191,  1427,  -362,    26,  -362,  -362,
    -362,   191,   169,   170,   191,  -362,  -362,   191,   191,   191,
     191,   191,   191,  -362,   396,   191,  -362,   191,    46,  -362,
    -362,  -362,  -362,  -362,  -362,   191,    46,   191,   191,   191,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,   173,   177,  -362,
     226,  -362,   156,   226,   420,   -65,   226,   226,   580,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   147,
    -362,  -362,  -362,     3,  1046,  -362,  -362,    52,    52,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,   467,   192,  -362,  -362,   194,
     226,   195,  -362,   -39,   198,   207,   210,   213,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,   218,  -362,  -362,   223,  -362,  -362,  -362,  -362,  -362,
    -362
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    22,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,     2,     5,    10,    47,    11,    13,    12,
      14,    15,    16,    17,    18,    19,    20,    21,     0,   232,
     233,   234,   235,   231,   230,   229,   191,   192,   193,   194,
     195,   172,     0,   224,     0,     0,   204,   236,   223,     9,
       8,     7,     0,   105,    35,     0,     0,   189,    42,     0,
      44,     0,   165,   164,     0,     0,     0,   178,   225,   228,
     227,   226,     0,   177,   182,   188,   190,   190,   190,   186,
     196,   197,   190,   190,    28,     0,   190,    48,     0,     0,
     175,     0,     0,   107,   190,    73,     0,   179,   190,   169,
      88,   170,     0,    94,     0,    29,     0,   190,     0,     0,
     111,     9,   100,     0,     0,     0,     0,    66,     0,    40,
       0,    38,     0,     0,     0,   161,   114,     0,    92,     0,
       0,     0,   110,     0,     0,    23,     0,     0,   190,     0,
     190,   190,     0,   190,    59,     0,     0,   156,     0,    75,
       0,    77,     0,    79,     0,    81,     0,     0,   159,     0,
       0,     0,    46,    90,     0,     0,    31,   160,   120,     0,
     122,   162,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   132,    33,     0,    82,    83,     0,   190,     0,
       9,   147,     0,   166,     0,   135,   109,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   263,   264,   265,   266,
     267,   270,   273,   274,   275,   276,   277,   278,   279,   268,
     271,   269,   272,   244,   240,     0,     0,     1,     6,     3,
       0,   173,     0,     0,     0,     0,   117,   104,   190,     0,
       0,     0,   167,   190,   139,     0,     0,    97,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,    50,    49,
     106,     0,    72,   168,   206,   206,    30,     0,    36,    37,
      99,     0,     0,     0,    64,     0,    65,     0,     0,   113,
     108,   115,   206,   112,   116,   118,    25,    24,     0,    52,
       0,    54,     0,     0,    56,     0,    58,   155,   157,    74,
      76,    78,    80,   217,     0,   215,   216,   119,   190,     0,
      89,    32,   123,     0,   121,   125,     0,   127,   128,     0,
     150,     0,     0,     0,     0,     0,   133,   148,   134,   151,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,   302,   303,   305,   306,     0,   286,   304,
       0,     0,     0,     0,     0,   280,     0,     0,     0,    95,
      96,   203,   202,   198,   199,   200,   201,     0,     0,     0,
      43,    45,     0,   140,     0,   144,     0,     0,   222,   221,
       0,   219,   220,   181,   183,   187,     0,     0,   176,   174,
       0,     0,     0,     0,     0,     0,   212,     0,   211,   213,
     103,     0,   242,   241,     0,    41,    39,     0,     0,     0,
       0,     0,     0,   158,     0,     0,   142,     0,     0,   126,
     149,   130,   131,    34,    84,     0,     0,     0,     0,     0,
      60,   251,   252,   253,   254,   255,   256,   248,     0,   288,
       0,   284,   282,     0,     0,     0,     0,     0,     0,   301,
     287,   289,   245,   246,   290,   247,   281,   145,   184,   146,
     136,   138,   143,    98,    70,   218,    69,    67,    71,   205,
      87,    93,    68,     0,     0,   101,   102,     0,   239,    63,
      91,    26,    51,    53,    55,    57,   214,   137,   141,   124,
      85,    86,   152,   154,    61,     0,     0,   285,   283,     0,
       0,     0,   296,     0,     0,     0,     0,     0,   210,   209,
     208,   207,   237,   238,   257,   250,   258,   259,   260,   249,
     298,     0,   294,   292,     0,   297,   299,   300,   291,   295,
     293
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -362,  -362,  -362,   423,   250,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,   510,
     265,   470,   108,  -362,    37,   -17,  -362,    17,   294,    -9,
      -6,  -312,    63,    28,   694,  -319,  -362,    25,  -262,  -361,
    -362,    23,  -130,  -362,  -103,  -362,  -362,  -362,    -1,  -362,
    -353,  -362,  -362,   234,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,   133,    94,    95,    96,    97,    98,   355,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   207,
     252,   144,   272,   181,   182,   123,   169,   170,   152,   176,
     177,   447,   178,   448,   124,   159,   160,   273,   472,   477,
     478,   384,   385,   460,   461,   126,   153,   127,   161,   482,
     108,   484,   304,   428,   429
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   168,   483,   129,   588,   128,   128,   441,   156,   162,
     163,   452,   465,   205,   142,   251,   465,   129,   187,   253,
     129,   423,   424,   198,   130,   131,   125,   129,   425,   426,
     129,   135,   136,  -185,   128,   129,   139,   141,   130,   131,
     254,   130,   131,   230,   232,   234,   236,   129,   130,   131,
     427,   130,   131,   244,  -185,  -185,   130,   131,   582,   184,
     203,   200,   202,   109,   110,   111,   112,   137,   130,   131,
     113,   114,   115,   128,   129,   209,   495,   157,   157,   157,
     165,   583,   128,   473,   603,   279,   186,   157,   303,   116,
     117,   118,   119,   120,   196,   130,   131,   517,   352,   258,
     487,   307,   518,   260,   261,   129,   264,   604,   267,   221,
     549,   129,   309,   528,   553,   129,   529,   311,   589,   237,
     129,   128,   109,   110,   111,   112,   130,   131,  -185,   113,
     114,   115,   130,   131,   128,   128,   130,   131,   128,   142,
     128,   130,   131,   128,   128,   128,   336,   310,   343,  -185,
    -185,   351,   137,   396,   116,   117,   118,   119,   120,   554,
     318,   319,   143,   132,   320,   422,   321,   -62,   436,   312,
     313,   314,   315,   344,   442,   345,   172,   314,   315,   437,
     328,   438,   554,   245,   329,   330,   331,   471,   481,   311,
     332,   333,   129,   591,   335,   312,   313,   314,   315,   128,
     362,   128,   341,    89,   592,   593,   330,   488,   458,   312,
     313,   314,   315,   130,   131,   347,   129,   137,   491,   492,
     511,   129,   459,   353,   137,   357,   512,   358,   121,   522,
     337,   116,   117,   118,   119,   120,   386,   130,   131,   128,
     128,   513,   130,   131,   368,  -190,   370,   137,   372,   373,
     514,   375,   323,   325,   326,   515,   128,  -190,   516,   128,
     128,   523,   526,   128,   205,   147,   128,   458,   148,   116,
     117,   118,   119,   120,   149,   150,   151,   393,   527,   420,
     421,   459,   399,   434,   435,   401,   402,   143,  -178,   403,
     557,   558,   404,   575,  -180,   576,   405,   116,   117,   118,
     119,   120,   578,   554,  -167,   410,   412,   599,  -180,  -178,
    -178,   128,   128,   128,   128,  -180,  -180,   600,   602,   454,
     168,   605,   193,   194,   195,  -167,  -167,   128,   462,   274,
     606,   386,   470,   607,   476,   468,   608,   443,   444,   445,
     446,   609,   413,   308,   423,   424,   610,   269,   388,   389,
     479,   425,   426,   457,   469,   466,   270,   545,   109,   110,
     111,   112,   423,   424,   566,   113,   114,   115,   214,   425,
     426,   116,   117,   118,   119,   120,   536,   130,   131,     0,
       0,     0,   449,   497,   305,   306,     0,     0,   157,   456,
       0,   520,   128,   463,   129,   505,   467,     0,     0,   109,
     110,   111,   112,     0,   128,   222,   113,   114,   115,   507,
     474,   508,   494,   137,     0,   130,   131,   509,   498,   423,
     424,   116,   117,   118,   119,   120,   425,   426,   134,     0,
     506,   138,   140,     0,     0,     0,   121,   535,     0,     0,
     164,   167,   173,   175,   180,   183,   185,     0,   524,     0,
     190,   192,   157,     0,   476,   197,   199,   201,   476,   462,
     206,   208,     0,     0,   212,     0,   215,     0,     0,     0,
     479,   224,     0,   227,   479,   229,   231,   233,   235,     0,
     238,   145,   146,     0,   242,   243,   246,   247,   248,     0,
     250,     0,     0,   386,   494,   188,   189,     0,   259,     0,
     262,   263,   265,   266,     0,     0,   271,   275,   276,     0,
     121,   538,     0,     0,   217,   219,     0,     0,     0,   226,
       0,   228,   122,     0,   109,   110,   111,   112,     0,   240,
     241,   113,   114,   115,     0,     0,   249,   476,   423,   424,
       0,   255,   256,   257,   383,   425,   426,     0,   316,   210,
     211,   268,   213,   479,     0,   317,   277,   278,     0,     0,
       0,   129,     0,  -190,  -190,  -190,  -190,   580,   239,     0,
    -190,  -190,  -190,     0,     0,   327,  -190,  -190,  -190,  -190,
    -190,     0,   130,   131,   594,     0,   595,     0,   334,     0,
       0,     0,   338,   191,   339,   340,   148,     0,     0,   342,
       0,     0,   149,   150,   151,   596,   597,   598,     0,   346,
       0,   348,   349,     0,   130,   131,   350,     0,     0,   354,
       0,   356,   312,   313,   314,   315,   359,   360,     0,     0,
     361,     0,     0,   363,   364,     0,   365,   366,   430,   367,
     369,   431,   371,     0,     0,   374,     0,     0,   376,   377,
     432,   378,   433,   379,     0,   380,   519,   381,     0,   382,
       0,   521,   387,     0,     0,   525,     0,   390,   391,   129,
     530,   531,   392,     0,     0,   394,   395,     0,   397,   398,
     137,   400,     0,     0,   116,   117,   118,   119,   120,     0,
     130,   131,   406,     0,     0,   407,     0,   408,   423,   424,
     409,   411,     0,     0,     0,   425,   426,   586,   158,   158,
     158,   166,   171,     0,   158,  -190,     0,   166,   158,     0,
       0,     0,     0,     0,     0,   166,   158,  -190,   439,   440,
     204,     0,     0,     0,     0,     0,     0,   216,   218,   220,
     166,   223,   225,   450,   451,     0,   158,   158,   158,   158,
     166,     0,     0,     0,   577,     0,   158,   579,   581,     0,
     584,   585,   587,     0,     0,     0,     0,     0,   322,     0,
     109,   110,   111,   112,     0,   480,     0,   113,   114,   115,
     485,   486,     0,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,   324,     0,   109,   110,   111,   112,     0,
       0,     0,   113,   114,   115,     0,     0,   493,   116,   117,
     118,   119,   120,     0,   601,     0,     0,     0,     0,   499,
       0,     0,   500,     0,   501,   502,   503,   504,     0,     0,
     109,   110,   111,   112,     0,     0,   510,   113,   114,   115,
     489,   129,   490,   109,   110,   111,   112,     0,     0,   154,
     113,   114,   115,     0,     0,     0,   116,   117,   118,   119,
     120,     0,   130,   131,     0,     0,     0,     0,     0,     0,
     537,     0,   539,     0,     0,   540,   158,   541,   158,   542,
     543,     0,     0,   544,     0,     0,     0,     0,     0,   546,
     547,     0,     0,   548,     0,   550,   551,   552,     0,     0,
     555,     0,     0,   158,   556,     0,     0,   559,     0,     0,
     560,   561,   562,   563,   564,   565,     0,     0,   567,     0,
     568,   569,   121,     0,     0,     0,     0,     0,   570,   571,
     572,   573,   574,     0,   122,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,   121,   113,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   122,
       0,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   166,   116,   117,   118,   119,   120,   129,
       0,   109,   110,   111,   112,     0,     0,   154,   113,   114,
     115,     0,   155,     0,   116,   117,   118,   119,   120,     0,
     130,   131,     0,   312,   313,   314,   315,     0,     0,     0,
       0,     0,   129,   166,  -190,  -190,  -190,  -190,     0,   158,
     166,  -190,  -190,  -190,   166,     0,     0,   166,     0,   109,
     110,   111,   112,   130,   131,   158,   113,   114,   115,     0,
       0,   166,   116,   117,   118,   119,   120,   590,     0,   109,
     110,   111,   112,     0,     0,     0,   113,   114,   115,     0,
       0,     0,   116,   117,   118,   119,   120,     0,     0,   129,
       0,  -171,  -171,  -171,  -171,     0,     0,  -171,  -171,  -171,
    -171,     0,   179,   158,  -171,  -171,  -171,  -171,  -171,     0,
     130,   131,     0,   121,     0,     0,     0,     0,   158,     0,
       0,   312,   313,   314,   315,   122,     0,     0,   109,   110,
     111,   112,     0,   121,   464,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   122,     0,     0,     0,     0,
     155,   137,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,   129,     0,   109,   110,
     111,   112,     0,     0,   154,   113,   114,   115,     0,  -190,
     475,   116,   117,   118,   119,   120,     0,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   312,
     313,   314,   315,     2,     0,     0,     0,     0,     0,     0,
       0,   121,     3,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
    -171,     0,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,    88,     0,     0,     0,   155,   129,     0,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,     0,   130,
     131,     0,     0,     1,     0,     0,     0,     0,     0,     2,
       0,    89,     0,     0,     0,     0,     0,     0,     0,    90,
      91,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,    87,    88,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,  -167,   155,
    -167,  -167,  -167,  -167,     0,     0,  -167,  -167,  -167,  -167,
       0,     0,     0,  -167,  -167,  -167,  -167,  -167,     0,   453,
       0,   109,   110,   111,   112,    90,    91,   154,   113,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   496,
       0,   109,   110,   111,   112,     0,     0,   154,   113,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   455,
       0,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   109,
     110,   111,   112,     0,     0,   154,   113,   114,   115,     0,
       0,   475,   116,   117,   118,   119,   120,   109,   110,   111,
     112,     0,     0,     0,   113,   114,   115,     0,     0,     0,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,     0,   121,   109,   110,   111,   112,     0,     0,     0,
     113,   114,   115,     0,     0,     0,     0,     0,     0,  -167,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,     0,     0,     0,   113,   114,   115,     0,     0,     0,
     155,   129,     0,  -190,  -190,  -190,  -190,     0,     0,     0,
    -190,  -190,  -190,     0,     0,     0,     0,     0,     0,     0,
     155,     0,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,   280,     0,   281,   282,     0,     0,   283,     0,
     284,     0,   285,     0,     0,     0,   155,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,     0,     0,   414,   415,   416,   417,
     418,   419,   532,   533,     0,     0,     0,     0,     0,   425,
     426,   534,     0,     0,     0,     0,     0,     0,     0,     0,
     137
};

static const yytype_int16 yycheck[] =
{
       1,    18,   355,     1,     1,     6,     7,     1,    14,    15,
      16,   323,   331,   150,     1,   150,   335,     1,    24,   148,
       1,   118,   119,    32,    22,    23,     1,     1,   125,   126,
       1,     6,     7,     1,    35,     1,     8,     9,    22,    23,
     148,    22,    23,    52,    53,    54,    55,     1,    22,    23,
     147,    22,    23,    62,    22,    23,    22,    23,   123,    22,
      35,    33,    34,     3,     4,     5,     6,   120,    22,    23,
      10,    11,    12,    74,     1,    38,   388,    14,    15,    16,
      17,   146,    83,   345,   123,    21,    23,    24,    89,    16,
      17,    18,    19,    20,    31,    22,    23,   115,     1,    74,
     362,     0,   120,    75,    76,     1,    78,   146,    80,    46,
     471,     1,    22,   120,   475,     1,   123,   155,   115,    56,
       1,   122,     3,     4,     5,     6,    22,    23,     1,    10,
      11,    12,    22,    23,   135,   136,    22,    23,   139,     1,
     141,    22,    23,   144,   145,   146,    21,   122,    14,    22,
      23,    15,   120,   148,    16,    17,    18,    19,    20,   156,
     135,   136,   149,   161,   139,   120,   141,   151,   120,   163,
     164,   165,   166,   182,   168,   184,   157,   165,   166,   120,
     152,   120,   156,   154,   156,   157,   158,    15,   148,   155,
     162,   163,     1,   554,   166,   163,   164,   165,   166,   200,
     209,   202,   174,   151,   557,   558,   178,   153,   148,   163,
     164,   165,   166,    22,    23,   187,     1,   120,   152,   152,
     115,     1,   162,   195,   120,   200,   115,   202,   155,   146,
     120,    16,    17,    18,    19,    20,   237,    22,    23,   240,
     241,   115,    22,    23,   216,   148,   218,   120,   220,   221,
     115,   223,   144,   145,   146,   115,   257,   153,   115,   260,
     261,   120,   120,   264,   150,     1,   267,   148,     4,    16,
      17,    18,    19,    20,    10,    11,    12,   249,   120,   280,
     281,   162,   257,   284,   285,   260,   261,   149,     1,   264,
     121,   121,   267,   120,     1,   118,   268,    16,    17,    18,
      19,    20,   146,   156,     1,   277,   278,   115,    15,    22,
      23,   312,   313,   314,   315,    22,    23,   123,   123,   325,
     337,   123,    28,    29,    30,    22,    23,   328,   329,   109,
     123,   332,   341,   123,   351,   336,   123,   312,   313,   314,
     315,   123,   279,    93,   118,   119,   123,    82,   240,   241,
     351,   125,   126,   328,   337,   332,     1,   460,     3,     4,
       5,     6,   118,   119,   494,    10,    11,    12,   153,   125,
     126,    16,    17,    18,    19,    20,   438,    22,    23,    -1,
      -1,    -1,   319,   389,    90,    91,    -1,    -1,   325,   326,
      -1,   147,   393,   330,     1,   404,   333,    -1,    -1,     3,
       4,     5,     6,    -1,   405,   152,    10,    11,    12,   410,
     347,   412,   384,   120,    -1,    22,    23,    24,   393,   118,
     119,    16,    17,    18,    19,    20,   125,   126,     5,    -1,
     405,     8,     9,    -1,    -1,    -1,   155,   438,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,   147,    -1,
      27,    28,   389,    -1,   471,    32,    33,    34,   475,   460,
      37,    38,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,
     471,    48,    -1,    50,   475,    52,    53,    54,    55,    -1,
      57,    11,    12,    -1,    61,    62,    63,    64,    65,    -1,
      67,    -1,    -1,   494,   466,    25,    26,    -1,    75,    -1,
      77,    78,    79,    80,    -1,    -1,    83,    84,    85,    -1,
     155,   448,    -1,    -1,    44,    45,    -1,    -1,    -1,    49,
      -1,    51,   167,    -1,     3,     4,     5,     6,    -1,    59,
      60,    10,    11,    12,    -1,    -1,    66,   554,   118,   119,
      -1,    71,    72,    73,   148,   125,   126,    -1,   125,    39,
      40,    81,    42,   554,    -1,   132,    86,    87,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,   147,    58,    -1,
      10,    11,    12,    -1,    -1,   152,    16,    17,    18,    19,
      20,    -1,    22,    23,   117,    -1,   119,    -1,   165,    -1,
      -1,    -1,   169,     1,   171,   172,     4,    -1,    -1,   176,
      -1,    -1,    10,    11,    12,   138,   139,   140,    -1,   186,
      -1,   188,   189,    -1,    22,    23,   193,    -1,    -1,   196,
      -1,   198,   163,   164,   165,   166,   203,   204,    -1,    -1,
     207,    -1,    -1,   210,   211,    -1,   213,   214,   117,   216,
     217,   120,   219,    -1,    -1,   222,    -1,    -1,   225,   226,
     129,   228,   131,   230,    -1,   232,   422,   234,    -1,   236,
      -1,   427,   239,    -1,    -1,   431,    -1,   244,   245,     1,
     436,   437,   249,    -1,    -1,   252,   253,    -1,   255,   256,
     120,   258,    -1,    -1,    16,    17,    18,    19,    20,    -1,
      22,    23,   269,    -1,    -1,   272,    -1,   274,   118,   119,
     277,   278,    -1,    -1,    -1,   125,   126,   127,    14,    15,
      16,    17,    18,    -1,    20,   155,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,   167,   305,   306,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,   320,   321,    -1,    52,    53,    54,    55,
      56,    -1,    -1,    -1,   520,    -1,    62,   523,   524,    -1,
     526,   527,   528,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,   352,    -1,    10,    11,    12,
     357,   358,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,   384,    16,    17,
      18,    19,    20,    -1,   580,    -1,    -1,    -1,    -1,   396,
      -1,    -1,   399,    -1,   401,   402,   403,   404,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,   413,    10,    11,    12,
     370,     1,   372,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
     447,    -1,   449,    -1,    -1,   452,   182,   454,   184,   456,
     457,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,   466,
     467,    -1,    -1,   470,    -1,   472,   473,   474,    -1,    -1,
     477,    -1,    -1,   209,   481,    -1,    -1,   484,    -1,    -1,
     487,   488,   489,   490,   491,   492,    -1,    -1,   495,    -1,
     497,   498,   155,    -1,    -1,    -1,    -1,    -1,   505,   506,
     507,   508,   509,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,   155,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,   167,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,   279,    16,    17,    18,    19,    20,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,   152,    -1,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,   163,   164,   165,   166,    -1,    -1,    -1,
      -1,    -1,     1,   319,     3,     4,     5,     6,    -1,   325,
     326,    10,    11,    12,   330,    -1,    -1,   333,    -1,     3,
       4,     5,     6,    22,    23,   341,    10,    11,    12,    -1,
      -1,   347,    16,    17,    18,    19,    20,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,    14,   389,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,   155,    -1,    -1,    -1,    -1,   404,    -1,
      -1,   163,   164,   165,   166,   167,    -1,    -1,     3,     4,
       5,     6,    -1,   155,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     152,   120,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    -1,   148,
     114,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,   163,
     164,   165,   166,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    22,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     152,    -1,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,   113,    -1,    -1,    -1,   152,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,   111,   112,   113,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,     1,   152,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    -1,     1,
      -1,     3,     4,     5,     6,   159,   160,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,   114,    16,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,   155,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
     152,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   114,    -1,   116,   117,    -1,    -1,   120,    -1,
     122,    -1,   124,    -1,    -1,    -1,   152,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,   136,   137,   138,   139,
     140,   141,   118,   119,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    13,    22,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      43,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   110,   111,   112,   113,   151,
     159,   160,   170,   171,   173,   174,   175,   176,   177,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   219,     3,
       4,     5,     6,    10,    11,    12,    16,    17,    18,    19,
      20,   155,   167,   194,   203,   206,   214,   216,   217,     1,
      22,    23,   161,   172,   172,   206,   206,   120,   172,   202,
     172,   202,     1,   149,   190,   190,   190,     1,     4,    10,
      11,    12,   197,   215,     9,   152,   199,   201,   203,   204,
     205,   217,   199,   199,   172,   201,   203,   172,   194,   195,
     196,   203,   157,   172,   157,   172,   198,   199,   201,    14,
     172,   192,   193,   172,   193,   172,   201,   199,   190,   190,
     172,     1,   172,   197,   197,   197,   201,   172,   198,   172,
     202,   172,   202,   206,   203,   150,   172,   188,   172,   193,
     188,   188,   172,   188,   153,   172,   203,   190,   203,   190,
     203,   201,   152,   203,   172,   203,   190,   172,   190,   172,
     198,   172,   198,   172,   198,   172,   198,   201,   172,   188,
     190,   190,   172,   172,   198,   154,   172,   172,   172,   190,
     172,   150,   189,   148,   148,   190,   190,   190,   206,   172,
     202,   202,   172,   172,   202,   172,   172,   202,   190,   189,
       1,   172,   191,   206,   109,   172,   172,   190,   190,    21,
     114,   116,   117,   120,   122,   124,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   217,   221,   197,   197,     0,   173,    22,
     206,   155,   163,   164,   165,   166,   172,   172,   206,   206,
     206,   206,     1,   191,     1,   191,   191,   172,   202,   202,
     202,   202,   202,   202,   172,   202,    21,   120,   172,   172,
     172,   202,   172,    14,   198,   198,   172,   202,   172,   172,
     172,    15,     1,   202,   172,   178,   172,   206,   206,   172,
     172,   172,   198,   172,   172,   172,   172,   172,   202,   172,
     202,   172,   202,   202,   172,   202,   172,   172,   172,   172,
     172,   172,   172,   148,   210,   211,   217,   172,   191,   191,
     172,   172,   172,   202,   172,   172,   148,   172,   172,   206,
     172,   206,   206,   206,   206,   202,   172,   172,   172,   172,
     202,   172,   202,   201,   136,   137,   138,   139,   140,   141,
     217,   217,   120,   118,   119,   125,   126,   147,   222,   223,
     117,   120,   129,   131,   217,   217,   120,   120,   120,   172,
     172,     1,   168,   206,   206,   206,   206,   200,   202,   201,
     172,   172,   200,     1,   199,     1,   201,   206,   148,   162,
     212,   213,   217,   201,     9,   204,   210,   201,   217,   196,
     198,    15,   207,   207,   201,   114,   194,   208,   209,   217,
     172,   148,   218,   219,   220,   172,   172,   207,   153,   190,
     190,   152,   152,   172,   202,   200,     1,   199,   206,   172,
     172,   172,   172,   172,   172,   198,   206,   217,   217,    24,
     172,   115,   115,   115,   115,   115,   115,   115,   120,   222,
     147,   222,   146,   120,   147,   222,   120,   120,   120,   123,
     222,   222,   118,   119,   127,   217,   223,   172,   201,   172,
     172,   172,   172,   172,   172,   213,   172,   172,   172,   208,
     172,   172,   172,   208,   156,   172,   172,   121,   121,   172,
     172,   172,   172,   172,   172,   172,   211,   172,   172,   172,
     172,   172,   172,   172,   172,   120,   118,   222,   146,   222,
     147,   222,   123,   146,   222,   222,   127,   222,     1,   115,
       1,   208,   219,   219,   117,   119,   138,   139,   140,   115,
     123,   222,   123,   123,   146,   123,   123,   123,   123,   123,
     123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   169,   170,   170,   170,   171,   171,   172,   172,   172,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   175,
     175,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   178,   177,   177,   177,   177,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   180,   180,   180,
     180,   180,   180,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   185,   186,   186,
     187,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   196,   197,   197,   198,
     198,   199,   199,   199,   200,   200,   201,   201,   201,   202,
     202,   203,   203,   203,   203,   203,   204,   205,   206,   206,
     206,   206,   206,   206,   206,   207,   207,   208,   208,   208,
     208,   208,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   213,   214,   214,   215,   215,   215,   215,   216,
     216,   216,   217,   217,   217,   217,   217,   218,   218,   218,
     219,   220,   220,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   222,   222,   222,   223,   223
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     5,     3,     2,     2,
       3,     2,     3,     2,     4,     2,     3,     3,     2,     4,
       2,     4,     2,     4,     2,     4,     2,     1,     2,     3,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     2,
       4,     5,     0,     5,     3,     3,     2,     5,     5,     5,
       5,     5,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     2,     2,     4,     5,     5,     5,     2,     3,
       2,     5,     2,     5,     2,     3,     3,     3,     5,     3,
       2,     5,     5,     4,     3,     2,     3,     2,     3,     2,
       2,     2,     3,     3,     2,     3,     3,     3,     3,     3,
       2,     3,     2,     3,     5,     3,     4,     3,     3,     2,
       4,     4,     2,     3,     3,     2,     5,     5,     5,     3,
       4,     5,     4,     5,     4,     5,     5,     2,     3,     4,
       3,     3,     5,     3,     5,     3,     2,     3,     4,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     2,     1,
       1,     0,     1,     2,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     2,     0,     1,     3,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     2,     0,     3,     3,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       2,     1,     1,     2,     1,     3,     3,     3,     3,     5,
       5,     3,     3,     3,     3,     3,     3,     5,     5,     5,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     4,     3,     4,     2,     3,     3,     3,
       3,     5,     5,     6,     5,     6,     4,     5,     5,     5,
       5,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 191 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 2358 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 192 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 2364 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 193 "mon_parse.y" /* yacc.c:1646  */
    { new_cmd = 1; asm_mode = 0;  (yyval.i) = 0; }
#line 2370 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 202 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_END_CMD; }
#line 2376 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 217 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_BAD_CMD; }
#line 2382 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank(e_default_space, NULL); }
#line 2388 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 223 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank((yyvsp[-1].i), NULL); }
#line 2394 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 225 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank(e_default_space, (yyvsp[-1].str)); }
#line 2400 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 227 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2406 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 229 "mon_parse.y" /* yacc.c:1646  */
    { mon_jump((yyvsp[-1].a)); }
#line 2412 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 231 "mon_parse.y" /* yacc.c:1646  */
    { mon_go(); }
#line 2418 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 233 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_io_regs(0); }
#line 2424 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_io_regs((yyvsp[-1].a)); }
#line 2430 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 237 "mon_parse.y" /* yacc.c:1646  */
    { monitor_cpu_type_set(""); }
#line 2436 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 239 "mon_parse.y" /* yacc.c:1646  */
    { monitor_cpu_type_set((yyvsp[-1].str)); }
#line 2442 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 241 "mon_parse.y" /* yacc.c:1646  */
    { mon_cpuhistory(-1); }
#line 2448 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "mon_parse.y" /* yacc.c:1646  */
    { mon_cpuhistory((yyvsp[-1].i)); }
#line 2454 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 245 "mon_parse.y" /* yacc.c:1646  */
    { mon_instruction_return(); }
#line 2460 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 247 "mon_parse.y" /* yacc.c:1646  */
    { machine_write_snapshot((yyvsp[-1].str),0,0,0); /* FIXME */ }
#line 2466 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "mon_parse.y" /* yacc.c:1646  */
    { machine_read_snapshot((yyvsp[-1].str), 0); }
#line 2472 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 251 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_step(-1); }
#line 2478 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 253 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_step((yyvsp[-1].i)); }
#line 2484 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_next(-1); }
#line 2490 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 257 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_next((yyvsp[-1].i)); }
#line 2496 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 259 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_up(-1); }
#line 2502 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_up((yyvsp[-1].i)); }
#line 2508 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_down(-1); }
#line 2514 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 265 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_down((yyvsp[-1].i)); }
#line 2520 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 267 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_screen(); }
#line 2526 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[default_memspace]->mon_register_print)(default_memspace); }
#line 2532 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[(yyvsp[-1].i)]->mon_register_print)((yyvsp[-1].i)); }
#line 2538 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 279 "mon_parse.y" /* yacc.c:1646  */
    {
                        /* What about the memspace? */
                        mon_playback_init((yyvsp[-1].str));
                    }
#line 2547 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 284 "mon_parse.y" /* yacc.c:1646  */
    {
                        /* What about the memspace? */
                        mon_playback_init((yyvsp[-1].str));
                    }
#line 2556 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 289 "mon_parse.y" /* yacc.c:1646  */
    { mon_save_symbols((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2562 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 291 "mon_parse.y" /* yacc.c:1646  */
    { mon_save_symbols(e_default_space, (yyvsp[-1].str)); }
#line 2568 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 55:
#line 293 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_name_to_symbol_table((yyvsp[-3].a), (yyvsp[-1].str)); }
#line 2574 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 295 "mon_parse.y" /* yacc.c:1646  */
    { mon_remove_name_from_symbol_table(e_default_space, (yyvsp[-1].str)); }
#line 2580 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 297 "mon_parse.y" /* yacc.c:1646  */
    { mon_remove_name_from_symbol_table((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2586 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_symbol_table((yyvsp[-1].i)); }
#line 2592 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 301 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_symbol_table(e_default_space); }
#line 2598 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 303 "mon_parse.y" /* yacc.c:1646  */
    {
                        mon_add_name_to_symbol_table((yyvsp[-1].a), mon_prepend_dot_to_name((yyvsp[-3].str)));
                    }
#line 2606 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 61:
#line 307 "mon_parse.y" /* yacc.c:1646  */
    {
                        mon_add_name_to_symbol_table((yyvsp[-2].a), mon_prepend_dot_to_name((yyvsp[-4].str)));
                    }
#line 2614 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 313 "mon_parse.y" /* yacc.c:1646  */
    { mon_start_assemble_mode((yyvsp[0].a), NULL); }
#line 2620 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 314 "mon_parse.y" /* yacc.c:1646  */
    { }
#line 2626 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 64:
#line 316 "mon_parse.y" /* yacc.c:1646  */
    { mon_start_assemble_mode((yyvsp[-1].a), NULL); }
#line 2632 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 65:
#line 318 "mon_parse.y" /* yacc.c:1646  */
    { mon_disassemble_lines((yyvsp[-1].range)[0], (yyvsp[-1].range)[1]); }
#line 2638 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 66:
#line 320 "mon_parse.y" /* yacc.c:1646  */
    { mon_disassemble_lines(BAD_ADDR, BAD_ADDR); }
#line 2644 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 67:
#line 324 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_move((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 2650 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 326 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_compare((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 2656 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 328 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_fill((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 2662 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 330 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_hunt((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 2668 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 332 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display((yyvsp[-3].rt), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2674 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 334 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(default_radix, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2680 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 336 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(default_radix, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 2686 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 338 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 8, 8); }
#line 2692 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 340 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 8, 8); }
#line 2698 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 342 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 24, 21); }
#line 2704 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 344 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 24, 21); }
#line 2710 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 346 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2716 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 348 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 2722 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 350 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_SCREEN_CODE); }
#line 2728 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 352 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, BAD_ADDR, BAD_ADDR, DF_SCREEN_CODE); }
#line 2734 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 354 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_zap(); }
#line 2740 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 356 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show(-1,BAD_ADDR,BAD_ADDR); }
#line 2746 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 358 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show((yyvsp[-1].i),BAD_ADDR,BAD_ADDR); }
#line 2752 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 360 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show((yyvsp[-2].i),(yyvsp[-1].range)[0],(yyvsp[-1].range)[1]); }
#line 2758 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 362 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 2764 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 366 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_exec, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2777 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 375 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2783 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 378 "mon_parse.y" /* yacc.c:1646  */
    {
                      mon_breakpoint_add_checkpoint((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE, e_exec, TRUE);
                  }
#line 2791 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 382 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2797 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 385 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_load | e_store, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2810 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 92:
#line 394 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2816 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 397 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, e_load | e_store, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2829 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 406 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2835 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 411 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_ON, (yyvsp[-1].i)); }
#line 2841 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 413 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_OFF, (yyvsp[-1].i)); }
#line 2847 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 415 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_ignore_count((yyvsp[-1].i), -1); }
#line 2853 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 417 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_ignore_count((yyvsp[-3].i), (yyvsp[-1].i)); }
#line 2859 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 99:
#line 419 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_delete_checkpoint((yyvsp[-1].i)); }
#line 2865 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 100:
#line 421 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_delete_checkpoint(-1); }
#line 2871 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 101:
#line 423 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_checkpoint_condition((yyvsp[-3].i), (yyvsp[-1].cond_node)); }
#line 2877 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 102:
#line 425 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_checkpoint_command((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2883 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 103:
#line 427 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_STRING; }
#line 2889 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 104:
#line 431 "mon_parse.y" /* yacc.c:1646  */
    { sidefx = (((yyvsp[-1].action) == e_TOGGLE) ? (sidefx ^ 1) : (yyvsp[-1].action)); }
#line 2895 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 105:
#line 433 "mon_parse.y" /* yacc.c:1646  */
    {
                         mon_out("I/O side effects are %s\n",
                                   sidefx ? "enabled" : "disabled");
                     }
#line 2904 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 106:
#line 438 "mon_parse.y" /* yacc.c:1646  */
    { default_radix = (yyvsp[-1].rt); }
#line 2910 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 107:
#line 440 "mon_parse.y" /* yacc.c:1646  */
    {
                         const char *p;

                         if (default_radix == e_hexadecimal)
                             p = "Hexadecimal";
                         else if (default_radix == e_decimal)
                             p = "Decimal";
                         else if (default_radix == e_octal)
                             p = "Octal";
                         else if (default_radix == e_binary)
                             p = "Binary";
                         else
                             p = "Unknown";

                         mon_out("Default radix is %s\n", p);
                     }
#line 2931 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 108:
#line 458 "mon_parse.y" /* yacc.c:1646  */
    { monitor_change_device((yyvsp[-1].i)); }
#line 2937 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 109:
#line 460 "mon_parse.y" /* yacc.c:1646  */
    { mon_export(); }
#line 2943 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 110:
#line 462 "mon_parse.y" /* yacc.c:1646  */
    { mon_quit(); YYACCEPT; }
#line 2949 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 111:
#line 464 "mon_parse.y" /* yacc.c:1646  */
    { mon_exit(); YYACCEPT; }
#line 2955 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 112:
#line 468 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_execute_disk_cmd((yyvsp[-1].str)); }
#line 2961 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 113:
#line 470 "mon_parse.y" /* yacc.c:1646  */
    { mon_out("\t%d\n",(yyvsp[-1].i)); }
#line 2967 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 114:
#line 472 "mon_parse.y" /* yacc.c:1646  */
    { mon_command_print_help(NULL); }
#line 2973 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 115:
#line 474 "mon_parse.y" /* yacc.c:1646  */
    { mon_command_print_help((yyvsp[-1].str)); }
#line 2979 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 116:
#line 476 "mon_parse.y" /* yacc.c:1646  */
    { printf("SYSTEM COMMAND: %s\n",(yyvsp[-1].str)); }
#line 2985 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 117:
#line 478 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_convert((yyvsp[-1].i)); }
#line 2991 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 118:
#line 480 "mon_parse.y" /* yacc.c:1646  */
    { mon_change_dir((yyvsp[-1].str)); }
#line 2997 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 119:
#line 482 "mon_parse.y" /* yacc.c:1646  */
    { mon_keyboard_feed((yyvsp[-1].str)); }
#line 3003 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 120:
#line 484 "mon_parse.y" /* yacc.c:1646  */
    { mon_backtrace(); }
#line 3009 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 121:
#line 486 "mon_parse.y" /* yacc.c:1646  */
    { mon_show_dir((yyvsp[-1].str)); }
#line 3015 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 122:
#line 488 "mon_parse.y" /* yacc.c:1646  */
    { mon_show_pwd(); }
#line 3021 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 123:
#line 490 "mon_parse.y" /* yacc.c:1646  */
    { mon_screenshot_save((yyvsp[-1].str),-1); }
#line 3027 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 124:
#line 492 "mon_parse.y" /* yacc.c:1646  */
    { mon_screenshot_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 3033 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 125:
#line 494 "mon_parse.y" /* yacc.c:1646  */
    { mon_resource_get((yyvsp[-1].str)); }
#line 3039 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 126:
#line 496 "mon_parse.y" /* yacc.c:1646  */
    { mon_resource_set((yyvsp[-2].str),(yyvsp[-1].str)); }
#line 3045 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 127:
#line 498 "mon_parse.y" /* yacc.c:1646  */
    { resources_load((yyvsp[-1].str)); }
#line 3051 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 128:
#line 500 "mon_parse.y" /* yacc.c:1646  */
    { resources_save((yyvsp[-1].str)); }
#line 3057 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 129:
#line 502 "mon_parse.y" /* yacc.c:1646  */
    { mon_reset_machine(-1); }
#line 3063 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 130:
#line 504 "mon_parse.y" /* yacc.c:1646  */
    { mon_reset_machine((yyvsp[-1].i)); }
#line 3069 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 131:
#line 506 "mon_parse.y" /* yacc.c:1646  */
    { mon_tape_ctrl((yyvsp[-1].i)); }
#line 3075 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 132:
#line 508 "mon_parse.y" /* yacc.c:1646  */
    { mon_cart_freeze(); }
#line 3081 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 133:
#line 510 "mon_parse.y" /* yacc.c:1646  */
    { }
#line 3087 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 134:
#line 512 "mon_parse.y" /* yacc.c:1646  */
    { mon_stopwatch_reset(); }
#line 3093 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 135:
#line 514 "mon_parse.y" /* yacc.c:1646  */
    { mon_stopwatch_show("Stopwatch: ", "\n"); }
#line 3099 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 136:
#line 518 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), FALSE); }
#line 3105 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 137:
#line 520 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), TRUE); }
#line 3111 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 138:
#line 522 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], FALSE); }
#line 3117 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 139:
#line 524 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_DEVICE_NUM; }
#line 3123 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 140:
#line 526 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3129 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 141:
#line 528 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE); }
#line 3135 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 142:
#line 530 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3141 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 143:
#line 532 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_verify((yyvsp[-3].str),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3147 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 144:
#line 534 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3153 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 145:
#line 536 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_block_cmd(0,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3159 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 146:
#line 538 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_block_cmd(1,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3165 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 147:
#line 540 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_list(-1); }
#line 3171 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 148:
#line 542 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_list((yyvsp[-1].i)); }
#line 3177 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 149:
#line 544 "mon_parse.y" /* yacc.c:1646  */
    { mon_attach((yyvsp[-2].str),(yyvsp[-1].i)); }
#line 3183 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 150:
#line 546 "mon_parse.y" /* yacc.c:1646  */
    { mon_detach((yyvsp[-1].i)); }
#line 3189 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 151:
#line 548 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-1].str),0,1); }
#line 3195 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 152:
#line 550 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),1); }
#line 3201 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 153:
#line 552 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-1].str),0,0); }
#line 3207 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 154:
#line 554 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),0); }
#line 3213 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 155:
#line 558 "mon_parse.y" /* yacc.c:1646  */
    { mon_record_commands((yyvsp[-1].str)); }
#line 3219 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 156:
#line 560 "mon_parse.y" /* yacc.c:1646  */
    { mon_end_recording(); }
#line 3225 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 157:
#line 562 "mon_parse.y" /* yacc.c:1646  */
    { mon_playback_init((yyvsp[-1].str)); }
#line 3231 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 158:
#line 566 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_fill((yyvsp[-2].a), BAD_ADDR, (unsigned char *)(yyvsp[-1].str)); }
#line 3237 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 159:
#line 568 "mon_parse.y" /* yacc.c:1646  */
    { printf("Not yet.\n"); }
#line 3243 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 160:
#line 572 "mon_parse.y" /* yacc.c:1646  */
    { yydebug = 1; }
#line 3249 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 161:
#line 575 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3255 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 162:
#line 578 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3261 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 163:
#line 579 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 3267 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 165:
#line 583 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_FILENAME; }
#line 3273 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 167:
#line 587 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_DEVICE_NUM; }
#line 3279 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 168:
#line 590 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i) | (yyvsp[0].i); }
#line 3285 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 169:
#line 591 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3291 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 170:
#line 594 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3297 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 171:
#line 595 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 3303 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 172:
#line 598 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = new_reg(default_memspace, (yyvsp[0].reg)); }
#line 3309 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 173:
#line 599 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = new_reg((yyvsp[-1].i), (yyvsp[0].reg)); }
#line 3315 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 176:
#line 607 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[reg_memspace((yyvsp[-2].i))]->mon_register_set_val)(reg_memspace((yyvsp[-2].i)), reg_regid((yyvsp[-2].i)), (WORD) (yyvsp[0].i)); }
#line 3321 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 177:
#line 610 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3327 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 178:
#line 611 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_CHECKNUM; }
#line 3333 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 180:
#line 615 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.range)[0] = (yyvsp[0].a); (yyval.range)[1] = BAD_ADDR; }
#line 3339 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 181:
#line 618 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.range)[0] = (yyvsp[-2].a); (yyval.range)[1] = (yyvsp[0].a); }
#line 3345 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 182:
#line 620 "mon_parse.y" /* yacc.c:1646  */
    { if (resolve_range(e_default_space, (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3351 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 183:
#line 622 "mon_parse.y" /* yacc.c:1646  */
    { if (resolve_range((yyvsp[-2].i), (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3357 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 184:
#line 625 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 3363 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 185:
#line 626 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.a) = BAD_ADDR; }
#line 3369 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 186:
#line 630 "mon_parse.y" /* yacc.c:1646  */
    {
             (yyval.a) = new_addr(e_default_space,(yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3378 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 187:
#line 635 "mon_parse.y" /* yacc.c:1646  */
    {
             (yyval.a) = new_addr((yyvsp[-2].i), (yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3387 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 188:
#line 640 "mon_parse.y" /* yacc.c:1646  */
    {
             temp = mon_symbol_table_lookup_addr(e_default_space, (yyvsp[0].str));
             if (temp >= 0)
                 (yyval.a) = new_addr(e_default_space, temp);
             else
                 return ERR_UNDEFINED_LABEL;
         }
#line 3399 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 191:
#line 653 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_comp_space; }
#line 3405 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 192:
#line 654 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk8_space; }
#line 3411 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 193:
#line 655 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk9_space; }
#line 3417 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 194:
#line 656 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk10_space; }
#line 3423 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 195:
#line 657 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk11_space; }
#line 3429 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 196:
#line 660 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); if (!CHECK_ADDR((yyvsp[0].i))) return ERR_ADDR_TOO_BIG; }
#line 3435 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 197:
#line 662 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3441 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 198:
#line 664 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) + (yyvsp[0].i); }
#line 3447 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 199:
#line 665 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) - (yyvsp[0].i); }
#line 3453 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 200:
#line 666 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) * (yyvsp[0].i); }
#line 3459 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 201:
#line 667 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = ((yyvsp[0].i)) ? ((yyvsp[-2].i) / (yyvsp[0].i)) : 1; }
#line 3465 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 202:
#line 668 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 3471 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 203:
#line 669 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_MISSING_CLOSE_PAREN; }
#line 3477 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 204:
#line 670 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3483 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 205:
#line 673 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 3489 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 206:
#line 674 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = 0; }
#line 3495 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 207:
#line 677 "mon_parse.y" /* yacc.c:1646  */
    {
               (yyval.cond_node) = new_cond; (yyval.cond_node)->is_parenthized = FALSE;
               (yyval.cond_node)->child1 = (yyvsp[-2].cond_node); (yyval.cond_node)->child2 = (yyvsp[0].cond_node); (yyval.cond_node)->operation = (yyvsp[-1].cond_op);
           }
#line 3504 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 208:
#line 682 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_INCOMPLETE_COMPARE_OP; }
#line 3510 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 209:
#line 684 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[-1].cond_node); (yyval.cond_node)->is_parenthized = TRUE; }
#line 3516 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 210:
#line 686 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_MISSING_CLOSE_PAREN; }
#line 3522 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 211:
#line 688 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 3528 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 212:
#line 691 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->reg_num = (yyvsp[0].i); (yyval.cond_node)->is_reg = TRUE;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 3539 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 213:
#line 697 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->value = (yyvsp[0].i); (yyval.cond_node)->is_reg = FALSE;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 3550 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 216:
#line 709 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 3556 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 217:
#line 710 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 3562 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 220:
#line 717 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 3568 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 221:
#line 718 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_masked_to_buffer((yyvsp[0].i), 0x00); }
#line 3574 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 222:
#line 719 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 3580 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 223:
#line 722 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3586 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 224:
#line 723 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (monitor_cpu_for_memspace[reg_memspace((yyvsp[0].i))]->mon_register_get_val)(reg_memspace((yyvsp[0].i)), reg_regid((yyvsp[0].i))); }
#line 3592 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 225:
#line 726 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3598 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 226:
#line 727 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3604 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 227:
#line 728 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3610 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 228:
#line 729 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3616 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 229:
#line 732 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(B_NUMBER,(yyvsp[0].str)); }
#line 3622 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 230:
#line 733 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(O_NUMBER,(yyvsp[0].str)); }
#line 3628 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 231:
#line 734 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(D_NUMBER,(yyvsp[0].str)); }
#line 3634 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 232:
#line 737 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3640 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 233:
#line 738 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3646 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 234:
#line 739 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3652 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 235:
#line 740 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3658 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 236:
#line 741 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3664 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 240:
#line 749 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0;
                                                if ((yyvsp[-1].str)) {
                                                    (monitor_cpu_for_memspace[default_memspace]->mon_assemble_instr)((yyvsp[-1].str), (yyvsp[0].mode));
                                                } else {
                                                    new_cmd = 1;
                                                    asm_mode = 0;
                                                }
                                                opt_asm = 0;
                                              }
#line 3678 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 242:
#line 760 "mon_parse.y" /* yacc.c:1646  */
    { asm_mode = 0; }
#line 3684 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 243:
#line 763 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].i) > 0xff) {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE_16;
                          (yyval.mode).param = (yyvsp[0].i);
                        } else {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE;
                          (yyval.mode).param = (yyvsp[0].i);
                        } }
#line 3696 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 244:
#line 770 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].i) < 0x100) {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE;
               (yyval.mode).param = (yyvsp[0].i);
             } else {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE;
               (yyval.mode).param = (yyvsp[0].i);
             }
           }
#line 3709 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 245:
#line 778 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 3722 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 246:
#line 786 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 3735 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 247:
#line 794 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_DOUBLE;
                            (yyval.mode).param = (yyvsp[0].i);
                            (yyval.mode).addr_submode = (yyvsp[-2].i);
                          }
                        }
#line 3746 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 248:
#line 800 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].i) < 0x100) {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             } else {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             }
                           }
#line 3759 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 249:
#line 808 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-3].i) < 0x100) {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         } else {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         }
                                       }
#line 3772 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 250:
#line 817 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_Y; (yyval.mode).param = (yyvsp[-3].i); }
#line 3778 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 251:
#line 818 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_BC; }
#line 3784 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 252:
#line 819 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_DE; }
#line 3790 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 253:
#line 820 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_HL; }
#line 3796 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 254:
#line 821 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IX; }
#line 3802 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 255:
#line 822 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IY; }
#line 3808 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 256:
#line 823 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_SP; }
#line 3814 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 257:
#line 825 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_A; (yyval.mode).param = (yyvsp[-3].i); }
#line 3820 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 258:
#line 827 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_HL; (yyval.mode).param = (yyvsp[-3].i); }
#line 3826 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 259:
#line 829 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IX; (yyval.mode).param = (yyvsp[-3].i); }
#line 3832 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 260:
#line 831 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IY; (yyval.mode).param = (yyvsp[-3].i); }
#line 3838 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 261:
#line 832 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_IMPLIED; }
#line 3844 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 262:
#line 833 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ACCUMULATOR; }
#line 3850 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 263:
#line 834 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_B; }
#line 3856 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 264:
#line 835 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_C; }
#line 3862 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 265:
#line 836 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_D; }
#line 3868 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 266:
#line 837 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_E; }
#line 3874 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 267:
#line 838 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_H; }
#line 3880 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 268:
#line 839 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXH; }
#line 3886 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 269:
#line 840 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYH; }
#line 3892 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 270:
#line 841 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_L; }
#line 3898 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 271:
#line 842 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXL; }
#line 3904 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 272:
#line 843 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYL; }
#line 3910 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 273:
#line 844 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_AF; }
#line 3916 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 274:
#line 845 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_BC; }
#line 3922 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 275:
#line 846 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_DE; }
#line 3928 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 276:
#line 847 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_HL; }
#line 3934 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 277:
#line 848 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IX; }
#line 3940 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 278:
#line 849 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IY; }
#line 3946 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 279:
#line 850 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_SP; }
#line 3952 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 280:
#line 852 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_DIRECT; (yyval.mode).param = (yyvsp[0].i); }
#line 3958 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 281:
#line 853 "mon_parse.y" /* yacc.c:1646  */
    {    /* Clash with addr,x addr,y modes! */
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-2].i) >= -16 && (yyvsp[-2].i) < 16) {
            (yyval.mode).addr_submode = (yyvsp[0].i) | ((yyvsp[-2].i) & 0x1F);
        } else if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-2].i);
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-2].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 3978 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 282:
#line 868 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 3987 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 283:
#line 872 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 3996 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 284:
#line 876 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4005 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 285:
#line 880 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4014 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 286:
#line 884 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4023 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 287:
#line 888 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4032 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 288:
#line 892 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4041 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 289:
#line 896 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4050 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 290:
#line 900 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-2].i);
        if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8;
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4067 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 291:
#line 912 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-3].i) >= -16 && (yyvsp[-3].i) < 16) {
            (yyval.mode).addr_submode = (yyvsp[-3].i) & 0x1F;
        } else if ((yyvsp[-4].i) >= -128 && (yyvsp[-4].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-3].i);
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-3].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4087 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 292:
#line 927 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 4096 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 293:
#line 931 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-3].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 4105 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 294:
#line 935 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4114 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 295:
#line 939 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4123 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 296:
#line 943 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4132 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 297:
#line 947 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4141 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 298:
#line 951 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4150 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 299:
#line 955 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4159 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 300:
#line 959 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-3].i);
        if ((yyvsp[-3].i) >= -128 && (yyvsp[-3].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8_IND;
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16_IND;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4176 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 301:
#line 971 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | ASM_ADDR_MODE_EXTENDED_INDIRECT;
        (yyval.mode).param = (yyvsp[-1].i);
        }
#line 4186 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 302:
#line 980 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (0 << 5); printf("reg_x\n"); }
#line 4192 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 303:
#line 981 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (1 << 5); printf("reg_y\n"); }
#line 4198 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 304:
#line 982 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 4204 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 305:
#line 986 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (2 << 5); printf("reg_u\n"); }
#line 4210 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;

  case 306:
#line 987 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (3 << 5); printf("reg_s\n"); }
#line 4216 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
    break;


#line 4220 "/home/chris/src/the64-firmware/src/vice2/src/monitor/mon_parse.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 991 "mon_parse.y" /* yacc.c:1906  */


void parse_and_execute_line(char *input)
{
   char *temp_buf;
   int i, rc;

   temp_buf = lib_malloc(strlen(input) + 3);
   strcpy(temp_buf,input);
   i = (int)strlen(input);
   temp_buf[i++] = '\n';
   temp_buf[i++] = '\0';
   temp_buf[i++] = '\0';

   make_buffer(temp_buf);
   if ( (rc =yyparse()) != 0) {
       mon_out("ERROR -- ");
       switch(rc) {
         case ERR_BAD_CMD:
           mon_out("Bad command:\n");
           break;
         case ERR_RANGE_BAD_START:
           mon_out("Bad first address in range:\n");
           break;
         case ERR_RANGE_BAD_END:
           mon_out("Bad second address in range:\n");
           break;
         case ERR_EXPECT_CHECKNUM:
           mon_out("Checkpoint number expected:\n");
           break;
         case ERR_EXPECT_END_CMD:
           mon_out("Unexpected token:\n");
           break;
         case ERR_MISSING_CLOSE_PAREN:
           mon_out("')' expected:\n");
           break;
         case ERR_INCOMPLETE_COMPARE_OP:
           mon_out("Compare operation missing an operand:\n");
           break;
         case ERR_EXPECT_FILENAME:
           mon_out("Expecting a filename:\n");
           break;
         case ERR_ADDR_TOO_BIG:
           mon_out("Address too large:\n");
           break;
         case ERR_IMM_TOO_BIG:
           mon_out("Immediate argument too large:\n");
           break;
         case ERR_EXPECT_STRING:
           mon_out("Expecting a string.\n");
           break;
         case ERR_UNDEFINED_LABEL:
           mon_out("Found an undefined label.\n");
           break;
         case ERR_EXPECT_DEVICE_NUM:
           mon_out("Expecting a device number.\n");
           break;
         case ERR_EXPECT_ADDRESS:
           mon_out("Expecting an address.\n");
           break;
         case ERR_ILLEGAL_INPUT:
         default:
           mon_out("Wrong syntax:\n");
       }
       mon_out("  %s\n", input);
       for (i = 0; i < last_len; i++)
           mon_out(" ");
       mon_out("  ^\n");
       asm_mode = 0;
       new_cmd = 1;
   }
   lib_free(temp_buf);
   free_buffer();
}

static int yyerror(char *s)
{
   fprintf(stderr, "ERR:%s\n", s);
   return 0;
}

static int resolve_datatype(unsigned guess_type, const char *num)
{
   /* FIXME: Handle cases when default type is non-numerical */
   if (default_radix == e_hexadecimal) {
       return strtol(num, NULL, 16);
   }

   if ((guess_type == D_NUMBER) || (default_radix == e_decimal)) {
       return strtol(num, NULL, 10);
   }

   if ((guess_type == O_NUMBER) || (default_radix == e_octal)) {
       return strtol(num, NULL, 8);
   }

   return strtol(num, NULL, 2);
}

/*
 * Resolve a character sequence containing 8 hex digits like "08001000".
 * This could be a lazy version of "0800 1000". If the default radix is not
 * hexadecimal, we handle it like a ordinary number, in the latter case there
 * is only one number in the range.
 */
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num)
{
    char start[5];
    char end[5];
    long sa;

    range[1] = BAD_ADDR;

    switch (default_radix)
    {
    case e_hexadecimal:
        /* checked twice, but as the code must have exactly 8 digits: */
        if (strlen(num) == 8) {
            memcpy(start, num, 4);
            start[4] = '\0';
            memcpy(end, num + 4, 4);
            end[4] = '\0';
            sa = strtol(start, NULL, 16);
            range[1] = new_addr(memspace, strtol(end, NULL, 16));
        }
        else
            sa = strtol(num, NULL, 16);
        break;

    case e_decimal:
       sa = strtol(num, NULL, 10);
       break;

    case e_octal:
       sa = strtol(num, NULL, 8);
       break;

    default:
       sa = strtol(num, NULL, 2);
    }

    if (!CHECK_ADDR(sa))
        return ERR_ADDR_TOO_BIG;

    range[0] = new_addr(memspace, sa);
    return 0;
}


