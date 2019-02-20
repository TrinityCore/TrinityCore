/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Wailing Caverns
SD%Complete: 95
SDComment: Need to add skill usage for Disciple of Naralex
SDCategory: Wailing Caverns
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "wailing_caverns.h"

/*######
## npc_disciple_of_naralex
######*/

enum Enums
{
    SAY_AT_LAST                   = 0,
    SAY_MAKE_PREPARATIONS         = 1,
    SAY_TEMPLE_OF_PROMISE         = 2,
    SAY_MUST_CONTINUE             = 3,
    SAY_BANISH_THE_SPIRITS        = 4,
    SAY_CAVERNS_PURIFIED          = 5,
    SAY_BEYOND_THIS_CORRIDOR      = 6,
    SAY_EMERALD_DREAM             = 7,
    EMOTE_AWAKENING_RITUAL        = 8,
    EMOTE_TROUBLED_SLEEP          = 0,
    EMOTE_WRITHE_IN_AGONY         = 1,
    EMOTE_HORRENDOUS_VISION       = 2,
    SAY_MUTANUS_THE_DEVOURER      = 9,
    SAY_I_AM_AWAKE                = 3,
    SAY_NARALEX_AWAKES            = 10,
    SAY_THANK_YOU                 = 4,
    SAY_FAREWELL                  = 5,
    SAY_ATTACKED                  = 11,

    GOSSIP_OPTION_LET_EVENT_BEGIN = 201,
    NPC_TEXT_NARALEX_SLEEPS_AGAIN = 698,
    NPC_TEXT_FANGLORDS_ARE_DEAD   = 699,

    SPELL_MARK_OF_THE_WILD_RANK_2 = 5232,
    SPELL_SERPENTINE_CLEANSING    = 6270,
    SPELL_NARALEXS_AWAKENING      = 6271,
    SPELL_FLIGHT_FORM             = 33943,

    NPC_DEVIATE_RAVAGER           = 3636,
    NPC_DEVIATE_VIPER             = 5755,
    NPC_DEVIATE_MOCCASIN          = 5762,
    NPC_NIGHTMARE_ECTOPLASM       = 5763,
    NPC_MUTANUS_THE_DEVOURER      = 3654,
};

class npc_disciple_of_naralex : public CreatureScript
{
public:
    npc_disciple_of_naralex() : CreatureScript("npc_disciple_of_naralex") { }

    struct npc_disciple_of_naralexAI : public EscortAI
    {
        npc_disciple_of_naralexAI(Creature* creature) : EscortAI(creature)
        {
            instance = creature->GetInstanceScript();
            eventTimer = 0;
            currentEvent = 0;
            eventProgress = 0;
            me->setActive(true);
            me->SetFarVisible(true);
            me->SetImmuneToPC(false);
        }

