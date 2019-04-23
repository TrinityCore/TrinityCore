/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
SDName: Winterspring
SD%Complete: Almost Completely Emptied
SDComment: Vendor Rivern Frostwind. Quest Support 4901
SDCategory: Winterspring
EndScriptData */

/* ContentData
npc_rivern_frostwind
npc_ranshalla
go_elune_fire
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

/*######
## npc_rivern_frostwind
######*/

class npc_rivern_frostwind : public CreatureScript
{
public:
    npc_rivern_frostwind() : CreatureScript("npc_rivern_frostwind") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor() && player->GetReputationRank(589) == REP_EXALTED)
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

enum Says
{
    // Escort texts
    SAY_QUEST_START         = 0,
    SAY_ENTER_OWL_THICKET   = 1,
    SAY_REACH_TORCH         = 2,
    SAY_AFTER_TORCH         = 3,
    SAY_REACH_ALTAR_1       = 4,
    SAY_REACH_ALTAR_2       = 5,

    // After lighting the altar cinematic
    SAY_RANSHALLA_ALTAR_1   = 6,
    SAY_RANSHALLA_ALTAR_2   = 7,
    SAY_PRIESTESS_ALTAR_3   = 8,
    SAY_PRIESTESS_ALTAR_4   = 9,
    SAY_RANSHALLA_ALTAR_5   = 10,
    SAY_RANSHALLA_ALTAR_6   = 11,
    SAY_PRIESTESS_ALTAR_7   = 12,
    SAY_PRIESTESS_ALTAR_8   = 13,
    SAY_PRIESTESS_ALTAR_9   = 14,
    SAY_PRIESTESS_ALTAR_10  = 15,
    SAY_PRIESTESS_ALTAR_11  = 16,
    SAY_PRIESTESS_ALTAR_12  = 17,
    SAY_PRIESTESS_ALTAR_13  = 18,
    SAY_PRIESTESS_ALTAR_14  = 19,
    SAY_VOICE_ALTAR_15      = 20,
    SAY_PRIESTESS_ALTAR_16  = 21,
    SAY_PRIESTESS_ALTAR_17  = 22,
    SAY_PRIESTESS_ALTAR_18  = 23,
    SAY_PRIESTESS_ALTAR_19  = 24,
    SAY_PRIESTESS_ALTAR_20  = 25,
    SAY_PRIESTESS_ALTAR_21  = 26,
    SAY_RANSHALLA_END_1     = 27,
    SAY_RANSHALLA_END_2     = 28,

    EMOTE_CHANT_SPELL       = 29,
};

enum Spells
{
    SPELL_LIGHT_TORCH       = 18953,  // channeled spell by Ranshalla while waiting for the torches / altar
};

enum NPCs
{
    NPC_RANSHALLA           = 10300,
    NPC_PRIESTESS_ELUNE     = 12116,
    NPC_VOICE_ELUNE         = 12152,
    NPC_GUARDIAN_ELUNE      = 12140,
};

enum GOs
{
    GO_ELUNE_ALTAR          = 177404,
    GO_ELUNE_FIRE           = 177417,
    GO_ELUNE_GEM            = 177414, // is respawned in script
    GO_ELUNE_LIGHT          = 177415, // are respawned in script
};

enum Quests
{
    QUEST_GUARDIANS_ALTAR   = 4901,
};

enum Dummies
{
    NPC_PRIESTESS_DATA_1    = -1, // dummy member for the first priestess (right)
    NPC_PRIESTESS_DATA_2    = -2, // dummy member for the second priestess (left)
    DATA_MOVE_PRIESTESS     = -3, // dummy member to check the priestess movement
    DATA_EVENT_END          = -4, // dummy member to indicate the event end

    EVENT_RESUME            = 1,  // trigger rest of event
};

// DialogueHelper (imported from SD)

struct DialogueEntry
{
    int32 TextEntry;    ///< To be said text entry
    int32 SayerEntry;   ///< Entry of the mob who should say
    uint32 SayTimer;    ///< Time delay until next text of array is said (0 stops)
};

class DialogueHelper
{
public:
    // The array MUST be terminated by {0, 0, 0}
    DialogueHelper(DialogueEntry const* dialogueArray) :
      _dialogueArray(dialogueArray),
          _currentEntry(NULL),
          _actionTimer(0)
      { }
      // The array MUST be terminated by {0, 0, 0, 0, 0}

