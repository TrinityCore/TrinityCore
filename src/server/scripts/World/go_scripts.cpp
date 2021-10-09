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
go_ethereum_prison
go_ethereum_stasis
go_southfury_moonstone
go_resonite_cask
go_tablet_of_the_seven
go_tele_to_dalaran_crystal
go_tele_to_violet_stand
go_soulwell
go_amberpine_outhouse
go_veil_skith_cage
go_bells
EndContentData */

#include "ScriptMgr.h"
#include "DBCStructure.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

/*######
## go_gilded_brazier (Paladin First Trail quest (9678))
######*/

enum GildedBrazier
{
    NPC_STILLBLADE        = 17716,
    QUEST_THE_FIRST_TRIAL = 9678
};

class go_gilded_brazier : public GameObjectScript
{
public:
    go_gilded_brazier() : GameObjectScript("go_gilded_brazier") { }

    struct go_gilded_brazierAI : public GameObjectAI
    {
        go_gilded_brazierAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (me->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            {
                if (player->GetQuestStatus(QUEST_THE_FIRST_TRIAL) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* Stillblade = player->SummonCreature(NPC_STILLBLADE, 8106.11f, -7542.06f, 151.775f, 3.02598f, TEMPSUMMON_DEAD_DESPAWN, 1min))
                        Stillblade->AI()->AttackStart(player);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_gilded_brazierAI(go);
    }
};

/*######
## go_tablet_of_the_seven
######*/

class go_tablet_of_the_seven : public GameObjectScript
{
public:
    go_tablet_of_the_seven() : GameObjectScript("go_tablet_of_the_seven") { }

    struct go_tablet_of_the_sevenAI : public GameObjectAI
    {
        go_tablet_of_the_sevenAI(GameObject* go) : GameObjectAI(go) { }

        /// @todo use gossip option ("Transcript the Tablet") instead, if Trinity adds support.
        bool OnGossipHello(Player* player) override
        {
            if (me->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
                return true;

            if (player->GetQuestStatus(4296) == QUEST_STATUS_INCOMPLETE)
                player->CastSpell(player, 15065, false);

            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_tablet_of_the_sevenAI(go);
    }
};

/*######
## go_ethereum_prison
######*/

enum EthereumPrison
{
    SPELL_REP_LC        = 39456,
    SPELL_REP_SHAT      = 39457,
    SPELL_REP_CE        = 39460,
    SPELL_REP_CON       = 39474,
    SPELL_REP_KT        = 39475,
    SPELL_REP_SPOR      = 39476
};

const uint32 NpcPrisonEntry[] =
{
    22810, 22811, 22812, 22813, 22814, 22815,               //good guys
    20783, 20784, 20785, 20786, 20788, 20789, 20790         //bad guys
};

class go_ethereum_prison : public GameObjectScript
{
public:
    go_ethereum_prison() : GameObjectScript("go_ethereum_prison") { }

    struct go_ethereum_prisonAI : public GameObjectAI
    {
        go_ethereum_prisonAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            me->UseDoorOrButton();
            int Random = rand32() % (sizeof(NpcPrisonEntry) / sizeof(uint32));

            if (Creature* creature = player->SummonCreature(NpcPrisonEntry[Random], me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetAbsoluteAngle(player),
                TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s))
            {
                if (!creature->IsHostileTo(player))
                {
                    if (FactionTemplateEntry const* pFaction = creature->GetFactionTemplateEntry())
                    {
                        uint32 Spell = 0;

                        switch (pFaction->Faction)
                        {
                            case 1011: Spell = SPELL_REP_LC; break;
                            case 935: Spell = SPELL_REP_SHAT; break;
                            case 942: Spell = SPELL_REP_CE; break;
                            case 933: Spell = SPELL_REP_CON; break;
                            case 989: Spell = SPELL_REP_KT; break;
                            case 970: Spell = SPELL_REP_SPOR; break;
                        }

                        if (Spell)
                            creature->CastSpell(player, Spell, false);
                        else
                            TC_LOG_ERROR("scripts", "go_ethereum_prison summoned Creature (entry %u) but faction (%u) are not expected by script.", creature->GetEntry(), creature->GetFaction());
                    }
                }
            }

            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_ethereum_prisonAI(go);
    }
};

/*######
## go_ethereum_stasis
######*/

const uint32 NpcStasisEntry[] =
{
    22825, 20888, 22827, 22826, 22828
};

class go_ethereum_stasis : public GameObjectScript
{
public:
    go_ethereum_stasis() : GameObjectScript("go_ethereum_stasis") { }

