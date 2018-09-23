#ifndef TRINITY_DBEDIT_SPELLSEARCHRESULTS_H
#define TRINITY_DBEDIT_SPELLSEARCHRESULTS_H

#include "Define.h"
#include <QListWidget>
#include <string>

class SpellSearchResults : public QListWidget
{
    Q_OBJECT

        static constexpr uint8 MAX_RESULTS = 150;
    
    public:
        SpellSearchResults(QWidget* parent = nullptr) : QListWidget(parent) {}
        void DoSearch(QString const& str);
        void AddMessage(QString const& msg);
};

#endif
