/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss Black Knight
SD%Complete: 95%
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "Vehicle.h"
#include "ScriptedEscortAI.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //phase 1
    SPELL_PLAGUE_STRIKE     = 67884,
    SPELL_PLAGUE_STRIKE_2   = 67724,
    SPELL_ICY_TOUCH_H       = 67881,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_DEATH_RESPITE_2   = 68306,
    SPELL_DEATH_RESPITE_3   = 66798,
    SPELL_OBLITERATE_H      = 67883,
    SPELL_OBLITERATE        = 67725,
    SPELL_RAISE_ARELAS      = 67705,
    SPELL_RAISE_JAEREN      = 67715,

    //phase 2 - During this phase, the Black Knight will use the same abilities as in phase 1, except for Death's Respite
    SPELL_ARMY_DEAD         = 67761,
    SPELL_DESECRATION       = 67778,
    SPELL_GHOUL_EXPLODE     = 67751,
    SPELL_EXPLODE           = 67729,
    SPELL_EXPLODE_H         = 67886,

    //phase 3
    SPELL_DEATH_BITE_H      = 67875,
    SPELL_DEATH_BITE        = 67808,
    SPELL_MARKED_DEATH      = 67882,
    SPELL_MARKED_DEATH_2    = 67823,

    SPELL_BLACK_KNIGHT_RES  = 67693,

    SPELL_CLAW              = 67774,
    SPELL_CLAW_H            = 67879,
    SPELL_LEAP              = 67749,
    SPELL_LEAP_H            = 67880
};

enum eModels
{
    MODEL_SKELETON = 29846,
    MODEL_GHOST    = 21300
};

enum ePhases
{
    PHASE_UNDEAD    = 1,
    PHASE_SKELETON  = 2,
    PHASE_GHOST     = 3
};

enum Says
{
    SAY_AGGRO    = 1,
    SAY_KILL     = 2,
    SAY_SKELETON = 3,
    SAY_GHOST    = 4,
    SAY_DEATH    = 5,
};

class boss_black_knight : public CreatureScript
{
public:
    boss_black_knight() : CreatureScript("boss_black_knight") { }

    struct boss_black_knightAI : public ScriptedAI
    {
        boss_black_knightAI(Creature* creature) : ScriptedAI(creature), summons(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        SummonList summons;

        bool resurrectInProgress;
        bool bSummonArmy;
        bool bDeathArmyDone;

        uint8 uiPhase;

        uint32 uiPlagueStrikeTimer;
        uint32 uiIcyTouchTimer;
        uint32 uiDeathRespiteTimer;
        uint32 uiObliterateTimer;
        uint32 uiDesecration;
        uint32 uiResurrectTimer;
        uint32 uiDeathArmyCheckTimer;
        uint32 uiGhoulExplodeTimer;
        uint32 uiDeathBiteTimer;
        uint32 uiMarkedDeathTimer;

        void Reset()
        {
            summons.DespawnAll();
            me->SetDisplayId(me->GetNativeDisplayId());
            SetEquipmentSlots(true);
            me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
            instance->SetData(DATA_I_VE_HAD_WORSE, (uint32)true);

            resurrectInProgress = false;
            bSummonArmy = false;
            bDeathArmyDone = false;

            uiPhase = PHASE_UNDEAD;

            uiIcyTouchTimer = urand(5000, 9000);
            uiPlagueStrikeTimer = urand(10000, 13000);
            uiDeathRespiteTimer = urand(15000, 16000);
            uiObliterateTimer = urand(17000, 19000);
            uiDesecration = urand(15000, 16000);
            uiDeathArmyCheckTimer = 1000;
            uiResurrectTimer = 4000;
            uiGhoulExplodeTimer = 8000;
            uiDeathBiteTimer = urand (2000, 4000);
            uiMarkedDeathTimer = urand (5000, 7000);
        }

        void EnterCombat(Unit* /*attacker*/)
        {
            DoCast(instance->GetData(DATA_TEAM) == ALLIANCE ? SPELL_RAISE_ARELAS : SPELL_RAISE_JAEREN);
            Talk(SAY_AGGRO);

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_BLACK_KNIGHT) != IN_PROGRESS)
                    instance->SetData(BOSS_BLACK_KNIGHT, IN_PROGRESS);
        }

