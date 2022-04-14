#ifndef OPEN_FILE_H
#define OPEN_FILE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>

class open_file{
public:
    open_file();
    void add_command(const std::string com,const std::string path);
private:

    std::vector<std::string> commands;
    std::vector<std::string> paths;
};

#endif // OPEN_FILE_H
