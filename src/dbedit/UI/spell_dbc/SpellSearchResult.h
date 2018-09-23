#ifndef TRINITY_DBEDIT_SPELLSEARCHRESULT_H
#define TRINITY_DBEDIT_SPELLSEARCHRESULT_H

#include "Define.h"
#include <QListWidgetItem>

class SpellSearchResult : public QListWidgetItem
{
    public:
        SpellSearchResult(uint32 spellId, char const* spellName) : QListWidgetItem(spellName), _spellId(spellId) {}
        uint32 GetId() const { return _spellId; }

    private:
        uint32 const _spellId;
};

#endif
