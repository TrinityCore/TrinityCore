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

#include "oculus.h"
#include "Containers.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_ARCANE_SHIELD                           = 53813,
    SPELL_SUMMON_MENAGERIE                        = 50476,
    SPELL_SUMMON_MENAGERIE_2                      = 50495,
    SPELL_SUMMON_MENAGERIE_3                      = 50496,
    SPELL_EMPOWERED_ARCANE_EXPLOSION              = 51110,
    SPELL_FROSTBOMB                               = 51103,
    SPELL_TELEPORT                                = 51112,
    SPELL_TIME_BOMB                               = 51121,
    SPELL_EVOCATE                                 = 51602,
    SPELL_FROST_BUFFET                            = 58025
};

enum Events
{
    EVENT_FROST_BOMB = 1,
    EVENT_TIME_BOMB,
    EVENT_CAST_EXPLOSION,
    EVENT_TELEPORT,
    EVENT_TELEPORT_BACK
};

enum Yells
{
    SAY_SUMMON_1                                  = 0,
    SAY_SUMMON_2                                  = 1,
    SAY_SUMMON_3                                  = 2,
    SAY_AGGRO                                     = 3,
    EMOTE_ARCANE_EXPLOSION                        = 4,
    SAY_ARCANE_EXPLOSION                          = 5,
    SAY_DEATH                                     = 6,
    SAY_PLAYER_KILL                               = 7
};

enum Creatures
{
    NPC_PHANTASMAL_CLOUDSCRAPER                   = 27645,
    NPC_PHANTASMAL_MAMMOTH                        = 27642,
    NPC_PHANTASMAL_WOLF                           = 27644,

    NPC_PHANTASMAL_AIR                            = 27650,
    NPC_PHANTASMAL_FIRE                           = 27651,
    NPC_PHANTASMAL_WATER                          = 27653,

    NPC_PHANTASMAL_MURLOC                         = 27649,
    NPC_PHANTASMAL_NAGAL                          = 27648,
    NPC_PHANTASMAL_OGRE                           = 27647
};

struct Summons
{
    uint32 entry[4];
};

static Summons Group[]=
{
    { {NPC_PHANTASMAL_CLOUDSCRAPER, NPC_PHANTASMAL_CLOUDSCRAPER, NPC_PHANTASMAL_MAMMOTH, NPC_PHANTASMAL_WOLF} },
    { {NPC_PHANTASMAL_AIR, NPC_PHANTASMAL_AIR, NPC_PHANTASMAL_WATER, NPC_PHANTASMAL_FIRE} },
    { {NPC_PHANTASMAL_OGRE, NPC_PHANTASMAL_OGRE, NPC_PHANTASMAL_NAGAL, NPC_PHANTASMAL_MURLOC} }
};

static uint32 TeleportSpells[]=
{
    SPELL_SUMMON_MENAGERIE, SPELL_SUMMON_MENAGERIE_2, SPELL_SUMMON_MENAGERIE_3
};

struct boss_urom : public BossAI
{
    boss_urom(Creature* creature) : BossAI(creature, DATA_UROM)
    {
        _platform = 0;
        _x = 0.0f;
        _y = 0.0f;
        _isInCenter = false;

        for (uint8 i = 0; i < 3; ++i)
            _group.push_back(i);

        Trinity::Containers::RandomShuffle(_group);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        // We can only evade if we're in the center platform
        if (_platform > 2)
        {
            _EnterEvadeMode(why);

            // If we're in the center, teleport to start position
            if (_isInCenter)
                me->NearTeleportTo(1118.3101f, 1080.3800f, 508.3610f, 4.25f);
            else
                me->GetMotionMaster()->MoveTargetedHome();

            Reset();
            events.Reset();
        }
    }

    void Reset() override
    {
        _isInCenter = false;
        me->SetControlled(false, UNIT_STATE_ROOT);
        me->SetDisableGravity(false);
        me->SetReactState(REACT_AGGRESSIVE);
        DoCastSelf(SPELL_EVOCATE);
        _Reset();
    }

