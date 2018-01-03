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

#include "GameObject.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

/*
 * Dalaran above Karazhan
 *
 * Legion Intro
 */

enum
{
    PHASE_DALARAN_KARAZHAN  = 5829,

    // True if one of two "In the Blink of an Eye" quests is rewarded
    PLAYERCONDITION_QUEST   = 45040
};

// 228330 - Téléportation
class spell_dalaran_teleportation : public SpellScriptLoader
{
public:
    spell_dalaran_teleportation() : SpellScriptLoader("spell_dalaran_teleportation") { }

    class spell_dalaran_teleportation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dalaran_teleportation_SpellScript);

        void EffectTeleportDalaranKarazhan(SpellEffIndex effIndex)
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (player->MeetPlayerCondition(PLAYERCONDITION_QUEST))
                    PreventHitEffect(effIndex);
        }

        void EffectTeleportDalaranLegion(SpellEffIndex effIndex)
        {
            if (Player* player = GetCaster()->ToPlayer())
                if (!player->MeetPlayerCondition(PLAYERCONDITION_QUEST))
                    PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_dalaran_teleportation_SpellScript::EffectTeleportDalaranKarazhan, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHitTarget += SpellEffectFn(spell_dalaran_teleportation_SpellScript::EffectTeleportDalaranLegion, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dalaran_teleportation_SpellScript();
    }
};

// 246854
class go_dalaran_karazhan : public GameObjectScript
{
public:
    go_dalaran_karazhan() : GameObjectScript("go_dalaran_karazhan") { }

    // This is also called on object Creation. Set dalaran to active to enable far sight
    void OnGameObjectStateChanged(GameObject* go, uint32 /*state*/) override
    {
        if (!go->isActiveObject())
            go->setActive(true);
    }
};

// 113986 - Khadgar
class npc_dalaran_karazhan_khadgar : public CreatureScript
{
public:
    npc_dalaran_karazhan_khadgar() : CreatureScript("npc_dalaran_karazhan_khadgar") { }

    enum
    {
        SPELL_PLAY_DALARAN_TELEPORTATION_SCENE = 227861
    };

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction) override
    {
        if (uiAction == 1)
            player->CastSpell(player, SPELL_PLAY_DALARAN_TELEPORTATION_SCENE, true);

        return true;
    }
};

class scene_dalaran_kharazan_teleportion : public SceneScript
{
public:
    scene_dalaran_kharazan_teleportion() : SceneScript("scene_dalaran_kharazan_teleportion") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName)
    {
        if (triggerName == "invisibledalaran")
            player->SetInPhase(PHASE_DALARAN_KARAZHAN, true, false);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        CompleteScene(player);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        CompleteScene(player);
    }

    void CompleteScene(Player* player)
    {
        player->KilledMonsterCredit(114506);
        player->TeleportTo(1220, -827.82f, 4369.25f, 738.64f, 1.893364f);
    }
};

/*
 * Legion Dalaran
 */

class OnLegionArrival : public PlayerScript
{
public:
    OnLegionArrival() : PlayerScript("OnLegionArrival") { }

    enum
    {
        SPELL_MAGE_LEARN_GUARDIAN_HALL_TP   = 204287,
        SPELL_WAR_LEARN_JUMP_TO_SKYHOLD     = 192084,
        SPELL_CREATE_CLASS_HALL_ALLIANCE    = 185506,
        SPELL_CREATE_CLASS_HALL_HORDE       = 192191,
    };

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->getLevel() == 100)
        {
            if (player->getClass() == CLASS_MAGE)
                player->CastSpell(player, SPELL_MAGE_LEARN_GUARDIAN_HALL_TP, true);
            else if (player->getClass() == CLASS_WARRIOR)
                player->CastSpell(player, SPELL_WAR_LEARN_JUMP_TO_SKYHOLD, true);

            player->CastSpell(player, player->IsInAlliance() ? SPELL_CREATE_CLASS_HALL_ALLIANCE : SPELL_CREATE_CLASS_HALL_HORDE, true);
        }
    }
};

void AddSC_dalaran_legion()
{
    new spell_dalaran_teleportation();
    new go_dalaran_karazhan();
    new npc_dalaran_karazhan_khadgar();
    new scene_dalaran_kharazan_teleportion();
    new OnLegionArrival();
}
