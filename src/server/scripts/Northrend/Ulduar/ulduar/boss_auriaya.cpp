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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ulduar.h"

enum AuriayaSpells
{
    // Auriaya
    SPELL_SENTINEL_BLAST                         = 64389,
    SPELL_SONIC_SCREECH                          = 64422,
    SPELL_TERRIFYING_SCREECH                     = 64386,
    SPELL_SUMMON_SWARMING_GUARDIAN               = 64396,
    SPELL_ACTIVATE_DEFENDER                      = 64449,
    SPELL_DEFENDER_TRIGGER                       = 64448,
    SPELL_SUMMON_DEFENDER                        = 64447,
    SPELL_BERSERK                                = 47008,

    // Feral Defender
    SPELL_FERAL_RUSH                             = 64496,
    SPELL_FERAL_POUNCE                           = 64478,
    SPELL_SEEPING_ESSENCE                        = 64458,
    SPELL_SUMMON_ESSENCE                         = 64457,
    SPELL_FERAL_ESSENCE                          = 64455,

    // Sanctum Sentry
    SPELL_SAVAGE_POUNCE                          = 64666,
    SPELL_RIP_FLESH                              = 64375,
    SPELL_STRENGHT_PACK                          = 64369,
};

enum AuriayaNPCs
{
    NPC_SANCTUM_SENTRY                           = 34014,
    NPC_FERAL_DEFENDER                           = 34035,
    NPC_FERAL_DEFENDER_TRIGGER                   = 34096,
    NPC_SEEPING_TRIGGER                          = 34098,
};

enum AuriayaEvents
{
    // Auriaya
    EVENT_SCREECH                                = 1,
    EVENT_BLAST                                  = 2,
    EVENT_TERRIFYING                             = 3,
    EVENT_SUMMON                                 = 4,
    EVENT_DEFENDER                               = 5,
    EVENT_ACTIVATE_DEFENDER                      = 6,
    EVENT_RESPAWN_DEFENDER                       = 7,
    EVENT_BERSERK                                = 8,

    // Sanctum Sentry
    EVENT_RIP                                    = 9,
    EVENT_POUNCE                                 = 10,

    // Feral Defender
    EVENT_FERAL_POUNCE                           = 11,
    EVENT_RUSH                                   = 12,
};

enum AuriayaYells
{
    // Yells
    SAY_AGGRO                                    = -1603050,
    SAY_SLAY_1                                   = -1603051,
    SAY_SLAY_2                                   = -1603052,
    SAY_DEATH                                    = -1603053,
    SAY_BERSERK                                  = -1603054,

    // Emotes
    EMOTE_FEAR                                   = -1603055,
    EMOTE_DEFENDER                               = -1603056,
};

enum AuriayaActions
{
    ACTION_CRAZY_CAT_LADY                        = 0,
    ACTION_RESPAWN_DEFENDER
};

#define SENTRY_NUMBER                            RAID_MODE<uint8>(2, 4)
#define DATA_NINE_LIVES                          30763077
#define DATA_CRAZY_CAT_LADY                      30063007

class boss_auriaya : public CreatureScript
{
    public:
        boss_auriaya() : CreatureScript("boss_auriaya") { }

        struct boss_auriayaAI : public BossAI
        {
            boss_auriayaAI(Creature* creature) : BossAI(creature, BOSS_AURIAYA)
            {
            }

