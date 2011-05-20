/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellAuraEffects.h"
#include "SmartAI.h"
#include "icecrown_citadel.h"
#include "Spell.h"

#define GOSSIP_TEXT(id) sObjectMgr->GetGossipText(id)->Options[0].Text_0
#define IS_TELEPORT_ENABLED(id) ((go->GetMap()->GetGameObject(instance->GetData64(id))->GetGoState() == GO_STATE_ACTIVE) ? true: false)
// Weekly quest support
//* Deprogramming
//* Securing the Ramparts        (DONE)
//* Residue Rendezvous
//* Blood Quickening
//* Respite for a Tormented Soul

enum Texts
{
    // Highlord Tirion Fordring (at Light's Hammer)
    SAY_TIRION_INTRO_1              = 0,
    SAY_TIRION_INTRO_2              = 1,
    SAY_TIRION_INTRO_3              = 2,
    SAY_TIRION_INTRO_4              = 3,
    SAY_TIRION_INTRO_H_5            = 4,
    SAY_TIRION_INTRO_A_5            = 5,

    // The Lich King (at Light's Hammer)
    SAY_LK_INTRO_1                  = 0,
    SAY_LK_INTRO_2                  = 1,
    SAY_LK_INTRO_3                  = 2,
    SAY_LK_INTRO_4                  = 3,
    SAY_LK_INTRO_5                  = 4,

    // Highlord Bolvar Fordragon (at Light's Hammer)
    SAY_BOLVAR_INTRO_1              = 0,

    // High Overlord Saurfang (at Light's Hammer)
    SAY_SAURFANG_INTRO_1            = 15,
    SAY_SAURFANG_INTRO_2            = 16,
    SAY_SAURFANG_INTRO_3            = 17,
    SAY_SAURFANG_INTRO_4            = 18,

    // Muradin Bronzebeard (at Light's Hammer)
    SAY_MURADIN_INTRO_1             = 13,
    SAY_MURADIN_INTRO_2             = 14,
    SAY_MURADIN_INTRO_3             = 15,

    // Rotting Frost Giant
    EMOTE_DEATH_PLAGUE_WARNING      = 0,

    // Sister Svalna
    SAY_SVALNA_KILL_CAPTAIN         = 1, // happens when she kills a captain
    SAY_SVALNA_KILL                 = 4,
    SAY_SVALNA_CAPTAIN_DEATH        = 5, // happens when a captain resurrected by her dies
    SAY_SVALNA_DEATH                = 6,
    EMOTE_SVALNA_IMPALE             = 7,
    EMOTE_SVALNA_BROKEN_SHIELD      = 8,

    SAY_CROK_INTRO_1                = 0, // Ready your arms, my Argent Brothers. The Vrykul will protect the Frost Queen with their lives.
    SAY_ARNATH_INTRO_2              = 5, // Even dying here beats spending another day collecting reagents for that madman, Finklestein.
    SAY_CROK_INTRO_3                = 1, // Enough idle banter! Our champions have arrived - support them as we push our way through the hall!
    SAY_SVALNA_EVENT_START          = 0, // You may have once fought beside me, Crok, but now you are nothing more than a traitor. Come, your second death approaches!
    SAY_CROK_COMBAT_WP_0            = 2, // Draw them back to us, and we'll assist you.
    SAY_CROK_COMBAT_WP_1            = 3, // Quickly, push on!
    SAY_CROK_FINAL_WP               = 4, // Her reinforcements will arrive shortly, we must bring her down quickly!
    SAY_SVALNA_RESURRECT_CAPTAINS   = 2, // Foolish Crok. You brought my reinforcements with you. Arise, Argent Champions, and serve the Lich King in death!
    SAY_CROK_COMBAT_SVALNA          = 5, // I'll draw her attacks. Return our brothers to their graves, then help me bring her down!
    SAY_SVALNA_AGGRO                = 3, // Come, Scourgebane. I'll show the master which of us is truly worthy of the title of "Champion"!
    SAY_CAPTAIN_DEATH               = 0,
    SAY_CAPTAIN_RESURRECTED         = 1,
    SAY_CAPTAIN_KILL                = 2,
    SAY_CAPTAIN_SECOND_DEATH        = 3,
    SAY_CAPTAIN_SURVIVE_TALK        = 4,
    SAY_CROK_WEAKENING_GAUNTLET     = 6,
    SAY_CROK_WEAKENING_SVALNA       = 7,
    SAY_CROK_DEATH                  = 8,
};
enum Spells
{
    SPELL_ON_ORGRIMS_HAMMER_DECK    = 70121, //maybe for gunship battle

    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE              = 72879,
    SPELL_DEATH_PLAGUE_AURA         = 72865,
    SPELL_RECENTLY_INFECTED         = 72884,
    SPELL_DEATH_PLAGUE_KILL         = 72867,
    SPELL_STOMP                     = 64652,
    SPELL_ARCTIC_BREATH             = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS            = 70460,

    // Alchemist Adrianna
    SPELL_HARVEST_BLIGHT_SPECIMEN   = 72155,
    SPELL_HARVEST_BLIGHT_SPECIMEN25 = 72162,

    SPELL_SPIRIT_ALARM_1            = 70536,
    SPELL_SPIRIT_ALARM_2            = 70546,
    SPELL_SPIRIT_ALARM_3            = 70545,
    SPELL_SPIRIT_ALARM_4            = 70547,
    SPELL_DARK_RECKONING            = 69483,
    SPELL_DARK_RECKONING_SIPHON_LIFE= 69482,
    SPELL_AURA_OF_DARKNESS          = 69491,
    SPELL_SEVERED_ESSENCE_10        = 71906,
    SPELL_SEVERED_ESSENCE_25        = 71942,
    //Severed essence spells
    SPELL_CLONE_PLAYER              = 57507,
    //Druid spells
    SPELL_CAT_FORM                  = 57655,
    SPELL_MANGLE                    = 71925,
    SPELL_RIP                       = 71926,
    //Warlock
    SPELL_CORRUPTION                = 71937,
    SPELL_SHADOW_BOLT               = 71936,
    SPELL_RAIN_OF_CHAOS             = 71965,
    //Shaman
    SPELL_REPLENISHING_RAINS        = 71956,
    SPELL_LIGHTNING_BOLT            = 71934,
    //Rouge
    SPELL_DISENGAGE                 = 57635,
    SPELL_FOCUSED_ATTACKS           = 71955,
    SPELL_SINISTER_STRIKE           = 57640,
    SPELL_EVISCERATE                = 71933,
    //Mage
    SPELL_FIREBALL                  = 71928,
    //Warior
    SPELL_BLOODTHIRST               = 71938,
    SPELL_HEROIC_LEAP               = 71961,
    //Dk
    SPELL_DEATH_GRIP                = 57602,
    SPELL_NECROTIC_STRIKE           = 71951,
    SPELL_PLAGUE_STRIKE             = 71924,
    //Priest
    SPELL_GREATER_HEAL              = 71931,
    SPELL_RENEW                     = 71932,
    //Paladin
    SPELL_CLEANSE                   = 57767,
    SPELL_FLASH_OF_LIGHT            = 71930,
    SPELL_RADIANCE_AURA             = 71953,
    //Hunter
    SPELL_SHOOT_10                  = 71927,
    SPELL_SHOOT_25                  = 72258,

    // Crok Scourgebane
    SPELL_ICEBOUND_ARMOR            = 70714,
    SPELL_SCOURGE_STRIKE            = 71488,
    SPELL_DEATH_STRIKE              = 71489,

    // Sister Svalna
    SPELL_CARESS_OF_DEATH           = 70078,
    SPELL_IMPALING_SPEAR_KILL       = 70196,
    SPELL_REVIVE_CHAMPION           = 70053,
    SPELL_UNDEATH                   = 70089,
    SPELL_IMPALING_SPEAR            = 71443,
    SPELL_AETHER_SHIELD             = 71463,
    SPELL_HURL_SPEAR                = 71466,

    // Captain Arnath
    SPELL_DOMINATE_MIND             = 14515,
    SPELL_FLASH_HEAL_NORMAL         = 71595,
    SPELL_POWER_WORD_SHIELD_NORMAL  = 71548,
    SPELL_SMITE_NORMAL              = 71546,
    SPELL_FLASH_HEAL_UNDEAD         = 71782,
    SPELL_POWER_WORD_SHIELD_UNDEAD  = 71780,
    SPELL_SMITE_UNDEAD              = 71778,

    // Captain Brandon
    SPELL_CRUSADER_STRIKE           = 71549,
    SPELL_DIVINE_SHIELD             = 71550,
    SPELL_JUDGEMENT_OF_COMMAND      = 71551,
    SPELL_HAMMER_OF_BETRAYAL        = 71784,

    // Captain Grondel
    SPELL_CHARGE                    = 71553,
    SPELL_MORTAL_STRIKE             = 71552,
    SPELL_SUNDER_ARMOR              = 71554,
    SPELL_CONFLAGRATION             = 71785,

    // Captain Rupert
    SPELL_FEL_IRON_BOMB_NORMAL      = 71592,
    SPELL_MACHINE_GUN_NORMAL        = 71594,
    SPELL_ROCKET_LAUNCH_NORMAL      = 71590,
    SPELL_FEL_IRON_BOMB_UNDEAD      = 71787,
    SPELL_MACHINE_GUN_UNDEAD        = 71788,
    SPELL_ROCKET_LAUNCH_UNDEAD      = 71786,
};

// Helper defines
// Captain Arnath
#define SPELL_FLASH_HEAL        (IsUndead ? SPELL_FLASH_HEAL_UNDEAD : SPELL_FLASH_HEAL_NORMAL)
#define SPELL_POWER_WORD_SHIELD (IsUndead ? SPELL_POWER_WORD_SHIELD_UNDEAD : SPELL_POWER_WORD_SHIELD_NORMAL)
#define SPELL_SMITE             (IsUndead ? SPELL_SMITE_UNDEAD : SPELL_SMITE_NORMAL)

