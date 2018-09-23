#include "SpellEffectsWidget.h"
#include "ui_SpellEffectsWidget.h"
#include "DBCStructure.h"
#include "SearchableDropdown.h"
#include "SharedDefines.h"
#include "SmartEnum.h"
#include "QtHelpers.h"

SpellEffectsWidget::SpellEffectsWidget(QWidget* parent, SpellEffIndex index) :
    QWidget(parent),
    _index(index),
    Q_SETUP()
{
    FIND_Q_CHILD_DELAYED(_effectDropdown);
}

void SpellEffectsWidget::SetEntry(SpellEntry const* entry)
{
    _effectDropdown->SetCurrentKey(entry->Effect[_index]);
}

void SpellEffectsWidget::BuildEntry(SpellEntry& entry) const
{
    entry.Effect[_index] = _effectDropdown->GetCurrentKey();
}

SpellEffectsWidget::~SpellEffectsWidget() {}
