/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    FOR = 260,
    WHILE = 261,
    IF = 262,
    ELSE = 263,
    SWITCH = 264,
    CASE = 265,
    DEFAULT = 266,
    IDENTIFICATEUR = 267,
    CONSTANTE = 268,
    BREAK = 269,
    RETURN = 270,
    PLUS = 271,
    MOINS = 272,
    MUL = 273,
    DIV = 274,
    LSHIFT = 275,
    RSHIFT = 276,
    BAND = 277,
    BOR = 278,
    LAND = 279,
    LOR = 280,
    LT = 281,
    GT = 282,
    GEQ = 283,
    LEQ = 284,
    EQ = 285,
    NEQ = 286,
    NOT = 287,
    EXTERN = 288,
    THEN = 289,
    OP = 290,
    REL = 291
  };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FOR 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define SWITCH 264
#define CASE 265
#define DEFAULT 266
#define IDENTIFICATEUR 267
#define CONSTANTE 268
#define BREAK 269
#define RETURN 270
#define PLUS 271
#define MOINS 272
#define MUL 273
#define DIV 274
#define LSHIFT 275
#define RSHIFT 276
#define BAND 277
#define BOR 278
#define LAND 279
#define LOR 280
#define LT 281
#define GT 282
#define GEQ 283
#define LEQ 284
#define EQ 285
#define NEQ 286
#define NOT 287
#define EXTERN 288
#define THEN 289
#define OP 290
#define REL 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "./miniC.y" /* yacc.c:1909  */

    char* chaine; 
    int valnum;

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
