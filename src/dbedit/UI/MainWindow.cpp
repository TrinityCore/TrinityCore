#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Errors.h"
#include "DBCStructure.h"
#include "GlobalDBCStores.h"
#include "Globals.h"
#include "QtHelpers.h"
#include "TopLevelPage.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    Q_SETUP(),
    FIND_Q_CHILD(_pageSwitcher),
    _hadSetup()
{
}

void MainWindow::Setup()
{
    printf("%u spells loaded from DBC\n", StaticDBCStore<SpellEntry>::GetNumRows());
    printf("%u spells loaded from spell_dbc\n", DatabaseDBCStore<SpellEntry>::GetNumRows());

    auto it = StaticDBCStore<SpellEntry>::begin();
    std::advance(it, 2500);
    printf("For example, spell %u is called %s.\n", it->Id, it->SpellName[0]);

    SwitchToPage(0);
    this->showMaximized();
    this->activateWindow();
}

void MainWindow::SwitchToPage(uint8 index)
{
    ASSERT(index < PAGE_MAX);
    if (!_hadSetup[index])
    {
        static_cast<TopLevelPage*>(_pageSwitcher.widget(index))->Setup();
        _hadSetup[index] = true;
    }
    _pageSwitcher.setCurrentIndex(index);
}

MainWindow::~MainWindow() {}
