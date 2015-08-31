/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Argent Challenge Encounter.
SD%Complete: 50 %
SDComment: AI for Argent Soldiers are not implemented. AI from bosses need more improvements.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum Yells
{
    // Eadric the Pure
    SAY_AGGRO_E                 = 1,
    EMOTE_RADIANCE              = 2,
    EMOTE_HAMMER_RIGHTEOUS      = 3,
    SAY_HAMMER_RIGHTEOUS        = 4,
    SAY_KILL_PLAYER_E           = 5,
    SAY_DEFEATED_E              = 6,

    // Argent Confessor Paletress
    SAY_AGGRO_P                 = 2,
    SAY_MEMORY_SUMMON           = 3,
    SAY_MEMORY_DEATH            = 4,
    SAY_KILL_PLAYER_P           = 5,
    SAY_DEFEATED_P              = 6,

    // Memory of X
    EMOTE_WAKING_NIGHTMARE      = 0
};

enum Events
{
    // Argent Lightwielder
    EVENT_BLAZING_LIGHT = 1,
    EVENT_CLEAVE,
    EVENT_UNBALANCING_STRIKE,
    // Argent Monk
    EVENT_FLURRY_OF_BLOWS,
    EVENT_PUMMEL,
    // Argent Priestess
    EVENT_HOLY_SMITE,
    EVENT_SHADOW_WORD_PAIN,
    EVENT_FOUNTAIN,
    EVENT_FOUNTAIN_DUMMY,
    EVENT_MIND_CONTROL,
    // Argent Confessor Paletress
    EVENT_HOLY_FIRE,
    EVENT_HOLY_SMITE_E,
    EVENT_RENEW,
    EVENT_SUMMON_MEMORY,
    EVENT_PALETRESS_DONE,
    // Memory
    EVENT_ENTER_AGGRESSIVE,
    EVENT_OLD_WOUNDS,
    EVENT_SHADOWS_PAST,
    EVENT_WAKING_NIGHTMARE,
    // Eadric the Pure
    EVENT_VENGEANCE,
    EVENT_RADIANCE,
    EVENT_HAMMER_OF_JUSTICE,
    EVENT_EADRIC_DONE
};

enum Spells
{
    // Argent Lightwielder
    SPELL_BLAZING_LIGHT         = 67247,
    SPELL_CLEAVE                = 15284,
    SPELL_UNBALANCING_STRIKE    = 67237,

    // Argent Monk
    SPELL_FLURRY_OF_BLOWS       = 67233,
    SPELL_PUMMEL                = 67235,
    SPELL_DIVINE_SHIELD         = 67251,
    SPELL_FINAL_MEDITATION      = 67255,

    // Argent Priestess
    SPELL_HOLY_SMITE            = 36176,
    SPELL_HOLY_SMITE_H          = 67289,
    SPELL_SHADOW_WORD_PAIN      = 34941,
    SPELL_SHADOW_WORD_PAIN_H    = 34942,
    SPELL_MIND_CONTROL          = 67229,
    SPELL_SUMMON_FOUNTAIN       = 67194,
    SPELL_FOUNTAIN_DUMMY_HEAL   = 67196,

    // Eadric the Pure
    SPELL_EADRIC_FACEROLLER     = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_JUSTICE_STUN   = 66940,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_HAMMER_RIGHT_DUMMY    = 66904,
    SPELL_HAMMER_RIGHTEOUS_PLR  = 66905,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,
    SPELL_EADRIC_ACH            = 68575,

    // Paletress
    SPELL_PALETRESS_CONFESSOR   = 68206, // achievement id 3802
    SPELL_SMITE                 = 66536,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_RENEW                 = 66537,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_SHIELD_REFLECT        = 33619,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,
    SPELL_PALETRESS_ACH         = 68574,

