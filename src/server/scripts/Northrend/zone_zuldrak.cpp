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
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*####
## npc_drakuru_shackles
####*/

enum DrakuruShackles
{
    NPC_RAGECLAW                             = 29686,
    QUEST_TROLLS_IS_GONE_CRAZY               = 12861,
    SPELL_LEFT_CHAIN                         = 59951,
    SPELL_RIGHT_CHAIN                        = 59952,
    SPELL_UNLOCK_SHACKLE                     = 55083,
    SPELL_FREE_RAGECLAW                      = 55223
};

class npc_drakuru_shackles : public CreatureScript
{
public:
    npc_drakuru_shackles() : CreatureScript("npc_drakuru_shackles") { }

    struct npc_drakuru_shacklesAI : public ScriptedAI
    {
        npc_drakuru_shacklesAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _rageclawGUID.Clear();
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            float x, y, z;
            me->GetClosePoint(x, y, z, me->GetCombatReach() / 3, 0.1f);

            if (Creature* summon = me->SummonCreature(NPC_RAGECLAW, x, y, z, 0, TEMPSUMMON_DEAD_DESPAWN, 1000))
            {
                _rageclawGUID = summon->GetGUID();
                LockRageclaw(summon);
            }
        }

        void LockRageclaw(Creature* rageclaw)
        {
            // pointer check not needed
            me->SetFacingToObject(rageclaw);
            rageclaw->SetFacingToObject(me);

            DoCast(rageclaw, SPELL_LEFT_CHAIN, true);
            DoCast(rageclaw, SPELL_RIGHT_CHAIN, true);
        }

        void UnlockRageclaw(Unit* who, Creature* rageclaw)
        {
            if (!who)
                return;

            // pointer check not needed
            DoCast(rageclaw, SPELL_FREE_RAGECLAW, true);

            me->setDeathState(DEAD);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_UNLOCK_SHACKLE)
            {
                if (caster->ToPlayer()->GetQuestStatus(QUEST_TROLLS_IS_GONE_CRAZY) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* rageclaw = ObjectAccessor::GetCreature(*me, _rageclawGUID))
                    {
                        UnlockRageclaw(caster, rageclaw);
                        caster->ToPlayer()->KilledMonster(rageclaw->GetCreatureTemplate(), _rageclawGUID);
                        me->DespawnOrUnsummon();
                    }
                    else
                        me->setDeathState(JUST_DIED);
                }
            }
        }

        private:
            ObjectGuid _rageclawGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drakuru_shacklesAI(creature);
    }
};

/*####
## npc_captured_rageclaw
####*/

enum Rageclaw
{
    SPELL_UNSHACKLED                         = 55085,
    SPELL_KNEEL                              = 39656,
    SAY_RAGECLAW                             = 0
};

class npc_captured_rageclaw : public CreatureScript
{
public:
    npc_captured_rageclaw() : CreatureScript("npc_captured_rageclaw") { }

    struct npc_captured_rageclawAI : public ScriptedAI
    {
        npc_captured_rageclawAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetFaction(FACTION_FRIENDLY);
            DoCast(me, SPELL_KNEEL, true); // Little Hack for kneel - Thanks Illy :P
        }

        void MoveInLineOfSight(Unit* /*who*/) override { }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_FREE_RAGECLAW)
            {
                me->RemoveAurasDueToSpell(SPELL_LEFT_CHAIN);
                me->RemoveAurasDueToSpell(SPELL_RIGHT_CHAIN);
                me->RemoveAurasDueToSpell(SPELL_KNEEL);
                me->SetFaction(me->GetCreatureTemplate()->faction);
                DoCast(me, SPELL_UNSHACKLED, true);
                Talk(SAY_RAGECLAW);
                me->GetMotionMaster()->MoveRandom(10);
                me->DespawnOrUnsummon(10000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_captured_rageclawAI(creature);
    }
};


/*####
## npc_released_offspring_harkoa
####*/

class npc_released_offspring_harkoa : public CreatureScript
{
public:
    npc_released_offspring_harkoa() : CreatureScript("npc_released_offspring_harkoa") { }

    struct npc_released_offspring_harkoaAI : public ScriptedAI
    {
        npc_released_offspring_harkoaAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            float x, y, z;
            me->GetClosePoint(x, y, z, me->GetCombatReach() / 3, 25.0f);
            me->GetMotionMaster()->MovePoint(0, x, y, z);
        }

        void MovementInform(uint32 Type, uint32 /*uiId*/) override
        {
            if (Type != POINT_MOTION_TYPE)
                return;
            me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_released_offspring_harkoaAI(creature);
    }
};

/*######
## npc_crusade_recruit
######*/

