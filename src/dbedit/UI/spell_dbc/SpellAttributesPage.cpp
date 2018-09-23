#include "SpellAttributesPage.h"
#include "DBCStructure.h"

SpellAttributesPageBase::SpellAttributesPageBase(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
}

