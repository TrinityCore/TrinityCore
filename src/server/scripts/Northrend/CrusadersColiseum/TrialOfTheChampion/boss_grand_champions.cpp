/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SD%Complete: 80 %
SDComment: Is missing the ai to make the npcs look for a new mount and use it.
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //Vehicle
    SPELL_CHARGE                    = 68282,
    SPELL_SHIELD_BREAKER            = 62575,
    SPELL_SHIELD_BREAKER_VISUAL     = 45815,
    SPELL_SHIELD                    = 66482,
    SPELL_THRUST                    = 62544,
    SPELL_KNEE                      = 68442,
    // 67870

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
    SPELL_HEX_OF_MENDING_HEAL       = 67535,

    // Jaelyne Evensong && Zul'tore || Hunter
    SPELL_DISENGAGE                 = 68339,
    SPELL_LIGHTNING_ARROWS          = 66085,
    SPELL_LIGHTNING_ARROWS_DAMAGE   = 66095,
    SPELL_LIGHTNING_ARROWS_VISUAL   = 66083,
    SPELL_MULTI_SHOT                = 66081,
    SPELL_SHOOT                     = 65868,
    SPELL_SHOOT_H                   = 67988,

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    SPELL_DEADLY_POISON             = 67711,
    SPELL_EVISCERATE                = 67709,
    SPELL_EVISCERATE_H              = 68317,
    SPELL_FAN_OF_KNIVES             = 67706,
    SPELL_POISON_BOTTLE             = 67701,
    SPELL_DUAL_WIELD                = 42459,
};

/*
* Generic AI for vehicles used by npcs in ToC, it needs more improvements.  *
* Script Complete: 25%.                                                     *
*/

