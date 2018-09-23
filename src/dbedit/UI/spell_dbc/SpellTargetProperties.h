#ifndef TRINITY_DBEDIT_SPELLTARGETPROPERTIES_H
#define TRINITY_DBEDIT_SPELLTARGETPROPERTIES_H

#include "SpellDataDisplay.h"
#include <QGroupBox>

struct SpellEntry;

class SpellTargetProperties : public SpellDataElement
{
    Q_OBJECT

    public:
        SpellTargetProperties(QWidget* parent = nullptr) : SpellDataElement(parent) {}
        void Setup() override;
        void SetEntry(SpellEntry const* entry) override;
        void BuildEntry(SpellEntry&) const override;
};

#endif
