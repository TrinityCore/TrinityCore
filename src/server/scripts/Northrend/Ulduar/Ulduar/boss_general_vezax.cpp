/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuraEffects.h"
#include "ulduar.h"

enum Yells
{
    SAY_AGGRO                                   = -1603290,
    SAY_SLAY_1                                  = -1603291,
    SAY_SLAY_2                                  = -1603292,
    SAY_KITE                                    = -1603293,
    SAY_DEATH                                   = -1603294,
    SAY_BERSERK                                 = -1603295,
    SAY_HARDMODE_ON                             = -1603296,
};

enum Emotes
{
    EMOTE_VAPORS                                = -1603289,
    EMOTE_ANIMUS                                = -1603297,
    EMOTE_BARRIER                               = -1603298,
    EMOTE_SURGE_OF_DARKNESS                     = -1603299,
};

enum Spells
{
    // General Vezax
    SPELL_AURA_OF_DESPAIR                       = 62692, // on combat start
    SPELL_AURA_OF_DESPAIR_EFFEKT_DESPAIR        = 64848, // dont know if needet ... need test
    SPELL_CORRUPTED_RAGE                        = 68415,
    SPELL_MARK_OF_THE_FACELESS                  = 63276, // Unknown Aura
    SPELL_MARK_OF_THE_FACELESS_LEECH            = 63278, // Leech Health 1 ... need custom cast
    SPELL_SARONIT_BARRIER                       = 63364, // Script Effekt, Apply while Saronit Animus spawned
    SPELL_SEARING_FLAMES                        = 62661,
    SPELL_SHADOW_CRASH                          = 62660, // Trigger Missile 62659 and 63277
    SPELL_SHADOW_CRASH_DAMAGE                   = 62659, // Explosion Damage
    SPELL_SHADOW_CRASH_AURA                     = 63277, // Triggered Cloud
    SPELL_SURGE_OF_DARKNESS                     = 62662, // every 60 seconds
    SPELL_SUMMON_SARONIT_VAPOR                  = 63081, // every 30 seconds
    // Saronit Animus - Spawnd after 6th Saronit Vapor
    SPELL_PROFOUND_DARKNESS                     = 63420,
    SPELL_VISUAL_SARONITE_ANIMUS                = 63319,
    // Saronit Vapor
    SPELL_SARONIT_VAPOR                         = 63323, // Casted on Death trigger 63322
    SPELL_SARONIT_VAPOR_AURA                    = 63322, // Unknown Aura Dummy needs Scripting ?
    // Player Shaman
    SPELL_SHAMANTIC_RAGE                        = 30823,
    SPELL_BERSERK                               = 47008,
};

enum NPCs
{
    ENTRY_GENERAL_VEZAX                         = 33271,
    ENTRY_SARONIT_VAPOR                         = 33488,
    ENTRY_SARONIT_ANIMUS                        = 33524
};

enum Data
{
    DATA_SMELL_OF_SARONITE,
    DATA_SHADOWDODGER
};

enum Actions
{
    ACTION_VAPOR_KILLED,
    ACTION_ANIMUS_KILLED
};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_SUMMON_VAPOR,
    EVENT_SURGE_OF_DARKNESS,
    EVENT_SHADOW_CRASH,
    EVENT_RESET_TARGET,
    EVENT_SEARING_FLAMES,
    EVENT_RESET_IMMUNITY,
    EVENT_MARK_OF_THE_FACELESS
};

class boss_general_vezax : public CreatureScript
{
    public:
        boss_general_vezax() : CreatureScript("boss_general_vezax") { }

        struct boss_general_vezaxAI : public BossAI
        {
            boss_general_vezaxAI(Creature* c) : BossAI(c, BOSS_VEZAX)
            {
            }

