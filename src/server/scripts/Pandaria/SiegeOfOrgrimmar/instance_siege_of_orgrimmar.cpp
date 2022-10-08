/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "siege_of_orgrimmar.hpp"

Position npcAfterShaOfPridePos2[7] =
{
    { 750.75f, 1131.48f, 356.08f, 1.73f}, // Jaina
    { 740.28f, 1129.70f, 356.08f, 1.73f}, // Lor'themar
    { 744.46f, 1134.51f, 356.08f, 1.73f}, // Gorehowl
    { 785.54f, 1171.07f, 356.08f, 4.14f}, // Portal to Orgrimmar (alliance)
    { 782.49f, 1165.84f, 356.08f, 0.82f}, // Jaina near portal
    { 688.79f, 1151.24f, 356.08f, 5.81f}, // Portal to Orgrimmar (horde)
    { 695.27f, 1146.95f, 356.08f, 2.62f}  // Lor'themar near portal
};

Position galakrasPlayersPos2[3] =
{
    { 1366.50f, -5416.54f, 10.47f, 1.59f}, // alliance intro position
    { 1767.58f, -5265.74f, 6.97f, 2.90f},  // horde intro position
    { 1440.49f, -5015.87f, 12.11f, 1.67f}  // position at the docks
};

Position norushenTeleportPos = { 800.0f, 866.0f, 371.1f, 1.82f };
Position immersusTeleportPos = { 1459.0883f, 1037.2127f, 340.2553f, 3.12f };
Position afterIronJuggernautPos = { 1384.97f, -4369.95f, 25.80f, 0.15f };
Position afterGeneralNazgrimPos = { 1799.07f, -4779.58f, -255.24f, 5.31f };
Position afterMalkorokPos = { 1982.62f, -5177.68f, -271.88f, 3.74f };
Position afterParagonsPos = { 1494.18f, -5744.90f, -306.73f, 3.72f };

DoorData const doorData[] =
{
    {GO_IMMERSEUS_DOOR,          DATA_IMMERSEUS,          DOOR_TYPE_PASSAGE},
    {GO_SHA_ENERGY_WALL,         DATA_FALLEN_PROTECTORS,  DOOR_TYPE_PASSAGE},
    {GO_NORUSHEN_EXIT,           DATA_NORUSHEN,           DOOR_TYPE_PASSAGE},
    {GO_PRIDE_ENTRANCE,          DATA_SHA_OF_PRIDE,       DOOR_TYPE_ROOM},
    {GO_WIND_DOOR,               DATA_IRON_JUGGERNAUT,    DOOR_TYPE_ROOM},
    // temporary hack untill we scripts the event
    {GO_ORGRIMMAR_FRONT_GATE,    DATA_IRON_JUGGERNAUT,    DOOR_TYPE_PASSAGE},
    {GO_GATES_OF_ORGRIMMAR,      DATA_IRON_JUGGERNAUT,    DOOR_TYPE_PASSAGE},
    {GO_OGRAID_FRONT_GATE_BACK,  DATA_KORKRON_DARK_SHAMANS, DOOR_TYPE_ROOM},
    {GO_RUSTED_IRON_PORTCULLIS,  DATA_KORKRON_DARK_SHAMANS, DOOR_TYPE_PASSAGE},
    {GO_NAZGRIM_ENTRY_DOOR,      DATA_GENERAL_NAZGRIM,    DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_1,DATA_GENERAL_NAZGRIM,    DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_4,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_5,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_2,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_2,DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_6,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_6,DATA_SIEGECRAFTER_BLACKFUSE,DOOR_TYPE_ROOM},
    {GO_IRON_GATE_OUT_1,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_2,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_3,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_4,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_3,DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_OGRAID_LARGE_DOOR,       DATA_THOK_THE_BLOODTHIRSTY,DOOR_TYPE_ROOM},
    ///< To open this door both data required
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_SIEGECRAFTER_BLACKFUSE,DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_THOK_THE_BLOODTHIRSTY, DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_SPOILS_OF_PANDARIA,    DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_PARAGONS_OF_THE_KLAXXI,DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_8,DATA_PARAGONS_OF_THE_KLAXXI,DOOR_TYPE_PASSAGE},
    {GO_ENTRANCE_1,              DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_ENTRANCE_2,              DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_SANCTUM_DOOR,            DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_SOUTH_EAST_DOOR,         DATA_GARROSH_HELLSCREAM, DOOR_TYPE_SPAWN_HOLE},
    {GO_SOUTH_WEST_DOOR,         DATA_GARROSH_HELLSCREAM, DOOR_TYPE_SPAWN_HOLE},
    {0,                                      0,           DOOR_TYPE_ROOM},// END
};

void ApplySpellToPlayersInRange(Unit* searcher, uint32 spellId, float range, bool isAura)
{
    std::list<Player*> players;
    searcher->GetPlayerListInGrid(players, range);

    if (!players.empty())
    {
        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = (*itr);

            // 'GetPlayerListInGrid' check 'GetDistance' but not 'GetExactDistance'
            if (searcher->GetExactDist(player) > range)
                continue;

            if (isAura)
            {
                if (player->HasAura(spellId))
                    continue;

                searcher->AddAura(spellId, player);
            }
            else
            {
                searcher->CastSpell(player, spellId, true);
            }
        }
    }
}

CombatAuraHelper::CombatAuraHelper(Creature* owner) :
m_Owner(owner), m_CombatAurasTimer(5000)
{
}

void CombatAuraHelper::RegisterCombatAura(uint32 spellId)
{
    m_CombatAuras.push_back(spellId);
}

void CombatAuraHelper::UnregisterCombatAura(uint32 p_SpellId)
{
    m_CombatAuras.remove(p_SpellId);
}

void CombatAuraHelper::UpdateCombatAuras(const uint32 diff)
{
    if (!m_Owner->IsInCombat())
        return;

    if (m_CombatAurasTimer <= diff)
    {
        m_CombatAurasTimer = 10000;

        std::list<HostileReference*> const& threatlist = m_Owner->getThreatManager().getThreatList();
        if (threatlist.empty())
            return;

        for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        {
            for (const auto spellId : m_CombatAuras)
            {
                Unit* target = (*itr)->getTarget();
                if (target && !target->HasAura(spellId))
                {
                    m_Owner->AddAura(spellId, target);
                }
            }
        }
    }
    else
    {
        m_CombatAurasTimer -= diff;
    }
}

struct instance_siege_of_orgrimmar : public InstanceScript
{
    instance_siege_of_orgrimmar(InstanceMap* map) : InstanceScript(map)
    {
        teamInInstance = 0;
        firstGalakrasIntroDone = false;
        secondGalakrasIntroDone = false;
        destroyedCannonsCount = 0;
    }

