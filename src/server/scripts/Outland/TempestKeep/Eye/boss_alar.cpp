/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: boss_alar
SD%Complete: 95
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "the_eye.h"

enum Spells
{
    SPELL_FLAME_BUFFET           = 34121, // Flame Buffet - every 1, 5 secs in phase 1 if there is no victim in melee range and after Dive Bomb in phase 2 with same conditions
    SPELL_FLAME_QUILLS           = 34229, // Randomly after changing position in phase after watching tons of movies, set probability 20%
    SPELL_REBIRTH                = 34342, // Rebirth - beginning of second phase(after losing all health in phase 1)
    SPELL_REBIRTH_2              = 35369, // Rebirth(another, without healing to full HP) - after Dive Bomb in phase 2
    SPELL_MELT_ARMOR             = 35410, // Melt Armor - every 60 sec in phase 2
    SPELL_CHARGE                 = 35412, // Charge - 30 sec cooldown
    SPELL_DIVE_BOMB_VISUAL       = 35367, // Bosskillers says 30 sec cooldown, wowwiki says 30 sec colldown, DBM and BigWigs addons says ~47 sec
    SPELL_DIVE_BOMB              = 35181, // after watching tonns of movies, set cooldown to 40+rand()%5.
    SPELL_BERSERK                = 45078, // 10 minutes after phase 2 starts(id is wrong, but proper id is unknown)

    CREATURE_EMBER_OF_ALAR       = 19551, // Al'ar summons one Ember of Al'ar every position change in phase 1 and two after Dive Bomb. Also in phase 2 when Ember of Al'ar dies, boss loses 3% health.
    SPELL_EMBER_BLAST            = 34133, // When Ember of Al'ar dies, it casts Ember Blast

    CREATURE_FLAME_PATCH_ALAR    = 20602, // Flame Patch - every 30 sec in phase 2
    SPELL_FLAME_PATCH            = 35380, //
};

static float waypoint[6][3] =
{
    {340.15f, 58.65f, 17.71f},
    {388.09f, 31.54f, 20.18f},
    {388.18f, -32.85f, 20.18f},
    {340.29f, -60.19f, 17.72f},
    {332.0f, 0.01f, 39.0f}, // better not use the same xy coord
    {331.0f, 0.01f, -2.39f}
};

enum WaitEventType
{
    WE_NONE     = 0,
    WE_DUMMY    = 1,
    WE_PLATFORM = 2,
    WE_QUILL    = 3,
    WE_DIE      = 4,
    WE_REVIVE   = 5,
    WE_CHARGE   = 6,
    WE_METEOR   = 7,
    WE_DIVE     = 8,
    WE_LAND     = 9,
    WE_SUMMON   = 10
};

uint32 const flameQuillsSpells[] =
{
    34269,
    34270,
    34271,
    34272,
    34273,
    34274,
    34275,
    34276,
    34277,
    34278,
    34279,
    34280,
    34281,
    34282,
    34283,
    34284,
    34285,
    34286,
    34287,
    34288,
    34289,
    34314,
    34315,
    34316
};

class boss_alar : public CreatureScript
{
    public:
        boss_alar() : CreatureScript("boss_alar") { }

        struct boss_alarAI : public BossAI
        {
            boss_alarAI(Creature* creature) : BossAI(creature, DATA_ALAR)
            {
                Initialize();
                DefaultMoveSpeedRate = creature->GetSpeedRate(MOVE_RUN);
                DiveBomb_Timer = 0;
                MeltArmor_Timer = 0;
                Charge_Timer = 0;
                FlamePatch_Timer = 0;
            }

            void Initialize()
            {
                Berserk_Timer = 1200000;
                Platforms_Move_Timer = 0;

                Phase1 = true;
                WaitEvent = WE_NONE;
                WaitTimer = 0;
                AfterMoving = false;
                ForceMove = false;
                ForceTimer = 5000;

                cur_wp = 4;
            }

            WaitEventType WaitEvent;
            uint32 WaitTimer;

