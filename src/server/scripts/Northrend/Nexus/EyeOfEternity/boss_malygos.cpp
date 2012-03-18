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

#include "ScriptPCH.h"
#include "eye_of_eternity.h"
#include "Vehicle.h"

enum Yells
{
    // intro
    SAY_INTRO_1                              =  -1616000,
    SAY_INTRO_2                              =  -1616001,
    SAY_INTRO_3                              =  -1616002,
    SAY_INTRO_4                              =  -1616003,
    SAY_INTRO_5                              =  -1616004,
    // phase 1
    SAY_PHASE1_AGGRO                         =  -1616005,
    SAY_MAGIC_BLAST                          =  -1616006, // ?
    SAY_SPARK_SUMMON                         =  -1616035,
    SAY_SPARK_BUFFED                         =  -1616007,
    SAY_PHASE1_SLAY_1                        =  -1616008,
    SAY_PHASE1_SLAY_2                        =  -1616009,
    SAY_PHASE1_SLAY_3                        =  -1616010,
    SAY_PHASE1_END                           =  -1616012,
    // phase 2
    SAY_PHASE2_AGGRO                         =  -1616013,
    SAY_BREATH_ATTACK                        =  -1616014,
    SAY_BREATH_ANNOUNCE                      =  -1616015,
    SAY_ANTI_MAGIC_SHELL                     =  -1616016,
    SAY_PHASE2_SLAY_1                        =  -1616020,
    SAY_PHASE2_SLAY_2                        =  -1616021,
    SAY_PHASE2_SLAY_3                        =  -1616022,
    SAY_PHASE2_END                           =  -1616017,
    // phase 3
    SAY_PHASE3_INTRO                         =  -1616018,
    SAY_PHASE3_AGGRO                         =  -1616019,
    SAY_PHASE3_SLAY_1                        =  -1616023,
    SAY_PHASE3_SLAY_2                        =  -1616024,
    SAY_PHASE3_SLAY_3                        =  -1616025,
    SAY_SURGE_OF_POWER                       =  -1616026,
    SAY_PHASE3_CAST_1                        =  -1616027,
    SAY_PHASE3_CAST_2                        =  -1616028,
    SAY_PHASE3_CAST_3                        =  -1616029,
    SAY_DEATH                                =  -1616030,
    SAY_OUTRO_1                              =  -1616031,
    SAY_OUTRO_2                              =  -1616032,
    SAY_OUTRO_3                              =  -1616033,
    SAY_OUTRO_4                              =  -1616034,
};

enum Spells
{
    // phase 1
    SPELL_IRIS_VISUAL                        = 61012,
    SPELL_ARCANE_BREATH_10                   = 56272,
    SPELL_ARCANE_BREATH_25                   = 60072,
    SPELL_ARCANE_STORM_10                    = 61693,
    SPELL_ARCANE_STORM_25                    = 61694,
    SPELL_VORTEX                             = 56105,
    SPELL_VORTEX_VISUAL                      = 55873,
    SPELL_VORTEX_PLAYER                      = 55853,
    SPELL_POWER_SPARK                        = 56152,
    SPELL_POWER_SPARK_VISUAL                 = 55845,
    SPELL_POWER_SPARK_PLAYERS                = 55852,

    // phase 2
    SPELL_ADD_RIDE_VEHICLE                   = 61421,

    SPELL_ARCANE_BOMB                        = 56430,
    SPELL_ARCANE_BOMB_KNOCKBACK              = 56431,
    SPELL_ARCANE_OVERLOAD                    = 56432,
    SPELL_DEEP_BREATH                        = 56505,

    SPELL_ARCANE_SHOCK_10                    = 57058,
    SPELL_ARCANE_SHOCK_25                    = 60073,
    SPELL_HASTE                              = 57060,
    SPELL_ARCANE_BARRAGE                     = 56397,
    SPELL_ARCANE_BARRAGE_DMG                 = 63934,

    SPELL_DESTROY_PLATFORM_CHANNEL           = 58842,
    SPELL_DESTROY_PLATFORM_BOOM              = 59084,
    SPELL_DESTROY_PLATFORM_EVENT             = 59099,

    // phase 3
    SPELL_ARCANE_PULSE                       = 57432,
    SPELL_STATIC_FIELD                       = 57428,
    SPELL_STATIC_FIELD_MISSLE                = 57430,
    SPELL_SURGE_OF_POWER_10                  = 57407,
    SPELL_SURGE_OF_POWER_25                  = 60936,
    //SPELL_SURGE_OF_POWER_25_MARKER           = 60939,

    SPELL_RIDE_RED_DRAGON_BUDDY              = 56071,
    SPELL_ALEXSTRASZAS_GIFT_VISUAL           = 61023,
    SPELL_ALEXSTRASZAS_GIFT_BEAM             = 61028,
    SPELL_ENRAGE                             = 47008,
    SPELL_ROOT                               = 18373 //hack
};

enum Phase
{
    PHASE_NONE,          // waiting for someone to use iris
    PHASE_GROUND,        // phase 1 melee / spells
    PHASE_VORTEX,        // phase 1 vortex
    PHASE_ADDS,          // phase 2
    PHASE_DRAGONS,       // phase 3
    PHASE_IDLE           // used between main phases
};

enum Events
{
    EVENT_IDLE = 1,
    EVENT_STORM,
    EVENT_SPARK,
    EVENT_ENRAGE,
    EVENT_VORTEX,
    EVENT_VORTEXFLYUP,
    EVENT_VORTEXFLYDOWN,
    EVENT_OVERLOAD,
    EVENT_STATICFIELD,
    EVENT_PULSE,
    EVENT_BREATH,
    EVENT_SURGEOFPOWER,
    EVENT_CHECKPLAYER
};

