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
#include "ScriptMgr.h"
#include "Containers.h"
#include "Player.h"
#include "Spell.h"
#include "SpellScript.h"
#include "Log.h"

enum DracthyrLoginSpells
{
    // Spells
    SPELL_DRACTHYR_LOGIN                = 369728, // teleports to random room, plays scene for the room, binds the home position
    SPELL_STASIS_1                      = 369735, // triggers 366620
    SPELL_STASIS_2                      = 366620, // triggers 366636
    SPELL_STASIS_3                      = 366636, // removes 365560, sends first quest (64864)
    SPELL_STASIS_4                      = 365560, // freeze the target
    SPELL_DRACTHYR_MOVIE_ROOM_01        = 394245, // scene for room 1
    SPELL_DRACTHYR_MOVIE_ROOM_02        = 394279, // scene for room 2
    SPELL_DRACTHYR_MOVIE_ROOM_03        = 394281, // scene for room 3
    SPELL_DRACTHYR_MOVIE_ROOM_04        = 394282, // scene for room 4
    //SPELL_DRACTHYR_MOVIE_ROOM_05        = 394283, // scene for room 5 (only plays sound, unused?)
    SPELL_MAINTAIN_DERVISHIAN           = 369731, // Alliance Personal Summon
    SPELL_MAINTAIN_KODETHI              = 370112, // Horde Personal Summon
    SPELL_AWAKEN_DRACTYHR_QUEST_ABANDON = 369744,
    SPELL_STASIS_FEEDBACK_KNOCKBACK     = 364074,
    SPELL_STASIS_FEEDBACK_VISUAL        = 374633
};

struct DracthyrLoginRoom
{
    uint32 MovieSpellId;
    Position PlayerPosition;
    Position SummonPosition;
};

std::array<DracthyrLoginRoom, 4> LoginRoomData =
{
    {
        {
            SPELL_DRACTHYR_MOVIE_ROOM_01,
            { 5725.32f, -3024.26f, 251.047f, 0.01745329238474369f },
            { 5739.97216796875f, -3023.970458984375f, 251.172332763671875f, 3.193952560424804687f }
        },
        {
            SPELL_DRACTHYR_MOVIE_ROOM_02,
            { 5743.03f, -3067.28f, 251.047f, 0.798488140106201171f },
            { 5754.3046875f, -3056.34716796875f, 251.1725006103515625f, 3.926990747451782226f }
        },
        {
            SPELL_DRACTHYR_MOVIE_ROOM_03,
            { 5787.1597f, -3083.3906f, 251.04698f, 1.570796370506286621f },
            { 5787.44970703125f, -3069.335205078125f, 251.168121337890625f, 4.729842185974121093f }
        },
        {
            SPELL_DRACTHYR_MOVIE_ROOM_04,
            { 5829.32f, -3064.49f, 251.047f, 2.364955902099609375f },
            { 5818.533203125f, -3054.5625f, 251.3630828857421875f, 5.480333805084228515f }
        }
    }
};

// 369728 - Dracthyr Login
// 369744 - Awaken, Dracthyr OnquestAbandon
class spell_dracthyr_login : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRACTHYR_MOVIE_ROOM_01, SPELL_DRACTHYR_MOVIE_ROOM_02, SPELL_DRACTHYR_MOVIE_ROOM_03, SPELL_DRACTHYR_MOVIE_ROOM_04 });
    }

    void HandleTeleport(SpellEffIndex /*effIndex*/)
    {
        DracthyrLoginRoom const& room = LoginRoomData[urand(0, 3)];

        WorldLocation dest = GetHitUnit()->GetWorldLocation();
        SetExplTargetDest(dest);

        GetHitDest()->Relocate(room.PlayerPosition);

        GetCaster()->CastSpell(GetHitUnit(), room.MovieSpellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dracthyr_login::HandleTeleport, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

// 3730 - Dracthyr Evoker Intro (Post Movie)
class scene_dracthyr_evoker_intro : public SceneScript
{
public:
    scene_dracthyr_evoker_intro() : SceneScript("scene_dracthyr_evoker_intro") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_STASIS_1, true);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_STASIS_1, true);
    }
};

// 369730 - Summon Dervishian
// 370111 - Summon Kodethi
class spell_dracthyr_summon_dervishian : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        float currentDist = 1000.0f;
        DracthyrLoginRoom const* currentRoom = nullptr;

        for (DracthyrLoginRoom const& room : LoginRoomData)
        {
            float dist = GetCaster()->GetDistance(room.PlayerPosition);
            if (dist < currentDist)
            {
                currentDist = dist;
                currentRoom = &room;
            }
        }
        if (!currentRoom)
            return;

        dest.Relocate(currentRoom->SummonPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_dracthyr_summon_dervishian::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// 64864 - Awaken, Dracthyr
class quest_awaken_dracthyr : public QuestScript
{
public:
    quest_awaken_dracthyr() : QuestScript("quest_awaken_dracthyr") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
            player->CastSpell(player, SPELL_AWAKEN_DRACTYHR_QUEST_ABANDON, false);
    }
};

// 30308 - Stasis Feedback
struct at_dracthyr_stasis_feedback : AreaTriggerAI
{
    at_dracthyr_stasis_feedback(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(nullptr, SPELL_STASIS_FEEDBACK_KNOCKBACK, false);
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(caster->GetPosition(), SPELL_STASIS_FEEDBACK_VISUAL, true);
    }
};

void AddSC_zone_the_forbidden_reach()
{
    RegisterSpellScript(spell_dracthyr_login);
    new scene_dracthyr_evoker_intro();
    RegisterSpellScript(spell_dracthyr_summon_dervishian);
    new quest_awaken_dracthyr();
    RegisterAreaTriggerAI(at_dracthyr_stasis_feedback);
}
