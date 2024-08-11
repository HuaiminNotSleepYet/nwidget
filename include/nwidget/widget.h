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



template<typename T>
class WidgetRefT : public ObjectRefT<T>
{
public:
    using ObjectRefT<T>::ObjectRefT;


    N_PROPERTY(bool                 , modal                , N_GETTER(isModal              ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(Qt::WindowModality   , windowModality       , N_GETTER(windowModality       ), N_SETTER(setWindowModality       ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , enabled              , N_GETTER(isEnabled            ), N_SETTER(setEnabled              ), N_NO_NOTIFY)
    N_PROPERTY(QRect                , geometry             , N_GETTER(geometry             ), N_SETTER(setGeometry             ), N_NO_NOTIFY)
    N_PROPERTY(QRect                , frameGeometry        , N_GETTER(frameGeometry        ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QRect                , normalGeometry       , N_GETTER(normalGeometry       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(int                  , x                    , N_GETTER(x                    ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(int                  , y                    , N_GETTER(y                    ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QPoint               , pos                  , N_GETTER(pos                  ), N_SETTER(move                    ), N_NO_NOTIFY)
    N_PROPERTY(QSize                , frameSize            , N_GETTER(frameSize            ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QSize                , size                 , N_GETTER(size                 ), N_SETTER(resize                  ), N_NO_NOTIFY)
    N_PROPERTY(int                  , width                , N_GETTER(width                ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(int                  , height               , N_GETTER(height               ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QRect                , rect                 , N_GETTER(rect                 ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QRect                , childrenRect         , N_GETTER(childrenRect         ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QRegion              , childrenRegion       , N_GETTER(childrenRegion       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QSizePolicy          , sizePolicy           , N_GETTER(sizePolicy           ), N_SETTER(setSizePolicy           ), N_NO_NOTIFY)
    N_PROPERTY(QSize                , minimumSize          , N_GETTER(minimumSize          ), N_SETTER(setMinimumSize          ), N_NO_NOTIFY)
    N_PROPERTY(QSize                , maximumSize          , N_GETTER(maximumSize          ), N_SETTER(setMaximumSize          ), N_NO_NOTIFY)
    N_PROPERTY(int                  , minimumWidth         , N_GETTER(minimumWidth         ), N_SETTER(setMinimumWidth         ), N_NO_NOTIFY)
    N_PROPERTY(int                  , minimumHeight        , N_GETTER(minimumHeight        ), N_SETTER(setMinimumHeight        ), N_NO_NOTIFY)
    N_PROPERTY(int                  , maximumWidth         , N_GETTER(maximumWidth         ), N_SETTER(setMaximumWidth         ), N_NO_NOTIFY)
    N_PROPERTY(int                  , maximumHeight        , N_GETTER(maximumHeight        ), N_SETTER(setMaximumHeight        ), N_NO_NOTIFY)
    N_PROPERTY(QSize                , sizeIncrement        , N_GETTER(sizeIncrement        ), N_SETTER(setSizeIncrement        ), N_NO_NOTIFY)
    N_PROPERTY(QSize                , baseSize             , N_GETTER(baseSize             ), N_SETTER(setBaseSize             ), N_NO_NOTIFY)
    N_PROPERTY(QPalette             , alette               , N_GETTER(palette              ), N_SETTER(setPalette              ), N_NO_NOTIFY)
    N_PROPERTY(QFont                , font                 , N_GETTER(font                 ), N_SETTER(setFont                 ), N_NO_NOTIFY)
#ifndef QT_NO_CURSOR
    N_PROPERTY(QCursor              , cursor               , N_GETTER(cursor               ), N_SETTER(setCursor               ), N_NO_NOTIFY)
#endif
    N_PROPERTY(bool                 , mouseTracking        , N_GETTER(hasMouseTracking     ), N_SETTER(setMouseTracking        ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , tabletTracking       , N_GETTER(hasTabletTracking    ), N_SETTER(setTabletTracking       ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , isActiveWindow       , N_GETTER(isActiveWindow       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(Qt::FocusPolicy      , focusPolicy          , N_GETTER(focusPolicy          ), N_SETTER(setFocusPolicy          ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , focus                , N_GETTER(hasFocus             ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(Qt::ContextMenuPolicy, contextMenuPolicy    , N_GETTER(contextMenuPolicy    ), N_SETTER(setContextMenuPolicy    ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , updatesEnabled       , N_GETTER(updatesEnabled       ), N_SETTER(setUpdatesEnabled       ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , visible              , N_GETTER(isVisible            ), N_SETTER(setVisible              ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , minimized            , N_GETTER(isMinimized          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(bool                 , maximized            , N_GETTER(isMaximized          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(bool                 , fullScreen           , N_GETTER(isFullScreen         ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QSize                , sizeHint             , N_GETTER(sizeHint             ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(QSize                , minimumSizeHint      , N_GETTER(minimumSizeHint      ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_PROPERTY(bool                 , acceptDrops          , N_GETTER(acceptDrops          ), N_SETTER(setAcceptDrops          ), N_NO_NOTIFY)
    N_PROPERTY(QString              , windowTitle          , N_GETTER(windowTitle          ), N_SETTER(setWindowTitle          ), N_NOTIFY(windowTitleChanged))
    N_PROPERTY(QIcon                , windowIcon           , N_GETTER(windowIcon           ), N_SETTER(setWindowIcon           ), N_NOTIFY(windowIconChanged))
    N_PROPERTY(QString              , windowIconText       , N_GETTER(windowIconText       ), N_SETTER(setWindowIconText       ), N_NOTIFY(windowIconTextChanged))
    N_PROPERTY(double               , windowOpacity        , N_GETTER(windowOpacity        ), N_SETTER(setWindowOpacity        ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , windowModified       , N_GETTER(isWindowModified     ), N_SETTER(setWindowModified       ), N_NO_NOTIFY)
#if QT_CONFIG(tooltip)
    N_PROPERTY(QString              , toolTip              , N_GETTER(toolTip              ), N_SETTER(setToolTip              ), N_NO_NOTIFY)
    N_PROPERTY(int                  , toolTipDuration      , N_GETTER(toolTipDuration      ), N_SETTER(setToolTipDuration      ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(statustip)
    N_PROPERTY(QString              , statusTip            , N_GETTER(statusTip            ), N_SETTER(setStatusTip            ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(whatsthis)
    N_PROPERTY(QString              , whatsThis            , N_GETTER(whatsThis            ), N_SETTER(setWhatsThis            ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(accessibility)
    N_PROPERTY(QString              , accessibleName       , N_GETTER(accessibleName       ), N_SETTER(setAccessibleName       ), N_NO_NOTIFY)
    N_PROPERTY(QString              , accessibleDescription, N_GETTER(accessibleDescription), N_SETTER(setAccessibleDescription), N_NO_NOTIFY)
#endif
    N_PROPERTY(Qt::LayoutDirection  , layoutDirection      , N_GETTER(layoutDirection      ), N_SETTER(setLayoutDirection      ), N_NO_NOTIFY)
    N_PROPERTY(Qt::WindowFlags      , windowFlags          , N_GETTER(windowFlags          ), N_SETTER(setWindowFlags          ), N_NO_NOTIFY)
    N_PROPERTY(bool                 , autoFillBackground   , N_GETTER(autoFillBackground   ), N_SETTER(setAutoFillBackground   ), N_NO_NOTIFY)
#ifndef QT_NO_STYLE_STYLESHEET
    N_PROPERTY(QString              , styleSheet           , N_GETTER(styleSheet           ), N_SETTER(setStyleSheet           ), N_NO_NOTIFY)
#endif
    N_PROPERTY(QLocale              , locale               , N_GETTER(locale               ), N_SETTER(setLocale               ), N_NO_NOTIFY)
    N_PROPERTY(QString              , windowFilePath       , N_GETTER(windowFilePath       ), N_SETTER(setWindowFilePath       ), N_NO_NOTIFY)
    N_PROPERTY(Qt::InputMethodHints , inputMethodHints     , N_GETTER(inputMethodHints     ), N_SETTER(setInputMethodHints     ), N_NO_NOTIFY)
};

using WidgetRef = WidgetRefT<QWidget>;

}

#endif // WIDGET_H