enum Action
{
    ACTION_START,
    ACTION_VORTEX,
    ACTION_SPARK,
    ACTION_OVERLOAD,
    ACTION_DEEP_BREATH,
    ACTION_SPAWN_ADDS,
    ACTION_SPAWN_MOUNTS,
    ACTION_MOUNT_ALL,
    ACTION_CAST_SURGE,
    ACTION_CHECK_PLAYER,
    ACTION_MOVESPARK,
    ACTION_STOPSPARK,
    ACTION_BUFF
};

enum MovePoints
{
    POINT_START = 1,
    POINT_VORTEX,
    POINT_FLYDOWN,
    POINT_PHASE_2,       // TODO: should move around
    POINT_DESTROYFLOOR,
    POINT_PHASE_3
};

enum Light
{
    LIGHT_DEFAULT      = 1773,
    LIGHT_RUNES        = 1824, // during phase 2
    LIGHT_SPACE_FLIGHT = 1823, // right after phase 2 ends
    LIGHT_CLOUDY       = 1822, // begin of phase 3
    LIGHT_CLOUDY_RUNES = 1825  // during phase 3
};

static Position Locations[]=
{
    {778.01f, 1276.01f, 268.2f, 2.3143f},  // p0 - first fly down position
    {754.20f, 1301.68f, 302.5f, 2.3143f},  // p1 - low room center / vortex
    {754.20f, 1301.68f, 285.5f, 2.3143f},  // p1 - vortex vehicle position
    {754.20f, 1301.68f, 320.5f, 2.3143f},  // p2 - higher room center, should fly around
    {754.20f, 1301.68f, 225.0f, 2.3143f},  // p3 - "inside" destroyed platform
    {754.35f, 1300.87f, 270.2f, 0.0f}      // alexstraszas gift
};

static Position SparkLocations[]=
{
    // power spark spawn positions
    {652.417f, 1200.52f, 295.972f, 0.78539f},
    {847.670f, 1408.05f, 295.972f, 3.97935f},
    {647.675f, 1403.80f, 295.972f, 5.53269f},
    {843.182f, 1215.42f, 295.972f, 2.35619f}
};

static Position LordLocations[]=
{
    // nexus lord fly to ground positions
    {772.396f, 1301.735f, 266.2f, 0.0f},
    {736.652f, 1301.850f, 266.2f, 0.0f},
    {754.490f, 1319.730f, 266.2f, 0.0f},
    {754.160f, 1282.878f, 266.2f, 0.0f}
};

#define FLOOR_Z            268.17f
#define WHISPER_SURGE     "Malygos fixes his eyes on you!"

class boss_malygos : public CreatureScript
{
    public:
        boss_malygos() : CreatureScript("boss_malygos") { }

        struct boss_malygosAI : public BossAI
        {
            boss_malygosAI(Creature* creature) : BossAI(creature, BOSS_MALYGOS)
            {
            }

