#pragma once

#include <QtWidgets/QWidget>
#include "ui_Maye.h"

class Maye : public QWidget
{
    Q_OBJECT

public:
    Maye(QWidget *parent = nullptr);
    ~Maye();

private:
    Ui::MayeClass ui;
};