enum CrusadeRecruit
{
    SPELL_QUEST_CREDIT                       = 50633,
    QUEST_TROLL_PATROL_INTESTINAL_FORTITUDE  = 12509,
    SAY_RECRUIT                              = 0
};

enum CrusadeRecruitEvents
{
    EVENT_RECRUIT_1                          = 1,
    EVENT_RECRUIT_2                          = 2
};

class npc_crusade_recruit : public CreatureScript
{
public:
    npc_crusade_recruit() : CreatureScript("npc_crusade_recruit") { }

    struct npc_crusade_recruitAI : public ScriptedAI
    {
        npc_crusade_recruitAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _heading = me->GetOrientation();
        }

        void Reset() override
        {
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->SetEmoteState(EMOTE_STATE_COWER);
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RECRUIT_1:
                        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        me->SetEmoteState(EMOTE_ONESHOT_NONE);
                        Talk(SAY_RECRUIT);
                        _events.ScheduleEvent(EVENT_RECRUIT_2, 3000);
                        break;
                    case EVENT_RECRUIT_2:
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(_heading) * 10), me->GetPositionY() + (std::sin(_heading) * 10), me->GetPositionZ());
                        me->DespawnOrUnsummon(5000);
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        {
            _events.ScheduleEvent(EVENT_RECRUIT_1, 100);
            CloseGossipMenuFor(player);
            me->CastSpell(player, SPELL_QUEST_CREDIT, true);
            me->SetFacingToObject(player);
            return false;
        }

        private:
        EventMap _events;
        float    _heading; // Store creature heading
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_crusade_recruitAI(creature);
    }
};

/*######
## Quest 12916: Our Only Hope!
## go_scourge_enclosure
######*/

enum ScourgeEnclosure
{
    QUEST_OUR_ONLY_HOPE                      = 12916,
    NPC_GYMER_DUMMY                          = 29928, // From quest template
    SPELL_GYMER_LOCK_EXPLOSION               = 55529
};

class go_scourge_enclosure : public GameObjectScript
{
public:
    go_scourge_enclosure() : GameObjectScript("go_scourge_enclosure") { }

