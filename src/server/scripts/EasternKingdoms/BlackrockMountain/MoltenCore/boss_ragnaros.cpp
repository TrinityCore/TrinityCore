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

 /* ScriptData
 SDName: Boss_Ragnaros
 SD%Complete: 95
 SDComment: some spells doesnt work correctly
 SDCategory: Molten Core
 EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "molten_core.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Texts
{
    SAY_SUMMON_MAJ = 0,
    SAY_ARRIVAL1_RAG = 1,
    SAY_ARRIVAL2_MAJ = 2,
    SAY_ARRIVAL3_RAG = 3,
    SAY_ARRIVAL5_RAG = 4,
    SAY_REINFORCEMENTS1 = 5,
    SAY_REINFORCEMENTS2 = 6,
    SAY_HAND = 7,
    SAY_WRATH = 8,
    SAY_KILL = 9,
    SAY_MAGMABURST = 10
};

enum Spells
{
    SPELL_HAND_OF_RAGNAROS = 19780,
    SPELL_WRATH_OF_RAGNAROS = 20566,
    SPELL_LAVA_BURST = 21158,
    SPELL_MAGMA_BLAST = 20565,                   // Ranged attack
    SPELL_SONS_OF_FLAME_DUMMY = 21108,                   // Server side effect
    SPELL_RAGSUBMERGE = 21107,                   // Stealth aura
    SPELL_RAGEMERGE = 20568,
    SPELL_MELT_WEAPON = 21388,
    SPELL_ELEMENTAL_FIRE = 20564,
    SPELL_ERRUPTION = 17731,
    SPELL_ELEMENTAL_FIRE_KILL = 19773,
};

enum Events
{
    EVENT_ERUPTION = 1,
    EVENT_WRATH_OF_RAGNAROS = 2,
    EVENT_HAND_OF_RAGNAROS = 3,
    EVENT_LAVA_BURST = 4,
    EVENT_ELEMENTAL_FIRE = 5,
    EVENT_MAGMA_BLAST = 6,
    EVENT_SUBMERGE = 7,

    EVENT_INTRO_1 = 8,
    EVENT_INTRO_2 = 9,
    EVENT_INTRO_3 = 10,
    EVENT_INTRO_4 = 11,
    EVENT_INTRO_5 = 12,
};

class boss_ragnaros : public CreatureScript
{
public:
    boss_ragnaros() : CreatureScript("boss_ragnaros") { }

    struct boss_ragnarosAI : public BossAI
    {
        boss_ragnarosAI(Creature* creature) : BossAI(creature, BOSS_RAGNAROS)
        {
            Initialize();
            _introState = 0;
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            SetCombatMovement(false);
        }

        void Initialize()
        {
            _emergeTimer = 60000;
            _hasYelledMagmaBurst = false;
            _hasSubmergedOnce = false;
            _isBanished = false;
        }

        void Reset() override
        {
            BossAI::Reset();
            Initialize();
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
        }

        void JustEngagedWith(Unit* victim) override
        {
            BossAI::JustEngagedWith(victim);
            events.ScheduleEvent(EVENT_ERUPTION, 15s);
            events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 30s);
            events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 25s);
            events.ScheduleEvent(EVENT_LAVA_BURST, 10s);
            events.ScheduleEvent(EVENT_ELEMENTAL_FIRE, 3s);
            events.ScheduleEvent(EVENT_MAGMA_BLAST, 2s);
            events.ScheduleEvent(EVENT_SUBMERGE, 1min);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (urand(0, 99) < 25)
                Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
        {
            if (_introState != 2)
            {
                if (!_introState)
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                    events.ScheduleEvent(EVENT_INTRO_1, 4000);
                    events.ScheduleEvent(EVENT_INTRO_2, 23000);
                    events.ScheduleEvent(EVENT_INTRO_3, 42000);
                    events.ScheduleEvent(EVENT_INTRO_4, 45000);
                    events.ScheduleEvent(EVENT_INTRO_5, 55000);
                    _introState = 1;
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_INTRO_1:
                        Talk(SAY_ARRIVAL1_RAG);
                        break;
                    case EVENT_INTRO_2:
                        Talk(SAY_ARRIVAL3_RAG);
                        break;
                    case EVENT_INTRO_3:
                        if (Creature* executus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(BOSS_MAJORDOMO_EXECUTUS)))
                        {
                            DoCast(executus, SPELL_ELEMENTAL_FIRE_KILL);
                        }
                        //me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                        break;
                    case EVENT_INTRO_4:
                    {
                        Talk(SAY_ARRIVAL5_RAG);
                        break;
                    }
                    case EVENT_INTRO_5:
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->SetImmuneToPC(false);
                        _introState = 2;
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
            else
            {
                if (_isBanished)
                {
                    _emergeTimer -= diff;
                    bool emerge = false;
                    if (_emergeTimer < 0)
                    {
                        emerge = true;
                    }
                    else if (instance->GetData(DATA_RAGNAROS_ADDS) >= 8)
                    {
                        emerge = true;
                    }
                    if (emerge)
                    {
                        //Become unbanished again
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAurasDueToSpell(SPELL_RAGSUBMERGE);
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        {
                            AttackStart(target);
                        }
                        _isBanished = false;
                        instance->SetData(DATA_RAGNAROS_ADDS, 0);
                        events.ScheduleEvent(EVENT_SUBMERGE, 1min);
                    }
                    return;
                }

                //Return since we have no target
                if (!UpdateVictim())
                {
                    return;
                }
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_ERUPTION:
                    {
                        DoCastVictim(SPELL_ERRUPTION);
                        events.ScheduleEvent(EVENT_ERUPTION, 20s, 45s);
                        break;
                    }
                    case EVENT_WRATH_OF_RAGNAROS:
                    {
                        DoCastVictim(SPELL_WRATH_OF_RAGNAROS);
                        if (urand(0, 1))
                        {
                            Talk(SAY_WRATH);
                        }
                        events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 25s);
                        break;
                    }
                    case EVENT_HAND_OF_RAGNAROS:
                    {
                        DoCast(me, SPELL_HAND_OF_RAGNAROS);
                        if (urand(0, 1))
                        {
                            Talk(SAY_HAND);
                        }
                        events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 20s);
                        break;
                    }
                    case EVENT_LAVA_BURST:
                    {
                        DoCastVictim(SPELL_LAVA_BURST);
                        events.ScheduleEvent(EVENT_LAVA_BURST, 10s);
                        break;
                    }
                    case EVENT_ELEMENTAL_FIRE:
                    {
                        DoCastVictim(SPELL_ELEMENTAL_FIRE);
                        events.ScheduleEvent(EVENT_ELEMENTAL_FIRE, 10s, 14s);
                        break;
                    }
                    case EVENT_MAGMA_BLAST:
                    {
                        if (Unit* myVictim = me->GetVictim())
                        {
                            float victimDistance = me->GetExactDist(myVictim->GetPosition());
                            if (victimDistance > 22.0f)
                            {
                                DoCastVictim(SPELL_MAGMA_BLAST);
                                if (!_hasYelledMagmaBurst)
                                {
                                    //Say our dialog
                                    Talk(SAY_MAGMABURST);
                                    _hasYelledMagmaBurst = true;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_MAGMA_BLAST, 2500ms);
                        break;
                    }
                    case EVENT_SUBMERGE:
                    {
                        if (!_isBanished)
                        {
                            //Creature spawning and ragnaros becomming unattackable
                            //is not very well supported in the core //no it really isnt
                            //so added normaly spawning and banish workaround and attack again after 90 secs.
                            // summon 8 elementals
                            for (uint8 i = 0; i < 8; ++i)
                            {
                                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                                {
                                    if (Creature* summoned = me->SummonCreature(12143, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 900000))
                                    {
                                        summoned->AI()->AttackStart(target);
                                    }
                                }
                            }
                            if (!_hasSubmergedOnce)
                            {
                                Talk(SAY_REINFORCEMENTS1);
                            }
                            else
                            {
                                Talk(SAY_REINFORCEMENTS2);
                            }
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            ResetThreatList();
                            me->InterruptNonMeleeSpells(false);
                            DoCastSelf(SPELL_RAGSUBMERGE);
                            _hasSubmergedOnce = true;
                            _isBanished = true;
                            _emergeTimer = 60000;

                            //Root self                                                                                            
                            //DoCast(me, 23973);
                            //me->SetFaction(FACTION_FRIENDLY);                                    
                            //me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SUBMERGED);                                    
                            instance->SetData(DATA_RAGNAROS_ADDS, 0);
                        }
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }

                DoMeleeAttackIfReady();
            }
        }

    private:
        int _emergeTimer;
        uint8 _introState;
        bool _hasYelledMagmaBurst;
        bool _hasSubmergedOnce;
        bool _isBanished;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMoltenCoreAI<boss_ragnarosAI>(creature);
    }
};

class npc_son_of_flame : public CreatureScript
{
public:
    npc_son_of_flame() : CreatureScript("npc_SonOfFlame") { }

    struct npc_son_of_flameAI : public ScriptedAI //didnt work correctly in EAI for me...
    {
        npc_son_of_flameAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_RAGNAROS_ADDS, 1);
        }

        void JustEngagedWith(Unit* victim) override
        {
            events.ScheduleEvent(1, 2000, 5000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                {
                    DoCastSelf(21858);
                    events.Repeat(10000, 15000);
                    break;
                }
                default:
                {
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMoltenCoreAI<npc_son_of_flameAI>(creature);
    }
};

void AddSC_boss_ragnaros()
{
    new boss_ragnaros();
    new npc_son_of_flame();
}
