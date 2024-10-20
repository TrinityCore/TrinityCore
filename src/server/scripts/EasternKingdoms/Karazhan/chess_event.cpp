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

 /* ContentData
 npc_echo_of_medivh
 npc_chess_piece_generic
 npc_chess_piece_king
 npc_chess_move_trigger
 spell_king_primary
 spell_chess
 spell_change_facing
 spell_control_piece
 spell_move_to_square
 spell_piece_move
 spell_move_cooldown
 spell_hand_of_medivh
 spell_fury_of_medivh
 spell_heal_of_medivh
 spell_game_over*/

#include "CellImpl.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "karazhan.h"
#include "Containers.h"
#include "EventMap.h"
#include "SpellHistory.h"

//todo Sometimes several chess pieces fit into the same square
//todo If a corpse lies for more than 300 seconds, it disappears and will not respawn when the game ends

enum SpellsChess
{
    // Movement spells
    // SPELL_MOVE_GENERIC            = 30012,  // Spell which sends the signal to move - handled in core
    // SPELL_MOVE_1                  = 32312,  // Spell which selects AI move square (for short range pieces)
    // SPELL_MOVE_2                  = 37388,  // Spell which selects AI move square (for long range pieces)
    SPELL_MOVE_PAWN                 = 37146,  // Individual move spells (used only by controlled npcs)
    SPELL_MOVE_KNIGHT               = 37144,
    SPELL_MOVE_QUEEN                = 37148,
    SPELL_MOVE_ROCK                 = 37151,
    SPELL_MOVE_BISHOP               = 37152,
    SPELL_MOVE_KING                 = 37153,

    // Additional movement spells
    SPELL_CHANGE_FACING             = 30284,  // Spell which sends the initial facing request - handled in core
    SPELL_FACE_SQUARE               = 30270,  // Change facing - finalize facing update
    SPELL_MOVE_TO_SQUARE            = 30253,  // Spell which sends the move response from the square to the piece
    SPELL_MOVE_COOLDOWN             = 30543,  // Add some cooldown to movement
    SPELL_MOVE_MARKER               = 32261,  // White beam visual - used to mark the movement as complete

    // Generic spells
    SPELL_CONTROL_PIECE             = 30019,  // Control a chess piece
    SPELL_MELEE_DAMAGE              = 32247,  // Melee damage spell - used by all chess pieces
    // SPELL_RECENTLY_IN_GAME        = 30529,  // Debuff on player after chess piece uncharm
    // SPELL_IN_GAME                 = 30532,  // Teleport player near the entrance

    // Melee action spells
    // SPELL_MELEE_FOOTMAN            = 32227,
    // SPELL_MELEE_WATER_ELEM         = 37142,
    // SPELL_MELEE_CHARGER            = 37143,
    // SPELL_MELEE_CLERIC             = 37147,
    // SPELL_MELEE_CONJURER           = 37149,
    // SPELL_MELEE_KING_LLANE         = 37150,
    // SPELL_MELEE_GRUNT              = 32228,
    // SPELL_MELEE_DAEMON             = 37220,
    // SPELL_MELEE_NECROLYTE          = 37337,
    // SPELL_MELEE_WOLF               = 37339,
    // SPELL_MELEE_WARLOCK            = 37345,
    // SPELL_MELEE_WARCHIEF_BLACKHAND = 37348,

    // Cheat spells
    SPELL_HAND_OF_MEDIVH_HORDE      = 39338,  // Triggers 39339
    SPELL_HAND_OF_MEDIVH_ALLIANCE   = 39342,  // Triggers 39339
    SPELL_FURY_OF_MEDIVH_HORDE      = 39341,  // Triggers 39343
    SPELL_FURY_OF_MEDIVH_ALLIANCE   = 39344,  // Triggers 39345
    SPELL_FURY_OF_MEDIVH_AURA       = 39383,
    SPELL_FULL_HEAL_HORDE           = 39334,
    SPELL_FULL_HEAL_ALLIANCE        = 39335,

    // Spells used by the chess NPCs
    SPELL_HEROISM                   = 37471,  // Human king
    SPELL_SWEEP                     = 37474,
    SPELL_BLOODLUST                 = 37472,  // Orc king
    SPELL_CLEAVE                    = 37476,
    SPELL_HEROIC_BLOW               = 37406,  // Human pawn
    SPELL_SHIELD_BLOCK              = 37414,
    SPELL_VICIOUS_STRIKE            = 37413,  // Orc pawn
    SPELL_WEAPON_DEFLECTION         = 37416,
    SPELL_SMASH                     = 37453,  // Human knight
    SPELL_STOMP                     = 37498,
    SPELL_BITE                      = 37454,  // Orc knight
    SPELL_HOWL                      = 37502,
    SPELL_ELEMENTAL_BLAST           = 37462,  // Human queen
    SPELL_RAIN_OF_FIRE              = 37465,
    SPELL_FIREBALL                  = 37463,  // Orc queen
    SPELL_POISON_CLOUD              = 37469,
    SPELL_HEALING                   = 37455,  // Human bishop
    SPELL_HOLY_LANCE                = 37459,
    SPELL_SHADOW_MEND               = 37456,  // Orc bishop
    SPELL_SHADOW_SPEAR              = 37461,
    SPELL_GEYSER                    = 37427,  // Human rook
    SPELL_WATER_SHIELD              = 37432,
    SPELL_HELLFIRE                  = 37428,  // Orc rook
    SPELL_FIRE_SHIELD               = 37434,
};

