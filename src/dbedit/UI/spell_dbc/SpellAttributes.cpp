#include "SpellAttributes.h"
#include "DBCStructure.h"
#include "SmartEnum.h"
#include "QtHelpers.h"
#include "SharedDefines.h"
#include "SpellAttributesOverview.h"
#include "SpellAttributesPage.h"
#include <QLayout>
#include <QStackedWidget>

void SpellAttributes::Setup()
{
    FIND_Q_CHILD_DELAYED(_pageSelector);
    FIND_Q_CHILD_DELAYED(_overview);
    CONNECT(_overview, PageHeaderClicked, _pageSelector, setCurrentIndex);
    _page0 = new SpellAttributesPage<SpellAttr0>();
    _page1 = new SpellAttributesPage<SpellAttr1>();
    _page2 = new SpellAttributesPage<SpellAttr2>();
    _page3 = new SpellAttributesPage<SpellAttr3>();
    _page4 = new SpellAttributesPage<SpellAttr4>();
    _page5 = new SpellAttributesPage<SpellAttr5>();
    _page6 = new SpellAttributesPage<SpellAttr6>();
    _page7 = new SpellAttributesPage<SpellAttr7>();
    _pageSelector->addWidget(_page0);
    _pageSelector->addWidget(_page1);
    _pageSelector->addWidget(_page2);
    _pageSelector->addWidget(_page3);
    _pageSelector->addWidget(_page4);
    _pageSelector->addWidget(_page5);
    _pageSelector->addWidget(_page6);
    _pageSelector->addWidget(_page7);
    CONNECT(_page0, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page1, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page2, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page3, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page4, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page5, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page6, ReturnClicked, this, RedrawOverviewPage);
    CONNECT(_page7, ReturnClicked, this, RedrawOverviewPage);
    CONNECT_SAME(_page0, this, ValueChanged);
    CONNECT_SAME(_page1, this, ValueChanged);
    CONNECT_SAME(_page2, this, ValueChanged);
    CONNECT_SAME(_page3, this, ValueChanged);
    CONNECT_SAME(_page4, this, ValueChanged);
    CONNECT_SAME(_page5, this, ValueChanged);
    CONNECT_SAME(_page6, this, ValueChanged);
    CONNECT_SAME(_page7, this, ValueChanged);
    CONNECT(_page1, ValueChanged, this, Attr1Changed);
}

void SpellAttributes::Attr1Changed()
{
    uint32 attr1 = _page1->GetValue();
    bool isChanneled = (attr1 & SPELL_ATTR1_CHANNELED_1) || (attr1 & SPELL_ATTR1_CHANNELED_2);
    Q_EMIT IsNowChanneled(isChanneled);
}

void SpellAttributes::RedrawOverviewPage()
{
    _overview->Update(_page0->GetValue(), _page1->GetValue(), _page2->GetValue(), _page3->GetValue(),
                      _page4->GetValue(), _page5->GetValue(), _page6->GetValue(), _page7->GetValue());
    _pageSelector->setCurrentIndex(0);
}

void SpellAttributes::SetEntry(SpellEntry const* entry)
{
    _pageSelector->setCurrentIndex(0);
    _page0->SetValue(entry->Attributes);
    _page1->SetValue(entry->AttributesEx);
    _page2->SetValue(entry->AttributesEx2);
    _page3->SetValue(entry->AttributesEx3);
    _page4->SetValue(entry->AttributesEx4);
    _page5->SetValue(entry->AttributesEx5);
    _page6->SetValue(entry->AttributesEx6);
    _page7->SetValue(entry->AttributesEx7);
    RedrawOverviewPage();
    Attr1Changed();
}

void SpellAttributes::BuildEntry(SpellEntry& entry) const
{
    entry.Attributes = _page0->GetValue();
    entry.AttributesEx = _page1->GetValue();
    entry.AttributesEx2 = _page2->GetValue();
    entry.AttributesEx3 = _page3->GetValue();
    entry.AttributesEx4 = _page4->GetValue();
    entry.AttributesEx5 = _page5->GetValue();
    entry.AttributesEx6 = _page6->GetValue();
    entry.AttributesEx7 = _page7->GetValue();
}
