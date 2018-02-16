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

#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"

enum Events
{
    // Grand Champion
    EVENT_WALK_TO_MOUNT                 = 1,
    EVENT_START_ATTACK_JOUST,
    EVENT_TRAMPLE,
    EVENT_EVADE_MODE,
    EVENT_START_ATTACK_REAL,
    EVENT_DESPAWN,
    // General vehicle AI
    EVENT_BUFF_SHIELD,
    EVENT_BUFF_FLAG,
    EVENT_MOUNT_CHARGE,
    EVENT_SHIELD_BREAKER,
    // Warrior - Grand Champion
    EVENT_BLADESTORM,
    EVENT_INTERCEPT,
    EVENT_MORTAL_STRIKE,
    EVENT_ROLLING_THROW,
    // Mage - Grand Champion
    EVENT_FIREBALL,
    EVENT_BLASTWAVE,
    EVENT_HASTE,
    EVENT_POLYMORPH,
    // Shaman - Grand Champion
    EVENT_DEF_CHECK,
    EVENT_CHAIN_LIGHTNING,
    EVENT_HEALING_WAVE,
    EVENT_EARTH_SHIELD,
    EVENT_HEX_MENDING,
    // Hunter - Grand Champion
    EVENT_MULTI_SHOT,
    EVENT_LIGHTNING_ARROWS,
    EVENT_DISENGAGE,
    // Rogue - Grand Champion
    EVENT_DEADLY_POISON,
    EVENT_EVISCERATE,
    EVENT_FAN_OF_KNIVES,
    EVENT_POISON_BOTTLE
};

enum Spells
{
    // Vehicle
    SPELL_CHARGE_GRAND_CHAMP            = 68321,
    SPELL_CHARGE_LESSER_CHAMP           = 63010,
    SPELL_SHIELD_BREAKER                = 68504,
    SPELL_SHIELD_GRAND_CHAMP            = 62719,
    SPELL_SHIELD_LESSER_CHAMP           = 64100,
    SPELL_TRAMPLE_DUMMY_AURA            = 67870, // triggers trample aura every 1 second, used by all vehicles
    SPELL_TRAMPLE_AURA                  = 67868, // actual trample stun

    // General
    SPELL_ACHIEVEMENT_CREDIT            = 68572, // dummy spell for achievement credit (IDs 4297, 4298, 3778, 4296)
    SPELL_KNEEL                         = 68442,

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
    SPELL_DISENGAGE                     = 68339, // 68340 is correct disengage but spell needs to be scripted
    SPELL_LIGHTNING_ARROWS              = 66083,
    SPELL_LIGHTNING_ARROWS_AURA         = 66085,
    SPELL_MULTI_SHOT                    = 66081,
    SPELL_SHOOT                         = 66079,

    // Lana Stouthammer && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                    = 67709,
    SPELL_FAN_OF_KNIVES                 = 67706,
    SPELL_POISON_BOTTLE                 = 67701,
    SPELL_DEADLY_POISON                 = 67711
};

enum Texts
{
    EMOTE_TRAMPLE                       = 0
};

enum PointMovement
{
    POINT_REMOUNT                       = 0,
    POINT_DESPAWN
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
            me->CastSpell(me, SPELL_PENNANT_ORGRIMMAR);
            break;
        case NPC_ERESSEA:
            me->CastSpell(me, SPELL_PENNANT_SILVERMOON);
            break;
        case NPC_RUNOK:
            me->CastSpell(me, SPELL_PENNANT_THUNDER_BLUFF);
            break;
        case NPC_ZULTORE:
            me->CastSpell(me, SPELL_PENNANT_SEN_JIN);
            break;
        case NPC_VISCERI:
            me->CastSpell(me, SPELL_PENNANT_UNDERCITY);
            break;
        case NPC_JACOB:
            me->CastSpell(me, SPELL_PENNANT_STORMWIND);
            break;
        case NPC_AMBROSE:
            me->CastSpell(me, SPELL_PENNANT_GNOMEREGAN);
            break;
        case NPC_COLOSOS:
            me->CastSpell(me, SPELL_PENNANT_EXODAR);
            break;
        case NPC_JAELYNE:
            me->CastSpell(me, SPELL_PENNANT_DARNASSUS);
            break;
        case NPC_LANA:
            me->CastSpell(me, SPELL_PENNANT_IRONFORGE);
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
        uint32 tmpEntry = instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? VEHICLE_ARGENT_BATTLEWORG_COSMETIC : VEHICLE_ARGENT_WARHORSE_COSMETIC;
        if (Creature* mount = me->SummonCreature(tmpEntry, bossExitPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
        {
            if (instance->GetGuidData(DATA_GRAND_CHAMPION_1) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, mount->GetGUID());
            else if (instance->GetGuidData(DATA_GRAND_CHAMPION_2) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, mount->GetGUID());
            else if (instance->GetGuidData(DATA_GRAND_CHAMPION_3) == me->GetGUID())
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, mount->GetGUID());
            mount->SetOrientation(centerOrientation);
            mount->SetHomePosition(me->GetHomePosition());
            return mount;
        }
    }
    if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_1))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1));
    else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_2))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2));
    else if (me->GetGUID() == instance->GetGuidData(DATA_GRAND_CHAMPION_3))
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3));

    // should not happen
    return nullptr;
}

