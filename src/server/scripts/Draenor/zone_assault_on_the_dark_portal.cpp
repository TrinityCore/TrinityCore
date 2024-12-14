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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedFollowerAI.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum AssaultOnTheDarkPortalSpells
{
    SPELL_ALTAR_ALTERCATION_CANCEL_AURAS = 167547, // Serverside Spell
    SPELL_BLEEDING_HOLLOW_HOLDOUT        = 164609,
    SPELL_BLEEDING_HOLLOW_KILROGG_REVEAL = 161771,
    SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME = 164611,
    SPELL_BLEEDING_HOLLOW_SNEAKY_ARMY    = 165061,
    SPELL_BLOOD_RITUAL_ORB_BEAM          = 170044,
    SPELL_CANCEL_PHASE_AURA              = 165053,
    SPELL_CANCEL_TRAIL_OF_FLAME_VISUAL   = 165993,
    SPELL_DARK_PORTAL_RUN_AWAY           = 158985,
    SPELL_HUT_CREDIT                     = 164613, // Serverside Spell
    SPELL_ON_ALTAR                       = 161637,
    SPELL_PUSH_ARMY                      = 165072,
    SPELL_TRAIL_OF_FLAME_LARGE           = 165991,
    SPELL_UPDATE_PHASE_SHIFT_PLAYER      = 82238
};

enum AssaultOnTheDarkPortalQuests
{
    QUEST_FLAG_ARMY_PUSHED          = 35297,
    QUEST_ALTAR_ALTERCATION         = 34423,
};

enum AssaultOnTheDarkPortalQuestObjectives
{
    OBJECTIVE_ALTAR_ALTERCATION_SPEAK_WITH_ARIOK    = 273075,
    OBJECTIVE_ALTAR_ALTERCATION_ESCORT_ARIOK        = 273677,
};

enum AssaultOnTheDarkPortalNPCs
{
    NPC_ALTAR_ALTERCATION_ARIOK     = 80087,
    NPC_ALTAR_ALTERCATION_KILROGG   = 81926,
    NPC_BLEEDING_HOLLOW_BLOODCHOSEN = 81895
};

enum AssaultOnTheDarkPortalTexts
{
    // Ariok
    SAY_ARIOK_INTRO_1               = 0,
    SAY_ARIOK_INTRO_2               = 1,
    SAY_ARIOK_INTRO_3               = 2,
    SAY_ARIOK_ON_ALTAR_1            = 3,
    SAY_ARIOK_ON_ALTAR_2            = 4,
    SAY_ARIOK_MIDDLE_ORB_INTERACT   = 5,
    SAY_ARIOK_ALTAR_KILROGG_REVEAL  = 6,

    // Kilrogg
    SAY_KILROGG_WEST_ORB_INTERACT   = 0,
    SAY_KILROGG_ENTER_ALTAR_AT      = 1
};

enum AssaultOnTheDarkPortalActions
{
    ACTION_INTRO        = 1,
    ACTION_ON_ALTAR     = 2
};

enum AssaultOnTheDarkPortalEvents
{
    EVENT_TALK_1 = 1,
    EVENT_TALK_2,
    EVENT_TALK_3,
    EVENT_ALTAR
};

// 621 - Dark Portal: Run away
class scene_dark_portal_run_away : public SceneScript
{
public:
    scene_dark_portal_run_away() : SceneScript("scene_dark_portal_run_away") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_DARK_PORTAL_RUN_AWAY);
        PhasingHandler::OnConditionChange(player);
    }
};

// 34420 - The Cost of War
class quest_the_cost_of_war : public QuestScript
{
public:
    quest_the_cost_of_war() : QuestScript("quest_the_cost_of_war") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveAurasDueToSpell(SPELL_DARK_PORTAL_RUN_AWAY);
            PhasingHandler::OnConditionChange(player);
        }
        else if (newStatus == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, SPELL_DARK_PORTAL_RUN_AWAY, TRIGGERED_FULL_MASK);
            PhasingHandler::OnConditionChange(player);
        }
    }
};