        uint32 eventTimer;
        uint32 currentEvent;
        uint32 eventProgress;
        InstanceScript* instance;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 4:
                    eventProgress = 1;
                    currentEvent = TYPE_NARALEX_PART1;
                    instance->SetData(TYPE_NARALEX_PART1, IN_PROGRESS);
                    break;
                case 5:
                    Talk(SAY_MUST_CONTINUE);
                    instance->SetData(TYPE_NARALEX_PART1, DONE);
                    break;
                case 11:
                    eventProgress = 1;
                    currentEvent = TYPE_NARALEX_PART2;
                    instance->SetData(TYPE_NARALEX_PART2, IN_PROGRESS);
                    break;
                case 19:
                    Talk(SAY_BEYOND_THIS_CORRIDOR);
                    break;
                case 24:
                    eventProgress = 1;
                    currentEvent = TYPE_NARALEX_PART3;
                    instance->SetData(TYPE_NARALEX_PART3, IN_PROGRESS);
                    break;
            }
        }

        void Reset() override
        {

        }

        void JustEngagedWith(Unit* who) override
        {
            Talk(SAY_ATTACKED, who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_NARALEX_EVENT, FAIL);
            instance->SetData(TYPE_NARALEX_PART1, FAIL);
            instance->SetData(TYPE_NARALEX_PART2, FAIL);
            instance->SetData(TYPE_NARALEX_PART3, FAIL);
        }

        void JustSummoned(Creature* summoned) override
        {
             summoned->AI()->AttackStart(me);
        }

        void UpdateAI(uint32 diff) override
        {
            if (currentEvent != TYPE_NARALEX_PART3)
                EscortAI::UpdateAI(diff);

            if (eventTimer <= diff)
            {
                eventTimer = 0;
                if (instance->GetData(currentEvent) == IN_PROGRESS)
                {
                    switch (currentEvent)
                    {
                        case TYPE_NARALEX_PART1:
                            if (eventProgress == 1)
                            {
                                ++eventProgress;
                                Talk(SAY_TEMPLE_OF_PROMISE);
                                me->SummonCreature(NPC_DEVIATE_RAVAGER, -82.1763f, 227.874f, -93.3233f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                                me->SummonCreature(NPC_DEVIATE_RAVAGER, -72.9506f, 216.645f, -93.6756f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            }
                        break;
                        case TYPE_NARALEX_PART2:
                            if (eventProgress == 1)
                            {
                                ++eventProgress;
                                Talk(SAY_BANISH_THE_SPIRITS);
                                DoCast(me, SPELL_SERPENTINE_CLEANSING);
                                //CAST_AI(EscortAI, me->AI())->SetCanDefend(false);
                                eventTimer = 30000;
                                me->SummonCreature(NPC_DEVIATE_VIPER, -61.5261f, 273.676f, -92.8442f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                                me->SummonCreature(NPC_DEVIATE_VIPER, -58.4658f, 280.799f, -92.8393f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                                me->SummonCreature(NPC_DEVIATE_VIPER, -50.002f,  278.578f, -92.8442f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            }
                            else
                            if (eventProgress == 2)
                            {
                                //CAST_AI(EscortAI, me->AI())->SetCanDefend(true);
                                Talk(SAY_CAVERNS_PURIFIED);
                                instance->SetData(TYPE_NARALEX_PART2, DONE);
                                if (me->HasAura(SPELL_SERPENTINE_CLEANSING))
                                    me->RemoveAura(SPELL_SERPENTINE_CLEANSING);
                            }
                        break;
                        case TYPE_NARALEX_PART3:
                            if (eventProgress == 1)
                            {
                                ++eventProgress;
                                eventTimer = 4000;
                                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                                Talk(SAY_EMERALD_DREAM);
                            }
                            else
                            if (eventProgress == 2)
                            {
                                ++eventProgress;
                                eventTimer = 15000;
                                //CAST_AI(EscortAI, me->AI())->SetCanDefend(false);
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    DoCast(naralex, SPELL_NARALEXS_AWAKENING, true);
                                Talk(EMOTE_AWAKENING_RITUAL);
                            }
                            else
                            if (eventProgress == 3)
                            {
                                ++eventProgress;
                                eventTimer = 15000;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->AI()->Talk(EMOTE_TROUBLED_SLEEP);
                                me->SummonCreature(NPC_DEVIATE_MOCCASIN, 135.943f, 199.701f, -103.529f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_DEVIATE_MOCCASIN, 151.08f,  221.13f,  -103.609f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_DEVIATE_MOCCASIN, 128.007f, 227.428f, -97.421f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            }
                            else
                            if (eventProgress == 4)
                            {
                                ++eventProgress;
                                eventTimer = 30000;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->AI()->Talk(EMOTE_WRITHE_IN_AGONY);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 133.413f, 207.188f, -102.469f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 142.857f, 218.645f, -102.905f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 105.102f, 227.211f, -102.752f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 153.372f, 235.149f, -102.826f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 149.524f, 251.113f, -102.558f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 136.208f, 266.466f, -102.977f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                                me->SummonCreature(NPC_NIGHTMARE_ECTOPLASM, 126.167f, 274.759f, -102.962f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                            }
                            else
                            if (eventProgress == 5)
                            {
                                ++eventProgress;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->AI()->Talk(EMOTE_HORRENDOUS_VISION);
                                me->SummonCreature(NPC_MUTANUS_THE_DEVOURER, 150.872f, 262.905f, -103.503f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                Talk(SAY_MUTANUS_THE_DEVOURER);
                                instance->SetData(TYPE_MUTANUS_THE_DEVOURER, IN_PROGRESS);
                            }
                            else
                            if (eventProgress == 6 && instance->GetData(TYPE_MUTANUS_THE_DEVOURER) == DONE)
                            {
                                ++eventProgress;
                                eventTimer = 3000;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                {
                                    if (me->HasAura(SPELL_NARALEXS_AWAKENING))
                                        me->RemoveAura(SPELL_NARALEXS_AWAKENING);
                                    naralex->SetStandState(UNIT_STAND_STATE_STAND);
                                    naralex->AI()->Talk(SAY_I_AM_AWAKE);
                                }
                                Talk(SAY_NARALEX_AWAKES);
                            }
                            else
                            if (eventProgress == 7)
                            {
                                ++eventProgress;
                                eventTimer = 6000;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->AI()->Talk(SAY_THANK_YOU);
                            }
                            else
                            if (eventProgress == 8)
                            {
                                ++eventProgress;
                                eventTimer = 8000;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                {
                                    naralex->AI()->Talk(SAY_FAREWELL);
                                    naralex->AddAura(SPELL_FLIGHT_FORM, naralex);
                                }
                                SetRun();
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                me->AddAura(SPELL_FLIGHT_FORM, me);
                            }
                            else
                            if (eventProgress == 9)
                            {
                                ++eventProgress;
                                eventTimer = 1500;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->GetMotionMaster()->MovePoint(25, naralex->GetPositionX(), naralex->GetPositionY(), naralex->GetPositionZ());
                            }
                            else
                            if (eventProgress == 10)
                            {
                                ++eventProgress;
                                eventTimer = 2500;
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                {
                                    naralex->GetMotionMaster()->MovePoint(0, 117.095512f, 247.107971f, -96.167870f);
                                    naralex->GetMotionMaster()->MovePoint(1, 90.388809f, 276.135406f, -83.389801f);
                                }
                                me->GetMotionMaster()->MovePoint(26, 117.095512f, 247.107971f, -96.167870f);
                                me->GetMotionMaster()->MovePoint(27, 144.375443f, 281.045837f, -82.477135f);
                            }
                            else
                            if (eventProgress == 11)
                            {
                                if (Creature* naralex = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_NARALEX)))
                                    naralex->SetVisible(false);
                                me->SetVisible(false);
                                instance->SetData(TYPE_NARALEX_PART3, DONE);
                            }
                        break;
                    }
                }
            } else eventTimer -= diff;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                if (instance)
                    instance->SetData(TYPE_NARALEX_EVENT, IN_PROGRESS);

                Talk(SAY_MAKE_PREPARATIONS);

                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_ACTIVE);
                me->SetImmuneToPC(false);

                Start(false, false, player->GetGUID());
                SetDespawnAtFar(false);
                SetDespawnAtEnd(false);
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            DoCast(player, SPELL_MARK_OF_THE_WILD_RANK_2, true);
            if ((instance->GetData(TYPE_LORD_COBRAHN) == DONE) && (instance->GetData(TYPE_LORD_PYTHAS) == DONE) &&
                (instance->GetData(TYPE_LADY_ANACONDRA) == DONE) && (instance->GetData(TYPE_LORD_SERPENTIS) == DONE))
            {
                AddGossipItemFor(player, GOSSIP_OPTION_LET_EVENT_BEGIN, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_FANGLORDS_ARE_DEAD, me->GetGUID());

                if (!instance->GetData(TYPE_NARALEX_YELLED))
                {
                    Talk(SAY_AT_LAST);
                    instance->SetData(TYPE_NARALEX_YELLED, 1);
                }
            }
            else
            {
                SendGossipMenuFor(player, NPC_TEXT_NARALEX_SLEEPS_AGAIN, me->GetGUID());
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetWailingCavernsAI<npc_disciple_of_naralexAI>(creature);
    }
};

void AddSC_wailing_caverns()
{
    new npc_disciple_of_naralex();
}
