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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "stratholme.h"

/*######
## go_gauntlet_gate (this is the _first_ of the gauntlet gates, two exist)
######*/

class go_gauntlet_gate : public GameObjectScript
{
    public:
        go_gauntlet_gate() : GameObjectScript("go_gauntlet_gate") { }

        struct go_gauntlet_gateAI : public GameObjectAI
        {
            go_gauntlet_gateAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* player) override
            {
                if (instance->GetData(TYPE_BARON_RUN) != NOT_STARTED)
                    return false;

                if (Group* group = player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* pGroupie = itr->GetSource();
                        if (!pGroupie || !pGroupie->IsInMap(player))
                            continue;

                        if (pGroupie->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                            !pGroupie->HasAura(SPELL_BARON_ULTIMATUM) &&
                            pGroupie->GetMap() == me->GetMap())
                            pGroupie->CastSpell(pGroupie, SPELL_BARON_ULTIMATUM, true);
                    }
                }
                else if (player->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE &&
                    !player->HasAura(SPELL_BARON_ULTIMATUM) &&
                    player->GetMap() == me->GetMap())
                    player->CastSpell(player, SPELL_BARON_ULTIMATUM, true);

                instance->SetData(TYPE_BARON_RUN, IN_PROGRESS);
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetStratholmeAI<go_gauntlet_gateAI>(go);
        }
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<npc_restless_soulAI>(creature);
    }

    struct npc_restless_soulAI : public ScriptedAI
    {
        npc_restless_soulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Tagger.Clear();
            Die_Timer = 5000;
            Tagged = false;
        }

        ObjectGuid Tagger;
        uint32 Die_Timer;
        bool Tagged;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (Tagged || spell->Id != SPELL_EGAN_BLASTER)
                return;

            Player* player = caster->ToPlayer();
            if (!player || player->GetQuestStatus(QUEST_RESTLESS_SOUL) != QUEST_STATUS_INCOMPLETE)
                return;

            Tagged = true;
            Tagger = caster->GetGUID();
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->CastSpell(summoned, SPELL_SOUL_FREED, false);

            if (Player* player = ObjectAccessor::GetPlayer(*me, Tagger))
                summoned->GetMotionMaster()->MoveFollow(player, 0.0f, 0.0f);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Tagged)
                me->SummonCreature(NPC_FREED, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 300000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                {
                    if (Unit* temp = ObjectAccessor::GetUnit(*me, Tagger))
                    {
                        if (Player* player = temp->ToPlayer())
                            player->KilledMonsterCredit(NPC_RESTLESS, me->GetGUID());
                        me->KillSelf();
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<npc_spectral_ghostly_citizenAI>(creature);
    }

    struct npc_spectral_ghostly_citizenAI : public ScriptedAI
    {
        npc_spectral_ghostly_citizenAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Die_Timer = 5000;
            Tagged = false;
        }

        uint32 Die_Timer;
        bool Tagged;

        void Reset() override
        {
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (!Tagged && spell->Id == SPELL_EGAN_BLASTER)
                Tagged = true;
        }

        void JustDied(Unit* /*killer*/) override
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

        void UpdateAI(uint32 diff) override
        {
            if (Tagged)
            {
                if (Die_Timer <= diff)
                    me->KillSelf();
                else Die_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
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

class spell_ysida_saved_credit : public SpellScript
{
    PrepareSpellScript(spell_ysida_saved_credit);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_YSIDA_SAVED });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj)
        {
            return obj->GetTypeId() != TYPEID_PLAYER;
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitUnit()->ToPlayer())
        {
            player->AreaExploredOrEventHappens(QUEST_DEAD_MAN_PLEA);
            player->KilledMonsterCredit(NPC_YSIDA);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ysida_saved_credit::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_ysida_saved_credit::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_stratholme()
{
    new go_gauntlet_gate();
    new npc_restless_soul();
    new npc_spectral_ghostly_citizen();
    RegisterSpellScript(spell_ysida_saved_credit);
}
