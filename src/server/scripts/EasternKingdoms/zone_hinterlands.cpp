/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: Hinterlands
SD%Complete: 100
SDComment: Quest support: 836
SDCategory: The Hinterlands
EndScriptData */

/* ContentData
npc_oox09hl
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_oox09hl
######*/

enum eOOX
{
    SAY_OOX_START           = 0,
    SAY_OOX_AGGRO           = 1,
    SAY_OOX_AMBUSH          = 2,
    SAY_OOX_AMBUSH_REPLY    = 3,
    SAY_OOX_END             = 4,
    QUEST_RESQUE_OOX_09     = 836,
    NPC_MARAUDING_OWL       = 7808,
    NPC_VILE_AMBUSHER       = 7809,
    FACTION_ESCORTEE_A      = 774,
    FACTION_ESCORTEE_H      = 775
};

class npc_oox09hl : public CreatureScript
{
public:
    npc_oox09hl() : CreatureScript("npc_oox09hl") { }

    struct npc_oox09hlAI : public npc_escortAI
    {
        npc_oox09hlAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* who) override
        {
            if (who->GetEntry() == NPC_MARAUDING_OWL || who->GetEntry() == NPC_VILE_AMBUSHER)
                return;

            Talk(SAY_OOX_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
        }

        void sQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_RESQUE_OOX_09)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->setFaction(player->GetTeam() == ALLIANCE ? FACTION_ESCORTEE_A : FACTION_ESCORTEE_H);
                Talk(SAY_OOX_START, player);
                npc_escortAI::Start(false, false, player->GetGUID(), quest);
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 26:
                    Talk(SAY_OOX_AMBUSH);
                    break;
                case 43:
                    Talk(SAY_OOX_AMBUSH);
                    break;
                case 64:
                    Talk(SAY_OOX_END);
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_RESQUE_OOX_09, me);
                    break;
            }
        }

        void WaypointStart(uint32 pointId) override
        {
            switch (pointId)
            {
                case 27:
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        const Position src = {147.927444f, -3851.513428f, 130.893f, 0};
                        Position dst = me->GetRandomPoint(src, 7.0f);
                        DoSummon(NPC_MARAUDING_OWL, dst, 25000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    }
                    break;
                case 44:
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        const Position src = {-141.151581f, -4291.213867f, 120.130f, 0};
                        Position dst = me->GetRandomPoint(src, 7.0f);
                        me->SummonCreature(NPC_VILE_AMBUSHER, dst, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 25000);
                    }
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oox09hlAI(creature);
    }
};

/*######
## npc_sharpbeak used by Entrys 43161 & 51125
######*/

enum Sharpbeak
{
    NPC_SHARPBEAK_CAMP            = 43161,
    NPC_SHARPBEAK_JINTHAALOR      = 51125,
    SPELL_EJECT_ALL_PASSENGERS    = 50630
};

Position const campPath[] =
{
    { -75.40077f, -4037.111f, 114.6418f },
    { -68.80193f, -4034.235f, 123.6844f },
    { -62.20310f, -4031.360f, 132.7270f },
    { -48.58510f, -4008.040f, 156.9770f },
    { -26.26910f, -3987.880f, 176.7550f },
    {  11.50870f, -3960.860f, 203.5610f },
    {  45.00870f, -3922.580f, 236.6720f },
    {  75.44270f, -3856.910f, 255.6720f },
    {  74.83510f, -3768.840f, 279.8390f },
    { -53.01040f, -3582.620f, 287.7550f },
    { -169.1230f, -3582.080f, 282.8660f },
    { -241.8403f, -3625.010f, 247.4203f }
};
size_t constexpr campPathSize = std::extent<decltype(campPath)>::value;

Position const jinthaalorPath[] =
{
    { -249.4681f, -3632.487f, 232.6947f },
    { -241.6060f, -3627.713f, 236.6187f },
    { -235.6163f, -3624.076f, 239.6081f },
    { -226.8698f, -3623.929f, 244.8882f },
    { -193.6406f, -3618.776f, 244.8882f },
    { -149.7292f, -3613.349f, 244.8882f },
    { -103.8976f, -3623.828f, 238.0368f },
    { -41.33681f, -3710.568f, 232.4109f },
    {  6.201389f, -3739.243f, 214.2869f },
    {  37.44097f, -3773.431f, 189.4650f },
    {  44.21875f, -3884.991f, 177.7446f },
    {  39.81424f, -3934.679f, 168.1627f },
    {  32.17535f, -3983.781f, 166.1228f },
    {  21.34896f, -4005.293f, 162.9598f },
    { -5.734375f, -4028.695f, 149.0161f },
    { -23.23611f, -4040.689f, 140.1189f },
    { -35.45139f, -4047.543f, 133.2071f },
    { -59.21181f, -4051.257f, 128.0297f },
    { -76.90625f, -4040.207f, 126.0433f },
    { -77.51563f, -4022.026f, 123.2135f }
};
size_t constexpr jinthaalorPathSize = std::extent<decltype(jinthaalorPath)>::value;