        void JustReachedHome()
        {
            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_BLACK_KNIGHT) == IN_PROGRESS)
                    instance->SetData(BOSS_BLACK_KNIGHT, FAIL);
        }

        void KilledUnit(Unit* target)
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustSummoned(Creature* summon)
        {
            if (summon->GetEntry() == NPC_RISEN_JAEREN || summon->GetEntry() == NPC_RISEN_ARELAS || summon->GetEntry() == NPC_RISEN_CHAMPION)
            {
                summons.Summon(summon);
                summon->AI()->AttackStart(me->getVictim());
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
        {
            summons.Despawn(summon);
            summon->SetCorpseDelay(5*IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target or we are casting
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (resurrectInProgress)
            {
                if (uiResurrectTimer <= diff)
                {
                    me->SetFullHealth();
                    switch (uiPhase)
                    {
                        case PHASE_UNDEAD:
                            Talk(SAY_SKELETON);
                            me->SetDisplayId(MODEL_SKELETON);
                            break;
                        case PHASE_SKELETON:
                            Talk(SAY_GHOST);
                            me->SetDisplayId(MODEL_GHOST);
                            SetEquipmentSlots(false, EQUIP_UNEQUIP);
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                            break;
                    }
                    DoCast(me, SPELL_BLACK_KNIGHT_RES, true);
                    uiPhase++;
                    uiResurrectTimer = 4000;
                    resurrectInProgress = false;
                    me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                } else uiResurrectTimer -= diff;
                return;
            }

            switch (uiPhase)
            {
                case PHASE_UNDEAD:
                case PHASE_SKELETON:
                {
                    if (uiIcyTouchTimer <= diff)
                    {
                        DoCastVictim(SPELL_ICY_TOUCH);
                        uiIcyTouchTimer = urand(5000, 7000);
                    } else uiIcyTouchTimer -= diff;
                    if (uiPlagueStrikeTimer <= diff)
                    {
                        DoCastVictim(SPELL_PLAGUE_STRIKE);
                        uiPlagueStrikeTimer = urand(12000, 15000);
                    } else uiPlagueStrikeTimer -= diff;
                    if (uiObliterateTimer <= diff)
                    {
                        DoCastVictim(SPELL_OBLITERATE);
                        uiObliterateTimer = urand(17000, 19000);
                    } else uiObliterateTimer -= diff;
                    switch (uiPhase)
                    {
                        case PHASE_UNDEAD:
                        {
                            if (uiDeathRespiteTimer <= diff)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                {
                                    if (target && target->isAlive())
                                        DoCast(target, SPELL_DEATH_RESPITE);
                                }
                                uiDeathRespiteTimer = urand(15000, 16000);
                            } else uiDeathRespiteTimer -= diff;
                            break;
                        }
                        case PHASE_SKELETON:
                        {
                            if (!bSummonArmy)
                            {
                                bSummonArmy = true;
                                me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                                DoCast(me, SPELL_ARMY_DEAD);
                            }
                            if (!bDeathArmyDone)
                            {
                                if (uiDeathArmyCheckTimer <= diff)
                                {
                                    me->GetMotionMaster()->MoveChase(me->getVictim());
                                    me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                                    uiDeathArmyCheckTimer = 0;
                                    bDeathArmyDone = true;
                                } else uiDeathArmyCheckTimer -= diff;
                            }
                            if (uiDesecration <= diff)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                {
                                    if (target && target->isAlive())
                                        DoCast(target, SPELL_DESECRATION);
                                }
                                uiDesecration = urand(15000, 16000);
                            } else uiDesecration -= diff;
                            if (!summons.empty() && uiGhoulExplodeTimer <= diff)
                            {
                                DoCast(me, SPELL_GHOUL_EXPLODE);
                                uiGhoulExplodeTimer = 8000;
                            } else uiGhoulExplodeTimer -= diff;
                            break;
                        }
                        break;
                    }
                    break;
                }
                case PHASE_GHOST:
                {
                    if (uiDeathBiteTimer <= diff)
                    {
                        DoCastAOE(SPELL_DEATH_BITE);
                        uiDeathBiteTimer = urand (1000, 2000);
                    } else uiDeathBiteTimer -= diff;
                    if (uiMarkedDeathTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            if (target && target->isAlive())
                                DoCast(target, SPELL_MARKED_DEATH);
                        }
                        uiMarkedDeathTimer = urand (5000, 7000);
                    } else uiMarkedDeathTimer -= diff;
                    break;
                }
            }

            if (!me->HasUnitState(UNIT_STATE_ROOT) && !me->HealthBelowPct(1))
                DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& damage)
        {
            if (damage > me->GetHealth() && uiPhase <= PHASE_SKELETON)
            {
                damage = 0;
                me->SetHealth(0);
                me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                me->GetMotionMaster()->MoveIdle();
                resurrectInProgress = true;
                ExplodeAliveGhouls();
            }
        }

        void ExplodeAliveGhouls()
        {
            if (summons.empty())
                return;

            for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                if (Creature* ghoul = me->GetCreature(*me, *itr))
                    ghoul->CastSpell(ghoul, SPELL_EXPLODE);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            if (instance)
                instance->SetData(BOSS_BLACK_KNIGHT, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_black_knightAI (creature);
    }
};

