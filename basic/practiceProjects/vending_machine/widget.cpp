#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QString>

widget::widget(QWidget *parent) : QWidget(parent), ui(new UI:widget) {

    ui->setupUI(this);
    _money = 0;
    setControl();
}

widget::~widget() {
    delete ui;
}

void widget::setControl() {
    ui->lcdNumber->display(_money);
    ui->pbCoffee->setEnabled(_money >= 100);
    ui->pbTea->setEnabled(_money >= 150);
    ui->pbCola->setEnabled(_money >= 200);
}

void widget::on_pb500_clicked() {
    _money += 500;
    setControl();
}

void widget::on_pb100_clicked()
{
    _money += 100;
    setControl();
}

void widget::on_pb50_clicked()
{
    _money += 50;
    setControl();
}

void widget::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}

void widget::on_pbCoffee_clicked()
{
    money_ -= 100;
    setControl();
}

void widget::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();
}

void widget::on_pbCola_clicked()
{
    money_ -= 200;
    setControl();
}

void widget::on_pbReset_clicked() {
    QMessageBox box;
    int num500, num100, num50, num10;

    num500 = money_ / 500; money_ %= 500;
    num100 = money_ / 100; money_ %= 100;
    num50 = money_ / 50; money_ %= 50;
    num10 = money_ / 10; money_ %= 10;

    QString status = QString("500Won : %1\n100Won : %2\n50Won : %3\n10Won : %4").arg(num500).arg(num100).arg(num50).arg(num10);
    box.setText(status);
    box.exec();
    setControl();
}