#include "miniZemax.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("miniZemax");
    w.setWindowIcon(QIcon(":/learner.png"));
    w.show();
    return a.exec();
}
