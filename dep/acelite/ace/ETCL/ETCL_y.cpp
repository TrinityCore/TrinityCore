
/*  A Bison parser, made from ETCL/ETCL.yy
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define  ETCL_GT  257
#define  ETCL_GE  258
#define  ETCL_LT  259
#define  ETCL_LE  260
#define  ETCL_EQ  261
#define  ETCL_NE  262
#define  ETCL_EXIST 263
#define  ETCL_DEFAULT 264
#define  ETCL_AND 265
#define  ETCL_OR  266
#define  ETCL_NOT 267
#define  ETCL_IN  268
#define  ETCL_TWIDDLE 269
#define  ETCL_BOOLEAN 270
#define  ETCL_PLUS  271
#define  ETCL_MINUS 272
#define  ETCL_MULT  273
#define  ETCL_DIV 274
#define  ETCL_UMINUS  275
#define  ETCL_INTEGER 276
#define  ETCL_FLOAT 277
#define  ETCL_STRING  278
#define  ETCL_RPAREN  279
#define  ETCL_LPAREN  280
#define  ETCL_RBRA  281
#define  ETCL_LBRA  282
#define  ETCL_IDENT 283
#define  ETCL_UNSIGNED  284
#define  ETCL_SIGNED  285
#define  ETCL_DOUBLE  286
#define  ETCL_CONSTRAINT  287
#define  ETCL_COMPONENT 288
#define  ETCL_WITH  289
#define  ETCL_MAX 290
#define  ETCL_MIN 291
#define  ETCL_FIRST 292
#define  ETCL_RANDOM  293
#define  ETCL_DOLLAR  294
#define  ETCL_DOT 295
#define  ETCL_DISCRIMINANT  296
#define  ETCL_LENGTH  297
#define  ETCL_TYPE_ID 298
#define  ETCL_REPOS_ID  299


//=============================================================================
/**
 *  @file   ETCL_y.cpp
 *
 *  $Id: ETCL_y.cpp 93651 2011-03-28 08:49:11Z johnnyw $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu> based on previous work by Seth Widoff <sbw1@cs.wustl.edu>
 */
//=============================================================================


#include "ace/ETCL/ETCL_y.h"
#include "ace/ETCL/ETCL_Constraint.h"
#include "ace/ETCL/ETCL_Interpreter.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

extern int yylex (void);
extern void yyflush_current_buffer (void);

static void yyerror (const char *)
{
  // @@ TODO
  // Ignore error messages
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include <stdio.h>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define  YYFINAL    114
#define  YYFLAG   -32768
#define  YYNTBASE 46

#define YYTRANSLATE(x) ((unsigned)(x) <= 299 ? yytranslate[x] : 65)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,    10,    13,    15,    17,    21,    23,
    27,    29,    33,    37,    41,    45,    49,    53,    55,    59,
    64,    66,    70,    72,    76,    80,    82,    86,    90,    92,
    95,    97,   101,   103,   106,   109,   111,   114,   117,   119,
   121,   124,   128,   132,   135,   137,   138,   141,   144,   146,
   148,   149,   152,   154,   156,   159,   161,   163,   165,   167,
   169,   171,   176,   181,   184,   189,   190,   192,   195,   198
};