// Captain Rupert
#define SPELL_FEL_IRON_BOMB     (IsUndead ? SPELL_FEL_IRON_BOMB_UNDEAD : SPELL_FEL_IRON_BOMB_NORMAL)
#define SPELL_MACHINE_GUN       (IsUndead ? SPELL_MACHINE_GUN_UNDEAD : SPELL_MACHINE_GUN_NORMAL)
#define SPELL_ROCKET_LAUNCH     (IsUndead ? SPELL_ROCKET_LAUNCH_UNDEAD : SPELL_ROCKET_LAUNCH_NORMAL)

enum Events
{
    // Highlord Tirion Fordring (at Light's Hammer)
    // The Lich King (at Light's Hammer)
    // Highlord Bolvar Fordragon (at Light's Hammer)
    // High Overlord Saurfang (at Light's Hammer)
    // Muradin Bronzebeard (at Light's Hammer)
    EVENT_TIRION_INTRO_2                = 1,
    EVENT_TIRION_INTRO_3                = 2,
    EVENT_TIRION_INTRO_4                = 3,
    EVENT_TIRION_INTRO_5                = 4,
    EVENT_LK_INTRO_1                    = 5,
    EVENT_TIRION_INTRO_6                = 6,
    EVENT_LK_INTRO_2                    = 7,
    EVENT_LK_INTRO_3                    = 8,
    EVENT_LK_INTRO_4                    = 9,
    EVENT_BOLVAR_INTRO_1                = 10,
    EVENT_LK_INTRO_5                    = 11,
    EVENT_SAURFANG_INTRO_1              = 12,
    EVENT_TIRION_INTRO_H_7              = 13,
    EVENT_SAURFANG_INTRO_2              = 14,
    EVENT_SAURFANG_INTRO_3              = 15,
    EVENT_SAURFANG_INTRO_4              = 16,
    EVENT_SAURFANG_RUN                  = 17,
    EVENT_MURADIN_INTRO_1               = 18,
    EVENT_MURADIN_INTRO_2               = 19,
    EVENT_MURADIN_INTRO_3               = 20,
    EVENT_TIRION_INTRO_A_7              = 21,
    EVENT_MURADIN_INTRO_4               = 22,
    EVENT_MURADIN_INTRO_5               = 23,
    EVENT_MURADIN_RUN                   = 24,

    // Rotting Frost Giant
    EVENT_DEATH_PLAGUE                  = 25,
    EVENT_STOMP                         = 26,
    EVENT_ARCTIC_BREATH                 = 27,

    // Frost Freeze Trap
    EVENT_ACTIVATE_TRAP                 = 28,
    
    //Deathspeaker High Priest
    EVENT_DARK_RECKONING                = 29,
    //Val'kyr Herald
    EVENT_SEVERED_ESSENCE               = 30,

    //Druid spells
    EVENT_CAT_FORM                      = 31,
    EVENT_MANGLE                        = 32,
    EVENT_RIP                           = 33,
    //Warlock
    EVENT_CORRUPTION                    = 34,
    EVENT_SHADOW_BOLT                   = 35,
    EVENT_RAIN_OF_CHAOS                 = 36,
    //Shaman
    EVENT_REPLENISHING_RAINS            = 37,
    EVENT_LIGHTNING_BOLT                = 38,
    EVENT_CAN_CAST_REPLENISHING_RAINS   = 39,
    //Rogue
    EVENT_FOCUSED_ATTACKS               = 40,
    EVENT_SINISTER_STRIKE               = 41,
    EVENT_EVISCERATE                    = 42,
    //Mage
    EVENT_FIREBALL                      = 43,
    //Warrior
    EVENT_BLOODTHIRST                   = 44,
    EVENT_HEROIC_LEAP                   = 45,
    //Dead Knight
    EVENT_DEATH_GRIP                    = 46,
    EVENT_NECROTIC_STRIKE               = 47,
    EVENT_PLAGUE_STRIKE                 = 48,
    //Priest
    EVENT_GREATER_HEAL                  = 49,
    EVENT_RENEW                         = 50,
    //Paladin
    EVENT_CLEANSE                       = 51,
    EVENT_FLASH_OF_LIGHT                = 52,
    EVENT_RADIANCE_AURA                 = 53,
    EVENT_CAN_CAST_RADIANCE_AURA        = 54, 
    //Hunter
    EVENT_SHOOT                         = 55,
    EVENT_DISENGAGE                     = 56,
    EVENT_CAN_CAST_DISENGAGE            = 57,

    // Crok Scourgebane
    EVENT_SCOURGE_STRIKE                = 58,
    EVENT_DEATH_STRIKE                  = 59,
    EVENT_HEALTH_CHECK                  = 60,
    EVENT_CROK_INTRO_3                  = 61,
    EVENT_START_PATHING                 = 62,

    // Sister Svalna
    EVENT_ARNATH_INTRO_2                = 63,
    EVENT_SVALNA_START                  = 64,
    EVENT_SVALNA_RESURRECT              = 65,
    EVENT_SVALNA_COMBAT                 = 66,
    EVENT_IMPALING_SPEAR                = 67,
    EVENT_AETHER_SHIELD                 = 68,

    // Captain Arnath
    EVENT_ARNATH_FLASH_HEAL             = 69,
    EVENT_ARNATH_PW_SHIELD              = 70,
    EVENT_ARNATH_SMITE                  = 71,
    EVENT_ARNATH_DOMINATE_MIND          = 72,

    // Captain Brandon
    EVENT_BRANDON_CRUSADER_STRIKE       = 73,
    EVENT_BRANDON_DIVINE_SHIELD         = 74,
    EVENT_BRANDON_JUDGEMENT_OF_COMMAND  = 75,
    EVENT_BRANDON_HAMMER_OF_BETRAYAL    = 76,

    // Captain Grondel
    EVENT_GRONDEL_CHARGE_CHECK          = 77,
    EVENT_GRONDEL_MORTAL_STRIKE         = 78,
    EVENT_GRONDEL_SUNDER_ARMOR          = 79,
    EVENT_GRONDEL_CONFLAGRATION         = 80,

    // Captain Rupert
    EVENT_RUPERT_FEL_IRON_BOMB          = 81,
    EVENT_RUPERT_MACHINE_GUN            = 82,
    EVENT_RUPERT_ROCKET_LAUNCH          = 83,
};
enum eData
{
    DATA_PLAYER_CLASS = 2,
};

enum eTeleportGossips
{
    GOSSIP_TELEPORT_LIGHTS_HAMMER           = 800000,
    GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED   = 800001,
    GOSSIP_TELEPORT_RAMPART_OF_SKULLS       = 800002,
    GOSSIP_TELEPORT_DEATHBRINGERS_RISE      = 800003,
    GOSSIP_TELEPORT_UPPER_SPIRE             = 800004,
    GOSSIP_TELEPORT_SINDRAGOSAS_LAIR        = 800005,
    GOSSIP_TELEPORT_FROZEN_THRONE           = 800006
};
enum eTrapEvents
{
    EVENT_COLDFLAME_JETS = 1,
    EVENT_REMOVE_COLDFLAME_JETS
};
enum eTrapActions
{
    ACTION_DISARM_FROST_TRAP = 2
};
enum DataTypesICC    
{
    DATA_DAMNED_KILLS       = 1,    
};
enum Actions
{
    // Sister Svalna
    ACTION_KILL_CAPTAIN         = 1,
    ACTION_START_GAUNTLET       = 2,
    ACTION_RESURRECT_CAPTAINS   = 3,
    ACTION_CAPTAIN_DIES         = 4,
    ACTION_RESET_EVENT          = 5,
};

class FrostwingVrykulSearcher
{
    public:
        FrostwingVrykulSearcher(Creature const* source, float range) : _source(source), _range(range) {}

        bool operator()(Unit* unit)
        {
            if (!unit->isAlive())
                return false;

            switch (unit->GetEntry())
            {
                case NPC_YMIRJAR_BATTLE_MAIDEN:
                case NPC_YMIRJAR_DEATHBRINGER:
                case NPC_YMIRJAR_FROSTBINDER:
                case NPC_YMIRJAR_HUNTRESS:
                case NPC_YMIRJAR_WARLORD:
                    break;
                default:
                    return false;
            }

            if (!unit->IsWithinDist(_source, _range, false))
                return false;

            return true;
        }

    private:
        Creature const* _source;
        float _range;
};

class FrostwingGauntletRespawner
{
    public:
        void operator()(Creature* creature)
        {
            switch (creature->GetOriginalEntry())
            {
                case NPC_YMIRJAR_BATTLE_MAIDEN:
                case NPC_YMIRJAR_DEATHBRINGER:
                case NPC_YMIRJAR_FROSTBINDER:
                case NPC_YMIRJAR_HUNTRESS:
                case NPC_YMIRJAR_WARLORD:
                    break;
                case NPC_CROK_SCOURGEBANE:
                case NPC_CAPTAIN_ARNATH:
                case NPC_CAPTAIN_BRANDON:
                case NPC_CAPTAIN_GRONDEL:
                case NPC_CAPTAIN_RUPERT:
                    creature->AI()->DoAction(ACTION_RESET_EVENT);
                    break;
                case NPC_SISTER_SVALNA:
                    creature->AI()->DoAction(ACTION_RESET_EVENT);
                    // return, this creature is never dead if event is reset
                    return;
                default:
                    return;
            }

            uint32 corpseDelay = creature->GetCorpseDelay();
            uint32 respawnDelay = creature->GetRespawnDelay();
            creature->SetCorpseDelay(1);
            creature->SetRespawnDelay(2);

            if (CreatureData const* data = creature->GetCreatureData())
                creature->SetPosition(data->posX, data->posY, data->posZ, data->orientation);
            creature->ForcedDespawn();

            creature->SetCorpseDelay(corpseDelay);
            creature->SetRespawnDelay(respawnDelay);
        }
};

