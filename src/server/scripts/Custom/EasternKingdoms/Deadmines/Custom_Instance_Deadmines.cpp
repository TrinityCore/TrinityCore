/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"

#include "Custom_Instance_Deadmines.h"
#include "Custom_DeadminesOLD_Defines.h"

namespace Scripts::EasternKingdoms::Deadmines
{

    class custom_instance_deadmines : public InstanceMapScript
    {
    public:
        custom_instance_deadmines() : InstanceMapScript(Misc::DMScriptName, 36) {  }

        struct custom_instance_deadmines_InstanceMapScript : public InstanceScript
        {
            custom_instance_deadmines_InstanceMapScript(InstanceMap* map) : InstanceScript(map),
                _version(*this, "DeadminesVersion", Version::NotSet),
                _cannonState(*this, "CannonState", CannonEvent::STATE_CANNON_NOT_USED),
                _secondSmiteAlarm(*this, "SecondSmiteAlarm", 0),
                _reaperCounter(*this, "ReaperCounter", 0),
                _foeReaper5000AOEWarning(*this, "FoeReaperAOEWarning", false),
                _ripsnarlFogActive(*this, "RipsnarlFogActive", false),
                _vaporCoalesceCount(*this, "RipsnarlVaporCoalesceCount", 0),
                _cookieDietFailed(*this, "CookieDietFailed", false),
                _vanessaNightmareState(*this, "VanessaNightmareState", 0),
                _nightmareHelixState(*this, "NightmareHelixState", 0),
                _nightmareMechanicalState(*this, "NightmareMechanicalState", 0),
                _steamValveCount(*this, "SteamValveCount", 0),
                _activeNightmare(*this, "ActiveNightmare", 0),
                _vindicatorElixirTime(*this, "VindicatorElixirTime", 0)
            {
                SetHeaders(Misc::DataHeader);
                SetBossNumber(Misc::EncounterCount);
                LoadObjectData(modernCreatureData, {});
                LoadDoorData(doorData);
                LoadDungeonEncounterData(modernEncounters);
            }

            void OnPlayerEnter(Player* player) override
            {
                // Reset fire wall hit tracking for this player when they enter
                _playersHitByFirewall.erase(player->GetGUID());

                // Despawn opposing faction NPCs with a small delay to ensure stability
                player->m_Events.AddEventAtOffset([this, player]()
                {
                    if (player && player->IsInWorld())
                        DespawnOpposingFactionNpcs(player);
                }, 1s);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->GetEntry() == Creatures::LumberingOaf)
                    _oafGUID = creature->GetGUID();

                if (creature->GetEntry() == Creatures::FoeReaper5000)
                    _foeReaperGUID = creature->GetGUID();
            }

            void MarkPlayerHitByFirewall(Player* player)
            {
                if (player)
                    _playersHitByFirewall.insert(player->GetGUID());
            }

            bool WasPlayerHitByFirewall(Player* player) const
            {
                return _playersHitByFirewall.contains(player->GetGUID());
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                // Manually respawn Oaf when Helix encounter resets
                if (id == DataTypes::BOSS_HELIX_GEARBREAKER && state == NOT_STARTED)
                    if (Creature* oaf = instance->GetCreature(_oafGUID))
                        if (!oaf->IsAlive())
                            oaf->Respawn();

                if (id == DataTypes::BOSS_VANESSA_VANCLEEF && state == NOT_STARTED)
                    _steamValveCount = 0;

                return true;
            }

            bool IsClassicVersion() const
            {
                return _version == Version::Classic;
            }

