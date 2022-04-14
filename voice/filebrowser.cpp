#include "filebrowser.h"
#include "ui_filebrowser.h"

FileBrowser::FileBrowser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
}

FileBrowser::~FileBrowser()
{
    delete ui;
}