    void Initialize()
    {
        SetBossNumber(DATA_MAX_BOSS_DATA);
        LoadDoorData(doorData);

        immerseusGuid = ObjectGuid::Empty;
        swirlTargetGuid = ObjectGuid::Empty;

        pressurePlateGuid = ObjectGuid::Empty;
        pressurePlateDoorGuid = ObjectGuid::Empty;

        for (uint8 i = 0; i < MAX_FALLEN_PROTECTORS; ++i)
            fallenProtectorsGuid[i] = ObjectGuid::Empty;

        norushenGuid = ObjectGuid::Empty;
        amalgamOfCorruptionGuid = ObjectGuid::Empty;
        shaOfPrideGuid = ObjectGuid::Empty;
        shaOfPrideNorushenGuid = ObjectGuid::Empty;
        galakrasGuid = ObjectGuid::Empty;
        zaelaGuid = ObjectGuid::Empty;
        ironJuggernautGuid = ObjectGuid::Empty;

        for (uint8 i = 0; i < MAX_KORKRON_DARK_SHAMANS; ++i)
            korkronDarkShamansGuid[i] = ObjectGuid::Empty;

        malkorokGuid = ObjectGuid::Empty;
        spoilsOfPandariaGuid = ObjectGuid::Empty;
        thokTheBloodthirstyGuid = ObjectGuid::Empty;
        siegecrafterBlackfuseGuid = ObjectGuid::Empty;

        klaxxiParagonsGuid = ObjectGuid::Empty;
        for (uint8 i = 0; i < MAX_PARAGONS_OF_THE_KLAXXI; ++i)
            paragonsOfTheKlaxxiGuid[i] = ObjectGuid::Empty;

        //garroshHellscreamObjectGuid = ObjectGuid::Empty;

        lorewalkerCho1GUID = ObjectGuid::Empty;
        lorewalkerCho2GUID = ObjectGuid::Empty;
        vanityGUID = ObjectGuid::Empty;
        arroganceGUID = ObjectGuid::Empty;
        zealGUID = ObjectGuid::Empty;
        zealDoorGuid = ObjectGuid::Empty;

        memset(tearsOfTheValeGUIDs, 0, sizeof(tearsOfTheValeGUIDs));
        memset(shadowPrisonGuids, 0, sizeof(shadowPrisonGuids));
        for (uint8 i = 0; i < MAX_SHADOW_PRISONS; ++i)
            memset(shadowPrisonTrapGuids[i], 0, sizeof(shadowPrisonTrapGuids[i]));

        memset(lightContainmentGUIDs, 0, sizeof(lightContainmentGUIDs));

        memset(vaultOfForbiddenTreasuresGUIDs, 0, sizeof(vaultOfForbiddenTreasuresGUIDs));

        jainaProudmooreGalakrasGUID = ObjectGuid::Empty;
        kingVarianWrynnGalakrasGUID = ObjectGuid::Empty;
        lorthemarTheronGalakrasGUID = ObjectGuid::Empty;
        sylvanasWindrunnerGalakrasGUID = ObjectGuid::Empty;
        aethasSunreaverGalakrasGUID = ObjectGuid::Empty;

        voljinIronJuggernautGUID = ObjectGuid::Empty;
        baineBloodhoofIronJuggernautGUID = ObjectGuid::Empty;
        aysaCloudsingerGUID = ObjectGuid::Empty;
        jiFirepawGUID = ObjectGuid::Empty;
        overseerKomakGUID = ObjectGuid::Empty;

        memset(spoilsOfPandariaGoGUIDs, 0, sizeof(spoilsOfPandariaGoGUIDs));
        memset(spoilsOfPandariaLevers, 0, sizeof(spoilsOfPandariaLevers));

        memset(unlockedStockpileGUIDs, 0, sizeof(unlockedStockpileGUIDs));

        memset(saurokPrisonGUIDs, 0, sizeof(saurokPrisonGUIDs));
        memset(yaungolPrisonGUIDs, 0, sizeof(yaungolPrisonGUIDs));
        memset(jinyuPrisonGUIDs, 0, sizeof(jinyuPrisonGUIDs));

        thrallGuid = ObjectGuid::Empty;

        lorewalkerChoIntro = 0;
        lorewalkerChoIntroImmerseus = 0;
        zealDied = 0;
        pressurePlateEvent = 0;
        beachCaptured = 0;

        thokTheBloodthirstyIntro = 0;

        blackfuseIntro = 0;

        garroshHellscreamIntro = 0;
        garroshEnergy = 0;

        //instance->SetVisibilityRange(200.0f);
    }

    void OnPlayerEnter(Player* player)
    {
        ///< TODO: make this code generic
        ///< TODO: use pos from WorldSafeLocs.dbc

        if (!teamInInstance)
            teamInInstance = player->GetTeam();

        const static uint32 options = TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET;

        Position const* pos = nullptr;

        if (GetBossState(DATA_PARAGONS_OF_THE_KLAXXI) == DONE)
            pos = &afterParagonsPos;
        else if (GetBossState(DATA_MALKOROK) == DONE)
            pos = &afterMalkorokPos;
        else if (GetBossState(DATA_GENERAL_NAZGRIM) == DONE)
            pos = &afterGeneralNazgrimPos;
        else if (GetBossState(DATA_IRON_JUGGERNAUT) == DONE)
            pos = &afterIronJuggernautPos;
        else if (GetBossState(DATA_GALAKRAS) == DONE)
            pos = &galakrasPlayersPos2[2];
        else if (GetBossState(DATA_SHA_OF_PRIDE) == DONE)
        {
            if (IsAllianceInstance())
                pos = &galakrasPlayersPos2[0];
            else if (IsHordeInstance())
                pos = &galakrasPlayersPos2[1];

            SetData(DATA_FIRST_GALAKRAS_INTRO, DONE);
        }
        else if (GetBossState(DATA_FALLEN_PROTECTORS) == DONE && GetData(DATA_ZEAL) == DONE)
            pos = &norushenTeleportPos;
        else if (GetBossState(DATA_IMMERSEUS) == DONE)
            pos = &immersusTeleportPos;

        if (pos)
            player->TeleportTo(player->GetMapId(), pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation(), options);

        // Preload npc
        // General Nazgrim
        instance->LoadGrid(1631.f, -4662.f);
    }

