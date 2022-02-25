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

#include "GameObject.h"
#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Fireworks
{
    NPC_OMEN                = 15467,
    NPC_MINION_OF_OMEN      = 15466,
    NPC_FIREWORK_BLUE       = 15879,
    NPC_FIREWORK_GREEN      = 15880,
    NPC_FIREWORK_PURPLE     = 15881,
    NPC_FIREWORK_RED        = 15882,
    NPC_FIREWORK_YELLOW     = 15883,
    NPC_FIREWORK_WHITE      = 15884,
    NPC_FIREWORK_BIG_BLUE   = 15885,
    NPC_FIREWORK_BIG_GREEN  = 15886,
    NPC_FIREWORK_BIG_PURPLE = 15887,
    NPC_FIREWORK_BIG_RED    = 15888,
    NPC_FIREWORK_BIG_YELLOW = 15889,
    NPC_FIREWORK_BIG_WHITE  = 15890,

    NPC_CLUSTER_BLUE        = 15872,
    NPC_CLUSTER_RED         = 15873,
    NPC_CLUSTER_GREEN       = 15874,
    NPC_CLUSTER_PURPLE      = 15875,
    NPC_CLUSTER_WHITE       = 15876,
    NPC_CLUSTER_YELLOW      = 15877,
    NPC_CLUSTER_BIG_BLUE    = 15911,
    NPC_CLUSTER_BIG_GREEN   = 15912,
    NPC_CLUSTER_BIG_PURPLE  = 15913,
    NPC_CLUSTER_BIG_RED     = 15914,
    NPC_CLUSTER_BIG_WHITE   = 15915,
    NPC_CLUSTER_BIG_YELLOW  = 15916,
    NPC_CLUSTER_ELUNE       = 15918,

    GO_FIREWORK_LAUNCHER_1  = 180771,
    GO_FIREWORK_LAUNCHER_2  = 180868,
    GO_FIREWORK_LAUNCHER_3  = 180850,
    GO_CLUSTER_LAUNCHER_1   = 180772,
    GO_CLUSTER_LAUNCHER_2   = 180859,
    GO_CLUSTER_LAUNCHER_3   = 180869,
    GO_CLUSTER_LAUNCHER_4   = 180874,

    SPELL_ROCKET_BLUE       = 26344,
    SPELL_ROCKET_GREEN      = 26345,
    SPELL_ROCKET_PURPLE     = 26346,
    SPELL_ROCKET_RED        = 26347,
    SPELL_ROCKET_WHITE      = 26348,
    SPELL_ROCKET_YELLOW     = 26349,
    SPELL_ROCKET_BIG_BLUE   = 26351,
    SPELL_ROCKET_BIG_GREEN  = 26352,
    SPELL_ROCKET_BIG_PURPLE = 26353,
    SPELL_ROCKET_BIG_RED    = 26354,
    SPELL_ROCKET_BIG_WHITE  = 26355,
    SPELL_ROCKET_BIG_YELLOW = 26356,
    SPELL_LUNAR_FORTUNE     = 26522,

    ANIM_GO_LAUNCH_FIREWORK = 3,
    ZONE_MOONGLADE          = 493,
};

Position omenSummonPos = {7558.993f, -2839.999f, 450.0214f, 4.46f};

struct npc_firework : public ScriptedAI
{
    npc_firework(Creature* creature) : ScriptedAI(creature) { }

    bool isCluster()
    {
        switch (me->GetEntry())
        {
            case NPC_FIREWORK_BLUE:
            case NPC_FIREWORK_GREEN:
            case NPC_FIREWORK_PURPLE:
            case NPC_FIREWORK_RED:
            case NPC_FIREWORK_YELLOW:
            case NPC_FIREWORK_WHITE:
            case NPC_FIREWORK_BIG_BLUE:
            case NPC_FIREWORK_BIG_GREEN:
            case NPC_FIREWORK_BIG_PURPLE:
            case NPC_FIREWORK_BIG_RED:
            case NPC_FIREWORK_BIG_YELLOW:
            case NPC_FIREWORK_BIG_WHITE:
                return false;
            case NPC_CLUSTER_BLUE:
            case NPC_CLUSTER_GREEN:
            case NPC_CLUSTER_PURPLE:
            case NPC_CLUSTER_RED:
            case NPC_CLUSTER_YELLOW:
            case NPC_CLUSTER_WHITE:
            case NPC_CLUSTER_BIG_BLUE:
            case NPC_CLUSTER_BIG_GREEN:
            case NPC_CLUSTER_BIG_PURPLE:
            case NPC_CLUSTER_BIG_RED:
            case NPC_CLUSTER_BIG_YELLOW:
            case NPC_CLUSTER_BIG_WHITE:
            case NPC_CLUSTER_ELUNE:
            default:
                return true;
        }
    }

