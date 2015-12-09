/****************************************************************************
** Meta object code from reading C++ file 'sout.hpp'
**
** Created: Mon Dec 7 17:03:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sout.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sout.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoutDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      24,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SoutDialog[] = {
    "SoutDialog\0\0updateMRL()\0ok()\0cancel()\0"
    "next()\0prev()\0closeTab()\0tabChanged(int)\0"
    "addDest()\0"
};

void SoutDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SoutDialog *_t = static_cast<SoutDialog *>(_o);
        switch (_id) {
        case 0: _t->updateMRL(); break;
        case 1: _t->ok(); break;
        case 2: _t->cancel(); break;
        case 3: _t->next(); break;
        case 4: _t->prev(); break;
        case 5: _t->closeTab(); break;
        case 6: _t->tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addDest(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SoutDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SoutDialog::staticMetaObject = {
    { &QVLCDialog::staticMetaObject, qt_meta_stringdata_SoutDialog,
      qt_meta_data_SoutDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoutDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoutDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoutDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoutDialog))
        return static_cast<void*>(const_cast< SoutDialog*>(this));
    return QVLCDialog::qt_metacast(_clname);
}

int SoutDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVLCDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
