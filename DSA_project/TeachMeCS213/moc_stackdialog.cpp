/****************************************************************************
** Meta object code from reading C++ file 'stackdialog.h'
**
** Created: Wed Dec 5 11:47:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stackdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stackdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StackDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      31,   12,   12,   12, 0x08,
      48,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
      87,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StackDialog[] = {
    "StackDialog\0\0on_Push_clicked()\0"
    "on_pop_clicked()\0on_sizecall_clicked()\0"
    "on_top_clicked()\0on_Theory_clicked()\0"
};

const QMetaObject StackDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StackDialog,
      qt_meta_data_StackDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StackDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StackDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StackDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StackDialog))
        return static_cast<void*>(const_cast< StackDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StackDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Push_clicked(); break;
        case 1: on_pop_clicked(); break;
        case 2: on_sizecall_clicked(); break;
        case 3: on_top_clicked(); break;
        case 4: on_Theory_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
