/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
SD%Complete: 99%
SDComment: Cosmetic things missing
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"
#include "Player.h"

enum Spells
{
    //Vehicle
    SPELL_CHARGE_GRAND_CHAMP            = 68321,
    SPELL_CHARGE_LESSER_CHAMP           = 63010,
    SPELL_SHIELD_BREAKER                = 68504,
    SPELL_SHIELD_GRAND_CHAMP            = 62719,
    SPELL_SHIELD_LESSER_CHAMP           = 64100,
    SPELL_TRAMPLE_DUMMY_AURA            = 67870, // triggers trample aura every 1 second, used by all vehicles
    SPELL_TRAMPLE_AURA                  = 67868, // actual trample stun

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    SPELL_MORTAL_STRIKE                 = 68783,
    SPELL_BLADESTORM                    = 67541,
    SPELL_INTERCEPT                     = 67540,
    SPELL_ROLLING_THROW                 = 67546,

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    SPELL_FIREBALL                      = 66042,
    SPELL_BLAST_WAVE                    = 66044,
    SPELL_HASTE                         = 66045,
    SPELL_POLYMORPH                     = 66043,

    // Colosos && Runok Wildmane || Shaman
    SPELL_CHAIN_LIGHTNING               = 67529,
    SPELL_EARTH_SHIELD                  = 67530,
    SPELL_HEALING_WAVE                  = 67528,
    SPELL_HEX_OF_MENDING                = 67534,

    // Jaelyne Evensong && Zul'tore || Hunter
    SPELL_DISENGAGE                     = 68340,
    SPELL_LIGHTNING_ARROWS              = 66083,
    SPELL_MULTI_SHOT                    = 66081,
    SPELL_SHOOT                         = 66079,

    // Lana Stouthammer && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                    = 67709,
    SPELL_FAN_OF_KNIVES                 = 67706,
    SPELL_POISON_BOTTLE                 = 67701
};

enum Texts
{
    EMOTE_TRAMPLE                       = 0
};

enum Seats
{
    SEAT_ID_0                           = 0
};

void EnterAggressiveMode(Creature* temp)
{
    temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
    temp->SetReactState(REACT_AGGRESSIVE);
}

void DoCastPennant(Creature* me)
{
    switch (me->GetEntry())
    {
        case NPC_MOKRA:
            me->CastSpell(me, SPELL_FLAG_ORGRIMMAR);
            break;
        case NPC_ERESSEA:
            me->CastSpell(me, SPELL_FLAG_SILVERMOON);
            break;
        case NPC_RUNOK:
            me->CastSpell(me, SPELL_FLAG_THUNDER_BLUFF);
            break;
        case NPC_ZULTORE:
            me->CastSpell(me, SPELL_FLAG_SENJIN);
            break;
        case NPC_VISCERI:
            me->CastSpell(me, SPELL_FLAG_UNDERCITY);
            break;
        case NPC_JACOB:
            me->CastSpell(me, SPELL_FLAG_STORMWIND);
            break;
        case NPC_AMBROSE:
            me->CastSpell(me, SPELL_FLAG_GNOMEREGAN);
            break;
        case NPC_COLOSOS:
            me->CastSpell(me, SPELL_FLAG_EXODAR);
            break;
        case NPC_JAELYNE:
            me->CastSpell(me, SPELL_FLAG_DARNASSUS);
            break;
        case NPC_LANA:
            me->CastSpell(me, SPELL_FLAG_IRONFORGE);
            break;
        default:
            break;
    }
    if (me->GetVehicleBase())
        me->CastSpell(me->GetVehicleBase(), SPELL_TRAMPLE_DUMMY_AURA, true);
}

Creature* FindMyMount(Creature* me, bool newMount = false)
{
    InstanceScript* instance = me->GetInstanceScript();
    if (newMount)
    {
        // Summoning a new vehicle if all others are used
        // can but should not occur
        uint32 tmpEntry = instance->GetData(DATA_PLAYERS_TEAM) == ALLIANCE ? VEHICLE_ARGENT_BATTLEWORG_COSMETIC : VEHICLE_ARGENT_WARHORSE_COSMETIC;
        if (Creature* newMount = me->SummonCreature(tmpEntry, bossExitPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
        {
            if (instance->GetGuidData(DATA_GRAND_CHAMPION_1) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, newMount->GetGUID());
            else if (instance->GetGuidData(DATA_GRAND_CHAMPION_2) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, newMount->GetGUID());
            else if (instance->GetGuidData(DATA_GRAND_CHAMPION_3) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, newMount->GetGUID());
            newMount->SetOrientation(centerOrientation);
            newMount->SetHomePosition(me->GetHomePosition());
            return newMount;
        }
    }
    if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_1))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1));
    else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_2))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2));
    else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_3))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3));

    // should not happen
    return NULL;
}

