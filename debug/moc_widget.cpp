/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[16];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 19), // "on_btn_open_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "on_btn_play_clicked"
QT_MOC_LITERAL(4, 48, 21), // "on_btn_pasuse_clicked"
QT_MOC_LITERAL(5, 70, 19), // "on_btn_stop_clicked"
QT_MOC_LITERAL(6, 90, 29), // "on_voice_control_valueChanged"
QT_MOC_LITERAL(7, 120, 5), // "value"
QT_MOC_LITERAL(8, 126, 25), // "on_btn_fullscreen_clicked"
QT_MOC_LITERAL(9, 152, 11), // "getDuration"
QT_MOC_LITERAL(10, 164, 8), // "playTime"
QT_MOC_LITERAL(11, 173, 11), // "getPosition"
QT_MOC_LITERAL(12, 185, 20), // "on_btn_backV_clicked"
QT_MOC_LITERAL(13, 206, 20), // "on_btn_nextV_clicked"
QT_MOC_LITERAL(14, 227, 26), // "on_listWidget_doubleCliked"
QT_MOC_LITERAL(15, 254, 5) // "index"

    },
    "Widget\0on_btn_open_clicked\0\0"
    "on_btn_play_clicked\0on_btn_pasuse_clicked\0"
    "on_btn_stop_clicked\0on_voice_control_valueChanged\0"
    "value\0on_btn_fullscreen_clicked\0"
    "getDuration\0playTime\0getPosition\0"
    "on_btn_backV_clicked\0on_btn_nextV_clicked\0"
    "on_listWidget_doubleCliked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_open_clicked(); break;
        case 1: _t->on_btn_play_clicked(); break;
        case 2: _t->on_btn_pasuse_clicked(); break;
        case 3: _t->on_btn_stop_clicked(); break;
        case 4: _t->on_voice_control_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_btn_fullscreen_clicked(); break;
        case 6: _t->getDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->getPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_btn_backV_clicked(); break;
        case 9: _t->on_btn_nextV_clicked(); break;
        case 10: _t->on_listWidget_doubleCliked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
