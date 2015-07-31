#ifndef FILEDELETER_H
#define FILEDELETER_H
#include <stdio.h>
#include <QString>
#include <QObject>
class FileDeleter: public QObject
{
    Q_OBJECT
protected:
    FILE *f;
    char *path;
    long long size;
    void readSize();
public:
    FileDeleter(char* pth);
    ~FileDeleter();
    void simpleRewrite();//нули
    void mediumRewrite();//рандомы
    void complexRewrite();//Гутман
    void deleteFile();
    bool isNull();
signals:
     void progress(int value);
};

#endif // FILEDELETER_H