    // Memory of X (Summon)
    SPELL_MEMORY_ALGALON        = 66715,
    SPELL_MEMORY_ARCHIMONDE     = 66704,
    SPELL_MEMORY_CHROMAGGUS     = 66697,
    SPELL_MEMORY_CYANIGOSA      = 66709,
    SPELL_MEMORY_DELRISSA       = 66706,
    SPELL_MEMORY_ECK            = 66710,
    SPELL_MEMORY_ENTROPIUS      = 66707,
    SPELL_MEMORY_GRUUL          = 66702,
    SPELL_MEMORY_HAKKAR         = 66698,
    SPELL_MEMORY_HEIGAN         = 66712,
    SPELL_MEMORY_HEROD          = 66694,
    SPELL_MEMORY_HOGGER         = 66543,
    SPELL_MEMORY_IGNIS          = 66713,
    SPELL_MEMORY_ILLIDAN        = 66705,
    SPELL_MEMORY_INGVAR         = 66708,
    SPELL_MEMORY_KALITHRESH     = 66700,
    SPELL_MEMORY_LUCIFRON       = 66695,
    SPELL_MEMORY_MALCHEZAAR     = 66701,
    SPELL_MEMORY_MUTANUS        = 66692,
    SPELL_MEMORY_ONYXIA         = 66711,
    SPELL_MEMORY_THUNDERAAN     = 66696,
    SPELL_MEMORY_VANCLEEF       = 66691,
    SPELL_MEMORY_VASHJ          = 66703,
    SPELL_MEMORY_VEKNILASH      = 66699,
    SPELL_MEMORY_VEZAX          = 66714,

    // Memory
    SPELL_SHADOWFORM            = 41408,
    SPELL_SPAWN_VISUAL          = 66675,
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_WAKING_NIGHTMARE      = 66552
};

class OrientationCheck : public std::unary_function<Unit*, bool>
{
    public:
        explicit OrientationCheck(Unit* _caster) : caster(_caster) { }
        bool operator()(WorldObject* object)
        {
            return !object->isInFront(caster, 2.5f) || !object->IsWithinDist(caster, 40.0f);
        }

    private:
        Unit* caster;
};

class spell_eadric_radiance : public SpellScriptLoader
{
    public:
        spell_eadric_radiance() : SpellScriptLoader("spell_eadric_radiance") { }
        class spell_eadric_radiance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_radiance_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(OrientationCheck(GetCaster()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_eadric_radiance_SpellScript();
        }
};

class boss_eadric : public CreatureScript
{
public:
    boss_eadric() : CreatureScript("boss_eadric") { }
    struct boss_eadricAI : public ScriptedAI
    {
        boss_eadricAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            faceRollerGUID.Clear();
            bDone = false;

            me->SetReactState(REACT_DEFENSIVE);
        }

        void Initialize()
        {
            events.Reset();
        }

        InstanceScript* instance;

        EventMap events;
        ObjectGuid faceRollerGUID;

        bool bDone;

        void Reset() override
        {
            if (bDone)
                return;
            Initialize();
        }

