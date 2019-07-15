#include "miniZemax.h"
#include "ui_miniZemax.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
/*文件选择*/
    QString filePath = this->ui->filePathBox->currentText();
    if(filePath == ""){
        QMessageBox::warning(this, "Prompt", "Please select the file");
        return;
    }
    QFile inFile(filePath);
    inFile.open(QIODevice::ReadOnly);
    QTextStream in(&inFile);
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(16);
    ui->plainTextEdit->setFont(font);
/*输入*/

    bool input_correct = Initialize_input();
    if(input_correct){
        ui->plainTextEdit->clear();
        int k;
        Light_d d; Light_f f; Light_c c;
        if(!ui->lineEdit->text().isEmpty())
            flag = 0;
        else{
            flag = 1;
            h = 10; W = 3;
        }
        Initialize_surface(in, k, d, f, c);
        d.Initialize(0);
        d.Initialize(flag);
        d.Initialize_d(flag);
        f.Initialize(flag);
        c.Initialize(flag);
        f.Cal_Chromatic_Aberration(flag,c);
        display(flag, d, f, c);
    }
}

void MainWindow::display(int flag, Light_d &d, Light_f &f, Light_c &c)
{
    if(ui->Light->currentText() == "Light_d")
    {
        if(ui->result->currentText() == "理想像高")
            ui->plainTextEdit->insertPlainText(d.show_ideal_y(flag));
        else if(ui->result->currentText() == "实际像高")
            ui->plainTextEdit->insertPlainText(d.show_actual_y(flag));
        else if(ui->result->currentText() == "理想像距")
                ui->plainTextEdit->insertPlainText(d.show_ideal_L(flag));
        else if(ui->result->currentText() == "实际像位置")
            ui->plainTextEdit->insertPlainText(d.show_actual_L(flag));
        else if(ui->result->currentText() == "透镜固定参数")
            ui->plainTextEdit->insertPlainText(d.show_f());
    }
    else if(ui->Light->currentText() == "Light_f")
    {
        if(ui->result->currentText() == "理想像高")
            ui->plainTextEdit->insertPlainText(d.show_ideal_y(flag));
        else if(ui->result->currentText() == "实际像高")
            ui->plainTextEdit->insertPlainText(f.show_actual_y(flag));
        else if(ui->result->currentText() == "理想像距")
                ui->plainTextEdit->insertPlainText(f.show_ideal_L(flag));
        else if(ui->result->currentText() == "实际像位置")
            ui->plainTextEdit->insertPlainText(f.show_actual_L(flag));
        else if(ui->result->currentText() == "透镜固定参数")
            ui->plainTextEdit->insertPlainText(f.show_f());
    }
    else if(ui->Light->currentText() == "Light_c")
    {
        if(ui->result->currentText() == "理想像高")
            ui->plainTextEdit->insertPlainText(d.show_ideal_y(flag));
        else if(ui->result->currentText() == "实际像高")
            ui->plainTextEdit->insertPlainText(c.show_actual_y(flag));
        else if(ui->result->currentText() == "理想像距")
                ui->plainTextEdit->insertPlainText(c.show_ideal_L(flag));
        else if(ui->result->currentText() == "实际像距离")
            ui->plainTextEdit->insertPlainText(c.show_actual_L(flag));
        else if(ui->result->currentText() == "透镜固定参数")
            ui->plainTextEdit->insertPlainText(c.show_f());
    }
    if(ui->aberration->currentText() == "球差"){
        ui->plainTextEdit->insertPlainText(d.Sa_show(flag));
    }
    else if(ui->aberration->currentText() == "场曲像散"){
        ui->plainTextEdit->insertPlainText(d.As_show(flag));
    }
    else if(ui->aberration->currentText() == "彗差"){
        ui->plainTextEdit->insertPlainText(d.coma_show(flag));
    }
    else if(ui->aberration->currentText() == "畸变"){
        ui->plainTextEdit->insertPlainText(d.dis_show(flag));
    }
    else if(ui->aberration->currentText() == "色差"){
        ui->plainTextEdit->insertPlainText(f.Ca_show(flag));
    }

}

void MainWindow::output(int flag, QTextStream& out, Light_d &d, Light_f &f, Light_c &c)
{
    d.show(flag, out);
    c.show(flag, out);
    f.show(flag, out);
}
void MainWindow::Initialize_surface(QTextStream& in, int &k, Light_d &d, Light_f &f, Light_c &c)
{
    in >> k;
    if(!ui->lineEdit->text().isEmpty()){
        d = Light_d(h, W, Read_File(in, k));
        f = Light_f(h, W, Read_File(in, k));
        c = Light_c(h, W,  Read_File(in, k));
    }
    else{
        d = Light_d(L, Y, U, Read_File(in, k));
        f = Light_f(L, Y, U, Read_File(in, k));
        c = Light_c(L, Y, U, Read_File(in, k));
    }
}