struct npc_sharpbeak : public ScriptedAI
{
    npc_sharpbeak(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        endPoint = 0;
    }

    void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        switch (me->GetEntry())
        {
            case NPC_SHARPBEAK_CAMP:
                me->GetMotionMaster()->MoveSmoothPath(uint32(campPathSize), campPath, campPathSize, false);
                endPoint = campPathSize;
                break;
            case NPC_SHARPBEAK_JINTHAALOR:
                me->GetMotionMaster()->MoveSmoothPath(uint32(jinthaalorPathSize), jinthaalorPath, jinthaalorPathSize, false, true);
                endPoint = jinthaalorPathSize;
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == EFFECT_MOTION_TYPE && pointId == endPoint)
            DoCast(SPELL_EJECT_ALL_PASSENGERS);
    }

private:
    size_t endPoint;
};

enum TrainedRazorbeak
{
    QUEST_RAZORBEAKFRIENDS  = 26546,
    SPELL_FEED_RAZORBEAK    = 80782,
    NPC_RAZORBEAK_CREDIT    = 43236
};

struct npc_trained_razorbeak : public ScriptedAI
{
    npc_trained_razorbeak(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id != SPELL_FEED_RAZORBEAK)
            return;

        Player* player = caster->ToPlayer();
        if (player && player->GetQuestStatus(QUEST_RAZORBEAKFRIENDS) == QUEST_STATUS_INCOMPLETE)
            player->KilledMonsterCredit(NPC_RAZORBEAK_CREDIT, ObjectGuid::Empty);
    }

};

enum FacesEvil
{
    NPC_MASK_BURNT_CREDIT     = 42704
};

class spell_tiki_torch : public SpellScript
{
    PrepareSpellScript(spell_tiki_torch);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (Creature* target = GetHitCreature())
            {
                player->RewardPlayerAndGroupAtEvent(NPC_MASK_BURNT_CREDIT, GetCaster());
                target->DisappearAndDie();
            }
        }
    }

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_MASK_BURNT_CREDIT, 15.0f, true);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_tiki_torch::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_tiki_torch::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum RitualShadra
{
    NPC_SHADRA_NW_ALTAR_BUNNY   = 43067,
    NPC_SHADRA_SW_ALTAR_BUNNY   = 43068,
    NPC_SHADRA_E_ALTAR_BUNNY    = 43069
};

class spell_ritual_of_shadra : public SpellScript
{
    PrepareSpellScript(spell_ritual_of_shadra);

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_SHADRA_NW_ALTAR_BUNNY, 15.0f, true);
        if (!target)
            target = GetCaster()->FindNearestCreature(NPC_SHADRA_SW_ALTAR_BUNNY, 15.0f, true);
        if (!target)
            target = GetCaster()->FindNearestCreature(NPC_SHADRA_E_ALTAR_BUNNY, 15.0f, true);
    }

    SpellCastResult CheckRequirement()
    {
        Creature* northwest = GetCaster()->FindNearestCreature(NPC_SHADRA_NW_ALTAR_BUNNY, 15.0f, true);
        Creature* southwest = GetCaster()->FindNearestCreature(NPC_SHADRA_SW_ALTAR_BUNNY, 15.0f, true);
        Creature* east = GetCaster()->FindNearestCreature(NPC_SHADRA_E_ALTAR_BUNNY, 15.0f, true);

        if (!northwest && !southwest && !east)
            return SPELL_FAILED_INCORRECT_AREA;
        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Creature* hitCreature = GetHitCreature();
        Player* player = GetCaster()->ToPlayer();
        if (!hitCreature || !player)
            return;

        switch (hitCreature->GetEntry())
        {
            case NPC_SHADRA_NW_ALTAR_BUNNY:
                player->RewardPlayerAndGroupAtEvent(hitCreature->GetEntry(), GetCaster());
                break;
            case NPC_SHADRA_SW_ALTAR_BUNNY:
                player->RewardPlayerAndGroupAtEvent(hitCreature->GetEntry(), GetCaster());
                break;
            case NPC_SHADRA_E_ALTAR_BUNNY:
                player->RewardPlayerAndGroupAtEvent(hitCreature->GetEntry(), GetCaster());
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_ritual_of_shadra::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_ritual_of_shadra::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_ritual_of_shadra::CheckRequirement);
    }
};

void AddSC_hinterlands()
{
    new npc_oox09hl();
    RegisterCreatureAI(npc_sharpbeak);
    RegisterCreatureAI(npc_trained_razorbeak);
    RegisterSpellScript(spell_tiki_torch);
    RegisterSpellScript(spell_ritual_of_shadra);
}
