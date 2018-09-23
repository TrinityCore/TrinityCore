#ifndef TRINITY_MAINWINDOW_H
#define TRINITY_MAINWINDOW_H

#include "Define.h"
#include <memory>
#include <QMainWindow>

class QTabWidget;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum Pages : uint8
    {
        PAGE_SPELL_DBC = 0,
        PAGE_MAX
    };
    
    public:
        MainWindow();
        ~MainWindow();

    public Q_SLOTS:
        void Setup();
        void SwitchToPage(unsigned char);
        
    private:
        std::unique_ptr<Ui::MainWindow> me;

        QTabWidget& _pageSwitcher;

        bool _hadSetup[PAGE_MAX];
};

#endif