    struct go_ethereum_stasisAI : public GameObjectAI
    {
        go_ethereum_stasisAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            me->UseDoorOrButton();
            int Random = rand32() % (sizeof(NpcStasisEntry) / sizeof(uint32));

            player->SummonCreature(NpcStasisEntry[Random], me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetAbsoluteAngle(player),
                TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);

            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_ethereum_stasisAI(go);
    }
};

/*######
## go_resonite_cask
######*/

enum ResoniteCask
{
    NPC_GOGGEROC    = 11920
};

class go_resonite_cask : public GameObjectScript
{
public:
    go_resonite_cask() : GameObjectScript("go_resonite_cask") { }

    struct go_resonite_caskAI : public GameObjectAI
    {
        go_resonite_caskAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* /*player*/) override
        {
            if (me->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
                me->SummonCreature(NPC_GOGGEROC, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5min);

            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_resonite_caskAI(go);
    }
};

/*######
## go_southfury_moonstone
######*/

enum Southfury
{
    NPC_RIZZLE                  = 23002,
    SPELL_BLACKJACK             = 39865, //stuns player
    SPELL_SUMMON_RIZZLE         = 39866
};

class go_southfury_moonstone : public GameObjectScript
{
public:
    go_southfury_moonstone() : GameObjectScript("go_southfury_moonstone") { }

    struct go_southfury_moonstoneAI : public GameObjectAI
    {
        go_southfury_moonstoneAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            //implicitTarget=48 not implemented as of writing this code, and manual summon may be just ok for our purpose
            //player->CastSpell(player, SPELL_SUMMON_RIZZLE, false);

            if (Creature* creature = player->SummonCreature(NPC_RIZZLE, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN))
                creature->CastSpell(player, SPELL_BLACKJACK, false);

            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_southfury_moonstoneAI(go);
    }
};

/*######
## go_tele_to_dalaran_crystal
######*/

enum DalaranCrystal
{
    QUEST_LEARN_LEAVE_RETURN    = 12790,
    QUEST_TELE_CRYSTAL_FLAG     = 12845
};

#define GO_TELE_TO_DALARAN_CRYSTAL_FAILED   "This teleport crystal cannot be used until the teleport crystal in Dalaran has been used at least once."

class go_tele_to_dalaran_crystal : public GameObjectScript
{
public:
    go_tele_to_dalaran_crystal() : GameObjectScript("go_tele_to_dalaran_crystal") { }

    struct go_tele_to_dalaran_crystalAI : public GameObjectAI
    {
        go_tele_to_dalaran_crystalAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (player->GetQuestRewardStatus(QUEST_TELE_CRYSTAL_FLAG))
                return false;

            player->GetSession()->SendNotification(GO_TELE_TO_DALARAN_CRYSTAL_FAILED);
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_tele_to_dalaran_crystalAI(go);
    }
};

/*######
## go_tele_to_violet_stand
######*/

class go_tele_to_violet_stand : public GameObjectScript
{
public:
    go_tele_to_violet_stand() : GameObjectScript("go_tele_to_violet_stand") { }

    struct go_tele_to_violet_standAI : public GameObjectAI
    {
        go_tele_to_violet_standAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (player->GetQuestRewardStatus(QUEST_LEARN_LEAVE_RETURN) || player->GetQuestStatus(QUEST_LEARN_LEAVE_RETURN) == QUEST_STATUS_INCOMPLETE)
                return false;

            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_tele_to_violet_standAI(go);
    }
};

/*######
## go_blood_filled_orb
######*/

enum BloodFilledOrb
{
    NPC_ZELEMAR     = 17830

};

class go_blood_filled_orb : public GameObjectScript
{
public:
    go_blood_filled_orb() : GameObjectScript("go_blood_filled_orb") { }

