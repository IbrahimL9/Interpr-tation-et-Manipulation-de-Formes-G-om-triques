// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 29 "parser/parser.yy"

    #include <iostream>
    #include <string>
    #include "scanner.hh"
    #include "driver.hh"
    #include <memory>
    #undef  yylex
    #define yylex scanner.yylex

#line 56 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 148 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.copy< Attributs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.copy< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.copy< std::shared_ptr<Forme> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_taille: // taille
        value.copy< std::shared_ptr<Taille> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.copy< std::vector<Attributs> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.copy< std::vector<int> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.move< Attributs > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.move< std::shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.move< std::shared_ptr<Forme> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_taille: // taille
        value.move< std::shared_ptr<Taille> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.move< std::vector<Attributs> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.move< std::vector<int> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.YY_MOVE_OR_COPY< Attributs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.YY_MOVE_OR_COPY< std::shared_ptr<Forme> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_taille: // taille
        value.YY_MOVE_OR_COPY< std::shared_ptr<Taille> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.YY_MOVE_OR_COPY< std::vector<Attributs> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.YY_MOVE_OR_COPY< std::vector<int> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.move< Attributs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.move< std::shared_ptr<Forme> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_taille: // taille
        value.move< std::shared_ptr<Taille> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.move< std::vector<Attributs> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.move< std::vector<int> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.copy< Attributs > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.copy< std::shared_ptr<Forme> > (that.value);
        break;

      case symbol_kind::S_taille: // taille
        value.copy< std::shared_ptr<Taille> > (that.value);
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.copy< std::vector<Attributs> > (that.value);
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.copy< std::vector<int> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.move< Attributs > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.move< std::shared_ptr<Forme> > (that.value);
        break;

      case symbol_kind::S_taille: // taille
        value.move< std::shared_ptr<Taille> > (that.value);
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.move< std::vector<Attributs> > (that.value);
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.move< std::vector<int> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        yylhs.value.emplace< Attributs > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        yylhs.value.emplace< std::shared_ptr<Forme> > ();
        break;

      case symbol_kind::S_taille: // taille
        yylhs.value.emplace< std::shared_ptr<Taille> > ();
        break;

      case symbol_kind::S_NOM_HEX: // NOM_HEX
      case symbol_kind::S_NOM_RGB: // NOM_RGB
      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_CHAINE: // CHAINE
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_fig: // fig
      case symbol_kind::S_critere: // critere
      case symbol_kind::S_color: // color
      case symbol_kind::S_coul: // coul
      case symbol_kind::S_SIGNE: // SIGNE
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        yylhs.value.emplace< std::vector<Attributs> > ();
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        yylhs.value.emplace< std::vector<int> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // programme: instruction programme
#line 87 "parser/parser.yy"
                          {
    }
#line 1032 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 3: // programme: NL programme
#line 89 "parser/parser.yy"
                 {}
#line 1038 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 4: // programme: $end
#line 90 "parser/parser.yy"
           {
           std::cout << "#-> " << driver.varAttToString() << std::endl;
           std::cout << "#-> " << driver.varSansAffectationToString() << std::endl;
           std::cout << "#-> " << driver.varIdbToString() << std::endl;
           std::cout << "#-> " << driver.couleur_toString() << std::endl;
           
        YYACCEPT;
    }
#line 1051 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 5: // instruction: expression
#line 100 "parser/parser.yy"
                {
    }
#line 1058 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 6: // instruction: affectation PV NL
#line 102 "parser/parser.yy"
                       {
    }
#line 1065 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 7: // instruction: variable NL
#line 104 "parser/parser.yy"
                 {
    }
#line 1072 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 8: // instruction: taille PV NL
#line 106 "parser/parser.yy"
                 {
        std::cout << "#-> " << yystack_[2].value.as < std::shared_ptr<Taille> > ()->tostring() << std::endl;
    }
#line 1080 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 9: // instruction: modif
#line 109 "parser/parser.yy"
          {}
#line 1086 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 10: // expression: ope
#line 112 "parser/parser.yy"
       { try{
        yystack_[0].value.as < std::shared_ptr<Expression> > ()->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    }
#line 1097 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 11: // taille: TAILLE NUMBER NUMBER
#line 120 "parser/parser.yy"
                         {
          yylhs.value.as < std::shared_ptr<Taille> > () = std::make_shared<Taille>(yystack_[1].value.as < int > (),yystack_[0].value.as < int > ());
    }
#line 1105 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 12: // figure: RECTANGLE NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER
#line 126 "parser/parser.yy"
                                                                       {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Rectangle>(yystack_[7].value.as < int > (),yystack_[6].value.as < int > (),yystack_[5].value.as < int > (),yystack_[4].value.as < int > (),yystack_[3].value.as < int > (),yystack_[2].value.as < int > (),yystack_[1].value.as < int > (),yystack_[0].value.as < int > ());
    }
#line 1113 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 13: // figure: CARRE NUMBER NUMBER NUMBER
#line 129 "parser/parser.yy"
                                  {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Carre>(yystack_[2].value.as < int > (),yystack_[1].value.as < int > (),yystack_[0].value.as < int > ());
    }
#line 1121 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 14: // figure: TRIANGLE NUMBER NUMBER NUMBER NUMBER
#line 132 "parser/parser.yy"
                                           {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Triangle>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > (), yystack_[0].value.as < int > ());
    }
