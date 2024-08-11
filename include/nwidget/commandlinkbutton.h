#ifndef COMMANDLINKBUTTON_H
#define COMMANDLINKBUTTON_H

#include <QCommandLinkButton>

#include "pushbutton.h"

namespace nw {

template<typename S, typename T>
class CommandLinkButtonBuilder : public PushButtonBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(PushButtonBuilder, S, T)

public:
    CommandLinkButtonBuilder()                                                : PushButtonBuilder<S, T>(new T) {}
    explicit CommandLinkButtonBuilder(T* target)                              : PushButtonBuilder<S, T>(target) {}
    CommandLinkButtonBuilder(const QString& text)                             : PushButtonBuilder<S, T>(new T(text)) {}
    CommandLinkButtonBuilder(const QString& text, const QString& description) : PushButtonBuilder<S, T>(new T(text, description)) {}

    S& description(const QString& s) { t->setDescription(s); return self(); }
};

N_BUILDER_IMPL(CommandLinkButtonBuilder, QCommandLinkButton, CommandLinkButton);



template<typename T>
class CommandLinkButtonRefT : public PushButtonRefT<T>
{
public:
    using PushButtonRefT<T>::PushButtonRefT;

    N_PROPERTY(QString, description, N_GETTER(description), N_SETTER(setDescription), N_NO_NOTIFY)
    N_PROPERTY(bool   , flat       , N_GETTER(isFlat     ), N_SETTER(setFlat       ), N_NO_NOTIFY)
};

using CommandLinkButtonRef = CommandLinkButtonRefT<QCommandLinkButton>;

}

#endif // COMMANDLINKBUTTON_H
