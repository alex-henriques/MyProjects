#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", SIGN_GRADE, EXEC_GRADE), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
    AForm::operator=(other);
    target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target =other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::executeAction() const {
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Couldn't create file " << filename << std::endl;
        return;
    }
    file << "       ______                                    ______" << std::endl;
    file << "      /      \\                                  /      \\" << std::endl;
    file << "     |  O  O  |                                |  O  O  |" << std::endl;
    file << "     |    >   |                                |   <    |" << std::endl;
    file << "     | \\____/ |                                | \\____/ |" << std::endl;
    file << "      \\______/                                  \\______/" << std::endl;
    file << "     _____|_____                                _____|_____" << std::endl;
    file << "    |   ARMOR   |                              |   ARMOR   |" << std::endl;
    file << "    |___________|                              |___________|" << std::endl;
    file << "    /  ||   ||  \\                              /  ||   ||  \\" << std::endl;
    file << "   |   ||   ||   |                            |   ||   ||   |" << std::endl;
    file << "   |   ||   ||   |                            |   ||   ||   |" << std::endl;
    file << "    \\  ||   ||  /                              \\  ||   ||  /" << std::endl;
    file << "     | ||   || |                                | ||   || |" << std::endl;
    file << "     | ||   || |                                | ||   || |" << std::endl;
    file << "    /  ||   ||  \\                              /  ||   ||  \\" << std::endl;
    file << "   |  /  \\ /  \\  |                            |  /  \\ /  \\  |" << std::endl;
    file << "   | |    X    | |                            | |    X    | |" << std::endl;
    file << "   |_|   / \\   |_|                            |_|   / \\   |_|" << std::endl;
    file << "  /  |  |   |  |  \\                          /  |  |   |  |  \\" << std::endl;
    file << " |___|__|   |__|___|                        |___|__|   |__|___|" << std::endl;
    file << std::endl;
    file << "           ███╗   ██╗██╗██╗           ███╗   ██╗██╗██╗" << std::endl;
    file << "           ████╗  ██║██║██║           ████╗  ██║██║██║" << std::endl;
    file << "           ██╔██╗ ██║██║██║           ██╔██╗ ██║██║██║" << std::endl;
    file << "           ██║╚██╗██║██║╚═╝           ██║╚██╗██║██║╚═╝" << std::endl;
    file << "           ██║ ╚████║██║██╗           ██║ ╚████║██║██╗" << std::endl;
    file << "           ╚═╝  ╚═══╝╚═╝╚═╝           ╚═╝  ╚═══╝╚═╝╚═╝" << std::endl;
    file << std::endl;
    file << "              \"WE ARE THE KNIGHTS WHO SAY... NI!\"" << std::endl;
    file << std::endl;
    file << "                   \"WE DEMAND... A SHRUBBERY!\"" << std::endl;
    file << std::endl;
    file << "                     \"One that looks nice...\"" << std::endl;
    file << "                  \"...and not too expensive.\"" << std::endl;
    file << std::endl;
    file << std::endl;
    file << "                        ccee88oo          " << std::endl;
    file << "                    C8O8O8Q8PoOb o8oo     " << std::endl;
    file << "                  dOB69QO8PdUOpugoO9bD     " << std::endl;
    file << "                 CgggbU8OU qOp qOdoUOdcb   " << std::endl;
    file << "                     6OuU  /p u gcoUodpP   " << std::endl;
    file << "                       \\\\//  /douUP        " << std::endl;
    file << "                         \\\\////            " << std::endl;
    file << "                          |||/\\            " << std::endl;
    file << "                          |||\\/            " << std::endl;
    file << "                          |||||            " << std::endl;
    file << "                    .....//||||\\.....      " << std::endl;

    file.close();
    std::cout << "Shrubbery created at " << filename << std::endl;
}