#line 1129 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 15: // figure: CERCLE NUMBER NUMBER NUMBER
#line 135 "parser/parser.yy"
                                   {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Cercle>(yystack_[2].value.as < int > (), yystack_[1].value.as < int > (), yystack_[0].value.as < int > ());
    }
#line 1137 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 16: // figure: ELLIPSE NUMBER NUMBER NUMBER NUMBER
#line 138 "parser/parser.yy"
                                         {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Ellipse>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > (), yystack_[0].value.as < int > ());
    }
#line 1145 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 17: // figure: LIGNE NUMBER NUMBER NUMBER NUMBER
#line 141 "parser/parser.yy"
                                        {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Ligne>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > (), yystack_[0].value.as < int > ());
    }
#line 1153 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 18: // figure: CHEMIN coordonnees
#line 144 "parser/parser.yy"
                         {
        if (yystack_[0].value.as < std::vector<int> > ().size() % 2 == 0) { 
            std::vector<std::pair<int, int>> points;
            for (unsigned int i = 0; i < yystack_[0].value.as < std::vector<int> > ().size(); i += 2) {
                points.push_back(std::make_pair(yystack_[0].value.as < std::vector<int> > ().at(i), yystack_[0].value.as < std::vector<int> > ().at(i + 1)));
            }
            yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Chemin>(points);
        } else {
            std::cerr << "Erreur : Nombre impair de coordonnées pour un chemin." << std::endl;
        }
    }
