#include "filedialog.h"
#include "ui_filedialog.h"
#include "filedeleter.h"

FileDialog::FileDialog(QWidget *parent, QString pth) :
    QDialog(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
    path=pth;
}

FileDialog::~FileDialog()
{
    delete ui;
}

void FileDialog::on_pushButtonStart_clicked()
{
    ui->pushButtonClose->setEnabled(false);//если файл обрабатывается нельзя закрыть окно
    ui->pushButtonStart->setEnabled(false);
    ui->radioButtonComplex->setEnabled(false);
    ui->radioButtonSimple->setEnabled(false);
    ui->radioButtonMedium->setEnabled(false);
    ui->textEdit->textCursor().insertText("Обрабатываем файл "+path+"\n");
    FileDeleter *fd = new FileDeleter((char*)path.toStdString().c_str());//обработчик файла
    if(fd->isNull()){
        delete fd;
        ui->textEdit->textCursor().insertText("Не удалось открыть файл"+path+"\n");
        return;
    }
    QObject::connect(fd, SIGNAL(progress(int)), ui->progressBar, SLOT(setValue(int)));
    //QObject::connect(fd, SIGNAL(progress(int)), ui->textEdit, SLOT(update()));
    if(ui->radioButtonSimple->isChecked())fd->simpleRewrite();
    if(ui->radioButtonComplex->isChecked())fd->complexRewrite();
    if(ui->radioButtonMedium->isChecked())fd->mediumRewrite();
    ui->textEdit->textCursor().insertText("Выполнено!");
    ui->pushButtonClose->setEnabled(true);
    ui->progressBar->setValue(100);
    delete fd;
}

void FileDialog::on_pushButtonClose_clicked()
{
    QDialog::close();
}
