#ifndef TRINITY_DBEDIT_SEARCHABLEDROPDOWN_H
#define TRINITY_DBEDIT_SEARCHABLEDROPDOWN_H

#include "SearchableDropdownDecl.h"
#include "advstd.h"
#include "DBCStructure.h"
#include "FuzzyFind.h"
#include "Optional.h"
#include "SearchTraits.h"
#include "SharedDefines.h"
#include <QLabel>
#include <QListWidget>
#include <vector>

class QLineEdit;

class SearchableDropdownBase : public QLabel
{
    Q_OBJECT

    public:
        // destructive on the passed array - pointers point into that array, be aware of lifetime concerns!
        static void Tokenize(QByteArray& raw, std::vector<LabeledSearchTag>& needles);

        bool IsDropdownShown() const;
        void ShowDropdown();
        void HideDropdown();

    protected:
        SearchableDropdownBase(QWidget* parent);
        void moveEvent(QMoveEvent*) override;
        void resizeEvent(QResizeEvent*) override;
        void mouseReleaseEvent(QMouseEvent*) override;
        bool eventFilter(QObject*, QEvent*) override;

        void SetValueText(QString const& str);
        void ClearResults() { _searchResults->clear(); }
        void AddMessage(QString const& str);
        void AddResult(QListWidgetItem* item);

        virtual void ShowSearchResults(std::vector<LabeledSearchTag> const& needles) = 0;

    protected Q_SLOTS:
        void ConfirmSelectionOrSearch();
        void ClearSelection();
        void SelectPreviousResult();
        void SelectNextResult();
        virtual void SelectResult(QListWidgetItem* item) = 0;

    Q_SIGNALS:
        void ValueChanged();

    private:
        void DoSearch();
        QWidget*        _dropdownContainer;
        QLineEdit*      _searchBox;
        QListWidget*    _searchResults;
};

template <typename ValueType, typename Traits>
class SearchableDropdown : public SearchableDropdownBase
{
    using KeyType = typename Traits::KeyType;

    class SearchableDropdownItem : public QListWidgetItem
    {
        public:
            SearchableDropdownItem(ValueType v) : QListWidgetItem(QString::fromStdString(Traits::GetTitle(v))), _val(v) {}
            ValueType GetValue() const { return _val; }

        private:
            ValueType const _val;
    };

    public:
        SearchableDropdown(QWidget* parent) : SearchableDropdownBase(parent) {}
        void SetCurrentValue(ValueType v)
        {
            _value = v;
            SetValueText(QString::fromStdString(Traits::GetTitle(v)));
        }
        void SetCurrentKey(KeyType k) { return SetCurrentValue(Traits::FromKey(k)); }
        KeyType GetCurrentKey() const { return Traits::ToKey(_value); }
        ValueType GetCurrentValue() const { return _value; }

    protected:
        void ShowSearchResults(std::vector<LabeledSearchTag> const& needles) override
        {
            if (needles.empty())
            {
                AddResult(new SearchableDropdownItem(_value));
                for (auto v : Traits::Iterate())
                    if (v != _value)
                        AddResult(new SearchableDropdownItem(v));
            }
            else
            {
                auto results = Trinity::Containers::FuzzyFindIn(Traits::Iterate(), needles, MatchesLabel<ValueType>);
                if (results.empty())
                {
                    AddMessage("No results found.");
                    return;
                }

                AddResult(new SearchableDropdownItem(_value));

                for (auto it = results.begin(), end = results.end(); it != end; ++it)
                    if (it->second != _value)
                        AddResult(new SearchableDropdownItem(it->second));
            }
        }

        void SelectResult(QListWidgetItem* item) override
        {
            SetCurrentValue(static_cast<SearchableDropdownItem*>(item)->GetValue());
            Q_EMIT ValueChanged();
        }

    private:
        ValueType _value;
};

#endif