    void OnCreatureCreate(Creature* creature)
    {
        ///< All SoO bosses should have immunity to disarm
        if (creature->IsDungeonBoss())
        {
            creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            creature->ApplySpellImmune(0, IMMUNITY_ID, 102051, true);
        }

        switch (creature->GetEntry())
        {
        case NPC_IMMERSEUS:
            immerseusGuid = creature->GetGUID();
            break;
        case NPC_SWIRL_TARGET:
            swirlTargetGuid = creature->GetGUID();
            break;
        case NPC_PRESSURE_PLATE:
            pressurePlateGuid = creature->GetGUID();
            break;
        case NPC_ROOK_STONETOE:
            fallenProtectorsGuid[0] = creature->GetGUID();
            break;
        case NPC_HE_SOFTFOOT:
            fallenProtectorsGuid[1] = creature->GetGUID();
            break;
        case NPC_SUN_THUNDERHEART:
            fallenProtectorsGuid[2] = creature->GetGUID();
            break;
        case NPC_NORUSHEN:
            norushenGuid = creature->GetGUID();
            break;
        case NPC_AMALGAM_OF_CORRUPTION:
            amalgamOfCorruptionGuid = creature->GetGUID();
            break;
        case NPC_SHA_OF_PRIDE:
            shaOfPrideGuid = creature->GetGUID();
            break;
        case NPC_NORUSHEN_1:
            shaOfPrideNorushenGuid = creature->GetGUID();
            break;
        case NPC_GALAKRAS:
            galakrasGuid = creature->GetGUID();
            break;
        case NPC_WARLORD_ZAELA:
            zaelaGuid = creature->GetGUID();
            break;
        case NPC_JAINA_PROUDMOORE_2:
            jainaProudmooreGalakrasGUID = creature->GetGUID();
            break;
        case NPC_KING_VARIAN_WRYNN_2:
            kingVarianWrynnGalakrasGUID = creature->GetGUID();
            break;
        case NPC_LORTHEMAR_THERON_2:
            lorthemarTheronGalakrasGUID = creature->GetGUID();
            break;
        case NPC_SYLVANAS_WINDRUNNER_2:
            sylvanasWindrunnerGalakrasGUID = creature->GetGUID();
            break;
        case NPC_AETHAS_SUNREAVER:
            aethasSunreaverGalakrasGUID = creature->GetGUID();
            break;
        case NPC_IRON_JUGGERNAUT:
            ironJuggernautGuid = creature->GetGUID();
            break;
        case NPC_VOLJIN_1:
            voljinIronJuggernautGUID = creature->GetGUID();
            break;
        case NPC_BAINE_BLOODHOOF_1:
            baineBloodhoofIronJuggernautGUID = creature->GetGUID();
            break;
        case NPC_EARTHBREAKER_HAROMM:
            korkronDarkShamansGuid[0] = creature->GetGUID();
            break;
        case NPC_WAVEBINDER_KARDIS:
            korkronDarkShamansGuid[1] = creature->GetGUID();
            break;
        case NPC_AYSA_CLOUDSINGER:
            aysaCloudsingerGUID = creature->GetGUID();
            break;
        case NPC_JI_FIREPAW:
            jiFirepawGUID = creature->GetGUID();
            break;
        case NPC_OVERSEER_KOMAK:
            overseerKomakGUID = creature->GetGUID();
            break;
        case NPC_GENERAL_NAZGRIM:
            generalNazgrimGuid = creature->GetGUID();
            break;
        case NPC_MALKOROK:
            malkorokGuid = creature->GetGUID();
            break;
        case NPC_SECURED_STOCKPILE_OF_PANDAREN_SPOILS:
            spoilsOfPandariaGuid = creature->GetGUID();
            break;
        case NPC_THOK_THE_BLOODTHIRSTY:
            thokTheBloodthirstyGuid = creature->GetGUID();
            break;
        case NPC_SIEGECRAFTER_BLACKFUSE:
            siegecrafterBlackfuseGuid = creature->GetGUID();
            break;
        case NPC_KLAXXI_PARAGONS:
            klaxxiParagonsGuid = creature->GetGUID();
            break;
        case NPC_KILRUK_THE_WIND_REAVER:
            paragonsOfTheKlaxxiGuid[0] = creature->GetGUID();
            break;
        case NPC_XARIL_THE_POISONED_MIND:
            paragonsOfTheKlaxxiGuid[1] = creature->GetGUID();
            break;
        case NPC_KAZTIK_THE_MANIPULATOR:
            paragonsOfTheKlaxxiGuid[2] = creature->GetGUID();
            break;
        case NPC_KORVEN_THE_PRIME:
            paragonsOfTheKlaxxiGuid[3] = creature->GetGUID();
            break;
        case NPC_IYYOKUK_THE_LUCID:
            paragonsOfTheKlaxxiGuid[4] = creature->GetGUID();
            break;
        case NPC_KAROZ_THE_LOCUST:
            paragonsOfTheKlaxxiGuid[5] = creature->GetGUID();
            break;
        case NPC_SKEER_THE_BLOODSEEKER:
            paragonsOfTheKlaxxiGuid[6] = creature->GetGUID();
            break;
        case NPC_RIKKAL_THE_DISSECTOR:
            paragonsOfTheKlaxxiGuid[7] = creature->GetGUID();
            break;
        case NPC_HISEK_THE_SWARMKEEPER:
            paragonsOfTheKlaxxiGuid[8] = creature->GetGUID();
            break;
        case NPC_GARROSH_HELLSCREAM:
            garroshHellscreamGuid = creature->GetGUID();
            break;
        case NPC_LOREWALKER_CHO_1:
            if (creature->GetPositionZ() < 400.0f)
            {
                lorewalkerCho1GUID = creature->GetGUID();
            }
            else
            {
                lorewalkerCho2GUID = creature->GetGUID();
            }
            break;
        case NPC_VANITY:
            vanityGUID = creature->GetGUID();
            break;
        case NPC_ARROGANCE:
            arroganceGUID = creature->GetGUID();
            break;
        case NPC_ZEAL:
            zealGUID = creature->GetGUID();
            break;
        case NPC_THRALL_1:
            thrallGuid = creature->GetGUID();
            break;
        default:
            break;
        }
    }

    void OnCreatureRemove(Creature* creature)
    {
        // There are creatures (bosses) those are summoned by npcs
        // Reset guid accessors to be able to summon bosses again
        switch (creature->GetEntry())
        {
        case NPC_AMALGAM_OF_CORRUPTION:
            amalgamOfCorruptionGuid = ObjectGuid::Empty;
            break;
        case NPC_SHA_OF_PRIDE:
            shaOfPrideGuid = ObjectGuid::Empty;
            break;
        case NPC_SWIRL_TARGET:
            swirlTargetGuid = ObjectGuid::Empty;
            break;
        }
    }

