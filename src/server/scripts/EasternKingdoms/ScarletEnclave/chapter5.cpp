/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedEscortAI.h"

#define LESS_MOB // if you do not have a good server and do not want it to be laggy as hell
//Light of Dawn
enum mograine
{
#ifdef LESS_MOB
    ENCOUNTER_DK_NUMBER               = 5,  // how many player queue to start the quest , or -
    ENCOUNTER_DK_TIMER                = 10, // *every 5 minutes. These have to be done in instance data
    ENCOUNTER_DEFENDER_NUMBER         = 10, // how many of defender
    ENCOUNTER_EARTHSHATTER_NUMBER     = 1, // how many of earthshatter
    ENCOUNTER_ABOMINATION_NUMBER      = 2,  // how many of abomination
    ENCOUNTER_BEHEMOTH_NUMBER         = 1,  // how many of behemoth
    ENCOUNTER_GHOUL_NUMBER            = 5, // how many of ghoul
    ENCOUNTER_WARRIOR_NUMBER          = 1,  // how many of warrior
#else
    ENCOUNTER_DK_NUMBER               = 5,  // how many player queue to start the quest , or -
    ENCOUNTER_DK_TIMER                = 10, // *every 5 minutes. These have to be done in instance data
    ENCOUNTER_DEFENDER_NUMBER         = 20, // how many of defender
    ENCOUNTER_EARTHSHATTER_NUMBER     = 20, // how many of earthshatter
    ENCOUNTER_ABOMINATION_NUMBER      = 3,  // how many of abomination
    ENCOUNTER_BEHEMOTH_NUMBER         = 2,  // how many of behemoth
    ENCOUNTER_GHOUL_NUMBER            = 10, // how many of ghoul
    ENCOUNTER_WARRIOR_NUMBER          = 2,  // how many of warrior
#endif
    ENCOUNTER_TOTAL_DAWN              = 300,  // Total number
    ENCOUNTER_TOTAL_SCOURGE           = 10000,

    WORLD_STATE_REMAINS               = 3592,
    WORLD_STATE_COUNTDOWN             = 3603,
    WORLD_STATE_EVENT_BEGIN           = 3605,

    SAY_LIGHT_OF_DAWN01               = -1609201, // pre text
    SAY_LIGHT_OF_DAWN02               = -1609202,
    SAY_LIGHT_OF_DAWN03               = -1609203,
    SAY_LIGHT_OF_DAWN04               = -1609204, // intro
    SAY_LIGHT_OF_DAWN05               = -1609205,
    SAY_LIGHT_OF_DAWN06               = -1609206,
    SAY_LIGHT_OF_DAWN07               = -1609207, // During the fight - Korfax, Champion of the Light
    SAY_LIGHT_OF_DAWN08               = -1609208, // Lord Maxwell Tyrosus
    SAY_LIGHT_OF_DAWN09               = -1609209, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN10               = -1609210,
    SAY_LIGHT_OF_DAWN11               = -1609211,
    SAY_LIGHT_OF_DAWN12               = -1609212,
    SAY_LIGHT_OF_DAWN13               = -1609213,
    SAY_LIGHT_OF_DAWN14               = -1609214,
    SAY_LIGHT_OF_DAWN15               = -1609215,
    SAY_LIGHT_OF_DAWN16               = -1609216,
    SAY_LIGHT_OF_DAWN17               = -1609217,
    SAY_LIGHT_OF_DAWN18               = -1609218,
    SAY_LIGHT_OF_DAWN19               = -1609219,
    SAY_LIGHT_OF_DAWN20               = -1609220,
    SAY_LIGHT_OF_DAWN21               = -1609221,
    SAY_LIGHT_OF_DAWN22               = -1609222,
    SAY_LIGHT_OF_DAWN23               = -1609223,
    SAY_LIGHT_OF_DAWN24               = -1609224,
    SAY_LIGHT_OF_DAWN25               = -1609225, // After the fight
    SAY_LIGHT_OF_DAWN26               = -1609226, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN27               = -1609227, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN28               = -1609228, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN29               = -1609229, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN30               = -1609230, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN31               = -1609231, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN32               = -1609232, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN33               = -1609233, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN34               = -1609234, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN35               = -1609235, // Darion Mograine
    SAY_LIGHT_OF_DAWN36               = -1609236, // Darion Mograine
    SAY_LIGHT_OF_DAWN37               = -1609237, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN38               = -1609238, // Darion Mograine
    SAY_LIGHT_OF_DAWN39               = -1609239, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN40               = -1609240, // Darion Mograine
    SAY_LIGHT_OF_DAWN41               = -1609241, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN42               = -1609242, // Highlord Alexandros Mograine
    SAY_LIGHT_OF_DAWN43               = -1609243, // The Lich King
    SAY_LIGHT_OF_DAWN44               = -1609244, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN45               = -1609245, // The Lich King
    SAY_LIGHT_OF_DAWN46               = -1609246, // The Lich King
    SAY_LIGHT_OF_DAWN47               = -1609247, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN48               = -1609248, // The Lich King
    SAY_LIGHT_OF_DAWN49               = -1609249, // The Lich King
    SAY_LIGHT_OF_DAWN50               = -1609250, // Lord Maxwell Tyrosus
    SAY_LIGHT_OF_DAWN51               = -1609251, // The Lich King
    SAY_LIGHT_OF_DAWN52               = -1609252, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN53               = -1609253, // Highlord Darion Mograine
    SAY_LIGHT_OF_DAWN54               = -1609254, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN55               = -1609255, // The Lich King
    SAY_LIGHT_OF_DAWN56               = -1609256, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN57               = -1609257, // The Lich King
    SAY_LIGHT_OF_DAWN58               = -1609258, // The Lich King
    SAY_LIGHT_OF_DAWN59               = -1609259, // The Lich King
    SAY_LIGHT_OF_DAWN60               = -1609260, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN61               = -1609261, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN62               = -1609262, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN63               = -1609263, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN64               = -1609264, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN65               = -1609265, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN66               = -1609266, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN67               = -1609267, // Highlord Tirion Fordring
    SAY_LIGHT_OF_DAWN68               = -1609268, // Highlord Darion Mograine

    EMOTE_LIGHT_OF_DAWN01             = -1609269,  // Emotes
    EMOTE_LIGHT_OF_DAWN02             = -1609270,
    EMOTE_LIGHT_OF_DAWN03             = -1609271,
    EMOTE_LIGHT_OF_DAWN04             = -1609272,
    EMOTE_LIGHT_OF_DAWN05             = -1609273,
    EMOTE_LIGHT_OF_DAWN06             = -1609274,
    EMOTE_LIGHT_OF_DAWN07             = -1609275,
    EMOTE_LIGHT_OF_DAWN08             = -1609276,
    EMOTE_LIGHT_OF_DAWN09             = -1609277,
    EMOTE_LIGHT_OF_DAWN10             = -1609278,
    EMOTE_LIGHT_OF_DAWN11             = -1609279,
    EMOTE_LIGHT_OF_DAWN12             = -1609280,
    EMOTE_LIGHT_OF_DAWN13             = -1609281,
    EMOTE_LIGHT_OF_DAWN14             = -1609282,
    EMOTE_LIGHT_OF_DAWN15             = -1609283,
    EMOTE_LIGHT_OF_DAWN16             = -1609284,
    EMOTE_LIGHT_OF_DAWN17             = -1609285,
    EMOTE_LIGHT_OF_DAWN18             = -1609286,

