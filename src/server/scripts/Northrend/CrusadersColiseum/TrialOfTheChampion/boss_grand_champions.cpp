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
SDName: boss_grand_champions
SD%Complete: 50 %
SDComment: Is missing the ai to make the npcs look for a new mount and use it.
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"
#include "Player.h"

enum eSpells
{
    //Vehicle
    SPELL_CHARGE                    = 63010,
    SPELL_SHIELD_BREAKER            = 68504,
    SPELL_SHIELD                    = 66482,

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    SPELL_MORTAL_STRIKE             = 68783,
    SPELL_MORTAL_STRIKE_H           = 68784,
    SPELL_BLADESTORM                = 63784,
    SPELL_INTERCEPT                 = 67540,
    SPELL_ROLLING_THROW             = 47115, //not implemented in the AI yet...

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    SPELL_FIREBALL                  = 66042,
    SPELL_FIREBALL_H                = 68310,
    SPELL_BLAST_WAVE                = 66044,
    SPELL_BLAST_WAVE_H              = 68312,
    SPELL_HASTE                     = 66045,
    SPELL_POLYMORPH                 = 66043,
    SPELL_POLYMORPH_H               = 68311,

    // Colosos && Runok Wildmane || Shaman
    SPELL_CHAIN_LIGHTNING           = 67529,
    SPELL_CHAIN_LIGHTNING_H         = 68319,
    SPELL_EARTH_SHIELD              = 67530,
    SPELL_HEALING_WAVE              = 67528,
    SPELL_HEALING_WAVE_H            = 68318,
    SPELL_HEX_OF_MENDING            = 67534,

    // Jaelyne Evensong && Zul'tore || Hunter
    SPELL_DISENGAGE                 = 68340, //not implemented in the AI yet...
    SPELL_LIGHTNING_ARROWS          = 66083,
    SPELL_MULTI_SHOT                = 66081,
    SPELL_SHOOT                     = 65868,
    SPELL_SHOOT_H                   = 67988,

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                = 67709,
    SPELL_EVISCERATE_H              = 68317,
    SPELL_FAN_OF_KNIVES             = 67706,
    SPELL_POISON_BOTTLE             = 67701
};

enum eSeat
{
    SEAT_ID_0                       = 0
};

/*
struct Point
{
    float x, y, z;
};

const Point MovementPoint[] =
{
  {746.84f, 623.15f, 411.41f},
  {747.96f, 620.29f, 411.09f},
  {750.23f, 618.35f, 411.09f}
};
*/
void AggroAllPlayers(Creature* temp)
{
    Map::PlayerList const &PlList = temp->GetMap()->GetPlayers();

    if (PlList.isEmpty())
            return;

    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if (Player* player = i->GetSource())
        {
            if (player->IsGameMaster())
                continue;

            if (player->IsAlive())
            {
                temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                temp->SetReactState(REACT_AGGRESSIVE);
                temp->SetInCombatWith(player);
                player->SetInCombatWith(temp);
                temp->AddThreat(player, 0.0f);
            }
        }
    }
}

