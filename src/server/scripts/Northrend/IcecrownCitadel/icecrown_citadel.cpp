/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "icecrown_citadel.h"
#include "CellImpl.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "VehicleDefines.h"

enum ICCTexts
{
    // Highlord Tirion Fordring (at Light's Hammer)
    SAY_TIRION_INTRO_1 = 0,
    SAY_TIRION_INTRO_2 = 1,
    SAY_TIRION_INTRO_3 = 2,
    SAY_TIRION_INTRO_4 = 3,
    SAY_TIRION_INTRO_H_5 = 4,
    SAY_TIRION_INTRO_A_5 = 5,

    // The Lich King (at Light's Hammer)
    SAY_LK_INTRO_1 = 0,
    SAY_LK_INTRO_2 = 1,
    SAY_LK_INTRO_3 = 2,
    SAY_LK_INTRO_4 = 3,
    SAY_LK_INTRO_5 = 4,

    // Highlord Bolvar Fordragon (at Light's Hammer)
    SAY_BOLVAR_INTRO_1 = 0,

    // High Overlord Saurfang (at Light's Hammer)
    SAY_SAURFANG_INTRO_1 = 15,
    SAY_SAURFANG_INTRO_2 = 16,
    SAY_SAURFANG_INTRO_3 = 17,
    SAY_SAURFANG_INTRO_4 = 18,

    // Muradin Bronzebeard (at Light's Hammer)
    SAY_MURADIN_INTRO_1 = 13,
    SAY_MURADIN_INTRO_2 = 14,
    SAY_MURADIN_INTRO_3 = 15,

    // Deathbound Ward
    SAY_TRAP_ACTIVATE = 0,

    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING = 0,
};

enum ICCSpells
{
    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE = 72879,
    SPELL_DEATH_PLAGUE_AURA = 72865,
    SPELL_RECENTLY_INFECTED = 72884,
    SPELL_DEATH_PLAGUE_KILL = 72867,
    SPELL_STOMP = 64652,
    SPELL_ARCTIC_BREATH = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS = 70460,

    // Alchemist Adrianna
    SPELL_HARVEST_BLIGHT_SPECIMEN = 72155,

    // Invisible Stalker (Float, Uninteractible, LargeAOI)
    SPELL_SOUL_MISSILE = 72585,

    // Empowering Blood Orb
    SPELL_EMPOWERED_BLOOD_2 = 70232,
    SPELL_EMPOWERED_BLOOD_3 = 70304,
    SPELL_EMPOWERED_BLOOD_4 = 70320,
    SPELL_ORB_CONTROLLER_ACTIVE = 70293,

    // Darkfallen Generic
    SPELL_BLOOD_ORB_VISUAL = 72099,
    SPELL_SIPHON_ESSENCE = 70299,

    // Darkfallen Blood Knight
    SPELL_VAMPIRIC_AURA = 71736,
    SPELL_BLOOD_MIRROR = 70450,
    SPELL_BLOOD_MIRROR_2 = 70451,
    SPELL_BLOOD_MIRROR_DAMAGE_SHARE = 70445,
    SPELL_UNHOLY_STRIKE = 70437,

    // Darkfallen Noble
    SPELL_SHADOW_BOLT = 72960,
    SPELL_CHAINS_OF_SHADOW = 72960,

    // Darkfallen Archmage
    SPELL_FIREBALL = 70409,
    SPELL_AMPLIFY_MAGIC = 70408,
    SPELL_BLAST_WAVE = 70407,
    SPELL_POLYMORPH_ALLY = 72106,
    SPELL_POLYMORPH = 70410,

    // Darkfallen Advisor
    SPELL_LICH_SLAP = 72057,
    SPELL_SHROUD_OF_SPELL_WARDING = 72066,

    // Vampiric Fiend
    SPELL_DISEASE_CLOUD = 41290,
    SPELL_LEECHING_ROOT = 70671,

    // Darkfallen Tactician
    SPELL_SHADOWSTEP = 70431,
    SPELL_BLOOD_SAP = 70432
};

enum ICCTimedEventIds
{
    // Light's Hammer RP
    EVENT_TIRION_INTRO_2 = 1,
    EVENT_TIRION_INTRO_3,
    EVENT_TIRION_INTRO_4,
    EVENT_TIRION_INTRO_5,
    EVENT_LK_INTRO_1,
    EVENT_TIRION_INTRO_6,
    EVENT_LK_INTRO_2,
    EVENT_LK_INTRO_3,
    EVENT_LK_INTRO_4,
    EVENT_BOLVAR_INTRO_1,
    EVENT_LK_INTRO_5,
    EVENT_SAURFANG_INTRO_1,
    EVENT_TIRION_INTRO_H_7,
    EVENT_SAURFANG_INTRO_2,
    EVENT_SAURFANG_INTRO_3,
    EVENT_SAURFANG_INTRO_4,
    EVENT_SAURFANG_RUN,
    EVENT_MURADIN_INTRO_1,
    EVENT_MURADIN_INTRO_2,
    EVENT_MURADIN_INTRO_3,
    EVENT_TIRION_INTRO_A_7,
    EVENT_MURADIN_INTRO_4,
    EVENT_MURADIN_INTRO_5,
    EVENT_MURADIN_RUN,

    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE,
    EVENT_STOMP,
    EVENT_ARCTIC_BREATH,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP,

