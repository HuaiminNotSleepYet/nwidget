#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "object.h"

namespace nw {

template<typename S, typename T>
class WidgetBuilder : public ObjectBuilder<S, T>
{
    N_USING_BUILDER_MEMBER(ObjectBuilder, S, T)

public:
    WidgetBuilder()                           : ObjectBuilder<S, T>(new T) {}
    WidgetBuilder(QLayout* layout)            : ObjectBuilder<S, T>(new T) { t->setLayout(layout); }
    explicit WidgetBuilder(T* target)         : ObjectBuilder<S, T>(target) {}
    WidgetBuilder(T* target, QLayout* layout) : ObjectBuilder<S, T>(target) { t->setLayout(layout); }

    S& enabled(bool b)                                           { t->setEnabled(b);                        return self(); }
    S& disabled(bool b)                                          { t->setDisabled(b);                       return self(); }
    S& windowModified(bool b)                                    { t->setWindowModified(b);                 return self(); }

    S& minimumSize(const QSize& s)                               { t->setMinimumSize(s);                    return self(); }
    S& minimumSize(int w, int h)                                 { t->setMinimumSize(w, h);                 return self(); }
    S& maximumSize(const QSize& s)                               { t->setMaximumSize(s);                    return self(); }
    S& maximumSize(int w, int h)                                 { t->setMaximumSize(w, h);                 return self(); }
    S& minimumWidth(int w)                                       { t->setMinimumWidth(w);                   return self(); }
    S& minimumHeight(int h)                                      { t->setMinimumHeight(h);                  return self(); }
    S& maximumWidth(int w)                                       { t->setMaximumWidth(w);                   return self(); }
    S& maximumHeight(int h)                                      { t->setMaximumHeight(h);                  return self(); }

    S& sizeIncrement(const QSize& s)                             { t->setSizeIncrement(s);                  return self(); }
    S& sizeIncrement(int w, int h)                               { t->setSizeIncrement(w, h);               return self(); }
    S& baseSize(const QSize& s)                                  { t->setBaseSize(s);                       return self(); }
    S& baseSize(int w, int h)                                    { t->setBaseSize(w, h);                    return self(); }

    S& fixedSize(const QSize& s)                                 { t->setFixedSize(s);                      return self(); }
    S& fixedSize(int w, int h)                                   { t->setFixedSize(w, h);                   return self(); }
    S& fixedWidth(int w)                                         { t->setFixedWidth(w);                     return self(); }
    S& fixedHeight(int h)                                        { t->setFixedHeight(h);                    return self(); }

    S& palette(const QPalette& p)                                { t->setPalette(p);                        return self(); }
    S& backgroundRole(QPalette::ColorRole role)                  { t->setBackgroundRole(role);              return self(); }
    S& foregroundRole(QPalette::ColorRole role)                  { t->setForegroundRole(role);              return self(); }
    S& font(const QFont& f)                                      { t->setFont(f);                           return self(); }

#ifndef QT_NO_CURSOR
    S& cursor(const QCursor& c)                                  { t->setCursor(c);                         return self(); }
#endif

    S& mouseTracking(bool b)                                     { t->setMouseTracking(b);                  return self(); }
    S& tabletTracking(bool b)                                    { t->setTabletTracking(b);                 return self(); }
    S& mask(const QBitmap& m)                                    { t->setMask(m);                           return self(); }
    S& mask(const QRegion& m)                                    { t->setMask(m);                           return self(); }

#if QT_CONFIG(graphicseffect)
    S& graphicsEffect(QGraphicsEffect* effect)                   { t->setGraphicsEffect(effect);            return self(); };
#endif

#ifndef QT_NO_STYLE_STYLESHEET
    S& styleSheet(const QString& s)                              { t->setStyleSheet(s);                     return self(); }
#endif