// called on rider
void SetGrandChampionToEvadeMode(Creature* me)
{
    me->RemoveAllAuras();
    me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
    me->GetThreatManager().ClearAllThreat();
    me->CombatStop(true);
    me->SetLootRecipient(nullptr);
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

struct boss_grand_championAI : BossAI
{
    boss_grand_championAI(Creature* creature) : BossAI(creature, DATA_GRAND_CHAMPIONS)
    {
        LookingForMount = false;
        MountedPhaseDone = false;
        IsChampionDown = false;
        bDone = false;
        bHome = false;

        uiPhase = 0;
    }
    uint8 uiPhase;

    bool LookingForMount; // if is in looking for mount phase
    bool MountedPhaseDone; // if jousting phase is done
    bool IsChampionDown; // if champion is defeated
    bool bDone; // if all champions have been downed
    bool bHome; // if champion has reached home after jousing phase

    void Reset() override
    {
        if (MountedPhaseDone)
            DoCastPennant(me);
        if (IsChampionDown)
            IsChampionDown = false;
        _Reset();
    }

    bool GrandChampionsOutOfVehicles()
    {
        for (int i = 0; i < 3; i++)
        {
            if (Creature* pGrandChampion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + i)))
            {
                if (pGrandChampion->GetVehicleBase())
                    return false;
            }
        }
        return true;
    }

    bool GrandChampionsDefeated()
    {
        for (int i = 0; i < 3; i++)
        {
            if (Creature* pGrandChampion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + i)))
            {
                if (!pGrandChampion->HasAura(SPELL_KNEEL))
                    return false;
            }
        }
        return true;
    }

    void AttackRandomPlayer()
    {
        Map::PlayerList const &players = me->GetMap()->GetPlayers();
        if (players.isEmpty())
            return;

        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player *plr = itr->GetSource();
            if (plr && !plr->IsGameMaster() && plr->IsAlive())
            {
                for (int i = 0; i < 3; i++)
                {
                    if (Creature* pGrandChampion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + i)))
                    {
                        EnterAggressiveMode(pGrandChampion);
                        if (!pGrandChampion->IsInCombat())
                            pGrandChampion->AI()->AttackStart(plr);
                    }
                }
                break;
            }
        }
    }

    bool CanUseNormalAI()
    {
        // must check for unattackable flag to prevent crash in certain situations
        return !UpdateVictim() || me->GetVehicleBase() || LookingForMount || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) || !MountedPhaseDone;
    }

    void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override
    {
        if (LookingForMount || !MountedPhaseDone)
            return;

        // we must check if other champions have been downed and call evade for them
        // for example, if players wipe during killing the last champion
        for (int i = 0; i < 3; ++i)
        {
            if (Creature* pGrandChampion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + i)))
            {
                if (pGrandChampion->HasAura(SPELL_KNEEL))
                {
                    pGrandChampion->RemoveAllAuras();
                    pGrandChampion->GetThreatManager().ClearAllThreat();
                    pGrandChampion->SetLootRecipient(nullptr);
                    pGrandChampion->SetRegenerateHealth(true);
                    pGrandChampion->GetMotionMaster()->MoveTargetedHome();
                    pGrandChampion->AI()->Reset();
                }
            }
        }
        BossAI::EnterEvadeMode(why);
    }

    void JustReachedHome() override
    {
        if (bHome)
        {
            // Champions will be unattackable for 15 seconds when reached their homepositions for first time after jousting event
            // After that time, they will start attacking a random player
            // if group wipes during actual fight, grand champions will be attackable immediately when reached home position
            uiPhase = 4;
            events.ScheduleEvent(EVENT_START_ATTACK_REAL, 15000);
            bHome = false;
        }
        else if (MountedPhaseDone && !bHome)
            EnterAggressiveMode(me);
        _JustReachedHome();
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TRAMPLE_AURA && LookingForMount && uiPhase == 0 && !me->IsImmunedToSpell(spell, caster))
        {
            uiPhase = 3;
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveIdle();
            Talk(EMOTE_TRAMPLE, me);
            events.ScheduleEvent(EVENT_TRAMPLE, spell->GetDuration());
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_REMOUNT && LookingForMount)
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
                me->SetRegenerateHealth(true);
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
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* player = itr->GetSource();
                    if (player && !player->IsGameMaster() && player->IsAlive())
                    {
                        foundPlr = true;
                        break;
                    }
                }
                if (foundPlr)
                    events.ScheduleEvent(EVENT_START_ATTACK_JOUST, 2000); // slight delay before attacking
                else
                    SetGrandChampionToEvadeMode(me);
            }
        }
        else if (id == POINT_DESPAWN)
            me->DisappearAndDie();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
            me->SetRegenerateHealth(false); // we don't regen health yet
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

                uint32 newMountEntry = instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? VEHICLE_ARGENT_BATTLEWORG_COSMETIC : VEHICLE_ARGENT_WARHORSE_COSMETIC;
                Creature* newMount = nullptr;
                float dist = 0.0f;
                std::list<Creature*> tempList;

                Trinity::AllCreaturesOfEntryInRange check(me, newMountEntry, 100);
                Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, tempList, check);
                Cell::VisitGridObjects(me, searcher, me->GetGridActivationRange());

                for (std::list<Creature*>::const_iterator itr = tempList.begin(); itr != tempList.end(); ++itr)
                {
                    Creature* tmpMount = *itr;

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
                    (void)FindMyMount(me, true);
                }

                // Defeated mount runs towards the center of arena and disappears
                if (Creature* announcer = instance->GetCreature(DATA_ANNOUNCER))
                {
                    mount->GetMotionMaster()->Clear();
                    mount->GetMotionMaster()->MovePoint(1, announcer->GetHomePosition());
                }
            }
            events.ScheduleEvent(EVENT_WALK_TO_MOUNT, 3000); // slight delay before we go for new mount
            return;
        }
        else if (damage >= me->GetHealth() && LookingForMount)
        {
            damage = 0;
            return;
        }
        else if (damage >= me->GetHealth() && MountedPhaseDone)
        {
            damage = 0;
            if (!IsChampionDown)
            {
                IsChampionDown = true;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                me->SetHealth(1);
                me->CombatStop(true);
                me->SetRegenerateHealth(false);
                me->GetMotionMaster()->MoveIdle();
                me->RemoveAura(SPELL_EARTH_SHIELD);
                me->RemoveAura(SPELL_HASTE);
                me->RemoveAura(SPELL_LIGHTNING_ARROWS_AURA);
                me->RemoveAura(SPELL_BLADESTORM);
                me->CastSpell(me, SPELL_KNEEL, true);
            }
            return;
        }
        else if (bDone)
        {
            damage = 0;
            return;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        //if (MountedPhaseDone)
        //{
            // All champions should attack together
            for (int i = 0; i < 3; i++)
            {
                Creature* pGrandChampion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + i));
                if (pGrandChampion && !pGrandChampion->HasAura(SPELL_KNEEL) && !pGrandChampion->IsInCombat())
                    pGrandChampion->AI()->AttackStart(who);
            }
            _JustEngagedWith();
        //}
    }

    void AttackStart(Unit* who) override
    {
        if (LookingForMount || uiPhase != 0)
            return;
        if (Creature* mount = FindMyMount(me))
            mount->AI()->AttackStart(who);
        BossAI::AttackStart(who);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WALK_TO_MOUNT:
                    // Starts walking for mount
                    if (!LookingForMount)
                        break;
                    me->ApplySpellImmune(SPELL_TRAMPLE_AURA, IMMUNITY_ID, SPELL_TRAMPLE_AURA, false);
                    // Sometimes boss can bug out after being thrown down from mount and reset flags to DB values
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                    me->GetMotionMaster()->Clear();
                    if (Creature* mount = FindMyMount(me))
                        me->GetMotionMaster()->MovePoint(POINT_REMOUNT, mount->GetPosition());
                    break;
                case EVENT_START_ATTACK_JOUST:
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
                        if (!foundPlr)
                            SetGrandChampionToEvadeMode(me);
                    }
                    break;
                }
                case EVENT_TRAMPLE:
                    // Got trampled and continuing walking
                    me->GetMotionMaster()->Clear();
                    if (Creature* mount = FindMyMount(me))
                        me->GetMotionMaster()->MovePoint(0, mount->GetPosition());
                    break;
                case EVENT_EVADE_MODE:
                    // Entering to evade mode after jousting event is done
                    bHome = true;
                    EnterEvadeMode();
                    break;
                case EVENT_START_ATTACK_REAL:
                    // Searches an enemy to attack after waited a while after jousting event
                    AttackRandomPlayer();
                    break;
                case EVENT_DESPAWN:
                    // Despawning
                    _JustDied();
                    me->RemoveAura(SPELL_KNEEL);
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_CREDIT, 0, me);
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_DESPAWN, bossExitPos);
                    break;
                default:
                    break;
            }
            uiPhase = 0;
        }

        if (!MountedPhaseDone && GrandChampionsOutOfVehicles())
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
            me->SetRegenerateHealth(true);
            instance->SetData(DATA_REMOVE_VEHICLES, 0);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            uiPhase = 5;
            events.ScheduleEvent(EVENT_EVADE_MODE, 2000); // minor delay before entering to evade mode to correct movement
        }

        if (!bDone && GrandChampionsDefeated())
        {
            // Grand Champions encounter is now over
            bDone = true;
            uiPhase = 6;
            events.ScheduleEvent(EVENT_DESPAWN, 2000); // minor delay before giving loot chest
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

    struct generic_vehicleAI_toc5AI : public EscortAI
    {
        generic_vehicleAI_toc5AI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
            SetDespawnAtEnd(false);
            uiWaypointPath = 0;

            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            castedPennant = false;
            events.ScheduleEvent(EVENT_BUFF_FLAG, 2000);
            events.ScheduleEvent(EVENT_BUFF_SHIELD, 5000);
            events.ScheduleEvent(EVENT_MOUNT_CHARGE, 5000);
            events.ScheduleEvent(EVENT_SHIELD_BREAKER, 8000);
        }

        InstanceScript* instance;

        EventMap events;

        bool castedPennant;
        uint32 uiWaypointPath;

        void Reset() override
        {
            events.Reset();
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
            switch (me->GetEntry())
            {
                case NPC_DARNASSUS_CHAMPION:
                case NPC_EXODAR_CHAMPION:
                case NPC_STORMWIND_CHAMPION:
                case NPC_GNOMEREGAN_CHAMPION:
                case NPC_IRONFORGE_CHAMPION:
                case NPC_UNDERCITY_CHAMPION:
                case NPC_THUNDER_BLUFF_CHAMPION:
                case NPC_ORGRIMMAR_CHAMPION:
                case NPC_SILVERMOON_CHAMPION:
                case NPC_SEN_JIN_CHAMPION:
                    return true;
            }
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
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(1, LesserChampLoc[uiData]);
                    uiWaypointPath = WAYPOINT_MAP_ADDS;
                    break;
            }

            if (uiType <= DATA_GENERATE_WAYPOINTS_FOR_BOSS_3)
                Start(false, true); // Grand Champions run to their positions
        }

        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override
        {
            // Evade is handled in UpdateAI for Grand Champions' vehicles
            // "Cosmetic" vehicles are no longer grand champions' vehicles when champions are
            // already walking to new mount, therefore they enter into evade mode instead of despawning
            if (IsGrandChampionVehicle() ||
                me->GetEntry() == VEHICLE_ARGENT_BATTLEWORG_COSMETIC ||
                me->GetEntry() == VEHICLE_ARGENT_WARHORSE_COSMETIC)
                return;

            EscortAI::EnterEvadeMode(why);
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            uint32 TeamInInstance = instance->GetData(DATA_TEAM_IN_INSTANCE);
            // Grand Champions reached their final positions in the jousting event
            // and Lesser Champions begin to correct their positions
            if ((uiWaypointPath == WAYPOINT_MAP_BOSS_1 && waypointId == 3) || ((uiWaypointPath == WAYPOINT_MAP_BOSS_2 || uiWaypointPath == WAYPOINT_MAP_BOSS_3) && waypointId == 2))
            {
                if (Creature* herald = instance->GetCreature(DATA_ANNOUNCER))
                {
                    if (TeamInInstance == ALLIANCE)
                        me->SetFacingTo(hordeOrientation);
                    else
                        me->SetFacingTo(allianceOrientation);
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TeamInInstance == ALLIANCE ? hordeOrientation : allianceOrientation);
                    if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0) && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                        me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature()->SetHomePosition(me->GetPosition());
                    herald->AI()->SetData(DATA_LESSER_CHAMPIONS_PREPARE, uiWaypointPath);
                }
            }
            // Grand Champions run from gates into the arena and then walk towards their waiting positions
            else if (uiWaypointPath < WAYPOINT_MAP_ADDS && waypointId == 0)
                me->SetWalk(true);
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            EscortAI::MovementInform(type, pointId);

            if (type != POINT_MOTION_TYPE)
                return;

            // Lesser Champions correct their orientation
            if (pointId == 1 && uiWaypointPath == WAYPOINT_MAP_ADDS)
            {
                uint32 TeamInInstance = instance->GetData(DATA_TEAM_IN_INSTANCE);
                if (TeamInInstance == ALLIANCE)
                    me->SetFacingTo(hordeOrientation);
                else
                    me->SetFacingTo(allianceOrientation);
                me->SetWalk(false);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TeamInInstance == ALLIANCE ? hordeOrientation : allianceOrientation);
            }

            // Grand Champions' old mount will despawn when it has run to the center of arena
            if (pointId == 1 && me->GetVehicleKit() && !me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                me->DisappearAndDie();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (IsLesserChampion())
            {
                me->Dismount();
                if (Creature* herald = instance->GetCreature(DATA_ANNOUNCER))
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

        void AttackStart(Unit* target) override
        {
            if (IsGrandChampionVehicle())
            {
                if (!(me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)))
                    return;

                if (me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                    me->AttackStop();

                me->GetMotionMaster()->MoveFollow(target, 0, 0);
            }
            else if (IsLesserChampion())
                ScriptedAI::AttackStart(target);
        }

        // returns true if we are in combat and we have a victim
        // returns false if we have no victim, and enters grand champion to evade mode
        bool CheckCombat()
        {
            if (IsGrandChampionVehicle())
            {
                if (!me->GetVehicleKit())
                    return false;

                Unit* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0);
                if (!rider)
                    return false;

                if (!rider->IsInCombat())
                    return false;

                if ((rider->ToCreature() && !rider->ToCreature()->HasReactState(REACT_PASSIVE)) && !me->HasReactState(REACT_PASSIVE))
                {
                    if (rider->GetVictim() == nullptr)
                    {
                        SetGrandChampionToEvadeMode(rider->ToCreature());
                        return false;
                    }
                }
                else if (rider->GetThreatManager().IsThreatListEmpty())
                {
                    SetGrandChampionToEvadeMode(rider->ToCreature());
                    return false;
                }
            }
            else if (!UpdateVictim())
                return false;
            return true;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            EscortAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BUFF_SHIELD:
                        DoCastShield();
                        events.ScheduleEvent(EVENT_BUFF_SHIELD, 7000);
                        break;
                    case EVENT_BUFF_FLAG:
                        if (IsGrandChampionVehicle())
                        {
                            if (!castedPennant)
                            {
                                if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0) && me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                                    DoCastPennant(me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature());
                                castedPennant = true;
                            }
                        }
                        break;
                    case EVENT_MOUNT_CHARGE:
                    {
                        if (CheckCombat())
                        {
                            // Charge is casted on random player
                            // Champions' threatlist is reseted when using charge
                            Map::PlayerList const& pList = me->GetMap()->GetPlayers();
                            // Player list is always in the same order so we must "randomize" it
                            if (!pList.isEmpty())
                            {
                                uint32 rand = urand(0, pList.getSize() - 1);
                                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                                {
                                    if (rand == 0)
                                    {
                                        Player* plr = itr->GetSource();
                                        if (plr && !plr->IsGameMaster() && plr->IsAlive() && me->IsInRange(plr, 8.0f, 25.0f, false))
                                        {
                                            uint32 spell_charge = IsGrandChampionVehicle() ? SPELL_CHARGE_GRAND_CHAMP : SPELL_CHARGE_LESSER_CHAMP;
                                            if (IsGrandChampionVehicle())
                                            {
                                                if (me->GetVehicleKit() && me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                                                {
                                                    if (Creature* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                                                    {
                                                        // Grand Champion
                                                        // Resetting rider's threat (DoResetThreat() cannot be used on external unit)
                                                        rider->GetThreatManager().ResetAllThreat();
                                                        // Setting gaze on the new player
                                                        if (plr->GetVehicleBase())
                                                            AddThreat(plr->GetVehicleBase(), 100000.0f);
                                                        else
                                                            AddThreat(plr, 100000.0f);
                                                        // Casting actual charge
                                                        if (plr->GetVehicleBase())
                                                            rider->CastSpell(plr->GetVehicleBase(), spell_charge);
                                                        else
                                                            rider->CastSpell(plr, spell_charge);
                                                        me->GetMotionMaster()->MoveCharge(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ());
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                // Lesser Champion
                                                // Resetting threat
                                                ResetThreatList();
                                                // Setting gaze on the new player
                                                if (plr->GetVehicleBase())
                                                    AddThreat(plr->GetVehicleBase(), 100000.0f);
                                                else
                                                    AddThreat(plr, 100000.0f);
                                                // Casting actual charge
                                                if (plr->GetVehicleBase())
                                                    DoCast(plr->GetVehicleBase(), spell_charge);
                                                else
                                                    DoCast(plr, spell_charge);
                                            }
                                            break;
                                        }
                                        else
                                            continue;
                                    }
                                    else
                                        --rand;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_MOUNT_CHARGE, 7000);
                        break;
                    }
                    case EVENT_SHIELD_BREAKER:
                        // Lesser Champions don't use Shield Breaker
                        if (IsGrandChampionVehicle() && me->GetVehicleKit())
                        {
                            if (CheckCombat())
                            {
                                if (Unit* rider = me->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                                {
                                    if (Unit* victim = rider->GetVictim())
                                    {
                                        if (rider->IsInRange(victim, 5.0f, 30.0f, false))
                                            rider->CastSpell(victim, SPELL_SHIELD_BREAKER);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_SHIELD_BREAKER, 4000);
                        }
                        break;
                    default:
                        break;
                }
            }

            if (!CheckCombat())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<generic_vehicleAI_toc5AI>(creature);
    }
};

class boss_warrior_toc5 : public CreatureScript
{
public:
    boss_warrior_toc5() : CreatureScript("boss_warrior_toc5") { }

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    struct boss_warrior_toc5AI : public boss_grand_championAI
    {
        boss_warrior_toc5AI(Creature* creature) : boss_grand_championAI(creature) { }

        void Reset() override
        {
            boss_grand_championAI::Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(EVENT_BLADESTORM, urand(15000, 20000));
            events.ScheduleEvent(EVENT_INTERCEPT, 7000);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(8000, 12000));
            events.ScheduleEvent(EVENT_ROLLING_THROW, 30000);
            boss_grand_championAI::JustEngagedWith(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            boss_grand_championAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTERCEPT:
                    {
                        if (!me->HasAura(SPELL_BLADESTORM))
                        {
                            Map::PlayerList const& pList = me->GetMap()->GetPlayers();
                            // Player list is always in the same order so we must "randomize" it
                            if (!pList.isEmpty())
                            {
                                uint32 rand = urand(0, pList.getSize() - 1);
                                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                                {
                                    if (rand == 0)
                                    {
                                        Player* plr = itr->GetSource();
                                        if (plr && !plr->IsGameMaster() && plr->IsAlive() && me->IsInRange(plr, 8.0f, 25.0f, false))
                                        {
                                            ResetThreatList();
                                            DoCast(plr, SPELL_INTERCEPT);
                                            AddThreat(plr, 5.0f);
                                            break;
                                        }
                                        else
                                            continue;
                                    }
                                    else
                                        --rand;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_INTERCEPT, 7000);
                        break;
                    }
                    case EVENT_BLADESTORM:
                        DoCastVictim(SPELL_BLADESTORM);
                        events.ScheduleEvent(EVENT_BLADESTORM, urand(15000, 20000));
                        break;
                    case EVENT_MORTAL_STRIKE:
                        if (!me->HasAura(SPELL_BLADESTORM))
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(8000, 12000));
                        break;
                    case EVENT_ROLLING_THROW:
                        // TODO: FIXME
                        // currently hackfixed at Spell::EffectLeapBack in SpellEffects.cpp
                        // without hackfix caster jumps forward, when caster should jump backwards and player jump forwards
                        if (!me->HasAura(SPELL_BLADESTORM))
                            DoCastVictim(SPELL_ROLLING_THROW);
                        events.ScheduleEvent(EVENT_ROLLING_THROW, 30000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_warrior_toc5AI>(creature);
    }
};

class boss_mage_toc5 : public CreatureScript
{
public:
    boss_mage_toc5() : CreatureScript("boss_mage_toc5") { }

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    struct boss_mage_toc5AI : public boss_grand_championAI
    {
        boss_mage_toc5AI(Creature* creature) : boss_grand_championAI(creature) { }

        void Reset() override
        {
            boss_grand_championAI::Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(EVENT_FIREBALL, 2000);
            events.ScheduleEvent(EVENT_POLYMORPH, 8000);
            events.ScheduleEvent(EVENT_BLASTWAVE, 12000);
            events.ScheduleEvent(EVENT_HASTE, 22000);
            boss_grand_championAI::JustEngagedWith(who);
        }

        void AttackStart(Unit* who) override
        {
            me->GetMotionMaster()->MoveChase(who, 20.0f);
            boss_grand_championAI::AttackStart(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            boss_grand_championAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_POLYMORPH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
                        {
                            DoCast(target, SPELL_POLYMORPH);
                            if (me->HasAura(SPELL_HASTE))
                                events.ScheduleEvent(EVENT_FIREBALL, 2000);
                            else
                                events.ScheduleEvent(EVENT_FIREBALL, 3000);
                        }
                        events.ScheduleEvent(EVENT_POLYMORPH, 8000);
                        break;
                    case EVENT_BLASTWAVE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0))
                        {
                            if (me->IsWithinDist(target, 5.0f, false))
                            {
                                me->InterruptNonMeleeSpells(true);
                                DoCastAOE(SPELL_BLAST_WAVE);
                                events.ScheduleEvent(EVENT_FIREBALL, 1500);
                            }
                        }
                        events.ScheduleEvent(EVENT_BLASTWAVE, 13000);
                        break;
                    case EVENT_HASTE:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_HASTE);
                        events.ScheduleEvent(EVENT_FIREBALL, 1500);
                        events.ScheduleEvent(EVENT_HASTE, 22000);
                        break;
                    case EVENT_FIREBALL:
                        DoCastVictim(SPELL_FIREBALL);
                        if (me->HasAura(SPELL_HASTE))
                            events.ScheduleEvent(EVENT_FIREBALL, 3000);
                        else
                            events.ScheduleEvent(EVENT_FIREBALL, 4000);
                        break;
                    default:
                        break;
                }
            }
            if ((100.f * me->GetPower(POWER_MANA) / me->GetMaxPower(POWER_MANA)) <= 1)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_mage_toc5AI>(creature);
    }
};

class boss_shaman_toc5 : public CreatureScript
{
public:
    boss_shaman_toc5() : CreatureScript("boss_shaman_toc5") { }

    // Colosos && Runok Wildmane || Shaman
    struct boss_shaman_toc5AI : public boss_grand_championAI
    {
        boss_shaman_toc5AI(Creature* creature) : boss_grand_championAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            earthShieldTarget.Clear();
            isDefensive = false;
        }
        ObjectGuid earthShieldTarget;
        // If shaman's friend or himself goes below 25% HP, he will go into defensive mode,
        // casting healing spells only
        bool isDefensive;

        void Reset() override
        {
            Initialize();
            boss_grand_championAI::Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(EVENT_DEF_CHECK, 5000);
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 16000);
            events.ScheduleEvent(EVENT_HEALING_WAVE, 12000);
            events.ScheduleEvent(EVENT_EARTH_SHIELD, 5000);
            events.ScheduleEvent(EVENT_HEX_MENDING, 7000);
            boss_grand_championAI::JustEngagedWith(who);
        }

        void EnterCombatMode(bool interrupt)
        {
            if (interrupt)
                me->InterruptNonMeleeSpells(true);
            isDefensive = false;
            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 1000);
        }

        void EnterDefensiveMode()
        {
            me->InterruptNonMeleeSpells(true);
            isDefensive = true;
            events.ScheduleEvent(EVENT_EARTH_SHIELD, 1000);
            events.ScheduleEvent(EVENT_HEALING_WAVE, 1500);
        }

        Unit* FindChampionWithLowestHp(float range)
        {
            // DoSelectLowestHpFriendly does not work correctly in this fight
            // We look for champion with the lowest percentage health left
            // ignoring champions with full hp or with kneel state (= defeated)
            // and champions who are more than 40 yards away from me (max range of healing spells)
            Unit* lowChampion = nullptr;
            Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1));
            Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2));
            Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3));
            if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
            {
                if (!pGrandChampion1->HasAura(SPELL_KNEEL) && pGrandChampion1->GetHealthPct() < 100 && me->IsWithinDist(pGrandChampion1, range))
                    lowChampion = pGrandChampion1;
                if (!pGrandChampion2->HasAura(SPELL_KNEEL) && pGrandChampion2->GetHealthPct() < 100 && me->IsWithinDist(pGrandChampion2, range))
                {
                    if (lowChampion)
                    {
                        if (lowChampion->GetHealthPct() > pGrandChampion2->GetHealthPct())
                            lowChampion = pGrandChampion2;
                    }
                    else
                        lowChampion = pGrandChampion2;
                }
                if (!pGrandChampion3->HasAura(SPELL_KNEEL) && pGrandChampion3->GetHealthPct() < 100 && me->IsWithinDist(pGrandChampion3, range))
                {
                    if (lowChampion)
                    {
                        if (lowChampion->GetHealthPct() > pGrandChampion3->GetHealthPct())
                            lowChampion = pGrandChampion3;
                    }
                    else
                        lowChampion = pGrandChampion3;
                }
            }
            // can return NULL if other champions are over 40 yards away and we're in full hp
            // or if one champion has been defeated and two are in full hp
            // or we are last man standing with full hp
            return lowChampion;
        }

        void UpdateAI(uint32 uiDiff) override
        {
            boss_grand_championAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEF_CHECK:
                        if (!isDefensive)
                        {
                            Unit* pFriend = FindChampionWithLowestHp(40.0f);
                            if (pFriend && pFriend->GetHealthPct() <= 25)
                                EnterDefensiveMode();
                        }
                        else
                        {
                            Unit* pFriend = FindChampionWithLowestHp(40.0f);
                            if (pFriend && pFriend->GetHealthPct() > 25)
                                EnterCombatMode(false);
                            else
                                EnterCombatMode(true);
                        }
                        events.ScheduleEvent(EVENT_DEF_CHECK, 5000);
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (!isDefensive)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 16000);
                        }
                        break;
                    case EVENT_HEALING_WAVE:
                        if (Unit* pFriend = FindChampionWithLowestHp(40.0f))
                        {
                            // double check to interrupt heal on defeated champion
                            if (pFriend->HasAura(SPELL_KNEEL))
                                EnterCombatMode(true);
                            else
                                DoCast(pFriend, SPELL_HEALING_WAVE);
                        }
                        if (isDefensive)
                            events.ScheduleEvent(EVENT_HEALING_WAVE, 4000);
                        else
                            events.ScheduleEvent(EVENT_HEALING_WAVE, 12000);
                        break;
                    case EVENT_EARTH_SHIELD:
                        if (Unit* pFriend = FindChampionWithLowestHp(40.0f))
                        {
                            // double check to interrupt shield on defeated champion
                            if (pFriend->HasAura(SPELL_KNEEL))
                                EnterCombatMode(true);
                            else
                            {
                                // Earth Shield is single target spell, we must remove it from previous target
                                if (Creature* target = ObjectAccessor::GetCreature(*me, earthShieldTarget))
                                {
                                    if (target->HasAura(SPELL_EARTH_SHIELD))
                                        target->RemoveAura(SPELL_EARTH_SHIELD);
                                }
                                DoCast(pFriend, SPELL_EARTH_SHIELD);
                                earthShieldTarget = pFriend->GetGUID();
                            }
                        }
                        events.ScheduleEvent(EVENT_EARTH_SHIELD, urand(30000, 35000));
                        break;
                    case EVENT_HEX_MENDING:
                        DoCastVictim(SPELL_HEX_OF_MENDING);
                        events.ScheduleEvent(EVENT_HEX_MENDING, urand(20000, 25000));
                        break;
                    default:
                        break;
                }
            }
            if (!isDefensive)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_shaman_toc5AI>(creature);
    }
};

