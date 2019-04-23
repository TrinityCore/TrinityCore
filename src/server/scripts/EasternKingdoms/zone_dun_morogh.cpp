/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"
#include "Vehicle.h"
#include "ObjectMgr.h"
#include "Unit.h"
#include "TemporarySummon.h"
#include "GameObject.h"
#include "CombatAI.h"
#include "ObjectAccessor.h"
#include "ScriptedEscortAI.h"

enum FrozenMountaineer
{
    DATA_SET_ICE_BROKEN      = 1,
    EVENT_RUN_AWAY           = 1,
    SAY_MONSTEREMOTE         = 0,
    SPELL_SUMMON_FROZEN_TOMB = 77906,
    SPELL_FREEZE_ANIM        = 77910
};

/*######
# npc_frozen_mountaineer
######*/

struct npc_frozen_mountaineer : public ScriptedAI
{
    npc_frozen_mountaineer(Creature* creature) : ScriptedAI(creature), _dataOneSet(false) { }

    void Reset() override
    {
        _events.Reset();
        DoCastSelf(SPELL_SUMMON_FROZEN_TOMB, true);
        DoCastSelf(SPELL_FREEZE_ANIM, true);
    }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        if (data == DATA_SET_ICE_BROKEN && !_dataOneSet)
        {
            me->RemoveAllAuras();
            Talk(SAY_MONSTEREMOTE);
            _dataOneSet = true;
            _events.ScheduleEvent(EVENT_RUN_AWAY, Seconds(3));
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_dataOneSet)
            return;

        _events.Update(diff);

        if (_events.ExecuteEvent() == EVENT_RUN_AWAY)
        {
            me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + (std::cos(me->GetOrientation()) * 15.0f), me->GetPositionY() + (std::sin(me->GetOrientation()) * 15.0f), me->GetPositionZ());
            me->DespawnOrUnsummon(Seconds(2));
        }
    }
private:
    EventMap _events;
    bool _dataOneSet;
};

enum ConstrictionTotem
{
    NPC_CONSTRICTION_TOTEM  = 41202,
    QUEST_PUSHINGFORWARD    = 25792
};

class spell_burn_constriction_totem : public SpellScript
{
    PrepareSpellScript(spell_burn_constriction_totem);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit() || !GetCaster()->IsPlayer())
            return;

        GetCaster()->ToPlayer()->RewardPlayerAndGroupAtEvent(NPC_CONSTRICTION_TOTEM, GetCaster());
        GetHitUnit()->ToCreature()->DisappearAndDie();
    }

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_CONSTRICTION_TOTEM, 5.0f, true);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_burn_constriction_totem::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_burn_constriction_totem::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum FrostmaneBuilder
{
    QUEST_VIEWFROMDOWNHERE = 28868,
    SPELL_EQUALIZEVIEWPOINT = 93773,
    NPC_FROSTMANE_CREDIT = 50606
};

struct npc_frostmane_builder : public ScriptedAI
{
    npc_frostmane_builder(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id != SPELL_EQUALIZEVIEWPOINT)
            return;

        Player* player = caster->ToPlayer();
        if (player && player->GetQuestStatus(QUEST_VIEWFROMDOWNHERE) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(NPC_FROSTMANE_CREDIT, ObjectGuid::Empty);
            player->CastSpell(me, SPELL_EQUALIZEVIEWPOINT);
        }
    }

};

enum StrikeFromAbove
{
    NPC_FROSTMANE_RETREAT_NORTH     = 41372,
    NPC_FROSTMANE_RETREAT_SOUTH     = 41373,
    NPC_COVERT_OPS_FLYING_MACHINE   = 41382,
    NPC_BOMBARDMENT_BUNNY           = 41375,
    SPELL_MISSILE_BARRAGE           = 77477,
    ACTION_FLYING_MACHINE_ATTACK    = 1,
    GOBJECT_FIRE                    = 182090
};

static const Position northernFlyingMachinePositions[2] =
{
    { -5705.887f, -997.9028f, 416.8214f },
    { -5699.643f, -995.9340f, 415.1655f }
};

static const Position northernFlyingMachineDestPositions[2] =
{
    { -5718.96f, -1026.789f, 405.8286f },
    { -5706.56f, -1015.849f, 410.3938f }
};

static const Position southernFlyingMachinePositions[2] =
{
    { -5777.16f, -959.2396f, 412.5151f },
    { -5777.124f, -956.1979f, 412.0958f }
};