            bool AfterMoving;

            uint32 Platforms_Move_Timer;
            uint32 DiveBomb_Timer;
            uint32 MeltArmor_Timer;
            uint32 Charge_Timer;
            uint32 FlamePatch_Timer;
            uint32 Berserk_Timer;

            float DefaultMoveSpeedRate;

            bool Phase1;
            bool ForceMove;
            uint32 ForceTimer;

            int8 cur_wp;

            void Reset() override
            {
                Initialize();
                _Reset();

                me->SetDisplayId(me->GetNativeDisplayId());
                me->SetSpeedRate(MOVE_RUN, DefaultMoveSpeedRate);
                //me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
                //me->SetFloatValue(UNIT_FIELD_COMBATREACH, 10);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
                me->SetDisableGravity(true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setActive(false);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                me->SetDisableGravity(true); // after enterevademode will be set walk movement
                me->setActive(true);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == CREATURE_EMBER_OF_ALAR)
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summon->AI()->AttackStart(target);
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }

            void AttackStart(Unit* who) override
            {
                if (Phase1)
                    AttackStartNoMove(who);
                else
                    ScriptedAI::AttackStart(who);
            }

            void DamageTaken(Unit* /*killer*/, uint32 &damage) override
            {
                if (damage >= me->GetHealth() && Phase1)
                {
                    damage = 0;
                    if (!WaitEvent)
                    {
                        WaitEvent = WE_DIE;
                        WaitTimer = 0;
                        me->SetHealth(0);
                        me->InterruptNonMeleeSpells(true);
                        me->RemoveAllAuras();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->AttackStop();
                        me->SetTarget(ObjectGuid::Empty);
                        me->SetSpeedRate(MOVE_RUN, 5.0f);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, waypoint[5][0], waypoint[5][1], waypoint[5][2]);
                    }
                }
            }