    GO_LIGHT_OF_DAWN                  = 191330,
    SPELL_THE_LIGHT_OF_DAWN_Q         = 53606, // quest credit

    // ---- Dark Knight npc --------------------
    // Highlord Darion Mograine
    NPC_HIGHLORD_DARION_MOGRAINE      = 29173,
    SPELL_ANTI_MAGIC_ZONE1            = 52893,
    SPELL_DEATH_STRIKE                = 53639,
    SPELL_DEATH_EMBRACE               = 53635,
    SPELL_ICY_TOUCH1                  = 49723,
    SPELL_THE_LIGHT_OF_DAWN           = 53658,
    SPELL_THE_MIGHT_OF_MOGRAINE       = 53642, // on players when begins
    SPELL_UNHOLY_BLIGHT               = 53640,
    SPELL_ALEXANDROS_MOGRAINE_SPAWN   = 53667,
    SPELL_MOGRAINE_CHARGE             = 53679,
    SPELL_ASHBRINGER                  = 53701,

    // Koltira Deathweaver & Orbaz Bloodbane are using the same abilities
    NPC_KOLTIRA_DEATHWEAVER           = 29199,
    NPC_ORBAZ_BLOODBANE               = 29204, // this guy fleed
    NPC_THASSARIAN                    = 29200, // he also does SPELL_THE_LIGHT_OF_DAWN 53658
    SPELL_BLOOD_STRIKE1               = 52374,
    SPELL_DEATH_GRIP                  = 49576,
    SPELL_ICY_TOUCH2                  = 52372,
    SPELL_PLAGUE_STRIKE1              = 50668,
    // all do SPELL_HERO_AGGRO_AURA    53627

    // Lich King
    NPC_THE_LICH_KING                 = 29183, // show up at end
    SPELL_APOCALYPSE                  = 53210,
    SPELL_TELEPORT_VISUAL             = 52233,
    SPELL_SOUL_FEAST_ALEX             = 53677, // on Alexandros
    SPELL_SOUL_FEAST_TIRION           = 53685, // on Tirion
    SPELL_ICEBOUND_VISAGE             = 53274, // not sure what is it for
    SPELL_REBUKE                      = 53680,

    // others
    NPC_RAMPAGING_ABOMINATION         = 29186,
    SPELL_CLEAVE1                     = 53633,
    SPELL_SCOURGE_HOOK                = 50335,
    SPELL_SCOURGE_AGGRO_AURA          = 53624,

    NPC_FLESH_BEHEMOTH                = 29190, // giant guy
    SPELL_STOMP                       = 53634,
    SPELL_THUNDERCLAP                 = 36706,
    SPELL_HERO_AGGRO_AURA             = 53627,

    NPC_ACHERUS_GHOUL                 = 29219, // just ghoul....
    SPELL_GHOULPLOSION                = 53632,

    NPC_WARRIOR_OF_THE_FROZEN_WASTES  = 29206, // use SPELL_CLEAVE 53631

    NPC_HIGHLORD_ALEXANDROS_MOGRAINE  = 29227, // ghost
    NPC_DARION_MOGRAINE               = 29228, // ghost

    // ---- Dawn npc --------------------
    // Highlord Tirion Fordring
    NPC_HIGHLORD_TIRION_FORDRING      = 29175,
    EQUIP_HIGHLORD_TIRION_FORDRING    = 13262,
    SPELL_LAY_ON_HANDS                = 53778,
    SPELL_REBIRTH_OF_THE_ASHBRINGER   = 53702,
    SPELL_TIRION_CHARGE               = 53705,
    SPELL_TIRION_CHARGE_VISUAL        = 53706,

    // others
    NPC_KORFAX_CHAMPION_OF_THE_LIGHT  = 29176,
    SPELL_CLEAVE                      = 53631,
    SPELL_HEROIC_LEAP                 = 53625,

    NPC_LORD_MAXWELL_TYROSUS          = 29178,
    NPC_LEONID_BARTHALOMEW_THE_REVERED = 29179,
    NPC_DUKE_NICHOLAS_ZVERENHOFF      = 29180,

    NPC_COMMANDER_ELIGOR_DAWNBRINGER  = 29177,
    SPELL_HOLY_LIGHT2                 = 37979,

    NPC_RAYNE                         = 29181,
    SPELL_REJUVENATION                = 20664,
    SPELL_STARFALL                    = 20678,
    SPELL_TRANQUILITY                 = 25817,
    SPELL_WRATH                       = 21807,

    NPC_DEFENDER_OF_THE_LIGHT         = 29174, // also does SPELL_HEROIC_LEAP 53625
    SPELL_HOLY_LIGHT1                 = 29427,
    SPELL_HOLY_STRIKE                 = 53643,
    SPELL_HOLY_WRATH                  = 53638,
    SPELL_UPPERCUT                    = 53629,

    NPC_RIMBLAT_EARTHSHATTER          = 29182,
    SPELL_CHAIN_HEAL                  = 33642,
    SPELL_THUNDER                     = 53630
};

struct Locations
{
    float x, y, z, o;
    uint32 id;
};

void UpdateWorldState(Map *map, uint32 id, uint32 state)
{
    Map::PlayerList const& players = map->GetPlayers();

    if (!players.isEmpty())
    {
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
                pPlayer->SendUpdateWorldState(id,state);
        }
    }
}

static Locations LightofDawnLoc[]=
{
    {2281.335f, -5300.409f, 85.170f, 0},     // 0 Tirion Fordring loc
    {2283.896f, -5287.914f, 83.066f, 1.55f},  // 1 Tirion Fordring loc2
    {2281.461f, -5263.014f, 81.164f, 0},     // 2 Tirion charges
    {2262.277f, -5293.477f, 82.167f, 0},     // 3 Tirion run
    {2270.286f, -5287.73f, 82.262f, 0},      // 4 Tirion relocate
    {2269.511f, -5288.289f, 82.225f, 0},     // 5 Tirion forward
    {2262.277f, -5293.477f, 82.167f, 0},     // 6 Tirion runs to Darion
    {2270.286f, -5287.73f, 82.262f, 0},
    {2269.511f, -5288.289f, 82.225f, 0},
    {2273.205f, -5288.848f, 82.617f, 0},     // 9 Korfax loc1
    {2274.739f, -5287.926f, 82.684f, 0},     // 10 Korfax loc2
    {2253.673f, -5318.004f, 81.724f, 0},     // 11 Korfax kicked
    {2287.028f, -5309.644f, 87.253f, 0},     // 12 Maxwell loc1
    {2286.978f, -5308.025f, 86.83f, 0},      // 13 Maxwell loc2
    {2248.877f, -5307.586f, 82.166f, 0},     // 14 maxwell kicked
    {2278.58f, -5316.933f, 88.319f, 0},      // 15 Eligor loc1
    {2278.535f, -5315.479f, 88.08f, 0},      // 16 Eligor loc2
    {2259.416f, -5304.505f, 82.149f, 0},     // 17 eligor kicked
    {2289.259f, -5280.355f, 82.112f, 0},     // 18 Koltira loc1
    {2289.02f, -5281.985f, 82.207f, 0},      // 19 Koltira loc2
    {2273.289f, -5273.675f, 81.701f, 0},     // 20 Thassarian loc1
    {2273.332f, -5275.544f, 81.849f, 0},     // 21 Thassarian loc2
    {2281.198f, -5257.397f, 80.224f, 4.66f},  // 22 Alexandros loc1
    {2281.156f, -5259.934f, 80.647f, 0},     // 23 Alexandros loc2
    {2281.294f, -5281.895f, 82.445f, 1.35f},  // 24 Darion loc1
    {2281.093f, -5263.013f, 81.125f, 0},     // 25 Darion loc1
    {2281.313f, -5250.282f, 79.322f, 4.69f},  // 26 Lich King spawns
    {2281.523f, -5261.058f, 80.877f, 0},     // 27 Lich king move forwards
    {2272.709f, -5255.552f, 78.226f, 0},     // 28 Lich king kicked
    {2273.972f, -5257.676f, 78.862f, 0}      // 29 Lich king moves forward
};