            void Reset()
            {
                _Reset();

                step = 0;
                phase = PHASE_NONE;
                SendLightOverride(LIGHT_DEFAULT, 1000);
                addsCount = 0;

                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetSpeed(MOVE_FLIGHT, 2.0f, true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);

                sparkList.clear();
                mounts.clear();

                if (instance)
                    instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_POWER_SPARK:
                        summon->setActive(true);
                        sparkList.insert(summon->GetGUID());
                        break;
                    case NPC_STATIC_FIELD:
                        summon->SetDisplayId(11686);
                        summon->SetCanFly(true);
                        summon->SetInCombatWithZone();
                        summon->AddUnitState(UNIT_STATE_ROOT);
                        summon->SetReactState(REACT_PASSIVE);
                        summon->ForcedDespawn(30*IN_MILLISECONDS);
                        summon->CastSpell(summon, SPELL_STATIC_FIELD, true);
                        break;
                }
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case NPC_POWER_SPARK:
                        sparkList.erase(summon->GetGUID());
                        break;
                    case NPC_NEXUS_LORD:
                    case NPC_SCION_OF_ETERNITY:
                        if (Creature* disc = me->SummonCreature(NPC_HOVER_DISK_CASTER, summon->GetPositionX(), summon->GetPositionY(), FLOOR_Z, 0.0f))
                        {
                            disc->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ARCANE_BOMB_KNOCKBACK, true);
                            disc->SetSpeed(MOVE_FLIGHT, 3.0f);
                        }
                        addsCount++;
                        break;
                }
                summons.Despawn(summon);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim == me)
                    return;

                switch (phase)
                {
                    case PHASE_GROUND:
                    case PHASE_VORTEX:
                        DoScriptText(RAND(SAY_PHASE1_SLAY_1, SAY_PHASE1_SLAY_2, SAY_PHASE1_SLAY_3), me);
                        break;
                    case PHASE_ADDS:
                        DoScriptText(RAND(SAY_PHASE2_SLAY_1, SAY_PHASE2_SLAY_2, SAY_PHASE2_SLAY_3), me);
                        break;
                    case PHASE_DRAGONS:
                        DoScriptText(RAND(SAY_PHASE3_SLAY_1, SAY_PHASE3_SLAY_2, SAY_PHASE3_SLAY_3), me);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                events.Reset();
                summons.DespawnAll();
                me->SummonCreature(NPC_ALEXSTRASZA, Locations[3], TEMPSUMMON_TIMED_DESPAWN, 9*MINUTE*IN_MILLISECONDS);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (phase != PHASE_GROUND || !who->ToCreature())
                    return;

                if (who->GetEntry() == NPC_POWER_SPARK && who->GetDistance(me) < 2.0f
                    && !who->HasAura(SPELL_POWER_SPARK_PLAYERS))
                {
                    who->ToCreature()->AI()->DoAction(ACTION_BUFF);
                }
            }

            void DoAction(int32 const param)
            {
                switch (param)
                {
                    case ACTION_START:
                    {
                        _EnterCombat();
                        me->SetInCombatWithZone();
                        me->GetMotionMaster()->MoveLand(POINT_START, Locations[0], 12.0f);

                        while (Creature* dragon = me->FindNearestCreature(NPC_WYRMREST_SKYTALON, 250.0f))
                            dragon->ForcedDespawn();

                        break;
                    }
                    case ACTION_VORTEX:
                    {
                        Map* map = me->GetMap();
                        if (!map->IsDungeon())
                            return;

                        Map::PlayerList const &PlayerList = map->GetPlayers();
                        for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* player = i->getSource();
                            if (player && !player->isGameMaster() && player->isAlive())
                            {
                                if (Creature* vortex = me->SummonCreature(NPC_VORTEX, Locations[2], TEMPSUMMON_TIMED_DESPAWN, 10*IN_MILLISECONDS))
                                {
                                    vortex->SetDisplayId(11686);
                                    vortex->SetCanFly(true);
                                    player->CastSpell(vortex, SPELL_VORTEX_PLAYER, true);
                                }
                            }
                        }
                        break;
                    }
                    case ACTION_SPARK:
                    {
                        if (Creature* spark = me->SummonCreature(NPC_POWER_SPARK, SparkLocations[urand(0, 3)], TEMPSUMMON_TIMED_DESPAWN, 90*IN_MILLISECONDS))
                        {
                            DoScriptText(SAY_SPARK_SUMMON, me);
                            spark->SetCanFly(true);
                            spark->SetSpeed(MOVE_FLIGHT, 0.8f);
                            spark->SetReactState(REACT_PASSIVE);
                            spark->SetInCombatWithZone();
                        }
                        break;
                    }
                    case ACTION_OVERLOAD:
                    {
                        float x, y, angle;
                        angle = float(2 * M_PI * rand_norm());
                        x = Locations[1].GetPositionX() + float(urand(10, 28)) * cos(angle);
                        y = Locations[1].GetPositionY() + float(urand(10, 28)) * sin(angle);

                        if (Creature* overload = me->SummonCreature(NPC_ARCANE_OVERLOAD, x, y, FLOOR_Z - 1.8f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 45*IN_MILLISECONDS))
                        {
                            if (!urand(0, 2))
                                DoScriptText(SAY_ANTI_MAGIC_SHELL, me);
                            overload->AddUnitState(UNIT_STATE_ROOT);
                            overload->SetReactState(REACT_PASSIVE);
                            overload->SetInCombatWithZone();
                            overload->GetMotionMaster()->MoveIdle();
                            DoCast(overload, SPELL_ARCANE_BOMB, true);
                        }
                        break;
                    }
                    case ACTION_DEEP_BREATH:
                    {
                        if (Creature* surge = me->SummonCreature(NPC_SURGE_OF_POWER, Locations[3], TEMPSUMMON_TIMED_DESPAWN, 10*IN_MILLISECONDS))
                        {
                            DoScriptText(SAY_BREATH_ANNOUNCE, me);
                            DoScriptText(SAY_BREATH_ATTACK, me);
                            surge->SetDisplayId(11686);
                            surge->SetReactState(REACT_PASSIVE);
                            surge->SetInCombatWithZone();
                            DoCast(surge, SPELL_DEEP_BREATH);
                        }
                        break;
                    }
                    case ACTION_SPAWN_ADDS:
                    {
                        // nexus lords
                        for (uint8 i = 0; i < RAID_MODE<uint8>(2, 4); ++i)
                        {
                            if (Creature* lord = me->SummonCreature(NPC_NEXUS_LORD, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                            {
                                lord->SetReactState(REACT_PASSIVE);
                                if (Creature* temp = me->SummonCreature(NPC_HOVER_DISK_MELEE, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                                {
                                    lord->CastSpell(temp, SPELL_ADD_RIDE_VEHICLE, true);
                                    temp->SetReactState(REACT_PASSIVE);
                                    temp->GetMotionMaster()->MovePoint(0, LordLocations[i]);
                                }
                            }
                        }
                        // scions of eternity
                        for (uint8 i = 0; i < RAID_MODE<uint8>(4, 8); ++i)
                        {
                            if (Creature* scion = me->SummonCreature(NPC_SCION_OF_ETERNITY, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                            {
                                scion->SetInCombatWithZone();
                                if (Creature* temp = me->SummonCreature(NPC_HOVER_DISK_MELEE, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                                {
                                    scion->CastSpell(temp, SPELL_ADD_RIDE_VEHICLE, true);
                                    temp->SetCanFly(true);
                                    temp->SetSpeed(MOVE_FLIGHT, 0.7f);
                                    temp->SetReactState(REACT_PASSIVE);
                                    temp->GetMotionMaster()->MovePoint(0, Locations[2]);
                                    temp->AI()->SetData(0, (i + 1) * RAID_MODE<uint32>(4, 2));
                                }
                            }
                        }
                        break;
                    }
                    case ACTION_SPAWN_MOUNTS:
                    {
                        Map* map = me->GetMap();
                        if (!map->IsDungeon())
                            return;

                        Map::PlayerList const &PlayerList = map->GetPlayers();
                        for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* player = i->getSource();
                            if (player && !player->isGameMaster() && player->isAlive())
                            {
                                if (Creature* mount = player->SummonCreature(NPC_WYRMREST_SKYTALON, player->GetPositionX(), player->GetPositionY(),
                                    220.0f, player->GetOrientation()))
                                {
                                    mount->SetCanFly(true);
                                    mount->SetSpeed(MOVE_FLIGHT, 2.0f);
                                    mounts.push_back(std::pair<uint64, uint64>(mount->GetGUID(), player->GetGUID()));
                                }
                            }
                        }
                        me->SetInCombatWithZone();
                        break;
                    }
                    case ACTION_MOUNT_ALL:
                    {
                        if (mounts.empty())
                            return;

                        for (std::list<std::pair<uint64,uint64> >::iterator iter = mounts.begin(); iter != mounts.end(); ++iter)
                        {
                            Creature* mount = Unit::GetCreature(*me, (*iter).first);
                            Player* player = Unit::GetPlayer(*me, (*iter).second);

                            if (!mount || !player)
                                continue;

                            if (!player->isAlive())
                                continue;

                            //mount->SetCreatorGUID(player->GetGUID());
                            if (Pet* pet = player->GetPet())
                                player->RemovePet(pet, PET_SAVE_NOT_IN_SLOT, true);
                            player->UnsummonAllTotems();
                            player->CastSpell(mount, SPELL_RIDE_RED_DRAGON_BUDDY, true);

                            me->SetInCombatWith(mount);
                            me->AddThreat(mount, 10.0f);
                            mount->SetInCombatWith(me);
                            mount->AddThreat(me, 10.0f);
                        }

                        me->SetInCombatWithZone();
                        break;
                    }
                    case ACTION_CAST_SURGE:
                    {
                        if (!urand(0, 2))
                            DoScriptText(SAY_SURGE_OF_POWER, me);

                        if (!Is25ManRaid())
                        {
                            if (Unit* target = SelectVehicleBaseOrPlayer())
                            {
                                if (Player* player = target->GetCharmerOrOwnerPlayerOrPlayerItself())
                                    me->MonsterWhisper(WHISPER_SURGE, player->GetGUID(), true);
                                DoCast(target, SPELL_SURGE_OF_POWER_10);
                            }
                        }
                        else
                        {
                            std::list<Unit*> targetList;

                            // get all player drakes with threat
                            const std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
                            for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                                if ((*itr)->getTarget()->ToCreature() && (*itr)->getTarget()->GetEntry() == NPC_WYRMREST_SKYTALON)
                                    targetList.push_back((*itr)->getTarget());

                            if (targetList.empty())
                                return;

                            // randomize and resize
                            Trinity::RandomResizeList<Unit*>(targetList, 3);

                            targetCount = 0;
                            // store guids and notify players
                            for (std::list<Unit*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                            {
                                surgeTargets[targetCount++] = (*itr)->GetGUID();

                                if (Player* player = (*itr)->GetCharmerOrOwnerPlayerOrPlayerItself())
                                    me->MonsterWhisper(WHISPER_SURGE, player->GetGUID(), true);
                            }

                            targetCount = 0;
                            DoCast(SPELL_SURGE_OF_POWER_25);
                        }
                        break;
                    }
                    case ACTION_CHECK_PLAYER:
                    {
                        /* workaround to prevent players from falling through map in alive state (once they got unmounted) */
                        Map* map = me->GetMap();
                        if (!map->IsDungeon())
                            return;

                        Map::PlayerList const &playerList = map->GetPlayers();
                        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        {
                            Player* player = i->getSource();
                            if (player && !player->isGameMaster() && player->isAlive())
                            {
                                if (!player->GetVehicle())
                                {
                                    player->SetUnitMovementFlags(0);
                                    me->DealDamage(player, player->GetHealth(), 0, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, 0, false);
                                    player->SetUnitMovementFlags(0);
                                    player->SetMovement(MOVE_ROOT);

                                    // despawn dragon
                                    for (std::list<std::pair<uint64, uint64> >::iterator iter = mounts.begin(); iter != mounts.end(); ++iter)
                                        if (player->GetGUID() == (*iter).second)
                                            if (Creature* mount = Unit::GetCreature(*me, (*iter).first))
                                                mount->ForcedDespawn(1*IN_MILLISECONDS);
                                }
                            }
                        }
                        break;
                    }
                    case ACTION_BUFF:
                    {
                        DoCast(SPELL_POWER_SPARK);
                        DoScriptText(SAY_SPARK_BUFFED, me);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SparkMovement(bool move)
            {
                if (sparkList.empty())
                    return;

                for (std::set<uint64>::const_iterator itr = sparkList.begin(); itr != sparkList.end(); ++itr)
                    if (Creature* spark = me->GetCreature(*me, *itr))
                    {
                        // spark already "dead"
                        if (spark->HasAura(SPELL_POWER_SPARK_PLAYERS))
                            continue;

                        spark->AI()->DoAction(move ? ACTION_MOVESPARK : ACTION_STOPSPARK);

                        // remove remaining free sparks
                        if (phase == PHASE_ADDS)
                            spark->DespawnOrUnsummon(1000);
                    }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    // landed right after iris got used
                    case POINT_START:
                    {
                        DoScriptText(SAY_PHASE1_AGGRO, me);
                        if (instance)
                            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);

                        me->SetCanFly(false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        events.ScheduleEvent(EVENT_ENRAGE, 10*MINUTE*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_STORM, 5*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SPARK, 20*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_BREATH, 10*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_VORTEXFLYUP, 25*IN_MILLISECONDS);
                        phase = PHASE_GROUND;
                        break;
                    }
                    // reached vortexing position
                    case POINT_VORTEX:
                    {
                        // cast visual and give 2 seconds for heal
                        DoCast(me, SPELL_VORTEX_VISUAL, true);
                        events.ScheduleEvent(EVENT_VORTEX, 2*IN_MILLISECONDS);
                        phase = PHASE_VORTEX;
                        break;
                    }
                    // vortex finished, reached current victim's pos.
                    case POINT_FLYDOWN:
                    {
                        SparkMovement(true);
                        me->SetCanFly(false);

                        if (Unit* victim = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->GetMotionMaster()->MoveChase(victim);

                        me->SetReactState(REACT_AGGRESSIVE);
                        // give some time to heal vortex dmg
                        events.ScheduleEvent(EVENT_STORM, urand(7, 10) * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SPARK, 15*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_BREATH, RAID_MODE<uint32>(7, 3) * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_VORTEXFLYUP, 45*IN_MILLISECONDS);
                        phase = PHASE_GROUND;
                        break;
                    }
                    // start phase 2
                    case POINT_PHASE_2:
                    {
                        DoScriptText(SAY_PHASE2_AGGRO, me);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveAllAuras();
                        DoAction(ACTION_SPAWN_ADDS);
                        phase = PHASE_ADDS;
                        SparkMovement(false);
                        events.ScheduleEvent(EVENT_OVERLOAD, 5*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SURGEOFPOWER, 60*IN_MILLISECONDS);
                        break;
                    }
                    case POINT_DESTROYFLOOR:
                    {
                        DoScriptText(SAY_PHASE3_INTRO, me);
                        DoCast(SPELL_DESTROY_PLATFORM_CHANNEL);
                        events.ScheduleEvent(EVENT_IDLE, 6*IN_MILLISECONDS);
                        step = 1;
                        phase = PHASE_IDLE;
                        break;
                    }
                    // start phase 3
                    case POINT_PHASE_3:
                    {
                        DoScriptText(SAY_PHASE3_AGGRO, me);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        DoCast(me, SPELL_ROOT, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_ARCANE_BOMB)
                {
                    target->CastSpell(target, SPELL_ARCANE_BOMB_KNOCKBACK, true);
                    target->CastSpell(target, SPELL_ARCANE_OVERLOAD, true);
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            uint64 GetGUID(int32 /*id*/ = 0)
            {
                return surgeTargets[targetCount++];
            }

            Unit* SelectVehicleBaseOrPlayer()
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    if (Unit* vehicle = target->GetVehicleBase())
                        return vehicle;

                    return target;
                }

                return NULL;
            }

            void UpdateAI(uint32 const diff)
            {
                if (phase == PHASE_NONE || (phase != PHASE_NONE && !UpdateVictim()))
                    return;

                events.Update(diff);
                _DoAggroPulse(diff);
                if (me->HasUnitState(UNIT_STATE_CASTING))

                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STORM:
                            DoCast(RAID_MODE<uint32>(SPELL_ARCANE_STORM_10, SPELL_ARCANE_STORM_25));
                            if (phase == PHASE_DRAGONS)
                            {
                                if (!urand(0, 2))
                                    DoScriptText(RAND(SAY_PHASE3_CAST_1, SAY_PHASE3_CAST_2, SAY_PHASE3_CAST_3), me);
                                events.ScheduleEvent(EVENT_STORM, 10*IN_MILLISECONDS);
                            }
                            else
                                events.ScheduleEvent(EVENT_STORM, urand(10, 15) * IN_MILLISECONDS);
                            break;
                        case EVENT_SPARK:
                            DoAction(ACTION_SPARK);
                            events.ScheduleEvent(EVENT_SPARK, 20*IN_MILLISECONDS);
                            break;
                        case EVENT_BREATH:
                            DoCastVictim(RAID_MODE<uint32>(SPELL_ARCANE_BREATH_10, SPELL_ARCANE_BREATH_25));
                            events.ScheduleEvent(EVENT_BREATH, 20*IN_MILLISECONDS);
                            break;
                        case EVENT_VORTEXFLYUP:
                            SparkMovement(false);
                            me->SetCanFly(true);
                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MoveTakeoff(POINT_VORTEX, Locations[1], 10.0f);
                            events.CancelEvent(EVENT_STORM);
                            events.CancelEvent(EVENT_SPARK);
                            events.CancelEvent(EVENT_BREATH);
                            phase = PHASE_IDLE;
                            break;
                        case EVENT_VORTEX:
                            DoAction(ACTION_VORTEX);
                            events.ScheduleEvent(EVENT_VORTEXFLYDOWN, 12*IN_MILLISECONDS);
                            break;
                        case EVENT_VORTEXFLYDOWN:
                            me->GetMotionMaster()->MoveLand(POINT_FLYDOWN, Locations[5], 8.0f);
                            phase = PHASE_IDLE;
                            break;
                        case EVENT_ENRAGE:
                            if (!me->HasAura(SPELL_ENRAGE))
                            {
                                if (phase == PHASE_GROUND || phase == PHASE_ADDS || phase == PHASE_DRAGONS)
                                {
                                    DoCast(me, SPELL_ENRAGE, true);

                                    if (phase == PHASE_ADDS)
                                    {
                                        me->SetCanFly(true);
                                        me->SetSpeed(MOVE_FLIGHT, 10.0f);
                                        me->SetReactState(REACT_AGGRESSIVE);
                                        me->GetMotionMaster()->Clear();
                                        me->GetMotionMaster()->MoveChase(me->getVictim());
                                    }
                                }
                                events.ScheduleEvent(EVENT_ENRAGE, 1*IN_MILLISECONDS);
                            }
                            break;
                        case EVENT_OVERLOAD:
                            DoAction(ACTION_OVERLOAD);
                            events.ScheduleEvent(EVENT_OVERLOAD, urand(15, 20) * IN_MILLISECONDS);
                            break;
                        case EVENT_SURGEOFPOWER:
                            if (phase == PHASE_DRAGONS)
                            {
                                DoAction(ACTION_CAST_SURGE);
                                events.ScheduleEvent(EVENT_SURGEOFPOWER, 10*IN_MILLISECONDS);
                            }
                            else
                            {
                                DoAction(ACTION_DEEP_BREATH);
                                events.ScheduleEvent(EVENT_SURGEOFPOWER, 60*IN_MILLISECONDS);
                            }
                            return;
                        case EVENT_STATICFIELD:
                            if (Unit* target = SelectVehicleBaseOrPlayer())
                            {
                                if (!urand(0, 2))
                                    DoScriptText(RAND(SAY_PHASE3_CAST_1, SAY_PHASE3_CAST_2, SAY_PHASE3_CAST_3), me);
                                DoCast(target, SPELL_STATIC_FIELD_MISSLE);
                            }
                            events.ScheduleEvent(EVENT_STATICFIELD, 25*IN_MILLISECONDS);
                            return;
                        case EVENT_PULSE:
                            DoCast(SPELL_ARCANE_PULSE);
                            events.ScheduleEvent(EVENT_PULSE, 10*IN_MILLISECONDS);
                            break;
                        case EVENT_CHECKPLAYER:
                            DoAction(ACTION_CHECK_PLAYER);
                            events.ScheduleEvent(EVENT_CHECKPLAYER, 1*IN_MILLISECONDS);
                            break;
                        case EVENT_IDLE:
                            switch (step)
                            {
                                case 1:
                                {
                                    SendLightOverride(LIGHT_CLOUDY, 1000);
                                    DoCast(me, SPELL_DESTROY_PLATFORM_BOOM, true);
                                    DoCast(SPELL_DESTROY_PLATFORM_EVENT);
                                    events.ScheduleEvent(EVENT_IDLE, 2*IN_MILLISECONDS);
                                    ++step;
                                    break;
                                }
                                case 2:
                                {
                                    if (instance)
                                        if (GameObject* platform = instance->instance->GetGameObject(instance->GetData64(DATA_PLATFORM)))
                                            platform->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);

                                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                                    me->GetMotionMaster()->MovePoint(POINT_PHASE_3, Locations[4]);
                                    DoAction(ACTION_SPAWN_MOUNTS);
                                    events.ScheduleEvent(EVENT_IDLE, 3*IN_MILLISECONDS);
                                    ++step;
                                    break;
                                }
                                case 3:
                                {
                                    DoAction(ACTION_MOUNT_ALL);
                                    events.ScheduleEvent(EVENT_SURGEOFPOWER, 10*IN_MILLISECONDS);
                                    events.ScheduleEvent(EVENT_STORM, 15*IN_MILLISECONDS);
                                    events.ScheduleEvent(EVENT_CHECKPLAYER, 5*IN_MILLISECONDS);
                                    events.ScheduleEvent(EVENT_STATICFIELD, 20*IN_MILLISECONDS);
                                    events.ScheduleEvent(EVENT_PULSE, 10*IN_MILLISECONDS);
                                    SendLightOverride(LIGHT_CLOUDY_RUNES, 20000);
                                    phase = PHASE_DRAGONS;
                                    ++step;
                                    break;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }

                // switch to phase 2
                if (phase == PHASE_GROUND && HealthBelowPct(50))
                {
                    if (!me->HasAura(SPELL_ENRAGE))
                    {
                        DoScriptText(SAY_PHASE1_END, me);
                        me->SetCanFly(true);
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MoveTakeoff(POINT_PHASE_2, Locations[3], 2.5f);
                        events.CancelEvent(EVENT_STORM);
                        events.CancelEvent(EVENT_SPARK);
                        events.CancelEvent(EVENT_BREATH);
                        events.CancelEvent(EVENT_VORTEXFLYUP);
                        SendLightOverride(LIGHT_RUNES, 3000);
                        phase = PHASE_IDLE;
                    }
                }

                // switch to phase 3
                if (phase == PHASE_ADDS && addsCount == RAID_MODE<uint8>(6, 12))
                {
                    DoScriptText(SAY_PHASE2_END, me);
                    me->SetSpeed(MOVE_FLIGHT, 0.3f, true);
                    me->GetMotionMaster()->MovePoint(POINT_DESTROYFLOOR, Locations[1]);
                    summons.DespawnAll(); // remove remaining anti-magic shells and discs
                    events.CancelEvent(EVENT_SURGEOFPOWER);
                    events.CancelEvent(EVENT_OVERLOAD);
                    SendLightOverride(LIGHT_SPACE_FLIGHT, 1000);
                    phase = PHASE_IDLE;
                }

                if (phase == PHASE_GROUND || me->HasAura(SPELL_ENRAGE))
                    DoMeleeAttackIfReady();
            }

        private:
            std::set<uint64> sparkList;
            std::list<std::pair<uint64,uint64> > mounts;
            uint64 surgeTargets[3];
            uint8 targetCount;
            uint8 step;
            uint8 phase;
            uint8 addsCount;

            void SendLightOverride(uint32 overrideId, uint32 fadeInTime) const
            {
                WorldPacket data(SMSG_OVERRIDE_LIGHT, 12);
                data << uint32(1773);
                data << uint32(overrideId);
                data << uint32(fadeInTime);
                SendPacketToPlayers(&data);
            }

            void SendPacketToPlayers(WorldPacket const* data) const
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->getSource())
                            player->GetSession()->SendPacket(data);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_malygosAI(creature);
        }
};

class npc_scion_of_eternity : public CreatureScript
{
    public:
        npc_scion_of_eternity() : CreatureScript("npc_scion_of_eternity") { }

        struct npc_scion_of_eternityAI : public ScriptedAI
        {
            npc_scion_of_eternityAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _arcaneBarrageTimer = urand(10, 20) * IN_MILLISECONDS;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_arcaneBarrageTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, false, -SPELL_ARCANE_BARRAGE_DMG))
                    {
                        // try to skip spell fly time
                        me->AddAura(SPELL_ARCANE_BARRAGE_DMG, target);

                        DoCast(target, SPELL_ARCANE_BARRAGE);
                        _arcaneBarrageTimer = urand(8, 12) * IN_MILLISECONDS;
                    }
                }
                else
                    _arcaneBarrageTimer -= diff;
            }

        private:
            uint32 _arcaneBarrageTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_scion_of_eternityAI(creature);
        }
};

class npc_nexus_lord : public CreatureScript
{
    public:
        npc_nexus_lord() : CreatureScript("npc_nexus_lord") { }

        struct npc_nexus_lordAI : public ScriptedAI
        {
            npc_nexus_lordAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _hasteTimer = urand(15, 20) * IN_MILLISECONDS;
                _arcaneShockTimer = urand(5, 10) * IN_MILLISECONDS;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_arcaneShockTimer <= diff)
                {
                    DoCastVictim(RAID_MODE<uint32>(SPELL_ARCANE_SHOCK_10, SPELL_ARCANE_SHOCK_25));
                    _arcaneShockTimer = urand(5, 10) * IN_MILLISECONDS;
                }
                else
                    _arcaneShockTimer -= diff;

                if (_hasteTimer <= diff)
                {
                    DoCast(me, SPELL_HASTE);
                    _hasteTimer = urand(15, 25) * IN_MILLISECONDS;
                }
                else
                    _hasteTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _arcaneShockTimer;
            uint32 _hasteTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_nexus_lordAI(creature);
        }
};

class npc_alexstrasza : public CreatureScript
{
    public:
        npc_alexstrasza() : CreatureScript("npc_alexstrasza") { }

        struct npc_alexstraszaAI : public ScriptedAI
        {
            npc_alexstraszaAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _step = 1;
                _stepTimer = 5*IN_MILLISECONDS;
                me->SetCanFly(true);
                me->setActive(true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (_step > 5)
                    return;

                if (_stepTimer <= diff)
                {
                    switch (_step)
                    {
                        // workaround
                        case 1:
                        {
                            if (_instance)
                                if (GameObject* platform = _instance->instance->GetGameObject(_instance->GetData64(DATA_PLATFORM)))
                                    platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);

                            Map* map = me->GetMap();
                            if (!map->IsDungeon())
                                return;

                            Map::PlayerList const &PlayerList = map->GetPlayers();
                            for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player* player = i->getSource();
                                if (player && !player->isGameMaster() && player->isAlive())
                                {
                                    if (Unit* mount = player->GetVehicleBase())
                                    {
                                        player->ExitVehicle();
                                        player->JumpTo(me, 10.0f);
                                        mount->ToCreature()->ForcedDespawn(1*IN_MILLISECONDS);
                                        me->CastSpell(player, VEHICLE_SPELL_PARACHUTE, true);
                                    }
                                }
                            }
                            _stepTimer = 7*IN_MILLISECONDS;
                            break;
                        }
                        case 2:
                        {
                            DoScriptText(SAY_OUTRO_1, me);
                            _stepTimer = 9*IN_MILLISECONDS;
                            break;
                        }
                        case 3:
                        {
                            DoScriptText(SAY_OUTRO_2, me);
                            if (Creature* gift = me->SummonCreature(NPC_ALEXSTRASZAS_GIFT, Locations[5], TEMPSUMMON_TIMED_DESPAWN, 90*IN_MILLISECONDS))
                            {
                                gift->SetCanFly(true);
                                gift->SetDisplayId(11686);
                                gift->CastSpell(gift, SPELL_ALEXSTRASZAS_GIFT_VISUAL, true);
                                DoCast(SPELL_ALEXSTRASZAS_GIFT_BEAM);
                            }
                            _stepTimer = 5*IN_MILLISECONDS;
                            break;
                        }
                        case 4:
                        {
                            DoScriptText(SAY_OUTRO_3, me);
                            me->SummonGameObject(RAID_MODE<uint32>(GO_ALEXSTRASZAS_GIFT_10, GO_ALEXSTRASZAS_GIFT_25), Locations[5].GetPositionX(),
                                Locations[5].GetPositionY(), Locations[5].GetPositionZ(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0);

                            //me->SummonGameObject(RAID_MODE<uint32>(GO_HEART_OF_MAGIC_10, GO_HEART_OF_MAGIC_25), Locations[5].GetPositionX() + 15.0f,
                            //    Locations[5].GetPositionY(), Locations[5].GetPositionZ(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0);

                            // custom
                            if (Creature* temporary = me->SummonCreature(NPC_ALEXSTRASZAS_GIFT, Locations[0]))
                            {
                                temporary->setFaction(7);
                                temporary->SetDisplayId(856);
                                temporary->GetMotionMaster()->MoveRandom(7.0f);
                                temporary->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                                DoCast(temporary, 1130, true);

                                if (Is25ManRaid())
                                    temporary->SetLootMode(LOOT_MODE_HARD_MODE_1);
                            }

                            if (_instance)
                            {
                                _instance->SetBossState(BOSS_MALYGOS, DONE);
                                _instance->SaveToDB();
                            }

                            _stepTimer = 23*IN_MILLISECONDS;
                            break;
                        }
                        case 5:
                        {
                            DoScriptText(SAY_OUTRO_4, me);
                            _stepTimer = 10*MINUTE*IN_MILLISECONDS;
                            break;
                        }
                    }
                    ++_step;
                }
                else
                    _stepTimer -= diff;
            }

        private:
            InstanceScript* _instance;
            uint32 _stepTimer;
            uint8 _step;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_alexstraszaAI(creature);
        }
};

class npc_power_spark : public CreatureScript
{
    public:
        npc_power_spark() : CreatureScript("npc_power_spark") { }

        struct npc_power_sparkAI : public ScriptedAI
        {
            npc_power_sparkAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _isNear = false;
                _delayTimer = 3*IN_MILLISECONDS;
                DoCast(me, SPELL_POWER_SPARK_VISUAL, true);
                DoAction(ACTION_MOVESPARK);
            }

            void DoAction(int32 const param)
            {
                switch (param)
                {
                    case ACTION_BUFF:
                        _isNear = true;
                        break;
                    case ACTION_MOVESPARK:
                        if (Creature* malygos = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_MALYGOS) : 0))
                            me->GetMotionMaster()->MoveFollow(malygos, 0, 0);
                        break;
                    case ACTION_STOPSPARK:
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    _isNear = false;
                    me->RemoveAllAuras();
                    damage = me->GetHealth() - 1;
                    DoCast(me, SPELL_POWER_SPARK_PLAYERS, true);

                    me->SetCanFly(false);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveFall();
                    me->ForcedDespawn(60*IN_MILLISECONDS);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_isNear)
                {
                    if (_delayTimer <= diff)
                    {
                        _isNear = false;
                        me->DespawnOrUnsummon(500);

                        if (Creature* malygos = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_MALYGOS) : 0))
                            malygos->AI()->DoAction(ACTION_BUFF);
                    }
                    else
                        _delayTimer -= diff;
                }
            }

        private:
            InstanceScript* _instance;
            uint32 _delayTimer;
            bool _isNear;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_power_sparkAI(creature);
        }
};