      /// Function to initialize the dialogue helper for instances. If not used with instances, GetSpeakerByEntry MUST be overwritten to obtain the speakers
      /// Set if take first entries or second entries

      void StartNextDialogueText(int32 textEntry)
      {
          // Find textEntry
          bool found = false;

          for (DialogueEntry const* entry = _dialogueArray; entry->TextEntry; ++entry)
          {
              if (entry->TextEntry == textEntry)
              {
                  _currentEntry = entry;
                  found = true;
                  break;
              }
          }

          if (!found)
              return;

          DoNextDialogueStep();
      }

      void DialogueUpdate(uint32 diff)
      {
          if (_actionTimer)
          {
              if (_actionTimer <= diff)
                  DoNextDialogueStep();
              else
                  _actionTimer -= diff;
          }
      }

protected:
    /// Will be called when a dialogue step was done
    virtual void JustDidDialogueStep(int32 /*entry*/) { }
    /// Will be called to get a speaker, MUST be implemented if not used in instances
    virtual Creature* GetSpeakerByEntry(int32 /*entry*/) { return NULL; }

private:
    void DoNextDialogueStep()
    {
        // Last Dialogue Entry done?
        if (!_currentEntry || !_currentEntry->TextEntry)
        {
            _actionTimer = 0;
            return;
        }

        // Get Text, SpeakerEntry and Timer
        int32 textEntry = _currentEntry->TextEntry;
        uint32 sayerEntry = _currentEntry->SayerEntry;
        _actionTimer = _currentEntry->SayTimer;

        // Simulate Case
        if (sayerEntry && textEntry >= 0)
        {
            // Use Speaker if directly provided
            if (Creature* speaker = GetSpeakerByEntry(sayerEntry))
                speaker->AI()->Talk(textEntry);
        }

        JustDidDialogueStep(_currentEntry->TextEntry);

        // Increment position
        ++_currentEntry;
    }

    DialogueEntry const* _dialogueArray;
    DialogueEntry const* _currentEntry;

    uint32 _actionTimer;
};

const DialogueEntry introDialogue[] =
{
    {SAY_REACH_ALTAR_1,         NPC_RANSHALLA,          2000},
    {SAY_REACH_ALTAR_2,         NPC_RANSHALLA,          3000},
    {NPC_RANSHALLA,             0,                         0}, // start the altar channeling
    {SAY_PRIESTESS_ALTAR_3,     NPC_PRIESTESS_DATA_2,   1000},
    {SAY_PRIESTESS_ALTAR_4,     NPC_PRIESTESS_DATA_1,   4000},
    {SAY_RANSHALLA_ALTAR_5,     NPC_RANSHALLA,          4000},
    {SAY_RANSHALLA_ALTAR_6,     NPC_RANSHALLA,          4000}, // start the escort here
    {SAY_PRIESTESS_ALTAR_7,     NPC_PRIESTESS_DATA_2,   4000},
    {SAY_PRIESTESS_ALTAR_8,     NPC_PRIESTESS_DATA_2,   5000}, // show the gem
    {GO_ELUNE_GEM,              0,                      5000},
    {SAY_PRIESTESS_ALTAR_9,     NPC_PRIESTESS_DATA_1,   4000}, // move priestess 1 near me
    {NPC_PRIESTESS_DATA_1,      0,                      3000},
    {SAY_PRIESTESS_ALTAR_10,    NPC_PRIESTESS_DATA_1,   5000},
    {SAY_PRIESTESS_ALTAR_11,    NPC_PRIESTESS_DATA_1,   4000},
    {SAY_PRIESTESS_ALTAR_12,    NPC_PRIESTESS_DATA_1,   5000},
    {SAY_PRIESTESS_ALTAR_13,    NPC_PRIESTESS_DATA_1,   8000}, // summon voice and guard of elune
    {NPC_VOICE_ELUNE,           0,                     12000},
    {SAY_VOICE_ALTAR_15,        NPC_VOICE_ELUNE,        5000}, // move priestess 2 near me
    {NPC_PRIESTESS_DATA_2,      0,                      3000},
    {SAY_PRIESTESS_ALTAR_16,    NPC_PRIESTESS_DATA_2,   4000},
    {SAY_PRIESTESS_ALTAR_17,    NPC_PRIESTESS_DATA_2,   6000},
    {SAY_PRIESTESS_ALTAR_18,    NPC_PRIESTESS_DATA_1,   5000},
    {SAY_PRIESTESS_ALTAR_19,    NPC_PRIESTESS_DATA_1,   3000}, // move the owlbeast
    {NPC_GUARDIAN_ELUNE,        0,                      2000},
    {SAY_PRIESTESS_ALTAR_20,    NPC_PRIESTESS_DATA_1,   4000}, // move the first priestess up
    {SAY_PRIESTESS_ALTAR_21,    NPC_PRIESTESS_DATA_2,  10000}, // move second priestess up
    {DATA_MOVE_PRIESTESS,       0,                      6000}, // despawn the gem
    {DATA_EVENT_END,            0,                      2000}, // turn towards the player
    {SAY_RANSHALLA_END_2,       NPC_RANSHALLA, 0},
    {0,                         0,                         0},
};

