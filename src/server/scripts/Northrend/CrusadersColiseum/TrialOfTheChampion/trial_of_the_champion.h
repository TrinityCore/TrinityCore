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

#ifndef DEF_TOC_H
#define DEF_TOC_H

enum eData
{
    BOSS_GRAND_CHAMPIONS,
    BOSS_ARGENT_CHALLENGE_E,
    BOSS_ARGENT_CHALLENGE_P,
    BOSS_BLACK_KNIGHT,
    MINION_ENCOUNTER,

    DATA_TEAM,
    DATA_CHAMPION_DEFEATED,
    DATA_GRAND_CHAMPION_ENTRY,
    DATA_GRAND_CHAMPION_GUID,
    DATA_MEMORY_ENTRY,
    DATA_I_VE_HAD_WORSE,
};

enum Data64
{
    DATA_ANNOUNCER,
    DATA_TIRION,
    DATA_THRALL,
    DATA_GARROSH,
    DATA_VARIAN,
    DATA_JAINA,

    DATA_MAIN_GATE,
    DATA_PORTCULLIS,
    DATA_CHEST,

    DATA_BLACK_KNIGHT,
    DATA_BLACK_KNIGHT_GRYPHON,
};

enum AnnouncerPhases
{
    EVENT_INTRO = 0, // Presentation of champions
    EVENT_WAVES,
    EVENT_CHAMPIONS,
    EVENT_INTRO_ARGENT,
    EVENT_WAVES_ARGENT,
    EVENT_BLACK_KNIGHT_INTRO,
    EVENTS_MAX,
};

enum achievementCriterias
{
    CRITERIA_CHAMPION_JACOB     = 11420,
    CRITERIA_CHAMPION_LANA      = 12298,
    CRITERIA_CHAMPION_COLOSOS   = 12299,
    CRITERIA_CHAMPION_AMBROSE   = 12300,
    CRITERIA_CHAMPION_JAELYNE   = 12301,

    CRITERIA_CHAMPION_MOKRA     = 12302,
    CRITERIA_CHAMPION_VISCERI   = 12303,
    CRITERIA_CHAMPION_RUNOK     = 12304,
    CRITERIA_CHAMPION_ERESSEA   = 12305,
    CRITERIA_CHAMPION_ZULTORE   = 12306,

    CRITERIA_CHAMPION_JACOB_H   = 12310,
    CRITERIA_CHAMPION_LANA_H    = 12311,
    CRITERIA_CHAMPION_COLOSOS_H = 12312,
    CRITERIA_CHAMPION_AMBROSE_H = 12313,
    CRITERIA_CHAMPION_JAELYNE_H = 12314,

    CRITERIA_CHAMPION_MOKRA_H   = 12318,
    CRITERIA_CHAMPION_VISCERI_H = 12319,
    CRITERIA_CHAMPION_RUNOK_H   = 12320,
    CRITERIA_CHAMPION_ERESSEA_H = 12321,
    CRITERIA_CHAMPION_ZULTORE_H = 12322,

    CRITERIA_MEMORY_HOGGER     = 11863,
    CRITERIA_MEMORY_VANCLEEF   = 11904,
    CRITERIA_MEMORY_MUTANUS    = 11905,
    CRITERIA_MEMORY_HEROD      = 11906,
    CRITERIA_MEMORY_LUCIFROM   = 11907,
    CRITERIA_MEMORY_THUNDERAAN = 11908,
    CRITERIA_MEMORY_CHROMAGGUS = 11909,
    CRITERIA_MEMORY_HAKKAR     = 11910,
    CRITERIA_MEMORY_VEKNILASH  = 11911,
    CRITERIA_MEMORY_KALITHRESH = 11912,
    CRITERIA_MEMORY_MALCHEZAAR = 11913,
    CRITERIA_MEMORY_GRUUL      = 11914,
    CRITERIA_MEMORY_VASHJ      = 11915,
    CRITERIA_MEMORY_ARCHIMONDE = 11916,
    CRITERIA_MEMORY_ILLIDAN    = 11917,
    CRITERIA_MEMORY_DELRISSA   = 11918,
    CRITERIA_MEMORY_MURU       = 11919,
    CRITERIA_MEMORY_INGVAR     = 11920,
    CRITERIA_MEMORY_CYANIGOSA  = 11921,
    CRITERIA_MEMORY_ECK        = 11922,
    CRITERIA_MEMORY_ONYXIA     = 11923,
    CRITERIA_MEMORY_HEIGAN     = 11924,
    CRITERIA_MEMORY_IGNIS      = 11925,
    CRITERIA_MEMORY_VEZAX      = 11926,
    CRITERIA_MEMORY_ALGALON    = 11927,

