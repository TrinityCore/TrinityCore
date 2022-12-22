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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*####
## npc_released_offspring_harkoa
####*/

struct npc_released_offspring_harkoa : public ScriptedAI
{
    npc_released_offspring_harkoa(Creature* creature) : ScriptedAI(creature) { }

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

struct npc_crusade_recruit : public ScriptedAI
{
    npc_crusade_recruit(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _heading = me->GetOrientation();
    }

    void Reset() override
    {
        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
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
                    _events.ScheduleEvent(EVENT_RECRUIT_2, 3s);
                    break;
                case EVENT_RECRUIT_2:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(_heading) * 10), me->GetPositionY() + (std::sin(_heading) * 10), me->GetPositionZ());
                    me->DespawnOrUnsummon(5s);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        _events.ScheduleEvent(EVENT_RECRUIT_1, 100ms);
        CloseGossipMenuFor(player);
        me->CastSpell(player, SPELL_QUEST_CREDIT, true);
        me->SetFacingToObject(player);
        return false;
    }

private:
    EventMap _events;
    float    _heading; // Store creature heading
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

struct npc_alchemist_finklestein : public ScriptedAI
{
    npc_alchemist_finklestein(Creature* creature) : ScriptedAI(creature)
    {
        _getingredienttry = 0;
    }

