/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Grand_Warlock_Nethekurse
SD%Complete: 75
SDComment: encounter not fully completed. missing part where boss kill minions.
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_grand_warlock_nethekurse
npc_fel_orc_convert
npc_lesser_shadow_fissure
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"

enum Says
{
    SAY_INTRO          = 0,
    SAY_PEON_ATTACKED  = 1,
    SAY_PEON_DIES      = 2,
    SAY_TAUNT          = 3,
    SAY_AGGRO          = 4,
    SAY_SLAY           = 5,
    SAY_DIE            = 6
};

enum Spells
{
    SPELL_DEATH_COIL           = 30500, // 30741 heroic
    SPELL_DARK_SPIN            = 30502, // core bug spell attack caster :D
    SPELL_SHADOW_FISSURE       = 30496, // Summon the ShadowFissure NPC
    SPELL_SHADOW_CLEAVE        = 30495,
    H_SPELL_SHADOW_SLAM        = 35953,
    SPELL_HEMORRHAGE           = 30478,
    SPELL_CONSUMPTION          = 30497,
    SPELL_TEMPORARY_VISUAL     = 39312, // this is wrong, a temporary solution. spell consumption already has the purple visual, but doesn't display as it should

    SPELL_SHADOW_SEAR          = 30735 // cast on entry 17083 which then makes sound 1343
    // 30948 cast on self by 17687
};

enum SetData
{
    SETDATA_DATA               = 1,
    SETDATA_PEON_AGGRO         = 1,
    SETDATA_PEON_DEATH         = 2
};

enum Events
{
    // Fel Orc Convert
    EVENT_HEMORRHAGE           = 1
};

// ########################################################
// Grand Warlock Nethekurse
// ########################################################

class boss_grand_warlock_nethekurse : public CreatureScript
{
    public:
        boss_grand_warlock_nethekurse() : CreatureScript("boss_grand_warlock_nethekurse") { }

        struct boss_grand_warlock_nethekurseAI : public BossAI
        {
            boss_grand_warlock_nethekurseAI(Creature* creature) : BossAI(creature, DATA_NETHEKURSE)
            {
                Initialize();
            }

            void Initialize()
            {
                IsIntroEvent = false;
                IntroOnce = false;
                IsMainEvent = false;
                //HasTaunted = false;
                SpinOnce = false;
                Phase = false;

                PeonEngagedCount = 0;
                PeonKilledCount = 0;

                IntroEvent_Timer = 90000;    // how long before getting bored and kills his minions?
                DeathCoil_Timer = 20000;
                ShadowFissure_Timer = 8000;
                Cleave_Timer = 5000;
            }

            void Reset() override
            {
                _Reset();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                Initialize();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DIE);
            }

