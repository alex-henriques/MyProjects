#ifndef FILENAME_HPP
#define FILENAME_HPP

#include <string>

class   FileReplace {
     public:
        FileReplace(const std::string& filename, const std::string& s1, const std::string& s2);
        bool    processFile() const;
    private:
        std::string filename;
        std::string s1;
        std::string s2;

        std::string readFile() const;
        bool writeToFile(const std::string& content) const;
        std::string replaceString(const std::string& content) const;
        bool validInput() const;
};

#endif