// 34422 - Blaze of Glory
class quest_blaze_of_glory : public QuestScript
{
public:
    quest_blaze_of_glory() : QuestScript("quest_blaze_of_glory") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_HOLDOUT);
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME);
            player->RemoveAurasDueToSpell(SPELL_PUSH_ARMY);
            player->RemoveRewardedQuest(QUEST_FLAG_ARMY_PUSHED);
            PhasingHandler::OnConditionChange(player);
        }
        else if (newStatus == QUEST_STATUS_INCOMPLETE)
            PhasingHandler::OnConditionChange(player);
        else if (newStatus == QUEST_STATUS_COMPLETE)
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME);
    }
};

// 770 - Bleeding Hollow: Holdout
class scene_bleeding_hollow_holdout : public SceneScript
{
public:
    scene_bleeding_hollow_holdout() : SceneScript("scene_bleeding_hollow_holdout") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_HOLDOUT);
        PhasingHandler::OnConditionChange(player);
    }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Push")
            player->CastSpell(player, SPELL_PUSH_ARMY, false);
    }
};

// 771 - Bleeding Hollow: Trail of Flame
class scene_bleeding_hollow_trail_of_flame : public SceneScript
{
    public:
        scene_bleeding_hollow_trail_of_flame() : SceneScript("scene_bleeding_hollow_trail_of_flame") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Visual")
            player->CastSpell(player, SPELL_TRAIL_OF_FLAME_LARGE, true);
        else if (triggerName == "Clear")
            player->CastSpell(player, SPELL_CANCEL_TRAIL_OF_FLAME_VISUAL, true);
        else if (triggerName == "Credit")
            player->CastSpell(player, SPELL_HUT_CREDIT, true);
    }
};

// 34423 - Altar Altercation
class quest_altar_altercation : public QuestScript
{
public:
    quest_altar_altercation() : QuestScript("quest_altar_altercation") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
            player->CastSpell(player, SPELL_ALTAR_ALTERCATION_CANCEL_AURAS, TRIGGERED_FULL_MASK);
    }
};

// 161618 - Summon Ariok
class spell_altar_altercation_summon_ariok : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UPDATE_PHASE_SHIFT_PLAYER });
    }

    void HandleOnCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_UPDATE_PHASE_SHIFT_PLAYER, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_altar_altercation_summon_ariok::HandleOnCast);
    }
};

// 694 - Bleeding Hollow: Kilrogg Reveal
class scene_bleeding_hollow_kilrogg_reveal : public SceneScript
{
public:
    scene_bleeding_hollow_kilrogg_reveal() : SceneScript("scene_bleeding_hollow_kilrogg_reveal") { }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_CANCEL_PHASE_AURA, false);
    }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "FreeCamera")
            player->CastSpell(player, SPELL_CANCEL_PHASE_AURA, false);
    }
};

// 167955 - Destroying
class spell_altar_altercation_destroying : public SpellScript
{
    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitUnit()->ToCreature();
        if (!creature)
            return;

        creature->DespawnOrUnsummon(); // @TODO: Spawntracking should cause despawn for casting player only and respawn on abandon quest
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_altar_altercation_destroying::HandleOnHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 80087 - Ariok
struct npc_altar_altercation_ariok : public FollowerAI
{
    npc_altar_altercation_ariok(Creature* creature) : FollowerAI(creature) { }

