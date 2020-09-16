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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Group.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Points
{
    POINT_NONE                      = 0,
    POINT_ID_TORG_DRAKEFLAYER_INTRO = 1,
    POINT_ID_SULLY_KNEECAPPER_INTRO = 1,
};

enum TwilightHightlandsArena
{
    // Quests
    QUEST_ID_COC_THE_BLOODEYE_BRUISER   = 27863,
    QUEST_ID_COC_THE_DEADLY_DRAGONMAW   = 27864,
    QUEST_ID_COC_THE_WAYWARD_WILDHAMMER = 27865,
    QUEST_ID_COC_CALDERS_CREATION       = 27866,

    // Events
    EVENT_SAY_REMEMBER = 1,
    EVENT_ANNOUNCE_BATTLE_1,
    EVENT_SUMMON_HURP_DERP,

    EVENT_ANNOUNCE_BATTLE_2_ALLIANCE,
    EVENT_SUMMON_TORG_DRAKEFLAYER,

    EVENT_ANNOUNCE_BATTLE_2_HORDE,
    EVENT_SUMMON_SULLY_KNEECAPPER,

    EVENT_ANNOUNCE_BATTLE_3,
    EVENT_SUMMON_CADAVER_COLLAGE,


    // Texts
    SAY_REMEMBER                    = 0,
    // Hurp'Derp
    SAY_INTRO_BATTLE_1              = 1,
    SAY_START_BATTLE_1              = 2,
    SAY_HURP_DERP_DEFEATED          = 3,
    // Torg Drakeflayer
    SAY_INTRO_BATTLE_2_ALLIANCE     = 4,
    SAY_TORG_DRAKEFLAYER_DEFEATED   = 5,
    // Sully Kneedcapper
    SAY_INTRO_BATTLE_2_HORDE        = 6,
    SAY_START_BATTLE_2_HORDE        = 7,
    SAY_SULLY_KNEECAPPER_DEFEATED   = 8,
    // Cadaver Collage
    SAY_INTRO_BATTLE_3              = 9,
    SAY_START_BATTLE_3              = 10,
    SAY_CADAVER_COLLAGE_DEFEATED    = 11,

    // Creatures
    NPC_HURP_DERP                   = 46944,
    NPC_TORG_DRAKEFLAYER            = 46945,
    NPC_SULLY_KNEECAPPER            = 46946,
    NPC_CADAVER_COLLAGE             = 46947,
};

Position const HurpDerpSpawnPosition        = { -4133.8647f, -5192.587f,    -9.481462f, 2.447715520858764648f };
Position const HurpDerpMovePosition         = { -4182.394f,  -5148.4478f,   -7.7360706f };
Position const TorgDrakeflayerSpawnPosition = { -4136.02f,   -5137.94f,     40.58253f, 3.379617214202880859 };
Position const TorgDrakeflayerJumpPosition  = { -4168.87f,   -5145.91f,     -7.73344f };
Position const SullyKneecapperSpawnPosition = { -4235.0522f, -5133.8877f,   -4.938032f, 5.69227f };
Position const CadaverCollageSpawnPosition  = { -4165.78f,   -5095.76f,     -11.078667f, 3.8550262451171875f };
Position const CadaverCollageMovePosition   = { -4182.644f,  -5148.0923f,   -7.736145f };

