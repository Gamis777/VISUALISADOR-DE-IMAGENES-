#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filename = QFileDialog::getOpenFileName(this, tr("add"),"",tr("images (*.png *.jpg *.jpeg *.bmp *.gif)"));

        if(QString::compare(filename,QString())!=0)
        {
            QImage image;
            bool valid = image.load(filename);

            if (valid)
            {
                //image = image.scaledToWidth(ui->picture->width(),Qt::SmoothTransformation);
                int w = ui->label_picture->width();
                int h = ui->label_picture->height();
                ui->label_picture->setPixmap(QPixmap::fromImage(image.scaled(w,h)));
            }
            else
            {
                //error
            }

        }
  ui->lineEdit->setPlaceholderText(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete a;
}

void MainWindow::on_pushButton_2_clicked()
{
    ++it;
    if(it!=pictures.end()){

    }
    else{
        it=pictures.begin();
    }
    string txt=*it;
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);

}

void MainWindow::on_pushButton_clicked()
{
    if(it!=pictures.begin()){
        --it;
    }
    else{
        it=pictures.last();
    }
    string txt=*it;
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);
}
