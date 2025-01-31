// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_ETUD_DOCUMENTS_ABED_ARINA_ABOUAKIL_IBRAHIM_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_HOME_ETUD_DOCUMENTS_ABED_ARINA_ABOUAKIL_IBRAHIM_BUILD_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "parser/parser.yy"

    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "expressionmodif.hh"
    #include "expressionTernaire.hh"
    #include "expressioncritere.hh"
    #include "constante.hh"
    #include "variable.hh"

    class Scanner;
    class Driver;

#line 63 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 197 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.hpp"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // attributs
      // attributs_variable
      char dummy1[sizeof (Attributs)];

      // BOOL
      // IS
      // comparaison
      // predicat
      char dummy2[sizeof (bool)];

      // DOUBLE
      char dummy3[sizeof (double)];

      // NUMBER
      // operation
      char dummy4[sizeof (int)];

      // ope
      // suite
      char dummy5[sizeof (std::shared_ptr<Expression>)];

      // figure
      // figure_att
      char dummy6[sizeof (std::shared_ptr<Forme>)];

      // taille
      char dummy7[sizeof (std::shared_ptr<Taille>)];

      // NOM_HEX
      // NOM_RGB
      // IDENT
      // CHAINE
      // variable
      // fig
      // critere
      // color
      // coul
      // SIGNE
      char dummy8[sizeof (std::string)];

      // liste_fleche
      // liste_acc
      char dummy9[sizeof (std::vector<Attributs>)];

      // coordonnees
      char dummy10[sizeof (std::vector<int>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    NL = 258,                      // NL
    NUMBER = 259,                  // NUMBER
    TAILLE = 260,                  // TAILLE
    CARRE = 261,                   // CARRE
    RECTANGLE = 262,               // RECTANGLE
    TRIANGLE = 263,                // TRIANGLE
    CERCLE = 264,                  // CERCLE
    ELLIPSE = 265,                 // ELLIPSE
    LIGNE = 266,                   // LIGNE
    CHEMIN = 267,                  // CHEMIN
    TEXTE = 268,                   // TEXTE
    FLECHE = 269,                  // FLECHE
    ET = 270,                      // ET
    OUVRE_ACCOLADE = 271,          // OUVRE_ACCOLADE
    FERME_ACCOLADE = 272,          // FERME_ACCOLADE
    COULEUR = 273,                 // COULEUR
    ROTATION = 274,                // ROTATION
    REMPLISSAGE = 275,             // REMPLISSAGE
    OPACITE = 276,                 // OPACITE
    EPAISSEUR = 277,               // EPAISSEUR
    DP = 278,                      // DP
    SI = 279,                      // SI
    ALORS = 280,                   // ALORS
    SINON = 281,                   // SINON
    TANT_QUE = 282,                // TANT_QUE
    REPETE = 283,                  // REPETE
    FONCTION = 284,                // FONCTION
    BOOLEEN = 285,                 // BOOLEEN
    ENT = 286,                     // ENT
    REEL = 287,                    // REEL
    X = 288,                       // X
    Y = 289,                       // Y
    X1 = 290,                      // X1
    Y1 = 291,                      // Y1
    X2 = 292,                      // X2
    Y2 = 293,                      // Y2
    X3 = 294,                      // X3
    Y3 = 295,                      // Y3
    X4 = 296,                      // X4
    Y4 = 297,                      // Y4
    HAUTEUR = 298,                 // HAUTEUR
    LARGEUR = 299,                 // LARGEUR
    RAY = 300,                     // RAY
    T = 301,                       // T
    BOOL = 302,                    // BOOL
    DOUBLE = 303,                  // DOUBLE
    rouge = 304,                   // rouge
    vert = 305,                    // vert
    bleu = 306,                    // bleu
    jaune = 307,                   // jaune
    violet = 308,                  // violet
    magenta = 309,                 // magenta
    cyan = 310,                    // cyan
    noir = 311,                    // noir
    blanc = 312,                   // blanc
    NOM_HEX = 313,                 // NOM_HEX
    NOM_RGB = 314,                 // NOM_RGB
    L = 315,                       // L
    LE = 316,                      // LE
    G = 317,                       // G
    GE = 318,                      // GE
    E = 319,                       // E
    NE = 320,                      // NE
    ETLOG = 321,                   // ETLOG
    OU = 322,                      // OU
    ESTPAS = 323,                  // ESTPAS
    EST = 324,                     // EST
    IDENT = 325,                   // IDENT
    CHAINE = 326,                  // CHAINE
    PV = 327,                      // PV
    V = 328,                       // V
    NEG = 329                      // NEG
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 85, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NL = 3,                                // NL
        S_NUMBER = 4,                            // NUMBER
        S_TAILLE = 5,                            // TAILLE
        S_CARRE = 6,                             // CARRE
        S_RECTANGLE = 7,                         // RECTANGLE
        S_TRIANGLE = 8,                          // TRIANGLE
        S_CERCLE = 9,                            // CERCLE
        S_ELLIPSE = 10,                          // ELLIPSE
        S_LIGNE = 11,                            // LIGNE
        S_CHEMIN = 12,                           // CHEMIN
        S_TEXTE = 13,                            // TEXTE
        S_FLECHE = 14,                           // FLECHE
        S_ET = 15,                               // ET
        S_OUVRE_ACCOLADE = 16,                   // OUVRE_ACCOLADE
        S_FERME_ACCOLADE = 17,                   // FERME_ACCOLADE
        S_COULEUR = 18,                          // COULEUR
        S_ROTATION = 19,                         // ROTATION
        S_REMPLISSAGE = 20,                      // REMPLISSAGE
        S_OPACITE = 21,                          // OPACITE
        S_EPAISSEUR = 22,                        // EPAISSEUR
        S_DP = 23,                               // DP
        S_SI = 24,                               // SI
        S_ALORS = 25,                            // ALORS
        S_SINON = 26,                            // SINON
        S_TANT_QUE = 27,                         // TANT_QUE
        S_REPETE = 28,                           // REPETE
        S_FONCTION = 29,                         // FONCTION
        S_BOOLEEN = 30,                          // BOOLEEN
        S_ENT = 31,                              // ENT
        S_REEL = 32,                             // REEL
        S_X = 33,                                // X
        S_Y = 34,                                // Y
        S_X1 = 35,                               // X1
        S_Y1 = 36,                               // Y1
        S_X2 = 37,                               // X2
        S_Y2 = 38,                               // Y2
        S_X3 = 39,                               // X3
        S_Y3 = 40,                               // Y3
        S_X4 = 41,                               // X4
        S_Y4 = 42,                               // Y4
        S_HAUTEUR = 43,                          // HAUTEUR
        S_LARGEUR = 44,                          // LARGEUR
        S_RAY = 45,                              // RAY
        S_T = 46,                                // T
        S_BOOL = 47,                             // BOOL
        S_DOUBLE = 48,                           // DOUBLE
        S_rouge = 49,                            // rouge
        S_vert = 50,                             // vert
        S_bleu = 51,                             // bleu
        S_jaune = 52,                            // jaune
        S_violet = 53,                           // violet
        S_magenta = 54,                          // magenta
        S_cyan = 55,                             // cyan
        S_noir = 56,                             // noir
        S_blanc = 57,                            // blanc
        S_NOM_HEX = 58,                          // NOM_HEX
        S_NOM_RGB = 59,                          // NOM_RGB
        S_L = 60,                                // L
        S_LE = 61,                               // LE
        S_G = 62,                                // G
        S_GE = 63,                               // GE
        S_E = 64,                                // E
        S_NE = 65,                               // NE
        S_ETLOG = 66,                            // ETLOG
        S_OU = 67,                               // OU
        S_ESTPAS = 68,                           // ESTPAS
        S_EST = 69,                              // EST
        S_IDENT = 70,                            // IDENT
        S_CHAINE = 71,                           // CHAINE
        S_PV = 72,                               // PV
        S_V = 73,                                // V
        S_74_ = 74,                              // '-'
        S_75_ = 75,                              // '+'
        S_76_ = 76,                              // '*'
        S_77_ = 77,                              // '/'
        S_NEG = 78,                              // NEG
        S_79_ = 79,                              // '='
        S_80_ = 80,                              // '.'
        S_81_ = 81,                              // '['
        S_82_ = 82,                              // ']'
        S_83_ = 83,                              // '('
        S_84_ = 84,                              // ')'
        S_YYACCEPT = 85,                         // $accept
        S_programme = 86,                        // programme
        S_instruction = 87,                      // instruction
        S_expression = 88,                       // expression
        S_taille = 89,                           // taille
        S_figure = 90,                           // figure
        S_figure_att = 91,                       // figure_att
        S_liste_fleche = 92,                     // liste_fleche
        S_liste_acc = 93,                        // liste_acc
        S_coordonnees = 94,                      // coordonnees
        S_attributs = 95,                        // attributs
        S_attributs_variable = 96,               // attributs_variable
        S_variable = 97,                         // variable
        S_fig = 98,                              // fig
        S_critere = 99,                          // critere
        S_modif = 100,                           // modif
        S_color = 101,                           // color
        S_coul = 102,                            // coul
        S_ope = 103,                             // ope
        S_suite = 104,                           // suite
        S_SIGNE = 105,                           // SIGNE
        S_IS = 106,                              // IS
        S_comparaison = 107,                     // comparaison
        S_predicat = 108,                        // predicat
        S_affectation = 109,                     // affectation
        S_operation = 110                        // operation
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.move< Attributs > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.move< std::shared_ptr<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.move< std::shared_ptr<Forme> > (std::move (that.value));
        break;

      case symbol_kind::S_taille: // taille
        value.move< std::shared_ptr<Taille> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.move< std::vector<Attributs> > (std::move (that.value));
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.move< std::vector<int> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Attributs&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Attributs& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Forme>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Forme>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Taille>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Taille>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Attributs>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Attributs>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<int>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<int>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_attributs: // attributs
      case symbol_kind::S_attributs_variable: // attributs_variable
        value.template destroy< Attributs > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_predicat: // predicat
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_DOUBLE: // DOUBLE
        value.template destroy< double > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.template destroy< int > ();
        break;

      case symbol_kind::S_ope: // ope
      case symbol_kind::S_suite: // suite
        value.template destroy< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_figure: // figure
      case symbol_kind::S_figure_att: // figure_att
        value.template destroy< std::shared_ptr<Forme> > ();
        break;

      case symbol_kind::S_taille: // taille
        value.template destroy< std::shared_ptr<Taille> > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_liste_fleche: // liste_fleche
      case symbol_kind::S_liste_acc: // liste_acc
        value.template destroy< std::vector<Attributs> > ();
        break;

      case symbol_kind::S_coordonnees: // coordonnees
        value.template destroy< std::vector<int> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::NL)
                   || (token::TAILLE <= tok && tok <= token::T)
                   || (token::rouge <= tok && tok <= token::blanc)
                   || (token::L <= tok && tok <= token::EST)
                   || (token::PV <= tok && tok <= token::V)
                   || tok == 45
                   || tok == 43
                   || tok == 42
                   || tok == 47
                   || tok == token::NEG
                   || tok == 61
                   || tok == 46
                   || tok == 91
                   || tok == 93
                   || (40 <= tok && tok <= 41));
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::BOOL);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::DOUBLE);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT ((token::NOM_HEX <= tok && tok <= token::NOM_RGB)
                   || (token::IDENT <= tok && tok <= token::CHAINE));
      }
    };

    /// Build a parser object.
     Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NL (location_type l)
      {
        return symbol_type (token::NL, std::move (l));
      }