class boss_hunter_toc5 : public CreatureScript
{
public:
    boss_hunter_toc5() : CreatureScript("boss_hunter_toc5") { }

    // Jaelyne Evensong && Zul'tore || Hunter
    struct boss_hunter_toc5AI : public boss_grand_championAI
    {
        boss_hunter_toc5AI(Creature* creature) : boss_grand_championAI(creature) { }

        void Reset() override
        {
            boss_grand_championAI::Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(EVENT_MULTI_SHOT, 7500);
            events.ScheduleEvent(EVENT_LIGHTNING_ARROWS, 15000);
            events.ScheduleEvent(EVENT_DISENGAGE, urand(25000, 35000));
            boss_grand_championAI::JustEngagedWith(who);
        }

        void AttackStart(Unit* who) override
        {
            me->GetMotionMaster()->MoveChase(who, 25.0f);
            boss_grand_championAI::AttackStart(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            boss_grand_championAI::UpdateAI(uiDiff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DISENGAGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0))
                        {
                            if (me->IsWithinDist(target, 5.0f, false))
                            {
                                me->InterruptNonMeleeSpells(true);
                                DoCast(me, SPELL_DISENGAGE);
                            }
                        }
                        events.ScheduleEvent(EVENT_DISENGAGE, urand(25000, 35000));
                        break;
                    case EVENT_LIGHTNING_ARROWS:
                        if (!me->HasAura(SPELL_LIGHTNING_ARROWS_AURA) && !me->IsWithinDist(me->GetVictim(), 2.0f))
                        {
                            me->InterruptNonMeleeSpells(true);
                            DoCastAOE(SPELL_LIGHTNING_ARROWS);
                        }
                        events.ScheduleEvent(EVENT_LIGHTNING_ARROWS, urand(20000, 30000));
                        break;
                    case EVENT_MULTI_SHOT:
                        if (me->IsInRange(me->GetVictim(), 5.0f, 30.0f, false) && !me->HasAura(SPELL_LIGHTNING_ARROWS))
                        {
                            me->InterruptNonMeleeSpells(true);
                            DoCastVictim(SPELL_MULTI_SHOT);
                        }
                        events.ScheduleEvent(EVENT_MULTI_SHOT, 8000);
                        break;
                    default:
                        break;
                }
            }