struct npc_mounted_championAI : ScriptedAI
{
    npc_mounted_championAI(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;

    uint32 chargeTimer;
    uint32 shieldBreakerTimer;
    uint32 buffTimer;
    bool _defeated;

    void Reset()
    {
        if(_defeated)
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        me->Mount(GetMountId());
        chargeTimer = urand(1000, 5000);
        shieldBreakerTimer = 8000;
        buffTimer = urand(4000, 5000);
        _defeated = false;
        if (instance)
            SetEquipmentSlots(false, instance->GetData(DATA_TEAM) == ALLIANCE ? 46070 : 46069);
    }

    uint32 GetMountId()
    {
        switch(me->GetEntry())
        {
            // Alliance
            case NPC_STORMWIND_CHAMPION:  return 28912;
            case NPC_IRONFORGE_CHAMPION:  return 29258;
            case NPC_GNOMEREGAN_CHAMPION: return 28571;
            case NPC_DARNASSUS_CHAMPION:  return 29256;
            case NPC_EXODAR_CHAMPION:     return 29255;
            case NPC_JACOB:               return 29284;
            case NPC_AMBROSE:             return 28571;
            case NPC_COLOSOS:             return 29255;
            case NPC_JAELYNE:             return 9991;
            case NPC_LANA:                return 2787;
            // Horde
            case NPC_ORGRIMMAR_CHAMPION:     return 29260;
            case NPC_THUNDER_BLUFF_CHAMPION: return 29259;
            case NPC_UNDERCITY_CHAMPION:     return 29257;
            case NPC_SENJIN_CHAMPION:        return 29261;
            case NPC_SILVERMOON_CHAMPION:    return 29262;
            case NPC_MOKRA:                  return 29879;
            case NPC_ERESSEA:                return 28607;
            case NPC_RUNOK:                  return 29880;
            case NPC_ZULTORE:                return 29261;
            case NPC_VISCERI:                return 10718;
        }
        return 0;
    }

    void DamageTaken(Unit* /*attacker*/, uint32 & damage)
    {
        if (!isGrandChampion())
            return;

        if(_defeated)
        {
            damage = 0;
            return;
        }

        if(damage >= me->GetHealth())
        {
            damage = 0;
            _defeated = true;
            me->GetMotionMaster()->MoveIdle();
            me->Dismount();
            me->RemoveAurasDueToSpell(SPELL_SHIELD);
            me->CastSpell(me, SPELL_KNEE, true);
            me->SetTarget(0);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    uint32 GetData(uint32 type)
    {
        if(type == DATA_CHAMPION_DEFEATED)
            return _defeated ? 1 : 0;

        return 0;
    }

    void EnterCombat(Unit* /*who*/)
    {
        // Set Defend to 3 charges at start
        for (uint8 i = 0; i < 3; ++i)
            DoCast(me, SPELL_SHIELD, true);

        if (instance->GetData(MINION_ENCOUNTER) != IN_PROGRESS)
            instance->SetData(MINION_ENCOUNTER, IN_PROGRESS);
    }

    void JustReachedHome()
    {
        if (instance->GetData(MINION_ENCOUNTER) == IN_PROGRESS)
            instance->SetData(MINION_ENCOUNTER, FAIL);
    }

    bool isGrandChampion()
    {
        return (me->GetEntry() == NPC_MOKRA   || me->GetEntry() == NPC_JACOB   ||
                me->GetEntry() == NPC_ERESSEA || me->GetEntry() == NPC_AMBROSE ||
                me->GetEntry() == NPC_RUNOK   || me->GetEntry() == NPC_COLOSOS ||
                me->GetEntry() == NPC_ZULTORE || me->GetEntry() == NPC_JAELYNE ||
                me->GetEntry() == NPC_VISCERI || me->GetEntry() == NPC_LANA);
    }

    bool isInMountedGauntlet()
    {
        if(Creature* announcer = me->GetCreature(*me, instance->GetData64(DATA_ANNOUNCER)))
        {
            if (announcer->AI()->GetData(EVENT_INTRO) == IN_PROGRESS || announcer->AI()->GetData(EVENT_WAVES) == IN_PROGRESS)
                return true;
        }
        return false;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if(_defeated)
            return;

        if (buffTimer <= uiDiff)
        {
            Aura* defend = me->GetAura(SPELL_SHIELD);
            if (!defend || defend->GetStackAmount() < 3)
            {
                DoCast(SPELL_SHIELD);
                buffTimer = urand(4000, 5000);
            } else buffTimer = urand(1000, 2000);
        }else buffTimer -= uiDiff;

        if (chargeTimer <= uiDiff)
        {
            if(Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
            {
                DoResetThreat();
                me->AddThreat(target, 5.0f);
                DoCast(target, SPELL_CHARGE, true);
            }
            chargeTimer = 5000;
        }else chargeTimer -= uiDiff;

        if (shieldBreakerTimer <= uiDiff)
        {
            if(Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                DoCast(target, SPELL_SHIELD_BREAKER, true);

            shieldBreakerTimer = 7000;
        }else shieldBreakerTimer -= uiDiff;

        // Use Thrust instead of melee attack
        if (me->isAttackReady() && me->IsWithinMeleeRange(me->getVictim()))
        {
            me->AddUnitState(UNIT_STATE_ONVEHICLE);
            DoCast(me->getVictim(), SPELL_THRUST);
            me->resetAttackTimer();
            me->ClearUnitState(UNIT_STATE_ONVEHICLE);
        }
    }
};

class generic_vehicleAI_toc5 : public CreatureScript
{
public:
    generic_vehicleAI_toc5() : CreatureScript("generic_vehicleAI_toc5") { }

    struct generic_vehicleAI_toc5AI : public npc_mounted_championAI
    {
        generic_vehicleAI_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}
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
    struct boss_warrior_toc5AI : public npc_mounted_championAI
    {
        boss_warrior_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}

        uint32 bladeStormTimer;
        uint32 interceptTimer;
        uint32 mortalStrikeTimer;
        bool defeated;

        void Reset()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::Reset();
                return;
            }

            defeated = false;
            bladeStormTimer = urand(15000, 20000);
            interceptTimer  = 7000;
            mortalStrikeTimer = urand(8000, 12000);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 & damage)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::DamageTaken(NULL, damage);
                return;
            }

            if(defeated)
            {
                damage = 0;
                return;
            }

            // Prevent damage from finishing hit and mark creature as defeated
            if(damage >= me->GetHealth())
            {
                damage = 0;
                defeated = true;
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                me->SetTarget(0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                BindPlayersToInstance(me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // Knee at home position after being defeated
            if(type == POINT_MOTION_TYPE && id == 1)
                me->CastSpell(me, SPELL_KNEE, true);
        }

        uint32 GetData(uint32 type)
        {
            if (isInMountedGauntlet())
                return npc_mounted_championAI::GetData(type);

            // Used by Announcer on periodic check of the bosses state
            if(type == DATA_CHAMPION_DEFEATED)
                return defeated ? 1 : 0;

            return 0;
        }

        void EnterCombat(Unit* who)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::EnterCombat(who);
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) != IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);
        };

        void JustReachedHome()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::JustReachedHome();
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, FAIL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::UpdateAI(diff);
                return;
            }