            void SetData(uint32 data, uint32 value) override
            {
                if (data != SETDATA_DATA)
                    return;

                switch (value)
                {
                    case SETDATA_PEON_AGGRO:
                        if (PeonEngagedCount >= 4)
                            return;

                        Talk(SAY_PEON_ATTACKED);
                        ++PeonEngagedCount;
                        break;
                    case SETDATA_PEON_DEATH:
                        if (PeonKilledCount >= 4)
                            return;

                        Talk(SAY_PEON_DIES);
                        ++PeonKilledCount;

                        if (PeonKilledCount == 4)
                        {
                            IsIntroEvent = false;
                            IsMainEvent = true;
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        break;
                    default:
                        break;
                }
            }

            void DoTauntPeons()
            {
                Talk(SAY_TAUNT);

                /// @todo kill the peons first
                IsIntroEvent = false;
                PeonEngagedCount = 4;
                PeonKilledCount = 4;
                IsMainEvent = true;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void AttackStart(Unit* who) override
            {
                if (IsIntroEvent || !IsMainEvent)
                    return;

                if (me->Attack(who, true))
                {
                    if (Phase)
                        DoStartNoMovement(who);
                    else
                        DoStartMovement(who);
                }
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!IntroOnce && me->IsWithinDistInMap(who, 30.0f))
                {
                    if (who->GetTypeId() != TYPEID_PLAYER)
                        return;

                    Talk(SAY_INTRO);
                    IntroOnce = true;
                    IsIntroEvent = true;

                    instance->SetBossState(DATA_NETHEKURSE, IN_PROGRESS);
                }

                if (IsIntroEvent || !IsMainEvent)
                    return;

                ScriptedAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned) override
            {
                summoned->setFaction(16);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                //triggered spell of consumption does not properly show it's SpellVisual, wrong spellid?
                summoned->CastSpell(summoned, SPELL_TEMPORARY_VISUAL, true);
                summoned->CastSpell(summoned, SPELL_CONSUMPTION, false, 0, 0, me->GetGUID());
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (IsIntroEvent)
                {
                    if (instance->GetBossState(DATA_NETHEKURSE) == IN_PROGRESS)
                    {
                        if (IntroEvent_Timer <= diff)
                            DoTauntPeons();
                        else
                            IntroEvent_Timer -= diff;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (!IsMainEvent)
                    return;

                if (Phase)
                {
                    if (!SpinOnce)
                    {
                        DoCastVictim(SPELL_DARK_SPIN);
                        SpinOnce = true;
                    }

                    if (Cleave_Timer <= diff)
                    {
                        DoCastVictim(SPELL_SHADOW_CLEAVE);
                        Cleave_Timer = 6000 + rand32() % 2500;
                    }
                    else
                        Cleave_Timer -= diff;
                }
                else
                {
                    if (ShadowFissure_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_FISSURE);
                        ShadowFissure_Timer = urand(7500, 15000);
                    }
                    else
                        ShadowFissure_Timer -= diff;

                    if (DeathCoil_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_DEATH_COIL);
                        DeathCoil_Timer = urand(15000, 20000);
                    }
                    else
                        DeathCoil_Timer -= diff;

                    if (!HealthAbovePct(20))
                        Phase = true;

                    DoMeleeAttackIfReady();
                }
            }

            private:
                uint32 PeonEngagedCount;
                uint32 PeonKilledCount;
                uint32 IntroEvent_Timer;
                uint32 DeathCoil_Timer;
                uint32 ShadowFissure_Timer;
                uint32 Cleave_Timer;
                bool IntroOnce;
                bool IsIntroEvent;
                bool IsMainEvent;
                bool SpinOnce;
                //bool HasTaunted;
                bool Phase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_grand_warlock_nethekurseAI>(creature);
        }
};

// ########################################################
// Fel Orc Convert
// ########################################################

class npc_fel_orc_convert : public CreatureScript
{
    public:
        npc_fel_orc_convert() : CreatureScript("npc_fel_orc_convert") { }

        struct npc_fel_orc_convertAI : public ScriptedAI
        {
            npc_fel_orc_convertAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                me->SetNoCallAssistance(true);              //we don't want any assistance (WE R HEROZ!)
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_HEMORRHAGE, 3000);

                if (Creature* Kurse = ObjectAccessor::GetCreature(*me, instance->GetGuidData(NPC_GRAND_WARLOCK_NETHEKURSE)))
                    if (me->IsWithinDist(Kurse, 45.0f))
                        Kurse->AI()->SetData(SETDATA_DATA, SETDATA_PEON_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (instance->GetBossState(DATA_NETHEKURSE) != IN_PROGRESS)
                    return;

                if (Creature* Kurse = ObjectAccessor::GetCreature(*me, instance->GetGuidData(NPC_GRAND_WARLOCK_NETHEKURSE)))
                    Kurse->AI()->SetData(SETDATA_DATA, SETDATA_PEON_DEATH);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_HEMORRHAGE)
                {
                    DoCastVictim(SPELL_HEMORRHAGE);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, 15000);
                }

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* instance;
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_fel_orc_convertAI>(creature);
        }
};

// ########################################################
// Lesser Shadow Fissure
// ########################################################

class npc_lesser_shadow_fissure : public CreatureScript
{
    public:
        npc_lesser_shadow_fissure() : CreatureScript("npc_lesser_shadow_fissure") { }

        struct npc_lesser_shadow_fissureAI : public ScriptedAI
        {
            npc_lesser_shadow_fissureAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override { }
            void MoveInLineOfSight(Unit* /*who*/) override { }
            void AttackStart(Unit* /*who*/) override { }
            void EnterCombat(Unit* /*who*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_lesser_shadow_fissureAI(creature);
        }
};

void AddSC_boss_grand_warlock_nethekurse()
{
    new boss_grand_warlock_nethekurse();
    new npc_fel_orc_convert();
    new npc_lesser_shadow_fissure();
}
