/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss General Bjarngrim
SD%Complete: 70%
SDComment: Waypoint needed, we expect boss to always have 2x Stormforged Lieutenant following
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_lightning.h"

enum Yells
{
    SAY_AGGRO                               = 0,
    SAY_DEFENSIVE_STANCE                    = 1,
    SAY_BATTLE_STANCE                       = 2,
    SAY_BERSEKER_STANCE                     = 3,
    SAY_SLAY                                = 4,
    SAY_DEATH                               = 5,
    EMOTE_DEFENSIVE_STANCE                  = 6,
    EMOTE_BATTLE_STANCE                     = 7,
    EMOTE_BERSEKER_STANCE                   = 8
};

enum Spells
{
    SPELL_DEFENSIVE_STANCE                  = 53790,
    //SPELL_DEFENSIVE_AURA                    = 41105,
    SPELL_SPELL_REFLECTION                  = 36096,
    SPELL_PUMMEL                            = 12555,
    SPELL_KNOCK_AWAY                        = 52029,
    SPELL_IRONFORM                          = 52022,

    SPELL_BERSEKER_STANCE                   = 53791,
    //SPELL_BERSEKER_AURA                     = 41107,
    SPELL_INTERCEPT                         = 58769,
    SPELL_WHIRLWIND                         = 52027,
    SPELL_CLEAVE                            = 15284,

    SPELL_BATTLE_STANCE                     = 53792,
    //SPELL_BATTLE_AURA                       = 41106,
    SPELL_MORTAL_STRIKE                     = 16856,
    SPELL_SLAM                              = 52026,

    //OTHER SPELLS
    //SPELL_CHARGE_UP                         = 52098,      // only used when starting walk from one platform to the other
    SPELL_TEMPORARY_ELECTRICAL_CHARGE       = 52092,      // triggered part of above

    SPELL_ARC_WELD                          = 59085,
    SPELL_RENEW_STEEL_N                     = 52774,
    SPELL_RENEW_STEEL_H                     = 59160
};

enum Creatures
{
    NPC_STORMFORGED_LIEUTENANT              = 29240
};

enum Equips
{
    EQUIP_SWORD                             = 37871,
    EQUIP_SHIELD                            = 35642,
    EQUIP_MACE                              = 43623
};

enum Stanges
{
    STANCE_DEFENSIVE                        = 0,
    STANCE_BERSERKER                        = 1,
    STANCE_BATTLE                           = 2
};

/*######
## boss_bjarngrim
######*/

