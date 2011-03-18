/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "icecrown_citadel.h"

// Weekly quest support
//* Deprogramming                (DONE)
//* Securing the Ramparts        (DONE)
//* Residue Rendezvous           (DONE)
//* Blood Quickening             (DONE)
//* Respite for a Tormented Soul

enum Texts
{
    // Highlord Tirion Fordring (at Light's Hammer)
    SAY_TIRION_INTRO_1          = 0,
    SAY_TIRION_INTRO_2          = 1,
    SAY_TIRION_INTRO_3          = 2,
    SAY_TIRION_INTRO_4          = 3,
    SAY_TIRION_INTRO_H_5        = 4,
    SAY_TIRION_INTRO_A_5        = 5,

    // The Lich King (at Light's Hammer)
    SAY_LK_INTRO_1              = 0,
    SAY_LK_INTRO_2              = 1,
    SAY_LK_INTRO_3              = 2,
    SAY_LK_INTRO_4              = 3,
    SAY_LK_INTRO_5              = 4,

    // Highlord Bolvar Fordragon (at Light's Hammer)
    SAY_BOLVAR_INTRO_1          = 0,

    // High Overlord Saurfang (at Light's Hammer)
    SAY_SAURFANG_INTRO_1        = 15,
    SAY_SAURFANG_INTRO_2        = 16,
    SAY_SAURFANG_INTRO_3        = 17,
    SAY_SAURFANG_INTRO_4        = 18,

    // Muradin Bronzebeard (at Light's Hammer)
    SAY_MURADIN_INTRO_1         = 13,
    SAY_MURADIN_INTRO_2         = 14,
    SAY_MURADIN_INTRO_3         = 15,

    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING  = 0,
};

enum Spells
{
    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE              = 72879,
    SPELL_DEATH_PLAGUE_AURA         = 72865,
    SPELL_RECENTLY_INFECTED         = 72884,
    SPELL_DEATH_PLAGUE_KILL         = 72867,
    SPELL_STOMP                     = 64652,
    SPELL_ARCTIC_BREATH             = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS            = 70460,

    // Alchemist Adrianna
    SPELL_HARVEST_BLIGHT_SPECIMEN   = 72155,
    SPELL_HARVEST_BLIGHT_SPECIMEN25 = 72162,
};

enum Events
{
    // Highlord Tirion Fordring (at Light's Hammer)
    // The Lich King (at Light's Hammer)
    // Highlord Bolvar Fordragon (at Light's Hammer)
    // High Overlord Saurfang (at Light's Hammer)
    // Muradin Bronzebeard (at Light's Hammer)
    EVENT_TIRION_INTRO_2    = 1,
    EVENT_TIRION_INTRO_3    = 2,
    EVENT_TIRION_INTRO_4    = 3,
    EVENT_TIRION_INTRO_5    = 4,
    EVENT_LK_INTRO_1        = 5,
    EVENT_TIRION_INTRO_6    = 6,
    EVENT_LK_INTRO_2        = 7,
    EVENT_LK_INTRO_3        = 8,
    EVENT_LK_INTRO_4        = 9,
    EVENT_BOLVAR_INTRO_1    = 10,
    EVENT_LK_INTRO_5        = 11,
    EVENT_SAURFANG_INTRO_1  = 12,
    EVENT_TIRION_INTRO_H_7  = 13,
    EVENT_SAURFANG_INTRO_2  = 14,
    EVENT_SAURFANG_INTRO_3  = 15,
    EVENT_SAURFANG_INTRO_4  = 16,
    EVENT_SAURFANG_RUN      = 17,
    EVENT_MURADIN_INTRO_1   = 18,
    EVENT_MURADIN_INTRO_2   = 19,
    EVENT_MURADIN_INTRO_3   = 20,
    EVENT_TIRION_INTRO_A_7  = 21,
    EVENT_MURADIN_INTRO_4   = 22,
    EVENT_MURADIN_INTRO_5   = 23,
    EVENT_MURADIN_RUN       = 24,

    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE      = 25,
    EVENT_STOMP             = 26,
    EVENT_ARCTIC_BREATH     = 27,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP     = 28,
};

