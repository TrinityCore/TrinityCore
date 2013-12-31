/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "Player.h"

enum Orphans
{
    ORPHAN_ORACLE                           = 33533,
    ORPHAN_WOLVAR                           = 33532,
    ORPHAN_BLOOD_ELF                        = 22817,
    ORPHAN_DRAENEI                          = 22818,
    ORPHAN_HUMAN                            = 14305,
    ORPHAN_ORCISH                           = 14444,
};

enum Texts
{
    TEXT_ORACLE_ORPHAN_1                    = 1,
    TEXT_ORACLE_ORPHAN_2                    = 2,
    TEXT_ORACLE_ORPHAN_3                    = 3,
    TEXT_ORACLE_ORPHAN_4                    = 4,
    TEXT_ORACLE_ORPHAN_5                    = 5,
    TEXT_ORACLE_ORPHAN_6                    = 6,
    TEXT_ORACLE_ORPHAN_7                    = 7,
    TEXT_ORACLE_ORPHAN_8                    = 8,
    TEXT_ORACLE_ORPHAN_9                    = 9,
    TEXT_ORACLE_ORPHAN_10                   = 10,
    TEXT_ORACLE_ORPHAN_11                   = 11,
    TEXT_ORACLE_ORPHAN_12                   = 12,
    TEXT_ORACLE_ORPHAN_13                   = 13,
    TEXT_ORACLE_ORPHAN_14                   = 14,

    TEXT_WOLVAR_ORPHAN_1                    = 1,
    TEXT_WOLVAR_ORPHAN_2                    = 2,
    TEXT_WOLVAR_ORPHAN_3                    = 3,
    TEXT_WOLVAR_ORPHAN_4                    = 4,
    TEXT_WOLVAR_ORPHAN_5                    = 5,
    // 6 - 9 used in Nesingwary script
    TEXT_WOLVAR_ORPHAN_10                   = 10,
    TEXT_WOLVAR_ORPHAN_11                   = 11,
    TEXT_WOLVAR_ORPHAN_12                   = 12,
    TEXT_WOLVAR_ORPHAN_13                   = 13,

    TEXT_WINTERFIN_PLAYMATE_1               = 1,
    TEXT_WINTERFIN_PLAYMATE_2               = 2,

    TEXT_SNOWFALL_GLADE_PLAYMATE_1          = 1,
    TEXT_SNOWFALL_GLADE_PLAYMATE_2          = 2,

    TEXT_SOO_ROO_1                          = 1,
    TEXT_ELDER_KEKEK_1                      = 1,

    TEXT_ALEXSTRASZA_2                      = 2,
    TEXT_KRASUS_8                           = 8,
};

enum Quests
{
    QUEST_PLAYMATE_WOLVAR                   = 13951,
    QUEST_PLAYMATE_ORACLE                   = 13950,
    QUEST_THE_BIGGEST_TREE_EVER             = 13929,
    QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE    = 13933,
    QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR    = 13934,
    QUEST_MEETING_A_GREAT_ONE               = 13956,
    QUEST_THE_MIGHTY_HEMET_NESINGWARY       = 13957,
    QUEST_DOWN_AT_THE_DOCKS                 = 910,
    QUEST_GATEWAY_TO_THE_FRONTIER           = 911,
    QUEST_BOUGHT_OF_ETERNALS                = 1479,
    QUEST_SPOOKY_LIGHTHOUSE                 = 1687,
    QUEST_STONEWROUGHT_DAM                  = 1558,
    QUEST_DARK_PORTAL_H                     = 10951,
    QUEST_DARK_PORTAL_A                     = 10952,
    QUEST_LORDAERON_THRONE_ROOM             = 1800,
    QUEST_AUCHINDOUN_AND_THE_RING           = 10950,
    QUEST_TIME_TO_VISIT_THE_CAVERNS_H       = 10963,
    QUEST_TIME_TO_VISIT_THE_CAVERNS_A       = 10962,
    QUEST_THE_SEAT_OF_THE_NARUU             = 10956,
    QUEST_CALL_ON_THE_FARSEER               = 10968,
    QUEST_JHEEL_IS_AT_AERIS_LANDING         = 10954,
    QUEST_HCHUU_AND_THE_MUSHROOM_PEOPLE     = 10945,
    QUEST_VISIT_THE_THRONE_OF_ELEMENTS      = 10953,
    QUEST_NOW_WHEN_I_GROW_UP                = 11975,
    QUEST_HOME_OF_THE_BEAR_MEN              = 13930,
    QUEST_THE_DRAGON_QUEEN_ORACLE           = 13954,
    QUEST_THE_DRAGON_QUEEN_WOLVAR           = 13955,
};