class npc_risen_ghoul : public CreatureScript
{
public:
    npc_risen_ghoul() : CreatureScript("npc_risen_ghoul") { }

    struct npc_risen_ghoulAI : public ScriptedAI
    {
        npc_risen_ghoulAI(Creature* creature) : ScriptedAI(creature) {}

        InstanceScript* instance;
        uint32 uiAttackTimer;
        uint32 uiLeapTimer;

        void Reset()
        {
            instance = me->GetInstanceScript();
            uiAttackTimer = 3500;
            uiLeapTimer = 1000;

            if (Creature* knight = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                knight->AI()->JustSummoned(me);
        }

        void SpellHitTarget(Unit* /*victim*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_EXPLODE_H)
                instance->SetData(DATA_I_VE_HAD_WORSE, (uint32)false);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uiLeapTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 30, true))
                {
                    DoResetThreat();
                    me->AddThreat(target, 5.0f);
                    DoCast(target, SPELL_LEAP);
                }
                uiLeapTimer = urand(7000, 10000);
            } else uiLeapTimer -= diff;

            if (uiAttackTimer <= diff)
            {
                DoCastVictim(SPELL_CLAW);
                uiAttackTimer = urand(1000, 3500);
            } else uiAttackTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risen_ghoulAI(creature);
    }
};

class npc_black_knight_skeletal_gryphon : public CreatureScript
{
public:
    npc_black_knight_skeletal_gryphon() : CreatureScript("npc_black_knight_skeletal_gryphon") { }

    struct npc_black_knight_skeletal_gryphonAI : public npc_escortAI
    {
        npc_black_knight_skeletal_gryphonAI(Creature* creature) : npc_escortAI(creature), _vehicleKit(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
            me->SetSpeed(MOVE_FLIGHT, 2.8f);
        }

        Vehicle* _vehicleKit;
        InstanceScript* instance;

        void SetData(uint32 type, uint32 data)
        {
            if (type == 1)
                Start(false, true, 0, NULL);
        }

        void WaypointReached(uint32 id)
        {
            switch (id)
            {
                case 13:
                    if (Creature* announcer = me->GetCreature(*me, instance->GetData64(DATA_ANNOUNCER)))
                        me->SetFacingToObject(announcer);

                    if (Unit* blackKnight = _vehicleKit->GetPassenger(0))
                        blackKnight->ExitVehicle();

                    break;
            }
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool /*apply*/)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                who->ExitVehicle();
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_black_knight_skeletal_gryphonAI(creature);
    }
};

void AddSC_boss_black_knight()
{
    new boss_black_knight();
    new npc_risen_ghoul();
    new npc_black_knight_skeletal_gryphon();
}
