#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum NPCs
{
    NPC_TRAP                        = 71003,
};

enum GOs
{
    GO_FORCEFIELD                   = 700000,
};

enum Spells
{
    SPELL_FINISHED_RACE             = 62398,   //Aura 'Race announcer' detects to verify racer finished race
    SPELL_HORDE_FLAG                = 32610,   //Placed on Horde member when they queue successfully
    SPELL_ALLIANCE_FLAG             = 32609,   //Placed on Alliance member when they queue successfully
    SPELL_HONORLESS                 = 2479,
    SPELL_SOULSTONE                 = 47883,
    SPELL_KNOCKBACK                 = 52687,
};

enum Texts
{
    SAY_RACE_BEGIN                  = 0,    //Announce race start in 15 seconds   - used by both race announcer and door checker

    // Race Announcer
    SAY_HORDE_WINS                  = 1,     //Announce Horde wins
    SAY_ALLIANCE_WINS               = 2,     //Announce Alliance wins
    SAY_HORDE_READY                 = 3,     //Announce Horde ready
    SAY_ALLIANCE_READY              = 4,     //Announce Alliance ready
    SAY_OPEN_REGISTRATION           = 5,     //Show when registration is open
    SAY_OPEN_REGISTRATION_TIMER     = 6,     //Show when registration will open in x amount of time
    SAY_RACE_FAIL_START             = 7,     //If players are missing on race start
    SAY_RACE_FAIL                   = 8,     //If players do not finish race within 15 minute timer
    SAY_RACE_HIGH_STAKES            = 9,     //If race exceeds 10 minutes

    // Door checker
    SAY_RACE_COUNTDOWN              = 1,    // 3 2 1... go!
};

enum Misc
{
    ITEM_RACING_TOKEN               = 22726,
    PLAYERS                         = 2,            // Change to players per team as required
    PLAYER_MINIMUM_LEVEL            = 80,           // Min player level required to race
    MAP_EASTERN_KINGDOMS            = 0,
    MAP_NORTHREND                   = 571,
    HIGH_STAKES_TIMER               = 5*MINUTE*IN_MILLISECONDS,    // Amount of time must be LEFT in order to begin high stakes timer
    RACE_FAIL_TIME                  = 15*MINUTE*IN_MILLISECONDS,    // Race limit timer
};

//Locations
const float HORDE_START[3]      =   { -11143.59f, -1805.91f, -28.50f };
const float ALLIANCE_START[3]   =   { -11167.20f, -1805.91f, -28.50f };
const float RACE_FINISH[3]      =   { 5804.35f, 640.28f, 610.01f };       //Dalaran Sewers

struct Locations
{
    float x,y,z;
};

// Blast Wave, Mass Slow, Flash Freeze, Piercing Howl, Earthgrab
uint32 SPELL_TRAP[] = { 36278, 30035, 16803, 38256, 31983 };

#define GOSSIP_ITEM_READY_RACE      "I am ready to race, Please add me to the list of racers."
#define GOSSIP_ITEM_REMOVE_RACE     "Please remove me from the list of racers."

static Locations TeleportRandom[]=
{
    // These locations are used for high stakes mode.

    {-14421.23f, 674.39f, 22.46f},     // On cannon outside booty bay
    {-10314.58f, -479.92f, 50.81f},    // Beside moon well in Twilight Groove
    {-11427.70f, 1947.67f, 14.77f},    // Beside Westfall lighthouse
    {-11878.01f, -3184.98f, -14.93f},  // Dark Portal
    {-11067.86f, -1828.86f, 60.30f},   // Outside Crypt
    {-10429.25f, -3828.52f, 37.99f},   // On top of Temple of Atal'Hakkar
    {-9049.32f, -1030.05f, 75.86f},    // North of Heroes' Vigil
    {-9345.34f, -3070.44f, 153.98f},   // Stonewatch hold
    {-7592.22f, -1134.49f, 262.02f},   // Black rock mountains heart
    {-6610.69f, -3702.53f, 278.57f},   // On top of cave for uldaman back entrance
    {-5174.22f, 716.45f, 369.77f},     // Inside Gnomeragon front entrance
    {-4756.56f, -3537.72f, 303.19f},   // East entrance of Stonewrought Dam
    {-831.47f, -1609.12f, 54.17f},     // Thoradins Wall
    {577.04f, -3935.80f, 115.24f},     // Beyond the bridge to Seradane
    {-761.04f, 1518.31f, 17.61f},      // Greymane Wall
    {286.66f, 380.60f, -67.47f},       // Heart of Dalarans Crater
    {2927.03f, -735.28f, 153.99f},     // Terace of Repose behind Scarlet monastery
    {3473.46f, -4489.75f, 137.49f},    // Thalassian Pass
    {1063.80f, -2518.68f, 60.22f},     // Caer Darrow
};

