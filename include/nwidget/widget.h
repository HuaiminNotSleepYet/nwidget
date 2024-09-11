#ifndef NWIDGET_WIDGET_H
#define NWIDGET_WIDGET_H

#include <QWidget>

#include "object.h"

namespace nwidget {

template<typename S, typename T>
class WidgetBuilder : public ObjectBuilder<S, T>
{
    N_BUILDER

public:
    WidgetBuilder()                           : ObjectBuilder<S, T>(new T) {}
    WidgetBuilder(QLayout* layout)            : ObjectBuilder<S, T>(new T) { t->setLayout(layout); }
    explicit
    WidgetBuilder(T* target)                  : ObjectBuilder<S, T>(target) {}
    WidgetBuilder(T* target, QLayout* layout) : ObjectBuilder<S, T>(target) { t->setLayout(layout); }


    N_BUILDER_PROPERTY(Qt::WindowModality   , windowModality       ,setWindowModality       )
    N_BUILDER_PROPERTY(bool                 , enabled              ,setEnabled              )
    N_BUILDER_PROPERTY(QRect                , geometry             ,setGeometry             )
    N_BUILDER_PROPERTY(QPoint               , pos                  ,move                    )
    N_BUILDER_PROPERTY(QSize                , size                 ,resize                  )
    N_BUILDER_PROPERTY(QSizePolicy          , sizePolicy           ,setSizePolicy           )
    N_BUILDER_PROPERTY(QSize                , minimumSize          ,setMinimumSize          )
    N_BUILDER_PROPERTY(QSize                , maximumSize          ,setMaximumSize          )
    N_BUILDER_PROPERTY(int                  , minimumWidth         ,setMinimumWidth         )
    N_BUILDER_PROPERTY(int                  , minimumHeight        ,setMinimumHeight        )
    N_BUILDER_PROPERTY(int                  , maximumWidth         ,setMaximumWidth         )
    N_BUILDER_PROPERTY(int                  , maximumHeight        ,setMaximumHeight        )
    N_BUILDER_PROPERTY(QSize                , sizeIncrement        ,setSizeIncrement        )
    N_BUILDER_PROPERTY(QSize                , baseSize             ,setBaseSize             )
    N_BUILDER_PROPERTY(QPalette             , alette               ,setPalette              )
    N_BUILDER_PROPERTY(QFont                , font                 ,setFont                 )
#ifndef QT_NO_CURSOR
    N_BUILDER_PROPERTY(QCursor              , cursor               ,setCursor               )
#endif
    N_BUILDER_PROPERTY(bool                 , mouseTracking        ,setMouseTracking        )
    N_BUILDER_PROPERTY(bool                 , tabletTracking       ,setTabletTracking       )
    N_BUILDER_PROPERTY(Qt::FocusPolicy      , focusPolicy          ,setFocusPolicy          )
    N_BUILDER_PROPERTY(Qt::ContextMenuPolicy, contextMenuPolicy    ,setContextMenuPolicy    )
    N_BUILDER_PROPERTY(bool                 , updatesEnabled       ,setUpdatesEnabled       )
    N_BUILDER_PROPERTY(bool                 , visible              ,setVisible              )
    N_BUILDER_PROPERTY(bool                 , acceptDrops          ,setAcceptDrops          )
    N_BUILDER_PROPERTY(QString              , windowTitle          ,setWindowTitle          )
    N_BUILDER_PROPERTY(QIcon                , windowIcon           ,setWindowIcon           )
    N_BUILDER_PROPERTY(QString              , windowIconText       ,setWindowIconText       )
    N_BUILDER_PROPERTY(double               , windowOpacity        ,setWindowOpacity        )
    N_BUILDER_PROPERTY(bool                 , windowModified       ,setWindowModified       )
#if QT_CONFIG(tooltip)
    N_BUILDER_PROPERTY(QString              , toolTip              ,setToolTip              )
    N_BUILDER_PROPERTY(int                  , toolTipDuration      ,setToolTipDuration      )
#endif
#if QT_CONFIG(statustip)
    N_BUILDER_PROPERTY(QString              , statusTip            ,setStatusTip            )
#endif
#if QT_CONFIG(whatsthis)
    N_BUILDER_PROPERTY(QString              , whatsThis            ,setWhatsThis            )
#endif
#if QT_CONFIG(accessibility)
    N_BUILDER_PROPERTY(QString              , accessibleName       ,setAccessibleName       )
    N_BUILDER_PROPERTY(QString              , accessibleDescription,setAccessibleDescription)
#endif
    N_BUILDER_PROPERTY(Qt::LayoutDirection  , layoutDirection      ,setLayoutDirection      )
    N_BUILDER_PROPERTY(Qt::WindowFlags      , windowFlags          ,setWindowFlags          )
    N_BUILDER_PROPERTY(bool                 , autoFillBackground   ,setAutoFillBackground   )
#ifndef QT_NO_STYLE_STYLESHEET
    N_BUILDER_PROPERTY(QString              , styleSheet           ,setStyleSheet           )
#endif
    N_BUILDER_PROPERTY(QLocale              , locale               ,setLocale               )
    N_BUILDER_PROPERTY(QString              , windowFilePath       ,setWindowFilePath       )
    N_BUILDER_PROPERTY(Qt::InputMethodHints , inputMethodHints     ,setInputMethodHints     )