class npc_vortex_vehicle : public CreatureScript
{
    public:
        npc_vortex_vehicle() : CreatureScript("npc_vortex_vehicle") { }

        struct npc_vortex_vehicleAI : public ScriptedAI
        {
            npc_vortex_vehicleAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _turnTimer = 100;
                me->setFaction(35);

                _angle = float(2 * M_PI * rand_norm());
                me->SetOrientation(_angle);
            }

            void UpdateAI(uint32 const diff)
            {
                // custom rotation
                if (_turnTimer <= diff)
                {
                    _angle += M_PI * 2 / 7;
                    if (_angle >= M_PI * 2)
                        _angle -= M_PI * 2;

                    me->SetOrientation(_angle);
                    me->SendMovementFlagUpdate();

                    _turnTimer = 100;
                }
                else
                    _turnTimer -= diff;
            }

        private:
            uint32 _turnTimer;
            float _angle;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_vortex_vehicleAI(creature);
        }
};

class npc_hover_disc : public CreatureScript
{
    public:
        npc_hover_disc() : CreatureScript("npc_hover_disc") { }

        struct npc_hover_discAI : public ScriptedAI
        {
            npc_hover_discAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _move = false;
                _checkTimer = 1*IN_MILLISECONDS;
                _relocateTimer = 1*IN_MILLISECONDS;
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ARCANE_BOMB_KNOCKBACK, true);
            }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
            {
                if (!apply)
                    me->ForcedDespawn(1*IN_MILLISECONDS);
            }

            void SetData(uint32 /*type*/, uint32 data)
            {
                _count = data;
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                {
                    if (!passenger->ToCreature())
                        return;

                    if (passenger->GetEntry() == NPC_NEXUS_LORD)
                    {
                        passenger->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                        passenger->ToCreature()->SetInCombatWithZone();
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                    }
                    else
                        _move = true;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_move)
                {
                    _move = false;
                    float x, y, angle;
                    angle = float(_count) * 2 * M_PI / 16;
                    x = Locations[1].GetPositionX() + float(urand(20, 28)) * cos(angle);
                    y = Locations[1].GetPositionY() + float(urand(20, 28)) * sin(angle);
                    me->GetMotionMaster()->MovePoint(1, x, y, FLOOR_Z + 10.0f);

                    _count--;
                    if (_count == 0)
                        _count = 16;
                }

                if (_relocateTimer <= diff)
                {
                    me->GetVehicleKit()->RelocatePassengers(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    _relocateTimer = 1*IN_MILLISECONDS;
                }
                else
                    _relocateTimer -= diff;

                if (!UpdateVictim())
                    return;

                // TODO: find a better way
                if (me->GetReactState() == REACT_AGGRESSIVE)
                {
                    if (_checkTimer <= diff)
                    {
                        Unit* passenger = me->GetVehicleKit()->GetPassenger(0);
                        if (passenger && passenger->ToCreature() && passenger->GetEntry() == NPC_NEXUS_LORD)
                        {
                            Unit* target = passenger->getVictim();
                            if (target && target != me->getVictim())
                            {
                                me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);
                                me->AddThreat(target, 9999999.0f);
                            }
                        }
                        _checkTimer = 1*IN_MILLISECONDS;
                    }
                    else
                        _checkTimer -= diff;
                }
            }

        private:
            bool _move;
            uint32 _count;
            uint32 _checkTimer;
            uint32 _relocateTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hover_discAI(creature);
        }
};

