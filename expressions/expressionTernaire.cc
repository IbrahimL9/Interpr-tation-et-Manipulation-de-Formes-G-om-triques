#include "expressionTernaire.hh"

ExpressionTernaire::ExpressionTernaire(bool condition, ExpressionPtr exp1, ExpressionPtr exp2, OperateurTernaire op):
    _condition(condition), _exp1(exp1), _exp2(exp2),  _op(op) {}

void ExpressionTernaire::calculer( Contexte_fig& contexte)  {
    
    switch (_op) {
        case OperateurTernaire::ifthenelse:
            {
             
                if (_condition) return _exp1->calculer(contexte);
                else return _exp2->calculer(contexte);
                break;
            }
       case OperateurTernaire::ifthen:
             { if (_condition) return _exp1->calculer(contexte);
                break;
          }
        default:;
    }
}
