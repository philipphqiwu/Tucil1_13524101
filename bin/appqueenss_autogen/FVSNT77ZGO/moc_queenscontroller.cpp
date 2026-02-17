/****************************************************************************
** Meta object code from reading C++ file 'queenscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../backend/queenscontroller.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'queenscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
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
struct qt_meta_tag_ZN16QueensControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto QueensController::qt_create_metaobjectdata<qt_meta_tag_ZN16QueensControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QueensController",
        "iterationChanged",
        "",
        "solvingChanged",
        "boardLoadedChanged",
        "errorMessageChanged",
        "updateIntervalChanged",
        "delayMsChanged",
        "useBacktrackingChanged",
        "elapsedMsChanged",
        "solveFinished",
        "success",
        "onBoardUpdated",
        "QList<Cell>",
        "cells",
        "size",
        "onIterationUpdated",
        "iteration",
        "onSolverFinished",
        "solved",
        "totalIterations",
        "loadFromTxtFile",
        "filePath",
        "startSolving",
        "stopSolving",
        "saveBoardAsTxt",
        "queensModel",
        "QueensModel*",
        "solving",
        "boardLoaded",
        "errorMessage",
        "updateInterval",
        "delayMs",
        "useBacktracking",
        "elapsedMs"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'iterationChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'solvingChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'boardLoadedChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorMessageChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateIntervalChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'delayMsChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'useBacktrackingChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'elapsedMsChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'solveFinished'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Slot 'onBoardUpdated'
        QtMocHelpers::SlotData<void(const QVector<Cell> &, int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 14 }, { QMetaType::Int, 15 },
        }}),
        // Slot 'onIterationUpdated'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'onSolverFinished'
        QtMocHelpers::SlotData<void(bool, int)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 19 }, { QMetaType::Int, 20 },
        }}),
        // Method 'loadFromTxtFile'
        QtMocHelpers::MethodData<void(const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 22 },
        }}),
        // Method 'startSolving'
        QtMocHelpers::MethodData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'stopSolving'
        QtMocHelpers::MethodData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'saveBoardAsTxt'
        QtMocHelpers::MethodData<bool(const QString &)>(25, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 22 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'queensModel'
        QtMocHelpers::PropertyData<QueensModel*>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'iteration'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'solving'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'boardLoaded'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'solved'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 8),
        // property 'errorMessage'
        QtMocHelpers::PropertyData<QString>(30, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'updateInterval'
        QtMocHelpers::PropertyData<int>(31, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'delayMs'
        QtMocHelpers::PropertyData<int>(32, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'useBacktracking'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'elapsedMs'
        QtMocHelpers::PropertyData<double>(34, QMetaType::Double, QMC::DefaultPropertyFlags, 7),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QueensController, qt_meta_tag_ZN16QueensControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QueensController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QueensControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QueensControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QueensControllerE_t>.metaTypes,
    nullptr
} };

void QueensController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QueensController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->iterationChanged(); break;
        case 1: _t->solvingChanged(); break;
        case 2: _t->boardLoadedChanged(); break;
        case 3: _t->errorMessageChanged(); break;
        case 4: _t->updateIntervalChanged(); break;
        case 5: _t->delayMsChanged(); break;
        case 6: _t->useBacktrackingChanged(); break;
        case 7: _t->elapsedMsChanged(); break;
        case 8: _t->solveFinished((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->onBoardUpdated((*reinterpret_cast<std::add_pointer_t<QList<Cell>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->onIterationUpdated((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->onSolverFinished((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->loadFromTxtFile((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->startSolving(); break;
        case 14: _t->stopSolving(); break;
        case 15: { bool _r = _t->saveBoardAsTxt((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::iterationChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::solvingChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::boardLoadedChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::errorMessageChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::updateIntervalChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::delayMsChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::useBacktrackingChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)()>(_a, &QueensController::elapsedMsChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QueensController::*)(bool )>(_a, &QueensController::solveFinished, 8))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QueensModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QueensModel**>(_v) = _t->queensModel(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->iteration(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->solving(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->boardLoaded(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->solved(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->errorMessage(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->updateInterval(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->delayMs(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->useBacktracking(); break;
        case 9: *reinterpret_cast<double*>(_v) = _t->elapsedMs(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 6: _t->setUpdateInterval(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setDelayMs(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setUseBacktracking(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QueensController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QueensController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QueensControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QueensController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QueensController::iterationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QueensController::solvingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QueensController::boardLoadedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QueensController::errorMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QueensController::updateIntervalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QueensController::delayMsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QueensController::useBacktrackingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QueensController::elapsedMsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QueensController::solveFinished(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
