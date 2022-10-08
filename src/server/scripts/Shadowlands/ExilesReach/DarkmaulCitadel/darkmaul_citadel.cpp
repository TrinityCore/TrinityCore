/*
 * Copyright 2021 ShadowCore
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

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "darkmaul_citadel.h"

const Position exile_reach_after_darkmaul_pos = { 722.804f, -1835.084f, 186.508f, 4.380f };

//npc_garrick_henry_161504
struct npc_garrick_henry_161504 : public ScriptedAI
{
    npc_garrick_henry_161504(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_AGGRESSIVE);
        events.ScheduleEvent(SPELL_HENRY_FLASH_HEAL, 5s);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void UpdateAI(const uint32 /*diff*/) override
    {
        /* prevent crashes if player loses bot ownership somehow -Varjgard */
        if (!me->GetOwner())
            me->ForcedDespawn();
    }

    void EnterCombat(Unit* victim) override
    {
        events.ScheduleEvent(SPELL_HENRY_POWER_WORD_SHIELD, 1s);
        events.ScheduleEvent(SPELL_HENRY_HOLY_SMITE, 3s);
        events.ScheduleEvent(SPELL_HENRY_FLASH_HEAL, 5s);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        // heal the amount of damage in here to make bots invincible
        me->SetHealth(me->GetHealth() + damage);
    }

    void ExecuteEvent(uint32 eventId)
    {
        switch (eventId)
        {
            case SPELL_HENRY_HOLY_SMITE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, false)) 
                    me->CastSpell(target, SPELL_HENRY_HOLY_SMITE, false);
                events.Repeat(2s);
                break;
            }

            case SPELL_HENRY_FLASH_HEAL:
            {
                if (Unit* player=me->GetOwner())
                {
                    if (player->IsAlive())
                    {
                        player->SetHealth(me->GetHealth() + 100);
                        me->CastSpell(player, SPELL_HENRY_FLASH_HEAL, false);
                    }
                }

                if (auto* garrick = me->FindNearestCreature(NPC_COMBAT_AI_GARRICK, 40.0f, true))
                {
                    me->CastSpell(garrick, SPELL_HENRY_FLASH_HEAL, false);
                    garrick->SetHealth(me->GetHealth() + 100);
                    me->SetHealth(me->GetHealth() + 50);
                }
                events.Repeat(6s);
                break;
            }

            case SPELL_HENRY_POWER_WORD_SHIELD:
            {
                if (Unit* player=me->GetOwner())
                    if (player->IsAlive())
                        me->CastSpell(player, SPELL_HENRY_POWER_WORD_SHIELD, false);

                if (auto* garrick = me->FindNearestCreature(NPC_COMBAT_AI_GARRICK, 40.0f, true))
                    me->CastSpell(garrick, SPELL_HENRY_POWER_WORD_SHIELD, true);
                events.Repeat(10s);
                break;
            }
        }
    }
};

//npc_captain_garrick_161350
struct npc_captain_garrick_161350 : public ScriptedAI
{
    npc_captain_garrick_161350(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void UpdateAI(const uint32 /*diff*/) override
    {
        /* prevent crashes if player loses bot ownership somehow -Varjgard */
        if (!me->GetOwner())
            me->ForcedDespawn();
    }

    /* dungeon-darkmaul-citadel q55992 */
    void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == 55992)
        {
           // instance->DoTeleportPlayers(MAP_NPE, exile_reach_after_darkmaul_pos);
        }
    }

    void EnterCombat(Unit* victim) override
    {
            events.ScheduleEvent(SPELL_GARRICK_CHARGE, 1s);
            events.ScheduleEvent(SPELL_GARRICK_SHIELD_SLAM, 3s);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        // heal the amount of damage in here to make bots invincible
        me->SetHealth(me->GetHealth() + damage);
    }

    void ExecuteEvent(uint32 eventId)
    {
      //  switch (eventId)
        //{
            //case SPELL_GARRICK_CHARGE:
            //{
              //  if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 20.0f, false))
                //    me->CastSpell(target, SPELL_GARRICK_CHARGE, true);

               // events.Repeat(15s);
               // break;
       // }

            //case SPELL_GARRICK_SHIELD_SLAM:
            //{
            //    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 10.0f, false))
              //  {
                //    me->CastSpell(target, SPELL_GARRICK_SHIELD_SLAM, true);
                  //  std::list<Creature*> creTargets;
                   // me->GetCreatureListInGrid(creTargets, 25.0f);
                   // for (auto& targets : creTargets)
                   // {
                     //   if (Unit* player = me->GetOwner()) // this should never return false... but apparently it has happened (no owner) and caused a crash -Varjgard
                       //     if (!targets->IsFriendlyTo(player))
                     //       {
                         //       me->CastSpell(targets, SPELL_GARRICK_TAUNT, true);
          //                      me->AddThreat(targets, 1000.0f, SPELL_SCHOOL_MASK_HOLY);
                       //     }
                   // }
               // }
               // events.Repeat(20s);
               // break;
            //}
       // }
    }
};

//156828
struct npc_shadowy_orb : public ScriptedAI
{
    npc_shadowy_orb(Creature* creature) : ScriptedAI(creature) { }

private:
    uint8 firstCreatureGroup;
    GameObject* GetFirstDoor() { return me->FindNearestGameObject(GO_FIRST_DOOR, 100.0f); }

    void Reset() override
    {
        ScriptedAI::Reset();
        this->firstCreatureGroup = 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (Creature* firstwave = me->FindNearestCreature(NPC_DARKMAUL_SHADOWCALLER, 100.0f, false))
            firstCreatureGroup++;
        if (this->firstCreatureGroup == 2)
            GetFirstDoor()->SetGoState(GO_STATE_ACTIVE);
    }
};

void AddSC_darkmaul_citadel()
{
    RegisterCreatureAI(npc_garrick_henry_161504);
    RegisterCreatureAI(npc_captain_garrick_161350);
    RegisterCreatureAI(npc_shadowy_orb);
};