    void OnGameObjectCreate(GameObject* go)
    {
        go->setActive(true);

        switch (go->GetEntry())
        {
        case GO_MYSTERIOUS_ORNATE_DOOR:
            zealDoorGuid = go->GetGUID();
            UpdateZealDoorState(go);
            break;
        case GO_PRESSURE_PLATE_DOOR:
            pressurePlateDoorGuid = go->GetGUID();
            UpdatePressurePlateDoorState(go);
            break;
        case GO_TEARS_OF_THE_VALE_10N:
            tearsOfTheValeGUIDs[0] = go->GetGUID();
            break;
        case GO_TEARS_OF_THE_VALE_25N:
            tearsOfTheValeGUIDs[1] = go->GetGUID();
            break;
        case GO_TEARS_OF_THE_VALE_10H:
            tearsOfTheValeGUIDs[2] = go->GetGUID();
            break;
        case GO_TEARS_OF_THE_VALE_25H:
            tearsOfTheValeGUIDs[3] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_1:
            lightContainmentGUIDs[0] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_2:
            lightContainmentGUIDs[1] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_3:
            lightContainmentGUIDs[2] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_4:
            lightContainmentGUIDs[3] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_TOP:
            lightContainmentGUIDs[4] = go->GetGUID();
            break;
        case GO_LIGHT_CONTAINMENT_BOTTOM:
            lightContainmentGUIDs[5] = go->GetGUID();
            break;
        case GO_WEST_SHADOW_PRISON:
            shadowPrisonGuids[SHADOW_PRISON_WEST] = go->GetGUID();
            break;
        case GO_NORTH_SHADOW_PRISON:
            shadowPrisonGuids[SHADOW_PRISON_NORTH] = go->GetGUID();
            break;
        case GO_EAST_SHADOW_PRISON:
            shadowPrisonGuids[SHADOW_PRISON_EAST] = go->GetGUID();
            break;
        case GO_SOUTH_SHADOW_PRISON:
            shadowPrisonGuids[SHADOW_PRISON_SOUTH] = go->GetGUID();
            break;
        case GO_WEST_SHADOW_PRISON_A:
            shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_A] = go->GetGUID();
            break;
        case GO_WEST_SHADOW_PRISON_B:
            shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_B] = go->GetGUID();
            break;
        case GO_WEST_SHADOW_PRISON_C:
            shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_C] = go->GetGUID();
            break;
        case GO_NORTH_SHADOW_PRISON_A:
            shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_A] = go->GetGUID();
            break;
        case GO_NORTH_SHADOW_PRISON_B:
            shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_B] = go->GetGUID();
            break;
        case GO_NORTH_SHADOW_PRISON_C:
            shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_C] = go->GetGUID();
            break;
        case GO_EAST_SHADOW_PRISON_A:
            shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_A] = go->GetGUID();
            break;
        case GO_EAST_SHADOW_PRISON_B:
            shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_B] = go->GetGUID();
            break;
        case GO_EAST_SHADOW_PRISON_C:
            shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_C] = go->GetGUID();
            break;
        case GO_SOUTH_SHADOW_PRISON_A:
            shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_A] = go->GetGUID();
            break;
        case GO_SOUTH_SHADOW_PRISON_B:
            shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_B] = go->GetGUID();
            break;
        case GO_SOUTH_SHADOW_PRISON_C:
            shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_C] = go->GetGUID();
            break;
        case GO_VAULT_OF_FORBIDDEN_TREASURES_10:
            vaultOfForbiddenTreasuresGUIDs[0] = go->GetGUID();
            break;
        case GO_VAULT_OF_FORBIDDEN_TREASURES_25:
            vaultOfForbiddenTreasuresGUIDs[1] = go->GetGUID();
            break;
        case GO_VAULT_OF_FORBIDDEN_TREASURES_10H:
            vaultOfForbiddenTreasuresGUIDs[2] = go->GetGUID();
            break;
        case GO_VAULT_OF_FORBIDDEN_TREASURES_25H:
            vaultOfForbiddenTreasuresGUIDs[3] = go->GetGUID();
            break;
        case GO_IRON_GATE_NORTH:
            spoilsOfPandariaGoGUIDs[0] = go->GetGUID();
            break;
        case GO_IRON_GATE_WEST:
            spoilsOfPandariaGoGUIDs[1] = go->GetGUID();
            break;
        case GO_IRON_GATE_SOUTH:
            spoilsOfPandariaGoGUIDs[2] = go->GetGUID();
            break;
        case GO_IRON_GATE_EAST:
            spoilsOfPandariaGoGUIDs[3] = go->GetGUID();
            break;
        case GO_IRON_GATE_NORTH_WEST:
            spoilsOfPandariaGoGUIDs[4] = go->GetGUID();
            break;
        case GO_IRON_GATE_SOUTH_EAST:
            spoilsOfPandariaGoGUIDs[5] = go->GetGUID();
            break;
        case GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_10:
            unlockedStockpileGUIDs[0] = go->GetGUID();
            break;
        case GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_25:
            unlockedStockpileGUIDs[1] = go->GetGUID();
            break;
        case GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_10H:
            unlockedStockpileGUIDs[2] = go->GetGUID();
            break;
        case GO_UNLOCKED_STOCKPILE_OF_PANDAREN_SPOILS_25H:
            unlockedStockpileGUIDs[3] = go->GetGUID();
            break;
        case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_NORTH:
            spoilsOfPandariaLevers[0] = go->GetGUID();
            break;
        case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_WEST:
            spoilsOfPandariaLevers[1] = go->GetGUID();
            break;
        case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_SOUTH:
            spoilsOfPandariaLevers[2] = go->GetGUID();
            break;
        case GO_DEFENSE_SYSTEM_OVERRIDE_LEVER_EAST:
            spoilsOfPandariaLevers[3] = go->GetGUID();
            break;
        case GO_SAUROK_PRISON_1:
            saurokPrisonGUIDs[0] = go->GetGUID();
            break;
        case GO_SAUROK_PRISON_2:
            saurokPrisonGUIDs[1] = go->GetGUID();
            break;
        case GO_YAUNGOL_PRISON_1:
            yaungolPrisonGUIDs[0] = go->GetGUID();
            break;
        case GO_YAUNGOL_PRISON_2:
            yaungolPrisonGUIDs[1] = go->GetGUID();
            break;
        case GO_JINYU_PRISON_1:
            jinyuPrisonGUIDs[0] = go->GetGUID();
            break;
        case GO_JINYU_PRISON_2:
            jinyuPrisonGUIDs[1] = go->GetGUID();
            break;

        case GO_IMMERSEUS_DOOR:
        case GO_SHA_ENERGY_WALL:
        case GO_NORUSHEN_EXIT:
        case GO_PRIDE_ENTRANCE:
        case GO_WIND_DOOR:
        case GO_ORGRIMMAR_FRONT_GATE:
        case GO_GATES_OF_ORGRIMMAR:
        case GO_OGRAID_FRONT_GATE_BACK:
        case GO_RUSTED_IRON_PORTCULLIS:
        case GO_NAZGRIM_ENTRY_DOOR:
        case GO_MASSIVE_IRONBOUND_DOOR_1:
        case GO_MASSIVE_IRONBOUND_DOOR_2:
        case GO_IRON_GATE_OUT_1:
        case GO_IRON_GATE_OUT_2:
        case GO_IRON_GATE_OUT_3:
        case GO_IRON_GATE_OUT_4:
        case GO_MASSIVE_IRONBOUND_DOOR_3:
        case GO_MASSIVE_IRONBOUND_DOOR_4:
        case GO_MASSIVE_IRONBOUND_DOOR_5:
        case GO_OGRAID_LARGE_DOOR:
        case GO_MASSIVE_IRONBOUND_DOOR_6:
        case GO_MASSIVE_IRONBOUND_DOOR_7:
        case GO_MASSIVE_IRONBOUND_DOOR_8:
        case GO_ENTRANCE_1:
        case GO_ENTRANCE_2:
        case GO_SOUTH_EAST_DOOR:
        case GO_SOUTH_WEST_DOOR:
            AddDoor(go, true);
            break;
        case GO_SANCTUM_DOOR:
            AddDoor(go, true);
            break;
        }
    }

    void OnGameObjectRemove(GameObject* go) override
    {
        switch (go->GetEntry())
        {
        case GO_IMMERSEUS_DOOR:
        case GO_SHA_ENERGY_WALL:
        case GO_NORUSHEN_EXIT:
        case GO_PRIDE_ENTRANCE:
        case GO_WIND_DOOR:
        case GO_ORGRIMMAR_FRONT_GATE:
        case GO_OGRAID_FRONT_GATE_BACK:
        case GO_RUSTED_IRON_PORTCULLIS:
        case GO_GATES_OF_ORGRIMMAR:
        case GO_NAZGRIM_ENTRY_DOOR:
        case GO_MASSIVE_IRONBOUND_DOOR_1:
        case GO_MASSIVE_IRONBOUND_DOOR_2:
        case GO_IRON_GATE_OUT_1:
        case GO_IRON_GATE_OUT_2:
        case GO_IRON_GATE_OUT_3:
        case GO_IRON_GATE_OUT_4:
        case GO_MASSIVE_IRONBOUND_DOOR_3:
        case GO_MASSIVE_IRONBOUND_DOOR_4:
        case GO_MASSIVE_IRONBOUND_DOOR_5:
        case GO_OGRAID_LARGE_DOOR:
        case GO_MASSIVE_IRONBOUND_DOOR_6:
        case GO_MASSIVE_IRONBOUND_DOOR_7:
        case GO_MASSIVE_IRONBOUND_DOOR_8:
        case GO_ENTRANCE_1:
        case GO_ENTRANCE_2:
        case GO_SANCTUM_DOOR:
        case GO_SOUTH_EAST_DOOR:
        case GO_SOUTH_WEST_DOOR:
            AddDoor(go, false);
            break;
        default:
            break;
        }
    }

    bool SetBossState(uint32 id, EncounterState state)
    {
        if (!InstanceScript::SetBossState(id, state))
            return false;

        switch (id)
        {
        case DATA_IMMERSEUS:
            //SetEntranceLocation(EntranceTransferLoc::PRE_GOLDEN_LOTUS);
            break;
        case DATA_FALLEN_PROTECTORS:
            /// EntranceTransferLoc::PRE_SHA - DATA_ZEAL
            break;
        case DATA_SHA_OF_PRIDE:
            if (state == DONE)
            {
                DelayedSpawnNpcAfterShaOfPride();
                //SetEntranceLocation(EntranceTransferLoc::PRE_GALAKRAS);
            }
            break;
        case DATA_GALAKRAS:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_GALAKRAS);
            break;
        case DATA_IRON_JUGGERNAUT:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_DARK_SHAMAN);
            break;
        case DATA_KORKRON_DARK_SHAMANS:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_GOLDEN_LOTUS_2);
            break;
        case DATA_GENERAL_NAZGRIM:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_MALKOROK);
            break;
        case DATA_MALKOROK:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::UNDERHOLD_NEXUS);
            break;
        case DATA_PARAGONS_OF_THE_KLAXXI:
            //if (state == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_GARROSH);
            break;
        }

        return true;
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
        case DATA_LOREWALKER_CHO_INTRO:
            lorewalkerChoIntro = data;
            break;
        case DATA_LOREWALKER_CHO_INTRO_IMMERSEUS:
            lorewalkerChoIntroImmerseus = data;
            break;
        case DATA_ZEAL:
            zealDied = data;
            UpdateZealDoorState();
            //if (data == DONE)
            //    SetEntranceLocation(EntranceTransferLoc::PRE_SHA);
            break;
        case DATA_BEACH_CAPTURED:
            beachCaptured = data;
            break;
        case DATA_FIRST_GALAKRAS_INTRO:
            DelayedFirstGalakrasIntro();
            break;
        case DATA_KORKRON_CANNON_DESTROYED:
            ProcessCannonsDestroyed();
            break;
        case DATA_START_GALAKRAS:
            StartGalakrasNpc();
            events.ScheduleEvent(EVENT_START_GALAKRAS, IsAllianceInstance() ? 35000 : 25000);
            break;
        case DATA_RESET_GALAKRAS:
            ResetGalakrasNpc();
            break;
        case DATA_IRON_JUGGERNAUT_START:
            StartIronJuggernautNpc();
            break;
        case DATA_IRON_JUGGERNAUT_DEAD:
            ProcessIronJuggernautDeadNpc();
            break;
        case DATA_ENRAGED_MUSHAN_BEAST:
            enragedMushanBeast = DONE;
            UpdateThokTheBloodthirstyIntro();
            break;
        case DATA_STARVED_YETTI:
            starvedYetti = DONE;
            UpdateThokTheBloodthirstyIntro();
            break;
        case DATA_BLACKFUSE_INTRO:
            blackfuseIntro = DONE;
            SendBlackfuseIntroToPlayers();
            break;
        case DATA_GARROSH_HELLSCREAM_INTRO:
            StartGarroshHellscreamIntro();
            break;
        case DATA_GARROSH_HELLSCREAM_ENERGY:
            garroshEnergy = data;
            break;
        }

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_TEAM_IN_INSTANCE: return teamInInstance;
        case DATA_LOREWALKER_CHO_INTRO: return lorewalkerChoIntro;
        case DATA_LOREWALKER_CHO_INTRO_IMMERSEUS: return lorewalkerChoIntroImmerseus;
        case DATA_THOK_THE_BLOODTHRISTY_INTRO: return thokTheBloodthirstyIntro;
        case DATA_BLACKFUSE_INTRO: return blackfuseIntro;
        case DATA_GARROSH_HELLSCREAM_INTRO: return garroshHellscreamIntro;
        case DATA_ZEAL: return zealDied;
        case DATA_PRESSURE_PLATE_EVENT: return pressurePlateEvent;
        case DATA_GARROSH_HELLSCREAM_ENERGY: return garroshEnergy;
        }
        return 0;
    }

    ObjectGuid GetObjectGuid(uint32 type)
    {
        switch (type)
        {
        case DATA_IMMERSEUS: return immerseusGuid;
        case DATA_SWIRL_TARGET: return swirlTargetGuid;
        case DATA_LOREWALKER_CHO_1: return lorewalkerCho1GUID;
        case DATA_ROOK_STONETOE: return fallenProtectorsGuid[0];
        case DATA_HE_SOFTFOOT: return fallenProtectorsGuid[1];
        case DATA_SUN_TENDERHEART: return fallenProtectorsGuid[2];
        case DATA_VANITY: return vanityGUID;
        case DATA_ARROGANCE: return arroganceGUID;
        case DATA_ZEAL: return zealGUID;
        case DATA_TEARS_OF_THE_VALE_10N: return tearsOfTheValeGUIDs[0];
        case DATA_TEARS_OF_THE_VALE_25N: return tearsOfTheValeGUIDs[1];
        case DATA_TEARS_OF_THE_VALE_10H: return tearsOfTheValeGUIDs[2];
        case DATA_TEARS_OF_THE_VALE_25H: return tearsOfTheValeGUIDs[3];
        case DATA_NORUSHEN: return norushenGuid;
        case DATA_AMALGAM_OF_CORRUPTION: return amalgamOfCorruptionGuid;
        case DATA_LIGHT_CONTAINMENT_1: return lightContainmentGUIDs[0];
        case DATA_LIGHT_CONTAINMENT_2: return lightContainmentGUIDs[1];
        case DATA_LIGHT_CONTAINMENT_3: return lightContainmentGUIDs[2];
        case DATA_LIGHT_CONTAINMENT_4: return lightContainmentGUIDs[3];
        case DATA_LIGHT_CONTAINMENT_TOP: return lightContainmentGUIDs[4];
        case DATA_LIGHT_CONTAINMENT_BOTTOM: return lightContainmentGUIDs[5];
        case DATA_SHA_OF_PRIDE: return shaOfPrideGuid;
        case DATA_SHA_OF_PRIDE_NORUSHEN: return shaOfPrideNorushenGuid;
        case DATA_WEST_SHADOW_PRISON: return shadowPrisonGuids[SHADOW_PRISON_WEST];
        case DATA_WEST_SHADOW_PRISON_A: return shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_A];
        case DATA_WEST_SHADOW_PRISON_B: return shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_B];
        case DATA_WEST_SHADOW_PRISON_C: return shadowPrisonTrapGuids[SHADOW_PRISON_WEST][SHADOW_PRISON_TRAP_C];
        case DATA_NORTH_SHADOW_PRISON: return shadowPrisonGuids[SHADOW_PRISON_NORTH];
        case DATA_NORTH_SHADOW_PRISON_A: return shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_A];
        case DATA_NORTH_SHADOW_PRISON_B: return shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_B];
        case DATA_NORTH_SHADOW_PRISON_C: return shadowPrisonTrapGuids[SHADOW_PRISON_NORTH][SHADOW_PRISON_TRAP_C];
        case DATA_EAST_SHADOW_PRISON: return shadowPrisonGuids[SHADOW_PRISON_EAST];
        case DATA_EAST_SHADOW_PRISON_A: return shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_A];
        case DATA_EAST_SHADOW_PRISON_B: return shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_B];
        case DATA_EAST_SHADOW_PRISON_C: return shadowPrisonTrapGuids[SHADOW_PRISON_EAST][SHADOW_PRISON_TRAP_C];
        case DATA_SOUTH_SHADOW_PRISON: return shadowPrisonGuids[SHADOW_PRISON_SOUTH];
        case DATA_SOUTH_SHADOW_PRISON_A: return shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_A];
        case DATA_SOUTH_SHADOW_PRISON_B: return shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_B];
        case DATA_SOUTH_SHADOW_PRISON_C: return shadowPrisonTrapGuids[SHADOW_PRISON_SOUTH][SHADOW_PRISON_TRAP_C];
        case DATA_VAULT_OF_FORBIDDEN_TREASURES_10: return vaultOfForbiddenTreasuresGUIDs[0];
        case DATA_VAULT_OF_FORBIDDEN_TREASURES_25: return vaultOfForbiddenTreasuresGUIDs[1];
        case DATA_VAULT_OF_FORBIDDEN_TREASURES_10H: return vaultOfForbiddenTreasuresGUIDs[2];
        case DATA_VAULT_OF_FORBIDDEN_TREASURES_25H: return vaultOfForbiddenTreasuresGUIDs[3];
        case DATA_GALAKRAS: return galakrasGuid;
        case DATA_WARLORD_ZAELA: return zaelaGuid;
        case DATA_IRON_JUGGERNAUT: return ironJuggernautGuid;
        case DATA_VOLJIN_1: return voljinIronJuggernautGUID;
        case DATA_BAINE_BLOODHOOF_1: return baineBloodhoofIronJuggernautGUID;
        case DATA_EARTHBREAKER_HAROMM: return korkronDarkShamansGuid[0];
        case DATA_WAVEBINDER_KARDRIS: return korkronDarkShamansGuid[1];
        case DATA_AYSA_CLOUDSINGER: return aysaCloudsingerGUID;
        case DATA_JI_FIREPAW: return jiFirepawGUID;
        case DATA_OVERSEER_KOMAK: return overseerKomakGUID;
        case DATA_GENERAL_NAZGRIM: return generalNazgrimGuid;
        case DATA_MALKOROK: return malkorokGuid;
        case DATA_SPOILS_OF_PANDARIA: return spoilsOfPandariaGuid;
        case DATA_THOK_THE_BLOODTHIRSTY: return thokTheBloodthirstyGuid;
        case DATA_SIEGECRAFTER_BLACKFUSE: return siegecrafterBlackfuseGuid;
        case DATA_UNLOCKED_STOCKPILE_10: return unlockedStockpileGUIDs[0];
        case DATA_UNLOCKED_STOCKPILE_25: return unlockedStockpileGUIDs[1];
        case DATA_UNLOCKED_STOCKPILE_10H: return unlockedStockpileGUIDs[2];
        case DATA_UNLOCKED_STOCKPILE_25H: return unlockedStockpileGUIDs[3];
        case DATA_SPOILS_OF_PANDARIA_GATE_NORTH: return spoilsOfPandariaGoGUIDs[0];
        case DATA_SPOILS_OF_PANDARIA_GATE_WEST: return spoilsOfPandariaGoGUIDs[1];
        case DATA_SPOILS_OF_PANDARIA_GATE_SOUTH: return spoilsOfPandariaGoGUIDs[2];
        case DATA_SPOILS_OF_PANDARIA_GATE_EAST: return spoilsOfPandariaGoGUIDs[3];
        case DATA_SPOILS_OF_PANDARIA_GATE_NORTH_WEST: return spoilsOfPandariaGoGUIDs[4];
        case DATA_SPOILS_OF_PANDARIA_GATE_SOUTH_EAST: return spoilsOfPandariaGoGUIDs[5];
        case DATA_SPOILS_OF_PANDARIA_LEVER_NORTH: return spoilsOfPandariaLevers[0];
        case DATA_SPOILS_OF_PANDARIA_LEVER_WEST: return spoilsOfPandariaLevers[1];
        case DATA_SPOILS_OF_PANDARIA_LEVER_SOUTH: return spoilsOfPandariaLevers[2];
        case DATA_SPOILS_OF_PANDARIA_LEVER_EAST: return spoilsOfPandariaLevers[3];
        case DATA_SAUROK_PRISON_1: return saurokPrisonGUIDs[0];
        case DATA_SAUROK_PRISON_2: return saurokPrisonGUIDs[1];
        case DATA_YAUNGOL_PRISON_1: return yaungolPrisonGUIDs[0];
        case DATA_YAUNGOL_PRISON_2: return yaungolPrisonGUIDs[1];
        case DATA_JINYU_PRISON_1: return jinyuPrisonGUIDs[0];
        case DATA_JINYU_PRISON_2: return jinyuPrisonGUIDs[1];
        case DATA_PARAGONS_OF_THE_KLAXXI: return klaxxiParagonsGuid;
        case DATA_GARROSH_HELLSCREAM: return garroshHellscreamGuid;
        default:
            break;
        }

        return ObjectGuid::Empty;
    }

    std::string GetSaveData()
    {
        std::ostringstream saveStream;
        saveStream << "S O O " /*<< ReadSaveDataBossStates()*/ << GetEventData();

        return saveStream.str();
    }

    std::string GetEventData()
    {
        std::ostringstream saveStream;
        saveStream << lorewalkerChoIntro << " " << lorewalkerChoIntroImmerseus << " " << thokTheBloodthirstyIntro << " " << blackfuseIntro << " " << zealDied << " "
            << pressurePlateEvent << " ";

        return saveStream.str();
    }

    void Load(const char* in)
    {
        if (!in)
        {
            //OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        char dataHead1, dataHead2, dataHead3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> dataHead3;

        if (dataHead1 == 'S' && dataHead2 == 'O' && dataHead3 == 'O')
        {
            for (uint32 i = 0; i < DATA_MAX_BOSS_DATA; ++i)
            {
                uint32 tmpState;
                loadStream >> tmpState;

                if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                    tmpState = NOT_STARTED;

                SetBossState(i, EncounterState(tmpState));
            }

            loadStream >> lorewalkerChoIntro;
            if (lorewalkerChoIntro != DONE)
                lorewalkerChoIntro = NOT_STARTED;

            loadStream >> lorewalkerChoIntroImmerseus;
            if (lorewalkerChoIntroImmerseus != DONE)
                lorewalkerChoIntroImmerseus = NOT_STARTED;

            loadStream >> thokTheBloodthirstyIntro;
            if (thokTheBloodthirstyIntro != DONE)
            {
                thokTheBloodthirstyIntro = NOT_STARTED;
            }
            else
            {
                SendThokTheBloodthirstyIntroDone();
            }

            loadStream >> blackfuseIntro;
            if (blackfuseIntro != DONE)
                blackfuseIntro = NOT_STARTED;

            loadStream >> zealDied;
            if (zealDied != DONE)
                zealDied = NOT_STARTED;
            UpdateZealDoorState();

            loadStream >> pressurePlateEvent;
            if (pressurePlateEvent != DONE)
                pressurePlateEvent = NOT_STARTED;
            UpdatePressurePlateDoorState();

        } //else OUT_LOAD_INST_DATA_FAIL;
    }

    void Update(uint32 diff) override
    {
        events.Update(diff);

        ProcessEvents();
    }

    void ProcessEvent(WorldObject* /*p_Object*/, uint32 p_EventId) override
    {
        if (p_EventId == InstanceEvents::EVENT_PRESSURE_PLATE)
        {
            pressurePlateEvent = DONE;
            UpdatePressurePlateDoorState();

            DoAddAuraOnPlayers(148615); ///< Start Corrupted Vale Intro
        }
    }

private:

    bool IsAllianceInstance()
    {
        return teamInInstance == ALLIANCE;
    }

    bool IsHordeInstance()
    {
        return teamInInstance == HORDE;
    }

    void PreLoadGrids()
    {
        instance->LoadGrid(1360.f, -5404.f); // jaina and wrynn galakras intro
        instance->LoadGrid(1756.f, -5258.f); // lor'themar and sylvanas galakras intro
    }

    void ProcessEvents()
    {
        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SPAWN_NPC_SHA_OF_PRIDE:
                SpawnNpcAfterShaOfPride();
                break;
            case EVENT_FIRST_GALAKRAS_INTRO:
                FirstGalakrasIntro();
                break;
            case EVENT_SECOND_GALAKRAS_INTRO:
                SecondGalakrasIntro();
                break;
            case EVENT_START_GALAKRAS:
                StartGalakras();
                break;
            }
        }
    }

    void UpdateZealDoorState(GameObject* pDoor = nullptr)
    {
        if (!pDoor)
            pDoor = instance->GetGameObject(zealDoorGuid);

        if (!pDoor)
            return;

        if (zealDied == DONE)
            pDoor->SetGoState(GO_STATE_ACTIVE);
        else
            pDoor->SetGoState(GO_STATE_READY);
    }

    void UpdatePressurePlateDoorState(GameObject* p_Door = nullptr)
    {
        if (p_Door == nullptr)
            p_Door = instance->GetGameObject(pressurePlateDoorGuid);

        if (p_Door)
        {
            GOState l_State = pressurePlateEvent == DONE ? GO_STATE_ACTIVE : GO_STATE_READY;
            p_Door->SetGoState(l_State);

            if (l_State == GO_STATE_ACTIVE)
                if (Creature* l_Creature = instance->GetCreature(pressurePlateGuid))
                    l_Creature->RemoveAura(InstanceSpells::SPELL_PRESSURE_PLATE);
        }
    }

    void DelayedSpawnNpcAfterShaOfPride()
    {
        events.ScheduleEvent(EVENT_SPAWN_NPC_SHA_OF_PRIDE, 5000);
    }

    void SpawnNpcAfterShaOfPride()
    {
        if (Creature* pJaina = instance->SummonCreature(NPC_JAINA_PROUDMOORE_1, npcAfterShaOfPridePos2[0]))
        {
            pJaina->AI()->DoAction(ACTION_SHA_OF_PRIDE_JAINA);
        }

        if (Creature* pLorthemar = instance->SummonCreature(NPC_LORTHEMAR_THERON_1, npcAfterShaOfPridePos2[1]))
        {
            pLorthemar->AI()->DoAction(ACTION_SHA_OF_PRIDE_LORTHEMAR);
        }

        if (Creature* pDummy = instance->SummonCreature(WORLD_TRIGGER, npcAfterShaOfPridePos2[2]))
        {
            pDummy->AddAura(SPELL_GOREHOWL, pDummy);
        }
    }

    void DelayedFirstGalakrasIntro()
    {
        if (firstGalakrasIntroDone)
            return;

        events.ScheduleEvent(EVENT_FIRST_GALAKRAS_INTRO, 8000);
    }

    void FirstGalakrasIntro()
    {
        if (firstGalakrasIntroDone)
            return;

        if (IsAllianceInstance())
        {
            if (Creature* pJaina = instance->GetCreature(jainaProudmooreGalakrasGUID))
            {
                pJaina->AI()->DoAction(ACTION_FIRST_INTRO_GALAKRAS);
            }
            if (Creature* pWrynn = instance->GetCreature(kingVarianWrynnGalakrasGUID))
            {
                pWrynn->AI()->DoAction(ACTION_FIRST_INTRO_GALAKRAS);
            }
        }
        else if (IsHordeInstance())
        {
            if (Creature* pLorthemar = instance->GetCreature(lorthemarTheronGalakrasGUID))
            {
                pLorthemar->AI()->DoAction(ACTION_FIRST_INTRO_GALAKRAS);
            }
            if (Creature* pSylvanas = instance->GetCreature(sylvanasWindrunnerGalakrasGUID))
            {
                pSylvanas->AI()->DoAction(ACTION_FIRST_INTRO_GALAKRAS);
            }
            if (Creature* pAethas = instance->GetCreature(aethasSunreaverGalakrasGUID))
            {
                pAethas->AI()->DoAction(ACTION_FIRST_INTRO_GALAKRAS);
            }
        }

        firstGalakrasIntroDone = true;
    }

    void ProcessCannonsDestroyed()
    {
        if (destroyedCannonsCount >= 7)
            return;

        destroyedCannonsCount++;

        if (destroyedCannonsCount >= 7)
        {
            DelayedSecondGalakrasIntro();
        }
    }

    void DelayedSecondGalakrasIntro()
    {
        if (secondGalakrasIntroDone)
            return;

        events.ScheduleEvent(EVENT_SECOND_GALAKRAS_INTRO, 8000);
    }

    void SecondGalakrasIntro()
    {
        if (secondGalakrasIntroDone)
            return;

        PreLoadGrids();

        if (IsAllianceInstance())
        {
            if (Creature* pJaina = instance->GetCreature(jainaProudmooreGalakrasGUID))
            {
                pJaina->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
            }
            if (Creature* pWrynn = instance->GetCreature(kingVarianWrynnGalakrasGUID))
            {
                pWrynn->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
            }
        }
        else if (IsHordeInstance())
        {
            if (Creature* pLorthemar = instance->GetCreature(lorthemarTheronGalakrasGUID))
            {
                pLorthemar->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
            }
            if (Creature* pSylvanas = instance->GetCreature(sylvanasWindrunnerGalakrasGUID))
            {
                pSylvanas->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
            }
            if (Creature* pAethas = instance->GetCreature(aethasSunreaverGalakrasGUID))
            {
                pAethas->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
            }
        }

        if (Creature* pZaela = instance->GetCreature(zaelaGuid))
        {
            pZaela->AI()->DoAction(ACTION_SECOND_INTRO_GALAKRAS);
        }

        secondGalakrasIntroDone = true;
    }

    void StartGalakrasNpc()
    {
        if (GetBossState(DATA_GALAKRAS) == IN_PROGRESS ||
            GetBossState(DATA_GALAKRAS) == DONE)
        {
            return;
        }

        if (IsAllianceInstance())
        {
            if (Creature* pJaina = instance->GetCreature(jainaProudmooreGalakrasGUID))
            {
                pJaina->AI()->DoAction(ACTION_START_GALAKRAS);
            }
            if (Creature* pWrynn = instance->GetCreature(kingVarianWrynnGalakrasGUID))
            {
                pWrynn->AI()->DoAction(ACTION_START_GALAKRAS);
            }
        }
        else if (IsHordeInstance())
        {
            if (Creature* pLorthemar = instance->GetCreature(lorthemarTheronGalakrasGUID))
            {
                pLorthemar->AI()->DoAction(ACTION_START_GALAKRAS);
            }
            if (Creature* pSylvanas = instance->GetCreature(sylvanasWindrunnerGalakrasGUID))
            {
                pSylvanas->AI()->DoAction(ACTION_START_GALAKRAS);
            }
            if (Creature* pAethas = instance->GetCreature(aethasSunreaverGalakrasGUID))
            {
                pAethas->AI()->DoAction(ACTION_START_GALAKRAS);
            }
        }
    }

    void StartGalakras()
    {
        if (GetBossState(DATA_GALAKRAS) == IN_PROGRESS ||
            GetBossState(DATA_GALAKRAS) == DONE)
        {
            return;
        }

        if (Creature* pGalakras = instance->GetCreature(galakrasGuid))
        {
            pGalakras->AI()->DoAction(ACTION_START_GALAKRAS);
        }

        if (Creature* pZaela = instance->GetCreature(zaelaGuid))
        {
            pZaela->AI()->DoAction(ACTION_START_GALAKRAS);
        }
    }

    void ResetGalakrasNpc()
    {
        if (IsAllianceInstance())
        {
            if (Creature* pJaina = instance->GetCreature(jainaProudmooreGalakrasGUID))
            {
                pJaina->AI()->DoAction(ACTION_RESET_GALAKRAS);
            }
            if (Creature* pWrynn = instance->GetCreature(kingVarianWrynnGalakrasGUID))
            {
                pWrynn->AI()->DoAction(ACTION_RESET_GALAKRAS);
            }
        }
        else if (IsHordeInstance())
        {
            if (Creature* pLorthemar = instance->GetCreature(lorthemarTheronGalakrasGUID))
            {
                pLorthemar->AI()->DoAction(ACTION_RESET_GALAKRAS);
            }
            if (Creature* pSylvanas = instance->GetCreature(sylvanasWindrunnerGalakrasGUID))
            {
                pSylvanas->AI()->DoAction(ACTION_RESET_GALAKRAS);
            }
            if (Creature* pAethas = instance->GetCreature(aethasSunreaverGalakrasGUID))
            {
                pAethas->AI()->DoAction(ACTION_RESET_GALAKRAS);
            }
        }
    }

    void StartIronJuggernautNpc()
    {
        if (Creature* pVoljin = instance->GetCreature(voljinIronJuggernautGUID))
        {
            pVoljin->AI()->DoAction(ACTION_IRON_JUGGERNAUT_START);
        }

        if (Creature* pBaine = instance->GetCreature(baineBloodhoofIronJuggernautGUID))
        {
            pBaine->AI()->DoAction(ACTION_IRON_JUGGERNAUT_START);
        }
    }

    void ProcessIronJuggernautDeadNpc()
    {
        if (Creature* pVoljin = instance->GetCreature(voljinIronJuggernautGUID))
        {
            pVoljin->AI()->DoAction(ACTION_IRON_JUGGERNAUT_DEAD);
        }

        if (Creature* pBaine = instance->GetCreature(baineBloodhoofIronJuggernautGUID))
        {
            pBaine->AI()->DoAction(ACTION_IRON_JUGGERNAUT_DEAD);
        }

        if (Creature* pNazgrim = instance->GetCreature(generalNazgrimGuid))
        {
            pNazgrim->AI()->DoAction(ACTION_IRON_JUGGERNAUT_DEAD);
        }
    }

    void UpdateThokTheBloodthirstyIntro()
    {
        if (thokTheBloodthirstyIntro == DONE)
            return;

        if (enragedMushanBeast == DONE && starvedYetti == DONE)
        {
            thokTheBloodthirstyIntro = DONE;

            SaveToDB();

            SendThokTheBloodthirstyIntroDone();
        }
    }

    void SendThokTheBloodthirstyIntroDone()
    {
        if (Creature* pThok = instance->GetCreature(thokTheBloodthirstyGuid))
        {
            pThok->AI()->DoAction(ACTION_THOK_THE_BLOODTHIRSTY_INTRO);
        }
    }

    void SendBlackfuseIntroToPlayers()
    {
        if (IsAllianceInstance())
        {

            DoPlaySceneOnPlayers(SCENE_SIEGECRAFTER_INTRO_ALLIANCE);
        }
        else if (IsHordeInstance())
        {
            DoPlaySceneOnPlayers(SCENE_SIEGECRAFTER_INTRO_HORDE);
        }
    }

    void StartGarroshHellscreamIntro()
    {
        if (garroshHellscreamIntro == DONE)
            return;

        garroshHellscreamIntro = DONE;

        if (Creature* pThrall = instance->GetCreature(thrallGuid))
        {
            pThrall->AI()->DoAction(ACTION_GARROSH_HELLSCREAM_INTRO);
        }
    }

