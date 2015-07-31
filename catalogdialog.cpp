#include "catalogdialog.h"
#include "ui_catalogdialog.h"


#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

#include <string.h>
#include <stdlib.h>

#include <QStack>
#include "filedeleter.h"

CatalogDialog::CatalogDialog(QWidget *parent, QString dir) :
    QDialog(parent),
    ui(new Ui::CatalogDialog)
{
    ui->setupUi(this);
    path=dir;
    catalogs = new QStack<QString>();
    files = new QStack<QString>();
}

CatalogDialog::~CatalogDialog()
{
    delete catalogs;
    delete files;
    delete ui;
}

void CatalogDialog::on_pushButtonClose_clicked()
{
    QDialog::close();
}

void CatalogDialog::on_pushButtonStart_clicked()
{
    ui->pushButtonStart->setEnabled(false);
    ui->radioButtonComplex->setEnabled(false);
    ui->radioButtonSimple->setEnabled(false);
    ui->radioButtonMedium->setEnabled(false);
    ui->textEdit->textCursor().insertText(QString("Сбор информации о файлах и подкаталогах ")+path+QString("\n"));
    getDirInfo((char*)path.toStdString().c_str());

    ui->textEdit->textCursor().insertText(QString("Удаление файлов:\n"));
    for(int i=0;i<files->length();i++){
        ui->textEdit->textCursor().insertText(files->at(i)+QString("\n"));
        FileDeleter *fd = new FileDeleter((char*)files->at(i).toStdString().c_str());//обработчик файла
        if(fd->isNull()){
            delete fd;
            ui->textEdit->textCursor().insertText("Не удалось открыть файл"+files->at(i)+"\n");
            continue;
        }
        QObject::connect(fd, SIGNAL(progress(int)), ui->progressBarFile, SLOT(setValue(int)));
        QObject::connect(fd, SIGNAL(progress(int)), ui->textEdit, SLOT(update()));
        if(ui->radioButtonSimple->isChecked())fd->simpleRewrite();
        if(ui->radioButtonComplex->isChecked())fd->complexRewrite();
        if(ui->radioButtonMedium->isChecked())fd->mediumRewrite();
        ui->progressBar->setValue((int)((i+1)*100/files->length()));
        delete fd;
    }
    ui->progressBarFile->setValue(100);
    ui->textEdit->textCursor().insertText(QString("Удаление каталогов:\n"));
    for(int i=0;i<catalogs->length();i++){
        ui->textEdit->textCursor().insertText(catalogs->at(i)+QString("\n"));
        for(int i=0;i<catalogs->length();i++){
            remove((char*)catalogs->at(i).toStdString().c_str());
        }
    }
    ui->textEdit->textCursor().insertText(path+QString("\n"));
    remove((char*)path.toStdString().c_str());
    ui->progressBar->setValue(100);
    ui->textEdit->textCursor().insertText(QString("Выполнено!")+QString("\n"));
}
void CatalogDialog::getDirInfo(char *dirname){
    DIR *d;
    d=opendir(dirname);
    struct dirent *dir=readdir(d);
    while(dir){
        char tmp[4096];
        if( (strcmp(dir->d_name,".")==0) || ((strcmp(dir->d_name,"..")==0)) ){
            dir=readdir(d);
            continue;
        }
        strcpy(tmp,dirname);
        strcat(tmp,"/");
        strcat(tmp,dir->d_name);

        if( dir->d_type==4 ){
            catalogs->push_back(QString(tmp));
            getDirInfo(tmp);
        }
        else files->push_back(QString(tmp));
        dir=readdir(d);
    }
    closedir(d);
    return;
}
