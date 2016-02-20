/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss Mr.Smite
SD%Complete:
SDComment: Timers and say taken from acid script
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "deadmines.h"

enum Spells
{
    SPELL_TRASH             = 3391,
    SPELL_SMITE_STOMP       = 6432,
    SPELL_SMITE_SLAM        = 6435,
    SPELL_NIMBLE_REFLEXES   = 6264
};

enum Equips
{
    EQUIP_SWORD             = 5191,
    EQUIP_AXE               = 5196,
    EQUIP_MACE              = 7230
};

enum Texts
{
    SAY_PHASE_1             = 2,
    SAY_PHASE_2             = 3
};

class boss_mr_smite : public CreatureScript
{
public:
    boss_mr_smite() : CreatureScript("boss_mr_smite") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_mr_smiteAI>(creature);
    }

    struct boss_mr_smiteAI : public ScriptedAI
    {
        boss_mr_smiteAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiTrashTimer = urand(5000, 9000);
            uiSlamTimer = 9000;
            uiNimbleReflexesTimer = urand(15500, 31600);

            uiHealth = 0;

            uiPhase = 0;
            uiTimer = 0;

            uiIsMoving = false;
        }

        InstanceScript* instance;

        uint32 uiTrashTimer;
        uint32 uiSlamTimer;
        uint32 uiNimbleReflexesTimer;

        uint8 uiHealth;

        uint32 uiPhase;
        uint32 uiTimer;

        bool uiIsMoving;

        void Reset() override
        {
            Initialize();

            SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        bool bCheckChances()
        {
            uint32 uiChances = urand(0, 99);
            if (uiChances <= 15)
                return false;
            else
                return true;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictim())
                return;

            if (!uiIsMoving) // halt abilities in between phases
            {
                if (uiTrashTimer <= uiDiff)
                {
                    if (bCheckChances())
                        DoCast(me, SPELL_TRASH);
                    uiTrashTimer = urand(6000, 15500);
                }
                else uiTrashTimer -= uiDiff;

                if (uiSlamTimer <= uiDiff)
                {
                    if (bCheckChances())
                        DoCastVictim(SPELL_SMITE_SLAM);
                    uiSlamTimer = 11000;
                }
                else uiSlamTimer -= uiDiff;

                if (uiNimbleReflexesTimer <= uiDiff)
                {
                    if (bCheckChances())
                        DoCast(me, SPELL_NIMBLE_REFLEXES);
                    uiNimbleReflexesTimer = urand(27300, 60100);
                }
                else uiNimbleReflexesTimer -= uiDiff;
            }

            if ((uiHealth == 0 && !HealthAbovePct(66)) || (uiHealth == 1 && !HealthAbovePct(33)))
            {
                ++uiHealth;
                DoCastAOE(SPELL_SMITE_STOMP, false);
                SetCombatMovement(false);
                me->AttackStop();
                me->InterruptNonMeleeSpells(false);
                me->SetReactState(REACT_PASSIVE);
                uiTimer = 2500;
                uiPhase = 1;

                switch (uiHealth)
                {
                    case 1:
                        Talk(SAY_PHASE_1);
                        break;
                    case 2:
                        Talk(SAY_PHASE_2);
                        break;
                }
            }

            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                        {
                            if (uiIsMoving)
                                break;

                            if (GameObject* go = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_SMITE_CHEST)))
                            {
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MovePoint(1, go->GetPositionX() - 1.5f, go->GetPositionY() + 1.4f, go->GetPositionZ());
                                uiIsMoving = true;
                            }
                            break;
                        }
                        case 2:
                            if (uiHealth == 1)
                                SetEquipmentSlots(false, EQUIP_AXE, EQUIP_AXE, EQUIP_NO_CHANGE);
                            else
                                SetEquipmentSlots(false, EQUIP_MACE, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                            uiTimer = 500;
                            uiPhase = 3;
                            break;
                        case 3:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            uiTimer = 750;
                            uiPhase = 4;
                            break;
                        case 4:
                            me->SetReactState(REACT_AGGRESSIVE);
                            SetCombatMovement(true);
                            me->GetMotionMaster()->MoveChase(me->GetVictim(), me->m_CombatDistance);
                            uiIsMoving = false;
                            uiPhase = 0;
                            break;
                    }
                } else uiTimer -= uiDiff;
            }

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->SetFacingTo(5.47f);
            me->SetStandState(UNIT_STAND_STATE_KNEEL);

            uiTimer = 2000;
            uiPhase = 2;
        }
    };
};

void AddSC_boss_mr_smite()
{
    new boss_mr_smite();
}
