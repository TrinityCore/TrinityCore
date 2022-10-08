#include "ScriptMgr.h"
#include "the_underrot.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "CreatureAI.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_TAINT_OF_GHUUN = 260685,
    SPELL_BLOOD_BOLT = 260879,

    SPELL_CREEPING_ROT = 260894,
    SPELL_CREEPING_ROT_TARGET_SELECTOR = 260889,
    SPELL_CREEPING_ROT_TRIGGER = 261496,
    SPELL_CREEPING_ROT_DOT = 261498,
    SPELL_CREEPING_ROT_VISUAL = 260891,

    SPELL_SANGUINE_FEAST_TARGET_SELECTOR = 264747,
    SPELL_SANGUINE_FEAST_CAST = 264757,
    SPELL_SANGUINE_FEAST_JUMP = 264753,

    SPELL_BLOOD_MIRROR = 264603,
    SPELL_BLOOD_MIRROR_MISSILE = 264609,
    SPELL_BLOOD_MIRROR_VISUAL = 272385,
};

enum Events
{
    EVENT_BLOOD_BOLT = 1,
    EVENT_CREEPING_ROT = 2,
    EVENT_BLOOD_MIRROR = 3,
    EVENT_SANGUINE_FEAST = 4,
};

enum Timers
{
    TIMER_BLOOD_BOLT = 4 * IN_MILLISECONDS,

    TIMER_BLOOD_MIRROR = 16 * IN_MILLISECONDS,
    TIMER_BLOOD_MIRROR_AFTER = 30 * IN_MILLISECONDS,

    TIMER_CREEPING_ROT = 15 * IN_MILLISECONDS,

    TIMER_SANGUINE_FEAST = 10 * IN_MILLISECONDS,
    TIMER_SANGUINE_FEAST_AFTER = 30 * IN_MILLISECONDS,
};

enum Sounds
{
    SOUND_ROT = 101026,
    SOUND_AGGRO = 101028,
    SOUND_KILL = 101029,
    SOUND_DEATH = 101030,
    SOUND_MIRROR = 101025,
    SOUND_FEAST = 101028,
};

enum Creatures
{
    BOSS_ELDER_LEAXA = 131318,

    NPC_CREEPING_ROG_TRIGGER = 132398,
    NPC_BLOOD_EFFIGY = 134701,
};

const Position centerPlatform = { 868.98f, 1230.07f, 56.30f }; //cheaters 23y

#define AGGRO_TEXT "For de glory of G'huun!"
#define ROT_TEXT "Rot and wither!"
#define KILL_TEXT "Time for de sacrifice!"
#define DEATH_TEXT "My blood for G'huun..."
#define MIRROR_TEXT "G'huun be everywhere!"
#define FEAST_TEXT "For de glory of G'huun!"

class bfa_boss_elder_leaxa : public CreatureScript
{
public:
    bfa_boss_elder_leaxa() : CreatureScript("bfa_boss_elder_leaxa")
    {}

    struct bfa_boss_elder_leaxa_AI : public BossAI
    {
        bfa_boss_elder_leaxa_AI(Creature* creature) : BossAI(creature, DATA_ELDER_LEAXA), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        SummonList summons;

        void Reset()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            events.Reset();
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();
        }