    CRITERIA_I_VE_HAD_WORSE    = 11789,

    SPELL_ACHIEVEMENT_CHAMPIONS = 68572,
    SPELL_ACHIEVEMENT_PALETRESS = 68574,
    SPELL_ACHIEVEMENT_MEMORIES  = 68206,
    SPELL_ACHIEVEMENT_EADRIC    = 68575,
    SPELL_ACHIEVEMENT_BLACK_KNIGHT = 68663,
};

enum eNpcs
{
    // Horde Champions
    NPC_MOKRA                   = 35572,
    NPC_ERESSEA                 = 35569,
    NPC_RUNOK                   = 35571,
    NPC_ZULTORE                 = 35570,
    NPC_VISCERI                 = 35617,

    // Alliance Champions
    NPC_JACOB                   = 34705,
    NPC_AMBROSE                 = 34702,
    NPC_COLOSOS                 = 34701,
    NPC_JAELYNE                 = 34657,
    NPC_LANA                    = 34703,

    // Alliance Pre-Champs
    NPC_STORMWIND_CHAMPION      = 35328,
    NPC_IRONFORGE_CHAMPION      = 35329,
    NPC_GNOMEREGAN_CHAMPION     = 35331,
    NPC_DARNASSUS_CHAMPION      = 35332,
    NPC_EXODAR_CHAMPION         = 35330,

    // Horde Pre-Champs
    NPC_ORGRIMMAR_CHAMPION      = 35314,
    NPC_THUNDER_BLUFF_CHAMPION  = 35325,
    NPC_UNDERCITY_CHAMPION      = 35327,
    NPC_SENJIN_CHAMPION         = 35323,
    NPC_SILVERMOON_CHAMPION     = 35326,

    // Argent Champions
    NPC_EADRIC                  = 35119,
    NPC_PALETRESS               = 34928,

    NPC_MEMORY_HOGGER           = 34942,
    NPC_MEMORY_VANCLEEF         = 35028,
    NPC_MEMORY_MUTANUS          = 35029,
    NPC_MEMORY_HEROD            = 35030,
    NPC_MEMORY_LUCIFROM         = 35031,
    NPC_MEMORY_THUNDERAAN       = 35032,
    NPC_MEMORY_CHROMAGGUS       = 35033,
    NPC_MEMORY_HAKKAR           = 35034,
    NPC_MEMORY_VEKNILASH        = 35036,
    NPC_MEMORY_KALITHRESH       = 35037,
    NPC_MEMORY_MALCHEZAAR       = 35038,
    NPC_MEMORY_GRUUL            = 35039,
    NPC_MEMORY_VASHJ            = 35040,
    NPC_MEMORY_ARCHIMONDE       = 35041,
    NPC_MEMORY_ILLIDAN          = 35042,
    NPC_MEMORY_DELRISSA         = 35043,
    NPC_MEMORY_MURU             = 35044,
    NPC_MEMORY_INGVAR           = 35045,
    NPC_MEMORY_CYANIGOSA        = 35046,
    NPC_MEMORY_ECK              = 35047,
    NPC_MEMORY_ONYXIA           = 35048,
    NPC_MEMORY_HEIGAN           = 35049,
    NPC_MEMORY_IGNIS            = 35050,
    NPC_MEMORY_VEZAX            = 35051,
    NPC_MEMORY_ALGALON          = 35052,

    // Argen Pre-Champs
    NPC_ARGENT_LIGHWIELDER      = 35309,
    NPC_ARGENT_MONK             = 35305,
    NPC_ARGENT_PRIESTESS        = 35307,

    NPC_BLACK_KNIGHT            = 35451,

    NPC_RISEN_JAEREN            = 35545,
    NPC_RISEN_ARELAS            = 35564,
    NPC_RISEN_CHAMPION          = 35590,

