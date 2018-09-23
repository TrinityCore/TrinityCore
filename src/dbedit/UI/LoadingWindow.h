#ifndef TRINITY_LOADINGWINDOW_H
#define TRINITY_LOADINGWINDOW_H

#include "Define.h"
#include <memory>
#include <QWidget>

class LoadingBar;

namespace Ui { class LoadingWindow; }

class LoadingWindow : public QWidget
{
    Q_OBJECT

    public:
        LoadingWindow();
        ~LoadingWindow();

        void Init(uint16 numSuperSteps, char const* const* labels);

        LoadingBar* operator[](uint16 i) const { return _bars[i].get(); }

    public Q_SLOTS:
        void LoadAborted(unsigned short);

    private:
        std::unique_ptr<Ui::LoadingWindow> me;

        uint16                          _numSteps;
        std::unique_ptr<LoadingBar>*    _bars;
};

#endif
