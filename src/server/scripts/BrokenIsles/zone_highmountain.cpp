/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "SceneHelper.h"

enum
{
    QUEST_THE_LONE_MOUNTAIN     = 39733,
    QUEST_KEEPERS_OF_THE_HAMMER = 38907,
    QUEST_THE_RIVERMANE_TRIBE   = 38911,
    QUEST_ORMGUL_THE_PESTILENT  = 39491,
    QUEST_THE_FLOW_OF_THE_RIVER = 39496,
    QUEST_TRAPPED_TAUREN        = 39316,

    QUEST_SECRETS_OF_HIGHMOUNTAIN = 38916,
    QUEST_THE_PATH_OF_HULN        = 39575,

    QUEST_THE_STORY_OF_HULN       = 40167,
    QUEST_TO_SEE_THE_PAST         = 40520,
    QUEST_HULNS_WAR_THE_ARRIVAL   = 39983,

    QUEST_GRASP_OF_THE_UNDERKING  = 39025,
    QUEST_BITESTONE_ENCLAVE       = 39043,
    QUEST_DARGRUL_AND_THE_HAMMER  = 39027,
    QUEST_GET_TO_HIGH_GROUND      = 38909,

    QUEST_THE_BLOODTOTEM_TRIBE    = 38912,
    QUEST_AN_AUDIENCE_WITH_TOROK  = 39374,
    QUEST_CAVE_OF_THE_BLOOD_TRIAL = 39455,
    QUEST_RITE_OF_BLOOD           = 39860,
    QUEST_ROCK_TROLL_IN_A_HARD_PLACE = 39381,
    QUEST_PET_ROCKS               = 39391,
    QUEST_STONEDARK_CRYSTAL       = 39425,
    QUEST_THEY_WILL_PAY_WITH_BLOOD = 39588,
    QUEST_BLOOD_DEBT              = 39426,
    QUEST_BREAK_WEAPON_RACKS      = 40243,
    QUEST_STEP_INTO_THE_DARK      = 40229,
    QUEST_UNEXPECTED_ALLIES       = 39456,

    QUEST_IN_DEFIANCE_OF_DEATHWING = 40219,
    QUEST_AN_ANCIENT_SECRET        = 39577,
    QUEST_EVACUATE_SNOWMANE        = 42088,
    QUEST_HIGHMOUNTAIN_STANDS      = 42512,
    QUEST_JUSTICE_RAINS_FROM_ABOVE = 40594,
    QUEST_THE_UNDERKING            = 39780,


    QUEST_THE_SKYHORN_TRIBE       = 38913,
    QUEST_NURSING_THE_WOUNDS      = 39318,
    QUEST_ROCS_VS_EAGLES          = 38910,
    QUEST_THE_THREE               = 39321,
    QUEST_THE_WITCHQUEEN          = 39322,
    QUEST_THE_SKIES_OF_HIGHMOUNTAIN = 39387,


    QUEST_CURSE_OF_THE_NECRODARK  = 41815,
    QUEST_THE_TAKEN               = 41839,
    QUEST_ICE_AND_SHADOW          = 41840,
    QUEST_WHISPERS_OF_THE_DARKNESS = 41882,
    QUEST_THE_FINAL_WARD         = 41841,
    QUEST_THE_DARKNESS           = 48403,
};

struct npc_94973 : public ScriptedAI
{
    npc_94973(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(40244))
        {
            if (gossipListId == 0)
            {
                player->CastSpell(player, 205336, true);
                CloseGossipMenuFor(player);
            }
        }
    }
};

struct npc_archmage_khadgar_91172 : public ScriptedAI
{
    npc_archmage_khadgar_91172(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_THE_LONE_MOUNTAIN))
                {
                    IsLock = true;
                    me->Say(99458);
                    SetUnlock(60000);
                }
            }
        }
    }
};

struct npc_warbrave_oro_97666 : public ScriptedAI
{
    npc_warbrave_oro_97666(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_KEEPERS_OF_THE_HAMMER)
        {
            me->Say(99459);
            player->KilledMonsterCredit(96813);
            me->GetScheduler().Schedule(Milliseconds(4000), [player](TaskContext context)
            {
                if (Creature* kadej = player->FindNearestCreature(91172, 50.f))
                    kadej->Say(99460, player);
            });
        }
    }
};

