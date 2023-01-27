/*
*
* Copyright (C) 2012-2014 Cerber Project <https://bitbucket.org/mojitoice/>
*
*/

#include "ScriptMgr.h"
#include "deadmines.h"

enum eSpells
{
    SPELL_GO_FOR_THE_THROAT         = 88836,
    SPELL_GO_FOR_THE_THROAT_H       = 91863,
    SPELL_SWIPE                     = 88839,
    SPELL_SWIPE_H                   = 91859,
    SPELL_THIRST_FOR_BLOOD          = 88736,
    SPELL_STEAM_AURA                = 95503,
    SPELL_FOG_AURA                  = 89247,
    SPELL_BUNNY_AURA                = 88755,
    SPELL_FOG                       = 88768,
    SPELL_SUMMON_VAPOR              = 88831,
    SPELL_CONDENSE                  = 92016,
    SPELL_CONDENSE_2                = 92020,
    SPELL_CONDENSE_3                = 92029,
    SPELL_CONDENSATION              = 92013,
    SPELL_FREEZING_VAPOR            = 92011,
    SPELL_COALESCE                  = 92042,
    SPELL_SWIRLING_VAPOR            = 92007,
    SPELL_CONDENSING_VAPOR          = 92008,
};

enum eAchievementMisc
{
    ACHIEVEMENT_ITS_FROST_DAMAGE    = 5369,
    VAPOR_CASTED_COALESCE           = 1,
};

enum AdmiralPhases
{
    PHASE_NORMAL = 1,
    PHASE_FOG    = 2
};

enum Events
{
    EVENT_NULL,
    EVENT_SWIPE,
    EVENT_FLEE_TO_FROG,
    EVENT_SUMMON_VAPOR,
    EVENT_PHASE_TWO,
    EVENT_UPDATE_FOG,
    EVENT_GO_FOR_THROAT,
    EVENT_THIRST_FOR_BLOOD,
    EVENT_SHOW_UP,
};

enum Says
{
    SAY_DEATH       = 0,
    SAY_KILL        = 1,
    SAY_FOG_1       = 2,
    SAY_FOG_2       = 3,
    SAY_SPELL_1     = 4,
    SAY_SPELL_2     = 5,
    SAY_AUUUU       = 6,
    SAY_AGGRO       = 7,
};

Position const VaporFinalSpawn[] =
{
    {-70.59f, -820.57f, 40.56f, 6.28f},
    {-55.73f, -815.84f, 41.97f, 3.85f},
    {-55.73f, -825.54f, 41.99f, 2.60f},
};