class boss_bjarngrim : public CreatureScript
{
public:
    boss_bjarngrim() : CreatureScript("boss_bjarngrim") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_bjarngrimAI>(creature);
    }

    struct boss_bjarngrimAI : public ScriptedAI
    {
        boss_bjarngrimAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            m_uiStance = STANCE_DEFENSIVE;
            memset(&m_auiStormforgedLieutenantGUID, 0, sizeof(m_auiStormforgedLieutenantGUID));
            canBuff = true;
        }

        InstanceScript* instance;

        bool m_bIsChangingStance;
        bool canBuff;

        uint8 m_uiChargingStatus;
        uint8 m_uiStance;

        uint32 m_uiCharge_Timer;
        uint32 m_uiChangeStance_Timer;

        uint32 m_uiReflection_Timer;
        uint32 m_uiKnockAway_Timer;
        uint32 m_uiPummel_Timer;
        uint32 m_uiIronform_Timer;

        uint32 m_uiIntercept_Timer;
        uint32 m_uiWhirlwind_Timer;
        uint32 m_uiCleave_Timer;

        uint32 m_uiMortalStrike_Timer;
        uint32 m_uiSlam_Timer;

        uint64 m_auiStormforgedLieutenantGUID[2];

        void Reset() override
        {
            if (canBuff)
                if (!me->HasAura(SPELL_TEMPORARY_ELECTRICAL_CHARGE))
                    me->AddAura(SPELL_TEMPORARY_ELECTRICAL_CHARGE, me);

            m_bIsChangingStance = false;

            m_uiChargingStatus = 0;
            m_uiCharge_Timer = 1000;

            m_uiChangeStance_Timer = urand(20000, 25000);

            m_uiReflection_Timer = 8000;
            m_uiKnockAway_Timer = 20000;
            m_uiPummel_Timer = 10000;
            m_uiIronform_Timer = 25000;

            m_uiIntercept_Timer = 5000;
            m_uiWhirlwind_Timer = 10000;
            m_uiCleave_Timer = 8000;

            m_uiMortalStrike_Timer = 8000;
            m_uiSlam_Timer = 10000;

            for (uint8 i = 0; i < 2; ++i)
            {
                if (Creature* pStormforgedLieutenant = ObjectAccessor::GetCreature(*me, m_auiStormforgedLieutenantGUID[i]))
                    if (!pStormforgedLieutenant->IsAlive())
                        pStormforgedLieutenant->Respawn();
            }

            if (m_uiStance != STANCE_DEFENSIVE)
            {
                DoRemoveStanceAura(m_uiStance);
                DoCast(me, SPELL_DEFENSIVE_STANCE);
                m_uiStance = STANCE_DEFENSIVE;
            }

            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);

            instance->SetBossState(DATA_BJARNGRIM, NOT_STARTED);
        }

        void EnterEvadeMode() override
        {
            if (me->HasAura(SPELL_TEMPORARY_ELECTRICAL_CHARGE))
                canBuff = true;
            else
                canBuff = false;

            ScriptedAI::EnterEvadeMode();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            //must get both lieutenants here and make sure they are with him
            me->CallForHelp(30.0f);

            instance->SetBossState(DATA_BJARNGRIM, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetBossState(DATA_BJARNGRIM, DONE);
        }

        /// @todo remove when removal is done by the core
        void DoRemoveStanceAura(uint8 uiStance)
        {
            switch (uiStance)
            {
                case STANCE_DEFENSIVE:
                    me->RemoveAurasDueToSpell(SPELL_DEFENSIVE_STANCE);
                    break;
                case STANCE_BERSERKER:
                    me->RemoveAurasDueToSpell(SPELL_BERSEKER_STANCE);
                    break;
                case STANCE_BATTLE:
                    me->RemoveAurasDueToSpell(SPELL_BATTLE_STANCE);
                    break;
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            // Change stance
            if (m_uiChangeStance_Timer <= uiDiff)
            {
                //wait for current spell to finish before change stance
                if (me->IsNonMeleeSpellCast(false))
                    return;

                DoRemoveStanceAura(m_uiStance);

                int uiTempStance = rand()%(3-1);

                if (uiTempStance >= m_uiStance)
                    ++uiTempStance;

                m_uiStance = uiTempStance;

                switch (m_uiStance)
                {
                    case STANCE_DEFENSIVE:
                        Talk(SAY_DEFENSIVE_STANCE);
                        Talk(EMOTE_DEFENSIVE_STANCE);
                        DoCast(me, SPELL_DEFENSIVE_STANCE);
                        SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);
                        break;
                    case STANCE_BERSERKER:
                        Talk(SAY_BERSEKER_STANCE);
                        Talk(EMOTE_BERSEKER_STANCE);
                        DoCast(me, SPELL_BERSEKER_STANCE);
                        SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SWORD, EQUIP_NO_CHANGE);
                        break;
                    case STANCE_BATTLE:
                        Talk(SAY_BATTLE_STANCE);
                        Talk(EMOTE_BATTLE_STANCE);
                        DoCast(me, SPELL_BATTLE_STANCE);
                        SetEquipmentSlots(false, EQUIP_MACE, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                        break;
                }

                m_uiChangeStance_Timer = urand(20000, 25000);
                return;
            }
            else
                m_uiChangeStance_Timer -= uiDiff;

            switch (m_uiStance)
            {
                case STANCE_DEFENSIVE:
                {
                    if (m_uiReflection_Timer <= uiDiff)
                    {
                        DoCast(me, SPELL_SPELL_REFLECTION);
                        m_uiReflection_Timer = urand(8000, 9000);
                    }
                    else
                        m_uiReflection_Timer -= uiDiff;

                    if (m_uiKnockAway_Timer <= uiDiff)
                    {
                        DoCast(me, SPELL_KNOCK_AWAY);
                        m_uiKnockAway_Timer = urand(20000, 21000);
                    }
                    else
                        m_uiKnockAway_Timer -= uiDiff;

                    if (m_uiPummel_Timer <= uiDiff)
                    {
                        DoCastVictim(SPELL_PUMMEL);
                        m_uiPummel_Timer = urand(10000, 11000);
                    }
                    else
                        m_uiPummel_Timer -= uiDiff;

                    if (m_uiIronform_Timer <= uiDiff)
                    {
                        DoCast(me, SPELL_IRONFORM);
                        m_uiIronform_Timer = urand(25000, 26000);
                    }
                    else
                        m_uiIronform_Timer -= uiDiff;

                    break;
                }
                case STANCE_BERSERKER:
                {
                    if (m_uiIntercept_Timer <= uiDiff)
                    {
                        //not much point is this, better random target and more often?
                        DoCastVictim(SPELL_INTERCEPT);
                        m_uiIntercept_Timer = urand(45000, 46000);
                    }
                    else
                        m_uiIntercept_Timer -= uiDiff;

                    if (m_uiWhirlwind_Timer <= uiDiff)
                    {
                        DoCast(me, SPELL_WHIRLWIND);
                        m_uiWhirlwind_Timer = urand(10000, 11000);
                    }
                    else
                        m_uiWhirlwind_Timer -= uiDiff;

                    if (m_uiCleave_Timer <= uiDiff)
                    {
                        DoCastVictim(SPELL_CLEAVE);
                        m_uiCleave_Timer = urand(8000, 9000);
                    }
                    else
                        m_uiCleave_Timer -= uiDiff;

                    break;
                }
                case STANCE_BATTLE:
                {
                    if (m_uiMortalStrike_Timer <= uiDiff)
                    {
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        m_uiMortalStrike_Timer = urand(20000, 21000);
                    }
                    else
                        m_uiMortalStrike_Timer -= uiDiff;

                    if (m_uiSlam_Timer <= uiDiff)
                    {
                        DoCastVictim(SPELL_SLAM);
                        m_uiSlam_Timer = urand(15000, 16000);
                    }
                    else
                        m_uiSlam_Timer -= uiDiff;

                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_stormforged_lieutenant
######*/

class npc_stormforged_lieutenant : public CreatureScript
{
public:
    npc_stormforged_lieutenant() : CreatureScript("npc_stormforged_lieutenant") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_stormforged_lieutenantAI>(creature);
    }

    struct npc_stormforged_lieutenantAI : public ScriptedAI
    {
        npc_stormforged_lieutenantAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiArcWeld_Timer;
        uint32 m_uiRenewSteel_Timer;

        void Reset() override
        {
            m_uiArcWeld_Timer = urand(20000, 21000);
            m_uiRenewSteel_Timer = urand(10000, 11000);
        }

        void EnterCombat(Unit* who) override
        {
            if (Creature* pBjarngrim = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BJARNGRIM)))
            {
                if (pBjarngrim->IsAlive() && !pBjarngrim->GetVictim())
                    pBjarngrim->AI()->AttackStart(who);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (m_uiArcWeld_Timer <= uiDiff)
            {
                DoCastVictim(SPELL_ARC_WELD);
                m_uiArcWeld_Timer = urand(20000, 21000);
            }
            else
                m_uiArcWeld_Timer -= uiDiff;

            if (m_uiRenewSteel_Timer <= uiDiff)
            {
                if (Creature* pBjarngrim = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BJARNGRIM)))
                {
                    if (pBjarngrim->IsAlive())
                        DoCast(pBjarngrim, SPELL_RENEW_STEEL_N);
                }
                m_uiRenewSteel_Timer = urand(10000, 14000);
            }
            else
                m_uiRenewSteel_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_bjarngrim()
{
    new boss_bjarngrim();
    new npc_stormforged_lieutenant();
}