struct npc_warbrave_oro_106244 : public ScriptedAI
{
    npc_warbrave_oro_106244(Creature* creature) : ScriptedAI(creature) {}

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            me->Say(99623);
            break;
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_KEEPERS_OF_THE_HAMMER))
                {
                    IsLock = true;
                    me->Say(99596);
                    player->KilledMonsterCredit(106244);
                    me->GetMotionMaster()->MovePoint(1, Position(4121.3989f, 4333.802f, 768.346f, 2.539f), true);
                    SetUnlock(60000);
                }
            }
        }
    }
};

struct npc_mayla_highmountain_93826 : public ScriptedAI
{
    npc_mayla_highmountain_93826(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_KEEPERS_OF_THE_HAMMER))
                {
                    IsLock = true;
                    me->Say(109202);
                    SetUnlock(60000);
                }
                if (!IsLock && player->HasQuest(QUEST_GET_TO_HIGH_GROUND))
                {
                    IsLock = true;

                    SetUnlock(60000);
                }
            }
        }
    }
    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_HIGHMOUNTAIN_STANDS)
        {
            player->SummonCreature(107704, Position(3868.5148f, 3886.949f, 901.2326f, 5.85f), TEMPSUMMON_MANUAL_DESPAWN);
        }
        if (quest->GetQuestId() == QUEST_THE_SKYHORN_TRIBE)
            player->CastSpell(player, 189692, true);
    }
};

struct npc_jale_rivermane_93833 : public ScriptedAI
{
    npc_jale_rivermane_93833(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_FLOW_OF_THE_RIVER)
            me->Say(102688);
    }
};

struct npc_mayla_highmountain_96049 : public ScriptedAI
{
    npc_mayla_highmountain_96049(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_SECRETS_OF_HIGHMOUNTAIN))
                {
                    IsLock = true;
                    me->Say(98213);
                    me->GetScheduler().Schedule(4s, [this](TaskContext /*context*/)
                    {
                        if (Creature* ebonhorn = me->FindNearestCreature(94571, 50.f))
                            ebonhorn->Say(101099);
                    });
                    SetUnlock(60000);
                }
            }
        }
    }
};

struct npc_spiritwalker_ebonhorn_94571 : public ScriptedAI
{
    npc_spiritwalker_ebonhorn_94571(Creature* creature) : ScriptedAI(creature) {}

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(2, Position(3825.51f, 4509.829f, 778.008f, 3.42f), true);
            });
            break;
        case 2:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(3, Position(3814.859f, 4510.02f, 776.197f, 3.1296f), false);
            });
            break;
        case 3:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(4, Position(3806.437f, 4510.21f, 777.956f, 2.2264f), false);
            });
            break;
        case 4:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(5, Position(3788.352f, 4533.211f, 776.817f, 2.246f), true);
            });
            break;
        case 5:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(6, Position(3770.7f, 4555.124f, 776.156f, 2.4f), true);
            });
            break;
        case 6:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(7, Position(3734.126f, 4580.137f, 779.989f, 2.89f), true);
            });
            break;
        case 7:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(8, Position(3700.6f, 4589.221f, 782.8f, 2.87f), true);
            });
            break;
        case 8:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(9, Position(3680.19f, 4592.656f, 786.136f, 2.929f), true);
            });
            break;
        case 9:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(10, Position(3640.457f, 4627.499f, 789.233f, 2.6426f), true);
            });
            break;
        case 10:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(11, Position(3618.997f, 4620.916f, 794.279f, 3.7343f), true);
            });
            break;
        case 11:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(12, Position(3582.9335f, 4596.624f, 803.419f, 3.7343f), true);
            });
            break;
        case 12:
            me->Say(98236);
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(13, Position(3553.9f, 4554.5f, 813.86f, 4.182f), true);
            });
            break;
        case 13:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(14, Position(3555.96f, 4534.238f, 812.9f, 4.7985f), true);
            });
            break;
        case 14:
            me->Say(98534);
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(15, Position(3557.82f, 4529.5375f, 813.7837f, 5.0813f), true);
            });
            break;
        case 15:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(16, Position(3564.324f, 4512.516f, 811.796f, 5.454f), true);
            });
            break;
        case 16:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(17, Position(3582.763f, 4495.098f, 803.8f, 5.5f), true);
            });
            break;
        case 17:
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(18, Position(3604.161f, 4473.469f, 787.92f, 5.5f), true);
            });
            break;
        case 18:
            me->Say(98289);
            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                player->KilledMonsterCredit(96164);

            if (Creature* target = me->FindNearestCreature(96049, 50.0f, true))
                target->Yell(100452);
            if (Creature* maya = ObjectAccessor::GetCreature(*me, mayaGUID))
                maya->GetMotionMaster()->Clear();
            break;
        default:
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_PATH_OF_HULN)
        {
            playerGUID = player->GetGUID();
            if (Creature* maya = me->FindNearestCreature(96049, 50.0f, true))
            {
                mayaGUID = maya->GetGUID();
                maya->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, maya->GetFollowAngle());
            }
            me->GetMotionMaster()->MovePoint(1, Position(3844.644f, 4515.443f, 776.7343f, 3.267f), true);
        }
    }

    ObjectGuid mayaGUID;
    ObjectGuid playerGUID;
};