        void SetFacerollerPlayer(ObjectGuid playerGuid)
        {
            if (!bDone)
                faceRollerGUID = playerGuid;
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!bDone)
                {
                    bDone = true;
                    events.Reset();
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetHealth(1);
                    me->CombatStop(true);
                    me->setRegeneratingHealth(false);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                    Talk(SAY_DEFEATED_E);
                    me->SetHomePosition(745.87f, 625.88f, 411.17f, me->GetHomePosition().GetOrientation());
                    me->GetMotionMaster()->MoveTargetedHome();
                }
                return;
            }
        }

        void JustReachedHome()
        {
            if (bDone)
                events.ScheduleEvent(EVENT_EADRIC_DONE, 4000);
            else
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 0)
            {
                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    announcer->AI()->SetData(DATA_ARGENT_CHAMPION_PREPARE, 0);
            }
            else if (id == 1)
            {
                me->SetWalk(false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
            }
            else if (id == 2)
                me->DisappearAndDie();
        }

        void EnterCombat(Unit* who) override
        {
            if (bDone)
                return;
            ScriptedAI::EnterCombat(who);
            events.ScheduleEvent(EVENT_VENGEANCE, 500);
            events.ScheduleEvent(EVENT_RADIANCE, urand(7000, 15000));
            Talk(SAY_AGGRO_E, who);
            DoZoneInCombat();
        }

        void KilledUnit(Unit* who)
        {
            if (who->ToPlayer())
                Talk(SAY_KILL_PLAYER_E, who);
        }

        void AttackStart(Unit* who) override
        {
            if (bDone)
                return;
            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_VENGEANCE:
                        if (!me->HasAura(SPELL_VENGEANCE))
                            DoCast(me, SPELL_VENGEANCE);
                        events.ScheduleEvent(EVENT_VENGEANCE, 30000);
                        break;
                    case EVENT_RADIANCE:
                        DoCastAOE(SPELL_RADIANCE);
                        Talk(EMOTE_RADIANCE);
                        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, urand(20000, 30000));
                        break;
                    case EVENT_HAMMER_OF_JUSTICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            DoCast(target, SPELL_HAMMER_JUSTICE, true);
                            DoCast(target, SPELL_HAMMER_RIGHTEOUS);
                            Talk(EMOTE_HAMMER_RIGHTEOUS, target);
                            Talk(SAY_HAMMER_RIGHTEOUS);
                        }
                        events.ScheduleEvent(EVENT_RADIANCE, urand(7000, 15000));
                        break;
                    case EVENT_EADRIC_DONE:
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->SetFullHealth();
                        me->RestoreFaction();
                        instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_EADRIC_ACH, 0, me);
                        if (Player* plr = ObjectAccessor::GetPlayer(*me, faceRollerGUID))
                            plr->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_EADRIC_FACEROLLER, 0, me);
                        instance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(2, bossExitPos);
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_eadricAI>(creature);
    }
};

class boss_paletress : public CreatureScript
{
public:
    boss_paletress() : CreatureScript("boss_paletress") { }

    struct boss_paletressAI : public ScriptedAI
    {
        boss_paletressAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            bDone = false;

            me->SetReactState(REACT_DEFENSIVE);
        }

        void Initialize()
        {
            events.Reset();

            bMemory = false;
        }

        InstanceScript* instance;
        ObjectGuid MemoryGUID;

        EventMap events;

        bool bMemory;
        bool bDone;

        void Reset() override
        {
            if (bDone)
                return;
            me->RemoveAura(SPELL_SHIELD);
            Initialize();
            if (Creature* pMemory = ObjectAccessor::GetCreature(*me, MemoryGUID))
                pMemory->DisappearAndDie();
        }

