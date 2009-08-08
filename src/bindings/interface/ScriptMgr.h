/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SCRIPTMGR_H
#define SCRIPTMGR_H

//Only required includes
#include "../../game/CreatureAI.h"
#include "../../game/Creature.h"
#include "../../game/InstanceData.h"

class Player;
class Creature;
class Quest;
class Item;
class GameObject;
class SpellCastTargets;
class Map;

#define MAX_SCRIPTS 1000

struct Script
{
    Script() :
        pGossipHello(NULL), pQuestAccept(NULL), pGossipSelect(NULL), pGossipSelectWithCode(NULL), pGOSelect(NULL), pGOSelectWithCode(NULL),
        pQuestSelect(NULL), pQuestComplete(NULL), pNPCDialogStatus(NULL), pGODialogStatus(NULL), pChooseReward(NULL),
        pItemHello(NULL), pGOHello(NULL), pAreaTrigger(NULL), pItemQuestAccept(NULL), pGOQuestAccept(NULL),
        pGOChooseReward(NULL), pItemUse(NULL), pItemExpire(NULL), pEffectDummyCreature(NULL), pEffectDummyGameObj(NULL),
        pEffectDummyItem(NULL),  GetAI(NULL), GetInstanceData(NULL)
    {}

    std::string Name;

    //Methods to be scripted
    bool (*pGossipHello         )(Player*, Creature*);
    bool (*pQuestAccept         )(Player*, Creature*, Quest const* );
    bool (*pGossipSelect        )(Player*, Creature*, uint32 , uint32 );
    bool (*pGossipSelectWithCode)(Player*, Creature*, uint32 , uint32 , const char* );
    bool (*pGOSelect            )(Player*, GameObject*, uint32 , uint32 );
    bool (*pGOSelectWithCode    )(Player*, GameObject*, uint32 , uint32 , const char* );
    bool (*pQuestSelect         )(Player*, Creature*, Quest const* );
    bool (*pQuestComplete       )(Player*, Creature*, Quest const* );
    uint32 (*pNPCDialogStatus   )(Player*, Creature* );
    uint32 (*pGODialogStatus    )(Player*, GameObject* );
    bool (*pChooseReward        )(Player*, Creature*, Quest const*, uint32 );
    bool (*pItemHello           )(Player*, Item*, Quest const* );
    bool (*pGOHello             )(Player*, GameObject* );
    bool (*pAreaTrigger         )(Player*, AreaTriggerEntry* );
    bool (*pItemQuestAccept     )(Player*, Item *, Quest const* );
    bool (*pGOQuestAccept       )(Player*, GameObject*, Quest const* );
    bool (*pGOChooseReward      )(Player*, GameObject*, Quest const*, uint32 );
    bool (*pItemUse             )(Player*, Item*, SpellCastTargets const& );
    bool (*pItemExpire          )(Player*, ItemPrototype const*);
    bool (*pEffectDummyCreature )(Unit*, uint32, uint32, Creature* );
    bool (*pEffectDummyGameObj  )(Unit*, uint32, uint32, GameObject* );
    bool (*pEffectDummyItem     )(Unit*, uint32, uint32, Item* );

    CreatureAI* (*GetAI)(Creature*);
    InstanceData* (*GetInstanceData)(Map*);

    void RegisterSelf();
};

class InstanceDataScript
{
    public:
        InstanceDataScript() : GetInstanceData(NULL) {};

        std::string name;
        InstanceData* (*GetInstanceData)(Map *_Map);
};

#define VISIBLE_RANGE (50.0f)

struct TRINITY_DLL_DECL ScriptedAI : public CreatureAI
{
    ScriptedAI(Creature* creature):CreatureAI(creature),m_creature(creature){}
    ~ScriptedAI() {}

    // Called if IsVisible(Unit *who) is true at each *who move
    void MoveInLineOfSight(Unit *) {}

    // Called at each attack of m_creature by any victim
    void AttackStart(Unit *) {}

    // Called at stopping attack by any attacker
    void EnterEvadeMode();

    // Called at any heal cast/item used (call non implemented)
    void HealBy(Unit* /*healer*/, uint32 /*amount_healed*/) {}

    // Called at any Damage to any victim (before damage apply)
    void DamageDeal(Unit* /*done_to*/, uint32& /*damage*/) {}

    // Called at any Damage from any attacker (before damage apply)
    void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/) {}

    // Is unit visible for MoveInLineOfSight
    bool IsVisible(Unit* who) const
    {
        return !who->HasStealthAura() && m_creature->GetDistance(who) <= VISIBLE_RANGE;
    }

    // Called at World update tick
    void UpdateAI(const uint32);

    // Called when the creature is killed
    void JustDied(Unit *){}

    // Called when the creature kills a unit
    void KilledUnit(Unit *){}

    // Called when hit by a spell
    void SpellHit(Unit *, const SpellEntry*){}

    Creature* m_creature;

    //= Some useful helpers =========================

    // Start attack of victim and go to him
    void DoStartAttack(Unit* victim);

    // Stop attack of current victim
    void DoStopAttack();

    // Cast spell
    void DoCast(Unit* victim, uint32 spelId)
    {
        m_creature->CastSpell(victim,spelId,true);
    }

    void DoCastSpell(Unit* who,SpellEntry *spellInfo)
    {
        m_creature->CastSpell(who,spellInfo,true);
    }

    void DoSay(char const* text, uint32 language)
    {
        m_creature->MonsterSay(text,language,0);
    }

    void DoGoHome();
};

#endif

