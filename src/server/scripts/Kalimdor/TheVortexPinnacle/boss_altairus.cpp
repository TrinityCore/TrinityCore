/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008 - 2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "SpellScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Cell.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "the_vortex_pinnacle.h"

enum spells
{
    SPELL_CHILLING_BREATH               = 88308,
    SPELL_UPWIND_OF_ALTAIRUS            = 88282,
    SPELL_DOWNWIND_OF_ALTAIRUS          = 88286,
    SPELL_TWISTER_AURA                  = 88313,
    SPELL_LIGHTNING_BLAST               = 88357,
    SPELL_SAFE_ZONE                     = 88350,
    SPELL_CALL_THE_WIND_VISUAL          = 88772,
    SPELL_WIND_OF_ALTAIRUS              = 88244
};

enum events
{
    EVENT_CHILLING_BREATH               = 1,
    EVENT_SUMMON                        = 2,
    EVENT_CALL_THE_WIND                 = 3,
    EVENT_DOWNWIND_OF_ALTAIRUS          = 4,
    EVENT_LIGHTNING_BLAST               = 5,
    EVENT_CALL_THE_WIND_POST            = 6
};

enum Texts
{
    EMOTE_WINDS                         = 0
};

Position const platform = { -1213.83f, 62.99f, 735.2f, 0.0f };

Position const summonPositions[4] =
{
    {-1208.316f, 74.2533f, 734.174f, 4.89f},
    {-1222.620f, 73.7265f, 734.174f, 4.89f},
    {-1224.178f, 60.8424f, 734.174f, 4.89f},
    {-1218.436f, 46.5356f, 734.174f, 4.89f},
};

class MoveTornade : public BasicEvent
{
public:
    MoveTornade(Unit* owner) : _owner(owner), _instance(owner->GetInstanceScript())
    {
    }

    bool Execute(uint64 execTime, uint32 /*diff*/) override
    {
        if (!_owner->HasAura(SPELL_TWISTER_AURA))
            _owner->CastSpell(_owner, SPELL_TWISTER_AURA, true);
        _owner->m_Events.AddEvent(this, execTime + 1000);
        return false;
    }

private:
    Unit* _owner;
    InstanceScript* _instance;
};


class boss_altairus : public CreatureScript
{
public:
    boss_altairus() : CreatureScript("boss_altairus")
    {
    }

    struct boss_altairusAI : public BossAI
    {
        boss_altairusAI(Creature* creature) : BossAI(creature, BOSS_ALTAIRUS)
        {
        }

        void Reset() override
        {
            _Reset();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WIND_OF_ALTAIRUS);
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            //me->SetHoverGroundTargetable(true);
            //me->SetHover(true);
            summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            events.ScheduleEvent(EVENT_CALL_THE_WIND, urand(7500, 10000));
            events.ScheduleEvent(EVENT_CHILLING_BREATH, urand(20000, 30000));
            events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 1000);