static const short yyrhs[] = {    48,
     0,    47,     0,    37,    48,     0,    36,    48,     0,    35,
    48,     0,    38,     0,    39,     0,    48,    12,    49,     0,
    49,     0,    49,    11,    50,     0,    50,     0,    51,     7,
    51,     0,    51,     8,    51,     0,    51,     3,    51,     0,
    51,     4,    51,     0,    51,     5,    51,     0,    51,     6,
    51,     0,    51,     0,    52,    14,    57,     0,    52,    14,
    40,    57,     0,    52,     0,    53,    15,    53,     0,    53,
     0,    53,    17,    54,     0,    53,    18,    54,     0,    54,
     0,    54,    19,    55,     0,    54,    20,    55,     0,    55,
     0,    13,    56,     0,    56,     0,    26,    48,    25,     0,
    22,     0,    17,    22,     0,    18,    22,     0,    23,     0,
    17,    23,     0,    18,    23,     0,    24,     0,    16,     0,
     9,    29,     0,     9,    40,    57,     0,    10,    40,    57,
     0,    40,    57,     0,    29,     0,     0,    41,    59,     0,
    29,    58,     0,    60,     0,    61,     0,     0,    41,    59,
     0,    60,     0,    61,     0,    29,    58,     0,    43,     0,
    42,     0,    44,     0,    45,     0,    62,     0,    63,     0,
    28,    22,    27,    58,     0,    26,    29,    25,    58,     0,
    22,    58,     0,    26,    64,    25,    58,     0,     0,    22,
     0,    17,    22,     0,    18,    22,     0,    24,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    92,    93,    96,    98,   100,   102,   104,   108,   110,   113,
   115,   118,   120,   122,   124,   126,   128,   130,   133,   135,
   137,   140,   142,   145,   147,   149,   152,   154,   156,   159,
   161,   164,   166,   168,   170,   172,   174,   176,   178,   180,
   182,   184,   186,   188,   190,   194,   196,   199,   202,   203,
   206,   208,   211,   212,   215,   217,   219,   221,   223,   225,
   226,   229,   233,   237,   241,   245,   247,   249,   251,   253
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ETCL_GT",
"ETCL_GE","ETCL_LT","ETCL_LE","ETCL_EQ","ETCL_NE","ETCL_EXIST",
"ETCL_DEFAULT","ETCL_AND","ETCL_OR","ETCL_NOT","ETCL_IN",
"ETCL_TWIDDLE","ETCL_BOOLEAN","ETCL_PLUS","ETCL_MINUS","ETCL_MULT",
"ETCL_DIV","ETCL_UMINUS","ETCL_INTEGER","ETCL_FLOAT","ETCL_STRING",
"ETCL_RPAREN","ETCL_LPAREN","ETCL_RBRA","ETCL_LBRA","ETCL_IDENT",
"ETCL_UNSIGNED","ETCL_SIGNED","ETCL_DOUBLE","ETCL_CONSTRAINT",
"ETCL_COMPONENT","ETCL_WITH","ETCL_MAX","ETCL_MIN","ETCL_FIRST",
"ETCL_RANDOM","ETCL_DOLLAR","ETCL_DOT","ETCL_DISCRIMINANT","ETCL_LENGTH",
"ETCL_TYPE_ID","ETCL_REPOS_ID","constraint","preference","bool_or","bool_and",
"bool_compare","expr_in","expr_twiddle","expr","term","factor_not","factor",
"component","component_ext","component_dot","component_array","component_assoc",
"component_pos","union_pos","union_val", 0
};
#endif

static const short yyr1[] = {     0,
    46,    46,    47,    47,    47,    47,    47,    48,    48,    49,
    49,    50,    50,    50,    50,    50,    50,    50,    51,    51,
    51,    52,    52,    53,    53,    53,    54,    54,    54,    55,
    55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
    56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
    58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
    59,    60,    61,    62,    63,    64,    64,    64,    64,    64
};

static const short yyr2[] = {     0,
     1,     1,     2,     2,     2,     1,     1,     3,     1,     3,
     1,     3,     3,     3,     3,     3,     3,     1,     3,     4,
     1,     3,     1,     3,     3,     1,     3,     3,     1,     2,
     1,     3,     1,     2,     2,     1,     2,     2,     1,     1,
     2,     3,     3,     2,     1,     0,     2,     2,     1,     1,
     0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     4,     4,     2,     4,     0,     1,     2,     2,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,    40,     0,     0,    33,    36,    39,     0,
    45,     0,     0,     0,     6,     7,    46,     2,     1,     9,
    11,    18,    21,    23,    26,    29,    31,    41,    46,    46,
    30,    34,    37,    35,    38,     0,     5,     4,     3,     0,
     0,    51,     0,    44,    49,    50,     0,     0,     0,     0,
     0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
    42,    43,    32,     0,     0,     0,    48,    53,    54,    51,
    66,    51,    57,    56,    58,    59,    47,    60,    61,     8,
    10,    14,    15,    16,    17,    12,    13,    46,    19,    22,
    24,    25,    27,    28,    51,    51,    52,    64,     0,     0,
    67,    70,     0,    55,    20,    63,    62,    68,    69,    51,
    65,     0,     0,     0
};

static const short yydefgoto[] = {   112,
    18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    44,    67,    77,    68,    69,    78,    79,   103
};