// 46935 - Gurgthock
struct npc_th_gurgthock : public ScriptedAI
{
    npc_th_gurgthock(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (!_playerGUID.IsEmpty())
            return;

        _playerGUID = player->GetGUID();
        me->setActive(true);
        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        _events.ScheduleEvent(EVENT_SAY_REMEMBER, 1ms);

        switch (quest->GetQuestId())
        {
            case QUEST_ID_COC_THE_BLOODEYE_BRUISER:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_1, 8s + 500ms);
                break;
            case QUEST_ID_COC_THE_DEADLY_DRAGONMAW:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_2_ALLIANCE, 8s + 500ms);
                break;
            case QUEST_ID_COC_THE_WAYWARD_WILDHAMMER:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_2_HORDE, 6s);
                break;
            case QUEST_ID_COC_CALDERS_CREATION:
                _events.ScheduleEvent(EVENT_ANNOUNCE_BATTLE_3, 10s);
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        // Summon has been defeated. Enable Questgiver and complete quest for killer's group
        summon->DespawnOrUnsummon(3s);

        switch (summon->GetEntry())
        {
            case NPC_HURP_DERP:
                Talk(SAY_HURP_DERP_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_BLOODEYE_BRUISER);
                break;
            case NPC_TORG_DRAKEFLAYER:
                Talk(SAY_TORG_DRAKEFLAYER_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_DEADLY_DRAGONMAW);
                break;
            case NPC_SULLY_KNEECAPPER:
                Talk(SAY_SULLY_KNEECAPPER_DEFEATED, killer);
                CompleteQuest(summon, QUEST_ID_COC_THE_WAYWARD_WILDHAMMER);
                break;
            default:
                break;
        }

        me->setActive(false);
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        _playerGUID.Clear();
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        // Summon has entered evade mode. Fail quest and reset quest giver
        if (summon->IsAlive())
        {
            switch (summon->GetEntry())
            {
                case NPC_HURP_DERP:
                    FailQuest(summon, QUEST_ID_COC_THE_BLOODEYE_BRUISER);
                    break;
                case NPC_TORG_DRAKEFLAYER:
                    FailQuest(summon, QUEST_ID_COC_THE_DEADLY_DRAGONMAW);
                    break;
                case NPC_SULLY_KNEECAPPER:
                    FailQuest(summon, QUEST_ID_COC_THE_WAYWARD_WILDHAMMER);
                    break;
                case NPC_CADAVER_COLLAGE:
                    if (summon->IsHovering())
                    {
                        CompleteQuest(summon, QUEST_ID_COC_CALDERS_CREATION);
                        Talk(SAY_CADAVER_COLLAGE_DEFEATED, ObjectAccessor::GetUnit(*me, _playerGUID));
                    }
                    else
                        FailQuest(summon, QUEST_ID_COC_CALDERS_CREATION);
                    break;
                default:
                    break;
            }

            me->setActive(false);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            _playerGUID.Clear();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_REMEMBER:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_REMEMBER, player);
                    break;
                case EVENT_ANNOUNCE_BATTLE_1:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_1, player);
                    _events.ScheduleEvent(EVENT_SUMMON_HURP_DERP, 8s);
                    break;
                case EVENT_SUMMON_HURP_DERP:
                    Talk(SAY_START_BATTLE_1);
                    if (Creature* hurpDerp = DoSummon(NPC_HURP_DERP, HurpDerpSpawnPosition))
                    {
                        hurpDerp->SetHomePosition(HurpDerpMovePosition);
                        hurpDerp->GetMotionMaster()->MovePoint(POINT_NONE, HurpDerpMovePosition);
                    }
                    break;
                case EVENT_ANNOUNCE_BATTLE_2_ALLIANCE:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_2_ALLIANCE, player);
                    _events.ScheduleEvent(EVENT_SUMMON_TORG_DRAKEFLAYER, 6s);
                    break;
                case EVENT_SUMMON_TORG_DRAKEFLAYER:
                    if (Creature* torg = DoSummon(NPC_TORG_DRAKEFLAYER, TorgDrakeflayerSpawnPosition))
                    {
                        torg->SetHomePosition(TorgDrakeflayerJumpPosition);
                        torg->GetMotionMaster()->MoveJump(TorgDrakeflayerJumpPosition, 11.5f, 16.f, POINT_ID_TORG_DRAKEFLAYER_INTRO);
                    }
                    break;
                case EVENT_ANNOUNCE_BATTLE_2_HORDE:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_2_HORDE, player);
                    _events.ScheduleEvent(EVENT_SUMMON_SULLY_KNEECAPPER, 6s);
                    break;
                case EVENT_SUMMON_SULLY_KNEECAPPER:
                    Talk(SAY_START_BATTLE_2_HORDE);
                    DoSummon(NPC_SULLY_KNEECAPPER, SullyKneecapperSpawnPosition);
                    break;
                case EVENT_ANNOUNCE_BATTLE_3:
                    if (Unit const* player = ObjectAccessor::GetUnit(*me, _playerGUID))
                        Talk(SAY_INTRO_BATTLE_3, player);
                    _events.ScheduleEvent(EVENT_SUMMON_CADAVER_COLLAGE, 8s + 500ms);
                    break;
                case EVENT_SUMMON_CADAVER_COLLAGE:
                    Talk(SAY_START_BATTLE_3);
                    DoSummon(NPC_CADAVER_COLLAGE, CadaverCollageSpawnPosition);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _playerGUID;

    void CompleteQuest(Creature const* defeatedBoss, uint32 questId)
    {
        Unit* unit = ObjectAccessor::GetUnit(*me, _playerGUID);
        if (!unit || !unit->IsPlayer())
            return;

        Player* player = unit->ToPlayer();
        player->GroupEventHappens(questId, defeatedBoss);
    }

    void FailQuest(Creature* const boss, uint32 questId)
    {
        Unit* unit = ObjectAccessor::GetUnit(*me, _playerGUID);
        if (!unit || !unit->IsPlayer())
            return;

        Player* player = unit->ToPlayer();

        if (Group* group = player->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* member = itr->GetSource();
                if (member && member->IsAtGroupRewardDistance(boss) && !player->GetCorpse())
                    member->FailQuest(questId);
            }
        }
        else
            player->FailQuest(questId);
    }
};