            if (me->IsWithinDist(me->GetVictim(), 2.0f))
                DoMeleeAttackIfReady();
            else
                DoSpellAttackIfReady(SPELL_SHOOT);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_hunter_toc5AI>(creature);
    }
};

class boss_rogue_toc5 : public CreatureScript
{
public:
    boss_rogue_toc5() : CreatureScript("boss_rouge_toc5") { }

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rogue
    struct boss_rogue_toc5AI : public boss_grand_championAI
    {
        boss_rogue_toc5AI(Creature* creature) : boss_grand_championAI(creature) { }

        void Reset() override
        {
            boss_grand_championAI::Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(EVENT_DEADLY_POISON, 500);
            events.ScheduleEvent(EVENT_EVISCERATE, 8000);
            events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 14000);
            events.ScheduleEvent(EVENT_POISON_BOTTLE, 19000);
            boss_grand_championAI::JustEngagedWith(who);
        }

        void UpdateAI(uint32 diff) override
        {
            boss_grand_championAI::UpdateAI(diff);

            if (CanUseNormalAI())
            {
                if (UpdateVictim())
                    DoMeleeAttackIfReady();
                return;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DEADLY_POISON:
                        if (!me->HasAura(SPELL_DEADLY_POISON))
                            DoCast(me, SPELL_DEADLY_POISON);
                        events.ScheduleEvent(EVENT_DEADLY_POISON, 30000);
                    case EVENT_EVISCERATE:
                        DoCastVictim(SPELL_EVISCERATE);
                        events.ScheduleEvent(EVENT_EVISCERATE, 8000);
                        break;
                    case EVENT_FAN_OF_KNIVES:
                        if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0))
                        {
                            if (me->IsWithinDist(target, 8.0f, false)) // 8 yards is minimum range
                                DoCastAOE(SPELL_FAN_OF_KNIVES);
                        }
                        events.ScheduleEvent(EVENT_FAN_OF_KNIVES, 14000);
                        break;
                    case EVENT_POISON_BOTTLE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(target, SPELL_POISON_BOTTLE);
                        events.ScheduleEvent(EVENT_POISON_BOTTLE, 19000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<boss_rogue_toc5AI>(creature);
    }
};

