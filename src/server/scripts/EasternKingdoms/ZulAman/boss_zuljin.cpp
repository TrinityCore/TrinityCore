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
SDName: Boss_ZulJin
SD%Complete: 85%
SDComment:
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulaman.h"
#include "SpellInfo.h"

enum Says
{
    YELL_INTRO                    = 0,
    YELL_AGGRO                    = 1,
    YELL_TRANSFORM_TO_BEAR        = 2,
    YELL_TRANSFORM_TO_EAGLE       = 3,
    YELL_TRANSFORM_TO_LYNX        = 4,
    YELL_TRANSFORM_TO_DRAGONHAWK  = 5,
    YELL_FIRE_BREATH              = 6,
    YELL_BERSERK                  = 7,
    YELL_KILL                     = 8,
    YELL_DEATH                    = 9
};

enum Spells
{
    // Troll Form
    SPELL_WHIRLWIND               = 17207,
    SPELL_GRIEVOUS_THROW          = 43093, // remove debuff after full healed
    // Bear Form
    SPELL_CREEPING_PARALYSIS      = 43095, // should cast on the whole raid
    SPELL_OVERPOWER               = 43456, // use after melee attack dodged
    // Eagle Form
    SPELL_ENERGY_STORM            = 43983, // enemy area aura, trigger 42577
    SPELL_ZAP_INFORM              = 42577,
    SPELL_ZAP_DAMAGE              = 43137, // 1250 damage
    SPELL_SUMMON_CYCLONE          = 43112, // summon four feather vortex
    CREATURE_FEATHER_VORTEX       = 24136,
    SPELL_CYCLONE_VISUAL          = 43119, // trigger 43147 visual
    SPELL_CYCLONE_PASSIVE         = 43120, // trigger 43121 (4y aoe) every second
    // Lynx Form
    SPELL_CLAW_RAGE_HASTE         = 42583,
    SPELL_CLAW_RAGE_TRIGGER       = 43149,
    SPELL_CLAW_RAGE_DAMAGE        = 43150,
    SPELL_LYNX_RUSH_HASTE         = 43152,
    SPELL_LYNX_RUSH_DAMAGE        = 43153,
    // Dragonhawk Form
    SPELL_FLAME_WHIRL             = 43213, // trigger two spells
    SPELL_FLAME_BREATH            = 43215,
    SPELL_SUMMON_PILLAR           = 43216, // summon 24187
    CREATURE_COLUMN_OF_FIRE       = 24187,
    SPELL_PILLAR_TRIGGER          = 43218, // trigger 43217
    // Cosmetic
    SPELL_SPIRIT_AURA             = 42466,
    SPELL_SIPHON_SOUL             = 43501,
    // Transforms:
    SPELL_SHAPE_OF_THE_BEAR       = 42594, // 15% dmg
    SPELL_SHAPE_OF_THE_EAGLE      = 42606,
    SPELL_SHAPE_OF_THE_LYNX       = 42607, // haste melee 30%
    SPELL_SHAPE_OF_THE_DRAGONHAWK = 42608,

    SPELL_BERSERK                 = 45078
};

enum Phase
{
    PHASE_BEAR                    = 0,
    PHASE_EAGLE                   = 1,
    PHASE_LYNX                    = 2,
    PHASE_DRAGONHAWK              = 3,
    PHASE_TROLL                   = 4
};

//coords for going for changing form
#define CENTER_X 120.148811f
#define CENTER_Y 703.713684f
#define CENTER_Z 45.111477f

struct SpiritInfoStruct
{
    uint32 entry;
    float x, y, z, orient;
};

static SpiritInfoStruct SpiritInfo[4] =
{
    {23878, 147.87f, 706.51f, 45.11f, 3.04f},
    {23880, 88.95f, 705.49f, 45.11f, 6.11f},
    {23877, 137.23f, 725.98f, 45.11f, 3.71f},
    {23879, 104.29f, 726.43f, 45.11f, 5.43f}
};

struct TransformStruct
{
    uint8  text;
    uint32 spell, unaura;
};