    S& layout(QLayout* l)                                        { t->setLayout(l);                         return self(); }
    S& minimumSize(int w, int h)                                 { t->setMinimumSize(w, h);                 return self(); }
    S& maximumSize(int w, int h)                                 { t->setMaximumSize(w, h);                 return self(); }
    S& sizeIncrement(int w, int h)                               { t->setSizeIncrement(w, h);               return self(); }
    S& baseSize(int w, int h)                                    { t->setBaseSize(w, h);                    return self(); }
    S& fixedSize(const QSize& s)                                 { t->setFixedSize(s);                      return self(); }
    S& fixedSize(int w, int h)                                   { t->setFixedSize(w, h);                   return self(); }
    S& fixedWidth(int w)                                         { t->setFixedWidth(w);                     return self(); }
    S& fixedHeight(int h)                                        { t->setFixedHeight(h);                    return self(); }
    S& backgroundRole(QPalette::ColorRole role)                  { t->setBackgroundRole(role);              return self(); }
    S& foregroundRole(QPalette::ColorRole role)                  { t->setForegroundRole(role);              return self(); }
    S& mask(const QBitmap& m)                                    { t->setMask(m);                           return self(); }
    S& mask(const QRegion& m)                                    { t->setMask(m);                           return self(); }
#if QT_CONFIG(graphicseffect)
    S& graphicsEffect(QGraphicsEffect* effect)                   { t->setGraphicsEffect(effect);            return self(); }
#endif
    S& windowRole(const QString& s)                              { t->setWindowRole(s);                     return self(); }
#if QT_CONFIG(accessibility)
    S& asccessibleName(const QString& name)                      { t->setAccessibleName(name);              return self(); }
    S& asccessibleDescription(const QString& desc)               { t->setAccessibleDescription(desc);       return self(); }
#endif
    S& focus(Qt::FocusReason reason)                             { t->setFocus(reason);                     return self(); }
    S& focusProxy(QWidget* proxy)                                { t->setFocusProxy(proxy);                 return self(); }
    S& geometry(int x, int y, int w, int h)                      { t->setGeometry(x, y, w, h);              return self(); }
    S& windowState(Qt::WindowStates state)                       { t->setWindowState(state);                return self(); }
    S& sizePolicy(QSizePolicy::Policy h, QSizePolicy::Policy v)  { t->setSizePolicy(h, v);                  return self(); }
    S& contentsMargins(int l, int t, int r, int b)               { this->t->setContentsMargins(l, t, r, b); return self(); }
    S& contentsMargins(const QMargins& margins)                  { t->setContentsMargins(margins);          return self(); }
    S& windowFlag(Qt::WindowType type, bool on = true)           { t->setWindowFlag(type, on);              return self(); }
    S& backingStore(QBackingStore* store)                        { t->setBackingStore(store);               return self(); }

