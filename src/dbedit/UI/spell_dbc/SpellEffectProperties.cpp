#include "SpellEffectProperties.h"
#include "DBCStructure.h"
#include "QtHelpers.h"
#include "SharedDefines.h"
#include "SmartEnum.h"
#include "SpellEffectsWidget.h"
#include <QBoxLayout>
#include <QStyleOptionGroupBox>
#include <QStylePainter>
#include <QTabWidget>

SpellEffectProperties::SpellEffectProperties(QWidget* parent)
    : SpellDataElement(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    _tab = new QTabWidget(this);
    for (SpellEffIndex i : EnumUtils::Iterate<SpellEffIndex>())
    {
        _children[i] = new SpellEffectsWidget(_tab, i);
        _tab->addTab(_children[i], EnumUtils::ToTitle(i));
    }
    layout->addWidget(_tab);
}

void SpellEffectProperties::Setup()
{

}

void SpellEffectProperties::SetEntry(SpellEntry const* entry)
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        _children[i]->SetEntry(entry);
}

void SpellEffectProperties::BuildEntry(SpellEntry& entry) const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        _children[i]->BuildEntry(entry);
}

void SpellEffectProperties::paintEvent(QPaintEvent*)
{
    QGroupBox::paintEvent(nullptr);
    QStylePainter paint(this);
    QStyleOptionGroupBox option;
    initStyleOption(&option);
    option.features = QStyleOptionFrame::None;
    paint.drawComplexControl(QStyle::CC_GroupBox, option);
}