enum Areatriggers
{
    AT_DOWN_AT_THE_DOCKS                    = 3551,
    AT_GATEWAY_TO_THE_FRONTIER              = 3549,
    AT_LORDAERON_THRONE_ROOM                = 3547,
    AT_BOUGHT_OF_ETERNALS                   = 3546,
    AT_SPOOKY_LIGHTHOUSE                    = 3552,
    AT_STONEWROUGHT_DAM                     = 3548,
    AT_DARK_PORTAL                          = 4356,

    NPC_CAVERNS_OF_TIME_CW_TRIGGER          = 22872,
    NPC_EXODAR_01_CW_TRIGGER                = 22851,
    NPC_EXODAR_02_CW_TRIGGER                = 22905,
    NPC_AERIS_LANDING_CW_TRIGGER            = 22838,
    NPC_AUCHINDOUN_CW_TRIGGER               = 22831,
    NPC_SPOREGGAR_CW_TRIGGER                = 22829,
    NPC_THRONE_OF_ELEMENTS_CW_TRIGGER       = 22839,
    NPC_SILVERMOON_01_CW_TRIGGER            = 22866,
    NPC_KRASUS                              = 27990,
};

enum Misc
{
    SPELL_SNOWBALL                          = 21343,
    SPELL_ORPHAN_OUT                        = 58818,

    DISPLAY_INVISIBLE                       = 11686,
};

uint64 getOrphanGUID(Player* player, uint32 orphan)
{
    if (Aura* orphanOut = player->GetAura(SPELL_ORPHAN_OUT))
        if (orphanOut->GetCaster() && orphanOut->GetCaster()->GetEntry() == orphan)
            return orphanOut->GetCaster()->GetGUID();

    return 0;
}

/*######
## npc_winterfin_playmate
######*/
class npc_winterfin_playmate : public CreatureScript
{
    public:
        npc_winterfin_playmate() : CreatureScript("npc_winterfin_playmate") { }

        struct npc_winterfin_playmateAI : public ScriptedAI
        {
            npc_winterfin_playmateAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_PLAYMATE_ORACLE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_ORACLE);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_1);
                            timer = 3000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            Talk(TEXT_WINTERFIN_PLAYMATE_1);
                            me->HandleEmoteCommand(EMOTE_STATE_DANCE);
                            timer = 3000;
                            break;
                        case 3:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_2);
                            timer = 3000;
                            break;
                        case 4:
                            Talk(TEXT_WINTERFIN_PLAYMATE_2);
                            timer = 5000;
                            break;
                        case 5:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_3);
                            me->HandleEmoteCommand(EMOTE_STATE_NONE);
                            player->GroupEventHappens(QUEST_PLAYMATE_ORACLE, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_winterfin_playmateAI(creature);
        }
};

/*######
## npc_snowfall_glade_playmate
######*/
class npc_snowfall_glade_playmate : public CreatureScript
{
    public:
        npc_snowfall_glade_playmate() : CreatureScript("npc_snowfall_glade_playmate") { }

        struct npc_snowfall_glade_playmateAI : public ScriptedAI
        {
            npc_snowfall_glade_playmateAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_PLAYMATE_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_WOLVAR);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_1);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            Talk(TEXT_SNOWFALL_GLADE_PLAYMATE_1);
                            DoCast(orphan, SPELL_SNOWBALL);
                            timer = 5000;
                            break;
                        case 3:
                            Talk(TEXT_SNOWFALL_GLADE_PLAYMATE_2);
                            timer = 5000;
                            break;
                        case 4:
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_2);
                            orphan->AI()->DoCast(me, SPELL_SNOWBALL);
                            timer = 5000;
                            break;
                        case 5:
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_3);
                            player->GroupEventHappens(QUEST_PLAYMATE_WOLVAR, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_snowfall_glade_playmateAI(pCreature);
        }
};

/*######
## npc_the_biggest_tree
######*/
class npc_the_biggest_tree : public CreatureScript
{
    public:
        npc_the_biggest_tree() : CreatureScript("npc_the_biggest_tree") { }

        struct npc_the_biggest_treeAI : public ScriptedAI
        {
            npc_the_biggest_treeAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(DISPLAY_INVISIBLE);
            }

            void Reset()
            {
                timer = 1000;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BIGGEST_TREE_EVER) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_ORACLE);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            timer = 2000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_4);
                            timer = 5000;
                            break;
                        case 3:
                            player->GroupEventHappens(QUEST_THE_BIGGEST_TREE_EVER, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            uint8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_the_biggest_treeAI(creature);
        }
};

