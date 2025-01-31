#include "forme.hh"
#include <algorithm>

void Texte::setTexte(const std::string &value)
{
    texte = value;
}

void Texte::setPolice(const std::string &value)
{
    police = value;
}


void Forme::ajouterAttribut(const Attributs& att) {
        if (att.couleur) {
            bool couleurTrouvee = false;
            for (auto& attribut : _attributs) {
                if (attribut.couleur) {
                    attribut.couleur = att.couleur;
                    couleurTrouvee = true;
                    break;
                }
            }
            if (!couleurTrouvee) {
                Attributs nouveauAttribut;
                nouveauAttribut.couleur = att.couleur;
                _attributs.push_back(nouveauAttribut);
            }
        }

        if (att.rotation) {
            bool rotationTrouvee = false;
            for (auto& attribut : _attributs) {
                if (attribut.rotation) {
                    attribut.rotation = att.rotation;
                    rotationTrouvee = true;
                    break;
                }
            }
            if (!rotationTrouvee) {
                Attributs nouveauAttribut;
                nouveauAttribut.rotation = att.rotation;
                _attributs.push_back(nouveauAttribut);
            }
        }
        if (att.remplissage) {
                bool remplissageTrouve = false;
                for (auto& attribut : _attributs) {
                    if (attribut.remplissage) {
                        attribut.remplissage = att.remplissage;
                        remplissageTrouve = true;
                        break;
                    }
                }
                if (!remplissageTrouve) {
                    Attributs nouveauAttribut;
                    nouveauAttribut.remplissage = att.remplissage;
                    _attributs.push_back(nouveauAttribut);
                }
            }

            if (att.opacite) {
                bool opaciteTrouvee = false;
                for (auto& attribut : _attributs) {
                    if (attribut.opacite) {
                        attribut.opacite = att.opacite;
                        opaciteTrouvee = true;
                        break;
                    }
                }
                if (!opaciteTrouvee) {
                    Attributs nouveauAttribut;
                    nouveauAttribut.opacite = att.opacite;
                    _attributs.push_back(nouveauAttribut);
                }

             }

            if (att.epaisseur) {
                bool epaisseurTrouvee = false;
                for (auto& attribut : _attributs) {
                    if (attribut.epaisseur) {
                        attribut.epaisseur = att.epaisseur;
                        epaisseurTrouvee = true;
                        break;
                    }
                }
                if (!epaisseurTrouvee) {
                    Attributs nouveauAttribut;
                    nouveauAttribut.epaisseur = att.epaisseur;
                    _attributs.push_back(nouveauAttribut);
                }
            }


}



std::string Forme::tostring() const {
       std::ostringstream oss;

       for (const auto& attribut : _attributs) {
           if (attribut.couleur) {
               oss << "couleur : " << *attribut.couleur << " ";
           }
           if (attribut.rotation) {
               oss << "rotation : " << *attribut.rotation << " ";
           }
           if (attribut.remplissage) {
               oss << "remplissage : " << *attribut.remplissage << " ";
           }
           if (attribut.opacite) {
               oss << "opacite : " << *attribut.opacite << "% ";
           }
           if (attribut.epaisseur) {
               oss << "epaisseur : " << *attribut.epaisseur << " ";
           }
       }
       std::string ch = oss.str();

       if (!ch.empty()) {
               ch = " -> " + ch;
           }

           return ch;
   }



std::string Forme::getcouleur ()const{
for (const auto& attribut : _attributs) {
    if (attribut.couleur) {
        return *attribut.couleur;}
}
return "";

}



std::string Forme::traduireCouleur(const std::string& c) {
 if (c == "rouge") return "red";
 else if (c == "vert") return "green";
 else if (c == "bleu") return "blue";
 else if (c == "jaune") return "yellow";
 else if (c == "violet") return "purple";
 else if (c== "magenta") return "magenta";
 else if (c == "cyan") return "cyan";
 else if (c == "noir") return "black";
 else if (c == "blanc") return "white";
 else return c;
}


std::string Forme::style() const {

std::ostringstream style;
std::string couleur = "black";
std::string remplissage = "none";
std::string opacite = "1";
std::string epaisseur = "1";

for (const auto& att : _attributs) {
    if (att.couleur) {
        couleur = traduireCouleur(*att.couleur);
    }
    if (att.remplissage) {
        remplissage = traduireCouleur(*att.remplissage);
    }
    if (att.opacite) {
        opacite = std::to_string(*att.opacite / 100.0);
    }
    if (att.epaisseur) {
        epaisseur = std::to_string(*att.epaisseur);
    }
}

style << "stroke:" << couleur << ";"
      << "fill:" << remplissage << ";"
      << "fill-opacity:" << opacite << ";"
      << "stroke-width:" << epaisseur << ";";

return " style=\"" + style.str() + "\"";
}