enum DataTypesICC
{
    DATA_DAMNED_KILLS       = 1,
};

// at Light's Hammer
class npc_highlord_tirion_fordring_lh : public CreatureScript
{
    public:
        npc_highlord_tirion_fordring_lh() : CreatureScript("npc_highlord_tirion_fordring_lh") { }

        struct npc_highlord_tirion_fordringAI : public ScriptedAI
        {
            npc_highlord_tirion_fordringAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                events.Reset();
                _theLichKing = 0;
                _bolvarFordragon = 0;
                _factionNPC = 0;
                _damnedKills = 0;
            }

            // IMPORTANT NOTE: This is triggered from per-GUID scripts
            // of The Damned SAI
            void SetData(uint32 type, uint32 data)
            {
                if (!instance)
                    return;

                if (type == DATA_DAMNED_KILLS && data == 1)
                {
                    if (++_damnedKills == 2)
                    {
                        if (Creature* theLichKing = me->FindNearestCreature(NPC_THE_LICH_KING_LH, 150.0f))
                        {
                            if (Creature* bolvarFordragon = me->FindNearestCreature(NPC_HIGHLORD_BOLVAR_FORDRAGON_LH, 150.0f))
                            {
                                if (Creature* factionNPC = me->FindNearestCreature(instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE ? NPC_SE_HIGH_OVERLORD_SAURFANG : NPC_SE_MURADIN_BRONZEBEARD, 50.0f))
                                {
                                    me->setActive(true);
                                    _theLichKing = theLichKing->GetGUID();
                                    theLichKing->setActive(true);
                                    _bolvarFordragon = bolvarFordragon->GetGUID();
                                    bolvarFordragon->setActive(true);
                                    _factionNPC = factionNPC->GetGUID();
                                    factionNPC->setActive(true);
                                }
                            }
                        }

                        if (!_bolvarFordragon || !_theLichKing || !_factionNPC)
                            return;

                        Talk(SAY_TIRION_INTRO_1);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_2, 4000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_3, 14000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_4, 18000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_5, 31000);
                        events.ScheduleEvent(EVENT_LK_INTRO_1, 35000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_6, 51000);
                        events.ScheduleEvent(EVENT_LK_INTRO_2, 58000);
                        events.ScheduleEvent(EVENT_LK_INTRO_3, 74000);
                        events.ScheduleEvent(EVENT_LK_INTRO_4, 86000);
                        events.ScheduleEvent(EVENT_BOLVAR_INTRO_1, 100000);
                        events.ScheduleEvent(EVENT_LK_INTRO_5, 108000);

                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_1, 120000);
                            events.ScheduleEvent(EVENT_TIRION_INTRO_H_7, 129000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_2, 139000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_3, 150000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_4, 162000);
                            events.ScheduleEvent(EVENT_SAURFANG_RUN, 170000);
                        }
                        else
                        {
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_1, 120000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_2, 124000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_3, 127000);
                            events.ScheduleEvent(EVENT_TIRION_INTRO_A_7, 136000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_4, 144000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_5, 151000);
                            events.ScheduleEvent(EVENT_MURADIN_RUN, 157000);
                        }
                    }
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_damnedKills != 2)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIRION_INTRO_2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_3:
                            Talk(SAY_TIRION_INTRO_2);
                            break;
                        case EVENT_TIRION_INTRO_4:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_5:
                            Talk(SAY_TIRION_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NOSHEATHE);
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_6:
                            Talk(SAY_TIRION_INTRO_4);
                            break;
                        case EVENT_LK_INTRO_2:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_2);
                            break;
                        case EVENT_LK_INTRO_3:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_4:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_4);
                            break;
                        case EVENT_BOLVAR_INTRO_1:
                            if (Creature* bolvarFordragon = ObjectAccessor::GetCreature(*me, _bolvarFordragon))
                            {
                                bolvarFordragon->AI()->Talk(SAY_BOLVAR_INTRO_1);
                                bolvarFordragon->setActive(false);
                            }
                            break;
                        case EVENT_LK_INTRO_5:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                            {
                                theLichKing->AI()->Talk(SAY_LK_INTRO_5);
                                theLichKing->setActive(false);
                            }
                            break;
                        case EVENT_SAURFANG_INTRO_1:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_H_7:
                            Talk(SAY_TIRION_INTRO_H_5);
                            break;
                        case EVENT_SAURFANG_INTRO_2:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_2);
                            break;
                        case EVENT_SAURFANG_INTRO_3:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_3);
                            break;
                        case EVENT_SAURFANG_INTRO_4:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_4);
                            break;
                        case EVENT_MURADIN_RUN:
                        case EVENT_SAURFANG_RUN:
                            if (Creature* factionNPC = ObjectAccessor::GetCreature(*me, _factionNPC))
                                factionNPC->GetMotionMaster()->MovePath(factionNPC->GetDBTableGUIDLow()*10, false);
                            me->setActive(false);
                            _damnedKills = 3;
                            break;
                        case EVENT_MURADIN_INTRO_1:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_1);
                            break;
                        case EVENT_MURADIN_INTRO_2:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            break;
                        case EVENT_MURADIN_INTRO_3:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_A_7:
                            Talk(SAY_TIRION_INTRO_A_5);
                            break;
                        case EVENT_MURADIN_INTRO_4:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_2);
                            break;
                        case EVENT_MURADIN_INTRO_5:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_3);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            InstanceScript* const instance;
            uint64 _theLichKing;
            uint64 _bolvarFordragon;
            uint64 _factionNPC;
            uint16 _damnedKills;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_highlord_tirion_fordringAI(creature);
        }
};

