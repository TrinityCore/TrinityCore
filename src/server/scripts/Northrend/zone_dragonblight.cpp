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
SDName: Dragonblight
SD%Complete: 100
SDComment:
SDCategory: Dragonblight
EndScriptData */

/* ContentData
npc_alexstrasza_wr_gate
EndContentData */

#include "ScriptMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"

/*#####
# npc_commander_eligor_dawnbringer
#####*/

enum CommanderEligorDawnbringer
{
    MODEL_IMAGE_OF_KELTHUZAD           = 24787, // Image of Kel'Thuzad
    MODEL_IMAGE_OF_SAPPHIRON           = 24788, // Image of Sapphiron
    MODEL_IMAGE_OF_RAZUVIOUS           = 24799, // Image of Razuvious
    MODEL_IMAGE_OF_GOTHIK              = 24804, // Image of Gothik
    MODEL_IMAGE_OF_THANE               = 24802, // Image of Thane Korth'azz
    MODEL_IMAGE_OF_BLAUMEUX            = 24794, // Image of Lady Blaumeux
    MODEL_IMAGE_OF_ZELIEK              = 24800, // Image of Sir Zeliek
    MODEL_IMAGE_OF_PATCHWERK           = 24798, // Image of Patchwerk
    MODEL_IMAGE_OF_GROBBULUS           = 24792, // Image of Grobbulus
    MODEL_IMAGE_OF_THADDIUS            = 24801, // Image of Thaddius
    MODEL_IMAGE_OF_GLUTH               = 24803, // Image of Gluth
    MODEL_IMAGE_OF_ANUBREKHAN          = 24789, // Image of Anub'rekhan
    MODEL_IMAGE_OF_FAERLINA            = 24790, // Image of Faerlina
    MODEL_IMAGE_OF_MAEXXNA             = 24796, // Image of Maexxna
    MODEL_IMAGE_OF_NOTH                = 24797, // Image of Noth
    MODEL_IMAGE_OF_HEIGAN              = 24793, // Image of Heigan
    MODEL_IMAGE_OF_LOATHEB             = 24795, // Image of Loatheb

    NPC_IMAGE_OF_KELTHUZAD             = 27766, // Image of Kel'Thuzad
    NPC_IMAGE_OF_SAPPHIRON             = 27767, // Image of Sapphiron
    NPC_IMAGE_OF_RAZUVIOUS             = 27768, // Image of Razuvious
    NPC_IMAGE_OF_GOTHIK                = 27769, // Image of Gothik
    NPC_IMAGE_OF_THANE                 = 27770, // Image of Thane Korth'azz
    NPC_IMAGE_OF_BLAUMEUX              = 27771, // Image of Lady Blaumeux
    NPC_IMAGE_OF_ZELIEK                = 27772, // Image of Sir Zeliek
    NPC_IMAGE_OF_PATCHWERK             = 27773, // Image of Patchwerk
    NPC_IMAGE_OF_GROBBULUS             = 27774, // Image of Grobbulus
    NPC_IMAGE_OF_THADDIUS              = 27775, // Image of Thaddius
    NPC_IMAGE_OF_GLUTH                 = 27782, // Image of Gluth
    NPC_IMAGE_OF_ANUBREKHAN            = 27776, // Image of Anub'rekhan
    NPC_IMAGE_OF_FAERLINA              = 27777, // Image of Faerlina
    NPC_IMAGE_OF_MAEXXNA               = 27778, // Image of Maexxna
    NPC_IMAGE_OF_NOTH                  = 27779, // Image of Noth
    NPC_IMAGE_OF_HEIGAN                = 27780, // Image of Heigan
    NPC_IMAGE_OF_LOATHEB               = 27781, // Image of Loatheb

    NPC_INFANTRYMAN                    = 27160, // Add in case I randomize the spawning
    NPC_SENTINAL                       = 27162,
    NPC_BATTLE_MAGE                    = 27164,