            void Reset()
            {
                _Reset();
                DefenderGUID = 0;
                defenderLifes = 9;
                crazyCatLady = true;
                nineLives = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                DoScriptText(SAY_AGGRO,me);

                events.ScheduleEvent(EVENT_SCREECH, urand(45000, 65000));
                events.ScheduleEvent(EVENT_BLAST, urand(20000, 25000));
                events.ScheduleEvent(EVENT_TERRIFYING, urand(20000, 30000));
                events.ScheduleEvent(EVENT_DEFENDER, urand(40000, 55000));
                events.ScheduleEvent(EVENT_SUMMON, urand(45000, 55000));
                events.ScheduleEvent(EVENT_BERSERK, 600000);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void JustSummoned(Creature* summoned)
            {
                summons.Summon(summoned);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    summoned->AI()->AttackStart(target);
                    summoned->AddThreat(target, 250.0f);
                    DoZoneInCombat(summoned);
                }

                if (summoned->GetEntry() == NPC_FERAL_DEFENDER)
                {
                    if (!summoned->isInCombat() && me->getVictim())
                        summoned->AI()->AttackStart(me->getVictim());
                    summoned->SetAuraStack(SPELL_FERAL_ESSENCE, summoned, 9);
                    DefenderGUID = summoned->GetGUID();
                    DoZoneInCombat(summoned);
                }
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_CRAZY_CAT_LADY:
                        SetData(DATA_CRAZY_CAT_LADY, 0);
                        break;
                    case ACTION_RESPAWN_DEFENDER:
                        --defenderLifes;
                        if (!defenderLifes)
                        {
                            SetData(DATA_NINE_LIVES, 1);
                            break;
                        }
                        events.ScheduleEvent(EVENT_RESPAWN_DEFENDER, 30000);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_NINE_LIVES:
                        return nineLives ? 1 : 0;
                    case DATA_CRAZY_CAT_LADY:
                        return crazyCatLady ? 1 : 0;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 data)
            {
               switch (id)
               {
                   case DATA_NINE_LIVES:
                        nineLives = data ? true : false;
                        break;
                    case DATA_CRAZY_CAT_LADY:
                        crazyCatLady = data ? true : false;
                        break;
               }
            }

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(SAY_DEATH, me);
                _JustDied();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SCREECH:
                            DoCast(SPELL_SONIC_SCREECH);
                            events.ScheduleEvent(EVENT_SCREECH, urand(40000, 60000));
                            break;
                        case EVENT_TERRIFYING:
                            DoScriptText(EMOTE_FEAR, me);
                            DoCast(SPELL_TERRIFYING_SCREECH);
                            events.ScheduleEvent(EVENT_TERRIFYING, urand(20000, 30000));
                            break;
                        case EVENT_BLAST:
                            DoCastAOE(SPELL_SENTINEL_BLAST);
                            events.ScheduleEvent(EVENT_BLAST, urand(25000, 35000));
                            break;
                        case EVENT_DEFENDER:
                            DoScriptText(EMOTE_DEFENDER, me);
                            DoCast(SPELL_DEFENDER_TRIGGER);
                            if (Creature* trigger = me->FindNearestCreature(NPC_FERAL_DEFENDER_TRIGGER, 15.0f, true))
                                DoCast(trigger, SPELL_ACTIVATE_DEFENDER, true);
                            break;
                        case EVENT_RESPAWN_DEFENDER:
                            if (Creature* Defender = ObjectAccessor::GetCreature(*me, DefenderGUID))
                            {
                                Defender->Respawn();
                                if (defenderLifes)
                                    Defender->SetAuraStack(SPELL_FERAL_ESSENCE, Defender, defenderLifes);
                                Defender->SetInCombatWithZone();
                                if (!Defender->isInCombat())
                                    Defender->AI()->AttackStart(me->getVictim());
                                events.CancelEvent(EVENT_RESPAWN_DEFENDER);
                            }
                            break;
                        case EVENT_SUMMON:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SUMMON_SWARMING_GUARDIAN);
                            events.ScheduleEvent(EVENT_SUMMON, urand(30000, 45000));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            DoScriptText(SAY_BERSERK, me);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint64 DefenderGUID;
            uint8 defenderLifes;
            bool crazyCatLady;
            bool nineLives;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_auriayaAI>(creature);
        }
};

class npc_auriaya_seeping_trigger : public CreatureScript
{
    public:
        npc_auriaya_seeping_trigger() : CreatureScript("npc_auriaya_seeping_trigger") { }

        struct npc_auriaya_seeping_triggerAI : public ScriptedAI
        {
            npc_auriaya_seeping_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

        void Reset()
        {
            me->ForcedDespawn(600000);
            DoCast(me, SPELL_SEEPING_ESSENCE);
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            if (instance->GetBossState(BOSS_AURIAYA) != IN_PROGRESS)
                me->ForcedDespawn();
        }

