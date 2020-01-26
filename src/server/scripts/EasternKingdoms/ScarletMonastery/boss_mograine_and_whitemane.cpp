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
SDName: Boss_Mograine_And_Whitemane
SD%Complete: 90
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Says
{
    //Mograine says
    SAY_MO_AGGRO                 = 0,
    SAY_MO_KILL                  = 1,
    SAY_MO_RESURRECTED           = 2,

    //Whitemane says
    SAY_WH_INTRO                 = 0,
    SAY_WH_KILL                  = 1,
    SAY_WH_RESURRECT             = 2,
};

enum Spells
{
    //Mograine Spells
    SPELL_CRUSADERSTRIKE         = 14518,
    SPELL_HAMMEROFJUSTICE        = 5589,
    SPELL_LAYONHANDS             = 9257,
    SPELL_RETRIBUTIONAURA        = 8990,

    //Whitemanes Spells
    SPELL_DEEPSLEEP              = 9256,
    SPELL_SCARLETRESURRECTION    = 9232,
    SPELL_DOMINATEMIND           = 14515,
    SPELL_HOLYSMITE              = 9481,
    SPELL_HEAL                   = 12039,
    SPELL_POWERWORDSHIELD        = 22187
};

class boss_scarlet_commander_mograine : public CreatureScript
{
public:
    boss_scarlet_commander_mograine() : CreatureScript("boss_scarlet_commander_mograine") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScarletMonasteryAI<boss_scarlet_commander_mograineAI>(creature);
    }

    struct boss_scarlet_commander_mograineAI : public ScriptedAI
    {
        boss_scarlet_commander_mograineAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            CrusaderStrike_Timer = 10000;
            HammerOfJustice_Timer = 10000;
            _bHasDied = false;
            _bHeal = false;
            _bFakeDeath = false;
        }

        InstanceScript* instance;

        uint32 CrusaderStrike_Timer;
        uint32 HammerOfJustice_Timer;

        bool _bHasDied;
        bool _bHeal;
        bool _bFakeDeath;

        void Reset() override
        {
            Initialize();

            //Incase wipe during phase that mograine fake death
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);

            if (me->IsAlive())
                instance->SetBossState(DATA_MOGRAINE_AND_WHITE_EVENT, NOT_STARTED);
        }

        void JustReachedHome() override
        {
            if (instance->GetBossState(DATA_MOGRAINE_AND_WHITE_EVENT) != NOT_STARTED)
                instance->SetBossState(DATA_MOGRAINE_AND_WHITE_EVENT, FAIL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_MO_AGGRO);
            DoCast(me, SPELL_RETRIBUTIONAURA);

            me->CallForHelp(VISIBLE_RANGE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_MO_KILL);
        }

        void DamageTaken(Unit* /*doneBy*/, uint32 &damage) override
        {
            if (damage < me->GetHealth() || _bHasDied || _bFakeDeath)
                return;

            //On first death, fake death and open door, as well as initiate whitemane if exist
            if (Unit* Whitemane = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_WHITEMANE)))
            {
                instance->SetBossState(DATA_MOGRAINE_AND_WHITE_EVENT, IN_PROGRESS);

                Whitemane->GetMotionMaster()->MovePoint(1, 1163.113370f, 1398.856812f, 32.527786f);

                me->GetMotionMaster()->MovementExpired();
                me->GetMotionMaster()->MoveIdle();

                me->SetHealth(0);

                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                me->RemoveAllAuras();
                me->ClearAllReactives();

                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                _bHasDied = true;
                _bFakeDeath = true;

                damage = 0;
            }
        }

        void SpellHit(Unit* /*who*/, const SpellInfo* spell) override
        {
            //When hit with resurrection say text
            if (spell->Id == SPELL_SCARLETRESURRECTION)
            {
                Talk(SAY_MO_RESURRECTED);
                _bFakeDeath = false;

                instance->SetBossState(DATA_MOGRAINE_AND_WHITE_EVENT, SPECIAL);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (_bHasDied && !_bHeal && instance->GetBossState(DATA_MOGRAINE_AND_WHITE_EVENT) == SPECIAL)
            {
                //On resurrection, stop fake death and heal whitemane and resume fight
                if (Unit* Whitemane = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_WHITEMANE)))
                {
                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    DoCast(Whitemane, SPELL_LAYONHANDS);

                    CrusaderStrike_Timer = 10000;
                    HammerOfJustice_Timer = 10000;

                    if (me->GetVictim())
                        me->GetMotionMaster()->MoveChase(me->GetVictim());

                    _bHeal = true;
                }
            }

            //This if-check to make sure mograine does not attack while fake death
            if (_bFakeDeath)
                return;

            //CrusaderStrike_Timer
            if (CrusaderStrike_Timer <= diff)
            {
                DoCastVictim(SPELL_CRUSADERSTRIKE);
                CrusaderStrike_Timer = 10000;
            }
            else CrusaderStrike_Timer -= diff;

            //HammerOfJustice_Timer
            if (HammerOfJustice_Timer <= diff)
            {
                DoCastVictim(SPELL_HAMMEROFJUSTICE);
                HammerOfJustice_Timer = 60000;
            }
            else HammerOfJustice_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_high_inquisitor_whitemane : public CreatureScript
{
public:
    boss_high_inquisitor_whitemane() : CreatureScript("boss_high_inquisitor_whitemane") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScarletMonasteryAI<boss_high_inquisitor_whitemaneAI>(creature);
    }

    struct boss_high_inquisitor_whitemaneAI : public ScriptedAI
    {
        boss_high_inquisitor_whitemaneAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            Wait_Timer = 7000;
            Heal_Timer = 10000;
            PowerWordShield_Timer = 15000;
            HolySmite_Timer = 6000;

            _bCanResurrectCheck = false;
            _bCanResurrect = false;
        }

        InstanceScript* instance;

        uint32 Heal_Timer;
        uint32 PowerWordShield_Timer;
        uint32 HolySmite_Timer;
        uint32 Wait_Timer;

        bool _bCanResurrectCheck;
        bool _bCanResurrect;

        void Reset() override
        {
            Initialize();

            if (me->IsAlive())
                instance->SetBossState(DATA_MOGRAINE_AND_WHITE_EVENT, NOT_STARTED);
        }

        void AttackStart(Unit* who) override
        {
            if (instance->GetBossState(DATA_MOGRAINE_AND_WHITE_EVENT) == NOT_STARTED)
                return;

            ScriptedAI::AttackStart(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_WH_INTRO);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_WH_KILL);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!_bCanResurrectCheck && damage >= me->GetHealth())
                damage = me->GetHealth() - 1;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (_bCanResurrect)
            {
                //When casting resuruction make sure to delay so on rez when reinstate battle deepsleep runs out
                if (Wait_Timer <= diff)
                {
                    if (Creature* mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                    {
                        DoCast(mograine, SPELL_SCARLETRESURRECTION);
                        Talk(SAY_WH_RESURRECT);
                        _bCanResurrect = false;
                    }
                }
                else Wait_Timer -= diff;
            }

            //Cast Deep sleep when health is less than 50%
            if (!_bCanResurrectCheck && !HealthAbovePct(50))
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                DoCastVictim(SPELL_DEEPSLEEP);
                _bCanResurrectCheck = true;
                _bCanResurrect = true;
                return;
            }

            //while in "resurrect-mode", don't do anything
            if (_bCanResurrect)
                return;

            //If we are <75% hp cast healing spells at self or Mograine
            if (Heal_Timer <= diff)
            {
                Creature* target = NULL;

                if (!HealthAbovePct(75))
                    target = me;

                if (Creature* mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                {
                    // checking _bCanResurrectCheck prevents her healing Mograine while he is "faking death"
                    if (_bCanResurrectCheck && mograine->IsAlive() && !mograine->HealthAbovePct(75))
                        target = mograine;
                }

                if (target)
                    DoCast(target, SPELL_HEAL);

                Heal_Timer = 13000;
            }
            else Heal_Timer -= diff;

            //PowerWordShield_Timer
            if (PowerWordShield_Timer <= diff)
            {
                DoCast(me, SPELL_POWERWORDSHIELD);
                PowerWordShield_Timer = 15000;
            }
            else PowerWordShield_Timer -= diff;

            //HolySmite_Timer
            if (HolySmite_Timer <= diff)
            {
                DoCastVictim(SPELL_HOLYSMITE);
                HolySmite_Timer = 6000;
            }
            else HolySmite_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_mograine_and_whitemane()
{
    new boss_scarlet_commander_mograine();
    new boss_high_inquisitor_whitemane();
}