class npc_soulstone_altar : public CreatureScript
{
    public:
        npc_soulstone_altar() : CreatureScript("npc_soulstone_altar") { }

        struct npc_soulstone_altarAI : public ScriptedAI
        {
            npc_soulstone_altarAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void MoveInLineOfSight(Unit* who)
            {
                // Make sure that all units near have soulstone and honorless target on.
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    //if (!who->HasAura(SPELL_SOULSTONE, EFFECT_0))
                      //  who->CastSpell(who, SPELL_SOULSTONE, true, NULL, NULL, me->GetGUID());

                    if (!who->HasAura(SPELL_HONORLESS, EFFECT_0))
                        who->CastSpell(who, SPELL_HONORLESS, true, NULL, NULL, me->GetGUID());

                    if (who->HealthBelowPct(80))
                        who->SetHealth(who->GetMaxHealth());
                }
            }

            void UpdateAI(uint32 const diff) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_soulstone_altarAI(creature);
        }
};

class npc_door_checker : public CreatureScript
{
    public:
        npc_door_checker() : CreatureScript("npc_door_checker") { }

        struct npc_door_checkerAI : public ScriptedAI
        {
            npc_door_checkerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _openDoorTimer = 30*IN_MILLISECONDS;
                _begin = false;
                _raceYell = false;

                for (uint8 i = 0; i < PLAYERS; ++i)
                    _hordeGUID[i] = 0;

                for (uint8 i = 0; i < PLAYERS; ++i)
                    _allianceGUID[i] = 0;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    if (static_cast<Player*>(who)->isGameMaster())
                        return;

                    if (!_begin)
                    {
                        SpawnShields();
                        _begin = true;
                    }

                    _targetGUID = who->GetGUID();

                    if (who->ToPlayer()->GetTeam() == HORDE)
                    {
                        for (uint8 i = 0; i < PLAYERS; ++i)
                        {
                            if (_hordeGUID[i] == _targetGUID)
                                return;

                            if (!_hordeGUID[i])
                            {
                                _hordeGUID[i] = _targetGUID;
                                return;
                            }
                        }
                    }
                    else        // if (who->ToPlayer()->GetTeam() == ALLIANCE)
                    {
                        for (uint8 i = 0; i < PLAYERS; ++i)
                        {
                            if (_allianceGUID[i] == _targetGUID)
                                return;

                            if (!_allianceGUID[i])
                            {
                                _allianceGUID[i] = _targetGUID;
                                return;
                            }
                        }
                    }

                    Reset();
                }
            }

            void SpawnShields()
            {
                me->SummonGameObject(GO_FORCEFIELD, HORDE_START[0], HORDE_START[1], HORDE_START[2], 0, 0, 0, 0, 0, 30*IN_MILLISECONDS);
                me->SummonGameObject(GO_FORCEFIELD, ALLIANCE_START[0], ALLIANCE_START[1], ALLIANCE_START[2], 0, 0, 0, 0, 0, 30*IN_MILLISECONDS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!_begin)
                    return;

                if (!_raceYell && _openDoorTimer < 15*IN_MILLISECONDS)
                {
                    _raceYell = true;
                    Talk(SAY_RACE_BEGIN);
                }

                if (_openDoorTimer)
                {
                    if (_openDoorTimer < 3*IN_MILLISECONDS)
                    {
                        Talk(SAY_RACE_COUNTDOWN);
                        _openDoorTimer = 0;
                        std::list<GameObject*> forceFieldList;
                        me->GetGameObjectListWithEntryInGrid(forceFieldList, GO_FORCEFIELD, 100.0f);

                        if (!forceFieldList.empty())
                            for (std::list<GameObject*>::iterator itr = forceFieldList.begin(); itr != forceFieldList.end(); itr++)
                                (*itr)->Delete();
                    }
                    else
                        _openDoorTimer -= diff;
                }
            }

            private:
                bool _begin;
                bool _raceYell;

                uint64 _targetGUID;
                uint64 _hordeGUID[PLAYERS];
                uint64 _allianceGUID[PLAYERS];
                uint32 _openDoorTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_door_checkerAI(creature);
        }
};

