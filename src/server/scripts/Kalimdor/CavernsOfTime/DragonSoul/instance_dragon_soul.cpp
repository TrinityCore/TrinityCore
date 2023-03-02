/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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

#include "ScriptMgr.h"
#include "dragon_soul.h"
#include "GameObject.h"

#define MAX_ENCOUNTER 8

enum Spells
{
    SPELL_TWILIGHT_SHIFT                        = 106368,
    SPELL_HEROIC_WILL_AOE                       = 105554,
    SPELL_HEROIC_WILL                           = 106108,
    SPELL_LAST_DEFENDER_OF_AZEROTH_DRUID        = 106224,
    SPELL_LAST_DEFENDER_OF_AZEROTH_PALADIN      = 106226,
    SPELL_LAST_DEFENDER_OF_AZEROTH_DK           = 106227,
    SPELL_LAST_DEFENDER_OF_AZEROTH_WARRIOR      = 106080,
    SPELL_LAST_DEFENDER_OF_AZEROTH_MONK         = 129873,
    SPELL_GIFT_OF_LIVE_AURA                     = 105896,
    SPELL_ESSENCE_OF_DREAMS_AURA                = 105900,
    SPELL_YSERA_PRESENCE                        = 106456,
    SPELL_YSERA_PRESENCE_AURA                   = 106457,
    SPELL_THE_DREAMER                           = 106463,
    SPELL_ENTER_THE_DREAM                       = 106464,
    SPELL_SOURCE_OF_MAGIC_AURA                  = 105903,
    SPELL_TIMELOOP                              = 105984,
    SPELL_DREAM                                 = 106466,
};

