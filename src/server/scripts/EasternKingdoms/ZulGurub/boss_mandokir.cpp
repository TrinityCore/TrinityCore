/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Mandokir
SD%Complete: 90
SDComment: Ohgan function needs improvements.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "zulgurub.h"

enum Says
{
    SAY_AGGRO                 = 0,
    SAY_DING_KILL             = 1,
    SAY_WATCH                 = 2,
    SAY_WATCH_WHISPER         = 3,
    SAY_OHGAN_DEAD            = 4,
    SAY_GRATS_JINDO           = 0,
};

enum Spells
{
    SPELL_CHARGE              = 24408, // seen
    SPELL_OVERPOWER           = 24407, // Seen
    SPELL_FEAR                = 29321,
    SPELL_WHIRLWIND           = 13736, // Triggers 15589
    SPELL_MORTAL_STRIKE       = 16856, // Seen
    SPELL_FRENZY              = 24318, // seen
    SPELL_WATCH               = 24314, // seen 24315, 24316
    SPELL_WATCH_CHARGE        = 24315, // Triggers 24316
    SPELL_LEVEL_UP            = 24312  //
};

enum Events
{
    EVENT_CHECK_SPEAKER       = 1,
    EVENT_CHECK_START         = 2,
    EVENT_STARTED             = 3,
    EVENT_OVERPOWER           = 4,
    EVENT_MORTAL_STRIKE       = 5,
    EVENT_WHIRLWIND           = 6,
    EVENT_CHECK_OHGAN         = 7,
    EVENT_WATCH_PLAYER        = 8,
    EVENT_CHARGE_PLAYER       = 9
};

enum Misc
{
    MODEL_OHGAN_MOUNT         = 15271,
    PATH_MANDOKIR             = 492861,
    POINT_MANDOKIR_END        = 24,
    CHAINED_SPIRT_COUNT       = 20
};

Position const PosSummonChainedSpirits[CHAINED_SPIRT_COUNT] =
{
    { -12167.17f, -1979.330f, 133.0992f, 2.268928f },
    { -12262.74f, -1953.394f, 133.5496f, 0.593412f },
    { -12176.89f, -1983.068f, 133.7841f, 2.129302f },
    { -12226.45f, -1977.933f, 132.7982f, 1.466077f },
    { -12204.74f, -1890.431f, 135.7569f, 4.415683f },
    { -12216.70f, -1891.806f, 136.3496f, 4.677482f },
    { -12236.19f, -1892.034f, 134.1041f, 5.044002f },
    { -12248.24f, -1893.424f, 134.1182f, 5.270895f },
    { -12257.36f, -1897.663f, 133.1484f, 5.462881f },
    { -12265.84f, -1903.077f, 133.1649f, 5.654867f },
    { -12158.69f, -1972.707f, 133.8751f, 2.408554f },
    { -12178.82f, -1891.974f, 134.1786f, 3.944444f },
    { -12193.36f, -1890.039f, 135.1441f, 4.188790f },
    { -12275.59f, -1932.845f, 134.9017f, 0.174533f },
    { -12273.51f, -1941.539f, 136.1262f, 0.314159f },
    { -12247.02f, -1963.497f, 133.9476f, 0.872665f },
    { -12238.68f, -1969.574f, 133.6273f, 1.134464f },
    { -12192.78f, -1982.116f, 132.6966f, 1.919862f },
    { -12210.81f, -1979.316f, 133.8700f, 1.797689f },
    { -12283.51f, -1924.839f, 133.5170f, 0.069813f }
};

Position const PosMandokir[2] =
{
    { -12167.8f, -1927.25f, 153.73f, 3.76991f },
    { -12197.86f, -1949.392f, 130.2745f, 0.0f }
};

class boss_mandokir : public CreatureScript
{
    public: boss_mandokir() : CreatureScript("boss_mandokir") { }

        struct boss_mandokirAI : public BossAI
        {
            boss_mandokirAI(Creature* creature) : BossAI(creature, DATA_MANDOKIR) { }

