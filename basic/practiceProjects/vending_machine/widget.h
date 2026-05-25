#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace UI {
    class Widget;
}

class Widget : public QWidget {
    
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();
    int _money;
    void setControl();

private slots:
    void on_pb500_clicked();
    void on_pb100_clicked();
    void on_pb50_clicked();
    void on_pb10_clicked();
    void on_pbCoffee_clicked();
    void on_pbTea_clicked();
    void on_pbCola_clicked();
    void on_pbReset_clicked();

private:
    UI::widget *ui;
};

#endif // WIDGET_H