static const short yypact[] = {    41,
   -13,   -39,    94,-32768,    38,    46,-32768,-32768,-32768,    73,
-32768,    73,    73,    73,-32768,-32768,    -9,-32768,    -6,     7,
-32768,   121,    -5,    19,    55,-32768,-32768,-32768,    -9,    -9,
-32768,-32768,-32768,-32768,-32768,    21,    -6,    -6,    -6,     6,
    25,    -2,    -1,-32768,-32768,-32768,    73,    73,    73,    73,
    73,    73,    73,    73,   -18,    73,    73,    73,    73,    73,
-32768,-32768,-32768,    27,    29,    -1,-32768,-32768,-32768,    -2,
    31,    -2,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     7,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -9,-32768,    67,
    55,    55,-32768,-32768,    -2,    -2,-32768,-32768,    44,    50,
-32768,-32768,    69,-32768,-32768,-32768,-32768,-32768,-32768,    -2,
-32768,    98,   100,-32768
};

static const short yypgoto[] = {-32768,
-32768,    95,    54,    58,    86,-32768,    59,    30,    33,   111,
   -26,   -65,    53,   -17,   -15,-32768,-32768,-32768
};


#define  YYLAST   140


static const short yytable[] = {    45,
    30,    46,    61,    62,    98,    47,   104,    40,    55,    41,
    42,    45,    45,    46,    46,    28,    40,    48,    41,    42,
    70,    88,    43,    40,    71,    41,    29,    72,    89,   106,
   107,    43,    47,    56,    64,    57,    58,    45,    66,    46,
    73,    74,    75,    76,   111,    63,    65,    99,   100,     1,
     2,    95,   101,     3,   102,    96,     4,     5,     6,    32,
    33,   105,     7,     8,     9,   108,    10,    34,    35,    11,
    45,   109,    46,    59,    60,    12,    13,    14,    15,    16,
    17,     1,     2,    57,    58,     3,    91,    92,     4,     5,
     6,    93,    94,   110,     7,     8,     9,   113,    10,   114,
    80,    11,     1,     2,    36,    81,    37,    38,    39,     4,
     5,     6,    17,    31,    90,     7,     8,     9,    97,    10,
     0,     0,    11,    49,    50,    51,    52,    53,    54,     0,
     0,     0,     0,    17,    82,    83,    84,    85,    86,    87
};

static const short yycheck[] = {    17,
    40,    17,    29,    30,    70,    12,    72,    26,    14,    28,
    29,    29,    30,    29,    30,    29,    26,    11,    28,    29,
    22,    40,    41,    26,    26,    28,    40,    29,    55,    95,
    96,    41,    12,    15,    29,    17,    18,    55,    41,    55,
    42,    43,    44,    45,   110,    25,    22,    17,    18,     9,
    10,    25,    22,    13,    24,    27,    16,    17,    18,    22,
    23,    88,    22,    23,    24,    22,    26,    22,    23,    29,
    88,    22,    88,    19,    20,    35,    36,    37,    38,    39,
    40,     9,    10,    17,    18,    13,    57,    58,    16,    17,
    18,    59,    60,    25,    22,    23,    24,     0,    26,     0,
    47,    29,     9,    10,    10,    48,    12,    13,    14,    16,
    17,    18,    40,     3,    56,    22,    23,    24,    66,    26,
    -1,    -1,    29,     3,     4,     5,     6,     7,     8,    -1,
    -1,    -1,    -1,    40,    49,    50,    51,    52,    53,    54
};
/* -*-C-*-  Note some compilers choke on comments on `//#line' lines.  */
//#line 3 "/pkg/gnu/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

ACE_END_VERSIONED_NAMESPACE_DECL

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
   instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
     and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok   (yyerrstatus = 0)
#define yyclearin  (yychar = YYEMPTY)
#define YYEMPTY   -2
#define YYEOF   0
#define YYACCEPT  goto yyacceptlab
#define YYABORT   goto yyabortlab
#define YYERROR   goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL    goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                \
  if (yychar == YYEMPTY && yylen == 1)        \
    { yychar = (token), yylval = (value);     \
      yychar1 = YYTRANSLATE (yychar);       \
      YYPOPSTACK;           \
      goto yybackup;            \
    }               \
  else                \
    { yyerror ("syntax error: cannot back up"); YYERROR; }  \
while (0)

#define YYTERROR  1
#define YYERRCODE  256

#ifndef YYPURE
#define YYLEX   yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX   yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX   yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX   yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX   yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int  yychar;      /*  the lookahead symbol    */
YYSTYPE  yylval;      /*  the semantic value of the   */
        /*  lookahead symbol      */
YYSTYPE yyval;    /*  the variable used to return   */
        /*  semantic values from the action */
        /*  routines        */


#ifdef YYLSP_NEEDED
YYLTYPE yylloc;     /*  location data for the lookahead */
        /*  symbol        */
