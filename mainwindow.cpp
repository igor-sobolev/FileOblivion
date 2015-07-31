#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "filedialog.h"
#include <QFileDialog>
#include "catalogdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAbout_triggered()
{
    About *a = new About();
    a->show();
}

void MainWindow::on_actionFile_triggered()
{
    QString name;
    name=QFileDialog::getOpenFileName(this,QString("Выберите файл..."),QString("."));//диалог выбора файла
    if(name==NULL)return;//если диалог был закрыт, то ничего не делаем и выходим из функции
    FileDialog *fd = new FileDialog(this,name);//иначе открываем окно диалога файла
    fd->show();
}

void MainWindow::on_actionCatalogue_triggered()
{
    QString namedir;
    namedir=QFileDialog::getExistingDirectory(this,QString("Выберите каталог..."));//диалог выбора каталога
    if(namedir==NULL)return;//если диалог был закрыт, то ничего не делаем и выходим из функции
    CatalogDialog *cd = new CatalogDialog(this,namedir);
    cd->show();
}
