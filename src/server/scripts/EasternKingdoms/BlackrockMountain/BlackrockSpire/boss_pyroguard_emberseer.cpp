/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "blackrock_spire.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Text
{
    EMOTE_ONE_STACK                 = 0,
    EMOTE_TEN_STACK                 = 1,
    EMOTE_FREE_OF_BONDS             = 2,
    YELL_FREE_OF_BONDS              = 3
};

enum Spells
{
    SPELL_ENCAGED_EMBERSEER         = 15282, // Self on spawn
    SPELL_FIRE_SHIELD_TRIGGER       = 13377, // Self on spawn missing from 335 dbc triggers SPELL_FIRE_SHIELD every 3 sec
    SPELL_FIRE_SHIELD               = 13376, // Triggered by SPELL_FIRE_SHIELD_TRIGGER
    SPELL_FREEZE_ANIM               = 16245, // Self on event start
    SPELL_EMBERSEER_GROWING         = 16048, // Self on event start
    SPELL_EMBERSEER_GROWING_TRIGGER = 16049, // Triggered by SPELL_EMBERSEER_GROWING
    SPELL_EMBERSEER_FULL_STRENGTH   = 16047, // Emberseer Full Strength
    SPELL_FIRENOVA                  = 23462, // Combat
    SPELL_FLAMEBUFFET               = 23341, // Combat
    SPELL_PYROBLAST                 = 17274, // Combat
    // Blackhand Incarcerator Spells
    SPELL_ENCAGE_EMBERSEER          = 15281, // Emberseer on spawn
    SPELL_STRIKE                    = 15580, // Combat
    SPELL_ENCAGE                    = 16045, // Combat
    // Cast on player by altar
    SPELL_EMBERSEER_OBJECT_VISUAL   = 16532
};

enum Events
{
    // Respawn
    EVENT_RESPAWN                   = 1,
    // Pre fight
    EVENT_PRE_FIGHT_1               = 2,
    EVENT_PRE_FIGHT_2               = 3,
    // Combat
    EVENT_FIRENOVA                  = 4,
    EVENT_FLAMEBUFFET               = 5,
    EVENT_PYROBLAST                 = 6,
    // Hack due to trigger spell not in dbc
    EVENT_FIRE_SHIELD               = 7,
    // Make sure all players have aura from altar
    EVENT_PLAYER_CHECK              = 8,
    EVENT_ENTER_COMBAT              = 9
};

class boss_pyroguard_emberseer : public CreatureScript
{
public:
    boss_pyroguard_emberseer() : CreatureScript("boss_pyroguard_emberseer") { }

    struct boss_pyroguard_emberseerAI : public BossAI
    {
        boss_pyroguard_emberseerAI(Creature* creature) : BossAI(creature, DATA_PYROGAURD_EMBERSEER) { }

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetImmuneToPC(true);
            events.Reset();
            // Apply auras on spawn and reset
            // DoCast(me, SPELL_FIRE_SHIELD_TRIGGER); // Need to find this in old DBC if possible
            me->RemoveAura(SPELL_EMBERSEER_FULL_STRENGTH);
            me->RemoveAura(SPELL_EMBERSEER_GROWING);
            me->RemoveAura(SPELL_EMBERSEER_GROWING_TRIGGER);
            events.ScheduleEvent(EVENT_RESPAWN, 5s);
            // Hack for missing trigger spell
            events.ScheduleEvent(EVENT_FIRE_SHIELD, 3s);

