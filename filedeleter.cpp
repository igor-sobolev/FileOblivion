#include "filedeleter.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include <QMessageBox>
FileDeleter::FileDeleter(char* pth):
    QObject(){//конструктор - сохраняет путь файла в поле и открывает файл
    path=new char[strlen(pth)+1];
    strcpy(path,pth);
    path[strlen(pth)]='\0';
    f=fopen(path,"r+");
    size=-1;
    if(f!=NULL)readSize();
    srand(time(0));
}

bool FileDeleter::isNull(){//проверка открылся ли файл
    if(f==NULL)return true;
    else return false;
}

FileDeleter::~FileDeleter(){
    delete[] path;
    fclose(f);
}

void FileDeleter::readSize(){//чтение размера файла
    if(f==NULL)return;
    fseek(f, 0L, SEEK_SET);//смещение в начало файла
    char c;
    do{
        c=fgetc(f);
        size++;
    }while(c!=EOF);
}

void FileDeleter::simpleRewrite(){//простая перезапись
    if(f==NULL)return;
    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",0);
        emit progress((int)((i+1)*100/size));
    }
    remove(path);
}

void FileDeleter::mediumRewrite(){//25 кратная перезапись случайными числами
    if(f==NULL)return;
    for(int k=0;k<25;k++){
        fseek(f, 0L, SEEK_SET);
        for(int i=0;i<size;i++){
            fprintf(f,"%c",rand()%128);
        }
        emit progress((int)((k+1)*100/25));
    }
    remove(path);
}

void FileDeleter::complexRewrite(){//35 кратная перезапись методом Гутмана
    if(f==NULL)return;
    for(int k=0;k<4;k++){
        fseek(f, 0L, SEEK_SET);
        for(int i=0;i<size;i++){
            fprintf(f,"%c",rand()%128);
        }
        emit progress((int)((k+1)*100/35));
    }

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",85);//01010101
    }
    emit progress((int)(5*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",170);//10101010
    }
    emit progress((int)(6*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",146);//10010010
    }
    emit progress((int)(7*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",73);//01001001
    }
    emit progress((int)(8*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",36);//00100100
    }
    emit progress((int)(9*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",0);//00000000
    }
    emit progress((int)(10*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",17);//00010001
    }
    emit progress((int)(11*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",34);//00100010
    }
    emit progress((int)(12*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",51);//00110011
    }
    emit progress((int)(13*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",68);//01000100
    }
    emit progress((int)(14*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",85);//01010101
    }
    emit progress((int)(15*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",102);//01100110
    }
    emit progress((int)(16*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",119);//01110111
    }
    emit progress((int)(17*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",136);//10001000
    }
    emit progress((int)(18*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",153);//10011001
    }
    emit progress((int)(19*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",170);//10101010
    }
    emit progress((int)(20*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",187);//10111011
    }
    emit progress((int)(21*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",204);//11001100
    }
    emit progress((int)(22*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",221);//11011101
    }
    emit progress((int)(23*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",238);//11101110
    }
    emit progress((int)(24*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",255);//11111111
    }
    emit progress((int)(25*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",146);//10010010
    }
    emit progress((int)(26*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",73);//01001001
    }
    emit progress((int)(27*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",36);//00100100
    }
    emit progress((int)(28*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",109);//01101101
    }
    emit progress((int)(29*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",182);//10110110
    }
    emit progress((int)(30*100/35));

    fseek(f, 0L, SEEK_SET);
    for(int i=0;i<size;i++){
        fprintf(f,"%c",219);//11011011
    }
    emit progress((int)(31*100/35));

    for(int k=0;k<4;k++){
        fseek(f, 0L, SEEK_SET);
        for(int i=0;i<size;i++){
            fprintf(f,"%c",rand()%128);
        }
        emit progress((int)((k+32)*100/35));
    }
    remove(path);
}
