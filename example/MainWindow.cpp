#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	QMessageBox::information(this, "MainPageID", ui->centralWidget->id());


}

MainWindow::~MainWindow()
{
    delete ui;
}