    // Invisible Stalker (Float, Uninteractible, LargeAOI)
    EVENT_SOUL_MISSILE,
};

enum ICCDataTypes
{
    DATA_DAMNED_KILLS = 1,
    DATA_GUID
};

enum ICCActions
{
    ACTION_SIPHON_INTERRUPTED = 1,
    ACTION_EVADE,
    ACTION_COMBAT
};

enum ICCEventIds
{
    EVENT_AWAKEN_WARD_1 = 22900,
    EVENT_AWAKEN_WARD_2 = 22907,
    EVENT_AWAKEN_WARD_3 = 22908,
    EVENT_AWAKEN_WARD_4 = 22909,
};

enum ICCMisc
{
    GOSSIP_MENUID_ALLY = 11204,
    GOSSIP_MENUID_HORDE = 11207
};

// at Light's Hammer
class npc_highlord_tirion_fordring_lh : public CreatureScript
{
    public:
        npc_highlord_tirion_fordring_lh() : CreatureScript("npc_highlord_tirion_fordring_lh") { }

        struct npc_highlord_tirion_fordringAI : public ScriptedAI
        {
            npc_highlord_tirion_fordringAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _theLichKing.Clear();
                _bolvarFordragon.Clear();
                _factionNPC.Clear();
                _damnedKills = 0;
            }

            void Reset() override
            {
                _events.Reset();
                Initialize();
            }

            // IMPORTANT NOTE: This is triggered from per-GUID scripts
            // of The Damned SAI
            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_DAMNED_KILLS && data == 1)
                {
                    if (++_damnedKills == 2)
                    {
                        if (Creature* theLichKing = me->FindNearestCreature(NPC_THE_LICH_KING_LH, 150.0f))
                        {
                            if (Creature* bolvarFordragon = me->FindNearestCreature(NPC_HIGHLORD_BOLVAR_FORDRAGON_LH, 150.0f))
                            {
                                if (Creature* factionNPC = me->FindNearestCreature(_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE ? NPC_SE_HIGH_OVERLORD_SAURFANG : NPC_SE_MURADIN_BRONZEBEARD, 50.0f))
                                {
                                    me->setActive(true);
                                    me->SetFarVisible(true);
                                    _theLichKing = theLichKing->GetGUID();
                                    theLichKing->setActive(true);
                                    theLichKing->SetFarVisible(true);
                                    _bolvarFordragon = bolvarFordragon->GetGUID();
                                    bolvarFordragon->setActive(true);
                                    bolvarFordragon->SetFarVisible(true);
                                    _factionNPC = factionNPC->GetGUID();
                                    factionNPC->setActive(true);
                                    factionNPC->SetFarVisible(true);
                                }
                            }
                        }

                        if (!_bolvarFordragon || !_theLichKing || !_factionNPC)
                            return;

                        Talk(SAY_TIRION_INTRO_1);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_2, 4000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_3, 14000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_4, 18000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_5, 31000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_1, 35000);
                        _events.ScheduleEvent(EVENT_TIRION_INTRO_6, 51000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_2, 58000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_3, 74000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_4, 86000);
                        _events.ScheduleEvent(EVENT_BOLVAR_INTRO_1, 100000);
                        _events.ScheduleEvent(EVENT_LK_INTRO_5, 108000);

                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_1, 120000);
                            _events.ScheduleEvent(EVENT_TIRION_INTRO_H_7, 129000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_2, 139000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_3, 150000);
                            _events.ScheduleEvent(EVENT_SAURFANG_INTRO_4, 162000);
                            _events.ScheduleEvent(EVENT_SAURFANG_RUN, 170000);
                        }
                        else
                        {
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_1, 120000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_2, 124000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_3, 127000);
                            _events.ScheduleEvent(EVENT_TIRION_INTRO_A_7, 136000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_4, 144000);
                            _events.ScheduleEvent(EVENT_MURADIN_INTRO_5, 151000);
                            _events.ScheduleEvent(EVENT_MURADIN_RUN, 157000);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (_damnedKills != 2)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIRION_INTRO_2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_3:
                            Talk(SAY_TIRION_INTRO_2);
                            break;
                        case EVENT_TIRION_INTRO_4:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_5:
                            Talk(SAY_TIRION_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NO_SHEATHE);
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_6:
                            Talk(SAY_TIRION_INTRO_4);
                            break;
                        case EVENT_LK_INTRO_2:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_2);
                            break;
                        case EVENT_LK_INTRO_3:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_3);
                            break;
                        case EVENT_LK_INTRO_4:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                                theLichKing->AI()->Talk(SAY_LK_INTRO_4);
                            break;
                        case EVENT_BOLVAR_INTRO_1:
                            if (Creature* bolvarFordragon = ObjectAccessor::GetCreature(*me, _bolvarFordragon))
                            {
                                bolvarFordragon->AI()->Talk(SAY_BOLVAR_INTRO_1);
                                bolvarFordragon->setActive(false);
                                bolvarFordragon->SetFarVisible(false);
                            }
                            break;
                        case EVENT_LK_INTRO_5:
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                            {
                                theLichKing->AI()->Talk(SAY_LK_INTRO_5);
                                theLichKing->setActive(false);
                                theLichKing->SetFarVisible(false);
                            }
                            break;
                        case EVENT_SAURFANG_INTRO_1:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_1);
                            break;
                        case EVENT_TIRION_INTRO_H_7:
                            Talk(SAY_TIRION_INTRO_H_5);
                            break;
                        case EVENT_SAURFANG_INTRO_2:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_2);
                            break;
                        case EVENT_SAURFANG_INTRO_3:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_3);
                            break;
                        case EVENT_SAURFANG_INTRO_4:
                            if (Creature* saurfang = ObjectAccessor::GetCreature(*me, _factionNPC))
                                saurfang->AI()->Talk(SAY_SAURFANG_INTRO_4);
                            break;
                        case EVENT_MURADIN_RUN:
                        case EVENT_SAURFANG_RUN:
                            if (Creature* factionNPC = ObjectAccessor::GetCreature(*me, _factionNPC))
                                factionNPC->GetMotionMaster()->MovePath(factionNPC->GetSpawnId() * 10, false);
                            me->setActive(false);
                            _damnedKills = 3;
                            break;
                        case EVENT_MURADIN_INTRO_1:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_1);
                            break;
                        case EVENT_MURADIN_INTRO_2:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            break;
                        case EVENT_MURADIN_INTRO_3:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            break;
                        case EVENT_TIRION_INTRO_A_7:
                            Talk(SAY_TIRION_INTRO_A_5);
                            break;
                        case EVENT_MURADIN_INTRO_4:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_2);
                            break;
                        case EVENT_MURADIN_INTRO_5:
                            if (Creature* muradin = ObjectAccessor::GetCreature(*me, _factionNPC))
                                muradin->AI()->Talk(SAY_MURADIN_INTRO_3);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* const _instance;
            ObjectGuid _theLichKing;
            ObjectGuid _bolvarFordragon;
            ObjectGuid _factionNPC;
            uint16 _damnedKills;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_highlord_tirion_fordringAI>(creature);
        }
};