    // Five platforms to choose from
    SAY_PINNACLE                       = 0,
    SAY_DEATH_KNIGHT_WING              = 1,
    SAY_ABOMINATION_WING               = 2,
    SAY_SPIDER_WING                    = 3,
    SAY_PLAGUE_WING                    = 4,
    // Used in all talks
    SAY_TALK_COMPLETE                  = 5,
    // Pinnacle of Naxxramas
    SAY_SAPPHIRON                      = 6,
    SAY_KELTHUZAD_1                    = 7,
    SAY_KELTHUZAD_2                    = 8,
    SAY_KELTHUZAD_3                    = 9,
    // Death knight wing of Naxxramas
    SAY_RAZUVIOUS                      = 10,
    SAY_GOTHIK                         = 11,
    SAY_DEATH_KNIGHTS_1                = 12,
    SAY_DEATH_KNIGHTS_2                = 13,
    SAY_DEATH_KNIGHTS_3                = 14,
    SAY_DEATH_KNIGHTS_4                = 15,
    // Blighted abomination wing of Naxxramas
    SAY_PATCHWERK                      = 16,
    SAY_GROBBULUS                      = 17,
    SAY_GLUTH                          = 18,
    SAY_THADDIUS                       = 19,
    // Accursed spider wing of Naxxramas
    SAY_ANUBREKHAN                     = 20,
    SAY_FAERLINA                       = 21,
    SAY_MAEXXNA                        = 22,
    // Dread plague wing of Naxxramas
    SAY_NOTH                           = 23,
    SAY_HEIGAN_1                       = 24,
    SAY_HEIGAN_2                       = 25,
    SAY_LOATHEB                        = 26,

    SPELL_HEROIC_IMAGE_CHANNEL         = 49519,

    EVENT_START_RANDOM                 = 1,
    EVENT_MOVE_TO_POINT                = 2,
    EVENT_TALK_COMPLETE                = 3,
    EVENT_GET_TARGETS                  = 4,
    EVENT_KELTHUZAD_2                  = 5,
    EVENT_KELTHUZAD_3                  = 6,
    EVENT_DEATH_KNIGHTS_2              = 7,
    EVENT_DEATH_KNIGHTS_3              = 8,
    EVENT_DEATH_KNIGHTS_4              = 9,
    EVENT_HEIGAN_2                     = 10
};

uint32 const AudienceMobs[3] = { NPC_INFANTRYMAN, NPC_SENTINAL, NPC_BATTLE_MAGE };

Position const PosTalkLocations[6] =
{
    { 3805.453f, -682.9075f, 222.2917f, 2.793398f }, // Pinnacle of Naxxramas
    { 3807.508f, -691.0882f, 221.9688f, 2.094395f }, // Death knight wing of Naxxramas
    { 3797.228f, -690.3555f, 222.5019f, 1.134464f }, // Blighted abomination wing of Naxxramas
    { 3804.038f, -672.3098f, 222.5019f, 4.578917f }, // Accursed spider wing of Naxxramas
    { 3815.097f, -680.2596f, 221.9777f, 2.86234f  }, // Dread plague wing of Naxxramas
    { 3798.05f,  -680.611f,  222.9825f, 6.038839f }, // Home
};

class npc_commander_eligor_dawnbringer : public CreatureScript
{
    public: npc_commander_eligor_dawnbringer() : CreatureScript("npc_commander_eligor_dawnbringer") {}

        struct npc_commander_eligor_dawnbringerAI : public ScriptedAI
        {
            npc_commander_eligor_dawnbringerAI(Creature* creature) : ScriptedAI(creature)
            {
                talkWing = 0;
            }