        private:
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_auriaya_seeping_triggerAI(creature);
        }
};

class npc_sanctum_sentry : public CreatureScript
{
    public:
        npc_sanctum_sentry() : CreatureScript("npc_sanctum_sentry") { }

        struct npc_sanctum_sentryAI : public ScriptedAI
        {
            npc_sanctum_sentryAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_RIP, urand(4000,8000));
                events.ScheduleEvent(EVENT_POUNCE, urand(12000,15000));
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoCast(me, SPELL_STRENGHT_PACK, true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RIP:
                            DoCastVictim(SPELL_RIP_FLESH);
                            events.ScheduleEvent(EVENT_RIP, urand(12000, 15000));
                            break;
                        case EVENT_POUNCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->AddThreat(target, 100.0f);
                                me->AI()->AttackStart(target);
                                DoCast(target, SPELL_SAVAGE_POUNCE);
                            }
                            events.ScheduleEvent(EVENT_POUNCE, urand(12000,17000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature* Auriaya = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_AURIAYA)))
                    Auriaya->AI()->DoAction(ACTION_CRAZY_CAT_LADY);
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sanctum_sentryAI(creature);
        }
};

class npc_feral_defender : public CreatureScript
{
    public:
        npc_feral_defender() : CreatureScript("npc_feral_defender") { }

        struct npc_feral_defenderAI : public ScriptedAI
        {
            npc_feral_defenderAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_FERAL_POUNCE, 5000);
                events.ScheduleEvent(EVENT_RUSH, 10000);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FERAL_POUNCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->AddThreat(target, 100.0f);
                                me->AI()->AttackStart(target);
                                DoCast(target, SPELL_FERAL_POUNCE);
                            }
                            events.ScheduleEvent(EVENT_FERAL_POUNCE, urand(10000, 12000));
                            break;
                        case EVENT_RUSH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->AddThreat(target, 100.0f);
                                me->AI()->AttackStart(target);
                                DoCast(target, SPELL_FERAL_RUSH);
                            }
                            events.ScheduleEvent(EVENT_RUSH, urand(10000, 12000));
                            break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                DoCast(me, SPELL_SUMMON_ESSENCE);
                if (Creature* Auriaya = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_AURIAYA)))
                    Auriaya->AI()->DoAction(ACTION_RESPAWN_DEFENDER);
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_feral_defenderAI(creature);
        }
};

class SanctumSentryCheck
{
    public:
        bool operator() (Unit* unit)
        {
            if (unit->GetEntry() == NPC_SANCTUM_SENTRY)
                return false;

            return true;
        }
};

class spell_auriaya_strenght_of_the_pack : public SpellScriptLoader
{
    public:
        spell_auriaya_strenght_of_the_pack() : SpellScriptLoader("spell_auriaya_strenght_of_the_pack") { }

        class spell_auriaya_strenght_of_the_pack_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_auriaya_strenght_of_the_pack_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(SanctumSentryCheck());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_auriaya_strenght_of_the_pack_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ALLY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_auriaya_strenght_of_the_pack_SpellScript();
        }
};

class achievement_nine_lives : public AchievementCriteriaScript
{
    public:
        achievement_nine_lives() : AchievementCriteriaScript("achievement_nine_lives")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (Creature* Auriaya = target->ToCreature())
                if (Auriaya->AI()->GetData(DATA_NINE_LIVES))
                    return true;

            return false;
        }
};

class achievement_crazy_cat_lady : public AchievementCriteriaScript
{
    public:
        achievement_crazy_cat_lady() : AchievementCriteriaScript("achievement_crazy_cat_lady")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (Creature* Auriaya = target->ToCreature())
                if (Auriaya->AI()->GetData(DATA_CRAZY_CAT_LADY))
                    return true;

            return false;
        }
};

void AddSC_boss_auriaya()
{
    new boss_auriaya();
    new npc_auriaya_seeping_trigger();
    new npc_feral_defender();
    new npc_sanctum_sentry();
    new spell_auriaya_strenght_of_the_pack();
    new achievement_nine_lives();
    new achievement_crazy_cat_lady();
}
