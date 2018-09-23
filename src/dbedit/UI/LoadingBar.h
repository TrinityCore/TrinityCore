#ifndef TRINITY_LOADINGBAR_H
#define TRINITY_LOADINGBAR_H

#include "Define.h"
#include <memory>
#include <QWidget>

class QLabel;
class QProgressBar;
class QStackedWidget;

namespace Ui { class LoadingBar; }

class LoadingBar : public QWidget
{
    Q_OBJECT

    enum Pages
    {
        WAITING     = 0,
        IN_PROGRESS = 1,
        DONE        = 2,
        FAIL        = 3,
        HIDDEN      = 4
    };

    public:
        LoadingBar(QWidget* parent, char const* label);
        ~LoadingBar();

    public Q_SLOTS:
        void SetProgress(unsigned short cur, unsigned short max);
        void HideProgress();
        void Complete(bool success);

    private:
        std::unique_ptr<Ui::LoadingBar> me;

        QLabel&         _label;
        QStackedWidget& _progressSwitcher;
        QProgressBar&   _progress;
};

#endif
