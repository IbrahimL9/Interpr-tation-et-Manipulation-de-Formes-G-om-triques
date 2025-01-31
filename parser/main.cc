#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

int main( int  argc, char* argv[]) {
    Driver * driver = new Driver;
    Scanner * scanner = new Scanner(std::cin, std::cout);
    yy::Parser * parser = new yy::Parser(*scanner, *driver);

    parser->parse();

    std::ofstream fichier("dessin.svg");
        fichier << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">" << std::endl;

        auto formes= driver->getVariables().getVar_sans_aff().getVariable_sans_affect();
        for (const auto& forme : formes) {
            fichier << forme->dessiner();
        }
        fichier << "</svg>" << std::endl;
        fichier.close();

    return 0;
}
