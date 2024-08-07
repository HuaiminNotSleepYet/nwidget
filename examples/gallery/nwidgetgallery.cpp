#include "nwidgetgallery.h"

#include <QApplication>
#include <QDesktopServices>
#include <QLibraryInfo>
#include <QFileSystemModel>
#include <QStyleFactory>
#include <QWindow>
#include <QTimer>
#include <QShortcut>
#include <QStandardItemModel>

#include "nwidget/action.h"
#include "nwidget/boxlayout.h"
#include "nwidget/checkbox.h"
#include "nwidget/combobox.h"
#include "nwidget/commandlinkbutton.h"
#include "nwidget/datetimeedit.h"
#include "nwidget/dial.h"
#include "nwidget/dialogbuttonbox.h"
#include "nwidget/gridlayout.h"
#include "nwidget/groupbox.h"
#include "nwidget/label.h"
#include "nwidget/lineedit.h"
#include "nwidget/listview.h"
#include "nwidget/menu.h"
#include "nwidget/plaintextedit.h"
#include "nwidget/progressbar.h"
#include "nwidget/pushbutton.h"
#include "nwidget/radiobutton.h"
#include "nwidget/scrollbar.h"
#include "nwidget/slider.h"
#include "nwidget/spinbox.h"
#include "nwidget/tablewidget.h"
#include "nwidget/tabwidget.h"
#include "nwidget/textbrowser.h"
#include "nwidget/textedit.h"
#include "nwidget/toolbox.h"
#include "nwidget/toolbutton.h"
#include "nwidget/treeview.h"

using namespace nw;

static QString className(const QObject *o)
{
    return QString::fromUtf8(o->metaObject()->className());
}

static QString helpUrl(const QString &page)
{
    QString result;
    QTextStream(&result) << "https://doc.qt.io/qt-" << QT_VERSION_MAJOR
                         << '/' << page << ".html";
    return result;
}

static QString helpUrl(const QWidget *w)
{
    return helpUrl(className(w).toLower());
}

static void launchHelp(const QWidget *w)
{
    QDesktopServices::openUrl(helpUrl(w));
}

static void launchModuleHelp()
{
    QDesktopServices::openUrl(helpUrl(QLatin1String("qtwidgets-index")));
}

QTextStream &operator<<(QTextStream &str, const QRect &r)
{
    str << r.width() << 'x' << r.height() << Qt::forcesign << r.x() << r.y()
        << Qt::noforcesign;
    return str;
}

static QString highDpiScaleFactorRoundingPolicy()
{
    QString result;
    QDebug(&result) << QGuiApplication::highDpiScaleFactorRoundingPolicy();
    if (result.endsWith(QLatin1Char(')')))
        result.chop(1);
    const int lastSep = result.lastIndexOf(QLatin1String("::"));
    if (lastSep != -1)
        result.remove(0, lastSep + 2);
    return result;
}

