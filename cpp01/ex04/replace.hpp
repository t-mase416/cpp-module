#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class FileReplacer {
    public:
        FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
        ~FileReplacer();
        bool    execute() const;
    private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _readFileToString() const;
    std::string _replace(std::string line) const;
    bool _writeOutputFile(const std::string& content) const;
};

#endif