#ifndef NWIDGET_COMMANDLINKBUTTON_H
#define NWIDGET_COMMANDLINKBUTTON_H

#include <QCommandLinkButton>

#include "pushbutton.h"

namespace nwidget {

template<typename S, typename T>
class CommandLinkButtonBuilder : public PushButtonBuilder<S, T>
{
    N_BUILDER

public:
    CommandLinkButtonBuilder()                                         : PushButtonBuilder<S, T>(new T) {}
    explicit
    CommandLinkButtonBuilder(const QString& text)                      : PushButtonBuilder<S, T>(new T(text)) {}
    CommandLinkButtonBuilder(const QString& text, const QString& desc) : PushButtonBuilder<S, T>(new T(text, desc)) {}
    explicit
    CommandLinkButtonBuilder(T* target)                                : PushButtonBuilder<S, T>(target) {}

    N_BUILDER_PROPERTY(QString, description, setDescription)
    N_BUILDER_PROPERTY(bool   , flat       , setFlat       )
};

N_DECLARE_BUILDER(CommandLinkButton, CommandLinkButtonBuilder, QCommandLinkButton)



template<typename T>
class CommandLinkButtonIdT : public PushButtonIdT<T>
{
public:
    using PushButtonIdT<T>::PushButtonIdT;

    N_ID_PROPERTY(QString, description, N_READ description N_WRITE setDescription)
    N_ID_PROPERTY(bool   , flat       , N_READ isFlat      N_WRITE setFlat       )
};

N_DECLARE_ID(CommandLinkButton, CommandLinkButtonIdT, QCommandLinkButton)

}

#endif // NWIDGET_COMMANDLINKBUTTON_H