//todo
struct npc_ebyssian_108199 : public ScriptedAI
{
    npc_ebyssian_108199(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(39578))
                {
                    IsLock = true;
                    player->KilledMonsterCredit(108199);
                    player->KilledMonsterCredit(96270);
                    SetUnlock(60000);
                }
            }
        }
    }
};

struct npc_spiritwalker_ebonhorn_98825 : public ScriptedAI
{
    npc_spiritwalker_ebonhorn_98825(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_SECRETS_OF_HIGHMOUNTAIN)
            Talk(0);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);

        if (player->HasQuest(QUEST_THE_STORY_OF_HULN))
            player->GetSceneMgr().PlayScene(1141);

        if (player->HasQuest(QUEST_HULNS_WAR_THE_ARRIVAL))
            player->CastSpell(player, 193751, true);
    }
};

//99153,108069
struct npc_spiritwalker_ebonhorn_99153 : public ScriptedAI
{
    npc_spiritwalker_ebonhorn_99153(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_IN_DEFIANCE_OF_DEATHWING)//SMSG_PHASE_SHIFT_CHANGE [1] Id: 5363 
        {
            player->CastSpell(player, 191564, true);
            //ID - 190732 War Harness
        }
    }
};
//250916,250978,250979
class go_quest_40219_highmountain_brazier : public GameObjectScript
{
public:
    go_quest_40219_highmountain_brazier() : GameObjectScript("go_quest_40219_highmountain_brazier") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetEntry() == 250916)
        {
            //Visión de escala
            Creature* Igrul = player->SummonCreature(96387, Position(3547.78f, 4373.75f, 663.031f, 0.977324f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Huln = player->SummonCreature(96318, Position(3550.959f, 4379.73f, 663.475f, 4.30743f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Warbrave01 = player->SummonCreature(98788, Position(3551.889f, 4382.259f, 663.932f, 3.94186f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Warbrave02 = player->SummonCreature(98788, Position(3555.33f, 4380.189f, 663.773f, 3.5473f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Igrul->Say(100465);
            player->GetScheduler().Schedule(Milliseconds(10000), [Huln](TaskContext context)
            {
                Huln->Say(100467);
            });
            player->GetScheduler().Schedule(Milliseconds(20000), [Igrul](TaskContext context)
            {
                Igrul->Say(100468);
            });
            Igrul->DespawnOrUnsummon(25000);
            Huln->DespawnOrUnsummon(25000);
            Warbrave01->DespawnOrUnsummon(25000);
            Warbrave02->DespawnOrUnsummon(25000);
            player->GetScheduler().Schedule(Milliseconds(24000), [player](TaskContext context)
            {
                player->RemoveAurasDueToSpell(194669);
            });
        }
        if (go->GetEntry() == 250978)
        {
            //ID - 195111 Visión del martillo
            Creature* Igrul = player->SummonCreature(96387, Position(3649.409f, 4265.33f, 665.0189f, 1.53473f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Huln = player->SummonCreature(96318, Position(3644.1f, 4270.6f, 665.405f, 0.4333f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            player->CastSpell(player, 195111, true);
            player->GetScheduler().Schedule(Milliseconds(20000), [player](TaskContext context)
            {
                player->RemoveAurasDueToSpell(194669);
            });
            Igrul->DespawnOrUnsummon(25000);
            Huln->DespawnOrUnsummon(25000);
        }
        if (go->GetEntry() == 250979)
        {
            //ID - 195117 Visión de esperanza
            Creature* Igrul = player->SummonCreature(96387, Position(3508.34f, 4295.92f, 682.3648f, 5.6015f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Huln = player->SummonCreature(96318, Position(3514.82f, 4297.66f, 681.512f, 2.66739f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Warbrave01 = player->SummonCreature(98788, Position(3507.429f, 4288.99f, 681.276f, 1.34693f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Warbrave02 = player->SummonCreature(98788, Position(3519.07f, 4295.7f, 680.42f, 2.621f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Igrul->Say(100831);
            player->GetScheduler().Schedule(Milliseconds(10000), [Huln](TaskContext context)
            {
                Huln->Say(100832);
            });
            player->GetScheduler().Schedule(Milliseconds(20000), [player](TaskContext context)
            {
                player->RemoveAurasDueToSpell(194669);
            });
            Igrul->DespawnOrUnsummon(25000);
            Huln->DespawnOrUnsummon(25000);
            Warbrave01->DespawnOrUnsummon(25000);
            Warbrave02->DespawnOrUnsummon(25000);
        }

        return false;
    }
};
//250994
class go_quest_39578_highmountain_brazier : public GameObjectScript
{
public:
    go_quest_39578_highmountain_brazier() : GameObjectScript("go_quest_39578_highmountain_brazier") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetEntry() == 250994)
        {
            player->RemoveAurasDueToSpell(191564);
            Creature* Ebonhorn = player->SummonCreature(99190, Position(3419.129f, 4297.44f, 704.041f, 4.68f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Igrul = player->SummonCreature(96387, Position(3427.0f, 4254.979f, 704.059f, 1.551f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Huln = player->SummonCreature(96318, Position(3425.44f, 4296.27f, 704.379f, 4.53f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Mayla = player->SummonCreature(96523, Position(3430.49f, 4295.62f, 703.898f, 4.34947f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);

            Creature* Deathwing = player->SummonCreature(97056, Position(3427.34f, 4272.229f, 704.005f, 1.57f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Deathwing->Say(98359);
            //ID - 191254 Exilio de Alamuerte
            player->GetScheduler().Schedule(Milliseconds(5000), [Deathwing, player](TaskContext context)
            {
                Deathwing->CastSpell(Deathwing, 191254, true);
                player->KilledMonsterCredit(97056);
            });
            player->GetScheduler().Schedule(Milliseconds(10000), [Deathwing](TaskContext context)
            {
                Deathwing->DespawnOrUnsummon();
            });

            Creature* Drogbar01 = player->SummonCreature(99138, Position(3410.1f, 4272.1098f, 704.4719f, 0.0069f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Creature* Drogbar02 = player->SummonCreature(99138, Position(3412.22f, 4263.99f, 705.056f, 0.49896f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            Huln->AddAura(193622);

            Drogbar02->DespawnOrUnsummon(25000);
            Drogbar01->DespawnOrUnsummon(25000);
            Igrul->DespawnOrUnsummon(25000);
            Huln->DespawnOrUnsummon(65000);
            Mayla->DespawnOrUnsummon(25000);
            Ebonhorn->DespawnOrUnsummon(65000);
        }
        return false;
    }
};

struct npc_spiritwalker_ebonhorn_99190 : public ScriptedAI
{
    npc_spiritwalker_ebonhorn_99190(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_AN_ANCIENT_SECRET)
        {
            me->GetMotionMaster()->MovePoint(1, Position(3389.22f, 4239.46f, 705.899f, 4.842f), true);
            player->CastSpell(player, 195026, true);
            me->GetScheduler().Schedule(15s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(2, Position(3405.01f, 4185.569f, 722.5579f, 1.3583f), true);
            });
        }
    }
};
//251031
class go_quest_39577_highmountain_brazier : public GameObjectScript
{
public:
    go_quest_39577_highmountain_brazier() : GameObjectScript("go_quest_39577_highmountain_brazier") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetEntry() == 251031)
        {
            //108199,96270
            if (Creature* Igrul = player->SummonCreature(96387, Position(3547.78f, 4373.75f, 663.031f, 0.977324f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
            {
                Igrul->AI()->Talk(0);
                go->GetScheduler().Schedule(10s, [Igrul, player](TaskContext /*context*/)
                {
                    Igrul->AI()->Talk(1);
                    Igrul->DespawnOrUnsummon(5000);
                });
            }
            player->GetScheduler().Schedule(12s, [player](TaskContext /*context*/)
            {
                std::list<Creature*> _list;
                player->GetCreatureListWithEntryInGrid(_list, 96242, 50.0f);
                if (!_list.empty())
                    for (Creature* mob : _list)
                        mob->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
            });
            if (Creature * Huln = player->FindNearestCreature(96318, 50.0f, true))
            {
                Huln->GetScheduler().Schedule(5s, [Huln](TaskContext /*context*/)
                {
                    Huln->Say(113354);
                });
            }

            //ID - 214960 Matar：Abby Xian Flashback： //ID - 195135 Diálogo de Abby Sian
            player->GetScheduler().Schedule(15s, [player](TaskContext /*context*/)
            {
                player->RemoveAurasDueToSpell(191564);
                player->CastSpell(player, 214960, true);
                player->KilledMonsterCredit(96270);
                player->CastSpell(player, 195135, true);
            });
            //99190 cast 81908
        }
        return false;
    }
};
//106191,106153,106115
struct npc_quest_evacuate_snowmane_42088 : public ScriptedAI
{
    npc_quest_evacuate_snowmane_42088(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);

        if (player->HasQuest(QUEST_EVACUATE_SNOWMANE))
        {
            Talk(0, player);
            player->KilledMonsterCredit(me->GetEntry());
        }
    }
};

struct npc_dargrul_107704 : public ScriptedAI
{
    npc_dargrul_107704(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(QUEST_HIGHMOUNTAIN_STANDS))
                {
                    me->GetMotionMaster()->MoveJump(Position(3846.4f, 3898.7f, 904.31f, 2.67f), 10.0f, 10.0f);
                    player->KilledMonsterCredit(me->GetEntry());
                    me->DespawnOrUnsummon(5000);
                }
            }
        }
    }
};

struct npc_war_eagle_100712 : public ScriptedAI
{
    npc_war_eagle_100712(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_JUSTICE_RAINS_FROM_ABOVE) == QUEST_STATUS_INCOMPLETE)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                player->ForceCompleteQuest(QUEST_JUSTICE_RAINS_FROM_ABOVE);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(QUEST_JUSTICE_RAINS_FROM_ABOVE))
                    me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }
};

struct npc_mayla_highmountain_97352 : public ScriptedAI
{
    npc_mayla_highmountain_97352(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(player, 15.0f, false))
                if (!IsLock && player->HasQuest(QUEST_THE_UNDERKING))
                {
                    IsLock = true;
                    Talk(0);
                    player->KilledMonsterCredit(me->GetEntry());
                }

    }
};

struct npc_the_hammer_of_khazgoroth_107587 : public ScriptedAI
{
    npc_the_hammer_of_khazgoroth_107587(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(player, 25.0f, false) && player->HasQuest(42454))
                player->KilledMonsterCredit(me->GetEntry());
    }
};
//QUEST_NURSING_THE_WOUNDS
struct npc_windmaster_julan_95403 : public ScriptedAI
{
    npc_windmaster_julan_95403(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->RemoveAurasDueToSpell(130966);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_NURSING_THE_WOUNDS))
        {
            player->KilledMonsterCredit(me->GetEntry());
            //ID - 189182 Tótem de viento ID - 189168 Viento opresivo
            player->RemoveAurasDueToSpell(189182);
            player->CastSpell(player, 189182, true);
        }
    }
};
// 189168 Viento opresivo target 95261 aura ID - 188911 Skyhorn Fire
class spell_suppressing_wind_189168 : public SpellScriptLoader
{
public:
    spell_suppressing_wind_189168() : SpellScriptLoader("spell_suppressing_wind_189168") { }

    class spell_suppressing_wind_189168_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_suppressing_wind_189168_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            if (!GetHitUnit() || !GetCaster() || GetHitUnit()->IsPlayer())
                return;

            if (GetHitUnit()->GetEntry() == 95261 && GetHitUnit()->HasAura(188911))
            {
                GetCaster()->ToPlayer()->KilledMonsterCredit(95261);
                GetHitUnit()->RemoveAurasDueToSpell(188911);
                GetHitUnit()->GetScheduler().Schedule(Milliseconds(15000), [](TaskContext context)
                {
                    GetContextCreature()->AddAura(188911);
                });
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_suppressing_wind_189168_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_suppressing_wind_189168_SpellScript();
    }
};


struct npc_captive_great_eagle_94991 : public ScriptedAI
{
    npc_captive_great_eagle_94991(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_ROCS_VS_EAGLES) == QUEST_STATUS_INCOMPLETE && me->HasAura(188434))
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                player->CastSpell(me, 188432, true);
                me->RemoveAurasDueToSpell(188434);
                player->KilledMonsterCredit(me->GetEntry());
                me->SetCanFly(true);
                me->SetFlying(true);
                me->SetDisableGravity(true);
                Position pos = me->ToCreature()->GetPositionWithDistInFront(20.0f);
                pos.m_positionZ = pos.GetPositionZ() + 15.0f;
                me->GetMotionMaster()->MovePoint(1, pos, true);
                me->DespawnOrUnsummon(5000);
            }
        }
    }
};

//95051,94255,94286
struct npc_warbrave_oro_95051 : public ScriptedAI
{
    npc_warbrave_oro_95051(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_GRASP_OF_THE_UNDERKING) == QUEST_STATUS_INCOMPLETE)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                player->KilledMonsterCredit(me->GetEntry());
                Talk(0);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_GRASP_OF_THE_UNDERKING))
                {
                    IsLock = true;
                    me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                }
            }
        }
    }
};

struct npc_spiritwalker_ebonhorn_93805 : public ScriptedAI
{
    npc_spiritwalker_ebonhorn_93805(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_GET_TO_HIGH_GROUND)
            player->CastSpell(player, 187298, true);
    }
};


struct npc_highmountain_elder_94547 : public ScriptedAI
{
    npc_highmountain_elder_94547(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 25.0f, false))
            {
                player->CastSpell(player, 187324, true);

                if (player->HasQuest(QUEST_GET_TO_HIGH_GROUND))
                    player->CastSpell(player, 193251, true);
            }
        }
    }
};

//244564 Altar QUEST_CAVE_OF_THE_BLOOD_TRIAL
class go_quest_39455_altar : public GameObjectScript
{
public:
    go_quest_39455_altar() : GameObjectScript("go_quest_39455_altar") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetEntry() == 244564)
        {
            if (player->HasQuest(QUEST_CAVE_OF_THE_BLOOD_TRIAL))
            {
                if (Creature* mobs = player->FindNearestCreature(97544, 25.0f, true))
                {
                    mobs->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    mobs->AI()->Talk(0);
                    mobs->Attack(player, true);
                }
            }
        }
        return false;
    }
};
//97418 QUEST_RITE_OF_BLOOD
struct npc_marakhan_97418 : public ScriptedAI
{
    npc_marakhan_97418(Creature* creature) : ScriptedAI(creature) {  }

    enum marakhan_Spells
    {
        SPELL_DOOM_BLADE = 197670,
        SPELL_UNYIELDING_TERROR = 197681,
    };

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(40, damage))
            events.ScheduleEvent(SPELL_UNYIELDING_TERROR, 1s);
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        if (Creature* mobs = me->FindNearestCreature(100055, 100.0f, true))
        {
            me->CastSpell(mobs, 197670, true);
            mobs->KillSelf();
        }
        events.ScheduleEvent(SPELL_DOOM_BLADE, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case SPELL_DOOM_BLADE:
        {
            DoCast(SPELL_DOOM_BLADE);
            events.Repeat(12s, 15s);
            break;
        }
        case SPELL_UNYIELDING_TERROR:
        {
            DoCast(SPELL_UNYIELDING_TERROR);
            events.Repeat(22s, 25s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_navarrogg_95259 : public ScriptedAI
{
    npc_navarrogg_95259(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 25.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_RITE_OF_BLOOD))
                {
                    IsLock = true;
                    Talk(0);
                    player->KilledMonsterCredit(me->GetEntry());
                }
                if (player->HasQuest(QUEST_ROCK_TROLL_IN_A_HARD_PLACE))
                    player->KilledMonsterCredit(96286);
            }
        }
    }
};
//    QUEST_PET_ROCKS = 39391,QUEST_STONEDARK_CRYSTAL = 39425,QUEST_THEY_WILL_PAY_WITH_BLOOD = 39588,
//95272,95273,95276
struct npc_quest_pet_rocks : public ScriptedAI
{
    npc_quest_pet_rocks(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_PET_ROCKS) == QUEST_STATUS_INCOMPLETE)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                player->KilledMonsterCredit(me->GetEntry());
                Talk(0);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_PET_ROCKS))
                {
                    IsLock = true;
                    me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                }
            }
        }
    }
};

