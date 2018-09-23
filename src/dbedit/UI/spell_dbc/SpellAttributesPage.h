#ifndef TRINITY_DBEDIT_SPELLATTRIBUTESPAGE_H
#define TRINITY_DBEDIT_SPELLATTRIBUTESPAGE_H

#include "ClickableLabel.h"
#include "Define.h"
#include "SmartEnum.h"
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <type_traits>
#include <unordered_map>

class SpellAttributesPageBase : public QWidget
{
    Q_OBJECT

    public:
        SpellAttributesPageBase(QWidget* parent);

    Q_SIGNALS:
        void ReturnClicked();
        void ValueChanged();
};

template <typename E>
class SpellAttributesPage : public SpellAttributesPageBase
{
    public:
        SpellAttributesPage(QWidget* parent = nullptr) : SpellAttributesPageBase(parent)
        {
            QLayout* layout = this->layout();

            ClickableLabel* label = new ClickableLabel("<- Back", this);
            QFont font = label->font();
            font.setBold(true);
            font.setUnderline(true);
            label->setFont(font);
            layout->addWidget(label);
            CONNECT(label, Clicked, this, ReturnClicked);

            for (E attr : EnumUtils<E>::Iterate())
            {
                QCheckBox* box = new QCheckBox(this);
                _checkboxes.emplace(box, attr);
                CONNECT(box, stateChanged, this, ValueChanged);
                EnumText text = EnumUtils<E>::ToString(attr);
                box->setText(text.Title);
                box->setToolTip(text.Description);
                layout->addWidget(box);
            }
        }

        void SetValue(uint32 value)
        {
            for (auto pair : _checkboxes)
                pair.first->setChecked(pair.second & value);
        }

        E GetValue() const
        {
            std::underlying_type_t<E> v = 0;
            for (auto pair : _checkboxes)
                if (pair.first->isChecked())
                    v |= pair.second;
            return static_cast<E>(v);
        }

    private:
        std::unordered_map<QCheckBox*, E> _checkboxes;
};

#endif