NWidgetGallery::NWidgetGallery()
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);



    QStringList styleNames = QStyleFactory::keys();
    const QString defaultStyleName = QApplication::style()->objectName();
    for (int i = 1, size = styleNames.size(); i < size; ++i) {
        if (defaultStyleName.compare(styleNames.at(i), Qt::CaseInsensitive) == 0) {
            styleNames.swapItemsAt(0, i);
            break;
        }
    }

    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::homePath());

    auto listModel = new QStandardItemModel(0, 1, this);
    listModel->appendRow(new QStandardItem(QIcon(QLatin1String(":/qt-project.org/styles/commonstyle/images/diropen-128.png")),
                                           tr("Directory")));
    listModel->appendRow(new QStandardItem(QIcon(QLatin1String(":/qt-project.org/styles/commonstyle/images/computer-32.png")),
                                           tr("Computer")));

    const QString plainText = tr("Twinkle, twinkle, little star,\n"
                                 "How I wonder what you are.\n"
                                 "Up above the world so high,\n"
                                 "Like a diamond in the sky.\n"
                                 "Twinkle, twinkle, little star,\n"
                                 "How I wonder what you are!\n");
    QString richText = QLatin1String("<html><head/><body><i>");
    for (const auto &line : QStringView{ plainText }.split(QLatin1Char('\n')))
        richText += QString::fromLatin1("<center>%1</center>").arg(line);
    richText += QLatin1String("</i></body></html>");



    QCheckBox* disableWidgetsCheckBox = nullptr;
    QWidget* buttonsGroupBox = nullptr;
    QWidget* itemViewTabWidget  = nullptr;
    QWidget* simpleInputWidgetsGroupBox  = nullptr;
    QWidget* textToolBox = nullptr;

    setLayout(GridLayout{
        {0, 0, 1, 2, HBoxLayout{
            Label(tr("Style:")),
            ComboBox(styleNames).onTextActivated(this, &NWidgetGallery::changeStyle),
            BoxLayoutItem::Stretch,
            Label(tr("Press F1 over a widget to see Documentation")),
            BoxLayoutItem::Stretch,
            CheckBox(tr("Disable widgets")).bindTo(disableWidgetsCheckBox),
        }},
        {1, 0, GroupBox(tr("Buttons"),
        HBoxLayout{
            VBoxLayout{
                PushButton(tr("Default Push Button")).default_(true),
                PushButton(tr("Toggle Push Button")).checkable(true),
                PushButton(tr("Flat Push Button")).flat(true),
                HBoxLayout{
                    ToolButton(tr("Tool Button")),
                    ToolButton(tr("Menu Button"))
                        .popupMode(QToolButton::InstantPopup)
                        .menu(Menu{
                            Action(tr("Option")),
                            MenuItem::Spearator,
                            Action(tr("Checkable Option")),
                        }),
                },
                CommandLinkButton(tr("Command Link Button"), tr("Description")),
                BoxLayoutItem::Stretch,
            },
            VBoxLayout{
                RadioButton(tr("Radio button 1")).checked(true),
                RadioButton(tr("Radio button 2")),
                RadioButton(tr("Radio button 3")),
                CheckBox(tr("Tri-state check box")).tristate().checkState(Qt::PartiallyChecked),
                BoxLayoutItem::Stretch,
            }
        }).bindTo(buttonsGroupBox)},
        {1, 1, GroupBox(tr("Simple Input Widgets"), GridLayout{
            {0, 0, 1, 2, LineEdit("zhang").clearButtonEnabled(true).echoMode(QLineEdit::Password)},
            {1, 0, 1, 2, SpinBox().value(50)},
            {2, 0, 1, 2, DateTimeEdit().dateTime(QDateTime::currentDateTime())},
            {3, 0,       Slider(Qt::Horizontal).value(40)},
            {4, 0,       ScrollBar(Qt::Horizontal).value(60)},
            {3, 1, 2, 1, Dial().value(30).notchesVisible(true)},
        }).bindTo(simpleInputWidgetsGroupBox).checkable(true).checked(true)},
        {2, 0, TabWidget{
            {tr("Tree View")     , TreeView(fileSystemModel)},
            {tr("Table")         , TableWidget(10, 10)},
            {tr("List")          , ListView(listModel)},
            {tr("Icon Mode List"), ListView(listModel).viewMode(QListView::IconMode)},
        }.bindTo(itemViewTabWidget)},
        {2, 1, ToolBox{
            {tr("Text Edit")      , TextEdit(richText)},
            {tr("Plain Text Edit"), PlainTextEdit(plainText)},
            {tr("Text Browser")   , TextBrowser().bindTo(systemInfoTextBrowser)},
        }.bindTo(textToolBox)},
        {3, 0, 1, 2, ProgressBar(0, 10000).bindTo(progressBar)},
        {4, 0, 1, 2,
            DialogButtonBox(QDialogButtonBox::Help | QDialogButtonBox::Close)
                .onHelpRequested(this, launchModuleHelp)
                .onRejected(this, &QDialog::reject)
        },
    });

    connect(disableWidgetsCheckBox, &QCheckBox::toggled, buttonsGroupBox            , &QWidget::setDisabled);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled, itemViewTabWidget          , &QWidget::setDisabled);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled, simpleInputWidgetsGroupBox , &QWidget::setDisabled);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled, textToolBox                , &QWidget::setDisabled);

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &NWidgetGallery::advanceProgressBar);
    timer->start(1000);

    new QShortcut(QKeySequence::HelpContents, this, this, &NWidgetGallery::helpOnCurrentWidget);
}

void NWidgetGallery::setVisible(bool visible)
{
    QDialog::setVisible(visible);
    if (visible) {
        connect(windowHandle(), &QWindow::screenChanged, this, &NWidgetGallery::updateSystemInfo);
        updateSystemInfo();
    }
}

void NWidgetGallery::changeStyle(const QString& styleName)
{
    QApplication::setStyle(QStyleFactory::create(styleName));
}

void NWidgetGallery::advanceProgressBar()
{
    int curVal = progressBar->value();
    int maxVal = progressBar->maximum();
    progressBar->setValue(curVal + (maxVal - curVal) / 100);
}

void NWidgetGallery::updateSystemInfo()
{
    QString systemInfo;
    QTextStream str(&systemInfo);
    str << "<html><head/><body><h3>Build</h3><p>" << QLibraryInfo::build() << "</p>"
        << "<h3>Operating System</h3><p>" << QSysInfo::prettyProductName() << "</p>"
        << "<h3>Screens</h3><p>High DPI scale factor rounding policy: "
        << highDpiScaleFactorRoundingPolicy() << "</p><ol>";
    const auto screens = QGuiApplication::screens();
    for (auto screen : screens) {
        const bool current = screen == this->screen();
        str << "<li>";
        if (current)
            str << "<i>";
        str << '"' << screen->name() << "\" " << screen->geometry() << ", "
            << screen->logicalDotsPerInchX() << "DPI, DPR="
            << screen->devicePixelRatio();
        if (current)
            str << "</i>";
        str << "</li>";
    }
    str << "</ol></body></html>";
    systemInfoTextBrowser->setHtml(systemInfo);
}

void NWidgetGallery::helpOnCurrentWidget()
{
    for (auto w = QApplication::widgetAt(QCursor::pos(screen())); w; w = w->parentWidget()) {
        launchHelp(w);
    }
}
