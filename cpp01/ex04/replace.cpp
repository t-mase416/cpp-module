#include "replace.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {

}

FileReplacer::~FileReplacer() {

}

//private内の関数のトリガーになる公開用関数
bool    FileReplacer::execute() const {
    std::string content = _readFileToString();
    if (content.empty())
        return (false);
    std::string replacedContent = _replace(content);
    if (!_writeOutputFile(replacedContent)) 
        return (false);
    return (true);
}

//ファイルを読み取って一行の文字列にする

std::string FileReplacer::_readFileToString() const {
    std::ifstream   file(this->_filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << this->_filename << std::endl;
        return ("");
    }
    std::string content = "";
    std::string line;
    while (std::getline(file, line)) {
        content += line;
        if (!file.eof()) {
            content += "\n";
        }
    }
    file.close();
    return (content);
}

//文字列の中身をサーチし、s1があればs2に置換する
std::string FileReplacer::_replace(std::string content) const {
    if (this->_s1.empty()) 
        return (content);
    std::string result = "";
    size_t  startPos = 0;
    while (true) {
        size_t found = content.find(this->_s1, startPos);
        if (found != std::string::npos) {
            result += content.substr(startPos, found - startPos);
            result += this->_s2;
            startPos = found + _s1.length();
        }
        else 
            break;
    }
    result += content.substr(startPos);
    return (result);
}

//出来上がった文字列をfilename.replaceに出力する

bool FileReplacer::_writeOutputFile(const std::string& content) const {
    std::string outFilename = _filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error : Could not create output file " << outFilename << std::endl;
        return (false); 
    }
    outFile << content;
    outFile.close();
    return (true);
}