// called on rider
void SetGrandChampionToEvadeMode(Creature* me)
{
    me->RemoveAllAuras();
    me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
    me->DeleteThreatList();
    me->CombatStop(true);
    me->SetLootRecipient(NULL);
    me->AI()->Reset();
    if (Creature* mount = FindMyMount(me))
    {
        mount->AI()->Reset();
        EnterAggressiveMode(mount);
        mount->GetMotionMaster()->Clear();
        mount->GetMotionMaster()->MoveTargetedHome();
    }
    DoCastPennant(me);
    // On reset Grand Champions' flags are restored to DB values and we don't want that
    EnterAggressiveMode(me);
}

/*
* Generic AI for Grand Champions in ToC.                    *
* Script Complete: 100%                                     *
*/

struct toc_bossAI : ScriptedAI
{
    toc_bossAI(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        LookingForMount = false;
        MountedPhaseDone = false;
        IsChampionDown = false;
        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;
    }

    InstanceScript* instance;
    uint8 uiPhase;
    uint32 uiPhaseTimer;

    bool LookingForMount; // if is in looking for mount phase
    bool MountedPhaseDone; // if jousting phase is done
    bool IsChampionDown; // if champion is defeated
    bool bDone; // if all champions have been downed
    bool bHome; // if champion has reached home after jousing phase

    void Reset()
    {
        if (MountedPhaseDone)
            DoCastPennant(me);
    }
    
