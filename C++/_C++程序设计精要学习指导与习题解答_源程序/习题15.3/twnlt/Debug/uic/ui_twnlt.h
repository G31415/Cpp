/********************************************************************************
** Form generated from reading UI file 'twnlt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWNLT_H
#define UI_TWNLT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_twnltClass
{
public:
    QAction *action_open;
    QAction *action_zszc;
    QAction *action_zdjl;
    QAction *action_cxbz;
    QAction *action_gy;
    QAction *action_exit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_Q;
    QMenu *menu_H;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *twnltClass)
    {
        if (twnltClass->objectName().isEmpty())
            twnltClass->setObjectName(QString::fromUtf8("twnltClass"));
        twnltClass->resize(1045, 790);
        twnltClass->setMaximumSize(QSize(1045, 790));
        action_open = new QAction(twnltClass);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_open->setCheckable(true);
        action_zszc = new QAction(twnltClass);
        action_zszc->setObjectName(QString::fromUtf8("action_zszc"));
        action_zszc->setCheckable(true);
        action_zszc->setChecked(false);
        action_zszc->setAutoRepeat(true);
        action_zdjl = new QAction(twnltClass);
        action_zdjl->setObjectName(QString::fromUtf8("action_zdjl"));
        action_zdjl->setCheckable(true);
        action_zdjl->setAutoRepeat(true);
        action_cxbz = new QAction(twnltClass);
        action_cxbz->setObjectName(QString::fromUtf8("action_cxbz"));
        action_gy = new QAction(twnltClass);
        action_gy->setObjectName(QString::fromUtf8("action_gy"));
        action_exit = new QAction(twnltClass);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_exit->setCheckable(true);
        centralWidget = new QWidget(twnltClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMouseTracking(true);
        graphicsView->setAutoFillBackground(true);
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/twnlt/\346\255\246\346\261\211\345\234\260\345\233\276.png);"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        graphicsView->setRubberBandSelectionMode(Qt::IntersectsItemShape);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        twnltClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(twnltClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1045, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_Q = new QMenu(menuBar);
        menu_Q->setObjectName(QString::fromUtf8("menu_Q"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setEnabled(false);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setEnabled(false);
        twnltClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(twnltClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMaximumSize(QSize(16777215, 16777215));
        twnltClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(twnltClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        twnltClass->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_Q->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_F->addAction(action_open);
        menu_F->addAction(action_exit);
        menu_Q->addAction(action_zszc);
        menu_Q->addAction(action_zdjl);

        retranslateUi(twnltClass);
        QObject::connect(action_exit, SIGNAL(triggered(bool)), twnltClass, SLOT(closewnd()));
        QObject::connect(action_open, SIGNAL(triggered(bool)), twnltClass, SLOT(loadmap()));
        QObject::connect(action_zszc, SIGNAL(triggered(bool)), twnltClass, SLOT(zszc()));
        QObject::connect(action_zdjl, SIGNAL(triggered(bool)), twnltClass, SLOT(zdjl()));

        QMetaObject::connectSlotsByName(twnltClass);
    } // setupUi

    void retranslateUi(QMainWindow *twnltClass)
    {
        twnltClass->setWindowTitle(QCoreApplication::translate("twnltClass", "\345\205\254\344\272\244\350\275\254\344\271\230", nullptr));
        action_open->setText(QCoreApplication::translate("twnltClass", "\350\257\273\345\205\245\345\234\260\345\233\276", nullptr));
        action_zszc->setText(QCoreApplication::translate("twnltClass", "\346\234\200\345\260\221\350\275\254\344\271\230", nullptr));
        action_zdjl->setText(QCoreApplication::translate("twnltClass", "\346\234\200\347\237\255\350\267\235\347\246\273", nullptr));
        action_cxbz->setText(QString());
        action_gy->setText(QString());
        action_exit->setText(QCoreApplication::translate("twnltClass", "\351\200\200\345\207\272", nullptr));
        menu_F->setTitle(QCoreApplication::translate("twnltClass", "\346\226\207\344\273\266(F)", nullptr));
        menu_Q->setTitle(QCoreApplication::translate("twnltClass", "\346\237\245\350\257\242(Q)", nullptr));
        menu_H->setTitle(QString());
        menu->setTitle(QString());
        menu_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class twnltClass: public Ui_twnltClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWNLT_H
