/****************************************************************************
** Meta object code from reading C++ file 'droplist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/droplist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'droplist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DropList_t {
    QByteArrayData data[8];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DropList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DropList_t qt_meta_stringdata_DropList = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 7),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 16),
QT_MOC_LITERAL(4, 35, 8),
QT_MOC_LITERAL(5, 44, 11),
QT_MOC_LITERAL(6, 56, 8),
QT_MOC_LITERAL(7, 65, 5)
    },
    "DropList\0changed\0\0const QMimeData*\0"
    "mimeData\0fileDropped\0filePath\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DropList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    0,   42,    2, 0x26 /* Public | MethodCloned */,
       5,    1,   43,    2, 0x06 /* Public */,
       5,    0,   46,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DropList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DropList *_t = static_cast<DropList *>(_o);
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< const QMimeData*(*)>(_a[1]))); break;
        case 1: _t->changed(); break;
        case 2: _t->fileDropped((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->fileDropped(); break;
        case 4: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DropList::*_t)(const QMimeData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DropList::changed)) {
                *result = 0;
            }
        }
        {
            typedef void (DropList::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DropList::fileDropped)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DropList::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_DropList.data,
      qt_meta_data_DropList,  qt_static_metacall, 0, 0}
};


const QMetaObject *DropList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DropList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DropList.stringdata))
        return static_cast<void*>(const_cast< DropList*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int DropList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DropList::changed(const QMimeData * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void DropList::fileDropped(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