            void Reset() OVERRIDE
            {
                if (me->GetPositionZ() > 140.0f)
                {
                    _Reset();
                    killCount = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC);
                    events.ScheduleEvent(EVENT_CHECK_START, 1000);
                    if (Creature* speaker = Creature::GetCreature(*me, instance->GetData64(NPC_VILEBRANCH_SPEAKER)))
                        if (!speaker->IsAlive())
                            speaker->Respawn(true);
                }
                summons.DespawnAll();
                me->Mount(MODEL_OHGAN_MOUNT);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                // Do not want to unsummon Ohgan
                for (int i = 0; i < CHAINED_SPIRT_COUNT; ++i)
                    if (Creature* unsummon = Creature::GetCreature(*me, chainedSpirtGUIDs[i]))
                        unsummon->DespawnOrUnsummon();
                instance->SetBossState(DATA_MANDOKIR, DONE);
                instance->SaveToDB();
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_OVERPOWER, urand(7000, 9000));
                events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(12000, 18000));
                events.ScheduleEvent(EVENT_WHIRLWIND, urand(24000, 30000));
                events.ScheduleEvent(EVENT_CHECK_OHGAN, 1000);
                events.ScheduleEvent(EVENT_WATCH_PLAYER, urand(13000, 15000));
                events.ScheduleEvent(EVENT_CHARGE_PLAYER, urand(33000, 38000));
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                Talk(SAY_AGGRO);
                me->Dismount();
                // Summon Ohgan (Spell missing) TEMP HACK
                me->SummonCreature(NPC_OHGAN, me->GetPositionX()-3, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 35000);
                // Summon Chained Spirits
                for (int i = 0; i < CHAINED_SPIRT_COUNT; ++i)
                {
                    Creature* chainedSpirt = me->SummonCreature(NPC_CHAINED_SPIRT, PosSummonChainedSpirits[i], TEMPSUMMON_CORPSE_DESPAWN);
                    chainedSpirtGUIDs[i] = chainedSpirt->GetGUID();
                }
                DoZoneInCombat();
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (++killCount == 3)
                {
                    Talk(SAY_DING_KILL);
                    if (Creature* jindo = Creature::GetCreature(*me, instance->GetData64(DATA_JINDO)))
                        if (jindo->IsAlive())
                            jindo->AI()->Talk(SAY_GRATS_JINDO);
                    DoCast(me, SPELL_LEVEL_UP, true);
                    killCount = 0;
                }
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type == WAYPOINT_MOTION_TYPE)
                {
                    me->SetWalk(false);
                    if (id == POINT_MANDOKIR_END)
                    {
                        me->SetHomePosition(PosMandokir[0]);
                        instance->SetBossState(DATA_MANDOKIR, NOT_STARTED);
                        me->DespawnOrUnsummon(6000); // No idea how to respawn on wipe.
                    }
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                events.Update(diff);

                if (!UpdateVictim())
                {
                    if (instance->GetBossState(DATA_MANDOKIR) == NOT_STARTED || instance->GetBossState(DATA_MANDOKIR) == SPECIAL)
                    {
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_CHECK_START:
                                    if (instance->GetBossState(DATA_MANDOKIR) == SPECIAL)
                                    {
                                        me->GetMotionMaster()->MovePoint(0, PosMandokir[1].m_positionX, PosMandokir[1].m_positionY, PosMandokir[1].m_positionZ);
                                        events.ScheduleEvent(EVENT_STARTED, 6000);
                                    }
                                    else
                                        events.ScheduleEvent(EVENT_CHECK_START, 1000);
                                    break;
                                case EVENT_STARTED:
                                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC);
                                    me->GetMotionMaster()->MovePath(PATH_MANDOKIR, false);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_OVERPOWER:
                            DoCastVictim(SPELL_OVERPOWER, true);
                            events.ScheduleEvent(EVENT_OVERPOWER, urand(6000, 12000));
                            break;
                        case EVENT_MORTAL_STRIKE:
                            if (me->GetVictim() && me->GetVictim()->HealthBelowPct(50))
                                DoCastVictim(SPELL_MORTAL_STRIKE, true);
                            events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(12000, 18000));
                            break;
                        case EVENT_WHIRLWIND:
                            DoCast(me, SPELL_WHIRLWIND);
                            events.ScheduleEvent(EVENT_WHIRLWIND, urand(22000, 26000));
                            break;
                        case EVENT_CHECK_OHGAN:
                            if (instance->GetBossState(DATA_OHGAN) == DONE)
                            {
                                DoCast(me, SPELL_FRENZY);
                                Talk(SAY_OHGAN_DEAD);
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_OHGAN, 1000);
                            break;
                        case EVENT_WATCH_PLAYER:
                            if (Unit* player = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                DoCast(player, SPELL_WATCH);
                                Talk(SAY_WATCH, player);
                            }
                            events.ScheduleEvent(EVENT_WATCH_PLAYER, urand(12000, 15000));
                            break;
                        case EVENT_CHARGE_PLAYER:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true), SPELL_CHARGE);
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, urand(22000, 30000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 killCount;
            uint64 chainedSpirtGUIDs[CHAINED_SPIRT_COUNT];
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetZulGurubAI<boss_mandokirAI>(creature);
        }
};

