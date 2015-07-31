#ifndef CATALOGDIALOG_H
#define CATALOGDIALOG_H

#include <QDialog>

namespace Ui {
class CatalogDialog;
}

class CatalogDialog : public QDialog
{
    Q_OBJECT
protected:
    QString path;
    QStack<QString> *catalogs;
    QStack<QString> *files;
public:
    CatalogDialog(QWidget *parent = 0, QString dir = 0);
    ~CatalogDialog();
    void getDirInfo(char*);

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonStart_clicked();

private:
    Ui::CatalogDialog *ui;
};

#endif // CATALOGDIALOG_H