    struct go_blood_filled_orbAI : public GameObjectAI
    {
        go_blood_filled_orbAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (me->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
                player->SummonCreature(NPC_ZELEMAR, -369.746f, 166.759f, -21.50f, 5.235f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);

            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_blood_filled_orbAI(go);
    }
};

/*######
## go_soulwell
######*/

enum SoulWellData
{
    GO_SOUL_WELL_R1                     = 181621,
    GO_SOUL_WELL_R2                     = 193169,

    SPELL_IMPROVED_HEALTH_STONE_R1      = 18692,
    SPELL_IMPROVED_HEALTH_STONE_R2      = 18693,

    SPELL_CREATE_MASTER_HEALTH_STONE_R0 = 34130,
    SPELL_CREATE_MASTER_HEALTH_STONE_R1 = 34149,
    SPELL_CREATE_MASTER_HEALTH_STONE_R2 = 34150,

    SPELL_CREATE_FEL_HEALTH_STONE_R0    = 58890,
    SPELL_CREATE_FEL_HEALTH_STONE_R1    = 58896,
    SPELL_CREATE_FEL_HEALTH_STONE_R2    = 58898,
};

class go_soulwell : public GameObjectScript
{
    public:
        go_soulwell() : GameObjectScript("go_soulwell") { }

        struct go_soulwellAI : public GameObjectAI
        {
            go_soulwellAI(GameObject* go) : GameObjectAI(go)
            {
                _stoneSpell = 0;
                _stoneId = 0;
                switch (go->GetEntry())
                {
                    case GO_SOUL_WELL_R1:
                        _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R0;
                        if (Unit* owner = go->GetOwner())
                        {
                            if (owner->HasAura(SPELL_IMPROVED_HEALTH_STONE_R1))
                                _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R1;
                            else if (owner->HasAura(SPELL_CREATE_MASTER_HEALTH_STONE_R2))
                                _stoneSpell = SPELL_CREATE_MASTER_HEALTH_STONE_R2;
                        }
                        break;
                    case GO_SOUL_WELL_R2:
                        _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R0;
                        if (Unit* owner = go->GetOwner())
                        {
                            if (owner->HasAura(SPELL_IMPROVED_HEALTH_STONE_R1))
                                _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R1;
                            else if (owner->HasAura(SPELL_CREATE_MASTER_HEALTH_STONE_R2))
                                _stoneSpell = SPELL_CREATE_FEL_HEALTH_STONE_R2;
                        }
                        break;
                }
                if (_stoneSpell == 0) // Should never happen
                    return;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(_stoneSpell);
                if (!spellInfo)
                    return;

                _stoneId = spellInfo->GetEffect(EFFECT_0).ItemType;
            }

            bool OnGossipHello(Player* player) override
            {
                Unit* owner = me->GetOwner();
                if (_stoneSpell == 0 || _stoneId == 0)
                    return true;

                if (!owner || owner->GetTypeId() != TYPEID_PLAYER || !player->IsInSameRaidWith(owner->ToPlayer()))
                    return true;

                // Don't try to add a stone if we already have one.
                if (player->HasItemCount(_stoneId))
                {
                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(_stoneSpell))
                        Spell::SendCastResult(player, spell, 0, SPELL_FAILED_TOO_MANY_OF_ITEM);
                    return true;
                }

                owner->CastSpell(player, _stoneSpell, true);
                // Item has to actually be created to remove a charge on the well.
                if (player->HasItemCount(_stoneId))
                    me->AddUse();

                return false;
            }

        private:
            uint32 _stoneSpell;
            uint32 _stoneId;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_soulwellAI(go);
        }
};

/*######
## go_amberpine_outhouse
######*/

#define GOSSIP_USE_OUTHOUSE "Use the outhouse."
#define GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND "Quest item Anderhol's Slider Cider not found."

enum AmberpineOuthouse
{
    ITEM_ANDERHOLS_SLIDER_CIDER     = 37247,
    NPC_OUTHOUSE_BUNNY              = 27326,
    QUEST_DOING_YOUR_DUTY           = 12227,
    SPELL_INDISPOSED                = 53017,
    SPELL_INDISPOSED_III            = 48341,
    SPELL_CREATE_AMBERSEEDS         = 48330,
    GOSSIP_OUTHOUSE_INUSE           = 12775,
    GOSSIP_OUTHOUSE_VACANT          = 12779
};

class go_amberpine_outhouse : public GameObjectScript
{
public:
    go_amberpine_outhouse() : GameObjectScript("go_amberpine_outhouse") { }