bool GrandChampionsOutVehicle(Creature* me)
{
    InstanceScript* instance = me->GetInstanceScript();

    if (!instance)
        return false;

    Creature* pGrandChampion1 = Unit::GetCreature(*me, instance->GetData64(DATA_GRAND_CHAMPION_1));
    Creature* pGrandChampion2 = Unit::GetCreature(*me, instance->GetData64(DATA_GRAND_CHAMPION_2));
    Creature* pGrandChampion3 = Unit::GetCreature(*me, instance->GetData64(DATA_GRAND_CHAMPION_3));

    if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
    {
        if (!pGrandChampion1->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion2->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion3->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return true;
    }

    return false;
}

/*
* Generic AI for vehicles used by npcs in ToC, it needs more improvements.  *
* Script Complete: 25%.                                                     *
*/

class generic_vehicleAI_toc5 : public CreatureScript
{
public:
    generic_vehicleAI_toc5() : CreatureScript("generic_vehicleAI_toc5") { }

    struct generic_vehicleAI_toc5AI : public npc_escortAI
    {
        generic_vehicleAI_toc5AI(Creature* creature) : npc_escortAI(creature)
        {
            SetDespawnAtEnd(false);
            uiWaypointPath = 0;

            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;
        uint32 uiBuffTimer;

        uint32 uiWaypointPath;

        void Reset()
        {
            uiChargeTimer = 5000;
            uiShieldBreakerTimer = 8000;
            uiBuffTimer = urand(30000, 60000);
        }

        void SetData(uint32 uiType, uint32 /*uiData*/)
        {
            switch (uiType)
            {
                case 1:
                    AddWaypoint(0, 747.36f, 634.07f, 411.572f);
                    AddWaypoint(1, 780.43f, 607.15f, 411.82f);
                    AddWaypoint(2, 785.99f, 599.41f, 411.92f);
                    AddWaypoint(3, 778.44f, 601.64f, 411.79f);
                    uiWaypointPath = 1;
                    break;
                case 2:
                    AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                    AddWaypoint(1, 768.72f, 581.01f, 411.92f);
                    AddWaypoint(2, 763.55f, 590.52f, 411.71f);
                    uiWaypointPath = 2;
                    break;
                case 3:
                    AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                    AddWaypoint(1, 784.02f, 645.33f, 412.39f);
                    AddWaypoint(2, 775.67f, 641.91f, 411.91f);
                    uiWaypointPath = 3;
                    break;
            }

            if (uiType <= 3)
                Start(false, true, 0, NULL);
        }

        void WaypointReached(uint32 waypointId)
        {
            if (!instance)
                return;

            switch (waypointId)
            {
                case 2:
                    if (uiWaypointPath == 3 || uiWaypointPath == 2)
                        instance->SetData(DATA_MOVEMENT_DONE, instance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
                case 3:
                    instance->SetData(DATA_MOVEMENT_DONE, instance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCastSpellShield();
        }

        void DoCastSpellShield()
        {
            for (uint8 i = 0; i < 3; ++i)
                DoCast(me, SPELL_SHIELD, true);
        }

        void UpdateAI(uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            if (uiBuffTimer <= uiDiff)
            {
                if (!me->HasAura(SPELL_SHIELD))
                    DoCastSpellShield();

                uiBuffTimer = urand(30000, 45000);
            }else uiBuffTimer -= uiDiff;

            if (uiChargeTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && me->IsInRange(player, 8.0f, 25.0f, false))
                        {
                            DoResetThreat();
                            me->AddThreat(player, 1.0f);
                            DoCast(player, SPELL_CHARGE);
                            break;
                        }
                    }
                }
                uiChargeTimer = 5000;
            }else uiChargeTimer -= uiDiff;

            //dosen't work at all
            if (uiShieldBreakerTimer <= uiDiff)
            {
                Vehicle* pVehicle = me->GetVehicleKit();
                if (!pVehicle)
                    return;

                if (Unit* pPassenger = pVehicle->GetPassenger(SEAT_ID_0))
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (me->GetMap()->IsDungeon() && !players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* player = itr->GetSource();
                            if (player && !player->IsGameMaster() && me->IsInRange(player, 10.0f, 30.0f, false))
                            {
                                pPassenger->CastSpell(player, SPELL_SHIELD_BREAKER, true);
                                break;
                            }
                        }
                    }
                }
                uiShieldBreakerTimer = 7000;
            }else uiShieldBreakerTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new generic_vehicleAI_toc5AI(creature);
    }
};

class boss_warrior_toc5 : public CreatureScript
{
public:
    boss_warrior_toc5() : CreatureScript("boss_warrior_toc5") { }

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    struct boss_warrior_toc5AI : public ScriptedAI
    {
        boss_warrior_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiBladeStormTimer;
        uint32 uiInterceptTimer;
        uint32 uiMortalStrikeTimer;
        uint32 uiAttackTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiBladeStormTimer = urand(15000, 20000);
            uiInterceptTimer  = 7000;
            uiMortalStrikeTimer = urand(8000, 12000);
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 412.393f, 4.49f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiInterceptTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && me->IsInRange(player, 8.0f, 25.0f, false))
                        {
                            DoResetThreat();
                            me->AddThreat(player, 5.0f);
                            DoCast(player, SPELL_INTERCEPT);
                            break;
                        }
                    }
                }
                uiInterceptTimer = 7000;
            } else uiInterceptTimer -= uiDiff;

            if (uiBladeStormTimer <= uiDiff)
            {
                DoCastVictim(SPELL_BLADESTORM);
                uiBladeStormTimer = urand(15000, 20000);
            } else uiBladeStormTimer -= uiDiff;

            if (uiMortalStrikeTimer <= uiDiff)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                uiMortalStrikeTimer = urand(8000, 12000);
            } else uiMortalStrikeTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_warrior_toc5AI(creature);
    }
};

