/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Desolace
SD%Complete: 100
SDComment: Quest support: 5561
SDCategory: Desolace
EndScriptData */

/* ContentData
npc_aged_dying_ancient_kodo
go_iruxos
npc_dalinda_malem
go_demon_portal
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "SpellInfo.h"

enum DyingKodo
{
    SAY_SMEED_HOME                  = 0,

    QUEST_KODO                      = 5561,

    NPC_SMEED                       = 11596,
    NPC_AGED_KODO                   = 4700,
    NPC_DYING_KODO                  = 4701,
    NPC_ANCIENT_KODO                = 4702,
    NPC_TAMED_KODO                  = 11627,

    SPELL_KODO_KOMBO_ITEM           = 18153,
    SPELL_KODO_KOMBO_PLAYER_BUFF    = 18172,
    SPELL_KODO_KOMBO_DESPAWN_BUFF   = 18377,
    SPELL_KODO_KOMBO_GOSSIP         = 18362

};

class npc_aged_dying_ancient_kodo : public CreatureScript
{
public:
    npc_aged_dying_ancient_kodo() : CreatureScript("npc_aged_dying_ancient_kodo") { }

    struct npc_aged_dying_ancient_kodoAI : public ScriptedAI
    {
        npc_aged_dying_ancient_kodoAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (who->GetEntry() == NPC_SMEED && me->IsWithinDistInMap(who, 10.0f) && !me->HasAura(SPELL_KODO_KOMBO_GOSSIP))
            {
                me->GetMotionMaster()->Clear();
                DoCast(me, SPELL_KODO_KOMBO_GOSSIP, true);
                if (Creature* smeed = who->ToCreature())
                    smeed->AI()->Talk(SAY_SMEED_HOME);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) OVERRIDE
        {
            if (spell->Id == SPELL_KODO_KOMBO_ITEM)
            {
                if (!(caster->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) || me->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
                    && (me->GetEntry() == NPC_AGED_KODO || me->GetEntry() == NPC_DYING_KODO || me->GetEntry() == NPC_ANCIENT_KODO))
                {
                    caster->CastSpell(caster, SPELL_KODO_KOMBO_PLAYER_BUFF, true);
                    DoCast(me, SPELL_KODO_KOMBO_DESPAWN_BUFF, true);

                    me->UpdateEntry(NPC_TAMED_KODO);
                    me->GetMotionMaster()->MoveFollow(caster, PET_FOLLOW_DIST, me->GetFollowAngle());
                }
            }
            else if (spell->Id == SPELL_KODO_KOMBO_GOSSIP)
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->DespawnOrUnsummon(60000);
            }
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) && creature->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
        {
            player->TalkedToCreature(creature->GetEntry(), 0);
            player->RemoveAurasDueToSpell(SPELL_KODO_KOMBO_PLAYER_BUFF);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_aged_dying_ancient_kodoAI(creature);
    }

};

/*######
## go_iruxos
## Hand of Iruxos
######*/

enum Iruxos
{
    QUEST_HAND_IRUXOS   = 5381,
    NPC_DEMON_SPIRIT    = 11876
};

class go_iruxos : public GameObjectScript
{
    public:
        go_iruxos() : GameObjectScript("go_iruxos") { }

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            if (player->GetQuestStatus(QUEST_HAND_IRUXOS) == QUEST_STATUS_INCOMPLETE && !go->FindNearestCreature(NPC_DEMON_SPIRIT, 25.0f, true))
                player->SummonCreature(NPC_DEMON_SPIRIT, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

            return true;
        }
};

/*######
## npc_dalinda_malem. Quest 1440
######*/

enum Dalinda
{
    QUEST_RETURN_TO_VAHLARRIEL      = 1440
};

class npc_dalinda : public CreatureScript
{
public:
    npc_dalinda() : CreatureScript("npc_dalinda") { }

    struct npc_dalindaAI : public npc_escortAI
    {
        npc_dalindaAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() OVERRIDE { }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_RETURN_TO_VAHLARRIEL);
            return;
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();

            switch (waypointId)
            {
                case 1:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 15:
                    if (player)
                        player->GroupEventHappens(QUEST_RETURN_TO_VAHLARRIEL, me);
                    break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_RETURN_TO_VAHLARRIEL)
       {
            if (npc_escortAI* escortAI = CAST_AI(npc_dalinda::npc_dalindaAI, creature->AI()))
            {
                escortAI->Start(true, false, player->GetGUID());
                creature->setFaction(113);
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_dalindaAI(creature);
    }
};

/*######
## go_demon_portal
######*/

enum DemonPortal
{
    NPC_DEMON_GUARDIAN          = 11937,
    QUEST_PORTAL_OF_THE_LEGION  = 5581
};

class go_demon_portal : public GameObjectScript
{
    public:
        go_demon_portal() : GameObjectScript("go_demon_portal") { }

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            if (player->GetQuestStatus(QUEST_PORTAL_OF_THE_LEGION) == QUEST_STATUS_INCOMPLETE && !go->FindNearestCreature(NPC_DEMON_GUARDIAN, 5.0f, true))
            {
                if (Creature* guardian = player->SummonCreature(NPC_DEMON_GUARDIAN, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
                    guardian->AI()->AttackStart(player);
            }

            return true;
        }
};

void AddSC_desolace()
{
    new npc_aged_dying_ancient_kodo();
    new go_iruxos();
    new npc_dalinda();
    new go_demon_portal();
}