class go_focusing_iris : public GameObjectScript
{
    public:
        go_focusing_iris() : GameObjectScript("go_focusing_iris") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            InstanceScript* instance = go->GetInstanceScript();

            Creature* malygos = Unit::GetCreature(*go, instance ? instance->GetData64(DATA_MALYGOS) : 0);
            if (malygos && malygos->isAlive())
            {
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                malygos->AI()->DoAction(ACTION_START);

                if (Creature* trigger = go->SummonCreature(NPC_SURGE_OF_POWER, go->GetPositionX(), go->GetPositionY(), 277.0f, 0.0f,
                    TEMPSUMMON_TIMED_DESPAWN, 6*IN_MILLISECONDS))
                {
                    trigger->SetDisplayId(11686);
                    trigger->SetCanFly(true);
                    trigger->SetReactState(REACT_PASSIVE);
                    trigger->CastSpell(trigger, SPELL_IRIS_VISUAL, true);
                }
            }
            return true;
        }
};

class spell_surge_of_power_targeting : public SpellScriptLoader
{
    public:
        spell_surge_of_power_targeting() : SpellScriptLoader("spell_surge_of_power_targeting") { }

        class spell_surge_of_power_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_surge_of_power_targeting_SpellScript)

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.clear();
                Unit* caster = GetCaster();

                if (!caster->GetAI())
                    return;

                for (uint8 i = 0; i < 3; ++i)
                    if (Unit* target = ObjectAccessor::GetUnit(*caster, caster->GetAI()->GetGUID()))
                        unitList.push_back(target);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_surge_of_power_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_surge_of_power_targeting_SpellScript();
        }
};

class achievement_denyin_the_scion : public AchievementCriteriaScript
{
    public:
        achievement_denyin_the_scion() : AchievementCriteriaScript("achievement_denyin_the_scion") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Unit* disk = source->GetVehicleBase())
                if (disk->GetEntry() == NPC_HOVER_DISK_CASTER || disk->GetEntry() == NPC_HOVER_DISK_MELEE)
                    return true;
            return false;
        }
};

void AddSC_boss_malygos()
{
    new boss_malygos();
    new npc_nexus_lord();
    new npc_scion_of_eternity();
    new npc_alexstrasza();
    new npc_power_spark();
    new npc_vortex_vehicle();
    new npc_hover_disc();
    new go_focusing_iris();
    new spell_surge_of_power_targeting();
    new achievement_denyin_the_scion();
}
