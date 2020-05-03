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

/* Script Data Start
SDName: Dalaran
SDAuthor: WarHead, MaXiMiUS
SD%Complete: 99%
SDComment: For what is 63990+63991? Same function but don't work correct...
SDCategory: Dalaran
Script Data End */

#include "ScriptMgr.h"
#include "DatabaseEnv.h"
#include "Mail.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*******************************************************
 * npc_mageguard_dalaran
 *******************************************************/

enum Spells
{
    SPELL_TRESPASSER_A                     = 54028,
    SPELL_TRESPASSER_H                     = 54029,

    SPELL_SUNREAVER_DISGUISE_FEMALE        = 70973,
    SPELL_SUNREAVER_DISGUISE_MALE          = 70974,
    SPELL_SILVER_COVENANT_DISGUISE_FEMALE  = 70971,
    SPELL_SILVER_COVENANT_DISGUISE_MALE    = 70972,
};

enum NPCs // All outdoor guards are within 35.0f of these NPCs
{
    NPC_APPLEBOUGH_A                       = 29547,
    NPC_SWEETBERRY_H                       = 29715,
    NPC_SILVER_COVENANT_GUARDIAN_MAGE      = 29254,
    NPC_SUNREAVER_GUARDIAN_MAGE            = 29255,
};

class npc_mageguard_dalaran : public CreatureScript
{
public:
    npc_mageguard_dalaran() : CreatureScript("npc_mageguard_dalaran") { }

    struct npc_mageguard_dalaranAI : public ScriptedAI
    {
        npc_mageguard_dalaranAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
            creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
        }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override { }

        void AttackStart(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld() || who->GetZoneId() != 4395)
                return;

            if (!me->IsWithinDist(who, 65.0f, false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player || player->IsGameMaster() || player->IsBeingTeleported() ||
                // If player has Disguise aura for quest A Meeting With The Magister or An Audience With The Arcanist, do not teleport it away but let it pass
                player->HasAura(SPELL_SUNREAVER_DISGUISE_FEMALE) || player->HasAura(SPELL_SUNREAVER_DISGUISE_MALE) ||
                player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_FEMALE) || player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_MALE))
                return;

            switch (me->GetEntry())
            {
                case NPC_SILVER_COVENANT_GUARDIAN_MAGE:
                    if (player->GetTeam() == HORDE)              // Horde unit found in Alliance area
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_APPLEBOUGH_A, 32.0f))
                        {
                            if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                                DoCast(who, SPELL_TRESPASSER_A); // Teleport the Horde unit out
                        }
                        else                                      // In my line of sight, and "indoors"
                            DoCast(who, SPELL_TRESPASSER_A);     // Teleport the Horde unit out
                    }
                    break;
                case NPC_SUNREAVER_GUARDIAN_MAGE:
                    if (player->GetTeam() == ALLIANCE)           // Alliance unit found in Horde area
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_SWEETBERRY_H, 32.0f))
                        {
                            if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                                DoCast(who, SPELL_TRESPASSER_H); // Teleport the Alliance unit out
                        }
                        else                                      // In my line of sight, and "indoors"
                            DoCast(who, SPELL_TRESPASSER_H);     // Teleport the Alliance unit out
                    }
                    break;
            }
            return;
        }

        void UpdateAI(uint32 /*diff*/) override { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mageguard_dalaranAI(creature);
    }
};

enum MinigobData
{
    ZONE_DALARAN            = 4395,

    SPELL_MANABONKED        = 61834,
    SPELL_TELEPORT_VISUAL   = 51347,
    SPELL_IMPROVED_BLINK    = 61995,

    EVENT_SELECT_TARGET     = 1,
    EVENT_BLINK             = 2,
    EVENT_DESPAWN_VISUAL    = 3,
    EVENT_DESPAWN           = 4,

    MAIL_MINIGOB_ENTRY      = 264,
    MAIL_DELIVER_DELAY_MIN  = 5*MINUTE,
    MAIL_DELIVER_DELAY_MAX  = 15*MINUTE
};

class npc_minigob_manabonk : public CreatureScript
{
    public:
        npc_minigob_manabonk() : CreatureScript("npc_minigob_manabonk") {}

        struct npc_minigob_manabonkAI : public ScriptedAI
        {
            npc_minigob_manabonkAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset() override
            {
                me->SetVisible(false);
                events.ScheduleEvent(EVENT_SELECT_TARGET, IN_MILLISECONDS);
            }

            Player* SelectTargetInDalaran()
            {
                std::vector<Player*> PlayerInDalaranList;
                PlayerInDalaranList.clear();

                Map::PlayerList const &players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource()->ToPlayer())
                        if (player->GetZoneId() == ZONE_DALARAN && !player->IsFlying() && !player->IsMounted() && !player->IsGameMaster())
                            PlayerInDalaranList.push_back(player);

                if (PlayerInDalaranList.empty())
                    return NULL;
                return Trinity::Containers::SelectRandomContainerElement(PlayerInDalaranList);
            }

            void SendMailToPlayer(Player* player)
            {
                CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                int16 deliverDelay = irand(MAIL_DELIVER_DELAY_MIN, MAIL_DELIVER_DELAY_MAX);
                MailDraft(MAIL_MINIGOB_ENTRY, true).SendMailTo(trans, MailReceiver(player), MailSender(MAIL_CREATURE, uint64(me->GetEntry())), MAIL_CHECK_MASK_NONE, deliverDelay);
                CharacterDatabase.CommitTransaction(trans);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SELECT_TARGET:
                            me->SetVisible(true);
                            DoCast(me, SPELL_TELEPORT_VISUAL);
                            if (Player* player = SelectTargetInDalaran())
                            {
                                me->NearTeleportTo(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0.0f);
                                DoCast(player, SPELL_MANABONKED);
                                SendMailToPlayer(player);
                            }
                            events.ScheduleEvent(EVENT_BLINK, 3*IN_MILLISECONDS);
                            break;
                        case EVENT_BLINK:
                        {
                            DoCast(me, SPELL_IMPROVED_BLINK);
                            Position pos = me->GetRandomNearPosition(frand(15, 40));
                            me->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                            events.ScheduleEvent(EVENT_DESPAWN, 3 * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_DESPAWN_VISUAL, 2.5*IN_MILLISECONDS);
                            break;
                        }
                        case EVENT_DESPAWN_VISUAL:
                            DoCast(me, SPELL_TELEPORT_VISUAL);
                            break;
                        case EVENT_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_minigob_manabonkAI(creature);
    }
};

void AddSC_dalaran()
{
    new npc_mageguard_dalaran();
    new npc_minigob_manabonk();
}
