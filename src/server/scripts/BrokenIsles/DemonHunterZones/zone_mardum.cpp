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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "Creature.h"
#include "GameObject.h"
#include "SceneMgr.h"

enum eQuests
{
    QUEST_INVASION_BEGIN        = 40077,
    QUEST_ASHTONGUE_FORCES      = 40378,
    QUEST_COILSKAR_FORCES       = 40379,
    QUEST_MEETING_WITH_QUEEN    = 39050
};

enum eScenes
{
    SPELL_SCENE_MARDUM_WELCOME          = 193525,
    SPELL_SCENE_MARDUM_LEGION_BANNER    = 191677,
    SPELL_SCENE_MARDUM_ASHTONGUE_FORCES = 189261,
    SPELL_SCENE_MARDUM_COILSKAR_FORCES  = 190793,
    SPELL_SCENE_MEETING_WITH_QUEEN      = 188539,
};

enum ePhases
{
    PHASE_MARDUM_WELCOME        = 50,
    PHASE_MARDUM_AFTER_BANNER   = 51,
    PHASE_MARDUM_FELSABBER      = 52,
};

class PlayerScript_mardum_welcome_scene_trigger : public PlayerScript
{
public:
    PlayerScript_mardum_welcome_scene_trigger() : PlayerScript("PlayerScript_mardum_welcome_scene_trigger") {}

    uint32 checkTimer = 1000;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            if (player->GetZoneId() == 7705 && player->GetQuestStatus(QUEST_INVASION_BEGIN) == QUEST_STATUS_INCOMPLETE &&
                player->GetPositionY() < 3280 && player->HasAura(SPELL_SCENE_MARDUM_WELCOME) &&
                !player->HasInPhaseList(PHASE_MARDUM_WELCOME))
            {
                player->CastSpell(player, SPELL_SCENE_MARDUM_WELCOME, true);
            }

            checkTimer = 1000;
        }
        else checkTimer -= 1000;
    }
};

class scene_mardum_welcome : public SceneScript
{
public:
    scene_mardum_welcome() : SceneScript("scene_mardum_welcome") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->AddPhase(PHASE_MARDUM_WELCOME);
    }
};

class npc_kayn_sunfury_welcome : public CreatureScript
{
public:
    npc_kayn_sunfury_welcome() : CreatureScript("npc_kayn_sunfury_welcome") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_INVASION_BEGIN)
        {
            player->RemovePhase(PHASE_MARDUM_WELCOME);

            // Todo : Make creatures wing out
        }
        return true;
    }
};

class go_mardum_legion_banner_1 : public GameObjectScript
{
public:
    go_mardum_legion_banner_1() : GameObjectScript("go_mardum_legion_banner_1") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_INVASION_BEGIN, 1))
            player->CastSpell(player, SPELL_SCENE_MARDUM_LEGION_BANNER, true);

        return false;
    }
};

class scene_mardum_change_legion_banner : public SceneScript
{
public:
    scene_mardum_change_legion_banner() : SceneScript("scene_mardum_change_legion_banner") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->AddPhase(PHASE_MARDUM_AFTER_BANNER);
    }
};

class go_mardum_portal_ashtongue : public GameObjectScript
{
public:
    go_mardum_portal_ashtongue() : GameObjectScript("go_mardum_portal_ashtongue") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_ASHTONGUE_FORCES, 0))
        {
            player->KilledMonsterCredit(88872); // QUEST_ASHTONGUE_FORCES storageIndex 0 KillCredit
            player->KilledMonsterCredit(97831); // QUEST_ASHTONGUE_FORCES storageIndex 1 KillCredit
            player->CastSpell(player, SPELL_SCENE_MARDUM_ASHTONGUE_FORCES, true);
        }

        return false;
    }
};

class scene_mardum_welcome_ashtongue : public SceneScript
{
public:
    scene_mardum_welcome_ashtongue() : SceneScript("scene_mardum_welcome_ashtongue") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName)
    {
        if (triggerName == "SEEFELSABERCREDIT")
        {
            player->KilledMonsterCredit(101534); // QUEST_ASHTONGUE_FORCES storageIndex 1 KillCredit
        }
        else if (triggerName == "UPDATEPHASE")
        {
            player->AddPhase(PHASE_MARDUM_FELSABBER);
        }
    }
};