    bool GrandChampionsOutVehicle()
    {
        Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1));
        Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2));
        Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3));
        if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
        {
            if (!pGrandChampion1->GetVehicleBase() &&
                !pGrandChampion2->GetVehicleBase() &&
                !pGrandChampion3->GetVehicleBase())
                return true;
        }
        return false;
    }

    bool GrandChampionsDefeated()
    {
        Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1));
        Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2));
        Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3));
        if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
        {
            if (pGrandChampion1->getStandState() == UNIT_STAND_STATE_KNEEL &&
                pGrandChampion2->getStandState() == UNIT_STAND_STATE_KNEEL &&
                pGrandChampion3->getStandState() == UNIT_STAND_STATE_KNEEL)
                return true;
        }
        return false;
    }
    
    void AttackRandomPlayer(bool isEventDone)
    {  
        Map::PlayerList const &players = me->GetMap()->GetPlayers();
        if (players.isEmpty())
            return;
    
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player *plr = itr->GetSource();
            if (plr && !plr->IsGameMaster() && plr->IsAlive())
            {
                // if this boolean is true, all the champions will attack together the first found player
                if (isEventDone)
                {
                    Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1));
                    Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2));
                    Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3));
                    if (pGrandChampion1)
                    {
                        EnterAggressiveMode(pGrandChampion1);
                        if (!pGrandChampion1->GetVictim())
                            pGrandChampion1->GetAI()->AttackStart(plr);
                    }

                    if (pGrandChampion2)
                    {
                        EnterAggressiveMode(pGrandChampion2);
                        if (!pGrandChampion2->GetVictim())
                            pGrandChampion2->GetAI()->AttackStart(plr);
                    }

                    if (pGrandChampion3)
                    {
                        EnterAggressiveMode(pGrandChampion3);
                        if (!pGrandChampion3->GetVictim())
                            pGrandChampion3->GetAI()->AttackStart(plr);
                    }
                }
                break;
            }
        }
    }

    bool CanUseNormalAI()
    {
        return !UpdateVictim() || me->GetVehicleBase() || LookingForMount || !MountedPhaseDone;
    }

    void EnterEvadeMode()
    {
        if (LookingForMount || !MountedPhaseDone)
            return;

        ScriptedAI::EnterEvadeMode();
    }

    void JustReachedHome()
    {
        ScriptedAI::JustReachedHome();

        if (bHome)
        {
            // Champions will be unattackable for 15 seconds when reached their homepositions for first time after jousting event
            // After that time, they will start attacking a random player
            // if group wipes during actual fight, grand champions will be attackable immediately when reached home position
            uiPhase = 4;
            uiPhaseTimer = 15000;
            bHome = false;
        }
        else if (bDone)
            me->DisappearAndDie();
        else if (MountedPhaseDone && !bHome)
            EnterAggressiveMode(me);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
    {
        if (spell->Id == SPELL_TRAMPLE_AURA && LookingForMount && uiPhase == 0 && !me->IsImmunedToSpell(spell))
        {
            uiPhase = 3;
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveIdle();
            Talk(EMOTE_TRAMPLE, me);
            uiPhaseTimer = spell->GetDuration();
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE || !LookingForMount)
            return;

        if (id == 0)
        {
            // Reached point, mounting again
            if (Creature* mount = FindMyMount(me))
            {
                if (!me->IsWithinDist(mount, INTERACTION_DISTANCE))
                    return;

                LookingForMount = false;
                uiPhase = 2;
                me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, true); // Champion should be immune to trample here
                me->GetMotionMaster()->Clear();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); // to prevent boss from bugging out
                me->SetHealth(me->GetMaxHealth());
                me->setRegeneratingHealth(true);
                me->SetWalk(false);
                mount->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                // sometimes a player can trample champion right when he is about to enter in vehicle
                // it will bug the boss and you can kill him without the need to kill others as well
                // so we remove the stun aura just incase
                me->RemoveAura(SPELL_TRAMPLE_AURA); 
                me->EnterVehicle(mount, SEAT_ID_0);

                // In rare scenario all players can die meanwhile one of the champions is going for new mount, and then the champion ends in a bugged state
                // so we must check do we have alive players in the map first, else we call evade
                bool foundPlr = false;
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && player->IsAlive())
                        {
                            foundPlr = true;
                            break;
                        }
                    }
                }
                if (foundPlr)
                    uiPhaseTimer = 2000; // slight delay before attacking
                else
                    SetGrandChampionToEvadeMode(me);
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (damage >= me->GetHealth() && me->GetVehicleBase())
        {
            damage = 0;
            LookingForMount = true;
            uiPhase = 1;
            me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, true); // Champion should be immune to trample here
            me->ExitVehicle();
            me->RemoveAllAuras();
            DoCastPennant(me);
            me->SetReactState(REACT_PASSIVE);
            me->SetHealth(1);
            me->CombatStop(true);
            me->setRegeneratingHealth(false); // we don't regen health yet
            me->GetMotionMaster()->MoveIdle();
            me->SetWalk(true);
            // Champion's current vehicle runs to the gates and despawns
            // Champion will search for new mount
            if (Creature* mount = FindMyMount(me))
            {
                mount->GetMotionMaster()->Clear();
                mount->SetWalk(false);
                mount->SetReactState(REACT_PASSIVE);
                mount->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                
                uint32 newMountEntry = instance->GetData(DATA_PLAYERS_TEAM) == ALLIANCE ? VEHICLE_ARGENT_BATTLEWORG_COSMETIC : VEHICLE_ARGENT_WARHORSE_COSMETIC;
                Creature* newMount = NULL;
                uint32 dist = 0;
                std::list<Creature*> tempList;
                float x, y;
                me->GetPosition(x, y);

                CellCoord pair(Trinity::ComputeCellCoord(x, y));
                Cell cell(pair);
                cell.SetNoCreate();

                Trinity::AllCreaturesOfEntryInRange check(me, newMountEntry, 100);
                Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, tempList, check);
                TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);
                cell.Visit(pair, cSearcher, *(me->GetMap()), *me, me->GetGridActivationRange());
                for (std::list<Creature*>::const_iterator itr = tempList.begin(); itr != tempList.end(); ++itr)
                {
                    if (Creature* tmpMount = (*itr))
                    {
                        if (instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1) == tmpMount->GetGUID() ||
                            instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2) == tmpMount->GetGUID() ||
                            instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3) == tmpMount->GetGUID())
                            continue;

                        if (!tmpMount->IsAlive())
                            continue;

                        if (dist == 0)
                        {
                            dist = me->GetDistance(tmpMount);
                            newMount = tmpMount;
                        }

                        if (me->GetDistance(tmpMount) < dist)
                        {
                            dist = me->GetDistance(tmpMount);
                            newMount = tmpMount;
                        }
                    }
                }
                if (newMount)
                {
                    if (instance->GetGuidData(DATA_GRAND_CHAMPION_1) == me->GetGUID())
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, newMount->GetGUID());
                    else if (instance->GetGuidData(DATA_GRAND_CHAMPION_2) == me->GetGUID())
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, newMount->GetGUID());
                    else if (instance->GetGuidData(DATA_GRAND_CHAMPION_3) == me->GetGUID())
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, newMount->GetGUID());
                    newMount->SetHomePosition(mount->GetHomePosition());
                }
                else
                {
                    // Summoning a new mount for Grand Champion if every other mount have been used
                    if (FindMyMount(me, true)) { }
                }

                // Defeated mount runs towards the center of arena and disappears
                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    mount->GetMotionMaster()->MovePoint(1, announcer->GetHomePosition());
            }
            uiPhaseTimer = 3000; // slight delay before we run for new mount
            return;
        }
        else if (damage >= me->GetHealth() && LookingForMount)
        {
            damage = 0;
            return;
        }
        else if (damage >= me->GetHealth() && instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
        {
            damage = 0;
            if (!IsChampionDown)
            {
                TC_LOG_INFO("server.worldserver", "DEBUG: Grand Champion %u is down", me->GetEntry());
                IsChampionDown = true;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetHealth(1);
                me->CombatStop(true);
                me->setRegeneratingHealth(false);
                me->GetMotionMaster()->MoveIdle();
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
            }
            return;
        }
    }

    void AttackStart(Unit* who)
    {
        if (LookingForMount || uiPhase != 0)
            return;
        ScriptedAI::AttackStart(who);
    }

    void UpdateAI(uint32 uiDiff)
    {
        if (uiPhaseTimer <= uiDiff)
        {
            switch (uiPhase)
            {
                case 1:
                    // Starts walking for mount
                    if (!LookingForMount)
                        break;
                    me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
                    me->GetMotionMaster()->Clear();
                    if (Creature* mount = FindMyMount(me))
                        me->GetMotionMaster()->MovePoint(0, mount->GetPosition());
                    break;
                case 2:
                {
                    // We're mounted and preparing to attack
                    if (Creature* mount = FindMyMount(me))
                    {
                        me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoCastPennant(me);
                        EnterAggressiveMode(me);
                        EnterAggressiveMode(mount);
                        bool foundPlr = false;
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        if (!players.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                            {
                                Player* player = itr->GetSource();
                                if (player && !player->IsGameMaster() && player->IsAlive())
                                {
                                    if (player->GetVehicleBase())
                                        mount->AI()->AttackStart(player->GetVehicleBase());
                                    else
                                        mount->AI()->AttackStart(player);
                                    foundPlr = true;
                                    break;
                                }
                            }
                        }
                        if (!foundPlr)
                            SetGrandChampionToEvadeMode(me);
                    }
                    break;
                }
                case 3:
                    // Got trampled and continuing walking
                    me->GetMotionMaster()->Clear();
                    if (Creature* mount = FindMyMount(me))
                        me->GetMotionMaster()->MovePoint(0, mount->GetPosition());
                    break;
                case 4:
                    // Searches an enemy to attack
                    AttackRandomPlayer(true);
                    break;
                case 5:
                    // Entering to evade mode
                    bHome = true;
                    EnterEvadeMode();
                    break;
                case 6:
                    // Returning home
                    instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                default:
                    break;
            }
            uiPhase = 0;
        }
        else uiPhaseTimer -= uiDiff;

        if (!MountedPhaseDone && GrandChampionsOutVehicle())
        {
            // Champions have been defeated in jousting event
            MountedPhaseDone = true;
            if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_1))
                me->SetHomePosition(739.678f, 660.975f, 412.393f, 4.49f);
            else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_2))
                me->SetHomePosition(746.71f, 661.02f, 411.69f, 4.6f);
            else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_3))
                me->SetHomePosition(754.34f, 660.70f, 412.39f, 4.79f);

            if (Creature* mount = FindMyMount(me))
                mount->DisappearAndDie();

            LookingForMount = false;
            me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
            me->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->Clear();
            me->setRegeneratingHealth(true);
            instance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            uiPhase = 5;
            uiPhaseTimer = 2000; // minor delay before entering to evade mode to correct movement
        }

        if (!bDone && GrandChampionsDefeated())
        {
            // Grand Champions encounter is now over
            TC_LOG_INFO("server.worldserver", "DEBUG: Grand Champion encounter down");
            bDone = true;
            me->SetHomePosition(bossExitPos);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetWalk(true);
            uiPhase = 6;
            uiPhaseTimer = 1000; // very short delay before giving loot chest
        }
    }
};