class CaptainSurviveTalk : public BasicEvent
{
    public:
        explicit CaptainSurviveTalk(Creature const& owner) : _owner(owner) { }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
        {
            _owner.AI()->Talk(SAY_CAPTAIN_SURVIVE_TALK);
            return true;
        }

    private:
        Creature const& _owner;
};

// at Light's Hammer
class npc_highlord_tirion_fordring_lh : public CreatureScript
{
    public:
        npc_highlord_tirion_fordring_lh() : CreatureScript("npc_highlord_tirion_fordring_lh") { }    
        struct npc_highlord_tirion_fordringAI : public ScriptedAI    
        {    
            npc_highlord_tirion_fordringAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
            {    
            }    
    
            void Reset()
            {    
                events.Reset();    
                _theLichKing = 0;    
                _bolvarFordragon = 0;    
                _factionNPC = 0;
                _damnedKills = 0;    
            }    
    
            // IMPORTANT NOTE: This is triggered from per-GUID scripts    
            // of The Damned SAI    
            void SetData(uint32 type, uint32 data)    
            {    
                if (!instance)
                    return;

                if (type == DATA_DAMNED_KILLS && data == 1)    
                {    
                    if (++_damnedKills == 2)    
                    {    
                        if (Creature* theLichKing = me->FindNearestCreature(NPC_THE_LICH_KING_LH, 150.0f))    
                        {
                            if (Creature* bolvarFordragon = me->FindNearestCreature(NPC_HIGHLORD_BOLVAR_FORDRAGON_LH, 150.0f))
                            {
                                if (Creature* factionNPC = me->FindNearestCreature(instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE ? NPC_SE_HIGH_OVERLORD_SAURFANG : NPC_SE_MURADIN_BRONZEBEARD, 50.0f))
                                {
                                    me->setActive(true);
                                    _theLichKing = theLichKing->GetGUID();
                                    theLichKing->setActive(true);
                                    _bolvarFordragon = bolvarFordragon->GetGUID();
                                    bolvarFordragon->setActive(true);
                                    _factionNPC = factionNPC->GetGUID();
                                    factionNPC->setActive(true);
                                }
                            }    
                        }    
                        if (!_bolvarFordragon || !_theLichKing || !_factionNPC)
                            return;    
    
                        Talk(SAY_TIRION_INTRO_1);    
                        events.ScheduleEvent(EVENT_TIRION_INTRO_2, 4000);    
                        events.ScheduleEvent(EVENT_TIRION_INTRO_3, 14000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_4, 18000);    
                        events.ScheduleEvent(EVENT_TIRION_INTRO_5, 31000);    
                        events.ScheduleEvent(EVENT_LK_INTRO_1, 35000);
                        events.ScheduleEvent(EVENT_TIRION_INTRO_6, 51000);
                        events.ScheduleEvent(EVENT_LK_INTRO_2, 58000);    
                        events.ScheduleEvent(EVENT_LK_INTRO_3, 74000);    
                        events.ScheduleEvent(EVENT_LK_INTRO_4, 86000);    
                        events.ScheduleEvent(EVENT_BOLVAR_INTRO_1, 100000);    
                        events.ScheduleEvent(EVENT_LK_INTRO_5, 108000);


                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_1, 120000);
                            events.ScheduleEvent(EVENT_TIRION_INTRO_H_7, 129000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_2, 139000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_3, 150000);
                            events.ScheduleEvent(EVENT_SAURFANG_INTRO_4, 162000);
                            events.ScheduleEvent(EVENT_SAURFANG_RUN, 170000);
                        }
                        else
                        {
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_1, 120000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_2, 124000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_3, 127000);
                            events.ScheduleEvent(EVENT_TIRION_INTRO_A_7, 136000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_4, 144000);
                            events.ScheduleEvent(EVENT_MURADIN_INTRO_5, 151000);
                            events.ScheduleEvent(EVENT_MURADIN_RUN, 157000);
                        }
                    }    
                }
            }    
    
            void UpdateAI(uint32 const diff)    
            {    
                if (_damnedKills != 2)    
                    return;    
    
                events.Update(diff);    
    
                while (uint32 eventId = events.ExecuteEvent())    
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
                            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT_NOSHEATHE);
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
                            }    
                            break;    
                        case EVENT_LK_INTRO_5:    
                            if (Creature* theLichKing = ObjectAccessor::GetCreature(*me, _theLichKing))
                            {    
                                theLichKing->AI()->Talk(SAY_LK_INTRO_5);    
                                theLichKing->setActive(false);    
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
                                factionNPC->GetMotionMaster()->MovePath(factionNPC->GetDBTableGUIDLow()*10, false);
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
            EventMap events;
            InstanceScript* const instance;    
            uint64 _theLichKing;
            uint64 _bolvarFordragon;
            uint64 _factionNPC;    
            uint16 _damnedKills;    
        };
    
        CreatureAI* GetAI(Creature* creature) const    
        {    
            return GetIcecrownCitadelAI<npc_highlord_tirion_fordringAI>(creature);
        }
};

class go_icecrown_teleporter : public GameObjectScript
{

public:
    go_icecrown_teleporter() : GameObjectScript("go_icecrown_teleporter") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* instance = go->GetInstanceScript();
        if(!instance)
            return false;
        if (instance->IsEncounterInProgress())
            return false;

        switch (go->GetEntry())
        {
            case GO_TELEPORT_ORATORY_OF_THE_DAMNED:
                instance->SetData(DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_RAMPART_OF_SKULLS:
                instance->SetData(DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED, DONE);
                instance->SetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_DEATHBRINGER_RISE:
                instance->SetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_UPPER_SPIRE:
                instance->SetData(DATA_TELEPORT_UPPER_SPIRE_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_SINDRAGOSA_S_LAIR:
                instance->SetData(DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED, DONE);
                break;
            case GO_TELEPORT_FROZEN_THRONE:
                instance->SetData(DATA_TELEPORT_FROZEN_THRONE_ACTIVATED, DONE);
                break;
        }
        instance->HandleGameObject(NULL, true, go);
        if (go->GetEntry() != GO_TELEPORT_LIGHT_S_HAMMER)
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_LIGHTS_HAMMER), GOSSIP_SENDER_MAIN, LIGHT_S_HAMMER_TELEPORT);

        if (go->GetEntry() != GO_TELEPORT_ORATORY_OF_THE_DAMNED && instance->GetData(DATA_LORD_MARROWGAR_EVENT) == DONE && instance->GetData(DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_ORATORY_OF_THE_DAMNED);
        if (go->GetEntry() != GO_TELEPORT_RAMPART_OF_SKULLS && instance->GetData(DATA_DEATHWHISPER_EVENT) == DONE && instance->GetData(DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_RAMPART_OF_SKULLS), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_RAMPART_OF_SKULLS);
        if (go->GetEntry() != GO_TELEPORT_DEATHBRINGER_RISE
            && instance->GetData(DATA_GUNSHIP_BATTLE_EVENT) == DONE
            && instance->GetData(DATA_DEATHWHISPER_EVENT) == DONE
            && instance->GetData(DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED) == DONE
                        //&& IS_TELEPORT_ENABLED(DATA_TELEPORT_DEATHBRINGERS_RISE) //Disabled until Gunship Battle encounter is implemented
            )
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_DEATHBRINGERS_RISE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_DEATHBRINGER_S_RISE);
        }
        if (go->GetEntry() != GO_TELEPORT_UPPER_SPIRE &&
            instance->GetData(DATA_SAURFANG_EVENT) == DONE && instance->GetData(DATA_TELEPORT_UPPER_SPIRE_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_UPPER_SPIRE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_UPPER_SPIRE);
        if (go->GetEntry() != GO_TELEPORT_SINDRAGOSA_S_LAIR &&
            instance->GetData(DATA_VALITHRIA_DREAMWALKER_EVENT) == DONE && instance->GetData(DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_SINDRAGOSAS_LAIR), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_SINDRAGOSA_S_LAIR);
        if (instance->GetData(DATA_BLOOD_QUEEN_LANA_THEL_EVENT) == DONE && instance->GetData(DATA_PROFESSOR_PUTRICIDE) == DONE && instance->GetData(DATA_SINDRAGOSA) == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_FROZEN_THRONE), GOSSIP_SENDER_MAIN, SPELL_TELEPORT_ICC_FROZEN_THRONE);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, go->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 uiSender, uint32 uiAction)
        {
            //player->PlayerTalkClass->ClearMenus();
            if(!player->getAttackers().empty())
                return false;

            SpellEntry const* spell = sSpellStore.LookupEntry(uiAction);
            if (!spell)
                return false;

            if (player->isInCombat())
            {
                Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (uiSender == GOSSIP_SENDER_MAIN)
            {
                //Preload the Lich King's platform before teleporting player to there
                if (uiAction == SPELL_TELEPORT_ICC_FROZEN_THRONE)
                    player->GetMap()->LoadGrid(530.3f, -2122.67f);
                player->CastSpell(player, spell, true);
                //Give him 2 tries, just in case if player will fall through the ground
                if (uiAction == SPELL_TELEPORT_ICC_FROZEN_THRONE)
                    TeleportPlayerToFrozenThrone(player);
            }
            return true;
        }
};

class spell_icc_spirit_alarm : public SpellScriptLoader
{
    public:
        spell_icc_spirit_alarm() : SpellScriptLoader("spell_icc_spirit_alarm") { }