    struct go_scourge_enclosureAI : public GameObjectAI
    {
        go_scourge_enclosureAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* player) override
        {
            me->UseDoorOrButton();
            if (player->GetQuestStatus(QUEST_OUR_ONLY_HOPE) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* gymerDummy = me->FindNearestCreature(NPC_GYMER_DUMMY, 20.0f))
                {
                    player->KilledMonsterCredit(gymerDummy->GetEntry(), gymerDummy->GetGUID());
                    gymerDummy->CastSpell(gymerDummy, SPELL_GYMER_LOCK_EXPLOSION, true);
                    gymerDummy->DespawnOrUnsummon(4 * IN_MILLISECONDS);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_scourge_enclosureAI(go);
    }
};

/*######
## Quest: Troll Patrol: The Alchemist's Apprentice
######*/

enum Finklestein
{
    // Creature
    NPC_FINKLESTEIN                          = 28205,
    // Item
    ITEM_KNOTROOT                            = 38338,
    ITEM_PICKLED_EAGLE_EGG                   = 38341,
    ITEM_SPECKLED_GUANO                      = 38337,
    ITEM_WITHERED_BATWING                    = 38339,
    ITEM_SEASONED_SLIDER_CIDER               = 38381,
    ITEM_PULVERIZED_GARGOYLE_TEETH           = 38384,
    ITEM_MUDDY_MIRE_MAGGOT                   = 38386,
    ITEM_SPIKY_SPIDER_EGG                    = 38393,
    ITEM_HAIRY_HERRING_HEAD                  = 38396,
    ITEM_PUTRID_PIRATE_PERSPIRATION          = 38397,
    ITEM_ICECROWN_BOTTLED_WATER              = 38398,
    ITEM_WASPS_WINGS                         = 38369,
    ITEM_PRISMATIC_MOJO                      = 38343,
    ITEM_RAPTOR_CLAW                         = 38370,
    ITEM_AMBERSEED                           = 38340,
    ITEM_SHRUNKEN_DRAGONS_CLAW               = 38344,
    ITEM_CHILLED_SERPENT_MUCUS               = 38346,
    ITEM_CRYSTALLIZED_HOGSNOT                = 38336,
    ITEM_CRUSHED_BASILISK_CRYSTALS           = 38379,
    ITEM_TROLLBANE                           = 38342,
    ITEM_FROZEN_SPIDER_ICHOR                 = 38345,
    // Quest
    QUEST_THE_ALCHEMIST_APPRENTICE_DAILY     = 12541,
    // Spells
    SPELL_ALCHEMIST_APPRENTICE_INVISBUFF     = 51216,
    SPELL_RANDOM_INGREDIENT_EASY_AURA        = 51015,
    SPELL_RANDOM_INGREDIENT_MEDIUM_AURA      = 51154,
    SPELL_RANDOM_INGREDIENT_HARD_AURA        = 51157,
    SPELL_RANDOM_INGREDIENT_EASY             = 51134,
    SPELL_RANDOM_INGREDIENT_MEDIUM           = 51105,
    SPELL_RANDOM_INGREDIENT_HARD             = 51107,
    SPELL_NEXT_INGREDIENT                    = 51049,
    SPELL_POT_CHECK                          = 51046,
    SPELL_THROW_INGREDIENT                   = 51025,
    SPELL_KILL_CREDIT                        = 51111,
    // Spell Fetch Easy
    SPELL_FETCH_KNOTROOT                     = 51018,
    SPELL_FETCH_PICKLED_EAGLE_EGG            = 51055,
    SPELL_FETCH_SPECKLED_GUANO               = 51057,
    SPELL_FETCH_WITHERED_BATWING             = 51059,
    SPELL_FETCH_SEASONED_SLIDER_CIDER        = 51062,
    SPELL_FETCH_PULVERIZED_GARGOYLE_TEETH    = 51064,
    SPELL_FETCH_MUDDY_MIRE_MAGGOT            = 51067,
    SPELL_FETCH_SPIKY_SPIDER_EGG             = 51069,
    SPELL_FETCH_HAIRY_HERRING_HEAD           = 51072,
    SPELL_FETCH_PUTRID_PIRATE_PERSPIRATION   = 51077,
    SPELL_FETCH_ICECROWN_BOTTLED_WATER       = 51079,
    // Spell Have Easy
    SPELL_HAVE_KNOTROOT                      = 51047,
    SPELL_HAVE_PICKLED_EAGLE_EGG             = 51056,
    SPELL_HAVE_SPECKLED_GUANO                = 51058,
    SPELL_HAVE_WITHERED_BATWING              = 51060,
    SPELL_HAVE_SEASONED_SLIDER_CIDER         = 51063,
    SPELL_HAVE_PULVERIZED_GARGOYLE_TEETH     = 51065,
    SPELL_HAVE_MUDDY_MIRE_MAGGOT             = 51068,
    SPELL_HAVE_SPIKY_SPIDER_EGG              = 51070,
    SPELL_HAVE_HAIRY_HERRING_HEAD            = 51075,
    SPELL_HAVE_PUTRID_PIRATE_PERSPIRATION    = 51078,
    SPELL_HAVE_ICECROWN_BOTTLED_WATER        = 51080,
    // Spell Fetch Medium
    SPELL_FETCH_WASPS_WINGS                  = 51081,
    SPELL_FETCH_PRISMATIC_MOJO               = 51083,
    SPELL_FETCH_RAPTOR_CLAW                  = 51085,
    SPELL_FETCH_AMBERSEED                    = 51087,
    SPELL_FETCH_SHRUNKEN_DRAGONS_CLAW        = 51091,
    // Spell Have Medium
    SPELL_HAVE_WASPS_WINGS                   = 51082,
    SPELL_HAVE_PRISMATIC_MOJO                = 51084,
    SPELL_HAVE_RAPTOR_CLAW                   = 51086,
    SPELL_HAVE_AMBERSEED                     = 51088,
    SPELL_HAVE_SHRUNKEN_DRAGONS_CLAW         = 51092,
    // Spell Fetch Hard
    SPELL_FETCH_CHILLED_SERPENT_MUCUS        = 51093,
    SPELL_FETCH_CRYSTALLIZED_HOGSNOT         = 51095,
    SPELL_FETCH_CRUSHED_BASILISK_CRYSTALS    = 51097,
    SPELL_FETCH_TROLLBANE                    = 51100,
    SPELL_FETCH_FROZEN_SPIDER_ICHOR          = 51102,
    // Spell Have Hard
    SPELL_HAVE_CHILLED_SERPENT_MUCUS         = 51094,
    SPELL_HAVE_CRYSTALLIZED_HOGSNOT          = 51096,
    SPELL_HAVE_CRUSHED_BASILISK_CRYSTALS     = 51098,
    SPELL_HAVE_TROLLBANE                     = 51101,
    SPELL_HAVE_FROZEN_SPIDER_ICHOR           = 51104,
    // Text
    SAY_EASY_123                             = 0,
    SAY_MEDIUM_4                             = 1,
    SAY_MEDIUM_5                             = 2,
    SAY_HARD_6                               = 3,
    SAY_RUINED                               = 4,
    // Text Easy
    SAY_KNOTROOT                             = 5,
    SAY_PICKLED_EAGLE_EGG                    = 6,
    SAY_SPECKLED_GUANO                       = 7,
    SAY_WITHERED_BATWING                     = 8,
    SAY_SEASONED_SLIDER_CIDER                = 9,
    SAY_PULVERIZED_GARGOYLE_TEETH            = 10,
    SAY_MUDDY_MIRE_MAGGOT                    = 11,
    SAY_SPIKY_SPIDER_EGG                     = 12,
    SAY_HAIRY_HERRING_HEAD                   = 13,
    SAY_PUTRID_PIRATE_PERSPIRATION           = 14,
    SAY_ICECROWN_BOTTLED_WATER               = 15,
    // Text Medium
    SAY_WASPS_WINGS                          = 16,
    SAY_PRISMATIC_MOJO                       = 17,
    SAY_RAPTOR_CLAW                          = 18,
    SAY_AMBERSEED                            = 19,
    SAY_SHRUNKEN_DRAGONS_CLAW                = 20,
    // Text Hard
    SAY_CHILLED_SERPENT_MUCUS                = 21,
    SAY_CRYSTALLIZED_HOGSNOT                 = 22,
    SAY_CRUSHED_BASILISK_CRYSTALS            = 23,
    SAY_TROLLBANE                            = 24,
    SAY_FROZEN_SPIDER_ICHOR                  = 25
};

enum FinklesteinEvents
{
    EVENT_TURN_TO_POT                      = 1,
    EVENT_TURN_BACK                        = 2,
    EVENT_EASY_123                         = 3,
    EVENT_MEDIUM_4                         = 4,
    EVENT_MEDIUM_5                         = 5,
    EVENT_HARD_6                           = 6
};

class npc_alchemist_finklestein : public CreatureScript
{
public:
    npc_alchemist_finklestein() : CreatureScript("npc_alchemist_finklestein") { }