    void Reset() override
    {
        _playerGUID.Clear();
        _getingredienttry = 0;
        _events.ScheduleEvent(EVENT_TURN_TO_POT, 15s, 26s);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == 1 && data == 1)
            switch (_getingredienttry)
           {
                case 2:
                case 3:
                    _events.ScheduleEvent(EVENT_EASY_123, 100ms);
                    break;
                case 4:
                    _events.ScheduleEvent(EVENT_MEDIUM_4, 100ms);
                    break;
                case 5:
                    _events.ScheduleEvent(EVENT_MEDIUM_5, 100ms);
                    break;
                case 6:
                    _events.ScheduleEvent(EVENT_HARD_6, 100ms);
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
                    _events.ScheduleEvent(EVENT_TURN_BACK, 11s);
                    break;
                case EVENT_TURN_BACK:
                    me->SetFacingTo(4.886922f);
                    me->SetEmoteState(EMOTE_STATE_NONE);
                    _events.ScheduleEvent(EVENT_TURN_TO_POT, 25s, 41s);
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

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        CloseGossipMenuFor(player);
        DoCast(player, SPELL_ALCHEMIST_APPRENTICE_INVISBUFF);
        _playerGUID = player->GetGUID();
        _getingredienttry = 1;
        _events.ScheduleEvent(EVENT_EASY_123, 100ms);
        return false;
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;
    uint8    _getingredienttry;
};

struct go_finklesteins_cauldron : public GameObjectAI
{
    go_finklesteins_cauldron(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        player->CastSpell(player, SPELL_POT_CHECK);
        return true;
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

// 51015 - Random Ingredient Easy Aura
// 51154 - Random Ingredient Medium Aura
// 51157 - Random Ingredient Hard Aura
class spell_random_ingredient_aura : public AuraScript
{
    PrepareAuraScript(spell_random_ingredient_aura);

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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_random_ingredient_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 51105 - Random Ingredient Medium
// 51107 - Random Ingredient Hard
// 51134 - Random Ingredient Easy
class spell_random_ingredient : public SpellScript
{
    PrepareSpellScript(spell_random_ingredient);

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
            SPELL_FETCH_FROZEN_SPIDER_ICHOR,        SPELL_HAVE_FROZEN_SPIDER_ICHOR,
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
                finklestein->CastSpell(player, FetchIngredients[ingredient][0], true);
                finklestein->AI()->Talk(FetchIngredients[ingredient][3], player);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_random_ingredient::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*#####
# spell_pot_check
#####*/

// 51046 - Pot Check
class spell_pot_check : public SpellScript
{
    PrepareSpellScript(spell_pot_check);

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
            SPELL_FETCH_FROZEN_SPIDER_ICHOR,        SPELL_HAVE_FROZEN_SPIDER_ICHOR,
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
        OnEffectHitTarget += SpellEffectFn(spell_pot_check::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*#####
# spell_fetch_ingredient_aura
#####*/

class spell_fetch_ingredient_aura : public AuraScript
{
    PrepareAuraScript(spell_fetch_ingredient_aura);

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
        OnEffectRemove += AuraEffectRemoveFn(spell_fetch_ingredient_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
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

struct npc_storm_cloud : public ScriptedAI
{
    npc_storm_cloud(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->CastSpell(me, STORM_VISUAL, true);
    }

    void JustAppeared() override
    {
        Reset();
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Unit* unitCaster = caster->ToUnit();
        if (!unitCaster)
            return;

        if (spellInfo->Id != GYMERS_GRAB)
            return;

        if (Vehicle* veh = unitCaster->GetVehicleKit())
        {
            if (veh->GetAvailableSeatCount() != 0)
            {
                me->CastSpell(caster, RIDE_VEHICLE, true);
                me->CastSpell(caster, HEALING_WINDS, true);
            }
        }
    }
};

enum ScourgeDisguise
{
    SPELL_SCOURGE_DISGUISE             = 51966,
    SPELL_SCOURGE_DISGUISE_INSTABILITY = 51971,
    SPELL_SCOURGE_DISGUISE_EXPIRING    = 52010,
    SPELL_DROP_DISGUISE                = 54089,
    TEXT_DISGUISE_WARNING              = 28891
};

// 51966 - Scourge Disguise
class spell_zuldrak_scourge_disguise : public AuraScript
{
    PrepareAuraScript(spell_zuldrak_scourge_disguise);

    void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_SCOURGE_DISGUISE_INSTABILITY, true);
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAura(SPELL_SCOURGE_DISGUISE_INSTABILITY);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_zuldrak_scourge_disguise::RemoveEffect, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_zuldrak_scourge_disguise::ApplyEffect, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 51971 - Scourge Disguise Instability
class spell_zuldrak_scourge_disguise_instability : public AuraScript
{
    PrepareAuraScript(spell_zuldrak_scourge_disguise_instability);

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = irand(30, 240) * IN_MILLISECONDS;
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SCOURGE_DISGUISE_EXPIRING, true);
    }

    void HandleUpdatePeriodic(AuraEffect* aurEff)
    {
        aurEff->CalculatePeriodic(GetCaster());
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_zuldrak_scourge_disguise_instability::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_zuldrak_scourge_disguise_instability::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_zuldrak_scourge_disguise_instability::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 52010 - Scourge Disguise Expiring
class spell_zuldrak_scourge_disguise_expiring : public AuraScript
{
    PrepareAuraScript(spell_zuldrak_scourge_disguise_expiring);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetTarget()->ToPlayer())
            if (player->HasAura(SPELL_SCOURGE_DISGUISE))
                player->Unit::Whisper(TEXT_DISGUISE_WARNING, player, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SCOURGE_DISGUISE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_zuldrak_scourge_disguise_expiring::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_zuldrak_scourge_disguise_expiring::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 52335 - Drop Scourge Disguise
// 54089 - Drop Disguise
class spell_zuldrak_drop_disguise : public SpellScript
{
    PrepareSpellScript(spell_zuldrak_drop_disguise);

    void HandleHit()
    {
        if (Unit* target = GetHitUnit())
            if (target->HasAura(SPELL_SCOURGE_DISGUISE))
                target->CastSpell(target, SPELL_SCOURGE_DISGUISE_EXPIRING, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_zuldrak_drop_disguise::HandleHit);
    }
};

/*######
## Quest 12606: Cocooned!
######*/

enum Cocooned
{
    SPELL_SUMMON_SCOURGED_CAPTIVE      = 51597,
    SPELL_SUMMON_CAPTIVE_FOOTMAN       = 51599
};

// 51596 - Cocooned: Player Not On Quest
class spell_zuldrak_cocooned_not_on_quest : public SpellScript
{
    PrepareSpellScript(spell_zuldrak_cocooned_not_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SCOURGED_CAPTIVE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_SUMMON_SCOURGED_CAPTIVE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zuldrak_cocooned_not_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 51598 - Cocooned: Player On Quest
class spell_zuldrak_cocooned_on_quest : public SpellScript
{
    PrepareSpellScript(spell_zuldrak_cocooned_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SCOURGED_CAPTIVE, SPELL_SUMMON_CAPTIVE_FOOTMAN });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), roll_chance_i(66) ? SPELL_SUMMON_SCOURGED_CAPTIVE : SPELL_SUMMON_CAPTIVE_FOOTMAN);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zuldrak_cocooned_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*######
## Quest 12676: Sabotage
######*/

enum Sabotage
{
    SPELL_EXPLODE_SCOURGEWAGON_ROLLER    = 52325,
    SPELL_EXPLODE_SCOURGEWAGON_FRAME     = 52329,
    SPELL_EXPLODE_SCOURGEWAGON_GRILL     = 52330,
    SPELL_EXPLODE_SCOURGEWAGON_WHEEL     = 52332
};

// 52324 - Scourgewagon Explosion
class spell_zuldrak_scourgewagon_explosion : public SpellScript
{
    PrepareSpellScript(spell_zuldrak_scourgewagon_explosion);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_EXPLODE_SCOURGEWAGON_ROLLER,
            SPELL_EXPLODE_SCOURGEWAGON_FRAME,
            SPELL_EXPLODE_SCOURGEWAGON_GRILL,
            SPELL_EXPLODE_SCOURGEWAGON_WHEEL
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_ROLLER);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_FRAME);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_GRILL);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_WHEEL);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_WHEEL);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_WHEEL);
        caster->CastSpell(caster, SPELL_EXPLODE_SCOURGEWAGON_WHEEL);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_zuldrak_scourgewagon_explosion::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 12861: Trolls Is Gone Crazy!
######*/

// 54990 - Chains of the Scourge
class spell_zuldrak_chains_of_the_scourge : public SpellScript
{
    PrepareSpellScript(spell_zuldrak_chains_of_the_scourge);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zuldrak_chains_of_the_scourge::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_zuldrak()
{
    RegisterCreatureAI(npc_released_offspring_harkoa);
    RegisterCreatureAI(npc_crusade_recruit);
    RegisterCreatureAI(npc_alchemist_finklestein);
    RegisterGameObjectAI(go_finklesteins_cauldron);
    RegisterSpellScript(spell_random_ingredient_aura);
    RegisterSpellScript(spell_random_ingredient);
    RegisterSpellScript(spell_pot_check);
    RegisterSpellScript(spell_fetch_ingredient_aura);
    RegisterCreatureAI(npc_storm_cloud);
    RegisterSpellScript(spell_zuldrak_scourge_disguise);
    RegisterSpellScript(spell_zuldrak_scourge_disguise_instability);
    RegisterSpellScript(spell_zuldrak_scourge_disguise_expiring);
    RegisterSpellScript(spell_zuldrak_drop_disguise);
    RegisterSpellScript(spell_zuldrak_cocooned_not_on_quest);
    RegisterSpellScript(spell_zuldrak_cocooned_on_quest);
    RegisterSpellScript(spell_zuldrak_scourgewagon_explosion);
    RegisterSpellScript(spell_zuldrak_chains_of_the_scourge);
}