class spell_toc5_trample_aura : public SpellScriptLoader
{
    public:
        spell_toc5_trample_aura() : SpellScriptLoader("spell_toc5_trample_aura") { }

        class spell_toc5_trample_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_toc5_trample_aura_SpellScript);

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                // The aura should not be applied if there is already a trample aura on target
                targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Id));
            }

            void HandleStun()
            {
                if (Unit* target = GetHitUnit())
                {
                    // If target is mounted, do not apply
                    if (target->GetVehicleKit() // Grand Champions
                    || target->GetVehicleBase() // Players
                    || target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT)) // Lesser Champions
                    {
                        PreventHitEffect(EFFECT_0);
                        _removed = true;
                    }
                }
            }

            void RemoveAura()
            {
                if (_removed)
                    PreventHitAura();
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_toc5_trample_aura_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                BeforeHit += SpellHitFn(spell_toc5_trample_aura_SpellScript::HandleStun);
                AfterHit += SpellHitFn(spell_toc5_trample_aura_SpellScript::RemoveAura);
            }

            bool _removed = false;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_toc5_trample_aura_SpellScript();
        }
};

class spell_toc5_lightning_arrows : public SpellScriptLoader
{
    public:
        spell_toc5_lightning_arrows() : SpellScriptLoader("spell_toc5_lightning_arrows") { }

