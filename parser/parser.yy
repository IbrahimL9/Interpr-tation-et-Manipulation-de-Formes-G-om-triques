%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
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
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }
%define parse.error verbose //affichage d'erreur

%code{
    #include <iostream>
    #include <string>
    #include "scanner.hh"
    #include "driver.hh"
    #include <memory>
    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token <int>            NUMBER
%token TAILLE CARRE RECTANGLE TRIANGLE CERCLE ELLIPSE LIGNE CHEMIN TEXTE
%token FLECHE ET OUVRE_ACCOLADE FERME_ACCOLADE COULEUR ROTATION REMPLISSAGE OPACITE EPAISSEUR DP
%token SI ALORS SINON TANT_QUE REPETE FONCTION
%token BOOLEEN ENT REEL
%token X Y X1 Y1 X2 Y2 X3 Y3 X4 Y4 HAUTEUR LARGEUR RAY T
%token  <bool> BOOL
%token  <double> DOUBLE

%token rouge vert bleu jaune violet magenta cyan noir blanc
%token <std::string> NOM_HEX NOM_RGB

%token  L LE G GE E NE  ETLOG OU ESTPAS EST 
 
%token <std::string> IDENT
%token <std::string> CHAINE
%token PV V

%type <std::string> coul
%type <std::string> color
%type <int>             operation

%type <std::shared_ptr<Taille>> taille
%type <std::shared_ptr<Forme>> figure
%type <std::shared_ptr<Forme>> figure_att
%type <std::vector<int>> coordonnees
%type <std::vector<Attributs>> liste_acc
%type <std::vector<Attributs>> liste_fleche
%type <Attributs> attributs
%type <Attributs> attributs_variable
%type <std::string> variable
%type <std::string> fig
%type <std::string> SIGNE
%type <std::string>  critere
%type <bool> IS
%type <bool> predicat
%type <bool> comparaison
%type <std::shared_ptr<Expression>> ope
%type <std::shared_ptr<Expression>> suite

%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction  programme{
    }
    |NL programme{}
    |YYEOF {
           std::cout << "#-> " << driver.varAttToString() << std::endl;
           std::cout << "#-> " << driver.varSansAffectationToString() << std::endl;
           std::cout << "#-> " << driver.varIdbToString() << std::endl;
           std::cout << "#-> " << driver.couleur_toString() << std::endl;
           
        YYACCEPT;
    };

instruction:
    expression  {
    }
    |affectation PV NL {
    }
    |variable  NL{
    }
    |taille PV NL{
        std::cout << "#-> " << $1->tostring() << std::endl;
    }
    |modif{};

expression:
    ope{ try{
        $1->calculer(driver.getContexte());
        } catch (const std::exception& err){
            std::cerr << "#-> " << err.what() << std::endl;
        }
    };
    
taille:
    TAILLE NUMBER NUMBER {
          $$ = std::make_shared<Taille>($2,$3);
    };
    
//instruction simple             
figure:
    RECTANGLE  NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Rectangle>($2,$3,$4,$5,$6,$7,$8,$9);
    }
    | CARRE  NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Carre>($2,$3,$4);
    }
    | TRIANGLE NUMBER NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Triangle>($2, $3, $4, $5);
    }
     | CERCLE NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Cercle>($2, $3, $4);
    }
    | ELLIPSE NUMBER NUMBER NUMBER NUMBER{
        $$ = std::make_shared<Ellipse>($2, $3, $4, $5);
    }
    | LIGNE NUMBER NUMBER NUMBER NUMBER {
        $$ = std::make_shared<Ligne>($2, $3, $4, $5);
    }
    | CHEMIN coordonnees {
        if ($2.size() % 2 == 0) { 
            std::vector<std::pair<int, int>> points;
            for (unsigned int i = 0; i < $2.size(); i += 2) {
                points.push_back(std::make_pair($2.at(i), $2.at(i + 1)));
            }
            $$ = std::make_shared<Chemin>(points);
        } else {
            std::cerr << "Erreur : Nombre impair de coordonnées pour un chemin." << std::endl;
        }
    }
    | TEXTE NUMBER NUMBER CHAINE CHAINE {
        $$ = std::make_shared<Texte>($2, $3, $4, $5);
    };
   

//creation de figure avec des attribus
figure_att:
    figure FLECHE attributs  liste_fleche PV{
         $1->ajouterAttribut($3) ;
        for(auto i : $4){
            $1->ajouterAttribut(i) ;
        }
        $$=$1;
    }
    |figure OUVRE_ACCOLADE  NL attributs  PV liste_acc FERME_ACCOLADE {
        $1->ajouterAttribut($4) ;
        for(auto i : $6){
            $1->ajouterAttribut(i) ;
        }
                $$=$1;
      }
      |figure PV{ $$ =$1; };

