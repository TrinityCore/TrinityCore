/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Stratholme
SD%Complete: 100
SDComment: Misc mobs for instance. go-script to apply aura and start event for quest 8945
SDCategory: Stratholme
EndScriptData */

/* ContentData
go_gauntlet_gate
npc_freed_soul
npc_restless_soul
npc_spectral_ghostly_citizen
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"
#include "Group.h"
#include "Player.h"
#include "SpellInfo.h"

/*######
## go_gauntlet_gate (this is the _first_ of the gauntlet gates, two exist)
######*/

class go_gauntlet_gate : public GameObjectScript
{
public:
    go_gauntlet_gate() : GameObjectScript("go_gauntlet_gate") { }

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        InstanceScript* instance = go->GetInstanceScript();

        if (!instance)
            return false;

        if (instance->GetData(TYPE_BARON_RUN) != NOT_STARTED)
            return false;

        if (Group* group = player->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* pGroupie = itr->GetSource();
                if (!pGroupie)
                    continue;

                if (pGroupie->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                    !pGroupie->HasAura(SPELL_BARON_ULTIMATUM) &&
                    pGroupie->GetMap() == go->GetMap())
                    pGroupie->CastSpell(pGroupie, SPELL_BARON_ULTIMATUM, true);
            }
        } else if (player->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                    !player->HasAura(SPELL_BARON_ULTIMATUM) &&
                    player->GetMap() == go->GetMap())
                    player->CastSpell(player, SPELL_BARON_ULTIMATUM, true);

        instance->SetData(TYPE_BARON_RUN, IN_PROGRESS);
        return false;
    }

};

/*######
## npc_freed_soul
######*/
enum FreedSoul
{
    SAY_ZAPPED = 0
};

class npc_freed_soul : public CreatureScript
{
public:
    npc_freed_soul() : CreatureScript("npc_freed_soul") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_freed_soulAI(creature);
    }

    struct npc_freed_soulAI : public ScriptedAI
    {
        npc_freed_soulAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE
        {
            Talk(SAY_ZAPPED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}
    };

};

/*######
## npc_restless_soul
######*/

enum RestlessSoul
{
    // Spells
    SPELL_EGAN_BLASTER      = 17368,
    SPELL_SOUL_FREED        = 17370,

    // Quest
    QUEST_RESTLESS_SOUL     = 5282,

    // Creatures
    NPC_RESTLESS            = 11122,
    NPC_FREED               = 11136
};

class npc_restless_soul : public CreatureScript
{
public:
    npc_restless_soul() : CreatureScript("npc_restless_soul") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_restless_soulAI(creature);
    }

    struct npc_restless_soulAI : public ScriptedAI
    {
        npc_restless_soulAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 Tagger;
        uint32 Die_Timer;
        bool Tagged;

        void Reset() OVERRIDE
        {
            Tagger = 0;
            Die_Timer = 5000;
            Tagged = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void SpellHit(Unit* caster, const SpellInfo* spell) OVERRIDE
        {
            if (Tagged || spell->Id != SPELL_EGAN_BLASTER)
                return;

            Player* player = caster->ToPlayer();
            if (!player || player->GetQuestStatus(QUEST_RESTLESS_SOUL) != QUEST_STATUS_INCOMPLETE)
                return;

            Tagged = true;
            Tagger = caster->GetGUID();
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            summoned->CastSpell(summoned, SPELL_SOUL_FREED, false);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Tagged)
                me->SummonCreature(NPC_FREED, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 300000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                {
                    if (Unit* temp = Unit::GetUnit(*me, Tagger))
                    {
                        if (Player* player = temp->ToPlayer())
                            player->KilledMonsterCredit(NPC_RESTLESS, me->GetGUID());
                        me->Kill(me);
                    }
                }
                else
                    Die_Timer -= diff;
            }
        }
    };

};

/*######
## npc_spectral_ghostly_citizen
######*/

enum GhostlyCitizenSpells
{
    SPELL_HAUNTING_PHANTOM  = 16336,
    SPELL_SLAP              = 6754
};

class npc_spectral_ghostly_citizen : public CreatureScript
{
public:
    npc_spectral_ghostly_citizen() : CreatureScript("npc_spectral_ghostly_citizen") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_spectral_ghostly_citizenAI(creature);
    }

    struct npc_spectral_ghostly_citizenAI : public ScriptedAI
    {
        npc_spectral_ghostly_citizenAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Die_Timer;
        bool Tagged;

        void Reset() OVERRIDE
        {
            Die_Timer = 5000;
            Tagged = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
        {
            if (!Tagged && spell->Id == SPELL_EGAN_BLASTER)
                Tagged = true;
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Tagged)
            {
                for (uint32 i = 1; i <= 4; ++i)
                {
                     //100%, 50%, 33%, 25% chance to spawn
                     if (urand(1, i) == 1)
                         DoSummon(NPC_RESTLESS, me, 20.0f, 600000);
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                    me->Kill(me);
                else Die_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) OVERRIDE
        {
            switch (emote)
            {
                case TEXT_EMOTE_DANCE:
                    EnterEvadeMode();
                    break;
                case TEXT_EMOTE_RUDE:
                    if (me->IsWithinDistInMap(player, 5))
                        DoCast(player, SPELL_SLAP, false);
                    else
                        me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                    break;
                case TEXT_EMOTE_WAVE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    break;
                case TEXT_EMOTE_BOW:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                    break;
                case TEXT_EMOTE_KISS:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
                    break;
            }
        }
    };

};

void AddSC_stratholme()
{
    new go_gauntlet_gate();
    new npc_freed_soul();
    new npc_restless_soul();
    new npc_spectral_ghostly_citizen();
}