            void Reset() override
            {
                talkWing = 0;
                for (ObjectGuid& guid : audienceList)
                    guid.Clear();

                for (ObjectGuid& guid : imageList)
                    guid.Clear();

                _events.ScheduleEvent(EVENT_GET_TARGETS, 5s);
                _events.ScheduleEvent(EVENT_START_RANDOM, 20s);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == 1)
                    {
                        me->SetFacingTo(PosTalkLocations[talkWing].GetOrientation());
                        TurnAudience();

                        switch (talkWing)
                        {
                        case 0: // Pinnacle of Naxxramas
                            {
                                switch (urand (0, 1))
                                {
                                    case 0: ChangeImage(NPC_IMAGE_OF_KELTHUZAD, MODEL_IMAGE_OF_KELTHUZAD, SAY_KELTHUZAD_1);
                                            _events.ScheduleEvent(EVENT_KELTHUZAD_2, 8000); break;
                                    case 1: ChangeImage(NPC_IMAGE_OF_SAPPHIRON, MODEL_IMAGE_OF_SAPPHIRON, SAY_SAPPHIRON); break;
                                }
                            }
                            break;
                        case 1: // Death knight wing of Naxxramas
                            {
                                switch (urand (0, 2))
                                {
                                    case 0: ChangeImage(NPC_IMAGE_OF_RAZUVIOUS, MODEL_IMAGE_OF_RAZUVIOUS, SAY_RAZUVIOUS); break;
                                    case 1: ChangeImage(NPC_IMAGE_OF_GOTHIK, MODEL_IMAGE_OF_GOTHIK, SAY_GOTHIK); break;
                                    case 2: ChangeImage(NPC_IMAGE_OF_THANE, MODEL_IMAGE_OF_THANE, SAY_DEATH_KNIGHTS_1);
                                            _events.ScheduleEvent(EVENT_DEATH_KNIGHTS_2, 10000); break;
                                }
                            }
                            break;
                        case 2: // Blighted abomination wing of Naxxramas
                            {
                                switch (urand (0, 3))
                                {
                                    case 0: ChangeImage(NPC_IMAGE_OF_PATCHWERK, MODEL_IMAGE_OF_PATCHWERK, SAY_PATCHWERK); break;
                                    case 1: ChangeImage(NPC_IMAGE_OF_GROBBULUS, MODEL_IMAGE_OF_GROBBULUS, SAY_GROBBULUS); break;
                                    case 2: ChangeImage(NPC_IMAGE_OF_THADDIUS, MODEL_IMAGE_OF_THADDIUS, SAY_THADDIUS); break;
                                    case 3: ChangeImage(NPC_IMAGE_OF_GLUTH, MODEL_IMAGE_OF_GLUTH, SAY_GLUTH); break;
                                }
                            }
                            break;
                        case 3: // Accursed spider wing of Naxxramas
                            {
                                switch (urand (0, 2))
                                {
                                    case 0: ChangeImage(NPC_IMAGE_OF_ANUBREKHAN, MODEL_IMAGE_OF_ANUBREKHAN, SAY_ANUBREKHAN); break;
                                    case 1: ChangeImage(NPC_IMAGE_OF_FAERLINA, MODEL_IMAGE_OF_FAERLINA, SAY_FAERLINA); break;
                                    case 2: ChangeImage(NPC_IMAGE_OF_MAEXXNA, MODEL_IMAGE_OF_MAEXXNA, SAY_MAEXXNA); break;
                                }
                            }
                            break;
                        case 4: // Dread plague wing of Naxxramas
                            {
                                switch (urand (0, 2))
                                {
                                    case 0: ChangeImage(NPC_IMAGE_OF_NOTH, MODEL_IMAGE_OF_NOTH, SAY_NOTH); break;
                                    case 1: ChangeImage(NPC_IMAGE_OF_HEIGAN, MODEL_IMAGE_OF_HEIGAN, SAY_HEIGAN_1);
                                            _events.ScheduleEvent(EVENT_HEIGAN_2, 8000); break;
                                    case 2: ChangeImage(NPC_IMAGE_OF_LOATHEB, MODEL_IMAGE_OF_LOATHEB, SAY_LOATHEB); break;
                                }
                            }
                            break;
                        case 5: // Home
                            _events.ScheduleEvent(EVENT_START_RANDOM, 30s);
                            break;
                        }
                    }
                }
            }

            void StoreTargets()
            {
                uint8 creaturecount;

                creaturecount = 0;

                for (uint8 ii = 0; ii < 3; ++ii)
                {
                    std::list<Creature*> creatureList;
                    GetCreatureListWithEntryInGrid(creatureList, me, AudienceMobs[ii], 15.0f);
                    for (Creature* creature : creatureList)
                    {
                        audienceList[creaturecount] = creature->GetGUID();
                        ++creaturecount;
                    }
                }

                if (Creature* creature = me->FindNearestCreature(NPC_IMAGE_OF_KELTHUZAD, 20.0f, true))
                    imageList[0] = creature->GetGUID();
                if (Creature* creature = me->FindNearestCreature(NPC_IMAGE_OF_RAZUVIOUS, 20.0f, true))
                    imageList[1] = creature->GetGUID();
                if (Creature* creature = me->FindNearestCreature(NPC_IMAGE_OF_PATCHWERK, 20.0f, true))
                    imageList[2] = creature->GetGUID();
                if (Creature* creature = me->FindNearestCreature(NPC_IMAGE_OF_ANUBREKHAN, 20.0f, true))
                    imageList[3] = creature->GetGUID();
                if (Creature* creature = me->FindNearestCreature(NPC_IMAGE_OF_NOTH, 20.0f, true))
                    imageList[4] = creature->GetGUID();
            }

            void ChangeImage(uint32 entry, uint32 model, uint8 text)
            {
                if (Creature* creature = ObjectAccessor::GetCreature(*me, imageList[talkWing]))
                {
                    Talk(text);
                    creature->SetEntry(entry);
                    creature->SetDisplayId(model);
                    creature->CastSpell(creature, SPELL_HEROIC_IMAGE_CHANNEL);
                    _events.ScheduleEvent(EVENT_TALK_COMPLETE, 40s);
                }
            }

            void TurnAudience()
            {
                for (uint8 i = 0; i < 10; ++i)
                {
                    if (Creature* creature = ObjectAccessor::GetCreature(*me, audienceList[i]))
                        creature->SetFacingToObject(me);
                }
            }

            void UpdateAI(uint32 diff) override
            {
               _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_RANDOM:
                            talkWing = urand (0, 4);
                            Talk(talkWing);
                            _events.ScheduleEvent(EVENT_MOVE_TO_POINT, 8s);
                            break;
                        case EVENT_MOVE_TO_POINT:
                            me->SetWalk(true);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(1, PosTalkLocations[talkWing].m_positionX, PosTalkLocations[talkWing].m_positionY, PosTalkLocations[talkWing].m_positionZ);
                            break;
                        case EVENT_TALK_COMPLETE:
                            talkWing = 5;
                            Talk(talkWing);
                            _events.ScheduleEvent(EVENT_MOVE_TO_POINT, 5s);
                            break;
                        case EVENT_GET_TARGETS:
                            StoreTargets();
                            break;
                        case EVENT_KELTHUZAD_2:
                            Talk(SAY_KELTHUZAD_2);
                            _events.ScheduleEvent(EVENT_KELTHUZAD_3, 8000);
                            break;
                        case EVENT_KELTHUZAD_3:
                            Talk(SAY_KELTHUZAD_3);
                            break;
                        case EVENT_DEATH_KNIGHTS_2:
                            Talk(SAY_DEATH_KNIGHTS_2);
                            if (Creature* creature = ObjectAccessor::GetCreature(*me, imageList[talkWing]))
                            {
                                creature->SetEntry(NPC_IMAGE_OF_BLAUMEUX);
                                creature->SetDisplayId(MODEL_IMAGE_OF_BLAUMEUX);
                            }
                            _events.ScheduleEvent(EVENT_DEATH_KNIGHTS_3, 10000);
                            break;
                        case EVENT_DEATH_KNIGHTS_3:
                            Talk(SAY_DEATH_KNIGHTS_3);
                            if (Creature* creature = ObjectAccessor::GetCreature(*me, imageList[talkWing]))
                            {
                                creature->SetEntry(NPC_IMAGE_OF_ZELIEK);
                                creature->SetDisplayId(MODEL_IMAGE_OF_ZELIEK);
                            }
                            _events.ScheduleEvent(EVENT_DEATH_KNIGHTS_4, 10000);
                            break;
                        case EVENT_DEATH_KNIGHTS_4:
                            Talk(SAY_DEATH_KNIGHTS_4);
                            break;
                        case EVENT_HEIGAN_2:
                            Talk(SAY_HEIGAN_2);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            private:
                EventMap _events;
                ObjectGuid audienceList[10];
                ObjectGuid imageList[5];
                uint8    talkWing;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_commander_eligor_dawnbringerAI(creature);
        }
};