class boss_mage_toc5 : public CreatureScript
{
public:
    boss_mage_toc5() : CreatureScript("boss_mage_toc5") { }

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    struct boss_mage_toc5AI : public ScriptedAI
    {
        boss_mage_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiFireBallTimer;
        uint32 uiBlastWaveTimer;
        uint32 uiHasteTimer;
        uint32 uiPolymorphTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiFireBallTimer = 5000;
            uiPolymorphTimer  = 8000;
            uiBlastWaveTimer = 12000;
            uiHasteTimer = 22000;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 412.393f, 4.49f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

                if (instance)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (uiFireBallTimer <= uiDiff)
            {
                if (me->GetVictim())
                    DoCastVictim(SPELL_FIREBALL);
                uiFireBallTimer = 5000;
            } else uiFireBallTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiFireBallTimer <= uiDiff)
            {
                DoCastVictim(SPELL_FIREBALL);
                uiFireBallTimer = 5000;
            } else uiFireBallTimer -= uiDiff;

            if (uiPolymorphTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_POLYMORPH);
                uiPolymorphTimer = 8000;
            } else uiPolymorphTimer -= uiDiff;

            if (uiBlastWaveTimer <= uiDiff)
            {
                DoCastAOE(SPELL_BLAST_WAVE, false);
                uiBlastWaveTimer = 13000;
            } else uiBlastWaveTimer -= uiDiff;

            if (uiHasteTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);

                DoCast(me, SPELL_HASTE);
                uiHasteTimer = 22000;
            } else uiHasteTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_mage_toc5AI(creature);
    }
};

class boss_shaman_toc5 : public CreatureScript
{
public:
    boss_shaman_toc5() : CreatureScript("boss_shaman_toc5") { }

    // Colosos && Runok Wildmane || Shaman
    struct boss_shaman_toc5AI : public ScriptedAI
    {
        boss_shaman_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiChainLightningTimer;
        uint32 uiEartShieldTimer;
        uint32 uiHealingWaveTimer;
        uint32 uiHexMendingTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiChainLightningTimer = 16000;
            uiHealingWaveTimer = 12000;
            uiEartShieldTimer = urand(30000, 35000);
            uiHexMendingTimer = urand(20000, 25000);
        }

        void EnterCombat(Unit* who)
        {
            DoCast(me, SPELL_EARTH_SHIELD);
            DoCast(who, SPELL_HEX_OF_MENDING);
        };

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 412.393f, 4.49f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

                if (instance)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiChainLightningTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHAIN_LIGHTNING);

                uiChainLightningTimer = 16000;
            } else uiChainLightningTimer -= uiDiff;

            if (uiHealingWaveTimer <= uiDiff)
            {
                bool bChance = urand(0, 1);

                if (!bChance)
                {
                    if (Unit* pFriend = DoSelectLowestHpFriendly(40))
                        DoCast(pFriend, SPELL_HEALING_WAVE);
                } else
                    DoCast(me, SPELL_HEALING_WAVE);

                uiHealingWaveTimer = 12000;
            } else uiHealingWaveTimer -= uiDiff;

            if (uiEartShieldTimer <= uiDiff)
            {
                DoCast(me, SPELL_EARTH_SHIELD);

                uiEartShieldTimer = urand(30000, 35000);
            } else uiEartShieldTimer -= uiDiff;

            if (uiHexMendingTimer <= uiDiff)
            {
                DoCastVictim(SPELL_HEX_OF_MENDING, true);

                uiHexMendingTimer = urand(20000, 25000);
            } else uiHexMendingTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_shaman_toc5AI(creature);
    }
};

