/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_actionLoad_File_triggered"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 18), // "drow_section_field"
QT_MOC_LITERAL(4, 60, 24), // "on_tree_sect_itemClicked"
QT_MOC_LITERAL(5, 85, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 102, 4), // "item"
QT_MOC_LITERAL(7, 107, 6), // "column"
QT_MOC_LITERAL(8, 114, 26), // "on_tablewidget_cellClicked"
QT_MOC_LITERAL(9, 141, 3), // "row"
QT_MOC_LITERAL(10, 145, 26), // "on_tablewidget_itemChanged"
QT_MOC_LITERAL(11, 172, 21), // "on_button_add_clicked"
QT_MOC_LITERAL(12, 194, 1), // "b"
QT_MOC_LITERAL(13, 196, 23), // "on_button_add_s_clicked"
QT_MOC_LITERAL(14, 220, 21), // "on_button_del_clicked"
QT_MOC_LITERAL(15, 242, 25), // "on_button_del_sec_clicked"
QT_MOC_LITERAL(16, 268, 18), // "on_line_add_s_edit"
QT_MOC_LITERAL(17, 287, 16), // "on_line_add_edit"
QT_MOC_LITERAL(18, 304, 28), // "on_actionSave_file_triggered"
QT_MOC_LITERAL(19, 333, 24) // "on_actionClear_triggered"

    },
    "MainWindow\0on_actionLoad_File_triggered\0"
    "\0drow_section_field\0on_tree_sect_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_tablewidget_cellClicked\0row\0"
    "on_tablewidget_itemChanged\0"
    "on_button_add_clicked\0b\0on_button_add_s_clicked\0"
    "on_button_del_clicked\0on_button_del_sec_clicked\0"
    "on_line_add_s_edit\0on_line_add_edit\0"
    "on_actionSave_file_triggered\0"
    "on_actionClear_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    2,   81,    2, 0x08 /* Private */,
       8,    2,   86,    2, 0x08 /* Private */,
      10,    2,   91,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      15,    1,  105,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,    7,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionLoad_File_triggered(); break;
        case 1: _t->drow_section_field(); break;
        case 2: _t->on_tree_sect_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_tablewidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_tablewidget_itemChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_button_add_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_button_add_s_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_button_del_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_button_del_sec_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_line_add_s_edit(); break;
        case 10: _t->on_line_add_edit(); break;
        case 11: _t->on_actionSave_file_triggered(); break;
        case 12: _t->on_actionClear_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
