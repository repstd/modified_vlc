#define Q_(a,b) QString::fromUtf8(_(a))
/********************************************************************************
** Form generated from reading UI file 'sout.ui'
**
** Created: Mon Dec 7 17:03:20 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SOUT_H
#define SOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "components/sout/profile_selector.hpp"
#include "components/sout/sout_widgets.hpp"

QT_BEGIN_NAMESPACE

class Ui_Sout
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *sourcePage;
    QGridLayout *gridLayout_3;
    QTextEdit *helpEdit;
    SoutInputBox *inputBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;
    QWidget *destPage;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QTabWidget *destTab;
    QWidget *tab;
    QGridLayout *gridLayout_10;
    QLabel *label;
    QComboBox *destBox;
    QPushButton *addButton;
    QLabel *label_2;
    QCheckBox *localOutput;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    VLCProfileSelector *profileSelect;
    QCheckBox *transcodeBox;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *nextButton2;
    QSpacerItem *verticalSpacer_2;
    QWidget *miscPage;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QCheckBox *soutAll;
    QCheckBox *sap;
    QLineEdit *sapName;
    QLabel *sapGroupLabel;
    QLineEdit *sapGroup;
    QLabel *ttlLabel;
    QSpinBox *ttl;
    QGroupBox *groupBox_4;
    QHBoxLayout *_4;
    QTextEdit *mrlEdit;
    QPushButton *prevButton2;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *acceptButtonBox;

    void setupUi(QWidget *Sout)
    {
        if (Sout->objectName().isEmpty())
            Sout->setObjectName(QString::fromUtf8("Sout"));
        Sout->resize(708, 587);
        verticalLayout = new QVBoxLayout(Sout);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBox = new QToolBox(Sout);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        sourcePage = new QWidget();
        sourcePage->setObjectName(QString::fromUtf8("sourcePage"));
        sourcePage->setGeometry(QRect(0, 0, 690, 472));
        gridLayout_3 = new QGridLayout(sourcePage);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        helpEdit = new QTextEdit(sourcePage);
        helpEdit->setObjectName(QString::fromUtf8("helpEdit"));
        helpEdit->setEnabled(true);
        helpEdit->setMaximumSize(QSize(16777215, 150));
        QPalette palette;
        QBrush brush(QColor(220, 220, 220, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        helpEdit->setPalette(palette);
        helpEdit->setAutoFillBackground(false);
        helpEdit->setReadOnly(true);

        gridLayout_3->addWidget(helpEdit, 0, 0, 1, 2);

        inputBox = new SoutInputBox(sourcePage);
        inputBox->setObjectName(QString::fromUtf8("inputBox"));

        gridLayout_3->addWidget(inputBox, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(581, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(581, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 0, 1, 1);

        nextButton = new QPushButton(sourcePage);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        gridLayout_3->addWidget(nextButton, 3, 1, 1, 1);

        toolBox->addItem(sourcePage, QString::fromUtf8("Source"));
        destPage = new QWidget();
        destPage->setObjectName(QString::fromUtf8("destPage"));
        destPage->setGeometry(QRect(0, 0, 690, 319));
        gridLayout_6 = new QGridLayout(destPage);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(destPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        destTab = new QTabWidget(groupBox);
        destTab->setObjectName(QString::fromUtf8("destTab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_10 = new QGridLayout(tab);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_10->addWidget(label, 1, 0, 1, 1);

        destBox = new QComboBox(tab);
        destBox->setObjectName(QString::fromUtf8("destBox"));

        gridLayout_10->addWidget(destBox, 1, 1, 1, 1);

        addButton = new QPushButton(tab);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(addButton, 1, 2, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::PlainText);
        label_2->setWordWrap(true);

        gridLayout_10->addWidget(label_2, 0, 0, 1, 3);

        localOutput = new QCheckBox(tab);
        localOutput->setObjectName(QString::fromUtf8("localOutput"));

        gridLayout_10->addWidget(localOutput, 2, 0, 1, 1);

        destTab->addTab(tab, QString());

        gridLayout_7->addWidget(destTab, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(destPage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        profileSelect = new VLCProfileSelector(groupBox_2);
        profileSelect->setObjectName(QString::fromUtf8("profileSelect"));

        gridLayout_5->addWidget(profileSelect, 1, 0, 1, 1);

        transcodeBox = new QCheckBox(groupBox_2);
        transcodeBox->setObjectName(QString::fromUtf8("transcodeBox"));
        transcodeBox->setChecked(true);

        gridLayout_5->addWidget(transcodeBox, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 1, 0, 1, 3);

        prevButton = new QPushButton(destPage);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));

        gridLayout_6->addWidget(prevButton, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(382, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 3, 1, 1, 1);

        nextButton2 = new QPushButton(destPage);
        nextButton2->setObjectName(QString::fromUtf8("nextButton2"));

        gridLayout_6->addWidget(nextButton2, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 2, 1, 1, 1);

        toolBox->addItem(destPage, QString::fromUtf8("Destination Setup"));
        miscPage = new QWidget();
        miscPage->setObjectName(QString::fromUtf8("miscPage"));
        miscPage->setGeometry(QRect(0, 0, 690, 469));
        gridLayout_2 = new QGridLayout(miscPage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_3 = new QGroupBox(miscPage);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        soutAll = new QCheckBox(groupBox_3);
        soutAll->setObjectName(QString::fromUtf8("soutAll"));

        gridLayout_4->addWidget(soutAll, 0, 0, 1, 5);

        sap = new QCheckBox(groupBox_3);
        sap->setObjectName(QString::fromUtf8("sap"));

        gridLayout_4->addWidget(sap, 1, 0, 2, 1);

        sapName = new QLineEdit(groupBox_3);
        sapName->setObjectName(QString::fromUtf8("sapName"));

        gridLayout_4->addWidget(sapName, 1, 1, 2, 2);

        sapGroupLabel = new QLabel(groupBox_3);
        sapGroupLabel->setObjectName(QString::fromUtf8("sapGroupLabel"));

        gridLayout_4->addWidget(sapGroupLabel, 2, 3, 1, 1);

        sapGroup = new QLineEdit(groupBox_3);
        sapGroup->setObjectName(QString::fromUtf8("sapGroup"));

        gridLayout_4->addWidget(sapGroup, 2, 4, 1, 1);

        ttlLabel = new QLabel(groupBox_3);
        ttlLabel->setObjectName(QString::fromUtf8("ttlLabel"));

        gridLayout_4->addWidget(ttlLabel, 3, 0, 1, 2);

        ttl = new QSpinBox(groupBox_3);
        ttl->setObjectName(QString::fromUtf8("ttl"));
        ttl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ttl->setMinimum(1);
        ttl->setMaximum(255);

        gridLayout_4->addWidget(ttl, 3, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 0, 1, 2);

        groupBox_4 = new QGroupBox(miscPage);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        _4 = new QHBoxLayout(groupBox_4);
        _4->setObjectName(QString::fromUtf8("_4"));
        mrlEdit = new QTextEdit(groupBox_4);
        mrlEdit->setObjectName(QString::fromUtf8("mrlEdit"));
        mrlEdit->setAcceptRichText(false);

        _4->addWidget(mrlEdit);


        gridLayout_2->addWidget(groupBox_4, 1, 0, 1, 2);

        prevButton2 = new QPushButton(miscPage);
        prevButton2->setObjectName(QString::fromUtf8("prevButton2"));

        gridLayout_2->addWidget(prevButton2, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(507, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        toolBox->addItem(miscPage, QString::fromUtf8("Option Setup"));

        verticalLayout->addWidget(toolBox);

        acceptButtonBox = new QDialogButtonBox(Sout);
        acceptButtonBox->setObjectName(QString::fromUtf8("acceptButtonBox"));
        acceptButtonBox->setStandardButtons(QDialogButtonBox::NoButton);

        verticalLayout->addWidget(acceptButtonBox);


        retranslateUi(Sout);

        toolBox->setCurrentIndex(0);
        destTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sout);
    } // setupUi

    void retranslateUi(QWidget *Sout)
    {
        Sout->setWindowTitle(Q_("Stream Output", 0));
        nextButton->setText(Q_("Next", 0));
        toolBox->setItemText(toolBox->indexOf(sourcePage), Q_("Source", 0));
        groupBox->setTitle(Q_("Destinations", 0));
        label->setText(Q_("New destination", 0));
        addButton->setText(Q_("Add", 0));
        label_2->setText(Q_("Add destinations following the streaming methods you need. Be sure to check with transcoding that the format is compatible with the method used.", 0));
        localOutput->setText(Q_("Display locally", 0));
        destTab->setTabText(destTab->indexOf(tab), QString());
        groupBox_2->setTitle(Q_("Transcoding options", 0));
        transcodeBox->setText(Q_("Activate Transcoding", 0));
        prevButton->setText(Q_("Previous", 0));
        nextButton2->setText(Q_("Next", 0));
        toolBox->setItemText(toolBox->indexOf(destPage), Q_("Destination Setup", 0));
        groupBox_3->setTitle(Q_("Miscellaneous Options", 0));
        soutAll->setText(Q_("Stream all elementary streams", 0));
        sap->setText(Q_("SAP announce", 0));
        sapGroupLabel->setText(Q_("Group name", 0));
        ttlLabel->setText(Q_("Time-To-Live (TTL)", 0));
        groupBox_4->setTitle(Q_("Generated stream output string", 0));
        prevButton2->setText(Q_("Previous", 0));
        toolBox->setItemText(toolBox->indexOf(miscPage), Q_("Option Setup", 0));
    } // retranslateUi

};

namespace Ui {
    class Sout: public Ui_Sout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SOUT_H