liste_fleche:
    ET attributs liste_fleche {
        $3.push_back($2); 
        $$ = $3;
    }
    | { $$ = std::vector<Attributs>(); } ;

liste_acc:
      NL attributs PV  NL liste_acc {
        $5.push_back($2); 
        $$ = $5;
    }
    | { $$ = std::vector<Attributs>(); } ;

    

coordonnees:
      NUMBER NUMBER {
          $$ = std::vector<int>{ $1, $2 };
      }
      | coordonnees V NUMBER NUMBER {
          $1.push_back($3);
          $1.push_back($4);
          $$ = $1;
      };



attributs:
        COULEUR DP color {
            Attributs att; 
            att.couleur = std::make_shared<std::string>($3);
            $$ = att;
        }
        | ROTATION DP NUMBER{
            Attributs att;
            att.rotation = std::make_shared<int>($3);
            $$ = att;
        }
        | REMPLISSAGE DP color{
            Attributs att;
            att.remplissage = std::make_shared<std::string>($3);
            $$ = att;
        }
        | OPACITE DP NUMBER{
            Attributs att;
            att.opacite = std::make_shared<int>($3);
            $$ = att;
        }
        | EPAISSEUR DP NUMBER{
            Attributs att;
            att.epaisseur = std::make_shared<int>($3);
            $$ = att;
        };
        
attributs_variable:
        COULEUR '=' color {
            Attributs att; 
            att.couleur = std::make_shared<std::string>($3);
            $$ = att;
        }
        | ROTATION '=' NUMBER{
            Attributs att;
            att.rotation = std::make_shared<int>($3);
            $$ = att;
        }
        | REMPLISSAGE '=' color{
            Attributs att;
            att.remplissage = std::make_shared<std::string>($3);
            $$ = att;
        }
        | OPACITE '='  NUMBER{
            Attributs att;
            att.opacite = std::make_shared<int>($3);
            $$ = att;
        }
        | EPAISSEUR '=' NUMBER{
            Attributs att;
            att.epaisseur = std::make_shared<int>($3);
            $$ = att;
        };
        

//creation et modification des attribus dune figure    
variable:
    IDENT '=' figure_att {
        driver.ajouterVariableForme($1,$3);
        driver.ajouterVariableSansAffectation($3);
    }
    | IDENT '.' attributs_variable PV{
        driver.ajouterAttributVariableForme($1, $3);
    }
    |fig '[' NUMBER ']' '.' attributs_variable PV{
        driver.ajouterAttribut($1,$3,$6);
    }
    |figure_att{
        driver.ajouterVariableSansAffectation($1);
    }
    |fig '[' NUMBER ']' PV{
       std::cout<< driver.afficher($1,$3);
    }
    | ENT IDENT '=' NUMBER PV{
        driver.ajouterIdb($2, $4);
    }
    | REEL IDENT '='  DOUBLE PV{
        driver.ajouterIdb($2, $4);
    }
    | BOOLEEN IDENT '=' BOOL PV{
        driver.ajouterIdb($2, $4);
    }
    | COULEUR IDENT '=' color PV{
        driver.ajouterCouleur($2, $4);
    };
    
 fig:
 RECTANGLE{
        $$ ="rectangle";
    }
    | CARRE{
        $$ ="carre" ;
    }
    | TRIANGLE{
        $$ ="triangle" ;
    }
     | CERCLE{
        $$ ="cercle";
    }
    | ELLIPSE{
        $$ ="ellipse";
    }
    | LIGNE{
        $$ = "ligne";
    }
    | CHEMIN{
            $$ ="chemin"  ;
    }
    | TEXTE{
        $$ ="texte";
    };   

critere:
   X1{
   $$="X1";}
   |Y1{
   $$="Y1";}
   |X2{
   $$="X2";}
   |Y2{
   $$="Y2";}
   |X3{
   $$="X3";}
   |Y3{
   $$="Y3";}
   |X4 {
   $$="X4";}
   |Y4{
   $$="Y4";}
   |TAILLE{
   $$="taille";}
   |X{
   $$="X";}
   |Y{
   $$="Y";}
   |LARGEUR{
   $$="largeur";}
   |HAUTEUR{
   $$="hauteur";}
   |RAY{
   $$="ray";};
    
    
//modifier les critere d'une figure donnée comme posisitionX par exp , la fonction appliquerModification verifie que la figure a comme atribus le critere sinn affche une erreur    
modif:
    fig '[' NUMBER ']' '.' critere '=' NUMBER {
        driver.appliquerModification($1,$3,$6,$8);
    }
    |IDENT '.' critere '=' NUMBER{
            driver.appliquerModification($1,$3,$5);
    };

    