        void SetData(uint32 uiId, uint32 /*uiValue*/) override
        {
            if (uiId == 1)
            {
                me->InterruptNonMeleeSpells(true);
                Talk(SAY_MEMORY_DEATH);
                me->GetMotionMaster()->Clear();
                me->RemoveAura(SPELL_SHIELD);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!bDone)
                {
                    bDone = true;
                    events.Reset();
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetHealth(1);
                    me->CombatStop(true);
                    me->setRegeneratingHealth(false);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                    Talk(SAY_DEFEATED_P);
                    me->SetHomePosition(745.87f, 625.88f, 411.17f, me->GetHomePosition().GetOrientation());
                    me->GetMotionMaster()->MoveTargetedHome();
                }
                return;
            }
        }

        void JustReachedHome()
        {
            if (bDone)
                events.ScheduleEvent(EVENT_PALETRESS_DONE, 4000);
            else
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 0)
            {
                if (Creature* announcer = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANNOUNCER)))
                    announcer->AI()->SetData(DATA_ARGENT_CHAMPION_PREPARE, 0);
            }
            else if (id == 1)
            {
                me->SetWalk(false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
            }
            else if (id == 2)
                me->DisappearAndDie();
        }

        void EnterCombat(Unit* who) override
        {
            if (bDone)
                return;
            ScriptedAI::EnterCombat(who);
            events.ScheduleEvent(EVENT_HOLY_SMITE_E, 2000);
            events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
            events.ScheduleEvent(EVENT_RENEW, urand(15000, 17000));
            Talk(SAY_AGGRO_P, who);
            DoZoneInCombat();
        }

        void KilledUnit(Unit* who)
        {
            if (who->ToPlayer())
                Talk(SAY_KILL_PLAYER_P, who);
        }

        void AttackStart(Unit* who) override
        {
            if (me->HasAura(SPELL_SHIELD) || bDone)
                return;
            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HOLY_SMITE_E:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_SMITE);
                        events.ScheduleEvent(EVENT_HOLY_SMITE_E, urand(2000, 3000));
                        break;
                    case EVENT_HOLY_FIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(target, SPELL_HOLY_FIRE);
                        events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9000, 12000));
                        break;
                    case EVENT_RENEW:
                        me->InterruptNonMeleeSpells(true);
                        if (rand32() % 2 && me->GetHealthPct() < 100)
                            DoCast(me, SPELL_RENEW);
                        else
                        {
                            Creature* pMemory = ObjectAccessor::GetCreature(*me, MemoryGUID);
                            if (pMemory && pMemory->GetHealth() > 1)
                                DoCast(pMemory, SPELL_RENEW);
                            else
                                DoCast(me, SPELL_RENEW);
                        }
                        events.ScheduleEvent(EVENT_RENEW, urand(15000, 17000));
                        break;
                    case EVENT_SUMMON_MEMORY:
                        // Memory spawns at random player's position
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_SUMMON_MEMORY, true);
                        break;
                    case EVENT_PALETRESS_DONE:
                        me->RemoveAllAuras();
                        me->DeleteThreatList();
                        me->SetFullHealth();
                        me->RestoreFaction();
                        instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_PALETRESS_ACH, 0, me);
                        if (Creature* memory = ObjectAccessor::GetCreature(*me, MemoryGUID))
                        {
                            if (IsHeroic())
                                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_PALETRESS_CONFESSOR, 0, memory);
                            memory->DisappearAndDie();
                        }
                        instance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(2, bossExitPos);
                        break;
                    default:
                        break; 
                }
            }

            if (!UpdateVictim())
                return;

            if (!bMemory && !HealthAbovePct(25))
            {
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_HOLY_NOVA, false);
                Talk(SAY_MEMORY_SUMMON);
                DoCast(me, SPELL_SHIELD);
                DoCastAOE(SPELL_CONFESS, false);
                me->AttackStop();
                events.ScheduleEvent(EVENT_SUMMON_MEMORY, 2000);

                bMemory = true;
            }

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon) override
        {
            MemoryGUID = summon->GetGUID();
            me->GetMotionMaster()->MoveFollow(summon, 30.0f, 0.0f);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_paletressAI>(creature);
    }
};

class npc_memory : public CreatureScript
{
public:
    npc_memory() : CreatureScript("npc_memory") { }

    struct npc_memoryAI : public ScriptedAI
    {
        npc_memoryAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            me->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            events.Reset();
            DoCast(me, SPELL_SHADOWFORM);
            DoCast(me, SPELL_SPAWN_VISUAL);
            events.ScheduleEvent(EVENT_ENTER_AGGRESSIVE, 3000);
        }

        EventMap events;

