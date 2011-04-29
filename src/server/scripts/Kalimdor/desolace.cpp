/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

enum eDyingKodo
{
    // signed for 9999
    SAY_SMEED_HOME_1                = -1000348,
    SAY_SMEED_HOME_2                = -1000349,
    SAY_SMEED_HOME_3                = -1000350,

    QUEST_KODO                      = 5561,

    NPC_SMEED                       = 11596,
    NPC_AGED_KODO                   = 4700,
    NPC_DYING_KODO                  = 4701,
    NPC_ANCIENT_KODO                = 4702,
    NPC_TAMED_KODO                  = 11627,

    SPELL_KODO_KOMBO_ITEM           = 18153,
    SPELL_KODO_KOMBO_PLAYER_BUFF    = 18172,                //spells here have unclear function, but using them at least for visual parts and checks
    SPELL_KODO_KOMBO_DESPAWN_BUFF   = 18377,
    SPELL_KODO_KOMBO_GOSSIP         = 18362

};

class npc_aged_dying_ancient_kodo : public CreatureScript
{
public:
    npc_aged_dying_ancient_kodo() : CreatureScript("npc_aged_dying_ancient_kodo") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) && pCreature->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
        {
            //the expected quest objective
            pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());

            pPlayer->RemoveAurasDueToSpell(SPELL_KODO_KOMBO_PLAYER_BUFF);
            pCreature->GetMotionMaster()->MoveIdle();
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool EffectDummyCreature(Unit *pCaster, uint32 spellId, uint32 effIndex, Creature *pCreatureTarget)
    {
        //always check spellid and effectindex
        if (spellId == SPELL_KODO_KOMBO_ITEM && effIndex == 0)
        {
            //no effect if player/creature already have aura from spells
            if (pCaster->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) || pCreatureTarget->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
                return true;

            if (pCreatureTarget->GetEntry() == NPC_AGED_KODO ||
                pCreatureTarget->GetEntry() == NPC_DYING_KODO ||
                pCreatureTarget->GetEntry() == NPC_ANCIENT_KODO)
            {
                pCaster->CastSpell(pCaster, SPELL_KODO_KOMBO_PLAYER_BUFF, true);

                pCreatureTarget->UpdateEntry(NPC_TAMED_KODO);
                pCreatureTarget->CastSpell(pCreatureTarget, SPELL_KODO_KOMBO_DESPAWN_BUFF, false);

                if (pCreatureTarget->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                    pCreatureTarget->GetMotionMaster()->MoveIdle();

                pCreatureTarget->GetMotionMaster()->MoveFollow(pCaster, PET_FOLLOW_DIST,  pCreatureTarget->GetFollowAngle());
            }

            //always return true when we are handling this spell and effect
            return true;
        }
        return false;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_aged_dying_ancient_kodoAI(pCreature);
    }

    struct npc_aged_dying_ancient_kodoAI : public ScriptedAI
    {
        npc_aged_dying_ancient_kodoAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

        uint32 m_uiDespawnTimer;

        void Reset()
        {
            m_uiDespawnTimer = 0;
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (pWho->GetEntry() == NPC_SMEED)
            {
                if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                    return;

                if (me->IsWithinDistInMap(pWho, 10.0f))
                {
                    DoScriptText(RAND(SAY_SMEED_HOME_1, SAY_SMEED_HOME_2, SAY_SMEED_HOME_3), pWho);

                    //spell have no implemented effect (dummy), so useful to notify spellHit
                    DoCast(me, SPELL_KODO_KOMBO_GOSSIP, true);
                }
            }
        }

        void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpell)
        {
            if (pSpell->Id == SPELL_KODO_KOMBO_GOSSIP)
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                m_uiDespawnTimer = 60000;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //timer should always be == 0 unless we already updated entry of creature. Then not expect this updated to ever be in combat.
            if (m_uiDespawnTimer && m_uiDespawnTimer <= diff)
            {
                if (!me->getVictim() && me->isAlive())
                {
                    Reset();
                    me->setDeathState(JUST_DIED);
                    me->Respawn();
                    return;
                }
            } else m_uiDespawnTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## go_iruxos. Quest 5381
######*/

class go_iruxos : public GameObjectScript
{
public:
    go_iruxos() : GameObjectScript("go_iruxos") { }

    bool OnGossipHello(Player *pPlayer, GameObject* /*pGO*/)
    {
            if (pPlayer->GetQuestStatus(5381) == QUEST_STATUS_INCOMPLETE)
                pPlayer->SummonCreature(11876, pPlayer->GetInnPosX(), pPlayer->GetInnPosY(), pPlayer->GetInnPosZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

            return true;
    }

};

/*######
## npc_dalinda_malem. Quest 1440
######*/

#define QUEST_RETURN_TO_VAHLARRIEL     1440

class npc_dalinda : public CreatureScript
{
public:
    npc_dalinda() : CreatureScript("npc_dalinda") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_RETURN_TO_VAHLARRIEL)
       {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_dalinda::npc_dalindaAI, pCreature->AI()))
            {
                pEscortAI->Start(true, false, pPlayer->GetGUID());
                pCreature->setFaction(113);
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dalindaAI(pCreature);
    }

    struct npc_dalindaAI : public npc_escortAI
    {
        npc_dalindaAI(Creature* pCreature) : npc_escortAI(pCreature) { }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();
            switch (i)
            {
                case 1:
                    me->IsStandState();
                    break;
                case 15:
                    if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_RETURN_TO_VAHLARRIEL, me);
                    break;
            }
        }

        void EnterCombat(Unit* /*pWho*/) { }

        void Reset() {}

        void JustDied(Unit* /*pKiller*/)
        {
            Player* pPlayer = GetPlayerForEscort();
            if (pPlayer)
                pPlayer->FailQuest(QUEST_RETURN_TO_VAHLARRIEL);
            return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_desolace()
{
    new npc_aged_dying_ancient_kodo();
    new go_iruxos();
    new npc_dalinda();
}