/*######
## npc_high_oracle_soo_roo
######*/
class npc_high_oracle_soo_roo : public CreatureScript
{
    public:
        npc_high_oracle_soo_roo() : CreatureScript("npc_high_oracle_soo_roo") { }

        struct npc_high_oracle_soo_rooAI : public ScriptedAI
        {
            npc_high_oracle_soo_rooAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_ORACLE);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_5);
                            timer = 3000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            Talk(TEXT_SOO_ROO_1);
                            timer = 6000;
                            break;
                        case 3:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_6);
                            player->GroupEventHappens(QUEST_THE_BRONZE_DRAGONSHRINE_ORACLE, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_high_oracle_soo_rooAI(creature);
        }
};

/*######
## npc_elder_kekek
######*/
class npc_elder_kekek : public CreatureScript
{
    public:
        npc_elder_kekek() : CreatureScript("npc_elder_kekek") { }

        struct npc_elder_kekekAI : public ScriptedAI
        {
            npc_elder_kekekAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_WOLVAR);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!player || !orphan)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_4);
                            timer = 3000;
                            break;
                        case 2:
                            Talk(TEXT_ELDER_KEKEK_1);
                            timer = 6000;
                            break;
                        case 3:
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_5);
                            player->GroupEventHappens(QUEST_THE_BRONZE_DRAGONSHRINE_WOLVAR, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_elder_kekekAI(creature);
        }
};

/*######
## npc_the_etymidian
## @todo A red crystal as a gift for the great one should be spawned during the event.
######*/
class npc_the_etymidian : public CreatureScript
{
    public:
        npc_the_etymidian() : CreatureScript("npc_the_etymidian") { }

        struct npc_the_etymidianAI : public ScriptedAI
        {
            npc_the_etymidianAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_MEETING_A_GREAT_ONE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_ORACLE);
                            if (orphanGUID)
                                phase = 1;
                        }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_7);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_8);
                            timer = 5000;
                            break;
                        case 3:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_9);
                            timer = 5000;
                            break;
                        case 4:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_10);
                            timer = 5000;
                            break;
                        case 5:
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            player->GroupEventHappens(QUEST_MEETING_A_GREAT_ONE, me);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

        private:
            uint32 timer;
            int8 phase;
            uint64 playerGUID;
            uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_the_etymidianAI(creature);
        }
};

/*######
## npc_cw_alexstrasza_trigger
######*/
class npc_alexstraza_the_lifebinder : public CreatureScript
{
    public:
        npc_alexstraza_the_lifebinder() : CreatureScript("npc_alexstraza_the_lifebinder") { }

        struct npc_alexstraza_the_lifebinderAI : public ScriptedAI
        {
            npc_alexstraza_the_lifebinderAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                timer = 0;
                phase = 0;
                playerGUID = 0;
                orphanGUID = 0;
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
            {
                // Existing SmartAI
                if (type == 0)
                {
                    switch (data)
                    {
                        case 1:
                            me->SetOrientation(1.6049f);
                            break;
                        case 2:
                            me->SetOrientation(me->GetHomePosition().GetOrientation());
                            break;
                    }
                }
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!phase && who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_THE_DRAGON_QUEEN_ORACLE) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_ORACLE);
                            if (orphanGUID)
                                phase = 1;
                        }
                        else if (player->GetQuestStatus(QUEST_THE_DRAGON_QUEEN_WOLVAR) == QUEST_STATUS_INCOMPLETE)
                        {
                            playerGUID = player->GetGUID();
                            orphanGUID = getOrphanGUID(player, ORPHAN_WOLVAR);
                            if (orphanGUID)
                                phase = 7;
                        }
                    }
            }

            void UpdateAI(uint32 diff)
            {
                if (!phase)
                    return;

                if (timer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
                    Creature* orphan = ObjectAccessor::GetCreature(*me, orphanGUID);

                    if (!orphan || !player)
                    {
                        Reset();
                        return;
                    }

                    switch (phase)
                    {
                        case 1:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_11);
                            timer = 5000;
                            break;
                        case 2:
                            orphan->SetFacingToObject(me);
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_12);
                            timer = 5000;
                            break;
                        case 3:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_13);
                            timer = 5000;
                            break;
                        case 4:
                            Talk(TEXT_ALEXSTRASZA_2);
                            me->SetStandState(UNIT_STAND_STATE_KNEEL);
                            me->SetFacingToObject(orphan);
                            timer = 5000;
                            break;
                        case 5:
                            orphan->AI()->Talk(TEXT_ORACLE_ORPHAN_14);
                            timer = 5000;
                            break;
                        case 6:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            me->SetOrientation(me->GetHomePosition().GetOrientation());
                            player->GroupEventHappens(QUEST_THE_DRAGON_QUEEN_ORACLE, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                        case 7:
                            orphan->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 5, me->GetPositionY() + sin(me->GetOrientation()) * 5, me->GetPositionZ());
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_11);
                            timer = 5000;
                            break;
                        case 8:
                            if (Creature* krasus = me->FindNearestCreature(NPC_KRASUS, 10.0f))
                            {
                                orphan->SetFacingToObject(krasus);
                                krasus->AI()->Talk(TEXT_KRASUS_8);
                            }
                            timer = 5000;
                            break;
                        case 9:
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_12);
                            timer = 5000;
                            break;
                        case 10:
                            orphan->SetFacingToObject(me);
                            Talk(TEXT_ALEXSTRASZA_2);
                            timer = 5000;
                            break;
                        case 11:
                            orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_13);
                            timer = 5000;
                            break;
                        case 12:
                            player->GroupEventHappens(QUEST_THE_DRAGON_QUEEN_WOLVAR, me);
                            orphan->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                            Reset();
                            return;
                    }
                    ++phase;
                }
                else
                    timer -= diff;
            }

            private:
                int8 phase;
                uint32 timer;
                uint64 playerGUID;
                uint64 orphanGUID;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_alexstraza_the_lifebinderAI(creature);
        }
};