            if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON, urand(2000, 3000), 0, 0);
        }

        void JustReachedHome() override
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WIND_OF_ALTAIRUS);
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_WIND:
                    summoned->CastSpell(summoned, SPELL_CALL_THE_WIND_VISUAL, true);
                    break;
                case NPC_TWISTER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                    {
                        summoned->SetSpeed(MOVE_RUN, 0.4f);
                        summoned->SetSpeed(MOVE_WALK, 0.4f);
                        summoned->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        summoned->Attack(target, true);
                        summoned->AddAura(88313, summoned);
                        summoned->GetMotionMaster()->MoveChase(target, 1.0f, 1.0f);
                        summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                    break;
                default:
                    break;
            }
            summons.Summon(summoned);
        }

        void JustDied(Unit* /*who*/) override
        {
            _JustDied();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
            summons.DespawnAll();
            me->SetHover(false);

            Creature * Slipstream = me->SummonCreature(NPC_SLIPSTREAM_TWO, -1198.95f, 106.13f, 743.16f, 1.2f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHILLING_BREATH:
                        DoCastRandom(SPELL_CHILLING_BREATH, 0.0f);
                        events.ScheduleEvent(EVENT_CHILLING_BREATH, urand(7500, 12500));
                        break;
                    case EVENT_SUMMON:
                        for (uint8 i = 0; i < 4; i++)
                        {
                            if (urand(0, 3) == 1)
                                me->SummonCreature(NPC_TWISTER, summonPositions[i], TEMPSUMMON_TIMED_DESPAWN, 7000);
                        }
                        events.ScheduleEvent(EVENT_SUMMON, urand(6000, 9000), 0, 0);
                        break;
                    case EVENT_CALL_THE_WIND:
                    {
                        if (Creature *c = me->FindNearestCreature(NPC_WIND, 100))
                            c->DespawnOrUnsummon();
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WIND_OF_ALTAIRUS);
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOWNWIND_OF_ALTAIRUS);
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UPWIND_OF_ALTAIRUS);
                        events.ScheduleEvent(EVENT_CALL_THE_WIND, urand(14000, 19000));
                        events.ScheduleEvent(EVENT_CALL_THE_WIND_POST, 2000);
                        break;
                    }
                    case EVENT_CALL_THE_WIND_POST:
                    {
                        Talk(EMOTE_WINDS);
                        float orientation = 0.0f;
                        switch (rand() % 4)
                        {
                            case 0:
                                orientation = float(M_PI) / 2.0f;
                                break;
                            case 1:
                                orientation = float(M_PI);
                                break;
                            case 2:
                                orientation = 3.0f * float(M_PI) / 2.0f;
                                break;
                            case 3:
                                orientation = 2.0f * float(M_PI);
                                break;
                            default:
                                orientation = float(M_PI);
                                break;
                        }
                        me->SummonCreature(NPC_WIND, -1213.83f, 62.99f, 734.2f, orientation, TEMPSUMMON_MANUAL_DESPAWN);
                        WindOfAltairus();
                        events.CancelEvent(EVENT_CALL_THE_WIND_POST);
                        break;
                    }
                    case EVENT_LIGHTNING_BLAST:
                        CheckPlatform();
                        events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 5000);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void WindOfAltairus()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        player->CastSpell(player, SPELL_WIND_OF_ALTAIRUS, true);
        }

        void CheckPlatform()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (!playerList.isEmpty())
                for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (player->GetDistance2d(platform.m_positionX, platform.m_positionY) > 25.0f)
                            me->CastSpell(player, SPELL_LIGHTNING_BLAST, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<boss_altairusAI>(creature);
    }
};

class spell_wind_of_alth : public SpellScriptLoader
{
public:
    spell_wind_of_alth() : SpellScriptLoader("spell_wind_of_alth") { }

    class spell_wind_of_alth_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_wind_of_alth_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        void RemovedWrongAuras()
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_WIND_OF_ALTAIRUS);
            GetCaster()->RemoveAurasDueToSpell(SPELL_UPWIND_OF_ALTAIRUS);
            GetCaster()->RemoveAurasDueToSpell(SPELL_DOWNWIND_OF_ALTAIRUS);
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            if (!GetCaster())
                return;
            if (Creature *c = GetCaster()->FindNearestCreature(42844, 100, true))
            {
                if (InstanceScript *instance = c->GetInstanceScript())
                {
                    if (instance->GetBossState(BOSS_ALTAIRUS) != IN_PROGRESS)
                    {
                        RemovedWrongAuras();
                        return;
                    }
                    if (Creature *wind = instance->instance->GetCreature(instance->GetGuidData(NPC_WIND)))
                    {
                        float windOrientation = wind->GetOrientation();
                        float orientationDiff = GetCaster()->GetOrientation();
                        float left_limit = windOrientation - M_PI / 2;
                        float right_limit = windOrientation + M_PI / 2;
                        if (orientationDiff >= left_limit && orientationDiff <= right_limit)
                        {
                            if (GetCaster()->HasAura(SPELL_UPWIND_OF_ALTAIRUS))
                                GetCaster()->RemoveAurasDueToSpell(SPELL_UPWIND_OF_ALTAIRUS);
                            if (!GetCaster()->HasAura(SPELL_DOWNWIND_OF_ALTAIRUS))
                                GetCaster()->AddAura(SPELL_DOWNWIND_OF_ALTAIRUS, GetCaster());
                        }
                        else
                        {
                            if (GetCaster()->HasAura(SPELL_DOWNWIND_OF_ALTAIRUS))
                                GetCaster()->RemoveAurasDueToSpell(SPELL_DOWNWIND_OF_ALTAIRUS);
                            if (!GetCaster()->HasAura(SPELL_UPWIND_OF_ALTAIRUS))
                                GetCaster()->AddAura(SPELL_UPWIND_OF_ALTAIRUS, GetCaster());
                        }
                    }
                }
                else
                    RemovedWrongAuras();
            }
            else
                RemovedWrongAuras();
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_wind_of_alth_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_wind_of_alth_AuraScript();
    }
};

void AddSC_boss_altairus()
{
    new boss_altairus();
    new spell_wind_of_alth();
}
