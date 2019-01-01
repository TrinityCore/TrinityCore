/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "temple_of_ahnqiraj.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_POISON_SHOCK          = 25993,
    SPELL_POISONBOLT_VOLLEY     = 25991,
    SPELL_TOXIN                 = 26575,
    SPELL_VISCIDUS_SLOWED       = 26034,
    SPELL_VISCIDUS_SLOWED_MORE  = 26036,
    SPELL_VISCIDUS_FREEZE       = 25937,
    SPELL_REJOIN_VISCIDUS       = 25896,
    SPELL_VISCIDUS_EXPLODE      = 25938,
    SPELL_VISCIDUS_SUICIDE      = 26003,
    SPELL_VISCIDUS_SHRINKS      = 25893,                   // Removed from client, in world.spell_dbc

    SPELL_MEMBRANE_VISCIDUS     = 25994,                   // damage reduction spell - removed from DBC
    SPELL_VISCIDUS_WEAKNESS     = 25926,                   // aura which procs at damage - should trigger the slow spells - removed from DBC
    SPELL_VISCIDUS_GROWS        = 25897,                   // removed from DBC
    SPELL_SUMMON_GLOBS          = 25885,                   // summons npc 15667 using spells from 25865 to 25884; All spells have target coords - removed from DBC
    SPELL_VISCIDUS_TELEPORT     = 25904,                   // removed from DBC
};

enum Events
{
    EVENT_POISONBOLT_VOLLEY     = 1,
    EVENT_POISON_SHOCK          = 2,
    EVENT_RESET_PHASE           = 3
};

enum Phases
{
    PHASE_FROST                 = 1,
    PHASE_MELEE                 = 2,
    PHASE_GLOB                  = 3
};

enum Emotes
{
    EMOTE_SLOW                  = 0,
    EMOTE_FREEZE                = 1,
    EMOTE_FROZEN                = 2,

    EMOTE_CRACK                 = 3,
    EMOTE_SHATTER               = 4,
    EMOTE_EXPLODE               = 5
};

enum HitCounter
{
    HITCOUNTER_SLOW             = 100,
    HITCOUNTER_SLOW_MORE        = 150,
    HITCOUNTER_FREEZE           = 200,

    HITCOUNTER_CRACK            = 50,
    HITCOUNTER_SHATTER          = 100,
    HITCOUNTER_EXPLODE          = 150,
};

enum MovePoints
{
    ROOM_CENTER                 = 1
};

Position const ViscidusCoord = { -7992.36f, 908.19f, -52.62f, 1.68f }; /// @todo Visci isn't in room middle
float const RoomRadius = 40.0f; /// @todo Not sure if its correct

class boss_viscidus : public CreatureScript
{
    public:
        boss_viscidus() : CreatureScript("boss_viscidus") { }

        struct boss_viscidusAI : public BossAI
        {
            boss_viscidusAI(Creature* creature) : BossAI(creature, DATA_VISCIDUS)
            {
                Initialize();
            }