    void JustReachedHome() override
    {
        DoCastSelf(SPELL_EVOCATE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        StartAttack();
    }

    void AttackStart(Unit* who) override
    {
        if (!who)
            return;

        if (me->GetPositionZ() > 518.63f)
            DoStartNoMovement(who);
        else
            BossAI::AttackStart(who);
    }

    void SetPosition(uint8 i)
    {
        switch (i)
        {
            case 0:
                _x = me->GetPositionX() + 4;
                _y = me->GetPositionY() - 4;
                break;
            case 1:
                _x = me->GetPositionX() + 4;
                _y = me->GetPositionY() + 4;
                break;
            case 2:
                _x = me->GetPositionX() - 4;
                _y = me->GetPositionY() + 4;
                break;
            case 3:
                _x = me->GetPositionX() - 4;
                _y = me->GetPositionY() - 4;
                break;
            default:
                break;
        }
    }

    void StartAttack()
    {
        // We're in center - start fight normally
        if (_platform > 2)
        {
            me->CastStop(); // Stop casting of Evocation
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_TELEPORT, 30s, 35s);
            events.ScheduleEvent(EVENT_FROST_BOMB, 5s, 8s);
            events.ScheduleEvent(EVENT_TIME_BOMB, 20s, 25s);
            return;
        }

        // We're on one of the three platforms - summon guards and jump to next platform
        for (uint8 i = 0; i < 4; ++i)
        {
            SetPosition(i);
            me->SummonCreature(Group[_group[_platform]].entry[i], _x, _y, me->GetPositionZ(), me->GetOrientation());
        }

        Talk(_platform);
        DoCast(TeleportSpells[_platform]);

        ++_platform;
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_PLAYER_KILL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (_platform < 3)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TELEPORT:
                    events.DelayEvents(10s);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->StopMoving();
                    me->SetDisableGravity(true);
                    me->SetCanFly(true);
                    me->SetControlled(true, UNIT_STATE_ROOT); // @hack: disabling gravity isn't enough to prevent falling
                    DoCast(SPELL_TELEPORT);
                    _isInCenter = true;
                    events.ScheduleEvent(EVENT_CAST_EXPLOSION, 2s);
                    break;
                case EVENT_CAST_EXPLOSION:
                    Talk(EMOTE_ARCANE_EXPLOSION);
                    Talk(SAY_ARCANE_EXPLOSION);
                    DoCastAOE(SPELL_EMPOWERED_ARCANE_EXPLOSION);
                    events.ScheduleEvent(EVENT_TELEPORT_BACK, DUNGEON_MODE(10s, 8s));
                    break;
                case EVENT_TELEPORT_BACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetDisableGravity(false);
                    me->SetCanFly(false);
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    if (Unit* victim = me->SelectVictim())
                    {
                        me->NearTeleportTo(victim->GetPosition());
                        AttackStart(victim);
                    }
                    _isInCenter = false;
                    events.ScheduleEvent(EVENT_TELEPORT, 30s, 35s);
                    break;
                case EVENT_FROST_BOMB:
                    DoCastVictim(SPELL_FROSTBOMB);
                    events.ScheduleEvent(EVENT_FROST_BOMB, 5s, 8s);
                    break;
                case EVENT_TIME_BOMB:
                    if (Unit* unit = SelectTarget(SelectTargetMethod::Random))
                        DoCast(unit, SPELL_TIME_BOMB);
                    events.ScheduleEvent(EVENT_TIME_BOMB, 20s, 25s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCastSelf(SPELL_DEATH_SPELL, true);
    }

    void LeaveCombat()
    {
        me->RemoveAllAuras();
        me->CombatStop(false);
        EngagementOver();
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SUMMON_MENAGERIE:
                me->SetHomePosition(968.66f, 1042.53f, 527.32f, 0.077f);
                LeaveCombat();
                DoCastSelf(SPELL_EVOCATE, true);
                break;
            case SPELL_SUMMON_MENAGERIE_2:
                me->SetHomePosition(1164.02f, 1170.85f, 527.321f, 3.66f);
                LeaveCombat();
                DoCastSelf(SPELL_EVOCATE, true);
                break;
            case SPELL_SUMMON_MENAGERIE_3:
                me->SetHomePosition(1118.31f, 1080.377f, 508.361f, 4.25f);
                LeaveCombat();
                DoCastSelf(SPELL_EVOCATE, true);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // If killed while in center, teleport to a valid ground position before dying
        if (damage >= me->GetHealth())
        {
            if (_isInCenter)
            {
                _isInCenter = false;
                me->NearTeleportTo(1124.0432f, 1078.2109f, 508.3597f, 5.4623f);
            }
        }
    }

private:
    float _x, _y;
    bool _isInCenter;
    uint8 _platform;
    std::vector<uint8> _group;
};

// 51103 - Frostbomb
class spell_urom_frostbomb : public AuraScript
{
    PrepareAuraScript(spell_urom_frostbomb);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BUFFET });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->GetMap()->IsHeroic() && caster->IsInCombat())
                if (Unit* target = GetTarget())
                    caster->CastSpell(target, SPELL_FROST_BUFFET, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_urom_frostbomb::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_urom()
{
    RegisterOculusCreatureAI(boss_urom);
    RegisterSpellScript(spell_urom_frostbomb);
}
