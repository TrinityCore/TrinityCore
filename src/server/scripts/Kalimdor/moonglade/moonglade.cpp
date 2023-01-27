/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
 SDName: Moonglade
 SD%Complete: 100
 SDComment: Quest support: 30, 272, 5929, 5930, 8736. Special Flight Paths for Druid class.
 SDCategory: Moonglade
 EndScriptData */

/* ContentData
 npc_great_bear_spirit
 EndContentData */

#include "scriptPCH.h"

/*######
 ## npc_great_bear_spirit
 ######*/

enum
{
    GOSSIP_BEAR1 = 7439,
    GOSSIP_BEAR2 = 7442,
    GOSSIP_BEAR3 = 7444,
    GOSSIP_BEAR4 = 7446,
};

bool GossipHello_npc_great_bear_spirit(Player* pPlayer, Creature* pCreature)
{
    //ally or horde quest
    if (pPlayer->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(4719, pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(4718, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_great_bear_spirit(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(4721, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(4733, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BEAR4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(4734, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            pPlayer->SEND_GOSSIP_MENU(4735, pCreature->GetGUID());
            if (pPlayer->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(5929);
            if (pPlayer->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
                pPlayer->AreaExploredOrEventHappens(5930);
            break;
    }
    return true;
}

/*######
 ## npc_keeper_remulos
 ######*/

enum KeeperRemulosData
{
    SPELL_CONJURE_RIFT           = 25813, // summon Eranikus
    SPELL_HEALING_TOUCH          = 23381,
    SPELL_REGROWTH               = 20665,
    SPELL_REJUVENATION           = 20664,
    SPELL_STARFIRE               = 21668,
    SPELL_ERANIKUS_REDEEMED      = 25846, // transform Eranikus
  //SPELL_MOONGLADE_TRANQUILITY  = unk,   // spell which acts as a spotlight over Eranikus after he is redeemed
    SPELL_THROW_NIGHTMARE_OBJECT = 25004,

    NPC_ERANIKUS_TYRANT     = 15491,
    NPC_NIGHTMARE_PHANTASM  = 15629, // shadows summoned during the event - should cast 17228 and 21307
    NPC_REMULOS             = 11832,
    NPC_TYRANDE_WHISPERWIND = 15633, // appears with the priestess during the event to help the players - should cast healing spells
    NPC_ELUNE_PRIESTESS     = 15634,
    NPC_MALFURION           = 15362,

    QUEST_NIGHTMARE_MANIFESTS = 8736,
    QUEST_WAKING_LEGENDS      = 8447,

    // yells -> in cronological order
    SAY_REMULOS_INTRO_1    = 11282, // remulos intro
    SAY_REMULOS_INTRO_2    = 11283,
    SAY_REMULOS_INTRO_3    = 11290,
    SAY_REMULOS_INTRO_4    = 11291,
    SAY_REMULOS_INTRO_5    = 11292,
    EMOTE_SUMMON_ERANIKUS  = 11277, // eranikus spawn - world emote
    SAY_ERANIKUS_SPAWN     = 11030,
    SAY_REMULOS_TAUNT_1    = 11293, // eranikus and remulos chat
    EMOTE_ERANIKUS_LAUGH   = 11296,
    SAY_ERANIKUS_TAUNT_2   = 11294,
    SAY_REMULOS_TAUNT_3    = 11295,
    SAY_ERANIKUS_TAUNT_4   = 11297,
    EMOTE_ERANIKUS_ATTACK  = 11298, // start attack
    SAY_REMULOS_DEFEND_1   = 11300,
    SAY_REMULOS_DEFEND_2   = 11301,
    SAY_ERANIKUS_SHADOWS   = 11299,
    SAY_REMULOS_DEFEND_3   = 11302,
    SAY_ERANIKUS_ATTACK_1  = 11304,
    SAY_ERANIKUS_ATTACK_2  = 11305,
    SAY_ERANIKUS_ATTACK_3  = 11306,
    SAY_ERANIKUS_KILL      = 11027,
    SAY_TYRANDE_APPEAR     = 11309, // Tyrande appears
    SAY_TYRANDE_HEAL       = 11317, // yelled by tyrande when healing is needed
    SAY_TYRANDE_FORGIVEN_1 = 11310,
    SAY_TYRANDE_FORGIVEN_2 = 11311,
    SAY_TYRANDE_FORGIVEN_3 = 11312,
    SAY_ERANIKUS_DEFEAT_1  = 11314,
    SAY_ERANIKUS_DEFEAT_2  = 11315,
    SAY_ERANIKUS_DEFEAT_3  = 11316,
    EMOTE_ERANIKUS_REDEEM  = 11313, // world emote before WotLK //Eranikus, Tyrant of the Dream, is wholly consumed by the Light of Elune. Tranquility sets in over the Moonglade"
    EMOTE_TYRANDE_KNEEL    = 11319,
    SAY_TYRANDE_REDEEMED   = 11320,
    SAY_REDEEMED_1         = 11323, // eranikus redeemed
    SAY_REDEEMED_2         = 11324,
    SAY_REDEEMED_3         = 11326,
    SAY_REDEEMED_4         = 11327,
    SAY_REMULOS_OUTRO_1    = 11303, // remulos outro
    SAY_REMULOS_OUTRO_2    = 11329,
    // Texts Waking_Legends quest
    SAY_REMULOS_1          = 10866,
    SAY_REMULOS_2          = 10867,
    SAY_REMULOS_3          = 10868,
    SAY_REMULOS_4          = 10870,
    SAY_REMULOS_5          = 10872,
    SAY_REMULOS_6          = 10874,
    SAY_REMULOS_7          = 10877,
    SAY_REMULOS_8          = 10879,
    SAY_MALFURION_1        = 10869,
    SAY_MALFURION_2        = 10871,
    SAY_MALFURION_3        = 10873,
    SAY_MALFURION_4        = 10876,
    SAY_MALFURION_5        = 10878,

    POINT_ID_ERANIKUS_FLIGHT   = 0,
    POINT_ID_ERANIKUS_COMBAT   = 1,
    POINT_ID_ERANIKUS_REDEEMED = 2,

    MAX_SHADOWS      = 4, // the max shadows summoned per turn
    MAX_SUMMON_TURNS = 10 // There are about 10 summoned shade waves
};

struct EventLocations
{
    float m_fX, m_fY, m_fZ, m_fO;
};

// Waking Legends Quest
static EventLocations aRemulosLocations[] =
{
    {7828.177246f, -2246.510010f, 463.565979f, 4.57f},
    {7817.905762f, -2303.467529f, 456.028320f, 3.58f},
    {7772.034668f, -2325.162354f, 454.414551f, 3.58f},
    {7753.641113f, -2305.021973f, 456.996155f, 3.41f},
    {7749.481934f, -2304.861328f, 455.891174f, 3.49f}, // Remulos final lake location
    {7848.299805f, -2216.350098f, 470.888000f, 4.05f}, // Remulos initial location
};
// End Waking Legends Quest

static EventLocations aEranikusLocations[] =
{
    {7881.72f, -2651.23f, 493.29f, 0.40f}, // eranikus spawn loc
    {7929.86f, -2574.88f, 505.35f, 0.0f }, // eranikus flight move loc
    {7912.98f, -2568.99f, 488.71f, 0.0f }, // eranikus combat move loc
    {7906.57f, -2565.63f, 488.39f, 0.0f }, // eranikus redeemed loc
};

static EventLocations aTyrandeLocations[] = //TODO : add waypoints, or spawn further and move with pathfinding. m_creature->GetMotionMaster()->MovePoint(0, fX, fY, fZ, MOVE_PATHFINDING);
{
    // Tyrande should appear along the pathway, but because of the missing pathfinding we'll summon here closer to Eranikus
    //{7948.89f, -2575.58f, 490.05f, 3.03f}, // tyrande spawn loc
    {7955.826172f, -2369.380856f, 486.537537f, 4.812577f}, //tyrande spawn au loin
    {7972.298828f, -2519.744873f, 487.863190f, 0.0f },//point sur le 2e pont avant le soucis de pathfinding.
    {7972.312500f, -2521.717773f, 488.041565f, 0.0f },//point sur le 2e pont après le soucis de pathfinding.
    {7976.151367f, -2549.361084f, 490.079834f, 0.0f },//point pour éviter de courrir sur la rembarde du pont.
    {7939.48352f, -2577.439941f, 488.615326f, 0.0f },//point avant dernier pont pour approprier.
    {7888.32f, -2566.25f, 487.02f, 0.0f }, // tyrande heal loc
    {7901.83f, -2565.24f, 488.04f, 0.0f }, // tyrande eranikus loc
};

static EventLocations aShadowsLocations[] =
{
    // Inside the house shades - first wave only
    {7832.78f, -2604.57f, 489.29f, 0.0f },
    {7826.68f, -2538.46f, 489.30f, 0.0f },
    {7811.48f, -2573.20f, 488.49f, 0.0f },
    // Outside shade points - basically only the first set of coords is used for the summoning; there is no solid proof of using the other coords
    {7888.32f, -2566.25f, 487.02f, 0.0f },
    {7946.12f, -2577.10f, 489.97f, 0.0f },//saw this in a vid... Alita. My theory : 3 spawn points, + one spawn point being near the player(or Remulos, in the vids they stick together..).
    {7963.00f, -2492.03f, 487.84f, 0.0f }//Alita, actually yes.
};

uint32 m_idQuestActive;
struct npc_keeper_remulosAI : public npc_escortAI
{
    npc_keeper_remulosAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiHealTimer;
    uint32 m_uiStarfireTimer;
    uint32 m_uiShadesummonTimer;
    uint32 m_uiOutroTimer;
    uint32 m_uiTransitionTimer;

    bool m_bEventWLStarted;
    uint32 m_uiSayingTimeTimer;
    uint32 m_uiTabMovementsTimer[5];
    uint32 m_uiCastSpellTimer;
    uint32 m_uiSummonMalfurionTimer;
    uint32 m_uiTabDialogsTimer[10];
    bool m_bReturnInitialPosition;
    uint32 m_uiInitialPositionTimer;
    uint32 m_uiQuestComplete;
    uint32 m_uiDispawnTimer;
    bool m_bEventWLFinished;

    ObjectGuid m_uiEranikusGUID;
    ObjectGuid m_uiMalfurionGUID;

    uint8 m_uiOutroPhase;
    uint8 m_uiSummonCount;

    bool m_bIsFirstWave;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiOutroTimer = 0;
            m_uiOutroPhase = 0;
            m_uiSummonCount = 0;

            m_uiEranikusGUID.Clear();

            m_uiShadesummonTimer = 0;
            m_uiHealTimer = 10000;
            m_uiStarfireTimer = 25000;

            m_bIsFirstWave = true;

            m_uiTransitionTimer = 0;

            m_bEventWLStarted = false;
            m_uiSayingTimeTimer = 0;
            m_uiCastSpellTimer = 0;
            m_uiSummonMalfurionTimer = 0;
            m_bReturnInitialPosition = false;
            m_uiInitialPositionTimer = 0;
            m_uiQuestComplete = 0;
            m_uiDispawnTimer = 0;
            m_bEventWLFinished = false;

            m_uiMalfurionGUID.Clear();

            for (uint32 & j : m_uiTabMovementsTimer)
                j = 0;
            for (uint32 & k : m_uiTabDialogsTimer)
                k = 0;
        }
    }

    // Remulos follows player
    void EnterEvadeMode() override
    {
        npc_escortAI::EnterEvadeMode();
        if (HasEscortState(STATE_ESCORT_ESCORTING) && !m_bIsFirstWave)
        {
            if (Player* pPlayer = GetPlayerForEscort())
            {
                if (m_idQuestActive == QUEST_NIGHTMARE_MANIFESTS && m_creature->IsWithinDistInMap(pPlayer, 200))
                    m_creature->GetMotionMaster()->MoveFollow(pPlayer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
            }
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_ERANIKUS_TYRANT:
                m_uiEranikusGUID = pSummoned->GetObjectGuid();
                // Make Eranikus unattackable first
                pSummoned->AddAura(17131); // hover
                pSummoned->SetFly(true);
                pSummoned->MonsterMove(aEranikusLocations[0].m_fX, aEranikusLocations[0].m_fY, aEranikusLocations[0].m_fZ);
                pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pSummoned->SetRespawnDelay(DAY);
                break;
            case NPC_NIGHTMARE_PHANTASM:
                pSummoned->AI()->AttackStart(m_creature);
                pSummoned->SetRespawnDelay(DAY);
                break;
            case NPC_MALFURION:
                m_uiMalfurionGUID = pSummoned->GetObjectGuid();
                pSummoned->AddAura(10665);
                pSummoned->AddAura(24999);
                break;
        }
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 uiType, uint32 uiPointId) override
    {
        if (m_idQuestActive == QUEST_NIGHTMARE_MANIFESTS)
        {
            if (uiType != POINT_MOTION_TYPE || pSummoned->GetEntry() != NPC_ERANIKUS_TYRANT)
                return;

            switch (uiPointId)
            {
                case POINT_ID_ERANIKUS_FLIGHT:
                    // Set Eranikus to face Remulos
                    pSummoned->SetFacingToObject(m_creature);
                    break;
                case POINT_ID_ERANIKUS_COMBAT:
                    // Start attack
                    pSummoned->SetFly(false);
                    pSummoned->HandleEmote(EMOTE_ONESHOT_LAND);
                    DoScriptText(SAY_ERANIKUS_ATTACK_2, pSummoned);
                    m_uiTransitionTimer = 1000;
                    break;
            }
        }
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_idQuestActive == QUEST_NIGHTMARE_MANIFESTS)
        {
            // set quest to failed
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_NIGHTMARE_MANIFESTS);

            // despawn the summons
            if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                pEranikus->AI()->EnterEvadeMode();
            m_idQuestActive = 0;
        }
        if (m_idQuestActive == QUEST_WAKING_LEGENDS)
        {
            // set quest to failed
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_WAKING_LEGENDS);
            m_idQuestActive = 0;
        }
    }

    void WaypointReached(uint32 uiPointId) override
    {
        if (m_idQuestActive == QUEST_NIGHTMARE_MANIFESTS)
        {
            switch (uiPointId)
            {
                case 0:
                    if (Player* pPlayer = GetPlayerForEscort())
                        DoScriptText(SAY_REMULOS_INTRO_1, m_creature, pPlayer);
                    m_creature->SetSpeedRate(MOVE_WALK, 2.2f); //du cout faudrait ptetre aussi revoir la vitesse de course.
                    m_creature->SetWalk(true);
                    break;
                case 1:
                    m_creature->SetFactionTemplateId(1254); //Alita stop Remulos from healing shades.
                    //1254 is a cenarian circle faction(609), belonging to group 1, has group 8 as ennemies, and is friendly with other cenarian circle guys
                    DoScriptText(SAY_REMULOS_INTRO_2, m_creature);
                    break;
                case 13:
                    if (Player* pPlayer = GetPlayerForEscort())
                        DoScriptText(SAY_REMULOS_INTRO_3, m_creature, pPlayer);
                    break;
                case 14:
                    DoScriptText(SAY_REMULOS_INTRO_4, m_creature);
                    break;
                case 15:
                    DoScriptText(SAY_REMULOS_INTRO_5, m_creature);
                    break;
                case 16:
                    // Summon ERANIKUS
                    DoCastSpellIfCan(m_creature, SPELL_CONJURE_RIFT);
                    break;
                case 17:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                    {
                        // This big yellow emote was removed at some point in WotLK
                        //DoScriptText(EMOTE_SUMMON_ERANIKUS, pEranikus);
                        DoScriptText(SAY_ERANIKUS_SPAWN, pEranikus);
                    }
                    break;
                case 18:
                    DoScriptText(SAY_REMULOS_TAUNT_1, m_creature);
                    break;
                case 19:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        DoScriptText(EMOTE_ERANIKUS_LAUGH, pEranikus);
                    break;
                case 20:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        DoScriptText(SAY_ERANIKUS_TAUNT_2, pEranikus);
                    break;
                case 21:
                    DoScriptText(SAY_REMULOS_TAUNT_3, m_creature);
                    break;
                case 22:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        DoScriptText(SAY_ERANIKUS_TAUNT_4, pEranikus);
                    break;
                case 23:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        DoScriptText(EMOTE_ERANIKUS_ATTACK, pEranikus);
                    break;
                case 24:
                    if (Player* pPlayer = GetPlayerForEscort())
                        DoScriptText(SAY_REMULOS_DEFEND_1, m_creature, pPlayer);
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        pEranikus->GetMotionMaster()->MovePoint(POINT_ID_ERANIKUS_FLIGHT, aEranikusLocations[1].m_fX, aEranikusLocations[1].m_fY, aEranikusLocations[1].m_fZ);
                    break;
                case 28:
                    DoScriptText(SAY_REMULOS_DEFEND_2, m_creature);
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                    {
                        m_creature->SetFacingToObject(pEranikus);
                        pEranikus->SetFacingToObject(m_creature);
                    }
                    break;
                case 29:
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        DoScriptText(SAY_ERANIKUS_SHADOWS, pEranikus);
                    break;
                case 30:
                    DoScriptText(SAY_REMULOS_DEFEND_3, m_creature);
                    SetEscortPaused(true);
                    m_uiShadesummonTimer = 5000;
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        m_creature->SetFacingToObject(pEranikus);
                    break;
                case 31:
                    SetEscortPaused(true);
                    break;
            }
        }
    }

    void DoHandleOutro(Creature* pTarget)
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->GroupEventHappens(QUEST_NIGHTMARE_MANIFESTS, pTarget);

        m_uiOutroTimer = 3000;
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (m_idQuestActive == QUEST_NIGHTMARE_MANIFESTS)
        {
            if (m_uiOutroTimer)
            {
                if (m_uiOutroTimer <= uiDiff)
                {
                    switch (m_uiOutroPhase)
                    {
                        case 0:
                            DoScriptText(SAY_REMULOS_OUTRO_1, m_creature);
                            m_uiOutroTimer = 3000;
                            break;
                        case 1:
                            // Despawn Remulos after the outro is finished - he will respawn automatically at his home position after a few min
                            DoScriptText(SAY_REMULOS_OUTRO_2, m_creature);
                            //m_creature->ForcedDespawn(3000);
                            // Alita : piqué ce morceau de code à ScriptedFollowerAI.h, car NON il ne se replaçait pas forcément correctement (p-etre lié à mon code dans evade mode)
                            //Ustaag <Nostalrius> : vilain fix des mobs qui voulaient pas respawn à leur point de spawn
                            //m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(),nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                            m_creature->NearTeleportTo(m_creature->GetHomePosition());
                            m_creature->ForcedDespawn();
                            m_uiOutroTimer = 0;
                            break;
                    }
                    ++m_uiOutroPhase;
                }
                else
                    m_uiOutroTimer -= uiDiff;
            }

            // during the battle
            if (m_uiShadesummonTimer)
            {
                if (m_uiShadesummonTimer <= uiDiff)
                {
                    // do this yell only first time
                    if (m_bIsFirstWave)
                    {
                        // summon 3 shades inside the house
                        for (uint8 i = 0; i < MAX_SHADOWS; ++i)
                            m_creature->SummonCreature(NPC_NIGHTMARE_PHANTASM, aShadowsLocations[i].m_fX, aShadowsLocations[i].m_fY, aShadowsLocations[i].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN, 0);

                        if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                            DoScriptText(SAY_ERANIKUS_ATTACK_1, pEranikus);

                        ++m_uiSummonCount;
                        SetEscortPaused(false);
                        m_bIsFirstWave = false;
                    }

                    // Summon 3 shades per turn until the maximum summon turns are reached
                    float fX, fY, fZ;
                    // Randomize the summon point - guesswork; not used //Alita, I'm convinced there's some randomness to add.
                    //uint8 uiSummonPoint = roll_chance_i(70) ? MAX_SHADOWS : urand(MAX_SHADOWS + 1, 2*MAX_SHADOWS - 1);

                    uint8 randomShadowNumber = urand(3, MAX_SHADOWS);

                    //Alita : four possible zones : in front of the building, accross the bridge(not far from the platform), another farther away, and next to player(well since the player is supposed to be with Remulos).
                    //I beleive there is also a loner, but oh well.
                    if (m_uiSummonCount < MAX_SUMMON_TURNS)
                    {
                        switch (m_uiSummonCount % 2)
                        {
                            case 0:
                                if (Player* pPlayer = GetPlayerForEscort())
                                {
                                    float plfX, plfY, plfZ;
                                    plfX = pPlayer->GetPositionX();
                                    plfY = pPlayer->GetPositionY();
                                    plfZ = pPlayer->GetPositionZ();
                                    for (uint8 i = 0; i < randomShadowNumber; ++i)
                                    {
                                        m_creature->GetRandomPoint(plfX, plfY, plfZ, 20.0f, fX, fY, fZ);
                                        m_creature->SummonCreature(NPC_NIGHTMARE_PHANTASM, fX, fY, fZ + 2, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    }
                                }
                                break;
                            case 1:
                                uint8 randomSummonPoint = urand(3, 5);
                                for (uint8 i = 0; i < randomShadowNumber; ++i)
                                {
                                    m_creature->GetRandomPoint(aShadowsLocations[randomSummonPoint].m_fX, aShadowsLocations[randomSummonPoint].m_fY, aShadowsLocations[randomSummonPoint].m_fZ, 10.0f, fX, fY, fZ);
                                    m_creature->SummonCreature(NPC_NIGHTMARE_PHANTASM, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 50000);
                                }
                                break;
                        }
                        ++m_uiSummonCount;
                    }

                    // If all the shades were summoned then set Eranikus in combat
                    // We don't count the dead shades, because the boss is usually set in combat before all shades are dead
                    if (m_uiSummonCount == MAX_SUMMON_TURNS)
                    {
                        m_uiShadesummonTimer = 0;

                        if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                        {
                            pEranikus->GetMotionMaster()->MovePoint(POINT_ID_ERANIKUS_COMBAT, aEranikusLocations[2].m_fX, aEranikusLocations[2].m_fY, aEranikusLocations[2].m_fZ);
                            pEranikus->RemoveAurasDueToSpell(17131);
                        }
                    }
                    else
                        m_uiShadesummonTimer = urand(20000, 30000);
                }
                else
                    m_uiShadesummonTimer -= uiDiff;
            }

            if (m_uiTransitionTimer)
            {
                if (m_uiTransitionTimer <= uiDiff)
                {
                    if (Creature* pEranikus = m_creature->GetMap()->GetCreature(m_uiEranikusGUID))
                    {
                        m_uiTransitionTimer = 0;

                        pEranikus->SetWalk(true);
                        pEranikus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pEranikus->AI()->AttackStart(m_creature);
                    }
                }
                else
                    m_uiTransitionTimer -= uiDiff;
            }

            // Combat spells
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;

            if (m_uiHealTimer < uiDiff)
            {
                if (Unit* pTarget = m_creature->FindLowestHpFriendlyUnit(DEFAULT_VISIBILITY_DISTANCE))
                {
                    switch (urand(0, 2))
                    {
                        case 0:
                            DoCastSpellIfCan(pTarget, SPELL_HEALING_TOUCH);
                            break;
                        case 1:
                            DoCastSpellIfCan(pTarget, SPELL_REJUVENATION);
                            break;
                        case 2:
                            DoCastSpellIfCan(pTarget, SPELL_REGROWTH);
                            break;
                    }
                }
                m_uiHealTimer = 10000;
            }
            else
                m_uiHealTimer -= uiDiff;

            if (m_uiStarfireTimer < uiDiff)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_STARFIRE) == CAST_OK)
                        m_uiStarfireTimer = 20000;
                }
            }
            else
                m_uiStarfireTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (m_idQuestActive == QUEST_WAKING_LEGENDS)
        {
            if (Player* pPlayer = GetPlayerForEscort())
            {
                if (pPlayer->GetQuestStatus(QUEST_WAKING_LEGENDS) == QUEST_STATUS_INCOMPLETE)
                {
                    if (!m_bEventWLStarted)
                    {
                        SetEscortPaused(true);
                        DoScriptText(SAY_REMULOS_1, m_creature, pPlayer);
                        m_uiSayingTimeTimer = 3000;
                        m_bEventWLStarted = true;
                    }

                    if (m_uiSayingTimeTimer)
                    {
                        if (m_uiSayingTimeTimer <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(0, aRemulosLocations[0].m_fX, aRemulosLocations[0].m_fY, aRemulosLocations[0].m_fZ, MOVE_PATHFINDING);
                            if (!m_bReturnInitialPosition)
                                m_uiTabMovementsTimer[0] = 7000;
                            else
                                m_uiInitialPositionTimer = 6000;
                            m_uiSayingTimeTimer = 0;
                        }
                        else
                            m_uiSayingTimeTimer -= uiDiff;
                    }

                    if (m_uiTabMovementsTimer[0])
                    {
                        if (m_uiTabMovementsTimer[0] <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(1, aRemulosLocations[1].m_fX, aRemulosLocations[1].m_fY, aRemulosLocations[1].m_fZ);
                            if (!m_bReturnInitialPosition)
                                m_uiTabMovementsTimer[1] = 9000;
                            else
                                m_uiSayingTimeTimer = 7000;
                            m_uiTabMovementsTimer[0] = 0;
                        }
                        else
                            m_uiTabMovementsTimer[0] -= uiDiff;
                    }

                    if (m_uiTabMovementsTimer[1])
                    {
                        if (m_uiTabMovementsTimer[1] <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(2, aRemulosLocations[2].m_fX, aRemulosLocations[2].m_fY, aRemulosLocations[2].m_fZ);
                            if (!m_bReturnInitialPosition)
                                m_uiTabMovementsTimer[2] = 8000;
                            else
                                m_uiTabMovementsTimer[0] = 8000;
                            m_uiTabMovementsTimer[1] = 0;
                        }
                        else
                            m_uiTabMovementsTimer[1] -= uiDiff;
                    }

                    if (m_uiTabMovementsTimer[2])
                    {
                        if (m_uiTabMovementsTimer[2] <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(3, aRemulosLocations[3].m_fX, aRemulosLocations[3].m_fY, aRemulosLocations[3].m_fZ);
                            if (!m_bReturnInitialPosition)
                                m_uiTabMovementsTimer[3] = 5000;
                            else
                                m_uiTabMovementsTimer[1] = 1000;
                            m_uiTabMovementsTimer[2] = 0;
                        }
                        else
                            m_uiTabMovementsTimer[2] -= uiDiff;
                    }

                    if (m_uiTabMovementsTimer[3])
                    {
                        if (m_uiTabMovementsTimer[3] <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(4, aRemulosLocations[4].m_fX, aRemulosLocations[4].m_fY, aRemulosLocations[4].m_fZ);
                            m_uiTabMovementsTimer[4] = 4000;
                            m_uiTabMovementsTimer[3] = 0;
                        }
                        else
                            m_uiTabMovementsTimer[3] -= uiDiff;
                    }

                    if (m_uiTabMovementsTimer[4])
                    {
                        if (m_uiTabMovementsTimer[4] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_2, m_creature, pPlayer);
                            m_uiCastSpellTimer = 7000;
                            m_uiTabMovementsTimer[4] = 0;
                        }
                        else
                            m_uiTabMovementsTimer[4] -= uiDiff;
                    }

                    if (m_uiCastSpellTimer)
                    {
                        if (m_uiCastSpellTimer <= uiDiff)
                        {
                            DoCast(m_creature, SPELL_THROW_NIGHTMARE_OBJECT);
                            m_uiSummonMalfurionTimer = 8000;
                            m_uiCastSpellTimer = 0;
                        }
                        else
                            m_uiCastSpellTimer -= uiDiff;
                    }

                    if (m_uiSummonMalfurionTimer)
                    {
                        if (m_uiSummonMalfurionTimer <= uiDiff)
                        {
                            m_creature->SummonCreature(NPC_MALFURION, 7734.575684f, -2312.118652f, 452.679504f, 0.068726f, TEMPSUMMON_TIMED_DESPAWN, 96000);
                            m_uiSummonMalfurionTimer = 0;
                            m_uiTabDialogsTimer[0] = 3000;
                        }
                        else
                            m_uiSummonMalfurionTimer -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[0])
                    {
                        if (m_uiTabDialogsTimer[0] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_3, m_creature);
                            m_uiTabDialogsTimer[0] = 0;
                            m_uiTabDialogsTimer[1] = 3000;
                        }
                        else
                            m_uiTabDialogsTimer[0] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[1])
                    {
                        if (m_uiTabDialogsTimer[1] <= uiDiff)
                        {
                            if (Creature* pMalfurion = m_creature->GetMap()->GetCreature(m_uiMalfurionGUID))
                            {
                                DoScriptText(SAY_MALFURION_1, pMalfurion);
                                m_uiTabDialogsTimer[1] = 0;
                                m_uiTabDialogsTimer[2] = 8000;
                            }
                        }
                        else
                            m_uiTabDialogsTimer[1] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[2])
                    {
                        if (m_uiTabDialogsTimer[2] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_4, m_creature);
                            m_uiTabDialogsTimer[2] = 0;
                            m_uiTabDialogsTimer[3] = 13000;
                        }
                        else
                            m_uiTabDialogsTimer[2] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[3])
                    {
                        if (m_uiTabDialogsTimer[3] <= uiDiff)
                        {
                            if (Creature* pMalfurion = m_creature->GetMap()->GetCreature(m_uiMalfurionGUID))
                            {
                                DoScriptText(SAY_MALFURION_2, pMalfurion);
                                m_uiTabDialogsTimer[3] = 0;
                                m_uiTabDialogsTimer[4] = 16000;
                            }
                        }
                        else
                            m_uiTabDialogsTimer[3] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[4])
                    {
                        if (m_uiTabDialogsTimer[4] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_5, m_creature);
                            m_uiTabDialogsTimer[4] = 0;
                            m_uiTabDialogsTimer[5] = 10000;
                        }
                        else
                            m_uiTabDialogsTimer[4] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[5])
                    {
                        if (m_uiTabDialogsTimer[5] <= uiDiff)
                        {
                            if (Creature* pMalfurion = m_creature->GetMap()->GetCreature(m_uiMalfurionGUID))
                            {
                                DoScriptText(SAY_MALFURION_3, pMalfurion);
                                m_uiTabDialogsTimer[5] = 0;
                                m_uiTabDialogsTimer[6] = 11000;
                            }
                        }
                        else
                            m_uiTabDialogsTimer[5] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[5])
                    {
                        if (m_uiTabDialogsTimer[5] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_6, m_creature);
                            m_uiTabDialogsTimer[5] = 0;
                            m_uiTabDialogsTimer[6] = 15000;
                        }
                        else
                            m_uiTabDialogsTimer[5] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[6])
                    {
                        if (m_uiTabDialogsTimer[6] <= uiDiff)
                        {
                            if (Creature* pMalfurion = m_creature->GetMap()->GetCreature(m_uiMalfurionGUID))
                            {
                                DoScriptText(SAY_MALFURION_4, pMalfurion);
                                m_uiTabDialogsTimer[6] = 0;
                                m_uiTabDialogsTimer[7] = 21000;
                            }
                        }
                        else
                            m_uiTabDialogsTimer[6] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[7])
                    {
                        if (m_uiTabDialogsTimer[7] <= uiDiff)
                        {
                            if (Creature* pMalfurion = m_creature->GetMap()->GetCreature(m_uiMalfurionGUID))
                            {
                                DoScriptText(SAY_MALFURION_5, pMalfurion);
                                m_uiTabDialogsTimer[7] = 0;
                                m_uiTabDialogsTimer[8] = 12000;
                            }
                        }
                        else
                            m_uiTabDialogsTimer[7] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[8])
                    {
                        if (m_uiTabDialogsTimer[8] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_7, m_creature);
                            m_uiTabDialogsTimer[8] = 0;
                            m_uiTabDialogsTimer[9] = 9000;
                        }
                        else
                            m_uiTabDialogsTimer[8] -= uiDiff;
                    }

                    if (m_uiTabDialogsTimer[9])
                    {
                        if (m_uiTabDialogsTimer[9] <= uiDiff)
                        {
                            DoScriptText(SAY_REMULOS_8, m_creature);
                            m_uiTabDialogsTimer[9] = 0;
                            m_bReturnInitialPosition = true;
                            m_uiTabMovementsTimer[2] = 7000;
                        }
                        else
                            m_uiTabDialogsTimer[9] -= uiDiff;
                    }

                    if (m_uiInitialPositionTimer)
                    {
                        if (m_uiInitialPositionTimer <= uiDiff)
                        {
                            m_creature->GetMotionMaster()->MovePoint(5, aRemulosLocations[5].m_fX, aRemulosLocations[5].m_fY, aRemulosLocations[5].m_fZ);
                            m_uiInitialPositionTimer = 0;
                            m_uiQuestComplete = 11000;
                        }
                        else
                            m_uiInitialPositionTimer -= uiDiff;
                    }
                    if (m_uiQuestComplete)
                    {
                        if (m_uiQuestComplete <= uiDiff)
                        {
                            m_creature->NearTeleportTo(m_creature->GetHomePosition());
                            if (pPlayer->GetQuestStatus(QUEST_WAKING_LEGENDS) == QUEST_STATUS_INCOMPLETE)
                                pPlayer->GroupEventHappens(QUEST_WAKING_LEGENDS, m_creature);
                            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            m_creature->ForcedDespawn();
                            m_creature->Respawn();
                            m_uiQuestComplete = 0;
                            m_idQuestActive = 0;
                        }
                        else
                            m_uiQuestComplete -= uiDiff;
                    }
                }
            }
        }
    }
};