private:

    // First part
    ObjectGuid immerseusGuid;
    ObjectGuid swirlTargetGuid;
    ObjectGuid pressurePlateGuid;
    ObjectGuid pressurePlateDoorGuid;
    ObjectGuid fallenProtectorsGuid[MAX_FALLEN_PROTECTORS];
    ObjectGuid norushenGuid;
    ObjectGuid amalgamOfCorruptionGuid;
    ObjectGuid shaOfPrideGuid;
    ObjectGuid shaOfPrideNorushenGuid;

    // Second part
    ObjectGuid galakrasGuid;
    ObjectGuid zaelaGuid;
    ObjectGuid ironJuggernautGuid;
    ObjectGuid korkronDarkShamansGuid[MAX_KORKRON_DARK_SHAMANS];
    ObjectGuid generalNazgrimGuid;

    // Third part
    ObjectGuid malkorokGuid;
    ObjectGuid spoilsOfPandariaGuid;
    ObjectGuid thokTheBloodthirstyGuid;

    // Last part
    ObjectGuid siegecrafterBlackfuseGuid;
    ObjectGuid klaxxiParagonsGuid;
    ObjectGuid paragonsOfTheKlaxxiGuid[MAX_PARAGONS_OF_THE_KLAXXI];
    ObjectGuid garroshHellscreamGuid;

    ObjectGuid lorewalkerCho1GUID;
    ObjectGuid lorewalkerCho2GUID;
    ObjectGuid vanityGUID;
    ObjectGuid arroganceGUID;
    ObjectGuid zealGUID;
    ObjectGuid zealDoorGuid;
    ObjectGuid tearsOfTheValeGUIDs[4];

    ObjectGuid lightContainmentGUIDs[6];

    ObjectGuid shadowPrisonGuids[MAX_SHADOW_PRISONS];
    ObjectGuid shadowPrisonTrapGuids[MAX_SHADOW_PRISONS][MAX_SHADOW_PRISON_TRAPS];

    ObjectGuid vaultOfForbiddenTreasuresGUIDs[4];

    ObjectGuid jainaProudmooreGalakrasGUID;
    ObjectGuid kingVarianWrynnGalakrasGUID;
    ObjectGuid lorthemarTheronGalakrasGUID;
    ObjectGuid sylvanasWindrunnerGalakrasGUID;
    ObjectGuid aethasSunreaverGalakrasGUID;

    ObjectGuid voljinIronJuggernautGUID;
    ObjectGuid baineBloodhoofIronJuggernautGUID;
    ObjectGuid aysaCloudsingerGUID;
    ObjectGuid jiFirepawGUID;
    ObjectGuid overseerKomakGUID;

    ObjectGuid spoilsOfPandariaGoGUIDs[6];
    ObjectGuid spoilsOfPandariaLevers[4];

    ObjectGuid unlockedStockpileGUIDs[4];

    ObjectGuid saurokPrisonGUIDs[2];
    ObjectGuid yaungolPrisonGUIDs[2];
    ObjectGuid jinyuPrisonGUIDs[2];

    ObjectGuid thrallGuid;

    uint32 lorewalkerChoIntro;
    uint32 lorewalkerChoIntroImmerseus;
    uint32 zealDied;
    uint32 pressurePlateEvent;
    uint32 beachCaptured;

    EventMap events;

    uint32 teamInInstance;

    bool firstGalakrasIntroDone;

    bool secondGalakrasIntroDone;
    uint32 destroyedCannonsCount;

    uint32 thokTheBloodthirstyIntro;
    uint32 enragedMushanBeast;
    uint32 starvedYetti;

    uint32 blackfuseIntro;
    uint32 garroshHellscreamIntro;

    uint32 garroshEnergy;
};

void AddSC_instance_siege_of_orgrimmar()
{
    RegisterInstanceScript(instance_siege_of_orgrimmar, 1136);
}
