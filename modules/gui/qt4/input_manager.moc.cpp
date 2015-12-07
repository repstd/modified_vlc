/****************************************************************************
** Meta object code from reading C++ file 'input_manager.hpp'
**
** Created: Mon Dec 7 17:03:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "input_manager.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'input_manager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InputManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x05,
      56,   52,   13,   13, 0x05,
      77,   13,   13,   13, 0x05,
      96,   13,   13,   13, 0x05,
     117,   13,   13,   13, 0x05,
     136,   13,   13,   13, 0x05,
     157,   13,   13,   13, 0x05,
     190,   13,   13,   13, 0x05,
     217,   13,   13,   13, 0x05,
     251,   13,   13,   13, 0x05,
     278,   13,   13,   13, 0x05,
     298,   13,   13,   13, 0x05,
     324,   13,   13,   13, 0x05,
     352,   13,   13,   13, 0x05,
     375,   13,   13,   13, 0x05,
     399,   13,   13,   13, 0x05,
     435,   13,   13,   13, 0x05,
     458,  456,   13,   13, 0x05,
     481,   13,   13,   13, 0x05,
     514,  499,   13,   13, 0x05,
     551,   13,   13,   13, 0x05,
     568,   13,   13,   13, 0x05,
     587,   13,   13,   13, 0x05,
     609,   13,   13,   13, 0x05,
     633,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     646,   13,   13,   13, 0x0a,
     672,   13,   13,   13, 0x0a,
     692,   13,   13,   13, 0x0a,
     702,   13,   13,   13, 0x0a,
     711,   13,   13,   13, 0x0a,
     720,   13,   13,   13, 0x0a,
     735,   13,   13,   13, 0x0a,
     750,   13,   13,   13, 0x0a,
     763,   13,   13,   13, 0x0a,
     776,   13,   13,   13, 0x0a,
     786,   13,   13,   13, 0x0a,
     796,   13,   13,   13, 0x0a,
     810,   13,   13,   13, 0x0a,
     824,   13,   13,   13, 0x0a,
     838,   13,   13,   13, 0x0a,
     856,   13,   13,   13, 0x0a,
     883,   13,   13,   13, 0x0a,
     906,   13,   13,   13, 0x0a,
     916,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InputManager[] = {
    "InputManager\0\0,,\0positionUpdated(float,int64_t,int)\0"
    "pos\0seekRequested(float)\0rateChanged(float)\0"
    "nameChanged(QString)\0titleChanged(bool)\0"
    "chapterChanged(bool)\0"
    "statisticsUpdated(input_item_t*)\0"
    "infoChanged(input_item_t*)\0"
    "currentMetaChanged(input_item_t*)\0"
    "metaChanged(input_item_t*)\0"
    "artChanged(QString)\0playingStatusChanged(int)\0"
    "recordingStateChanged(bool)\0"
    "teletextPossible(bool)\0teletextActivated(bool)\0"
    "teletextTransparencyActivated(bool)\0"
    "newTelexPageSet(int)\0,\0AtoBchanged(bool,bool)\0"
    "voutChanged(bool)\0pp_vout,i_vout\0"
    "voutListChanged(vout_thread_t**,int)\0"
    "synchroChanged()\0bookmarksChanged()\0"
    "cachingChanged(float)\0encryptionChanged(bool)\0"
    "epgChanged()\0setInput(input_thread_t*)\0"
    "sliderUpdate(float)\0reverse()\0slower()\0"
    "faster()\0littlefaster()\0littleslower()\0"
    "normalRate()\0setRate(int)\0jumpFwd()\0"
    "jumpBwd()\0sectionNext()\0sectionPrev()\0"
    "sectionMenu()\0telexSetPage(int)\0"
    "telexSetTransparency(bool)\0"
    "activateTeletext(bool)\0setAtoB()\0"
    "AtoBLoop(float,int64_t,int)\0"
};

void InputManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InputManager *_t = static_cast<InputManager *>(_o);
        switch (_id) {
        case 0: _t->positionUpdated((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->seekRequested((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->rateChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->titleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->chapterChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->statisticsUpdated((*reinterpret_cast< input_item_t*(*)>(_a[1]))); break;
        case 7: _t->infoChanged((*reinterpret_cast< input_item_t*(*)>(_a[1]))); break;
        case 8: _t->currentMetaChanged((*reinterpret_cast< input_item_t*(*)>(_a[1]))); break;
        case 9: _t->metaChanged((*reinterpret_cast< input_item_t*(*)>(_a[1]))); break;
        case 10: _t->artChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->playingStatusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->recordingStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->teletextPossible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->teletextActivated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->teletextTransparencyActivated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->newTelexPageSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->AtoBchanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->voutChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->voutListChanged((*reinterpret_cast< vout_thread_t**(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->synchroChanged(); break;
        case 21: _t->bookmarksChanged(); break;
        case 22: _t->cachingChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 23: _t->encryptionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->epgChanged(); break;
        case 25: _t->setInput((*reinterpret_cast< input_thread_t*(*)>(_a[1]))); break;
        case 26: _t->sliderUpdate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 27: _t->reverse(); break;
        case 28: _t->slower(); break;
        case 29: _t->faster(); break;
        case 30: _t->littlefaster(); break;
        case 31: _t->littleslower(); break;
        case 32: _t->normalRate(); break;
        case 33: _t->setRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->jumpFwd(); break;
        case 35: _t->jumpBwd(); break;
        case 36: _t->sectionNext(); break;
        case 37: _t->sectionPrev(); break;
        case 38: _t->sectionMenu(); break;
        case 39: _t->telexSetPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->telexSetTransparency((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->activateTeletext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->setAtoB(); break;
        case 43: _t->AtoBLoop((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InputManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InputManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InputManager,
      qt_meta_data_InputManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InputManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InputManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InputManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InputManager))
        return static_cast<void*>(const_cast< InputManager*>(this));
    return QObject::qt_metacast(_clname);
}

int InputManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void InputManager::positionUpdated(float _t1, int64_t _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InputManager::seekRequested(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InputManager::rateChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InputManager::nameChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void InputManager::titleChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void InputManager::chapterChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void InputManager::statisticsUpdated(input_item_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void InputManager::infoChanged(input_item_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void InputManager::currentMetaChanged(input_item_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void InputManager::metaChanged(input_item_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void InputManager::artChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void InputManager::playingStatusChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void InputManager::recordingStateChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void InputManager::teletextPossible(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void InputManager::teletextActivated(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void InputManager::teletextTransparencyActivated(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void InputManager::newTelexPageSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void InputManager::AtoBchanged(bool _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void InputManager::voutChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void InputManager::voutListChanged(vout_thread_t * * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void InputManager::synchroChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}

// SIGNAL 21
void InputManager::bookmarksChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, 0);
}

// SIGNAL 22
void InputManager::cachingChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void InputManager::encryptionChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void InputManager::epgChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, 0);
}
static const uint qt_meta_data_MainInputManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      48,   17,   17,   17, 0x05,
      64,   17,   17,   17, 0x05,
      99,   83,   17,   17, 0x05,
     136,  129,   17,   17, 0x05,
     161,   17,   17,   17, 0x05,
     184,   17,   17,   17, 0x05,
     204,   17,   17,   17, 0x05,
     227,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     249,   17,   17,   17, 0x0a,
     267,   17,   17,   17, 0x0a,
     274,   17,   17,   17, 0x0a,
     282,   17,   17,   17, 0x0a,
     297,   17,   17,   17, 0x0a,
     304,   17,   17,   17, 0x0a,
     311,   17,   17,   17, 0x0a,
     318,   17,   17,   17, 0x0a,
     332,   17,   17,   17, 0x0a,
     355,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainInputManager[] = {
    "MainInputManager\0\0inputChanged(input_thread_t*)\0"
    "volumeChanged()\0soundMuteChanged()\0"
    "itemId,parentId\0playlistItemAppended(int,int)\0"
    "itemId\0playlistItemRemoved(int)\0"
    "playlistNotEmpty(bool)\0randomChanged(bool)\0"
    "repeatLoopChanged(int)\0leafBecameParent(int)\0"
    "togglePlayPause()\0play()\0pause()\0"
    "toggleRandom()\0stop()\0next()\0prev()\0"
    "prevOrReset()\0activatePlayQuit(bool)\0"
    "loopRepeatLoopStatus()\0"
};

void MainInputManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainInputManager *_t = static_cast<MainInputManager *>(_o);
        switch (_id) {
        case 0: _t->inputChanged((*reinterpret_cast< input_thread_t*(*)>(_a[1]))); break;
        case 1: _t->volumeChanged(); break;
        case 2: _t->soundMuteChanged(); break;
        case 3: _t->playlistItemAppended((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->playlistItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->playlistNotEmpty((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->randomChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->repeatLoopChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->leafBecameParent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->togglePlayPause(); break;
        case 10: _t->play(); break;
        case 11: _t->pause(); break;
        case 12: _t->toggleRandom(); break;
        case 13: _t->stop(); break;
        case 14: _t->next(); break;
        case 15: _t->prev(); break;
        case 16: _t->prevOrReset(); break;
        case 17: _t->activatePlayQuit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->loopRepeatLoopStatus(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainInputManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainInputManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainInputManager,
      qt_meta_data_MainInputManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainInputManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainInputManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainInputManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainInputManager))
        return static_cast<void*>(const_cast< MainInputManager*>(this));
    if (!strcmp(_clname, "Singleton<MainInputManager>"))
        return static_cast< Singleton<MainInputManager>*>(const_cast< MainInputManager*>(this));
    return QObject::qt_metacast(_clname);
}

int MainInputManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainInputManager::inputChanged(input_thread_t * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainInputManager::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainInputManager::soundMuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainInputManager::playlistItemAppended(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainInputManager::playlistItemRemoved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainInputManager::playlistNotEmpty(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainInputManager::randomChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainInputManager::repeatLoopChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainInputManager::leafBecameParent(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