/*
* Generic AI for vehicles used by npcs in ToC.              *
* Code requires cleanup and vehicles some improvement       *
* Script Complete: 95%.                                     *
*/

class generic_vehicleAI_toc5 : public CreatureScript
{
public:
    generic_vehicleAI_toc5() : CreatureScript("generic_vehicleAI_toc5") { }

    struct generic_vehicleAI_toc5AI : public npc_escortAI
    {
        generic_vehicleAI_toc5AI(Creature* creature) : npc_escortAI(creature)
        {
            Initialize();
            SetDespawnAtEnd(false);
            uiWaypointPath = 0;

            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiChargeTimer = 5000;
            uiShieldBreakerTimer = 8000;
            uiBuffTimer = 5000;
            uiFlagTimer = 5000;
            castedPennant = false;
        }

        InstanceScript* instance;

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;
        uint32 uiBuffTimer;
        uint32 uiFlagTimer;

        bool castedPennant;
        uint32 uiWaypointPath;

        void Reset() override
        {
            Initialize();
        }

        bool IsGrandChampionVehicle()
        {
            if (instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1) == me->GetGUID() ||
                instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2) == me->GetGUID() ||
                instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3) == me->GetGUID())
                return true;
            return false;
        }

        bool IsLesserChampion()
        {
            if (me->GetEntry() == VEHICLE_DARNASSUS_CHAMPION ||
                me->GetEntry() == VEHICLE_EXODAR_CHAMPION ||
                me->GetEntry() == VEHICLE_STORMWIND_CHAMPION ||
                me->GetEntry() == VEHICLE_GNOMEREGAN_CHAMPION ||
                me->GetEntry() == VEHICLE_IRONFORGE_CHAMPION ||
                me->GetEntry() == VEHICLE_UNDERCITY_CHAMPION ||
                me->GetEntry() == VEHICLE_THUNDER_BLUFF_CHAMPION ||
                me->GetEntry() == VEHICLE_ORGRIMMAR_CHAMPION ||
                me->GetEntry() == VEHICLE_SILVERMOON_CHAMPION ||
                me->GetEntry() == VEHICLE_SENJIN_CHAMPION)
                return true;
            return false;
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_GENERATE_WAYPOINTS_FOR_BOSS_1:
                    if (uiData == HORDE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 780.43f, 607.15f, 411.82f);
                        AddWaypoint(2, 785.99f, 599.41f, 411.92f);
                        AddWaypoint(3, GrandChampFinalLoc[3].GetPositionX(), GrandChampFinalLoc[3].GetPositionY(), GrandChampFinalLoc[3].GetPositionZ());
                    }
                    else if (uiData == ALLIANCE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 700.39f, 618.73f, 412.39f);
                        AddWaypoint(2, 703.59f, 618.48f, 411.92f);
                        AddWaypoint(3, GrandChampFinalLoc[0].GetPositionX(), GrandChampFinalLoc[0].GetPositionY(), GrandChampFinalLoc[0].GetPositionZ());
                    }
                    uiWaypointPath = WAYPOINT_MAP_BOSS_1;
                    break;
                case DATA_GENERATE_WAYPOINTS_FOR_BOSS_2:
                    if (uiData == HORDE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 792.36f, 614.47f, 412.39f);
                        AddWaypoint(2, GrandChampFinalLoc[4].GetPositionX(), GrandChampFinalLoc[4].GetPositionY(), GrandChampFinalLoc[4].GetPositionZ());
                    }
                    else if (uiData == ALLIANCE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 708.31f, 635.07f, 411.93f);
                        AddWaypoint(2, GrandChampFinalLoc[1].GetPositionX(), GrandChampFinalLoc[1].GetPositionY(), GrandChampFinalLoc[1].GetPositionZ());
                    }
                    uiWaypointPath = WAYPOINT_MAP_BOSS_2;
                    break;
                case DATA_GENERATE_WAYPOINTS_FOR_BOSS_3:
                    if (uiData == HORDE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 793.00f, 624.40f, 412.39f);
                        AddWaypoint(2, GrandChampFinalLoc[5].GetPositionX(), GrandChampFinalLoc[5].GetPositionY(), GrandChampFinalLoc[5].GetPositionZ());
                    }
                    else if (uiData == ALLIANCE)
                    {
                        AddWaypoint(0, 747.35f, 634.07f, 411.57f);
                        AddWaypoint(1, 716.67f, 651.1f, 411.93f);
                        AddWaypoint(2, GrandChampFinalLoc[2].GetPositionX(), GrandChampFinalLoc[2].GetPositionY(), GrandChampFinalLoc[2].GetPositionZ());
                    }
                    uiWaypointPath = WAYPOINT_MAP_BOSS_3;
                    break;
                case DATA_GENERATE_WAYPOINTS_FOR_ADDS:
                    AddWaypoint(0, LesserChampLoc[uiData].GetPositionX(), LesserChampLoc[uiData].GetPositionY(), LesserChampLoc[uiData].GetPositionZ());
                    uiWaypointPath = WAYPOINT_MAP_ADDS;
                    Start(false); // Lesser Champions walk to their positions
                    break;
            }

            if (uiType <= DATA_GENERATE_WAYPOINTS_FOR_BOSS_3)
                Start(false, true); // Grand Champions run to their positions
        }

        void EnterEvadeMode() override
        {
            // Evade is handled in its own custom function for vehicles
            if (IsGrandChampionVehicle() || me->GetEntry() == VEHICLE_ARGENT_BATTLEWORG_COSMETIC || me->GetEntry() == VEHICLE_ARGENT_WARHORSE_COSMETIC)
                return;

            npc_escortAI::EnterEvadeMode();
        }

        void WaypointReached(uint32 waypointId) override 
        {
            uint32 TeamInInstance = instance->GetData(DATA_PLAYERS_TEAM);
            // Grand Champions reached their final positions in the jousting event
            // and Lesser Champions begin to correct their positions
            if ((uiWaypointPath == WAYPOINT_MAP_BOSS_1 && waypointId == 3) || ((uiWaypointPath == WAYPOINT_MAP_BOSS_2 || uiWaypointPath == WAYPOINT_MAP_BOSS_3) && waypointId == 2))
            {
                if (Creature* herald = ObjectAccessor::GetCreature(*me, (instance->GetGuidData(DATA_ANNOUNCER))))
                {
                    if (TeamInInstance == ALLIANCE)
                        me->SetFacingTo(hordeOrientation);
                    else
                        me->SetFacingTo(allianceOrientation);
                    me->SetHomePosition(me->GetPosition());
                    if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0) && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                        me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature()->SetHomePosition(me->GetPosition());
                    herald->AI()->SetData(DATA_LESSER_CHAMPIONS_PREPARE, uiWaypointPath);
                }
            }
            // Grand Champions run from gates into the arena and then walk towards their waiting positions
            else if (uiWaypointPath < WAYPOINT_MAP_ADDS && waypointId == 0)
                me->SetWalk(true);
            // Lesser Champions correct their orientation
            else if (uiWaypointPath == WAYPOINT_MAP_ADDS && waypointId == 0)
            {
                if (TeamInInstance == ALLIANCE)
                    me->SetFacingTo(hordeOrientation);
                else
                    me->SetFacingTo(allianceOrientation);
                me->SetHomePosition(me->GetPosition());
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            npc_escortAI::MovementInform(uiType, uiPointId);

            if (uiType != POINT_MOTION_TYPE)
                return;

            // Grand Champions' mount will despawn when it has run to the gates
            if (uiPointId == 1 && me->GetVehicleKit() && !me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                me->DisappearAndDie();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (IsLesserChampion())
            {
                me->Dismount();
                if (Creature* herald = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    herald->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED, 0);
            }
        }

        void DoCastShield()
        {
            if (IsGrandChampionVehicle())
            {
                if (me->GetVehicleKit())
                    if (Unit *rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                        rider->CastSpell(rider, SPELL_SHIELD_GRAND_CHAMP, true);
            }
            else if (IsLesserChampion())
                  DoCast(me, SPELL_SHIELD_LESSER_CHAMP, true);
        }

        void AttackStart(Unit* target)
        {
            if (IsGrandChampionVehicle())
            {
                if (!(me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)))
                    return;

                if (me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->AttackStop();
                
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(target, 0, 0);
            }
            else if (IsLesserChampion())
                ScriptedAI::AttackStart(target);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (uiBuffTimer <= uiDiff)
            {
                DoCastShield();
                uiBuffTimer = 7000;
            }
            else uiBuffTimer -= uiDiff;

            if (IsGrandChampionVehicle())
            {
                if (uiFlagTimer <= uiDiff && !castedPennant)
                {
                    if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0) && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                        DoCastPennant(me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature());
                    castedPennant = true;
                    uiFlagTimer = 0;
                }
                else uiFlagTimer -= uiDiff;
            }

            if (IsGrandChampionVehicle())
            {
                if (!me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                    return;

                Unit* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0);
                if (!rider)
                    return;

                if (!rider->IsInCombat())
                    return;

                if ((rider->ToCreature() && !rider->ToCreature()->HasReactState(REACT_PASSIVE)) && !me->HasReactState(REACT_PASSIVE))
                {
                    if (rider->GetVictim() == nullptr)
                    {
                        SetGrandChampionToEvadeMode(rider->ToCreature());
                        return;
                    }
                }
                else if (rider->getThreatManager().isThreatListEmpty())
                {
                    SetGrandChampionToEvadeMode(rider->ToCreature());
                    return;
                }
            }
            else if (!UpdateVictim())
                return;

            // Charge is casted on random player
            // Champions' threatlist is reseted when using charge
            if (uiChargeTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->IsGameMaster() && player->IsAlive() && me->IsInRange(player, 8.0f, 25.0f, false))
                        {
                            uint32 spell_charge = IsGrandChampionVehicle() ? SPELL_CHARGE_GRAND_CHAMP : SPELL_CHARGE_LESSER_CHAMP;
                            if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                            {
                                if (Unit* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                                {
                                    if (player->GetVehicleBase())
                                        rider->CastSpell(player->GetVehicleBase(), spell_charge);
                                    else
                                        rider->CastSpell(player, spell_charge);
                                    me->GetMotionMaster()->MoveCharge(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
                                }
                            }
                            else
                            {
                                if (player->GetVehicleBase())
                                    DoCast(player->GetVehicleBase(), spell_charge);
                                else
                                    DoCast(player, spell_charge);
                            }

                            if (IsGrandChampionVehicle())
                            {
                                if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                                {
                                    if (Creature* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                                    {
                                        // DoResetThreat() basically
                                        if (!rider->getThreatManager().isThreatListEmpty())
                                        {
                                            ThreatContainer::StorageType threatlist = rider->getThreatManager().getThreatList();
                                            for (ThreatContainer::StorageType::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                                            {
                                                if (Unit* unit = ObjectAccessor::GetUnit(*rider, (*itr)->getUnitGuid()))
                                                {
                                                    if (rider->getThreatManager().getThreat(unit))
                                                        rider->getThreatManager().modifyThreatPercent(unit, -100);
                                                }
                                            }
                                        }
                                        if (player->GetVehicleBase())
                                        {
                                            rider->AddThreat(player->GetVehicleBase(), 1.0f);
                                            me->AI()->AttackStart(player->GetVehicleBase());
                                        }
                                        else
                                        {
                                            rider->AddThreat(player, 1.0f);
                                            me->AI()->AttackStart(player);
                                        }
                                        me->GetMotionMaster()->MoveCharge(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
                                    }
                                }
                            }
                            else
                            {
                                DoResetThreat();
                                if (player->GetVehicleBase())
                                    me->AddThreat(player->GetVehicleBase(), 1.0f);
                                else
                                    me->AddThreat(player, 1.0f);
                            }
                            break;
                        }
                    }
                }
                uiChargeTimer = 5000;
            }else uiChargeTimer -= uiDiff;

            // Lesser Champions don't use Shield Breaker
            // Shield Breaker is cast on random player
            if (IsGrandChampionVehicle())
            {
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
                                if (player && !player->IsGameMaster() && player->IsAlive() && me->IsInRange(player, 5.0f, 30.0f, false))
                                {
                                    if (player->GetVehicleBase())
                                        pPassenger->CastSpell(player->GetVehicleBase(), SPELL_SHIELD_BREAKER);
                                    else
                                        pPassenger->CastSpell(player, SPELL_SHIELD_BREAKER);
                                    break;
                                }
                            }
                        }
                    }
                    uiShieldBreakerTimer = 7000;
                }
                else uiShieldBreakerTimer -= uiDiff;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<generic_vehicleAI_toc5AI>(creature);
    }
};

