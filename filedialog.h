#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT
protected:
    QString path;
public:
    FileDialog(QWidget *parent = 0,QString pth = 0);
    ~FileDialog();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::FileDialog *ui;
};

#endif // FILEDIALOG_H