    struct go_amberpine_outhouseAI : public GameObjectAI
    {
        go_amberpine_outhouseAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            QuestStatus status = player->GetQuestStatus(QUEST_DOING_YOUR_DUTY);
            if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_USE_OUTHOUSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, GOSSIP_OUTHOUSE_VACANT, me->GetGUID());
            }
            else
                SendGossipMenuFor(player, GOSSIP_OUTHOUSE_INUSE, me->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                Creature* target = GetClosestCreatureWithEntry(player, NPC_OUTHOUSE_BUNNY, 3.0f);
                if (target)
                {
                    target->AI()->SetData(1, player->GetNativeGender());
                    me->CastSpell(target, SPELL_INDISPOSED_III);
                }
                me->CastSpell(player, SPELL_INDISPOSED);
                if (player->HasItemCount(ITEM_ANDERHOLS_SLIDER_CIDER))
                    me->CastSpell(player, SPELL_CREATE_AMBERSEEDS);
                return true;
            }
            else
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification(GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND);
                return false;
            }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_amberpine_outhouseAI(go);
    }
};

class go_massive_seaforium_charge : public GameObjectScript
{
    public:
        go_massive_seaforium_charge() : GameObjectScript("go_massive_seaforium_charge") { }

        struct go_massive_seaforium_chargeAI : public GameObjectAI
        {
            go_massive_seaforium_chargeAI(GameObject* go) : GameObjectAI(go) { }

            bool OnGossipHello(Player* /*player*/) override
            {
                me->SetLootState(GO_JUST_DEACTIVATED);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_massive_seaforium_chargeAI(go);
        }
};

/*######
#### go_veil_skith_cage
#####*/

enum MissingFriends
{
   QUEST_MISSING_FRIENDS    = 10852,
   NPC_CAPTIVE_CHILD        = 22314,
   SAY_FREE_0               = 0,
};

class go_veil_skith_cage : public GameObjectScript
{
    public:
       go_veil_skith_cage() : GameObjectScript("go_veil_skith_cage") { }

       struct go_veil_skith_cageAI : public GameObjectAI
       {
           go_veil_skith_cageAI(GameObject* go) : GameObjectAI(go) { }

           bool OnGossipHello(Player* player) override
           {
               me->UseDoorOrButton();
               if (player->GetQuestStatus(QUEST_MISSING_FRIENDS) == QUEST_STATUS_INCOMPLETE)
               {
                   std::vector<Creature*> childrenList;
                   GetCreatureListWithEntryInGrid(childrenList, me, NPC_CAPTIVE_CHILD, INTERACTION_DISTANCE);
                   for (Creature* creature : childrenList)
                   {
                       player->KilledMonsterCredit(NPC_CAPTIVE_CHILD, creature->GetGUID());
                       creature->DespawnOrUnsummon(5s);
                       creature->GetMotionMaster()->MovePoint(1, me->GetPositionX() + 5, me->GetPositionY(), me->GetPositionZ());
                       creature->AI()->Talk(SAY_FREE_0);
                       creature->GetMotionMaster()->Clear();
                   }
               }
               return false;
           }
       };

       GameObjectAI* GetAI(GameObject* go) const override
       {
           return new go_veil_skith_cageAI(go);
       }
};

/*######
## go_frostblade_shrine
######*/

enum TheCleansing
{
   QUEST_THE_CLEANSING_HORDE      = 11317,
   QUEST_THE_CLEANSING_ALLIANCE   = 11322,
   SPELL_CLEANSING_SOUL           = 43351,
   SPELL_RECENT_MEDITATION        = 61720,
};

class go_frostblade_shrine : public GameObjectScript
{
public:
    go_frostblade_shrine() : GameObjectScript("go_frostblade_shrine") { }

