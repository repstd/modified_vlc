/****************************************************************************
** Meta object code from reading C++ file 'interface_widgets.hpp'
**
** Created: Mon Dec 7 17:03:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "interface_widgets.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface_widgets.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VideoWidget[] = {
    "VideoWidget\0\0,\0sizeChanged(int,int)\0"
    "SetSizing(uint,uint)\0"
};

void VideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VideoWidget *_t = static_cast<VideoWidget *>(_o);
        switch (_id) {
        case 0: _t->sizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SetSizing((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VideoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VideoWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_VideoWidget,
      qt_meta_data_VideoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoWidget))
        return static_cast<void*>(const_cast< VideoWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int VideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void VideoWidget::sizeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_BackgroundWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      27,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BackgroundWidget[] = {
    "BackgroundWidget\0\0toggle()\0"
    "updateArt(QString)\0"
};

void BackgroundWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BackgroundWidget *_t = static_cast<BackgroundWidget *>(_o);
        switch (_id) {
        case 0: _t->toggle(); break;
        case 1: _t->updateArt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BackgroundWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BackgroundWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BackgroundWidget,
      qt_meta_data_BackgroundWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BackgroundWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BackgroundWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BackgroundWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundWidget))
        return static_cast<void*>(const_cast< BackgroundWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BackgroundWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_TimeLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   36,   10,   10, 0x08,
      94,   90,   10,   10, 0x08,
     120,   10,   10,   10, 0x08,
     143,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TimeLabel[] = {
    "TimeLabel\0\0timeLabelDoubleClicked()\0"
    "pos,time,length\0setDisplayPosition(float,int64_t,int)\0"
    "pos\0setDisplayPosition(float)\0"
    "updateBuffering(float)\0updateBuffering()\0"
};

void TimeLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimeLabel *_t = static_cast<TimeLabel *>(_o);
        switch (_id) {
        case 0: _t->timeLabelDoubleClicked(); break;
        case 1: _t->setDisplayPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->setDisplayPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->updateBuffering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->updateBuffering(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TimeLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TimeLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_TimeLabel,
      qt_meta_data_TimeLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeLabel))
        return static_cast<void*>(const_cast< TimeLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int TimeLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TimeLabel::timeLabelDoubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_SpeedLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpeedLabel[] = {
    "SpeedLabel\0\0showSpeedMenu(QPoint)\0"
    "setRate(float)\0"
};

void SpeedLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SpeedLabel *_t = static_cast<SpeedLabel *>(_o);
        switch (_id) {
        case 0: _t->showSpeedMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->setRate((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SpeedLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SpeedLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_SpeedLabel,
      qt_meta_data_SpeedLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpeedLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpeedLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpeedLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpeedLabel))
        return static_cast<void*>(const_cast< SpeedLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int SpeedLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_SpeedControlWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      38,   19,   19,   19, 0x08,
      54,   19,   19,   19, 0x08,
      80,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpeedControlWidget[] = {
    "SpeedControlWidget\0\0activateOnState()\0"
    "updateRate(int)\0updateSpinBoxRate(double)\0"
    "resetRate()\0"
};

void SpeedControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SpeedControlWidget *_t = static_cast<SpeedControlWidget *>(_o);
        switch (_id) {
        case 0: _t->activateOnState(); break;
        case 1: _t->updateRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateSpinBoxRate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->resetRate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SpeedControlWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SpeedControlWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SpeedControlWidget,
      qt_meta_data_SpeedControlWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpeedControlWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpeedControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpeedControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpeedControlWidget))
        return static_cast<void*>(const_cast< SpeedControlWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int SpeedControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_CoverArtLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   14,   14,   14, 0x0a,
      49,   14,   14,   14, 0x0a,
      58,   14,   14,   14, 0x0a,
      81,   14,   14,   14, 0x0a,
      89,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CoverArtLabel[] = {
    "CoverArtLabel\0\0updateRequested()\0"
    "requestUpdate()\0update()\0"
    "showArtUpdate(QString)\0clear()\0"
    "askForUpdate()\0"
};

void CoverArtLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoverArtLabel *_t = static_cast<CoverArtLabel *>(_o);
        switch (_id) {
        case 0: _t->updateRequested(); break;
        case 1: _t->requestUpdate(); break;
        case 2: _t->update(); break;
        case 3: _t->showArtUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        case 5: _t->askForUpdate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CoverArtLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CoverArtLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_CoverArtLabel,
      qt_meta_data_CoverArtLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CoverArtLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CoverArtLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CoverArtLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoverArtLabel))
        return static_cast<void*>(const_cast< CoverArtLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int CoverArtLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CoverArtLabel::updateRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
