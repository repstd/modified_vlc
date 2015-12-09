#define Q_(a,b) QString::fromUtf8(_(a))
/********************************************************************************
** Form generated from reading UI file 'profiles.ui'
**
** Created: Mon Dec 7 17:03:20 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PROFILES_H
#define PROFILES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profiles
{
public:
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLineEdit *profileLine;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *muxer;
    QGridLayout *gridLayout;
    QRadioButton *TSMux;
    QRadioButton *PSMux;
    QRadioButton *WAVMux;
    QRadioButton *WEBMux;
    QRadioButton *ASFMux;
    QRadioButton *OggMux;
    QRadioButton *RAWMux;
    QRadioButton *MPEG1Mux;
    QRadioButton *FLVMux;
    QRadioButton *AVIMux;
    QRadioButton *MOVMux;
    QRadioButton *MJPEGMux;
    QRadioButton *MKVMux;
    QWidget *videoCodec;
    QGridLayout *gridLayout_2;
    QCheckBox *transcodeVideo;
    QLabel *vCodecLabel;
    QComboBox *vCodecBox;
    QLabel *vBitrateLabel;
    QSpinBox *vBitrateSpin;
    QLabel *vFrameLabel;
    QDoubleSpinBox *vFrameBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QLabel *vScaleLabel;
    QComboBox *vScaleBox;
    QLabel *widthLabel;
    QLineEdit *widthBox;
    QSpacerItem *horizontalSpacer;
    QLabel *heightLabel;
    QLineEdit *heightBox;
    QCheckBox *keepVideo;
    QWidget *audioCodec;
    QGridLayout *gridLayout_3;
    QCheckBox *transcodeAudio;
    QCheckBox *keepAudio;
    QLabel *aCodecLabel;
    QComboBox *aCodecBox;
    QLabel *aBitrateLabel;
    QSpinBox *aBitrateSpin;
    QLabel *aChannelsLabel;
    QSpinBox *aChannelsSpin;
    QLabel *aSampleLabel;
    QComboBox *aSampleBox;
    QSpacerItem *verticalSpacer;
    QWidget *subtitles;
    QGridLayout *_4;
    QCheckBox *transcodeSubs;
    QComboBox *subsCodecBox;
    QCheckBox *subsOverlay;

    void setupUi(QWidget *Profiles)
    {
        if (Profiles->objectName().isEmpty())
            Profiles->setObjectName(QString::fromUtf8("Profiles"));
        Profiles->resize(584, 442);
        gridLayout_4 = new QGridLayout(Profiles);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(Profiles);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMargin(10);

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        profileLine = new QLineEdit(Profiles);
        profileLine->setObjectName(QString::fromUtf8("profileLine"));

        gridLayout_4->addWidget(profileLine, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Profiles);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));

        gridLayout_4->addWidget(buttonBox, 2, 1, 1, 1);

        tabWidget = new QTabWidget(Profiles);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        muxer = new QWidget();
        muxer->setObjectName(QString::fromUtf8("muxer"));
        gridLayout = new QGridLayout(muxer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TSMux = new QRadioButton(muxer);
        TSMux->setObjectName(QString::fromUtf8("TSMux"));
        TSMux->setChecked(true);

        gridLayout->addWidget(TSMux, 2, 0, 1, 1);

        PSMux = new QRadioButton(muxer);
        PSMux->setObjectName(QString::fromUtf8("PSMux"));

        gridLayout->addWidget(PSMux, 3, 0, 1, 1);

        WAVMux = new QRadioButton(muxer);
        WAVMux->setObjectName(QString::fromUtf8("WAVMux"));

        gridLayout->addWidget(WAVMux, 3, 2, 1, 1);

        WEBMux = new QRadioButton(muxer);
        WEBMux->setObjectName(QString::fromUtf8("WEBMux"));

        gridLayout->addWidget(WEBMux, 2, 1, 1, 1);

        ASFMux = new QRadioButton(muxer);
        ASFMux->setObjectName(QString::fromUtf8("ASFMux"));

        gridLayout->addWidget(ASFMux, 6, 0, 1, 1);

        OggMux = new QRadioButton(muxer);
        OggMux->setObjectName(QString::fromUtf8("OggMux"));

        gridLayout->addWidget(OggMux, 2, 2, 1, 1);

        RAWMux = new QRadioButton(muxer);
        RAWMux->setObjectName(QString::fromUtf8("RAWMux"));

        gridLayout->addWidget(RAWMux, 5, 2, 1, 1);

        MPEG1Mux = new QRadioButton(muxer);
        MPEG1Mux->setObjectName(QString::fromUtf8("MPEG1Mux"));

        gridLayout->addWidget(MPEG1Mux, 5, 0, 1, 1);

        FLVMux = new QRadioButton(muxer);
        FLVMux->setObjectName(QString::fromUtf8("FLVMux"));

        gridLayout->addWidget(FLVMux, 3, 3, 1, 1);

        AVIMux = new QRadioButton(muxer);
        AVIMux->setObjectName(QString::fromUtf8("AVIMux"));

        gridLayout->addWidget(AVIMux, 5, 3, 1, 1);

        MOVMux = new QRadioButton(muxer);
        MOVMux->setObjectName(QString::fromUtf8("MOVMux"));

        gridLayout->addWidget(MOVMux, 2, 3, 1, 1);

        MJPEGMux = new QRadioButton(muxer);
        MJPEGMux->setObjectName(QString::fromUtf8("MJPEGMux"));

        gridLayout->addWidget(MJPEGMux, 3, 1, 1, 1);

        MKVMux = new QRadioButton(muxer);
        MKVMux->setObjectName(QString::fromUtf8("MKVMux"));

        gridLayout->addWidget(MKVMux, 5, 1, 1, 1);

        tabWidget->addTab(muxer, QString());
        videoCodec = new QWidget();
        videoCodec->setObjectName(QString::fromUtf8("videoCodec"));
        videoCodec->setEnabled(true);
        gridLayout_2 = new QGridLayout(videoCodec);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        transcodeVideo = new QCheckBox(videoCodec);
        transcodeVideo->setObjectName(QString::fromUtf8("transcodeVideo"));

        gridLayout_2->addWidget(transcodeVideo, 0, 0, 1, 2);

        vCodecLabel = new QLabel(videoCodec);
        vCodecLabel->setObjectName(QString::fromUtf8("vCodecLabel"));
        vCodecLabel->setEnabled(true);

        gridLayout_2->addWidget(vCodecLabel, 2, 0, 1, 1);

        vCodecBox = new QComboBox(videoCodec);
        vCodecBox->setObjectName(QString::fromUtf8("vCodecBox"));
        vCodecBox->setEditable(false);

        gridLayout_2->addWidget(vCodecBox, 2, 1, 1, 2);

        vBitrateLabel = new QLabel(videoCodec);
        vBitrateLabel->setObjectName(QString::fromUtf8("vBitrateLabel"));

        gridLayout_2->addWidget(vBitrateLabel, 3, 0, 1, 2);

        vBitrateSpin = new QSpinBox(videoCodec);
        vBitrateSpin->setObjectName(QString::fromUtf8("vBitrateSpin"));
        vBitrateSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        vBitrateSpin->setAccelerated(true);
        vBitrateSpin->setMinimum(0);
        vBitrateSpin->setMaximum(32768);
        vBitrateSpin->setValue(800);

        gridLayout_2->addWidget(vBitrateSpin, 3, 2, 1, 1);

        vFrameLabel = new QLabel(videoCodec);
        vFrameLabel->setObjectName(QString::fromUtf8("vFrameLabel"));

        gridLayout_2->addWidget(vFrameLabel, 4, 0, 1, 2);

        vFrameBox = new QDoubleSpinBox(videoCodec);
        vFrameBox->setObjectName(QString::fromUtf8("vFrameBox"));
        vFrameBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(vFrameBox, 4, 2, 1, 1);

        groupBox = new QGroupBox(videoCodec);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setWordWrap(true);

        gridLayout1->addWidget(label, 0, 0, 1, 4);

        vScaleLabel = new QLabel(groupBox);
        vScaleLabel->setObjectName(QString::fromUtf8("vScaleLabel"));

        gridLayout1->addWidget(vScaleLabel, 1, 0, 1, 1);

        vScaleBox = new QComboBox(groupBox);
        vScaleBox->setObjectName(QString::fromUtf8("vScaleBox"));
        vScaleBox->setEditable(true);

        gridLayout1->addWidget(vScaleBox, 1, 3, 1, 2);

        widthLabel = new QLabel(groupBox);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));

        gridLayout1->addWidget(widthLabel, 2, 0, 1, 1);

        widthBox = new QLineEdit(groupBox);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widthBox->sizePolicy().hasHeightForWidth());
        widthBox->setSizePolicy(sizePolicy2);
        widthBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(widthBox, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout1->addItem(horizontalSpacer, 2, 2, 1, 1);

        heightLabel = new QLabel(groupBox);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));

        gridLayout1->addWidget(heightLabel, 2, 3, 1, 1);

        heightBox = new QLineEdit(groupBox);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        sizePolicy2.setHeightForWidth(heightBox->sizePolicy().hasHeightForWidth());
        heightBox->setSizePolicy(sizePolicy2);
        heightBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout1->addWidget(heightBox, 2, 4, 1, 1);


        gridLayout_2->addWidget(groupBox, 5, 0, 1, 3);

        keepVideo = new QCheckBox(videoCodec);
        keepVideo->setObjectName(QString::fromUtf8("keepVideo"));

        gridLayout_2->addWidget(keepVideo, 1, 0, 1, 1);

        tabWidget->addTab(videoCodec, QString());
        audioCodec = new QWidget();
        audioCodec->setObjectName(QString::fromUtf8("audioCodec"));
        gridLayout_3 = new QGridLayout(audioCodec);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        transcodeAudio = new QCheckBox(audioCodec);
        transcodeAudio->setObjectName(QString::fromUtf8("transcodeAudio"));

        gridLayout_3->addWidget(transcodeAudio, 0, 0, 1, 1);

        keepAudio = new QCheckBox(audioCodec);
        keepAudio->setObjectName(QString::fromUtf8("keepAudio"));

        gridLayout_3->addWidget(keepAudio, 1, 0, 1, 2);

        aCodecLabel = new QLabel(audioCodec);
        aCodecLabel->setObjectName(QString::fromUtf8("aCodecLabel"));

        gridLayout_3->addWidget(aCodecLabel, 2, 0, 1, 1);

        aCodecBox = new QComboBox(audioCodec);
        aCodecBox->setObjectName(QString::fromUtf8("aCodecBox"));

        gridLayout_3->addWidget(aCodecBox, 2, 2, 1, 2);

        aBitrateLabel = new QLabel(audioCodec);
        aBitrateLabel->setObjectName(QString::fromUtf8("aBitrateLabel"));

        gridLayout_3->addWidget(aBitrateLabel, 3, 0, 1, 1);

        aBitrateSpin = new QSpinBox(audioCodec);
        aBitrateSpin->setObjectName(QString::fromUtf8("aBitrateSpin"));
        aBitrateSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        aBitrateSpin->setMinimum(8);
        aBitrateSpin->setMaximum(512);
        aBitrateSpin->setValue(128);

        gridLayout_3->addWidget(aBitrateSpin, 3, 3, 1, 1);

        aChannelsLabel = new QLabel(audioCodec);
        aChannelsLabel->setObjectName(QString::fromUtf8("aChannelsLabel"));

        gridLayout_3->addWidget(aChannelsLabel, 4, 0, 1, 1);

        aChannelsSpin = new QSpinBox(audioCodec);
        aChannelsSpin->setObjectName(QString::fromUtf8("aChannelsSpin"));
        aChannelsSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        aChannelsSpin->setMinimum(1);
        aChannelsSpin->setMaximum(10);
        aChannelsSpin->setValue(2);

        gridLayout_3->addWidget(aChannelsSpin, 4, 3, 1, 1);

        aSampleLabel = new QLabel(audioCodec);
        aSampleLabel->setObjectName(QString::fromUtf8("aSampleLabel"));

        gridLayout_3->addWidget(aSampleLabel, 5, 0, 1, 1);

        aSampleBox = new QComboBox(audioCodec);
        aSampleBox->setObjectName(QString::fromUtf8("aSampleBox"));

        gridLayout_3->addWidget(aSampleBox, 5, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 6, 2, 1, 1);

        tabWidget->addTab(audioCodec, QString());
        subtitles = new QWidget();
        subtitles->setObjectName(QString::fromUtf8("subtitles"));
        _4 = new QGridLayout(subtitles);
        _4->setObjectName(QString::fromUtf8("_4"));
        transcodeSubs = new QCheckBox(subtitles);
        transcodeSubs->setObjectName(QString::fromUtf8("transcodeSubs"));

        _4->addWidget(transcodeSubs, 0, 0, 1, 1);

        subsCodecBox = new QComboBox(subtitles);
        subsCodecBox->setObjectName(QString::fromUtf8("subsCodecBox"));

        _4->addWidget(subsCodecBox, 0, 1, 1, 1);

        subsOverlay = new QCheckBox(subtitles);
        subsOverlay->setObjectName(QString::fromUtf8("subsOverlay"));

        _4->addWidget(subsOverlay, 1, 1, 1, 1);

        tabWidget->addTab(subtitles, QString());

        gridLayout_4->addWidget(tabWidget, 1, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(profileLine);
        vCodecLabel->setBuddy(vCodecBox);
        vBitrateLabel->setBuddy(vBitrateSpin);
        vFrameLabel->setBuddy(vFrameBox);
        vScaleLabel->setBuddy(vScaleBox);
        widthLabel->setBuddy(widthBox);
        heightLabel->setBuddy(heightBox);
        aCodecLabel->setBuddy(aCodecBox);
        aBitrateLabel->setBuddy(aBitrateSpin);
        aChannelsLabel->setBuddy(aChannelsSpin);
        aSampleLabel->setBuddy(aSampleBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(profileLine, tabWidget);
        QWidget::setTabOrder(tabWidget, TSMux);
        QWidget::setTabOrder(TSMux, ASFMux);
        QWidget::setTabOrder(ASFMux, OggMux);
        QWidget::setTabOrder(OggMux, MOVMux);
        QWidget::setTabOrder(MOVMux, PSMux);
        QWidget::setTabOrder(PSMux, MJPEGMux);
        QWidget::setTabOrder(MJPEGMux, WAVMux);
        QWidget::setTabOrder(WAVMux, FLVMux);
        QWidget::setTabOrder(FLVMux, MPEG1Mux);
        QWidget::setTabOrder(MPEG1Mux, MKVMux);
        QWidget::setTabOrder(MKVMux, RAWMux);
        QWidget::setTabOrder(RAWMux, AVIMux);
        QWidget::setTabOrder(AVIMux, buttonBox);
        QWidget::setTabOrder(buttonBox, transcodeVideo);
        QWidget::setTabOrder(transcodeVideo, keepVideo);
        QWidget::setTabOrder(keepVideo, vCodecBox);
        QWidget::setTabOrder(vCodecBox, vBitrateSpin);
        QWidget::setTabOrder(vBitrateSpin, vFrameBox);
        QWidget::setTabOrder(vFrameBox, vScaleBox);
        QWidget::setTabOrder(vScaleBox, widthBox);
        QWidget::setTabOrder(widthBox, heightBox);
        QWidget::setTabOrder(heightBox, transcodeAudio);
        QWidget::setTabOrder(transcodeAudio, keepAudio);
        QWidget::setTabOrder(keepAudio, aCodecBox);
        QWidget::setTabOrder(aCodecBox, aBitrateSpin);
        QWidget::setTabOrder(aBitrateSpin, aChannelsSpin);
        QWidget::setTabOrder(aChannelsSpin, aSampleBox);
        QWidget::setTabOrder(aSampleBox, transcodeSubs);
        QWidget::setTabOrder(transcodeSubs, subsCodecBox);
        QWidget::setTabOrder(subsCodecBox, subsOverlay);

        retranslateUi(Profiles);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Profiles);
    } // setupUi

    void retranslateUi(QWidget *Profiles)
    {
        Profiles->setWindowTitle(Q_("Form", 0));
        label_5->setText(Q_("Profile Name", 0));
        TSMux->setText(Q_("MPEG-TS", 0));
        PSMux->setText(Q_("MPEG-PS", 0));
        WAVMux->setText(Q_("WAV", 0));
        WEBMux->setText(Q_("Webm", 0));
        ASFMux->setText(Q_("ASF/WMV", 0));
        OggMux->setText(Q_("Ogg/Ogm", 0));
        RAWMux->setText(Q_("RAW", 0));
        MPEG1Mux->setText(Q_("MPEG 1", 0));
        FLVMux->setText(Q_("FLV", 0));
        AVIMux->setText(Q_("AVI", 0));
        MOVMux->setText(Q_("MP4/MOV", 0));
        MJPEGMux->setText(Q_("MJPEG", 0));
        MKVMux->setText(Q_("MKV", 0));
        tabWidget->setTabText(tabWidget->indexOf(muxer), Q_("Encapsulation", 0));
        transcodeVideo->setText(Q_("Video", 0));
        vCodecLabel->setText(Q_("Codec", 0));
        vBitrateLabel->setText(Q_("Bitrate", 0));
        vBitrateSpin->setSuffix(Q_(" kb/s", 0));
        vFrameLabel->setText(Q_("Frame Rate", 0));
        vFrameBox->setPrefix(QString());
        vFrameBox->setSuffix(Q_(" fps", 0));
        groupBox->setTitle(Q_("Resolution", 0));
        label->setText(Q_("You just need to fill one of the three following parameters, VLC will autodetect the other using the original aspect ratio", 0));
        vScaleLabel->setText(Q_("Scale", 0));
        widthLabel->setText(Q_("Width", 0));
        widthBox->setInputMask(Q_("00000; ", 0));
        widthBox->setText(QString());
        heightLabel->setText(Q_("Height", 0));
        heightBox->setInputMask(Q_("00000; ", 0));
        heightBox->setText(QString());
        keepVideo->setText(Q_("Keep original video track", 0));
        tabWidget->setTabText(tabWidget->indexOf(videoCodec), Q_("Video codec", 0));
        transcodeAudio->setText(Q_("Audio", 0));
        keepAudio->setText(Q_("Keep original audio track", 0));
        aCodecLabel->setText(Q_("Codec", 0));
        aBitrateLabel->setText(Q_("Bitrate", 0));
        aBitrateSpin->setSuffix(Q_(" kb/s", 0));
        aChannelsLabel->setText(Q_("Channels", 0));
        aSampleLabel->setText(Q_("Sample Rate", 0));
        tabWidget->setTabText(tabWidget->indexOf(audioCodec), Q_("Audio codec", 0));
        transcodeSubs->setText(Q_("Subtitles", 0));
        subsOverlay->setText(Q_("Overlay subtitles on the video", 0));
        tabWidget->setTabText(tabWidget->indexOf(subtitles), Q_("Subtitles", 0));
    } // retranslateUi

};

namespace Ui {
    class Profiles: public Ui_Profiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROFILES_H