        struct npc_alchemist_finklesteinAI : public ScriptedAI
        {
            npc_alchemist_finklesteinAI(Creature* creature) : ScriptedAI(creature)
            {
                _getingredienttry = 0;
            }

            void Reset() override
            {
                _playerGUID.Clear();
                _getingredienttry = 0;
                _events.ScheduleEvent(EVENT_TURN_TO_POT, urand(15000, 26000));
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == 1 && data == 1)
                    switch (_getingredienttry)
                   {
                        case 2:
                        case 3:
                            _events.ScheduleEvent(EVENT_EASY_123, 100);
                            break;
                        case 4:
                            _events.ScheduleEvent(EVENT_MEDIUM_4, 100);
                            break;
                        case 5:
                            _events.ScheduleEvent(EVENT_MEDIUM_5, 100);
                            break;
                        case 6:
                            _events.ScheduleEvent(EVENT_HARD_6, 100);
                            break;
                        default:
                            break;
                    }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TURN_TO_POT:
                            me->SetFacingTo(6.230825f);
                            me->SetEmoteState(EMOTE_STATE_USE_STANDING_NO_SHEATHE);
                            _events.ScheduleEvent(EVENT_TURN_BACK, 11000);
                            break;
                        case EVENT_TURN_BACK:
                            me->SetFacingTo(4.886922f);
                            me->SetEmoteState(EMOTE_STATE_NONE);
                            _events.ScheduleEvent(EVENT_TURN_TO_POT, urand(25000, 41000));
                            break;
                        case EVENT_EASY_123:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            {
                                Talk(SAY_EASY_123, player);
                                DoCast(player, SPELL_RANDOM_INGREDIENT_EASY_AURA);
                                ++_getingredienttry;
                            }
                            break;
                        case EVENT_MEDIUM_4:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            {
                                Talk(SAY_MEDIUM_4, player);
                                DoCast(player, SPELL_RANDOM_INGREDIENT_MEDIUM_AURA);
                                ++_getingredienttry;
                            }
                            break;
                        case EVENT_MEDIUM_5:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            {
                                Talk(SAY_MEDIUM_5, player);
                                DoCast(player, SPELL_RANDOM_INGREDIENT_MEDIUM_AURA);
                                ++_getingredienttry;
                            }
                            break;
                        case EVENT_HARD_6:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            {
                                Talk(SAY_HARD_6, player);
                                DoCast(player, SPELL_RANDOM_INGREDIENT_HARD_AURA);
                                ++_getingredienttry;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                CloseGossipMenuFor(player);
                DoCast(player, SPELL_ALCHEMIST_APPRENTICE_INVISBUFF);
                _playerGUID = player->GetGUID();
                _getingredienttry = 1;
                _events.ScheduleEvent(EVENT_EASY_123, 100);
                return false;
            }