            // Open doors on reset
            if (instance->GetBossState(DATA_PYROGAURD_EMBERSEER) == IN_PROGRESS)
                OpenDoors(false); // Opens 2 entrance doors
        }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            switch (data)
            {
                case 1:
                    events.ScheduleEvent(EVENT_PLAYER_CHECK, 5s);
                    break;
                case 2:
                   // Close these two doors on Blackhand Incarcerators aggro
                   if (GameObject* door1 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_IN)))
                       if (door1->GetGoState() == GO_STATE_ACTIVE)
                           door1->SetGoState(GO_STATE_READY);
                   if (GameObject* door2 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_DOORS)))
                       if (door2->GetGoState() == GO_STATE_ACTIVE)
                           door2->SetGoState(GO_STATE_READY);
                    break;
                case 3:
                    Reset();
                    break;
                default:
                    break;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            // ### TODO Check combat timing ###
            events.ScheduleEvent(EVENT_FIRENOVA,    6000);
            events.ScheduleEvent(EVENT_FLAMEBUFFET, 3s);
            events.ScheduleEvent(EVENT_PYROBLAST,  14000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            // Activate all the runes
            UpdateRunes(GO_STATE_READY);
            // Opens all 3 doors
            OpenDoors(true);
            // Complete encounter
            instance->SetBossState(DATA_PYROGAURD_EMBERSEER, DONE);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_ENCAGE_EMBERSEER)
            {
                if (!me->GetAuraCount(SPELL_ENCAGED_EMBERSEER))
                    me->CastSpell(me, SPELL_ENCAGED_EMBERSEER);
            }

            if (spell->Id == SPELL_EMBERSEER_GROWING_TRIGGER)
            {
                if (me->GetAuraCount(SPELL_EMBERSEER_GROWING_TRIGGER) == 10)
                    Talk(EMOTE_TEN_STACK);

                if (me->GetAuraCount(SPELL_EMBERSEER_GROWING_TRIGGER) == 20)
                {
                    me->RemoveAura(SPELL_ENCAGED_EMBERSEER);
                    me->RemoveAura(SPELL_FREEZE_ANIM);
                    me->CastSpell(me, SPELL_EMBERSEER_FULL_STRENGTH);
                    Talk(EMOTE_FREE_OF_BONDS);
                    Talk(YELL_FREE_OF_BONDS);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetImmuneToPC(false);
                    events.ScheduleEvent(EVENT_ENTER_COMBAT, 2s);
                }
            }
        }

       void OpenDoors(bool Boss_Killed)
       {
           // These two doors reopen on reset or boss kill
           if (GameObject* door1 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_IN)))
               door1->SetGoState(GO_STATE_ACTIVE);
           if (GameObject* door2 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_DOORS)))
               door2->SetGoState(GO_STATE_ACTIVE);

           // This door opens on boss kill
           if (Boss_Killed)
               if (GameObject* door3 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_OUT)))
                    door3->SetGoState(GO_STATE_ACTIVE);
       }

        void UpdateRunes(GOState state)
        {
            // update all runes
            if (GameObject* rune1 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_1)))
                rune1->SetGoState(state);
            if (GameObject* rune2 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_2)))
                rune2->SetGoState(state);
            if (GameObject* rune3 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_3)))
                rune3->SetGoState(state);
            if (GameObject* rune4 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_4)))
                rune4->SetGoState(state);
            if (GameObject* rune5 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_5)))
                rune5->SetGoState(state);
            if (GameObject* rune6 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_6)))
                rune6->SetGoState(state);
            if (GameObject* rune7 = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_EMBERSEER_RUNE_7)))
                rune7->SetGoState(state);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESPAWN:
                        {
                            // Respawn all Blackhand Incarcerators
                            std::list<Creature*> creatureList;
                            GetCreatureListWithEntryInGrid(creatureList, me, NPC_BLACKHAND_INCARCERATOR, 35.0f);
                            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                                if (Creature* creature = *itr)
                                {
                                    if (!creature->IsAlive())
                                        creature->Respawn();

                                    creature->AI()->SetData(1, 1);
                                }
                            me->AddAura(SPELL_ENCAGED_EMBERSEER, me);
                            instance->SetBossState(DATA_PYROGAURD_EMBERSEER, NOT_STARTED);
                            break;
                        }
                        case EVENT_PRE_FIGHT_1:
                        {
                            // Set data on all Blackhand Incarcerators
                            std::list<Creature*> creatureList;
                            GetCreatureListWithEntryInGrid(creatureList, me, NPC_BLACKHAND_INCARCERATOR, 35.0f);
                            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                            {
                                if (Creature* creature = *itr)
                                    creature->AI()->SetData(1, 1);
                            }
                            events.ScheduleEvent(EVENT_PRE_FIGHT_2, 32000);
                            break;
                        }
                        case EVENT_PRE_FIGHT_2:
                            me->CastSpell(me, SPELL_FREEZE_ANIM);
                            me->CastSpell(me, SPELL_EMBERSEER_GROWING);
                            Talk(EMOTE_ONE_STACK);
                            break;
                        case EVENT_FIRE_SHIELD:
                            // #### Spell isn't doing any damage ??? ####
                            DoCast(me, SPELL_FIRE_SHIELD);
                            events.ScheduleEvent(EVENT_FIRE_SHIELD, 3s);
                            break;
                        case EVENT_PLAYER_CHECK:
                        {
                            // Check to see if all players in instance have aura SPELL_EMBERSEER_START before starting event
                            bool _hasAura = true;
                            Map::PlayerList const& players = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* player = itr->GetSource()->ToPlayer())
                                    if (!player->HasAura(SPELL_EMBERSEER_OBJECT_VISUAL))
                                        _hasAura = false;

                            if (_hasAura)
                            {
                                events.ScheduleEvent(EVENT_PRE_FIGHT_1, 1000);
                                instance->SetBossState(DATA_PYROGAURD_EMBERSEER, IN_PROGRESS);
                            }
                            break;
                        }
                        case EVENT_ENTER_COMBAT:
                            AttackStart(me->SelectNearestPlayer(30.0f));
                            break;
                        default:
                            break;
                    }
                }
                return;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIRE_SHIELD:
                        DoCast(me, SPELL_FIRE_SHIELD);
                        events.ScheduleEvent(EVENT_FIRE_SHIELD, 3s);
                        break;
                    case EVENT_FIRENOVA:
                        DoCast(me, SPELL_FIRENOVA);
                        events.ScheduleEvent(EVENT_FIRENOVA, 6s);
                        break;
                    case EVENT_FLAMEBUFFET:
                        DoCast(me, SPELL_FLAMEBUFFET);
                        events.ScheduleEvent(EVENT_FLAMEBUFFET, 14s);
                        break;
                    case EVENT_PYROBLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_PYROBLAST);
                        events.ScheduleEvent(EVENT_PYROBLAST, 15s);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_pyroguard_emberseerAI>(creature);
    }
};