    N_BUILDER_SIGNAL(onWindowTitleChanged        , windowTitleChanged        )
    N_BUILDER_SIGNAL(onWindowIconChanged         , windowIconChanged         )
    N_BUILDER_SIGNAL(onWindowIconTextChanged     , windowIconTextChanged     )
    N_BUILDER_SIGNAL(onCustomContextMenuRequested, customContextMenuRequested)
};

N_DECLARE_BUILDER(Widget, WidgetBuilder, QWidget);



template<typename T>
class WidgetIdT : public ObjectIdT<T>
{
public:
    using ObjectIdT<T>::ObjectIdT;

    N_ID_PROPERTY(bool                 , modal                , N_GETTER(isModal              ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::WindowModality   , windowModality       , N_GETTER(windowModality       ), N_SETTER(setWindowModality       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , enabled              , N_GETTER(isEnabled            ), N_SETTER(setEnabled              ), N_NO_NOTIFY)
    N_ID_PROPERTY(QRect                , geometry             , N_GETTER(geometry             ), N_SETTER(setGeometry             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QRect                , frameGeometry        , N_GETTER(frameGeometry        ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QRect                , normalGeometry       , N_GETTER(normalGeometry       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , x                    , N_GETTER(x                    ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , y                    , N_GETTER(y                    ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QPoint               , pos                  , N_GETTER(pos                  ), N_SETTER(move                    ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , frameSize            , N_GETTER(frameSize            ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , size                 , N_GETTER(size                 ), N_SETTER(resize                  ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , width                , N_GETTER(width                ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , height               , N_GETTER(height               ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QRect                , rect                 , N_GETTER(rect                 ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QRect                , childrenRect         , N_GETTER(childrenRect         ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QRegion              , childrenRegion       , N_GETTER(childrenRegion       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QSizePolicy          , sizePolicy           , N_GETTER(sizePolicy           ), N_SETTER(setSizePolicy           ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , minimumSize          , N_GETTER(minimumSize          ), N_SETTER(setMinimumSize          ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , maximumSize          , N_GETTER(maximumSize          ), N_SETTER(setMaximumSize          ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , minimumWidth         , N_GETTER(minimumWidth         ), N_SETTER(setMinimumWidth         ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , minimumHeight        , N_GETTER(minimumHeight        ), N_SETTER(setMinimumHeight        ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , maximumWidth         , N_GETTER(maximumWidth         ), N_SETTER(setMaximumWidth         ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , maximumHeight        , N_GETTER(maximumHeight        ), N_SETTER(setMaximumHeight        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , sizeIncrement        , N_GETTER(sizeIncrement        ), N_SETTER(setSizeIncrement        ), N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , baseSize             , N_GETTER(baseSize             ), N_SETTER(setBaseSize             ), N_NO_NOTIFY)
    N_ID_PROPERTY(QPalette             , alette               , N_GETTER(palette              ), N_SETTER(setPalette              ), N_NO_NOTIFY)
    N_ID_PROPERTY(QFont                , font                 , N_GETTER(font                 ), N_SETTER(setFont                 ), N_NO_NOTIFY)
#ifndef QT_NO_CURSOR
    N_ID_PROPERTY(QCursor              , cursor               , N_GETTER(cursor               ), N_SETTER(setCursor               ), N_NO_NOTIFY)
#endif
    N_ID_PROPERTY(bool                 , mouseTracking        , N_GETTER(hasMouseTracking     ), N_SETTER(setMouseTracking        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , tabletTracking       , N_GETTER(hasTabletTracking    ), N_SETTER(setTabletTracking       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , isActiveWindow       , N_GETTER(isActiveWindow       ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::FocusPolicy      , focusPolicy          , N_GETTER(focusPolicy          ), N_SETTER(setFocusPolicy          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , focus                , N_GETTER(hasFocus             ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::ContextMenuPolicy, contextMenuPolicy    , N_GETTER(contextMenuPolicy    ), N_SETTER(setContextMenuPolicy    ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , updatesEnabled       , N_GETTER(updatesEnabled       ), N_SETTER(setUpdatesEnabled       ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , visible              , N_GETTER(isVisible            ), N_SETTER(setVisible              ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , minimized            , N_GETTER(isMinimized          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , maximized            , N_GETTER(isMaximized          ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , fullScreen           , N_GETTER(isFullScreen         ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , sizeHint             , N_GETTER(sizeHint             ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(QSize                , minimumSizeHint      , N_GETTER(minimumSizeHint      ), N_NO_SETTER                       , N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , acceptDrops          , N_GETTER(acceptDrops          ), N_SETTER(setAcceptDrops          ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString              , windowTitle          , N_GETTER(windowTitle          ), N_SETTER(setWindowTitle          ), N_NOTIFY(windowTitleChanged))
    N_ID_PROPERTY(QIcon                , windowIcon           , N_GETTER(windowIcon           ), N_SETTER(setWindowIcon           ), N_NOTIFY(windowIconChanged))
    N_ID_PROPERTY(QString              , windowIconText       , N_GETTER(windowIconText       ), N_SETTER(setWindowIconText       ), N_NOTIFY(windowIconTextChanged))
    N_ID_PROPERTY(double               , windowOpacity        , N_GETTER(windowOpacity        ), N_SETTER(setWindowOpacity        ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , windowModified       , N_GETTER(isWindowModified     ), N_SETTER(setWindowModified       ), N_NO_NOTIFY)
#if QT_CONFIG(tooltip)
    N_ID_PROPERTY(QString              , toolTip              , N_GETTER(toolTip              ), N_SETTER(setToolTip              ), N_NO_NOTIFY)
    N_ID_PROPERTY(int                  , toolTipDuration      , N_GETTER(toolTipDuration      ), N_SETTER(setToolTipDuration      ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(statustip)
    N_ID_PROPERTY(QString              , statusTip            , N_GETTER(statusTip            ), N_SETTER(setStatusTip            ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(whatsthis)
    N_ID_PROPERTY(QString              , whatsThis            , N_GETTER(whatsThis            ), N_SETTER(setWhatsThis            ), N_NO_NOTIFY)
#endif
#if QT_CONFIG(accessibility)
    N_ID_PROPERTY(QString              , accessibleName       , N_GETTER(accessibleName       ), N_SETTER(setAccessibleName       ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString              , accessibleDescription, N_GETTER(accessibleDescription), N_SETTER(setAccessibleDescription), N_NO_NOTIFY)
#endif
    N_ID_PROPERTY(Qt::LayoutDirection  , layoutDirection      , N_GETTER(layoutDirection      ), N_SETTER(setLayoutDirection      ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::WindowFlags      , windowFlags          , N_GETTER(windowFlags          ), N_SETTER(setWindowFlags          ), N_NO_NOTIFY)
    N_ID_PROPERTY(bool                 , autoFillBackground   , N_GETTER(autoFillBackground   ), N_SETTER(setAutoFillBackground   ), N_NO_NOTIFY)
#ifndef QT_NO_STYLE_STYLESHEET
    N_ID_PROPERTY(QString              , styleSheet           , N_GETTER(styleSheet           ), N_SETTER(setStyleSheet           ), N_NO_NOTIFY)
#endif
    N_ID_PROPERTY(QLocale              , locale               , N_GETTER(locale               ), N_SETTER(setLocale               ), N_NO_NOTIFY)
    N_ID_PROPERTY(QString              , windowFilePath       , N_GETTER(windowFilePath       ), N_SETTER(setWindowFilePath       ), N_NO_NOTIFY)
    N_ID_PROPERTY(Qt::InputMethodHints , inputMethodHints     , N_GETTER(inputMethodHints     ), N_SETTER(setInputMethodHints     ), N_NO_NOTIFY)
};

N_DECLARE_ID(Widget, WidgetIdT, QWidget)

}

#endif // NWIDGET_WIDGET_H
