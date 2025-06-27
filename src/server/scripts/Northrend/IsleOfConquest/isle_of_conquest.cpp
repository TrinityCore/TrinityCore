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
#include "BattlegroundIC.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

struct npc_four_car_garage : public NullCreatureAI
{
    npc_four_car_garage(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            uint32 spellId = 0;

            switch (me->GetEntry())
            {
                case NPC_DEMOLISHER:
                    spellId = SPELL_DRIVING_CREDIT_DEMOLISHER;
                    break;
                case NPC_GLAIVE_THROWER_A:
                case NPC_GLAIVE_THROWER_H:
                    spellId = SPELL_DRIVING_CREDIT_GLAIVE;
                    break;
                case NPC_SIEGE_ENGINE_H:
                case NPC_SIEGE_ENGINE_A:
                    spellId = SPELL_DRIVING_CREDIT_SIEGE;
                    break;
                case NPC_CATAPULT:
                    spellId = SPELL_DRIVING_CREDIT_CATAPULT;
                    break;
                default:
                    return;
            }

            me->CastSpell(who, spellId, true);
        }
    }
};

enum Events
{
    EVENT_TALK  = 1,
    EVENT_DESPAWN
};

enum Texts
{
    SAY_ONBOARD = 0
};

struct npc_ioc_gunship_captain : public ScriptedAI
{
    npc_ioc_gunship_captain(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_GUNSHIP_READY)
        {
            DoCast(me, SPELL_SIMPLE_TELEPORT);
            _events.ScheduleEvent(EVENT_TALK, 3s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK:
                    _events.ScheduleEvent(EVENT_DESPAWN, 1s);
                    Talk(SAY_ONBOARD);
                    DoCast(me, SPELL_TELEPORT_VISUAL_ONLY);
                    break;
                case EVENT_DESPAWN:
                    if (BattlegroundMap* iocMap = me->GetMap()->ToBattlegroundMap())
                        if (Battleground* bgIoC = iocMap->GetBG())
                            bgIoC->DelCreature(BG_IC_NPC_GUNSHIP_CAPTAIN_1);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 66630 - Alliance Gunship Portal
// 66637 - Horde Gunship Portal
class spell_ioc_gunship_portal : public SpellScript
{
    PrepareSpellScript(spell_ioc_gunship_portal);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        /*
         * HACK: GetWorldLocation() returns real position and not transportposition.
         * ServertoClient: SMSG_MOVE_TELEPORT (0x0B39)
         * counter: 45
         * Tranpsort Guid: Full: xxxx Type: MOTransport Low: xxx
         * Transport Position X: 0 Y: 0 Z: 0 O: 0
         * Position: X: 7.305609 Y: -0.095246 Z: 34.51022 O: 0
         */
        caster->TeleportTo(GetHitCreature()->GetWorldLocation(), TELE_TO_NOT_LEAVE_TRANSPORT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ioc_gunship_portal::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 66656 - Parachute
class spell_ioc_parachute_ic : public AuraScript
{
    PrepareAuraScript(spell_ioc_parachute_ic);

    void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Player* target = GetTarget()->ToPlayer())
            if (target->m_movementInfo.fallTime > 2000 && !target->GetTransport())
                target->CastSpell(target, SPELL_PARACHUTE_IC, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ioc_parachute_ic::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class StartLaunchEvent : public BasicEvent
{
    public:
        StartLaunchEvent(Position const& pos, ObjectGuid::LowType lowGuid) : _pos(pos), _lowGuid(lowGuid)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            Player* player = ObjectAccessor::FindPlayerByLowGUID(_lowGuid);
            if (!player || !player->GetVehicle())
                return true;

            player->AddAura(SPELL_LAUNCH_NO_FALLING_DAMAGE, player); // prevents falling damage
            float speedZ = 10.0f;
            float dist = player->GetExactDist2d(&_pos);

            player->ExitVehicle();
            player->GetMotionMaster()->MoveJump(_pos, dist, speedZ, EVENT_JUMP, true);
            return true;
        }

    private:
        Position _pos;
        ObjectGuid::LowType _lowGuid;
};

// 66218 - Launch
class spell_ioc_launch : public SpellScript
{
    PrepareSpellScript(spell_ioc_launch);

    void Launch()
    {
        if (!GetCaster()->ToCreature() || !GetExplTargetDest())
            return;

        GetCaster()->ToCreature()->m_Events.AddEvent(new StartLaunchEvent(*GetExplTargetDest(), ASSERT_NOTNULL(GetHitPlayer())->GetGUID().GetCounter()), GetCaster()->ToCreature()->m_Events.CalculateTime(2500ms));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_ioc_launch::Launch);
    }
};

enum SeaforiumBombSpells
{
    SPELL_SEAFORIUM_BLAST         = 66676,
    SPELL_SEAFORIUM_BLAST_H       = 67814,
    SPELL_HUGE_SEAFORIUM_BLAST    = 66672,
    SPELL_HUGE_SEAFORIUM_BLAST_H  = 67813,
    SPELL_A_BOMB_INABLE_CREDIT    = 68366,
    SPELL_A_BOMB_INATION_CREDIT   = 68367
};

// 66672 - Huge Seaforium Blast
// 66676 - Seaforium Blast
class spell_ioc_seaforium_blast_credit : public SpellScript
{
    PrepareSpellScript(spell_ioc_seaforium_blast_credit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_A_BOMB_INABLE_CREDIT, SPELL_A_BOMB_INATION_CREDIT });
    }

    void HandleAchievementCredit(SpellEffIndex /*effIndex*/)
    {
        uint32 _creditSpell = 0;
        Unit* caster = GetOriginalCaster();
        if (!caster)
            return;

        uint32 spellId = GetSpellInfo()->Id;
        if (spellId == SPELL_SEAFORIUM_BLAST || spellId == SPELL_SEAFORIUM_BLAST_H)
            _creditSpell = SPELL_A_BOMB_INABLE_CREDIT;
        else if (spellId == SPELL_HUGE_SEAFORIUM_BLAST || spellId == SPELL_HUGE_SEAFORIUM_BLAST_H)
            _creditSpell = SPELL_A_BOMB_INATION_CREDIT;

        if (GetHitGObj() && GetHitGObj()->IsDestructibleBuilding())
            caster->CastSpell(caster, _creditSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ioc_seaforium_blast_credit::HandleAchievementCredit, EFFECT_1, SPELL_EFFECT_GAMEOBJECT_DAMAGE);
    }
};

void AddSC_isle_of_conquest()
{
    RegisterCreatureAI(npc_four_car_garage);
    RegisterCreatureAI(npc_ioc_gunship_captain);
    RegisterSpellScript(spell_ioc_gunship_portal);
    RegisterSpellScript(spell_ioc_parachute_ic);
    RegisterSpellScript(spell_ioc_launch);
    RegisterSpellScript(spell_ioc_seaforium_blast_credit);
}
