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

#include "zulgurub.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Says
{
    SAY_AGGRO                 = 0,
    SAY_DING_KILL             = 1,
    SAY_WATCH                 = 2,
    SAY_WATCH_WHISPER         = 3,
    SAY_OHGAN_DEAD            = 4,

    SAY_GRATS_JINDO           = 0
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
    EVENT_CHECK_START,
    EVENT_STARTED,
    EVENT_OVERPOWER,
    EVENT_MORTAL_STRIKE,
    EVENT_WHIRLWIND,
    EVENT_WATCH_PLAYER,
    EVENT_CHARGE_PLAYER
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
    public:
        boss_mandokir() : CreatureScript("boss_mandokir") { }

        struct boss_mandokirAI : public BossAI
        {
            boss_mandokirAI(Creature* creature) : BossAI(creature, DATA_MANDOKIR)
            {
                Initialize();
            }

            void Initialize()
            {
                _killCount = 0;
            }

            void Reset() override
            {
                if (me->GetPositionZ() > 140.0f)
                {
                    _Reset();
                    Initialize();
                    me->SetImmuneToAll(true);
                    events.ScheduleEvent(EVENT_CHECK_START, 1s);
                    if (Creature* speaker = instance->GetCreature(DATA_VILEBRANCH_SPEAKER))
                        if (!speaker->IsAlive())
                            speaker->Respawn(true);
                }
                summons.DespawnAll();
                me->Mount(MODEL_OHGAN_MOUNT);
            }

            void JustDied(Unit* /*killer*/) override
            {
                summons.DespawnEntry(NPC_CHAINED_SPIRT);
                instance->SetBossState(DATA_MANDOKIR, DONE);
                instance->SaveToDB();
            }

            void JustReachedHome() override
            {
                me->SetImmuneToAll(false);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_OVERPOWER, 7s, 9s);
                events.ScheduleEvent(EVENT_MORTAL_STRIKE, 12s, 18s);
                events.ScheduleEvent(EVENT_WHIRLWIND, 24s, 30s);
                events.ScheduleEvent(EVENT_WATCH_PLAYER, 13s, 15s);
                events.ScheduleEvent(EVENT_CHARGE_PLAYER, 33s, 38s);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                Talk(SAY_AGGRO);
                me->Dismount();

                // Summon Ohgan (Spell missing) TEMP HACK
                me->SummonCreature(NPC_OHGAN, me->GetPositionX() - 3, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 35000);
                // Summon Chained Spirits
                for (int i = 0; i < CHAINED_SPIRT_COUNT; ++i)
                    me->SummonCreature(NPC_CHAINED_SPIRT, PosSummonChainedSpirits[i], TEMPSUMMON_CORPSE_DESPAWN);

                DoZoneInCombat();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (++_killCount == 3)
                {
                    Talk(SAY_DING_KILL);
                    if (Creature* jindo = instance->GetCreature(DATA_JINDO))
                        if (jindo->IsAlive())
                            jindo->AI()->Talk(SAY_GRATS_JINDO);
                    DoCast(me, SPELL_LEVEL_UP, true);
                    _killCount = 0;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() == NPC_OHGAN)
                {
                    DoCast(me, SPELL_FRENZY);
                    Talk(SAY_OHGAN_DEAD);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == WAYPOINT_MOTION_TYPE)
                {
                    me->SetWalk(false);
                    if (id == POINT_MANDOKIR_END)
                    {
                        me->SetHomePosition(PosMandokir[1]);
                        me->GetMotionMaster()->MoveTargetedHome();
                        instance->SetBossState(DATA_MANDOKIR, NOT_STARTED);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
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
                                        me->GetMotionMaster()->MovePoint(0, PosMandokir[1]);
                                        events.ScheduleEvent(EVENT_STARTED, 6s);
                                    }
                                    else
                                        events.ScheduleEvent(EVENT_CHECK_START, 1s);
                                    break;
                                case EVENT_STARTED:
                                    me->SetImmuneToAll(false);
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
                            events.ScheduleEvent(EVENT_OVERPOWER, 6s, 12s);
                            break;
                        case EVENT_MORTAL_STRIKE:
                            if (me->GetVictim() && me->EnsureVictim()->HealthBelowPct(50))
                                DoCastVictim(SPELL_MORTAL_STRIKE, true);
                            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 12s, 18s);
                            break;
                        case EVENT_WHIRLWIND:
                            DoCast(me, SPELL_WHIRLWIND);
                            events.ScheduleEvent(EVENT_WHIRLWIND, 22s, 26s);
                            break;
                        case EVENT_WATCH_PLAYER:
                            if (Unit* player = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                            {
                                DoCast(player, SPELL_WATCH);
                                Talk(SAY_WATCH, player);
                            }
                            events.ScheduleEvent(EVENT_WATCH_PLAYER, 12s, 15s);
                            break;
                        case EVENT_CHARGE_PLAYER:
                            DoCast(SelectTarget(SelectTargetMethod::Random, 0, 40, true), SPELL_CHARGE);
                            events.ScheduleEvent(EVENT_CHARGE_PLAYER, 22s, 30s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _killCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
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
    public:
        npc_ohgan() : CreatureScript("npc_ohgan") { }

        struct npc_ohganAI : public ScriptedAI
        {
            npc_ohganAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _sunderArmorTimer = 5000;
            }

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_sunderArmorTimer <= diff)
                {
                    DoCastVictim(SPELL_SUNDERARMOR, true);
                    _sunderArmorTimer = urand(10000, 15000);
                }
                else
                    _sunderArmorTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _sunderArmorTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
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
    public:
        npc_vilebranch_speaker() : CreatureScript("npc_vilebranch_speaker") { }

        struct npc_vilebranch_speakerAI : public ScriptedAI
        {
            npc_vilebranch_speakerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _demoralizingShoutTimer = urand(2000, 4000);
                _cleaveTimer = urand(5000, 8000);
            }

            void Reset() override
            {
                Initialize();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SetBossState(DATA_MANDOKIR, SPECIAL);
            }

            void UpdateAI(uint32 diff) override
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                if (_demoralizingShoutTimer <= diff)
                {
                    DoCast(me, SPELL_DEMORALIZING_SHOUT);
                    _demoralizingShoutTimer = urand(22000, 30000);
                }
                else
                    _demoralizingShoutTimer -= diff;

                if (_cleaveTimer <= diff)
                {
                    DoCastVictim(SPELL_CLEAVE, true);
                    _cleaveTimer = urand(6000, 9000);
                }
                else
                    _cleaveTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _demoralizingShoutTimer;
            uint32 _cleaveTimer;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_vilebranch_speakerAI>(creature);
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_threatening_gaze_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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