/*######
## Quest Strengthen the Ancients (12096|12092)
######*/

enum StrengthenAncientsMisc
{
    SAY_WALKER_FRIENDLY         = 0,
    SAY_WALKER_ENEMY            = 1,
    SAY_LOTHALOR                = 0,

    SPELL_CREATE_ITEM_BARK      = 47550,
    SPELL_CONFUSED              = 47044,

    NPC_LOTHALOR                = 26321
};

class spell_q12096_q12092_dummy : public SpellScriptLoader // Strengthen the Ancients: On Interact Dummy to Woodlands Walker
{
public:
    spell_q12096_q12092_dummy() : SpellScriptLoader("spell_q12096_q12092_dummy") { }

    class spell_q12096_q12092_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q12096_q12092_dummy_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            uint32 roll = rand32() % 2;

            Creature* tree = GetHitCreature();
            Player* player = GetCaster()->ToPlayer();

            if (!tree || !player)
                return;

            tree->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

            if (roll == 1) // friendly version
            {
                tree->CastSpell(player, SPELL_CREATE_ITEM_BARK);
                tree->AI()->Talk(SAY_WALKER_FRIENDLY, player);
                tree->DespawnOrUnsummon(1000);
            }
            else // enemy version
            {
                tree->AI()->Talk(SAY_WALKER_ENEMY, player);
                tree->SetFaction(FACTION_MONSTER);
                tree->Attack(player, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_q12096_q12092_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_q12096_q12092_dummy_SpellScript();
    }
};

class spell_q12096_q12092_bark : public SpellScriptLoader // Bark of the Walkers
{
public:
    spell_q12096_q12092_bark() : SpellScriptLoader("spell_q12096_q12092_bark") { }