        private:
            EventMap _events;
            ObjectGuid _playerGUID;
            uint8    _getingredienttry;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_alchemist_finklesteinAI(creature);
        }
};

class go_finklesteins_cauldron : public GameObjectScript
{
public:
    go_finklesteins_cauldron() : GameObjectScript("go_finklesteins_cauldron") { }

    struct go_finklesteins_cauldronAI : public GameObjectAI
    {
        go_finklesteins_cauldronAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* player) override
        {
            player->CastSpell(player, SPELL_POT_CHECK);
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_finklesteins_cauldronAI(go);
    }
};

uint32 const FetchIngredients[21][4] =
{
    { SPELL_FETCH_KNOTROOT,                   SPELL_HAVE_KNOTROOT,                   ITEM_KNOTROOT,                   SAY_KNOTROOT                   },
    { SPELL_FETCH_PICKLED_EAGLE_EGG,          SPELL_HAVE_PICKLED_EAGLE_EGG,          ITEM_PICKLED_EAGLE_EGG,          SAY_PICKLED_EAGLE_EGG          },
    { SPELL_FETCH_SPECKLED_GUANO,             SPELL_HAVE_SPECKLED_GUANO,             ITEM_SPECKLED_GUANO,             SAY_SPECKLED_GUANO             },
    { SPELL_FETCH_WITHERED_BATWING,           SPELL_HAVE_WITHERED_BATWING,           ITEM_WITHERED_BATWING,           SAY_WITHERED_BATWING           },
    { SPELL_FETCH_SEASONED_SLIDER_CIDER,      SPELL_HAVE_SEASONED_SLIDER_CIDER,      ITEM_SEASONED_SLIDER_CIDER,      SAY_SEASONED_SLIDER_CIDER      },
    { SPELL_FETCH_PULVERIZED_GARGOYLE_TEETH,  SPELL_HAVE_PULVERIZED_GARGOYLE_TEETH,  ITEM_PULVERIZED_GARGOYLE_TEETH,  SAY_PULVERIZED_GARGOYLE_TEETH  },
    { SPELL_FETCH_MUDDY_MIRE_MAGGOT,          SPELL_HAVE_MUDDY_MIRE_MAGGOT,          ITEM_MUDDY_MIRE_MAGGOT,          SAY_MUDDY_MIRE_MAGGOT          },
    { SPELL_FETCH_SPIKY_SPIDER_EGG,           SPELL_HAVE_SPIKY_SPIDER_EGG,           ITEM_SPIKY_SPIDER_EGG,           SAY_SPIKY_SPIDER_EGG           },
    { SPELL_FETCH_HAIRY_HERRING_HEAD,         SPELL_HAVE_HAIRY_HERRING_HEAD,         ITEM_HAIRY_HERRING_HEAD,         SAY_HAIRY_HERRING_HEAD         },
    { SPELL_FETCH_PUTRID_PIRATE_PERSPIRATION, SPELL_HAVE_PUTRID_PIRATE_PERSPIRATION, ITEM_PUTRID_PIRATE_PERSPIRATION, SAY_PUTRID_PIRATE_PERSPIRATION },
    { SPELL_FETCH_ICECROWN_BOTTLED_WATER,     SPELL_HAVE_ICECROWN_BOTTLED_WATER,     ITEM_ICECROWN_BOTTLED_WATER,     SAY_ICECROWN_BOTTLED_WATER     },
    { SPELL_FETCH_WASPS_WINGS,                SPELL_HAVE_WASPS_WINGS,                ITEM_WASPS_WINGS,                SAY_WASPS_WINGS                },
    { SPELL_FETCH_PRISMATIC_MOJO,             SPELL_HAVE_PRISMATIC_MOJO,             ITEM_PRISMATIC_MOJO,             SAY_PRISMATIC_MOJO             },
    { SPELL_FETCH_RAPTOR_CLAW,                SPELL_HAVE_RAPTOR_CLAW,                ITEM_RAPTOR_CLAW,                SAY_RAPTOR_CLAW                },
    { SPELL_FETCH_AMBERSEED,                  SPELL_HAVE_AMBERSEED,                  ITEM_AMBERSEED,                  SAY_AMBERSEED                  },
    { SPELL_FETCH_SHRUNKEN_DRAGONS_CLAW,      SPELL_HAVE_SHRUNKEN_DRAGONS_CLAW,      ITEM_SHRUNKEN_DRAGONS_CLAW,      SAY_SHRUNKEN_DRAGONS_CLAW      },
    { SPELL_FETCH_CHILLED_SERPENT_MUCUS,      SPELL_HAVE_CHILLED_SERPENT_MUCUS,      ITEM_CHILLED_SERPENT_MUCUS,      SAY_CHILLED_SERPENT_MUCUS      },
    { SPELL_FETCH_CRYSTALLIZED_HOGSNOT,       SPELL_HAVE_CRYSTALLIZED_HOGSNOT,       ITEM_CRYSTALLIZED_HOGSNOT,       SAY_CRYSTALLIZED_HOGSNOT       },
    { SPELL_FETCH_CRUSHED_BASILISK_CRYSTALS,  SPELL_HAVE_CRUSHED_BASILISK_CRYSTALS,  ITEM_CRUSHED_BASILISK_CRYSTALS,  SAY_CRUSHED_BASILISK_CRYSTALS  },
    { SPELL_FETCH_TROLLBANE,                  SPELL_HAVE_TROLLBANE,                  ITEM_TROLLBANE,                  SAY_TROLLBANE                  },
    { SPELL_FETCH_FROZEN_SPIDER_ICHOR,        SPELL_HAVE_FROZEN_SPIDER_ICHOR,        ITEM_FROZEN_SPIDER_ICHOR,        SAY_FROZEN_SPIDER_ICHOR        }
};

/*#####
# spell_random_ingredient_aura
#####*/

class spell_random_ingredient_aura : public SpellScriptLoader
{
    public: spell_random_ingredient_aura() : SpellScriptLoader("spell_random_ingredient_aura") { }

