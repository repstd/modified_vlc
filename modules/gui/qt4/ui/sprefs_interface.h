#define Q_(a,b) QString::fromUtf8(_(a))
/********************************************************************************
** Form generated from reading UI file 'sprefs_interface.ui'
**
** Created: Mon Dec 7 17:03:20 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SPREFS_INTERFACE_H
#define SPREFS_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>
#include "components/preferences_widgets.hpp"

QT_BEGIN_NAMESPACE

class Ui_SPrefsInterface
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *OneInterfaceBox;
    QGridLayout *gridLayout_2;
    QCheckBox *OneInterfaceMode;
    QCheckBox *EnqueueOneInterfaceMode;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *updatesDays;
    QComboBox *artFetcher;
    QLabel *filterLabel;
    QLineEdit *recentlyPlayedFilters;
    QCheckBox *saveRecentlyPlayed;
    QLabel *artFetchLabel;
    QCheckBox *updatesBox;
    QGroupBox *languageBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *languageLabel;
    QComboBox *language;
    QGroupBox *playlistGroupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *treePlaylist;
    QCheckBox *playPauseBox;
    QLabel *assocLabel;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *assoButton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *sqlMLbtn;
    QGroupBox *LooknfeelBox;
    QGridLayout *gridLayout;
    QRadioButton *skins;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *qt4;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line;
    QStackedWidget *styleStackedWidget;
    QWidget *nativePage;
    QHBoxLayout *horizontalLayout_4;
    InterfacePreviewWidget *mainPreview;
    QWidget *native_zone;
    QGridLayout *gridLayout1;
    QCheckBox *fsController;
    QCheckBox *minimalviewBox;
    QCheckBox *pauseMinimizedBox;
    QCheckBox *embedVideo;
    QCheckBox *resizingBox;
    QCheckBox *systrayBox;
    QCheckBox *sysPop;
    QLabel *stylesLabel;
    QComboBox *stylesCombo;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QWidget *skinsPage;
    QHBoxLayout *horizontalLayout_5;
    InterfacePreviewWidget *skinsPreview;
    QWidget *skins_zone;
    QGridLayout *gridLayout_7;
    QLabel *skinFileLabel;
    QLineEdit *fileSkin;
    QPushButton *skinBrowse;
    QLabel *skinsLabel;

    void setupUi(QWidget *SPrefsInterface)
    {
        if (SPrefsInterface->objectName().isEmpty())
            SPrefsInterface->setObjectName(QString::fromUtf8("SPrefsInterface"));
        SPrefsInterface->resize(734, 623);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SPrefsInterface->sizePolicy().hasHeightForWidth());
        SPrefsInterface->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(SPrefsInterface);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(9, 0, -1, 0);
        OneInterfaceBox = new QGroupBox(SPrefsInterface);
        OneInterfaceBox->setObjectName(QString::fromUtf8("OneInterfaceBox"));
        gridLayout_2 = new QGridLayout(OneInterfaceBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(9, -1, 9, 9);
        OneInterfaceMode = new QCheckBox(OneInterfaceBox);
        OneInterfaceMode->setObjectName(QString::fromUtf8("OneInterfaceMode"));

        gridLayout_2->addWidget(OneInterfaceMode, 0, 0, 1, 1);

        EnqueueOneInterfaceMode = new QCheckBox(OneInterfaceBox);
        EnqueueOneInterfaceMode->setObjectName(QString::fromUtf8("EnqueueOneInterfaceMode"));

        gridLayout_2->addWidget(EnqueueOneInterfaceMode, 0, 1, 1, 2);


        gridLayout_3->addWidget(OneInterfaceBox, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(SPrefsInterface);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        updatesDays = new QSpinBox(groupBox_2);
        updatesDays->setObjectName(QString::fromUtf8("updatesDays"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(updatesDays->sizePolicy().hasHeightForWidth());
        updatesDays->setSizePolicy(sizePolicy1);
        updatesDays->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(updatesDays, 1, 3, 1, 1);

        artFetcher = new QComboBox(groupBox_2);
        artFetcher->setObjectName(QString::fromUtf8("artFetcher"));

        gridLayout_5->addWidget(artFetcher, 0, 3, 1, 2);

        filterLabel = new QLabel(groupBox_2);
        filterLabel->setObjectName(QString::fromUtf8("filterLabel"));
        filterLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        filterLabel->setMargin(5);

        gridLayout_5->addWidget(filterLabel, 2, 2, 1, 1);

        recentlyPlayedFilters = new QLineEdit(groupBox_2);
        recentlyPlayedFilters->setObjectName(QString::fromUtf8("recentlyPlayedFilters"));
        sizePolicy1.setHeightForWidth(recentlyPlayedFilters->sizePolicy().hasHeightForWidth());
        recentlyPlayedFilters->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(recentlyPlayedFilters, 2, 3, 1, 2);

        saveRecentlyPlayed = new QCheckBox(groupBox_2);
        saveRecentlyPlayed->setObjectName(QString::fromUtf8("saveRecentlyPlayed"));
        saveRecentlyPlayed->setMinimumSize(QSize(220, 0));

        gridLayout_5->addWidget(saveRecentlyPlayed, 2, 0, 1, 1);

        artFetchLabel = new QLabel(groupBox_2);
        artFetchLabel->setObjectName(QString::fromUtf8("artFetchLabel"));
        artFetchLabel->setMinimumSize(QSize(220, 0));

        gridLayout_5->addWidget(artFetchLabel, 0, 0, 1, 1);

        updatesBox = new QCheckBox(groupBox_2);
        updatesBox->setObjectName(QString::fromUtf8("updatesBox"));
        updatesBox->setMinimumSize(QSize(220, 0));

        gridLayout_5->addWidget(updatesBox, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 3, 0, 1, 2);

        languageBox = new QGroupBox(SPrefsInterface);
        languageBox->setObjectName(QString::fromUtf8("languageBox"));
        horizontalLayout_3 = new QHBoxLayout(languageBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        languageLabel = new QLabel(languageBox);
        languageLabel->setObjectName(QString::fromUtf8("languageLabel"));
        languageLabel->setMaximumSize(QSize(220, 16777215));
        languageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(languageLabel);

        language = new QComboBox(languageBox);
        language->setObjectName(QString::fromUtf8("language"));

        horizontalLayout_3->addWidget(language);


        gridLayout_3->addWidget(languageBox, 0, 0, 1, 2);

        playlistGroupBox = new QGroupBox(SPrefsInterface);
        playlistGroupBox->setObjectName(QString::fromUtf8("playlistGroupBox"));
        gridLayout_4 = new QGridLayout(playlistGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        treePlaylist = new QCheckBox(playlistGroupBox);
        treePlaylist->setObjectName(QString::fromUtf8("treePlaylist"));

        gridLayout_4->addWidget(treePlaylist, 0, 0, 1, 1);

        playPauseBox = new QCheckBox(playlistGroupBox);
        playPauseBox->setObjectName(QString::fromUtf8("playPauseBox"));

        gridLayout_4->addWidget(playPauseBox, 0, 2, 1, 2);

        assocLabel = new QLabel(playlistGroupBox);
        assocLabel->setObjectName(QString::fromUtf8("assocLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(assocLabel->sizePolicy().hasHeightForWidth());
        assocLabel->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(assocLabel, 2, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 2, 1, 1, 1);

        assoButton = new QPushButton(playlistGroupBox);
        assoButton->setObjectName(QString::fromUtf8("assoButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(assoButton->sizePolicy().hasHeightForWidth());
        assoButton->setSizePolicy(sizePolicy3);
        assoButton->setMinimumSize(QSize(220, 0));

        gridLayout_4->addWidget(assoButton, 2, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 2, 3, 1, 1);

        sqlMLbtn = new QPushButton(playlistGroupBox);
        sqlMLbtn->setObjectName(QString::fromUtf8("sqlMLbtn"));

        gridLayout_4->addWidget(sqlMLbtn, 1, 0, 1, 1);


        gridLayout_3->addWidget(playlistGroupBox, 4, 0, 1, 2);

        LooknfeelBox = new QGroupBox(SPrefsInterface);
        LooknfeelBox->setObjectName(QString::fromUtf8("LooknfeelBox"));
        gridLayout = new QGridLayout(LooknfeelBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        skins = new QRadioButton(LooknfeelBox);
        skins->setObjectName(QString::fromUtf8("skins"));

        gridLayout->addWidget(skins, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        qt4 = new QRadioButton(LooknfeelBox);
        qt4->setObjectName(QString::fromUtf8("qt4"));
        qt4->setChecked(true);

        gridLayout->addWidget(qt4, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        line = new QFrame(LooknfeelBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 2, 1, 3);

        styleStackedWidget = new QStackedWidget(LooknfeelBox);
        styleStackedWidget->setObjectName(QString::fromUtf8("styleStackedWidget"));
        nativePage = new QWidget();
        nativePage->setObjectName(QString::fromUtf8("nativePage"));
        horizontalLayout_4 = new QHBoxLayout(nativePage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, 0, -1);
        mainPreview = new InterfacePreviewWidget(nativePage);
        mainPreview->setObjectName(QString::fromUtf8("mainPreview"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mainPreview->sizePolicy().hasHeightForWidth());
        mainPreview->setSizePolicy(sizePolicy4);
        mainPreview->setMinimumSize(QSize(122, 50));
        mainPreview->setBaseSize(QSize(0, 0));
        mainPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 192, 192);"));
        mainPreview->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_4->addWidget(mainPreview);

        native_zone = new QWidget(nativePage);
        native_zone->setObjectName(QString::fromUtf8("native_zone"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(10);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(native_zone->sizePolicy().hasHeightForWidth());
        native_zone->setSizePolicy(sizePolicy5);
        gridLayout1 = new QGridLayout(native_zone);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setContentsMargins(0, 0, -1, -1);
        fsController = new QCheckBox(native_zone);
        fsController->setObjectName(QString::fromUtf8("fsController"));

        gridLayout1->addWidget(fsController, 0, 0, 1, 3);

        minimalviewBox = new QCheckBox(native_zone);
        minimalviewBox->setObjectName(QString::fromUtf8("minimalviewBox"));

        gridLayout1->addWidget(minimalviewBox, 1, 0, 1, 1);

        pauseMinimizedBox = new QCheckBox(native_zone);
        pauseMinimizedBox->setObjectName(QString::fromUtf8("pauseMinimizedBox"));

        gridLayout1->addWidget(pauseMinimizedBox, 1, 2, 1, 2);

        embedVideo = new QCheckBox(native_zone);
        embedVideo->setObjectName(QString::fromUtf8("embedVideo"));

        gridLayout1->addWidget(embedVideo, 2, 0, 1, 1);

        resizingBox = new QCheckBox(native_zone);
        resizingBox->setObjectName(QString::fromUtf8("resizingBox"));

        gridLayout1->addWidget(resizingBox, 2, 2, 1, 2);

        systrayBox = new QCheckBox(native_zone);
        systrayBox->setObjectName(QString::fromUtf8("systrayBox"));

        gridLayout1->addWidget(systrayBox, 3, 0, 2, 1);

        sysPop = new QCheckBox(native_zone);
        sysPop->setObjectName(QString::fromUtf8("sysPop"));

        gridLayout1->addWidget(sysPop, 3, 2, 2, 2);

        stylesLabel = new QLabel(native_zone);
        stylesLabel->setObjectName(QString::fromUtf8("stylesLabel"));
        sizePolicy2.setHeightForWidth(stylesLabel->sizePolicy().hasHeightForWidth());
        stylesLabel->setSizePolicy(sizePolicy2);

        gridLayout1->addWidget(stylesLabel, 5, 0, 1, 1);

        stylesCombo = new QComboBox(native_zone);
        stylesCombo->setObjectName(QString::fromUtf8("stylesCombo"));

        gridLayout1->addWidget(stylesCombo, 5, 2, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer_7, 1, 4, 1, 1);


        horizontalLayout_4->addWidget(native_zone);

        styleStackedWidget->addWidget(nativePage);
        skinsPage = new QWidget();
        skinsPage->setObjectName(QString::fromUtf8("skinsPage"));
        horizontalLayout_5 = new QHBoxLayout(skinsPage);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, 0, -1);
        skinsPreview = new InterfacePreviewWidget(skinsPage);
        skinsPreview->setObjectName(QString::fromUtf8("skinsPreview"));
        sizePolicy4.setHeightForWidth(skinsPreview->sizePolicy().hasHeightForWidth());
        skinsPreview->setSizePolicy(sizePolicy4);
        skinsPreview->setMinimumSize(QSize(122, 50));
        skinsPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 192, 192);"));
        skinsPreview->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(skinsPreview);

        skins_zone = new QWidget(skinsPage);
        skins_zone->setObjectName(QString::fromUtf8("skins_zone"));
        skins_zone->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(skins_zone->sizePolicy().hasHeightForWidth());
        skins_zone->setSizePolicy(sizePolicy6);
        gridLayout_7 = new QGridLayout(skins_zone);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        skinFileLabel = new QLabel(skins_zone);
        skinFileLabel->setObjectName(QString::fromUtf8("skinFileLabel"));
        skinFileLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(skinFileLabel, 1, 1, 1, 1);

        fileSkin = new QLineEdit(skins_zone);
        fileSkin->setObjectName(QString::fromUtf8("fileSkin"));
        sizePolicy1.setHeightForWidth(fileSkin->sizePolicy().hasHeightForWidth());
        fileSkin->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(fileSkin, 1, 2, 1, 1);

        skinBrowse = new QPushButton(skins_zone);
        skinBrowse->setObjectName(QString::fromUtf8("skinBrowse"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(skinBrowse->sizePolicy().hasHeightForWidth());
        skinBrowse->setSizePolicy(sizePolicy7);

        gridLayout_7->addWidget(skinBrowse, 1, 3, 1, 1);

        skinsLabel = new QLabel(skins_zone);
        skinsLabel->setObjectName(QString::fromUtf8("skinsLabel"));
        sizePolicy6.setHeightForWidth(skinsLabel->sizePolicy().hasHeightForWidth());
        skinsLabel->setSizePolicy(sizePolicy6);
        skinsLabel->setFrameShape(QFrame::NoFrame);
        skinsLabel->setText(QString::fromUtf8("-This is the skinsLabel place-"));
        skinsLabel->setTextFormat(Qt::RichText);
        skinsLabel->setScaledContents(false);
        skinsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        skinsLabel->setWordWrap(true);
        skinsLabel->setMargin(5);
        skinsLabel->setOpenExternalLinks(true);

        gridLayout_7->addWidget(skinsLabel, 2, 1, 1, 3);


        horizontalLayout_5->addWidget(skins_zone);

        styleStackedWidget->addWidget(skinsPage);

        gridLayout->addWidget(styleStackedWidget, 2, 0, 6, 7);


        gridLayout_3->addWidget(LooknfeelBox, 1, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        filterLabel->setBuddy(recentlyPlayedFilters);
        artFetchLabel->setBuddy(artFetcher);
        languageLabel->setBuddy(language);
        assocLabel->setBuddy(assoButton);
        stylesLabel->setBuddy(stylesCombo);
        skinFileLabel->setBuddy(fileSkin);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(language, qt4);
        QWidget::setTabOrder(qt4, skins);
        QWidget::setTabOrder(skins, fsController);
        QWidget::setTabOrder(fsController, minimalviewBox);
        QWidget::setTabOrder(minimalviewBox, pauseMinimizedBox);
        QWidget::setTabOrder(pauseMinimizedBox, embedVideo);
        QWidget::setTabOrder(embedVideo, resizingBox);
        QWidget::setTabOrder(resizingBox, systrayBox);
        QWidget::setTabOrder(systrayBox, sysPop);
        QWidget::setTabOrder(sysPop, stylesCombo);
        QWidget::setTabOrder(stylesCombo, OneInterfaceMode);
        QWidget::setTabOrder(OneInterfaceMode, EnqueueOneInterfaceMode);
        QWidget::setTabOrder(EnqueueOneInterfaceMode, artFetcher);
        QWidget::setTabOrder(artFetcher, updatesBox);
        QWidget::setTabOrder(updatesBox, updatesDays);
        QWidget::setTabOrder(updatesDays, saveRecentlyPlayed);
        QWidget::setTabOrder(saveRecentlyPlayed, recentlyPlayedFilters);
        QWidget::setTabOrder(recentlyPlayedFilters, treePlaylist);
        QWidget::setTabOrder(treePlaylist, assoButton);
        QWidget::setTabOrder(assoButton, fileSkin);
        QWidget::setTabOrder(fileSkin, skinBrowse);

        retranslateUi(SPrefsInterface);

        styleStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SPrefsInterface);
    } // setupUi

    void retranslateUi(QWidget *SPrefsInterface)
    {
        SPrefsInterface->setWindowTitle(Q_("Form", 0));
        OneInterfaceBox->setTitle(Q_("Instances", 0));
        OneInterfaceMode->setText(Q_("Allow only one instance", 0));
        EnqueueOneInterfaceMode->setText(Q_("Enqueue files when in one instance mode", 0));
        groupBox_2->setTitle(Q_("Privacy / Network Interaction", 0));
        updatesDays->setSuffix(Q_(" days", 0));
        updatesDays->setPrefix(Q_("Every ", 0));
        filterLabel->setText(Q_("Filter:", 0));
#ifndef QT_NO_TOOLTIP
        recentlyPlayedFilters->setToolTip(Q_("Separate words by | (without space)", 0));
#endif // QT_NO_TOOLTIP
        saveRecentlyPlayed->setText(Q_("Save recently played items", 0));
        artFetchLabel->setText(Q_("Album art download policy:", 0));
        updatesBox->setText(Q_("Activate updates notifier", 0));
        languageBox->setTitle(Q_("Language", 0));
        languageLabel->setText(Q_("Menus language:", 0));
        playlistGroupBox->setTitle(Q_("Playlist", 0));
        treePlaylist->setText(Q_("Display playlist tree", 0));
        playPauseBox->setText(Q_("Pause on the last frame of a video", 0));
        assocLabel->setText(Q_("File extensions association", 0));
        assoButton->setText(Q_("Set up associations...", 0));
        sqlMLbtn->setText(Q_("Configure Media Library", 0));
        LooknfeelBox->setTitle(Q_("Look and feel", 0));
        skins->setText(Q_("Use custom skin", 0));
#ifndef QT_NO_TOOLTIP
        qt4->setToolTip(Q_("This is VLC's default interface, with a native look and feel.", 0));
#endif // QT_NO_TOOLTIP
        qt4->setText(Q_("Use native style", 0));
        fsController->setText(Q_("Show controls in full screen mode", 0));
        minimalviewBox->setText(Q_("Start in minimal view mode", 0));
        pauseMinimizedBox->setText(Q_("Pause playback when minimized", 0));
        embedVideo->setText(Q_("Integrate video in interface", 0));
        resizingBox->setText(Q_("Resize interface to video size", 0));
        systrayBox->setText(Q_("Show systray icon", 0));
        sysPop->setText(Q_("Systray popup when minimized", 0));
        stylesLabel->setText(Q_("Force window style:", 0));
        skinFileLabel->setText(Q_("Skin resource file:", 0));
        skinBrowse->setText(Q_("Choose...", 0));
    } // retranslateUi

};

namespace Ui {
    class SPrefsInterface: public Ui_SPrefsInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPREFS_INTERFACE_H