#line 1169 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 19: // figure: TEXTE NUMBER NUMBER CHAINE CHAINE
#line 155 "parser/parser.yy"
                                        {
        yylhs.value.as < std::shared_ptr<Forme> > () = std::make_shared<Texte>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1177 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 20: // figure_att: figure FLECHE attributs liste_fleche PV
#line 162 "parser/parser.yy"
                                            {
         yystack_[4].value.as < std::shared_ptr<Forme> > ()->ajouterAttribut(yystack_[2].value.as < Attributs > ()) ;
        for(auto i : yystack_[1].value.as < std::vector<Attributs> > ()){
            yystack_[4].value.as < std::shared_ptr<Forme> > ()->ajouterAttribut(i) ;
        }
        yylhs.value.as < std::shared_ptr<Forme> > ()=yystack_[4].value.as < std::shared_ptr<Forme> > ();
    }
#line 1189 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 21: // figure_att: figure OUVRE_ACCOLADE NL attributs PV liste_acc FERME_ACCOLADE
#line 169 "parser/parser.yy"
                                                                      {
        yystack_[6].value.as < std::shared_ptr<Forme> > ()->ajouterAttribut(yystack_[3].value.as < Attributs > ()) ;
        for(auto i : yystack_[1].value.as < std::vector<Attributs> > ()){
            yystack_[6].value.as < std::shared_ptr<Forme> > ()->ajouterAttribut(i) ;
        }
                yylhs.value.as < std::shared_ptr<Forme> > ()=yystack_[6].value.as < std::shared_ptr<Forme> > ();
      }
#line 1201 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 22: // figure_att: figure PV
#line 176 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Forme> > () =yystack_[1].value.as < std::shared_ptr<Forme> > (); }
#line 1207 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 23: // liste_fleche: ET attributs liste_fleche
#line 179 "parser/parser.yy"
                              {
        yystack_[0].value.as < std::vector<Attributs> > ().push_back(yystack_[1].value.as < Attributs > ()); 
        yylhs.value.as < std::vector<Attributs> > () = yystack_[0].value.as < std::vector<Attributs> > ();
    }
#line 1216 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 24: // liste_fleche: %empty
#line 183 "parser/parser.yy"
      { yylhs.value.as < std::vector<Attributs> > () = std::vector<Attributs>(); }
#line 1222 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 25: // liste_acc: NL attributs PV NL liste_acc
#line 186 "parser/parser.yy"
                                    {
        yystack_[0].value.as < std::vector<Attributs> > ().push_back(yystack_[3].value.as < Attributs > ()); 
        yylhs.value.as < std::vector<Attributs> > () = yystack_[0].value.as < std::vector<Attributs> > ();
    }
#line 1231 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 26: // liste_acc: %empty
#line 190 "parser/parser.yy"
      { yylhs.value.as < std::vector<Attributs> > () = std::vector<Attributs>(); }
#line 1237 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 27: // coordonnees: NUMBER NUMBER
#line 195 "parser/parser.yy"
                    {
          yylhs.value.as < std::vector<int> > () = std::vector<int>{ yystack_[1].value.as < int > (), yystack_[0].value.as < int > () };
      }
#line 1245 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 28: // coordonnees: coordonnees V NUMBER NUMBER
#line 198 "parser/parser.yy"
                                    {
          yystack_[3].value.as < std::vector<int> > ().push_back(yystack_[1].value.as < int > ());
          yystack_[3].value.as < std::vector<int> > ().push_back(yystack_[0].value.as < int > ());
          yylhs.value.as < std::vector<int> > () = yystack_[3].value.as < std::vector<int> > ();
      }
#line 1255 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 29: // attributs: COULEUR DP color
#line 207 "parser/parser.yy"
                         {
            Attributs att; 
            att.couleur = std::make_shared<std::string>(yystack_[0].value.as < std::string > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1265 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 30: // attributs: ROTATION DP NUMBER
#line 212 "parser/parser.yy"
                            {
            Attributs att;
            att.rotation = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1275 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 31: // attributs: REMPLISSAGE DP color
#line 217 "parser/parser.yy"
                              {
            Attributs att;
            att.remplissage = std::make_shared<std::string>(yystack_[0].value.as < std::string > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1285 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 32: // attributs: OPACITE DP NUMBER
#line 222 "parser/parser.yy"
                           {
            Attributs att;
            att.opacite = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1295 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 33: // attributs: EPAISSEUR DP NUMBER
#line 227 "parser/parser.yy"
                             {
            Attributs att;
            att.epaisseur = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1305 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 34: // attributs_variable: COULEUR '=' color
#line 234 "parser/parser.yy"
                          {
            Attributs att; 
            att.couleur = std::make_shared<std::string>(yystack_[0].value.as < std::string > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1315 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 35: // attributs_variable: ROTATION '=' NUMBER
#line 239 "parser/parser.yy"
                             {
            Attributs att;
            att.rotation = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1325 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 36: // attributs_variable: REMPLISSAGE '=' color
#line 244 "parser/parser.yy"
                               {
            Attributs att;
            att.remplissage = std::make_shared<std::string>(yystack_[0].value.as < std::string > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1335 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 37: // attributs_variable: OPACITE '=' NUMBER
#line 249 "parser/parser.yy"
                             {
            Attributs att;
            att.opacite = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1345 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 38: // attributs_variable: EPAISSEUR '=' NUMBER
#line 254 "parser/parser.yy"
                              {
            Attributs att;
            att.epaisseur = std::make_shared<int>(yystack_[0].value.as < int > ());
            yylhs.value.as < Attributs > () = att;
        }
#line 1355 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 39: // variable: IDENT '=' figure_att
#line 263 "parser/parser.yy"
                         {
        driver.ajouterVariableForme(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::shared_ptr<Forme> > ());
        driver.ajouterVariableSansAffectation(yystack_[0].value.as < std::shared_ptr<Forme> > ());
    }
#line 1364 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 40: // variable: IDENT '.' attributs_variable PV
#line 267 "parser/parser.yy"
                                     {
        driver.ajouterAttributVariableForme(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Attributs > ());
    }
#line 1372 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 41: // variable: fig '[' NUMBER ']' '.' attributs_variable PV
#line 270 "parser/parser.yy"
                                                 {
        driver.ajouterAttribut(yystack_[6].value.as < std::string > (),yystack_[4].value.as < int > (),yystack_[1].value.as < Attributs > ());
    }
#line 1380 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 42: // variable: figure_att
#line 273 "parser/parser.yy"
               {
        driver.ajouterVariableSansAffectation(yystack_[0].value.as < std::shared_ptr<Forme> > ());
    }
#line 1388 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 43: // variable: fig '[' NUMBER ']' PV
#line 276 "parser/parser.yy"
                          {
       std::cout<< driver.afficher(yystack_[4].value.as < std::string > (),yystack_[2].value.as < int > ());
    }
#line 1396 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 44: // variable: ENT IDENT '=' NUMBER PV
#line 279 "parser/parser.yy"
                             {
        driver.ajouterIdb(yystack_[3].value.as < std::string > (), yystack_[1].value.as < int > ());
    }
#line 1404 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 45: // variable: REEL IDENT '=' DOUBLE PV
#line 282 "parser/parser.yy"
                               {
        driver.ajouterIdb(yystack_[3].value.as < std::string > (), yystack_[1].value.as < double > ());
    }
#line 1412 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 46: // variable: BOOLEEN IDENT '=' BOOL PV
#line 285 "parser/parser.yy"
                               {
        driver.ajouterIdb(yystack_[3].value.as < std::string > (), yystack_[1].value.as < bool > ());
    }
#line 1420 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 47: // variable: COULEUR IDENT '=' color PV
#line 288 "parser/parser.yy"
                                {
        driver.ajouterCouleur(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > ());
    }
#line 1428 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 48: // fig: RECTANGLE
#line 293 "parser/parser.yy"
          {
        yylhs.value.as < std::string > () ="rectangle";
    }
#line 1436 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 49: // fig: CARRE
#line 296 "parser/parser.yy"
           {
        yylhs.value.as < std::string > () ="carre" ;
    }
#line 1444 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 50: // fig: TRIANGLE
#line 299 "parser/parser.yy"
              {
        yylhs.value.as < std::string > () ="triangle" ;
    }
#line 1452 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 51: // fig: CERCLE
#line 302 "parser/parser.yy"
             {
        yylhs.value.as < std::string > () ="cercle";
    }
#line 1460 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 52: // fig: ELLIPSE
#line 305 "parser/parser.yy"
             {
        yylhs.value.as < std::string > () ="ellipse";
    }
#line 1468 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 53: // fig: LIGNE
#line 308 "parser/parser.yy"
           {
        yylhs.value.as < std::string > () = "ligne";
    }
#line 1476 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 54: // fig: CHEMIN
#line 311 "parser/parser.yy"
            {
            yylhs.value.as < std::string > () ="chemin"  ;
    }
#line 1484 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 55: // fig: TEXTE
#line 314 "parser/parser.yy"
           {
        yylhs.value.as < std::string > () ="texte";
    }
#line 1492 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 56: // critere: X1
#line 319 "parser/parser.yy"
     {
   yylhs.value.as < std::string > ()="X1";}
#line 1499 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 57: // critere: Y1
#line 321 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="Y1";}
#line 1506 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 58: // critere: X2
#line 323 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="X2";}
#line 1513 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 59: // critere: Y2
#line 325 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="Y2";}
#line 1520 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 60: // critere: X3
#line 327 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="X3";}
#line 1527 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 61: // critere: Y3
#line 329 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="Y3";}
#line 1534 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 62: // critere: X4
#line 331 "parser/parser.yy"
       {
   yylhs.value.as < std::string > ()="X4";}
#line 1541 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 63: // critere: Y4
#line 333 "parser/parser.yy"
      {
   yylhs.value.as < std::string > ()="Y4";}
#line 1548 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 64: // critere: TAILLE
#line 335 "parser/parser.yy"
          {
   yylhs.value.as < std::string > ()="taille";}
#line 1555 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 65: // critere: X
#line 337 "parser/parser.yy"
     {
   yylhs.value.as < std::string > ()="X";}
#line 1562 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 66: // critere: Y
#line 339 "parser/parser.yy"
     {
   yylhs.value.as < std::string > ()="Y";}
#line 1569 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 67: // critere: LARGEUR
#line 341 "parser/parser.yy"
           {
   yylhs.value.as < std::string > ()="largeur";}
#line 1576 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 68: // critere: HAUTEUR
#line 343 "parser/parser.yy"
           {
   yylhs.value.as < std::string > ()="hauteur";}
#line 1583 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 69: // critere: RAY
#line 345 "parser/parser.yy"
       {
   yylhs.value.as < std::string > ()="ray";}
#line 1590 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 70: // modif: fig '[' NUMBER ']' '.' critere '=' NUMBER
#line 351 "parser/parser.yy"
                                              {
        driver.appliquerModification(yystack_[7].value.as < std::string > (),yystack_[5].value.as < int > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < int > ());
    }
#line 1598 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 71: // modif: IDENT '.' critere '=' NUMBER
#line 354 "parser/parser.yy"
                                 {
            driver.appliquerModification(yystack_[4].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < int > ());
    }
#line 1606 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 72: // color: coul
#line 360 "parser/parser.yy"
         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1612 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 73: // color: NOM_HEX
#line 361 "parser/parser.yy"
              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1618 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 74: // color: NOM_RGB
#line 362 "parser/parser.yy"
              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1624 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 75: // coul: rouge
#line 366 "parser/parser.yy"
          { yylhs.value.as < std::string > () = "rouge"; }
#line 1630 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 76: // coul: vert
#line 367 "parser/parser.yy"
           { yylhs.value.as < std::string > () = "vert"; }
#line 1636 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 77: // coul: bleu
#line 368 "parser/parser.yy"
           { yylhs.value.as < std::string > () = "bleu"; }
#line 1642 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 78: // coul: jaune
#line 369 "parser/parser.yy"
            { yylhs.value.as < std::string > () = "jaune"; }
#line 1648 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 79: // coul: violet
#line 370 "parser/parser.yy"
             { yylhs.value.as < std::string > () = "violet"; }
#line 1654 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 80: // coul: magenta
#line 371 "parser/parser.yy"
              { yylhs.value.as < std::string > () = "magenta"; }
#line 1660 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 81: // coul: cyan
#line 372 "parser/parser.yy"
           { yylhs.value.as < std::string > () = "cyan"; }
#line 1666 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 82: // coul: noir
#line 373 "parser/parser.yy"
           { yylhs.value.as < std::string > () = "noir"; }
#line 1672 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 83: // coul: blanc
#line 374 "parser/parser.yy"
            { yylhs.value.as < std::string > () = "blanc"; }
#line 1678 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 84: // ope: SI comparaison ALORS OUVRE_ACCOLADE NL ope FERME_ACCOLADE NL suite
#line 378 "parser/parser.yy"
                                                                           {
       if(yystack_[3].value.as < std::shared_ptr<Expression> > ()!=nullptr){
       if(yystack_[0].value.as < std::shared_ptr<Expression> > ()==nullptr){
                yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ExpressionTernaire>(yystack_[7].value.as < bool > (),yystack_[3].value.as < std::shared_ptr<Expression> > (),yystack_[0].value.as < std::shared_ptr<Expression> > (),OperateurTernaire::ifthen);
        }
        else{
        yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ExpressionTernaire>(yystack_[7].value.as < bool > (),yystack_[3].value.as < std::shared_ptr<Expression> > (),yystack_[0].value.as < std::shared_ptr<Expression> > (),OperateurTernaire::ifthenelse);
        }}else yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ExpressionTernaire>(false,yystack_[3].value.as < std::shared_ptr<Expression> > (),yystack_[0].value.as < std::shared_ptr<Expression> > (),OperateurTernaire::ifthen);
    }
#line 1692 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 85: // ope: IDENT '.' attributs_variable PV NL
#line 387 "parser/parser.yy"
                                        {
    yylhs.value.as < std::shared_ptr<Expression> > ()= std::make_shared<ExpressionModif>(yystack_[4].value.as < std::string > (),yystack_[2].value.as < Attributs > ());
    }
#line 1700 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 86: // ope: fig '[' NUMBER ']' '.' attributs_variable PV NL
#line 390 "parser/parser.yy"
                                                     {
    yylhs.value.as < std::shared_ptr<Expression> > ()= std::make_shared<ExpressionModif>(yystack_[7].value.as < std::string > (),yystack_[5].value.as < int > (),yystack_[2].value.as < Attributs > ());
    }
#line 1708 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 87: // ope: IDENT '.' critere '=' NUMBER PV NL
#line 393 "parser/parser.yy"
                                         {
    yylhs.value.as < std::shared_ptr<Expression> > ()= std::make_shared<ExpressionCritere>(yystack_[6].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[2].value.as < int > ());
    }
#line 1716 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 88: // ope: fig '[' NUMBER ']' '.' critere '=' NUMBER PV NL
#line 396 "parser/parser.yy"
                                                      {
    yylhs.value.as < std::shared_ptr<Expression> > ()= std::make_shared<ExpressionCritere>(yystack_[9].value.as < std::string > (),yystack_[7].value.as < int > (),yystack_[4].value.as < std::string > (),yystack_[2].value.as < int > ());
    }
#line 1724 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 89: // ope: %empty
#line 399 "parser/parser.yy"
     {yylhs.value.as < std::shared_ptr<Expression> > ()=nullptr;}
#line 1730 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 90: // suite: SINON OUVRE_ACCOLADE NL ope FERME_ACCOLADE
#line 403 "parser/parser.yy"
                                              {
    yylhs.value.as < std::shared_ptr<Expression> > ()=yystack_[1].value.as < std::shared_ptr<Expression> > ();}
#line 1737 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 91: // suite: %empty
#line 405 "parser/parser.yy"
     {
        yylhs.value.as < std::shared_ptr<Expression> > ()=nullptr;
    }
#line 1745 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 92: // SIGNE: G
#line 410 "parser/parser.yy"
     {
    yylhs.value.as < std::string > ()=">";}
#line 1752 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 93: // SIGNE: GE
#line 412 "parser/parser.yy"
       {
    yylhs.value.as < std::string > ()=">=";}
#line 1759 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 94: // SIGNE: L
#line 414 "parser/parser.yy"
      {
    yylhs.value.as < std::string > ()="<";}
#line 1766 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 95: // SIGNE: LE
#line 416 "parser/parser.yy"
       {
    yylhs.value.as < std::string > ()="<=";}
#line 1773 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 96: // SIGNE: E
#line 418 "parser/parser.yy"
      {
    yylhs.value.as < std::string > ()="==";}
#line 1780 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 97: // SIGNE: NE
#line 420 "parser/parser.yy"
       {
    yylhs.value.as < std::string > ()="!=";}
#line 1787 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 98: // IS: EST
#line 425 "parser/parser.yy"
       {
    yylhs.value.as < bool > ()=true;
    }
#line 1795 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 99: // IS: ESTPAS
#line 428 "parser/parser.yy"
           {
    yylhs.value.as < bool > ()=false; }
#line 1802 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 100: // comparaison: predicat
#line 433 "parser/parser.yy"
            {
        yylhs.value.as < bool > ()=yystack_[0].value.as < bool > ();}
#line 1809 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 101: // comparaison: '(' predicat ETLOG comparaison ')'
#line 435 "parser/parser.yy"
                                       {
        yylhs.value.as < bool > ()=(yystack_[3].value.as < bool > () && yystack_[1].value.as < bool > ());
    }
#line 1817 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 102: // comparaison: '(' predicat OU comparaison ')'
#line 438 "parser/parser.yy"
                                     {
     yylhs.value.as < bool > ()=(yystack_[3].value.as < bool > () || yystack_[1].value.as < bool > ());
}
#line 1825 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 103: // predicat: '(' IDENT '.' critere SIGNE NUMBER ')'
#line 444 "parser/parser.yy"
                                         {
       yylhs.value.as < bool > ()=driver.evaluation(yystack_[5].value.as < std::string > (),yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[1].value.as < int > ());
    }
#line 1833 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 104: // predicat: '(' IDENT '.' COULEUR IS color ')'
#line 447 "parser/parser.yy"
                                     {
        yylhs.value.as < bool > ()=driver.evaluationcouleur(yystack_[5].value.as < std::string > (),yystack_[2].value.as < bool > (),yystack_[1].value.as < std::string > ());}
#line 1840 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 105: // predicat: '(' fig '[' NUMBER ']' '.' critere SIGNE NUMBER ')'
#line 449 "parser/parser.yy"
                                                         {
       yylhs.value.as < bool > ()=driver.evaluation(yystack_[8].value.as < std::string > (),yystack_[6].value.as < int > (),yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[1].value.as < int > ());
    }
#line 1848 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 106: // predicat: '(' fig '[' NUMBER ']' '.' COULEUR IS color ')'
#line 452 "parser/parser.yy"
                                                   {
        yylhs.value.as < bool > ()=driver.evaluationcouleur(yystack_[8].value.as < std::string > (),yystack_[6].value.as < int > (),yystack_[2].value.as < bool > (),yystack_[1].value.as < std::string > ());}
#line 1855 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 107: // expression: operation
#line 457 "parser/parser.yy"
             {
        //Modifier cette partie pour prendre en compte la structure avec expressions
        std::cout << "#-> " << yystack_[0].value.as < int > () << std::endl;
     }
#line 1864 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 108: // affectation: '='
#line 463 "parser/parser.yy"
        { std::cout << "Affectation à réaliser" << std::endl;
    }
#line 1871 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 109: // operation: NUMBER
#line 467 "parser/parser.yy"
           {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1879 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 110: // operation: BOOL
#line 470 "parser/parser.yy"
          {
        yylhs.value.as < int > () = yystack_[0].value.as < bool > ();
    }
#line 1887 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 111: // operation: DOUBLE
#line 473 "parser/parser.yy"
            {
        yylhs.value.as < int > () = yystack_[0].value.as < double > ();
    }
#line 1895 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 112: // operation: '(' operation ')'
#line 476 "parser/parser.yy"
                        {
        yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    }
#line 1903 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 113: // operation: operation '+' operation
#line 479 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > ();
    }
#line 1911 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 114: // operation: operation '-' operation
#line 482 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > ();
    }
#line 1919 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 115: // operation: operation '*' operation
#line 485 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > ();
    }
#line 1927 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 116: // operation: operation '/' operation
#line 488 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > ();
    }
#line 1935 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;

  case 117: // operation: '-' operation
#line 491 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = - yystack_[0].value.as < int > ();
    }
#line 1943 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"
    break;


#line 1947 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short  Parser ::yypact_ninf_ = -208;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
      16,  -208,    16,  -208,    14,    38,    45,    52,    73,    79,
      87,    88,    90,   -61,   -72,    26,    27,    28,  -208,  -208,
     -35,     4,  -208,     4,   102,    16,  -208,    29,     1,  -208,
     100,    23,  -208,  -208,    33,   -38,  -208,   111,   112,   113,
     115,   116,   117,   118,   119,    51,   122,    48,    59,   103,
    -208,    66,    67,    68,   156,   139,  -208,    64,  -208,  -208,
     140,    40,   146,  -208,  -208,   147,   150,     4,     4,     4,
       4,  -208,   152,   166,   188,   189,   191,   192,  -208,   193,
      83,   151,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
      70,   124,    74,   -13,   195,   179,   236,   196,    38,    45,
      52,    73,    79,    87,    88,    90,  -208,  -208,   163,   164,
     167,   168,   169,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,  -208,   173,   170,  -208,  -208,
     227,   228,   229,   230,   231,   240,    40,   174,  -208,   -45,
     -45,  -208,  -208,  -208,   253,   254,  -208,   255,   256,   257,
     197,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,   190,  -208,   180,   259,   -72,   -72,   261,   198,
     199,   200,   151,   262,   151,   263,   265,   270,   271,   151,
     272,   151,   273,   274,    40,   202,   207,   -66,   276,  -208,
    -208,  -208,  -208,  -208,  -208,     7,   126,   183,   201,   203,
     101,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
     209,  -208,  -208,  -208,  -208,  -208,   240,  -208,   279,  -208,
     139,   280,  -208,  -208,   151,  -208,  -208,  -208,  -208,  -208,
    -208,   282,   208,  -208,  -208,   210,   211,   266,   286,  -208,
      40,   277,   219,   214,   291,   212,   213,   194,   139,   294,
     296,  -208,   232,  -208,   297,   298,   299,  -208,  -208,     7,
     126,   233,   222,   224,   281,   305,  -208,   237,  -208,   151,
     306,   270,   307,   234,   300,  -208,   279,   309,   235,   238,
     209,   139,   310,  -208,  -208,  -208,  -208,   243,   239,   101,
     297,   313,   303,   237,  -208
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     4,     0,   109,     0,    49,    48,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     0,   110,   111,
       0,     0,   108,     0,     0,     0,     5,     0,     0,    42,
       0,     0,     9,    10,     0,   107,     3,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
     100,     0,     0,     0,     0,     0,   117,     0,     1,     2,
       0,     0,     0,    22,     7,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    49,    48,    50,    51,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    64,     0,     0,
       0,     0,     0,    65,    66,    56,    57,    58,    59,    60,
      61,    62,    63,    68,    67,    69,     0,     0,   112,     8,
       0,     0,     0,     0,     0,    24,     0,     0,     6,   114,
     113,   115,   116,    13,     0,     0,    15,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      73,    74,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      16,    17,    28,    19,    47,     0,     0,     0,     0,     0,
      89,    46,    44,    45,    34,    35,    36,    37,    38,    85,
      71,    29,    30,    31,    32,    33,    24,    20,    26,    43,
       0,     0,    99,    98,     0,    94,    95,    92,    93,    96,
      97,     0,     0,   101,   102,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    21,     0,     0,     0,   104,   103,     0,
       0,     0,     0,     0,    91,     0,    86,    70,    12,     0,
       0,     0,     0,     0,     0,    84,    26,     0,     0,     0,
       0,     0,     0,    25,    88,   106,   105,     0,     0,    89,
       0,     0,     0,     0,    90
  };

  const short
   Parser ::yypgoto_[] =
  {
    -208,     5,  -208,  -208,  -208,  -208,   267,   107,    49,  -208,
    -134,  -207,  -208,   -48,  -163,  -208,  -169,  -208,  -196,  -208,
      69,    65,   -78,   278,  -208,    12
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    24,    25,    26,    27,    28,    29,   185,   241,    45,
     135,   126,    30,    31,   127,    32,   162,   163,    33,   275,
     231,   224,    49,    50,    34,    35
  };

  const short
   Parser ::yytable_[] =
  {
      92,   196,   186,   204,   237,   206,   219,    36,     3,    47,
     211,    48,   213,   242,   220,    61,     1,    62,    37,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      59,    69,    70,    56,    13,    57,    67,    68,    69,    70,
      14,   261,    38,    92,    54,    55,    15,    16,    17,    39,
     216,    18,    19,   166,   167,   245,    40,   243,   130,   131,
     132,   133,   134,    18,    19,    82,    83,    84,    85,    86,
      87,    88,    89,    63,   287,   222,   223,    41,    21,   139,
     140,   141,   142,    42,   260,   262,    20,    23,   198,   199,
      21,    43,    44,   292,    46,    22,    51,    52,    53,    23,
     278,    60,    58,    64,    65,    66,   252,    82,    83,    84,
      85,    86,    87,    88,    89,    71,    72,    73,   288,    74,
      75,    76,    77,    78,    79,    14,    80,    81,    94,    90,
      82,    83,    84,    85,    86,    87,    88,    89,    67,    68,
      69,    70,    91,   129,   107,    95,    96,    97,   128,   136,
     164,   137,   236,   138,   150,   165,   143,   108,   109,   110,
     111,   112,    98,    99,   100,   101,   102,   103,   104,   105,
     144,   235,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   107,   225,   226,   227,   228,
     229,   230,   145,   146,    90,   147,   148,   149,   195,   107,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   168,   259,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   169,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     170,   236,   172,   173,   171,   177,   174,   175,   176,   178,
     179,   180,   181,   182,   183,   184,   187,   188,   189,   190,
     191,   192,   194,   197,   200,   232,   205,   207,   193,   208,
     201,   202,   203,   209,   217,   210,   212,   214,   215,   218,
     221,   238,   240,   250,   244,   233,   246,   234,   247,   251,
     248,   254,   249,   255,   253,   256,   257,   258,   263,   264,
     266,   272,   267,   268,   265,   271,   273,   274,   276,   277,
     279,   280,   284,   289,   281,   290,   282,   293,   291,   285,
     294,   106,   286,   239,   269,   283,    93,     0,     0,   270
  };

  const short
   Parser ::yycheck_[] =
  {
      48,   164,   136,   172,   200,   174,    72,     2,     4,    70,
     179,    83,   181,   220,    80,    14,     0,    16,     4,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      25,    76,    77,    21,    18,    23,    74,    75,    76,    77,
      24,   248,     4,    91,    79,    80,    30,    31,    32,     4,
     184,    47,    48,    66,    67,   224,     4,   220,    18,    19,
      20,    21,    22,    47,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    72,   281,    68,    69,     4,    74,    67,
      68,    69,    70,     4,   247,   248,    70,    83,   166,   167,
      74,     4,     4,   289,     4,    79,    70,    70,    70,    83,
     269,    72,     0,     3,    81,    72,   240,     6,     7,     8,
       9,    10,    11,    12,    13,     4,     4,     4,   281,     4,
       4,     4,     4,     4,    73,    24,     4,    79,    25,    70,
       6,     7,     8,     9,    10,    11,    12,    13,    74,    75,
      76,    77,    83,     3,     5,    79,    79,    79,    84,     3,
      80,     4,   200,     3,    71,    81,     4,    18,    19,    20,
      21,    22,     6,     7,     8,     9,    10,    11,    12,    13,
       4,    70,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     5,    60,    61,    62,    63,
      64,    65,     4,     4,    70,     4,     4,     4,    18,     5,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    16,    18,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    47,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       4,   289,    79,    79,    48,    72,    79,    79,    79,    79,
      23,    23,    23,    23,    23,    15,    82,     4,     4,     4,
       4,     4,    72,     4,     3,    82,     4,     4,    71,     4,
      72,    72,    72,     3,    72,     4,     4,     4,     4,    72,
       4,    72,     3,    17,     4,    84,     4,    84,    80,     3,
      80,    72,    81,    79,    17,     4,    84,    84,     4,     3,
       3,    79,     4,     4,    72,    72,    82,    26,     3,    72,
       4,     4,     3,     3,    80,    72,    16,     4,    79,    84,
      17,    54,    84,   216,   259,   276,    48,    -1,    -1,   260
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    18,    24,    30,    31,    32,    47,    48,
      70,    74,    79,    83,    86,    87,    88,    89,    90,    91,
      97,    98,   100,   103,   109,   110,    86,     4,     4,     4,
       4,     4,     4,     4,     4,    94,     4,    70,    83,   107,
     108,    70,    70,    70,    79,    80,   110,   110,     0,    86,
      72,    14,    16,    72,     3,    81,    72,    74,    75,    76,
      77,     4,     4,     4,     4,     4,     4,     4,     4,    73,
       4,    79,     6,     7,     8,     9,    10,    11,    12,    13,
      70,    83,    98,   108,    25,    79,    79,    79,     6,     7,
       8,     9,    10,    11,    12,    13,    91,     5,    18,    19,
      20,    21,    22,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    96,    99,    84,     3,
      18,    19,    20,    21,    22,    95,     3,     4,     3,   110,
     110,   110,   110,     4,     4,     4,     4,     4,     4,     4,
      71,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   101,   102,    80,    81,    66,    67,    16,    47,
       4,    48,    79,    79,    79,    79,    79,    72,    79,    23,
      23,    23,    23,    23,    15,    92,    95,    82,     4,     4,
       4,     4,     4,    71,    72,    18,    99,     4,   107,   107,
       3,    72,    72,    72,   101,     4,   101,     4,     4,     3,
       4,   101,     4,   101,     4,     4,    95,    72,    72,    72,
      80,     4,    68,    69,   106,    60,    61,    62,    63,    64,
      65,   105,    82,    84,    84,    70,    98,   103,    72,    92,
       3,    93,    96,    99,     4,   101,     4,    80,    80,    81,
      17,     3,    95,    17,    72,    79,     4,    84,    84,    18,
      99,    96,    99,     4,     3,    72,     3,     4,     4,   106,
     105,    72,    79,    82,    26,   104,     3,    72,   101,     4,
       4,    80,    16,    93,     3,    84,    84,    96,    99,     3,
      72,    79,   103,     4,    17
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    85,    86,    86,    86,    87,    87,    87,    87,    87,
      88,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   106,   106,
     107,   107,   107,   108,   108,   108,   108,    88,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     2,     1,     1,     3,     2,     3,     1,
       1,     3,     9,     4,     5,     4,     5,     5,     2,     5,
       5,     7,     2,     3,     0,     5,     0,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     7,     1,     5,     5,     5,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       8,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     9,     5,     8,     7,    10,     0,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     7,     7,    10,    10,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "NUMBER",
  "TAILLE", "CARRE", "RECTANGLE", "TRIANGLE", "CERCLE", "ELLIPSE", "LIGNE",
  "CHEMIN", "TEXTE", "FLECHE", "ET", "OUVRE_ACCOLADE", "FERME_ACCOLADE",
  "COULEUR", "ROTATION", "REMPLISSAGE", "OPACITE", "EPAISSEUR", "DP", "SI",
  "ALORS", "SINON", "TANT_QUE", "REPETE", "FONCTION", "BOOLEEN", "ENT",
  "REEL", "X", "Y", "X1", "Y1", "X2", "Y2", "X3", "Y3", "X4", "Y4",
  "HAUTEUR", "LARGEUR", "RAY", "T", "BOOL", "DOUBLE", "rouge", "vert",
  "bleu", "jaune", "violet", "magenta", "cyan", "noir", "blanc", "NOM_HEX",
  "NOM_RGB", "L", "LE", "G", "GE", "E", "NE", "ETLOG", "OU", "ESTPAS",
  "EST", "IDENT", "CHAINE", "PV", "V", "'-'", "'+'", "'*'", "'/'", "NEG",
  "'='", "'.'", "'['", "']'", "'('", "')'", "$accept", "programme",
  "instruction", "expression", "taille", "figure", "figure_att",
  "liste_fleche", "liste_acc", "coordonnees", "attributs",
  "attributs_variable", "variable", "fig", "critere", "modif", "color",
  "coul", "ope", "suite", "SIGNE", "IS", "comparaison", "predicat",
  "affectation", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,    87,    87,    89,    90,   100,   102,   104,   106,   109,
     112,   120,   126,   129,   132,   135,   138,   141,   144,   155,
     162,   169,   176,   179,   183,   186,   190,   195,   198,   207,
     212,   217,   222,   227,   234,   239,   244,   249,   254,   263,
     267,   270,   273,   276,   279,   282,   285,   288,   293,   296,
     299,   302,   305,   308,   311,   314,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   337,   339,   341,   343,   345,
     351,   354,   360,   361,   362,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   378,   387,   390,   393,   396,   399,
     403,   405,   410,   412,   414,   416,   418,   420,   425,   428,
     433,   435,   438,   444,   447,   449,   452,   457,   463,   467,
     470,   473,   476,   479,   482,   485,   488,   491
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      83,    84,    76,    75,     2,    74,    80,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    78
    };
    // Last valid token kind.
    const int code_max = 329;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2658 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.cpp"

#line 495 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
