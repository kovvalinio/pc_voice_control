#include "open_file.h"




void open_file::add_command(const std::string com,const std::string path){
    commands.emplace_back(com);
    paths.emplace_back(path);

}