/*######
## at_bring_your_orphan_to
######*/

class at_bring_your_orphan_to : public AreaTriggerScript
{
    public:
        at_bring_your_orphan_to() : AreaTriggerScript("at_bring_your_orphan_to") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (player->isDead() || !player->HasAura(SPELL_ORPHAN_OUT))
                return false;

            uint32 questId = 0;
            uint32 orphanId = 0;

            switch (trigger->id)
            {
                case AT_DOWN_AT_THE_DOCKS:
                    questId = QUEST_DOWN_AT_THE_DOCKS;
                    orphanId = ORPHAN_ORCISH;
                    break;
                case AT_GATEWAY_TO_THE_FRONTIER:
                    questId = QUEST_GATEWAY_TO_THE_FRONTIER;
                    orphanId = ORPHAN_ORCISH;
                    break;
                case AT_LORDAERON_THRONE_ROOM:
                    questId = QUEST_LORDAERON_THRONE_ROOM;
                    orphanId = ORPHAN_ORCISH;
                    break;
                case AT_BOUGHT_OF_ETERNALS:
                    questId = QUEST_BOUGHT_OF_ETERNALS;
                    orphanId = ORPHAN_HUMAN;
                    break;
                case AT_SPOOKY_LIGHTHOUSE:
                    questId = QUEST_SPOOKY_LIGHTHOUSE;
                    orphanId = ORPHAN_HUMAN;
                    break;
                case AT_STONEWROUGHT_DAM:
                    questId = QUEST_STONEWROUGHT_DAM;
                    orphanId = ORPHAN_HUMAN;
                    break;
                case AT_DARK_PORTAL:
                    questId = player->GetTeam() == ALLIANCE ? QUEST_DARK_PORTAL_A : QUEST_DARK_PORTAL_H;
                    orphanId = player->GetTeam() == ALLIANCE ? ORPHAN_DRAENEI : ORPHAN_BLOOD_ELF;
                    break;
            }

            if (questId && orphanId && getOrphanGUID(player, orphanId) && player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(questId);

            return true;
        }
};

/*######
## npc_cw_area_trigger
######*/
class npc_cw_area_trigger : public CreatureScript
{
    public:
        npc_cw_area_trigger() : CreatureScript("npc_cw_area_trigger") { }

