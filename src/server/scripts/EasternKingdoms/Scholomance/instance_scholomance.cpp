/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "scholomance.h"

Position const GandlingLoc = { 180.7712f, -5.428603f, 75.57024f, 1.291544f };

class instance_scholomance : public InstanceMapScript
{
public:
    instance_scholomance() : InstanceMapScript(ScholomanceScriptName, 289) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_scholomance_InstanceMapScript(map);
    }

    struct instance_scholomance_InstanceMapScript : public InstanceScript
    {
        instance_scholomance_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            chargerQuestNPCEntrySet.clear();
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_ASPECT_OF_BANALITY);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_ASPECT_OF_CORRUPTION);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_ASPECT_OF_MALICE);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_ASPECT_OF_SHADOW);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_BANAL_SPIRIT);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_CORRUPTED_SPIRIT);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_MALICIOUS_SPIRIT);
            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_SHADOWED_SPIRIT);

            chargerQuestNPCEntrySet.insert(SCHOLOMANCE_NPC::NPC_DEATH_KNIGHT_DARKREAVER);

            rasGateOpened = false;
            rasGateCheckDelay = 1000;

            SetBossState(SCDataTypes::DATA_DARKMASTERGANDLING, EncounterState::NOT_STARTED);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == SCCreatureIds::NPC_DARKMASTER_GANDLING)
            {                
                creature->AI()->Talk(SCHOLOMANCE_LINE_DARKMASTER_GANDLING::LINE_DARKMASTER_GANDLING_0);
                creature->GetMotionMaster()->MoveRandom(5);
            }
            else if (creature->GetEntry() == SCHOLOMANCE_NPC::NPC_DARKREAVER_FALLEN_CHARGER)
            {
                OGCharger = creature->GetGUID();
            }
            else if (chargerQuestNPCEntrySet.find(creature->GetEntry()) != chargerQuestNPCEntrySet.end())
            {
                creature->GetThreatManager().AddThreat(creature->SelectNearestPlayer(50.0f), 100);
            }
        }        

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_GATE_KIRTONOS:
                GateKirtonosGUID = go->GetGUID();
                break;
            case GO_GATE_GANDLING:
                GateGandlingGUID = go->GetGUID();
                break;
            case GO_GATE_MALICIA:
                GateMiliciaGUID = go->GetGUID();
                break;
            case GO_GATE_THEOLEN:
                GateTheolenGUID = go->GetGUID();
                break;
            case GO_GATE_POLKELT:
                GatePolkeltGUID = go->GetGUID();
                break;
            case GO_GATE_RAVENIAN:
                GateRavenianGUID = go->GetGUID();
                break;
            case GO_GATE_BAROV:
                GateBarovGUID = go->GetGUID();
                break;
            case GO_GATE_ILLUCIA:
                GateIlluciaGUID = go->GetGUID();
                break;
            case GO_BRAZIER_OF_THE_HERALD:
                BrazierOfTheHeraldGUID = go->GetGUID();
                break;
            case SCGameobjectIds::GO_GATE_RAS_FROSTWHISPER:
            {
                OGGateRasFrostwhisper = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_LORDALEXEIBAROV:
            case DATA_DOCTORTHEOLENKRASTINOV:
            case DATA_THERAVENIAN:
            case DATA_LOREKEEPERPOLKELT:
            case DATA_INSTRUCTORMALICIA:
            case DATA_LADYILLUCIABAROV:
                CheckToSpawnGandling();
                break;
            default:
                break;
            }

            return true;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case GO_GATE_KIRTONOS:
                return GateKirtonosGUID;
            case GO_GATE_GANDLING:
                return GateGandlingGUID;
            case GO_GATE_MALICIA:
                return GateMiliciaGUID;
            case GO_GATE_THEOLEN:
                return GateTheolenGUID;
            case GO_GATE_POLKELT:
                return GatePolkeltGUID;
            case GO_GATE_RAVENIAN:
                return GateRavenianGUID;
            case GO_GATE_BAROV:
                return GateBarovGUID;
            case GO_GATE_ILLUCIA:
                return GateIlluciaGUID;
            case GO_BRAZIER_OF_THE_HERALD:
                return BrazierOfTheHeraldGUID;
            default:
                break;
            }

            return ObjectGuid::Empty;
        }

        bool CheckPreBosses(uint32 bossId) const
        {
            switch (bossId)
            {
            case DATA_DARKMASTERGANDLING:
                if (GetBossState(DATA_LORDALEXEIBAROV) != DONE)
                    return false;
                if (GetBossState(DATA_DOCTORTHEOLENKRASTINOV) != DONE)
                    return false;
                if (GetBossState(DATA_THERAVENIAN) != DONE)
                    return false;
                if (GetBossState(DATA_LOREKEEPERPOLKELT) != DONE)
                    return false;
                if (GetBossState(DATA_INSTRUCTORMALICIA) != DONE)
                    return false;
                if (GetBossState(DATA_LADYILLUCIABAROV) != DONE)
                    return false;
                if (GetBossState(DATA_DARKMASTERGANDLING) == DONE)
                    return false;
                break;
            default:
                break;
            }

            return true;
        }

        void CheckToSpawnGandling()
        {
            if (CheckPreBosses(DATA_DARKMASTERGANDLING))
                instance->SummonCreature(NPC_DARKMASTER_GANDLING, GandlingLoc);
        }

        void ReadSaveDataMore(std::istringstream& /*data*/) override
        {
            CheckToSpawnGandling();
        }

        virtual void Update(uint32 diff) override
        {
            if (!OGCharger.IsEmpty())
            {
                if (chargerSummonCastVisualDelay > 0)
                {
                    chargerSummonCastVisualDelay -= diff;
                    if (chargerSummonCastVisualDelay <= 0)
                    {
                        if (Creature* chargerC = instance->GetCreature(OGCharger))
                        {
                            chargerC->CastSpell(chargerC, SCHOLOMANCE_SPELL::SPELL_SUMMON_VISUAL);
                            OGCharger.Clear();
                        }
                    }
                }
                else
                {
                    if (Creature* chargerC = instance->GetCreature(OGCharger))
                    {
                        chargerSummonCastVisualDelay = 100;
                    }
                }
            }

            if (!rasGateOpened)
            {
                rasGateCheckDelay -= diff;
                if (rasGateCheckDelay < 0)
                {
                    if (GetBossState(SCDataTypes::DATA_DARKMASTERGANDLING) == EncounterState::DONE)
                    {
                        if (GameObject* goGateRas = instance->GetGameObject(OGGateRasFrostwhisper))
                        {
                            if (goGateRas->SelectNearestPlayer(5.0f))
                            {
                                goGateRas->SetGoState(GOState::GO_STATE_ACTIVE);
                                rasGateOpened = true;
                            }
                        }
                    }
                }
            }
        }

    protected:
        ObjectGuid GateKirtonosGUID;
        ObjectGuid GateGandlingGUID;
        ObjectGuid GateMiliciaGUID;
        ObjectGuid GateTheolenGUID;
        ObjectGuid GatePolkeltGUID;
        ObjectGuid GateRavenianGUID;
        ObjectGuid GateBarovGUID;
        ObjectGuid GateIlluciaGUID;
        ObjectGuid BrazierOfTheHeraldGUID;

        ObjectGuid OGGateRasFrostwhisper;
        int rasGateCheckDelay;
        bool rasGateOpened;
        ObjectGuid OGCharger;

    private:
        std::unordered_set<uint32> chargerQuestNPCEntrySet;
        int chargerSummonCastVisualDelay = 0;
    };
};