            if (!UpdateVictim())
                return;

            if(defeated)
                return;

            if (interceptTimer <= diff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->getSource();
                        if (player && !player->isGameMaster() && me->IsInRange(player, 8.0f, 25.0f, false))
                        {
                            DoResetThreat();
                            me->AddThreat(player, 5.0f);
                            DoCast(player, SPELL_INTERCEPT);
                            break;
                        }
                    }
                   }
                interceptTimer = 7000;
            } else interceptTimer -= diff;

            if (bladeStormTimer <= diff)
            {
                DoCastVictim(SPELL_BLADESTORM);
                bladeStormTimer = urand(15000, 20000);
            } else bladeStormTimer -= diff;

            if (mortalStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                mortalStrikeTimer = urand(8000, 12000);
            } else mortalStrikeTimer -= diff;

            DoMeleeAttackIfReady();
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
    struct boss_mage_toc5AI : public npc_mounted_championAI
    {
        boss_mage_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}

        uint32 fireBallTimer;
        uint32 blastWaveTimer;
        uint32 hasteTimer;
        uint32 polymorphTimer;
        bool defeated;

        void Reset()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::Reset();
                return;
            }

            defeated = false;
            fireBallTimer = 2000;
            polymorphTimer  = 8000;
            blastWaveTimer = 12000;
            hasteTimer = 22000;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 & damage)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::DamageTaken(NULL, damage);
                return;
            }

            if(defeated)
            {
                damage = 0;
                return;
            }

            // Prevent damage from finishing hit and mark creature as defeated
            if(damage >= me->GetHealth())
            {
                damage = 0;
                defeated = true;
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                me->SetTarget(0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                BindPlayersToInstance(me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // Knee at home position after being defeated
            if(type == POINT_MOTION_TYPE && id == 1)
                me->CastSpell(me, SPELL_KNEE, true);
        }

        uint32 GetData(uint32 type)
        {
            if (isInMountedGauntlet())
                return npc_mounted_championAI::GetData(type);

            // Used by Announcer on periodic check of the bosses state
            if(type == DATA_CHAMPION_DEFEATED)
                return defeated ? 1 : 0;

            return 0;
        }

        void EnterCombat(Unit* who)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::EnterCombat(who);
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) != IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);
        };

        void JustReachedHome()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::JustReachedHome();
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, FAIL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::UpdateAI(diff);
                return;
            }

            if (!UpdateVictim())
                return;

            if(defeated)
                return;

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (polymorphTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_POLYMORPH);
                polymorphTimer = 8000;
            } else polymorphTimer -= diff;

            if (blastWaveTimer <= diff)
            {
                DoCastAOE(SPELL_BLAST_WAVE, false);
                blastWaveTimer = 13000;
            } else blastWaveTimer -= diff;

            if (hasteTimer <= diff)
            {
                me->InterruptNonMeleeSpells(true);

                DoCast(me, SPELL_HASTE);
                hasteTimer = 22000;
            } else hasteTimer -= diff;

            if (fireBallTimer <= diff)
            {
                DoCastVictim(SPELL_FIREBALL);
                fireBallTimer = 2600;
            } else fireBallTimer -= diff;

            DoMeleeAttackIfReady();
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
    struct boss_shaman_toc5AI : public npc_mounted_championAI
    {
        boss_shaman_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}

        uint32 chainLightningTimer;
        uint32 eartShieldTimer;
        uint32 healingWaveTimer;
        uint32 hexMendingTimer;
        bool defeated;

        void Reset()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::Reset();
                return;
            }

            defeated = false;
            chainLightningTimer = 5000;
            healingWaveTimer = 12000;
            eartShieldTimer = urand(30000, 35000);
            hexMendingTimer = urand(1000, 5000);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void EnterCombat(Unit* who)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::EnterCombat(who);
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) != IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            DoCast(me, SPELL_EARTH_SHIELD);
        };

        void JustReachedHome()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::JustReachedHome();
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, FAIL);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 & damage)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::DamageTaken(NULL, damage);
                return;
            }

            if(defeated)
            {
                damage = 0;
                return;
            }

            // Prevent damage from finishing hit and mark creature as defeated
            if(damage >= me->GetHealth())
            {
                damage = 0;
                defeated = true;
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                me->SetTarget(0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                BindPlayersToInstance(me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // Knee at home position after being defeated
            if(type == POINT_MOTION_TYPE && id == 1)
                me->CastSpell(me, SPELL_KNEE, true);
        }

        uint32 GetData(uint32 type)
        {
            if (isInMountedGauntlet())
                return npc_mounted_championAI::GetData(type);

            // Used by Announcer on periodic check of the bosses state
            if(type == DATA_CHAMPION_DEFEATED)
                return defeated ? 1 : 0;

            return 0;
        }

        void UpdateAI(const uint32 diff)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::UpdateAI(diff);
                return;
            }

            if (!UpdateVictim())
                return;

            if(defeated)
                return;

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (chainLightningTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHAIN_LIGHTNING);

                chainLightningTimer = 8000;
            } else chainLightningTimer -= diff;

            if (healingWaveTimer <= diff)
            {
                bool chance = urand(0, 1);

                if(!chance)
                {
                    if (Unit* friendUnit = DoSelectLowestHpFriendly(40))
                    {
                        DoCast(friendUnit, SPELL_HEALING_WAVE);
                        healingWaveTimer = 5000;
                    }
                }else
                {
                    DoCast(me, SPELL_HEALING_WAVE);
                    healingWaveTimer = 8000;
                }
            } else healingWaveTimer -= diff;

            if (eartShieldTimer <= diff)
            {
                Unit* friendUnit = DoSelectLowestHpFriendly(40);

                if (friendUnit && friendUnit->HealthBelowPct(60) && !friendUnit->HasAura(SPELL_EARTH_SHIELD))
                {
                    DoCast(friendUnit, SPELL_EARTH_SHIELD);
                    eartShieldTimer = urand(30000, 35000);
                }else if(!me->HasAura(SPELL_EARTH_SHIELD))
                {
                    DoCast(me, SPELL_EARTH_SHIELD);
                    eartShieldTimer = urand(30000, 35000);
                } else eartShieldTimer = urand(1500, 3500);
            } else eartShieldTimer -= diff;

            if (hexMendingTimer <= diff)
            {
                DoCastVictim(SPELL_HEX_OF_MENDING, true);

                hexMendingTimer = urand(12000, 15000);
            } else hexMendingTimer -= diff;

            DoMeleeAttackIfReady();
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
    struct boss_hunter_toc5AI : public npc_mounted_championAI
    {
        boss_hunter_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}

        uint32 multiShotTimer;
        uint32 lightningArrowsTimer;
        uint32 disengageTimer;

        bool ligthingArrows;
        bool defeated;

        void Reset()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::Reset();
                return;
            }

            if(defeated)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            defeated = false;
            ligthingArrows = false;
            multiShotTimer = 2000;
            disengageTimer = 3000;
            lightningArrowsTimer = 7000;
            me->SetSheath(SHEATH_STATE_RANGED);
            me->SetStatFloatValue(UNIT_FIELD_MINRANGEDDAMAGE, IsHeroic() ? 5000.0f : 3000.0f);
            me->SetStatFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE, IsHeroic() ? 6000.0f : 4000.0f);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 & damage)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::DamageTaken(NULL, damage);
                return;
            }

            if(defeated)
            {
                damage = 0;
                return;
            }

            // Prevent damage from finishing hit and mark creature as defeated
            if(damage >= me->GetHealth())
            {
                damage = 0;
                defeated = true;
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                me->SetTarget(0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                BindPlayersToInstance(me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // Knee at home position after being defeated
            if(type == POINT_MOTION_TYPE && id == 1)
                me->CastSpell(me, SPELL_KNEE, true);
        }

        uint32 GetData(uint32 type)
        {
            if (isInMountedGauntlet())
                return npc_mounted_championAI::GetData(type);

            // Used by Announcer on periodic check of the bosses state
            if(type == DATA_CHAMPION_DEFEATED)
                return defeated ? 1 : 0;

            return 0;
        }

        void EnterCombat(Unit* who)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::EnterCombat(who);
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) != IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);
        };

        void JustReachedHome()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::JustReachedHome();
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, FAIL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::UpdateAI(diff);
                return;
            }

            if (!UpdateVictim())
                return;

            if(defeated)
                return;

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(me->GetDistance(me->getVictim()) >= 30.0f)
                me->GetMotionMaster()->MoveChase(me->getVictim(), 25.0f);

            if (disengageTimer <= diff)
            {
                if(me->GetDistance(me->getVictim()) <= 3.0f)
                {
                    DoCast(SPELL_DISENGAGE);
                    disengageTimer = 7000;
                }
                else disengageTimer = 1000;
            } else disengageTimer -= diff;

            if (lightningArrowsTimer <= diff && !me->HasAura(SPELL_LIGHTNING_ARROWS))
            {
                DoCastAOE(SPELL_LIGHTNING_ARROWS_VISUAL, false);
                lightningArrowsTimer = 14000;
                ligthingArrows = true;
                return;
            } else lightningArrowsTimer -= diff;

            // Trigger the aura after the visual storm
            if(ligthingArrows && !me->HasAura(SPELL_LIGHTNING_ARROWS_VISUAL))
            {
                DoCast(SPELL_LIGHTNING_ARROWS);
                ligthingArrows = false;
            }

            if (multiShotTimer <= diff)
            {
                if(Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                    if(target->IsInRange(me, 5.0f, 35.0f))
                    {
                        DoCast(target, SPELL_MULTI_SHOT);
                        multiShotTimer = 6000;
                    } else multiShotTimer = 1000;
            } else multiShotTimer -= diff;

            // Shoot instead of meele swing
            if (me->isAttackReady())
            {
                if(Aura* lArrows = me->GetAura(SPELL_LIGHTNING_ARROWS))
                {
                    DoCast(me->getVictim(), SPELL_LIGHTNING_ARROWS_DAMAGE, true);
                    lArrows->ModCharges(-1);
                }
                DoCast(me->getVictim(), SPELL_SHOOT, true);
                me->resetAttackTimer();
            }
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
    struct boss_rouge_toc5AI : public npc_mounted_championAI
    {
        boss_rouge_toc5AI(Creature* creature) : npc_mounted_championAI(creature) {}

        uint32 eviscerateTimer;
        uint32 fanKivesTimer;
        uint32 posionBottleTimer;

        bool defeated;

        void Reset()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::Reset();
                return;
            }

            if(defeated)
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            defeated = false;
            eviscerateTimer = 8000;
            fanKivesTimer   = 14000;
            posionBottleTimer = 19000;

            // Settings for offhand attack
            DoCast(me, SPELL_DUAL_WIELD, true);
            me->SetAttackTime(OFF_ATTACK, 1400);
            me->SetStatFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE, IsHeroic() ? 5000.0f : 3000.0f);
            me->SetStatFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE, IsHeroic() ? 6000.0f : 4000.0f);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 & damage)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::DamageTaken(NULL, damage);
                return;
            }

            if(defeated)
            {
                damage = 0;
                return;
            }

            // Prevent damage from finishing hit and mark creature as defeated
            if(damage >= me->GetHealth())
            {
                damage = 0;
                defeated = true;
                me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
                me->SetTarget(0);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                BindPlayersToInstance(me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            // Knee at home position after being defeated
            if(type == POINT_MOTION_TYPE && id == 1)
                me->CastSpell(me, SPELL_KNEE, true);
        }

        uint32 GetData(uint32 type)
        {
            if (isInMountedGauntlet())
                return npc_mounted_championAI::GetData(type);

            // Used by Announcer on periodic check of the bosses state
            if(type == DATA_CHAMPION_DEFEATED)
                return defeated ? 1 : 0;

            return 0;
        }

        void EnterCombat(Unit* who)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::EnterCombat(who);
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) != IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            DoCast(me, SPELL_DEADLY_POISON);
        };

        void JustReachedHome()
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::JustReachedHome();
                return;
            }

            if(InstanceScript* instance = me->GetInstanceScript())
                if(instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                    instance->SetData(BOSS_GRAND_CHAMPIONS, FAIL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (isInMountedGauntlet())
            {
                npc_mounted_championAI::UpdateAI(diff);
                return;
            }

            if (!UpdateVictim())
                return;

            if(defeated)
                return;

            if (eviscerateTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_EVISCERATE);
                eviscerateTimer = 8000;
            } else eviscerateTimer -= diff;

            if (fanKivesTimer <= diff)
            {
                DoCastAOE(SPELL_FAN_OF_KNIVES, false);
                fanKivesTimer = 14000;
            } else fanKivesTimer -= diff;

            if (posionBottleTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_POISON_BOTTLE);
                posionBottleTimer = 19000;
            } else posionBottleTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rouge_toc5AI(creature);
    }
};

