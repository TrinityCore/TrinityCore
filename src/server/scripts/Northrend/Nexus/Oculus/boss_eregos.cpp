/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "oculus.h"

//Types of drake mounts: Ruby(Tank),  Amber(DPS),  Emerald(Healer)
//Two Repeating phases

enum Events
{
    EVENT_ARCANE_BARRAGE = 1,
    EVENT_ARCANE_VOLLEY,
    EVENT_ENRAGED_ASSAULT,
    EVENT_SUMMON_LEY_WHELP
};

enum Says
{
    SAY_SPAWN  = -1578022,
    SAY_AGGRO  = -1578023,
    SAY_ENRAGE = -1578024,
    SAY_KILL_1 = -1578025,
    SAY_KILL_2 = -1578026,
    SAY_KILL_3 = -1578027,
    SAY_DEATH  = -1578028,
};

enum Spells
{
    SPELL_ARCANE_BARRAGE                          = 50804,
    SPELL_ARCANE_VOLLEY                           = 51153,
    SPELL_ENRAGED_ASSAULT                         = 51170,
    SPELL_PLANAR_ANOMALIES                        = 57959,
    SPELL_PLANAR_SHIFT                            = 51162,
    SPELL_SUMMON_LEY_WHELP                        = 51175,
};

enum Npcs
{
    NPC_PLANAR_ANOMALY = 30879
};

enum Phases
{
    PHASE_NORMAL = 1,
    PHASE_FIRST_PLANAR = 2,
    PHASE_SECOND_PLANAR = 3
};

enum Actions
{
    ACTION_SET_NORMAL_EVENTS = 1
};

#define DATA_EMERALD_VOID  0
#define DATA_RUBY_VOID     1
#define DATA_AMBER_VOID    2

class boss_eregos : public CreatureScript
{
public:
    boss_eregos() : CreatureScript("boss_eregos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_eregosAI (creature);
    }

    struct boss_eregosAI : public BossAI
    {
        boss_eregosAI(Creature* creature) : BossAI(creature, DATA_EREGOS_EVENT)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset()
        {
            _Reset();

            phase = PHASE_NORMAL;

            me->SetSpeed(MOVE_FLIGHT, 2.8f);
            DoAction(ACTION_SET_NORMAL_EVENTS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            DoScriptText(SAY_AGGRO, me);
        }

        void DoAction(const int32 action)
        {
            if (action != ACTION_SET_NORMAL_EVENTS)
                return;

            events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(3, 10) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_ARCANE_VOLLEY, urand(10, 25) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_ENRAGED_ASSAULT, urand(35, 50) * IN_MILLISECONDS, 0, PHASE_NORMAL);
            events.ScheduleEvent(EVENT_SUMMON_LEY_WHELP, urand(15, 30) * IN_MILLISECONDS, 0, PHASE_NORMAL);
        }


        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
        {
            if (!me->GetMap()->IsHeroic())
                return;

            if ((me->HealthBelowPct(60) && me->HealthAbovePct(20) && phase < PHASE_FIRST_PLANAR) ||
                (me->HealthBelowPct(20) && phase < PHASE_SECOND_PLANAR))
            {
                events.Reset();
                phase = (me->HealthBelowPct(60)  && me->HealthAbovePct(20)) ? PHASE_FIRST_PLANAR : PHASE_SECOND_PLANAR;
                // Planar anomalies are summoned on SpellScript
                DoCast(SPELL_PLANAR_SHIFT);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ARCANE_BARRAGE:
                        DoCast(me->getVictim(), SPELL_ARCANE_BARRAGE);
                        events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(3, 10) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_ARCANE_VOLLEY:
                        DoCastAOE(SPELL_ARCANE_VOLLEY);
                        events.ScheduleEvent(EVENT_ARCANE_VOLLEY, urand(10, 25) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_ENRAGED_ASSAULT:
                        DoScriptText(SAY_ENRAGE, me);
                        DoCast(SPELL_ENRAGED_ASSAULT);
                        events.ScheduleEvent(EVENT_ENRAGED_ASSAULT, urand(35, 50) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                    case EVENT_SUMMON_LEY_WHELP:
                        for (uint8 i = 0; i < 3; i++)
                            DoCast(SPELL_SUMMON_LEY_WHELP);
                        events.ScheduleEvent(EVENT_SUMMON_LEY_WHELP, urand(15, 30) * IN_MILLISECONDS, 0, PHASE_NORMAL);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_AMBER_VOID:
                    return uiAmberDrakes;
                case DATA_EMERALD_VOID:
                    return uiEmeraldDrakes;
                case DATA_RUBY_VOID:
                    return uiRubyDrakes;
            }

            return 0;
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            //Achievements
            uiRubyDrakes = 0;
            uiEmeraldDrakes = 0;
            uiAmberDrakes = 0;

            if (IsHeroic())
            {
                Map::PlayerList const &players = pInstance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    // Check every player's drake for void achievements
                    if (Unit* drake = itr->getSource()->GetVehicleBase())
                    {
                        switch(drake->GetEntry())
                        {
                            case NPC_AMBER_DRAKE_VEHICLE:
                                                              uiAmberDrakes++;
                                break;
                            case NPC_RUBY_DRAKE_VEHICLE:
                                uiRubyDrakes++;
                                break;
                            case NPC_EMERALD_DRAKE_VEHICLE:
                                uiEmeraldDrakes++;
                                break;
                        }
                    }
                }
            }

            _JustDied();
        }

    private:
        uint8 phase;
        uint8 uiRubyDrakes;
        uint8 uiEmeraldDrakes;
        uint8 uiAmberDrakes;
    };
};

enum AnomalySpells
{
    SPELL_PLANAR_BLAST      = 57976, // Final damage spell
    SPELL_PLANAR_DISTORTION = 59379, // Periodic damage aura
    SPELL_PLANAR_SPARK      = 57971, // Visual
};

class mob_planar_anomaly : public CreatureScript
{
public:
    mob_planar_anomaly() : CreatureScript("mob_planar_anomaly") { }

