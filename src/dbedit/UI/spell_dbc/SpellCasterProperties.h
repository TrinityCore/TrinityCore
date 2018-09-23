#ifndef TRINITY_DBEDIT_SPELLCASTERPROPERTIES_H
#define TRINITY_DBEDIT_SPELLCASTERPROPERTIES_H

#include "SpellDataDisplay.h"
#include <QGroupBox>

struct SpellEntry;

class SpellCasterProperties : public SpellDataElement
{
    Q_OBJECT

    public:
        SpellCasterProperties(QWidget* parent = nullptr) : SpellDataElement(parent) {}
        void Setup() override;
        void SetEntry(SpellEntry const*) override;
        void BuildEntry(SpellEntry&) const override;
};

#endif
