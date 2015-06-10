/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "utgarde_pinnacle.h"
#include "Player.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_AGGRO                        = 0,
    SAY_KILL                         = 1,
    SAY_DEATH                        = 3,
    SAY_DRAKE_DEATH                  = 5,
    SAY_DRAKE_BREATH                 = 6,
};

enum Emotes
{
    EMOTE_GRAUF                      = 0,
};

static Position SpawnLoc = { 468.931f, -513.555f, 104.723f, 0 };
static Position firstWave[] =
{
    // Warriors
    { 463.998962f, -508.309021f, 104.246231f, 3.262319f },    // 0
    { 463.711945f, -516.229126f, 104.546730f, 3.010991f },    // 1
    { 429.458008f, -510.208405f, 104.861153f, 3.069111f },    // 2
    { 428.809753f, -517.521545f, 104.945396f, 2.994498f },    // 3
    // Harpooners
    { 482.749725f, -507.775513f, 104.723076f, 3.252893f },    // 4
    { 482.827271f, -514.537415f, 104.723076f, 3.048689f },    // 5
    // Witch Doctor
    { 480.122498f, -510.371124f, 104.723076f, 3.225404f }     // 6
};

static Position spawnWave[] =
{
    { 477.580994f, -484.558990f, 104.821999f, 4.677480f },    // 0
    { 476.717499f, -506.566071f, 104.723991f, 3.182994f }     // 1
};

static Position Location[] =
{
    // Boss
    { 341.740997f, -516.955017f, 104.66900f, 0 },             // 0
    { 311.029724f, -509.694824f, 128.50389f, 0 },             // 1
    { 312.449860f, -538.114868f, 149.73173f, 0 },             // 2
    { 502.650330f, -535.114380f, 125.29112f, 0 },             // 3
    { 477.311981f, -509.296814f, 104.72308f, 0 },             // 4 
    { 341.740997f, -516.955017f, 104.66900f, 0 },             // 5
    // Breach Zone
    { 502.478271f, -512.426270f, 112.50000f, 0 },             // 6
    { 335.601959f, -510.965790f, 112.50000f, 0 },             // 7
    { 500.107239f, -512.377258f, 111.91300f, 0 },             // 8
    { 498.631683f, -531.179321f, 124.41099f, 0 }              // 9
};

enum CombatPhase
{
    PHASE_FLYING,
    PHASE_SKADI
};

enum Spells
{
    // Skadi Spells
    SPELL_CRUSH                         = 50234,
    SPELL_POISONED_SPEAR                = 50255,
    SPELL_POISONED_SPEAR_PERIODIC       = 50258,
    SPELL_WHIRLWIND                     = 50228, // random target, but not the tank approx. every 20s
    SPELL_RAPID_FIRE                    = 51368,
    SPELL_FREEZING_CLOUD                = 47579,
    SPELL_RIDE_GRAUF                    = 61791,
    SPELL_FREEZING_CLOUD_RIGHT_PERIODIC = 47592,
    SPELL_FREEZING_CLOUD_LEFT_PERIODIC  = 47590,
    SPELL_FREEZING_CLOUD_RIGHT          = 47593,
    SPELL_FREEZING_CLOUD_LEFT           = 47563,
    SPELL_FREEZING_CLOUD_RIGHT_AREA     = 47594,
    SPELL_FREEZING_CLOUD_LEFT_AREA      = 47574,
    SPELL_FREEZING_CLOUD_H              = 60020,
    SPELL_SKADI_TELEPORT                = 61790
};

enum Creatures
{
    NPC_YMIRJAR_WARRIOR       = 26690,
    NPC_YMIRJAR_WITCH_DOCTOR  = 26691,
    NPC_YMIRJAR_HARPOONER     = 26692,
    NPC_GRAUF                 = 26893,
    NPC_TRIGGER               = 23472,
    NPC_TRIGGER2              = 19871
};

uint32 wavesComp[3][2] =
{
    { NPC_YMIRJAR_WARRIOR, NPC_YMIRJAR_HARPOONER },
    { NPC_YMIRJAR_WARRIOR, NPC_YMIRJAR_WITCH_DOCTOR },
    { NPC_YMIRJAR_HARPOONER, NPC_YMIRJAR_WITCH_DOCTOR }
};

enum Data
{
    DATA_FLYING             = 0,
    DATA_RANGE_HARPOON,
    DATA_FLAME,
    DATA_GAUNTLET_END,
    DATA_HARPOON_HIT,
    DATA_LOVE_TO_SKADI
};

enum Achievments
{
    ACHIEV_TIMED_START_EVENT =                      17726,
};