class npc_highlord_darion_mograine : public CreatureScript
{
public:
    npc_highlord_darion_mograine() : CreatureScript("npc_highlord_darion_mograine") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CLOSE_GOSSIP_MENU();
                CAST_AI(npc_highlord_darion_mograine::npc_highlord_darion_mograineAI, pCreature->AI())->uiStep = 1;
                CAST_AI(npc_highlord_darion_mograine::npc_highlord_darion_mograineAI, pCreature->AI())->Start(true, false, pPlayer->GetGUID());
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(12801) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(0, "I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_highlord_darion_mograineAI(pCreature);
    }

    struct npc_highlord_darion_mograineAI : public npc_escortAI
    {
        npc_highlord_darion_mograineAI(Creature *pCreature) : npc_escortAI(pCreature)
        {
            Reset();
        }

        bool bIsBattle;
        uint32 uiStep;
        uint32 uiPhase_timer;
        uint32 uiFight_duration;
        uint32 uiTotal_dawn;
        uint32 uiTotal_scourge;
        uint32 uiSummon_counter;

        // Darion Mograine
        uint32 uiAnti_magic_zone;
        uint32 uiDeath_strike;
        uint32 uiDeath_embrace;
        uint32 uiIcy_touch;
        uint32 uiUnholy_blight;
        uint32 uiFight_speech;
        uint32 uiSpawncheck;
        uint32 uiTargetcheck;

        // Dawn
        uint64 uiTirionGUID;
        uint64 uiAlexandrosGUID;
        uint64 uiDarionGUID;
        uint64 uiKorfaxGUID;
        uint64 uiMaxwellGUID;
        uint64 uiEligorGUID;
        uint64 uiRayneGUID;
        uint64 uiDefenderGUID[ENCOUNTER_DEFENDER_NUMBER];
        uint64 uiEarthshatterGUID[ENCOUNTER_EARTHSHATTER_NUMBER];

        // Death
        uint64 uiKoltiraGUID;
        uint64 uiOrbazGUID;
        uint64 uiThassarianGUID;
        uint64 uiLichKingGUID;
        uint64 uiAbominationGUID[ENCOUNTER_ABOMINATION_NUMBER];
        uint64 uiBehemothGUID[ENCOUNTER_BEHEMOTH_NUMBER];
        uint64 uiGhoulGUID[ENCOUNTER_GHOUL_NUMBER];
        uint64 uiWarriorGUID[ENCOUNTER_WARRIOR_NUMBER];

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                bIsBattle = false;
                uiStep = 0;
                uiPhase_timer = 3000;
                uiFight_duration = 300000; // 5 minutes
                uiTotal_dawn = ENCOUNTER_TOTAL_DAWN;
                uiTotal_scourge = ENCOUNTER_TOTAL_SCOURGE;
                uiSummon_counter = 0;

                uiAnti_magic_zone = urand(1000,6000);
                uiDeath_strike = urand(5000,10000);
                uiDeath_embrace = urand(5000,10000);
                uiIcy_touch = urand(5000,10000);
                uiUnholy_blight = urand(5000,10000);

                uiFight_speech = 15000;
                uiSpawncheck = 1000;
                uiTargetcheck = 10000;

                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->Mount(25279);
                me->SetVisibility(VISIBILITY_ON);

                UpdateWorldState(me->GetMap(), WORLD_STATE_REMAINS, 0);
                //UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 0);
                UpdateWorldState(me->GetMap(), WORLD_STATE_EVENT_BEGIN, 0);

