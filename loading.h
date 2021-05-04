#ifndef LOADING_H
#define LOADING_H

#include <QWidget>
#include <QMovie>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QProcess>

namespace Ui {
class Loading;
}

class Loading : public QWidget
{
    Q_OBJECT

public:
    explicit Loading(QWidget *parent = nullptr);
    ~Loading();
    void setDateTimeTitle(const QDate& date, const QTime& time);
    void setUsername(QString username);
    void setPassword(QString password);

private slots:
    void on_cancelButton_clicked();
    void execProgram();

signals:
    void CancelClicked();
    void ValidCredentials();

private:
    Ui::Loading *ui;
    void loadingGIF();
    void waitTil(QDateTime time);
    QString username;
    QString password;
    QString day;
    QString time;





};

#endif // LOADING_H