    class spell_q12096_q12092_bark_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q12096_q12092_bark_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Creature* lothalor = GetHitCreature();
            if (!lothalor || lothalor->GetEntry() != NPC_LOTHALOR)
                return;

            lothalor->AI()->Talk(SAY_LOTHALOR);
            lothalor->RemoveAura(SPELL_CONFUSED);
            lothalor->DespawnOrUnsummon(4000);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_q12096_q12092_bark_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_q12096_q12092_bark_SpellScript();
    }
};

/*######
## Quest: Defending Wyrmrest Temple ID: 12372
######*/

enum WyrmDefenderEnum
{
    // Quest data
    QUEST_DEFENDING_WYRMREST_TEMPLE          = 12372,
    GOSSIP_TEXTID_DEF1                       = 12899,

    // Gossip data
    GOSSIP_TEXTID_DEF2                       = 12900,

    // Spells data
    SPELL_CHARACTER_SCRIPT                   = 49213,
    SPELL_DEFENDER_ON_LOW_HEALTH_EMOTE       = 52421, // ID - 52421 Wyrmrest Defender: On Low Health Boss Emote to Controller - Random /self/
    SPELL_RENEW                              = 49263, // cast to heal drakes
    SPELL_WYRMREST_DEFENDER_MOUNT            = 49256,

    // Texts data
    WHISPER_MOUNTED                        = 0,
    BOSS_EMOTE_ON_LOW_HEALTH               = 2
};

#define GOSSIP_ITEM_1      "We need to get into the fight. Are you ready?"

class npc_wyrmrest_defender : public CreatureScript
{
    public:
        npc_wyrmrest_defender() : CreatureScript("npc_wyrmrest_defender") { }

        struct npc_wyrmrest_defenderAI : public VehicleAI
        {
            npc_wyrmrest_defenderAI(Creature* creature) : VehicleAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                hpWarningReady = true;
                renewRecoveryCanCheck = false;

                RenewRecoveryChecker = 0;
            }

            bool hpWarningReady;
            bool renewRecoveryCanCheck;

            uint32 RenewRecoveryChecker;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                VehicleAI::UpdateAI(diff);

                // Check system for Health Warning should happen first time whenever get under 30%,
                // after it should be able to happen only after recovery of last renew is fully done (20 sec),
                // next one used won't interfere
                if (hpWarningReady && me->GetHealthPct() <= 30.0f)
                {
                    me->CastSpell(me, SPELL_DEFENDER_ON_LOW_HEALTH_EMOTE);
                    hpWarningReady = false;
                }

                if (renewRecoveryCanCheck)
                {
                    if (RenewRecoveryChecker <= diff)
                    {
                        renewRecoveryCanCheck = false;
                        hpWarningReady = true;
                    }
                    else
                        RenewRecoveryChecker -= diff;
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_WYRMREST_DEFENDER_MOUNT:
                        Talk(WHISPER_MOUNTED, me->GetCharmerOrOwner());
                        me->SetImmuneToAll(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
                        break;
                    // Both below are for checking low hp warning
                    case SPELL_DEFENDER_ON_LOW_HEALTH_EMOTE:
                        Talk(BOSS_EMOTE_ON_LOW_HEALTH, me->GetCharmerOrOwner());
                        break;
                    case SPELL_RENEW:
                        if (!hpWarningReady && RenewRecoveryChecker <= 100)
                            RenewRecoveryChecker = 20000;

                        renewRecoveryCanCheck = true;
                        break;
                }
            }

