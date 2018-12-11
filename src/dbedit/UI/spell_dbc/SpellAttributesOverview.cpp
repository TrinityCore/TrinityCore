#include "SpellAttributesOverview.h"
#include "ClickableLabel.h"
#include "DBCStructure.h"
#include "SmartEnum.h"
#include "Errors.h"
#include "SharedDefines.h"
#include "StringFormat.h"
#include <QVBoxLayout>

SpellAttributesOverview::SpellAttributesOverview(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
}

static constexpr int MARGIN_X = 5;
static constexpr int MARGIN_Y = 0;
static constexpr int HEADER_X = 5;
static constexpr int PADDING_Y_HEADER = 5;
static constexpr int ENTRY_X = 15;
static constexpr int PADDING_Y_ENTRY = 0;

ClickableLabel* SpellAttributesOverview::AddNewChild(std::string const& label, int32 x, int32 y)
{
    ClickableLabel* l = new ClickableLabel(QString::fromStdString(label));
    l->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
    this->layout()->addWidget(l);
    l->setContentsMargins(x, y, MARGIN_X, 0);
    _children.push_back(l);
    return l;
}

template <typename E>
void SpellAttributesOverview::AddChildrenFor(int32 index, char const* label, E value)
{
    ClickableLabel* header = AddNewChild(Trinity::StringFormat("%s: 0x%08X", label, value), HEADER_X, PADDING_Y_HEADER);
    QFont font = header->font();
    font.setBold(true);
    font.setUnderline(true);
    header->setFont(font);
    connect(header, &ClickableLabel::Clicked, this, [this, index]() { Q_EMIT PageHeaderClicked(index); });


    for (E attr : EnumUtils::Iterate<E>())
    {
        if (!(value & attr))
            continue;
        ClickableLabel* entry = AddNewChild(EnumUtils::ToTitle(attr), ENTRY_X, PADDING_Y_ENTRY);
        QFont font = entry->font();
        font.setBold(false);
        font.setUnderline(false);
        entry->setFont(font);
    }
}

void SpellAttributesOverview::Update(SpellAttr0 attr0, SpellAttr1 attr1, SpellAttr2 attr2, SpellAttr3 attr3,
                                     SpellAttr4 attr4, SpellAttr5 attr5, SpellAttr6 attr6, SpellAttr7 attr7)
{
    for (QWidget* child : _children)
    {
        this->layout()->removeWidget(child);
        delete child;
    }
    _children.clear();

    AddChildrenFor<SpellAttr0>(1, "Attributes",    attr0);
    AddChildrenFor<SpellAttr1>(2, "AttributesEx",  attr1);
    AddChildrenFor<SpellAttr2>(3, "AttributesEx2", attr2);
    AddChildrenFor<SpellAttr3>(4, "AttributesEx3", attr3);
    AddChildrenFor<SpellAttr4>(5, "AttributesEx4", attr4);
    AddChildrenFor<SpellAttr5>(6, "AttributesEx5", attr5);
    AddChildrenFor<SpellAttr6>(7, "AttributesEx6", attr6);
    AddChildrenFor<SpellAttr7>(8, "AttributesEx7", attr7);
}