static Position wingThicketLocations[] =
{
    {5515.98f, -4903.43f, 846.30f, 4.58f},  // 0 right priestess summon loc
    {5501.94f, -4920.20f, 848.69f, 6.15f},  // 1 left priestess summon loc
    {5497.35f, -4906.49f, 850.83f, 2.76f},  // 2 guard of elune summon loc
    {5518.38f, -4913.47f, 845.57f, 0.00f},  // 3 right priestess move loc
    {5510.36f, -4921.17f, 846.33f, 0.00f},  // 4 left priestess move loc
    {5511.31f, -4913.82f, 847.17f, 0.00f},  // 5 guard of elune move loc
    {5518.51f, -4917.56f, 845.23f, 0.00f},  // 6 right priestess second move loc
    {5514.40f, -4921.16f, 845.49f, 0.00f}   // 7 left priestess second move loc
};

/*#####
# npc_ranshalla
#####*/

class npc_ranshalla : public CreatureScript
{
public:
    npc_ranshalla() : CreatureScript("npc_ranshalla") { }
    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_GUARDIANS_ALTAR)
        {
            creature->AI()->Talk(SAY_QUEST_START);
            creature->setFaction(FACTION_ESCORT_A_NEUTRAL_PASSIVE);

            if (npc_ranshallaAI* escortAI = dynamic_cast<npc_ranshallaAI*>(creature->AI()))
                escortAI->Start(false, false, player->GetGUID(), quest);

            return true;
        }

        return false;
    }
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ranshallaAI(creature);
    }

    struct npc_ranshallaAI : public npc_escortAI, private DialogueHelper
    {
        npc_ranshallaAI(Creature* creature) : npc_escortAI(creature),
            DialogueHelper(introDialogue)
        {
            Initialize();
        }

        void Initialize()
        {
            _delayTimer = 0;
        }

        uint32 _delayTimer;

        ObjectGuid _firstPriestessGUID;
        ObjectGuid _secondPriestessGUID;
        ObjectGuid _guardEluneGUID;
        ObjectGuid _voiceEluneGUID;
        ObjectGuid _altarGUID;

        void Reset() override
        {
            Initialize();
        }

        // Called when the player activates the torch / altar
        void DoContinueEscort(bool isAltarWaypoint = false)
        {
            me->InterruptNonMeleeSpells(false);

            if (isAltarWaypoint)
                Talk(SAY_RANSHALLA_ALTAR_1);
            else
                Talk(SAY_AFTER_TORCH);

            _delayTimer = 2000;
        }

        // Called when Ranshalla starts to channel on a torch / altar
        void DoChannelTorchSpell(bool isAltarWaypoint = false)
        {
            // Check if we are using the fire or the altar and remove the no_interact flag
            if (isAltarWaypoint)
            {
                if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_ELUNE_ALTAR, 10.0f))
                {
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    me->SetFacingToObject(go);
                    _altarGUID = go->GetGUID();
                }
            }
            else if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_ELUNE_FIRE, 10.0f))
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

            // Yell and set escort to pause
            Talk(SAY_REACH_TORCH);
            Talk(EMOTE_CHANT_SPELL);
            SetEscortPaused(true);
            DoCast(me, SPELL_LIGHT_TORCH);
        }

        void DoSummonPriestess()
        {
            // Summon 2 Elune priestess and make each of them move to a different spot
            if (Creature* priestess = me->SummonCreature(NPC_PRIESTESS_ELUNE, wingThicketLocations[0], TEMPSUMMON_CORPSE_DESPAWN, 0))
            {
                priestess->GetMotionMaster()->MovePoint(0, wingThicketLocations[3]);
                _firstPriestessGUID = priestess->GetGUID();
            }
            if (Creature* priestess = me->SummonCreature(NPC_PRIESTESS_ELUNE, wingThicketLocations[1], TEMPSUMMON_CORPSE_DESPAWN, 0))
            {
                // Left priestess should have a distinct move point because she is the one who starts the dialogue at point reach
                priestess->GetMotionMaster()->MovePoint(1, wingThicketLocations[4]);
                _secondPriestessGUID = priestess->GetGUID();
            }
        }

        void SummonedMovementInform(Creature* summoned, uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE || summoned->GetEntry() != NPC_PRIESTESS_ELUNE || pointId != 1)
                return;

            // Start the dialogue when the priestess reach the altar (they should both reach the point in the same time)
            StartNextDialogueText(SAY_PRIESTESS_ALTAR_3);
        }

        void WaypointReached(uint32 pointId) override
        {
            switch (pointId)
            {
                case 3:
                    Talk(SAY_ENTER_OWL_THICKET);
                    break;
                case 10: // Cavern 1
                case 15: // Cavern 2
                case 20: // Cavern 3
                case 25: // Cavern 4
                case 36: // Cavern 5
                    DoChannelTorchSpell();
                    break;
                case 39:
                    StartNextDialogueText(SAY_REACH_ALTAR_1);
                    SetEscortPaused(true);
                    break;
                case 41:
                {
                    // Search for all nearest lights and respawn them
                    std::list<GameObject*> eluneLights;
                    GetGameObjectListWithEntryInGrid(eluneLights, me, GO_ELUNE_LIGHT, 20.0f);
                    for (std::list<GameObject*>::const_iterator itr = eluneLights.begin(); itr != eluneLights.end(); ++itr)
                    {
                        if ((*itr)->isSpawned())
                            continue;

                        (*itr)->SetRespawnTime(115);
                        (*itr)->Refresh();
                    }

                    if (GameObject* altar = ObjectAccessor::GetGameObject(*me ,_altarGUID))
                        me->SetFacingToObject(altar);
                    break;
                }
                case 42:
                    // Summon the 2 priestess
                    SetEscortPaused(true);
                    DoSummonPriestess();
                    Talk(SAY_RANSHALLA_ALTAR_2);
                    events.ScheduleEvent(EVENT_RESUME, 2000);
                    break;
                case 44:
                    // Stop the escort and turn towards the altar
                    SetEscortPaused(true);
                    if (GameObject* altar = ObjectAccessor::GetGameObject(*me, _altarGUID))
                        me->SetFacingToObject(altar);
                    break;
            }
        }

        void JustDidDialogueStep(int32 entry) override
        {
            switch (entry)
            {
                case NPC_RANSHALLA:
                    // Start the altar channeling
                    DoChannelTorchSpell(true);
                    break;
                case SAY_RANSHALLA_ALTAR_6:
                    SetEscortPaused(false);
                    break;
                case SAY_PRIESTESS_ALTAR_8:
                    // make the gem respawn
                    if (GameObject* gem = GetClosestGameObjectWithEntry(me, GO_ELUNE_GEM, 10.0f))
                    {
                        if (gem->isSpawned())
                            break;

                        gem->SetRespawnTime(90);
                        gem->Refresh();
                    }
                    break;
                case SAY_PRIESTESS_ALTAR_9:
                    // move near the escort npc
                    if (Creature* priestess = ObjectAccessor::GetCreature(*me, _firstPriestessGUID))
                        priestess->GetMotionMaster()->MovePoint(0, wingThicketLocations[6]);
                    break;
                case SAY_PRIESTESS_ALTAR_13:
                    // summon the Guardian of Elune
                    if (Creature* guard = me->SummonCreature(NPC_GUARDIAN_ELUNE, wingThicketLocations[2], TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        guard->GetMotionMaster()->MovePoint(0, wingThicketLocations[5]);
                        _guardEluneGUID = guard->GetGUID();
                    }
                    // summon the Voice of Elune
                    if (GameObject* altar = ObjectAccessor::GetGameObject(*me, _altarGUID))
                    {
                        if (Creature* voice = me->SummonCreature(NPC_VOICE_ELUNE, *altar, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            _voiceEluneGUID = voice->GetGUID();
                    }
                    break;
                case SAY_VOICE_ALTAR_15:
                    // move near the escort npc and continue dialogue
                    if (Creature* priestess = ObjectAccessor::GetCreature(*me, _secondPriestessGUID))
                    {
                        priestess->AI()->Talk(SAY_PRIESTESS_ALTAR_14);
                        priestess->GetMotionMaster()->MovePoint(0, wingThicketLocations[7]);
                    }
                    break;
                case SAY_PRIESTESS_ALTAR_19:
                    // make the voice of elune leave
                    if (Creature* guard = ObjectAccessor::GetCreature(*me, _guardEluneGUID))
                    {
                        guard->GetMotionMaster()->MovePoint(0, wingThicketLocations[2]);
                        guard->DespawnOrUnsummon(4000);
                    }
                    break;
                case SAY_PRIESTESS_ALTAR_20:
                    // make the first priestess leave
                    if (Creature* priestess = ObjectAccessor::GetCreature(*me, _firstPriestessGUID))
                    {
                        priestess->GetMotionMaster()->MovePoint(0, wingThicketLocations[0]);
                        priestess->DespawnOrUnsummon(4000);
                    }
                    break;
                case SAY_PRIESTESS_ALTAR_21:
                    // make the second priestess leave
                    if (Creature* priestess = ObjectAccessor::GetCreature(*me, _secondPriestessGUID))
                    {
                        priestess->GetMotionMaster()->MovePoint(0, wingThicketLocations[1]);
                        priestess->DespawnOrUnsummon(4000);
                    }
                    break;
                case DATA_EVENT_END:
                    // Turn towards the player
                    if (Player* player = GetPlayerForEscort())
                    {
                        me->SetFacingToObject(player);
                        Talk(SAY_RANSHALLA_END_1, player);
                    }
                    break;
                case SAY_RANSHALLA_END_2:
                    // Turn towards the altar and kneel - quest complete
                    if (GameObject* altar = ObjectAccessor::GetGameObject(*me, _altarGUID))
                    {
                        me->SetFacingToObject(altar);
                        altar->ResetDoorOrButton();
                    }
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    if (Player* player = GetPlayerForEscort())
                    {
                        player->GroupEventHappens(QUEST_GUARDIANS_ALTAR, me);
                        Talk(SAY_RANSHALLA_END_2, player);
                    }
                    me->DespawnOrUnsummon(4000);
                    break;
            }
        }

        Creature* GetSpeakerByEntry(int32 entry) override
        {
            switch (entry)
            {
                case NPC_RANSHALLA:
                    return me;
                case NPC_VOICE_ELUNE:
                    return ObjectAccessor::GetCreature(*me, _voiceEluneGUID);
                case NPC_PRIESTESS_DATA_1:
                    return ObjectAccessor::GetCreature(*me, _firstPriestessGUID);
                case NPC_PRIESTESS_DATA_2:
                    return ObjectAccessor::GetCreature(*me, _secondPriestessGUID);
                default:
                    return NULL;
            }

        }

        void UpdateEscortAI(uint32 diff) override
        {
            DialogueUpdate(diff);

            if (_delayTimer)
            {
                if (_delayTimer <= diff)
                {
                    SetEscortPaused(false);
                    _delayTimer = 0;
                }
                else
                    _delayTimer -= diff;
            }
            events.Update(diff);
            if (events.ExecuteEvent() == EVENT_RESUME)
                StartNextDialogueText(SAY_PRIESTESS_ALTAR_3);

            npc_escortAI::UpdateEscortAI(diff);
        }
    private:
        EventMap events;
    };
};

/*#####
# go_elune_fire
#####*/

class go_elune_fire : public GameObjectScript
{
public:
    go_elune_fire() : GameObjectScript("go_elune_fire") { }
    bool OnGossipHello(Player* /*player*/, GameObject* go) override
    {
        // Check if we are using the torches or the altar
        bool isAltar = false;

        if (go->GetEntry() == GO_ELUNE_ALTAR)
            isAltar = true;

        if (Creature* ranshalla = GetClosestCreatureWithEntry(go, NPC_RANSHALLA, 10.0f))
        {
            if (npc_ranshalla::npc_ranshallaAI* escortAI = dynamic_cast<npc_ranshalla::npc_ranshallaAI*>(ranshalla->AI()))
                escortAI->DoContinueEscort(isAltar);
        }
        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

        return false;
    }
};

void AddSC_winterspring()
{
    new npc_rivern_frostwind();
    new npc_ranshalla();
    new go_elune_fire();
}
