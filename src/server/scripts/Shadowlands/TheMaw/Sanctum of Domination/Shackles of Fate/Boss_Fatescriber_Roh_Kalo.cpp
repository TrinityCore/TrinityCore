/*
* Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuras.h"
//#include "zone_the_maw"
#include "zone_Sanctum_of_Domination.h"
//#include "Sanctum_of_Domination.h"

enum Creatures
{
    NPC_Shade_of_Destiny        = 179124,
    NPC_Fatespawn_Monstrosity   = 180323,
};

enum Spells
{
    //phase 1
    SPELL_Fated_Conjunction = 350355,
    SPELL_Call_of_Eternity = 350819,
    SPELL_Fate_Fragment = 353162,
    SPELL_Invoke_Destiny = 351680,
    SPELL_Diviners_Probe = 353603,
    SPELL_Despair = 357144,
    //phase 2
    SPELL_Runic_Affinity = 354964,
    SPELL_Darkest_Destiny = 353122,
    SPELL_Monstrositys_Boon = 357141,
    SPELL_Anomalous_Blast = 353398,
    //phase 3
    SPELL_Echo_of_Eternity = 350826,
};

enum Loot
{
    Arcane_Prodigy = 181509,
    Brutal_Projectiles = 182649,
    Demonic_Momentum = 182470,
    Felfire_Haste = 182324,
    Front_of_the_Pack = 183469,
    Resolute_Defender = 182684,
    Sleight_of_Hand = 183509,
    Swift_Penitence = 181867,
    Swift_Transference = 181624,
    Thunderous_Paws = 182108,
    Binding_of_Dark_Destinies = 186352,
    Carved Ivory Keepsake = 186435,
    Conjunction-Forged_Chainmail = 186340,
    Cowl_of_Haunting_Precognition = 186330,
    Demigaunts_of_Predestination = 186345,
    Diviners_Draped_Finery = 186320,
    Fate-Threaded_Bindings = 186335,
    Fateforged_Legplates = 186348,
    Gloves_of_Forsaken_Purpose = 186326,
    Oscillating_Ouroboros = 186376,
    Record_of_Collapsing_Realities = 186419,
    Weave_of_Warped_Fates = 186434,
}

struct NPC_Shade_of_Destiny : public CreatureAI
{
    NPC_Shade_of_Destiny(Creature* creature) : CreatureData (DATA_NPC_Shade_of_Destiny) { }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(SPELL_Diviners_Probe, 1.5s);
        void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id 353603)
        {
        case SPELL_:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_, true);
            }
            break;
        }

        //case SPELL_:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_, true);
                    at->Remove();
                }
            }
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                if (targets->GetPositionZ() < -45.0f && !targets->HasAura(SPELL_))
                    me->CastSpell(targets, SPELL_, true);
            }
            break;
        }
        }    
    }
    }
};

//179390
struct Boss_Fatescribe_Roh_Kalo_179390 : public BossAI
{
    Boss_Fatescribe_Roh_Kalo_179390(Creature* creature) : BossAI(creature, DATA_FATESCRIBE_ROH_KALO_179390) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(SPELL_, 0s);
        events.ScheduleEvent(SPELL_, 0s);
        events.ScheduleEvent(SPELL_, 0s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_, true);
            }
            break;
        }

        //case SPELL_:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_, true);
                    at->Remove();
                }
            }
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                if (targets->GetPositionZ() < -45.0f && !targets->HasAura(SPELL_))
                    me->CastSpell(targets, SPELL_, true);
            }
            break;
        }
        }    
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_:
            me->CastSpell(nullptr, SPELL_, true);
            events.Repeat(20s, 25s); 
            break;

        //case SPELL_:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
            {
                me->CastSpell(target, SPELL_, true);
                me->AddAura(SPELL_, target);
            }
            events.Repeat(0s);
            break;

        //case SPELL_1:
            me->CastSpell(nullptr, SPELL_, false);
            events.Repeat(0s);
            break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    }
};

void AddSC_Boss_Fatescriber_Roh_Kalo();
{
    AddSC_Boss_Fatescriber_Roh_Kalo();
}

//57.4 70.2