    GameObject* FindNearestLauncher()
    {
        GameObject* launcher = nullptr;

        if (isCluster())
        {
            GameObject* launcher1 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_1, 0.5f);
            GameObject* launcher2 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_2, 0.5f);
            GameObject* launcher3 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_3, 0.5f);
            GameObject* launcher4 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_4, 0.5f);

            if (launcher1)
                launcher = launcher1;
            else if (launcher2)
                launcher = launcher2;
            else if (launcher3)
                launcher = launcher3;
            else if (launcher4)
                launcher = launcher4;
        }
        else
        {
            GameObject* launcher1 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_1, 0.5f);
            GameObject* launcher2 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_2, 0.5f);
            GameObject* launcher3 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_3, 0.5f);

            if (launcher1)
                launcher = launcher1;
            else if (launcher2)
                launcher = launcher2;
            else if (launcher3)
                launcher = launcher3;
        }

        return launcher;
    }

    uint32 GetFireworkSpell(uint32 entry)
    {
        switch (entry)
        {
            case NPC_FIREWORK_BLUE:
                return SPELL_ROCKET_BLUE;
            case NPC_FIREWORK_GREEN:
                return SPELL_ROCKET_GREEN;
            case NPC_FIREWORK_PURPLE:
                return SPELL_ROCKET_PURPLE;
            case NPC_FIREWORK_RED:
                return SPELL_ROCKET_RED;
            case NPC_FIREWORK_YELLOW:
                return SPELL_ROCKET_YELLOW;
            case NPC_FIREWORK_WHITE:
                return SPELL_ROCKET_WHITE;
            case NPC_FIREWORK_BIG_BLUE:
                return SPELL_ROCKET_BIG_BLUE;
            case NPC_FIREWORK_BIG_GREEN:
                return SPELL_ROCKET_BIG_GREEN;
            case NPC_FIREWORK_BIG_PURPLE:
                return SPELL_ROCKET_BIG_PURPLE;
            case NPC_FIREWORK_BIG_RED:
                return SPELL_ROCKET_BIG_RED;
            case NPC_FIREWORK_BIG_YELLOW:
                return SPELL_ROCKET_BIG_YELLOW;
            case NPC_FIREWORK_BIG_WHITE:
                return SPELL_ROCKET_BIG_WHITE;
            default:
                return 0;
        }
    }

    uint32 GetFireworkGameObjectId()
    {
        uint32 spellId = 0;

        switch (me->GetEntry())
        {
            case NPC_CLUSTER_BLUE:
                spellId = GetFireworkSpell(NPC_FIREWORK_BLUE);
                break;
            case NPC_CLUSTER_GREEN:
                spellId = GetFireworkSpell(NPC_FIREWORK_GREEN);
                break;
            case NPC_CLUSTER_PURPLE:
                spellId = GetFireworkSpell(NPC_FIREWORK_PURPLE);
                break;
            case NPC_CLUSTER_RED:
                spellId = GetFireworkSpell(NPC_FIREWORK_RED);
                break;
            case NPC_CLUSTER_YELLOW:
                spellId = GetFireworkSpell(NPC_FIREWORK_YELLOW);
                break;
            case NPC_CLUSTER_WHITE:
                spellId = GetFireworkSpell(NPC_FIREWORK_WHITE);
                break;
            case NPC_CLUSTER_BIG_BLUE:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_BLUE);
                break;
            case NPC_CLUSTER_BIG_GREEN:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_GREEN);
                break;
            case NPC_CLUSTER_BIG_PURPLE:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_PURPLE);
                break;
            case NPC_CLUSTER_BIG_RED:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_RED);
                break;
            case NPC_CLUSTER_BIG_YELLOW:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_YELLOW);
                break;
            case NPC_CLUSTER_BIG_WHITE:
                spellId = GetFireworkSpell(NPC_FIREWORK_BIG_WHITE);
                break;
            case NPC_CLUSTER_ELUNE:
                spellId = GetFireworkSpell(urand(NPC_FIREWORK_BLUE, NPC_FIREWORK_WHITE));
                break;
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);

        if (spellInfo && spellInfo->GetEffect(EFFECT_0).Effect == SPELL_EFFECT_SUMMON_OBJECT_WILD)
            return spellInfo->GetEffect(EFFECT_0).MiscValue;

        return 0;
    }

    void Reset() override
    {
        if (GameObject* launcher = FindNearestLauncher())
        {
            launcher->SendCustomAnim(ANIM_GO_LAUNCH_FIREWORK);
            me->SetOrientation(launcher->GetOrientation() + float(M_PI) / 2);
        }
        else
            return;

        if (isCluster())
        {
            // Check if we are near Elune'ara lake south, if so try to summon Omen or a minion
            if (me->GetZoneId() == ZONE_MOONGLADE)
            {
                if (!me->FindNearestCreature(NPC_OMEN, 100.0f) && me->GetDistance2d(omenSummonPos.GetPositionX(), omenSummonPos.GetPositionY()) <= 100.0f)
                {
                    switch (urand(0, 9))
                    {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            if (Creature* minion = me->SummonCreature(NPC_MINION_OF_OMEN, me->GetPositionX()+frand(-5.0f, 5.0f), me->GetPositionY()+frand(-5.0f, 5.0f), me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s))
                                minion->AI()->AttackStart(me->SelectNearestPlayer(20.0f));
                            break;
                        case 9:
                            me->SummonCreature(NPC_OMEN, omenSummonPos);
                            break;
                    }
                }
            }
            if (me->GetEntry() == NPC_CLUSTER_ELUNE)
                DoCast(SPELL_LUNAR_FORTUNE);

            float displacement = 0.7f;
            for (uint8 i = 0; i < 4; i++)
                me->SummonGameObject(GetFireworkGameObjectId(), me->GetPositionX() + (i % 2 == 0 ? displacement : -displacement), me->GetPositionY() + (i > 1 ? displacement : -displacement), me->GetPositionZ() + 4.0f, me->GetOrientation(), QuaternionData(), 1s);
        }
        else
            //me->CastSpell(me, GetFireworkSpell(me->GetEntry()), true);
            me->CastSpell(me->GetPosition(), GetFireworkSpell(me->GetEntry()), true);
    }
};