class npc_rotting_frost_giant : public CreatureScript
{
    public:
        npc_rotting_frost_giant() : CreatureScript("npc_rotting_frost_giant") { }

        struct npc_rotting_frost_giantAI : public ScriptedAI
        {
            npc_rotting_frost_giantAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15s);
                _events.ScheduleEvent(EVENT_STOMP, 5s, 8s);
                _events.ScheduleEvent(EVENT_ARCTIC_BREATH, 10s, 15s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _events.Reset();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target);
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            _events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15s);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            _events.ScheduleEvent(EVENT_STOMP, 15s, 18s);
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            _events.ScheduleEvent(EVENT_ARCTIC_BREATH, 26s, 33s);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_rotting_frost_giantAI>(creature);
        }
};

class npc_frost_freeze_trap : public CreatureScript
{
    public:
        npc_frost_freeze_trap() : CreatureScript("npc_frost_freeze_trap") { }

        struct npc_frost_freeze_trapAI: public ScriptedAI
        {
            npc_frost_freeze_trapAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        _events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    _events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22s);
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_frost_freeze_trapAI>(creature);
        }
};

class npc_alchemist_adrianna : public CreatureScript
{
    public:
        npc_alchemist_adrianna() : CreatureScript("npc_alchemist_adrianna") { }

        struct npc_alchemist_adriannaAI : public ScriptedAI
        {
            npc_alchemist_adriannaAI(Creature* creature) : ScriptedAI(creature) { }

            bool GossipHello(Player* player) override
            {
                if (!me->FindCurrentSpellBySpellId(sSpellMgr->GetSpellIdForDifficulty(SPELL_HARVEST_BLIGHT_SPECIMEN, me)))
                    if (player->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE) && player->HasAura(SPELL_GREEN_BLIGHT_RESIDUE))
                        DoCastSelf(SPELL_HARVEST_BLIGHT_SPECIMEN, false);
                return false;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_alchemist_adriannaAI>(creature);
        }
};

class npc_arthas_teleport_visual : public CreatureScript
{
    public:
        npc_arthas_teleport_visual() : CreatureScript("npc_arthas_teleport_visual") { }

        struct npc_arthas_teleport_visualAI : public NullCreatureAI
        {
            npc_arthas_teleport_visualAI(Creature* creature) : NullCreatureAI(creature), _instance(creature->GetInstanceScript())
            {
            }

            void Reset() override
            {
                _events.Reset();
                if (_instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE &&
                    _instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE &&
                    _instance->GetBossState(DATA_SINDRAGOSA) == DONE)
                    _events.ScheduleEvent(EVENT_SOUL_MISSILE, 1s, 6s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_events.Empty())
                    return;

                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_SOUL_MISSILE)
                {
                    DoCastAOE(SPELL_SOUL_MISSILE);
                    _events.ScheduleEvent(EVENT_SOUL_MISSILE, 5s, 7s);
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            // Distance from the center of the spire
            if (creature->GetExactDist2d(4357.052f, 2769.421f) < 100.0f && creature->GetHomePosition().GetPositionZ() < 315.0f)
                return GetIcecrownCitadelAI<npc_arthas_teleport_visualAI>(creature);

            // Default to no script
            return nullptr;
        }
};

struct npc_entrance_faction_leader : public ScriptedAI
{
    npc_entrance_faction_leader(Creature* creature) : ScriptedAI(creature) { }