class npc_crypt_bomb : public CreatureScript
{
    public:
        npc_crypt_bomb() : CreatureScript("npc_crypt_bomb") { }

        struct npc_crypt_bombAI : public ScriptedAI
        {
            npc_crypt_bombAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                _explosionTimer = 3*IN_MILLISECONDS;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_explosionTimer < diff)
                {
                    
                    me->CastSpell(trap, SPELL_KNOCKBACK, true, NULL, NULL, trap->GetGUID());
                    _explosionTimer = 3*IN_MILLISECONDS;
                }
                else
                    _explosionTimer -= diff;
            }

            private:
                uint32 _explosionTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_crypt_bombAI(creature);
        }
};

class npc_trap_trigger : public CreatureScript
{
public:
    npc_trap_trigger() : CreatureScript("npc_trap_trigger") { }

    struct npc_trap_triggerAI : public ScriptedAI
    {
        npc_trap_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset(){}

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                if (me->GetDistance(who) <= 10)
                {
                    me->CastSpell(who, SPELL_TRAP[urand(0, 4)], true, NULL, NULL, me->GetGUID());
                    // DB - Respawn time 3 minutes
                    me->DespawnOrUnsummon();
                }

        }

        void UpdateAI(uint32 const diff){}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_trap_triggerAI(creature);
    }
};

class npc_race_announcer : public CreatureScript
{
    public:
        npc_race_announcer() : CreatureScript("npc_race_announcer") { }

        struct npc_race_announcerAI : public ScriptedAI
        {
            npc_race_announcerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _targetGUID = 0;
                _raceStart = 0;
                _raceTimer = RACE_FAIL_TIME;
                _teleportTimer = 0;
                _race = false;
                _hordeReady = false;
                _allianceReady = false;
                _hordeWins = false;
                _allianceWins = false;
                _highStakes = false;

                _hordeFinished = 0;
                _allianceFinished = 0;
                _tokenRewards = sWorld->getIntConfig(CONFIG_CRYPT_RUN_REWARDS);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                for (uint8 i = 0; i < PLAYERS; ++i)
                    _hordeGUID[i] = 0;

                for (uint8 i = 0; i < PLAYERS; ++i)
                    _allianceGUID[i] = 0;
            }

            void CheckTeamRace()
            {
                for (uint8 i = 0; i < PLAYERS; ++i)
                {
                    if (!_hordeGUID[i]|| !_allianceGUID[i])
                    {
                        StopRace(true);
                        return;
                    }
            
                    if (Player* player = me->GetPlayer(*me, _hordeGUID[i]))
                    {
                        if (me->GetDistance(player) > 40)
                        {
                            StopRace(true);
                            return;
                        }
                    }
                    else
                        StopRace(true);

                    if (Player* player = me->GetPlayer(*me, _allianceGUID[i]))
                    {
                        if (me->GetDistance(player) > 40)
                        {
                            StopRace(true);
                            return;
                        }
                    }
                    else
                        StopRace(true);
                }
            }

