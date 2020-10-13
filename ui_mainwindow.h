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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
    QLabel *configPresetLabel;
    QComboBox *configPresetComboBox;
    QLabel *cameraPositionLabel;
    QSlider *cameraPositionSlider;
    QLabel *zoomAmountLabel;
    QSlider *zoomAmountSlider;
    QLabel *horizontalViewLabel;
    QSlider *horizontalViewSlider;
    QLabel *verticalViewLabel;
    QSlider *verticalViewSlider;
    QLabel *moonPositionLabel;
    QSlider *moonPositionSlider;
    QCheckBox *automaticMoonMovementCheckBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *exitButton;
    GLWidget *widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 500);
        MainWindow->setMinimumSize(QSize(900, 500));
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
        configPresetLabel = new QLabel(centralWidget);
        configPresetLabel->setObjectName(QStringLiteral("configPresetLabel"));

        verticalLayout->addWidget(configPresetLabel);

        configPresetComboBox = new QComboBox(centralWidget);
        configPresetComboBox->setObjectName(QStringLiteral("configPresetComboBox"));

        verticalLayout->addWidget(configPresetComboBox);

        cameraPositionLabel = new QLabel(centralWidget);
        cameraPositionLabel->setObjectName(QStringLiteral("cameraPositionLabel"));
        cameraPositionLabel->setEnabled(true);

        verticalLayout->addWidget(cameraPositionLabel);

        cameraPositionSlider = new QSlider(centralWidget);
        cameraPositionSlider->setObjectName(QStringLiteral("cameraPositionSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cameraPositionSlider->sizePolicy().hasHeightForWidth());
        cameraPositionSlider->setSizePolicy(sizePolicy);
        cameraPositionSlider->setMinimum(-30);
        cameraPositionSlider->setMaximum(500);
        cameraPositionSlider->setValue(18);
        cameraPositionSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(cameraPositionSlider);

        zoomAmountLabel = new QLabel(centralWidget);
        zoomAmountLabel->setObjectName(QStringLiteral("zoomAmountLabel"));

        verticalLayout->addWidget(zoomAmountLabel);

        zoomAmountSlider = new QSlider(centralWidget);
        zoomAmountSlider->setObjectName(QStringLiteral("zoomAmountSlider"));
        sizePolicy.setHeightForWidth(zoomAmountSlider->sizePolicy().hasHeightForWidth());
        zoomAmountSlider->setSizePolicy(sizePolicy);
        zoomAmountSlider->setMinimum(15);
        zoomAmountSlider->setMaximum(150);
        zoomAmountSlider->setValue(130);
        zoomAmountSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(zoomAmountSlider);

        horizontalViewLabel = new QLabel(centralWidget);
        horizontalViewLabel->setObjectName(QStringLiteral("horizontalViewLabel"));

        verticalLayout->addWidget(horizontalViewLabel);

        horizontalViewSlider = new QSlider(centralWidget);
        horizontalViewSlider->setObjectName(QStringLiteral("horizontalViewSlider"));
        sizePolicy.setHeightForWidth(horizontalViewSlider->sizePolicy().hasHeightForWidth());
        horizontalViewSlider->setSizePolicy(sizePolicy);
        horizontalViewSlider->setMaximum(360);
        horizontalViewSlider->setValue(30);
        horizontalViewSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalViewSlider);

        verticalViewLabel = new QLabel(centralWidget);
        verticalViewLabel->setObjectName(QStringLiteral("verticalViewLabel"));

        verticalLayout->addWidget(verticalViewLabel);

        verticalViewSlider = new QSlider(centralWidget);
        verticalViewSlider->setObjectName(QStringLiteral("verticalViewSlider"));
        verticalViewSlider->setEnabled(true);
        sizePolicy.setHeightForWidth(verticalViewSlider->sizePolicy().hasHeightForWidth());
        verticalViewSlider->setSizePolicy(sizePolicy);
        verticalViewSlider->setMinimum(0);
        verticalViewSlider->setMaximum(358);
        verticalViewSlider->setValue(70);
        verticalViewSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(verticalViewSlider);

        moonPositionLabel = new QLabel(centralWidget);
        moonPositionLabel->setObjectName(QStringLiteral("moonPositionLabel"));

        verticalLayout->addWidget(moonPositionLabel);

        moonPositionSlider = new QSlider(centralWidget);
        moonPositionSlider->setObjectName(QStringLiteral("moonPositionSlider"));
        sizePolicy.setHeightForWidth(moonPositionSlider->sizePolicy().hasHeightForWidth());
        moonPositionSlider->setSizePolicy(sizePolicy);
        moonPositionSlider->setMinimumSize(QSize(160, 0));
        moonPositionSlider->setMinimum(0);
        moonPositionSlider->setMaximum(360);
        moonPositionSlider->setValue(0);
        moonPositionSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(moonPositionSlider);

        automaticMoonMovementCheckBox = new QCheckBox(centralWidget);
        automaticMoonMovementCheckBox->setObjectName(QStringLiteral("automaticMoonMovementCheckBox"));
        automaticMoonMovementCheckBox->setChecked(true);

        verticalLayout->addWidget(automaticMoonMovementCheckBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout->addWidget(exitButton);


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
        QObject::connect(exitButton, SIGNAL(released()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Solar Eclipse Simulator", Q_NULLPTR));
        configPresetLabel->setText(QApplication::translate("MainWindow", "Config Preset:", Q_NULLPTR));
        configPresetComboBox->clear();
        configPresetComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Preset 1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Preset 2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Preset 3", Q_NULLPTR)
        );
        cameraPositionLabel->setText(QApplication::translate("MainWindow", "Camera Position (18):", Q_NULLPTR));
        zoomAmountLabel->setText(QApplication::translate("MainWindow", "Zoom Amount (130):", Q_NULLPTR));
        horizontalViewLabel->setText(QApplication::translate("MainWindow", "Horizontal View (30):", Q_NULLPTR));
        verticalViewLabel->setText(QApplication::translate("MainWindow", "Vertical View (70):", Q_NULLPTR));
        moonPositionLabel->setText(QApplication::translate("MainWindow", "Moon Position (0):", Q_NULLPTR));
        automaticMoonMovementCheckBox->setText(QApplication::translate("MainWindow", "Automatic Moon Movement", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Press f1 to toggle fullscreen", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