    bool GossipSelect(Player* /*player*/, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENUID_ALLY || menuId == GOSSIP_MENUID_HORDE)
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetData(DATA_FACTION_BUFF, 0);
        return false;
    }
};

class ICCOrbControllerMinionSearch
{
public:
    ICCOrbControllerMinionSearch(Unit* owner, bool checkCasting) : _owner(owner), _checkCasting(checkCasting) { }

    bool operator()(Creature* target) const
    {
        if (!target->IsAlive() || (_checkCasting && target->HasUnitState(UNIT_STATE_CASTING)) || target->GetWaypointPath() || _owner->GetDistance(target) > 10.0f)
            return false;

        switch (target->GetEntry())
        {
            case NPC_DARKFALLEN_BLOOD_KNIGHT:
            case NPC_DARKFALLEN_NOBLE:
            case NPC_DARKFALLEN_ARCHMAGE:
            case NPC_DARKFALLEN_ADVISOR:
            case NPC_DARKFALLEN_TACTICIAN:
                return true;
            default:
                return false;
        }
    }

private:
    // Need check to not use polymorph in a casting creature
    Unit* _owner;
    bool _checkCasting;
};

static std::vector<uint32> const DarkFallensEmotes =
{
    EMOTE_ONESHOT_TALK,
    EMOTE_ONESHOT_EXCLAMATION,
    EMOTE_ONESHOT_QUESTION,
    EMOTE_ONESHOT_LAUGH,
    EMOTE_ONESHOT_YES,
    EMOTE_ONESHOT_NO
};

struct npc_icc_orb_controller : public ScriptedAI
{
    npc_icc_orb_controller(Creature* creature) : ScriptedAI(creature), _isInCombat(false), _isLongRepeat(false) { }

    void Reset() override
    {
        _scheduler.Schedule(1s, [this](TaskContext /*initialize*/)
        {
            std::vector<Creature*> creatures;
            ICCOrbControllerMinionSearch check(me, false);
            Trinity::CreatureListSearcher<ICCOrbControllerMinionSearch> searcher(me, creatures, check);
            Cell::VisitGridObjects(me, searcher, 10.0f);

            if (creatures.empty())
                return;

            for (Creature* creature : creatures)
            {
                creature->AI()->SetGUID(me->GetGUID(), DATA_GUID);
                _minionGuids.push_back(creature->GetGUID());
            }

            ScheduleVisualChannel(false);
        });
    }

    void ScheduleVisualChannel(bool evading)
    {
        _scheduler.Schedule(evading ? 5s : 1s, [this](TaskContext visual)
        {
            ObjectGuid guid = Trinity::Containers::SelectRandomContainerElement(_minionGuids);
            if (Unit* minion = ObjectAccessor::GetUnit(*me, guid))
                minion->CastSpell(nullptr, SPELL_BLOOD_ORB_VISUAL);
            visual.Repeat(_isLongRepeat ? 21s : 3s);
            _isLongRepeat = !_isLongRepeat;
        });
    }

    void UpdateValidGuids()
    {
        for (GuidVector::iterator itr = _minionGuids.begin(); itr != _minionGuids.end();)
        {
            if (Unit* minion = ObjectAccessor::GetUnit(*me, (*itr)))
            {
                if (!minion->IsAlive())
                {
                    itr = _minionGuids.erase(itr);
                    continue;
                }

                ++itr;
            }
            // Is not in world anymore
            else
                itr = _minionGuids.erase(itr);
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ORB_CONTROLLER_ACTIVE)
            if (GameObject* orb = me->FindNearestGameObject(GO_EMPOWERING_BLOOD_ORB, 5.0f))
                orb->AI()->SetGUID(caster->GetGUID(), DATA_GUID);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id != ACTION_COMBAT || _isInCombat)
            return;

        Creature* darkfallen = ObjectAccessor::GetCreature(*me, guid);
        if (!darkfallen)
            return;

        _isInCombat = true;
        _scheduler.CancelAll();
        if (_minionGuids.empty())
            return;

        for (ObjectGuid guid : _minionGuids)
        {
            if (Creature* minion = ObjectAccessor::GetCreature(*me, guid))
                if (minion->IsAIEnabled() && !minion->IsInCombat())
                    minion->AI()->DoZoneInCombat(darkfallen);
        }

        if (Unit* minion = ObjectAccessor::GetUnit(*me, Trinity::Containers::SelectRandomContainerElement(_minionGuids)))
            minion->CastSpell(nullptr, SPELL_SIPHON_ESSENCE);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_EVADE && _isInCombat)
        {
            _isInCombat = false;
            UpdateValidGuids();
            ScheduleVisualChannel(true);
            if (GameObject* orb = me->FindNearestGameObject(GO_EMPOWERING_BLOOD_ORB, 5.0f))
                orb->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    GuidVector _minionGuids;
    bool _isInCombat;
    bool _isLongRepeat;
};

