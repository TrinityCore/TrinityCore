/*
 * Copyright 2023 AzgathCore
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
#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MovementGenerator.h"
#include "terrace_of_endless_spring.h"
#include <numeric>
#include "Player.h"

enum eShaOfFearSpells
{
    // Sha of Fear
    SPELL_REACHING_ATTACK = 119775,
    SPELL_EERIE_SKULL = 119519,
    SPELL_BREATH_OF_FEAR = 119414,
    SPELL_THRASH_AURA = 131996,
    SPELL_THRASH_EXTRA_ATTACKS = 131994,
    SPELL_CONJURE_TERROR_SPAWN_TICK = 119108,
    // 4 spells for spawn, cauz' of different spawn coordinates
    SPELL_CONJURE_TERROR_SPAWN_01 = 119312,
    SPELL_CONJURE_TERROR_SPAWN_02 = 119370,
    SPELL_SEEK_THE_LIGHT = 120392,
    SPELL_CONJURE_TERROR_SPAWN_03 = 119371,
    SPELL_CONJURE_TERROR_SPAWN_04 = 119372,
    SPELL_CUSTOM_ENERGY_REGEN = 119417,

    //Heroic
    SPELL_NAKED_AND_AFRAID = 120669,
    SPELL_FADING_LIGHT = 129378,
    SPELL_IMPLACABLE_STRIKE = 120672,
    SPELL_DREAD_THRASH = 132007,
    SPELL_SUBMERGE = 120455,
    SPELL_EMERGE = 120458,
    SPELL_DREAD_THRASH_ATTACKS = 132000,
    SPELL_EMERGE_STUN = 120475,
    SPELL_HUDDLE_IN_TERROR = 120629,
    SPELL_WATERSPOUT_PERIODIC = 120520,
    SPELL_WATERSPOUT_DAMAGE = 120521,
    SPELL_WATERSPOUT_VISUAL = 120556,
    SPELL_WATERSPOUT = 120519,
    SPELL_CHAMPION_OF_THE_LIGHT = 120268,
    SPELL_TRANSFER_LIGHT = 120285,
    SPELL_DREAD_EXPANSE = 120289,
    SPELL_ETERNAL_DARKNESS = 120394,
    SPELL_TELEPORT_SHA = 120191,
    SPELL_TELEPORT_PLAYER = 120192,
    SPELL_TELEPORT_TO_DREAD_EXPANSE = 120221,
    SPELL_PHASE2_ENERGY_REGEN = 120284,

    // Other mobs
    SPELL_LIGHT_WALL = 117865,
    SPELL_CHAMPION_OF_LIGHT = 117866,
    SPELL_LIGHT_WALL_READY = 117770,
    SPELL_LIGHT_WALL_VISUAL = 107141,
    SPELL_FEARLESS = 118977,
    SPELL_WALL_OF_LIGHT_BUFF = 117999,
    SPELL_PENETRATING_BOLT = 129075,
    SPELL_PENETRATING_BOLT_MISSILE = 129077,
    SPELL_DARK_BULWARK = 119083,

    SPELL_SHA_SPINE = 120438,
    SPELL_GATHERING_SPEED = 128419,
};

enum eShaOfFearEvents
{
    EVENT_CHECK_MELEE = 1,
    EVENT_EERIE_SKULL = 2,
    EVENT_CHECK_ENERGY = 3,
    EVENT_FIRST_TERRORS = 4,
    EVENT_PENETRATING_BOLT = 5,
    EVENT_OMINOUS_CACKLE = 6,
    EVENT_EVADE = 7,
    EVENT_BERSERK = 8,
    EVENT_SET_EVADE_TRUE = 10,
    EVENT_HUDDLE_IN_TERROR = 11,
    EVENT_WATERSPOUT = 12,
    EVENT_NAKED_AND_AFRAID = 13,
    EVENT_IMPLACABLE_STRIKE = 14,
    EVENT_CAST_WATERS = 15,
    EVENT_RETURN_TO_COMBAT,
    EVENT_SHA_SPINE,
    EVENT_CHASE_VICTIM,
    EVENT_KILL_NEAR_PLAYERS,
    EVENT_GATHERING_SPEED,
    EVENT_CHECK_PLAYERS_IN_PLATFORM,
    EVENT_SPAWN_DREADS,
    EVENT_SUBMERGE,
    EVENT_MODIFY_EVENTS_SCHEDULE,
    EVENT_RESET_PLAYERS_CDS,
    EVENT_ENRAGE_TIMER,
    EVENT_LEIS_HOPE,
    EVENT_EMERGE,
    EVENT_FOLLOW_TARGETED_PLAYERS,
    EVENT_MOVE_TO_TARGET,
    EVENT_CHECK_PLAYERS,
    EVENT_MOVE_THE_LIGHT,
    EVENT_CHECK_FOR_MOVING_LIGHT,
};

enum eShaOfFearActions
{
    ACTION_ACTIVATE_WALL_OF_LIGHT,
    ACTION_DESACTIVATE_WALL_OF_LIGHT,
    ACTION_SPAWN_TERROR,
    ACTION_DO_WIPE,
};

enum eShaOfFearSays
{
    SAY_INTRO,
    SAY_AGGRO,
    SAY_BREATH_OF_FEAR,
    SAY_SLAY,
    SAY_PHASE_2,
    SAY_SUBMERGE,
    SAY_HUDDLE,
    EMOTE_PHASE_2,

};

enum Entities
{
    NPC_YANG_GUOSHI = 61038,
    NPC_JINLUN_KUN = 61046,
    NPC_CHENG_KANG = 61042,
};

enum AdditionalAIs
{
    NPC_WATERSPOUT = 48571,
    NPC_DREAD_SPAWN = 61003,
};

enum AdditionalMisc
{
    ACTION_NEW_TARGET = 12, // cel putin cred ca e 12 next ..
};

enum Misc
{
    ACTION_BOWMAN_AGGRESSIVE = 10
};

struct BowmanData
{
    uint32 entry;
    uint32 spellId;
    float x;
    float y;
    float z;
    float o;
    bool active;
};

static BowmanData bowmenData[] = // DNC
{
    { NPC_YANG_GUOSHI, 119593, -1214.795f, -2824.823f, 41.24303f, 3.506719f },
    { NPC_CHENG_KANG, 119693, -1075.198f, -2577.711f, 15.828019f, 1.725f },
    { NPC_JINLUN_KUN, 119692, -832.0764f, -2745.405f, 31.67757f, 0.1583484f }
};

Position const centerPlatform{ -1017.52f, -2772.47f, 38.57f, 0.0f };

Player* GetChampionOfLight(Creature* me)
{
    if (!me)
        return NULL;

    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
        if (Player* player = itr->GetSource())
            if (player->HasAura(SPELL_CHAMPION_OF_LIGHT))
                return player;

    return NULL;
}

static const Position spawnTerrorPos[4] =
{
    { -1052.588f, -2788.164f, 38.268f, 0.0f },
    { -983.4550f, -2787.942f, 38.269f, 0.0f },
    { -989.6860f, -2772.245f, 38.303f, 0.0f },
    { -1046.274f, -2772.215f, 38.303f, 0.0f }
};

enum eShaPhases
{
    PHASE_TERRACE = 1,
    PHASE_DREAD_EXPANSE = 2,
};

class notValidTargetPredicate
{
public:
    notValidTargetPredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        return target && target->ToPlayer() && target->ToPlayer()->GetExactDist2d(caster) > 70.f; // && (target->ToPlayer()->HasAura(SPELL_CHAMPION_OF_LIGHT)
    }
private:
    Unit* caster;
};

static const Position lightPos = { -1017.835f, -2771.984f, 38.65444f, 4.718282f };

void AddSC_boss_sha_of_fear()
{
    
}