CreatureAI* GetAI_npc_keeper_remulos(Creature* pCreature)
{
    return new npc_keeper_remulosAI(pCreature);
}

bool QuestAccept_npc_keeper_remulos(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    m_idQuestActive = pQuest->GetQuestId();

    if (pQuest->GetQuestId() == QUEST_NIGHTMARE_MANIFESTS)
    {
        // avoid starting the escort twice
        pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        if (npc_keeper_remulosAI* pEscortAI = dynamic_cast<npc_keeper_remulosAI*>(pCreature->AI()))
        {
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
            pEscortAI->SetMaxPlayerDistance(0);
        }
    }
    if (pQuest->GetQuestId() == QUEST_WAKING_LEGENDS)
    {
        pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        if (npc_keeper_remulosAI* pEscortAI = dynamic_cast<npc_keeper_remulosAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
    }

    return true;
}

bool EffectDummyCreature_conjure_rift(WorldObject* pCaster, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget)
{
    //always check spellid and effectindex
    if (uiSpellId == SPELL_CONJURE_RIFT && uiEffIndex == EFFECT_INDEX_0)
    {
        pCaster->SummonCreature(NPC_ERANIKUS_TYRANT, aEranikusLocations[0].m_fX, aEranikusLocations[0].m_fY, aEranikusLocations[0].m_fZ, aEranikusLocations[0].m_fO, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);

        //always return true when we are handling this spell and effect
        return true;
    }

    return false;
}

/*######
 ## boss_eranikus
 ######*/

enum EranikusData
{
    NPC_KEEPER_REMULOS = 11832,

    SPELL_ACID_BREATH       = 24839,
    SPELL_NOXIOUS_BREATH    = 24818,
    SPELL_SHADOWBOLT_VOLLEY = 25586,
    SPELL_ARCANE_CHANNELING = 23017, // used by Tyrande - not sure if it's the right id

    FACTION_FRIENDLY = 35,
    MAX_PRIESTESS    = 7,

    POINT_ID_TYRANDE_HEAL       = 5, // 0,
    POINT_ID_TYRANDE_ABSOLUTION = 6, // 1,
};

struct boss_eranikusAI : public ScriptedAI
{
    boss_eranikusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiAcidBreathTimer;
    uint32 m_uiNoxiousBreathTimer;
    uint32 m_uiShadowboltVolleyTimer;
    uint32 m_uiEventTimer;
    uint32 m_uiTyrandeMoveTimer;

    uint8 m_uiEventPhase;
    uint8 m_uiTyrandeMovePoint;
    uint8 m_uiHealthCheck;

    ObjectGuid m_uiRemulosGUID;
    ObjectGuid m_uiTyrandeGUID;
    std::list<uint64> m_lPriestessList;

    void Reset() override
    {
        m_uiAcidBreathTimer = 10000;
        m_uiNoxiousBreathTimer = 3000;
        m_uiShadowboltVolleyTimer = 5000;
        m_uiTyrandeMoveTimer = 0;

        m_uiRemulosGUID.Clear();
        m_uiTyrandeGUID.Clear();

        m_uiHealthCheck = 85;
        m_uiEventPhase = 0;
        m_uiEventTimer = 0;

        // For some reason the boss doesn't move in combat
        SetCombatMovement(false);
    }

    void EnterEvadeMode() override
    {
        if (m_creature->GetHealthPercent() < 20.0f)
        {
            m_creature->RemoveAllAuras();
            m_creature->DeleteThreatList();
            m_creature->CombatStop(true);
            m_creature->LoadCreatureAddon(true);

            m_creature->SetLootRecipient(nullptr);

            // Get Remulos guid and make him stop summoning shades
            if (Creature* pRemulos = GetClosestCreatureWithEntry(m_creature, NPC_REMULOS, 50.0f))
            {
                m_uiRemulosGUID = pRemulos->GetObjectGuid();
                pRemulos->AI()->EnterEvadeMode();
                pRemulos->RemoveAllAuras();
                pRemulos->DeleteThreatList();
                pRemulos->CombatStop(true);
            }

            // Despawn the priestess
            DoDespawnSummoned();

            // redeem eranikus
            m_uiEventTimer = 5000;
            m_creature->SetFactionTemplateId(FACTION_FRIENDLY);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
        }
        else
        {
            // There may be a core issue related to the reached home function for summoned creatures so we are cleaning things up here
            // if the creature evades while the event is in progress then we despawn all the summoned, including himself
            m_creature->ForcedDespawn();
            DoDespawnSummoned();

            if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                pTyrande->ForcedDespawn();
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() != TYPEID_PLAYER)
            return;

        DoScriptText(SAY_ERANIKUS_KILL, m_creature);
    }

    void DoSummonHealers()
    {
        float fX, fY, fZ;
        for (uint8 j = 0; j < MAX_PRIESTESS; ++j)
        {
            m_creature->GetRandomPoint(aTyrandeLocations[0].m_fX, aTyrandeLocations[0].m_fY, aTyrandeLocations[0].m_fZ, 10.0f, fX, fY, fZ);
            m_creature->SummonCreature(NPC_ELUNE_PRIESTESS, fX, fY, fZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_TYRANDE_WHISPERWIND:
                m_uiTyrandeGUID = pSummoned->GetObjectGuid();
                //pSummoned->GetMotionMaster()->MovePoint(POINT_ID_TYRANDE_HEAL, aTyrandeLocations[1].m_fX, aTyrandeLocations[1].m_fY, aTyrandeLocations[1].m_fZ);
                pSummoned->GetMotionMaster()->MovePoint(1, aTyrandeLocations[1].m_fX, aTyrandeLocations[1].m_fY, aTyrandeLocations[1].m_fZ, MOVE_PATHFINDING | MOVE_RUN_MODE);
                break;
            case NPC_ELUNE_PRIESTESS:
                m_lPriestessList.push_back(pSummoned->GetObjectGuid());
                float fX, fY, fZ;
                m_creature->GetRandomPoint(aTyrandeLocations[1].m_fX, aTyrandeLocations[1].m_fY, aTyrandeLocations[1].m_fZ, 10.0f, fX, fY, fZ);
                //pSummoned->GetMotionMaster()->MovePoint(POINT_ID_TYRANDE_HEAL, fX, fY, fZ);
                pSummoned->GetMotionMaster()->MovePoint(1, fX, fY, fZ, MOVE_PATHFINDING | MOVE_RUN_MODE);
                pSummoned->SetFactionTemplateId(495);//Alita : works out ^^'. 495 is an escort faction
                break;
        }
    }

    void DoDespawnSummoned()
    {
        for (auto& guid : m_lPriestessList)
        {
            if (Creature* creature = m_creature->GetMap()->GetCreature(guid))
            {
                creature->ForcedDespawn();
            }
        }
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiPointId) //TODO : ADDWAYPOINTS TO priestesses & tyrande
        {
            case 1:
                if (pSummoned->GetEntry() == NPC_TYRANDE_WHISPERWIND || pSummoned->GetEntry() == NPC_ELUNE_PRIESTESS)
                    pSummoned->GetMotionMaster()->MovePoint(3, aTyrandeLocations[3].m_fX, aTyrandeLocations[3].m_fY, aTyrandeLocations[3].m_fZ);
                break;
            case 2:
            case 3:
                if (pSummoned->GetEntry() == NPC_TYRANDE_WHISPERWIND || pSummoned->GetEntry() == NPC_ELUNE_PRIESTESS)
                    pSummoned->GetMotionMaster()->MovePoint(uiPointId + 1, aTyrandeLocations[uiPointId + 1].m_fX, aTyrandeLocations[uiPointId + 1].m_fY, aTyrandeLocations[uiPointId + 1].m_fZ, MOVE_PATHFINDING | MOVE_RUN_MODE);
                break;
            case 4:
                if (pSummoned->GetEntry() == NPC_TYRANDE_WHISPERWIND)
                    pSummoned->GetMotionMaster()->MovePoint(POINT_ID_TYRANDE_HEAL, aTyrandeLocations[5].m_fX, aTyrandeLocations[5].m_fY, aTyrandeLocations[5].m_fZ, MOVE_PATHFINDING | MOVE_RUN_MODE);
                else if (pSummoned->GetEntry() == NPC_ELUNE_PRIESTESS)
                {
                    pSummoned->Unmount();//they don't unmount well.
                    float fX, fY, fZ;
                    m_creature->GetRandomPoint(aTyrandeLocations[5].m_fX, aTyrandeLocations[5].m_fY, aTyrandeLocations[5].m_fZ, 5.0f, fX, fY, fZ);
                    pSummoned->GetMotionMaster()->MovePoint(POINT_ID_TYRANDE_HEAL, fX, fY, fZ, MOVE_PATHFINDING);
                }
                break;
            case POINT_ID_TYRANDE_HEAL:
                if (pSummoned->GetEntry() == NPC_TYRANDE_WHISPERWIND)
                {
                    // Unmont, yell and prepare to channel the spell on Eranikus
                    DoScriptText(SAY_TYRANDE_HEAL, pSummoned);
                    pSummoned->Unmount();
                    m_uiTyrandeMoveTimer = 5000;
                }
                // Unmount the priestess - unk what is their exact purpose (maybe healer)
                else if (pSummoned->GetEntry() == NPC_ELUNE_PRIESTESS)
                {
                    pSummoned->Unmount();
                    if (m_creature->GetHealthPercent() > 20)
                        pSummoned->AI()->AttackStart(m_creature); // should just focus on healing really
                    pSummoned->Unmount();//last try... just unmount pretty please?
                }
                break;
            case POINT_ID_TYRANDE_ABSOLUTION:
                if (pSummoned->GetEntry() == NPC_TYRANDE_WHISPERWIND)
                {
                    pSummoned->CastSpell(pSummoned, SPELL_ARCANE_CHANNELING, false);
                    DoScriptText(SAY_TYRANDE_FORGIVEN_1, pSummoned);
                }
                break;
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE || uiPointId != POINT_ID_ERANIKUS_REDEEMED)
            return;

        DoScriptText(SAY_REDEEMED_1, m_creature);
        m_uiEventTimer = 11000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiEventTimer)
        {
            if (m_uiEventTimer <= uiDiff)
            {
                switch (m_uiEventPhase)
                {
                    case 0:
                        // Eranikus is redeemed - make Tyrande kneel and stop casting
                        if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                        {
                            pTyrande->InterruptNonMeleeSpells(false);
                            pTyrande->SetStandState(UNIT_STAND_STATE_KNEEL);
                            DoScriptText(EMOTE_TYRANDE_KNEEL, pTyrande);
                        }
                        // Note: this emote was a world wide yellow emote before WotLK
                        //DoScriptText(EMOTE_ERANIKUS_REDEEM, m_creature);
                        sWorld.SendWorldText(EMOTE_ERANIKUS_REDEEM, m_creature->GetName());
                        //DoCastSpellIfCan(m_creature, SPELL_MOONGLADE_TRANQUILITY); // spell id unk for the moment
                        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
                        m_uiEventTimer = 5000;
                        break;
                    case 1:
                        if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                            DoScriptText(SAY_TYRANDE_REDEEMED, pTyrande);
                        m_uiEventTimer = 6000;
                        break;
                    case 2:
                        // Transform Eranikus into elf
                        DoCastSpellIfCan(m_creature, SPELL_ERANIKUS_REDEEMED);
                        m_uiEventTimer = 5000;
                        break;
                    case 3:
                        // Move Eranikus in front of Tyrande
                        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                        m_creature->GetMotionMaster()->MovePoint(POINT_ID_ERANIKUS_REDEEMED, aEranikusLocations[3].m_fX, aEranikusLocations[3].m_fY, aEranikusLocations[3].m_fZ);
                        m_uiEventTimer = 0;
                        break;
                    case 4:
                        DoScriptText(SAY_REDEEMED_2, m_creature);
                        m_uiEventTimer = 11000;
                        break;
                    case 5:
                        DoScriptText(SAY_REDEEMED_3, m_creature);
                        m_uiEventTimer = 13000;
                        break;
                    case 6:
                        DoScriptText(SAY_REDEEMED_4, m_creature);
                        m_uiEventTimer = 7000;
                        break;
                    case 7:
                        // Complete Quest and end event
                        if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                        {
                            pTyrande->SetStandState(UNIT_STAND_STATE_STAND);
                            pTyrande->ForcedDespawn(9000);
                        }
                        if (Creature* pRemulos = m_creature->GetMap()->GetCreature(m_uiRemulosGUID))
                            ((npc_keeper_remulosAI*)pRemulos->AI())->DoHandleOutro(m_creature);
                        m_creature->HandleEmote(EMOTE_ONESHOT_BOW);
                        m_creature->ForcedDespawn(2000);
                        break;
                }
                ++m_uiEventPhase;
            }
            else
                m_uiEventTimer -= uiDiff;
        }

        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        //Alita : make sure he prefers targets he can hit. TO REMOVE WHEN AGGRO MECANICS WILL DO THE JOB.
        Unit* pTarget = m_creature->GetVictim();

        if (!m_creature->CanReachWithMeleeAutoAttack(pTarget))
        {
            ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
            for (const auto itr : tList)
            {
                if (Unit* pAttacker = m_creature->GetMap()->GetUnit(itr->getUnitGuid()))
                    if (m_creature->CanReachWithMeleeAutoAttack(pAttacker))
                        m_creature->GetThreatManager().modifyThreatPercent(pAttacker, 5);
            }
        }
        // Move Tyrande after she is summoned
        if (m_uiTyrandeMoveTimer)
        {
            if (m_uiTyrandeMoveTimer <= uiDiff)
            {
                if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                    pTyrande->GetMotionMaster()->MovePoint(POINT_ID_TYRANDE_ABSOLUTION, aTyrandeLocations[6].m_fX, aTyrandeLocations[6].m_fY, aTyrandeLocations[6].m_fZ);
                m_uiTyrandeMoveTimer = 0;
            }
            else
                m_uiTyrandeMoveTimer -= uiDiff;
        }

        // Not sure if this should be handled by health percent, but this is the only reasonable way
        if (m_creature->GetHealthPercent() < m_uiHealthCheck)
        {
            switch (m_uiHealthCheck)
            {
                case 85:
                    DoScriptText(SAY_ERANIKUS_ATTACK_3, m_creature);
                    m_creature->SummonCreature(NPC_TYRANDE_WHISPERWIND, aTyrandeLocations[0].m_fX, aTyrandeLocations[0].m_fY, aTyrandeLocations[0].m_fZ, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                        DoScriptText(SAY_TYRANDE_APPEAR, pTyrande);
                    m_uiHealthCheck = 83; // priestess' should arrive a moment after Tyrande - hacks :(
                    break;
                case 83:
                    // Summon the priestess
                    DoSummonHealers();
                    m_uiHealthCheck = 75;
                    break;
                case 75:
                    // Eranikus yells again
                    DoScriptText(SAY_ERANIKUS_ATTACK_3, m_creature);
                    m_uiHealthCheck = 35;
                    break;
                case 35:
                    DoScriptText(SAY_ERANIKUS_DEFEAT_1, m_creature);
                    m_uiHealthCheck = 31;
                    break;
                case 31:
                    if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                        DoScriptText(SAY_TYRANDE_FORGIVEN_2, pTyrande);
                    m_uiHealthCheck = 27;
                    break;
                case 27:
                    if (Creature* pTyrande = m_creature->GetMap()->GetCreature(m_uiTyrandeGUID))
                        DoScriptText(SAY_TYRANDE_FORGIVEN_3, pTyrande);
                    m_uiHealthCheck = 25;
                    break;
                case 25:
                    DoScriptText(SAY_ERANIKUS_DEFEAT_2, m_creature);
                    m_uiHealthCheck = 20;
                    break;
                case 20:
                    // Eranikus is redeemed - stop the fight
                    DoScriptText(SAY_ERANIKUS_DEFEAT_3, m_creature);
                    m_creature->AI()->EnterEvadeMode();
                    m_uiHealthCheck = 0;
                    break;
            }
        }

        // Combat spells
        if (m_uiAcidBreathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ACID_BREATH) == CAST_OK)
                m_uiAcidBreathTimer = 15000;
        }
        else
            m_uiAcidBreathTimer -= uiDiff;

        if (m_uiNoxiousBreathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_NOXIOUS_BREATH) == CAST_OK)
                m_uiNoxiousBreathTimer = 30000;
        }
        else
            m_uiNoxiousBreathTimer -= uiDiff;

        if (m_uiShadowboltVolleyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SHADOWBOLT_VOLLEY) == CAST_OK)
                m_uiShadowboltVolleyTimer = 25000;
        }
        else
            m_uiShadowboltVolleyTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_eranikus(Creature* pCreature)
{
    return new boss_eranikusAI(pCreature);
}

void AddSC_moonglade()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_great_bear_spirit";
    pNewScript->pGossipHello =  &GossipHello_npc_great_bear_spirit;
    pNewScript->pGossipSelect = &GossipSelect_npc_great_bear_spirit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_keeper_remulos";
    pNewScript->GetAI = &GetAI_npc_keeper_remulos;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_keeper_remulos;
    pNewScript->pEffectDummyCreature = &EffectDummyCreature_conjure_rift;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_eranikus";
    pNewScript->GetAI = &GetAI_boss_eranikus;
    pNewScript->RegisterSelf();
}