            void TeleportToStart()
            {
                CheckTeamRace();

                for (uint8 i = 0; i < PLAYERS; ++i)
                {
                    if (Player* player = me->GetPlayer(*me, _hordeGUID[i]))
                    {
                        if (player->IsMounted())
                        {
                            player->Dismount();
                            player->RemoveAurasDueToSpell(SPELL_AURA_MOUNTED);
                        }

                        if (player->HasAura(SPELL_HORDE_FLAG, EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_HORDE_FLAG);

                        player->CastSpell(player, SPELL_FINISHED_RACE, true, NULL, NULL, player->GetGUID());
                        player->TeleportTo(MAP_EASTERN_KINGDOMS, HORDE_START[0], HORDE_START[1], HORDE_START[2], player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
                    }

                    if (Player* player = me->GetPlayer(*me, _allianceGUID[i]))
                    {
                        if (player->IsMounted())
                        {
                            player->Dismount();
                            player->RemoveAurasDueToSpell(SPELL_AURA_MOUNTED);
                        }

                        if (player->HasAura(SPELL_ALLIANCE_FLAG,EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_ALLIANCE_FLAG);

                        player->CastSpell(player, SPELL_FINISHED_RACE, true, NULL, NULL, player->GetGUID());
                        player->TeleportTo(MAP_EASTERN_KINGDOMS, ALLIANCE_START[0], ALLIANCE_START[1], ALLIANCE_START[2], player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
                    }
                }
            }

            void CheckTeamReady(uint16 faction)
            {
                uint16 hordeTempCheck = 0;
                uint16 allianceTempCheck = 0;

                for (uint8 i = 0; i < PLAYERS; ++i)
                {
                    if (_hordeGUID[i])
                        ++hordeTempCheck;

                    if (_allianceGUID[i])
                        ++allianceTempCheck;

                    if (i == PLAYERS - 1)
                    {
                        if (faction == HORDE)
                        {
                            if (hordeTempCheck == PLAYERS)
                            {
                                _hordeReady = true;
                                Talk(SAY_HORDE_READY);
                            }
                        }
                        else    // if (faction == ALLIANCE)
                        {
                            if (allianceTempCheck == PLAYERS)
                            {
                                _allianceReady = true;
                                Talk(SAY_ALLIANCE_READY);
                            }
                        }
                    }
                }
            }
            void RemoveGUID(uint64 guid, uint16 faction)
            {
                if (faction == HORDE)
                {
                    for (uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (_hordeGUID[i] == guid)
                        {
                            if (Player* player = me->GetPlayer(*me, guid))
                            {
                                if (player->HasAura(SPELL_HORDE_FLAG, EFFECT_0))
                                    player->RemoveAurasDueToSpell(SPELL_HORDE_FLAG);
                            }
                            _hordeGUID[i] = 0;
                            _hordeReady = false;

                            return;
                        }
                    }
                }
                else        // if (faction == ALLIANCE)
                {
                    for (uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (_allianceGUID[i] == guid)
                        {
                            if (Player* player = me->GetPlayer(*me, guid))
                            {
                                if (player->HasAura(SPELL_ALLIANCE_FLAG, EFFECT_0))
                                    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_FLAG);
                            }
                            _allianceGUID[i] = 0;
                            _allianceReady = false;

                            return;
                        }
                    }
                }
            }

            void StoreGUID(uint64 guid, uint16 faction)
            {
                if (faction == HORDE)
                {
                    for (uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (_hordeGUID[i] == guid)
                            return;

                        if (!_hordeGUID[i])
                        {
                            if (Player* player = me->GetPlayer(*me, guid))
                            {
                                _hordeGUID[i] = guid;
                                player->CastSpell(player, SPELL_HORDE_FLAG, true, NULL, NULL, player->GetGUID());
                            }

                            CheckTeamReady(HORDE);
                            return;
                        }
                    }
                }
                else        // if (faction == ALLIANCE)
                {
                    for (uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (_allianceGUID[i] == guid)
                            return;

                        if (!_allianceGUID[i])
                        {
                            if (Player* player = me->GetPlayer(*me, guid))
                            {
                                _allianceGUID[i] = guid;
                                player->CastSpell(player, SPELL_ALLIANCE_FLAG, true, NULL, NULL, player->GetGUID());
                            }

                            CheckTeamReady(ALLIANCE);

                            return;
                        }
                    }
                }
            }

            void MoveInLineOfSight(Unit *who)
            {
                if (who->HasAura(SPELL_FINISHED_RACE, EFFECT_0))
                {
                    who->RemoveAurasDueToSpell(SPELL_FINISHED_RACE);

                    if (who->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (who->ToPlayer()->GetTeam() == HORDE)
                        {
                            _targetGUID = who->GetGUID();

                            for (uint8 i = 0; i < PLAYERS; ++i)
                            {
                                if (_targetGUID == _hordeGUID[i])
                                {
                                    ++_hordeFinished;
                                    return;
                                }
                            }
                        }
                        else if (who->ToPlayer()->GetTeam() == ALLIANCE)
                        {
                            _targetGUID = who->GetGUID();

                            for (uint8 i = 0; i < PLAYERS; ++i)
                            {
                                if (_targetGUID == _allianceGUID[i])
                                {
                                    ++_allianceFinished;
                                    return;
                                }
                            }
                        }
                    }
                }
            }

            void StopRace(bool raceFailStart)
            {
                for (uint8 i = 0; i < PLAYERS; ++i)
                {
                    if (Player* player = me->GetPlayer(*me, _hordeGUID[i]))
                    {
                        if (player->HasAura(SPELL_FINISHED_RACE, EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_FINISHED_RACE);

                        if (player->HasAura(SPELL_HORDE_FLAG, EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_HORDE_FLAG);

                        if (player->isDead())
                            player->ResurrectPlayer(50.0f,false);

                        if (_highStakes && _allianceWins)
                        {
                            uint32 random = urand(0, 18);

                            float X = TeleportRandom[random].x;
                            float Y = TeleportRandom[random].y;
                            float Z = TeleportRandom[random].z;

                            player->TeleportTo(MAP_EASTERN_KINGDOMS, X, Y, Z, player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
                        }
                        else
                            player->TeleportTo(MAP_NORTHREND, RACE_FINISH[0], RACE_FINISH[1], RACE_FINISH[2], player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
                    }

                    if (Player* player = me->GetPlayer(*me, _allianceGUID[i]))
                    {
                        if (player->HasAura(SPELL_FINISHED_RACE, EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_FINISHED_RACE);

                        if (player->HasAura(SPELL_ALLIANCE_FLAG, EFFECT_0))
                            player->RemoveAurasDueToSpell(SPELL_ALLIANCE_FLAG);

                        if (player->isDead())
                            player->ResurrectPlayer(50.0f,false);

                        if (_highStakes && _hordeWins)
                        {
                            uint32 random = urand(0, 18);

                            float X = TeleportRandom[random].x;
                            float Y = TeleportRandom[random].y;
                            float Z = TeleportRandom[random].z;

                            player->TeleportTo(MAP_EASTERN_KINGDOMS, X, Y, Z, player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);                    
                        }
                        else
                            player->TeleportTo(MAP_NORTHREND, RACE_FINISH[0], RACE_FINISH[1], RACE_FINISH[2], player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
                    }
                }

                if (raceFailStart)
                    Talk(SAY_RACE_FAIL_START);

                Talk(SAY_OPEN_REGISTRATION);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                Reset();
            }

            void StartHighStakes()
            {
                for (uint8 i = 0; i < PLAYERS; ++i)
                {
                    if (Player* player = me->GetPlayer(*me, _hordeGUID[i]))
                        Talk(SAY_RACE_HIGH_STAKES, player->GetGUID());

                    if (Player* player = me->GetPlayer(*me, _allianceGUID[i]))
                        Talk(SAY_RACE_HIGH_STAKES, player->GetGUID());
                }
                _tokenRewards *= 2;
            }

            void Finish(uint16 faction)
            {
                if (faction == HORDE)
                {
                    _hordeWins = true;
                    Talk(SAY_HORDE_WINS);
                    for(uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (Player* player = me->GetPlayer(*me, _hordeGUID[i]))
                        {
                            for (uint8 i = 0; i < _tokenRewards; ++i)
                            {
                                ItemPosCountVec dest;
                                InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_RACING_TOKEN, 1);

                                if (msg == EQUIP_ERR_OK)
                                    player->StoreNewItem(dest, ITEM_RACING_TOKEN, true);
                            }
                        }
                    }
                }
                else        // if (faction == ALLIANCE)
                {
                    _allianceWins = true;
                    Talk(SAY_ALLIANCE_WINS);
                    for(uint8 i = 0; i < PLAYERS; ++i)
                    {
                        if (Player* player = me->GetPlayer(*me, _allianceGUID[i]))
                        {
                            for (uint8 i = 0; i < _tokenRewards; ++i)
                            {
                                ItemPosCountVec dest;
                                InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_RACING_TOKEN, 1);
                                if (msg == EQUIP_ERR_OK)
                                    player->StoreNewItem(dest, ITEM_RACING_TOKEN, true);
                            }
                        }
                    }
                }

                _race = false;
                Talk(SAY_OPEN_REGISTRATION_TIMER);
                _teleportTimer = 45*IN_MILLISECONDS;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_hordeReady && _allianceReady)
                {
                    Talk(SAY_RACE_BEGIN);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    _hordeReady = false;
                    _allianceReady = false;
                    _raceStart = 15*IN_MILLISECONDS;
                }

                if (_raceStart)
                {
                    if (_raceStart < diff)
                    {
                        TeleportToStart();
                        _race = true;
                        _raceStart = 0;
                    }
                    else
                        _raceStart -= diff;
                }

                if (_teleportTimer)
                {
                    if (_teleportTimer < diff)
                        StopRace(false);
                    else
                        _teleportTimer -= diff;
                }

                if (_race)
                {
                    if (!_highStakes && _raceTimer < HIGH_STAKES_TIMER)
                    {
                        StartHighStakes();
                        _highStakes = true;
                    }

                    if (_raceTimer < diff)
                    {
                        StopRace(false);
                        Talk(SAY_RACE_FAIL);
                    }
                    else
                        _raceTimer -= diff;

                    if (_hordeFinished == PLAYERS)
                        Finish(HORDE);

                    if (_allianceFinished == PLAYERS)
                        Finish(ALLIANCE);
                }
            }

            private:
                uint64 _targetGUID;
                uint64 _hordeGUID[PLAYERS];
                uint64 _allianceGUID[PLAYERS];
                uint32 _raceStart;
                uint32 _raceTimer;
                uint32 _teleportTimer;

                bool _race;                         // Is a race active or not
                bool _hordeReady;
                bool _allianceReady;
                bool _hordeWins;
                bool _allianceWins;
                bool _highStakes;                   // If race has entered high stakes mode

                float _hordeFinished;               // Counter to check how many horde have finished
                float _allianceFinished;            // Conuter to check how many alliance have finished
                float _tokenRewards;                // Amount of tokens rewarded to players on win (equal to PLAYERS)
        };


        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!sWorld->getBoolConfig(CONFIG_CRYPT_RUN_ENABLE))
                return false;

            if (player->IsMounted())
            {
                player->Dismount();
                player->RemoveAurasDueToSpell(SPELL_AURA_MOUNTED);
            }

            if (player->getLevel() >= PLAYER_MINIMUM_LEVEL)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, GOSSIP_ITEM_READY_RACE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, GOSSIP_ITEM_REMOVE_RACE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            if (npc_race_announcer::npc_race_announcerAI* announcer = dynamic_cast<npc_race_announcer::npc_race_announcerAI*>(creature->AI()))
            {
                if (action == GOSSIP_ACTION_INFO_DEF)
                {
                    if (player->GetTeam() == HORDE)
                        announcer->StoreGUID(player->GetGUID(), HORDE);
                    else        // if (player->GetTeam() == ALLIANCE)
                        announcer->StoreGUID(player->GetGUID(), ALLIANCE);

                    player->CLOSE_GOSSIP_MENU();
                }

                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                {
                    if (player->GetTeam() == HORDE)
                        announcer->RemoveGUID(player->GetGUID(), HORDE);
                    else        // if (player->GetTeam() == ALLIANCE)
                        announcer->RemoveGUID(player->GetGUID(), ALLIANCE);

                    player->CLOSE_GOSSIP_MENU();
                }
            }

            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_race_announcerAI(creature);
        }
};

class go_race_teleporter : public GameObjectScript
{
    public:
        go_race_teleporter() : GameObjectScript("go_race_teleporter") { }

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            if (player->HasAura(SPELL_FINISHED_RACE,EFFECT_0))
            {
                ItemPosCountVec dest;
                InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_RACING_TOKEN, 1);
                if (msg == EQUIP_ERR_OK)
                    player->StoreNewItem(dest, ITEM_RACING_TOKEN, true);
            }

            player->CastSpell(player, SPELL_FINISHED_RACE, true, NULL, NULL, player->GetGUID());
            player->TeleportTo(MAP_NORTHREND, RACE_FINISH[0], RACE_FINISH[1], RACE_FINISH[2], player->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT);
            return true;
        }
};

void AddSC_crypt_run()
{
    new npc_soulstone_altar();
    new npc_door_checker();
    new npc_crypt_bomb();
    new npc_trap_trigger();
    new npc_race_announcer();
    new go_race_teleporter();
}
