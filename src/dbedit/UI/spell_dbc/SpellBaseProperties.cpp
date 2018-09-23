#include "SpellBaseProperties.h"
#include "DBCStructure.h"
#include "Errors.h"
#include "QtHelpers.h"
#include "SearchableDropdown.h"
#include "SmartEnum.h"
#include "StringFormat.h"
#include <QLabel>

void SpellBaseProperties::Setup()
{
    FIND_Q_CHILD_DELAYED(_spellId);
    FIND_Q_CHILD_DELAYED(_spellName);
    FIND_Q_CHILD_DELAYED(_spellRank);
    FIND_Q_CHILD_DELAYED(_spellFamily);

    CONNECT_SAME(_spellFamily, this, ValueChanged);
}

void SpellBaseProperties::SetEntry(SpellEntry const* entry)
{
    _currentSpellId = entry->Id;
    _spellId->setText(Trinity::QStringFormat("#%05u", entry->Id));
    _spellName->setText(entry->SpellName[0]);
    _spellRank->setText(entry->Rank[0]);
    _spellFamily->SetCurrentValue(SpellFamilyNames(entry->SpellFamilyName));
}

void SpellBaseProperties::BuildEntry(SpellEntry& entry) const
{
    entry.SpellFamilyName = _spellFamily->GetCurrentValue();
}