    // Announcers
    NPC_JAEREN                  = 35004,
    NPC_ARELAS                  = 35005,

    NPC_TIRION                  = 34996,
    NPC_THRALL                  = 34994,
    NPC_GARROSH                 = 34995,
    NPC_VARIAN                  = 34990,
    NPC_JAINA                   = 34992,
};

enum eGameObjects
{
    GO_MAIN_GATE                = 195647,
    GO_PORTCULLIS               = 195650,

    GO_CHAMPIONS_LOOT           = 195709,
    GO_CHAMPIONS_LOOT_H         = 195710,

    GO_EADRIC_LOOT              = 195374,
    GO_EADRIC_LOOT_H            = 195375,

    GO_PALETRESS_LOOT           = 195323,
    GO_PALETRESS_LOOT_H         = 195324
};

enum eVehicles
{
    //Grand Champions Alliance Vehicles
    VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT             = 35637,
    VEHICLE_AMBROSE_BOLTSPARK_MOUNT                 = 35633,
    VEHICLE_COLOSOS_MOUNT                           = 35768,
    VEHICLE_EVENSONG_MOUNT                          = 34658,
    VEHICLE_LANA_STOUTHAMMER_MOUNT                  = 35636,
    //Faction Champions (ALLIANCE)
    VEHICLE_DARNASSIA_NIGHTSABER                    = 33319,
    VEHICLE_EXODAR_ELEKK                            = 33318,
    VEHICLE_STORMWIND_STEED                         = 33217,
    VEHICLE_GNOMEREGAN_MECHANOSTRIDER               = 33317,
    VEHICLE_IRONFORGE_RAM                           = 33316,
    //Grand Champions Horde Vehicles
    VEHICLE_MOKRA_SKILLCRUSHER_MOUNT                = 35638,
    VEHICLE_ERESSEA_DAWNSINGER_MOUNT                = 35635,
    VEHICLE_RUNOK_WILDMANE_MOUNT                    = 35640,
    VEHICLE_ZUL_TORE_MOUNT                          = 35641,
    VEHICLE_DEATHSTALKER_VESCERI_MOUNT              = 35634,
    //Faction Champions (HORDE)
    VEHICLE_FORSAKE_WARHORSE                        = 33324,
    VEHICLE_THUNDER_BLUFF_KODO                      = 33322,
    VEHICLE_ORGRIMMAR_WOLF                          = 33320,
    VEHICLE_SILVERMOON_HAWKSTRIDER                  = 33323,
    VEHICLE_DARKSPEAR_RAPTOR                        = 33321,

    VEHICLE_ARGENT_WARHORSE                         = 35644,
    VEHICLE_ARGENT_BATTLEWORG                       = 36558,

    VEHICLE_BLACK_KNIGHT                            = 35491
};

enum IntroSpells
{
    SPELL_MOUNT_LANCE_STAND   = 64723,
    SPELL_DEATH_RESPITE_INTRO = 66798,
    SPELL_DEATH_PUSH_INTRO    = 66797,
};

static void BindPlayersToInstance(Creature* creature)
{
    Map* map = creature->GetMap();

    if (map && map->IsDungeon() && map->IsRaidOrHeroicDungeon())
    {
        Map::PlayerList const &PlList = map->GetPlayers();
        if (!PlList.isEmpty() && PlList.begin()->getSource())
            ((InstanceMap*)map)->PermBindAllPlayers(PlList.begin()->getSource());
    }
};

static void AggroAllPlayers(Creature* creature)
{
    Map::PlayerList const &PlList = creature->GetMap()->GetPlayers();

    if (PlList.isEmpty())
        return;

    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if (Player* player = i->getSource())
        {
            if (player->isGameMaster())
                continue;

            if (player->isAlive())
            {
                if (Unit* mount = player->GetVehicleBase())
                {
                    creature->SetInCombatWith(mount);
                    mount->SetInCombatWith(creature);
                    creature->AddThreat(mount, 0.0f);
                }
                else
                {
                    creature->SetInCombatWith(player);
                    player->SetInCombatWith(creature);
                    creature->AddThreat(player, 0.0f);
                }
            }
        }
    }
};
#endif
