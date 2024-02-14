/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _CharmInfo_h__
#define _CharmInfo_h__

#include "Define.h"
#include "UnitDefines.h"

class SpellInfo;
class Unit;
class WorldPacket;

constexpr uint8 MAX_SPELL_CHARM         = 4;
constexpr uint8 MAX_SPELL_VEHICLE       = 6;
constexpr uint8 MAX_SPELL_POSSESS       = 8;
constexpr uint8 MAX_SPELL_CONTROL_BAR   = 10;

#define UNIT_ACTION_BUTTON_ACTION(X) (uint32(X) & 0x007FFFFF)
#define UNIT_ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 23)
#define MAKE_UNIT_ACTION_BUTTON(A, T) (uint32(A) | (uint32(T) << 23))

struct UnitActionBarEntry
{
    UnitActionBarEntry() : packedData(uint32(ACT_DISABLED) << 24) { }

    uint32 packedData;

    // helper
    ActiveStates GetType() const { return ActiveStates(UNIT_ACTION_BUTTON_TYPE(packedData)); }
    uint32 GetAction() const { return UNIT_ACTION_BUTTON_ACTION(packedData); }
    bool IsActionBarForSpell() const
    {
        ActiveStates Type = GetType();
        return Type == ACT_DISABLED || Type == ACT_ENABLED || Type == ACT_PASSIVE;
    }

    void SetActionAndType(uint32 action, ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(action, type);
    }

    void SetType(ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(UNIT_ACTION_BUTTON_ACTION(packedData), type);
    }

    void SetAction(uint32 action)
    {
        packedData = (packedData & 0xFF000000) | UNIT_ACTION_BUTTON_ACTION(action);
    }
};

enum CharmType : uint8
{
    CHARM_TYPE_CHARM = 0,
    CHARM_TYPE_POSSESS,
    CHARM_TYPE_VEHICLE,
    CHARM_TYPE_CONVERT
};

typedef UnitActionBarEntry CharmSpellInfo;

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START              = 0,
    ACTION_BAR_INDEX_PET_SPELL_START    = 3,
    ACTION_BAR_INDEX_PET_SPELL_END      = 7,
    ACTION_BAR_INDEX_END                = 10
};

#define MAX_UNIT_ACTION_BAR_INDEX (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START)

struct TC_GAME_API CharmInfo
{
    public:
        explicit CharmInfo(Unit* unit);
        ~CharmInfo();
        void RestoreState();
        uint32 GetPetNumber() const { return _petnumber; }
        void SetPetNumber(uint32 petnumber, bool statwindow);

        void SetCommandState(CommandStates st) { _CommandState = st; }
        CommandStates GetCommandState() const { return _CommandState; }
        bool HasCommandState(CommandStates state) const { return (_CommandState == state); }

        void InitPossessCreateSpells();
        void InitCharmCreateSpells();
        void InitPetActionBar();
        void InitEmptyActionBar(bool withAttack = true);

                                                            //return true if successful
        bool AddSpellToActionBar(SpellInfo const* spellInfo, ActiveStates newstate = ACT_DECIDE, uint8 preferredSlot = 0);
        bool RemoveSpellFromActionBar(uint32 spell_id);
        void LoadPetActionBar(const std::string& data);
        void BuildActionBar(WorldPacket* data);
        void SetSpellAutocast(SpellInfo const* spellInfo, bool state);
        void SetActionBar(uint8 index, uint32 spellOrAction, ActiveStates type)
        {
            PetActionBar[index].SetActionAndType(spellOrAction, type);
        }

        UnitActionBarEntry const* GetActionBarEntry(uint8 index) const { return &(PetActionBar[index]); }

        void ToggleCreatureAutocast(SpellInfo const* spellInfo, bool apply);

        CharmSpellInfo* GetCharmSpell(uint8 index) { return &(_charmspells[index]); }

        void SetIsCommandAttack(bool val);
        bool IsCommandAttack();
        void SetIsCommandFollow(bool val);
        bool IsCommandFollow();
        void SetIsAtStay(bool val);
        bool IsAtStay();
        void SetIsFollowing(bool val);
        bool IsFollowing();
        void SetIsReturning(bool val);
        bool IsReturning();
        void SaveStayPosition();
        void GetStayPosition(float &x, float &y, float &z);

    private:

        Unit* _unit;
        UnitActionBarEntry PetActionBar[MAX_UNIT_ACTION_BAR_INDEX];
        CharmSpellInfo _charmspells[4];
        CommandStates _CommandState;
        uint32 _petnumber;

        //for restoration after charmed
        ReactStates _oldReactState;

        bool _isCommandAttack;
        bool _isCommandFollow;
        bool _isAtStay;
        bool _isFollowing;
        bool _isReturning;
        float _stayX;
        float _stayY;
        float _stayZ;
};

#endif // _CharmInfo_h__
