#include "SpellProperties.h"
#include "DBCStructure.h"
#include "Log.h"
#include "QtHelpers.h"
#include "SearchableDropdown.h"
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QStackedWidget>

QCheckBox* SelectorBase::MakeBox(uint32 value, char const* title)
{
    QCheckBox* box = new QCheckBox(this);
    _checkboxes.emplace(box, value);
    box->setText(title);
    CONNECT(box, stateChanged, this, ValueChanged);
    return box;
}

void SelectorBase::SetMask(uint32 mask)
{
    for (auto pair : _checkboxes)
        pair.first->setChecked(pair.second & mask);
}

uint32 SelectorBase::GetMask() const
{
    uint32 v = 0;
    for (auto pair : _checkboxes)
        if (pair.first->isChecked())
            v |= pair.second;
    return v;
}

SpellSchoolSelector::SpellSchoolSelector(QWidget* parent) : SelectorBase(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignTop);
    for (SpellSchools v : EnumUtils::Iterate<SpellSchools>())
    {
        QCheckBox* box = MakeBox(1 << v, EnumUtils::ToTitle(v));
        layout->addWidget(box, (v + 1) / 2, (v ? 1 - (v % 2) : 0), 1, (v ? 1 : 2), Qt::AlignLeft);
    }
}

CastInterruptSelector::CastInterruptSelector(QWidget* parent) : SelectorBase(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignTop);
    uint32 i = 0;
    for (SpellInterruptFlags v : EnumUtils::Iterate<SpellInterruptFlags>())
    {
        QCheckBox* box = MakeBox(v, EnumUtils::ToTitle(v));
        layout->addWidget(box, i/2, i%2, Qt::AlignLeft);
        ++i;
    }
}

ChannelInterruptSelector::ChannelInterruptSelector(QWidget* parent) : SelectorBase(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignTop);
    uint32 i = 0;
    for (SpellChannelInterruptFlags v : EnumUtils::Iterate<SpellChannelInterruptFlags>())
    {
        QCheckBox* box = MakeBox(v, EnumUtils::ToTitle(v));
        layout->addWidget(box, i/2, i%2, Qt::AlignLeft);
        ++i;
    }
}


void SpellProperties::Setup()
{
    FIND_Q_CHILD_DELAYED(_damageClass);
    FIND_Q_CHILD_DELAYED(_preventionType);

    FIND_Q_CHILD_DELAYED(_powerType);
    FIND_Q_CHILD_DELAYED(_powerTypeSub);
    FIND_Q_CHILD_DELAYED(_manaCost);
    FIND_Q_CHILD_DELAYED(_manaCostPctPrefix);
    FIND_Q_CHILD_DELAYED(_manaCostPercentage);
    FIND_Q_CHILD_DELAYED(_manaCostPctSuffix);
    FIND_Q_CHILD_DELAYED(_runeCost);
    FIND_Q_CHILD_DELAYED(_upkeepLabel);
    FIND_Q_CHILD_DELAYED(_upkeepWidget);
    FIND_Q_CHILD_DELAYED(_channelCost);
    FIND_Q_CHILD_DELAYED(_channelCostPerLevel);
    
    FIND_Q_CHILD_DELAYED(_castTime);
    FIND_Q_CHILD_DELAYED(_recoveryTime);
    FIND_Q_CHILD_DELAYED(_spellCategory);
    FIND_Q_CHILD_DELAYED(_categoryCooldown);
    FIND_Q_CHILD_DELAYED(_gcdCategory);
    FIND_Q_CHILD_DELAYED(_gcdDuration);

    FIND_Q_CHILD_DELAYED(_spellSchools);
    FIND_Q_CHILD_DELAYED(_interruptFlags);
    FIND_Q_CHILD_DELAYED(_channelInterruptFlags);
}

