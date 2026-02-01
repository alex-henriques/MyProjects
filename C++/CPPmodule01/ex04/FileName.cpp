#include "FileName.hpp"
#include <iostream>
#include <fstream>

FileReplace::FileReplace(const std::string& filename, const std::string& s1, const std::string& s2) : filename(filename), s1(s1), s2(s2) {}
//nothing in the brackets because everything happens in the initialiser list

bool    FileReplace::validInput() const {
    if (filename.empty()) {
        std::cerr << "Error: Filename is empty" << std::endl;
        return false;
    }
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return false;
    }
    return true;
}

std::string FileReplace::readFile() const {
    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: Could not open file" << std::endl;
        return "";
    }
    std::string content;
    std::string line;
    while (std::getline(in, line)) {
        content += line;
        if (!in.eof()) {
            content += "\n";
        }
    }
    in.close();
    return content;
}

std::string FileReplace::replaceString(const std::string& content) const {
    std::string res;
    std::size_t position = 0;
    std::size_t found;

    while (true) {
        found = content.find(s1, position);
        if (found == std::string::npos) {
            res += content.substr(position);
            break;
        }
        res += content.substr(position, found - position);
        res += s2;
        position = found + s1.length();
    }
    return res;
}

bool    FileReplace::writeToFile(const std::string& content) const {
    std::string outname = filename + ".replace";
    std::ofstream out(outname.c_str());
    if (!out) {
        std::cerr << "Error: cannot open file" << std::endl;
        return false;
    }
    out << content;
    out.close();
    return true;
}

bool    FileReplace::processFile() const {
    if (!validInput()) {
        return false;
    }
    std::string content = readFile();
    if (content.empty() && !std::ifstream(filename.c_str())) {
        return false;
    }
    std::string replaced = replaceString(content);
    return writeToFile(replaced);
}