    S& windowTitle(const QString& s)                             { t->setWindowTitle(s);                    return self(); }
    S& windowIcon(const QIcon& icon)                             { t->setWindowIcon(icon);                  return self(); }
    S& windowIconText(const QString& s)                          { t->setWindowIconText(s);                 return self(); }
    S& windowRole(const QString& s)                              { t->setWindowRole(s);                     return self(); }
    S& windowFilePath(const QString& path)                       { t->setWindowFilePath(path);              return self(); }
    S& windowOpacity(qreal level)                                { t->setWindowOpacity(level);              return self(); }

#if QT_CONFIG(tooltip)
    S& toolTip(const QString& s)                                 { t->setToolTip(s);                        return self(); }
    S& toolTipDuration(int ms)                                   { t->setToolTipDuration(ms);               return self(); }
#endif

#if QT_CONFIG(statustip)
    S& statusTip(const QString& s)                               { t->setStatusTip(s);                      return self(); }
#endif

#if QT_CONFIG(whatsthis)
    S& whatsThis(const QString& s)                               { t->setWhatsThis(s);                      return self(); }
#endif

#if QT_CONFIG(accessibility)
    S& asccessibleName(const QString& name)                      { t->setAccessibleName(name);              return self(); }
    S& asccessibleDescription(const QString& desc)               { t->setAccessibleDescription(desc);       return self(); }
#endif

    S& layoutDirection(Qt::LayoutDirection direction)            { t->setLayoutDirection(direction);        return self(); }

    S& locale(const QLocale& l)                                  { t->setLocale(l);                         return self(); }

    S& focus(Qt::FocusReason reason)                             { t->setFocus(reason);                     return self(); }
    S& focusPolicy(Qt::FocusPolicy policy)                       { t->setFocusPolicy(policy);               return self(); }

    S& focusProxy(QWidget* proxy)                                { t->setFocusProxy(proxy);                 return self(); }

    S& contextMenuPolicy(Qt::ContextMenuPolicy policy)           { t->setContextMenuPolicy(policy);         return self(); }

    S& updatesEnabled(bool b)                                    { t->setUpdatesEnabled(b);                 return self(); }

    S& visible(bool b)                                           { t->setVisible(b);                        return self(); }
    S& hidden(bool b)                                            { t->setHidden(b);                         return self(); }

    S& geometry(int x, int y, int w, int h)                      { t->setGeometry(x, y, w, h);              return self(); }
    S& geometry(const QRect& r)                                  { t->setGeometry(r);                       return self(); }

    S& windowState(Qt::WindowStates state)                       { t->setWindowState(state);                return self(); }

    S& sizePolicy(QSizePolicy p)                                 { t->setSizePolicy(p);                     return self(); }
    S& sizePolicy(QSizePolicy::Policy h, QSizePolicy::Policy v)  { t->setSizePolicy(h, v);                  return self(); };

    S& contentsMargins(int l, int t, int r, int b)               { this->t->setContentsMargins(l, t, r, b); return self(); }
    S& contentsMargins(const QMargins& margins)                  { t->setContentsMargins(margins);          return self(); }

    S& layout(QLayout* l)                                        { t->setLayout(l);                         return self(); }

    S& acceptDrops(bool b)                                       { t->setAcceptDrops(b);                    return self(); }

    S& windowFlags(Qt::WindowFlags type)                         { t->setWindowFlags(type);                 return self(); }
    S& windowFlag(Qt::WindowType type, bool on = true)           { t->setWindowFlag(type, on);              return self(); }

    S& inputMethodHints(Qt::InputMethodHints hints)              { t->setInputMethodHints(hints);           return self(); }

    S& backingStore(QBackingStore* store)                        { t->setBackingStore(store);               return self(); }

    N_SIGNAL(onWindowTitleChanged        , QWidget::windowTitleChanged        )
    N_SIGNAL(onWindowIconChanged         , QWidget::windowIconChanged         )
    N_SIGNAL(onWindowIconTextChanged     , QWidget::windowIconTextChanged     )
    N_SIGNAL(onCustomContextMenuRequested, QWidget::customContextMenuRequested)
};

N_BUILDER_IMPL(WidgetBuilder, QWidget, Widget);

}

#endif // WIDGET_H