class go_mardum_cage : public GameObjectScript
{
public:
    go_mardum_cage(const char* name, uint32 insideNpc, uint32 killCredit = 0) : GameObjectScript(name), _insideNpc(insideNpc), _killCredit(killCredit)
    {
        if (_killCredit == 0)
            _killCredit = insideNpc;
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* npc = go->FindNearestCreature(_insideNpc, 10.0f))
        {
            float x, y, z;
            npc->GetClosePoint(x, y, z, npc->GetObjectSize() / 3, 50.0f);
            npc->GetMotionMaster()->MovePoint(0, x, y, z);
            npc->DespawnOrUnsummon(5000);

            player->KilledMonsterCredit(_killCredit);
        }

        return false;
    }

    uint32 _insideNpc;
    uint32 _killCredit;
};

class npc_mardum_inquisitor_pernissius : public CreatureScript
{
public:
    npc_mardum_inquisitor_pernissius() : CreatureScript("npc_mardum_inquisitor_pernissius") { }

    struct npc_mardum_inquisitor_pernissiusAI : public ScriptedAI
    {
        npc_mardum_inquisitor_pernissiusAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Player*> players;
            me->GetPlayerListInGrid(players, 50.0f);

            for (Player* player : players)
            {
                player->KilledMonsterCredit(105946);
                player->KilledMonsterCredit(96159);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mardum_inquisitor_pernissiusAI(creature);
    }
};

class npc_mardum_ashtongue_mystic : public CreatureScript
{
public:
    npc_mardum_ashtongue_mystic() : CreatureScript("npc_mardum_ashtongue_mystic") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->KilledMonsterCredit(creature->GetEntry());
        creature->KillSelf();
        return true;
    }
};

class go_mardum_portal_coilskar : public GameObjectScript
{
public:
    go_mardum_portal_coilskar() : GameObjectScript("go_mardum_portal_coilskar") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_COILSKAR_FORCES, 0))
        {
            player->KilledMonsterCredit(94406); // QUEST_COILSKAR_FORCES storageIndex 0 KillCredit
            player->KilledMonsterCredit(97831); // QUEST_COILSKAR_FORCES storageIndex 1 KillCredit
            player->CastSpell(player, SPELL_SCENE_MARDUM_COILSKAR_FORCES, true);
        }

        return false;
    }
};

class go_meeting_with_queen_ritual : public GameObjectScript
{
public:
    go_meeting_with_queen_ritual() : GameObjectScript("go_meeting_with_queen_ritual") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_MEETING_WITH_QUEEN, 0))
        {
            player->CastSpell(player, SPELL_SCENE_MEETING_WITH_QUEEN, true);
        }

        return false;
    }
};

class scene_mardum_meeting_with_queen : public SceneScript
{
public:
    scene_mardum_meeting_with_queen() : SceneScript("scene_mardum_meeting_with_queen") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->KilledMonsterCredit(100722);
    }
};

void AddSC_mardum()
{
    new PlayerScript_mardum_welcome_scene_trigger();
    new scene_mardum_welcome();
    new npc_kayn_sunfury_welcome();
    new go_mardum_legion_banner_1();
    new scene_mardum_change_legion_banner();
    new go_mardum_portal_ashtongue();
    new scene_mardum_welcome_ashtongue();
    new go_mardum_cage("go_mardum_cage_belath",     94400);
    new go_mardum_cage("go_mardum_cage_cyana",      94377);
    new go_mardum_cage("go_mardum_cage_izal",       93117);
    new go_mardum_cage("go_mardum_cage_mannethrel", 93230);
    new npc_mardum_inquisitor_pernissius();
    new npc_mardum_ashtongue_mystic();
    new go_mardum_portal_coilskar();
    new go_meeting_with_queen_ritual();
    new scene_mardum_meeting_with_queen();
}