    struct go_frostblade_shrineAI : public GameObjectAI
    {
        go_frostblade_shrineAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            me->UseDoorOrButton(10);
            if (!player->HasAura(SPELL_RECENT_MEDITATION))
            {
                if (player->GetQuestStatus(QUEST_THE_CLEANSING_HORDE) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_THE_CLEANSING_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->CastSpell(player, SPELL_CLEANSING_SOUL);
                    player->SetStandState(UNIT_STAND_STATE_SIT);
                }
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_frostblade_shrineAI(go);
    }
};

/*######
## go_midsummer_bonfire
######*/

enum MidsummerBonfire
{
    STAMP_OUT_BONFIRE_QUEST_COMPLETE    = 45458,
};

class go_midsummer_bonfire : public GameObjectScript
{
public:
    go_midsummer_bonfire() : GameObjectScript("go_midsummer_bonfire") { }

    struct go_midsummer_bonfireAI : public GameObjectAI
    {
        go_midsummer_bonfireAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        {
            player->CastSpell(player, STAMP_OUT_BONFIRE_QUEST_COMPLETE, true);
            CloseGossipMenuFor(player);
            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_midsummer_bonfireAI(go);
    }
};

enum MidsummerPoleRibbon
{
    SPELL_TEST_RIBBON_POLE_1 = 29705,
    SPELL_TEST_RIBBON_POLE_2 = 29726,
    SPELL_TEST_RIBBON_POLE_3 = 29727,
    NPC_POLE_RIBBON_BUNNY    = 17066,
    ACTION_COSMETIC_FIRES    = 0
};

uint32 const RibbonPoleSpells[3] =
{
    SPELL_TEST_RIBBON_POLE_1,
    SPELL_TEST_RIBBON_POLE_2,
    SPELL_TEST_RIBBON_POLE_3
};

class go_midsummer_ribbon_pole : public GameObjectScript
{
public:
    go_midsummer_ribbon_pole() : GameObjectScript("go_midsummer_ribbon_pole") { }

    struct go_midsummer_ribbon_poleAI : public GameObjectAI
    {
        go_midsummer_ribbon_poleAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (Creature* creature = me->FindNearestCreature(NPC_POLE_RIBBON_BUNNY, 10.0f))
            {
                creature->GetAI()->DoAction(ACTION_COSMETIC_FIRES);
                player->CastSpell(player, RibbonPoleSpells[urand(0, 2)], true);
            }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_midsummer_ribbon_poleAI(go);
    }
};

/*####
## go_brewfest_music
####*/

enum BrewfestMusic
{
    EVENT_BREWFESTDWARF01 = 11810, // 1.35 min
    EVENT_BREWFESTDWARF02 = 11812, // 1.55 min
    EVENT_BREWFESTDWARF03 = 11813, // 0.23 min
    EVENT_BREWFESTGOBLIN01 = 11811, // 1.08 min
    EVENT_BREWFESTGOBLIN02 = 11814, // 1.33 min
    EVENT_BREWFESTGOBLIN03 = 11815 // 0.28 min
};

constexpr Seconds EVENT_BREWFESTDWARF01_TIME = 95s;
constexpr Seconds EVENT_BREWFESTDWARF02_TIME = 155s;
constexpr Seconds EVENT_BREWFESTDWARF03_TIME = 23s;
constexpr Seconds EVENT_BREWFESTGOBLIN01_TIME = 68s;
constexpr Seconds EVENT_BREWFESTGOBLIN02_TIME = 93s;
constexpr Seconds EVENT_BREWFESTGOBLIN03_TIME = 28s;

enum BrewfestMusicAreas
{
    SILVERMOON = 3430, // Horde
    UNDERCITY = 1497,
    ORGRIMMAR_1 = 1296,
    ORGRIMMAR_2 = 14,
    THUNDERBLUFF = 1638,
    IRONFORGE_1 = 809, // Alliance
    IRONFORGE_2 = 1,
    STORMWIND = 12,
    EXODAR = 3557,
    DARNASSUS = 1657,
    SHATTRATH = 3703 // General
};

enum BrewfestMusicEvents
{
    EVENT_BM_SELECT_MUSIC = 1,
    EVENT_BM_START_MUSIC = 2
};

class go_brewfest_music : public GameObjectScript
{
public:
    go_brewfest_music() : GameObjectScript("go_brewfest_music") { }

    struct go_brewfest_musicAI : public GameObjectAI
    {
        uint32 rnd = 0;
        Milliseconds musicTime = 1s;

