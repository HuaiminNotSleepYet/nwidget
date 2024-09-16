#ifndef NWIDGET_WIDGET_H
#define NWIDGET_WIDGET_H

#include <QWidget>
#include <QLocale>

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

    N_ID_PROPERTY(bool                 , modal                , N_READ isModal                                           )
    N_ID_PROPERTY(Qt::WindowModality   , windowModality       , N_READ windowModality        N_WRITE setWindowModality   )
    N_ID_PROPERTY(bool                 , enabled              , N_READ isEnabled             N_WRITE setEnabled          )
    N_ID_PROPERTY(QRect                , geometry             , N_READ geometry              N_WRITE setGeometry         )
    N_ID_PROPERTY(QRect                , frameGeometry        , N_READ frameGeometry                                     )
    N_ID_PROPERTY(QRect                , normalGeometry       , N_READ normalGeometry                                    )
    N_ID_PROPERTY(int                  , x                    , N_READ x                                                 )
    N_ID_PROPERTY(int                  , y                    , N_READ y                                                 )
    N_ID_PROPERTY(QPoint               , pos                  , N_READ pos                   N_WRITE move                )
    N_ID_PROPERTY(QSize                , frameSize            , N_READ frameSize                                         )
    N_ID_PROPERTY(QSize                , size                 , N_READ size                  N_WRITE resize              )
    N_ID_PROPERTY(int                  , width                , N_READ width                                             )
    N_ID_PROPERTY(int                  , height               , N_READ height                                            )
    N_ID_PROPERTY(QRect                , rect                 , N_READ rect                                              )
    N_ID_PROPERTY(QRect                , childrenRect         , N_READ childrenRect                                      )
    N_ID_PROPERTY(QRegion              , childrenRegion       , N_READ childrenRegion                                    )
    N_ID_PROPERTY(QSizePolicy          , sizePolicy           , N_READ sizePolicy            N_WRITE setSizePolicy       )
    N_ID_PROPERTY(QSize                , minimumSize          , N_READ minimumSize           N_WRITE setMinimumSize      )
    N_ID_PROPERTY(QSize                , maximumSize          , N_READ maximumSize           N_WRITE setMaximumSize      )
    N_ID_PROPERTY(int                  , minimumWidth         , N_READ minimumWidth          N_WRITE setMinimumWidth     )
    N_ID_PROPERTY(int                  , minimumHeight        , N_READ minimumHeight         N_WRITE setMinimumHeight    )
    N_ID_PROPERTY(int                  , maximumWidth         , N_READ maximumWidth          N_WRITE setMaximumWidth     )
    N_ID_PROPERTY(int                  , maximumHeight        , N_READ maximumHeight         N_WRITE setMaximumHeight    )
    N_ID_PROPERTY(QSize                , sizeIncrement        , N_READ sizeIncrement         N_WRITE setSizeIncrement    )
    N_ID_PROPERTY(QSize                , baseSize             , N_READ baseSize              N_WRITE setBaseSize         )
    N_ID_PROPERTY(QPalette             , alette               , N_READ palette               N_WRITE setPalette          )
    N_ID_PROPERTY(QFont                , font                 , N_READ font                  N_WRITE setFont             )
#ifndef QT_NO_CURSOR
    N_ID_PROPERTY(QCursor              , cursor               , N_READ cursor                N_WRITE setCursor           )