class npc_rotting_frost_giant : public CreatureScript
{
    public:
        npc_rotting_frost_giant() : CreatureScript("npc_rotting_frost_giant") { }

        struct npc_rotting_frost_giantAI : public ScriptedAI
        {
            npc_rotting_frost_giantAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                events.ScheduleEvent(EVENT_STOMP, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target->GetGUID());
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, urand(15000, 18000));
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(26000, 33000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_rotting_frost_giantAI(creature);
        }
};

class npc_frost_freeze_trap : public CreatureScript
{
    public:
        npc_frost_freeze_trap() : CreatureScript("npc_frost_freeze_trap") { }

        struct npc_frost_freeze_trapAI: public Scripted_NoMovementAI
        {
            npc_frost_freeze_trapAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    case ACTION_STOP_TRAPS:
                        me->RemoveAurasDueToSpell(SPELL_COLDFLAME_JETS);
                        events.CancelEvent(EVENT_ACTIVATE_TRAP);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frost_freeze_trapAI(creature);
        }
};

class npc_alchemist_adrianna : public CreatureScript
{
    public:
        npc_alchemist_adrianna() : CreatureScript("npc_alchemist_adrianna") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN) && !creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN25))
                if (player->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE) && player->HasAura(SPELL_GREEN_BLIGHT_RESIDUE))
                    creature->CastSpell(creature, SPELL_HARVEST_BLIGHT_SPECIMEN, false);
            return false;
        }
};

class DeathPlagueTargetSelector
{
    public:
        DeathPlagueTargetSelector(Unit* _caster) : caster(_caster) {}

        bool operator()(Unit* unit)
        {
            if (unit == caster)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (unit->HasAura(SPELL_RECENTLY_INFECTED) || unit->HasAura(SPELL_DEATH_PLAGUE_AURA))
                return true;

            return false;
        }

        Unit* caster;
};

