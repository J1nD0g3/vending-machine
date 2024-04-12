#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeAbility(bool coffee, bool tea, bool milk)
{
    ui->pbCoffee->setEnabled(coffee);
    ui->pbTea->setEnabled(tea);
    ui->pbMilk->setEnabled(milk);
}

void Widget::changeMoney(int diff)
{
    money+=diff;
    if(money<100){
        changeAbility(false, false, false);
    }
    else if(money<150){
        changeAbility(true, false, false);
    }
    else if(money<200){
        changeAbility(true, true, false);
    }
    else{
        changeAbility(true, true, true);
    }
    ui->lcdNumber->display(money);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int m = money;
    char res[128];

    int c500 = money / 500; money %= 500;
    int c100 = money / 100; money %= 100;
    int c50 = money / 50; money %= 50;
    int c10 = money / 10; money %= 10;
    sprintf(res, "500 x %d\n100 x %d\n50   x %d\n10   x %d\n\nall : %d", c500, c100, c50, c10, m);
    QMessageBox mb;
    mb.information(this, "Change", res);
    changeMoney(-money);
}

