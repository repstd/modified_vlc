/****************************************************************************
** Meta object code from reading C++ file 'dialogs_provider.hpp'
**
** Created: Mon Dec 7 17:03:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs_provider.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogs_provider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogsProvider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   16,   16,   16, 0x0a,
      55,   16,   16,   16, 0x0a,
      72,   16,   16,   16, 0x0a,
      90,   16,   16,   16, 0x0a,
     108,   16,   16,   16, 0x0a,
     127,   16,   16,   16, 0x0a,
     141,   16,   16,   16, 0x0a,
     158,   16,   16,   16, 0x0a,
     174,   16,   16,   16, 0x0a,
     191,   16,   16,   16, 0x0a,
     204,   16,   16,   16, 0x0a,
     218,   16,   16,   16, 0x0a,
     235,   16,   16,   16, 0x0a,
     260,   16,   16,   16, 0x0a,
     276,   16,   16,   16, 0x0a,
     291,   16,   16,   16, 0x0a,
     303,   16,   16,   16, 0x0a,
     346,   16,   16,   16, 0x0a,
     365,   16,   16,   16, 0x0a,
     388,   16,   16,   16, 0x0a,
     411,   16,   16,   16, 0x0a,
     424,   16,   16,   16, 0x0a,
     441,   16,   16,   16, 0x0a,
     458,   16,   16,   16, 0x0a,
     474,   16,   16,   16, 0x0a,
     490,   16,   16,   16, 0x0a,
     514,  510,   16,   16, 0x0a,
     534,   16,   16,   16, 0x2a,
     551,  510,   16,   16, 0x0a,
     571,   16,   16,   16, 0x2a,
     588,   16,   16,   16, 0x0a,
     600,   16,   16,   16, 0x0a,
     614,   16,   16,   16, 0x0a,
     656,  628,   16,   16, 0x0a,
     727,  707,   16,   16, 0x2a,
     777,  766,   16,   16, 0x2a,
     811,   16,   16,   16, 0x0a,
     837,   16,   16,   16, 0x0a,
     865,   16,   16,   16, 0x0a,
     881,   16,   16,   16, 0x0a,
     897,   16,   16,   16, 0x0a,
     917,   16,   16,   16, 0x0a,
     924,   16,   16,   16, 0x08,
     945,   16,   16,   16, 0x08,
     972,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogsProvider[] = {
    "DialogsProvider\0\0toolBarConfUpdated()\0"
    "playMRL(QString)\0playlistDialog()\0"
    "bookmarksDialog()\0mediaInfoDialog()\0"
    "mediaCodecDialog()\0prefsDialog()\0"
    "extendedDialog()\0synchroDialog()\0"
    "messagesDialog()\0helpDialog()\0"
    "aboutDialog()\0gotoTimeDialog()\0"
    "podcastConfigureDialog()\0toolbarDialog()\0"
    "pluginDialog()\0epgDialog()\0"
    "openFileGenericDialog(intf_dialog_args_t*)\0"
    "simpleOpenDialog()\0simplePLAppendDialog()\0"
    "simpleMLAppendDialog()\0openDialog()\0"
    "openDiscDialog()\0openFileDialog()\0"
    "openUrlDialog()\0openNetDialog()\0"
    "openCaptureDialog()\0tab\0PLAppendDialog(int)\0"
    "PLAppendDialog()\0MLAppendDialog(int)\0"
    "MLAppendDialog()\0PLOpenDir()\0PLAppendDir()\0"
    "MLAppendDir()\0parent,mrl,b_stream,options\0"
    "streamingDialog(QWidget*,QString,bool,QStringList)\0"
    "parent,mrl,b_stream\0"
    "streamingDialog(QWidget*,QString,bool)\0"
    "parent,mrl\0streamingDialog(QWidget*,QString)\0"
    "openAndStreamingDialogs()\0"
    "openAndTranscodingDialogs()\0openAPlaylist()\0"
    "saveAPlaylist()\0loadSubtitlesFile()\0"
    "quit()\0menuAction(QObject*)\0"
    "menuUpdateAction(QObject*)\0"
    "SDMenuAction(QString)\0"
};

void DialogsProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogsProvider *_t = static_cast<DialogsProvider *>(_o);
        switch (_id) {
        case 0: _t->toolBarConfUpdated(); break;
        case 1: _t->playMRL((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->playlistDialog(); break;
        case 3: _t->bookmarksDialog(); break;
        case 4: _t->mediaInfoDialog(); break;
        case 5: _t->mediaCodecDialog(); break;
        case 6: _t->prefsDialog(); break;
        case 7: _t->extendedDialog(); break;
        case 8: _t->synchroDialog(); break;
        case 9: _t->messagesDialog(); break;
        case 10: _t->helpDialog(); break;
        case 11: _t->aboutDialog(); break;
        case 12: _t->gotoTimeDialog(); break;
        case 13: _t->podcastConfigureDialog(); break;
        case 14: _t->toolbarDialog(); break;
        case 15: _t->pluginDialog(); break;
        case 16: _t->epgDialog(); break;
        case 17: _t->openFileGenericDialog((*reinterpret_cast< intf_dialog_args_t*(*)>(_a[1]))); break;
        case 18: _t->simpleOpenDialog(); break;
        case 19: _t->simplePLAppendDialog(); break;
        case 20: _t->simpleMLAppendDialog(); break;
        case 21: _t->openDialog(); break;
        case 22: _t->openDiscDialog(); break;
        case 23: _t->openFileDialog(); break;
        case 24: _t->openUrlDialog(); break;
        case 25: _t->openNetDialog(); break;
        case 26: _t->openCaptureDialog(); break;
        case 27: _t->PLAppendDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->PLAppendDialog(); break;
        case 29: _t->MLAppendDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->MLAppendDialog(); break;
        case 31: _t->PLOpenDir(); break;
        case 32: _t->PLAppendDir(); break;
        case 33: _t->MLAppendDir(); break;
        case 34: _t->streamingDialog((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 35: _t->streamingDialog((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 36: _t->streamingDialog((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 37: _t->openAndStreamingDialogs(); break;
        case 38: _t->openAndTranscodingDialogs(); break;
        case 39: _t->openAPlaylist(); break;
        case 40: _t->saveAPlaylist(); break;
        case 41: _t->loadSubtitlesFile(); break;
        case 42: _t->quit(); break;
        case 43: _t->menuAction((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 44: _t->menuUpdateAction((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 45: _t->SDMenuAction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DialogsProvider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogsProvider::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DialogsProvider,
      qt_meta_data_DialogsProvider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogsProvider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogsProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogsProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogsProvider))
        return static_cast<void*>(const_cast< DialogsProvider*>(this));
    return QObject::qt_metacast(_clname);
}

int DialogsProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void DialogsProvider::toolBarConfUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
