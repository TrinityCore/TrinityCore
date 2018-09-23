#ifndef TRINITYCORE_DBEDIT_SPELLEFFECTSWIDGET_H
#define TRINITYCORE_DBEDIT_SPELLEFFECTSWIDGET_H

#include "Define.h"
#include "SearchableDropdownDecl.h"
#include <memory>
#include <QWidget>

namespace Ui { class SpellEffectsWidget; }

enum SpellEffIndex : uint8;
struct SpellEntry;

class SpellEffectsWidget : public QWidget
{
    Q_OBJECT
    
    public:
        SpellEffectsWidget(QWidget* parent, SpellEffIndex index);
        ~SpellEffectsWidget();
        void SetEntry(SpellEntry const*);
        void BuildEntry(SpellEntry&) const;
        
    private:
        SpellEffIndex const _index;
        std::unique_ptr<Ui::SpellEffectsWidget> me;

        SpellEffectsDropdown* _effectDropdown;
};

#endif