// 94999 - Grab Targetting
class spell_th_grab_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject const* target)
        {
            Unit const* unit = target->ToUnit();
            return (!unit || !unit->IsInCombatWith(GetCaster()));
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_th_grab_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_th_grab_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

std::array<Position, 2> ChargeDestinations =
{
    Position(-4204.6f, -5180.2f, -8.61639f),
    Position(-4194.45f, -5104.34f, -7.22446f)
};

// 88540 - Charge
class spell_th_charge : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        // While the target type indicates a nearby entry target, there is no sniffable unit target at given coordinates.
        dest.Relocate(Trinity::Containers::SelectRandomContainerElement(ChargeDestinations));
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_th_charge::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

enum BrawlerExplosion
{
    SPELL_PLAGUE_EXPLOSION  = 88614,
    SPELL_BRAWLER_PARTS_00  = 87706,
    SPELL_BRAWLER_PARTS_01  = 87708,
    SPELL_BRAWLER_PARTS_02  = 87711
};

std::array<uint32, 3> BrawlerPartsSpells
{
    SPELL_BRAWLER_PARTS_00,
    SPELL_BRAWLER_PARTS_01,
    SPELL_BRAWLER_PARTS_02
};

// 87705 - Brawler Explosion
class spell_th_brawler_explosion : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PLAGUE_EXPLOSION,
                SPELL_BRAWLER_PARTS_00,
                SPELL_BRAWLER_PARTS_01,
                SPELL_BRAWLER_PARTS_02
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        for (uint8 i = 0; i < BrawlerPartsSpells.size(); ++i)
            for (uint8 j = 0; j < 2; j++)
                target->CastSpell(target, BrawlerPartsSpells[i], true);

        target->CastSpell(target, SPELL_PLAGUE_EXPLOSION);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_th_brawler_explosion::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 90449 - Poison
class spell_th_poison : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* target = GetTarget())
        {
            uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 radius = int32(166.66f * aurEff->GetTickNumber());
            target->CastSpell(nullptr, triggerSpell, CastSpellExtraArgs(aurEff).SetOriginalCaster(target->GetGUID()).AddSpellMod(SPELLVALUE_RADIUS_MOD, radius));
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_th_poison::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_twilight_highlands()
{
    RegisterCreatureAI(npc_th_gurgthock);
    RegisterSpellScript(spell_th_grab_targeting);
    RegisterSpellScript(spell_th_charge);
    RegisterSpellScript(spell_th_brawler_explosion);
    RegisterSpellScript(spell_th_poison);
}