class instance_dragon_soul : public InstanceMapScript
{
    public:
        instance_dragon_soul() : InstanceMapScript("instance_dragon_soul", 967) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_dragon_soul_InstanceMapScript(map);
        }

        struct instance_dragon_soul_InstanceMapScript : public InstanceScript
        {
            instance_dragon_soul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);

                memset(uiLesserCacheofTheAspects, 0, sizeof(uiLesserCacheofTheAspects));
                memset(uiBackPlates, 0, sizeof(uiBackPlates));
                memset(uiGreaterCacheofTheAspects, 0, sizeof(uiGreaterCacheofTheAspects));
                memset(uiElementiumFragment, 0, sizeof(uiElementiumFragment));

                bHagaraEvent = 0;
                isHeroicFailed = 0;
            }

            void OnPlayerEnter(Player* pPlayer) override
            {
                if (!uiTeamInInstance)
                    uiTeamInInstance = pPlayer->GetTeam();

                if (GetBossState(BOSS_ULTRAXION) != DONE)
                {
                    StartEventWyrmrest(pPlayer, NPC_HARBRINGER_OF_TWILIGHT);
                    StartEventWyrmrest(pPlayer, NPC_HARBRINGER_OF_DESTRUCTION);
                    StartEventWyrmrest(pPlayer, NPC_FORCE_OF_DESTRUCTION);
                    StartEventWyrmrest(pPlayer, NPC_PORTENT_OF_TWILIGHT);
                    StartEventWyrmrest(pPlayer, NPC_ARCANE_WARDEN);
                    StartEventWyrmrest(pPlayer, NPC_CHAMPION_OF_MAGIC);
                    StartEventWyrmrest(pPlayer, NPC_CHAMPION_OF_LIFE);
                    StartEventWyrmrest(pPlayer, NPC_CHAMPION_OF_TIME);
                    StartEventWyrmrest(pPlayer, NPC_CHAMPION_OF_EMERALD_DREAM);
                    StartEventWyrmrest(pPlayer, NPC_DEATHWING_TOWER);
                }

                if (GetBossState(DATA_ZONOZZ) != IN_PROGRESS || GetBossState(DATA_YORSAHJ) != IN_PROGRESS)
                {
                    std::list<Creature*> portalEternity;
                    std::list<Creature*> portalBase;
                    GetCreatureListWithEntryInGrid(portalEternity, pPlayer, NPC_TRAVEL_TO_EYE_OF_ETERNITY, 2000.0f);
                    GetCreatureListWithEntryInGrid(portalBase, pPlayer, NPC_TRAVEL_TO_WYRMREST_BASE, 2000.0f);
                    if (portalEternity.empty())
                        return;
                    if (portalBase.empty())
                        return;

                    for (std::list<Creature*>::iterator itr = portalEternity.begin(); itr != portalEternity.end(); ++itr)
                    {
                        (*itr)->RemoveAura(SPELL_TELEPORT_VISUAL_DISABLED);
                        (*itr)->CastSpell((*itr), SPELL_TELEPORT_VISUAL_ACTIVE, true);
                    }

                    for (std::list<Creature*>::iterator itr = portalBase.begin(); itr != portalBase.end(); ++itr)
                    {
                        (*itr)->RemoveAura(SPELL_TELEPORT_VISUAL_DISABLED);
                        (*itr)->CastSpell((*itr), SPELL_TELEPORT_VISUAL_ACTIVE, true);
                    }
                }

                if (pPlayer->HasSpell(SPELL_DREAM))
                    pPlayer->RemoveAurasDueToSpell(SPELL_DREAM);
                RemoveEncounterAuras();
            }

            void OnCreatureCreate(Creature* pCreature) override
            {
                switch (pCreature->GetEntry())
                {
                    case NPC_MORCHOK:
                        uiMorchokGUID = pCreature->GetGUID();
                        break;
                    case NPC_KOHCROM:
                        uiKohcromGUID = pCreature->GetGUID();
                        break;
                    case NPC_YORSAHJ:
                        uiYorsahjGUID = pCreature->GetGUID();
                        break;
                    case NPC_ZONOZZ:
                        uiZonozzGUID = pCreature->GetGUID();
                        break;
                    case NPC_HAGARA:
                        uiHagaraGUID = pCreature->GetGUID();
                        break;
                    case NPC_ULTRAXION:
                        uiUltraxionGUID = pCreature->GetGUID();
                        break;
                    case NPC_BLACKHORN:
                        uiBlackhornGUID = pCreature->GetGUID();
                        break;
                    case NPC_SKY_CAPTAIN_SWAYZE:
                        if (pCreature->GetPositionZ() > 200.0f)
                        {
                            uiSwayzeGUID = pCreature->GetGUID();
                            if (GetBossState(DATA_ULTRAXION) == DONE)
                                pCreature->SetVisible(true);
                            else
                                pCreature->SetVisible(false);
                        }
                        break;
                    case NPC_KAANU_REEVS:
                        if (pCreature->GetPositionZ() > 200.0f)
                        {
                            uiReevsGUID = pCreature->GetGUID();
                            if (GetBossState(DATA_ULTRAXION) == DONE)
                                pCreature->SetVisible(true);
                            else
                                pCreature->SetVisible(false);
                        }
                        break;
                    case NPC_DEATHWING:
                        uiDeathwingGUID = pCreature->GetGUID();
                        break;
                    case NPC_ALEXSTRASZA_DRAGON:
                        uiAlexstraszaDragonGUID = pCreature->GetGUID();
                        break;
                    case NPC_NOZDORMU_DRAGON:
                        uiNozdormuDragonGUID = pCreature->GetGUID();
                        break;
                    case NPC_YSERA_DRAGON:
                        uiYseraDragonGUID = pCreature->GetGUID();
                        break;
                    case NPC_KALECGOS_DRAGON:
                        uiKalecgosDragonGUID = pCreature->GetGUID();
                        break;
                    case NPC_THRALL_2:
                        uiTrallMaelstrom = pCreature->GetGUID();
                        break;
                    case NPC_TRAVEL_TO_WYRMREST_TEMPLE:
                    case NPC_TRAVEL_TO_EYE_OF_ETERNITY:
                    case NPC_TRAVEL_TO_WYRMREST_BASE:
                    case NPC_TRAVEL_TO_WYRMREST_SUMMIT:
                        teleportGUIDs.push_back(pCreature->GetGUID());
                        break;
                    case NPC_TRAVEL_TO_DECK:
                        if (GetBossState(DATA_BLACKHORN) == DONE)
                            pCreature->SetVisible(true);
                        else
                            pCreature->SetVisible(false);

                        uiDeckGUID = pCreature->GetGUID();
                        teleportGUIDs.push_back(pCreature->GetGUID());
                        break;
                    case NPC_TRAVEL_TO_MAELSTORM:
                        if (GetBossState(DATA_SPINE) == DONE)
                            pCreature->SetVisible(true);
                        else
                            pCreature->SetVisible(false);

                        uiMaelstormGUID = pCreature->GetGUID();
                        teleportGUIDs.push_back(pCreature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* pCreature) override
            {
                switch (pCreature->GetEntry())
                {
                    case NPC_ULTRAXION:
                        uiUltraxionGUID = ObjectGuid::Empty;
                        break;
                    case NPC_BLACKHORN:
                        uiBlackhornGUID = ObjectGuid::Empty;
                        break;
                    case NPC_DEATHWING:
                        uiDeathwingGUID = ObjectGuid::Empty;
                        break;
                    case NPC_ALEXSTRASZA_DRAGON:
                        uiAlexstraszaDragonGUID = ObjectGuid::Empty;
                        break;
                    case NPC_NOZDORMU_DRAGON:
                        uiNozdormuDragonGUID = ObjectGuid::Empty;
                        break;
                    case NPC_YSERA_DRAGON:
                        uiYseraDragonGUID = ObjectGuid::Empty;
                        break;
                    case NPC_KALECGOS_DRAGON:
                        uiKalecgosDragonGUID = ObjectGuid::Empty;
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* pGo) override
            {
                switch (pGo->GetEntry())
                {
                    case GO_LESSER_CACHE_OF_THE_ASPECTS_10N:
                        uiLesserCacheofTheAspects[0] = pGo->GetGUID();
                        break;
                    case GO_LESSER_CACHE_OF_THE_ASPECTS_25N:
                        uiLesserCacheofTheAspects[1] = pGo->GetGUID();
                        break;
                    case GO_LESSER_CACHE_OF_THE_ASPECTS_10H:
                        uiLesserCacheofTheAspects[2] = pGo->GetGUID();
                        break;
                    case GO_LESSER_CACHE_OF_THE_ASPECTS_25H:
                        uiLesserCacheofTheAspects[3] = pGo->GetGUID();
                        break;
                    case GO_ALLIANCE_SHIP:
                        uiAllianceShipGUID = pGo->GetGUID();
                        if (GetBossState(DATA_ULTRAXION) == DONE)
                            pGo->RemoveFlag(GO_FLAG_DESTROYED);
                        pGo->UpdateObjectVisibility();
                        break;
                    case GO_DEATHWING_BACK_PLATE_1:
                        uiBackPlates[0] = pGo->GetGUID();
                        break;
                    case GO_DEATHWING_BACK_PLATE_2:
                        uiBackPlates[1] = pGo->GetGUID();
                        break;
                    case GO_DEATHWING_BACK_PLATE_3:
                        uiBackPlates[2] = pGo->GetGUID();
                        break;
                    case GO_GREATER_CACHE_OF_THE_ASPECTS_10N:
                        uiGreaterCacheofTheAspects[0] = pGo->GetGUID();
                        break;
                    case GO_GREATER_CACHE_OF_THE_ASPECTS_25N:
                        uiGreaterCacheofTheAspects[1] = pGo->GetGUID();
                        break;
                    case GO_GREATER_CACHE_OF_THE_ASPECTS_10H:
                        uiGreaterCacheofTheAspects[2] = pGo->GetGUID();
                        break;
                    case GO_GREATER_CACHE_OF_THE_ASPECTS_25H:
                        uiGreaterCacheofTheAspects[3] = pGo->GetGUID();
                        break;
                    case GO_ELEMENTIUM_FRAGMENT_10N:
                        uiElementiumFragment[0] = pGo->GetGUID();
                        break;
                    case GO_ELEMENTIUM_FRAGMENT_25N:
                        uiElementiumFragment[1] = pGo->GetGUID();
                        break;
                    case GO_ELEMENTIUM_FRAGMENT_10H:
                        uiElementiumFragment[2] = pGo->GetGUID();
                        break;
                    case GO_ELEMENTIUM_FRAGMENT_25H:
                        uiElementiumFragment[3] = pGo->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_MORCHOK: return uiMorchokGUID;
                    case DATA_KOHCROM: return uiKohcromGUID;
                    case DATA_YORSAHJ: return uiYorsahjGUID;
                    case DATA_ZONOZZ: return uiZonozzGUID;
                    case DATA_HAGARA: return uiHagaraGUID;
                    case DATA_ULTRAXION: return uiUltraxionGUID;
                    case DATA_BLACKHORN: return uiBlackhornGUID;
                    case DATA_LESSER_CACHE_10N: return uiLesserCacheofTheAspects[0];
                    case DATA_LESSER_CACHE_25N: return uiLesserCacheofTheAspects[1];
                    case DATA_LESSER_CACHE_10H: return uiLesserCacheofTheAspects[2];
                    case DATA_LESSER_CACHE_25H: return uiLesserCacheofTheAspects[3];
                    case DATA_SWAYZE: return uiSwayzeGUID;
                    case DATA_REEVS: return uiReevsGUID;
                    case DATA_DEATHWING: return uiDeathwingGUID;
                    case DATA_ALEXSTRASZA_DRAGON: return uiAlexstraszaDragonGUID;
                    case DATA_NOZDORMU_DRAGON: return uiNozdormuDragonGUID;
                    case DATA_YSERA_DRAGON: return uiYseraDragonGUID;
                    case DATA_KALECGOS_DRAGON: return uiKalecgosDragonGUID;
                    case DATA_TRALL_MAELSTROM: return uiTrallMaelstrom;
                    case DATA_ALLIANCE_SHIP: return uiAllianceShipGUID;
                    case DATA_BACK_PLATE_1: return uiBackPlates[0];
                    case DATA_BACK_PLATE_2: return uiBackPlates[1];
                    case DATA_BACK_PLATE_3: return uiBackPlates[2];
                    case DATA_GREATER_CACHE_10N: return uiGreaterCacheofTheAspects[0];
                    case DATA_GREATER_CACHE_25N: return uiGreaterCacheofTheAspects[1];
                    case DATA_GREATER_CACHE_10H: return uiGreaterCacheofTheAspects[2];
                    case DATA_GREATER_CACHE_25H: return uiGreaterCacheofTheAspects[3];
                    case DATA_ELEMENTIUM_FRAGMENT_10N: return uiElementiumFragment[0];
                    case DATA_ELEMENTIUM_FRAGMENT_25N: return uiElementiumFragment[1];
                    case DATA_ELEMENTIUM_FRAGMENT_10H: return uiElementiumFragment[2];
                    case DATA_ELEMENTIUM_FRAGMENT_25H: return uiElementiumFragment[3];
                    default: break;
                }
                return ObjectGuid::Empty;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_HAGARA_EVENT)
                {
                    bHagaraEvent = data;
                    SaveToDB();
                }

                switch (type)
                {
                    case DATA_MORCHOK:
                    {
                        MorchokEvent = data;
                        break;
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_MORCHOK)
                    return MorchokEvent;
                if (type == DATA_HAGARA_EVENT)
                    return bHagaraEvent;
                else if (type == DATA_ALL_HEROIC)
                    return (isHeroicFailed == 0) ? true : false;

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (type == DATA_BLACKHORN)
                    if (Creature* pDeck = instance->GetCreature(uiDeckGUID))
                        pDeck->SetVisible(state == DONE ? true : false);

                if (type == DATA_SPINE)
                    if (Creature* pMaelstorm = instance->GetCreature(uiMaelstormGUID))
                        pMaelstorm->SetVisible(state == DONE ? true : false);

                if (state == DONE)
                    if (!instance->IsHeroic())
                    {
                        isHeroicFailed = 1;
                        SaveToDB();
                    }

                // visual state of teleporters
                if (state == IN_PROGRESS)
                {
                    if (!teleportGUIDs.empty())
                        for (std::vector<ObjectGuid>::const_iterator itr = teleportGUIDs.begin(); itr != teleportGUIDs.end(); ++itr)
                            if (Creature* pTeleport = instance->GetCreature((*itr)))
                            {
                                pTeleport->RemoveAura(SPELL_TELEPORT_VISUAL_ACTIVE);
                                pTeleport->CastSpell(pTeleport, SPELL_TELEPORT_VISUAL_DISABLED, true);
                            }
                }
                else
                {
                    if (!teleportGUIDs.empty())
                        for (std::vector<ObjectGuid>::const_iterator itr = teleportGUIDs.begin(); itr != teleportGUIDs.end(); ++itr)
                            if (Creature* pTeleport = instance->GetCreature((*itr)))
                            {
                                pTeleport->RemoveAura(SPELL_TELEPORT_VISUAL_DISABLED);
                                pTeleport->CastSpell(pTeleport, SPELL_TELEPORT_VISUAL_ACTIVE, true);
                            }
                }


                return true;
            }

            void TrownRock(uint32 entry)
            {
                std::list<Creature*> targetRock;
                Creature* morchok = instance->GetCreature(uiMorchokGUID);
                GetCreatureListWithEntryInGrid(targetRock, morchok, entry, 200.0f);
                if (targetRock.empty())
                    return;

                targetRock.remove_if([&morchok](Creature* c) {return !morchok->IsWithinLOSInMap(c); });

                if (targetRock.size() > 1)
                {
                    Trinity::Containers::RandomResize(targetRock, 1);
                    if (Creature* target = targetRock.front())
                    {
                        morchok->CastSpell(target, SPELL_MORCHOK_SIEGE_MISSILE_2, true);
                    }
                }
            }

            void RemoveEncounterAuras()
            {
                if (GetBossState(BOSS_ULTRAXION) == NOT_STARTED)
                {
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL_AOE);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_GIFT_OF_LIVE_AURA);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_DREAMS_AURA);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_SOURCE_OF_MAGIC_AURA);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_TIMELOOP);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEFENDER_OF_AZEROTH_DK);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEFENDER_OF_AZEROTH_PALADIN);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEFENDER_OF_AZEROTH_DRUID);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEFENDER_OF_AZEROTH_WARRIOR);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEFENDER_OF_AZEROTH_MONK);
                }
                if (GetBossState(DATA_SPINE) == DONE && GetBossState(DATA_MADNESS) != DONE)
                {
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE_AURA);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_THE_DREAMER);
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_ENTER_THE_DREAM);
                }
            }

            void StartEventWyrmrest(Player* player, uint32 entry)
            {
                std::list<Creature*> dragon;
                GetCreatureListWithEntryInGrid(dragon, player, entry, 1000.0f);

                if (dragon.empty())
                    return;

                for (std::list<Creature*>::iterator itr = dragon.begin(); itr != dragon.end(); ++itr)
                    (*itr)->AI()->DoAction(ACTION_START_WYRMREST_EVENT);
            }

            void ExitBlistering(Player* player) //Hack for evite the blistering all time in the limb of madness
            {
                std::list<Creature*> dragon;
                GetCreatureListWithEntryInGrid(dragon, player, 56188, 1000.0f); //Blistering Tentacle, Madness of Deathwing

                if (dragon.empty())
                    return;

                for (std::list<Creature*>::iterator itr = dragon.begin(); itr != dragon.end(); ++itr)
                    (*itr)->AI()->Reset();
            }

            void Update(uint32 diff) override
            {
                if (playerTimer <= diff)
                {
                    for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                    {
                        if (Player* pPlayer = i->GetSource())
                        {
                            if (GetBossState(BOSS_MORCHOK) != DONE)
                                if (pPlayer->GetPositionZ() < 50.0f && !pPlayer->IsBeingTeleported())
                                    pPlayer->NearTeleportTo(morchokPos.GetPositionX(), morchokPos.GetPositionY(), morchokPos.GetPositionZ(), morchokPos.GetOrientation());

                            if (GetBossState(BOSS_ULTRAXION) == IN_PROGRESS)
                                if (pPlayer->GetPositionZ() < 310.0f && !pPlayer->IsBeingTeleported())
                                    pPlayer->NearTeleportTo(-1761.76f, -2388.99f, 341.59f, 0);

                            if (GetBossState(DATA_BLACKHORN) == DONE && GetBossState(DATA_SPINE) == NOT_STARTED)
                                if (pPlayer->isDead())
                                    pPlayer->NearTeleportTo(skyfirePos.GetPositionX(), skyfirePos.GetPositionY(), skyfirePos.GetPositionZ(), skyfirePos.GetOrientation());

                            if (GetBossState(BOSS_MORCHOK) == DONE && GetBossState(DATA_ZONOZZ) != DONE)
                                if (pPlayer->GetPositionZ() < -250.0f && !pPlayer->IsBeingTeleported())
                                    pPlayer->NearTeleportTo(-1769.329956f, -1916.869995f, -226.28f, 0.0f);

                            if (GetBossState(DATA_SPINE) == DONE && GetBossState(DATA_MADNESS) == NOT_STARTED)
                                if (pPlayer->isDead())
                                    ExitBlistering(pPlayer);

                            if (GetBossState(DATA_MADNESS) == DONE || GetBossState(DATA_MADNESS) == NOT_STARTED)
                                if (pPlayer->HasSpell(SPELL_DREAM))
                                    pPlayer->RemoveAurasDueToSpell(SPELL_DREAM);

                            if (GetBossState(DATA_MADNESS) == NOT_STARTED && GetBossState(DATA_SPINE) == DONE)
                                if (Creature* trall = instance->GetCreature(uiTrallMaelstrom))
                                    if (trall->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP))
                                        trall->AI()->DoAction(ACTION_RESET_BATTLE);
                        }
                    }
                    playerTimer = 2000;
                }
                else
                    playerTimer -= diff;

                if (trownStoneTimer <= diff)
                {
                    if (GetBossState(BOSS_MORCHOK) == NOT_STARTED)
                        if (Creature* morchok = instance->GetCreature(uiMorchokGUID))
                            for (Map::PlayerList::const_iterator i = plrList.begin(); i != plrList.end(); ++i)
                            {
                                morchok->CastSpell(morchok, SPELL_MORCHOK_SIEGE_MISSILE_1, true);
                                TrownRock(NPC_TARGET_DUMMY);
                            }

                    trownStoneTimer = 7000;
                }
                else
                    trownStoneTimer -= diff;
            }

            private:
                uint32 uiTeamInInstance;
                uint32 playerTimer;
                uint32 trownStoneTimer;
                ObjectGuid uiMorchokGUID;
                ObjectGuid uiKohcromGUID;
                ObjectGuid uiYorsahjGUID;
                ObjectGuid uiZonozzGUID;
                ObjectGuid uiHagaraGUID;
                ObjectGuid uiUltraxionGUID;
                ObjectGuid uiBlackhornGUID;
                ObjectGuid uiAllianceShipGUID;
                ObjectGuid uiSwayzeGUID;
                ObjectGuid uiReevsGUID;
                ObjectGuid uiDeckGUID;
                ObjectGuid uiMaelstormGUID;
                ObjectGuid uiDeathwingGUID;
                ObjectGuid uiAlexstraszaDragonGUID;
                ObjectGuid uiNozdormuDragonGUID;
                ObjectGuid uiYseraDragonGUID;
                ObjectGuid uiKalecgosDragonGUID;
                ObjectGuid uiTrallMaelstrom;

                ObjectGuid uiLesserCacheofTheAspects[4];
                ObjectGuid uiBackPlates[3];
                ObjectGuid uiGreaterCacheofTheAspects[4];
                ObjectGuid uiElementiumFragment[4];

                std::vector<ObjectGuid> teleportGUIDs;

                uint32 bHagaraEvent;
                uint32 isHeroicFailed;
                uint32 MorchokEvent;
                Map::PlayerList const &plrList = instance->GetPlayers();
        };
};

void AddSC_instance_dragon_soul()
{
    new instance_dragon_soul();
}