        class spell_icc_spirit_alarm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_icc_spirit_alarm_SpellScript);

            void AwakenDeathboundWard(SpellEffIndex effIndex)
            {
                if (!GetTargetUnit() || GetTargetUnit()->GetTypeId() != TYPEID_PLAYER)
                    return;
                if (!GetCaster())
                    return;
                InstanceScript *instance = GetCaster()->GetInstanceScript();
                GameObject *spiritAlarm = NULL;
                Creature *pWard = NULL;
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_SPIRIT_ALARM_1:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM1));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD1));
                        //Preload Spirit Alarm traps near Lord Marrowgar
                        spiritAlarm->GetMap()->LoadGrid(-273.845f, 2220.22f);
                        spiritAlarm->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM3))->SetPhaseMask(1, true);
                        break;
                    case SPELL_SPIRIT_ALARM_2:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM2));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD2));
                        //Preload Spirit Alarm traps near Lord Marrowgar
                        spiritAlarm->GetMap()->LoadGrid(-273.845f, 2220.22f);
                        spiritAlarm->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM4))->SetPhaseMask(1, true);
                        break;
                    case SPELL_SPIRIT_ALARM_3:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM3));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD3));
                        break;
                    case SPELL_SPIRIT_ALARM_4:
                        spiritAlarm = GetCaster()->GetMap()->GetGameObject(instance->GetData64(GUID_SPIRIT_ALARM4));
                        pWard = spiritAlarm->GetMap()->GetCreature(instance->GetData64(GUID_DEATHBOUND_WARD4));
                        break;
                }
                spiritAlarm->setActive(false);
                if (pWard && pWard->isAlive())
                {
                    pWard->SetReactState(REACT_AGGRESSIVE);
                    pWard->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pWard->AI()->AttackStart(GetTargetUnit());
                }
            }
            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_spirit_alarm_SpellScript::AwakenDeathboundWard, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_spirit_alarm_SpellScript();
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

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                events.ScheduleEvent(EVENT_STOMP, urand(5000, 8000));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(10000, 15000));
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEATH_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(EMOTE_DEATH_PLAGUE_WARNING, target->GetGUID());
                                DoCast(target, SPELL_DEATH_PLAGUE);
                            }
                            events.ScheduleEvent(EVENT_DEATH_PLAGUE, 15000);
                            break;
                        case EVENT_STOMP:
                            DoCastVictim(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, urand(15000, 18000));
                            break;
                        case EVENT_ARCTIC_BREATH:
                            DoCastVictim(SPELL_ARCTIC_BREATH);
                            events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(26000, 33000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_rotting_frost_giantAI>(creature);
        }
};

class npc_frost_freeze_trap : public CreatureScript
{
    public:
        npc_frost_freeze_trap() : CreatureScript("npc_frost_freeze_trap") { }

        struct npc_frost_freeze_trapAI: public Scripted_NoMovementAI
        {
            npc_frost_freeze_trapAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case 1000:
                    case 11000:
                        events.ScheduleEvent(EVENT_ACTIVATE_TRAP, uint32(action));
                        break;
                    case ACTION_STOP_TRAPS:
                        me->RemoveAurasDueToSpell(SPELL_COLDFLAME_JETS);
                        events.CancelEvent(EVENT_ACTIVATE_TRAP);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ACTIVATE_TRAP)
                {
                    DoCast(me, SPELL_COLDFLAME_JETS);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRAP, 22000);
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_frost_freeze_trapAI>(creature);
        }
};

class npc_alchemist_adrianna : public CreatureScript
{
    public:
        npc_alchemist_adrianna() : CreatureScript("npc_alchemist_adrianna") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (!creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN) && !creature->FindCurrentSpellBySpellId(SPELL_HARVEST_BLIGHT_SPECIMEN25))
                if (player->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE) && player->HasAura(SPELL_GREEN_BLIGHT_RESIDUE))
                    creature->CastSpell(creature, SPELL_HARVEST_BLIGHT_SPECIMEN, false);
            return false;
        }
};

class boss_sister_svalna : public CreatureScript
{
    public:
        boss_sister_svalna() : CreatureScript("boss_sister_svalna") { }

        struct boss_sister_svalnaAI : public BossAI
        {
            boss_sister_svalnaAI(Creature* creature) : BossAI(creature, DATA_SISTER_SVALNA),
                _isEventInProgress(false)
            {
            }

            void InitializeAI()
            {
                if (!me->isDead())
                    Reset();

                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                _Reset();
                me->SetReactState(REACT_DEFENSIVE);
                _isEventInProgress = false;
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_SVALNA_DEATH);

                uint64 delay = 1;
                for (uint32 i = 0; i < 4; ++i)
                {
                    if (Creature* crusader = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_CAPTAIN_ARNATH + i)))
                    {
                        if (crusader->isAlive() && crusader->GetEntry() == crusader->GetCreatureData()->id)
                        {
                            crusader->m_Events.AddEvent(new CaptainSurviveTalk(*crusader), crusader->m_Events.CalculateTime(delay));
                            delay += 6000;
                        }
                    }
                }
            }

            void EnterCombat(Unit* /*attacker*/)
            {
                _EnterCombat();
                if (Creature* crok = ObjectAccessor::GetCreature(*me, instance->GetData64(GUID_CROK_SCOURGEBANE)))
                    crok->AI()->Talk(SAY_CROK_COMBAT_SVALNA);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                events.ScheduleEvent(EVENT_SVALNA_COMBAT, 9000);
                events.ScheduleEvent(EVENT_IMPALING_SPEAR, urand(40000, 50000));
                events.ScheduleEvent(EVENT_AETHER_SHIELD, urand(100000, 110000));
            }

            void KilledUnit(Unit* victim)
            {
                switch (victim->GetTypeId())
                {
                    case TYPEID_PLAYER:
                        Talk(SAY_SVALNA_KILL);
                        break;
                    case TYPEID_UNIT:
                        switch (victim->GetEntry())
                        {
                            case NPC_CAPTAIN_ARNATH:
                            case NPC_CAPTAIN_BRANDON:
                            case NPC_CAPTAIN_GRONDEL:
                            case NPC_CAPTAIN_RUPERT:
                                Talk(SAY_SVALNA_KILL_CAPTAIN);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                me->SetReactState(REACT_PASSIVE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_KILL_CAPTAIN:
                        me->CastCustomSpell(SPELL_CARESS_OF_DEATH, SPELLVALUE_MAX_TARGETS, 1, me, true);
                        break;
                    case ACTION_START_GAUNTLET:
                        me->setActive(true);
                        _isEventInProgress = true;
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);
                        events.ScheduleEvent(EVENT_SVALNA_START, 25000);
                        break;
                    case ACTION_RESURRECT_CAPTAINS:
                        events.ScheduleEvent(EVENT_SVALNA_RESURRECT, 7000);
                        break;
                    case ACTION_CAPTAIN_DIES:
                        Talk(SAY_SVALNA_CAPTAIN_DEATH);
                        break;
                    case ACTION_RESET_EVENT:
                        me->setActive(false);
                        Reset();
                        break;
                    default:
                        break;
                }
            }

            void SpellHit(Unit* caster, SpellEntry const* spell)
            {
                if (spell->Id == SPELL_HURL_SPEAR && me->HasAura(SPELL_AETHER_SHIELD))
                {
                    me->RemoveAurasDueToSpell(SPELL_AETHER_SHIELD);
                    Talk(EMOTE_SVALNA_BROKEN_SHIELD, caster->GetGUID());
                }
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_REVIVE_CHAMPION:
                        if (!_isEventInProgress)
                            break;
                        _isEventInProgress = false;
                        me->setActive(false);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);
                        break;
                    case SPELL_IMPALING_SPEAR_KILL:
                        me->Kill(target);
                        break;
                    case SPELL_IMPALING_SPEAR:
                        if (TempSummon* summon = target->SummonCreature(NPC_IMPALING_SPEAR, *target))
                        {
                            Talk(EMOTE_SVALNA_IMPALE, target->GetGUID());
                            summon->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_UNK1 | 0x4000);
                            summon->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, target, false);
                        }
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() && !_isEventInProgress)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SVALNA_START:
                            Talk(SAY_SVALNA_EVENT_START);
                            break;
                        case EVENT_SVALNA_RESURRECT:
                            Talk(SAY_SVALNA_RESURRECT_CAPTAINS);
                            me->CastSpell(me, SPELL_REVIVE_CHAMPION, false);
                            break;
                        case EVENT_SVALNA_COMBAT:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                            me->SetReactState(REACT_DEFENSIVE);
                            Talk(SAY_SVALNA_AGGRO);
                            break;
                        case EVENT_IMPALING_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_IMPALING_SPEAR))
                                DoCast(target, SPELL_IMPALING_SPEAR);
                            events.ScheduleEvent(EVENT_IMPALING_SPEAR, urand(20000, 25000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _isEventInProgress;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<boss_sister_svalnaAI>(creature);
        }
};

class npc_crok_scourgebane : public CreatureScript
{
    public:
        npc_crok_scourgebane() : CreatureScript("npc_crok_scourgebane") { }