class boss_warrior_toc5 : public CreatureScript
{
public:
    boss_warrior_toc5() : CreatureScript("boss_warrior_toc5") { }

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    struct boss_warrior_toc5AI : public toc_bossAI
    {
        boss_warrior_toc5AI(Creature* creature) : toc_bossAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiBladeStormTimer = urand(15000, 20000);
            uiInterceptTimer = 7000;
            uiMortalStrikeTimer = urand(8000, 12000);
            uiRollingThrowTimer = 30000;
        }

        InstanceScript* instance;

        uint32 uiBladeStormTimer;
        uint32 uiInterceptTimer;
        uint32 uiMortalStrikeTimer;
        uint32 uiRollingThrowTimer;

        void Reset() override
        {
            Initialize();
            toc_bossAI::Reset();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            toc_bossAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (uiInterceptTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
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

            if (uiRollingThrowTimer <= uiDiff)
            {
                DoCastVictim(SPELL_ROLLING_THROW);
                uiRollingThrowTimer = 30000;
            } else uiRollingThrowTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_warrior_toc5AI>(creature);
    }
};

class boss_mage_toc5 : public CreatureScript
{
public:
    boss_mage_toc5() : CreatureScript("boss_mage_toc5") { }

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    struct boss_mage_toc5AI : public toc_bossAI
    {
        boss_mage_toc5AI(Creature* creature) : toc_bossAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiFireBallTimer = 2000;
            uiPolymorphTimer = 8000;
            uiBlastWaveTimer = 12000;
            uiHasteTimer = 22000;
        }

