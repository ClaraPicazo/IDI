/****************************************************************************
** Meta object code from reading C++ file 'my_label.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "my_label.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_my_label[] = {

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
      12,   10,    9,    9, 0x0a,
      26,   24,    9,    9, 0x0a,
      42,   40,    9,    9, 0x0a,
      55,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_my_label[] = {
    "my_label\0\0r\0getRed(int)\0g\0getGreen(int)\0"
    "b\0getBlue(int)\0updateColor()\0"
};

void my_label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        my_label *_t = static_cast<my_label *>(_o);
        switch (_id) {
        case 0: _t->getRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateColor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData my_label::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject my_label::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_my_label,
      qt_meta_data_my_label, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &my_label::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *my_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *my_label::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_my_label))
        return static_cast<void*>(const_cast< my_label*>(this));
    return QLabel::qt_metacast(_clname);
}

int my_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