        class spell_random_ingredient_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_random_ingredient_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_RANDOM_INGREDIENT_EASY,
                    SPELL_RANDOM_INGREDIENT_MEDIUM,
                    SPELL_RANDOM_INGREDIENT_HARD
                });
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_RANDOM_INGREDIENT_EASY_AURA:
                        GetTarget()->CastSpell(GetTarget(), SPELL_RANDOM_INGREDIENT_EASY);
                        break;
                    case SPELL_RANDOM_INGREDIENT_MEDIUM_AURA:
                        GetTarget()->CastSpell(GetTarget(), SPELL_RANDOM_INGREDIENT_MEDIUM);
                        break;
                    case SPELL_RANDOM_INGREDIENT_HARD_AURA:
                        GetTarget()->CastSpell(GetTarget(), SPELL_RANDOM_INGREDIENT_HARD);
                        break;
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_random_ingredient_aura_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_random_ingredient_aura_AuraScript();
        }
};

/*#####
# spell_random_ingredient
#####*/

class spell_random_ingredient : public SpellScriptLoader
{
    public: spell_random_ingredient() : SpellScriptLoader("spell_random_ingredient") { }

        class spell_random_ingredient_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_random_ingredient_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_FETCH_KNOTROOT,                   SPELL_HAVE_KNOTROOT,
                    SPELL_FETCH_PICKLED_EAGLE_EGG,          SPELL_HAVE_PICKLED_EAGLE_EGG,
                    SPELL_FETCH_SPECKLED_GUANO,             SPELL_HAVE_SPECKLED_GUANO,
                    SPELL_FETCH_WITHERED_BATWING,           SPELL_HAVE_WITHERED_BATWING,
                    SPELL_FETCH_SEASONED_SLIDER_CIDER,      SPELL_HAVE_SEASONED_SLIDER_CIDER,
                    SPELL_FETCH_PULVERIZED_GARGOYLE_TEETH,  SPELL_HAVE_PULVERIZED_GARGOYLE_TEETH,
                    SPELL_FETCH_MUDDY_MIRE_MAGGOT,          SPELL_HAVE_MUDDY_MIRE_MAGGOT,
                    SPELL_FETCH_SPIKY_SPIDER_EGG,           SPELL_HAVE_SPIKY_SPIDER_EGG,
                    SPELL_FETCH_HAIRY_HERRING_HEAD,         SPELL_HAVE_HAIRY_HERRING_HEAD,
                    SPELL_FETCH_PUTRID_PIRATE_PERSPIRATION, SPELL_HAVE_PUTRID_PIRATE_PERSPIRATION,
                    SPELL_FETCH_ICECROWN_BOTTLED_WATER,     SPELL_HAVE_ICECROWN_BOTTLED_WATER,
                    SPELL_FETCH_WASPS_WINGS,                SPELL_HAVE_WASPS_WINGS,
                    SPELL_FETCH_PRISMATIC_MOJO,             SPELL_HAVE_PRISMATIC_MOJO,
                    SPELL_FETCH_RAPTOR_CLAW,                SPELL_HAVE_RAPTOR_CLAW,
                    SPELL_FETCH_AMBERSEED,                  SPELL_HAVE_AMBERSEED,
                    SPELL_FETCH_SHRUNKEN_DRAGONS_CLAW,      SPELL_HAVE_SHRUNKEN_DRAGONS_CLAW,
                    SPELL_FETCH_CHILLED_SERPENT_MUCUS,      SPELL_HAVE_CHILLED_SERPENT_MUCUS,
                    SPELL_FETCH_CRYSTALLIZED_HOGSNOT,       SPELL_HAVE_CRYSTALLIZED_HOGSNOT,
                    SPELL_FETCH_CRUSHED_BASILISK_CRYSTALS,  SPELL_HAVE_CRUSHED_BASILISK_CRYSTALS,
                    SPELL_FETCH_TROLLBANE,                  SPELL_HAVE_TROLLBANE,
                    SPELL_FETCH_FROZEN_SPIDER_ICHOR,        SPELL_HAVE_FROZEN_SPIDER_ICHOR
                });
            }

            void HandleScriptEffect(SpellEffIndex /* effIndex */)
            {
                if (Player* player = GetHitPlayer())
                {
                    uint8 ingredient = 0;

                    switch (GetSpellInfo()->Id)
                    {
                        case SPELL_RANDOM_INGREDIENT_EASY:
                            ingredient = urand(0, 10);
                            break;
                        case SPELL_RANDOM_INGREDIENT_MEDIUM:
                            ingredient = urand(11, 15);
                            break;
                        case SPELL_RANDOM_INGREDIENT_HARD:
                            ingredient = urand(16, 20);
                            break;
                    }

                    if (Creature* finklestein = GetClosestCreatureWithEntry(player, NPC_FINKLESTEIN, 25.0f))
                    {
                        finklestein->CastSpell(player, FetchIngredients[ingredient][0], true, nullptr);
                        finklestein->AI()->Talk(FetchIngredients[ingredient][3], player);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_random_ingredient_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
    };

        SpellScript* GetSpellScript() const override
        {
            return new spell_random_ingredient_SpellScript();
        }
};

/*#####
# spell_pot_check
#####*/

class spell_pot_check : public SpellScriptLoader
{
    public: spell_pot_check() : SpellScriptLoader("spell_pot_check") { }

        class spell_pot_check_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pot_check_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_FETCH_KNOTROOT,                   SPELL_HAVE_KNOTROOT,
                    SPELL_FETCH_PICKLED_EAGLE_EGG,          SPELL_HAVE_PICKLED_EAGLE_EGG,
                    SPELL_FETCH_SPECKLED_GUANO,             SPELL_HAVE_SPECKLED_GUANO,
                    SPELL_FETCH_WITHERED_BATWING,           SPELL_HAVE_WITHERED_BATWING,
                    SPELL_FETCH_SEASONED_SLIDER_CIDER,      SPELL_HAVE_SEASONED_SLIDER_CIDER,
                    SPELL_FETCH_PULVERIZED_GARGOYLE_TEETH,  SPELL_HAVE_PULVERIZED_GARGOYLE_TEETH,
                    SPELL_FETCH_MUDDY_MIRE_MAGGOT,          SPELL_HAVE_MUDDY_MIRE_MAGGOT,
                    SPELL_FETCH_SPIKY_SPIDER_EGG,           SPELL_HAVE_SPIKY_SPIDER_EGG,
                    SPELL_FETCH_HAIRY_HERRING_HEAD,         SPELL_HAVE_HAIRY_HERRING_HEAD,
                    SPELL_FETCH_PUTRID_PIRATE_PERSPIRATION, SPELL_HAVE_PUTRID_PIRATE_PERSPIRATION,
                    SPELL_FETCH_ICECROWN_BOTTLED_WATER,     SPELL_HAVE_ICECROWN_BOTTLED_WATER,
                    SPELL_FETCH_WASPS_WINGS,                SPELL_HAVE_WASPS_WINGS,
                    SPELL_FETCH_PRISMATIC_MOJO,             SPELL_HAVE_PRISMATIC_MOJO,
                    SPELL_FETCH_RAPTOR_CLAW,                SPELL_HAVE_RAPTOR_CLAW,
                    SPELL_FETCH_AMBERSEED,                  SPELL_HAVE_AMBERSEED,
                    SPELL_FETCH_SHRUNKEN_DRAGONS_CLAW,      SPELL_HAVE_SHRUNKEN_DRAGONS_CLAW,
                    SPELL_FETCH_CHILLED_SERPENT_MUCUS,      SPELL_HAVE_CHILLED_SERPENT_MUCUS,
                    SPELL_FETCH_CRYSTALLIZED_HOGSNOT,       SPELL_HAVE_CRYSTALLIZED_HOGSNOT,
                    SPELL_FETCH_CRUSHED_BASILISK_CRYSTALS,  SPELL_HAVE_CRUSHED_BASILISK_CRYSTALS,
                    SPELL_FETCH_TROLLBANE,                  SPELL_HAVE_TROLLBANE,
                    SPELL_FETCH_FROZEN_SPIDER_ICHOR,        SPELL_HAVE_FROZEN_SPIDER_ICHOR
                });
            }

        void HandleScriptEffect(SpellEffIndex /* effIndex */)
        {
            if (Player* player = GetHitPlayer())
            {
                for (uint8 i = 0; i < 21; ++i)
                {
                    if (player->HasAura(FetchIngredients[i][0]))
                    {
                        player->CastSpell(player, SPELL_THROW_INGREDIENT);
                        player->RemoveAura(FetchIngredients[i][0]);
                        if (player->HasAura(FetchIngredients[i][1]))
                        {
                            player->RemoveAura(FetchIngredients[i][1]);
                            player->DestroyItemCount(FetchIngredients[i][2], 1, true);
                            if (i < 15)
                            {
                                if (Creature* finklestein = GetClosestCreatureWithEntry(player, NPC_FINKLESTEIN, 25.0f))
                                    finklestein->AI()->SetData(1, 1);
                                return;
                            }
                            else
                            {
                                if (player->GetQuestStatus(QUEST_THE_ALCHEMIST_APPRENTICE_DAILY) == QUEST_STATUS_INCOMPLETE)
                                {
                                    player->RemoveAura(SPELL_ALCHEMIST_APPRENTICE_INVISBUFF);
                                    player->CastSpell(player, SPELL_KILL_CREDIT);
                                }
                            }
                        }
                        else
                        {
                            RemoveItems(player);
                            player->RemoveAura(SPELL_ALCHEMIST_APPRENTICE_INVISBUFF);
                            if (Creature* finklestein = GetClosestCreatureWithEntry(player, NPC_FINKLESTEIN, 25.0f))
                                finklestein->AI()->Talk(SAY_RUINED, player);
                            return;
                        }
                    }
                 }
             }
         }

        void RemoveItems(Player* player)
        {
            for (uint8 i = 0; i < 21; ++i)
                if (player->HasItemCount(FetchIngredients[i][2], 1, true))
                    player->DestroyItemCount(FetchIngredients[i][2], 1, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pot_check_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pot_check_SpellScript();
        }
};