class boss_hunter_toc5 : public CreatureScript
{
public:
    boss_hunter_toc5() : CreatureScript("boss_hunter_toc5") { }

        // Jaelyne Evensong && Zul'tore || Hunter
    struct boss_hunter_toc5AI : public ScriptedAI
    {
        boss_hunter_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiShootTimer;
        uint32 uiMultiShotTimer;
        uint32 uiLightningArrowsTimer;

        uint64 uiTargetGUID;

        bool bShoot;
        bool bDone;
        bool bHome;

        void Reset()
        {
            uiShootTimer = 12000;
            uiMultiShotTimer = 0;
            uiLightningArrowsTimer = 7000;

            uiTargetGUID = 0;

            bShoot = false;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 412.393f, 4.49f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

                if (instance)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiLightningArrowsTimer <= uiDiff)
            {
                DoCastAOE(SPELL_LIGHTNING_ARROWS, false);
                uiLightningArrowsTimer = 7000;
            } else uiLightningArrowsTimer -= uiDiff;

            if (uiShootTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 30.0f))
                {
                    uiTargetGUID = target->GetGUID();
                    DoCast(target, SPELL_SHOOT);
                }
                uiShootTimer = 12000;
                uiMultiShotTimer = 3000;
                bShoot = true;
            } else uiShootTimer -= uiDiff;

            if (bShoot && uiMultiShotTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);
                Unit* target = Unit::GetUnit(*me, uiTargetGUID);

                if (target && me->IsInRange(target, 5.0f, 30.0f, false))
                {
                    DoCast(target, SPELL_MULTI_SHOT);
                }
                else
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (me->GetMap()->IsDungeon() && !players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* player = itr->GetSource();
                            if (player && !player->IsGameMaster() && me->IsInRange(player, 5.0f, 30.0f, false))
                            {
                                DoCast(player, SPELL_MULTI_SHOT);
                                break;
                            }
                        }
                    }
                }
                bShoot = false;
            } else uiMultiShotTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_hunter_toc5AI(creature);
    }
};

class boss_rouge_toc5 : public CreatureScript
{
public:
    boss_rouge_toc5() : CreatureScript("boss_rouge_toc5") { }

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    struct boss_rouge_toc5AI : public ScriptedAI
    {
        boss_rouge_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;
        uint32 uiEviscerateTimer;
        uint32 uiFanKivesTimer;
        uint32 uiPosionBottleTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiEviscerateTimer = 8000;
            uiFanKivesTimer   = 14000;
            uiPosionBottleTimer = 19000;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f, 662.541f, 412.393f, 4.49f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
                else if (instance && me->GetGUID() == instance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

                if (instance)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            } else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiEviscerateTimer <= uiDiff)
            {
                DoCastVictim(SPELL_EVISCERATE);
                uiEviscerateTimer = 8000;
            } else uiEviscerateTimer -= uiDiff;

            if (uiFanKivesTimer <= uiDiff)
            {
                DoCastAOE(SPELL_FAN_OF_KNIVES, false);
                uiFanKivesTimer = 14000;
            } else uiFanKivesTimer -= uiDiff;

            if (uiPosionBottleTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_POISON_BOTTLE);
                uiPosionBottleTimer = 19000;
            } else uiPosionBottleTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rouge_toc5AI(creature);
    }
};

void AddSC_boss_grand_champions()
{
    new generic_vehicleAI_toc5();
    new boss_warrior_toc5();
    new boss_mage_toc5();
    new boss_shaman_toc5();
    new boss_hunter_toc5();
    new boss_rouge_toc5();
}
