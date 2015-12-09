#define Q_(a,b) QString::fromUtf8(_(a))
/********************************************************************************
** Form generated from reading UI file 'equalizer.ui'
**
** Created: Mon Dec 7 17:03:20 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EQUALIZER_H
#define EQUALIZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EqualizerWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QCheckBox *enableCheck;
    QCheckBox *eq2PassCheck;
    QSpacerItem *spacerItem;
    QLabel *presetLabel;
    QComboBox *presetsCombo;
    QSlider *preampSlider;
    QFrame *frame;
    QLabel *preampLabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *EqualizerWidget)
    {
        if (EqualizerWidget->objectName().isEmpty())
            EqualizerWidget->setObjectName(QString::fromUtf8("EqualizerWidget"));
        EqualizerWidget->resize(341, 241);
        gridLayout = new QGridLayout(EqualizerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        enableCheck = new QCheckBox(EqualizerWidget);
        enableCheck->setObjectName(QString::fromUtf8("enableCheck"));

        hboxLayout->addWidget(enableCheck);

        eq2PassCheck = new QCheckBox(EqualizerWidget);
        eq2PassCheck->setObjectName(QString::fromUtf8("eq2PassCheck"));

        hboxLayout->addWidget(eq2PassCheck);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        presetLabel = new QLabel(EqualizerWidget);
        presetLabel->setObjectName(QString::fromUtf8("presetLabel"));
        presetLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        hboxLayout->addWidget(presetLabel);

        presetsCombo = new QComboBox(EqualizerWidget);
        presetsCombo->setObjectName(QString::fromUtf8("presetsCombo"));
        presetsCombo->setMinimumSize(QSize(110, 0));

        hboxLayout->addWidget(presetsCombo);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 3);

        preampSlider = new QSlider(EqualizerWidget);
        preampSlider->setObjectName(QString::fromUtf8("preampSlider"));
        preampSlider->setMaximum(400);
        preampSlider->setOrientation(Qt::Vertical);
        preampSlider->setInvertedAppearance(false);

        gridLayout->addWidget(preampSlider, 1, 0, 1, 1);

        frame = new QFrame(EqualizerWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);

        gridLayout->addWidget(frame, 1, 2, 2, 1);

        preampLabel = new QLabel(EqualizerWidget);
        preampLabel->setObjectName(QString::fromUtf8("preampLabel"));

        gridLayout->addWidget(preampLabel, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        presetLabel->setBuddy(presetsCombo);
        preampLabel->setBuddy(preampSlider);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(enableCheck, eq2PassCheck);
        QWidget::setTabOrder(eq2PassCheck, presetsCombo);
        QWidget::setTabOrder(presetsCombo, preampSlider);

        retranslateUi(EqualizerWidget);

        QMetaObject::connectSlotsByName(EqualizerWidget);
    } // setupUi

    void retranslateUi(QWidget *EqualizerWidget)
    {
        EqualizerWidget->setWindowTitle(Q_("Form", 0));
        enableCheck->setText(Q_("Enable", 0));
        eq2PassCheck->setText(Q_("2 Pass", 0));
        presetLabel->setText(Q_("Preset", 0));
        preampLabel->setText(Q_("Preamp", 0));
    } // retranslateUi

};

namespace Ui {
    class EqualizerWidget: public Ui_EqualizerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EQUALIZER_H
