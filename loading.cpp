#include "loading.h"
#include "ui_loading.h"

Loading::Loading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loading)
{
    ui->setupUi(this);
    loadingGIF();

}

Loading::~Loading()
{
    delete ui;
}

void Loading::setDateTimeTitle(const QDate& date, const QTime& time)
{
    QDateTime dt = QDateTime(date, time);
    waitTil(dt);
    this->time = time.toString("h m");
    this->day = date.toString("dddd");
    ui->waitinTilLabel->setText("Waiting til: " + date.toString("dddd") + " at " + time.toString("hh:mm ap") + " to book the gym");
}

void Loading::setPassword(QString password)
{
    this->password = password;
}

void Loading::setUsername(QString username)
{

    this->username = username;
}

void Loading::on_cancelButton_clicked()
{
    emit CancelClicked();
}

void Loading::loadingGIF()
{
    QMovie *movie = new QMovie(":/imgs/C:/Users/joshm/OneDrive/Desktop/loading.gif");
    QLabel *processLabel = ui->image;
    processLabel->setMovie(movie);
    movie->start();
}

void Loading::waitTil(QDateTime dt)
{
    int seconds = dt.time().second();
    QDateTime newDT = dt.addSecs(-seconds);
    qint64 myTime = newDT.toSecsSinceEpoch() - QDateTime::currentDateTime().toSecsSinceEpoch();
    qDebug() << QString::number(myTime);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(execProgram()));
    timer->start(myTime * 1000);
}

void Loading::execProgram()
{

    QProcess p;
    QStringList params;
    QString pythonPath = "C:/Users/joshm/AppData/Local/Microsoft/WindowsApps/PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0/python3.9.exe";
    QString pythonScript = "/CarletonGymBookingAutomation.py";
    params << pythonScript << username << password << day << time;
    p.start(pythonPath, params);
    p.waitForFinished(-1);
    p.close();

}