                if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiRayneGUID))
                    pTemp->setDeathState(JUST_DIED);

                uiTirionGUID = NULL;
                uiKorfaxGUID = NULL;
                uiMaxwellGUID = NULL;
                uiEligorGUID = NULL;
                uiRayneGUID = NULL;

                for (uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiDefenderGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiDefenderGUID[i] = 0;
                }
                for (uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiEarthshatterGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiEarthshatterGUID[i] = 0;
                }

                if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiOrbazGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                    pTemp->setDeathState(JUST_DIED);
                if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                    pTemp->setDeathState(JUST_DIED);

                uiKoltiraGUID = NULL;
                uiOrbazGUID = NULL;
                uiThassarianGUID = NULL;
                uiLichKingGUID = NULL;
                for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiAbominationGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiAbominationGUID[i] = 0;
                }
                for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiBehemothGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiBehemothGUID[i] = 0;
                }
                for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiGhoulGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiGhoulGUID[i] = 0;
                }
                for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                {
                    if (Creature* pTemp = Unit::GetCreature(*me, uiWarriorGUID[i]))
                        pTemp->setDeathState(JUST_DIED);
                    uiWarriorGUID[i] = 0;
                }
            }
        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if (who == me)
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (who->isTargetableForAttack() && me->IsHostileTo(who))
                if (me->IsWithinDistInMap(who, 20) && me->IsWithinLOSInMap(who))
                    AttackStart(who);
        }

        void SetHoldState(bool bOnHold)
        {
            SetEscortPaused(bOnHold);
        }

        void WaypointReached(uint32 i)
        {
            switch (i)
            {
                case 0:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    SetHoldState(true);
                    break;
                case 1:
                    SetHoldState(true);

                    SpawnNPC();
                    if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                        DoScriptText(SAY_LIGHT_OF_DAWN07, pTemp);
                    if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                        DoScriptText(SAY_LIGHT_OF_DAWN08, pTemp);

                    for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                        NPCChangeTarget(uiGhoulGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                        NPCChangeTarget(uiWarriorGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                        NPCChangeTarget(uiAbominationGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                        NPCChangeTarget(uiBehemothGUID[i]);
                    NPCChangeTarget(uiKoltiraGUID);
                    NPCChangeTarget(uiOrbazGUID);
                    NPCChangeTarget(uiThassarianGUID);

                    me->Unmount();
                    me->CastSpell(me, SPELL_THE_MIGHT_OF_MOGRAINE, true); // need to fix, on player only

                    if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                        pTemp->Unmount();
                    if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                        pTemp->Unmount();

                    bIsBattle = true;
                    break;
                case 2:
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    DoCast(me, SPELL_THE_LIGHT_OF_DAWN);
                    break;
                case 3:
                {
                    //Unit* pTirion = Unit::GetCreature(*me, uiTirionGUID);

                    DoScriptText(EMOTE_LIGHT_OF_DAWN05, me);
                    if (me->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                        me->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                    if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                    {
                        if (pTemp->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                            pTemp->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                        pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[19].x, LightofDawnLoc[19].y, LightofDawnLoc[19].z);
                    }
                    if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                    {
                        if (pTemp->HasAura(SPELL_THE_LIGHT_OF_DAWN, 0))
                            pTemp->RemoveAurasDueToSpell(SPELL_THE_LIGHT_OF_DAWN);
                        pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[21].x, LightofDawnLoc[21].y, LightofDawnLoc[21].z);
                    }
                    if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                    {
                        pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[10].x, LightofDawnLoc[10].y, LightofDawnLoc[10].z);
                    }
                    if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                    {
                        pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[13].x, LightofDawnLoc[13].y, LightofDawnLoc[13].z);
                    }
                    if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                    {
                        pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[16].x, LightofDawnLoc[16].y, LightofDawnLoc[16].z);
                    }
                    JumpToNextStep(10000);
                } break;
                case 4:
                    DoScriptText(SAY_LIGHT_OF_DAWN27, me);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);

                    if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                        pTemp->SetStandState(UNIT_STAND_STATE_KNEEL);
                    if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                        pTemp->SetStandState(UNIT_STAND_STATE_KNEEL);
                    SetHoldState(true);
                    break;
                case 5:
                    DoScriptText(SAY_LIGHT_OF_DAWN33, me);
                    SetHoldState(true);
                    break;
                case 6:
                    SetHoldState(true);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SPECIALATTACK1H);
                    JumpToNextStep(1000);
                    break;
                case 7:
                    SetHoldState(true);
                    JumpToNextStep(2000);
                    break;
                case 8:
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_UNEQUIP));
                    if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                        me->CastSpell(pTemp, SPELL_ASHBRINGER, true);
                    DoScriptText(EMOTE_LIGHT_OF_DAWN14, me);
                    SetHoldState(true);
                    break;
            }
        }

        void EnterEvadeMode()
        {
            if (!bIsBattle)//do not reset self if we are in battle
                npc_escortAI::EnterEvadeMode();
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!bIsBattle)
            {
                if (uiPhase_timer <= diff)
                {
                    // ******* Before battle *****************************************************************
                    switch (uiStep)
                    {
                        case 0:  // countdown
                            //UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 1);
                            break;

                        case 1:  // just delay
                            //UpdateWorldState(me->GetMap(), WORLD_STATE_REMAINS, 1);
                            UpdateWorldState(me->GetMap(), WORLD_STATE_COUNTDOWN, 0);
                            UpdateWorldState(me->GetMap(), WORLD_STATE_EVENT_BEGIN, 1);
                            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            JumpToNextStep(3000);
                            break;

                        case 2:
                            DoScriptText(SAY_LIGHT_OF_DAWN04, me);
                            if (Creature* pKoltira = GetClosestCreatureWithEntry(me, NPC_KOLTIRA_DEATHWEAVER, 50.0f))
                                uiKoltiraGUID = pKoltira->GetGUID();
                            if (Creature* pOrbaz = GetClosestCreatureWithEntry(me, NPC_ORBAZ_BLOODBANE, 50.0f))
                                uiOrbazGUID = pOrbaz->GetGUID();
                            if (Creature* pThassarian = GetClosestCreatureWithEntry(me, NPC_THASSARIAN, 50.0f))
                                uiThassarianGUID = pThassarian->GetGUID();
                            JumpToNextStep(10000);
                            break;

                        case 3: // rise
                            DoScriptText(SAY_LIGHT_OF_DAWN05, me);
                            JumpToNextStep(3000);
                            break;

                        case 4: // summon ghoul
                            // Dunno whats the summon spell, so workaround
                            DoCast(me, 33271); // shack effect
                            uiPhase_timer = 500;
                            if (uiSummon_counter < ENCOUNTER_GHOUL_NUMBER)
                            {
                                Unit* pTemp = me->SummonCreature(NPC_ACHERUS_GHOUL, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->setFaction(2084);
                                uiGhoulGUID[uiSummon_counter] = pTemp->GetGUID();
                                ++uiSummon_counter;
                            }
                            else
                            {
                                uiSummon_counter = 0;
                                ++uiStep;
                            }
                            break;

                        case 5: // summon abomination
                            DoCast(me, 33271); // shack effect
                            uiPhase_timer = 500;
                            if (uiSummon_counter < ENCOUNTER_ABOMINATION_NUMBER)
                            {
                                Unit* pTemp = me->SummonCreature(NPC_RAMPAGING_ABOMINATION, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->setFaction(2084);
                                uiAbominationGUID[uiSummon_counter] = pTemp->GetGUID();
                                ++uiSummon_counter;
                            }
                            else
                            {
                                uiSummon_counter = 0;
                                ++uiStep;
                            }
                            break;

                        case 6: // summon warrior
                            DoCast(me, 33271); // shack effect
                            uiPhase_timer = 500;
                            if (uiSummon_counter < ENCOUNTER_WARRIOR_NUMBER)
                            {
                                Unit* pTemp = me->SummonCreature(NPC_WARRIOR_OF_THE_FROZEN_WASTES, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->setFaction(2084);
                                uiWarriorGUID[uiSummon_counter] = pTemp->GetGUID();
                                ++uiSummon_counter;
                            }
                            else
                            {
                                uiSummon_counter = 0;
                                ++uiStep;
                            }
                            break;

                        case 7: // summon warrior
                            DoCast(me, 33271); // shack effect
                            uiPhase_timer = 500;
                            if (uiSummon_counter < ENCOUNTER_BEHEMOTH_NUMBER)
                            {
                                Unit* pTemp = me->SummonCreature(NPC_FLESH_BEHEMOTH, (me->GetPositionX()-20)+rand()%40, (me->GetPositionY()-20)+rand()%40, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->setFaction(2084);
                                uiBehemothGUID[uiSummon_counter] = pTemp->GetGUID();
                                ++uiSummon_counter;
                            }
                            else
                            {
                                uiSummon_counter = 0;
                                ++uiStep;
                            }
                            break;

                        case 8: // summon announce
                            DoScriptText(SAY_LIGHT_OF_DAWN06, me);
                            JumpToNextStep(5000);
                            break;

                        case 9: // charge begins
                            SetHoldState(false);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                            {
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiOrbazGUID))
                            {
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                            {
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            }
                            for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                                if (Creature* pTemp = Unit::GetCreature(*me, uiAbominationGUID[i]))
                                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                                if (Creature* pTemp = Unit::GetCreature(*me, uiBehemothGUID[i]))
                                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                                if (Creature* pTemp = Unit::GetCreature(*me, uiGhoulGUID[i]))
                                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                                if (Creature* pTemp = Unit::GetCreature(*me, uiWarriorGUID[i]))
                                    pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z);
                            JumpToNextStep(5000);
                            break;

                        // ******* After battle *****************************************************************
                        case 11: // Tirion starts to speak
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN28, pTemp);
                            JumpToNextStep(21000);
                            break;

                        case 12:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN29, pTemp);
                            JumpToNextStep(13000);
                            break;

                        case 13:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN30, pTemp);
                            JumpToNextStep(13000);
                            break;

                        case 14:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(SAY_LIGHT_OF_DAWN31, me);
                            JumpToNextStep(7000);
                            break;

                        case 15: // summon gate
                            if (Unit* pTemp = me->SummonCreature(NPC_HIGHLORD_ALEXANDROS_MOGRAINE, LightofDawnLoc[22].x, LightofDawnLoc[22].y, LightofDawnLoc[22].z, LightofDawnLoc[22].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                            {
                                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pTemp->CastSpell(pTemp, SPELL_ALEXANDROS_MOGRAINE_SPAWN, true);
                                DoScriptText(EMOTE_LIGHT_OF_DAWN06, pTemp);
                                uiAlexandrosGUID = pTemp->GetGUID();
                            }
                            JumpToNextStep(4000);
                            break;

                        case 16: // Alexandros out
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID))
                            {
                                pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[23].x, LightofDawnLoc[23].y, LightofDawnLoc[23].z);
                                DoScriptText(SAY_LIGHT_OF_DAWN32, pTemp);
                            }
                            SetHoldState(false); // makes darion turns back
                            JumpToNextStep(5000);
                            break;

                        case 17:
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            DoScriptText(SAY_LIGHT_OF_DAWN34, me);
                            JumpToNextStep(5000);
                            break;

                        case 18: // Darion's spirit out
                            if (Unit* pTemp = me->SummonCreature(NPC_DARION_MOGRAINE, LightofDawnLoc[24].x, LightofDawnLoc[24].y, LightofDawnLoc[24].z, LightofDawnLoc[24].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                            {
                                DoScriptText(SAY_LIGHT_OF_DAWN35, pTemp);
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                uiDarionGUID = pTemp->GetGUID();
                            }
                            JumpToNextStep(4000);
                            break;

                        case 19: // runs to father
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                            {
                                DoScriptText(EMOTE_LIGHT_OF_DAWN07, pTemp);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[25].x, LightofDawnLoc[25].y, LightofDawnLoc[25].z);
                            }
                            JumpToNextStep(4000);
                            break;

                        case 20:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN36, pTemp);
                            JumpToNextStep(4000);
                            break;

                        case 21:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                                DoScriptText(EMOTE_LIGHT_OF_DAWN08, pTemp);
                            JumpToNextStep(4000);
                            break;

                        case 22:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN37, pTemp);
                            JumpToNextStep(8000);
                            break;

                        case 23:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN38, pTemp);
                            JumpToNextStep(8000);
                            break;

                        case 24:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN39, pTemp);

                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID)) // Tirion moves forward here
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[1].x, LightofDawnLoc[1].y, LightofDawnLoc[1].z);

                            JumpToNextStep(15000);
                            break;

                        case 25:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN40, pTemp);
                            JumpToNextStep(11000);
                            break;

                        case 26:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN41, pTemp);
                            JumpToNextStep(5000);
                            break;

                        case 27:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDarionGUID))
                                pTemp->setDeathState(JUST_DIED);
                            JumpToNextStep(24000);
                            break;

                        case 28:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN42, pTemp);
                            JumpToNextStep(6000);
                            break;

                        case 29: // lich king spawns
                            if (Unit* pTemp = me->SummonCreature(NPC_THE_LICH_KING, LightofDawnLoc[26].x, LightofDawnLoc[26].y, LightofDawnLoc[26].z, LightofDawnLoc[26].o, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000))
                            {
                                DoScriptText(SAY_LIGHT_OF_DAWN43, pTemp);
                                uiLichKingGUID = pTemp->GetGUID();
                                if (Unit* pAlex = Unit::GetCreature(*me, uiAlexandrosGUID))
                                    pTemp->CastSpell(pAlex, SPELL_SOUL_FEAST_ALEX, false);
                            }
                            JumpToNextStep(2000);
                            break;

                        case 30:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiAlexandrosGUID)) // just hide him
                            {
                                DoScriptText(EMOTE_LIGHT_OF_DAWN09, pTemp);
                                pTemp->SetVisibility(VISIBILITY_OFF);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                            {
                                pTemp->InterruptNonMeleeSpells(false);
                                DoScriptText(SAY_LIGHT_OF_DAWN45, pTemp);
                            }
                            JumpToNextStep(3000);
                            break;

                        case 31:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(EMOTE_LIGHT_OF_DAWN10, me);
                            DoScriptText(SAY_LIGHT_OF_DAWN44, me);
                            JumpToNextStep(3000);
                            break;

                        case 32:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[27].x, LightofDawnLoc[27].y, LightofDawnLoc[27].z);
                            JumpToNextStep(6000);
                            break;

                        case 33: // Darion supports to jump to lich king here
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoCast(me, SPELL_MOGRAINE_CHARGE); // jumping charge
    //   doesn't make it looks well, so workarounds, Darion charges, looks better
                            me->SetSpeed(MOVE_RUN, 3.0f);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            SetHoldState(false);
                            JumpToNextStep(0);
                            break;

                        case 35: // Lich king counterattacks
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                            {
                                pTemp->HandleEmoteCommand(EMOTE_ONESHOT_KICK);
                                DoScriptText(SAY_LIGHT_OF_DAWN46, pTemp);
                            }
                            me->SetSpeed(MOVE_RUN, 6.0f);
                            me->SetStandState(UNIT_STAND_STATE_DEAD);
                            SetHoldState(false); // Darion got kicked by lich king
                            JumpToNextStep(0);
                            break;

                        case 37: // Lich king counterattacks
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            JumpToNextStep(3000);
                            break;

                        case 38:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN47, pTemp);
                            JumpToNextStep(8000);
                            break;

                        case 39:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN48, pTemp);
                            JumpToNextStep(15000);
                            break;

                        case 40:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN49, pTemp);
                            JumpToNextStep(17000);
                            break;

                        case 41: // Lich king - Apocalypse
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                            {
                                DoScriptText(EMOTE_LIGHT_OF_DAWN11, pTemp);
                                DoScriptText(SAY_LIGHT_OF_DAWN51, pTemp);
                                if (Unit* pTirion = Unit::GetCreature(*me, uiTirionGUID))
                                {
                                    pTirion->SetStandState(UNIT_STAND_STATE_KNEEL);
                                    //pTemp->CastSpell(pTirion, SPELL_APOCALYPSE, false); // not working
                                    pTemp->CastSpell(pTirion, SPELL_SOUL_FEAST_TIRION, false);
                                    DoScriptText(EMOTE_LIGHT_OF_DAWN12, pTirion);
                                }
                            }
                            JumpToNextStep(2000);
                            break;

                        case 42: // Maxwell yells for attack
                            {
                                float fLichPositionX = 0,
                                      fLichPositionY = 0,
                                      fLichPositionZ = 0;
                                if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                {
                                    fLichPositionX = pTemp->GetPositionX();
                                    fLichPositionY = pTemp->GetPositionY();
                                    fLichPositionZ = pTemp->GetPositionZ();
                                }

                                if (fLichPositionX && fLichPositionY)
                                {
                                    Unit* pTemp;
                                    pTemp = me->SummonCreature(NPC_DEFENDER_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                    pTemp->setFaction(me->getFaction());
                                    pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                    uiDefenderGUID[0] = pTemp->GetGUID();

                                    pTemp = me->SummonCreature(NPC_RIMBLAT_EARTHSHATTER, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                    pTemp->setFaction(me->getFaction());
                                    pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                    uiEarthshatterGUID[0] = pTemp->GetGUID();
                                }
                                if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                                {
                                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                    pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                    DoScriptText(SAY_LIGHT_OF_DAWN50, pTemp);
                                }
                                if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                                {
                                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                    pTemp->HandleEmoteCommand(EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                }
                                if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                                {
                                    pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
                                    pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pTemp->SetSpeed(MOVE_RUN, 2.0f);
                                    pTemp->GetMotionMaster()->MovePoint(0, fLichPositionX, fLichPositionY, fLichPositionZ);
                                }
                            }
                            JumpToNextStep(4500);
                            break;

                        case 43: // They all got kicked
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(EMOTE_LIGHT_OF_DAWN13, pTemp);

                            if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                                pTemp->SetSpeed(MOVE_RUN, 6.0f);
                                pTemp->SetStandState(UNIT_STAND_STATE_DEAD);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[14].x, LightofDawnLoc[14].y, LightofDawnLoc[14].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                                pTemp->SetSpeed(MOVE_RUN, 6.0f);
                                pTemp->SetStandState(UNIT_STAND_STATE_DEAD);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[11].x, LightofDawnLoc[11].y, LightofDawnLoc[11].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                                pTemp->SetSpeed(MOVE_RUN, 6.0f);
                                pTemp->SetStandState(UNIT_STAND_STATE_DEAD);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[17].x, LightofDawnLoc[17].y, LightofDawnLoc[17].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiDefenderGUID[0]))
                            {
                                pTemp->SetSpeed(MOVE_RUN, 6.0f);
                                pTemp->SetStandState(UNIT_STAND_STATE_DEAD);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiEarthshatterGUID[0]))
                            {
                                pTemp->SetSpeed(MOVE_RUN, 6.0f);
                                pTemp->SetStandState(UNIT_STAND_STATE_DEAD);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[0].x+rand()%10, LightofDawnLoc[0].y+rand()%10, LightofDawnLoc[0].z);
                            }
                            JumpToNextStep(3000);
                            break;

                        case 44: // make them stand up
                            if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                                pTemp->SetStandState(UNIT_STAND_STATE_STAND);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                                pTemp->SetStandState(UNIT_STAND_STATE_STAND);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                                pTemp->SetStandState(UNIT_STAND_STATE_STAND);
                            JumpToNextStep(1000);
                            break;

                        case 45:
                            DoScriptText(SAY_LIGHT_OF_DAWN52, me);
                            JumpToNextStep(5000);
                            break;

                        case 46: // Darion stand up, "not today"
                            me->SetSpeed(MOVE_RUN, 1.0f);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(SAY_LIGHT_OF_DAWN53, me);
                            SetHoldState(false); // Darion throws sword
                            JumpToNextStep(7000);
                            break;

                        case 47: // Ashbringer rebirth
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            DoScriptText(EMOTE_LIGHT_OF_DAWN15, me);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                            {
                                pTemp->SetStandState(UNIT_STAND_STATE_STAND);
                                pTemp->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_HIGHLORD_TIRION_FORDRING));
                                pTemp->CastSpell(pTemp, SPELL_REBIRTH_OF_THE_ASHBRINGER, false);
                            }
                            JumpToNextStep(1000);
                            break;

                        case 48: // Show the cleansing effect (dawn of light)
                            //if (GameObject* pGo = me->GetMap()->GetGameObject(uiDawnofLightGUID))
                            //    pGo->SetPhaseMask(128, true);
                            me->SummonGameObject(GO_LIGHT_OF_DAWN, 2283.896f, -5287.914f, 83.066f, 0, 0, 0, 0, 0, 30000);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                            {
                                if (pTemp->HasAura(SPELL_REBIRTH_OF_THE_ASHBRINGER, 0))
                                    pTemp->RemoveAurasDueToSpell(SPELL_REBIRTH_OF_THE_ASHBRINGER);
                                pTemp->CastSpell(pTemp, 41542, false); // workarounds, light expoded, makes it cool
                                pTemp->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            }
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                pTemp->InterruptNonMeleeSpells(false);
                            JumpToNextStep(2500);
                            break;

                        case 49:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN54, pTemp);
                            JumpToNextStep(4000);
                            break;

                        case 50:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN55, pTemp);
                            JumpToNextStep(5000);
                            break;

                        case 51:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN56, pTemp);
                            JumpToNextStep(1000);
                            break;

                        case 52: // Tiron charges
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                            {
                                DoScriptText(EMOTE_LIGHT_OF_DAWN16, pTemp);
                                pTemp->CastSpell(pTemp, SPELL_TIRION_CHARGE, false); // jumping charge
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2H);
                                pTemp->SetSpeed(MOVE_RUN, 3.0f); // workarounds, make Tirion still running
                                pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[2].x, LightofDawnLoc[2].y, LightofDawnLoc[2].z);
                                if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                    pTemp->Relocate(LightofDawnLoc[28].x, LightofDawnLoc[28].y, LightofDawnLoc[28].z); // workarounds, he should kick back by Tirion, but here we relocate him
                            }
                            JumpToNextStep(1500);
                            break;

                        case 53:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN57, pTemp);
                            JumpToNextStep(1000);
                            break;

                        case 54:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                            {
                                pTemp->SetSpeed(MOVE_RUN, 1.0f);
                                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[29].x, LightofDawnLoc[29].y, LightofDawnLoc[29].z); // 26
                            }
                            JumpToNextStep(4000);
                            break;

                        case 55:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                pTemp->SetStandState(UNIT_STAND_STATE_KNEEL);
                            JumpToNextStep(2000);
                            break;

                        case 56:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                pTemp->SetStandState(UNIT_STAND_STATE_STAND);
                            JumpToNextStep(1500);
                            break;

                        case 57:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN58, pTemp);
                            JumpToNextStep(10000);
                            break;

                        case 58:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN59, pTemp);
                            JumpToNextStep(10000);
                            break;

                        case 59:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID))
                                pTemp->CastSpell(pTemp, SPELL_TELEPORT_VISUAL, false);
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID)) // Tirion runs to Darion
                            {
                                pTemp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                                pTemp->SetSpeed(MOVE_RUN, 1.0f);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[6].x, LightofDawnLoc[6].y, LightofDawnLoc[6].z);
                            }
                            JumpToNextStep(2500);
                            break;

                        case 60:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiLichKingGUID)) // Lich king disappears here
                            {
                                DoScriptText(EMOTE_LIGHT_OF_DAWN17, pTemp);
                                pTemp->Kill(pTemp);
                            }
                            JumpToNextStep(10000);
                            break;

                        case 61:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN60, pTemp);
                            JumpToNextStep(3000);
                            break;

                        case 62:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                            {
                                pTemp->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[7].x, LightofDawnLoc[7].y, LightofDawnLoc[7].z);
                            }
                            JumpToNextStep(5500);
                            break;

                        case 63:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                            {
                                pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[8].x, LightofDawnLoc[8].y, LightofDawnLoc[8].z);
                                DoScriptText(SAY_LIGHT_OF_DAWN61, pTemp);
                            }
                            JumpToNextStep(15000);
                            break;

                        case 64:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN62, pTemp);
                            JumpToNextStep(7000);
                            break;

                        case 65:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN63, pTemp);
                            JumpToNextStep(10000);
                            break;

                        case 66:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN64, pTemp);
                            JumpToNextStep(11000);
                            break;

                        case 67:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN65, pTemp);
                            JumpToNextStep(10000);
                            break;

                        case 68:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN66, pTemp);
                            JumpToNextStep(8000);
                            break;

                        case 69:
                            if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                                DoScriptText(SAY_LIGHT_OF_DAWN67, pTemp);
                            JumpToNextStep(10000);
                            break;

                        case 70:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            DoScriptText(SAY_LIGHT_OF_DAWN68, me);
                            JumpToNextStep(10000);
                            break;

                        case 71:
                            //if (GameObject* pGo = me->GetMap()->GetGameObject(uiDawnofLightGUID)) // Turn off dawn of light
                            //    pGo->SetPhaseMask(0, true);

                            {
                                Map *map = me->GetMap(); // search players with in 50 yards for quest credit
                                Map::PlayerList const &PlayerList = map->GetPlayers();
                                if (!PlayerList.isEmpty())
                                {
                                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                        if (i->getSource()->isAlive() && me->IsWithinDistInMap(i->getSource(), 50))
                                            i->getSource()->CastSpell(i->getSource(), SPELL_THE_LIGHT_OF_DAWN_Q, false);
                                }
                            }
                            me->SetVisibility(VISIBILITY_OFF); // respawns another Darion for quest turn in
                            me->SummonCreature(NPC_HIGHLORD_DARION_MOGRAINE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
                            JumpToNextStep(1000);
                            break;

                        case 72:
                            SetHoldState(false); // Escort ends
                            JumpToNextStep(25000);
                            break;

                        case 73:
                            me->ForcedDespawn();
                            break;
                    }

                } else uiPhase_timer -= diff;
            }

            // ******* During battle *****************************************************************
            else
            {
                if (uiAnti_magic_zone <= diff)
                {
                    DoCast(me, SPELL_ANTI_MAGIC_ZONE1);
                    uiAnti_magic_zone = 25000 + rand()%5000;
                } else uiAnti_magic_zone -= diff;

                if (uiDeath_strike <= diff)
                {
                    DoCast(me->getVictim(), SPELL_DEATH_STRIKE);
                    uiDeath_strike = 5000 + rand()%5000;
                } else uiDeath_strike -= diff;

                if (uiDeath_embrace <= diff)
                {
                    DoCast(me->getVictim(), SPELL_DEATH_EMBRACE);
                    uiDeath_embrace = 5000 + rand()%5000;
                } else uiDeath_embrace -= diff;

                if (uiIcy_touch <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ICY_TOUCH1);
                    uiIcy_touch = 5000 + rand()%5000;
                } else uiIcy_touch -= diff;

                if (uiUnholy_blight <= diff)
                {
                    DoCast(me->getVictim(), SPELL_UNHOLY_BLIGHT);
                    uiUnholy_blight = 5000 + rand()%5000;
                } else uiUnholy_blight -= diff;

                if (uiFight_speech <= diff)
                {
                    DoScriptText(RAND(SAY_LIGHT_OF_DAWN09,SAY_LIGHT_OF_DAWN10,SAY_LIGHT_OF_DAWN11,
                                      SAY_LIGHT_OF_DAWN12,SAY_LIGHT_OF_DAWN13,SAY_LIGHT_OF_DAWN14,
                                      SAY_LIGHT_OF_DAWN15,SAY_LIGHT_OF_DAWN16,SAY_LIGHT_OF_DAWN17,
                                      SAY_LIGHT_OF_DAWN18,SAY_LIGHT_OF_DAWN19,SAY_LIGHT_OF_DAWN20,
                                      SAY_LIGHT_OF_DAWN21,SAY_LIGHT_OF_DAWN22,SAY_LIGHT_OF_DAWN23,
                                      SAY_LIGHT_OF_DAWN24), me);
                    uiFight_speech = 15000 + rand()%5000;
                } else uiFight_speech -= diff;

                // Check spawns
                if (uiSpawncheck <= diff)
                {
                    SpawnNPC();
                    uiSpawncheck = 1000;
                } else uiSpawncheck -= diff;

                // Check targets
                if (uiTargetcheck <= diff)
                {
                    for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                        NPCChangeTarget(uiGhoulGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                        NPCChangeTarget(uiWarriorGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                        NPCChangeTarget(uiAbominationGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                        NPCChangeTarget(uiBehemothGUID[i]);
                    NPCChangeTarget(uiKoltiraGUID);
                    NPCChangeTarget(uiOrbazGUID);
                    NPCChangeTarget(uiThassarianGUID);

                    uiTargetcheck = 10000;
                } else uiTargetcheck -= diff;

                // Battle end
                if (uiFight_duration <= diff + 5000)
                {
                    if (!uiTirionGUID)
                        if (Unit* pTemp = me->SummonCreature(NPC_HIGHLORD_TIRION_FORDRING, LightofDawnLoc[0].x, LightofDawnLoc[0].y, LightofDawnLoc[0].z, 1.528f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000))
                        {
                            pTemp->setFaction(me->getFaction());
                            pTemp->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(EQUIP_UNEQUIP));
                            DoScriptText(SAY_LIGHT_OF_DAWN25, pTemp);
                            uiTirionGUID = pTemp->GetGUID();
                        }
                }
                if (uiFight_duration <= diff)
                {
                    bIsBattle = false;
                    uiFight_duration = 300000;

                    if (me->HasAura(SPELL_THE_MIGHT_OF_MOGRAINE, 0))
                        me->RemoveAurasDueToSpell(SPELL_THE_MIGHT_OF_MOGRAINE);
                    me->RemoveAllAuras();
                    me->DeleteThreatList();
                    me->CombatStop(true);
                    me->InterruptNonMeleeSpells(false);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                    for (uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
                        DespawnNPC(uiDefenderGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
                        DespawnNPC(uiEarthshatterGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
                        DespawnNPC(uiAbominationGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
                        DespawnNPC(uiBehemothGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
                        DespawnNPC(uiGhoulGUID[i]);
                    for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
                        DespawnNPC(uiWarriorGUID[i]);

                    if (Creature* pTemp = Unit::GetCreature(*me, uiKorfaxGUID))
                    {
                        pTemp->RemoveAllAuras();
                        pTemp->DeleteThreatList();
                        pTemp->CombatStop(true);
                        pTemp->AttackStop();
                        pTemp->setFaction(me->getFaction());
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[9].x, LightofDawnLoc[9].y, LightofDawnLoc[9].z);
                    }

                    if (Creature* pTemp = Unit::GetCreature(*me, uiMaxwellGUID))
                    {
                        pTemp->RemoveAllAuras();
                        pTemp->DeleteThreatList();
                        pTemp->CombatStop(true);
                        pTemp->AttackStop();
                        pTemp->setFaction(me->getFaction());
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[12].x, LightofDawnLoc[12].y, LightofDawnLoc[12].z);
                    }

                    if (Creature* pTemp = Unit::GetCreature(*me, uiEligorGUID))
                    {
                        pTemp->RemoveAllAuras();
                        pTemp->DeleteThreatList();
                        pTemp->CombatStop(true);
                        pTemp->AttackStop();
                        pTemp->setFaction(me->getFaction());
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[15].x, LightofDawnLoc[15].y, LightofDawnLoc[15].z);
                    }
                    DespawnNPC(uiRayneGUID);

                    if (Creature* pTemp = Unit::GetCreature(*me, uiKoltiraGUID))
                    {
                        pTemp->RemoveAllAuras();
                        pTemp->DeleteThreatList();
                        pTemp->CombatStop(true);
                        pTemp->AttackStop();
                        pTemp->setFaction(me->getFaction());
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[18].x, LightofDawnLoc[18].y, LightofDawnLoc[18].z);
                        pTemp->CastSpell(pTemp, SPELL_THE_LIGHT_OF_DAWN, false);
                    }

                    if (Creature* pTemp = Unit::GetCreature(*me, uiOrbazGUID))
                        DoScriptText(EMOTE_LIGHT_OF_DAWN04, pTemp);

                    if (Creature* pTemp = Unit::GetCreature(*me, uiThassarianGUID))
                    {
                        pTemp->RemoveAllAuras();
                        pTemp->DeleteThreatList();
                        pTemp->CombatStop(true);
                        pTemp->AttackStop();
                        pTemp->setFaction(me->getFaction());
                        pTemp->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pTemp->GetMotionMaster()->MovePoint(0, LightofDawnLoc[20].x, LightofDawnLoc[20].y, LightofDawnLoc[20].z);
                        pTemp->CastSpell(pTemp, SPELL_THE_LIGHT_OF_DAWN, false);
                    }

                    if (Creature* pTemp = Unit::GetCreature(*me, uiTirionGUID))
                        DoScriptText(SAY_LIGHT_OF_DAWN26, pTemp);

                    SetHoldState(false);

                } else uiFight_duration -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            uiPhase_timer = uiTimer;
            ++uiStep;
        }

        void NPCChangeTarget(uint64 ui_GUID)
        {
            if (Creature* pTemp = Unit::GetCreature(*me, ui_GUID))
                if (pTemp->isAlive())
                    if (Unit* pTarger = SelectUnit(SELECT_TARGET_RANDOM,0))
                        if (pTarger->isAlive())
                        {
                            // pTemp->DeleteThreatList();
                            pTemp->AddThreat(pTarger, 0.0f);
                            pTemp->AI()->AttackStart(pTarger);
                            pTemp->SetInCombatWith(pTarger);
                            pTarger->SetInCombatWith(pTemp);
                            // pTemp->GetMotionMaster()->MoveChase(pTarger, 20.0f);
                        }
        }

        void SpawnNPC()
        {
            Unit* pTemp = NULL;

            // Death
            for (uint8 i = 0; i < ENCOUNTER_GHOUL_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiGhoulGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_ACHERUS_GHOUL, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2084);
                    uiGhoulGUID[i] = pTemp->GetGUID();
                }
            }
            for (uint8 i = 0; i < ENCOUNTER_ABOMINATION_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiAbominationGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_WARRIOR_OF_THE_FROZEN_WASTES, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2084);
                    uiAbominationGUID[i] = pTemp->GetGUID();
                }
            }
            for (uint8 i = 0; i < ENCOUNTER_WARRIOR_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiWarriorGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_RAMPAGING_ABOMINATION, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2084);
                    uiWarriorGUID[i] = pTemp->GetGUID();
                }
            }
            for (uint8 i = 0; i < ENCOUNTER_BEHEMOTH_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiBehemothGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_FLESH_BEHEMOTH, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2084);
                    uiBehemothGUID[i] = pTemp->GetGUID();
                }
            }

            // Dawn
            for (uint8 i = 0; i < ENCOUNTER_DEFENDER_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiDefenderGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_DEFENDER_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2089);
                    me->AddThreat(pTemp, 0.0f);
                    uiDefenderGUID[i] = pTemp->GetGUID();
                }
            }
            for (uint8 i = 0; i < ENCOUNTER_EARTHSHATTER_NUMBER; ++i)
            {
                pTemp = Unit::GetCreature(*me, uiEarthshatterGUID[i]);
                if (!pTemp)
                {
                    pTemp = me->SummonCreature(NPC_RIMBLAT_EARTHSHATTER, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    pTemp->setFaction(2089);
                    me->AddThreat(pTemp, 0.0f);
                    uiEarthshatterGUID[i] = pTemp->GetGUID();
                }
            }
            pTemp = Unit::GetCreature(*me, uiKorfaxGUID);
            if (!pTemp)
            {
                pTemp = me->SummonCreature(NPC_KORFAX_CHAMPION_OF_THE_LIGHT, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiKorfaxGUID = pTemp->GetGUID();
            }
            pTemp = Unit::GetCreature(*me, uiMaxwellGUID);
            if (!pTemp)
            {
                pTemp = me->SummonCreature(NPC_LORD_MAXWELL_TYROSUS, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiMaxwellGUID = pTemp->GetGUID();
            }
            pTemp = Unit::GetCreature(*me, uiEligorGUID);
            if (!pTemp)
            {
                pTemp = me->SummonCreature(NPC_COMMANDER_ELIGOR_DAWNBRINGER, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiEligorGUID = pTemp->GetGUID();
            }
            pTemp = Unit::GetCreature(*me, uiRayneGUID);
            if (!pTemp)
            {
                pTemp = me->SummonCreature(NPC_RAYNE, LightofDawnLoc[0].x+rand()%30, LightofDawnLoc[0].y+rand()%30, LightofDawnLoc[0].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                pTemp->setFaction(2089);
                me->AddThreat(pTemp, 0.0f);
                uiRayneGUID = pTemp->GetGUID();
            }
        }

        void DespawnNPC(uint64 pGUID)
        {
            if (Creature* pTemp = Unit::GetCreature(*me, pGUID))
                if (pTemp->isAlive())
                {
                    pTemp->SetVisibility(VISIBILITY_OFF);
                    pTemp->Kill(pTemp);
                }
        }
    };

};



/*######
## npc the lich king in dawn of light
######*/
class npc_the_lich_king_tirion_dawn : public CreatureScript
{
public:
    npc_the_lich_king_tirion_dawn() : CreatureScript("npc_the_lich_king_tirion_dawn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_the_lich_king_tirion_dawnAI (pCreature);
    }

    struct npc_the_lich_king_tirion_dawnAI : public ScriptedAI
    {
        npc_the_lich_king_tirion_dawnAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
        void Reset() {}
        void AttackStart(Unit * /*who*/) {} // very sample, just don't make them aggreesive
        void UpdateAI(const uint32 /*diff*/) {}
        void JustDied(Unit* /*killer*/) {}
    };

};



void AddSC_the_scarlet_enclave_c5()
{
    new npc_highlord_darion_mograine();
    new npc_the_lich_king_tirion_dawn();
}
