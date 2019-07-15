#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <iostream>
#include <string>
#include "Light.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool Initialize_input();
    void Initialize_surface(QTextStream& in, int &k, Light_d &d, Light_f &f, Light_c &c);
    std::vector<Surface> Read_File(QTextStream& in, int k);
    void output(int flag, QTextStream& out, Light_d &d, Light_f &f, Light_c &c);
    void display(int flag, Light_d &d, Light_f &f, Light_c &c);
private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

    void on_lineEdit_4_returnPressed();

    void on_lineEdit_5_returnPressed();

    void on_file_output_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
