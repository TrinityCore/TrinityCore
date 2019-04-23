/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "WodGarrison.h"

enum
{
    QUEST_THE_HOME_OF_THE_FROSTWOLFES   = 33868,
    QUEST_A_SONG_OF_FROST_AND_FIRE      = 33815,
    QUEST_OF_WOLFES_AND_WARRIORS        = 34402,

    QUEST_ESTABLISH_YOUR_GARRISON       = 34378,
};

enum
{
    SpellEarthrendingSlam = 165907,
    SpellRampage          = 148852
};

enum
{
    EventEarthrendingSlam = 1,
    EventRampage          = 2,
};

enum
{
    NPC_DUROTAN_BEGIN                       = 78272,
    NPC_OF_WOLFES_AND_WARRIOR_KILL_CREDIT   = 78407,
    NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT = 79757,
};

enum
{
    SCENE_LANDING_TO_TOP_OF_HILL    = 771,
    SCENE_TOP_OF_HILL_TO_GARRISON   = 778,
    SCENE_PORTAL_OPENING            = 789,
    SCENE_DUROTAN_DEPARTS           = 798,
};

/// Passive Scene Object
class playerScript_frostridge_landing_to_hill : public PlayerScript
{
public:
    playerScript_frostridge_landing_to_hill() : PlayerScript("playerScript_frostridge_landing_to_hill") { }

    void OnSceneTriggerEvent(Player* player, uint32 p_SceneInstanceID, std::string p_Event) override
    {
        if (!player->GetSceneMgr().HasScene(p_SceneInstanceID, SCENE_LANDING_TO_TOP_OF_HILL))
            return;

        if (p_Event == "durotanIntroduced")
        {
            if (Creature* durotan = player->FindNearestCreature(NPC_DUROTAN_BEGIN, 50.0f))
                durotan->AI()->Talk(0);

            player->KilledMonsterCredit(NPC_DUROTAN_BEGIN);
        }
    }
};

/// Passive Scene Object
class playerScript_frostridge_hill_to_garrison : public PlayerScript
{
public:
    playerScript_frostridge_hill_to_garrison() : PlayerScript("playerScript_frostridge_hill_to_garrison") { }

    void OnSceneComplete(Player* player, uint32 p_SceneInstanceId) override
    {
        if (!player->GetSceneMgr().HasScene(p_SceneInstanceId, SCENE_TOP_OF_HILL_TO_GARRISON))
            return;

        player->KilledMonsterCredit(NPC_OF_WOLFES_AND_WARRIOR_KILL_CREDIT);
    }
};

// 76411 - Drek'Thar - Début Givrefeu
class npc_drekthar_frostridge_begin : public CreatureScript
{
public:
    npc_drekthar_frostridge_begin() : CreatureScript("npc_drekthar_frostridge_begin") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_A_SONG_OF_FROST_AND_FIRE)
        {
            player->GetSceneMgr().PlaySceneByPackageId(SCENE_LANDING_TO_TOP_OF_HILL);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drekthar_frostridge_beginAI(creature);
    }

    struct npc_drekthar_frostridge_beginAI : public ScriptedAI
    {
        npc_drekthar_frostridge_beginAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 waitTime;

        void Reset() override
        {
            waitTime = 1000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (waitTime > diff)
            {
                waitTime -= diff;
                return;
            }

            waitTime = 1000;

            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 30.0f);

            for (Player* player : playerList)
            {
                if (player->GetQuestStatus(QUEST_THE_HOME_OF_THE_FROSTWOLFES) != QUEST_STATUS_NONE)
                    continue;

                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_HOME_OF_THE_FROSTWOLFES))
                    player->AddQuestAndCheckCompletion(quest, me);
            }
        }
    };
};

// 78272 - Durotan - Début Givrefeu
class npc_durotan_frostridge_begin : public CreatureScript
{
public:
    npc_durotan_frostridge_begin() : CreatureScript("npc_durotan_frostridge_begin") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_OF_WOLFES_AND_WARRIORS)
        {
            player->GetSceneMgr().PlaySceneByPackageId(SCENE_TOP_OF_HILL_TO_GARRISON);
        }

        return true;
    }
};

// Revendication 169421
class spell_frostridge_claiming : public SpellScriptLoader
{
public:
    spell_frostridge_claiming() : SpellScriptLoader("spell_frostridge_claiming") { }