/*####
## npc_blackhand_incarcerator
####*/

enum IncarceratorEvents
{
    // OOC
    EVENT_ENCAGED_EMBERSEER         = 1,
    // Combat
    EVENT_STRIKE                    = 2,
    EVENT_ENCAGE                    = 3
};

class npc_blackhand_incarcerator : public CreatureScript
{
public:
    npc_blackhand_incarcerator() : CreatureScript("npc_blackhand_incarcerator") { }

    struct npc_blackhand_incarceratorAI : public ScriptedAI
    {
        npc_blackhand_incarceratorAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetImmuneToAll(true);
            if (Creature* Emberseer = me->FindNearestCreature(NPC_PYROGAURD_EMBERSEER, 30.0f, true))
                Emberseer->AI()->SetData(1, 3);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(10000);
        }

        void SetData(uint32 data, uint32 value) override
        {
            if (data == 1 && value == 1)
            {
                me->SetImmuneToAll(false);
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                _events.CancelEvent(EVENT_ENCAGED_EMBERSEER);
            }

            if (data == 1 && value == 2)
                _events.ScheduleEvent(EVENT_ENCAGED_EMBERSEER, 1s);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            // Used to close doors
            if (Creature* Emberseer = me->FindNearestCreature(NPC_PYROGAURD_EMBERSEER, 30.0f, true))
                Emberseer->AI()->SetData(1, 2);

            // Had to do this because CallForHelp will ignore any npcs without LOS
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_BLACKHAND_INCARCERATOR, 60.0f);
            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
            {
                if (Creature* creature = *itr)
                    DoZoneInCombat(creature);    // AI()->AttackStart(me->GetVictim());
            }

            _events.ScheduleEvent(EVENT_STRIKE, 8s, 16s);
            _events.ScheduleEvent(EVENT_ENCAGE, 10s, 20s);
        }

        void UpdateAI(uint32 diff) override
        {


            if (!UpdateVictim())
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENCAGED_EMBERSEER:
                        {
                            if (me->GetPositionX() == me->GetHomePosition().GetPositionX())
                                if (!me->HasAura(SPELL_ENCAGE_EMBERSEER))
                                    if (Creature* Emberseer = me->FindNearestCreature(NPC_PYROGAURD_EMBERSEER, 30.0f, true))
                                        DoCast(Emberseer, SPELL_ENCAGE_EMBERSEER);
                            break;

                        }
                    }
                }
                return;
            }

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STRIKE:
                        DoCastVictim(SPELL_STRIKE, true);
                        _events.ScheduleEvent(EVENT_STRIKE, 14s, 23s);
                        break;
                    case EVENT_ENCAGE:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), EVENT_ENCAGE, true);
                        _events.ScheduleEvent(EVENT_ENCAGE, 6s, 12s);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<npc_blackhand_incarceratorAI>(creature);
    }
};

void AddSC_boss_pyroguard_emberseer()
{
    new boss_pyroguard_emberseer();
    new npc_blackhand_incarcerator();
}