            void Reset()
            {
                _Reset();

                _vaporList.clear();
                _guidSaronitAnimus = 0;
                _animusSummoned = false;
                _hitByShadowCrash = false;
                _animusKilled = false;
                _vaporKilled = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();

                //DoCast(me, SPELL_CORRUPTED_RAGE, true);
                DoCast(SPELL_AURA_OF_DESPAIR);
                DoScriptText(SAY_AGGRO, me);

                events.ScheduleEvent(EVENT_SUMMON_VAPOR, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 60*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHADOW_CRASH, 10*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(5, 10) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(15, 25) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 10*MINUTE*IN_MILLISECONDS);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (target && target->ToPlayer())
                {
                    switch (spell->Id)
                    {
                        case SPELL_SHADOW_CRASH_DAMAGE:
                            _hitByShadowCrash = true;
                            break;
                    }
                }
            }

            void JustSummoned(Creature* summoned)
            {
                switch (summoned->GetEntry())
                {
                    case ENTRY_SARONIT_VAPOR:
                        _vaporList.push_back(summoned->GetGUID());
                        if (!_vaporKilled && _vaporList.size() > 5)
                            if (Creature* animus = DoSummon(ENTRY_SARONIT_ANIMUS, me->GetHomePosition(), 30000, TEMPSUMMON_MANUAL_DESPAWN))
                                animus->AI()->AttackStart(me->getVictim());
                        break;
                    case ENTRY_SARONIT_ANIMUS:
                        _guidSaronitAnimus = summoned->GetGUID();
                        _animusSummoned = true;
                        events.CancelEvent(EVENT_SEARING_FLAMES);
                        DoScriptText(SAY_HARDMODE_ON, me);
                        DoScriptText(EMOTE_BARRIER, me);
                        me->InterruptNonMeleeSpells(false);
                        DoCast(SPELL_SARONIT_BARRIER);
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                        break;
                }

                summons.Summon(summoned);
                DoZoneInCombat(summoned);
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (urand(0, 5) == 0)
                    DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(SAY_DEATH, me);
                _JustDied();
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_SMELL_OF_SARONITE)
                    return (!_vaporKilled && _animusSummoned && _animusKilled) ? 1 : 0;
                if (type == DATA_SHADOWDODGER)
                    return !_hitByShadowCrash ? 1 : 0;

                return 0;
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_VAPOR_KILLED:
                        _vaporKilled = true;
                        break;
                    case ACTION_ANIMUS_KILLED:
                        _animusKilled = true;
                        me->RemoveAurasDueToSpell(SPELL_SARONIT_BARRIER);
                        events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(10, 15) * IN_MILLISECONDS);
                        break;
                }
            }

            Unit* CheckPlayersInRange(uint32 PlayersMin, float RangeMin, float RangeMax)
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    std::list<Player*> playerList;
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    {
                        if (Player* player = itr->getSource())
                        {
                            if (player->isDead() || player->isGameMaster())
                                continue;

                            float Distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (Distance < RangeMin || Distance > RangeMax)
                                continue;

                            playerList.push_back(player);
                        }
                    }

                    if (playerList.empty())
                        return NULL;

                    size_t size = playerList.size();
                    if (size < PlayersMin)
                        return NULL;

                    std::list<Player*>::const_iterator itr = playerList.begin();
                    std::advance(itr, urand(0, size - 1));
                    return *itr;
                }
                else
                    return NULL;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);
                _DoAggroPulse(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_VAPOR:
                            float x, y, angle;
                            angle = float(2 * M_PI * rand_norm());
                            x = 1841.98f + float(25) * cos(angle);
                            y = 113.078f + float(25) * sin(angle);
                            me->SummonCreature(ENTRY_SARONIT_VAPOR, x, y, 344.13f, 0.0f);
                            if (!_animusSummoned)
                                events.ScheduleEvent(EVENT_SUMMON_VAPOR, 30*IN_MILLISECONDS);
                            else
                                summons.DespawnEntry(ENTRY_SARONIT_VAPOR);
                            break;
                        case EVENT_SURGE_OF_DARKNESS:
                            DoCast(me, SPELL_SURGE_OF_DARKNESS);
                            DoScriptText(SAY_KITE, me);
                            DoScriptText(EMOTE_SURGE_OF_DARKNESS, me);
                            events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 63*IN_MILLISECONDS);
                            break;
                        case EVENT_SHADOW_CRASH:
                        {
                            Unit* target = CheckPlayersInRange(RAID_MODE<uint8>(4, 9), 15.0f, 100.0f);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);
                            if (target)
                            {
                                me->SetTarget(target->GetGUID());
                                DoCast(target, SPELL_SHADOW_CRASH);
                            }
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, 10*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_RESET_TARGET, 1*IN_MILLISECONDS);
                            break;
                        }
                        case EVENT_RESET_TARGET:
                            if (me->getVictim())
                                me->SetTarget(me->getVictim()->GetGUID());
                            break;
                        case EVENT_MARK_OF_THE_FACELESS:
                        {
                            Unit* target = CheckPlayersInRange(RAID_MODE<uint8>(4, 9), 15.0f, 100.0f);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);
                            if (target)
                                DoCast(target, SPELL_MARK_OF_THE_FACELESS);
                            events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(15, 25) * IN_MILLISECONDS);
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            DoScriptText(SAY_BERSERK, me);
                            break;
                        case EVENT_RESET_IMMUNITY: // called right after Searing Flames' UNIT_STAT_CASTING gets removed
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                            break;
                        case EVENT_SEARING_FLAMES:
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                            DoCast(SPELL_SEARING_FLAMES);
                            events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(10, 15) * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_RESET_IMMUNITY, 0);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            std::list<uint64> _vaporList;
            uint64 _guidSaronitAnimus;
            bool _animusSummoned;
            bool _animusKilled;
            bool _vaporKilled;
            bool _hitByShadowCrash;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_general_vezaxAI(creature);
        }
};