        InstanceScript* instance;

        uint32 uiFireBallTimer;
        uint32 uiBlastWaveTimer;
        uint32 uiHasteTimer;
        uint32 uiPolymorphTimer;

        void Reset() override
        {
            Initialize();
            toc_bossAI::Reset();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            toc_bossAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (uiFireBallTimer <= uiDiff)
            {
                DoCastVictim(SPELL_FIREBALL);
                uiFireBallTimer = 3000;
            } else uiFireBallTimer -= uiDiff;

            if (uiPolymorphTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_POLYMORPH);
                uiPolymorphTimer = 8000;
            } else uiPolymorphTimer -= uiDiff;

            if (uiBlastWaveTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                {
                    if (me->IsWithinDist(target, 10.0f, false))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCastAOE(SPELL_BLAST_WAVE);
                    }
                }
                uiBlastWaveTimer = 13000;
            } else uiBlastWaveTimer -= uiDiff;

            if (uiHasteTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);
                DoCast(me, SPELL_HASTE);
                uiHasteTimer = 22000;
            } else uiHasteTimer -= uiDiff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_mage_toc5AI>(creature);
    }
};

class boss_shaman_toc5 : public CreatureScript
{
public:
    boss_shaman_toc5() : CreatureScript("boss_shaman_toc5") { }

