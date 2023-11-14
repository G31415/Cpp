/********************************************************************************
** Form generated from reading UI file 'QtWidgetsFL.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSFL_H
#define UI_QTWIDGETSFL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsFL
{
public:
    QLabel *labelLine;
    QPushButton *pushButtonQuit;
    QPushButton *pushButtonDone;
    QTextEdit *textEditStop;
    QLabel *labelStop;
    QPushButton *pushButtonLine;
    QTextEdit *textEditLine;
    QPushButton *pushButtonStop;
    QLabel *labelWind;
    QLabel *labelHits;

    void setupUi(QWidget *QtWidgetsFL)
    {
        if (QtWidgetsFL->objectName().isEmpty())
            QtWidgetsFL->setObjectName(QString::fromUtf8("QtWidgetsFL"));
        QtWidgetsFL->resize(635, 292);
        QtWidgetsFL->setMinimumSize(QSize(635, 292));
        QtWidgetsFL->setMaximumSize(QSize(635, 292));
        labelLine = new QLabel(QtWidgetsFL);
        labelLine->setObjectName(QString::fromUtf8("labelLine"));
        labelLine->setEnabled(false);
        labelLine->setGeometry(QRect(10, 172, 71, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        labelLine->setFont(font);
        pushButtonQuit = new QPushButton(QtWidgetsFL);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(380, 230, 75, 30));
        pushButtonDone = new QPushButton(QtWidgetsFL);
        pushButtonDone->setObjectName(QString::fromUtf8("pushButtonDone"));
        pushButtonDone->setGeometry(QRect(190, 230, 75, 30));
        textEditStop = new QTextEdit(QtWidgetsFL);
        textEditStop->setObjectName(QString::fromUtf8("textEditStop"));
        textEditStop->setGeometry(QRect(80, 100, 471, 30));
        labelStop = new QLabel(QtWidgetsFL);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        labelStop->setEnabled(false);
        labelStop->setGeometry(QRect(10, 105, 71, 21));
        labelStop->setFont(font);
        pushButtonLine = new QPushButton(QtWidgetsFL);
        pushButtonLine->setObjectName(QString::fromUtf8("pushButtonLine"));
        pushButtonLine->setGeometry(QRect(550, 170, 75, 30));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        pushButtonLine->setPalette(palette);
        pushButtonLine->setToolTipDuration(-1);
        textEditLine = new QTextEdit(QtWidgetsFL);
        textEditLine->setObjectName(QString::fromUtf8("textEditLine"));
        textEditLine->setGeometry(QRect(80, 170, 471, 30));
        pushButtonStop = new QPushButton(QtWidgetsFL);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(550, 100, 75, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        pushButtonStop->setPalette(palette1);
        pushButtonStop->setMouseTracking(false);
        pushButtonStop->setToolTipDuration(-1);
        pushButtonStop->setCheckable(false);
        labelWind = new QLabel(QtWidgetsFL);
        labelWind->setObjectName(QString::fromUtf8("labelWind"));
        labelWind->setGeometry(QRect(210, 50, 231, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(18);
        labelWind->setFont(font1);
        labelHits = new QLabel(QtWidgetsFL);
        labelHits->setObjectName(QString::fromUtf8("labelHits"));
        labelHits->setEnabled(false);
        labelHits->setGeometry(QRect(0, 270, 631, 21));
        labelHits->setFont(font);

        retranslateUi(QtWidgetsFL);
        QObject::connect(pushButtonStop, SIGNAL(clicked()), QtWidgetsFL, SLOT(inputStop()));
        QObject::connect(pushButtonLine, SIGNAL(clicked()), QtWidgetsFL, SLOT(inputLine()));
        QObject::connect(pushButtonDone, SIGNAL(clicked()), QtWidgetsFL, SLOT(checkFile()));
        QObject::connect(pushButtonQuit, SIGNAL(clicked()), QtWidgetsFL, SLOT(close()));

        QMetaObject::connectSlotsByName(QtWidgetsFL);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsFL)
    {
        QtWidgetsFL->setWindowTitle(QCoreApplication::translate("QtWidgetsFL", "\346\226\207\344\273\266\345\212\240\350\275\275", nullptr));
        labelLine->setText(QCoreApplication::translate("QtWidgetsFL", "\347\272\277\350\267\257\346\226\207\344\273\266", nullptr));
        pushButtonQuit->setText(QCoreApplication::translate("QtWidgetsFL", "\351\200\200\345\207\272", nullptr));
        pushButtonDone->setText(QCoreApplication::translate("QtWidgetsFL", "\347\241\256\345\256\232", nullptr));
        textEditStop->setMarkdown(QString());
        textEditStop->setHtml(QCoreApplication::translate("QtWidgetsFL", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        labelStop->setText(QCoreApplication::translate("QtWidgetsFL", "\347\253\231\347\202\271\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonLine->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonLine->setText(QCoreApplication::translate("QtWidgetsFL", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonStop->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonStop->setText(QCoreApplication::translate("QtWidgetsFL", "\346\265\217\350\247\210...", nullptr));
        labelWind->setText(QCoreApplication::translate("QtWidgetsFL", "\347\253\231\347\202\271\345\217\212\347\272\277\350\267\257\346\226\207\344\273\266\345\212\240\350\275\275", nullptr));
        labelHits->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsFL: public Ui_QtWidgetsFL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSFL_H
