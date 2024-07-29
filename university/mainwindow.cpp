#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "databasehelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , addbox(new addBox(this))
    , findbox(new findBox(this))
    , updatebox(new updateBox(this))
    , dbHelper(new DatabaseHelper(this))
{
    ui->setupUi(this);

    // setup db
    dbHelper->setupDatabase();

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addFun);
    connect(addbox, &addBox::enterInfo, this, &MainWindow::getInfo );
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::searchFun);
    connect(findbox, &findBox::onSearch, this, &MainWindow::onFind);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::updateFun);
    connect(updatebox, &updateBox::newSub, this, &MainWindow::onUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addbox;
    delete findbox;
    delete updatebox;
    delete dbHelper;
}

/* QStringList rollNoList;
QStringList nameList;
QStringList subList;

bool found = false; */

void MainWindow::addFun()
{
    addbox->show();

}

void MainWindow::getInfo(const QString &rn, const QString &n, const QString &s){

    if (dbHelper->addStudent(rn, n, s)) {
        QMessageBox::information(this, "Success", "Student Added Successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to add student.");
    }

    /* rollNoList.append(rn);
    nameList.append(n);
    subList.append(s);

    QMessageBox::information(this, "Success", "Student Added Successfuly!"); */
}

void MainWindow::searchFun()
{
    findbox->show();
}

void MainWindow::onFind(const QString &rn){

    QString name, subject;
    if (dbHelper->findStudent(rn, name, subject)) {
        QMessageBox::information(this, "Success",
                                "RollNo: " + rn + "\n"
                                "Name of Student: " + name + "\n"
                                "Subject of Student: " + subject);
    } else {
        QMessageBox::information(this, "Error", "Sorry Invalid RollNo!");
    }

    /*for (int i = 0; i < rollNoList.length(); i++) {
        if(rn == rollNoList[i]){
            found = true;
            QMessageBox::information(this, "Success",
                                "RollNo: " + rollNoList[i] + "\n"
                                "Name of Student: " + nameList[i] + "\n"
                                "Subject of Student: "+ subList[i]);
            break;
        }
    }
    if(!found){
        QMessageBox::information(this, "Error", "Sorry Inavlid RollNo!");
    }*/
}


void MainWindow::updateFun()
{
    updatebox->show();
}

void MainWindow::onUpdate(const QString &rn, const QString &s){

    if (dbHelper->updateStudent(rn, s)) {
        QMessageBox::information(this, "Success", "Subject of Student updated successfully!");
    } else {
        QMessageBox::information(this, "Error", "Sorry Invalid RollNo!");
    }

    /* for(int i = 0; i < rollNoList.length(); i++){
        if(rn == rollNoList[i]){
            found = true;
            subList[i] = s;
            QMessageBox::information(this, "Success", "Subject of Student: "+ subList[i]);
            break;
        }
    }
    if(!found){
        QMessageBox::information(this, "Error", "Sorry Inavlid RollNo!");
    } */
}