struct DarkFallenAI : public ScriptedAI
{
    DarkFallenAI(Creature* creature) : ScriptedAI(creature), IsDoingEmotes(true), AttackSpellId(0) { }

    virtual void ScheduleSpells() = 0;

    void Reset() override
    {
        IsDoingEmotes = me->GetWaypointPath() ? false : true;
        Scheduler.CancelAll();
        Scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        })
        .Schedule(1s, 10s, [this](TaskContext emote)
        {
            if (!IsDoingEmotes)
                return;

            if (roll_chance_i(20))
            {
                std::vector<Creature*> creatures;
                ICCOrbControllerMinionSearch check(me, true);
                Trinity::CreatureListSearcher<ICCOrbControllerMinionSearch> searcher(me, creatures, check);
                Cell::VisitGridObjects(me, searcher, 10.0f);
                if (!creatures.empty())
                {
                    Creature* friendly = Trinity::Containers::SelectRandomContainerElement(creatures);
                    DoCast(friendly, SPELL_POLYMORPH_ALLY);
                }
            }
            Scheduler.Schedule(1s, [this](TaskContext /*emote*/)
            {
                me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(DarkFallensEmotes));
            });
            emote.Repeat(15s, 30s);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        IsDoingEmotes = false;
        Scheduler.CancelAll();
        ScheduleSpells();
        if (Unit* trigger = ObjectAccessor::GetUnit(*me, TriggerGuid))
            trigger->GetAI()->SetGUID(me->GetGUID(), ACTION_COMBAT);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SIPHON_INTERRUPTED)
            if (GameObject* orb = me->FindNearestGameObject(GO_EMPOWERING_BLOOD_ORB, 10.0f))
                orb->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_GUID)
            TriggerGuid = guid;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        if (Unit* trigger = ObjectAccessor::GetUnit(*me, TriggerGuid))
            trigger->GetAI()->DoAction(ACTION_EVADE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !IsDoingEmotes)
            return;

        Scheduler.Update(diff);

        if (AttackSpellId)
            DoSpellAttackIfReady(AttackSpellId);
        else
            DoMeleeAttackIfReady();
    }

protected:
    TaskScheduler Scheduler;
    ObjectGuid TriggerGuid;
    bool IsDoingEmotes;
    uint32 AttackSpellId;
};

struct npc_darkfallen_blood_knight : public DarkFallenAI
{
    npc_darkfallen_blood_knight(Creature* creature) : DarkFallenAI(creature) { }

    void ScheduleSpells() override
    {
        Scheduler.Schedule(500ms, [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_VAMPIRIC_AURA);
        })
        .Schedule(8s, [this](TaskContext unholyStrike)
        {
            DoCastVictim(SPELL_UNHOLY_STRIKE);
            unholyStrike.Repeat(8s, 9s);
        })
        .Schedule(6s, [this](TaskContext bloodMirror)
        {
            DoCastSelf(SPELL_BLOOD_MIRROR);
            bloodMirror.Repeat(34s);
        });
    }
};

struct npc_darkfallen_noble : public DarkFallenAI
{
    npc_darkfallen_noble(Creature* creature) : DarkFallenAI(creature) { }

    void ScheduleSpells() override
    {
        AttackSpellId = SPELL_SHADOW_BOLT;
        Scheduler.Schedule(500ms, [this](TaskContext /*context*/)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, false, -SPELL_CHAINS_OF_SHADOW))
                DoCast(target, SPELL_CHAINS_OF_SHADOW);
        })
        .Schedule(11s, [this](TaskContext summonVampiric)
        {
            // Vampiric should be summoned by 70647 but i have no idea what is miscB of summon effect
            if (Unit* target = me->GetVictim())
                if (Creature* vampiric = me->SummonCreature(NPC_VAMPIRIC_FIEND, target->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN))
                    vampiric->AI()->AttackStart(target);
            summonVampiric.Repeat(30s);
        });
    }
};

struct npc_vampiric_fiend : public ScriptedAI
{
    npc_vampiric_fiend(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_DISEASE_CLOUD);
        _scheduler.Schedule(9s, [this](TaskContext /*leechingRoot*/)
        {
            DoCastVictim(SPELL_LEECHING_ROOT);
        })
        .Schedule(38s, [this](TaskContext /*leechingRoot*/)
        {
            me->DespawnOrUnsummon();
        });
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _scheduler.CancelAll();
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

struct npc_darkfallen_archmage : public DarkFallenAI
{
    npc_darkfallen_archmage(Creature* creature) : DarkFallenAI(creature) { }