        void Reset() override
        {
            Initialize();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                // We can't make memory despawn yet 
                // to give correct achievement credit later when Paletress is defeated
                // so we make him invisible
                damage = 0;
                events.Reset();
                me->SetHealth(1);
                me->setRegeneratingHealth(false);
                me->RemoveAllAuras();
                me->CombatStop(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->GetMotionMaster()->MoveIdle();
                me->SetVisible(false);

                if (TempSummon* summ = me->ToTempSummon())
                {
                    if (Unit* summoner = summ->GetSummoner())
                        summoner->GetAI()->SetData(1, 0);
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ENTER_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_OLD_WOUNDS, urand(11000, 13000));
                        events.ScheduleEvent(EVENT_SHADOWS_PAST, 5000);
                        events.ScheduleEvent(EVENT_WAKING_NIGHTMARE, urand(7000, 10000));
                        break;
                    case EVENT_OLD_WOUNDS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            DoCast(target, SPELL_OLD_WOUNDS);
                        events.ScheduleEvent(EVENT_OLD_WOUNDS, urand(11000, 13000));
                        break;
                    case EVENT_SHADOWS_PAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_SHADOWS_PAST);
                        events.ScheduleEvent(EVENT_SHADOWS_PAST, urand(5000, 7000));
                        break;
                    case EVENT_WAKING_NIGHTMARE:
                        me->InterruptNonMeleeSpells(true);
                        Talk(EMOTE_WAKING_NIGHTMARE);
                        DoCastAOE(SPELL_WAKING_NIGHTMARE);
                        events.ScheduleEvent(EVENT_WAKING_NIGHTMARE, urand(20000, 40000));
                        break;
                    default:
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_memoryAI(creature);
    }
};

class npc_argent_soldier : public CreatureScript
{
public:
    npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

    struct npc_argent_soldierAI : public ScriptedAI
    {
        npc_argent_soldierAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            Initialize();
            uiWaypoint = 0;
        }

        void Initialize()
        {
            events.Reset();
            shielded = false;
        }
        EventMap events;
        InstanceScript* instance;

        bool shielded;
        uint8 uiWaypoint;

        ObjectGuid fountainGuid;

        void Reset()
        {
            Initialize();
            if (me->GetEntry() == NPC_PRIESTESS)
            {
                if (Creature* fountain = ObjectAccessor::GetCreature(*me, fountainGuid))
                    fountain->DisappearAndDie();
            }
        }

        Position const GenerateFinalPosition()
        {
            Position finalPos = NULL;
            switch (me->GetEntry())
            {
                case NPC_ARGENT_LIGHWIELDER:
                    switch (uiWaypoint)
                    {
                        case 0:
                            finalPos = { 712.14f, 628.42f, 411.88f, 5.81f };
                            break;
                        case 1:
                            finalPos = { 742.44f, 650.29f, 411.79f, 4.60f };
                            break;
                        case 2:
                            finalPos = { 774.94f, 636.64f, 411.89f, 3.78f };
                            break;
                    }
                    break;
                case NPC_ARGENT_MONK:
                    switch (uiWaypoint)
                    {
                        case 0:
                            finalPos = { 713.12f, 632.97f, 411.90f, 5.81f };
                            break;
                        case 1:
                            finalPos = { 746.73f, 650.24f, 411.56f, 4.60f };
                            break;
                        case 2:
                            finalPos = { 777.33f, 633.08f, 411.89f, 3.78f };
                            break;
                    }
                    break;
                case NPC_PRIESTESS:
                    switch (uiWaypoint)
                    {
                        case 0:
                            finalPos = { 715.06f, 637.07f, 411.91f, 5.81f };
                            break;
                        case 1:
                            finalPos = { 750.72f, 650.20f, 411.77f, 4.60f };
                            break;
                        case 2:
                            finalPos = { 780.13f, 629.18f, 411.89f, 3.78f };
                            break;
                    }
                    break;
                default:
                    break;
            }
            return finalPos;
        }

