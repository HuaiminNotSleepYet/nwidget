#ifndef NWIDGETGALLERY_H
#define NWIDGETGALLERY_H

#include <QDialog>

class QProgressBar;
class QTextBrowser;

class NWidgetGallery : public QDialog
{
    Q_OBJECT

public:
    NWidgetGallery();

    void setVisible(bool visible) override;

private slots:
    void changeStyle(const QString &styleName);
    void advanceProgressBar();
    void helpOnCurrentWidget();
    void updateSystemInfo();

private:
    QProgressBar* progressBar = nullptr;
    QTextBrowser* systemInfoTextBrowser = nullptr;
};

#endif // NWIDGETGALLERY_H
