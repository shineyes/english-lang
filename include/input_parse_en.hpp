#include <vector>
#include <string>
#include "types_en.hpp"

Verb string_to_verb(std::string command);

Identifier string_to_identifier(std::string command);

std::vector<std::string> tokenize(std::string input);

bool valid_command(std::string command);