class spell_frost_giant_death_plague : public SpellScriptLoader
{
    public:
        spell_frost_giant_death_plague() : SpellScriptLoader("spell_frost_giant_death_plague") { }

        class spell_frost_giant_death_plague_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frost_giant_death_plague_SpellScript);

            bool Load()
            {
                failed = false;
                return true;
            }

            // First effect
            void CountTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetCaster());
                failed = unitList.empty();
            }

            // Second effect
            void FilterTargets(std::list<Unit*>& unitList)
            {
                // Select valid targets for jump
                unitList.remove_if(DeathPlagueTargetSelector(GetCaster()));
                if (!unitList.empty())
                {
                    std::list<Unit*>::iterator itr = unitList.begin();
                    std::advance(itr, urand(0, unitList.size()-1));
                    Unit* target = *itr;
                    unitList.clear();
                    unitList.push_back(target);
                }

                unitList.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit() != GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEATH_PLAGUE_AURA, true);
                else if (failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
                OnEffect += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool failed;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_frost_giant_death_plague_SpellScript();
        }
};

class spell_icc_harvest_blight_specimen : public SpellScriptLoader
{
    public:
        spell_icc_harvest_blight_specimen() : SpellScriptLoader("spell_icc_harvest_blight_specimen") { }

        class spell_icc_harvest_blight_specimen_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_harvest_blight_specimen_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void HandleQuestComplete(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleQuestComplete, EFFECT_1, SPELL_EFFECT_QUEST_COMPLETE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_harvest_blight_specimen_SpellScript();
        }
};

class at_icc_saurfang_portal : public AreaTriggerScript
{
    public:
        at_icc_saurfang_portal() : AreaTriggerScript("at_icc_saurfang_portal") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(DATA_DEATHBRINGER_SAURFANG) != DONE)
                return true;

            player->TeleportTo(631, 4126.35f, 2769.23f, 350.963f, 0.0f);

            if (instance->GetData(DATA_COLDFLAME_JETS) == NOT_STARTED)
            {
                // Process relocation now, to preload the grid and initialize traps
                player->GetMap()->PlayerRelocation(player, 4126.35f, 2769.23f, 350.963f, 0.0f);

                instance->SetData(DATA_COLDFLAME_JETS, IN_PROGRESS);
                std::list<Creature*> traps;
                GetCreatureListWithEntryInGrid(traps, player, NPC_FROST_FREEZE_TRAP, 120.0f);
                traps.sort(Trinity::ObjectDistanceOrderPred(player));
                bool instant = false;
                for (std::list<Creature*>::iterator itr = traps.begin(); itr != traps.end(); ++itr)
                {
                    (*itr)->AI()->DoAction(instant ? 1000 : 11000);
                    instant = !instant;
                }
            }
            return true;
        }
};

class at_icc_shutdown_traps : public AreaTriggerScript
{
    public:
        at_icc_shutdown_traps() : AreaTriggerScript("at_icc_shutdown_traps") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_COLDFLAME_JETS) == IN_PROGRESS)
                    instance->SetData(DATA_COLDFLAME_JETS, DONE);
            return true;
        }
};

class at_icc_start_blood_quickening : public AreaTriggerScript
{
    public:
        at_icc_start_blood_quickening() : AreaTriggerScript("at_icc_start_blood_quickening") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_BLOOD_QUICKENING_STATE) == NOT_STARTED)
                    instance->SetData(DATA_BLOOD_QUICKENING_STATE, IN_PROGRESS);
            return true;
        }
};

void AddSC_icecrown_citadel()
{
    new npc_highlord_tirion_fordring_lh();
    new npc_rotting_frost_giant();
    new npc_frost_freeze_trap();
    new npc_alchemist_adrianna();
    new spell_frost_giant_death_plague();
    new spell_icc_harvest_blight_specimen();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();
    new at_icc_start_blood_quickening();
}
