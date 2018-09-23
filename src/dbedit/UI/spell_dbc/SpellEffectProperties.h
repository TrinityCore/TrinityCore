#ifndef TRINITY_DBEDIT_SPELLEFFECTPROPERTIES_H
#define TRINITY_DBEDIT_SPELLEFFECTPROPERTIES_H

#include "DBCEnums.h"
#include "Define.h"
#include "SpellDataDisplay.h"
#include <QWidget>

class QTabWidget;
class SpellEffectsWidget;
struct SpellEntry;

class SpellEffectProperties : public SpellDataElement
{
    Q_OBJECT

    public:
        SpellEffectProperties(QWidget* parent = nullptr);
        void Setup() override;
        void SetEntry(SpellEntry const*) override;
        void BuildEntry(SpellEntry&) const override;
        void paintEvent(QPaintEvent*) override;

    Q_SIGNALS:
        void ValueChanged();

    private:
        QTabWidget*         _tab;
        SpellEffectsWidget* _children[MAX_SPELL_EFFECTS];
};

#endif
