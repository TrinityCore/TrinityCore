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

#ifndef SC_HYJALAI_H
#define SC_HYJALAI_H

#include "hyjal.h"
#include "ScriptedEscortAI.h"

#define HYJAL_AI_MAX_SPELLS 3

enum SpellIds
{
    SPELL_TELEPORT_VISUAL     = 41232,
    SPELL_MASS_TELEPORT       = 16807,

    //Spells for Jaina
    SPELL_BRILLIANCE_AURA     = 31260,   // The database must handle this spell via creature_addon(it should, but is removed in evade..)
    SPELL_BLIZZARD            = 31266,
    SPELL_PYROBLAST           = 31263,
    SPELL_SUMMON_ELEMENTALS   = 31264,

    //Thrall spells
    SPELL_CHAIN_LIGHTNING     = 31330,
    SPELL_SUMMON_DIRE_WOLF    = 31331
};

struct Wave
{
    uint32 Mob[18];                                         // Stores Creature Entries to be summoned in Waves
    uint32 WaveTimer;                                       // The timer before the next wave is summoned
    bool IsBoss;                                            // Simply used to inform the wave summoner that the next wave contains a boss to halt all waves after that
};

const Wave AllianceWaves[]=                                // Waves that will be summoned in the Alliance Base
{   // Rage Winterchill Wave 1-8
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, 0, 0, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, ABOMINATION, ABOMINATION, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    // All 8 Waves are summoned, summon Rage Winterchill, next few waves are for Anetheron
    {{RAGE_WINTERCHILL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true},
    // Anetheron Wave 1-8
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, 0, 0, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, BANSHEE, BANSHEE, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, NECROMANCER, NECROMANCER, BANSHEE, BANSHEE, BANSHEE, BANSHEE, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 120000, false},
    {{CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, BANSHEE, BANSHEE, BANSHEE, BANSHEE, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, GHOUL, GHOUL, 0, 0, 0, 0}, 120000, false},
    {{GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, BANSHEE, BANSHEE, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    // All 8 Waves are summoned, summon Anatheron
    {{ANETHERON, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true}
};

const Wave HordeWaves[]=                                   // Waves that are summoned in the Horde base
{   // Kaz'Rogal Wave 1-8
    {{GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, BANSHEE, BANSHEE, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    {{CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    {{GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, FROST_WYRM, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, FROST_WYRM, 0, 0, 0, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, BANSHEE, BANSHEE, NECROMANCER, NECROMANCER, 0, 0}, 240000, false},
    // All 8 Waves are summoned, summon Kaz'Rogal, next few waves are for Azgalor
    {{KAZROGAL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true},
    // Azgalor Wave 1-8
    {{ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, FROST_WYRM, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, GARGOYLE, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GHOUL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, 0, 0, 0, 0}, 180000, false},
    {{GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, 0, 0, 0, 0}, 180000, false},
    {{FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, FEL_STALKER, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, 0, 0, 0, 0}, 180000, false},
    {{NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, NECROMANCER, BANSHEE, BANSHEE, BANSHEE, BANSHEE, BANSHEE, BANSHEE, 0, 0, 0, 0, 0, 0}, 180000, false},
    {{GHOUL, GHOUL, CRYPT_FIEND, CRYPT_FIEND, FEL_STALKER, FEL_STALKER, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, GIANT_INFERNAL, 0, 0, 0, 0}, 180000, false},
    {{CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, CRYPT_FIEND, FEL_STALKER, FEL_STALKER, ABOMINATION, ABOMINATION, ABOMINATION, ABOMINATION, BANSHEE, BANSHEE, BANSHEE, BANSHEE, NECROMANCER, NECROMANCER, 0, 0}, 240000, false},
    // All 8 Waves are summoned, summon Azgalor
    {{AZGALOR, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true}
};

enum TargetType                                             // Used in the spell cast system for the AI
{
    TARGETTYPE_SELF     = 0,
    TARGETTYPE_RANDOM   = 1,
    TARGETTYPE_VICTIM   = 2,
};

enum YellId
{
    ATTACKED     = 0,                                       // Used when attacked and set in combat
    BEGIN        = 1,                                       // Used when the event is begun
    INCOMING     = 2,                                       // Used to warn the raid that another wave phase is coming
    RALLY        = 3,                                       // Used to rally the raid and warn that the next wave has been summoned
    FAILURE      = 4,                                       // Used when raid has failed (unsure where to place)
    SUCCESS      = 5,                                       // Used when the raid has sucessfully defeated a wave phase
    DEATH        = 6,                                       // Used on death
};

struct hyjalAI : public npc_escortAI
{
    hyjalAI(Creature* creature);

    void Initialize();

    void Reset();                                           // Generically used to reset our variables. Do *not* call in EnterEvadeMode as this may make problems if the raid is still in combat

    void EnterEvadeMode();                                  // Send creature back to spawn location and evade.

    void EnterCombat(Unit* /*who*/);                                  // Used to reset cooldowns for our spells and to inform the raid that we're under attack

    void UpdateAI(uint32 diff);                       // Called to summon waves, check for boss deaths and to cast our spells.

    void JustDied(Unit* /*killer*/);                             // Called on death, informs the raid that they have failed.

    void SetFaction(uint32 _faction)                        // Set the faction to either Alliance or Horde in Hyjal
    {
        Faction = _faction;
    }

    void Retreat();                                         // "Teleport" (teleport visual + set invisible) all friendly creatures away from the base.

    void SpawnVeins();
    void DeSpawnVeins();
    void JustSummoned(Creature* summoned);
    void SummonedCreatureDespawn(Creature* summoned);
    void HideNearPos(float x, float y);
    void RespawnNearPos(float x, float y);
    void WaypointReached(uint32 waypointId);
    void DoOverrun(uint32 faction, const uint32 diff);
    void MoveInLineOfSight(Unit* who);

    void SummonCreature(uint32 entry, float Base[4][3]);    // Summons a creature for that wave in that base

                                                            // Summons the next wave, calls SummonCreature
    void SummonNextWave(const Wave wave[18], uint32 Count, float Base[4][3]);

    void StartEvent(Player* player);                        // Begins the event by gossip click

    uint32 GetInstanceData(uint32 Event);                   // Gets instance data for this instance, used to check if raid has gotten past a certain point and can access the next phase

    public:
        InstanceScript* instance;

        uint64 PlayerGUID;
        uint64 BossGUID[2];
        uint64 VeinGUID[14];

        uint32 NextWaveTimer;
        uint32 WaveCount;
        uint32 CheckTimer;
        uint32 Faction;
        uint32 EnemyCount;
        uint32 RetreatTimer;

        bool EventBegun;
        bool FirstBossDead;
        bool SecondBossDead;
        bool Summon;
        bool bRetreat;
        bool Debug;
        bool VeinsSpawned[2];
        uint8 InfernalCount;
        SummonList Summons;
        bool Overrun;
        bool Teleported;
        bool WaitForTeleport;
        uint32 TeleportTimer;
        uint32 OverrunCounter;
        uint32 OverrunCounter2;
        uint32 InfernalPoint;
        uint32 RespawnTimer;
        bool DoRespawn;
        bool DoHide;
        bool IsDummy;
        uint32 MassTeleportTimer;
        bool DoMassTeleport;
        uint64 DummyGuid;

        struct Spell
        {
            uint32 SpellId;
            uint32 Cooldown;
            uint32 TargetType;
        } Spells[HYJAL_AI_MAX_SPELLS];

    private:
        uint32 SpellTimer[3];
        //std::list<uint64> CreatureList;
};
#endif