        go_brewfest_musicAI(GameObject* go) : GameObjectAI(go)
        {
            _events.ScheduleEvent(EVENT_BM_SELECT_MUSIC, 1s);
            _events.ScheduleEvent(EVENT_BM_START_MUSIC, 2s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BM_SELECT_MUSIC:
                    if (!IsHolidayActive(HOLIDAY_BREWFEST)) // Check if Brewfest is active
                        break;
                    rnd = urand(0, 2); // Select random music sample
                    _events.ScheduleEvent(EVENT_BM_SELECT_MUSIC, musicTime); // Select new song music after play time is over
                    break;
                case EVENT_BM_START_MUSIC:
                    if (!IsHolidayActive(HOLIDAY_BREWFEST)) // Check if Brewfest is active
                        break;

                    switch (me->GetAreaId())
                    {
                        // Horde
                        case SILVERMOON:
                        case UNDERCITY:
                        case ORGRIMMAR_1:
                        case ORGRIMMAR_2:
                        case THUNDERBLUFF:
                            if (rnd == 0)
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTGOBLIN01);
                                musicTime = EVENT_BREWFESTGOBLIN01_TIME;
                            }
                            else if (rnd == 1)
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTGOBLIN02);
                                musicTime = EVENT_BREWFESTGOBLIN02_TIME;
                            }
                            else
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTGOBLIN03);
                                musicTime = EVENT_BREWFESTGOBLIN03_TIME;
                            }
                            break;
                        // Alliance
                        case IRONFORGE_1:
                        case IRONFORGE_2:
                        case STORMWIND:
                        case EXODAR:
                        case DARNASSUS:
                            if (rnd == 0)
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTDWARF01);
                                musicTime = EVENT_BREWFESTDWARF01_TIME;
                            }
                            else if (rnd == 1)
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTDWARF02);
                                musicTime = EVENT_BREWFESTDWARF02_TIME;
                            }
                            else
                            {
                                me->PlayDirectMusic(EVENT_BREWFESTDWARF03);
                                musicTime = EVENT_BREWFESTDWARF03_TIME;
                            }
                            break;
                        // Neurtal
                        case SHATTRATH:
                            std::vector<Player*> playersNearby;
                            me->GetPlayerListInGrid(playersNearby, me->GetVisibilityRange());
                            for (Player* player : playersNearby)
                            {
                                if (player->GetTeamId() == TEAM_HORDE)
                                {
                                    if (rnd == 0)
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTGOBLIN01);
                                        musicTime = EVENT_BREWFESTGOBLIN01_TIME;
                                    }
                                    else if (rnd == 1)
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTGOBLIN02);
                                        musicTime = EVENT_BREWFESTGOBLIN02_TIME;
                                    }
                                    else
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTGOBLIN03);
                                        musicTime = EVENT_BREWFESTGOBLIN03_TIME;
                                    }
                                }
                                else
                                {
                                    if (rnd == 0)
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTDWARF01);
                                        musicTime = EVENT_BREWFESTDWARF01_TIME;
                                    }
                                    else if (rnd == 1)
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTDWARF02);
                                        musicTime = EVENT_BREWFESTDWARF02_TIME;
                                    }
                                    else
                                    {
                                        me->PlayDirectMusic(EVENT_BREWFESTDWARF03);
                                        musicTime = EVENT_BREWFESTDWARF03_TIME;
                                    }
                                }
                            }
                            break;
                    }

                    _events.ScheduleEvent(EVENT_BM_START_MUSIC, 5s); // Every 5 second's SMSG_PLAY_MUSIC packet (PlayDirectMusic) is pushed to the client
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_brewfest_musicAI(go);
    }
};

/*####
## go_midsummer_music
####*/

enum MidsummerMusic
{
    EVENTMIDSUMMERFIREFESTIVAL_A = 12319, // 1.08 min
    EVENTMIDSUMMERFIREFESTIVAL_H = 12325, // 1.12 min
};

enum MidsummerMusicEvents
{
    EVENT_MM_START_MUSIC = 1
};

class go_midsummer_music : public GameObjectScript
{
public:
    go_midsummer_music() : GameObjectScript("go_midsummer_music") { }