#else
      static
      symbol_type
      make_NL (const location_type& l)
      {
        return symbol_type (token::NL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (int v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const int& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAILLE (location_type l)
      {
        return symbol_type (token::TAILLE, std::move (l));
      }
#else
      static
      symbol_type
      make_TAILLE (const location_type& l)
      {
        return symbol_type (token::TAILLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARRE (location_type l)
      {
        return symbol_type (token::CARRE, std::move (l));
      }
#else
      static
      symbol_type
      make_CARRE (const location_type& l)
      {
        return symbol_type (token::CARRE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECTANGLE (location_type l)
      {
        return symbol_type (token::RECTANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_RECTANGLE (const location_type& l)
      {
        return symbol_type (token::RECTANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRIANGLE (location_type l)
      {
        return symbol_type (token::TRIANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRIANGLE (const location_type& l)
      {
        return symbol_type (token::TRIANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CERCLE (location_type l)
      {
        return symbol_type (token::CERCLE, std::move (l));
      }
#else
      static
      symbol_type
      make_CERCLE (const location_type& l)
      {
        return symbol_type (token::CERCLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSE (location_type l)
      {
        return symbol_type (token::ELLIPSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSE (const location_type& l)
      {
        return symbol_type (token::ELLIPSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIGNE (location_type l)
      {
        return symbol_type (token::LIGNE, std::move (l));
      }
#else
      static
      symbol_type
      make_LIGNE (const location_type& l)
      {
        return symbol_type (token::LIGNE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHEMIN (location_type l)
      {
        return symbol_type (token::CHEMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_CHEMIN (const location_type& l)
      {
        return symbol_type (token::CHEMIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEXTE (location_type l)
      {
        return symbol_type (token::TEXTE, std::move (l));
      }
#else
      static
      symbol_type
      make_TEXTE (const location_type& l)
      {
        return symbol_type (token::TEXTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLECHE (location_type l)
      {
        return symbol_type (token::FLECHE, std::move (l));
      }
#else
      static
      symbol_type
      make_FLECHE (const location_type& l)
      {
        return symbol_type (token::FLECHE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ET (location_type l)
      {
        return symbol_type (token::ET, std::move (l));
      }
#else
      static
      symbol_type
      make_ET (const location_type& l)
      {
        return symbol_type (token::ET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUVRE_ACCOLADE (location_type l)
      {
        return symbol_type (token::OUVRE_ACCOLADE, std::move (l));
      }
#else
      static
      symbol_type
      make_OUVRE_ACCOLADE (const location_type& l)
      {
        return symbol_type (token::OUVRE_ACCOLADE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FERME_ACCOLADE (location_type l)
      {
        return symbol_type (token::FERME_ACCOLADE, std::move (l));
      }
#else
      static
      symbol_type
      make_FERME_ACCOLADE (const location_type& l)
      {
        return symbol_type (token::FERME_ACCOLADE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEUR (location_type l)
      {
        return symbol_type (token::COULEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_COULEUR (const location_type& l)
      {
        return symbol_type (token::COULEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROTATION (location_type l)
      {
        return symbol_type (token::ROTATION, std::move (l));
      }
#else
      static
      symbol_type
      make_ROTATION (const location_type& l)
      {
        return symbol_type (token::ROTATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REMPLISSAGE (location_type l)
      {
        return symbol_type (token::REMPLISSAGE, std::move (l));
      }
#else
      static
      symbol_type
      make_REMPLISSAGE (const location_type& l)
      {
        return symbol_type (token::REMPLISSAGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPACITE (location_type l)
      {
        return symbol_type (token::OPACITE, std::move (l));
      }
#else
      static
      symbol_type
      make_OPACITE (const location_type& l)
      {
        return symbol_type (token::OPACITE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EPAISSEUR (location_type l)
      {
        return symbol_type (token::EPAISSEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_EPAISSEUR (const location_type& l)
      {
        return symbol_type (token::EPAISSEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DP (location_type l)
      {
        return symbol_type (token::DP, std::move (l));
      }
#else
      static
      symbol_type
      make_DP (const location_type& l)
      {
        return symbol_type (token::DP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SI (location_type l)
      {
        return symbol_type (token::SI, std::move (l));
      }
#else
      static
      symbol_type
      make_SI (const location_type& l)
      {
        return symbol_type (token::SI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALORS (location_type l)
      {
        return symbol_type (token::ALORS, std::move (l));
      }
#else
      static
      symbol_type
      make_ALORS (const location_type& l)
      {
        return symbol_type (token::ALORS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINON (location_type l)
      {
        return symbol_type (token::SINON, std::move (l));
      }
#else
      static
      symbol_type
      make_SINON (const location_type& l)
      {
        return symbol_type (token::SINON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TANT_QUE (location_type l)
      {
        return symbol_type (token::TANT_QUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TANT_QUE (const location_type& l)
      {
        return symbol_type (token::TANT_QUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPETE (location_type l)
      {
        return symbol_type (token::REPETE, std::move (l));
      }
#else
      static
      symbol_type
      make_REPETE (const location_type& l)
      {
        return symbol_type (token::REPETE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FONCTION (location_type l)
      {
        return symbol_type (token::FONCTION, std::move (l));
      }
#else
      static
      symbol_type
      make_FONCTION (const location_type& l)
      {
        return symbol_type (token::FONCTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEEN (location_type l)
      {
        return symbol_type (token::BOOLEEN, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEEN (const location_type& l)
      {
        return symbol_type (token::BOOLEEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENT (location_type l)
      {
        return symbol_type (token::ENT, std::move (l));
      }
#else
      static
      symbol_type
      make_ENT (const location_type& l)
      {
        return symbol_type (token::ENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REEL (location_type l)
      {
        return symbol_type (token::REEL, std::move (l));
      }
#else
      static
      symbol_type
      make_REEL (const location_type& l)
      {
        return symbol_type (token::REEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_X (location_type l)
      {
        return symbol_type (token::X, std::move (l));
      }
#else
      static
      symbol_type
      make_X (const location_type& l)
      {
        return symbol_type (token::X, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y (location_type l)
      {
        return symbol_type (token::Y, std::move (l));
      }
#else
      static
      symbol_type
      make_Y (const location_type& l)
      {
        return symbol_type (token::Y, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_X1 (location_type l)
      {
        return symbol_type (token::X1, std::move (l));
      }
#else
      static
      symbol_type
      make_X1 (const location_type& l)
      {
        return symbol_type (token::X1, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y1 (location_type l)
      {
        return symbol_type (token::Y1, std::move (l));
      }
#else
      static
      symbol_type
      make_Y1 (const location_type& l)
      {
        return symbol_type (token::Y1, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_X2 (location_type l)
      {
        return symbol_type (token::X2, std::move (l));
      }
#else
      static
      symbol_type
      make_X2 (const location_type& l)
      {
        return symbol_type (token::X2, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y2 (location_type l)
      {
        return symbol_type (token::Y2, std::move (l));
      }
#else
      static
      symbol_type
      make_Y2 (const location_type& l)
      {
        return symbol_type (token::Y2, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_X3 (location_type l)
      {
        return symbol_type (token::X3, std::move (l));
      }
#else
      static
      symbol_type
      make_X3 (const location_type& l)
      {
        return symbol_type (token::X3, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y3 (location_type l)
      {
        return symbol_type (token::Y3, std::move (l));
      }
#else
      static
      symbol_type
      make_Y3 (const location_type& l)
      {
        return symbol_type (token::Y3, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_X4 (location_type l)
      {
        return symbol_type (token::X4, std::move (l));
      }
#else
      static
      symbol_type
      make_X4 (const location_type& l)
      {
        return symbol_type (token::X4, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Y4 (location_type l)
      {
        return symbol_type (token::Y4, std::move (l));
      }
#else
      static
      symbol_type
      make_Y4 (const location_type& l)
      {
        return symbol_type (token::Y4, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HAUTEUR (location_type l)
      {
        return symbol_type (token::HAUTEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_HAUTEUR (const location_type& l)
      {
        return symbol_type (token::HAUTEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LARGEUR (location_type l)
      {
        return symbol_type (token::LARGEUR, std::move (l));
      }
#else
      static
      symbol_type
      make_LARGEUR (const location_type& l)
      {
        return symbol_type (token::LARGEUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAY (location_type l)
      {
        return symbol_type (token::RAY, std::move (l));
      }
#else
      static
      symbol_type
      make_RAY (const location_type& l)
      {
        return symbol_type (token::RAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T (location_type l)
      {
        return symbol_type (token::T, std::move (l));
      }
#else
      static
      symbol_type
      make_T (const location_type& l)
      {
        return symbol_type (token::T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v, location_type l)
      {
        return symbol_type (token::BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v, const location_type& l)
      {
        return symbol_type (token::BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (double v, location_type l)
      {
        return symbol_type (token::DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const double& v, const location_type& l)
      {
        return symbol_type (token::DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_rouge (location_type l)
      {
        return symbol_type (token::rouge, std::move (l));
      }
#else
      static
      symbol_type
      make_rouge (const location_type& l)
      {
        return symbol_type (token::rouge, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_vert (location_type l)
      {
        return symbol_type (token::vert, std::move (l));
      }
#else
      static
      symbol_type
      make_vert (const location_type& l)
      {
        return symbol_type (token::vert, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_bleu (location_type l)
      {
        return symbol_type (token::bleu, std::move (l));
      }
#else
      static
      symbol_type
      make_bleu (const location_type& l)
      {
        return symbol_type (token::bleu, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_jaune (location_type l)
      {
        return symbol_type (token::jaune, std::move (l));
      }
#else
      static
      symbol_type
      make_jaune (const location_type& l)
      {
        return symbol_type (token::jaune, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_violet (location_type l)
      {
        return symbol_type (token::violet, std::move (l));
      }
#else
      static
      symbol_type
      make_violet (const location_type& l)
      {
        return symbol_type (token::violet, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_magenta (location_type l)
      {
        return symbol_type (token::magenta, std::move (l));
      }
#else
      static
      symbol_type
      make_magenta (const location_type& l)
      {
        return symbol_type (token::magenta, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_cyan (location_type l)
      {
        return symbol_type (token::cyan, std::move (l));
      }
#else
      static
      symbol_type
      make_cyan (const location_type& l)
      {
        return symbol_type (token::cyan, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_noir (location_type l)
      {
        return symbol_type (token::noir, std::move (l));
      }
#else
      static
      symbol_type
      make_noir (const location_type& l)
      {
        return symbol_type (token::noir, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_blanc (location_type l)
      {
        return symbol_type (token::blanc, std::move (l));
      }
#else
      static
      symbol_type
      make_blanc (const location_type& l)
      {
        return symbol_type (token::blanc, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOM_HEX (std::string v, location_type l)
      {
        return symbol_type (token::NOM_HEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOM_HEX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOM_HEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOM_RGB (std::string v, location_type l)
      {
        return symbol_type (token::NOM_RGB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOM_RGB (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOM_RGB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L (location_type l)
      {
        return symbol_type (token::L, std::move (l));
      }
#else
      static
      symbol_type
      make_L (const location_type& l)
      {
        return symbol_type (token::L, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_G (location_type l)
      {
        return symbol_type (token::G, std::move (l));
      }
#else
      static
      symbol_type
      make_G (const location_type& l)
      {
        return symbol_type (token::G, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_E (location_type l)
      {
        return symbol_type (token::E, std::move (l));
      }
#else
      static
      symbol_type
      make_E (const location_type& l)
      {
        return symbol_type (token::E, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ETLOG (location_type l)
      {
        return symbol_type (token::ETLOG, std::move (l));
      }
#else
      static
      symbol_type
      make_ETLOG (const location_type& l)
      {
        return symbol_type (token::ETLOG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OU (location_type l)
      {
        return symbol_type (token::OU, std::move (l));
      }
#else
      static
      symbol_type
      make_OU (const location_type& l)
      {
        return symbol_type (token::OU, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ESTPAS (location_type l)
      {
        return symbol_type (token::ESTPAS, std::move (l));
      }
#else
      static
      symbol_type
      make_ESTPAS (const location_type& l)
      {
        return symbol_type (token::ESTPAS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EST (location_type l)
      {
        return symbol_type (token::EST, std::move (l));
      }
#else
      static
      symbol_type
      make_EST (const location_type& l)
      {
        return symbol_type (token::EST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v, location_type l)
      {
        return symbol_type (token::IDENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAINE (std::string v, location_type l)
      {
        return symbol_type (token::CHAINE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAINE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CHAINE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PV (location_type l)
      {
        return symbol_type (token::PV, std::move (l));
      }
#else
      static
      symbol_type
      make_PV (const location_type& l)
      {
        return symbol_type (token::PV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_V (location_type l)
      {
        return symbol_type (token::V, std::move (l));
      }
#else
      static
      symbol_type
      make_V (const location_type& l)
      {
        return symbol_type (token::V, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


    class context
    {
    public:
      context (const  Parser & yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const  Parser & yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 329,     ///< Last index in yytable_.
      yynnts_ = 26,  ///< Number of nonterminal symbols.
      yyfinal_ = 58 ///< Termination state number.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;

  };


} // yy
#line 2713 "/home/etud/Documents/abed_arina_abouakil_ibrahim/build/parser.hpp"




#endif // !YY_YY_HOME_ETUD_DOCUMENTS_ABED_ARINA_ABOUAKIL_IBRAHIM_BUILD_PARSER_HPP_INCLUDED
