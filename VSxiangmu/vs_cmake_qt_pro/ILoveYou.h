#pragma once

#include <QtWidgets/QWidget>
#include "ui_ILoveYou.h"

class ILoveYou : public QWidget
{
    Q_OBJECT

public:
    ILoveYou(QWidget *parent = nullptr);
    ~ILoveYou();

private:
    Ui::ILoveYouClass ui;
};

