/****************************************************************************
** Meta object code from reading C++ file 'calendarmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../calendarmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15CalendarManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto CalendarManager::qt_create_metaobjectdata<qt_meta_tag_ZN15CalendarManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "CalendarManager",
        "onAddEvent",
        "",
        "onDeleteEvent",
        "onCalendarClicked",
        "date",
        "onEventSelectionChanged",
        "QItemSelection",
        "selected",
        "deselected"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onAddEvent'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDeleteEvent'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCalendarClicked'
        QtMocHelpers::SlotData<void(const QDate &)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QDate, 5 },
        }}),
        // Slot 'onEventSelectionChanged'
        QtMocHelpers::SlotData<void(const QItemSelection &, const QItemSelection &)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CalendarManager, qt_meta_tag_ZN15CalendarManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject CalendarManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15CalendarManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15CalendarManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15CalendarManagerE_t>.metaTypes,
    nullptr
} };

void CalendarManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CalendarManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onAddEvent(); break;
        case 1: _t->onDeleteEvent(); break;
        case 2: _t->onCalendarClicked((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: _t->onEventSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject *CalendarManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalendarManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15CalendarManagerE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CalendarManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
