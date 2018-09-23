#ifndef TRINITY_DBEDIT_SPELLDBCPAGE_H
#define TRINITY_DBEDIT_SPELLDBCPAGE_H

#include "TopLevelPage.h"

class QLineEdit;
class QListWidgetItem;
class SpellDataDisplay;
class SpellSearchResults;

namespace Ui { class SpellDBCPage; }

class SpellDBCPage : public TopLevelPage
{
    Q_OBJECT
    
    public:
        SpellDBCPage(QWidget* parent = nullptr);
        ~SpellDBCPage();
        void Setup() override {}

    public Q_SLOTS:
        void SearchEnterPressed();
        void SearchItemSelected(QListWidgetItem* selected, QListWidgetItem*);

    private:
        std::unique_ptr<Ui::SpellDBCPage> me;
        
        QLineEdit* _searchBox;
        SpellSearchResults* _searchResults;
        SpellDataDisplay* _dataDisplay;
};

#endif