std::vector<Surface> MainWindow::Read_File(QTextStream&in, int k)
{
    std::vector<Surface> opt_system;
    double r, n1, n2, d1, d2;
        for (int i = 0; i < k; i++) {
            if (i == 0) {
                in >> r >> n1 >> n2 >> d2;
                opt_system.push_back(Surface(r, n1, n2, d2));
            }
            else if (i != k - 1) {
                in >> r >> n1 >> d1;
                opt_system.push_back(Surface(r, n2, n1, d2, d1));
                n2 = n1; d2 = d1;
            }
            else {
                in >> r >> n1;
                opt_system.push_back(Surface(r, n2, n1, d2, 0));
            }
        }
    return opt_system;
}

bool MainWindow::Initialize_input()
{
    bool front = ui->lineEdit->text().isEmpty()&&ui->lineEdit_2->text().isEmpty();
    bool behind = ui->lineEdit_3->text().isEmpty()&&ui->lineEdit_4->text().isEmpty()&&ui->lineEdit_5->text().isEmpty();
    if(front){
        if(ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()||ui->lineEdit_5->text().isEmpty()){
            QMessageBox ::warning(this, "Prompt" , "Lack of Information");
            return false;
        }
        on_lineEdit_3_returnPressed();
        on_lineEdit_4_returnPressed();
        on_lineEdit_5_returnPressed();
    }
    else if(behind){
        if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()){
            QMessageBox ::warning(this, "Prompt" , "Lack of Information");
            return false;
        }
        on_lineEdit_returnPressed();
        on_lineEdit_2_returnPressed();
    }
    else if(!(front || behind)){
        QMessageBox ::critical(this, "Prompt" , "Wrong Input");
        return false;
    }
    return true;
}//已检查

void MainWindow::on_toolButton_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("text(*.txt)"));

        if (!directory.isEmpty())
        {
            if (this->ui->filePathBox->findText(directory) == -1)
            {
                this->ui->filePathBox->addItem(directory);
            }
            this->ui->filePathBox->setCurrentIndex(this->ui->filePathBox->findText(directory));
        }
}

void MainWindow::on_toolButton_2_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("text(*.txt)"));

        if (!directory.isEmpty())
        {
            if (this->ui->filePathBox2->findText(directory) == -1)
            {
                this->ui->filePathBox2->addItem(directory);
            }
            this->ui->filePathBox2->setCurrentIndex(this->ui->filePathBox2->findText(directory));
        }
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString h_str = ui->lineEdit->text();
    ::h = (double)atof(h_str.toStdString().c_str());
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    QString W_str = ui->lineEdit_2->text();
    ::W = (double)atof(W_str.toStdString().c_str());
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    QString L_str = ui->lineEdit_3->text();
    ::L = (double)atof(L_str.toStdString().c_str());
}

void MainWindow::on_lineEdit_4_returnPressed()
{
    QString y_str = ui->lineEdit_4->text();
    Y = (double)atof(y_str.toStdString().c_str());
}

void MainWindow::on_lineEdit_5_returnPressed()
{
    QString U_str = ui->lineEdit_5->text();
    ::U = (double)atof(U_str.toStdString().c_str());
}

void MainWindow::on_file_output_btn_clicked()
{
    QString filePath = this->ui->filePathBox->currentText();
    if(filePath == ""){
        QMessageBox::warning(this, "Prompt", "Please select the file");
        return;
    }
    QFile inFile(filePath);
    inFile.open(QIODevice::ReadOnly);
    QTextStream in(&inFile);
    QString filePath2 = this->ui->filePathBox2->currentText();
    if(filePath2 == ""){
        QMessageBox::warning(this, "Prompt", "Please select the file");
        return;
    }
    QFile outFile(filePath2);
    outFile.open(QIODevice::WriteOnly);
    QTextStream out(&outFile);
    bool input_correct = Initialize_input();
    if(input_correct){

        int k;
        Light_d d; Light_f f; Light_c c;
        if(!ui->lineEdit->text().isEmpty())
            flag = 0;
        else{
            flag = 1;
            h = 10; W = 3;
        }
        Initialize_surface(in, k, d, f, c);
        d.Initialize(0);
        qDebug() << ::ideal_L_infinite;
        d.Initialize(flag);
        d.Initialize_d(flag);
        f.Initialize(flag);
        c.Initialize(flag);
        f.Cal_Chromatic_Aberration(flag,c);
        output(flag, out, d, f, c);
        QMessageBox ::about(this, "Prompt" , "Output Success");
    }
}