            void SetDeadminesVersion(uint8 version)
            {
                if (_version != Version::NotSet)
                    return;

                _version = version;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case Misc::DeadminesVersion:
                        SetDeadminesVersion(uint8(data));
                        break;
                    case CannonEvent::DATA_EVENT:
                        _cannonState = data;
                        break;
                    case MiscOLD::SecondSmiteAlarm:
                        _secondSmiteAlarm = data;
                        break;
                    case Misc::FoeReaperAddCounter:
                        _reaperCounter = data;
                        break;
                    case Misc::FoeReaper5000AOEWarning:
                        _foeReaper5000AOEWarning = data;
                        break;
                    case Misc::RipsnarlFogActive:
                        _ripsnarlFogActive = data;
                        // Remove the fog screen aura immediately once the fog phase ends
                        if (!_ripsnarlFogActive)
                            DoRemoveAurasDueToSpellOnPlayers(Spells::RipsnarlsFogAura);
                        break;
                    case Misc::RipsnarlVaporAchievement:
                        _vaporCoalesceCount = data;
                        break;
                    case Misc::CookieDietFailed:
                        _cookieDietFailed = data;
                        break;
                    case Misc::VanessaNightmareState:
                        _vanessaNightmareState = data;
                        break;
                    case Misc::NightmareHelixState:
                        _nightmareHelixState = data;
                        break;
                    case Misc::NightmareMechanicalState:
                        _nightmareMechanicalState = data;
                        break;
                    case Misc::SteamValveCount:
                        _steamValveCount = data;
                        break;
                    case Misc::ActiveNightmare:
                        _activeNightmare = data;
                        break;
                    case Misc::VindicatorElixirTime:
                        if (!_vindicatorElixirTime)
                            _vindicatorElixirTime = data;
                        break;
                    default:
                        // Check if this is a player GUID (used for firewall hit tracking)
                        if (data == 1)
                            _playersHitByFirewall.insert(ObjectGuid::Create<HighGuid::Player>(type));
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case Misc::DeadminesVersion:
                        return _version;
                    case CannonEvent::DATA_EVENT:
                        return _cannonState;
                    case MiscOLD::SecondSmiteAlarm:
                        return _secondSmiteAlarm;
                    case Misc::FoeReaperAddCounter:
                        return _reaperCounter;
                    case Misc::FoeReaper5000AOEWarning:
                        return _foeReaper5000AOEWarning;
                    case Misc::RipsnarlFogActive:
                        return _ripsnarlFogActive;
                    case Misc::RipsnarlVaporAchievement:
                        return _vaporCoalesceCount;
                    case Misc::CookieDietFailed:
                        return _cookieDietFailed;
                    case Misc::VanessaNightmareState:
                        return _vanessaNightmareState;
                    case Misc::NightmareHelixState:
                        return _nightmareHelixState;
                    case Misc::NightmareMechanicalState:
                        return _nightmareMechanicalState;
                    case Misc::SteamValveCount:
                        return _steamValveCount;
                    case Misc::ActiveNightmare:
                        return _activeNightmare;
                    case Misc::VindicatorElixirTime:
                        return _vindicatorElixirTime;
                    default:
                        // Check if this is a player GUID (used for firewall hit tracking)
                        if (_playersHitByFirewall.contains(ObjectGuid::Create<HighGuid::Player>(type)))
                            return 1;
                        return 0;
                }
            }

            bool IsAllianceNPC(Creature* creature) const
            {
                switch (creature->GetEntry())
                {
                    case Creatures::StormwindDefender:
                    case Creatures::HoratioLaine:
                    case Creatures::CrimeSceneBot:
                    case Creatures::StormwindInvestigator:
                    case Creatures::QuartermasterLewis:
                        return true;
                    default:
                        return false;
                }
            }

            bool IsHordeNPC(Creature* creature) const
            {
                switch (creature->GetEntry())
                {
                    case Creatures::MissMayhem:
                    case Creatures::MayhemPrototype:
                    case Creatures::Kagtha:
                    case Creatures::ShatteredHandAssassin:
                    case Creatures::SlinkySharpshiv:
                        return true;
                    default:
                        return false;
                }
            }