static const Position southernFlyingMachineDestPositions[2] =
{
    { -5814.012f, -957.7242f, 404.7715f },
    { -5800.190f, -952.4794f, 407.7211f }
};

class spell_signal_flare : public SpellScript
{
    PrepareSpellScript(spell_signal_flare);

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_FROSTMANE_RETREAT_NORTH, 25.0f, true);
        if (!target)
            target = GetCaster()->FindNearestCreature(NPC_FROSTMANE_RETREAT_SOUTH, 25.0f, true);
    }

    SpellCastResult CheckRequirement()
    {
        Creature* north = GetCaster()->FindNearestCreature(NPC_FROSTMANE_RETREAT_NORTH, 25.0f, true);
        Creature* south = GetCaster()->FindNearestCreature(NPC_FROSTMANE_RETREAT_SOUTH, 25.0f, true);

        if (!north && !south)
            return SPELL_FAILED_INCORRECT_AREA;
        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        if (!hitUnit || !GetCaster()->IsPlayer())
            return;

        if (Creature* target = hitUnit->ToCreature())
        {
            switch (target->GetEntry())
            {
                case NPC_FROSTMANE_RETREAT_NORTH:
                    FlyingMachineAttack(northernFlyingMachineDestPositions[0], GetCaster()->SummonCreature(NPC_COVERT_OPS_FLYING_MACHINE, northernFlyingMachinePositions[0]));
                    FlyingMachineAttack(northernFlyingMachineDestPositions[1], GetCaster()->SummonCreature(NPC_COVERT_OPS_FLYING_MACHINE, northernFlyingMachinePositions[1]));
                    GetCaster()->ToPlayer()->RewardPlayerAndGroupAtEvent(target->GetEntry(), GetCaster());
                    break;

                case NPC_FROSTMANE_RETREAT_SOUTH:
                    FlyingMachineAttack(southernFlyingMachineDestPositions[0], GetCaster()->SummonCreature(NPC_COVERT_OPS_FLYING_MACHINE, southernFlyingMachinePositions[0]));
                    FlyingMachineAttack(southernFlyingMachineDestPositions[1], GetCaster()->SummonCreature(NPC_COVERT_OPS_FLYING_MACHINE, southernFlyingMachinePositions[1]));
                    GetCaster()->ToPlayer()->RewardPlayerAndGroupAtEvent(target->GetEntry(), GetCaster());
                    break;
            }
        }
    }

    void FlyingMachineAttack(Position destination, TempSummon* summon)
    {
        if (!summon)
            return;

        summon->GetMotionMaster()->MovePoint(0, destination);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_signal_flare::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_signal_flare::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_signal_flare::CheckRequirement);
    }
};

struct npc_flying_machine : public ScriptedAI
{
    npc_flying_machine(Creature* creature) : ScriptedAI(creature) {}

    enum Data
    {
        EVENT_ATTACK = 1
    };

    void Reset() override
    {
        events.ScheduleEvent(EVENT_ATTACK, 3500);
        me->DespawnOrUnsummon(6000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_ATTACK:
                DoCast(SPELL_MISSILE_BARRAGE);
                events.ScheduleEvent(EVENT_ATTACK, 1000);
                break;
            }
        }
    }

private:
    EventMap events;
};

class spell_missile_barrage : public SpellScript
{
    PrepareSpellScript(spell_missile_barrage);

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_BOMBARDMENT_BUNNY, 30.0f, true);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        if (!hitUnit)
            return;

        hitUnit->SummonGameObject(GOBJECT_FIRE, hitUnit->GetPosition(), QuaternionData(), 25);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_missile_barrage::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_missile_barrage::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

};

enum BurningBomber
{
    NPC_BURNING_BOMBER_CREDIT = 42046,
    QUEST_EXTINGUISH_FIRES = 26078
};

