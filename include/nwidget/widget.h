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

    inline S& enabled(bool b)                                           { t->setEnabled(b);                         return self(); }
    inline S& disabled(bool b)                                          { t->setDisabled(b);                        return self(); }
    inline S& windowModified(bool b)                                    { t->setWindowModified(b);                  return self(); }

    inline S& minimumSize(const QSize& s)                               { t->setMinimumSize(s);                     return self(); }
    inline S& minimumSize(int w, int h)                                 { t->setMinimumSize(w, h);                  return self(); }
    inline S& maximumSize(const QSize& s)                               { t->setMaximumSize(s);                     return self(); }
    inline S& maximumSize(int w, int h)                                 { t->setMaximumSize(w, h);                  return self(); }
    inline S& minimumWidth(int w)                                       { t->setMinimumWidth(w);                    return self(); }
    inline S& minimumHeight(int h)                                      { t->setMinimumHeight(h);                   return self(); }
    inline S& maximumWidth(int w)                                       { t->setMaximumWidth(w);                    return self(); }
    inline S& maximumHeight(int h)                                      { t->setMaximumHeight(h);                   return self(); }

    inline S& sizeIncrement(const QSize& s)                             { t->setSizeIncrement(s);                   return self(); }
    inline S& sizeIncrement(int w, int h)                               { t->setSizeIncrement(w, h);                return self(); }
    inline S& baseSize(const QSize& s)                                  { t->setBaseSize(s);                        return self(); }
    inline S& baseSize(int w, int h)                                    { t->setBaseSize(w, h);                     return self(); }

    inline S& fixedSize(const QSize& s)                                 { t->setFixedSize(s);                       return self(); }
    inline S& fixedSize(int w, int h)                                   { t->setFixedSize(w, h);                    return self(); }
    inline S& fixedWidth(int w)                                         { t->setFixedWidth(w);                      return self(); }
    inline S& fixedHeight(int h)                                        { t->setFixedHeight(h);                     return self(); }

    inline S& palette(const QPalette& p)                                { t->setPalette(p);                         return self(); }
    inline S& backgroundRole(QPalette::ColorRole role)                  { t->setBackgroundRole(role);               return self(); }
    inline S& foregroundRole(QPalette::ColorRole role)                  { t->setForegroundRole(role);               return self(); }
    inline S& font(const QFont& f)                                      { t->setFont(f);                            return self(); }

#ifndef QT_NO_CURSOR
    inline S& cursor(const QCursor& c)                                  { t->setCursor(c);                          return self(); }
#endif

    inline S& mouseTracking(bool b)                                     { t->setMouseTracking(b);                   return self(); }
    inline S& tabletTracking(bool b)                                    { t->setTabletTracking(b);                  return self(); }
    inline S& mask(const QBitmap& m)                                    { t->setMask(m);                            return self(); }
    inline S& mask(const QRegion& m)                                    { t->setMask(m);                            return self(); }

#if QT_CONFIG(graphicseffect)
    inline S& graphicsEffect(QGraphicsEffect* effect)                   { t->setGraphicsEffect(effect);             return self(); };
#endif

#ifndef QT_NO_STYLE_STYLESHEET
    inline S& styleSheet(const QString& s)                              { t->setStyleSheet(s);                      return self(); }
#endif

    inline S& windowTitle(const QString& s)                             { t->setWindowTitle(s);                     return self(); }
    inline S& windowIcon(const QIcon& icon)                             { t->setWindowIcon(icon);                   return self(); }
    inline S& windowIconText(const QString& s)                          { t->setWindowIconText(s);                  return self(); }
    inline S& windowRole(const QString& s)                              { t->setWindowRole(s);                      return self(); }
    inline S& windowFilePath(const QString& path)                       { t->setWindowFilePath(path);               return self(); }
    inline S& windowOpacity(qreal level)                                { t->setWindowOpacity(level);               return self(); }

#if QT_CONFIG(tooltip)
    inline S& toolTip(const QString& s)                                 { t->setToolTip(s);                         return self(); }
    inline S& toolTipDuration(int ms)                                   { t->setToolTipDuration(ms);                return self(); }
#endif

#if QT_CONFIG(statustip)
    inline S& statusTip(const QString& s)                               { t->setStatusTip(s);                       return self(); }
#endif

#if QT_CONFIG(whatsthis)
    inline S& whatsThis(const QString& s)                               { t->setWhatsThis(s);                       return self(); }
#endif

#if QT_CONFIG(accessibility)
    inline S& asccessibleName(const QString& name)                      { t->setAccessibleName(name);               return self(); }
    inline S& asccessibleDescription(const QString& desc)               { t->setAccessibleDescription(desc);        return self(); }
#endif

    inline S& layoutDirection(Qt::LayoutDirection direction)            { t->setLayoutDirection(direction);         return self(); }

    inline S& locale(const QLocale& l)                                  { t->setLocale(l);                          return self(); }

    inline S& focus(Qt::FocusReason reason)                             { t->setFocus(reason);                      return self(); }
    inline S& focusPolicy(Qt::FocusPolicy policy)                       { t->setFocusPolicy(policy);                return self(); }

    inline S& focusProxy(QWidget* proxy)                                { t->setFocusProxy(proxy);                  return self(); }

    inline S& contextMenuPolicy(Qt::ContextMenuPolicy policy)           { t->setContextMenuPolicy(policy);          return self(); }

    inline S& updatesEnabled(bool b)                                    { t->setUpdatesEnabled(b);                  return self(); }

    inline S& visible(bool b)                                           { t->setVisible(b);                         return self(); }
    inline S& hidden(bool b)                                            { t->setHidden(b);                          return self(); }

    inline S& geometry(int x, int y, int w, int h)                      { t->setGeometry(x, y, w, h);               return self(); }
    inline S& geometry(const QRect& r)                                  { t->setGeometry(r);                        return self(); }

    inline S& windowState(Qt::WindowStates state)                       { t->setWindowState(state);                 return self(); }

    inline S& sizePolicy(QSizePolicy p)                                 { t->setSizePolicy(p);                      return self(); }
    inline S& sizePolicy(QSizePolicy::Policy h, QSizePolicy::Policy v)  { t->setSizePolicy(h, v);                   return self(); };

    inline S& contentsMargins(int l, int t, int r, int b)               { this->t->setContentsMargins(l, t, r, b);  return self(); }
    inline S& contentsMargins(const QMargins& margins)                  { t->setContentsMargins(margins);           return self(); }

    inline S& layout(QLayout* l)                                        { t->setLayout(l);                          return self(); }

    inline S& parent(QWidget* p)                                        { t->setParent(p);                          return self(); }
    inline S& parent(QWidget* p, Qt::WindowFlags flag)                  { t->setParent(p, flag);                    return self(); }

    inline S& acceptDrops(bool b)                                       { t->setAcceptDrops(b);                     return self(); }

    inline S& windowFlags(Qt::WindowFlags type)                         { t->setWindowFlags(type);                  return self(); }
    inline S& windowFlag(Qt::WindowType type, bool on = true)           { t->setWindowFlag(type, on);               return self(); }

    inline S& inputMethodHints(Qt::InputMethodHints hints)              { t->setInputMethodHints(hints);            return self(); }

    inline S& backingStore(QBackingStore* store)                        { t->setBackingStore(store);                return self(); }
};

N_BUILDER_IMPL(WidgetBuilder, QWidget, Widget);

}

#endif // WIDGET_H