class mob_saronit_vapor : public CreatureScript
{
    public:
        mob_saronit_vapor() : CreatureScript("mob_saronit_vapor") { }

        struct mob_saronit_vaporAI : public ScriptedAI
        {
            mob_saronit_vaporAI(Creature* c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->SetReactState(REACT_PASSIVE);
                DoScriptText(EMOTE_VAPORS, me);
            }

            void Reset()
            {
                _randomMoveTimer = urand(5000, 7500);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1;
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetHealth(me->GetMaxHealth());
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(30000);
                    me->CastSpell(me, SPELL_SARONIT_VAPOR, true);

                    if (_instance)
                        if (Creature* vezax = Creature::GetCreature(*me, _instance->GetData64(BOSS_VEZAX)))
                            vezax->AI()->DoAction(ACTION_VAPOR_KILLED);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_randomMoveTimer < diff)
                {
                    me->GetMotionMaster()->MoveRandom(25.0f);
                    _randomMoveTimer = urand(5000, 7500);
                }
                else
                    _randomMoveTimer -= diff;
            }

        private:
            InstanceScript* _instance;
            uint32 _randomMoveTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_saronit_vaporAI(creature);
        }
};

class mob_saronit_animus : public CreatureScript
{
    public:
        mob_saronit_animus() : CreatureScript("mob_saronit_animus") { }

        struct mob_saronit_animusAI : public ScriptedAI
        {
            mob_saronit_animusAI(Creature* c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
            }

            void Reset()
            {
                _profoundDarknessTimer = 1000;
                DoCast(me, SPELL_VISUAL_SARONITE_ANIMUS);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (_instance)
                    if (Creature* vezax = Creature::GetCreature(*me, _instance->GetData64(BOSS_VEZAX)))
                        vezax->AI()->DoAction(ACTION_ANIMUS_KILLED);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() )
                    return;

                if (_profoundDarknessTimer < diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(SPELL_PROFOUND_DARKNESS);
                        _profoundDarknessTimer = RAID_MODE(7000, 3000);
                    }
                }
                else
                    _profoundDarknessTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            uint32 _profoundDarknessTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_saronit_animusAI(creature);
        }
};

class spell_general_vezax_aura_of_despair_aura : public SpellScriptLoader
{
public:
    spell_general_vezax_aura_of_despair_aura() : SpellScriptLoader("spell_general_vezax_aura_of_despair_aura") { }

