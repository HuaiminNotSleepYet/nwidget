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

    inline S& description(const QString& s) { t->setDescription(s); return self(); }
};

N_BUILDER_IMPL(CommandLinkButtonBuilder, QCommandLinkButton, CommandLinkButton);

}

#endif // COMMANDLINKBUTTON_H
