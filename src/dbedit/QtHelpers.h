#ifndef TRINITYCORE_QTHELPERS_H
#define TRINITYCORE_QTHELPERS_H

#include "advstd.h"
#include "Errors.h"
#include "StringFormat.h"
#include <memory>
#include <QWidget>

// FIND_Q_CHILD

template <typename T>
inline T FindHelper(QWidget const& widget, char const* name)
{
    using base_type = std::remove_reference_t<T>;
    static_assert(advstd::is_reference_v<T> && !advstd::is_pointer_v<base_type>, "FIND_Q_CHILD only works on references!");
    base_type* ptr = widget.findChild<base_type*>(name);
    ASSERT(ptr, "Could not find Q child %s", name);
    return *ptr;
}
#define FIND_Q_CHILD(name) name(FindHelper<decltype(name)>(*this, #name))
#define FIND_Q_CHILD_DELAYED(name) name = &FindHelper<decltype(*name)>(*this, #name);


// Q_SETUP

template <typename T>
struct QSetupHelper { static_assert(!advstd::is_same_v<T, T>, "me must be a unique_ptr when using Q_SETUP!"); };

template <typename UIType>
struct QSetupHelper<std::unique_ptr<UIType>>
{
    template <typename WidgetType>
    static std::unique_ptr<UIType> Setup(WidgetType* widget)
    {
        std::unique_ptr<UIType> ui = std::make_unique<UIType>();
        ui->setupUi(widget);
        return ui;
    }
};
#define Q_SETUP() me(QSetupHelper<decltype(me)>::Setup(this))

#define CONNECT_SAME(me, other, name) connect(&*me, &advstd::remove_cvref_t<decltype(*me)>::name, &*other, &advstd::remove_cvref_t<decltype(*other)>::name)
#define CONNECT(me, mine, other, theirs) connect(&*me, &advstd::remove_cvref_t<decltype(*me)>::mine, &*other, &advstd::remove_cvref_t<decltype(*other)>::theirs)
#define DISCONNECT(c) disconnect(c)

namespace Trinity
{
    template <typename... Args>
    QString QStringFormat(Args&&... a) { return QString::fromStdString(Trinity::StringFormat(std::forward<Args>(a)...)); }
}

#endif
