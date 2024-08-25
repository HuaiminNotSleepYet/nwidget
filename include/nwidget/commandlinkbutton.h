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
    CommandLinkButtonBuilder()                                         : PushButtonBuilder<S, T>(new T) {}
    explicit CommandLinkButtonBuilder(const QString& text)             : PushButtonBuilder<S, T>(new T(text)) {}
    CommandLinkButtonBuilder(const QString& text, const QString& desc) : PushButtonBuilder<S, T>(new T(text, desc)) {}

    explicit CommandLinkButtonBuilder(T* target)                                           : PushButtonBuilder<S, T>(target) {}
    explicit CommandLinkButtonBuilder(T* target, const QString& text)                      : PushButtonBuilder<S, T>(target, text) {}
    explicit CommandLinkButtonBuilder(T* target, const QString& text, const QString& desc) : PushButtonBuilder<S, T>(target, text) { t->setDescription(desc); }

    S& description(const QString& s) { t->setDescription(s); return self(); }
};

N_BUILDER_IMPL(CommandLinkButtonBuilder, QCommandLinkButton, CommandLinkButton);



template<typename T>
class CommandLinkButtonIdT : public PushButtonIdT<T>
{
public:
    using PushButtonIdT<T>::PushButtonIdT;

    N_PROPERTY(QString, description, N_GETTER(description), N_SETTER(setDescription), N_NO_NOTIFY)
    N_PROPERTY(bool   , flat       , N_GETTER(isFlat     ), N_SETTER(setFlat       ), N_NO_NOTIFY)
};

using CommandLinkButtonId = CommandLinkButtonIdT<QCommandLinkButton>;

}

#endif // COMMANDLINKBUTTON_H