class npc_quest_charger_enemy_spirit : public CreatureScript
{
public:
    npc_quest_charger_enemy_spirit() : CreatureScript("npc_quest_charger_enemy_spirit") { }

    struct spell_event
    {
    public:
        spell_event()
        {
            spellID = 0;
            onself = false;
            castRepeatMin = 3000;
            castRepeatMax = 5000;
            activeDelay = urand(3000, 8000);
        }

        uint32 spellID;
        bool onself;
        uint32 castRepeatMin;
        uint32 castRepeatMax;
        int activeDelay;
    };

    struct npc_quest_charger_enemy_spiritAI : public ScriptedAI
    {
        npc_quest_charger_enemy_spiritAI(Creature* creature) : ScriptedAI(creature)
        {
            seMap.clear();
            switch (me->GetEntry())
            {
            case SCHOLOMANCE_NPC::NPC_ASPECT_OF_BANALITY:
            {
                spell_event se1;
                se1.spellID = 8140;
                se1.castRepeatMin = 15000;
                se1.castRepeatMax = 20000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 23262;
                se2.castRepeatMin = 30000;
                se2.castRepeatMax = 35000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_ASPECT_OF_CORRUPTION:
            {
                spell_event se1;
                se1.spellID = 23244;
                se1.castRepeatMin = 8000;
                se1.castRepeatMax = 10000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 10894;
                se2.castRepeatMin = 25000;
                se2.castRepeatMax = 30000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_ASPECT_OF_MALICE:
            {
                spell_event se1;
                se1.spellID = 24673;
                se1.castRepeatMin = 55000;
                se1.castRepeatMax = 65000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 17504;
                se2.castRepeatMin = 35000;
                se2.castRepeatMax = 40000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_ASPECT_OF_SHADOW:
            {
                spell_event se1;
                se1.spellID = 11660;
                se1.castRepeatMin = 3000;
                se1.castRepeatMax = 5000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 30138;
                se2.castRepeatMin = 15000;
                se2.castRepeatMax = 20000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_BANAL_SPIRIT:
            {
                spell_event se1;
                se1.spellID = 8140;
                se1.castRepeatMin = 25000;
                se1.castRepeatMax = 30000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 23262;
                se2.castRepeatMin = 40000;
                se2.castRepeatMax = 45000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_CORRUPTED_SPIRIT:
            {
                spell_event se1;
                se1.spellID = 6819;
                se1.castRepeatMin = 8000;
                se1.castRepeatMax = 10000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 18376;
                se2.castRepeatMin = 30000;
                se2.castRepeatMax = 35000;
                seMap[seMap.size()] = se2;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_MALICIOUS_SPIRIT:
            {
                spell_event se1;
                se1.spellID = 13738;
                se1.castRepeatMin = 15000;
                se1.castRepeatMax = 20000;
                seMap[seMap.size()] = se1;
                break;
            }
            case SCHOLOMANCE_NPC::NPC_SHADOWED_SPIRIT:
            {
                spell_event se1;
                se1.spellID = 12739;
                se1.castRepeatMin = 5000;
                se1.castRepeatMax = 8000;
                seMap[seMap.size()] = se1;
                spell_event se2;
                se2.spellID = 15245;
                se2.castRepeatMin = 15000;
                se2.castRepeatMax = 20000;
                seMap[seMap.size()] = se2;
                spell_event se3;
                se3.spellID = 22417;
                se3.onself = true;
                se3.castRepeatMin = 40000;
                se3.castRepeatMax = 45000;
                seMap[seMap.size()] = se3;
                spell_event se4;
                se4.spellID = 22575;
                se4.castRepeatMin = 15000;
                se4.castRepeatMax = 20000;
                seMap[seMap.size()] = se4;
                break;
            }
            default:
            {
                break;
            }
            }
            Reset();
        }

        void Reset() override
        {

        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsNonMeleeSpellCast(false))
            {
                return;
            }
            if (UpdateVictim())
            {
                for (std::unordered_map<uint32, spell_event>::iterator seIT = seMap.begin(); seIT != seMap.end(); seIT++)
                {
                    if (seIT->second.activeDelay > 0)
                    {
                        seIT->second.activeDelay -= diff;
                    }
                    if (seIT->second.activeDelay <= 0)
                    {
                        if (seIT->second.onself)
                        {
                            if (me->CastSpell(me, seIT->second.spellID) == SpellCastResult::SPELL_CAST_OK)
                            {
                                seIT->second.activeDelay = urand(seIT->second.castRepeatMin, seIT->second.castRepeatMax);
                                return;
                            }
                        }
                        else
                        {
                            if (Unit* target = me->GetVictim())
                            {
                                if (me->CastSpell(target, seIT->second.spellID) == SpellCastResult::SPELL_CAST_OK)
                                {
                                    seIT->second.activeDelay = urand(seIT->second.castRepeatMin, seIT->second.castRepeatMax);
                                    return;
                                }
                            }
                        }
                    }
                }
                DoMeleeAttackIfReady();
            }
        }

        std::unordered_map<uint32, spell_event> seMap;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_quest_charger_enemy_spiritAI(creature);
    }
};

void AddSC_instance_scholomance()
{
    new instance_scholomance();
    new npc_quest_charger_enemy_spirit();
}