        void JustReachedHome()
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            ScriptedAI::MovementInform(uiType, uiPointId);

            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 0)
            {
                me->SetWalk(false);
                me->GetMotionMaster()->MoveTargetedHome(); // this corrects facing 100%
                if (me->GetEntry() == NPC_ARGENT_MONK)
                {
                    if (Creature* pLightwielder = me->FindNearestCreature(NPC_ARGENT_LIGHWIELDER, 15.0f))
                    {
                        if (pLightwielder->GetFollowAngle() != 0)
                        {
                            pLightwielder->GetMotionMaster()->Clear();
                            pLightwielder->GetMotionMaster()->MovePoint(0, pLightwielder->GetHomePosition());
                        }
                    }
                    if (Creature* pPriestess = me->FindNearestCreature(NPC_PRIESTESS, 15.0f))
                    {
                        if (pPriestess->GetFollowAngle() != 0)
                        {
                            pPriestess->GetMotionMaster()->Clear();
                            pPriestess->GetMotionMaster()->MovePoint(0, pPriestess->GetHomePosition());
                        }
                    }
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (me->GetEntry() == NPC_PRIESTESS)
            {
                fountainGuid = summon->GetGUID();
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& dmg)
        {
            if (me->GetEntry() == NPC_ARGENT_MONK && dmg >= me->GetHealth() && !shielded)
            {
                dmg = 0;
                shielded = true;
                me->SetHealth(1);
                me->AttackStop();
                DoCast(SPELL_DIVINE_SHIELD);
                DoCast(SPELL_FINAL_MEDITATION);
                return;
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) override
        {
            uiWaypoint = uiType;
            Position const homePos = GenerateFinalPosition();
            if (homePos.IsPositionValid())
            {
                me->SetHomePosition(homePos);
                me->SetWalk(true);
                if (me->GetEntry() == NPC_ARGENT_MONK)
                    me->GetMotionMaster()->MovePoint(0, homePos);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (me->GetEntry() == NPC_ARGENT_LIGHWIELDER)
            {
                events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(4000, 6000));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 8000);
            }
            else if (me->GetEntry() == NPC_ARGENT_MONK)
            {
                events.ScheduleEvent(EVENT_FLURRY_OF_BLOWS, 2000);
                events.ScheduleEvent(EVENT_PUMMEL, 12000);
            }
            else if (me->GetEntry() == NPC_PRIESTESS)
            {
                events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 500);
                events.ScheduleEvent(EVENT_HOLY_SMITE, 2500);
                events.ScheduleEvent(EVENT_FOUNTAIN, 10000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_MIND_CONTROL, 15000);
            }
        }

        void AttackStart(Unit* who) override
        {
            if (me->GetEntry() == NPC_ARGENT_MONK && me->HasAura(SPELL_DIVINE_SHIELD))
                return;
            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BLAZING_LIGHT:
                        if (Unit* pFriend = DoSelectLowestHpFriendly(40.0f))
                        {
                            if (pFriend->GetHealthPct() > me->GetHealthPct())
                                DoCast(me, SPELL_BLAZING_LIGHT);
                            else
                                DoCast(pFriend, SPELL_BLAZING_LIGHT);
                        }
                        events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10000);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(4000, 6000));
                        break;
                    case EVENT_UNBALANCING_STRIKE:
                        DoCastVictim(SPELL_UNBALANCING_STRIKE);
                        events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 15000);
                        break;
                    case EVENT_FLURRY_OF_BLOWS:
                        DoCast(SPELL_FLURRY_OF_BLOWS);
                        events.ScheduleEvent(EVENT_FLURRY_OF_BLOWS, 15000);
                        break;
                    case EVENT_PUMMEL:
                    {
                        Map::PlayerList const &pList = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                        {
                            Player* plr = itr->GetSource();
                            if (plr && me->IsWithinDist(plr, 5.0f) && plr->IsNonMeleeSpellCast(true))
                            {
                                DoCast(plr, SPELL_PUMMEL);
                                break;
                            }
                        }
                        events.ScheduleEvent(EVENT_PUMMEL, 12000);
                        break;
                    }
                    case EVENT_SHADOW_WORD_PAIN:
                        if (IsHeroic())
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN_H);
                        else
                            DoCastVictim(SPELL_SHADOW_WORD_PAIN);
                        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 15000);
                        break;
                    case EVENT_HOLY_SMITE:
                        if (IsHeroic())
                            DoCastVictim(SPELL_HOLY_SMITE_H);
                        else
                            DoCastVictim(SPELL_HOLY_SMITE);
                        events.ScheduleEvent(EVENT_HOLY_SMITE, urand(4000, 7000));
                        break;
                    case EVENT_FOUNTAIN:
                        DoCast(SPELL_SUMMON_FOUNTAIN);
                        events.ScheduleEvent(EVENT_FOUNTAIN, 50000);
                        break;
                    case EVENT_MIND_CONTROL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
                            DoCast(target, SPELL_MIND_CONTROL);
                        events.ScheduleEvent(EVENT_MIND_CONTROL, 15000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, instance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
            if (me->GetEntry() == NPC_PRIESTESS)
            {
                if (Creature* fountain = ObjectAccessor::GetCreature(*me, fountainGuid))
                    fountain->DisappearAndDie();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_argent_soldierAI>(creature);
    }
};