std::string Rectangle::dessiner() const{
    std::ostringstream svg;
    int width = std::abs(x3 - x1);
        int height = std::abs(y3 - y1);
        svg << "<rect x=\"" << x1 << "\" y=\"" << y1
            << "\" width=\"" << width << "\" height=\"" << height << "\""
            << style();

        auto rotationAttribut = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; });
                if (rotationAttribut != _attributs.end() && rotationAttribut->rotation) {
                    int centerX = x1 + width / 2;
                    int centerY = y1 + height / 2;
                    svg << " transform=\"rotate(" << *rotationAttribut->rotation << " " << centerX << " " << centerY << ")\"";
                }

                svg << "/>";
    return svg.str();
}




std::string Carre::dessiner() const{
    std::ostringstream svg;
    svg << "<rect x=\"" << x << "\" y=\"" << y
        << "\" width=\"" << taille << "\" height=\"" << taille << "\""
        << style();
    if (auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; }); it != _attributs.end() && it->rotation) {
            int centerX = x + taille / 2;
            int centerY = y + taille / 2;
            svg << " transform=\"rotate(" << *it->rotation << " " << centerX << " " << centerY << ")\"";
        }

    svg << "/>";

    return svg.str();
}



std::string Triangle::dessiner() const {
    std::ostringstream svg;
    int centerX = x + longueur / 2;
        int centerY = y - hauteur / 2;

        svg << "<polygon points=\""
            << x << "," << y << " "
            << (x + longueur) << "," << y << " "
            << (x + longueur / 2) << "," << (y - hauteur) << "\""
            << style();

        if (auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; }); it != _attributs.end() && it->rotation) {
            svg << " transform=\"rotate(" << *it->rotation << " " << centerX << " " << centerY << ")\"";
        }

        svg << "/>";
    return svg.str();
}


std::string Cercle::dessiner() const{
    std::ostringstream svg;
    svg << "<circle cx=\"" << x << "\" cy=\"" << y
        << "\" r=\"" << rayon << "\""
        << style()
        << "/>\n";
    return svg.str();
}


std::string Ellipse::dessiner() const{
    std::ostringstream svg;
    svg << "<ellipse cx=\"" << x << "\" cy=\"" << y
            << "\" rx=\"" << longueur / 2 << "\" ry=\"" << hauteur / 2 << "\""
            << style();

        if (auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; }); it != _attributs.end() && it->rotation) {
            svg << " transform=\"rotate(" << *it->rotation << " " << x << " " << y << ")\"";
        }

     svg << "/>";
    return svg.str();
}


std::string Ligne::dessiner() const {
    std::ostringstream svg;
    int centerX = (x1 + x2) / 2;
       int centerY = (y1 + y2) / 2;

       svg << "<line x1=\"" << x1 << "\" y1=\"" << y1
           << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\""
           << style();

       if (auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; }); it != _attributs.end() && it->rotation) {
           svg << " transform=\"rotate(" << *it->rotation << " " << centerX << " " << centerY << ")\"";
       }

       svg << "/>";
    return svg.str();
}

std::string Chemin::dessiner() const{
    std::ostringstream svg;
    svg << "<path d=\"M ";
        for (const auto& point : points) {
            svg << point.first << " " << point.second << " ";
        }
        svg << "\"" << style();

        // Correction de l'initialisation if avec une syntaxe correcte
        if (!points.empty()) {
            auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; });
            if (it != _attributs.end() && it->rotation) {
                int centerX = points[0].first + (points.back().first - points[0].first) / 2;
                int centerY = points[0].second + (points.back().second - points[0].second) / 2;
                svg << " transform=\"rotate(" << *it->rotation << " " << centerX << " " << centerY << ")\"";
            }
        }

        svg << "/>";
        return svg.str();
}


std::string Texte::dessiner() const {
        std::ostringstream svg;
        svg << "<text x=\"" << x << "\" y=\"" << y << "\""
                << " font-family=\"" << police << "\""
                << style();

            if (auto it = std::find_if(_attributs.begin(), _attributs.end(), [](const Attributs& att) { return att.rotation; }); it != _attributs.end() && it->rotation) {
                svg << " transform=\"rotate(" << *it->rotation << " " << x << " " << y << ")\"";
            }

            svg << ">" << texte << "</text>";
        return svg.str();
}





















