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

#include "Conversation.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum MardumSpellData
{
    SPELL_START_DEMON_HUNTER_PLAY_SCENE = 193525
};

enum MardumQuestData
{
    QUEST_DEMON_HUNTER_INTRO_TRACKER    = 40076
};

enum MardumConversationData
{
    CONVO_DEMONHUNTER_INTRO_START       = 705
};

class scene_demonhunter_intro : public SceneScript
{
public:
    scene_demonhunter_intro() : SceneScript("scene_demonhunter_intro") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Conversation::CreateConversation(CONVO_DEMONHUNTER_INTRO_START, player, *player, player->GetGUID(), nullptr);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::OnConditionChange(player);
    }
};

// 196030 - Start: Quest Invis
class spell_demon_hunter_intro_aura : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_START_DEMON_HUNTER_PLAY_SCENE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_demon_hunter_intro_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_zone_mardum()
{
    // Scene
    new scene_demonhunter_intro();

    // Spells
    RegisterSpellScript(spell_demon_hunter_intro_aura);
};
