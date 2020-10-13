/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSlider *cameraPositionSlider;
    QLabel *label;
    QSlider *zoomSlider;
    QLabel *label_3;
    QSlider *horizontalViewSlider;
    QLabel *label_4;
    QSlider *verticalViewSlider;
    QLabel *label_2;
    QSlider *moonPosSlider;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    GLWidget *widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 500);
        MainWindow->setMinimumSize(QSize(800, 500));
        MainWindow->setBaseSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, -1, 9);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        cameraPositionSlider = new QSlider(centralWidget);
        cameraPositionSlider->setObjectName(QStringLiteral("cameraPositionSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cameraPositionSlider->sizePolicy().hasHeightForWidth());
        cameraPositionSlider->setSizePolicy(sizePolicy);
        cameraPositionSlider->setMinimum(-30);
        cameraPositionSlider->setMaximum(500);
        cameraPositionSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(cameraPositionSlider);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        zoomSlider = new QSlider(centralWidget);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        sizePolicy.setHeightForWidth(zoomSlider->sizePolicy().hasHeightForWidth());
        zoomSlider->setSizePolicy(sizePolicy);
        zoomSlider->setMinimum(15);
        zoomSlider->setMaximum(150);
        zoomSlider->setValue(15);
        zoomSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(zoomSlider);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        horizontalViewSlider = new QSlider(centralWidget);
        horizontalViewSlider->setObjectName(QStringLiteral("horizontalViewSlider"));
        sizePolicy.setHeightForWidth(horizontalViewSlider->sizePolicy().hasHeightForWidth());
        horizontalViewSlider->setSizePolicy(sizePolicy);
        horizontalViewSlider->setMaximum(360);
        horizontalViewSlider->setValue(30);
        horizontalViewSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalViewSlider);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        verticalViewSlider = new QSlider(centralWidget);
        verticalViewSlider->setObjectName(QStringLiteral("verticalViewSlider"));
        verticalViewSlider->setEnabled(true);
        sizePolicy.setHeightForWidth(verticalViewSlider->sizePolicy().hasHeightForWidth());
        verticalViewSlider->setSizePolicy(sizePolicy);
        verticalViewSlider->setMinimum(0);
        verticalViewSlider->setMaximum(358);
        verticalViewSlider->setValue(69);
        verticalViewSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(verticalViewSlider);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        moonPosSlider = new QSlider(centralWidget);
        moonPosSlider->setObjectName(QStringLiteral("moonPosSlider"));
        sizePolicy.setHeightForWidth(moonPosSlider->sizePolicy().hasHeightForWidth());
        moonPosSlider->setSizePolicy(sizePolicy);
        moonPosSlider->setMinimumSize(QSize(160, 0));
        moonPosSlider->setMinimum(0);
        moonPosSlider->setMaximum(360);
        moonPosSlider->setValue(0);
        moonPosSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(moonPosSlider);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(released()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Solar Eclipse Simulator", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Camera Position", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Zoom Amount:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Horizontal View:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Vertical View:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Moon Position:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