class boss_admiral_ripsnarl : public CreatureScript
{
public:
    boss_admiral_ripsnarl() : CreatureScript("boss_admiral_ripsnarl") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_admiral_ripsnarlAI(creature);
    }

    struct boss_admiral_ripsnarlAI : public BossAI
    {
        boss_admiral_ripsnarlAI(Creature* creature) : BossAI(creature, DATA_RIPSNARL) { }

        uint32 eventId;
        uint8 vaporCount;
        AdmiralPhases phase;
        uint32 numberCastCoalesce;

        bool below_10;
        bool below_25;
        bool below_50;
        bool below_75;

        void Reset() override
        {
            if (!me)
                return;

            _Reset();
            summons.DespawnAll();
            events.Reset();
            vaporCount = 0;
            me->SetFullHealth();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            RemoveAuraFromMap();
            SetFog(false);

            below_10 = false;
            below_25 = false;
            below_50 = false;
            below_75 = false;
            numberCastCoalesce = 0;
            phase = PHASE_NORMAL;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!me)
                return;

            _EnterCombat();
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_THIRST_FOR_BLOOD, 0);
            events.ScheduleEvent(EVENT_SWIPE, 10000);

            if (IsHeroic())
            {
                events.ScheduleEvent(EVENT_GO_FOR_THROAT, 10000);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetAI())
                summoned->GetAI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));

            summons.Summon(summoned);
        }

        void JustReachedHome() override
        {
            if (!me)
                return;

            _JustReachedHome();
            Talk(SAY_KILL);
            RemoveAuraFromMap();
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!me)
                return;

            _JustDied();
            summons.DespawnAll();
            Talk(SAY_DEATH);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            RemoveAuraFromMap();
            RemoveFog();
            me->SummonCreature(NPC_CAPTAIN_COOKIE, CookieSpawn);
        }

        void SetData(uint32 /*uiI*/, uint32 uiValue) override
        {
            if (uiValue == VAPOR_CASTED_COALESCE && numberCastCoalesce < 3)
            {
                numberCastCoalesce++;

                if (numberCastCoalesce >= 3)
                {
                    Map* map = me->GetMap();
                    AchievementEntry const* its_frost_damage = sAchievementStore.LookupEntry(ACHIEVEMENT_ITS_FROST_DAMAGE);

                    if (map && map->IsDungeon() && map->GetDifficultyID() == DIFFICULTY_HEROIC)
                    {
                        Map::PlayerList const   & players = map->GetPlayers();
                        if (!players.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                            {
                                if (Player* player = i->GetSource())
                                {
                                    if (player->GetDistance(me) < 300.0f)
                                    {
                                        player->CompletedAchievement(its_frost_damage);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        void VaporsKilled()
        {
            vaporCount++;

            if (vaporCount == 4)
                events.ScheduleEvent(EVENT_SHOW_UP, 1000);
        }

        void SetFog(bool apply)
        {
            if (!me)
                return;

            phase = PHASE_FOG;
            std::list<Creature*> creature_list;
            me->GetCreatureListWithEntryInGrid(creature_list, NPC_GENERAL_PURPOSE_BUNNY_JMF2, 100.0f);

            creature_list.sort(Trinity::ObjectDistanceOrderPred(me));
            for (std::list<Creature*>::iterator itr = creature_list.begin(); itr != creature_list.end(); ++itr)
            {
                if (( *itr ) && ( *itr )->IsAlive() && ( *itr )->GetTypeId() == TYPEID_UNIT)
                {
                    if (Creature* bunny = ( *itr )->ToCreature())
                    {
                        if (apply)
                            bunny->AddAura(SPELL_FOG, bunny);
                        else
                            bunny->RemoveAura(SPELL_FOG);
                    }
                }
            }
            return;
        }

        void RemoveFog()
        {
            phase = PHASE_NORMAL;
            std::list<Player*> players;
            me->GetPlayerListInGrid(players, 150.0f);

            for (Player* player : players)
                player->RemoveAurasDueToSpell(SPELL_FOG_AURA);
        }

        void RemoveAuraFromMap()
        {
            if (!me)
                return;

            SetFog(false);

            if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, 20.0f))
            {
                bunny->DespawnOrUnsummon();
            }
        }

        void SummonFinalVapors()
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                me->SummonCreature(NPC_VAPOR, VaporFinalSpawn[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!me || !instance)
                return;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();

            events.Update(uiDiff);

            if (me->GetHealthPct() < 75 && !below_75)
            {
                Talk(SAY_FOG_1);
                if (Creature* bunny = me->SummonCreature(NPC_GENERAL_PURPOSE_BUNNY_JMF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
                {
                    bunny->AddAura(SPELL_BUNNY_AURA, bunny);
                    bunny->AddAura(SPELL_FOG_AURA, bunny);
                }
                SetFog(true);
                events.ScheduleEvent(EVENT_PHASE_TWO, 1000);
                events.ScheduleEvent(EVENT_UPDATE_FOG, 100);
                below_75 = true;
            } else if (me->GetHealthPct() < 50 && !below_50)
            {
                Talk(SAY_FOG_1);
                events.ScheduleEvent(EVENT_PHASE_TWO, 500);
                below_50 = true;
            } else if (me->GetHealthPct() < 25 && !below_25)
            {
                Talk(SAY_FOG_1);
                events.ScheduleEvent(EVENT_PHASE_TWO, 500);
                below_25 = true;
            } else if (me->GetHealthPct() < 10 && !below_10)
            {
                if (IsHeroic())
                {
                    SummonFinalVapors();
                    below_10 = true;
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SWIPE:
                        if (Unit* victim = me->GetVictim())
                            me->CastSpell(victim, IsHeroic() ? SPELL_SWIPE_H :SPELL_SWIPE);
                        events.ScheduleEvent(EVENT_SWIPE, 3000);
                        break;

                    case EVENT_UPDATE_FOG:
                        instance->DoCastSpellOnPlayers(SPELL_FOG_AURA);
                        break;

                    case EVENT_GO_FOR_THROAT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(target, SPELL_GO_FOR_THE_THROAT);
                        events.ScheduleEvent(EVENT_GO_FOR_THROAT, 10000);
                        break;

                    case EVENT_THIRST_FOR_BLOOD:
                        DoCast(me, SPELL_THIRST_FOR_BLOOD);
                        break;

                    case EVENT_PHASE_TWO:
                        events.CancelEvent(EVENT_GO_FOR_THROAT);
                        events.CancelEvent(EVENT_SWIPE);
                        me->RemoveAurasDueToSpell(SPELL_THIRST_FOR_BLOOD);
                        me->SetVisible(false);
                        events.ScheduleEvent(EVENT_FLEE_TO_FROG, 100);

                        if (vaporCount > 0)
                        {
                            Talk(SAY_FOG_2);
                        } else if (Unit* victim = me->GetVictim())
                        {
                            Talk(SAY_SPELL_1);
                            me->CastSpell(victim, SPELL_GO_FOR_THE_THROAT);
                        }
                        break;

                    case EVENT_FLEE_TO_FROG:
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));
                        me->DoFleeToGetAssistance();
                        Talk(SAY_AUUUU);
                        events.RescheduleEvent(EVENT_SUMMON_VAPOR, 1000);
                        events.ScheduleEvent(EVENT_SHOW_UP, 25000);
                        break;

                    case EVENT_SHOW_UP:
                        me->SetVisible(true);
                        vaporCount = 0;
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));
                        events.ScheduleEvent(EVENT_SWIPE, 1000);
                        events.ScheduleEvent(EVENT_GO_FOR_THROAT, 3000);
                        events.ScheduleEvent(EVENT_THIRST_FOR_BLOOD, 0);
                        break;

                    case EVENT_SUMMON_VAPOR:
                        if (phase == PHASE_FOG)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                me->CastSpell(target, SPELL_SUMMON_VAPOR);
                        events.RescheduleEvent(EVENT_SUMMON_VAPOR, 3500);
                        break;
                }
            }
        }
    };
};

enum VaporEvents
{
    EVENT_CONDENSING_VAPOR = 1,
    EVENT_SWIRLING_VAPOR,
    EVENT_FREEZING_VAPOR,
    EVENT_COALESCE,
};

class npc_vapor : public CreatureScript
{
public:
    npc_vapor() : CreatureScript("npc_vapor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vaporAI(creature);
    }

    struct npc_vaporAI : public ScriptedAI
    {
        npc_vaporAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;

        bool form_1;
        bool form_2;
        bool form_3;

        void Reset() override
        {
            events.Reset();
            form_1 = false;
            form_2 = false;
            form_3 = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!me)
                return;

            if (IsHeroic())
                me->AddAura(SPELL_CONDENSATION, me);
        }

        void JustDied(Unit* /*who*/) override
        {
            if (Creature* Ripsnarl = me->FindNearestCreature(NPC_ADMIRAL_RIPSNARL, 250, true))
                if (boss_admiral_ripsnarl::boss_admiral_ripsnarlAI* pAI = CAST_AI(boss_admiral_ripsnarl::boss_admiral_ripsnarlAI, Ripsnarl->AI()))
                    pAI->VaporsKilled();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasAura(SPELL_CONDENSE) && !form_1)
            {
                events.ScheduleEvent(EVENT_CONDENSING_VAPOR, 2000);
                form_1 = true;
            } else if (me->HasAura(SPELL_CONDENSE_2) && !form_2)
            {
                me->SetDisplayId(25654);
                events.CancelEvent(EVENT_CONDENSING_VAPOR);
                events.ScheduleEvent(EVENT_SWIRLING_VAPOR, 2000);
                form_2 = true;
            } else if (me->HasAura(SPELL_CONDENSE_3) && !form_3)
            {
                me->SetDisplayId(36455);
                events.CancelEvent(EVENT_SWIRLING_VAPOR);
                events.ScheduleEvent(EVENT_FREEZING_VAPOR, 2000);
                form_3 = true;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CONDENSING_VAPOR:
                        DoCastVictim(SPELL_CONDENSING_VAPOR);
                        events.ScheduleEvent(EVENT_SWIRLING_VAPOR, 3500);
                        break;
                    case EVENT_SWIRLING_VAPOR:
                        DoCastVictim(SPELL_SWIRLING_VAPOR);
                        events.ScheduleEvent(EVENT_SWIRLING_VAPOR, 3500);
                        break;
                    case EVENT_FREEZING_VAPOR:
                        DoCastVictim(SPELL_FREEZING_VAPOR);
                        events.ScheduleEvent(EVENT_COALESCE, 5000);
                        break;
                    case EVENT_COALESCE:
                        DoCastVictim(SPELL_COALESCE);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class spell_coalesce_achievement : public SpellScriptLoader
{
public:
    spell_coalesce_achievement() : SpellScriptLoader("spell_coalesce_achievement") { }

    SpellScript* GetSpellScript() const override
    {
        return new spell_coalesce_achievement_SpellScript();
    }

    class spell_coalesce_achievement_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_coalesce_achievement_SpellScript);

        void HandleExtraEffect()
        {
            Unit* caster = GetCaster();
            if (caster)
            {
                if (Creature* boss = caster->FindNearestCreature(NPC_ADMIRAL_RIPSNARL, 300.0f))
                {
                    boss->AI()->SetData(0, VAPOR_CASTED_COALESCE);
                }
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_coalesce_achievement_SpellScript::HandleExtraEffect);
        }
    };
};

void AddSC_boss_admiral_ripsnarl()
{
    new boss_admiral_ripsnarl();
    new npc_vapor();
    new spell_coalesce_achievement();
}