class spell_extinguish_fire : public SpellScript
{
    PrepareSpellScript(spell_extinguish_fire);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit())
            return;
        GetCaster()->ToPlayer()->RewardPlayerAndGroupAtEvent(NPC_BURNING_BOMBER_CREDIT, GetCaster());
        GetHitUnit()->ToCreature()->DisappearAndDie();
    }

    void SelectTarget(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreature(NPC_BURNING_BOMBER_CREDIT, 9.0f, true);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_extinguish_fire::SelectTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_extinguish_fire::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum StolenRam
{
    QUEST_RAMS_ON_THE_LAM = 25905,
    SPELL_ON_WAVEEMOTE_TO_STOLEN_RAM = 80464,
    NPC_RAMS_CREDIT = 43064,
    NPC_STOLEN_RAM = 41539
};

class spell_emote_stolen_ram : public SpellScript
{
    PrepareSpellScript(spell_emote_stolen_ram);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        if (!hitUnit)
            return;

        if (hitUnit->GetTypeId() != TYPEID_PLAYER)
            return;

        if (hitUnit->ToPlayer()->GetQuestStatus(QUEST_RAMS_ON_THE_LAM) != QUEST_STATUS_INCOMPLETE)
            return;

        GetCaster()->GetMotionMaster()->MovePoint(0, hitUnit->GetPosition());

        if (GetCaster()->ToCreature())
            GetCaster()->ToCreature()->DespawnOrUnsummon(3000);

        hitUnit->ToPlayer()->RewardPlayerAndGroupAtEvent(NPC_RAMS_CREDIT, hitUnit);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_emote_stolen_ram::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct npc_stolen_ram : public ScriptedAI
{
    npc_stolen_ram(Creature* creature) : ScriptedAI(creature) {}

    void ReceiveEmote(Player* player, uint32 emoteId) override
    {
        if (player->GetDistance(me) > 15.f)
            return;

        switch (emoteId)
        {
            case TEXT_EMOTE_WHISTLE:
            case TEXT_EMOTE_WAVE:
                DoCast(player, SPELL_ON_WAVEEMOTE_TO_STOLEN_RAM);
                break;
            default:
                break;
        }
    }
};

class npc_sergeant_flinthammer : public CreatureScript
{
public:
    npc_sergeant_flinthammer() : CreatureScript("npc_sergeant_flinthammer") { }

    enum Data
    {
        QUEST_ITS_RAID_NIGHT_EVERY_NIGHT    = 25932,
        NPC_AMBERSTILL_MOUNTAINEER          = 41611,
        NPC_FROSTMANE_RAIDER                = 41603,
        SPELL_AURA_READY_THROWN_JAVELIN     = 77677,
        NPC_AMBERSTILL_RAID_CONTROLLER      = 42169, // this gives credit for the quest
        ACTION_START_EVENT                  = 1,
        EVENT_SAY_0                         = 1,
        EVENT_SAY_1                         = 2,
        EVENT_SAY_2                         = 3,
        EVENT_SAY_3                         = 4,
        EVENT_SAY_4                         = 5,
        EVENT_SAY_5                         = 6,
        EVENT_SAY_6                         = 7,
        EVENT_SAY_7                         = 8,
        EVENT_SAY_8                         = 9,
        EVENT_SPAWN_TROLLS                  = 10,
        EVENT_SAY_9                         = 11,

    };

    enum TalkData
    {
        TALK_0 = 0,
        TALK_1 = 1,
        TALK_2 = 2,
        TALK_3 = 3,
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case QUEST_ITS_RAID_NIGHT_EVERY_NIGHT:
                creature->AI()->SetGUID(player->GetGUID());
                creature->AI()->DoAction(ACTION_START_EVENT);
                break;
        }

        return true;
    }

    struct npc_sergeant_flinthammerAI : public ScriptedAI
    {
        npc_sergeant_flinthammerAI(Creature* creature) : ScriptedAI(creature) { }

        std::array<ObjectGuid, 4> TrollGUIDs;
        ObjectGuid PlayerGUID;
        uint32 SummonTimer;
        uint8 Phase;

        bool bSummoned;

        void Reset() override
        {
            Phase = 0;
            bSummoned = false;
            SummonTimer = 2000;
        }

        void SetGUID(ObjectGuid guid, int32 /*id*/) override
        {
            PlayerGUID = guid;
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_START_EVENT:
                    SummonTimer = 2000;
                    break;
            }
        }

        void SummonSpawns()
        {
            if (!bSummoned)
            {
                if (Creature* Troll1 = me->SummonCreature(NPC_FROSTMANE_RAIDER, -5552.28f, -1303.05f, 398.639f, 5.79634f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90000,true))
                if (Creature* Troll2 = me->SummonCreature(NPC_FROSTMANE_RAIDER, -5552.03f, -1308.41f, 398.271f, 6.02804f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90000,true))
                if (Creature* Troll3 = me->SummonCreature(NPC_FROSTMANE_RAIDER, -5551.05f, -1314.46f, 398.581f, 0.157184f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90000,true))
                if (Creature* Troll4 = me->SummonCreature(NPC_FROSTMANE_RAIDER, -5547.3f, -1318.42f, 398.635f, 0.565593f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 90000,true))
                if (Creature* Guard1 = me->SummonCreature(NPC_AMBERSTILL_MOUNTAINEER, -5541.07f, -1317.56f, 398.805f, 2.62334f, TEMPSUMMON_TIMED_DESPAWN, 90000,true))
                if (Creature* Guard2 = me->SummonCreature(NPC_AMBERSTILL_MOUNTAINEER, -5540.12f, -1314.39f, 398.721f, 2.69402f, TEMPSUMMON_TIMED_DESPAWN, 90000,true))
                if (Creature* Guard3 = me->SummonCreature(NPC_AMBERSTILL_MOUNTAINEER, -5540.65f, -1310.12f, 398.374f, 3.14955f, TEMPSUMMON_TIMED_DESPAWN, 90000,true))
                if (Creature* Guard4 = me->SummonCreature(NPC_AMBERSTILL_MOUNTAINEER, -5542.06f, -1305.57f, 398.801f, 3.41266f, TEMPSUMMON_TIMED_DESPAWN, 90000,true))
                    {
                        TrollGUIDs[0] = Troll1->GetGUID();
                        TrollGUIDs[1] = Troll2->GetGUID();
                        TrollGUIDs[2] = Troll3->GetGUID();
                        TrollGUIDs[3] = Troll4->GetGUID();
                        bSummoned = true;
                    }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            Creature* agent;
            if (SummonTimer < diff)
            {

                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                {
                    switch (Phase)
                    {
                        case 0:
                        {
                            Talk(TALK_0);
                            SummonTimer = 3500;
                            Phase++;
                            break;
                        }
                        case 1:
                        {
                            agent = me->FindNearestCreature(NPC_AMBERSTILL_MOUNTAINEER, 25.0f, true);
                            agent->AI()->Talk(TALK_0);
                            SummonTimer = 4500;
                            Phase++;
                        }
                        case 2:
                        {
                            Talk(TALK_1);
                            SummonTimer = 5500;
                            Phase++;
                            break;
                        }
                        case 3:
                        {
                            Talk(TALK_2);
                            SummonTimer = 6500;
                            Phase++;
                            break;
                        }
                        case 4:
                        {
                            agent = me->FindNearestCreature(NPC_AMBERSTILL_MOUNTAINEER, 25.0f, true);
                            agent->AI()->Talk(TALK_1);
                            SummonTimer = 7500;
                            Phase++;
                        }
                        case 5:
                        {
                            Talk(TALK_3);
                            SummonTimer = 8500;
                            Phase++;
                            break;
                        }
                        case 6:
                        {
                            SummonSpawns();
                            SummonTimer = 9500;
                            Phase++;
                            break;
                        }
                        case 7:
                        {
                            agent = me->FindNearestCreature(NPC_FROSTMANE_RAIDER, 25.0f, true);
                            agent->AI()->Talk(TALK_0);
                            SummonTimer = 10500;
                            Phase++;
                        }

                        case 8:
                        {
                            for (ObjectGuid trollGUID : TrollGUIDs)
                            {
                                if (Creature* Troll = ObjectAccessor::GetCreature(*me, trollGUID))
                                {
                                    Troll->SetReactState(REACT_AGGRESSIVE);
                                    Troll->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                }
                            }
                            SummonTimer = 11000;
                            Phase++;
                            break;
                        }
                        case 9:
                        {
                            for (ObjectGuid trollGUID : TrollGUIDs)
                                if (Creature* Troll = ObjectAccessor::GetCreature(*me, trollGUID))
                                    Troll->CombatStart(player, true);

                            SummonTimer = 20000;
                            Phase++;
                            break;
                        }
                        case 10:
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                                player->KilledMonsterCredit(NPC_AMBERSTILL_RAID_CONTROLLER, PlayerGUID);
                            SummonTimer = 30000;
                            break;
                        }

                        default:
                            break;
                    }
                }
            }
            else SummonTimer -= diff;
        }

    private:
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sergeant_flinthammerAI(creature);
    }
};

void AddSC_dun_morogh()
{
    RegisterCreatureAI(npc_frozen_mountaineer);
    RegisterSpellScript(spell_burn_constriction_totem);
    RegisterCreatureAI(npc_frostmane_builder);
    RegisterSpellScript(spell_signal_flare);
    RegisterCreatureAI(npc_flying_machine);
    RegisterSpellScript(spell_missile_barrage);
    RegisterSpellScript(spell_extinguish_fire);
    RegisterSpellScript(spell_emote_stolen_ram);
    RegisterCreatureAI(npc_stolen_ram);
    new npc_sergeant_flinthammer();
}