static TransformStruct Transform[4] =
{
    {YELL_TRANSFORM_TO_BEAR, SPELL_SHAPE_OF_THE_BEAR, SPELL_WHIRLWIND},
    {YELL_TRANSFORM_TO_EAGLE, SPELL_SHAPE_OF_THE_EAGLE, SPELL_SHAPE_OF_THE_BEAR},
    {YELL_TRANSFORM_TO_LYNX, SPELL_SHAPE_OF_THE_LYNX, SPELL_SHAPE_OF_THE_EAGLE},
    {YELL_TRANSFORM_TO_DRAGONHAWK, SPELL_SHAPE_OF_THE_DRAGONHAWK, SPELL_SHAPE_OF_THE_LYNX}
};

class boss_zuljin : public CreatureScript
{
    public:

        boss_zuljin()
            : CreatureScript("boss_zuljin")
        {
        }

        struct boss_zuljinAI : public ScriptedAI
        {
            boss_zuljinAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }
            InstanceScript* instance;

            uint64 SpiritGUID[4];
            uint64 ClawTargetGUID;
            uint64 TankGUID;

            uint32 Phase;
            uint32 health_20;

            uint32 Intro_Timer;
            uint32 Berserk_Timer;

            uint32 Whirlwind_Timer;
            uint32 Grievous_Throw_Timer;

            uint32 Creeping_Paralysis_Timer;
            uint32 Overpower_Timer;

            uint32 Claw_Rage_Timer;
            uint32 Lynx_Rush_Timer;
            uint32 Claw_Counter;
            uint32 Claw_Loop_Timer;

            uint32 Flame_Whirl_Timer;
            uint32 Flame_Breath_Timer;
            uint32 Pillar_Of_Fire_Timer;

            SummonList Summons;

            void Reset() OVERRIDE
            {
                instance->SetData(DATA_ZULJINEVENT, NOT_STARTED);

                Phase = 0;

                health_20 = me->CountPctFromMaxHealth(20);

                Intro_Timer = 37000;
                Berserk_Timer = 600000;

                Whirlwind_Timer = 7000;
                Grievous_Throw_Timer = 8000;

                Creeping_Paralysis_Timer = 7000;
                Overpower_Timer = 0;

                Claw_Rage_Timer = 5000;
                Lynx_Rush_Timer = 14000;
                Claw_Loop_Timer = 0;
                Claw_Counter = 0;

                Flame_Whirl_Timer = 5000;
                Flame_Breath_Timer = 6000;
                Pillar_Of_Fire_Timer = 7000;

                ClawTargetGUID = 0;
                TankGUID = 0;

                Summons.DespawnAll();

                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 33975);
                //me->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 218172674);
                //me->SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                instance->SetData(DATA_ZULJINEVENT, IN_PROGRESS);

                DoZoneInCombat();

                Talk(YELL_INTRO);
                SpawnAdds();
                EnterPhase(0);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                if (Intro_Timer)
                    return;

                Talk(YELL_KILL);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                instance->SetData(DATA_ZULJINEVENT, DONE);

                Talk(YELL_DEATH);
                Summons.DespawnEntry(CREATURE_COLUMN_OF_FIRE);

