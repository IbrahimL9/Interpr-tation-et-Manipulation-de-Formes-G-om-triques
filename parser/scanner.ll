%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap


%%
%{
    yylval = lval;
%}


"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"[" return '[';
"]" return ']';
"=" return '=';

(?i:taille)       return token::TAILLE; 
(?i:carré)        return token::CARRE; 
(?i:rectangle)    return token::RECTANGLE; 
(?i:triangle)    return token::TRIANGLE; 
(?i:cercle)       return token::CERCLE;
(?i:ellipse)      return token::ELLIPSE;
(?i:ligne)        return token::LIGNE; 
(?i:chemin)       return token::CHEMIN; 
(?i:texte)        return token::TEXTE; 
";"            return token::PV;
","            return token::V;

"<" return token::L;
"<=" return token::LE;;
">" return token::G;
">=" return token::GE;
"==" return token::E;
"!=" return token::NE;

"&&" return token::ETLOG;
"||" return token::OU;

(?i:est)           return token::EST;
(?i:n'est)[ ]*(?i:pas)      return token::ESTPAS;

":"             return token::DP;
"->"            return token::FLECHE;
"&"             return token::ET; 
"{"             return token::OUVRE_ACCOLADE; 
"}"             return token::FERME_ACCOLADE; 
(?i:couleur)       return token::COULEUR; 
(?i:rotation)      return token::ROTATION; 
(?i:remplissage)   return token::REMPLISSAGE; 
(?i:opacité)       return token::OPACITE; 
(?i:épaisseur)     return token::EPAISSEUR; 
(?i:si)            return token::SI; 
(?i:alors)         return token::ALORS; 
(?i:sinon)         return token::SINON; 
(?i:tant_que)      return token::TANT_QUE; 
(?i:repete)        return token::REPETE; 
(?i:fonction)      return token::FONCTION;
(?i:booléen)       return token::BOOLEEN;
(?i:entier)        return token::ENT;
(?i:réel)          return token::REEL;

(?i:positionX)      return token::X; 
(?i:positionY)      return token::Y; 
(?i:positionX1)     return token::X1; 
(?i:positionY1)     return token::Y1; 
(?i:positionX2)     return token::X2; 
(?i:positionY2)     return token::Y2; 
(?i:positionX3)     return token::X3; 
(?i:positionY3)     return token::Y3; 
(?i:positionX4)     return token::X4; 
(?i:positionY4)     return token::Y4; 
(?i:hauteur)        return token::HAUTEUR; 
(?i:largeur)       return token::LARGEUR; 
(?i:rayon)           return token::RAY;

(?i:rouge)       return token::rouge; 
(?i:vert)        return token::vert; 
(?i:bleu)        return token::bleu; 
(?i:jaune)       return token::jaune; 
(?i:violet)      return token::violet; 
(?i:magenta)     return token::magenta; 
(?i:cyan)        return token::cyan; 
(?i:noir)        return token::noir; 
(?i:blanc)       return token::blanc; 

rgb\([0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\) {
    yylval->build<std::string>(YYText()); //RGB
    return token::NOM_RGB;
}


\#([0-9A-Fa-f]{6}) {
    yylval->build<std::string>(YYText()); //hexadécimale
    return token::NOM_HEX;
}


[0-9]+ {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER; 
}

[0-9]+(\.[0-9]+)?     {
    yylval->build<double>(std::atof(YYText()));
    return token::DOUBLE;
}


"true"          { lval->build<bool>(true); 
                        return token::BOOL; }

"false"         { lval->build<bool>(false); 
                        return token::BOOL; }



[ \t] {}

[a-zA-Z_][a-zA-Z0-9_]*   {
    yylval->build<std::string>(YYText());
    return token::IDENT;
}

"." {
    return '.';
}


\"([^"\\]*(\\.[^"\\]*)*)\" {
    yylval->build<std::string>(std::string(yytext + 1, yyleng - 2)); 
    return token::CHAINE;
}

"%" { }
"°" { }

"\n"          {
    loc->lines();
    return token::NL;
}


%%