    struct mob_planar_anomalyAI : public ScriptedAI
    {
        mob_planar_anomalyAI(Creature *creature) : ScriptedAI(creature) {}

        uint32 uiBlastTimer;

        void Reset()
        {
            uiBlastTimer = 16000;
            me->SetCanFly(true);
            me->SetSpeed(MOVE_FLIGHT, 3.1f);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->AddAura(SPELL_PLANAR_DISTORTION, me);
            me->AddAura(SPELL_PLANAR_SPARK, me);
            me->DespawnOrUnsummon(18000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            if(uiBlastTimer && uiBlastTimer <= uiDiff)
            {
                DoCastAOE(SPELL_PLANAR_BLAST, true);
                uiBlastTimer = 0;
            }
            else
                uiBlastTimer -= uiDiff;
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_planar_anomalyAI(creature);
    }
};

class spell_eregos_planar_shift : public SpellScriptLoader
{
    public:
        spell_eregos_planar_shift() : SpellScriptLoader("spell_eregos_planar_shift") { }

        class spell_eregos_planar_shift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_eregos_planar_shift_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creatureCaster = caster->ToCreature())
                        if(InstanceScript* instance = caster->GetInstanceScript())
                        {
                            Map::PlayerList const &players = instance->instance->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* player = itr->getSource())
                                    if(Creature* anomaly = player->SummonCreature(NPC_PLANAR_ANOMALY, player->GetPositionX() + urand(5, 10), player->GetPositionY() + urand(5, 10), player->GetPositionZ()))
                                        if(Unit* drake = player->GetVehicleBase())
                                            anomaly->GetMotionMaster()->MoveChase(drake);
                                        else
                                            anomaly->GetMotionMaster()->MoveChase(player);
                        }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creatureCaster = caster->ToCreature())
                        creatureCaster->AI()->DoAction(ACTION_SET_NORMAL_EVENTS);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_eregos_planar_shift_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_eregos_planar_shift_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_eregos_planar_shift_AuraScript();
        }
};

class achievement_amber_void : public AchievementCriteriaScript
{
    public:
        achievement_amber_void() : AchievementCriteriaScript("achievement_amber_void") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Creature* eregos = target->ToCreature())
                if (eregos->AI()->GetData(DATA_AMBER_VOID) == 0)
                    return true;

            return false;
        }
};

class achievement_amber_drake_rider : public AchievementCriteriaScript
{
    public:
        achievement_amber_drake_rider() : AchievementCriteriaScript("achievement_amber_drake_rider") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Unit* drake = player->GetVehicleBase())
                if (drake->GetEntry() == NPC_AMBER_DRAKE_VEHICLE)
                    return true;

            return false;
        }
};

class achievement_ruby_void : public AchievementCriteriaScript
{
    public:
        achievement_ruby_void() : AchievementCriteriaScript("achievement_ruby_void") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Creature* eregos = target->ToCreature())
                if (eregos->AI()->GetData(DATA_RUBY_VOID) == 0)
                    return true;

            return false;
        }
};

class achievement_ruby_drake_rider : public AchievementCriteriaScript
{
    public:
        achievement_ruby_drake_rider() : AchievementCriteriaScript("achievement_ruby_drake_rider") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Unit* drake = player->GetVehicleBase())
                if (drake->GetEntry() == NPC_RUBY_DRAKE_VEHICLE)
                    return true;

            return false;
        }
};

class achievement_emerald_void : public AchievementCriteriaScript
{
    public:
        achievement_emerald_void() : AchievementCriteriaScript("achievement_emerald_void") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Creature* eregos = target->ToCreature())
                if (eregos->AI()->GetData(DATA_EMERALD_VOID) == 0)
                    return true;

            return false;
        }
};

class achievement_emerald_drake_rider : public AchievementCriteriaScript
{
    public:
        achievement_emerald_drake_rider() : AchievementCriteriaScript("achievement_emerald_drake_rider") {}

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target || !player)
                return false;

            if (Unit* drake = player->GetVehicleBase())
                if (drake->GetEntry() == NPC_EMERALD_DRAKE_VEHICLE)
                    return true;

            return false;
        }
};

void AddSC_boss_eregos()
{
    new boss_eregos();
    new mob_planar_anomaly();
    new spell_eregos_planar_shift();
    new achievement_amber_void();
    new achievement_ruby_void();
    new achievement_emerald_void();
    new achievement_amber_drake_rider();
    new achievement_ruby_drake_rider();
    new achievement_emerald_drake_rider();
}
