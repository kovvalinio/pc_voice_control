 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <QFileDialog>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::fstream file;


    file.open("C:/Users/Michal/OneDrive/Documents/voice_control/config.txt", std::fstream::in | std::fstream::out);

    std::string command = ui->textEdit->toPlainText().toStdString();
    std::string path = ui->textEdit_2->toPlainText().toStdString();

    if(command.size() != 0 && path.size()){
        if(file.is_open()){

            file.seekg(0, file.end);

            for(int i = 0 ; i < static_cast<int>(command.size()); i++){

                file << command[i];
            }

            file << ";";

            for(int i = 0 ; i < static_cast<int>(path.size()); i++){

                file << path[i];
            }

            file << std::endl;

            check_actual_commands();

            ui->textEdit->clear();
            ui->textEdit_2->clear();

        }
    }
}






void MainWindow::on_textEdit_textChanged()
{
    text = ui->textEdit->toPlainText();
}

void MainWindow::check_actual_commands(){

    std::fstream file;


    file.open("C:/Users/Michal/OneDrive/Documents/voice_control/config.txt", std::fstream::in | std::fstream::out);

    if(file.is_open()){

        file.seekg(0, file.beg);

        ui->listWidget->clear();

        while(!file.eof()){
            std::string buffer;
            getline(file,buffer);

            ui->listWidget->addItem(QString::fromStdString(buffer));
        }
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->pushButton_2->setEnabled(1);
    selected_line = *item;
}


void MainWindow::on_pushButton_2_clicked()
{

            std::fstream database;

            fstream outputFile("C:/Users/Michal/OneDrive/Documents/voice_control/outputFileName", std::fstream::in | std::fstream::out | std::fstream::app);

            database.open("C:/Users/Michal/OneDrive/Documents/voice_control/config.txt", std::fstream::in | std::fstream::out | std::fstream::app);

            if(database.is_open()){

                database.seekg(0, database.beg);

                string line;
                while(getline(database, line)){
                    if(line != selected_line.text().toStdString()){
                        outputFile << line << endl;
                    }
                }
                database.close();
                outputFile.close();
                remove("C:/Users/Michal/OneDrive/Documents/voice_control/config.txt");
                if(rename("C:/Users/Michal/OneDrive/Documents/voice_control/outputFileName","C:/Users/Michal/OneDrive/Documents/voice_control/config.txt")!=0){
                std::cout<<"error"<<std::endl;
                }




            }
            check_actual_commands();
}


void MainWindow::on_pushButton_3_clicked()
{
        QString filename = QFileDialog::getOpenFileName(this, "open a file", "C:/");
        ui->textEdit_2->setPlainText('"'+filename+'"');
}