            void SpellHit(Unit*, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_DIVE_BOMB_VISUAL)
                {
                    me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
                    me->SetDisplayId(11686);
                    //me->SendUpdateObjectToAllExcept(nullptr);
                }
            }

            void MovementInform(uint32 type, uint32 /*id*/) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    WaitTimer = 1;
                    AfterMoving = true;
                    ForceMove = false;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!me->IsEngaged())
                    return;

                if (Berserk_Timer <= diff)
                {
                    DoCast(me, SPELL_BERSERK, true);
                    Berserk_Timer = 60000;
                }
                else
                    Berserk_Timer -= diff;

                if (ForceMove)
                {
                    if (ForceTimer <= diff)
                    {
                        me->GetMotionMaster()->MovePoint(0, waypoint[cur_wp][0], waypoint[cur_wp][1], waypoint[cur_wp][2]);
                        ForceTimer = 5000;
                    }
                    else
                        ForceTimer -= diff;

                }
                if (WaitEvent)
                {
                    if (WaitTimer)
                    {
                        if (WaitTimer <= diff)
                        {
                            if (AfterMoving)
                            {
                                me->GetMotionMaster()->MoveIdle();
                                AfterMoving = false;
                            }

                            switch (WaitEvent)
                            {
                            case WE_PLATFORM:
                                Platforms_Move_Timer = 30000 + rand32() % 5000;
                                break;
                            case WE_QUILL:
                                DoCast(me, SPELL_FLAME_QUILLS, true);
                                Platforms_Move_Timer = 1;
                                WaitTimer = 10000;
                                WaitEvent = WE_DUMMY;
                                return;
                            case WE_DIE:
                                ForceMove = false;
                                me->SetStandState(UNIT_STAND_STATE_DEAD);
                                WaitTimer = 5000;
                                WaitEvent = WE_REVIVE;
                                return;
                            case WE_REVIVE:
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                me->SetFullHealth();
                                me->SetSpeedRate(MOVE_RUN, DefaultMoveSpeedRate);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                DoZoneInCombat();
                                DoCast(me, SPELL_REBIRTH, true);
                                MeltArmor_Timer = 60000;
                                Charge_Timer = 7000;
                                DiveBomb_Timer = 40000 + rand32() % 5000;
                                FlamePatch_Timer = 30000;
                                Phase1 = false;
                                break;
                            case WE_METEOR:
                                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, false);
                                DoCast(me, SPELL_DIVE_BOMB_VISUAL, false);
                                WaitEvent = WE_DIVE;
                                WaitTimer = 4000;
                                return;
                            case WE_DIVE:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                {
                                    me->RemoveAurasDueToSpell(SPELL_DIVE_BOMB_VISUAL);
                                    DoCast(target, SPELL_DIVE_BOMB, true);
                                    float dist = 3.0f;
                                    if (me->IsWithinDist3d(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 5.0f))
                                        dist = 5.0f;
                                    WaitTimer = 1000 + uint32(floor(dist / 80 * 1000.0f));
                                    me->UpdatePosition(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f);
                                    me->StopMoving();
                                    WaitEvent = WE_LAND;
                                    return;
                                }
                                else
                                {
                                    EnterEvadeMode();
                                    return;
                                }
                            case WE_LAND:
                                WaitEvent = WE_SUMMON;
                                WaitTimer = 2000;
                                return;
                            case WE_SUMMON:
                                for (uint8 i = 0; i < 2; ++i)
                                    DoSpawnCreature(CREATURE_EMBER_OF_ALAR, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 10);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                me->SetDisplayId(me->GetNativeDisplayId());
                                DoCast(me, SPELL_REBIRTH_2, true);
                                break;
                            case WE_DUMMY:
                            default:
                                break;
                            }

                            WaitEvent = WE_NONE;
                            WaitTimer = 0;
                        }
                        else
                            WaitTimer -= diff;
                    }
                    return;
                }

                if (Phase1)
                {
                    if (!me->IsThreatened())
                    {
                        EnterEvadeMode();
                        return;
                    }

                    if (Platforms_Move_Timer <= diff)
                    {
                        if (cur_wp == 4)
                        {
                            cur_wp = 0;
                            WaitEvent = WE_PLATFORM;
                        }
                        else
                        {
                            if (urand(0, 4)) // next platform
                            {
                                DoSpawnCreature(CREATURE_EMBER_OF_ALAR, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                                if (cur_wp == 3)
                                    cur_wp = 0;
                                else
                                    ++cur_wp;
                                WaitEvent = WE_PLATFORM;
                            }
                            else // flame quill
                            {
                                cur_wp = 4;
                                WaitEvent = WE_QUILL;
                            }
                        }
                        ForceMove = true;
                        ForceTimer = 5000;
                        me->GetMotionMaster()->MovePoint(0, waypoint[cur_wp][0], waypoint[cur_wp][1], waypoint[cur_wp][2]);
                        WaitTimer = 0;
                        return;
                    }
                    else
                        Platforms_Move_Timer -= diff;
                }
                else
                {
                    if (Charge_Timer <= diff)
                    {
                        Unit* target= SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                        if (target)
                            DoCast(target, SPELL_CHARGE);
                        Charge_Timer = 30000;
                    }
                    else
                        Charge_Timer -= diff;

                    if (MeltArmor_Timer <= diff)
                    {
                        DoCastVictim(SPELL_MELT_ARMOR);
                        MeltArmor_Timer = 60000;
                    }
                    else
                        MeltArmor_Timer -= diff;

                    if (DiveBomb_Timer <= diff)
                    {
                        me->AttackStop();
                        me->GetMotionMaster()->MovePoint(6, waypoint[4][0], waypoint[4][1], waypoint[4][2]);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 50);
                        WaitEvent = WE_METEOR;
                        WaitTimer = 0;
                        DiveBomb_Timer = 40000 + rand32() % 5000;
                        return;
                    }
                    else
                        DiveBomb_Timer -= diff;

                    if (FlamePatch_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            Creature* Summoned = me->SummonCreature(CREATURE_FLAME_PATCH_ALAR, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 120000);
                            if (Summoned)
                            {
                                Summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                Summoned->SetObjectScale(Summoned->GetObjectScale() * 2.5f);
                                Summoned->SetDisplayId(11686);
                                Summoned->SetFaction(me->GetFaction());
                                Summoned->SetLevel(me->getLevel());
                                Summoned->CastSpell(Summoned, SPELL_FLAME_PATCH, false);
                            }
                        }
                        FlamePatch_Timer = 30000;
                    }
                    else
                        FlamePatch_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void DoMeleeAttackIfReady()
            {
                if (me->isAttackReady() && !me->IsNonMeleeSpellCast(false))
                {
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        me->AttackerStateUpdate(me->GetVictim());
                        me->resetAttackTimer();
                    }
                    else
                    {
                        if (Unit* target = me->SelectNearestTargetInAttackDistance(5))
                            AttackStart(target);
                        else
                        {
                            DoCast(me, SPELL_FLAME_BUFFET, true);
                            me->setAttackTimer(BASE_ATTACK, 1500);
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_alarAI>(creature);
        }
};

class npc_ember_of_alar : public CreatureScript
{
    public:
        npc_ember_of_alar() : CreatureScript("npc_ember_of_alar") { }

        struct npc_ember_of_alarAI : public ScriptedAI
        {
            npc_ember_of_alarAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
                creature->SetDisableGravity(true);
                creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
            }

            void Initialize()
            {
                toDie = false;
            }

            InstanceScript* instance;
            bool toDie;

            void Reset() override
            {
                Initialize();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                DoZoneInCombat();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                me->setDeathState(JUST_DIED);
            }

            void DamageTaken(Unit* killer, uint32& damage) override
            {
                if (damage >= me->GetHealth() && killer != me && !toDie)
                {
                    damage = 0;
                    DoCast(me, SPELL_EMBER_BLAST, true);
                    me->SetDisplayId(11686);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    if (instance->GetBossState(DATA_ALAR) == IN_PROGRESS)
                    {
                        if (Unit* Alar = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_ALAR)))
                        {
                            int32 AlarHealth = int32(Alar->GetHealth()) - int32(Alar->CountPctFromMaxHealth(3));
                            if (AlarHealth > 0)
                                Alar->SetHealth(AlarHealth);
                            else
                                Alar->SetHealth(1);
                        }
                    }
                    toDie = true;
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                if (toDie)
                {
                    me->KillSelf();
                    //me->SetVisibility(VISIBILITY_OFF);
                }

                DoMeleeAttackIfReady();
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<npc_ember_of_alarAI>(creature);
        }
};