    struct go_midsummer_musicAI : public GameObjectAI
    {
        go_midsummer_musicAI(GameObject* go) : GameObjectAI(go)
        {
            _events.ScheduleEvent(EVENT_MM_START_MUSIC, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MM_START_MUSIC:
                    {
                        if (!IsHolidayActive(HOLIDAY_FIRE_FESTIVAL))
                            break;

                        std::vector<Player*> playersNearby;
                        me->GetPlayerListInGrid(playersNearby, me->GetVisibilityRange());
                        for (Player* player : playersNearby)
                        {
                            if (player->GetTeamId() == TEAM_HORDE)
                                me->PlayDirectMusic(EVENTMIDSUMMERFIREFESTIVAL_H, player);
                            else
                                me->PlayDirectMusic(EVENTMIDSUMMERFIREFESTIVAL_A, player);
                        }
                        _events.ScheduleEvent(EVENT_MM_START_MUSIC, 5s); // Every 5 second's SMSG_PLAY_MUSIC packet (PlayDirectMusic) is pushed to the client (sniffed value)
                        break;
                    }
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_midsummer_musicAI(go);
    }
};

/*####
## go_darkmoon_faire_music
####*/

enum DarkmoonFaireMusic
{
    MUSIC_DARKMOON_FAIRE_MUSIC = 8440
};

enum DarkmoonFaireMusicEvents
{
    EVENT_DFM_START_MUSIC = 1
};

class go_darkmoon_faire_music : public GameObjectScript
{
public:
    go_darkmoon_faire_music() : GameObjectScript("go_darkmoon_faire_music") { }

    struct go_darkmoon_faire_musicAI : public GameObjectAI
    {
        go_darkmoon_faire_musicAI(GameObject* go) : GameObjectAI(go)
        {
            _events.ScheduleEvent(EVENT_DFM_START_MUSIC, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DFM_START_MUSIC:
                        if (!IsHolidayActive(HOLIDAY_DARKMOON_FAIRE_ELWYNN) && !IsHolidayActive(HOLIDAY_DARKMOON_FAIRE_THUNDER) && !IsHolidayActive(HOLIDAY_DARKMOON_FAIRE_SHATTRATH))
                            break;
                        me->PlayDirectMusic(MUSIC_DARKMOON_FAIRE_MUSIC);
                        _events.ScheduleEvent(EVENT_DFM_START_MUSIC, 5s);  // Every 5 second's SMSG_PLAY_MUSIC packet (PlayDirectMusic) is pushed to the client (sniffed value)
                        break;
                    default:
                        break;
                }
            }
        }
    private:
        EventMap _events;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_darkmoon_faire_musicAI(go);
    }
};

/*####
## go_pirate_day_music
####*/

enum PirateDayMusic
{
    MUSIC_PIRATE_DAY_MUSIC = 12845
};

enum PirateDayMusicEvents
{
    EVENT_PDM_START_MUSIC = 1
};

class go_pirate_day_music : public GameObjectScript
{
public:
    go_pirate_day_music() : GameObjectScript("go_pirate_day_music") { }

    struct go_pirate_day_musicAI : public GameObjectAI
    {
        go_pirate_day_musicAI(GameObject* go) : GameObjectAI(go)
        {
            _events.ScheduleEvent(EVENT_PDM_START_MUSIC, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PDM_START_MUSIC:
                    if (!IsHolidayActive(HOLIDAY_PIRATES_DAY))
                        break;
                    me->PlayDirectMusic(MUSIC_PIRATE_DAY_MUSIC);
                    _events.ScheduleEvent(EVENT_PDM_START_MUSIC, 5s);  // Every 5 second's SMSG_PLAY_MUSIC packet (PlayDirectMusic) is pushed to the client (sniffed value)
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_pirate_day_musicAI(go);
    }
};

/*####
## go_bells
####*/

enum BellHourlySoundFX
{
    BELLTOLLHORDE      = 6595, // Undercity
    BELLTOLLTRIBAL     = 6675, // Orgrimma/Thunderbluff
    BELLTOLLALLIANCE   = 6594, // Stormwind
    BELLTOLLNIGHTELF   = 6674, // Darnassus
    BELLTOLLDWARFGNOME = 7234, // Ironforge
    BELLTOLLKHARAZHAN  = 9154  // Kharazhan
};

enum BellHourlySoundZones
{
    TIRISFAL_ZONE            = 85,
    UNDERCITY_ZONE           = 1497,
    DUN_MOROGH_ZONE          = 1,
    IRONFORGE_ZONE           = 1537,
    TELDRASSIL_ZONE          = 141,
    DARNASSUS_ZONE           = 1657,
    ASHENVALE_ZONE           = 331,
    HILLSBRAD_FOOTHILLS_ZONE = 267,
    DUSKWOOD_ZONE            = 10
};

enum BellHourlyObjects
{
    GO_HORDE_BELL          = 175885,
    GO_ALLIANCE_BELL       = 176573,
    GO_KHARAZHAN_BELL      = 182064
};

enum BellHourlyMisc
{
    GAME_EVENT_HOURLY_BELLS = 73,
    EVENT_RING_BELL        = 1
};

class go_bells : public GameObjectScript
{
public:
    go_bells() : GameObjectScript("go_bells") { }

