#ifndef TRINITY_DBEDIT_SPELLAURAPROPERTIES_H
#define TRINITY_DBEDIT_SPELLAURAPROPERTIES_H

#include "SpellDataDisplay.h"
#include <QGroupBox>

struct SpellEntry;

class SpellAuraProperties : public SpellDataElement
{
    Q_OBJECT

    public:
        SpellAuraProperties(QWidget* parent = nullptr) : SpellDataElement(parent) {}
        void Setup() override;
        void SetEntry(SpellEntry const*) override;
        void BuildEntry(SpellEntry&) const override;
};

#endif