        void JustDied(Unit*)
        {
            SelectSoundAndText(me, 4);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveAllAreaTriggers();
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_BLOOD_EFFIGY:
                summon->SetInCombatWithZone();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
                break;
            }
        }

        void EnterEvadeMode(EvadeReason why)
        {
            _DespawnAtEvade(15);
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(centerPlatform.GetPositionX(), centerPlatform.GetPositionY(), centerPlatform.GetPositionZ()) >= 25.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_AGGRO);
                    break;
                case 2:
                    me->Yell(ROT_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_ROT);
                    break;
                case 3:
                    me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_KILL);
                    break;
                case 4:
                    me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_DEATH);
                    break;
                case 5:
                    me->Yell(MIRROR_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_MIRROR);
                    break;
                case 6:
                    me->Yell(FEAST_TEXT, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_FEAST);
                    break;
                }
            }
        }

        void KilledUnit(Unit*)
        {
            SelectSoundAndText(me, 3);
        }

        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_BLOOD_MIRROR:
                HandleBloodMirrorSpawns();
                break;
            case SPELL_CREEPING_ROT:
                HandleCreepingRoot();
                break;
            case SPELL_BLOOD_BOLT:
                me->CastSpell(me->GetVictim(), SPELL_TAINT_OF_GHUUN, true);
                break;
            }
        }

        void HandleBloodMirrorSpawns()
        {
            float x;
            float y;

            switch (rand() % 3)
            {
            case 1:
                x = 875.113159f;
                y = 1240.381958f;
                break;
            case 2:
                x = 879.703979f;
                y = 1224.49646f;
                break;
            case 3:
                x = 858.541931f;
                y = 1221.745239f;
                break;
            }

            me->CastSpell(x, y, me->GetPositionZ(), SPELL_BLOOD_MIRROR_MISSILE);
            me->SummonCreature(NPC_BLOOD_EFFIGY, x, y, me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_BLOOD_BOLT, TIMER_BLOOD_BOLT);
            events.ScheduleEvent(EVENT_BLOOD_MIRROR, TIMER_BLOOD_MIRROR);
            events.ScheduleEvent(EVENT_CREEPING_ROT, TIMER_CREEPING_ROT);

            if(me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_SANGUINE_FEAST, TIMER_SANGUINE_FEAST);
        }

        void HandleCreepingRoot()
        {
            events.DelayEvents(3 * IN_MILLISECONDS);

            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
            if (!targets.empty())
                if (targets.size() >= 1)
                    targets.resize(1);

            for (auto target : targets)
            {
                me->SetFacingToObject(target);

                float orientation = me->GetOrientation();
                Position pos;

                if (Creature* trigger = me->SummonCreature(NPC_CREEPING_ROG_TRIGGER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
                {
                    trigger->DespawnOrUnsummon(30 * IN_MILLISECONDS);

                    trigger->SetReactState(REACT_PASSIVE);
                    trigger->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                    trigger->SetFlying(true);

                    trigger->CastSpell(trigger, SPELL_CREEPING_ROT_VISUAL, true);
                    //trigger->CastSpell(trigger, SPELL_CREEPING_ROT_TRIGGER, true);

                    trigger->GetNearPoint(NULL, pos.m_positionX, pos.m_positionY, pos.m_positionZ, DEFAULT_WORLD_OBJECT_SIZE, 250, orientation);
                    trigger->GetMotionMaster()->MovePoint(0, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
                }
            }
        }

        void HandleFeast()
        {
            events.DelayEvents(3 * IN_MILLISECONDS);

            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
            if (!targets.empty())
                if (targets.size() >= 1)
                    targets.resize(1);

            for (auto target : targets)
            {
                me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation(), 20.0f, 10.0f);
                me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SANGUINE_FEAST_CAST);
                    });
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->IsInCombat())
                CheckCheaters();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLOOD_BOLT:
                    me->CastSpell(me->GetVictim(), SPELL_BLOOD_BOLT);
                    events.ScheduleEvent(EVENT_BLOOD_BOLT, TIMER_BLOOD_BOLT);
                    break;
                case EVENT_BLOOD_MIRROR:
                {
                    SelectSoundAndText(me, 5);

                    std::ostringstream str;
                    str << "Elder Leaxa begins to cast |cFFF00000|h[Blood Mirror]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);

                    me->CastSpell(me->GetVictim(), SPELL_BLOOD_MIRROR);
                    events.ScheduleEvent(EVENT_BLOOD_MIRROR, TIMER_BLOOD_MIRROR_AFTER);
                    break;
                }
                case EVENT_CREEPING_ROT:
                    SelectSoundAndText(me, 2);
                    me->CastSpell(me, SPELL_CREEPING_ROT);
                    events.ScheduleEvent(EVENT_CREEPING_ROT, TIMER_CREEPING_ROT);
                    break;
                case EVENT_SANGUINE_FEAST:
                    SelectSoundAndText(me, 6);
                    HandleFeast();
                    events.ScheduleEvent(EVENT_SANGUINE_FEAST, TIMER_SANGUINE_FEAST_AFTER);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_elder_leaxa_AI(creature);
    }
};

