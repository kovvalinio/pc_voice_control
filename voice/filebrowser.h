#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QMainWindow>

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileBrowser(QWidget *parent = nullptr);
    ~FileBrowser();

private:
    Ui::FileBrowser *ui;
};

#endif // FILEBROWSER_H