class npc_flame_patch_alar : public CreatureScript
{
    public:
        npc_flame_patch_alar() : CreatureScript("npc_flame_patch_alar") { }

        struct npc_flame_patch_alarAI : public ScriptedAI
        {
            npc_flame_patch_alarAI(Creature* creature) : ScriptedAI(creature) { }
            void Reset() override { }
            void JustEngagedWith(Unit* /*who*/) override { }
            void AttackStart(Unit* /*who*/) override { }
            void MoveInLineOfSight(Unit* /*who*/) override { }

            void UpdateAI(uint32 /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<npc_flame_patch_alarAI>(creature);
        }
};

// 34229 - Flame Quills
class spell_alar_flame_quills : public AuraScript
{
    PrepareAuraScript(spell_alar_flame_quills);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(flameQuillsSpells);
    }

    bool Load() override
    {
        return InstanceHasScript(GetUnitOwner(), TheEyeScriptName);
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        // cast 24 spells 34269-34289, 34314-34316
        for (uint32 spellId : flameQuillsSpells)
            GetTarget()->CastSpell(nullptr, spellId, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alar_flame_quills::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_alar()
{
    new boss_alar();
    new npc_ember_of_alar();
    new npc_flame_patch_alar();
    RegisterAuraScript(spell_alar_flame_quills);
}