/*####
# npc_omen
####*/

enum Omen
{
    SPELL_OMEN_CLEAVE           = 15284,
    SPELL_OMEN_STARFALL         = 26540,
    SPELL_OMEN_SUMMON_SPOTLIGHT = 26392,
    SPELL_ELUNE_CANDLE          = 26374,

    GO_ELUNE_TRAP_1             = 180876,
    GO_ELUNE_TRAP_2             = 180877,

    EVENT_CAST_CLEAVE           = 1,
    EVENT_CAST_STARFALL         = 2,
    EVENT_DESPAWN               = 3,
};

struct npc_omen : public ScriptedAI
{
    npc_omen(Creature* creature) : ScriptedAI(creature)
    {
        me->SetImmuneToPC(true);
        me->GetMotionMaster()->MovePoint(1, 7549.977f, -2855.137f, 456.9678f);
    }

    EventMap events;

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == 1)
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            me->SetImmuneToPC(false);
            if (Player* player = me->SelectNearestPlayer(40.0f))
                AttackStart(player);
        }
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_CAST_CLEAVE, 3s, 5s);
        events.ScheduleEvent(EVENT_CAST_STARFALL, 8s, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCast(SPELL_OMEN_SUMMON_SPOTLIGHT);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ELUNE_CANDLE)
        {
            if (me->HasAura(SPELL_OMEN_STARFALL))
                me->RemoveAurasDueToSpell(SPELL_OMEN_STARFALL);

            events.RescheduleEvent(EVENT_CAST_STARFALL, 14s, 16s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case EVENT_CAST_CLEAVE:
                DoCastVictim(SPELL_OMEN_CLEAVE);
                events.ScheduleEvent(EVENT_CAST_CLEAVE, 8s, 10s);
                break;
            case EVENT_CAST_STARFALL:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_OMEN_STARFALL);
                events.ScheduleEvent(EVENT_CAST_STARFALL, 14s, 16s);
                break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_giant_spotlight : public ScriptedAI
{
    npc_giant_spotlight(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_DESPAWN, 5min);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_DESPAWN)
        {
            if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_1, 5.0f))
                trap->RemoveFromWorld();

            if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_2, 5.0f))
                trap->RemoveFromWorld();

            if (Creature* omen = me->FindNearestCreature(NPC_OMEN, 5.0f, false))
                omen->DespawnOrUnsummon();

            me->DespawnOrUnsummon();
        }
    }
};

enum EluneCandle
{
    SPELL_ELUNE_CANDLE_OMEN_HEAD   = 26622,
    SPELL_ELUNE_CANDLE_OMEN_CHEST  = 26624,
    SPELL_ELUNE_CANDLE_OMEN_HAND_R = 26625,
    SPELL_ELUNE_CANDLE_OMEN_HAND_L = 26649,
    SPELL_ELUNE_CANDLE_NORMAL      = 26636
};

// 26374 - Elune's Candle
class spell_lunar_festival_elune_candle : public SpellScript
{
    PrepareSpellScript(spell_lunar_festival_elune_candle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ELUNE_CANDLE_OMEN_HEAD,
            SPELL_ELUNE_CANDLE_OMEN_CHEST,
            SPELL_ELUNE_CANDLE_OMEN_HAND_R,
            SPELL_ELUNE_CANDLE_OMEN_HAND_L,
            SPELL_ELUNE_CANDLE_NORMAL
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = 0;

        if (GetHitUnit()->GetEntry() == NPC_OMEN)
        {
            switch (urand(0, 3))
            {
                case 0:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HEAD;
                    break;
                case 1:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_CHEST;
                    break;
                case 2:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HAND_R;
                    break;
                case 3:
                    spellId = SPELL_ELUNE_CANDLE_OMEN_HAND_L;
                    break;
            }
        }
        else
            spellId = SPELL_ELUNE_CANDLE_NORMAL;

        GetCaster()->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lunar_festival_elune_candle::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_event_lunar_festival()
{
    RegisterCreatureAI(npc_firework);
    RegisterCreatureAI(npc_omen);
    RegisterCreatureAI(npc_giant_spotlight);
    RegisterSpellScript(spell_lunar_festival_elune_candle);
}
