/****************************************************************************
** Meta object code from reading C++ file 'sortdialog.h'
**
** Created: Wed Dec 5 11:47:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sortdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SortDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SortDialog[] = {
    "SortDialog\0\0on_Input_clicked()\0"
    "on_Next_clicked()\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_InSortTheory_clicked()\0"
    "on_SelSortTheory_clicked()\0"
};

const QMetaObject SortDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SortDialog,
      qt_meta_data_SortDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SortDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SortDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SortDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SortDialog))
        return static_cast<void*>(const_cast< SortDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SortDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Input_clicked(); break;
        case 1: on_Next_clicked(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: on_InSortTheory_clicked(); break;
        case 5: on_SelSortTheory_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
