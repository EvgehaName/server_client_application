/****************************************************************************
** Meta object code from reading C++ file 'serverapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "serverapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerApp_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerApp_t qt_meta_stringdata_ServerApp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ServerApp"
QT_MOC_LITERAL(1, 10, 19), // "newServerConnection"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "sockReady"
QT_MOC_LITERAL(4, 41, 17), // "sockDisconnection"
QT_MOC_LITERAL(5, 59, 12), // "writeLogData"
QT_MOC_LITERAL(6, 72, 11), // "std::string"
QT_MOC_LITERAL(7, 84, 4), // "data"
QT_MOC_LITERAL(8, 89, 4), // "flag"
QT_MOC_LITERAL(9, 94, 17), // "readToSendLogData"
QT_MOC_LITERAL(10, 112, 9), // "splitElem"
QT_MOC_LITERAL(11, 122, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(12, 147, 4) // "elem"

    },
    "ServerApp\0newServerConnection\0\0sockReady\0"
    "sockDisconnection\0writeLogData\0"
    "std::string\0data\0flag\0readToSendLogData\0"
    "splitElem\0std::vector<std::string>\0"
    "elem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    2,   47,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    0x80000000 | 11, 0x80000000 | 6,   12,

       0        // eod
};

void ServerApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerApp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newServerConnection(); break;
        case 1: _t->sockReady(); break;
        case 2: _t->sockDisconnection(); break;
        case 3: _t->writeLogData((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 4: _t->readToSendLogData(); break;
        case 5: { std::vector<std::string> _r = _t->splitElem((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<std::string>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_ServerApp.data,
    qt_meta_data_ServerApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerApp.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int ServerApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