    void ScheduleSpells() override
    {
        AttackSpellId = SPELL_FIREBALL;
        Scheduler.Schedule(1s, [this](TaskContext amplifyMagic)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(target, SPELL_AMPLIFY_MAGIC);
            amplifyMagic.Repeat(15s, 24s);
        })
        .Schedule(10s, [this](TaskContext blastWave)
        {
            DoCastSelf(SPELL_BLAST_WAVE);
            blastWave.Repeat(25s, 30s);
        })
        .Schedule(17s, [this](TaskContext polymorph)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, false, -SPELL_POLYMORPH))
                DoCast(target, SPELL_POLYMORPH);
            polymorph.Repeat(25s, 35s);
        });
    }
};

struct npc_darkfallen_advisor : public DarkFallenAI
{
    npc_darkfallen_advisor(Creature* creature) : DarkFallenAI(creature) { }

    void ScheduleSpells() override
    {
        Scheduler.Schedule(8s, [this](TaskContext lichSlap)
        {
            DoCastVictim(SPELL_LICH_SLAP);
            lichSlap.Repeat(12s);
        })
        .Schedule(50s, [this](TaskContext immunity)
        {
            if (Unit* target = DoSelectLowestHpFriendly(40.0f))
                DoCast(target, SPELL_SHROUD_OF_SPELL_WARDING);
            immunity.Repeat(20s, 25s);
        });
    }
};

struct npc_darkfallen_tactician : public DarkFallenAI
{
    npc_darkfallen_tactician(Creature* creature) : DarkFallenAI(creature) { }

    void ScheduleSpells() override
    {
        Scheduler.Schedule(8s, [this](TaskContext unholyStrike)
        {
            DoCastVictim(SPELL_UNHOLY_STRIKE);
            unholyStrike.Repeat(8s, 11s);
        })
        .Schedule(10s, [this](TaskContext shadowStep)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, false))
            {
                DoCast(target, SPELL_SHADOWSTEP);
                DoCast(target, SPELL_BLOOD_SAP);
            }
            shadowStep.Repeat(20s);
        });
    }
};

struct go_empowering_blood_orb : public GameObjectAI
{
    go_empowering_blood_orb(GameObject* go) : GameObjectAI(go) { }

    void Reset() override
    {
        if (Creature* trigger = me->SummonCreature(NPC_ORB_VISUAL_STALKER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN))
            _triggerGuid = trigger->GetGUID();
    }

    bool GossipHello(Player* player) override
    {
        me->CastSpell(player, SPELL_EMPOWERED_BLOOD, true);
        HandleObjectUse();
        return true;
    }

    void HandleObjectUse()
    {
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        me->SetGoAnimProgress(255);
        me->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
        if (Creature* trigger = ObjectAccessor::GetCreature(*me, _triggerGuid))
            trigger->DespawnOrUnsummon();
        _scheduler.Schedule(3s, [this](TaskContext /*context*/)
        {
            me->Delete();
        });
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_GUID)
        {
            if (Unit* target = ObjectAccessor::GetUnit(*me, guid))
                me->CastSpell(target, SPELL_EMPOWERED_BLOOD_3, true);
            HandleObjectUse();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _triggerGuid;
};

// 70227 - Empowered Blood
class spell_icc_empowered_blood : public AuraScript
{
    PrepareAuraScript(spell_icc_empowered_blood);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_EMPOWERED_BLOOD_2 });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_EMPOWERED_BLOOD_2, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_EMPOWERED_BLOOD_2);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_icc_empowered_blood::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_icc_empowered_blood::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70304 - Empowered Blood
class spell_icc_empowered_blood_3 : public AuraScript
{
    PrepareAuraScript(spell_icc_empowered_blood_3);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_EMPOWERED_BLOOD_4 });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_EMPOWERED_BLOOD_4, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_EMPOWERED_BLOOD_4);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_icc_empowered_blood_3::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_icc_empowered_blood_3::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70299 - Siphon Essence
class spell_icc_siphon_essence : public AuraScript
{
    PrepareAuraScript(spell_icc_siphon_essence);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_CANCEL)
            GetTarget()->GetAI()->DoAction(ACTION_SIPHON_INTERRUPTED);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_icc_siphon_essence::OnRemove, EFFECT_1, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70450 - Blood Mirror
class spell_darkfallen_blood_mirror : public SpellScript
{
    PrepareSpellScript(spell_darkfallen_blood_mirror);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOOD_MIRROR_2, SPELL_BLOOD_MIRROR_DAMAGE_SHARE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target)
        {
            return target->GetTypeId() != TYPEID_PLAYER;
        });

        if (targets.size() < 2)
            return;

        _targets = targets;
        Trinity::Containers::RandomResize(_targets, 2);
    }

    void HandleMirror(SpellEffIndex /*effIndex*/)
    {
        if (_targets.empty())
            return;

        Unit* caster = GetCaster();
        WorldObject* target = _targets.front();
        WorldObject* mirror = _targets.back();

        caster->CastSpell(target, SPELL_BLOOD_MIRROR_2, true);
        target->CastSpell(mirror, SPELL_BLOOD_MIRROR_DAMAGE_SHARE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_darkfallen_blood_mirror::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectLaunch += SpellEffectFn(spell_darkfallen_blood_mirror::HandleMirror, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    std::list<WorldObject*> _targets;
};

// 72131 - Remove Empowered Blood
// 70939 - Blood Queen Lana'thel - Clear all Status Ailments
class spell_generic_remove_empowered_blood : public SpellScript
{
    PrepareSpellScript(spell_generic_remove_empowered_blood);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_EMPOWERED_BLOOD });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_EMPOWERED_BLOOD);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_generic_remove_empowered_blood::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_icc_stoneform : public SpellScriptLoader
{
    public:
        spell_icc_stoneform() : SpellScriptLoader("spell_icc_stoneform") { }

        class spell_icc_stoneform_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_icc_stoneform_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->SetReactState(REACT_PASSIVE);
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    target->SetImmuneToPC(true);
                    target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_02);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->SetReactState(REACT_AGGRESSIVE);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    target->SetImmuneToPC(false);
                    target->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_icc_stoneform_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_icc_stoneform_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_icc_stoneform_AuraScript();
        }
};