            void DespawnOpposingFactionNpcs(Player* player)
            {
                TeamId teamId = player->GetTeamId();

                std::vector<Creature*> toDespawn;
                for (auto const& pair : instance->GetCreatureBySpawnIdStore())
                {
                    Creature* creature = pair.second;
                    if (!creature || !creature->IsInWorld())
                        continue;

                    if (teamId == TEAM_ALLIANCE && IsHordeNPC(creature))
                        toDespawn.push_back(creature);
                    else if (teamId == TEAM_HORDE && IsAllianceNPC(creature))
                        toDespawn.push_back(creature);
                }

                for (Creature* creature : toDespawn)
                    creature->DespawnOrUnsummon();
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                case Objects::IronCladDoor:
                    _ironCladDoorGUID = go->GetGUID();
                    break;
                case Objects::DefiasCannon:
                    _defiasCannonGUID = go->GetGUID();
                    break;
                case Objects::DoorLever:
                    _doorLeverGUID = go->GetGUID();
                    break;
                case Objects::FoundryDoor:
                    _foundryDoorGUID = go->GetGUID();
                    break;
                case ObjectsOLD::MrSmiteChest:
                    _mrSmiteChestGUID = go->GetGUID();
                    break;
                default:
                    break;
                }
            }

            void Update(uint32 diff) override
            {
                // Apply HelixRide aura to all players during Helix encounter for Rat Pack achievement
                // Strange that this aura is needed but it is part of the conditions tree for the criteria
                if (GetBossState(DataTypes::BOSS_HELIX_GEARBREAKER) == IN_PROGRESS)
                {
                    if (_helixRideAuraTimer <= diff)
                    {
                        instance->DoOnPlayers([](Player* player)
                        {
                            if (!player->HasAura(Spells::HelixRide))
                                player->AddAura(Spells::HelixRide, player);
                        });
                        _helixRideAuraTimer = 60000; // 60 seconds
                    }
                    else
                        _helixRideAuraTimer -= diff;
                }

                // Apply the fog screen aura to all players while Ripsnarl is engaged and in his fog phase.
                // Polling here keeps late joiners / resurrected players covered; removal is handled in SetData.
                if (GetBossState(DataTypes::BOSS_ADMIRAL_RIPSNARL) == IN_PROGRESS && _ripsnarlFogActive)
                {
                    if (_ripsnarlFogAuraTimer <= diff)
                    {
                        instance->DoOnPlayers([](Player* player)
                        {
                            if (!player->HasAura(Spells::RipsnarlsFogAura))
                                player->AddAura(Spells::RipsnarlsFogAura, player);
                        });
                        _ripsnarlFogAuraTimer = 1000; // 1 second
                    }
                    else
                        _ripsnarlFogAuraTimer -= diff;
                }

                if (_cannonState == CannonEvent::STATE_DONE)
                    return;

                // Defias Cannon Event Starts Here
                GameObject* IronCladDoor = instance->GetGameObject(_ironCladDoorGUID);
                if (!IronCladDoor)
                    return;

                switch (_cannonState)
                {
                case CannonEvent::STATE_CANNON_GUNPOWDER_USED:
                {
                    _cannonBlastTimer = CannonEvent::BLAST_TIMER;
                    _cannonState = CannonEvent::STATE_CANNON_BLAST_INITIATED;
                    if (!IsClassicVersion())
                    {
                        GameObject* Cannon = instance->GetGameObject(_defiasCannonGUID);
                        if (Cannon)
                        {
                            Creature* cannonBunny = Cannon->FindNearestCreature(Creatures::GeneralPurposeBunnyJMF, 5.f);
                            if (cannonBunny)
                            {
                                cannonBunny->m_Events.AddEventAtOffset([cannonBunny]()
                                    {
                                        if (cannonBunny)
                                            cannonBunny->AI()->Talk(0); // Cannon gunpowder used
                                    }, std::chrono::seconds(2));
                            }
                        }
                    }
                    break;
                }
                case CannonEvent::STATE_CANNON_BLAST_INITIATED:
                {
                    if (_cannonBlastTimer <= diff)
                    {
                        if (IsClassicVersion())
                            SummonCreatures();
                        else SummonCreaturesModern();

                        ShootCannon();
                        BlastOutDoor();
                        LeverStuck();

                        if (IsClassicVersion())
                        {
                            instance->LoadGrid(-22.8f, -797.24f); // Loads Mr. Smite's grid.
                            if (Creature* smite = instance->GetCreatureBySpawnId(SpawnsOLD::MrSmite)) // goes off when door blows up
                            {
                                // Use m_Events to add a delay for Smite
                                // Otherwise the sound does not play completely since it overlaps with the explosion/door sounds
                                smite->m_Events.AddEventAtOffset([smite]()
                                    {
                                        if (smite && smite->IsAlive())
                                            smite->AI()->Talk(TextsOLD::SmiteAlarm1);
                                    }, std::chrono::seconds(3));
                            }
                        }

                        _piratesTimer = CannonEvent::PIRATES_TIMER;
                        _cannonState = CannonEvent::STATE_PIRATES_ATTACK;

                    }
                    else _cannonBlastTimer -= diff;
                    break;
                }
                case CannonEvent::STATE_PIRATES_ATTACK:
                    if (_piratesTimer <= diff)
                    {
                        MoveCreaturesInside();
                        _cannonState = CannonEvent::STATE_DONE;
                    }
                    else _piratesTimer -= diff;
                    break;
                }
            }

            void SummonCreatures()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(_ironCladDoorGUID))
                {
                    if(Creature* DefiasPirate1 = pIronCladDoor->SummonCreature(CreaturesOLD::DefiasPirate,
                        pIronCladDoor->GetPositionX() - 2,
                        pIronCladDoor->GetPositionY() - 7,
                        pIronCladDoor->GetPositionZ(),
                        0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                    {
                        _defiasPirate1GUID = DefiasPirate1->GetGUID();
                        DefiasPirate1->RemoveAllAuras();
                    }

                    if (Creature* DefiasPirate2 = pIronCladDoor->SummonCreature(CreaturesOLD::DefiasPirate,
                        pIronCladDoor->GetPositionX() + 3,
                        pIronCladDoor->GetPositionY() - 6,
                        pIronCladDoor->GetPositionZ(),
                        0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                    {
                        _defiasPirate2GUID = DefiasPirate2->GetGUID();
                        DefiasPirate2->RemoveAllAuras();
                    }
                }
            }

            void SummonCreaturesModern()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(_ironCladDoorGUID))
                {
                    if (Creature* DefiasEnforcer1 = pIronCladDoor->SummonCreature(Creatures::DefiasEnforcer,
                        Positions::DefiasEnforcer, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                        _defiasEnforcer1GUID = DefiasEnforcer1->GetGUID();

                    if (Creature* DefiasEnforcer2 = pIronCladDoor->SummonCreature(Creatures::DefiasShadowguard,
                        Positions::DefiasShadowguard, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                        _defiasEnforcer2GUID = DefiasEnforcer2->GetGUID();

                    if (Creature* DefiasBloodWizzard1 = pIronCladDoor->SummonCreature(Creatures::DefiasBloodWizzard,
                        Positions::DefiasBloodWizzard1, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                        _defiasWizzard1GUID = DefiasBloodWizzard1->GetGUID();

                    if (Creature* DefiasBloodWizzard2 = pIronCladDoor->SummonCreature(Creatures::DefiasBloodWizzard,
                        Positions::DefiasBloodWizzard2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s))
                        _defiasWizzard2GUID = DefiasBloodWizzard2->GetGUID();
                }
            }

            void MoveCreaturesInside()
            {
                if (!_defiasEnforcer1GUID || !_defiasEnforcer2GUID || !_defiasWizzard1GUID || !_defiasWizzard2GUID)
                    return;

                Creature* pDefiasEnforcer1 = instance->GetCreature(_defiasEnforcer1GUID);
                Creature* pDefiasEnforcer2 = instance->GetCreature(_defiasEnforcer2GUID);
                Creature* pDefiasWizzard1 = instance->GetCreature(_defiasWizzard1GUID);
                Creature* pDefiasWizzard2 = instance->GetCreature(_defiasWizzard2GUID);
                if (!pDefiasEnforcer1 || !pDefiasEnforcer2 || !pDefiasWizzard1 || !pDefiasWizzard2)
                    return;

                MoveCreatureInside(pDefiasEnforcer1);
                MoveCreatureInside(pDefiasEnforcer2);
                MoveCreatureInside(pDefiasWizzard1);
                MoveCreatureInside(pDefiasWizzard2);
            }

            void MoveCreaturesInsideModern()
            {
                if (!_defiasPirate1GUID || !_defiasPirate2GUID)
                    return;

                Creature* pDefiasPirate1 = instance->GetCreature(_defiasPirate1GUID);
                Creature* pDefiasPirate2 = instance->GetCreature(_defiasPirate2GUID);
                if (!pDefiasPirate1 || !pDefiasPirate2)
                    return;

                MoveCreatureInside(pDefiasPirate1);
                MoveCreatureInside(pDefiasPirate2);
            }

            void MoveCreatureInside(Creature* creature)
            {
                creature->SetWalk(false);
                creature->GetMotionMaster()->MovePoint(0, -102.7f, -655.9f, creature->GetPositionZ());
            }

            void ShootCannon()
            {
                if (GameObject* pDefiasCannon = instance->GetGameObject(_defiasCannonGUID))
                {
                    pDefiasCannon->SetGoState(GO_STATE_ACTIVE);
                    pDefiasCannon->PlayDirectSound(SoundsOLD::CannonFire);
                }
            }

            void BlastOutDoor()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(_ironCladDoorGUID))
                {
                    pIronCladDoor->SetGoState(GO_STATE_DESTROYED);
                    pIronCladDoor->PlayDirectSound(SoundsOLD::DestroyDoor);
                }
            }

            void LeverStuck()
            {
                if (GameObject* pDoorLever = instance->GetGameObject(_doorLeverGUID))
                    pDoorLever->SetFlag(GO_FLAG_INTERACT_COND);
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                case MiscOLD::DATA_SMITE_CHEST:
                    return _mrSmiteChestGUID;
                case DataTypes::BOSS_FOE_REAPER_5000:
                    return _foeReaperGUID;
                case Objects::FoundryDoor:
                    return _foundryDoorGUID;
                }

                return ObjectGuid::Empty;
            }

        private:
            PersistentInstanceScriptValue<uint8> _version;
            PersistentInstanceScriptValue<uint8> _cannonState;
            PersistentInstanceScriptValue<uint8> _secondSmiteAlarm;
            PersistentInstanceScriptValue<uint8> _reaperCounter;
            PersistentInstanceScriptValue<bool> _foeReaper5000AOEWarning;
            PersistentInstanceScriptValue<bool> _ripsnarlFogActive;
            PersistentInstanceScriptValue<int8> _vaporCoalesceCount;
            PersistentInstanceScriptValue<bool> _cookieDietFailed;
            PersistentInstanceScriptValue<uint8> _vanessaNightmareState;
            PersistentInstanceScriptValue<uint8> _nightmareHelixState;
            PersistentInstanceScriptValue<uint8> _nightmareMechanicalState;
            PersistentInstanceScriptValue<uint8> _steamValveCount;
            PersistentInstanceScriptValue<int8> _activeNightmare;
            PersistentInstanceScriptValue<uint32> _vindicatorElixirTime;

            uint32 _cannonBlastTimer = 0;
            uint32 _piratesTimer = 0;
            uint32 _helixRideAuraTimer = 0;
            uint32 _ripsnarlFogAuraTimer = 0;

            ObjectGuid _oafGUID;
            ObjectGuid _foundryDoorGUID;
            ObjectGuid _ironCladDoorGUID;
            ObjectGuid _doorLeverGUID;
            ObjectGuid _defiasCannonGUID;
            ObjectGuid _mrSmiteChestGUID;

            ObjectGuid _defiasPirate1GUID;
            ObjectGuid _defiasPirate2GUID;

            ObjectGuid _defiasEnforcer1GUID;
            ObjectGuid _defiasEnforcer2GUID;
            ObjectGuid _defiasWizzard1GUID;
            ObjectGuid _defiasWizzard2GUID;

            ObjectGuid _foeReaperGUID;

            GuidSet _playersHitByFirewall;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new custom_instance_deadmines_InstanceMapScript(map);
        }
    };
}

void AddSC_custom_instance_deadmines()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    new custom_instance_deadmines();
}
