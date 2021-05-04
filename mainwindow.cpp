#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    ui->stackedWidget->addWidget(&loading);
    connect(&loading, SIGNAL(CancelClicked()), this, SLOT(showMain()));
    setup_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{
    qDebug("Button Clicked");
    if(check_inputs()){
        qDebug("Valid Inputs");
        time = ui->timeEdit->time();
        date = ui->dateEdit->date();
        loading.setDateTimeTitle(date, time);
        loading.setUsername(ui->usernameLineEdit->text());
        loading.setPassword(ui->passwordLineEdit->text());
        ui->stackedWidget->setCurrentIndex(1);
    }

}

bool MainWindow::check_inputs()
{
    bool isValid = true;
    if(ui->usernameLineEdit->text() == "")
    {
        ui->userNameErrorLabel->setText("username cannot be empty");
        isValid = false;
    }else{
        ui->userNameErrorLabel->setText("");
    }

    if(ui->passwordLineEdit->text() == "")
    {
        ui->passwordErrorLabel->setText("password cannot be empty");
        isValid = false;
    }else{
        ui->passwordErrorLabel->setText("");
    }

    if(ui->dateEdit->date() < QDate::currentDate())
    {
        ui->dateErrorLabel->setText("you are not a time traveller. stop the cap");
        isValid = false;
    }else{
        ui->dateErrorLabel->setText("");
    }

    if(ui->timeEdit->time().addSecs(-time.second()) < QTime::currentTime().addSecs(-QTime::currentTime().second()))
    {
        ui->timeErrorText->setText("you are too late, you need to book in advance");
        isValid = false;
    }else{
        ui->timeErrorText->setText("");
    }

    return isValid;
}


void MainWindow::showMain()
{
    qDebug("showMain()");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setup_ui()
{
    // Change main window background to white and set the window so it doesn't resize
    this->setStyleSheet("background-color: white");
    this->resize(925,518);

    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setStyleSheet("color: black");

    ui->runButton->setStyleSheet("background-color: #D3D3D3");

    ui->passwordErrorLabel->setStyleSheet("color: red");
    ui->passwordErrorLabel->setText("");

    ui->userNameErrorLabel->setStyleSheet("color: red");
    ui->userNameErrorLabel->setText("");

    ui->dateErrorLabel->setStyleSheet("color: red");
    ui->dateErrorLabel->setText("");

    ui->timeErrorText->setStyleSheet("color: red");
    ui->timeErrorText->setText("");
}

void MainWindow::on_actionfollow_me_on_instagram_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.instagram.com/joshmorrison99/"));
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