class spell_icc_sprit_alarm : public SpellScriptLoader
{
    public:
        spell_icc_sprit_alarm() : SpellScriptLoader("spell_icc_sprit_alarm") { }

        class spell_icc_sprit_alarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_sprit_alarm_SpellScript);

            void HandleEvent(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                uint32 trapId = 0;
                switch (GetSpellInfo()->Effects[effIndex].MiscValue)
                {
                    case EVENT_AWAKEN_WARD_1:
                        trapId = GO_SPIRIT_ALARM_1;
                        break;
                    case EVENT_AWAKEN_WARD_2:
                        trapId = GO_SPIRIT_ALARM_2;
                        break;
                    case EVENT_AWAKEN_WARD_3:
                        trapId = GO_SPIRIT_ALARM_3;
                        break;
                    case EVENT_AWAKEN_WARD_4:
                        trapId = GO_SPIRIT_ALARM_4;
                        break;
                    default:
                        return;
                }

                if (GameObject* trap = GetGObjCaster()->FindNearestGameObject(trapId, 5.0f))
                    trap->SetRespawnTime(trap->GetGOInfo()->GetAutoCloseTime() / IN_MILLISECONDS);

                std::list<Creature*> wards;
                GetGObjCaster()->GetCreatureListWithEntryInGrid(wards, NPC_DEATHBOUND_WARD, 150.0f);
                wards.sort(Trinity::ObjectDistanceOrderPred(GetGObjCaster()));
                for (std::list<Creature*>::iterator itr = wards.begin(); itr != wards.end(); ++itr)
                {
                    if ((*itr)->IsAlive() && (*itr)->HasAura(SPELL_STONEFORM))
                    {
                        (*itr)->AI()->Talk(SAY_TRAP_ACTIVATE);
                        (*itr)->RemoveAurasDueToSpell(SPELL_STONEFORM);
                        if (Unit* target = (*itr)->SelectNearestTarget(150.0f))
                            (*itr)->AI()->AttackStart(target);
                        break;
                    }
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_icc_sprit_alarm_SpellScript::HandleEvent, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_icc_sprit_alarm_SpellScript();
        }
};

class DeathPlagueTargetSelector
{
    public:
        explicit DeathPlagueTargetSelector(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object) const
        {
            if (object == _caster)
                return true;

            if (object->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (object->ToUnit()->HasAura(SPELL_RECENTLY_INFECTED) || object->ToUnit()->HasAura(SPELL_DEATH_PLAGUE_AURA))
                return true;

            return false;
        }

    private:
        Unit* _caster;
};

class spell_frost_giant_death_plague : public SpellScriptLoader
{
    public:
        spell_frost_giant_death_plague() : SpellScriptLoader("spell_frost_giant_death_plague") { }

        class spell_frost_giant_death_plague_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frost_giant_death_plague_SpellScript);

        public:
            spell_frost_giant_death_plague_SpellScript()
            {
                _failed = false;
            }

        private:
            // First effect
            void CountTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetCaster());
                _failed = targets.empty();
            }

            // Second effect
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // Select valid targets for jump
                targets.remove_if(DeathPlagueTargetSelector(GetCaster()));
                if (!targets.empty())
                {
                    WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                    targets.clear();
                    targets.push_back(target);
                }

                targets.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit() != GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEATH_PLAGUE_AURA, true);
                else if (_failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool _failed;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_frost_giant_death_plague_SpellScript();
        }
};

class spell_icc_harvest_blight_specimen : public SpellScriptLoader
{
    public:
        spell_icc_harvest_blight_specimen() : SpellScriptLoader("spell_icc_harvest_blight_specimen") { }

        class spell_icc_harvest_blight_specimen_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_harvest_blight_specimen_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void HandleQuestComplete(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleQuestComplete, EFFECT_1, SPELL_EFFECT_QUEST_COMPLETE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_icc_harvest_blight_specimen_SpellScript();
        }
};

// 72585 - Soul Missile
class spell_icc_soul_missile : public SpellScriptLoader
{
    public:
        spell_icc_soul_missile() : SpellScriptLoader("spell_icc_soul_missile") { }

        class spell_icc_soul_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_soul_missile_SpellScript);

            void RelocateDest(SpellDestination& dest)
            {
                static Position const offset = { 0.0f, 0.0f, 200.0f, 0.0f };
                dest.RelocateOffset(offset);
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_icc_soul_missile_SpellScript::RelocateDest, EFFECT_0, TARGET_DEST_CASTER);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_icc_soul_missile_SpellScript();
        }
};