enum Events
{
    EVENT_FLYING            = 1,
    EVENT_MOVEMENT,
    EVENT_EMOTE,
    EVENT_SPAWN_MOVE,
    EVENT_SUMMON,
    EVENT_CRUSH,
    EVENT_POISONED_SPEAR,
    EVENT_WHIRLWIND
};

class boss_skadi : public CreatureScript
{
public:
    boss_skadi() : CreatureScript("boss_skadi") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_skadiAI>(creature);
    }


    struct boss_skadiAI : public ScriptedAI
    {
        boss_skadiAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            firstSummon = true;
            waveCount = 0;
            harpoonHit = 0;
            loveSkadi = 0;
            Phase = PHASE_SKADI;
        }

        void Reset() override
        {
            Initialize();
            spawns.clear();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            events.Reset();

            Summons.DespawnAll();
            if (ObjectAccessor::GetCreature(*me, m_uiGraufGUID) == NULL)
                me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, NOT_STARTED);
            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustReachedHome() override
        {
            if (!ObjectAccessor::GetCreature(*me, m_uiGraufGUID))
                me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* grauf = ObjectAccessor::GetCreature(*me, m_uiGraufGUID))
                DoCast(grauf, SPELL_RIDE_GRAUF);

            Talk(SAY_AGGRO);
            Phase = PHASE_FLYING;
            events.ScheduleEvent(EVENT_FLYING, 2500);
            events.ScheduleEvent(EVENT_SUMMON, 1500);
            me->SetReactState(REACT_PASSIVE);
            me->SetInCombatWithZone();
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, IN_PROGRESS);
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustSummoned(Creature* summoned) override
        {
            switch (summoned->GetEntry())
            {
                case NPC_GRAUF:
                    m_uiGraufGUID = summoned->GetGUID();
                    instance->SetGuidData(DATA_GRAUF, m_uiGraufGUID);
                    break;
                case NPC_YMIRJAR_WARRIOR:
                case NPC_YMIRJAR_WITCH_DOCTOR:
                case NPC_YMIRJAR_HARPOONER:
                    summoned->setActive(true);
                    break;
            }
            Summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_GRAUF)
                m_uiGraufGUID.Clear();
            Summons.Despawn(summoned);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            Summons.DespawnAll();
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, DONE);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void SpawnMobs()
        {
            if (firstSummon)
            {
                firstSummon = false;
                for (uint8 i = 0; i < DUNGEON_MODE(5, 6); ++i)
                    if (Creature* warrior = me->SummonCreature(NPC_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX() + rand() % 5, SpawnLoc.GetPositionY() + rand() % 5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
                    {
                        warrior->SetInCombatWithZone();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            warrior->AI()->AttackStart(target);
                    }
                for (uint8 i = 0; i < 4; i++)
                    me->SummonCreature(NPC_YMIRJAR_WARRIOR, firstWave[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                for (uint8 i = 4; i < 6; i++)
                    me->SummonCreature(NPC_YMIRJAR_HARPOONER, firstWave[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                me->SummonCreature(NPC_YMIRJAR_WITCH_DOCTOR, firstWave[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
            }
            else
            {
                for (uint8 i = 0; i < 2; i++)
                {
                    if (Creature* summon = me->SummonCreature(wavesComp[waveCount][i], spawnWave[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                    {
                        spawns.push_back(summon);
                        summon->SetNoCallAssistance(true);
                        summon->GetMotionMaster()->MovePoint(0, spawnWave[1]);
                    }
                }
                events.ScheduleEvent(EVENT_SPAWN_MOVE, 2500);
                waveCount++;
                if (waveCount == 3)
                    waveCount = 0;
            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case DATA_FLAME:
                    if (loveSkadi == 1)
                        loveSkadi++;
                    Talk(SAY_DRAKE_BREATH);
                    break;
                case DATA_GAUNTLET_END:
                    me->RemoveAurasDueToSpell(SPELL_RIDE_GRAUF);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    Phase = PHASE_SKADI;
                    Summons.DespawnEntry(NPC_GRAUF);
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    Talk(SAY_DRAKE_DEATH);
                    me->GetMotionMaster()->MoveJump(Location[4].GetPositionX(), Location[4].GetPositionY(), Location[4].GetPositionZ(), 25.0f, 5.0f);
                    events.ScheduleEvent(EVENT_CRUSH, 8000);
                    events.ScheduleEvent(EVENT_POISONED_SPEAR, 10000);
                    events.ScheduleEvent(EVENT_WHIRLWIND, 20000);
                    break;
                case DATA_HARPOON_HIT:
                    harpoonHit++;
                    if (harpoonHit == 1)
                        loveSkadi = 1;
                    if (harpoonHit >= 3)
                        DoAction(DATA_GAUNTLET_END);
                    break;
            }
        }

        uint32 GetData(uint32 id) const override
        {
            if (id == DATA_LOVE_TO_SKADI)
                return loveSkadi;

            return 0;
        }

        void UpdateAI(uint32 diff) override
        {
            switch (Phase)
            {
                case PHASE_FLYING:
                    if (!UpdateVictim())
                    {
                        Reset();
                        DoCast(SPELL_SKADI_TELEPORT);
                        return;
                    }

                    events.Update(diff);

                    switch (uint32 eventId = events.ExecuteEvent())
                    {
                        case EVENT_FLYING:
                            if (Creature* grauf = ObjectAccessor::GetCreature(*me, m_uiGraufGUID))
                                grauf->AI()->DoAction(DATA_FLYING);
                            break;
                        case EVENT_SUMMON:
                            SpawnMobs();
                            events.ScheduleEvent(EVENT_SUMMON, 32000);
                            break;
                        case EVENT_SPAWN_MOVE:
                            if (!spawns.empty())
                            {
                                for(std::list<Creature*>::const_iterator itr = spawns.begin(); itr != spawns.end(); ++itr)
                                    (*itr)->SetInCombatWithZone();
                                spawns.clear();
                            }
                            break;
                    }
                    break;
                case PHASE_SKADI:
                    if (!UpdateVictim())
                        return;

                    events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    switch (uint32 eventId = events.ExecuteEvent())
                    {
                        case EVENT_CRUSH:
                            DoCastVictim(SPELL_CRUSH);
                            events.ScheduleEvent(EVENT_CRUSH, 8000);
                            break;
                        case EVENT_POISONED_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_POISONED_SPEAR);
                            events.ScheduleEvent(EVENT_POISONED_SPEAR, 10000);
                            break;
                        case EVENT_WHIRLWIND:
                            DoCast(SPELL_WHIRLWIND);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->GetMotionMaster()->MoveChase(target);
                            events.DelayEvents(10000);
                            events.ScheduleEvent(EVENT_WHIRLWIND, 20000);
                            break;
                    }

                    DoMeleeAttackIfReady();
                    break;
            }
        }

    private:
        EventMap events;
        InstanceScript* instance;
        SummonList Summons;
        ObjectGuid m_uiGraufGUID;
        CombatPhase Phase;
        bool firstSummon;
        uint8 waveCount;
        std::list<Creature*> spawns;
        uint8 harpoonHit;
        uint8 loveSkadi;
    };
};

class npc_grauf : public CreatureScript
{
public:
    npc_grauf() : CreatureScript("npc_grauf") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_graufAI(creature);
    }

    struct npc_graufAI : public ScriptedAI
    {
        npc_graufAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            triggers.clear();
            step = 0;
        }

        void Reset() override
        {
            Initialize();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetSpeed(MOVE_RUN, 2.25f);
            events.Reset();
        }

        void DoAction(int32 action) override
        {
            if (action == DATA_FLYING)
            {
                me->SetInCombatWithZone();
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->GetMotionMaster()->MoveTakeoff(0, Location[1]);
                events.ScheduleEvent(EVENT_MOVEMENT, 2500);
                if (Creature* skadi = me->FindNearestCreature(NPC_SKADI_THE_RUTHLESS, 10.0f))
                    skadiGUID = skadi->GetGUID();
                // Populate trigger list
                triggers.clear();
                GetCreatureListWithEntryInGrid(triggers, me, NPC_TRIGGER, 70.0f);
                GetCreatureListWithEntryInGrid(triggers, me, NPC_TRIGGER2, 200.0f);
            }
        }

        void SpellHit(Unit*, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_RAPID_FIRE)
                if (Creature* skadi = ObjectAccessor::GetCreature(*me, skadiGUID))
                    skadi->AI()->DoAction(DATA_HARPOON_HIT);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (uint32 eventId = events.ExecuteEvent())
            {
                case EVENT_MOVEMENT:
                    switch (step)
                    {
                        case 0:
                            me->GetMotionMaster()->MovePoint(0, Location[2]);
                            events.ScheduleEvent(EVENT_MOVEMENT, 2000);
                            break;
                        case 1:
                            me->GetMotionMaster()->MovePoint(0, Location[3]);
                            events.ScheduleEvent(EVENT_EMOTE, 12500);
                            events.ScheduleEvent(EVENT_MOVEMENT, 22500);
                            break;
                        case 2:
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                            me->GetMotionMaster()->MovePoint(0, Location[6]);
                            events.ScheduleEvent(EVENT_EMOTE, 2000);
                            events.ScheduleEvent(EVENT_MOVEMENT, 5000);
                            break;
                        case 3:
                            if (Creature* skadi = ObjectAccessor::GetCreature(*me, skadiGUID))
                                skadi->AI()->DoAction(DATA_FLAME);
                            DoCast(RAND(SPELL_FREEZING_CLOUD_LEFT_PERIODIC, SPELL_FREEZING_CLOUD_RIGHT_PERIODIC));
                            me->GetMotionMaster()->MovePoint(0, Location[7]);
                            events.ScheduleEvent(EVENT_MOVEMENT, 10000);
                            break;
                        case 4:
                            me->RemoveAurasDueToSpell(SPELL_FREEZING_CLOUD_LEFT_PERIODIC);
                            me->RemoveAurasDueToSpell(SPELL_FREEZING_CLOUD_RIGHT_PERIODIC);
                            me->GetMotionMaster()->MovePoint(0, Location[1]);
                            events.ScheduleEvent(EVENT_MOVEMENT, 3500);
                            break;
                    }
                    step++;
                    if (step == 5)
                        step = 0;
                    break;
                case EVENT_EMOTE:
                    switch (step)
                    {
                        case 2:
                        
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                            me->GetMotionMaster()->MovePoint(0, Location[9]);
                            if (!triggers.empty())
                                for (std::list<Creature*>::const_iterator itr = triggers.begin(); itr != triggers.end(); ++itr)
                                    (*itr)->AI()->SetData(0, 0);
                            break;
                        
                        case 3:
                            me->GetMotionMaster()->MovePoint(0, Location[8]);
                            Talk(EMOTE_GRAUF);
                            break;
                    }
                    break;
            }
        }

    private:
        EventMap events;
        uint8 step;
        ObjectGuid skadiGUID;
        std::list<Creature*> triggers;
    };
};

class spell_freezing_cloud_area_right : public SpellScriptLoader
{
public:
    spell_freezing_cloud_area_right() : SpellScriptLoader("spell_freezing_cloud_area_right") { }

    class spell_freezing_cloud_area_right_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_freezing_cloud_area_right_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* a)
            {
                if (a)
                    return a->GetPositionY() > -511.0f;
                else
                    return false;
            });

            targets.remove_if([](WorldObject* a)
            {
                if (a && a->ToCreature())
                    return a->ToCreature()->HasAura(SPELL_FREEZING_CLOUD) || a->ToCreature()->HasAura(SPELL_FREEZING_CLOUD_H);
                else
                    return false;
            });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_freezing_cloud_area_right_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_freezing_cloud_area_right_SpellScript();
    }
};

class spell_freezing_cloud_area_left : public SpellScriptLoader
{
public:
    spell_freezing_cloud_area_left() : SpellScriptLoader("spell_freezing_cloud_area_left") { }

    class spell_freezing_cloud_area_left_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_freezing_cloud_area_left_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* a)
            {
                if (a)
                    return a->GetPositionY() > -511.0f;
                else
                    return false;
            });

            targets.remove_if([](WorldObject* a)
            {
                if (a && a->ToCreature())
                    return a->ToCreature()->HasAura(SPELL_FREEZING_CLOUD) || a->ToCreature()->HasAura(SPELL_FREEZING_CLOUD_H);
                else
                    return false;
            });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_freezing_cloud_area_left_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_freezing_cloud_area_left_SpellScript();
    }
};