enum GossipTexts
{
    // Gossip texts
    GOSSIP_ITEM_ID_LLANE            = 19297,
    GOSSIP_ITEM_ID_BLACKHAND        = 19384,
    GOSSIP_ITEM_ID_CONJURER         = 19295,
    GOSSIP_ITEM_ID_WARLOCK          = 19377,
    GOSSIP_ITEM_ID_FOOTMAN          = 14008,
    GOSSIP_ITEM_ID_GRUNT            = 19320,
    GOSSIP_ITEM_ID_ELEMENTAL        = 19285,
    GOSSIP_ITEM_ID_DEAMON           = 19323,
    GOSSIP_ITEM_ID_CHARGER          = 19288,
    GOSSIP_ITEM_ID_WOLF             = 19375,
    GOSSIP_ITEM_ID_CLERIC           = 19293,
    GOSSIP_ITEM_ID_NECROLYTE        = 19367,

    // Gossip menu
    GOSSIP_MENU_ID_MEDIVH           = 8404,
    GOSSIP_MENU_ID_MEDIVH_BEATEN    = 8404,  // ?
    GOSSIP_MENU_ID_LLANE            = 8349,
    GOSSIP_MENU_ID_BLACKHAND        = 8368,
    GOSSIP_MENU_ID_CONJURER         = 8348,
    GOSSIP_MENU_ID_WARLOCK          = 8367,
    GOSSIP_MENU_ID_FOOTMAN          = 7413,
    GOSSIP_MENU_ID_GRUNT            = 8354,
    GOSSIP_MENU_ID_ELEMENTAL        = 8345,
    GOSSIP_MENU_ID_DEAMON           = 8355,
    GOSSIP_MENU_ID_CHARGER          = 8346,
    GOSSIP_MENU_ID_WOLF             = 8366,
    GOSSIP_MENU_ID_CLERIC           = 8347,
    GOSSIP_MENU_ID_NECROLYTE        = 8362,

    // Text ID menu
    GOSSIP_TEXT_ID_MEDIVH           = 10506,
    GOSSIP_TEXT_ID_MEDIVH_BEATEN    = 10718,
    GOSSIP_TEXT_ID_LLANE            = 10418,
    GOSSIP_TEXT_ID_BLACKHAND        = 10442,
    GOSSIP_TEXT_ID_CONJURER         = 10417,
    GOSSIP_TEXT_ID_WARLOCK          = 10440,
    GOSSIP_TEXT_ID_FOOTMAN          = 8952,
    GOSSIP_TEXT_ID_GRUNT            = 10425,
    GOSSIP_TEXT_ID_ELEMENTAL        = 10413,
    GOSSIP_TEXT_ID_DEAMON           = 10426,
    GOSSIP_TEXT_ID_CHARGER          = 10414,
    GOSSIP_TEXT_ID_WOLF             = 10439,
    GOSSIP_TEXT_ID_CLERIC           = 10416,
    GOSSIP_TEXT_ID_NECROLYTE        = 10434,
};

Position const WaitingRoomPos = { -11107.200195f, -1842.880005f, 229.707993f, 5.365469f };

/*######
## npc_echo_of_medivh
######*/

enum MedivhEvents
{
    EVENT_CHEAT = 1
};

struct npc_echo_of_medivh : public ScriptedAI
{
    npc_echo_of_medivh(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        Reset();
    }

    void Reset() override
    {
        events.ScheduleEvent(EVENT_CHEAT, 50s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_FURY_MEDIVH_VISUAL)
            summoned->CastSpell(summoned, SPELL_FURY_OF_MEDIVH_AURA, true);
    }

    void UpdateAI(const uint32 diff) override
    {
        if (instance->GetBossState(DATA_CHESS) != IN_PROGRESS)
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_CHEAT)
            {
                uint32 spellId = 0;
                switch (urand(0, 2))
                {
                case 0:
                    spellId = (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE) ? SPELL_FURY_OF_MEDIVH_ALLIANCE : SPELL_FURY_OF_MEDIVH_HORDE;
                    break;
                case 1:
                    spellId = (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE) ? SPELL_HAND_OF_MEDIVH_ALLIANCE : SPELL_HAND_OF_MEDIVH_HORDE;
                    break;
                case 2:
                    spellId = (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE) ? SPELL_FULL_HEAL_ALLIANCE : SPELL_FULL_HEAL_HORDE;
                    break;
                }

                for (uint8 i = 0; i < urand(1, 3); ++i)
                    DoCastSelf(spellId, true);

                switch (urand(0, 2))
                {
                case 0: DoPlaySoundToSet(me, SOUND_ID_CHEAT_1); break;
                case 1: DoPlaySoundToSet(me, SOUND_ID_CHEAT_2); break;
                case 2: DoPlaySoundToSet(me, SOUND_ID_CHEAT_3); break;
                }

                events.ScheduleEvent(EVENT_CHEAT, 50s, 60s);
            }
        }
    }

    bool OnGossipHello(Player* player) override
    {
        InitGossipMenuFor(player, GOSSIP_MENU_ID_MEDIVH);
        if (instance->GetBossState(DATA_CHESS) == DONE)
            SendGossipMenuFor(player, GOSSIP_TEXT_ID_MEDIVH_BEATEN, me->GetGUID());
        else
            SendGossipMenuFor(player, GOSSIP_TEXT_ID_MEDIVH, me->GetGUID());
        return true;
    }