class spell_trigger_spell_from_caster_SpellScript : public SpellScript
{
    PrepareSpellScript(spell_trigger_spell_from_caster_SpellScript);

    public:
        spell_trigger_spell_from_caster_SpellScript(uint32 triggerId, TriggerCastFlags triggerFlags)
            : SpellScript(), _triggerId(triggerId), _triggerFlags(triggerFlags) { }

    private:
        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ _triggerId });
        }

        void HandleTrigger()
        {
            GetCaster()->CastSpell(GetHitUnit(), _triggerId, _triggerFlags);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_trigger_spell_from_caster_SpellScript::HandleTrigger);
        }

        uint32 _triggerId;
        TriggerCastFlags _triggerFlags;
};

spell_trigger_spell_from_caster::spell_trigger_spell_from_caster(char const* scriptName, uint32 triggerId)
    : SpellScriptLoader(scriptName), _triggerId(triggerId), _triggerFlags(TRIGGERED_FULL_MASK)
{
}

spell_trigger_spell_from_caster::spell_trigger_spell_from_caster(char const* scriptName, uint32 triggerId, TriggerCastFlags triggerFlags)
    : SpellScriptLoader(scriptName), _triggerId(triggerId), _triggerFlags(triggerFlags)
{
}

SpellScript* spell_trigger_spell_from_caster::GetSpellScript() const
{
    return new spell_trigger_spell_from_caster_SpellScript(_triggerId, _triggerFlags);
}

class at_icc_saurfang_portal : public AreaTriggerScript
{
    public:
        at_icc_saurfang_portal() : AreaTriggerScript("at_icc_saurfang_portal") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(DATA_DEATHBRINGER_SAURFANG) != DONE)
                return true;

            player->TeleportTo(631, 4126.35f, 2769.23f, 350.963f, 0.0f);

            if (instance->GetData(DATA_COLDFLAME_JETS) == NOT_STARTED)
            {
                // Process relocation now, to preload the grid and initialize traps
                player->GetMap()->PlayerRelocation(player, 4126.35f, 2769.23f, 350.963f, 0.0f);

                instance->SetData(DATA_COLDFLAME_JETS, IN_PROGRESS);
                std::list<Creature*> traps;
                GetCreatureListWithEntryInGrid(traps, player, NPC_FROST_FREEZE_TRAP, 120.0f);
                traps.sort(Trinity::ObjectDistanceOrderPred(player));
                bool instant = false;
                for (std::list<Creature*>::iterator itr = traps.begin(); itr != traps.end(); ++itr)
                {
                    (*itr)->AI()->DoAction(instant ? 1000 : 11000);
                    instant = !instant;
                }
            }

            return true;
        }
};

class at_icc_shutdown_traps : public AreaTriggerScript
{
    public:
        at_icc_shutdown_traps() : AreaTriggerScript("at_icc_shutdown_traps") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_UPPERSPIRE_TELE_ACT, DONE);

            return true;
        }
};

class at_icc_start_blood_quickening : public AreaTriggerScript
{
    public:
        at_icc_start_blood_quickening() : AreaTriggerScript("at_icc_start_blood_quickening") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_BLOOD_QUICKENING_STATE) == NOT_STARTED)
                    instance->SetData(DATA_BLOOD_QUICKENING_STATE, IN_PROGRESS);
            return true;
        }
};

void AddSC_icecrown_citadel()
{
    new npc_highlord_tirion_fordring_lh();
    new npc_rotting_frost_giant();
    new npc_frost_freeze_trap();
    new npc_alchemist_adrianna();
    new npc_arthas_teleport_visual();
    RegisterIcecrownCitadelCreatureAI(npc_entrance_faction_leader);
    RegisterIcecrownCitadelCreatureAI(npc_icc_orb_controller);
    RegisterIcecrownCitadelCreatureAI(npc_darkfallen_blood_knight);
    RegisterIcecrownCitadelCreatureAI(npc_darkfallen_noble);
    RegisterIcecrownCitadelCreatureAI(npc_vampiric_fiend);
    RegisterIcecrownCitadelCreatureAI(npc_darkfallen_archmage);
    RegisterIcecrownCitadelCreatureAI(npc_darkfallen_advisor);
    RegisterIcecrownCitadelCreatureAI(npc_darkfallen_tactician);
    RegisterGameObjectAI(go_empowering_blood_orb);
    RegisterAuraScript(spell_icc_empowered_blood);
    RegisterAuraScript(spell_icc_empowered_blood_3);
    RegisterAuraScript(spell_icc_siphon_essence);
    RegisterSpellScript(spell_darkfallen_blood_mirror);
    RegisterSpellScript(spell_generic_remove_empowered_blood);
    new spell_icc_stoneform();
    new spell_icc_sprit_alarm();
    new spell_frost_giant_death_plague();
    new spell_icc_harvest_blight_specimen();
    new spell_icc_soul_missile();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();
    new at_icc_start_blood_quickening();
}