    struct go_bellsAI : public GameObjectAI
    {
        go_bellsAI(GameObject* go) : GameObjectAI(go), _soundId(0) { }

        void InitializeAI() override
        {
            uint32 zoneId = me->GetZoneId();

            switch (me->GetEntry())
            {
                case GO_HORDE_BELL:
                {
                    switch (zoneId)
                    {
                        case TIRISFAL_ZONE:
                        case UNDERCITY_ZONE:
                        case HILLSBRAD_FOOTHILLS_ZONE:
                        case DUSKWOOD_ZONE:
                            _soundId = BELLTOLLHORDE;  // undead bell sound
                            break;
                        default:
                            _soundId = BELLTOLLTRIBAL; // orc drum sound
                            break;
                    }
                    break;
                }
                case GO_ALLIANCE_BELL:
                {
                    switch (zoneId)
                    {
                        case IRONFORGE_ZONE:
                        case DUN_MOROGH_ZONE:
                            _soundId = BELLTOLLDWARFGNOME; // horn sound
                            break;
                        case DARNASSUS_ZONE:
                        case TELDRASSIL_ZONE:
                        case ASHENVALE_ZONE:
                            _soundId = BELLTOLLNIGHTELF;   // nightelf bell sound
                            break;
                        default:
                            _soundId = BELLTOLLALLIANCE;   // human bell sound
                    }
                    break;
                }
                case GO_KHARAZHAN_BELL:
                {
                    _soundId = BELLTOLLKHARAZHAN;
                    break;
                }
            }
        }

        void OnGameEvent(bool start, uint16 eventId) override
        {
            if (eventId == GAME_EVENT_HOURLY_BELLS && start)
            {
                time_t time = GameTime::GetGameTime();
                tm localTm;
                localtime_r(&time, &localTm);
                uint8 _rings = (localTm.tm_hour) % 12;
                if (_rings == 0) // 00:00 and 12:00
                {
                    _rings = 12;
                }

                for (auto i = 0; i < _rings; ++i)
                    _events.ScheduleEvent(EVENT_RING_BELL, Seconds(i * 4 + 1));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RING_BELL:
                        me->PlayDirectSound(_soundId);
                        break;
                    default:
                        break;
                }
            }
        }
    private:
        EventMap _events;
        uint32 _soundId;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_bellsAI(go);
    }
};

void AddSC_go_scripts()
{
    new go_gilded_brazier();
    new go_southfury_moonstone();
    new go_tablet_of_the_seven();
    new go_ethereum_prison();
    new go_ethereum_stasis();
    new go_resonite_cask();
    new go_tele_to_dalaran_crystal();
    new go_tele_to_violet_stand();
    new go_blood_filled_orb();
    new go_soulwell();
    new go_amberpine_outhouse();
    new go_massive_seaforium_charge();
    new go_veil_skith_cage();
    new go_frostblade_shrine();
    new go_midsummer_bonfire();
    new go_midsummer_ribbon_pole();
    new go_brewfest_music();
    new go_midsummer_music();
    new go_darkmoon_faire_music();
    new go_pirate_day_music();
    new go_bells();
}