private:
    EventMap events;
    InstanceScript* instance;
};

/*######
## npc_chess_piece_generic
######*/

enum Events
{
    EVENT_MOVE_COMMAND = 1,
    EVENT_SPELL_COMMAND,
    EVENT_MOVE,
};

struct npc_chess_piece_generic : public ScriptedAI
{
    npc_chess_piece_generic(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_GAME_IN_SESSION, true);
        me->SetSheath(SHEATH_STATE_MELEE);
        events.Reset();
        events.ScheduleEvent(EVENT_MOVE_COMMAND, 1s, 2s);
        if (!me->HasAura(SPELL_CONTROL_PIECE))
            events.ScheduleEvent(EVENT_SPELL_COMMAND, 1s, 2s);
        primarySpell = true;

        // cancel move event for player faction npcs or for friendly games
        if ((instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetFaction() != FACTION_ID_CHESS_HORDE) ||
            (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE && me->GetFaction() != FACTION_ID_CHESS_ALLIANCE) ||
            instance->GetBossState(DATA_CHESS) == DONE)
        {
            events.CancelEvent(EVENT_MOVE_COMMAND);
        }
    }

    void AttackStart(Unit* /*who*/) override { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void OnCharmed(bool /*isNew*/) override { Reset(); }

    void JustDied(Unit* killer) override
    {
        CreatureAI::JustDied(killer);

        // Remove used aura
        AddUsedAura(false);
        instance->SetGuidData(DATA_CHESS_MOVE_TO_SIDES, me->GetGUID());
    }

    void MovementInform(uint32 /*type*/, uint32 /*id*/) override
    {
        if (Unit* target = GetPiece(TARGET_TYPE_HOSTILE, 13.0f, float(M_PI_M2 - 0.01)))
            DoCast(target, SPELL_CHANGE_FACING);
    }

    void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_ACTION_MELEE)
            return;
        if (Unit* target = GetPiece(TARGET_TYPE_HOSTILE, 8.1f, 1.6f))
            DoCast(target, SPELL_MELEE_DAMAGE, true);
    }

    void UpdateAI(const uint32 diff) override
    {
        if (instance->GetBossState(DATA_CHESS) != IN_PROGRESS || !me->IsAlive())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MOVE_COMMAND:
                // Check for nearby hostile targets to update facing
                if (Unit* target = GetPiece(TARGET_TYPE_HOSTILE, 8.1f, float(M_PI_M2 - 0.01)))
                    DoCast(target, SPELL_CHANGE_FACING);
                else
                {
                    // 15% chance to move
                    if (roll_chance_i(15))
                    {
                        // Get the movement square and cast move spell
                        if (Unit* target = GetMovementSquare())
                        {
                            currSquareGUID = target->GetGUID();
                            me->CastSpell(target, SPELL_MOVE_TO_SQUARE);
                            events.ScheduleEvent(EVENT_MOVE, 2s);
                        }
                    }
                }
                events.ScheduleEvent(EVENT_MOVE_COMMAND, 5s);
                break;
            case EVENT_MOVE:
                // Execute move to the square
                if (Creature* square = ObjectAccessor::GetCreature(*me, currSquareGUID))
                {
                    // Remove used aura before moving
                    AddUsedAura(false);

                    DoCast(square, SPELL_MOVE_MARKER);
                    me->GetMotionMaster()->MovePoint(1, square->GetPosition());
                }
                break;
            case EVENT_SPELL_COMMAND:
            {
                // Alternate between primary and secondary spells and reset the timer
                uint32 spellCooldown = urand(0, 2000);
                spellCooldown = primarySpell ? DoCastPrimarySpell() : DoCastSecondarySpell();
                events.ScheduleEvent(EVENT_SPELL_COMMAND, Milliseconds(spellCooldown));
                primarySpell = !primarySpell;
            }
            break;
            default:
                break;
            }
        }
    }

    bool OnGossipHello(Player* player) override
    {
        if (me->HasAura(SPELL_CONTROL_PIECE))
            return true;

        uint32 gossipText = 0;
        uint32 gossipMenu = 0;

        switch (me->GetEntry())
        {
        case NPC_KING_LLANE:
            gossipText = GOSSIP_TEXT_ID_LLANE;
            gossipMenu = GOSSIP_MENU_ID_LLANE;
            break;
        case NPC_WARCHIEF_BLACKHAND:
            gossipText = GOSSIP_TEXT_ID_BLACKHAND;
            gossipMenu = GOSSIP_MENU_ID_BLACKHAND;
            break;
        case NPC_HUMAN_CONJURER:
            gossipText = GOSSIP_TEXT_ID_CONJURER;
            gossipMenu = GOSSIP_MENU_ID_CONJURER;
            break;
        case NPC_ORC_WARLOCK:
            gossipText = GOSSIP_TEXT_ID_WARLOCK;
            gossipMenu = GOSSIP_MENU_ID_WARLOCK;
            break;
        case NPC_HUMAN_FOOTMAN:
            gossipText = GOSSIP_TEXT_ID_FOOTMAN;
            gossipMenu = GOSSIP_MENU_ID_FOOTMAN;
            break;
        case NPC_ORC_GRUNT:
            gossipText = GOSSIP_TEXT_ID_GRUNT;
            gossipMenu = GOSSIP_MENU_ID_GRUNT;
            break;
        case NPC_CONJURED_WATER_ELEMENTAL:
            gossipText = GOSSIP_TEXT_ID_ELEMENTAL;
            gossipMenu = GOSSIP_MENU_ID_ELEMENTAL;
            break;
        case NPC_SUMMONED_DAEMON:
            gossipText = GOSSIP_TEXT_ID_DEAMON;
            gossipMenu = GOSSIP_MENU_ID_DEAMON;
            break;
        case NPC_HUMAN_CHARGER:
            gossipText = GOSSIP_TEXT_ID_CHARGER;
            gossipMenu = GOSSIP_MENU_ID_CHARGER;
            break;
        case NPC_ORC_WOLF:
            gossipText = GOSSIP_TEXT_ID_WOLF;
            gossipMenu = GOSSIP_MENU_ID_WOLF;
            break;
        case NPC_HUMAN_CLERIC:
            gossipText = GOSSIP_TEXT_ID_CLERIC;
            gossipMenu = GOSSIP_MENU_ID_CLERIC;
            break;
        case NPC_ORC_NECROLYTE:
            gossipText = GOSSIP_TEXT_ID_NECROLYTE;
            gossipMenu = GOSSIP_MENU_ID_NECROLYTE;
            break;
        default:
            return false;
        }

        InitGossipMenuFor(player, gossipMenu);

        switch (me->GetEntry())
        {
        case NPC_KING_LLANE:
            if ((instance->GetBossState(DATA_CHESS) != DONE && player->GetTeam() == ALLIANCE) ||
                instance->GetBossState(DATA_CHESS) == DONE)
                AddGossipItemFor(player, gossipMenu, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case NPC_WARCHIEF_BLACKHAND:
            if ((instance->GetBossState(DATA_CHESS) != DONE && player->GetTeam() == HORDE) ||
                instance->GetBossState(DATA_CHESS) == DONE)
                AddGossipItemFor(player, gossipMenu, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case NPC_HUMAN_CONJURER:
        case NPC_HUMAN_FOOTMAN:
        case NPC_CONJURED_WATER_ELEMENTAL:
        case NPC_HUMAN_CHARGER:
        case NPC_HUMAN_CLERIC:
            if ((instance->GetBossState(DATA_CHESS) == IN_PROGRESS && player->GetTeam() == ALLIANCE) ||
                instance->GetData(DATA_CHESS) == SPECIAL)
                AddGossipItemFor(player, gossipMenu, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        case NPC_ORC_WARLOCK:
        case NPC_ORC_GRUNT:
        case NPC_SUMMONED_DAEMON:
        case NPC_ORC_WOLF:
        case NPC_ORC_NECROLYTE:
            if ((instance->GetBossState(DATA_CHESS) == IN_PROGRESS && player->GetTeam() == HORDE) ||
                instance->GetData(DATA_CHESS) == SPECIAL)
                AddGossipItemFor(player, gossipMenu, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            break;
        default:
            return false;
        }
        SendGossipMenuFor(player, gossipText, me->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        ClearGossipMenuFor(player);

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            // Teleport the player to the waiting room and start controlling the chess piece
            player->SendTeleportPacket(WaitingRoomPos);
            player->CastSpell(me, SPELL_CONTROL_PIECE);

            if (me->GetEntry() == NPC_KING_LLANE || me->GetEntry() == NPC_WARCHIEF_BLACKHAND)
            {
                // Handle the boss state based on the current state of the chess event
                switch (instance->GetBossState(DATA_CHESS))
                {
                case NOT_STARTED:
                    instance->SetBossState(DATA_CHESS, IN_PROGRESS);
                    AddUsedAura(true);
                    break;
                case DONE:
                    instance->SetData(DATA_CHESS, SPECIAL);
                    AddUsedAura(true);
                    break;
                default:
                    break;
                }
            }

            CloseGossipMenuFor(player);
        }
        return true;
    }

    // Function which returns a random target by type and range
    Unit* GetPiece(uint8 type, float range, float arc = float(M_PI))
    {
        uint32 faction;

        if (type == TARGET_TYPE_FRIENDLY)
            faction = me->GetFaction();    // Get friendly list for this type
        else
            faction = me->GetFaction() == FACTION_ID_CHESS_ALLIANCE ? FACTION_ID_CHESS_HORDE : FACTION_ID_CHESS_ALLIANCE;

        // Get the list of chess pieces based on the faction
        const GuidList* tempSet = GetChessPieces(instance, faction);
        std::vector<Creature*> targets;
        targets.reserve(tempSet->size());
        for (GuidList::const_iterator itr = tempSet->begin(); itr != tempSet->end(); ++itr)
        {
            Creature* temp = ObjectAccessor::GetCreature(*me, (*itr));
            if (temp && temp->IsAlive())
            {
                if ((me->GetExactDist2d(temp) > range || !me->HasInArc(arc, temp))) //?hasinline
                    continue;

                // Skip friendly targets which are at full HP
                if (type == TARGET_TYPE_FRIENDLY && temp->GetHealth() == temp->GetMaxHealth())
                    continue;

                targets.push_back(temp);
            }
        }

        if (!targets.empty())
            return Trinity::Containers::SelectRandomContainerElement(targets);
        return nullptr;
    }

    // Function to get a square as close as possible to the enemy
    Unit* GetMovementSquare()
    {
        instance->SetGuidData(DATA_CHESS_TARGET, me->GetGUID());
        if (Creature* square = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CHESS_MOVEMENT_SQUARE)))
            return square;
        return nullptr;
    }

    uint32 DoCastPrimarySpell()
    {
        uint32 spellId = 0;
        float range = 25.0f;
        float arc = float(M_PI);

        switch (me->GetEntry())
        {
        case  NPC_KING_LLANE:               spellId = SPELL_HEROISM;         break;
        case  NPC_WARCHIEF_BLACKHAND:       spellId = SPELL_BLOODLUST;       break;
        case  NPC_HUMAN_CONJURER:           spellId = SPELL_ELEMENTAL_BLAST; break;
        case  NPC_ORC_WARLOCK:              spellId = SPELL_FIREBALL;        break;
        case  NPC_HUMAN_FOOTMAN:            spellId = SPELL_HEROIC_BLOW;     break;
        case  NPC_ORC_GRUNT:                spellId = SPELL_VICIOUS_STRIKE;  break;
        case  NPC_CONJURED_WATER_ELEMENTAL: spellId = SPELL_GEYSER;          break;
        case  NPC_SUMMONED_DAEMON:          spellId = SPELL_HELLFIRE;        break;
        case  NPC_HUMAN_CHARGER:            spellId = SPELL_SMASH;           break;
        case  NPC_ORC_WOLF:                 spellId = SPELL_BITE;            break;
        case  NPC_HUMAN_CLERIC:             spellId = SPELL_HEALING;         break;
        case  NPC_ORC_NECROLYTE:            spellId = SPELL_SHADOW_MEND;     break;
        }

        // Even if the target is not used in some cases, the check is necessary so that the spell is not cast in vain
        switch (spellId)
        {
        case SPELL_HEROISM:
        case SPELL_BLOODLUST:
            range = 20.0f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range, arc))
            {
                DoCastSelf(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
            break;
        case SPELL_HEROIC_BLOW:
        case SPELL_VICIOUS_STRIKE:
        case SPELL_SMASH:
        case SPELL_BITE:
            range = 8.0f;
            arc = 1.6f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range, arc))
            {
                DoCastAOE(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
            break;
        case SPELL_GEYSER:
        case SPELL_HELLFIRE:
            range = 9.0f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range, arc))
            {
                DoCastAOE(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
            break;
        case SPELL_ELEMENTAL_BLAST:
        case SPELL_FIREBALL:
            range = 20.0f;
            if (Unit* target = GetPiece(TARGET_TYPE_HOSTILE, range))
            {
                DoCast(target, spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
            break;
        case SPELL_HEALING:
        case SPELL_SHADOW_MEND:
            range = 25.0f;
            if (Unit* target = GetPiece(TARGET_TYPE_FRIENDLY, range))
            {
                DoCast(target, spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
            break;
        default:
            break;
        }
        return 5000;
    }

    uint32 DoCastSecondarySpell()
    {
        uint32 spellId = 0;
        float range = 25.0f;
        float arc = float(M_PI);

        switch (me->GetEntry())
        {
        case  NPC_KING_LLANE:               spellId = SPELL_SWEEP;               break;
        case  NPC_WARCHIEF_BLACKHAND:       spellId = SPELL_CLEAVE;              break;
        case  NPC_HUMAN_CONJURER:           spellId = SPELL_RAIN_OF_FIRE;        break;
        case  NPC_ORC_WARLOCK:              spellId = SPELL_POISON_CLOUD;        break;
        case  NPC_HUMAN_FOOTMAN:            spellId = SPELL_SHIELD_BLOCK;        break;
        case  NPC_ORC_GRUNT:                spellId = SPELL_WEAPON_DEFLECTION;   break;
        case  NPC_CONJURED_WATER_ELEMENTAL: spellId = SPELL_WATER_SHIELD;        break;
        case  NPC_SUMMONED_DAEMON:          spellId = SPELL_FIRE_SHIELD;         break;
        case  NPC_HUMAN_CHARGER:            spellId = SPELL_STOMP;               break;
        case  NPC_ORC_WOLF:                 spellId = SPELL_HOWL;                break;
        case  NPC_HUMAN_CLERIC:             spellId = SPELL_HOLY_LANCE;          break;
        case  NPC_ORC_NECROLYTE:            spellId = SPELL_SHADOW_SPEAR;        break;
        }

        // Even if the target is not used in some cases, the check is necessary so that the spell is not cast in vain
        switch (spellId)
        {
        case SPELL_RAIN_OF_FIRE:
        case SPELL_POISON_CLOUD:
        {
            if (Unit* target = GetPiece(TARGET_TYPE_HOSTILE, range))
            {
                DoCast(target, spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        case SPELL_SWEEP:
        case SPELL_CLEAVE:
        {
            range = 10.0f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range))
            {
                DoCastAOE(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        case SPELL_WATER_SHIELD:
        case SPELL_FIRE_SHIELD:
        {
            range = 9.0f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range, arc))
            {
                DoCastSelf(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        case SPELL_SHIELD_BLOCK:
        case SPELL_WEAPON_DEFLECTION:
        {
            range = 8.0f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range, arc))
            {
                DoCastSelf(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        case SPELL_STOMP:
        case SPELL_HOWL:
        {
            range = 10.0f;
            arc = 1.6f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range))
            {
                DoCastAOE(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        case SPELL_HOLY_LANCE:
        case SPELL_SHADOW_SPEAR:
        {
            range = 18.0f;
            arc = 1.6f;
            if (GetPiece(TARGET_TYPE_HOSTILE, range))
            {
                DoCastAOE(spellId);
                const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(spellId);
                return spellInfo->GetRecoveryTime() ? spellInfo->GetRecoveryTime() : 5000;
            }
        }
        break;
        default:
            break;
        }

        return 5000;
    }

    void AddUsedAura(bool on)
    {
        if (on)
        {
            if (Creature* currSquare = me->FindNearestCreature(NPC_SQUARE_BLACK, 0.0f))
                currSquare->AddAura(SPELL_IS_SQUARE_USED, currSquare);
            if (Creature* currSquare = me->FindNearestCreature(NPC_SQUARE_WHITE, 0.0f))
                currSquare->AddAura(SPELL_IS_SQUARE_USED, currSquare);
        }
        else
        {
            if (Creature* currSquare = me->FindNearestCreature(NPC_SQUARE_BLACK, 0.0f))
                currSquare->RemoveAllAuras();
            if (Creature* currSquare = me->FindNearestCreature(NPC_SQUARE_WHITE, 0.0f))
                currSquare->RemoveAllAuras();
        }
    }

protected:
    InstanceScript* instance;
    ObjectGuid currSquareGUID;
    EventMap events;
    bool primarySpell;
};

/*######
## npc_chess_piece_king
######*/

struct npc_chess_piece_king : public npc_chess_piece_generic
{
    npc_chess_piece_king(Creature* creature) : npc_chess_piece_generic(creature)
    {
        isAttacked = false;
        Reset();
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!damage || !isAttacked || attacker->GetTypeId() != TYPEID_UNIT)
            return;

        if (Creature* medivh = instance->GetCreature(DATA_ECHO_OF_MEDIVH))
        {
            uint32 soundId;
            if ((me->GetEntry() == NPC_KING_LLANE && instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE) ||
                (me->GetEntry() == NPC_WARCHIEF_BLACKHAND && instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE))
                soundId = SOUND_ID_CHECK_PLAYER;
            else
                soundId = SOUND_ID_CHECK_MEDIVH;
            DoPlaySoundToSet(medivh, soundId);
        }

        isAttacked = true;
    }

    void JustDied(Unit* killer) override
    {
        npc_chess_piece_generic::JustDied(killer);

        if (instance->GetBossState(DATA_CHESS) == DONE)
            instance->SetData(DATA_CHESS, DONE);
        else
        {
            EncounterState chessResult;
            if ((me->GetEntry() == NPC_KING_LLANE && instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE) ||
                (me->GetEntry() == NPC_WARCHIEF_BLACKHAND && instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE))
                chessResult = DONE;
            else
                chessResult = FAIL;
            instance->SetBossState(DATA_CHESS, chessResult);
        }
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GAME_IN_SESSION);
    }
protected:
    bool isAttacked;
};

/*######
## npc_chess_move_trigger
######*/

struct npc_chess_move_trigger : public ScriptedAI //todo delete
{
    npc_chess_move_trigger(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;
    }
};

///
/// chess piece spells
///

class FactionCheck
{
public:
    explicit FactionCheck(uint32 faction) : _faction(faction) { }
    bool operator()(WorldObject* object)
    {
        return object->GetFaction() != _faction;
    }

private:
    uint32 _faction;
};

// 37474 - Sweep
// 37476 - Cleave
struct spell_king_primary : public SpellScript
{
    PrepareSpellScript(spell_king_primary);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        uint32 faction = GetCaster()->GetFaction() == FACTION_ID_CHESS_ALLIANCE ? FACTION_ID_CHESS_HORDE : FACTION_ID_CHESS_ALLIANCE;
        targets.remove_if(FactionCheck(faction));
        targets.remove_if([&](WorldObject* obj)
            {
                //if (!caster->isInFrontInMap(obj->ToUnit(), 4.2f, 1.6f))
                if ((caster->GetExactDist2d(obj) <= 8.1f && caster->HasInArc(1.6f, obj))) //HasInLine
                    return false;
                return true;
            });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_king_primary::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//king
// 37471 - Heroism
// 37472 - Bloodlust
//bishop
// 37459 - Holy Lance
// 37461 - Shadow Spear
//knight
// 37453 - Smash
// 37454 - Bite
// 37498 - Stomp
// 37502 - Howl
//rook
// 37427 - Geyser
// 37428 - Hellfire
//pawn
// 37406 - Heroic Blow
// 37413 - Vicious Strike
struct spell_chess : public SpellScript
{
    PrepareSpellScript(spell_chess);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 faction;
        if (GetSpellInfo()->Id == SPELL_HEROISM || GetSpellInfo()->Id == SPELL_BLOODLUST)
            faction = GetCaster()->GetFaction();
        else
            faction = GetCaster()->GetFaction() == FACTION_ID_CHESS_ALLIANCE ? FACTION_ID_CHESS_HORDE : FACTION_ID_CHESS_ALLIANCE;
        targets.remove_if(FactionCheck(faction));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chess::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chess::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 30284 - Change Facing
struct spell_change_facing : public SpellScript
{
    PrepareSpellScript(spell_change_facing);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 faction = GetCaster()->GetFaction() == FACTION_ID_CHESS_ALLIANCE ? FACTION_ID_CHESS_HORDE : FACTION_ID_CHESS_ALLIANCE;
        targets.remove_if(FactionCheck(faction));

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitEffect(effIndex);
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            float angle = caster->GetRelativeAngle(target);
            float ori = caster->GetOrientation();
            if (angle <= M_PI)
                ori += angle;
            else
            {
                angle = M_PI_M2 - angle;
                ori -= angle;
            }
            caster->SetOrientation(ori);
            caster->SetFacingToObject(target);
        }

        //??caster->CastSpell(caster, SPELL_MOVE_COOLDOWN, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_change_facing::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_change_facing::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 37146 - Move Pawn
// 37144 - Move Knight
// 37148 - Move Queen
// 37151 - Move Rock
// 37152 - Move Bishop
// 37153 - Move King
struct spell_piece_move : public SpellScript
{
    PrepareSpellScript(spell_piece_move);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_IS_SQUARE_USED));
        targets.remove_if([](WorldObject* obj)
            {
                if (obj->GetEntry() != NPC_SQUARE_WHITE && obj->GetEntry() != NPC_SQUARE_BLACK)
                    return true;
                return false;
            });
        if (targets.empty())
            return;

        WorldObject* target = targets.front();
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            if (Creature* currSquare = caster->FindNearestCreature(NPC_SQUARE_BLACK, 0.0f))
                currSquare->RemoveAllAuras();
            if (Creature* currSquare = caster->FindNearestCreature(NPC_SQUARE_WHITE, 0.0f))
                currSquare->RemoveAllAuras();

            caster->GetMotionMaster()->MovePoint(0, target->GetPosition());
            float angle = caster->GetRelativeAngle(target);
            float ori = caster->GetOrientation();
            if (angle <= M_PI)
                ori += angle;
            else
            {
                angle = M_PI_M2 - angle;
                ori -= angle;
            }
            caster->SetOrientation(ori);
            target->CastSpell(target, SPELL_MOVE_MARKER, true);
            target->CastSpell(target, SPELL_DISABLE_SQUARE, true);
            target->CastSpell(target, SPELL_IS_SQUARE_USED, true);
            caster->CastSpell(caster, SPELL_MOVE_COOLDOWN, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_piece_move::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_piece_move::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

///
/// helper spells
///

// 30019 - Control Piece
class spell_control_piece : public AuraScript
{
    PrepareAuraScript(spell_control_piece);

    void ApplyBindSight(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        PreventDefaultAction();
    }

    void ApplyCharm(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        PreventDefaultAction();
        //??me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        Unit* caster = GetCaster();
        if (Player* playerCharmer = caster->ToPlayer())
        {
            if (Unit* target = GetTarget())
            {
                //!HACK
                uint32 faction = target->GetFaction();
                target->SetCharmedBy(caster, CHARM_TYPE_POSSESS);
                playerCharmer->SetClientControl(target, false);
                target->SetFaction(faction);
            }
        }
    }

    void OnRemoveDummy(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (Unit* charm = caster->GetCharmed())
        {
            charm->RemoveAurasDueToSpell(SPELL_CONTROL_PIECE);
            caster->RemoveAurasDueToSpell(SPELL_CONTROL_PIECE);
        }
    }

    void OnRemoveCharm(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetTarget())
            if (Player* playerCharmer = caster->ToPlayer())
                playerCharmer->SetClientControl(target, true);
        caster->RemoveAurasDueToSpell(SPELL_CONTROL_PIECE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_control_piece::ApplyBindSight, EFFECT_0, SPELL_AURA_BIND_SIGHT, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_control_piece::ApplyCharm, EFFECT_2, SPELL_AURA_MOD_CHARM, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_control_piece::OnRemoveDummy, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_control_piece::OnRemoveCharm, EFFECT_2, SPELL_AURA_MOD_CHARM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 30253 - Move to Square
struct spell_move_to_square : public SpellScript
{
    PrepareSpellScript(spell_move_to_square);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (target)
            if (caster->GetTypeId() == TYPEID_UNIT)
            {
                target->CastSpell(target, SPELL_DISABLE_SQUARE, true);
                target->CastSpell(target, SPELL_IS_SQUARE_USED, true);
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_move_to_square::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 30543 - Move Cooldown
struct spell_move_cooldown : public SpellScript
{
    PrepareSpellScript(spell_move_cooldown);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        Player* owner = caster->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!target)
            return;
        if (!owner)
            return;
        if (Creature* creature = caster->ToCreature())
        {
            WorldPacket data;
            uint32 spellIdMove = creature->GetCreatureTemplate()->spells[0];
            uint32 spellIdFacing = creature->GetCreatureTemplate()->spells[1];
            caster->GetSpellHistory()->BuildCooldownPacket(data, SPELL_COOLDOWN_FLAG_NONE, spellIdMove, 15000);
            owner->SendDirectMessage(&data);
            data.clear();
            caster->GetSpellHistory()->BuildCooldownPacket(data, SPELL_COOLDOWN_FLAG_NONE, spellIdFacing, 15000);
            owner->SendDirectMessage(&data);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_move_cooldown::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//39401 - Game Over
struct spell_game_over : public SpellScript
{
    PrepareSpellScript(spell_game_over);

    //!I'm not sure exactly who the spell is supposed to be cast on
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj)
            {
                if (obj->GetFaction() != FACTION_ID_CHESS_ALLIANCE && obj->GetFaction() != FACTION_ID_CHESS_HORDE)
                    return true;
                return false;
            });

        targets.remove_if([](WorldObject* obj)
            {
                if (Unit* unit = obj->ToUnit())
                    if (unit->IsAlive())
                        return false;
                return true;
            });
    }

    void ApplyAura(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->RemoveAurasDueToSpell(SPELL_CHESS_AI_ATTACK_TIMER);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_game_over::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_game_over::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_game_over::ApplyAura, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

///
/// Medivh spells
///

// 39338 - Hand of Medivh Horde
// 39342 - Hand of Medivh Alliance
struct spell_hand_of_medivh : public SpellScript
{
    PrepareSpellScript(spell_hand_of_medivh);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 faction;
        if (GetSpellInfo()->Id == SPELL_HAND_OF_MEDIVH_HORDE)
            faction = FACTION_ID_CHESS_ALLIANCE;
        else
            faction = FACTION_ID_CHESS_HORDE;
        targets.remove_if(FactionCheck(faction));

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, SPELL_HAND_OF_MEDIVH);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hand_of_medivh::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_hand_of_medivh::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 39341 - Fury of Medivh Horde
// 39344 - Fury of Medivh Alliance
struct spell_fury_of_medivh : public SpellScript
{
    PrepareSpellScript(spell_fury_of_medivh);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 faction;
        if (GetSpellInfo()->Id == SPELL_FURY_OF_MEDIVH_ALLIANCE)
        {
            faction = FACTION_ID_CHESS_ALLIANCE;
            summonSpellId = 39343;
        }
        else
        {
            faction = FACTION_ID_CHESS_HORDE;
            summonSpellId = 39345;
        }
        targets.remove_if(FactionCheck(faction));

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, summonSpellId);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fury_of_medivh::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_fury_of_medivh::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
private:
    uint32 summonSpellId;
};

// 39334 - Full Heal Horde
// 39335 - Full Heal Alliance
struct spell_heal_of_medivh : public SpellScript
{
    PrepareSpellScript(spell_heal_of_medivh);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (GetCaster()->GetEntry() == NPC_CHESS_VICTORY_CONTROLLER)
        {
            targets.remove_if([](WorldObject* obj)
                {
                    if (obj->GetEntry() != NPC_SQUARE_WHITE && obj->GetEntry() != NPC_SQUARE_BLACK)
                        return true;
                    return false;
                });
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
            return;
        }

        uint32 faction;
        if (GetSpellInfo()->Id == SPELL_FULL_HEAL_HORDE)
            faction = FACTION_ID_CHESS_ALLIANCE;
        else
            faction = FACTION_ID_CHESS_HORDE;

        targets.remove_if(FactionCheck(faction));

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_heal_of_medivh::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

void AddSC_chess_event()
{
    RegisterKarazhanCreatureAI(npc_echo_of_medivh);
    RegisterKarazhanCreatureAI(npc_chess_piece_generic);
    RegisterKarazhanCreatureAI(npc_chess_piece_king);
    RegisterKarazhanCreatureAI(npc_chess_move_trigger);
    RegisterSpellScript(spell_king_primary);
    RegisterSpellScript(spell_chess);
    RegisterSpellScript(spell_change_facing);
    RegisterSpellScript(spell_control_piece);
    RegisterSpellScript(spell_move_to_square);
    RegisterSpellScript(spell_piece_move);
    RegisterSpellScript(spell_move_cooldown);
    RegisterSpellScript(spell_game_over);
    RegisterSpellScript(spell_hand_of_medivh);
    RegisterSpellScript(spell_fury_of_medivh);
    RegisterSpellScript(spell_heal_of_medivh);
}
