/********************************************************************************
** Form generated from reading UI file 'miniZemax.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIZEMAX_H
#define UI_MINIZEMAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpen_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *filePathBox;
    QToolButton *toolButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QComboBox *filePathBox2;
    QToolButton *toolButton_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QComboBox *Light;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *result;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QComboBox *aberration;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *file_output_btn;
    QPushButton *pushButtonclose;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(894, 722);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen_2 = new QAction(MainWindow);
        actionOpen_2->setObjectName(QStringLiteral("actionOpen_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_9 = new QVBoxLayout(centralWidget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        filePathBox = new QComboBox(centralWidget);
        filePathBox->setObjectName(QStringLiteral("filePathBox"));

        horizontalLayout_3->addWidget(filePathBox);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_3->addWidget(toolButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        filePathBox2 = new QComboBox(centralWidget);
        filePathBox2->setObjectName(QStringLiteral("filePathBox2"));

        horizontalLayout->addWidget(filePathBox2);

        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_9->addLayout(horizontalLayout_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_8->addWidget(label_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_5);


        verticalLayout_5->addLayout(formLayout);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_7->addLayout(verticalLayout_5);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_13);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        Light = new QComboBox(centralWidget);
        Light->setObjectName(QStringLiteral("Light"));
        Light->setMaxVisibleItems(10);
        Light->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        Light->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(Light);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        result = new QComboBox(centralWidget);
        result->setObjectName(QStringLiteral("result"));

        horizontalLayout_5->addWidget(result);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        aberration = new QComboBox(centralWidget);
        aberration->addItem(QStringLiteral(""));
        aberration->addItem(QString());
        aberration->addItem(QString());
        aberration->addItem(QString());
        aberration->addItem(QString());
        aberration->addItem(QString());
        aberration->setObjectName(QStringLiteral("aberration"));

        horizontalLayout_6->addWidget(aberration);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        file_output_btn = new QPushButton(centralWidget);
        file_output_btn->setObjectName(QStringLiteral("file_output_btn"));

        verticalLayout_2->addWidget(file_output_btn);

        pushButtonclose = new QPushButton(centralWidget);
        pushButtonclose->setObjectName(QStringLiteral("pushButtonclose"));

        verticalLayout_2->addWidget(pushButtonclose);


        verticalLayout_7->addLayout(verticalLayout_2);


        horizontalLayout_7->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_9->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonclose, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "open", 0));
        actionOpen_2->setText(QApplication::translate("MainWindow", "open", 0));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\273\345\205\245\350\267\257\345\276\204", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\255\230\345\202\250\350\267\257\345\276\204", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "h", 0));
        label_3->setText(QApplication::translate("MainWindow", "W", 0));
        label_4->setText(QApplication::translate("MainWindow", "L", 0));
        label_5->setText(QApplication::translate("MainWindow", "y", 0));
        label_6->setText(QApplication::translate("MainWindow", "U", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\350\257\267\344\270\215\350\246\201\345\220\214\346\227\266\350\276\223\345\205\245\346\227\240\347\251\267\350\277\234\345\205\211\345\222\214\346\234\211\351\231\220\350\277\234\345\205\211\345\217\202\346\225\260", 0));
        label_13->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232\n"
"\346\227\240\347\251\267\350\277\234\345\205\211\357\274\232\n"
"\350\276\223\345\205\245\345\205\245\347\236\263\345\215\212\345\276\204h\345\222\214\350\247\206\345\234\272\350\247\222W\n"
"\n"
"\346\234\211\351\231\220\350\277\234\345\205\211\357\274\232\n"
"\350\276\223\345\205\245\347\211\251\350\267\235L\357\274\214 \347\211\251\351\253\230y\357\274\214\347\211\251\346\226\271\345\255\224\345\276\204\350\247\222U\n"
"\n"
"\n"
"\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\n"
"\347\220\206\346\203\263\345\203\217\351\253\230\351\203\275\346\230\257d\345\205\211\347\220\206\346\203\263\345\203\217\351\253\230", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\211\262\345\205\211", 0));
        Light->clear();
        Light->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Light_d", 0)
         << QApplication::translate("MainWindow", "Light_f", 0)
         << QApplication::translate("MainWindow", "Light_c", 0)
        );
        label_10->setText(QApplication::translate("MainWindow", "\345\205\211\347\272\277\350\277\275\350\270\252       ", 0));
        result->clear();
        result->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "\351\200\217\351\225\234\345\233\272\345\256\232\345\217\202\346\225\260", 0)
         << QApplication::translate("MainWindow", "\347\220\206\346\203\263\345\203\217\350\267\235", 0)
         << QApplication::translate("MainWindow", "\345\256\236\351\231\205\345\203\217\344\275\215\347\275\256", 0)
         << QApplication::translate("MainWindow", "\347\220\206\346\203\263\345\203\217\351\253\230", 0)
         << QApplication::translate("MainWindow", "\345\256\236\351\231\205\345\203\217\351\253\230", 0)
        );
        label_11->setText(QApplication::translate("MainWindow", "\345\220\204\347\261\273\345\203\217\345\267\256", 0));
        aberration->setItemText(1, QApplication::translate("MainWindow", "\347\220\203\345\267\256", 0));
        aberration->setItemText(2, QApplication::translate("MainWindow", "\345\234\272\346\233\262\345\203\217\346\225\243", 0));
        aberration->setItemText(3, QApplication::translate("MainWindow", "\347\225\270\345\217\230", 0));
        aberration->setItemText(4, QApplication::translate("MainWindow", "\350\211\262\345\267\256", 0));
        aberration->setItemText(5, QApplication::translate("MainWindow", "\345\275\227\345\267\256", 0));

        pushButton->setText(QApplication::translate("MainWindow", "Show", 0));
        file_output_btn->setText(QApplication::translate("MainWindow", "File Output", 0));
        pushButtonclose->setText(QApplication::translate("MainWindow", "Quit", 0));
        label_2->setText(QApplication::translate("MainWindow", "copyright@2019 By \350\203\241\345\220\257\347\254\240 \345\221\250\347\232\223\345\256\207 \345\274\240\346\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIZEMAX_H