    // Colosos && Runok Wildmane || Shaman
    struct boss_shaman_toc5AI : public toc_bossAI
    {
        boss_shaman_toc5AI(Creature* creature) : toc_bossAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiCheckTimer = 5000;
            uiChainLightningTimer = 16000;
            uiHealingWaveTimer = 12000;
            uiEartShieldTimer = 5000;
            uiHexMendingTimer = 7000;

            isDefensive = false;
        }

        InstanceScript* instance;

        uint32 uiCheckTimer;
        uint32 uiChainLightningTimer;
        uint32 uiEartShieldTimer;
        uint32 uiHealingWaveTimer;
        uint32 uiHexMendingTimer;

        // If shaman's friend or himself goes below 25% HP, he will go into defensive mode,
        // casting healing spells only
        bool isDefensive;

        void Reset() override
        {
            Initialize();
            toc_bossAI::Reset();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            toc_bossAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (uiCheckTimer <= uiDiff)
            {
                if (!isDefensive)
                {
                    Unit* pFriend = DoSelectLowestHpFriendly(40.0f);
                    if (pFriend->GetHealthPct() <= 25 || me->GetHealthPct() <= 25)
                    {
                        me->InterruptNonMeleeSpells(true);
                        uiEartShieldTimer = 1000;
                        uiHealingWaveTimer = 1000;
                        TC_LOG_INFO("server.worldserver", "DEBUG: Shaman entered into defensive mode");
                        isDefensive = true;
                    }
                }
                else
                {
                    Unit* pFriend = DoSelectLowestHpFriendly(40.0f);
                    if (pFriend->GetHealthPct() > 25 && me->GetHealthPct() > 25)
                    {
                        uiChainLightningTimer = 1000;
                        TC_LOG_INFO("server.worldserver", "DEBUG: Shaman entered into combat mode");
                        isDefensive = false;
                    }
                }
                uiCheckTimer = 5000;
            } else uiCheckTimer -= uiDiff;

            if (uiChainLightningTimer <= uiDiff)
            {
                if (!isDefensive)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    uiChainLightningTimer = 16000;
                }
            } else uiChainLightningTimer -= uiDiff;