        struct npc_cw_area_triggerAI : public ScriptedAI
        {
            npc_cw_area_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(DISPLAY_INVISIBLE);
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (who && me->GetDistance2d(who) < 20.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->HasAura(SPELL_ORPHAN_OUT))
                        {
                            uint32 questId = 0;
                            uint32 orphanId = 0;
                            switch (me->GetEntry())
                            {
                                case NPC_CAVERNS_OF_TIME_CW_TRIGGER:
                                    questId = player->GetTeam() == ALLIANCE ? QUEST_TIME_TO_VISIT_THE_CAVERNS_A : QUEST_TIME_TO_VISIT_THE_CAVERNS_H;
                                    orphanId = player->GetTeam() == ALLIANCE ? ORPHAN_DRAENEI : ORPHAN_BLOOD_ELF;
                                    break;
                                case NPC_EXODAR_01_CW_TRIGGER:
                                    questId = QUEST_THE_SEAT_OF_THE_NARUU;
                                    orphanId = ORPHAN_DRAENEI;
                                    break;
                                case NPC_EXODAR_02_CW_TRIGGER:
                                    questId = QUEST_CALL_ON_THE_FARSEER;
                                    orphanId = ORPHAN_DRAENEI;
                                    break;
                                case NPC_AERIS_LANDING_CW_TRIGGER:
                                    questId = QUEST_JHEEL_IS_AT_AERIS_LANDING;
                                    orphanId = ORPHAN_DRAENEI;
                                    break;
                                case NPC_AUCHINDOUN_CW_TRIGGER:
                                    questId = QUEST_AUCHINDOUN_AND_THE_RING;
                                    orphanId = ORPHAN_DRAENEI;
                                    break;
                                case NPC_SPOREGGAR_CW_TRIGGER:
                                    questId = QUEST_HCHUU_AND_THE_MUSHROOM_PEOPLE;
                                    orphanId = ORPHAN_BLOOD_ELF;
                                    break;
                                case NPC_THRONE_OF_ELEMENTS_CW_TRIGGER:
                                    questId = QUEST_VISIT_THE_THRONE_OF_ELEMENTS;
                                    orphanId = ORPHAN_BLOOD_ELF;
                                    break;
                                case NPC_SILVERMOON_01_CW_TRIGGER:
                                    if (player->GetQuestStatus(QUEST_NOW_WHEN_I_GROW_UP) == QUEST_STATUS_INCOMPLETE && getOrphanGUID(player, ORPHAN_BLOOD_ELF))
                                    {
                                        player->AreaExploredOrEventHappens(QUEST_NOW_WHEN_I_GROW_UP);
                                        if (player->GetQuestStatus(QUEST_NOW_WHEN_I_GROW_UP) == QUEST_STATUS_COMPLETE)
                                            if (Creature* samuro = me->FindNearestCreature(25151, 20.0f))
                                            {
                                                uint32 emote = 0;
                                                switch (urand(1, 5))
                                                {
                                                    case 1:
                                                        emote = EMOTE_ONESHOT_WAVE;
                                                        break;
                                                    case 2:
                                                        emote = EMOTE_ONESHOT_ROAR;
                                                        break;
                                                    case 3:
                                                        emote = EMOTE_ONESHOT_FLEX;
                                                        break;
                                                    case 4:
                                                        emote = EMOTE_ONESHOT_SALUTE;
                                                        break;
                                                    case 5:
                                                        emote = EMOTE_ONESHOT_DANCE;
                                                        break;
                                                }
                                                samuro->HandleEmoteCommand(emote);
                                            }
                                    }
                                    break;
                            }
                            if (questId && orphanId && getOrphanGUID(player, orphanId) && player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                                player->AreaExploredOrEventHappens(questId);
                        }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_cw_area_triggerAI(creature);
        }
};

/*######
## npc_grizzlemaw_cw_trigger
######*/
class npc_grizzlemaw_cw_trigger : public CreatureScript
{
    public:
        npc_grizzlemaw_cw_trigger() : CreatureScript("npc_grizzlemaw_cw_trigger") { }

        struct npc_grizzlemaw_cw_triggerAI : public ScriptedAI
        {
            npc_grizzlemaw_cw_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(DISPLAY_INVISIBLE);
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (who && who->GetDistance2d(me) < 10.0f)
                    if (Player* player = who->ToPlayer())
                        if (player->GetQuestStatus(QUEST_HOME_OF_THE_BEAR_MEN) == QUEST_STATUS_INCOMPLETE)
                            if (Creature* orphan = Creature::GetCreature(*me, getOrphanGUID(player, ORPHAN_WOLVAR)))
                            {
                                player->AreaExploredOrEventHappens(QUEST_HOME_OF_THE_BEAR_MEN);
                                orphan->AI()->Talk(TEXT_WOLVAR_ORPHAN_10);
                            }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_grizzlemaw_cw_triggerAI(creature);
        }
};

void AddSC_event_childrens_week()
{
    new npc_elder_kekek();
    new npc_high_oracle_soo_roo();
    new npc_winterfin_playmate();
    new npc_snowfall_glade_playmate();
    new npc_the_etymidian();
    new npc_the_biggest_tree();
    new at_bring_your_orphan_to();
    new npc_grizzlemaw_cw_trigger();
    new npc_cw_area_trigger();
    new npc_alexstraza_the_lifebinder();
}
