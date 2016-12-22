/*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "Player.h"

enum MardumBroadcastTexts
{
    CREATURE_TEXT_ZERO,
    CREATURE_TEXT_ONE,
    CREATURE_TEXT_TWO,
};

enum MardumQuests
{
    QUEST_ENTER_THE_ILLIDARI_ASHTONGUE = 40378,
    QUEST_ENTER_THE_ILLIDARI_COILSKAR  = 40379,
    QUEST_ENTER_THE_ILLIDARI_SHIVARRA  = 38765,
    QUEST_EYE_ON_THE_PRIZE             = 39049,
    QUEST_BEFORE_WE_RE_OVERRUN         = 38766
};

enum MardumQuestObjectives
{
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_ASHTONGUE = 280769,
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_COILSKAR  = 280773,
    OBJECTIVE_FIRST_SUMMONED_GUARDIAN_SHIVARRA  = 280115,
    OBJECTIVE_FIND_ALLARI                       = 281030,
};

enum MardumCreatures
{
    CREATURE_FIRST_SUMMONED_GUARDIAN     = 97831,
    CREATURE_ALLARI_THE_SOULEATER        = 94410,
    CREATURE_ASHTONGUE_MYSTIC            = 99914,
    CREATURE_COLOSSAL_ELEMENTAL          = 96159,
    CREATURE_EYE_ON_THE_PRIZE_CREDIT     = 105946,
    CREATURE_BEFORE_WE_RE_OVERRUN_CREDIT = 106003,
    CREATURE_SEVIS_BRIGHTFLAME           = 99915
};

enum MardumSpells
{
    SPELL_SACRIFICING_MYSTICS_SOUL = 196724,
    SPELL_EYE_BEAM                 = 198013,
    SPELL_LEARN_EYE_BEAM           = 195447,
    SPELL_CONSUME_MAGIC            = 183752,
    SPELL_LEARN_CONSUME_MAGIC      = 195439,
    SPELL_SEVIS_SACRIFICE_ME       = 196735,
    SPELL_SACRIFICING_SEVIS        = 196731,
};

class npc_sevis_brightflame_1 : public CreatureScript
{
public:
    npc_sevis_brightflame_1() : CreatureScript("npc_sevis_brightflame_1") { }

    struct npc_sevis_brightflame_1AI : public ScriptedAI
    {
        npc_sevis_brightflame_1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_INCOMPLETE)
                {
                    Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE);
                    if (!qInfo)
                        return;

                    for (QuestObjective const& obj : qInfo->GetObjectives())
                    {
                        if (obj.ID == OBJECTIVE_FIRST_SUMMONED_GUARDIAN_ASHTONGUE)
                            if (!player->IsQuestObjectiveComplete(qInfo, obj))
                            {
                                Talk(CREATURE_TEXT_ZERO, who);
                                player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                            }
                    }
                    
                }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_1AI(creature);
    }
};

class npc_sevis_brightflame_2 : public CreatureScript
{
public:
    npc_sevis_brightflame_2() : CreatureScript("npc_sevis_brightflame_2") { }

    struct npc_sevis_brightflame_2AI : public ScriptedAI
    {
        npc_sevis_brightflame_2AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_COILSKAR) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_COILSKAR) == QUEST_STATUS_INCOMPLETE)
                {
                    Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_ENTER_THE_ILLIDARI_COILSKAR);
                    if (!qInfo)
                        return;

                    for (QuestObjective const& obj : qInfo->GetObjectives())
                    {
                        if (obj.ID == OBJECTIVE_FIRST_SUMMONED_GUARDIAN_COILSKAR)
                            if (!player->IsQuestObjectiveComplete(qInfo, obj))
                            {
                                Talk(CREATURE_TEXT_ZERO, who);
                                Talk(CREATURE_TEXT_ONE, who);
                                player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                            }
                    }

                }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_2AI(creature);
    }
};

class npc_sevis_brightflame_3 : public CreatureScript
{
public:
    npc_sevis_brightflame_3() : CreatureScript("npc_sevis_brightflame_3") { }

    struct npc_sevis_brightflame_3AI : public ScriptedAI
    {
        npc_sevis_brightflame_3AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (me->IsWithinDistInMap(who, 15.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_SHIVARRA) == QUEST_STATUS_INCOMPLETE)
                {
                    Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_ENTER_THE_ILLIDARI_SHIVARRA);
                    if (!qInfo)
                        return;

                    for (QuestObjective const& obj : qInfo->GetObjectives())
                    {
                        if (obj.ID == OBJECTIVE_FIRST_SUMMONED_GUARDIAN_SHIVARRA)
                            if (!player->IsQuestObjectiveComplete(qInfo, obj))
                            {
                                Talk(CREATURE_TEXT_ZERO, who);
                                player->KilledMonsterCredit(CREATURE_FIRST_SUMMONED_GUARDIAN);
                            }
                    }

                }
        }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == 19133 && gossipListId == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                // Personal Spawn Part Missing
                player->CastSpell(me->ToCreature(), SPELL_SACRIFICING_SEVIS);
            }

            if (menuId == 19132 && gossipListId == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                // Personal Spawn Part Missing
                player->CastSpell(player, SPELL_SEVIS_SACRIFICE_ME);
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sevis_brightflame_3AI(creature);
    }
};

class npc_allari_the_souleater_1 : public CreatureScript
{
public:
    npc_allari_the_souleater_1() : CreatureScript("npc_allari_the_souleater_1") { }

    struct npc_allari_the_souleater_1AI : public ScriptedAI
    {
        npc_allari_the_souleater_1AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (!player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_INCOMPLETE)
                {
                    Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE);
                    if (!qInfo)
                        return;

                    for (QuestObjective const& obj : qInfo->GetObjectives())
                    {
                        if (obj.ID == OBJECTIVE_FIND_ALLARI)
                            if (!player->IsQuestObjectiveComplete(qInfo, obj))
                                player->KilledMonsterCredit(CREATURE_ALLARI_THE_SOULEATER);
                    }

                    if (me->IsWithinDistInMap(who, 20.0f) && !player->GetQuestRewardStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) && player->GetQuestStatus(QUEST_ENTER_THE_ILLIDARI_ASHTONGUE) == QUEST_STATUS_COMPLETE)
                        Talk(CREATURE_TEXT_ZERO, who);
                }
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_allari_the_souleater_1AI(creature);
    }
};

class npc_ashtongue_mystic_sacrifice : public CreatureScript
{
public:
    npc_ashtongue_mystic_sacrifice() : CreatureScript("npc_ashtongue_mystic_sacrifice") { }

    struct npc_ashtongue_mystic_sacrificeAI : public ScriptedAI
    {
        npc_ashtongue_mystic_sacrificeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override { }

        void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (gossipListId == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                // Personal Spawn Part Missing
                player->CastSpell(player, SPELL_SACRIFICING_MYSTICS_SOUL);
            }
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ashtongue_mystic_sacrificeAI(creature);
    }
};

class npc_inquisitor_baleful : public CreatureScript
{
public:
    npc_inquisitor_baleful() : CreatureScript("npc_inquisitor_baleful") { }

    struct npc_inquisitor_balefulAI : public ScriptedAI
    {
        npc_inquisitor_balefulAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override 
        { 
            Talk(CREATURE_TEXT_ZERO);
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void JustDied(Unit* killer) override
        {
            Talk(CREATURE_TEXT_ONE);

            if (Player* player = killer->ToPlayer())
                if (!player->HasSpell(SPELL_EYE_BEAM) && !player->GetQuestRewardStatus(QUEST_EYE_ON_THE_PRIZE) && player->GetQuestStatus(QUEST_EYE_ON_THE_PRIZE) == QUEST_STATUS_INCOMPLETE)
                {
                    // must be different
                    player->CastSpell(player, SPELL_LEARN_EYE_BEAM);
                    player->KilledMonsterCredit(CREATURE_COLOSSAL_ELEMENTAL);
                    player->KilledMonsterCredit(CREATURE_EYE_ON_THE_PRIZE_CREDIT);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            // Totaly missing yet
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_inquisitor_balefulAI(creature);
    }
};

class npc_doom_commander_beliash : public CreatureScript
{
public:
    npc_doom_commander_beliash() : CreatureScript("npc_doom_commander_beliash") { }

    struct npc_doom_commander_beliashAI : public ScriptedAI
    {
        npc_doom_commander_beliashAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
        }

        void Reset() override
        {
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(CREATURE_TEXT_ZERO);
        }

        void SpellHit(Unit* Caster, const SpellInfo* Spell) override
        {
        }

        void JustDied(Unit* killer) override
        {
            Talk(CREATURE_TEXT_ONE);

            if (Player* player = killer->ToPlayer())
                if (!player->HasSpell(SPELL_CONSUME_MAGIC) && !player->GetQuestRewardStatus(QUEST_BEFORE_WE_RE_OVERRUN) && player->GetQuestStatus(QUEST_BEFORE_WE_RE_OVERRUN) == QUEST_STATUS_INCOMPLETE)
                {
                    // must be different
                    player->CastSpell(player, SPELL_LEARN_CONSUME_MAGIC);
                    player->KilledMonsterCredit(CREATURE_BEFORE_WE_RE_OVERRUN_CREDIT);
                }
        }

        void UpdateAI(uint32 diff) override
        {
            // Totaly missing yet
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_doom_commander_beliashAI(creature);
    }
};

class spell_sacrificing_mystics_soul : public SpellScriptLoader
{
public:
    spell_sacrificing_mystics_soul() : SpellScriptLoader("spell_sacrificing_mystics_soul") { }

    class spell_sacrificing_mystics_soul_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sacrificing_mystics_soul_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                player->KilledMonsterCredit(CREATURE_ASHTONGUE_MYSTIC);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_sacrificing_mystics_soul_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sacrificing_mystics_soul_SpellScript();
    }

};

class spell_sevis_sacrifice_me : public SpellScriptLoader
{

public:
    spell_sevis_sacrifice_me() : SpellScriptLoader("spell_sevis_sacrifice_me") { }

    class spell_sevis_sacrifice_me_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sevis_sacrifice_me_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                // probably shall be granted by Personal Spawn
                player->KilledMonsterCredit(CREATURE_SEVIS_BRIGHTFLAME);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_sevis_sacrifice_me_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_sevis_sacrifice_me_SpellScript();
    }

};

class spell_enter_the_illidari_shivarra_sacrificing_sevis : public SpellScriptLoader
{

public:
    spell_enter_the_illidari_shivarra_sacrificing_sevis() : SpellScriptLoader("spell_enter_the_illidari_shivarra_sacrificing_sevis") { }

    class spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript);

        void HandleEvent(SpellEffIndex /* index */)
        {
            if (Player* player = GetCaster()->ToPlayer())
                // probably shall be granted by Personal Spawn
                player->KilledMonsterCredit(CREATURE_SEVIS_BRIGHTFLAME);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_enter_the_illidari_shivarra_sacrificing_sevis_SpellScript();
    }

};

void AddSC_zone_mardum()
{
    new npc_sevis_brightflame_1;
    new npc_sevis_brightflame_2;
    new npc_sevis_brightflame_3;
    new npc_allari_the_souleater_1;
    new npc_ashtongue_mystic_sacrifice;
    new npc_inquisitor_baleful;
    new npc_doom_commander_beliash;
    new spell_sacrificing_mystics_soul;
    new spell_sevis_sacrifice_me;
    new spell_enter_the_illidari_shivarra_sacrificing_sevis;
}
