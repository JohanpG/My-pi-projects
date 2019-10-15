/****************************************************************************
** Meta object code from reading C++ file 'servoguic.h'
**
** Created: Fri Jan 10 04:36:18 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ServoGuiC/servoguic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servoguic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_servoGuiC[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   34,   34,   34, 0x08,
      35,   34,   34,   34, 0x08,
      61,   34,   34,   34, 0x08,
      87,   34,   34,   34, 0x08,
     113,   34,  121,   34, 0x08,
     125,   34,  121,   34, 0x08,
     132,   34,  121,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_servoGuiC[] = {
    "servoGuiC\0on_pushButton_clicked()\0\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_4_clicked()\0right()\0int\0"
    "left()\0center()\0"
};

void servoGuiC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        servoGuiC *_t = static_cast<servoGuiC *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: { int _r = _t->right();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->left();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->center();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData servoGuiC::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject servoGuiC::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_servoGuiC,
      qt_meta_data_servoGuiC, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &servoGuiC::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *servoGuiC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *servoGuiC::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_servoGuiC))
        return static_cast<void*>(const_cast< servoGuiC*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int servoGuiC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