/*#####
# spell_fetch_ingredient_aura
#####*/

class spell_fetch_ingredient_aura : public SpellScriptLoader
{
    public: spell_fetch_ingredient_aura() : SpellScriptLoader("spell_fetch_ingredient_aura") { }

        class spell_fetch_ingredient_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_fetch_ingredient_aura_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (target->HasAura(SPELL_ALCHEMIST_APPRENTICE_INVISBUFF))
                        if (Creature* finklestein = GetClosestCreatureWithEntry(target, NPC_FINKLESTEIN, 100.0f))
                        {
                            target->RemoveAura(SPELL_ALCHEMIST_APPRENTICE_INVISBUFF);
                            finklestein->AI()->Talk(SAY_RUINED, target);
                        }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_fetch_ingredient_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_fetch_ingredient_aura_AuraScript();
        }
};

enum StormCloud
{
    STORM_COULD         = 29939,
    HEALING_WINDS       = 55549,
    STORM_VISUAL        = 55708,
    GYMERS_GRAB         = 55516,
    RIDE_VEHICLE        = 43671
};

class npc_storm_cloud : public CreatureScript
{
public:
    npc_storm_cloud() : CreatureScript("npc_storm_cloud") { }

    struct npc_storm_cloudAI : public ScriptedAI
    {
        npc_storm_cloudAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->CastSpell(me, STORM_VISUAL, true);
        }

        void JustAppeared() override
        {
            Reset();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id != GYMERS_GRAB)
                return;

            if (Vehicle* veh = caster->GetVehicleKit())
                if (veh->GetAvailableSeatCount() != 0)
            {
                me->CastSpell(caster, RIDE_VEHICLE, true);
                me->CastSpell(caster, HEALING_WINDS, true);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_storm_cloudAI(creature);
    }
};

void AddSC_zuldrak()
{
    new npc_drakuru_shackles();
    new npc_captured_rageclaw();
    new npc_released_offspring_harkoa();
    new npc_crusade_recruit();
    new go_scourge_enclosure();
    new npc_alchemist_finklestein();
    new go_finklesteins_cauldron();
    new spell_random_ingredient_aura();
    new spell_random_ingredient();
    new spell_pot_check();
    new spell_fetch_ingredient_aura();
    new npc_storm_cloud();
}
