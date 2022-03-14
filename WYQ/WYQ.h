#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WYQ.h"

class WYQ : public QMainWindow
{
    Q_OBJECT

public:
    WYQ(QWidget *parent = Q_NULLPTR);

private:
    Ui::WYQClass ui;
};