        class spell_toc5_lightning_arrows_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_toc5_lightning_arrows_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_LIGHTNING_ARROWS_AURA))
                    return false;
                return true;
            }

            void HandleScript(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_LIGHTNING_ARROWS_AURA, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_toc5_lightning_arrows_AuraScript::HandleScript, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_toc5_lightning_arrows_AuraScript();
        }
};

enum CriteriaIds
{
    CRITERIA_WARRIOR    = 12538,
    CRITERIA_HUNTER     = 12540,
    CRITERIA_MAGE       = 12542,
    CRITERIA_ROGUE      = 12544,
    CRITERIA_SHAMAN     = 12546,
    CRITERIA_WARRIOR_H  = 12539,
    CRITERIA_HUNTER_H   = 12541,
    CRITERIA_MAGE_H     = 12543,
    CRITERIA_ROGUE_H    = 12545,
    CRITERIA_SHAMAN_H   = 12547
};

// Statistics achievements "Victories over X champion" both normal and heroic
class achievement_victories_over_champion : public AchievementCriteriaScript
{
    public:
        achievement_victories_over_champion(char const* name, uint32 criteriaId) : AchievementCriteriaScript(name),
            _criteriaId(criteriaId)
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (target)
            {
                switch (_criteriaId)
                {
                    case CRITERIA_WARRIOR:
                    case CRITERIA_WARRIOR_H:
                        return target->GetEntry() == NPC_JACOB || target->GetEntry() == NPC_MOKRA;
                    case CRITERIA_HUNTER:
                    case CRITERIA_HUNTER_H:
                        return target->GetEntry() == NPC_JAELYNE || target->GetEntry() == NPC_ZULTORE;
                    case CRITERIA_MAGE:
                    case CRITERIA_MAGE_H:
                        return target->GetEntry() == NPC_AMBROSE || target->GetEntry() == NPC_ERESSEA;
                    case CRITERIA_ROGUE:
                    case CRITERIA_ROGUE_H:
                        return target->GetEntry() == NPC_LANA || target->GetEntry() == NPC_VISCERI;
                    case CRITERIA_SHAMAN:
                    case CRITERIA_SHAMAN_H:
                        return target->GetEntry() == NPC_COLOSOS || target->GetEntry() == NPC_RUNOK;
                    default:
                        break;
                }
            }
            return false;
        }

    private:
        uint32 const _criteriaId;
};

