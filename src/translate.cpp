#include "../include/translate.hpp"
#include "../include/control_flow.hpp"
#include "../include/io.hpp"
#include "../include/variables.hpp"

#include <vector>

enum CommandType{
  _undefiend,
  _if,
  _or,
  _else,
  _create,
  _perform,
  _write,
  _put,
  _open,
  _set,
  _function,
  _takes,
  _returns,
  _does,
  _end,
  _close,
  _append
};

CommandType translate(std::string const& inString){
  CommandType val = _undefiend;
  if(inString == "if") { val = _if; }
  else if(inString == "or") { val = _or;}
  else if(inString == "else") { val = _else;}
  else if(inString == "create") { val = _create;}
  else if(inString == "perform") { val = _write;}
  else if(inString == "write") { val = _write;}
  else if(inString == "put") { val = _put;}
  else if(inString == "open") { val = _open;}
  else if(inString == "close") { val = _close;}
  else if(inString == "append") { val = _append;}
  else if(inString == "set") { val = _set;}
  else if(inString == "function") { val = _function;}
  else if(inString == "takes") { val = _takes;}
  else if(inString == "returns") { val = _returns;}
  else if(inString == "does") { val = _does;}
  else if(inString == "end") { val = _end;}
  return val;
}

int translate_command_from(std::string initial_token, std::string line, std::ofstream& outfile){
  CommandType identifier = translate(initial_token);
  int status = 0;
  switch(identifier){
    case(_if):
      IfStatement if_statement;
      if(if_statement.is_valid(line)){
        std::vector<std::string> tokens = if_statement.parse(line);
        if_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_or):
      OrStatement or_statement;
      if(or_statement.is_valid(line)){
        std::vector<std::string> tokens = or_statement.parse(line);
        or_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_else):
      ElseStatement else_statement;
      if(else_statement.is_valid(line)){
        else_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_end):
      EndStatement end_statement;
      if(end_statement.is_valid(line)){
        end_statement.write(outfile);
      }else{
        status = 1;
      }
      break;
    case(_write):
      WriteStatement write_statement;
      if(write_statement.is_valid(line)){
        std::vector<std::string> tokens = write_statement.parse(line);
        write_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_put):
      PutStatement put_statement;
      if(put_statement.is_valid(line)){
        std::vector<std::string> tokens = put_statement.parse(line);
        put_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_create):
      CreateStatement create_statement;
      if(create_statement.is_valid(line)){
        std::vector<std::string> tokens = create_statement.parse(line);
        create_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_open):
      OpenStatement open_statement;
      if(open_statement.is_valid(line)){
        std::vector<std::string> tokens = open_statement.parse(line);
        open_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_append):
      AppendStatement append_statement;
      if(create_statement.is_valid(line)){
        std::vector<std::string> tokens = append_statement.parse(line);
        append_statement.write(tokens, outfile);
      }else{
        status = 1;
      }
      break;
    case(_close):
      CloseStatement close_statement;
      if(close_statement.is_valid(line)){
        std::string filename = close_statement.parse(line);
        close_statement.write(filename, outfile);
      }else{
        status = 1;
      }
      break;
  }
  return status;
}