class spell_skadi_poisoned_spear : public SpellScriptLoader
{
public:
    spell_skadi_poisoned_spear() : SpellScriptLoader("spell_skadi_poisoned_spear") { }

    class spell_skadi_poisoned_spear_left_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skadi_poisoned_spear_left_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_POISONED_SPEAR_PERIODIC, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skadi_poisoned_spear_left_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skadi_poisoned_spear_left_SpellScript();
    }
};

class achievement_girl_love_to_skadi : public AchievementCriteriaScript
{
public:
    achievement_girl_love_to_skadi() : AchievementCriteriaScript("achievement_girl_love_to_skadi")
    {
    }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* skadi = target->ToCreature())
            if (skadi->AI()->GetData(DATA_LOVE_TO_SKADI) == 1)
                return true;

        return false;
    }
};

class go_harpoon_launcher : public GameObjectScript
{
public:
    go_harpoon_launcher() : GameObjectScript("go_harpoon_launcher") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return false;

        if (Creature* grauf = ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_GRAUF)))
            if (!grauf->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                player->CastSpell(grauf, SPELL_RAPID_FIRE, true);

        return false;
    }

};

void AddSC_boss_skadi()
{
    new boss_skadi();
    new go_harpoon_launcher();
    new npc_grauf();
    new spell_freezing_cloud_area_left();
    new spell_freezing_cloud_area_right();
    new spell_skadi_poisoned_spear();
    new achievement_girl_love_to_skadi();
}