class scene_the_story_of_huln : public SceneScript
{
public:
    scene_the_story_of_huln() : SceneScript("scene_the_story_of_huln") { }

    // Called when a scene is either canceled or completed
    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->KilledMonsterCredit(98825);
        player->SummonCreature(98825, Position(4057.2099f, 4320.37f, 675.603f, 1.2158f), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
    }
};

void AddSC_highmountain()
{
    RegisterCreatureAI(npc_94973);
    RegisterCreatureAI(npc_archmage_khadgar_91172);
    RegisterCreatureAI(npc_warbrave_oro_97666);
    RegisterCreatureAI(npc_warbrave_oro_106244);
    RegisterCreatureAI(npc_mayla_highmountain_93826);
    RegisterCreatureAI(npc_jale_rivermane_93833);

    RegisterCreatureAI(npc_mayla_highmountain_96049);
    RegisterCreatureAI(npc_spiritwalker_ebonhorn_94571);

    RegisterCreatureAI(npc_ebyssian_108199);
    RegisterCreatureAI(npc_spiritwalker_ebonhorn_98825);

    RegisterCreatureAI(npc_spiritwalker_ebonhorn_99153); //QUEST_IN_DEFIANCE_OF_DEATHWING
    new go_quest_40219_highmountain_brazier();
    new go_quest_39578_highmountain_brazier();
    RegisterCreatureAI(npc_spiritwalker_ebonhorn_99190);
    new go_quest_39577_highmountain_brazier();
    RegisterCreatureAI(npc_quest_evacuate_snowmane_42088);
    RegisterCreatureAI(npc_dargrul_107704);
    RegisterCreatureAI(npc_war_eagle_100712);
    RegisterCreatureAI(npc_mayla_highmountain_97352);
    RegisterCreatureAI(npc_the_hammer_of_khazgoroth_107587);

    RegisterCreatureAI(npc_windmaster_julan_95403);
    new spell_suppressing_wind_189168();
    RegisterCreatureAI(npc_captive_great_eagle_94991);

    RegisterCreatureAI(npc_warbrave_oro_95051);
    RegisterCreatureAI(npc_spiritwalker_ebonhorn_93805);
    RegisterCreatureAI(npc_highmountain_elder_94547);

    new go_quest_39455_altar();
    RegisterCreatureAI(npc_marakhan_97418);
    RegisterCreatureAI(npc_navarrogg_95259);
    RegisterCreatureAI(npc_quest_pet_rocks);
    RegisterSceneScript(scene_the_story_of_huln);
}