        struct npc_crok_scourgebaneAI : public npc_escortAI
        {
            npc_crok_scourgebaneAI(Creature* creature) : npc_escortAI(creature),
                _instance(creature->GetInstanceScript()), _respawnTime(creature->GetRespawnDelay()),
                _corpseDelay(creature->GetCorpseDelay())
            {
                SetDespawnAtEnd(false);
                SetDespawnAtFar(false);
                _isEventActive = false;
                _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
                _didUnderTenPercentText = false;
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, urand(7500, 12500));
                _events.ScheduleEvent(EVENT_DEATH_STRIKE, urand(25000, 30000));
                me->SetReactState(REACT_DEFENSIVE);
                _didUnderTenPercentText = false;
                _wipeCheckTimer = 1000;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_GAUNTLET)
                {
                    if (_isEventDone || !me->isAlive())
                        return;

                    _isEventActive = true;
                    _isEventDone = true;
                    // Load Grid with Sister Svalna
                    me->GetMap()->LoadGrid(4356.71f, 2484.33f);
                    if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                        svalna->AI()->DoAction(ACTION_START_GAUNTLET);
                    Talk(SAY_CROK_INTRO_1);
                    _events.ScheduleEvent(EVENT_ARNATH_INTRO_2, 7000);
                    _events.ScheduleEvent(EVENT_CROK_INTRO_3, 14000);
                    _events.ScheduleEvent(EVENT_START_PATHING, 37000);
                    me->setActive(true);
                    for (uint32 i = 0; i < 4; ++i)
                        if (Creature* crusader = ObjectAccessor::GetCreature(*me, _instance->GetData64(GUID_CAPTAIN_ARNATH + i)))
                            crusader->AI()->DoAction(ACTION_START_GAUNTLET);
                }
                else if (action == ACTION_RESET_EVENT)
                {
                    _isEventActive = false;
                    _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
                    me->setActive(false);
                    _aliveTrash.clear();
                    _currentWPid = 0;
                }
            }

            void SetGUID(uint64 const& guid, int32 type/* = 0*/)
            {
                if (type == ACTION_VRYKUL_DEATH)
                {
                    _aliveTrash.erase(guid);
                    if (_aliveTrash.empty())
                    {
                        SetEscortPaused(false);
                        if (_currentWPid == 4 && _isEventActive)
                        {
                            _isEventActive = false;
                            me->setActive(false);
                            Talk(SAY_CROK_FINAL_WP);
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                        }
                    }
                }
            }

            void WaypointReached(uint32 waypointId)
            {
                switch (waypointId)
                {
                    // pause pathing until trash pack is cleared
                    case 0:
                        Talk(SAY_CROK_COMBAT_WP_0);
                        if (!_aliveTrash.empty())
                            SetEscortPaused(true);
                        break;
                    case 1:
                        Talk(SAY_CROK_COMBAT_WP_1);
                        if (!_aliveTrash.empty())
                            SetEscortPaused(true);
                        break;
                    case 4:
                        if (_aliveTrash.empty() && _isEventActive)
                        {
                            _isEventActive = false;
                            me->setActive(false);
                            Talk(SAY_CROK_FINAL_WP);
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                        }
                        break;
                    default:
                        break;
                }
            }

            void WaypointStart(uint32 waypointId)
            {
                _currentWPid = waypointId;
                switch (waypointId)
                {
                    case 0:
                    case 1:
                    case 4:
                    {
                        // get spawns by home position
                        float minY = 2600.0f;
                        float maxY = 2650.0f;
                        if (waypointId == 1)
                        {
                            minY -= 50.0f;
                            maxY -= 50.0f;
                            // at waypoints 1 and 2 she kills one captain
                            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                                svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                        }
                        else if (waypointId == 4)
                        {
                            minY -= 100.0f;
                            maxY -= 100.0f;
                        }

                        // get all nearby vrykul
                        std::list<Creature*> temp;
                        FrostwingVrykulSearcher check(me, 80.0f);
                        Trinity::CreatureListSearcher<FrostwingVrykulSearcher> searcher(me, temp, check);
                        me->VisitNearbyGridObject(80.0f, searcher);

                        _aliveTrash.clear();
                        for (std::list<Creature*>::iterator itr = temp.begin(); itr != temp.end(); ++itr)
                            if ((*itr)->GetHomePosition().GetPositionY() < maxY && (*itr)->GetHomePosition().GetPositionY() > minY)
                                _aliveTrash.insert((*itr)->GetGUID());
                        break;
                    }
                    // at waypoints 1 and 2 she kills one captain
                    case 2:
                        if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SISTER_SVALNA)))
                            svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                // check wipe
                if (!_wipeCheckTimer)
                {
                    _wipeCheckTimer = 1000;
                    Player* player = NULL;
                    Trinity::AnyPlayerInObjectRangeCheck check(me, 60.0f);
                    Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, check);
                    me->VisitNearbyWorldObject(60.0f, searcher);
                    // wipe
                    if (!player)
                    {
                        damage *= 100;
                        if (damage >= me->GetHealth())
                        {
                            FrostwingGauntletRespawner respawner;
                            Trinity::CreatureWorker<FrostwingGauntletRespawner> worker(me, respawner);
                            me->VisitNearbyGridObject(333.0f, worker);
                            Talk(SAY_CROK_DEATH);
                        }
                        return;
                    }
                }

                if (HealthBelowPct(10))
                {
                    if (!_didUnderTenPercentText)
                    {
                        _didUnderTenPercentText = true;
                        if (_isEventActive)
                            Talk(SAY_CROK_WEAKENING_GAUNTLET);
                        else
                            Talk(SAY_CROK_WEAKENING_SVALNA);
                    }

                    damage = 0;
                    DoCast(me, SPELL_ICEBOUND_ARMOR);
                    _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1000);
                }
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (_wipeCheckTimer <= diff)
                    _wipeCheckTimer = 0;
                else
                    _wipeCheckTimer -= diff;

                if (!UpdateVictim() && !_isEventActive)
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARNATH_INTRO_2:
                            if (Creature* arnath = ObjectAccessor::GetCreature(*me, _instance->GetData64(GUID_CAPTAIN_ARNATH)))
                                arnath->AI()->Talk(SAY_ARNATH_INTRO_2);
                            break;
                        case EVENT_CROK_INTRO_3:
                            Talk(SAY_CROK_INTRO_3);
                            break;
                        case EVENT_START_PATHING:
                            Start(true, true);
                            break;
                        case EVENT_SCOURGE_STRIKE:
                            DoCastVictim(SPELL_SCOURGE_STRIKE);
                            _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, urand(10000, 14000));
                            break;
                        case EVENT_DEATH_STRIKE:
                            if (HealthBelowPct(20))
                                DoCastVictim(SPELL_DEATH_STRIKE);
                            _events.ScheduleEvent(EVENT_DEATH_STRIKE, urand(5000, 10000));
                            break;
                        case EVENT_HEALTH_CHECK:
                            if (HealthAbovePct(15))
                            {
                                me->RemoveAurasDueToSpell(SPELL_ICEBOUND_ARMOR);
                                _didUnderTenPercentText = false;
                            }
                            else
                            {
                                me->DealHeal(me, me->CountPctFromMaxHealth(5));
                                _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1000);
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            bool CanAIAttack(Unit const* target) const
            {
                // do not see targets inside Frostwing Halls when we are not there
                return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
            }

        private:
            EventMap _events;
            std::set<uint64> _aliveTrash;
            InstanceScript* _instance;
            uint32 _currentWPid;
            uint32 _wipeCheckTimer;
            uint32 const _respawnTime;
            uint32 const _corpseDelay;
            bool _isEventActive;
            bool _isEventDone;
            bool _didUnderTenPercentText;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_crok_scourgebaneAI>(creature);
        }
};

struct npc_argent_captainAI : public ScriptedAI
{
    public:
        npc_argent_captainAI(Creature* creature) : ScriptedAI(creature), Instance(creature->GetInstanceScript()), _firstDeath(true)
        {
            FollowAngle = PET_FOLLOW_ANGLE;
            FollowDist = PET_FOLLOW_DIST;
            IsUndead = false;
        }

        void JustDied(Unit* /*killer*/)
        {
            if (_firstDeath)
            {
                _firstDeath = false;
                Talk(SAY_CAPTAIN_DEATH);
            }
            else
                Talk(SAY_CAPTAIN_SECOND_DEATH);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_CAPTAIN_KILL);
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_START_GAUNTLET)
            {
                if (Creature* crok = ObjectAccessor::GetCreature(*me, Instance->GetData64(GUID_CROK_SCOURGEBANE)))
                {
                    me->SetReactState(REACT_DEFENSIVE);
                    FollowAngle = me->GetAngle(crok) + me->GetOrientation();
                    FollowDist = me->GetDistance2d(crok);
                    me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_IDLE);
                }

                me->setActive(true);
            }
            else if (action == ACTION_RESET_EVENT)
            {
                _firstDeath = true;
            }
        }

        void EnterCombat(Unit* /*target*/)
        {
            me->SetHomePosition(*me);
            if (IsUndead)
                DoZoneInCombat();
        }

        bool CanAIAttack(Unit const* target) const
        {
            // do not see targets inside Frostwing Halls when we are not there
            return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
        }

        void EnterEvadeMode()
        {
            // not yet following
            if (me->GetMotionMaster()->GetMotionSlotType(MOTION_SLOT_IDLE) != TARGETED_MOTION_TYPE || IsUndead)
            {
                ScriptedAI::EnterEvadeMode();
                return;
            }

            if (!_EnterEvadeMode())
                return;

            if (!me->GetVehicle())
            {
                me->GetMotionMaster()->Clear(false);
                if (Creature* crok = ObjectAccessor::GetCreature(*me, Instance->GetData64(GUID_CROK_SCOURGEBANE)))
                    me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_IDLE);
            }

            Reset();
        }

        void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
        {
            if (spell->Id == SPELL_REVIVE_CHAMPION && !IsUndead)
            {
                IsUndead = true;
                me->setDeathState(JUST_ALIVED);
                uint32 newEntry = 0;
                switch (me->GetEntry())
                {
                    case NPC_CAPTAIN_ARNATH:
                        newEntry = NPC_CAPTAIN_ARNATH_UNDEAD;
                        break;
                    case NPC_CAPTAIN_BRANDON:
                        newEntry = NPC_CAPTAIN_BRANDON_UNDEAD;
                        break;
                    case NPC_CAPTAIN_GRONDEL:
                        newEntry = NPC_CAPTAIN_GRONDEL_UNDEAD;
                        break;
                    case NPC_CAPTAIN_RUPERT:
                        newEntry = NPC_CAPTAIN_RUPERT_UNDEAD;
                        break;
                    default:
                        return;
                }

                Talk(SAY_CAPTAIN_RESURRECTED);
                me->UpdateEntry(newEntry, Instance->GetData(DATA_TEAM_IN_INSTANCE), me->GetCreatureData());
                DoCast(me, SPELL_UNDEATH, true);
            }
        }

    protected:
        EventMap Events;
        InstanceScript* Instance;
        float FollowAngle;
        float FollowDist;
        bool IsUndead;

    private:
        bool _firstDeath;
};

