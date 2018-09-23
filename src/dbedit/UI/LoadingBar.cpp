#include "LoadingBar.h"
#include "ui_LoadingBar.h"
#include "Errors.h"
#include "StringFormat.h"
#include "QtHelpers.h"
#include <QLabel>
#include <QProgressBar>
#include <QStackedWidget>

LoadingBar::LoadingBar(QWidget* parent, char const* label) :
    QWidget(parent),
    Q_SETUP(),
    FIND_Q_CHILD(_label),
    FIND_Q_CHILD(_progressSwitcher),
    FIND_Q_CHILD(_progress)
{
    _label.setText(label);
    _progressSwitcher.setCurrentIndex(WAITING);
}

void LoadingBar::SetProgress(uint16 cur, uint16 max)
{
    _progress.setRange(0, max);
    _progress.setValue(cur);
    _progressSwitcher.setCurrentIndex(IN_PROGRESS);
}

void LoadingBar::HideProgress()
{
    _progressSwitcher.setCurrentIndex(HIDDEN);
}

void LoadingBar::Complete(bool success)
{
    _progressSwitcher.setCurrentIndex(success ? DONE : FAIL);
}

LoadingBar::~LoadingBar() {}
