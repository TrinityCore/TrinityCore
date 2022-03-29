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

/* ScriptData
SDName: Desolace
SD%Complete: 100
SDComment: Quest support: 5561
SDCategory: Desolace
EndScriptData */

/* ContentData
npc_aged_dying_ancient_kodo
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
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

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetEntry() == NPC_SMEED && me->IsWithinDistInMap(who, 10.0f) && !me->HasAura(SPELL_KODO_KOMBO_GOSSIP))
            {
                me->GetMotionMaster()->Clear();
                DoCast(me, SPELL_KODO_KOMBO_GOSSIP, true);
                if (Creature* smeed = who->ToCreature())
                    smeed->AI()->Talk(SAY_SMEED_HOME);
            }
        }

        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
        {
            Unit* unitCaster = caster->ToUnit();
            if (!unitCaster)
                return;

            if (spellInfo->Id == SPELL_KODO_KOMBO_ITEM)
            {
                if (!(unitCaster->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) || me->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
                    && (me->GetEntry() == NPC_AGED_KODO || me->GetEntry() == NPC_DYING_KODO || me->GetEntry() == NPC_ANCIENT_KODO))
                {
                    unitCaster->CastSpell(unitCaster, SPELL_KODO_KOMBO_PLAYER_BUFF, true);
                    DoCast(me, SPELL_KODO_KOMBO_DESPAWN_BUFF, true);

                    me->UpdateEntry(NPC_TAMED_KODO);
                    me->CombatStop();
                    me->SetFaction(FACTION_FRIENDLY);
                    me->SetSpeedRate(MOVE_RUN, 0.6f);

                    EngagementOver();

                    me->GetMotionMaster()->MoveFollow(unitCaster, PET_FOLLOW_DIST, me->GetFollowAngle());
                    me->setActive(true);
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }
            else if (spellInfo->Id == SPELL_KODO_KOMBO_GOSSIP)
            {
                me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                me->setActive(false);
                me->DespawnOrUnsummon(60s);
            }
        }

        bool OnGossipHello(Player* player) override
        {
            if (player->HasAura(SPELL_KODO_KOMBO_PLAYER_BUFF) && me->HasAura(SPELL_KODO_KOMBO_DESPAWN_BUFF))
            {
                player->TalkedToCreature(me->GetEntry(), ObjectGuid::Empty);
                player->RemoveAurasDueToSpell(SPELL_KODO_KOMBO_PLAYER_BUFF);
            }

            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aged_dying_ancient_kodoAI(creature);
    }

};

void AddSC_desolace()
{
    new npc_aged_dying_ancient_kodo();
}
