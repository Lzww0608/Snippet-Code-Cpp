#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

class TextFileParser {
public:
    TextFileParser(const std::string& filePath);
    void parse();
    const std::vector<std::string>& getLines() const;
private:
    std::string filePath;
    std::vector<std::string> lines;
};


TextFileParser::TextFileParser(const std::string& file): filePath(file) {}

void TextFileParser::parse() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
}

const std::vector<std::string>& TextFileParser::getLines() const {
    return lines;
}

int main() {
    try {
        TextFileParser parser("example.txt");
        parser.parse();
        for (const auto& line : parser.getLines()) {
            std::cout << line << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