enum vehicleSpells
{
    // Defend
    SPELL_DEFEND          = 66482,
    SPELL_VISUAL_SHIELD_1 = 63130,
    SPELL_VISUAL_SHIELD_2 = 63131,
    SPELL_VISUAL_SHIELD_3 = 63132,

    // Shield break
    SPELL_THROW_VISUAL    = 45827,
};

class spell_toc5_ride_mount : public SpellScriptLoader
{
    public:
        spell_toc5_ride_mount() : SpellScriptLoader("spell_toc5_ride_mount") {}

        class spell_toc5_ride_mount_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_toc5_ride_mount_SpellScript);

            SpellCastResult CheckRequirement()
            {
                if(GetCaster()->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID) == 46106 ||
                    GetCaster()->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID) == 46069 ||
                    GetCaster()->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID) == 46070)
                {
                    GetCaster()->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);
                    return SPELL_CAST_OK;
                } else {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_HAVE_LANCE_EQUIPPED);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_toc5_ride_mount_SpellScript::CheckRequirement);
            }
        };

        class spell_toc5_ride_mount_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_toc5_ride_mount_AuraScript);

            void HandleOnEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    target->RemoveAurasDueToSpell(SPELL_DEFEND);
                if (Unit* caster = GetCaster())
                {
                    caster->RemoveAurasDueToSpell(SPELL_DEFEND);
                    for (uint8 i=0; i<3; i++)
                        caster->RemoveAurasDueToSpell(SPELL_VISUAL_SHIELD_1+i);
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_toc5_ride_mount_AuraScript::HandleOnEffect, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_toc5_ride_mount_AuraScript::HandleOnEffect, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_toc5_ride_mount_AuraScript();
        }

        SpellScript* GetSpellScript() const
        {
            return new spell_toc5_ride_mount_SpellScript();
        }
};