color:
    coul { $$ = $1; }
    | NOM_HEX { $$ = $1; }
    | NOM_RGB { $$ = $1; };
    
    
coul:
    rouge { $$ = "rouge"; }
    | vert { $$ = "vert"; }
    | bleu { $$ = "bleu"; }
    | jaune { $$ = "jaune"; }
    | violet { $$ = "violet"; }
    | magenta { $$ = "magenta"; }
    | cyan { $$ = "cyan"; }
    | noir { $$ = "noir"; }
    | blanc { $$ = "blanc"; };

//condition    
ope:
    SI  comparaison  ALORS OUVRE_ACCOLADE NL ope  FERME_ACCOLADE NL suite  {
       if($6!=nullptr){
       if($9==nullptr){
                $$ = std::make_shared<ExpressionTernaire>($2,$6,$9,OperateurTernaire::ifthen);
        }
        else{
        $$ = std::make_shared<ExpressionTernaire>($2,$6,$9,OperateurTernaire::ifthenelse);
        }}else $$ = std::make_shared<ExpressionTernaire>(false,$6,$9,OperateurTernaire::ifthen);
    }  
    |IDENT '.' attributs_variable PV NL {
    $$= std::make_shared<ExpressionModif>($1,$3);
    }
    |fig '[' NUMBER ']' '.' attributs_variable PV NL {
    $$= std::make_shared<ExpressionModif>($1,$3,$6);
    }
    |IDENT '.' critere '=' NUMBER  PV NL {
    $$= std::make_shared<ExpressionCritere>($1,$3,$5);
    }
    |fig '[' NUMBER ']' '.' critere '=' NUMBER  PV NL {
    $$= std::make_shared<ExpressionCritere>($1,$3,$6,$8);
    }
    |{$$=nullptr;}; // dans le cas ou il ne faut rien faire comme operation on rtourne un nullptr cela nous permetra de reconnaitre ce cas et de retourner dans ExpressionTernaire la valeur false pour larguùent de comparason donc l'operation(qui est inexistante) ne sera alors pas calculé 
 
//possibilité de continuer la conditionnelle avec un else dans ce cas on retourne l'operation a effectuer ou si on s'arrete on retourne un nullptr cela permetra de gerer le cas ou il n y a pas else alors on retourneraa dans lexpresion ternaire avec comme argument OperateurTernaire::iften et non ifthenelse
suite:
    SINON OUVRE_ACCOLADE NL ope FERME_ACCOLADE{
    $$=$4;}
    |{
        $$=nullptr;
    };

SIGNE:
    G{
    $$=">";}
    |GE{
    $$=">=";}
    |L{
    $$="<";}
    |LE{
    $$="<=";}
    |E{
    $$="==";}
    |NE{
    $$="!=";};
 
//permet de retourner un booleen equivalent à ce que doit etre egale la condition pour qu'elle soit consideré comme vrai (juste pour l'attribus couleur)
IS:
    EST{
    $$=true;
    }
    |ESTPAS{
    $$=false; };

//possibilité de generer plusieurs condition à la suite separé par des et/ou logique 
comparaison:
    predicat{
        $$=$1;}
    |'(' predicat ETLOG comparaison ')'{
        $$=($2 && $4);
    }
    | '(' predicat OU comparaison ')'{
     $$=($2 || $4);
};
    
//retourne booleen qui represente la valeur de la condition 
predicat:
    '('IDENT '.' critere SIGNE NUMBER ')'{
       $$=driver.evaluation($2,$4,$5,$6);
    }
    |'('IDENT '.' COULEUR IS color')'{
        $$=driver.evaluationcouleur($2,$5,$6);}
    |'(' fig '[' NUMBER ']'  '.' critere SIGNE NUMBER ')'{
       $$=driver.evaluation($2,$4,$7,$8,$9);
    }
    |'(' fig '[' NUMBER ']' '.' COULEUR IS color')'{
        $$=driver.evaluationcouleur($2,$4,$8,$9);};


expression:
    operation{
        //Modifier cette partie pour prendre en compte la structure avec expressions
        std::cout << "#-> " << $1 << std::endl;
     };

affectation:
    '=' { std::cout << "Affectation à réaliser" << std::endl;
    };

operation:
    NUMBER {
        $$ = $1;
    }
    |BOOL {
        $$ = $1;
    }
    |DOUBLE {
        $$ = $1;
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = $1 + $3;
    }
    | operation '-' operation {
        $$ = $1 - $3;
    }
    | operation '*' operation {
        $$ = $1 * $3;
    }
    | operation '/' operation {
        $$ = $1 / $3;
    }
    | '-' operation %prec NEG {
        $$ = - $2;
    };

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