class npc_fountain_of_light : public CreatureScript
{
    public:
        npc_fountain_of_light() : CreatureScript("npc_fountain_of_light") { }

        struct npc_fountain_of_lightAI : public ScriptedAI
        {
            npc_fountain_of_lightAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                SetCombatMovement(false);
                instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_FOUNTAIN_DUMMY, 2000);
            }

            InstanceScript* instance;
            EventMap events;

            void Reset() override
            {
                Initialize();
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
                me->DespawnOrUnsummon();
            }

            void AttackStart(Unit* /*who*/) override
            {
                return;
            }

            void UpdateAI(uint32 uiDiff) override
            {
                ScriptedAI::UpdateAI(uiDiff);
                events.Update(uiDiff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_FOUNTAIN_DUMMY)
                    {
                        if (!me->HasAura(SPELL_FOUNTAIN_DUMMY_HEAL))
                            DoCast(me, SPELL_FOUNTAIN_DUMMY_HEAL);
                        events.ScheduleEvent(EVENT_FOUNTAIN_DUMMY, 5000);
                    }
                }

                if (!UpdateVictim())
                    return;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_fountain_of_lightAI>(creature);
        }
};

uint32 const memorySpellId[25] =
{
    SPELL_MEMORY_ALGALON,
    SPELL_MEMORY_ARCHIMONDE,
    SPELL_MEMORY_CHROMAGGUS,
    SPELL_MEMORY_CYANIGOSA,
    SPELL_MEMORY_DELRISSA,
    SPELL_MEMORY_ECK,
    SPELL_MEMORY_ENTROPIUS,
    SPELL_MEMORY_GRUUL,
    SPELL_MEMORY_HAKKAR,
    SPELL_MEMORY_HEIGAN,
    SPELL_MEMORY_HEROD,
    SPELL_MEMORY_HOGGER,
    SPELL_MEMORY_IGNIS,
    SPELL_MEMORY_ILLIDAN,
    SPELL_MEMORY_INGVAR,
    SPELL_MEMORY_KALITHRESH,
    SPELL_MEMORY_LUCIFRON,
    SPELL_MEMORY_MALCHEZAAR,
    SPELL_MEMORY_MUTANUS,
    SPELL_MEMORY_ONYXIA,
    SPELL_MEMORY_THUNDERAAN,
    SPELL_MEMORY_VANCLEEF,
    SPELL_MEMORY_VASHJ,
    SPELL_MEMORY_VEKNILASH,
    SPELL_MEMORY_VEZAX
};

// 66545 - Summon Memory
class spell_paletress_summon_memory : public SpellScriptLoader
{
    public:
        spell_paletress_summon_memory() : SpellScriptLoader("spell_paletress_summon_memory") { }