class npc_captain_arnath : public CreatureScript
{
    public:
        npc_captain_arnath() : CreatureScript("npc_captain_arnath") { }

        struct npc_captain_arnathAI : public npc_argent_captainAI
        {
            npc_captain_arnathAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, urand(4000, 7000));
                Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, urand(8000, 14000));
                Events.ScheduleEvent(EVENT_ARNATH_SMITE, urand(3000, 6000));
                if (Is25ManRaid() && IsUndead)
                    Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, urand(22000, 27000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARNATH_FLASH_HEAL:
                            if (Creature* target = FindFriendlyCreature())
                                DoCast(target, SPELL_FLASH_HEAL);
                            Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, urand(6000, 9000));
                            break;
                        case EVENT_ARNATH_PW_SHIELD:
                        {
                            std::list<Creature*> targets = DoFindFriendlyMissingBuff(40.0f, SPELL_POWER_WORD_SHIELD);
                            std::list<Creature*>::iterator itr = targets.begin();
                            std::advance(itr, urand(0, targets.size() - 1));
                            DoCast(*itr, SPELL_POWER_WORD_SHIELD);
                            Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, urand(15000, 20000));
                            break;
                        }
                        case EVENT_ARNATH_SMITE:
                            DoCastVictim(SPELL_SMITE);
                            Events.ScheduleEvent(EVENT_ARNATH_SMITE, urand(4000, 7000));
                            break;
                        case EVENT_ARNATH_DOMINATE_MIND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_DOMINATE_MIND);
                            Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, urand(28000, 37000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            Creature* FindFriendlyCreature() const
            {
                Creature* target = NULL;
                Trinity::MostHPMissingInRange u_check(me, 60.0f, 0);
                Trinity::CreatureLastSearcher<Trinity::MostHPMissingInRange> searcher(me, target, u_check);
                me->VisitNearbyGridObject(60.0f, searcher);
                return target;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_arnathAI>(creature);
        }
};

class npc_captain_brandon : public CreatureScript
{
    public:
        npc_captain_brandon() : CreatureScript("npc_captain_brandon") { }

        struct npc_captain_brandonAI : public npc_argent_captainAI
        {
            npc_captain_brandonAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, urand(6000, 10000));
                Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500);
                Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, urand(8000, 13000));
                if (IsUndead)
                    Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, urand(25000, 30000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BRANDON_CRUSADER_STRIKE:
                            DoCastVictim(SPELL_CRUSADER_STRIKE);
                            Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, urand(6000, 12000));
                            break;
                        case EVENT_BRANDON_DIVINE_SHIELD:
                            if (HealthBelowPct(20))
                                DoCast(me, SPELL_DIVINE_SHIELD);
                            Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500);
                            break;
                        case EVENT_BRANDON_JUDGEMENT_OF_COMMAND:
                            DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                            Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, urand(8000, 13000));
                            break;
                        case EVENT_BRANDON_HAMMER_OF_BETRAYAL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_HAMMER_OF_BETRAYAL);
                            Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, urand(45000, 60000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_brandonAI>(creature);
        }
};

class npc_captain_grondel : public CreatureScript
{
    public:
        npc_captain_grondel() : CreatureScript("npc_captain_grondel") { }

        struct npc_captain_grondelAI : public npc_argent_captainAI
        {
            npc_captain_grondelAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500);
                Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, urand(8000, 14000));
                Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, urand(3000, 12000));
                if (IsUndead)
                    Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, urand(12000, 17000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRONDEL_CHARGE_CHECK:
                            if (CanCast(me->getVictim(), sSpellStore.LookupEntry(SPELL_CHARGE)))
                                DoCastVictim(SPELL_CHARGE);
                            Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500);
                            break;
                        case EVENT_GRONDEL_MORTAL_STRIKE:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, urand(10000, 15000));
                            break;
                        case EVENT_GRONDEL_SUNDER_ARMOR:
                            DoCastVictim(SPELL_SUNDER_ARMOR);
                            Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, urand(5000, 17000));
                            break;
                        case EVENT_GRONDEL_CONFLAGRATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_CONFLAGRATION);
                            Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_grondelAI>(creature);
        }
};

class npc_captain_rupert : public CreatureScript
{
    public:
        npc_captain_rupert() : CreatureScript("npc_captain_rupert") { }

        struct npc_captain_rupertAI : public npc_argent_captainAI
        {
            npc_captain_rupertAI(Creature* creature) : npc_argent_captainAI(creature)
            {
            }

            void Reset()
            {
                Events.Reset();
                Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, urand(15000, 20000));
                Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, urand(25000, 30000));
                Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, urand(10000, 15000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                Events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RUPERT_FEL_IRON_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FEL_IRON_BOMB);
                            Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, urand(15000, 20000));
                            break;
                        case EVENT_RUPERT_MACHINE_GUN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_MACHINE_GUN);
                            Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, urand(25000, 30000));
                            break;
                        case EVENT_RUPERT_ROCKET_LAUNCH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_ROCKET_LAUNCH);
                            Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, urand(10000, 15000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_captain_rupertAI>(creature);
        }
};

class npc_frostwing_vrykul : public CreatureScript
{
    public:
        npc_frostwing_vrykul() : CreatureScript("npc_frostwing_vrykul") { }

        struct npc_frostwing_vrykulAI : public SmartAI
        {
            npc_frostwing_vrykulAI(Creature* creature) : SmartAI(creature)
            {
            }

            bool CanAIAttack(Unit const* target) const
            {
                // do not see targets inside Frostwing Halls when we are not there
                return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f) && SmartAI::CanAIAttack(target);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frostwing_vrykulAI(creature);
        }
};

class npc_impaling_spear : public CreatureScript
{
    public:
        npc_impaling_spear() : CreatureScript("npc_impaling_spear") { }

        struct npc_impaling_spearAI : public CreatureAI
        {
            npc_impaling_spearAI(Creature* creature) : CreatureAI(creature)
            {
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                _vehicleCheckTimer = 500;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_vehicleCheckTimer <= diff)
                {
                    _vehicleCheckTimer = 500;
                    if (!me->GetVehicle())
                        me->DespawnOrUnsummon(100);
                }
                else
                    _vehicleCheckTimer -= diff;
            }

            uint32 _vehicleCheckTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_impaling_spearAI(creature);
        }
};


class spell_coldflame_trap : public SpellScriptLoader
{
    public:
        spell_coldflame_trap() : SpellScriptLoader("spell_coldflame_trap") { }

        class spell_coldflame_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_coldflame_trap_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                std::list<Unit*> nonTrapped;
                if (Unit *pCaster = GetCaster())
                {
                    float x, y, z, angle, ux, uy;
                    pCaster->GetPosition(x, y, z, angle);
                    float opX = x + 25.0f * cos(angle);
                    float opY = y + 25.0f * sin(angle);
                    for (std::list<Unit*>::iterator it = unitList.begin(); it != unitList.end(); ++it)
                    {
                        Unit *curUnit = *it;
                        float unitRadius = curUnit->GetObjectSize();
                        ux = curUnit->GetPositionX();
                        uy = curUnit->GetPositionY();
                        if (   ux - unitRadius > std::max(x, opX)
                            || ux + unitRadius < std::min(x, opX)
                            || uy - unitRadius > std::max(y, opY)
                            || uy + unitRadius < std::min(y, opY))
                        {
                            nonTrapped.push_back(curUnit);
                            continue;
                        }

                        float angle = pCaster->GetAngle(curUnit) - pCaster->GetAngle(opX, opY);
                        bool inBetween = abs(sin(angle)) * curUnit->GetExactDist2d(pCaster) < unitRadius;
                        if (!inBetween)
                            nonTrapped.push_back(curUnit);
                    }
                }
                for (std::list<Unit*>::iterator it = nonTrapped.begin(); it != nonTrapped.end(); ++it)
                    unitList.erase(std::find(unitList.begin(), unitList.end(), *it));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_coldflame_trap_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_PATH);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_coldflame_trap_SpellScript();
        }
};

class DeathPlagueTargetSelector
{
    public:
        explicit DeathPlagueTargetSelector(Unit* caster) : _caster(caster) {}

        bool operator()(Unit* unit)
        {
            if (unit == _caster)
                return true;

            if (unit->GetTypeId() != TYPEID_PLAYER)
                return true;

            if (unit->HasAura(SPELL_RECENTLY_INFECTED) || unit->HasAura(SPELL_DEATH_PLAGUE_AURA))
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

            bool Load()
            {
                _failed = false;
                return true;
            }

            // First effect
            void CountTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetCaster());
                _failed = unitList.empty();
            }

            // Second effect
            void FilterTargets(std::list<Unit*>& unitList)
            {
                // Select valid targets for jump
                unitList.remove_if(DeathPlagueTargetSelector(GetCaster()));
                if (!unitList.empty())
                {
                    std::list<Unit*>::iterator itr = unitList.begin();
                    std::advance(itr, urand(0, unitList.size()-1));
                    Unit* target = *itr;
                    unitList.clear();
                    unitList.push_back(target);
                }

                unitList.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit() != GetCaster())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DEATH_PLAGUE_AURA, true);
                else if (_failed)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DEATH_PLAGUE_KILL, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frost_giant_death_plague_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ALLY_SRC);
                OnEffect += SpellEffectFn(spell_frost_giant_death_plague_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            bool _failed;
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffect += SpellEffectFn(spell_icc_harvest_blight_specimen_SpellScript::HandleQuestComplete, EFFECT_1, SPELL_EFFECT_QUEST_COMPLETE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_icc_harvest_blight_specimen_SpellScript();
        }
};

class AliveCheck
{
    public:
        bool operator()(Unit* unit)
        {
            return unit->isAlive();
        }
};

class spell_svalna_revive_champion : public SpellScriptLoader
{
    public:
        spell_svalna_revive_champion() : SpellScriptLoader("spell_svalna_revive_champion") { }