class bfa_npc_creeping_rot_trigger : public CreatureScript
{
public:
    bfa_npc_creeping_rot_trigger() : CreatureScript("bfa_npc_creeping_rot_trigger")
    {}

    struct bfa_npc_creeping_rot_trigger_AI : public ScriptedAI
    {
        bfa_npc_creeping_rot_trigger_AI(Creature* creature) : ScriptedAI(creature)
        {
        }
        uint32 damageTimer;

        void Reset()
        {
            damageTimer = 0;
        }

        void UpdateAI(uint32 diff)
        {
            damageTimer += diff;
            if (damageTimer >= 500)
            {
                me->CastSpell(me, SPELL_CREEPING_ROT_VISUAL, true);

                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                    {
                        if (!player->IsGameMaster()) //gm check
                        {
                            if (me->GetDistance(player) <= 3.0f)
                                me->AddAura(SPELL_CREEPING_ROT_DOT, player);
                            else
                                player->RemoveAura(SPELL_CREEPING_ROT_DOT);
                        }
                    }
                damageTimer = 0;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_creeping_rot_trigger_AI(creature);
    }
};

class bfa_npc_blood_effigy : public CreatureScript
{
public:
    bfa_npc_blood_effigy() : CreatureScript("bfa_npc_blood_effigy")
    {}

    struct bfa_npc_blood_effigy_AI : public ScriptedAI
    {
        bfa_npc_blood_effigy_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_BLOOD_BOLT, TIMER_BLOOD_BOLT);

            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_SANGUINE_FEAST, TIMER_SANGUINE_FEAST);
        }

        void HandleFeast()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
            if (!targets.empty())
                if (targets.size() >= 1)
                    targets.resize(1);

            for (auto target : targets)
            {
                me->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation(), 20.0f, 10.0f);
                me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SANGUINE_FEAST_CAST);
                    });
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BLOOD_BOLT:
                    me->CastSpell(me->GetVictim(), SPELL_BLOOD_BOLT);
                    events.ScheduleEvent(EVENT_BLOOD_BOLT, TIMER_BLOOD_BOLT);
                    break;
                case EVENT_SANGUINE_FEAST:
                    HandleFeast();
                    events.ScheduleEvent(EVENT_SANGUINE_FEAST, TIMER_SANGUINE_FEAST_AFTER);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_blood_effigy_AI(creature);
    }
};

// 260685 Taint of G'huun
class bfa_spell_taint_of_ghunn : public SpellScriptLoader
{
public:
    bfa_spell_taint_of_ghunn() : SpellScriptLoader("bfa_spell_taint_of_ghunn") { }

    class bfa_spell_taint_of_ghunn_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_taint_of_ghunn_AuraScript);

        void HandleAbsorb(AuraEffect* aurEff, HealInfo& healInfo, uint32& absorbAmount)
        {
            uint32 heal = healInfo.GetHeal();
            int32 maxPct = GetAura()->GetEffect(EFFECT_0)->GetAmount();
            uint64 maxHp = GetTarget()->GetMaxHealth() * maxPct / 100;
            uint64 hp = GetTarget()->GetHealth();
            uint64 maxHeal = maxHp - hp;

            if (hp >= maxHp)
                absorbAmount = heal;
            else if (heal >= maxHeal)
                absorbAmount = heal - maxHeal;
            else
                absorbAmount = 0;
        }


        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetTarget())
            {
                if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_1))
                    if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_1))
                        aurEff->SetDamage(caster->SpellDamageBonusDone(GetTarget(), GetSpellInfo(), 0, DOT, aurEff->GetSpellEffectInfo(), GetStackAmount()) * aurEff->GetDonePct());
            }
        }


        void Register() override
        {
            OnEffectHealAbsorb += AuraEffectHealAbsorbFn(bfa_spell_taint_of_ghunn_AuraScript::HandleAbsorb, EFFECT_0);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_taint_of_ghunn_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new bfa_spell_taint_of_ghunn_AuraScript();
    }
};



void AddSC_boss_elder_leaxa()
{
    new bfa_boss_elder_leaxa();
    new bfa_npc_blood_effigy();
    new bfa_npc_creeping_rot_trigger();

    new bfa_spell_taint_of_ghunn();
}