#endif

int yynerrs;      /*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;      /*  nonzero means print parse trace */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks  */

#ifndef  YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1    /* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)  __builtin_memcpy(TO,FROM,COUNT)
#else       /* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

//#line 217 "/pkg/gnu/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;  /*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;    /*  lookahead token as an internal (translated) token number */

  short  yyssa[YYINITDEPTH];  /*  the state stack     */
  YYSTYPE yyvsa[YYINITDEPTH];  /*  the semantic value stack   */

  short *yyss = yyssa;    /*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;  /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];  /*  the location stack     */
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    ACE_OS::fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;   /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
   the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
   but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
     &yyss1, size * sizeof (*yyssp),
     &yyvs1, size * sizeof (*yyvsp),
     &yyls1, size * sizeof (*yylsp),
     &yystacksize);
#else
      yyoverflow("parser stack overflow",
     &yyss1, size * sizeof (*yyssp),
     &yyvs1, size * sizeof (*yyvsp),
     &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
  {
    yyerror("parser stack overflow");
    if (yyfree_stacks)
      {
        ACE_OS::free (yyss);
        ACE_OS::free (yyvs);
#ifdef YYLSP_NEEDED
        ACE_OS::free (yyls);
#endif
      }
    return 2;
  }
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
  yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
       size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
       size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
       size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
        ACE_OS::fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
  YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    ACE_OS::fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
        ACE_OS::fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)    /* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;   /* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
        ACE_OS::fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
  {
    ACE_OS::fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
    /* Give the individual parser a way to print the precise meaning
       of a token, for further debugging info.  */
#ifdef YYPRINT
    YYPRINT (stderr, yychar, yylval);
#endif
    ACE_OS::fprintf (stderr, ")\n");
  }
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
  goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    ACE_OS::fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      ACE_OS::fprintf (stderr, "Reducing via rule %d (line %d), ",
                       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
        ACE_OS::fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      ACE_OS::fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
//#line 97 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Preference (ETCL_MIN, yyvsp[0].constraint); ;
    break;}
case 4:
//#line 99 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Preference (ETCL_MAX, yyvsp[0].constraint); ;
    break;}
case 5:
//#line 101 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Preference (ETCL_WITH, yyvsp[0].constraint); ;
    break;}
case 6:
//#line 103 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Preference (ETCL_FIRST); ;
    break;}
case 7:
//#line 105 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Preference (ETCL_RANDOM); ;
    break;}
case 8:
//#line 109 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_OR, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 10:
//#line 114 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_AND, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 12:
//#line 119 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_EQ, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 13:
//#line 121 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_NE, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 14:
//#line 123 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_GT, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 15:
//#line 125 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_GE, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 16:
//#line 127 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_LT, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 17:
//#line 129 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_LE, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 19:
//#line 134 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_IN, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 20:
//#line 136 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_IN, yyvsp[-3].constraint, yyvsp[0].constraint); ;
    break;}
case 22:
//#line 141 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_TWIDDLE, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 24:
//#line 146 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_PLUS, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 25:
//#line 148 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_MINUS, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 27:
//#line 153 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_MULT, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 28:
//#line 155 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Binary_Expr (ETCL_DIV, yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 30:
//#line 160 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Unary_Expr (ETCL_NOT, yyvsp[0].constraint); ;
    break;}
case 32:
//#line 165 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[-1].constraint; ;
    break;}
case 33:
//#line 167 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[0].constraint; ;
    break;}
case 34:
//#line 169 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Unary_Expr (ETCL_PLUS, yyvsp[0].constraint); ;
    break;}
case 35:
//#line 171 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Unary_Expr (ETCL_MINUS, yyvsp[0].constraint); ;
    break;}
case 36:
//#line 173 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[0].constraint; ;
    break;}
case 37:
//#line 175 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Unary_Expr (ETCL_PLUS, yyvsp[0].constraint); ;
    break;}
case 38:
//#line 177 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Unary_Expr (ETCL_MINUS, yyvsp[0].constraint); ;
    break;}
case 39:
//#line 179 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[0].constraint; ;
    break;}
case 40:
//#line 181 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[0].constraint; ;
    break;}
case 41:
//#line 183 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Exist (yyvsp[0].constraint); ;
    break;}
case 42:
//#line 185 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Exist (yyvsp[0].constraint); ;
    break;}
case 43:
//#line 187 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Default (yyvsp[0].constraint); ;
    break;}