        class spell_svalna_revive_champion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_svalna_revive_champion_SpellScript);

            void RemoveAliveTarget(std::list<Unit*>& unitList)
            {
                unitList.remove_if(AliveCheck());
                Trinity::RandomResizeList(unitList, 2);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_svalna_revive_champion_SpellScript::RemoveAliveTarget, EFFECT_0, TARGET_UNIT_AREA_ENTRY_DST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_svalna_revive_champion_SpellScript();
        }
};

class spell_svalna_remove_spear : public SpellScriptLoader
{
    public:
        spell_svalna_remove_spear() : SpellScriptLoader("spell_svalna_remove_spear") { }

        class spell_svalna_remove_spear_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_svalna_remove_spear_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Creature* target = GetHitCreature())
                    target->DespawnOrUnsummon();
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_svalna_remove_spear_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_svalna_remove_spear_SpellScript();
        }
};

class at_icc_saurfang_portal : public AreaTriggerScript
{
    public:
        at_icc_saurfang_portal() : AreaTriggerScript("at_icc_saurfang_portal") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetData(DATA_SAURFANG_EVENT) != DONE)
                return true;

            player->GetMap()->LoadGrid(4207.0f, 2769.23f);
            player->TeleportTo(631, 4126.35f, 2769.23f, 350.963f, 0.0f);

            if (instance->GetData(DATA_COLDFLAME_JETS_EVENT) == NOT_STARTED)
            {
                // Process relocation now, to preload the grid and initialize traps
                player->GetMap()->PlayerRelocation(player, 4126.35f, 2769.23f, 350.963f, 0.0f);

                instance->SetData(DATA_COLDFLAME_JETS_EVENT, IN_PROGRESS);

                std::list<Creature*> traps;
                if (GameObject *go = player->GetMap()->GetGameObject(instance->GetData64(GUID_TELEPORT_UPPER_SPIRE)))
                    GetCreatureListWithEntryInGrid(traps, go, NPC_FROST_FREEZE_TRAP, 200.0f);
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

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_COLDFLAME_JETS_EVENT) == IN_PROGRESS)
                    instance->SetData(DATA_COLDFLAME_JETS_EVENT, DONE);
            return true;
        }
};

class npc_deathspeaker_high_priest : public CreatureScript
{
public:
    npc_deathspeaker_high_priest() : CreatureScript("npc_deathspeaker_high_priest") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_deathspeaker_high_priestAI (pCreature);

    }

    struct npc_deathspeaker_high_priestAI : public ScriptedAI
    {

        npc_deathspeaker_high_priestAI(Creature *c) : ScriptedAI(c)
        {
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_AURA_OF_DARKNESS);
            events.Reset();
            events.ScheduleEvent(EVENT_DARK_RECKONING, 10000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DARK_RECKONING:
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,1, 35.0f, false, -SPELL_DARK_RECKONING))
                            DoCast(pTarget, SPELL_DARK_RECKONING);
                        events.ScheduleEvent(EVENT_DARK_RECKONING, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            EventMap events;
    };

};
class spell_icc_dark_reckoning : public SpellScriptLoader
{
    public:
        spell_icc_dark_reckoning() : SpellScriptLoader("spell_icc_dark_reckoning") { }

        class spell_icc_dark_reckoning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_icc_dark_reckoning_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_DARK_RECKONING) ||
                    !sSpellStore.LookupEntry(SPELL_DARK_RECKONING_SIPHON_LIFE))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit *caster = GetCaster(), *target = GetTarget();
                if (caster && caster->isAlive() && target && target->isAlive())
                    caster->CastSpell(target, SPELL_DARK_RECKONING_SIPHON_LIFE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_icc_dark_reckoning_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_icc_dark_reckoning_AuraScript();
        }
};
class npc_val_kyr_herald : public CreatureScript
{
public:
    npc_val_kyr_herald() : CreatureScript("npc_val_kyr_herald") { }

    CreatureAI* GetAI(Creature* pCreature) const

    {
        return new npc_val_kyr_heraldAI (pCreature);

    }

    struct npc_val_kyr_heraldAI : public ScriptedAI
    {

        npc_val_kyr_heraldAI(Creature *c) : ScriptedAI(c), summons(c)
        {
            instance = c->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_SEVERED_ESSENCE, 8000);
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);
        }

        void JustDied (Unit *killer)
        {
            summons.DespawnAll();
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
        {
            // Not good target or too many players
            if (pTarget->GetTypeId() != TYPEID_PLAYER || !pTarget->isAlive())
                return;
            // Summon clone
            me->SummonCreature(NPC_SEVERED_ESSENCE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation(),TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SEVERED_ESSENCE:
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0, 100.0f, true))
                        {
                            DoCast(me, RAID_MODE<uint32>(SPELL_SEVERED_ESSENCE_10, SPELL_SEVERED_ESSENCE_25, SPELL_SEVERED_ESSENCE_10, SPELL_SEVERED_ESSENCE_25));
                        }
                        events.ScheduleEvent(EVENT_SEVERED_ESSENCE, 40000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript *instance;
            EventMap events;
            SummonList summons;
    };

};

class npc_severed_essence : public CreatureScript
{
public:
    npc_severed_essence() : CreatureScript("npc_severed_essence") { }

    CreatureAI* GetAI(Creature* pCreature) const

    {
        return new npc_severed_essenceAI (pCreature);

    }

    struct npc_severed_essenceAI : public ScriptedAI
    {
        npc_severed_essenceAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
            playerClass = 0;
        }