            bool GossipHello(Player* player) override
            {
                if (player->GetQuestStatus(QUEST_DEFENDING_WYRMREST_TEMPLE) == QUEST_STATUS_INCOMPLETE)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, GOSSIP_TEXTID_DEF1, me->GetGUID());
                }
                else
                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());

                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                {
                    SendGossipMenuFor(player, GOSSIP_TEXTID_DEF2, me->GetGUID());
                    // Makes player cast trigger spell for 49207 on self
                    player->CastSpell(player, SPELL_CHARACTER_SCRIPT, true);
                    // The gossip should not auto close
                }

                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wyrmrest_defenderAI(creature);
        }
};

/*#####
# npc_torturer_lecraft
#####*/

enum TorturerLeCraft
{
    SPELL_HEMORRHAGE                   = 30478,
    SPELL_KIDNEY_SHOT                  = 30621,
    SPELL_HIGH_EXECUTORS_BRANDING_IRON = 48603,
    NPC_TORTURER_LECRAFT               = 27394,
    EVENT_HEMORRHAGE                   = 1,
    EVENT_KIDNEY_SHOT                  = 2,
    SAY_AGGRO                          = 0
};

class npc_torturer_lecraft : public CreatureScript
{
    public: npc_torturer_lecraft() : CreatureScript("npc_torturer_lecraft") {}

        struct npc_torturer_lecraftAI : public ScriptedAI
        {
            npc_torturer_lecraftAI(Creature* creature) : ScriptedAI(creature)
            {
                _textCounter = 1;
            }

            void Reset() override
            {
                _textCounter = 1;
                _playerGUID.Clear();
            }

            void JustEngagedWith(Unit* who) override
            {
                _events.ScheduleEvent(EVENT_HEMORRHAGE, 5s, 8s);
                _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12s, 15s);

                if (Player* player = who->ToPlayer())
                    Talk (SAY_AGGRO, player);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id != SPELL_HIGH_EXECUTORS_BRANDING_IRON)
                    return;

                if (Player* player = caster->ToPlayer())
                {
                    if (_textCounter == 1)
                        _playerGUID = player->GetGUID();

                    if (_playerGUID != player->GetGUID())
                        return;

                    Talk(_textCounter, player);

                    if (_textCounter == 5)
                        player->KilledMonsterCredit(NPC_TORTURER_LECRAFT);

                    ++_textCounter;

                    if (_textCounter == 13)
                        _textCounter = 6;
                }
            }

            void UpdateAI(uint32 diff) override
            {
               if (!UpdateVictim())
                   return;

               _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEMORRHAGE:
                            DoCastVictim(SPELL_HEMORRHAGE);
                            _events.ScheduleEvent(EVENT_HEMORRHAGE, urand(12000, 168000));
                            break;
                        case EVENT_KIDNEY_SHOT:
                            DoCastVictim(SPELL_KIDNEY_SHOT);
                            _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 20s, 26s);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            private:
                EventMap _events;
                uint8    _textCounter;
                ObjectGuid _playerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_torturer_lecraftAI(creature);
        }
};

enum MessengerTorvus
{
    NPC_MESSENGER_TORVUS        = 26649,
    QUEST_MESSAGE_FROM_THE_WEST = 12033,

    TALK_0 = 0
};

class at_nearby_messenger_torvus : public AreaTriggerScript
{
public:
    at_nearby_messenger_torvus() : AreaTriggerScript("at_nearby_messenger_torvus") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(QUEST_MESSAGE_FROM_THE_WEST))
                if (player->CanTakeQuest(quest, false))
                    if (Creature* creature = player->FindNearestCreature(NPC_MESSENGER_TORVUS, 50.0f, true))
                        creature->AI()->Talk(TALK_0, player);

        return true;
    }
};

void AddSC_dragonblight()
{
    new npc_commander_eligor_dawnbringer();
    new spell_q12096_q12092_dummy();
    new spell_q12096_q12092_bark();
    new npc_wyrmrest_defender();
    new npc_torturer_lecraft();
    new at_nearby_messenger_torvus();
}