void SpellProperties::PowerTypeChanged()
{
    switch (_powerType->GetCurrentValue())
    {
        case POWER_RUNE:
            _powerTypeSub->setCurrentIndex(PAGE_RUNE);
            _upkeepLabel->hide();
            _upkeepWidget->hide();
            break;
        case POWER_RUNIC_POWER:
            _manaCostPctPrefix->hide();
            _manaCostPercentage->hide();
            _manaCostPctSuffix->hide();
            _upkeepLabel->hide();
            _upkeepWidget->hide();
            _powerTypeSub->setCurrentIndex(PAGE_REGULAR);
            break;
        default:
            _manaCostPctPrefix->show();
            _manaCostPercentage->show();
            _manaCostPctSuffix->show();
            if (_isChanneled)
            {
                _upkeepLabel->show();
                _upkeepWidget->show();
            }
            else
            {
                _upkeepLabel->hide();
                _upkeepWidget->hide();
            }
            _powerTypeSub->setCurrentIndex(PAGE_REGULAR);
            break;
    }
}

void SpellProperties::SetEntry(SpellEntry const* entry)
{
    _damageClass->SetCurrentKey(entry->DmgClass);
    _preventionType->SetCurrentKey(entry->PreventionType);

    _powerType->SetCurrentValue(Powers(entry->powerType));
    _manaCost->setValue(entry->manaCost);
    _manaCostPercentage->setValue(entry->ManaCostPercentage);
    _runeCost->SetCurrentKey(entry->runeCostID);
    _manaCostPerLevel = entry->manaCostPerlevel;
    _channelCost->setValue(entry->manaPerSecond);
    _channelCostPerLevel->setValue(entry->manaPerSecondPerLevel);
    PowerTypeChanged();
    CONNECT(_powerType, ValueChanged, this, PowerTypeChanged);
    CONNECT(_powerType, ValueChanged, this, ValueChanged);
    connect(_manaCost, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpellProperties::ValueChanged);
    connect(_manaCostPercentage, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpellProperties::ValueChanged);
    CONNECT(_runeCost, ValueChanged, this, ValueChanged);

    _castTime->SetCurrentKey(entry->CastingTimeIndex);
    _recoveryTime->setValue(double(entry->RecoveryTime) / 1000);
    _spellCategory->setValue(entry->Category);
    _categoryCooldown->setValue(double(entry->CategoryRecoveryTime) / 1000);
    _gcdCategory->setValue(entry->StartRecoveryCategory);
    _gcdDuration->setValue(double(entry->StartRecoveryTime) / 1000);

    _spellSchools->SetMask(entry->SchoolMask);
    _interruptFlags->SetMask(entry->InterruptFlags);
    _channelInterruptFlags->SetMask(entry->ChannelInterruptFlags);
}

void SpellProperties::BuildEntry(SpellEntry& entry) const
{
    entry.DmgClass = _damageClass->GetCurrentKey();
    entry.PreventionType = _preventionType->GetCurrentKey();

    entry.powerType = _powerType->GetCurrentValue();
    entry.manaCost = _manaCost->value();
    entry.ManaCostPercentage = _manaCostPercentage->value();
    entry.runeCostID = _runeCost->GetCurrentKey();
    entry.manaCostPerlevel = _manaCostPerLevel;
    entry.manaPerSecond = _channelCost->value();
    entry.manaPerSecondPerLevel = _channelCostPerLevel->value();

    entry.CastingTimeIndex = _castTime->GetCurrentKey();
    entry.RecoveryTime = uint32(_recoveryTime->value() * 1000);

    entry.Category = _spellCategory->value();
    entry.CategoryRecoveryTime = uint32(_categoryCooldown->value() * 1000);
    entry.StartRecoveryCategory = _gcdCategory->value();
    entry.StartRecoveryTime = uint32(_gcdDuration->value() * 1000);

    entry.SchoolMask = _spellSchools->GetMask();
    entry.InterruptFlags = _interruptFlags->GetMask();
    entry.ChannelInterruptFlags = _channelInterruptFlags->GetMask();
}

void SpellProperties::SetIsChanneled(bool state)
{
    _isChanneled = state;
    PowerTypeChanged();
    if (state)
        _channelInterruptFlags->show();
    else
        _channelInterruptFlags->hide();
}