#endif
    N_ID_PROPERTY(bool                 , mouseTracking        , N_READ hasMouseTracking      N_WRITE setMouseTracking    )
    N_ID_PROPERTY(bool                 , tabletTracking       , N_READ hasTabletTracking     N_WRITE setTabletTracking   )
    N_ID_PROPERTY(bool                 , isActiveWindow       , N_READ isActiveWindow                                    )
    N_ID_PROPERTY(Qt::FocusPolicy      , focusPolicy          , N_READ focusPolicy           N_WRITE setFocusPolicy      )
    N_ID_PROPERTY(bool                 , focus                , N_READ hasFocus                                          )
    N_ID_PROPERTY(Qt::ContextMenuPolicy, contextMenuPolicy    , N_READ contextMenuPolicy     N_WRITE setContextMenuPolicy)
    N_ID_PROPERTY(bool                 , updatesEnabled       , N_READ updatesEnabled        N_WRITE setUpdatesEnabled   )
    N_ID_PROPERTY(bool                 , visible              , N_READ isVisible             N_WRITE setVisible          )
    N_ID_PROPERTY(bool                 , minimized            , N_READ isMinimized                                       )
    N_ID_PROPERTY(bool                 , maximized            , N_READ isMaximized                                       )
    N_ID_PROPERTY(bool                 , fullScreen           , N_READ isFullScreen                                      )
    N_ID_PROPERTY(QSize                , sizeHint             , N_READ sizeHint                                          )
    N_ID_PROPERTY(QSize                , minimumSizeHint      , N_READ minimumSizeHint                                   )
    N_ID_PROPERTY(bool                 , acceptDrops          , N_READ acceptDrops           N_WRITE setAcceptDrops      )
    N_ID_PROPERTY(QString              , windowTitle          , N_READ windowTitle           N_WRITE setWindowTitle      N_NOTIFY windowTitleChanged)
    N_ID_PROPERTY(QIcon                , windowIcon           , N_READ windowIcon            N_WRITE setWindowIcon       N_NOTIFY windowIconChanged)
    N_ID_PROPERTY(QString              , windowIconText       , N_READ windowIconText        N_WRITE setWindowIconText   N_NOTIFY windowIconTextChanged)
    N_ID_PROPERTY(double               , windowOpacity        , N_READ windowOpacity         N_WRITE setWindowOpacity    )
    N_ID_PROPERTY(bool                 , windowModified       , N_READ isWindowModified      N_WRITE setWindowModified   )
#if QT_CONFIG(tooltip)
    N_ID_PROPERTY(QString              , toolTip              , N_READ toolTip               N_WRITE setToolTip          )
    N_ID_PROPERTY(int                  , toolTipDuration      , N_READ toolTipDuration       N_WRITE setToolTipDuration  )
#endif
#if QT_CONFIG(statustip)
    N_ID_PROPERTY(QString              , statusTip            , N_READ statusTip             N_WRITE setStatusTip        )
#endif
#if QT_CONFIG(whatsthis)
    N_ID_PROPERTY(QString              , whatsThis            , N_READ whatsThis             N_WRITE setWhatsThis        )
#endif
#if QT_CONFIG(accessibility)
    N_ID_PROPERTY(QString              , accessibleName       , N_READ accessibleName        N_WRITE setAccessibleName   )
    N_ID_PROPERTY(QString              , accessibleDescription, N_READ accessibleDescription N_WRITE setAccessibleDescription)
#endif
    N_ID_PROPERTY(Qt::LayoutDirection  , layoutDirection      , N_READ layoutDirection       N_WRITE setLayoutDirection   )
    N_ID_PROPERTY(Qt::WindowFlags      , windowFlags          , N_READ windowFlags           N_WRITE setWindowFlags       )
    N_ID_PROPERTY(bool                 , autoFillBackground   , N_READ autoFillBackground    N_WRITE setAutoFillBackground)
#ifndef QT_NO_STYLE_STYLESHEET
    N_ID_PROPERTY(QString              , styleSheet           , N_READ styleSheet            N_WRITE setStyleSheet        )
#endif
    N_ID_PROPERTY(QLocale              , locale               , N_READ locale                N_WRITE setLocale            )
    N_ID_PROPERTY(QString              , windowFilePath       , N_READ windowFilePath        N_WRITE setWindowFilePath    )
    N_ID_PROPERTY(Qt::InputMethodHints , inputMethodHints     , N_READ inputMethodHints      N_WRITE setInputMethodHints  )
};

N_DECLARE_ID(Widget, WidgetIdT, QWidget)

}

#endif // NWIDGET_WIDGET_H