            if (uiHealingWaveTimer <= uiDiff)
            {
                if (Unit* pFriend = DoSelectLowestHpFriendly(40.0f))
                {
                    if (pFriend->GetHealthPct() < me->GetHealthPct())
                        DoCast(pFriend, SPELL_HEALING_WAVE);
                    else
                        DoCast(me, SPELL_HEALING_WAVE);
                }
                if (isDefensive)
                    uiHealingWaveTimer = 4000;
                else
                    uiHealingWaveTimer = 12000;
            } else uiHealingWaveTimer -= uiDiff;

            if (uiEartShieldTimer <= uiDiff)
            {
                if (Unit* pFriend = DoSelectLowestHpFriendly(40.0f))
                {
                    if (pFriend->GetHealthPct() < me->GetHealthPct())
                        DoCast(pFriend, SPELL_EARTH_SHIELD);
                    else
                        DoCast(me, SPELL_EARTH_SHIELD);
                }
                uiEartShieldTimer = urand(30000, 35000);
            } else uiEartShieldTimer -= uiDiff;

            if (uiHexMendingTimer <= uiDiff)
            {
                DoCastVictim(SPELL_HEX_OF_MENDING);
                uiHexMendingTimer = urand(20000, 25000);
            } else uiHexMendingTimer -= uiDiff;

            if (!isDefensive)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_shaman_toc5AI>(creature);
    }
};

class boss_hunter_toc5 : public CreatureScript
{
public:
    boss_hunter_toc5() : CreatureScript("boss_hunter_toc5") { }

        // Jaelyne Evensong && Zul'tore || Hunter
    struct boss_hunter_toc5AI : public toc_bossAI
    {
        boss_hunter_toc5AI(Creature* creature) : toc_bossAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiShootTimer = 2000;
            uiMultiShotTimer = 0;
            uiLightningArrowsTimer = 7000;
            uiDisengageTimer = urand(25000, 35000);

            uiTargetGUID.Clear();
            bShoot = false;
        }

        InstanceScript* instance;

        uint32 uiShootTimer;
        uint32 uiMultiShotTimer;
        uint32 uiLightningArrowsTimer;
        uint32 uiDisengageTimer;

        ObjectGuid uiTargetGUID;
        bool bShoot;

        void Reset() override
        {
            Initialize();
            toc_bossAI::Reset();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            toc_bossAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (uiDisengageTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                {
                    if (me->IsWithinDist(target, 5.0f, false)) // Disengage only if there is player too close
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_DISENGAGE);
                    }
                }
                uiDisengageTimer = urand(25000, 35000);
            }
            else uiDisengageTimer -= uiDiff;

            if (uiLightningArrowsTimer <= uiDiff)
            {
                DoCastAOE(SPELL_LIGHTNING_ARROWS);
                uiLightningArrowsTimer = 7000;
            } else uiLightningArrowsTimer -= uiDiff;

            if (uiShootTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 30.0f))
                {
                    uiTargetGUID = target->GetGUID();
                    DoCast(target, SPELL_SHOOT);
                }
                uiShootTimer = 2000;
                if (!bShoot)
                {
                    uiMultiShotTimer = 7500;
                    bShoot = true;
                }
            } else uiShootTimer -= uiDiff;

            if (bShoot && uiMultiShotTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);
                Unit* target = ObjectAccessor::GetUnit(*me, uiTargetGUID);
                if (target && me->IsInRange(target, 5.0f, 30.0f, false))
                {
                    DoCast(target, SPELL_MULTI_SHOT);
                }
                else
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (!players.isEmpty())
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
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_hunter_toc5AI>(creature);
    }
};

class boss_rouge_toc5 : public CreatureScript
{
public:
    boss_rouge_toc5() : CreatureScript("boss_rouge_toc5") { }

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    struct boss_rouge_toc5AI : public toc_bossAI
    {
        boss_rouge_toc5AI(Creature* creature) : toc_bossAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiEviscerateTimer = 8000;
            uiFanKivesTimer = 14000;
            uiPosionBottleTimer = 19000;
        }

        InstanceScript* instance;

        uint32 uiEviscerateTimer;
        uint32 uiFanKivesTimer;
        uint32 uiPosionBottleTimer;

        void Reset() override
        {
            Initialize();
            toc_bossAI::Reset();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            toc_bossAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (uiEviscerateTimer <= uiDiff)
            {
                DoCastVictim(SPELL_EVISCERATE);
                uiEviscerateTimer = 8000;
            } else uiEviscerateTimer -= uiDiff;

            if (uiFanKivesTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                {
                    if (me->IsWithinDist(target, 8.0f, false)) // 8 yards is minimum range
                        DoCastAOE(SPELL_FAN_OF_KNIVES);
                }
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
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_rouge_toc5AI>(creature);
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
