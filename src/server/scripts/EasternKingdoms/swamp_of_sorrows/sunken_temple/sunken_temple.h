/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

enum
{
    SUNKENTEMPLE_MAX_ENCOUNTER = 6,
    MAX_STATUES           = 6,
    MAX_FLAMES            = 4,

    // Don't change types 1,2 and 3 (handled in ACID)
    TYPE_ATALARION_OBSOLET= 1,
    TYPE_PROTECTORS_OBS   = 2,
    TYPE_JAMMALAN_OBS     = 3,

    TYPE_ATALARION        = 4,
    TYPE_PROTECTORS       = 5,
    TYPE_JAMMALAN         = 6,
    TYPE_MALFURION        = 7,
    TYPE_AVATAR           = 8,
    TYPE_ERANIKUS         = 9,

    NPC_ATALARION         = 8580,
    NPC_DREAMSCYTH        = 5721,
    NPC_WEAVER            = 5720,
    NPC_JAMMALAN          = 5710,
    NPC_AVATAR_OF_HAKKAR  = 8443,
    NPC_SHADE_OF_ERANIKUS = 5709,

    // Jammalain mini-bosses
    NPC_ZOLO              = 5712,
    NPC_GASHER            = 5713,
    NPC_LORO              = 5714,
    NPC_HUKKU             = 5715,
    NPC_ZULLOR            = 5716,
    NPC_MIJAN             = 5717,

    // Avatar of hakkar mobs
    NPC_SHADE_OF_HAKKAR   = 8440,                           // Shade of Hakkar appears when the event starts; will despawn when avatar of hakkar is summoned
    NPC_BLOODKEEPER       = 8438,                           // Spawned rarely and contains the hakkari blood -> used to extinguish the flames
    NPC_HAKKARI_MINION    = 8437,                           // Npc randomly spawned during the event = trash
    NPC_SUPPRESSOR        = 8497,                           // Npc summoned at one of the two doors and moves to the boss

    NPC_MALFURION         = 15362,
    AREATRIGGER_MALFURION = 4016,

    GO_ALTAR_OF_HAKKAR    = 148836,                         // Used in order to show the player the order of the statue activation
    GO_IDOL_OF_HAKKAR     = 148838,                         // Appears when atalarion is summoned; this was removed in 4.0.1

    GO_ATALAI_STATUE_1    = 148830,
    GO_ATALAI_STATUE_2    = 148831,
    GO_ATALAI_STATUE_3    = 148832,
    GO_ATALAI_STATUE_4    = 148833,
    GO_ATALAI_STATUE_5    = 148834,
    GO_ATALAI_STATUE_6    = 148835,

    GO_ATALAI_LIGHT       = 148883,                         // Green light, activates when the correct statue is chosen
    GO_ATALAI_LIGHT_BIG   = 148937,                         // Big light, used at the altar event

    GO_ATALAI_TRAP_1      = 177484,                         // Trapps triggered if the wrong statue is activated
    GO_ATALAI_TRAP_2      = 177485,                         // The traps are spawned in DB randomly around the statues (we don't know exactly which statue has which trap)
    GO_ATALAI_TRAP_3      = 148837,

    GO_ETERNAL_FLAME_1    = 148418,
    GO_ETERNAL_FLAME_2    = 148419,
    GO_ETERNAL_FLAME_3    = 148420,
    GO_ETERNAL_FLAME_4    = 148421,

    GO_EVIL_CIRCLE        = 148998,                         // Objects used at the avatar event. they are spawned when the event starts, and the mobs are summon atop of them
    GO_HAKKAR_DOOR_1      = 149432,                         // Combat doors
    GO_HAKKAR_DOOR_2      = 149433,

    GO_JAMMALAN_BARRIER   = 149431,

    // Event ids related to the statue activation
    EVENT_ID_STATUE_1     = 3094,
    EVENT_ID_STATUE_2     = 3095,
    EVENT_ID_STATUE_3     = 3097,
    EVENT_ID_STATUE_4     = 3098,
    EVENT_ID_STATUE_5     = 3099,
    EVENT_ID_STATUE_6     = 3100,

    SPELL_SUMMON_AVATAR   = 12639,                          // Cast by the shade of hakkar, updates entry to avatar
    SPELL_AVATAR_SUMMONED = 12948,

    SAY_JAMMALAN_INTRO    = -1109005,
    SAY_AVATAR_BRAZIER_1  = -1109006,
    SAY_AVATAR_BRAZIER_2  = -1109007,
    SAY_AVATAR_BRAZIER_3  = -1109008,
    SAY_AVATAR_BRAZIER_4  = -1109009,
    SAY_AVATAR_SPAWN      = -1109010,

    SAY_DREAMSCYTHE_INTRO = -1109011,
    SAY_DREAMSCYTHE_AGGRO = -1109012,
    SAY_ATALALARION_AGGRO = -1109013,
    SAY_ATALALARION_SPAWN = -1109014,
};

enum ShadeOfHakkar
{
    SHADE_SPAWN_TYPES   = 2,                             // The number of different event spawn types for the Shade of Hakkar
    SHADE_HAKKARI_TYPE  = 0,
    SHADE_KEEPER_TYPE   = 1,
    MAX_HAKKARI_MINION  = 17,                            // Maximum number of Hakkari minions that can be alive at once 8 + 3 + 3 + 3 = 17 (4 waves w/ max spawn each time)
    MAX_BLOODKEEPER     = 4,                             // Maximum number of blood keepers that can be alive at once
    NUM_BRAZIERS        = 4,
};

struct npc_shade_hakkarAI : public ScriptedAI
{
    npc_shade_hakkarAI(Creature *m_creature);

    ScriptedInstance* m_pInstance;

    uint32 m_uiBraziersUsed;
    uint32 m_uiHakkariTimer;
    uint32 m_uiSuppressorTimer;
    uint32 m_uiSuppressingTimer;
    uint32 CheckTimer;
    bool EngagedOnce;
    bool FirstPop;
    uint32 eventSpawns[SHADE_SPAWN_TYPES];

    void Reset() override;
    void Aggro(Unit *pWho) override;
    void JustSummoned(Creature *m_creature) override;
    void SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId) override;
    void UpdateAI(uint32 const uiDiff) override;

    void SummonJustDied(Creature *m_pcreature);
    void UpdateBrazierState(GameObject *go, bool used);
    void SummonTheAvatar();
};

#endif