void AddSC_boss_grand_champions()
{
    new generic_vehicleAI_toc5();
    new boss_warrior_toc5();
    new boss_mage_toc5();
    new boss_shaman_toc5();
    new boss_hunter_toc5();
    new boss_rogue_toc5();
    new spell_toc5_trample_aura();
    new spell_toc5_lightning_arrows();
    new achievement_victories_over_champion("achievement_victories_over_war_champion", CRITERIA_WARRIOR);
    new achievement_victories_over_champion("achievement_victories_over_hun_champion", CRITERIA_HUNTER);
    new achievement_victories_over_champion("achievement_victories_over_mag_champion", CRITERIA_MAGE);
    new achievement_victories_over_champion("achievement_victories_over_rog_champion", CRITERIA_ROGUE);
    new achievement_victories_over_champion("achievement_victories_over_sha_champion", CRITERIA_SHAMAN);
    new achievement_victories_over_champion("achievement_victories_over_war_champion_h", CRITERIA_WARRIOR_H);
    new achievement_victories_over_champion("achievement_victories_over_hun_champion_h", CRITERIA_HUNTER_H);
    new achievement_victories_over_champion("achievement_victories_over_mag_champion_h", CRITERIA_MAGE_H);
    new achievement_victories_over_champion("achievement_victories_over_rog_champion_h", CRITERIA_ROGUE_H);
    new achievement_victories_over_champion("achievement_victories_over_sha_champion_h", CRITERIA_SHAMAN_H);
}