case 44:
//#line 189 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Eval (yyvsp[0].constraint); ;
    break;}
case 45:
//#line 191 "ETCL/ETCL.yy"
{ yyval.constraint = yyvsp[0].constraint; ;
    break;}
case 46:
//#line 195 "ETCL/ETCL.yy"
{ yyval.constraint = 0; ;
    break;}
case 47:
//#line 197 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Dot (yyvsp[0].constraint); ;
    break;}
case 48:
//#line 200 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Component (yyvsp[-1].constraint, yyvsp[0].constraint); ;
    break;}
case 51:
//#line 207 "ETCL/ETCL.yy"
{ yyval.constraint = 0; ;
    break;}
case 52:
//#line 209 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Dot (yyvsp[0].constraint); ;
    break;}
case 55:
//#line 216 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Component (yyvsp[-1].constraint, yyvsp[0].constraint); ;
    break;}
case 56:
//#line 218 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Special (ETCL_LENGTH); ;
    break;}
case 57:
//#line 220 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Special (ETCL_DISCRIMINANT); ;
    break;}
case 58:
//#line 222 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Special (ETCL_TYPE_ID); ;
    break;}
case 59:
//#line 224 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Special (ETCL_REPOS_ID); ;
    break;}
case 62:
//#line 230 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Component_Array (yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 63:
//#line 234 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Component_Assoc (yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 64:
//#line 238 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Component_Pos (yyvsp[-1].constraint, yyvsp[0].constraint); ;
    break;}
case 65:
//#line 242 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Union_Pos (yyvsp[-2].constraint, yyvsp[0].constraint); ;
    break;}
case 66:
//#line 246 "ETCL/ETCL.yy"
{ yyval.constraint = 0; ;
    break;}
case 67:
//#line 248 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Union_Value (+1, yyvsp[0].constraint); ;
    break;}
case 68:
//#line 250 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Union_Value (+1, yyvsp[0].constraint); ;
    break;}
case 69:
//#line 252 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Union_Value (-1, yyvsp[0].constraint); ;
    break;}
case 70:
//#line 254 "ETCL/ETCL.yy"
{ yyval.constraint = new ETCL_Union_Value (yyvsp[0].constraint); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
//#line 543 "/pkg/gnu/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      ACE_OS::fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
        ACE_OS::fprintf (stderr, " %d", *++ssp1);
      ACE_OS::fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
  {
    int size = 0;
    char *msg;
    int x, count;

    count = 0;
    /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
    for (x = (yyn < 0 ? -yyn : 0);
         x < (sizeof(yytname) / sizeof(char *)); x++)
      if (yycheck[x + yyn] == x)
        size += ACE_OS::strlen(yytname[x]) + 15, count++;
    msg = (char *) ACE_OS::malloc(size + 15);
    if (msg != 0)
      {
        ACE_OS::strcpy(msg, "parse error");

        if (count < 5)
    {
      count = 0;
      for (x = (yyn < 0 ? -yyn : 0);
           x < (sizeof(yytname) / sizeof(char *)); x++)
        if (yycheck[x + yyn] == x)
          {
            ACE_OS::strcat(msg, count == 0 ? ", expecting `" : " or `");
            ACE_OS::strcat(msg, yytname[x]);
            ACE_OS::strcat(msg, "'");
            count++;
          }
    }
        yyerror(msg);
        ACE_OS::free(msg);
      }
    else
      yyerror ("parse error; also virtual memory exceeded");
  }
      else
#endif /* YYERROR_VERBOSE */
  yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
  YYABORT;

#if YYDEBUG != 0
      if (yydebug)
        ACE_OS::fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;    /* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      ACE_OS::fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
        ACE_OS::fprintf (stderr, " %d", *++ssp1);
      ACE_OS::fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
  goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    ACE_OS::fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      ACE_OS::free (yyss);
      ACE_OS::free (yyvs);
#ifdef YYLSP_NEEDED
      ACE_OS::free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */

  /* Flush out yy_current_buffer before next parse.  Since there is
     no error recovery, the buffer could still contain tokens from this
     parse. */
  yyflush_current_buffer();

  if (yyfree_stacks)
    {
      ACE_OS::free (yyss);
      ACE_OS::free (yyvs);
#ifdef YYLSP_NEEDED
      ACE_OS::free (yyls);
#endif
    }
  return 1;
}
//#line 257 "ETCL/ETCL.yy"

ACE_END_VERSIONED_NAMESPACE_DECL