                if (Unit* Temp = Unit::GetUnit(*me, SpiritGUID[3]))
                    Temp->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
            }

            void AttackStart(Unit* who) OVERRIDE
            {
                if (Phase == 2)
                    AttackStartNoMove(who);
                else
                    ScriptedAI::AttackStart(who);
            }

            void DoMeleeAttackIfReady()
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    if (me->isAttackReady() && me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        if (Phase == 1 && !Overpower_Timer)
                        {
                            uint32 health = me->GetVictim()->GetHealth();
                            me->AttackerStateUpdate(me->GetVictim());
                            if (me->GetVictim() && health == me->GetVictim()->GetHealth())
                            {
                                DoCastVictim(SPELL_OVERPOWER, false);
                                Overpower_Timer = 5000;
                            }
                        } else me->AttackerStateUpdate(me->GetVictim());
                        me->resetAttackTimer();
                    }
                }
            }

            void SpawnAdds()
            {
                Creature* creature = NULL;
                for (uint8 i = 0; i < 4; ++i)
                {
                    creature = me->SummonCreature(SpiritInfo[i].entry, SpiritInfo[i].x, SpiritInfo[i].y, SpiritInfo[i].z, SpiritInfo[i].orient, TEMPSUMMON_DEAD_DESPAWN, 0);
                    if (creature)
                    {
                        creature->CastSpell(creature, SPELL_SPIRIT_AURA, true);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        SpiritGUID[i] = creature->GetGUID();
                    }
                }
            }

            void DespawnAdds()
            {
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (SpiritGUID[i])
                    {
                        if (Unit* temp = Unit::GetUnit(*me, SpiritGUID[i]))
                        {
                            temp->SetVisible(false);
                            temp->setDeathState(DEAD);
                        }
                    }
                    SpiritGUID[i] = 0;
                }
            }

            void JustSummoned(Creature* summon) OVERRIDE
            {
                Summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) OVERRIDE
            {
                Summons.Despawn(summon);
            }

            void EnterPhase(uint32 NextPhase)
            {
                switch (NextPhase)
                {
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    DoTeleportTo(CENTER_X, CENTER_Y, CENTER_Z, 100);
                    DoResetThreat();
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, 0);
                    me->RemoveAurasDueToSpell(Transform[Phase].unaura);
                    DoCast(me, Transform[Phase].spell);
                    Talk(Transform[Phase].text);
                    if (Phase > 0)
                    {
                        if (Unit* Temp = Unit::GetUnit(*me, SpiritGUID[Phase - 1]))
                            Temp->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_STAND_STATE_DEAD);
                    }
                    if (Unit* Temp = Unit::GetUnit(*me, SpiritGUID[NextPhase - 1]))
                        Temp->CastSpell(me, SPELL_SIPHON_SOUL, false); // should m cast on temp
                    if (NextPhase == 2)
                    {
                        me->GetMotionMaster()->Clear();
                        DoCast(me, SPELL_ENERGY_STORM, true); // enemy aura
                        for (uint8 i = 0; i < 4; ++i)
                        {
                            Creature* Vortex = DoSpawnCreature(CREATURE_FEATHER_VORTEX, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                            if (Vortex)
                            {
                                Vortex->CastSpell(Vortex, SPELL_CYCLONE_PASSIVE, true);
                                Vortex->CastSpell(Vortex, SPELL_CYCLONE_VISUAL, true);
                                Vortex->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                Vortex->SetSpeed(MOVE_RUN, 1.0f);
                                Vortex->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                                DoZoneInCombat(Vortex);
                            }
                        }
                    }
                    else
                        me->AI()->AttackStart(me->GetVictim());
                    if (NextPhase == 3)
                    {
                        me->RemoveAurasDueToSpell(SPELL_ENERGY_STORM);
                        Summons.DespawnEntry(CREATURE_FEATHER_VORTEX);
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                    }
                    break;
                default:
                    break;
                }
                Phase = NextPhase;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!TankGUID)
                {
                    if (!UpdateVictim())
                        return;

                    if (me->GetHealth() < health_20 * (4 - Phase))
                        EnterPhase(Phase + 1);
                }

                if (Berserk_Timer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    Talk(YELL_BERSERK);
                    Berserk_Timer = 60000;
                } else Berserk_Timer -= diff;

                switch (Phase)
                {
                case 0:
                    if (Intro_Timer)
                    {
                        if (Intro_Timer <= diff)
                        {
                            Talk(YELL_AGGRO);
                            Intro_Timer = 0;
                        } else Intro_Timer -= diff;
                    }

                    if (Whirlwind_Timer <= diff)
                    {
                        DoCast(me, SPELL_WHIRLWIND);
                        Whirlwind_Timer = urand(15000, 20000);
                    } else Whirlwind_Timer -= diff;

                    if (Grievous_Throw_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_GRIEVOUS_THROW, false);
                        Grievous_Throw_Timer = 10000;
                    } else Grievous_Throw_Timer -= diff;
                    break;

                case 1:
                    if (Creeping_Paralysis_Timer <= diff)
                    {
                        DoCast(me, SPELL_CREEPING_PARALYSIS);
                        Creeping_Paralysis_Timer = 20000;
                    } else Creeping_Paralysis_Timer -= diff;

                    if (Overpower_Timer <= diff)
                    {
                        // implemented in DoMeleeAttackIfReady()
                        Overpower_Timer = 0;
                    } else Overpower_Timer -= diff;
                    break;

                case 2:
                    return;

                case 3:
                    if (Claw_Rage_Timer <= diff)
                    {
                        if (!TankGUID)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                TankGUID = me->GetVictim()->GetGUID();
                                me->SetSpeed(MOVE_RUN, 5.0f);
                                AttackStart(target); // change victim
                                Claw_Rage_Timer = 0;
                                Claw_Loop_Timer = 500;
                                Claw_Counter = 0;
                            }
                        }
                        else if (!Claw_Rage_Timer) // do not do this when Lynx_Rush
                        {
                            if (Claw_Loop_Timer <= diff)
                            {
                                Unit* target = me->GetVictim();
                                if (!target || !target->isTargetableForAttack()) target = Unit::GetUnit(*me, TankGUID);
                                if (!target || !target->isTargetableForAttack()) target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                if (target)
                                {
                                    AttackStart(target);
                                    if (me->IsWithinMeleeRange(target))
                                    {
                                        DoCast(target, SPELL_CLAW_RAGE_DAMAGE, true);
                                        ++Claw_Counter;
                                        if (Claw_Counter == 12)
                                        {
                                            Claw_Rage_Timer = urand(15000, 20000);
                                            me->SetSpeed(MOVE_RUN, 1.2f);
                                            AttackStart(Unit::GetUnit(*me, TankGUID));
                                            TankGUID = 0;
                                            return;
                                        }
                                        else
                                            Claw_Loop_Timer = 500;
                                    }
                                }
                                else
                                {
                                    EnterEvadeMode(); // if (target)
                                    return;
                                }
                            } else Claw_Loop_Timer -= diff;
                        } //if (TankGUID)
                    } else Claw_Rage_Timer -= diff;

                    if (Lynx_Rush_Timer <= diff)
                    {
                        if (!TankGUID)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                TankGUID = me->GetVictim()->GetGUID();
                                me->SetSpeed(MOVE_RUN, 5.0f);
                                AttackStart(target); // change victim
                                Lynx_Rush_Timer = 0;
                                Claw_Counter = 0;
                            }
                        }
                        else if (!Lynx_Rush_Timer)
                        {
                            Unit* target = me->GetVictim();
                            if (!target || !target->isTargetableForAttack())
                            {
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                AttackStart(target);
                            }
                            if (target)
                            {
                                if (me->IsWithinMeleeRange(target))
                                {
                                    DoCast(target, SPELL_LYNX_RUSH_DAMAGE, true);
                                    ++Claw_Counter;
                                    if (Claw_Counter == 9)
                                    {
                                        Lynx_Rush_Timer = urand(15000, 20000);
                                        me->SetSpeed(MOVE_RUN, 1.2f);
                                        AttackStart(Unit::GetUnit(*me, TankGUID));
                                        TankGUID = 0;
                                    }
                                    else
                                        AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                                }
                            }
                            else
                            {
                                EnterEvadeMode(); // if (target)
                                return;
                            }
                        } //if (TankGUID)
                    } else Lynx_Rush_Timer -= diff;

                    break;
                case 4:
                    if (Flame_Whirl_Timer <= diff)
                    {
                        DoCast(me, SPELL_FLAME_WHIRL);
                        Flame_Whirl_Timer = 12000;
                    }Flame_Whirl_Timer -= diff;

                    if (Pillar_Of_Fire_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SUMMON_PILLAR);
                        Pillar_Of_Fire_Timer = 10000;
                    } else Pillar_Of_Fire_Timer -= diff;

                    if (Flame_Breath_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            me->SetInFront(target);
                        DoCast(me, SPELL_FLAME_BREATH);
                        Flame_Breath_Timer = 10000;
                    } else Flame_Breath_Timer -= diff;
                    break;

                default:
                    break;
                }

                if (!TankGUID)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_zuljinAI>(creature);
        }
};

class npc_zuljin_vortex : public CreatureScript
{
    public:

        npc_zuljin_vortex()
            : CreatureScript("npc_zuljin_vortex")
        {
        }

        struct npc_zuljin_vortexAI : public ScriptedAI
        {
            npc_zuljin_vortexAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() OVERRIDE { }

            void EnterCombat(Unit* /*target*/) OVERRIDE { }

            void SpellHit(Unit* caster, const SpellInfo* spell) OVERRIDE
            {
                if (spell->Id == SPELL_ZAP_INFORM)
                    DoCast(caster, SPELL_ZAP_DAMAGE, true);
            }

            void UpdateAI(uint32 /*diff*/) OVERRIDE
            {
                //if the vortex reach the target, it change his target to another player
                if (me->IsWithinMeleeRange(me->GetVictim()))
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_zuljin_vortexAI(creature);
        }
};

void AddSC_boss_zuljin()
{
    new boss_zuljin();
    new npc_zuljin_vortex();
}