    class spell_frostridge_claiming_spellscript : public SpellScript
    {
        PrepareSpellScript(spell_frostridge_claiming_spellscript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            Player* player = GetCaster()->ToPlayer();

            if (!player)
                return;

            player->GetSceneMgr().PlaySceneByPackageId(SCENE_PORTAL_OPENING);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_frostridge_claiming_spellscript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_frostridge_claiming_spellscript();
    }
};

// 233664 - Niveau de Geomètre
class go_frostridge_master_surveyor : public GameObjectScript
{
public:
    go_frostridge_master_surveyor() : GameObjectScript("go_frostridge_master_surveyor") { }

    struct go_frostridge_master_surveyorAI : public GameObjectAI
    {
        go_frostridge_master_surveyorAI(GameObject* p_Go) : GameObjectAI(p_Go)
        {
            waitTimer = 1000;
        }

        enum
        {
            SPELL_CREATE_GARRISON_HORDE = 160767,
        };

        uint32 waitTimer;

        void UpdateAI(uint32 diff) override
        {
            if (waitTimer > diff)
            {
                waitTimer -= diff;
                return;
            }

            waitTimer = 1000;

            std::list<Player*> playerList;
            go->GetPlayerListInGrid(playerList, 10.0f);

            for (Player* player : playerList)
            {
                if (player->GetQuestStatus(QUEST_ESTABLISH_YOUR_GARRISON) != QUEST_STATUS_INCOMPLETE &&
                    player->GetQuestStatus(QUEST_ESTABLISH_YOUR_GARRISON) != QUEST_STATUS_COMPLETE)
                    continue;

                if (!player->GetGarrison(GARRISON_TYPE_GARRISON))
                {
                    player->CastSpell(player, SPELL_CREATE_GARRISON_HORDE, true);

                    if (Garrison* garr = player->GetGarrison(GARRISON_TYPE_GARRISON))
                    {
                        garr->ToWodGarrison()->TeleportOwnerAndPlayMovie();
                        player->KilledMonsterCredit(NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT);
                    }
                }
            }
        }

    };

    GameObjectAI* GetAI(GameObject* p_Go) const override
    {
        return new go_frostridge_master_surveyorAI(p_Go);
    }
};

// 80167 - Groog
class npc_groog : public CreatureScript
{
    public:
        npc_groog() : CreatureScript("npc_groog") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_groogAI(creature);
        }

        struct npc_groogAI : public ScriptedAI
        {
            npc_groogAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            void Reset() override
            {
                me->setFaction(14);
            }

            void EnterCombat(Unit* /*p_Victim*/) override
            {
                m_Events.Reset();

                m_Events.ScheduleEvent(EventEarthrendingSlam, 3000);
                m_Events.ScheduleEvent(EventRampage, 7000);
            }

            void UpdateAI(uint32 diff) override
            {
                m_Events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) || !UpdateVictim())
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case EventEarthrendingSlam:
                        me->CastSpell(me, SpellEarthrendingSlam, false);
                        m_Events.ScheduleEvent(EventEarthrendingSlam, 15000);
                        break;
                    case EventRampage:
                        me->AddAura(SpellRampage, me);
                        m_Events.ScheduleEvent(EventRampage, 15000);
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };
};

/// Rampage - 148852
class spell_groog_rampage : public SpellScriptLoader
{
    public:
        spell_groog_rampage() : SpellScriptLoader("spell_groog_rampage") { }

        class spell_groog_rampage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_groog_rampage_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                Unit* caster = GetCaster();

                if (!caster)
                    return;

                PreventDefaultAction();

                std::list<Player*> playerList;
                caster->GetPlayerListInGrid(playerList, 2.0f);

                caster->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);

                for (Player* player : playerList)
                {
                    if (player->HasUnitState(UNIT_STATE_ROOT))
                        continue;

                    player->KnockbackFrom(player->m_positionX, player->m_positionY, 10.0f, 10.0f);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_groog_rampage_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_groog_rampage_AuraScript();
        }
};

void AddSC_frostfire_ridge()
{
    /* BEGIN */
    new playerScript_frostridge_landing_to_hill();
    new playerScript_frostridge_hill_to_garrison();

    new npc_drekthar_frostridge_begin();
    new npc_durotan_frostridge_begin();

    new go_frostridge_master_surveyor();

    new spell_frostridge_claiming();

    /* BOSS */
    new npc_groog();
    new spell_groog_rampage();
}
