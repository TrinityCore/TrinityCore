#ifndef TRINITY_DBEDIT_SPELLSOURCESELECTOR_H
#define TRINITY_DBEDIT_SPELLSOURCESELECTOR_H

#include "Define.h"
#include <QGroupBox>

struct SpellEntry;
class QPushButton;
class QStackedWidget;

class SpellSourceSelector : public QGroupBox
{
    enum Sources
    {
        SOURCE_NONE,
        SOURCE_DBC,
        SOURCE_DB
    };

    enum Pages
    {
        PAGE_VIEW = 0,
        PAGE_SAVE = 1
    };

    Q_OBJECT

    public:
        SpellSourceSelector(QWidget* parent = nullptr) : QGroupBox(parent) {}
        void Setup();
        void UpdateForSpell(uint32 spellId);

        Sources GetCurrentSource() const { return _currentSource; }
        SpellEntry const* GetCurrentSpellEntry() const;

    Q_SIGNALS:
        void NeedSave();
        void NeedRedraw();

    public Q_SLOTS:
        void SwitchToDB();
        void SwitchToDBC();
        void SetHavePendingChanges(bool);

    private:
        void UpdateButtonStates();

        QStackedWidget* _sourcePageSelector = nullptr;
        QPushButton*    _buttonDB = nullptr;
        QPushButton*    _buttonDBC = nullptr;

        QPushButton*    _buttonSave = nullptr;
        QPushButton*    _buttonDiscard = nullptr;

        Sources             _currentSource = SOURCE_NONE;
        SpellEntry const*   _entryDB = nullptr;
        SpellEntry const*   _entryDBC = nullptr;
};

#endif