    class spell_general_vezax_aura_of_despair_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_general_vezax_aura_of_despair_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_AURA_OF_DESPAIR_EFFEKT_DESPAIR))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_CORRUPTED_RAGE))
                return false;
            return true;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* target = GetTarget()->ToPlayer();

            if (target->getClass() == CLASS_SHAMAN && target->HasSpell(SPELL_SHAMANTIC_RAGE))
                target->CastSpell(target, SPELL_CORRUPTED_RAGE, true);

            target->CastSpell(target, SPELL_AURA_OF_DESPAIR_EFFEKT_DESPAIR, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* target = GetTarget()->ToPlayer();

            target->RemoveAurasDueToSpell(SPELL_CORRUPTED_RAGE);
            target->RemoveAurasDueToSpell(SPELL_AURA_OF_DESPAIR_EFFEKT_DESPAIR);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_general_vezax_aura_of_despair_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PREVENT_REGENERATE_POWER, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_general_vezax_aura_of_despair_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PREVENT_REGENERATE_POWER, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_general_vezax_aura_of_despair_AuraScript();
    }
};

class spell_general_vezax_mark_of_the_faceless_aura : public SpellScriptLoader
{
public:
    spell_general_vezax_mark_of_the_faceless_aura() : SpellScriptLoader("spell_general_vezax_mark_of_the_faceless_aura") { }

    class spell_general_vezax_mark_of_the_faceless_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_general_vezax_mark_of_the_faceless_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_THE_FACELESS_LEECH))
                return false;
            return true;
        }

        void HandleDummyTick(AuraEffect const* aurEff)
        {
            GetCaster()->CastCustomSpell(SPELL_MARK_OF_THE_FACELESS_LEECH, SPELLVALUE_BASE_POINT1, aurEff->GetAmount(), GetTarget(), true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_general_vezax_mark_of_the_faceless_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_general_vezax_mark_of_the_faceless_AuraScript();
    }
};

class spell_general_vezax_mark_of_the_faceless_drain : public SpellScriptLoader
{
    public:
        spell_general_vezax_mark_of_the_faceless_drain() : SpellScriptLoader("spell_general_vezax_mark_of_the_faceless_drain") { }

        class spell_general_vezax_mark_of_the_faceless_drain_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_vezax_mark_of_the_faceless_drain_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove(GetTargetUnit());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_general_vezax_mark_of_the_faceless_drain_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            }

            Unit* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_general_vezax_mark_of_the_faceless_drain_SpellScript();
        }
};

class achievement_shadowdodger : public AchievementCriteriaScript
{
    public:
        achievement_shadowdodger() : AchievementCriteriaScript("achievement_shadowdodger") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_SHADOWDODGER);

            return false;
        }
};

class achievement_i_love_the_smell_of_saronite_in_the_morning : public AchievementCriteriaScript
{
    public:
        achievement_i_love_the_smell_of_saronite_in_the_morning() : AchievementCriteriaScript("achievement_i_love_the_smell_of_saronite_in_the_morning") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_SMELL_OF_SARONITE);

            return false;
        }
};

/*
UPDATE creature_template SET scriptname = 'boss_general_vezax' WHERE entry = 33271;
UPDATE creature_template SET scriptname = 'mob_saronit_varpor' WHERE entry = 33488;
UPDATE creature_template SET scriptname = 'mob_saronit_animus' WHERE entry = 33524;
DELETE FROM spell_script_names WHERE spell_id = 62692;
INSERT INTO spell_script_names VALUE (62692,'spell_general_vezax_aura_of_despair_aura');
DELETE FROM spell_script_names WHERE spell_id = 63276;
INSERT INTO spell_script_names VALUE (63276,'spell_general_vezax_mark_of_the_faceless_aura');
*/

void AddSC_boss_general_vezax()
{
    new boss_general_vezax();
    new mob_saronit_vapor();
    new mob_saronit_animus();
    new spell_general_vezax_aura_of_despair_aura();
    new spell_general_vezax_mark_of_the_faceless_aura();
    new spell_general_vezax_mark_of_the_faceless_drain();
    new achievement_shadowdodger();
    new achievement_i_love_the_smell_of_saronite_in_the_morning();
}
