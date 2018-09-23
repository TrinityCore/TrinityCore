#ifndef TRINITY_DBEDIT_SPELLATTRIBUTESOVERVIEW_H
#define TRINITY_DBEDIT_SPELLATTRIBUTESOVERVIEW_H

#include "Define.h"
#include <QLabel>
#include <QWidget>
#include <vector>

class ClickableLabel;
struct SpellEntry;
enum SpellAttr0 : uint32;
enum SpellAttr1 : uint32;
enum SpellAttr2 : uint32;
enum SpellAttr3 : uint32;
enum SpellAttr4 : uint32;
enum SpellAttr5 : uint32;
enum SpellAttr6 : uint32;
enum SpellAttr7 : uint32;

class SpellAttributesOverview : public QWidget
{
    Q_OBJECT

    public:
        SpellAttributesOverview(QWidget* parent = nullptr);
        void Update(SpellAttr0, SpellAttr1, SpellAttr2, SpellAttr3, SpellAttr4, SpellAttr5, SpellAttr6, SpellAttr7);

    Q_SIGNALS:
        void PageHeaderClicked(int);

    private:
        ClickableLabel* AddNewChild(std::string const& label, int32 x, int32 y);
        template <typename E>
        void AddChildrenFor(int32 index, char const* label, E value);
        std::vector<ClickableLabel*> _children;
};

#endif