class player_hex_mendingAI : public PlayerAI
{
    public:
        player_hex_mendingAI(Player* player) : PlayerAI(player) {}

        void HealReceived(Unit* healer, uint32 & addHealth)
        {
            PlayerAI::HealReceived(healer, addHealth);
            me->CastCustomSpell(SPELL_HEX_OF_MENDING_HEAL, SPELLVALUE_BASE_POINT0, int32(addHealth*2.0f), me, true);
        }

        void UpdateAI(const uint32 /*diff*/) { }

    private:
        uint64 casterGUID;
};

class spell_toc5_hex_mending : public SpellScriptLoader
{
    public:
        spell_toc5_hex_mending() : SpellScriptLoader("spell_toc5_hex_mending") { }

        class spell_toc5_hex_mending_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_toc5_hex_mending_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                oldAI = GetTarget()->GetAI();
                GetTarget()->SetAI(new player_hex_mendingAI(GetTarget()->ToPlayer()));
                oldAIState = GetTarget()->IsAIEnabled;
                GetTarget()->IsAIEnabled = true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                delete GetTarget()->GetAI();
                GetTarget()->SetAI(oldAI);
                GetTarget()->IsAIEnabled = oldAIState;
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_toc5_hex_mending_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_toc5_hex_mending_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            UnitAI* oldAI;
            bool oldAIState;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_toc5_hex_mending_AuraScript();
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
    new spell_toc5_ride_mount();
    new spell_toc5_hex_mending();
}