        class spell_paletress_summon_memory_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paletress_summon_memory_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint8 i = 0; i < 25; ++i)
                    if (!sSpellMgr->GetSpellInfo(memorySpellId[i]))
                        return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), memorySpellId[urand(0, 24)], true, NULL, NULL, GetCaster()->GetGUID());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paletress_summon_memory_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_paletress_summon_memory_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_paletress_summon_memory_SpellScript();
        }
};

class spell_paletress_reflective_shield : public SpellScriptLoader
{
    public:
        spell_paletress_reflective_shield() : SpellScriptLoader("spell_paletress_reflective_shield") { }

        class spell_paletress_reflective_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_paletress_reflective_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHIELD_REFLECT))
                    return false;
                return true;
            }

            void HandleScript(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                // Reflecting 25% of absorbed damage back to attacker
                if (dmgInfo.GetAttacker() == GetTarget())
                    return;
                int32 bp = absorbAmount / 4;
                GetTarget()->CastCustomSpell(dmgInfo.GetAttacker(), SPELL_SHIELD_REFLECT, &bp, NULL, NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_paletress_reflective_shield_AuraScript::HandleScript, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_paletress_reflective_shield_AuraScript();
        }
};

class spell_eadric_hammer_of_righteous : public SpellScriptLoader
{
    public:
        spell_eadric_hammer_of_righteous() : SpellScriptLoader("spell_eadric_hammer_of_righteous") { }

        class spell_eadric_hammer_of_righteous_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_hammer_of_righteous_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_HAMMER_RIGHT_DUMMY) || 
                    !sSpellMgr->GetSpellInfo(SPELL_HAMMER_JUSTICE_STUN))
                    return false;
                return true;
            }

            void HandleDamage()
            {
                if (Unit* target = GetHitUnit())
                {
                    if (!target->HasAura(SPELL_HAMMER_JUSTICE_STUN))
                    {
                        // If target does not have Hammer of Justice stun,
                        // then target gets the dummy aura which allows you to throw hammer back to Eadric
                        PreventHitDefaultEffect(EFFECT_0);
                        PreventHitDamage();
                        GetCaster()->CastSpell(target, SPELL_HAMMER_RIGHT_DUMMY, true);
                    }
                }
            }

            void Register() override
            {
                BeforeHit += SpellHitFn(spell_eadric_hammer_of_righteous_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_eadric_hammer_of_righteous_SpellScript();
        }
};

class spell_eadric_hammer_of_righteous_faceroller : public SpellScriptLoader
{
    public:
        spell_eadric_hammer_of_righteous_faceroller() : SpellScriptLoader("spell_eadric_hammer_of_righteous_faceroller") { }

        class spell_eadric_hammer_of_righteous_faceroller_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_eadric_hammer_of_righteous_faceroller_SpellScript);

            void CheckHealth(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster()->ToPlayer() || !GetCaster()->ToPlayer()->GetMap()->IsHeroic())
                    return;

                if (!GetHitUnit() || !GetHitUnit()->ToCreature() || GetHitUnit()->ToCreature()->GetEntry() != NPC_EADRIC)
                    return;

                if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
                    ENSURE_AI(boss_eadric::boss_eadricAI, GetHitUnit()->ToCreature()->AI())->SetFacerollerPlayer(GetCaster()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_eadric_hammer_of_righteous_faceroller_SpellScript::CheckHealth, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_eadric_hammer_of_righteous_faceroller_SpellScript();
        }
};

void AddSC_boss_argent_challenge()
{
    new boss_eadric();
    new spell_eadric_radiance();
    new boss_paletress();
    new npc_memory();
    new npc_argent_soldier();
    new npc_fountain_of_light();
    new spell_paletress_summon_memory();
    new spell_paletress_reflective_shield();
    new spell_eadric_hammer_of_righteous();
    new spell_eadric_hammer_of_righteous_faceroller();
}
