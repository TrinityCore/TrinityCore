#include "SpellSourceSelector.h"
#include "Errors.h"
#include "Log.h"
#include "QtHelpers.h"
#include "SpellAccessor.h"
#include <QPushButton>
#include <QStackedWidget>

void SpellSourceSelector::Setup()
{
    FIND_Q_CHILD_DELAYED(_sourcePageSelector);
    FIND_Q_CHILD_DELAYED(_buttonDB);
    FIND_Q_CHILD_DELAYED(_buttonDBC);
    FIND_Q_CHILD_DELAYED(_buttonSave);
    FIND_Q_CHILD_DELAYED(_buttonDiscard);

    CONNECT(_buttonDB, clicked, this, SwitchToDB);
    CONNECT(_buttonDBC, clicked, this, SwitchToDBC);
    CONNECT(_buttonSave, clicked, this, NeedSave);
    CONNECT(_buttonDiscard, clicked, this, NeedRedraw);
}

void SpellSourceSelector::UpdateForSpell(uint32 spellId)
{
    _entryDB = SpellAccessor::GetDBSpellEntry(spellId);
    _entryDBC = SpellAccessor::GetDBCSpellEntry(spellId);

    if (_entryDB)
        _currentSource = SOURCE_DB;
    else if (_entryDBC)
        _currentSource = SOURCE_DBC;
    else
    {
        _currentSource = SOURCE_NONE;
        TC_LOG_ERROR("dbedit", "Spell %u selected, but has no data anywhere - huh?\n", spellId);
    }

    UpdateButtonStates();

    Q_EMIT NeedRedraw();
}

SpellEntry const* SpellSourceSelector::GetCurrentSpellEntry() const
{
    switch (_currentSource)
    {
        case SOURCE_DB:
            return ASSERT_NOTNULL(_entryDB);
        case SOURCE_DBC:
            return ASSERT_NOTNULL(_entryDBC);
        default:
            return nullptr;
    }
}

void SpellSourceSelector::SwitchToDB()
{
    if (!_entryDB)
        return;

    _currentSource = SOURCE_DB;
    UpdateButtonStates();
    Q_EMIT NeedRedraw();
}

void SpellSourceSelector::SwitchToDBC()
{
    if (!_entryDBC)
        return;

    _currentSource = SOURCE_DBC;
    UpdateButtonStates();
    Q_EMIT NeedRedraw();
}

void SpellSourceSelector::SetHavePendingChanges(bool state)
{
    _sourcePageSelector->setCurrentIndex(state ? PAGE_SAVE : PAGE_VIEW);
}

void SpellSourceSelector::UpdateButtonStates()
{
    if (_entryDB)
    {
        _buttonDB->setEnabled(true);
        _buttonDB->setDown(_currentSource == SOURCE_DB);
    }
    else
    {
        _buttonDB->setDown(false);
        _buttonDB->setEnabled(false);
    }

    if (_entryDBC)
    {
        _buttonDBC->setEnabled(true);
        _buttonDBC->setDown(_currentSource == SOURCE_DBC);
    }
    else
    {
        _buttonDBC->setDown(false);
        _buttonDBC->setEnabled(false);
    }
}
