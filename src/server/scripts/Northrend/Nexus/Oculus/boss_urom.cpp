/*
 * Copyright (C) 2010 TrinityScript 2
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
 
#include "ScriptPCH.h"
#include "oculus.h"

struct Locations {
        float x,y,z,o;
};

static Locations BossLocSpawn[]=
{
    {968.181213f, 1042.239502f, 527.322777f, 0.021777f},  // AT I° spawn
    {1164.015747f, 1171.213989f, 527.322655f, 4.282561f}, // AT II° spawn
    {1123.280151f, 1080.605347f, 508.361016f, 1.251068f}, // AT III° spawn
    {1101.646729f, 1053.799927f, 509.238610f, 1.555070f}, // Oculus centre
};

enum Spells
{
    SPELL_ARCANE_SHIELD                           = 53813, //Dummy --> Channeled, shields the caster from damage.
    SPELL_EMPOWERED_ARCANE_EXPLOSION              = 51110,
    H_SPELL_EMPOWERED_ARCANE_EXPLOSION            = 59377,
    SPELL_FROSTBOMB                               = 51103, //Urom throws a bomb, hitting its target with the highest aggro which inflict directly 650 frost damage and drops a frost zone on the ground. This zone deals 650 frost damage per second and reduce the movement speed by 35%. Lasts 1 minute.
    SPELL_SUMMON_MENAGERIE_1                      = 50476, //Summons an assortment of creatures and teleports the caster to safety.
    SPELL_SUMMON_MENAGERIE_2                      = 50495,
    SPELL_SUMMON_MENAGERIE_3                      = 50496,
    SPELL_TELEPORT                                = 51112, //Teleports to the center of Oculus
    SPELL_TIME_BOMB                               = 51121, //Deals arcane damage to a random player, and after 6 seconds, deals zone damage to nearby equal to the health missing of the target afflicted by the debuff.
    H_SPELL_TIME_BOMB                             = 59376,
    SPELL_PARACHUTE                               = 61243  // Parachute
};

//not in db
enum Yells
{
    SAY_AGGRO                                     = -1578012,
    SAY_KILL_1                                    = -1578013,
    SAY_KILL_2                                    = -1578014,
    SAY_KILL_3                                    = -1578015,
    SAY_DEATH                                     = -1578016,
    SAY_EXPLOSION_1                               = -1578017,
    SAY_EXPLOSION_2                               = -1578018,
    SAY_SUMMON_1                                  = -1578019,
    SAY_SUMMON_2                                  = -1578020,
    SAY_SUMMON_3                                  = -1578021,
};

enum Creatures
{
        //I° spawn (2 fire, 1 water, 1 air)
        NPC_PHANTASMAL_WATER                                    = 27653,  //ScriptedAI
        NPC_PHANTASMAL_AIR                                      = 27650,  //ScriptedAI
        NPC_PHANTASMAL_FIRE                                    = 27651,  //ScriptedAI

        //II° spawn (2 ogres, 1 naga, 1 murloc)
        NPC_PHANTASMAL_OGRE                                     = 27647,  //ScriptedAI
        NPC_PHANTASMAL_NAGA                                     = 27648,  //ScriptedAI
        NPC_PHANTASMAL_MURLOC                                   = 27649,  //NO ABILITIES

        //III° spawn (1 mammoth, 2 wolves, 2 cloudscrapers)
        NPC_PHANTASMAL_MAMMOTH                                  = 27642,  //ScriptedAI
        NPC_PHANTASMAL_WOLVE                                    = 27644,  //ScriptedAI
        NPC_PHANTASMAL_CLUODSCRAPER                             = 27645,  //ScriptedAI


};

//range for adds spawn
#define RANGE  25

class boss_urom : public CreatureScript
{
    public:
        boss_urom(): CreatureScript("boss_urom") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_uromAI (pCreature);
    }

    struct boss_uromAI : public ScriptedAI
    {
        boss_uromAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;
            uint8 phase;
            uint32 ui_SummonSimulation_Timer;
            uint32 ui_FrostBomb_Timer;
            uint32 ui_TimeBomb_Timer;
            uint32 ui_ArcaneExplosion_Timer;
            bool just_summoned;
            bool summoning_casted;
            bool casting_explosion;
            bool done_casting_explosion;
            bool started;
            bool waiting_teleport;
            uint32 ui_ArcaneExplosionDuration;
            Creature * temp_summ;

        void Reset()
        {
            if (pInstance)
                pInstance->SetData(DATA_UROM_EVENT, NOT_STARTED);
                    phase = 0;
                    temp_summ = 0;
                    started = false;
                    ui_SummonSimulation_Timer = 4000;
                    just_summoned = false;
                    summoning_casted = false;
                    casting_explosion = false;
                    done_casting_explosion = false;
                    waiting_teleport = false;
                    ui_ArcaneExplosionDuration = 6000;
                    ui_FrostBomb_Timer = 10000;
                    ui_TimeBomb_Timer = 15000;
                    ui_ArcaneExplosion_Timer = 30000;
                    ui_ArcaneExplosionDuration = DUNGEON_MODE(9000,7000);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(SPELL_ARCANE_SHIELD);
                    me->SetReactState(REACT_PASSIVE);

        }

            bool PlayerInRange(float distance)
            {
                    Map *map = me->GetMap();
                    if (map->IsDungeon())
                    {            
                            Map::PlayerList const &PlayerList = map->GetPlayers();
                 
                            if (PlayerList.isEmpty())
                                    return false;
                     
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {

                                    if (i->getSource()->isAlive() && i->getSource()->GetDistance2d(me->GetPositionX(), me->GetPositionY()) <= distance)
                                    {
                                            return true;
                                    }
                            }
                    }
                    return false;
            }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_UROM_EVENT, IN_PROGRESS);
        }

            void DismountPlayers()
            {
                    std::list<HostileReference*>& m_threatlist = me->getThreatManager().getThreatList();
                    std::list<HostileReference*>::const_iterator i = m_threatlist.begin();
                    for (i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
                    {
                            Unit* pUnit = Unit::GetUnit((*me), (*i)->getUnitGuid());
                            if (pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER) )
                            {
                                    Vehicle* v = pUnit->GetVehicle();
                                    if(v)
                                    {
                                            pUnit->ExitVehicle();
                                            v->Dismiss();
                                            DoCast(pUnit,SPELL_PARACHUTE);                                      
                                    }
                            }
                    }
            }

        void UpdateAI(const uint32 uiDiff)
        {
                    if(!started && !waiting_teleport && PlayerInRange(31.0f) && pInstance->GetData(DATA_VAROS_EVENT) == DONE)
                    {
                            phase++;
                            just_summoned = false;
                            summoning_casted = false;
                            ui_SummonSimulation_Timer = 4000;
                            waiting_teleport = true;
                            if(phase == 4)
                                    started=true;
                    }
                    switch(phase)
                    {
                            case 0:
                                    return;
                            case 1:
                                    if(!summoning_casted)
                                    {
                                            DoScriptText(SAY_SUMMON_1,me);
                                            DoCast(SPELL_SUMMON_MENAGERIE_1);
                                            summoning_casted = true;
                                    }
                                    if (!just_summoned && ui_SummonSimulation_Timer <= uiDiff)
                                    {
                                            temp_summ = DoSummon(NPC_PHANTASMAL_WATER, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_AIR, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_FIRE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_FIRE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            just_summoned = true;
                                            ui_SummonSimulation_Timer = 4000;
                                            me->GetMotionMaster()->Clear(false);
                                            DoResetThreat();
                                            me->CombatStop(true);
                                            me->NearTeleportTo(BossLocSpawn[0].x, BossLocSpawn[0].y, BossLocSpawn[0].z, BossLocSpawn[0].o);
                                            me->GetMotionMaster()->MoveIdle();
                                            waiting_teleport = false;
                                    }else ui_SummonSimulation_Timer -= uiDiff;
                                    break;
                            case 2:
                                    if(!summoning_casted)
                                    {
                                            DoScriptText(SAY_SUMMON_2,me);
                                            DoCast(SPELL_SUMMON_MENAGERIE_2);
                                            summoning_casted = true;
                                    }
                                    if (!just_summoned && ui_SummonSimulation_Timer <= uiDiff)
                                    {
                                            temp_summ = DoSummon(NPC_PHANTASMAL_NAGA, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_MURLOC, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_OGRE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_OGRE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            just_summoned = true;
                                            ui_SummonSimulation_Timer = 4000;
                                            me->GetMotionMaster()->Clear(false);
                                            DoResetThreat();
                                            me->CombatStop(true);
                                            me->NearTeleportTo(BossLocSpawn[1].x, BossLocSpawn[1].y, BossLocSpawn[1].z, BossLocSpawn[1].o);
                                            me->GetMotionMaster()->MoveIdle();
                                            waiting_teleport = false;
                                    }else ui_SummonSimulation_Timer -= uiDiff;
                                    break;
                            case 3:
                                    if(!summoning_casted)
                                    {
                                            DoScriptText(SAY_SUMMON_3,me);
                                            DoCast(SPELL_SUMMON_MENAGERIE_3);
                                            summoning_casted = true;
                                    }
                                    if (!just_summoned && ui_SummonSimulation_Timer <= uiDiff)
                                    {
                                            temp_summ = DoSummon(NPC_PHANTASMAL_MAMMOTH, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_WOLVE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_WOLVE, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_CLUODSCRAPER, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            temp_summ = DoSummon(NPC_PHANTASMAL_CLUODSCRAPER, me, (rand()%RANGE)+1, 30000, TEMPSUMMON_DEAD_DESPAWN);
                                            if(temp_summ)
                                                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                                            temp_summ->Attack(pTarget,true);
                                            just_summoned = true;
                                            ui_SummonSimulation_Timer = 4000;
                                            me->GetMotionMaster()->Clear(false);
                                            DoResetThreat();
                                            me->CombatStop(true);
                                            me->GetMotionMaster()->MoveIdle();
                                            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
                                            DoCast(SPELL_TELEPORT);
                                            //me->NearTeleportTo(BossLocSpawn[2].x, BossLocSpawn[2].y, BossLocSpawn[2].z, BossLocSpawn[2].o);
                                            waiting_teleport = false;
                                    }else ui_SummonSimulation_Timer -= uiDiff;
                                    break;
                            case 4:
                                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    me->SetReactState(REACT_AGGRESSIVE);
                                    me->RemoveAllAuras();
                                    me->GetMotionMaster()->MoveIdle();

                                    //Return since we have no target
                                    if (!UpdateVictim())
                                            return;
                                    if(casting_explosion && !done_casting_explosion)
                                    {
                                            DoScriptText(RAND(SAY_EXPLOSION_1,SAY_EXPLOSION_2), me);
                                            DoCast(SPELL_EMPOWERED_ARCANE_EXPLOSION);
                                            done_casting_explosion = true;
                                    }
                                    if(casting_explosion && ui_ArcaneExplosionDuration <= uiDiff){
                                            Unit* victim = me->getVictim();
                                            if(victim)
                                                    me->NearTeleportTo(victim->GetPositionX()+4,victim->GetPositionY(),victim->GetPositionZ(),0);
                                            me->SetUnitMovementFlags(MOVEMENTFLAG_NONE);
                                            me->GetMotionMaster()->MoveChase(me->getVictim(),0,0);
                                            casting_explosion = false;
                                    }
                                    else if (casting_explosion)
                                            ui_ArcaneExplosionDuration -= uiDiff;

                                    if(ui_FrostBomb_Timer <= uiDiff)
                                    {
                                            DoCast(me->getVictim(),SPELL_FROSTBOMB);
                                            ui_FrostBomb_Timer = 60000;
                                    } else ui_FrostBomb_Timer -= uiDiff;

                                    if(ui_TimeBomb_Timer <= uiDiff)
                                    {
                                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                                DoCast(pTarget, SPELL_TIME_BOMB);
                                                            ui_TimeBomb_Timer = 15000;
                                            }
                                    } else ui_TimeBomb_Timer -= uiDiff;

                                    if(ui_ArcaneExplosion_Timer <= uiDiff)
                                    {
                                            casting_explosion = true;
                                            done_casting_explosion = false; 
                                            ui_ArcaneExplosion_Timer = 50000;
                                            ui_ArcaneExplosionDuration=DUNGEON_MODE(9000,7000);
                                    } else ui_ArcaneExplosion_Timer -= uiDiff;
                                    DoMeleeAttackIfReady();
                                    DismountPlayers();
                                    break;

                    }

        }
        void JustDied(Unit* killer)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_UROM_EVENT, DONE);
        }
        void KilledUnit(Unit *victim)
        {
            if (victim == me)
                return;
            DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), me);
        }
    };
};

void AddSC_boss_urom()
{
    new boss_urom();
}