// Ohgan

enum OhganSpells
{
    SPELL_SUNDERARMOR         = 24317
};

class npc_ohgan : public CreatureScript
{
    public: npc_ohgan() : CreatureScript("npc_ohgan") { }

        struct npc_ohganAI : public ScriptedAI
        {
            npc_ohganAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

            void Reset() OVERRIDE
            {
                SunderArmor_Timer = 5000;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE { }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                instance->SetBossState(DATA_OHGAN, DONE);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                if (SunderArmor_Timer <= diff)
                {
                    DoCastVictim(SPELL_SUNDERARMOR, true);
                    SunderArmor_Timer = urand(10000, 15000);
                } else SunderArmor_Timer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 SunderArmor_Timer;
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetZulGurubAI<npc_ohganAI>(creature);
        }
};

enum VilebranchSpells
{
    SPELL_DEMORALIZING_SHOUT  = 13730,
    SPELL_CLEAVE              = 15284
};

class npc_vilebranch_speaker : public CreatureScript
{
    public: npc_vilebranch_speaker() : CreatureScript("npc_vilebranch_speaker") { }

        struct npc_vilebranch_speakerAI : public ScriptedAI
        {
            npc_vilebranch_speakerAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

            void Reset() OVERRIDE
            {
                demoralizing_Shout_Timer = urand(2000, 4000);
                cleave_Timer = urand(5000, 8000);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE { }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                instance->SetBossState(DATA_MANDOKIR, SPECIAL);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                if (demoralizing_Shout_Timer <= diff)
                {
                    DoCast(me, SPELL_DEMORALIZING_SHOUT);
                    demoralizing_Shout_Timer = urand(22000, 30000);
                } else demoralizing_Shout_Timer -= diff;

                if (cleave_Timer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE, true);
                    cleave_Timer = urand(6000, 9000);
                } else cleave_Timer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 demoralizing_Shout_Timer;
            uint32 cleave_Timer;
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_vilebranch_speakerAI>(creature);
        }
};

class spell_threatening_gaze : public SpellScriptLoader
{
    public:
        spell_threatening_gaze() : SpellScriptLoader("spell_threatening_gaze") { }

        class spell_threatening_gaze_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_threatening_gaze_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetTarget())
                        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                            caster->CastSpell(target, SPELL_WATCH_CHARGE);
            }

            void Register() OVERRIDE
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_threatening_gaze_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_threatening_gaze_AuraScript();
        }
};

void AddSC_boss_mandokir()
{
    new boss_mandokir();
    new npc_ohgan();
    new npc_vilebranch_speaker();
    new spell_threatening_gaze();
}