    void JustAppeared() override
    {
        DoAction(ACTION_INTRO);

        if (TempSummon const* tempSummon = me->ToTempSummon())
        {
            if (Player* summoner = tempSummon->GetSummoner()->ToPlayer())
            {
                if (!summoner)
                    return;

                StartFollow(summoner);
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INTRO:
            {
                events.ScheduleEvent(EVENT_TALK_1, 1s);
                break;
            }
            case ACTION_ON_ALTAR:
            {
                Talk(SAY_ARIOK_ON_ALTAR_1);
                me->AddUnitState(UNIT_STATE_ROOT);
                events.ScheduleEvent(EVENT_ALTAR, 5s + 400ms);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_1:
                    Talk(SAY_ARIOK_INTRO_1);
                    events.ScheduleEvent(EVENT_TALK_2, 5s + 700ms);
                    break;
                case EVENT_TALK_2:
                    Talk(SAY_ARIOK_INTRO_2);
                    events.ScheduleEvent(EVENT_TALK_3, 7s + 400ms);
                    break;
                case EVENT_TALK_3:
                    Talk(SAY_ARIOK_INTRO_3);
                    break;
                case EVENT_ALTAR:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    Talk(SAY_ARIOK_ON_ALTAR_2);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap events;
};

// 164979 - (Serverside/Non-DB2) Trigger Ariok
class spell_trigger_ariok_altar_altercation : public SpellScript
{
    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitUnit()->ToCreature();

        if (!creature)
            return;

        if (GetCaster()->HasAura(SPELL_BLEEDING_HOLLOW_KILROGG_REVEAL))
        {
            creature->AI()->Talk(SAY_ARIOK_ALTAR_KILROGG_REVEAL);
            creature->DespawnOrUnsummon();
        }
        else if (GetCaster()->HasAura(SPELL_ON_ALTAR))
            creature->AI()->DoAction(ACTION_ON_ALTAR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_trigger_ariok_altar_altercation::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 83670 - Blood Ritual Orb
struct npc_altar_altercation_blood_ritual_orb : public ScriptedAI
{
    npc_altar_altercation_blood_ritual_orb(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (Creature* bloodChosen = me->FindNearestCreature(NPC_BLEEDING_HOLLOW_BLOODCHOSEN, 50.0f))
            me->CastSpell(bloodChosen, SPELL_BLOOD_RITUAL_ORB_BEAM, true);
    }

    void OnSpellClick(Unit* clicker, bool /*spellClickHandled*/) override
    {
        if (me->HasStringId("west_orb"))
        {
            Creature* kilrogg = clicker->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_ALTAR_ALTERCATION_KILROGG, .IgnorePhases = true });
            if (!kilrogg)
                return;

            kilrogg->AI()->Talk(SAY_KILROGG_WEST_ORB_INTERACT, clicker);
        }
        else if (me->HasStringId("middle_orb"))
        {
            Creature* ariok = clicker->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_ALTAR_ALTERCATION_ARIOK, .IsSummon = true, .IgnorePhases = true, .OwnerGuid = clicker->GetGUID() });
            if (!ariok)
                return;

            clicker->CastSpell(clicker, SPELL_BLEEDING_HOLLOW_SNEAKY_ARMY, true);
            ariok->AI()->Talk(SAY_ARIOK_MIDDLE_ORB_INTERACT);
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }
};

// Id - 52
struct at_altar_altercation_kilrogg_talk : AreaTriggerAI
{
    at_altar_altercation_kilrogg_talk(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Creature* kilrogg = unit->FindNearestCreature(NPC_ALTAR_ALTERCATION_KILROGG, 100.0f);
        if (!kilrogg)
            return;

        kilrogg->AI()->Talk(SAY_KILROGG_ENTER_ALTAR_AT, player);
    }
};

// Id - 50
struct at_altar_altercation_reach_altar : AreaTriggerAI
{
    at_altar_altercation_reach_altar(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        if (!player->IsQuestObjectiveComplete(QUEST_ALTAR_ALTERCATION, OBJECTIVE_ALTAR_ALTERCATION_SPEAK_WITH_ARIOK))
            return;

        if (player->IsQuestObjectiveComplete(QUEST_ALTAR_ALTERCATION, OBJECTIVE_ALTAR_ALTERCATION_ESCORT_ARIOK))
            return;

        player->CastSpell(nullptr, SPELL_ON_ALTAR);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_ON_ALTAR);
    }
};

void AddSC_assault_on_the_dark_portal()
{
    new scene_dark_portal_run_away();
    new quest_the_cost_of_war();
    new quest_blaze_of_glory();
    new scene_bleeding_hollow_holdout();
    new scene_bleeding_hollow_trail_of_flame();

    new quest_altar_altercation();
    RegisterSpellScript(spell_altar_altercation_summon_ariok);
    new scene_bleeding_hollow_kilrogg_reveal();
    RegisterSpellScript(spell_altar_altercation_destroying);
    RegisterCreatureAI(npc_altar_altercation_ariok);
    RegisterSpellScript(spell_trigger_ariok_altar_altercation);
    RegisterCreatureAI(npc_altar_altercation_blood_ritual_orb);
    RegisterAreaTriggerAI(at_altar_altercation_kilrogg_talk);
    RegisterAreaTriggerAI(at_altar_altercation_reach_altar);
};
