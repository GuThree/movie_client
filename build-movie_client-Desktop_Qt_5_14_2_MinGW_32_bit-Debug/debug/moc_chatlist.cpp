/****************************************************************************
** Meta object code from reading C++ file 'chatlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../movie_client/chatlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chatlist_t {
    QByteArrayData data[11];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chatlist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chatlist_t qt_meta_stringdata_Chatlist = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Chatlist"
QT_MOC_LITERAL(1, 9, 20), // "signal_to_sub_widget"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 27), // "signal_to_sub_widget_member"
QT_MOC_LITERAL(4, 59, 30), // "signal_to_sub_widget_member_id"
QT_MOC_LITERAL(5, 90, 25), // "signal_to_sub_widget_room"
QT_MOC_LITERAL(6, 116, 12), // "server_reply"
QT_MOC_LITERAL(7, 129, 26), // "on_addFriendButton_clicked"
QT_MOC_LITERAL(8, 156, 28), // "on_friendList_double_clicked"
QT_MOC_LITERAL(9, 185, 27), // "on_createRoomButton_clicked"
QT_MOC_LITERAL(10, 213, 26) // "on_enterRoomButton_clicked"

    },
    "Chatlist\0signal_to_sub_widget\0\0"
    "signal_to_sub_widget_member\0"
    "signal_to_sub_widget_member_id\0"
    "signal_to_sub_widget_room\0server_reply\0"
    "on_addFriendButton_clicked\0"
    "on_friendList_double_clicked\0"
    "on_createRoomButton_clicked\0"
    "on_enterRoomButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chatlist[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   71,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chatlist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Chatlist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_to_sub_widget((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->signal_to_sub_widget_member((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->signal_to_sub_widget_member_id((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 3: _t->signal_to_sub_widget_room((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->server_reply(); break;
        case 5: _t->on_addFriendButton_clicked(); break;
        case 6: _t->on_friendList_double_clicked(); break;
        case 7: _t->on_createRoomButton_clicked(); break;
        case 8: _t->on_enterRoomButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Chatlist::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chatlist::signal_to_sub_widget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chatlist::signal_to_sub_widget_member)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chatlist::signal_to_sub_widget_member_id)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chatlist::signal_to_sub_widget_room)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chatlist::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Chatlist.data,
    qt_meta_data_Chatlist,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Chatlist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chatlist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chatlist.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Chatlist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Chatlist::signal_to_sub_widget(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Chatlist::signal_to_sub_widget_member(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Chatlist::signal_to_sub_widget_member_id(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Chatlist::signal_to_sub_widget_room(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
