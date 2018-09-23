#include "LoadingWindow.h"
#include "ui_LoadingWindow.h"
#include "Errors.h"
#include "LoadingBar.h"
#include "StringFormat.h"
#include "QtHelpers.h"
#include <QLabel>
#include <QProgressBar>
#include <QStackedWidget>

LoadingWindow::LoadingWindow() :
    QWidget(nullptr, Qt::Dialog),
    Q_SETUP(),
    _numSteps(0),
    _bars(nullptr)
{
}

static constexpr int MARGIN_EDGE = 10;
static constexpr int MARGIN_BETWEEN = 5;
void LoadingWindow::Init(uint16 numSteps, char const* const* labels)
{
    ASSERT(!_bars);
    _numSteps = numSteps;
    _bars = new std::unique_ptr<LoadingBar>[numSteps];

    int height = MARGIN_EDGE;
    for (uint16 i = 0; i < numSteps; ++i)
    {
        _bars[i] = std::make_unique<LoadingBar>(this, labels[i]);
        QRect rect = _bars[i]->geometry();
        rect.moveTopLeft({ MARGIN_EDGE, height });
        height = height + rect.height() + MARGIN_BETWEEN;
        _bars[i]->setGeometry(rect);
    }
    height = height - MARGIN_BETWEEN + MARGIN_EDGE;
    int width = MARGIN_EDGE * 2 + _bars[0]->geometry().width();
    this->setFixedSize(width, height);
    this->show();
}

void LoadingWindow::LoadAborted(uint16 at)
{
    for (uint16 i = at+1; i < _numSteps; ++i)
        _bars[i]->HideProgress();
}

LoadingWindow::~LoadingWindow() {}