        void Reset()
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* owner)
        {
            if (owner->GetTypeId() != TYPEID_UNIT || owner->GetEntry() != NPC_VALKYR_HERALD)
                return;
            uiOwnerId = owner->GetGUID();
        }

        void KilledUnit(Unit* victim)
        {
            if (Unit *newVictim = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f))
                AttackStart(newVictim);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Unit *player = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
            {
                player->CastSpell(me, SPELL_CLONE_PLAYER, true);
                SetData(DATA_PLAYER_CLASS, player->getClass());
            }
            else
            {
                me->DespawnOrUnsummon();
                return;
            }
            ASSERT(playerClass != 0);
            events.Reset();
            switch (playerClass)
            {
                case CLASS_DRUID:
                {
                    events.ScheduleEvent(EVENT_CAT_FORM, 100);
                    events.ScheduleEvent(EVENT_MANGLE, 3000);
                    events.ScheduleEvent(EVENT_RIP, 8000);
                    break;
                }
                case CLASS_WARLOCK:
                {
                    events.ScheduleEvent(EVENT_CORRUPTION, 100);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 3000);
                    events.ScheduleEvent(EVENT_RAIN_OF_CHAOS, 8000);
                    break;
                }
                case CLASS_SHAMAN:
                {
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 3000);
                    bCanCastReplenishingRains = true;
                    break;
                }
                case CLASS_ROGUE:
                {
                    events.ScheduleEvent(EVENT_FOCUSED_ATTACKS, 10000);
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, 2000);
                    events.ScheduleEvent(EVENT_EVISCERATE, 8000);
                    break;
                }
                case CLASS_MAGE:
                {
                    events.ScheduleEvent(EVENT_FIREBALL, 100);
                    break;
                }
                case CLASS_WARRIOR:
                {
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 5000);
                    events.ScheduleEvent(EVENT_HEROIC_LEAP, 8000);
                    break;
                }
                case CLASS_DEATH_KNIGHT:
                {
                    events.ScheduleEvent(EVENT_DEATH_GRIP, 100);
                    events.ScheduleEvent(EVENT_NECROTIC_STRIKE, 4000);
                    events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 7000);
                    break;
                }
                case CLASS_HUNTER:
                {
                    events.ScheduleEvent(EVENT_SHOOT, 100);
                    bCanCastDisengage = true;
                    break;
                }
                case CLASS_PALADIN:
                {
                    events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 100);
                    events.ScheduleEvent(EVENT_CLEANSE, 3000);
                    bCanCastRadianceAura = true;
                    break;
                case CLASS_PRIEST:
                {
                    events.ScheduleEvent(EVENT_GREATER_HEAL, 100);
                    events.ScheduleEvent(EVENT_RENEW, 1000);
                    break;
                }
            }
            }
        }
        void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/)
        {
            switch (playerClass)
            {
                case CLASS_SHAMAN:
                {
                    if(HealthBelowPct(30) && bCanCastReplenishingRains)
                    {
                        events.ScheduleEvent(EVENT_REPLENISHING_RAINS, 100);
                        events.ScheduleEvent(EVENT_CAN_CAST_REPLENISHING_RAINS, 15000);
                        bCanCastReplenishingRains = false;
                    }
                }
                case CLASS_HUNTER:
                {
                    if (!bCanCastDisengage)
                        break;
                    std::list<HostileReference*> &players = me->getThreatManager().getThreatList();
                    if (players.empty())
                        break;
                    for (std::list<HostileReference*>::iterator it = players.begin(); it != players.end(); ++it)
                    {
                        if (Unit *curTarget = (*it)->getTarget())
                        {
                            if (me->GetDistance2d(curTarget) < 5.0f)
                            {
                                me->SetFacingToObject(curTarget);
                                DoCast(curTarget, SPELL_DISENGAGE);
                                bCanCastDisengage = false;
                                events.ScheduleEvent(EVENT_CAN_CAST_DISENGAGE, 15000);
                                break;
                            }
                        }
                    }
                    break;
                }
                case CLASS_PALADIN:
                    if(HealthBelowPct(30) && bCanCastRadianceAura)
                    {
                        events.ScheduleEvent(EVENT_RADIANCE_AURA, 100);
                        events.ScheduleEvent(EVENT_CAN_CAST_RADIANCE_AURA, 15000);
                        bCanCastRadianceAura = false;
                    }
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_PLAYER_CLASS)
                playerClass = data;
        }

        void HandleDruidEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAT_FORM:
                    DoCast(me, SPELL_CAT_FORM);
                    break;
                case EVENT_MANGLE:
                    DoCast(me->getVictim(), SPELL_MANGLE);
                    events.ScheduleEvent(EVENT_MANGLE, 2000);
                    break;
                case EVENT_RIP:
                    DoCast(me->getVictim(), SPELL_RIP);
                    events.ScheduleEvent(EVENT_RIP, 8000);
                    break;
            }
        }

        void HandleWarlockEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CORRUPTION:
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f, true, -SPELL_CORRUPTION))
                        DoCast(pUnit, SPELL_CORRUPTION);
                    events.ScheduleEvent(EVENT_CORRUPTION, 20000);
                    break;
                case EVENT_SHADOW_BOLT:
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 5000);
                    break;
                case EVENT_RAIN_OF_CHAOS:
                    DoCast(me->getVictim(), SPELL_RAIN_OF_CHAOS);
                    events.ScheduleEvent(EVENT_RAIN_OF_CHAOS, 18000);
                    break;
            }
        }

        void HandleShamanEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_REPLENISHING_RAINS:
                    bCanCastReplenishingRains = true;
                    break;
                case EVENT_REPLENISHING_RAINS:
                    DoCast(me, SPELL_REPLENISHING_RAINS);
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 4000);
                    break;

            }
        }

        void HandleRogueEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_FOCUSED_ATTACKS:
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, 5.0f, true, -SPELL_FOCUSED_ATTACKS))
                        DoCast(pUnit, SPELL_FOCUSED_ATTACKS);
                    events.ScheduleEvent(EVENT_FOCUSED_ATTACKS, 15000);
                    break;
                case EVENT_SINISTER_STRIKE:
                    DoCast(me->getVictim(), SPELL_SINISTER_STRIKE);
                    events.ScheduleEvent(EVENT_SINISTER_STRIKE, 1000);
                    break;
                case EVENT_EVISCERATE:
                    DoCast(me->getVictim(), SPELL_EVISCERATE);
                    events.ScheduleEvent(EVENT_EVISCERATE, 6000);
                    break;
            }
        }

        void HandleMageEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_FIREBALL:
                    DoCast(me->getVictim(), SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 3500);
                    break;
            }
        }

        void HandleWarriorEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_BLOODTHIRST:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                        DoCast(pUnit, SPELL_BLOODTHIRST);
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 12000);
                    break;
                }
                case EVENT_HEROIC_LEAP:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 1, 8.0f, true))
                        DoCast(pUnit, SPELL_HEROIC_LEAP);
                    events.ScheduleEvent(EVENT_HEROIC_LEAP, 45000);
                    break;
                }
            }
        }

        void HandleDeathKnightEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_DEATH_GRIP:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                    {
                        DoCast(pUnit, EVENT_DEATH_GRIP);
                        me->getThreatManager().clearReferences();
                        AttackStart(pUnit);
                    }
                    events.ScheduleEvent(EVENT_DEATH_GRIP, 35000);
                    break;
                }
                case EVENT_NECROTIC_STRIKE:
                {
                    DoCast(me->getVictim(), SPELL_NECROTIC_STRIKE);
                    events.ScheduleEvent(EVENT_NECROTIC_STRIKE, 6000);
                    break;
                }
                case EVENT_PLAGUE_STRIKE:
                {
                    if (Unit *pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                        DoCast(pUnit, SPELL_PLAGUE_STRIKE);
                    events.ScheduleEvent(EVENT_PLAGUE_STRIKE, 7000);
                    break;
                }

            }
        }

        void HandleHunterEvents()
        {
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_DISENGAGE:
                {
                    bCanCastDisengage = true;
                    break;
                }
                case EVENT_SHOOT:
                {
                    DoCast(me->getVictim(), RAID_MODE<uint32>(SPELL_SHOOT_10, SPELL_SHOOT_25, SPELL_SHOOT_10, SPELL_SHOOT_25));
                    events.ScheduleEvent(EVENT_SHOOT, 2000);
                    break;
                }
            }
        }

        void HandlePaladinEvents()
        {
            Creature *valkyrHerald;
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_CAN_CAST_RADIANCE_AURA:
                {
                    bCanCastRadianceAura = true;
                    break;
                }
                case EVENT_FLASH_OF_LIGHT:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_FLASH_OF_LIGHT);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct())
                                pMob = (*itr);
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_FLASH_OF_LIGHT);
                    }
                    events.ScheduleEvent(EVENT_FLASH_OF_LIGHT, 5000);
                    break;
                }
                case EVENT_CLEANSE:
                {
                    if (valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 30.0f))
                        DoCast(valkyrHerald, SPELL_CLEANSE);
                    events.ScheduleEvent(EVENT_CLEANSE, 5000);
                    break;
                }
                case EVENT_RADIANCE_AURA:
                {
                    DoCast(me, SPELL_RADIANCE_AURA);
                    break;
                }
            }
        }

        void HandlePriestEvents()
        {
            Creature *valkyrHerald;
            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_RENEW:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_RENEW);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!((*itr)->HasAura(SPELL_RENEW)) && (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct()))
                                pMob = (*itr);
                        if (!pMob)
                        {
                            Aura *pMobAura;
                            for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            {
                                if (!pMob && (*itr)->HasAura(SPELL_RENEW))
                                {
                                    pMob = (*itr);
                                    continue;
                                }
                                if ((*itr)->HasAura(SPELL_RENEW) &&
                                    ((pMobAura = (*itr)->GetAura(SPELL_RENEW)) && pMobAura->GetDuration() < pMob->GetAura(SPELL_RENEW)->GetDuration()))
                                    pMob = (*itr);
                            }
                        }
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_RENEW);
                    }
                    events.ScheduleEvent(EVENT_RENEW, 5000);
                    break;
                }
                case EVENT_GREATER_HEAL:
                {
                    if ((valkyrHerald = me->FindNearestCreature(NPC_VALKYR_HERALD, 40.0f)) && urand(0, 1))
                    {
                        DoCast(valkyrHerald, SPELL_GREATER_HEAL);
                    }
                    else
                    {
                        std::list<Creature*> others;
                        GetCreatureListWithEntryInGrid(others, me, NPC_SEVERED_ESSENCE, 40.0f);
                        Unit *pMob = 0;
                        for (std::list<Creature*>::const_iterator itr = others.begin(); itr != others.end(); ++itr)
                            if (!pMob || pMob->GetHealthPct() < (*itr)->GetHealthPct())
                                pMob = (*itr);
                        if (!pMob)
                            pMob = valkyrHerald;
                        if (pMob)
                            DoCast(pMob, SPELL_GREATER_HEAL);
                    }
                    events.ScheduleEvent(EVENT_GREATER_HEAL, 5000);
                    break;
                }
            }
        }


        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);

            switch (playerClass)
            {
                case CLASS_DRUID:
                    HandleDruidEvents();
                    break;
                case CLASS_WARLOCK:
                    HandleWarlockEvents();
                case CLASS_SHAMAN:
                    HandleShamanEvents();
                case CLASS_ROGUE:
                    HandleRogueEvents();
                case CLASS_MAGE:
                    HandleMageEvents();
                case CLASS_WARRIOR:
                    HandleWarriorEvents();
                case CLASS_DEATH_KNIGHT:
                    HandleDeathKnightEvents();
                case CLASS_HUNTER:
                    HandleHunterEvents();
                case CLASS_PALADIN:
                    HandlePaladinEvents();
                case CLASS_PRIEST:
                    HandlePriestEvents();
                default:
                    break;
            }
            DoMeleeAttackIfReady();
        }
        private:
            uint8 playerClass;
            InstanceScript *instance;
            EventMap events;
            uint64 uiOwnerId;
            bool bCanCastReplenishingRains;
            bool bCanCastDisengage;
            bool bCanCastRadianceAura;
    };

};

class at_icc_start_blood_quickening : public AreaTriggerScript
{
    public:
        at_icc_start_blood_quickening() : AreaTriggerScript("at_icc_start_blood_quickening") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_BLOOD_QUICKENING_STATE) == NOT_STARTED)
                    instance->SetData(DATA_BLOOD_QUICKENING_STATE, IN_PROGRESS);
            return true;
        }
};

class at_icc_start_frostwing_gauntlet : public AreaTriggerScript
{
    public:
        at_icc_start_frostwing_gauntlet() : AreaTriggerScript("at_icc_start_frostwing_gauntlet") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* crok = ObjectAccessor::GetCreature(*player, instance->GetData64(GUID_CROK_SCOURGEBANE)))
                    crok->AI()->DoAction(ACTION_START_GAUNTLET);
            return true;
        }
};

void AddSC_icecrown_citadel()
{
    new npc_highlord_tirion_fordring_lh();
    new go_icecrown_teleporter();
    new npc_frost_freeze_trap();
    new npc_alchemist_adrianna();
    new boss_sister_svalna();
    new npc_crok_scourgebane();
    new npc_captain_arnath();
    new npc_captain_brandon();
    new npc_captain_grondel();
    new npc_captain_rupert();
    new npc_frostwing_vrykul();
    new npc_impaling_spear();
    new spell_icc_spirit_alarm();
    new spell_coldflame_trap();
    new npc_deathspeaker_high_priest();
    new spell_icc_dark_reckoning();
    new npc_val_kyr_herald();
    new npc_severed_essence();
    new npc_rotting_frost_giant();
    new spell_frost_giant_death_plague();
    new spell_icc_harvest_blight_specimen();
    new spell_trigger_spell_from_caster("spell_svalna_caress_of_death", SPELL_IMPALING_SPEAR_KILL);
    new spell_svalna_revive_champion();
    new spell_svalna_remove_spear();
    new at_icc_saurfang_portal();
    new at_icc_shutdown_traps();
    new at_icc_start_blood_quickening();
    new at_icc_start_frostwing_gauntlet();
}