            void Initialize()
            {
                _hitcounter = 0;
                _phase = PHASE_FROST;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void DamageTaken(Unit* attacker, uint32& /*damage*/) override
            {
                if (_phase != PHASE_MELEE)
                    return;

                ++_hitcounter;

                if (attacker->HasUnitState(UNIT_STATE_MELEE_ATTACKING) && _hitcounter >= HITCOUNTER_EXPLODE)
                {
                    Talk(EMOTE_EXPLODE);
                    events.Reset();
                    _phase = PHASE_GLOB;
                    DoCast(me, SPELL_VISCIDUS_EXPLODE);
                    me->SetVisible(false);
                    me->RemoveAura(SPELL_TOXIN);
                    me->RemoveAura(SPELL_VISCIDUS_FREEZE);

                    uint8 NumGlobes = me->GetHealthPct() / 5.0f;
                    for (uint8 i = 0; i < NumGlobes; ++i)
                    {
                        float Angle = i * 2 * float(M_PI) / NumGlobes;
                        float X = ViscidusCoord.GetPositionX() + std::cos(Angle) * RoomRadius;
                        float Y = ViscidusCoord.GetPositionY() + std::sin(Angle) * RoomRadius;
                        float Z = -35.0f;

                        if (TempSummon* Glob = me->SummonCreature(NPC_GLOB_OF_VISCIDUS, X, Y, Z))
                        {
                            Glob->UpdateAllowedPositionZ(X, Y, Z);
                            Glob->NearTeleportTo(X, Y, Z, 0.0f);
                            Glob->GetMotionMaster()->MovePoint(ROOM_CENTER, ViscidusCoord);
                        }
                    }
                }
                else if (_hitcounter == HITCOUNTER_SHATTER)
                    Talk(EMOTE_SHATTER);
                else if (_hitcounter == HITCOUNTER_CRACK)
                    Talk(EMOTE_CRACK);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if ((spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST) && _phase == PHASE_FROST && me->GetHealthPct() > 5.0f)
                {
                    ++_hitcounter;

                    if (_hitcounter >= HITCOUNTER_FREEZE)
                    {
                        _hitcounter = 0;
                        Talk(EMOTE_FROZEN);
                        _phase = PHASE_MELEE;
                        DoCast(me, SPELL_VISCIDUS_FREEZE);
                        me->RemoveAura(SPELL_VISCIDUS_SLOWED_MORE);
                        events.ScheduleEvent(EVENT_RESET_PHASE, 15000);
                    }
                    else if (_hitcounter >= HITCOUNTER_SLOW_MORE)
                    {
                        Talk(EMOTE_FREEZE);
                        me->RemoveAura(SPELL_VISCIDUS_SLOWED);
                        DoCast(me, SPELL_VISCIDUS_SLOWED_MORE);
                    }
                    else if (_hitcounter >= HITCOUNTER_SLOW)
                    {
                        Talk(EMOTE_SLOW);
                        DoCast(me, SPELL_VISCIDUS_SLOWED);
                    }
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.Reset();
                InitSpells();
            }

            void InitSpells()
            {
                DoCast(me, SPELL_TOXIN);
                events.ScheduleEvent(EVENT_POISONBOLT_VOLLEY, urand(10000, 15000));
                events.ScheduleEvent(EVENT_POISON_SHOCK, urand(7000, 12000));
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                summons.DespawnAll();
                ScriptedAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCast(me, SPELL_VISCIDUS_SUICIDE);
                summons.DespawnAll();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_phase == PHASE_GLOB && summons.empty())
                {
                    DoResetThreat();
                    me->NearTeleportTo(ViscidusCoord.GetPositionX(),
                        ViscidusCoord.GetPositionY(),
                        ViscidusCoord.GetPositionZ(),
                        ViscidusCoord.GetOrientation());

                    _hitcounter = 0;
                    _phase = PHASE_FROST;
                    InitSpells();
                    me->SetVisible(true);
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POISONBOLT_VOLLEY:
                            DoCast(me, SPELL_POISONBOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_POISONBOLT_VOLLEY, urand(10000, 15000));
                            break;
                        case EVENT_POISON_SHOCK:
                            DoCast(me, SPELL_POISON_SHOCK);
                            events.ScheduleEvent(EVENT_POISON_SHOCK, urand(7000, 12000));
                            break;
                        case EVENT_RESET_PHASE:
                            _hitcounter = 0;
                            _phase = PHASE_FROST;
                            break;
                        default:
                            break;
                    }
                }

                if (_phase != PHASE_GLOB)
                    DoMeleeAttackIfReady();
            }

        private:
            uint8 _hitcounter;
            Phases _phase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAQ40AI<boss_viscidusAI>(creature);
        }
};

class npc_glob_of_viscidus : public CreatureScript
{
    public:
        npc_glob_of_viscidus() : CreatureScript("boss_glob_of_viscidus") { }

        struct npc_glob_of_viscidusAI : public ScriptedAI
        {
            npc_glob_of_viscidusAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit* /*killer*/) override
            {
                InstanceScript* Instance = me->GetInstanceScript();

                if (Creature* Viscidus = ObjectAccessor::GetCreature(*me, Instance->GetGuidData(DATA_VISCIDUS)))
                {
                    Viscidus->AI()->SummonedCreatureDespawn(me);

                    if (Viscidus->IsAlive() && Viscidus->GetHealthPct() < 5.0f)
                    {
                        Viscidus->SetVisible(true);
                        if (Viscidus->GetVictim())
                            Viscidus->EnsureVictim()->Kill(Viscidus);
                    }
                    else
                    {
                        Viscidus->SetHealth(Viscidus->GetHealth() - Viscidus->GetMaxHealth() / 20);
                        Viscidus->CastSpell(Viscidus, SPELL_VISCIDUS_SHRINKS);
                    }
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id == ROOM_CENTER)
                {
                    DoCast(me, SPELL_REJOIN_VISCIDUS);
                    if (TempSummon* summon = me->ToTempSummon())
                        summon->UnSummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAQ40AI<npc_glob_of_viscidusAI>(creature);
        }
};

void AddSC_boss_viscidus()
{
    new boss_viscidus();
    new npc_glob_of_viscidus();
}
