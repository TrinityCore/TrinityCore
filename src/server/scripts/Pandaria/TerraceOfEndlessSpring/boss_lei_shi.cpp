#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "terrace_of_endless_spring.h"
#include "GridNotifiers.h"
#include "Group.h"

static const Position aLeiWps[] =
{
    { -1017.7f, -2864.0f, 30.4f, 4.71f },
    { -1017.8f, -2771.9f, 38.6f, 4.71f },
};

enum eLeiShiSpells
{
    SPELL_AFRAID = 123181,
    SPELL_SPRAY = 123121,
    SPELL_HIDE = 123244,
    SPELL_HIDE_SUMMON = 123213,
    SPELL_HIDE_STACKS = 123233,
    SPELL_GET_AWAY = 123461,
    SPELL_GET_AWAY_TELEPORT = 123441,
    SPELL_PROTECT = 123250,
    SPELL_PROTECT_RESPAWN = 123493,
    SPELL_PROTECT_VISUAL = 123505,
    SPELL_CLOUDED_REFLECTION = 123620,
    SPELL_CLOUDED_IMPACT = 123625,

    // This is for Heroic Mode
    SPELL_SCARY_FOG_CIRCLE = 123797,
    SPELL_SCARY_FOG_DOT = 123705,
    SPELL_SCARY_FOG_STACKS = 123712,

    SPELL_LEI_SHI_TRANSFORM = 127535,
    SPELL_LEI_SHI_ACHIEVEMENT_MARKER = 123903,
};

enum eLeiShiEvents
{
    // Lei Shi
    EVENT_SPECIAL = 1,
    EVENT_SPRAY = 2,
    EVENT_GET_AWAY = 3,
    EVENT_GET_AWAY_CAST = 4,
    EVENT_PROTECT = 5,
    EVENT_HIDE = 6,

    // Lei Shi (hidden)
    EVENT_HIDDEN_SPRAY = 7,
    EVENT_BERSERK = 8,

    // OOC
    EVENT_WP_1 = 9,
    EVENT_WP_2 = 10,
    EVENT_WP_3 = 11,

    EVENT_HIDE_NEW,
    EVENT_HIDE_REVEAL,
    EVENT_PROTECT_FINAL,
};

enum eLeiShiActions
{
    ACTION_ANIMATED_PROTECTOR_DIED,
    ACTION_ACTIVATE_ANIMATED_PROTECTORS,
    ACTION_TERMINATE_GET_AWAY_PHASE,
    ACTION_TERMINATE_HIDE_PHASE,
};

enum eLeiShiSays
{
    TALK_AGGRO = 1,
    TALK_HIDE,
    TALK_GET_AWAY,
    TALK_SLAY,
    TALK_INTRO,
    TALK_DEFEATED,
    TALK_OUTRO_1,
    TALK_OUTRO_2
};

enum eReflectionSays
{
    EMOTE_RIPPLE,
    EMOTE_RIPPLE_2,
    EMOTE_APPEAR
};

Position leiShiPos = { -1017.93f, -2911.3f, 19.902f, 4.74f };

Position hidePositions[4] =
{
    { -990.678f,  -2890.043f, 19.172f, 3.781f },
    { -994.835f,  -2933.835f, 19.172f, 2.377f },
    { -1041.316f, -2932.84f,  19.172f, 0.733f },
    { -1045.101f, -2890.742f, 19.172f, 5.646f }
};

#define HEROIC_DIST_TO_VORTEX 21.0f
#define DIST_TO_SCARY_FOG_DOT 4.5f

class boss_lei_shi : public CreatureScript
{
public:
    boss_lei_shi() : CreatureScript("boss_lei_shi") { }

    struct boss_lei_shiAI : public BossAI
    {
        boss_lei_shiAI(Creature* creature) : BossAI(creature, DATA_LEI_SHI)
        {
            pInstance = creature->GetInstanceScript();
            leiShiFreed = false;
            //me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* pInstance;
        EventMap events;
        EventMap m_mEvents;

        uint8 nextAfraidPct;
        uint8 nextProtectPct;

        uint8 endCombatPct;

        std::list<uint64> animatedProtectors;

        bool hidden;
        bool shielded;
        bool getAwayPhase;
        bool protectScheduled;
        bool leiShiFreed;
        bool nextSpecial;
        bool protectone;
        bool protecttwo;
        bool protectthree;
        bool protectfour;

        float getAwayHealthPct;

        void Reset()
        {
            _Reset();

            summons.DespawnAll();
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
            protectone = false;
            protecttwo = false;
            protectthree = false;
            protectfour = false;
            hidden = false;
            getAwayPhase = false;
            shielded = false;
            protectScheduled = false;
            nextSpecial = (bool)urand(0, 1);

            nextAfraidPct = 90;
            nextProtectPct = 80;
            endCombatPct = 2;

            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RestoreDisplayId();
            me->RemoveAura(SPELL_AFRAID);
            me->RemoveAura(SPELL_HIDE);
            me->RemoveAura(SPELL_HIDE_STACKS);
            me->RemoveAura(SPELL_SCARY_FOG_CIRCLE);
            me->RemoveAura(SPELL_SCARY_FOG_DOT);
            me->RemoveAura(SPELL_SCARY_FOG_STACKS);
            me->RemoveAllAreaTriggers();

            events.Reset();

            events.ScheduleEvent(EVENT_SPRAY, 400);

            ScheduleSpecialSpell();

            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_CIRCLE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_DOT);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_STACKS);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPRAY);

                /* if (pInstance->GetData(SPELL_RITUAL_OF_PURIFICATION))
                     me->AddAura(SPELL_RITUAL_OF_PURIFICATION, me);*/

                std::list<Creature*> protectors;
                me->GetCreatureListWithEntryInGrid(protectors, NPC_ANIMATED_PROTECTOR, 100.0f);

                for (auto itr : protectors)
                {
                    itr->Respawn();
                    itr->AddAura(SPELL_PROTECT_RESPAWN, itr);
                    itr->RemoveAura(SPELL_PROTECT_VISUAL);
                    itr->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            if (leiShiFreed)
                me->CastSpell(me, SPELL_LEI_SHI_TRANSFORM, true);
        }

        void ScheduleSpecialSpell()
        {
            events.ScheduleEvent(nextSpecial ? EVENT_GET_AWAY : EVENT_HIDE_NEW, 32000);
            nextSpecial = !nextSpecial;
        }

        void JustReachedHome()
        {
            _JustReachedHome();
            if (leiShiFreed)
                return;

            if (pInstance)
                pInstance->SetBossState(DATA_LEI_SHI, FAIL);
;
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 45)
            {
                me->SetFacingTo(4.71f);
                m_mEvents.ScheduleEvent(EVENT_WP_2, 500);
            }
        }

        void EnterCombat(Unit* /*attacker*/)
        {
            if (pInstance)
            {

                me->CastSpell(me, SPELL_AFRAID, true);

                pInstance->SetBossState(DATA_LEI_SHI, IN_PROGRESS);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();

                if (me->GetMap()->IsHeroic())
                    me->CastSpell(me, SPELL_SCARY_FOG_CIRCLE, true);

                Talk(TALK_AGGRO);

                events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);
            }
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(TALK_SLAY);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (!pInstance)
                return;

            if (nextAfraidPct)
            {
                if (me->HealthBelowPctDamaged(nextAfraidPct, damage))
                {

                    nextAfraidPct -= 10;
                }

                if (me->HealthBelowPctDamaged(int32(getAwayHealthPct - 4.0f), damage))
                    me->RemoveAura(SPELL_GET_AWAY);

                /*if (nextProtectPct >= 20)
                {
                    if (me->HealthBelowPctDamaged(nextProtectPct, damage) && !protectScheduled)
                    {
                        protectScheduled = true;
                        events.ScheduleEvent(EVENT_PROTECT, 100);
                    }
                }*/

                if (me->HealthBelowPct(80) && !protectone)
                {
                    protectone = true;
                    events.ScheduleEvent(EVENT_PROTECT, 100);
                }

                if (me->HealthBelowPct(60) && !protecttwo)
                {
                    protecttwo = true;
                    events.ScheduleEvent(EVENT_PROTECT, 100);
                }

                if (me->HealthBelowPct(40) && !protectthree)
                {
                    protectthree = true;
                    events.ScheduleEvent(EVENT_PROTECT_FINAL, 100);
                }

                if (me->HealthBelowPct(20) && !protectfour)
                {
                    protectfour = true;
                    events.ScheduleEvent(EVENT_PROTECT_FINAL, 100);
                }
            }

            if (me->HealthBelowPctDamaged(endCombatPct, damage))
            {
                damage = 0;

                if (leiShiFreed)
                    return;

                me->CastSpell(me, SPELL_LEI_SHI_ACHIEVEMENT_MARKER, true);

                summons.DespawnAll();
                pInstance->SetBossState(DATA_LEI_SHI, DONE);
                events.Reset();

                EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

                me->CombatStop();
                me->DeleteThreatList();
                me->SetFaction(35);
                me->CastSpell(me, SPELL_LEI_SHI_TRANSFORM, true);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->RestoreDisplayId();
                me->RemoveAura(SPELL_AFRAID);
                me->RemoveAura(SPELL_HIDE);
                me->RemoveAura(SPELL_HIDE_STACKS);
                me->RemoveAura(SPELL_SCARY_FOG_CIRCLE);
                me->RemoveAura(SPELL_SCARY_FOG_DOT);
                me->RemoveAura(SPELL_SCARY_FOG_STACKS);
                me->RemoveAura(SPELL_BERSERK);
                me->RemoveAllAreaTriggers();
                me->setRegeneratingHealth(false);

                leiShiFreed = true;
                Talk(TALK_DEFEATED);

                m_mEvents.ScheduleEvent(EVENT_WP_1, 15000);

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_CIRCLE);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_DOT);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARY_FOG_STACKS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPRAY);
                }
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (!hidden)
                return;

            if (!caster)
                return;

            if (caster->GetTypeId() == TYPEID_UNIT && (caster->GetEntry() == NPC_LEI_SHI || caster->GetEntry() == NPC_LEI_SHI_HIDDEN))
                return;

            if (!spell)
                return;

            if (!spell->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) &&
                !spell->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG) &&
                !spell->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE) &&
                !spell->HasEffect(SPELL_EFFECT_WEAPON_PERCENT_DAMAGE) &&
                !spell->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL))
                return;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ANIMATED_PROTECTOR_DIED:
            {
                me->RemoveAura(SPELL_PROTECT);
                shielded = false;
                protectScheduled = false;

                Creature* protector = NULL;

                for (auto itr : animatedProtectors)
                {
                    if (Creature* elemental = me->FindNearestCreature(NPC_ANIMATED_PROTECTOR, 500.0f))
                    {
                        if (!elemental->IsAlive())
                            protector = elemental;

                        elemental->RemoveAura(SPELL_PROTECT_VISUAL);
                        elemental->AddAura(SPELL_PROTECT_RESPAWN, elemental);
                        elemental->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                        elemental->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                        elemental->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                    }
                }

                break;
            }
            case ACTION_ACTIVATE_ANIMATED_PROTECTORS:
            {
                if (animatedProtectors.empty())
                    break;

                me->CastSpell(me, SPELL_PROTECT, false);
                shielded = true;

                uint8 protectorsActivated = 0;
                for (auto itr : animatedProtectors)
                {
                    // 3 Animated Protectors at 80% and 60%
                    if (((me->GetMap()->IsHeroic() && protectorsActivated >= 3) ||
                        (!me->GetMap()->IsHeroic() && protectorsActivated >= 3)))
                        // && nextProtectPct > 40)
                        break;

                    // 4 Animated Protectors at 40% and 20%
                  //  if (((me->GetMap()->IsHeroic() && protectorsActivated >= 5) ||
                  //      (!me->GetMap()->IsHeroic() && protectorsActivated >= 4)))
                        // && nextProtectPct <= 40)
                //        break;

                    if (Creature* protector = me->FindNearestCreature(NPC_ANIMATED_PROTECTOR, 500.0f))
                    {
                        protector->SetHealth(protector->GetMaxHealth());
                        protector->RemoveAura(SPELL_PROTECT_RESPAWN);
                        protector->CastSpell(protector, SPELL_PROTECT_VISUAL, true);
                        protector->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        protector->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        protector->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);

                        if (protector->AI())
                            protector->AI()->DoZoneInCombat();

                        ++protectorsActivated;
                    }
                }

                break;
            }
            case ACTION_TERMINATE_GET_AWAY_PHASE:
            {
                getAwayPhase = false;
                me->RemoveAllAreaTriggers();

                ScheduleSpecialSpell();
                break;
            }
            case ACTION_TERMINATE_HIDE_PHASE:
            {
                me->RemoveAura(SPELL_HIDE);
                me->RemoveAura(SPELL_HIDE_STACKS);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->RestoreDisplayId();
                hidden = false;

                if (me->GetMap()->IsHeroic())
                    me->CastSpell(me, SPELL_SCARY_FOG_CIRCLE, true);

                // Only have Lei Shi (hidden) in summons
                summons.DespawnAll();

                ScheduleSpecialSpell();
                break;
            }
            case ACTION_LEISHI_INTRO:
            {
                me->SetReactState(REACT_AGGRESSIVE);
                Talk(TALK_INTRO);

                break;
            }
            case ACTION_ACTIVATE_ANIMATED_PROTECTORS_FINAL:
            {
                if (animatedProtectors.empty())
                    break;

                me->CastSpell(me, SPELL_PROTECT, false);
                shielded = true;

                uint8 protectorsActivated = 0;
                for (auto itr : animatedProtectors)
                {
                    if ((me->GetMap()->IsHeroic() && protectorsActivated >= 4) ||
                        (!me->GetMap()->IsHeroic() && protectorsActivated >= 4))
                        break;

                    if (Creature* protector = me->FindNearestCreature(NPC_ANIMATED_PROTECTOR, 500.0f))
                    {
                        protector->SetHealth(protector->GetMaxHealth());
                        protector->RemoveAura(SPELL_PROTECT_RESPAWN);
                        protector->CastSpell(protector, SPELL_PROTECT_VISUAL, true);
                        protector->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        protector->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        protector->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);

                        if (protector->AI())
                            protector->AI()->DoZoneInCombat();

                        ++protectorsActivated;
                    }
                }

                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            m_mEvents.Update(diff);

            switch (m_mEvents.ExecuteEvent())
            {
            case EVENT_WP_1:
                Talk(TALK_OUTRO_1);

                me->SetWalk(true);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(45, aLeiWps[0]);
                break;
            case EVENT_WP_2:
                Talk(TALK_OUTRO_2);
                m_mEvents.ScheduleEvent(EVENT_WP_3, 8000);
                break;
            case EVENT_WP_3:
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(46, aLeiWps[1]);
                break;
            }

            if (!UpdateVictim())
            {
                /*
                if (pInstance && pInstance->GetData(SPELL_RITUAL_OF_PURIFICATION) == false)
                    me->RemoveAura(SPELL_RITUAL_OF_PURIFICATION);*/

                std::list<Creature*> protectors;
                me->GetCreatureListWithEntryInGrid(protectors, NPC_ANIMATED_PROTECTOR, 100.0f);

                protectors.remove_if(Trinity::UnitAuraCheck(true, SPELL_PROTECT_RESPAWN));

                for (auto itr : protectors)
                {
                    itr->Respawn();
                    itr->AddAura(SPELL_PROTECT_RESPAWN, itr);
                    itr->RemoveAura(SPELL_PROTECT_VISUAL);
                    itr->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    itr->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                    itr->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                }

                return;
            }

            if (hidden)
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_BERSERK:
                DoCast(me, SPELL_BERSERK, true);
                break;
            case EVENT_SPRAY:
            {
                if (getAwayPhase || me->HasUnitState(UNIT_STATE_CASTING))
                {
                    events.ScheduleEvent(EVENT_SPRAY, 400);
                    break;
                }

                //if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                if (Unit* target = me->GetVictim())
                {
                    if (!target)
                        break;

                    if (target->GetTypeId() == TYPEID_PLAYER)
                        me->CastSpell(target, SPELL_SPRAY);
                }
                events.ScheduleEvent(EVENT_SPRAY, 400);
                break;
            }
            case EVENT_GET_AWAY:
            {
                if ((me->HasUnitState(UNIT_STATE_CASTING) && !getAwayPhase) || shielded)
                {
                    events.ScheduleEvent(EVENT_GET_AWAY, 0);
                    break;
                }

                // Teleport Lei Shi to the center of the room
                Talk(TALK_GET_AWAY);
                me->CastSpell(me, SPELL_GET_AWAY_TELEPORT, true);
                getAwayPhase = true;
                getAwayHealthPct = me->GetHealthPct();
                events.ScheduleEvent(EVENT_GET_AWAY_CAST, 300);
                break;
            }
            case EVENT_GET_AWAY_CAST:
            {
                me->CastSpell(me, SPELL_GET_AWAY, false);
                break;
            }
            case EVENT_PROTECT:
            {
                if (getAwayPhase || me->HasUnitState(UNIT_STATE_CASTING))
                {
                    events.RescheduleEvent(EVENT_PROTECT, 0);
                    break;
                }

                DoAction(ACTION_ACTIVATE_ANIMATED_PROTECTORS);
                break;
            }
            case EVENT_PROTECT_FINAL:
            {
                if (getAwayPhase || me->HasUnitState(UNIT_STATE_CASTING))
                {
                    events.RescheduleEvent(EVENT_PROTECT_FINAL, 0);
                    break;
                }

                DoAction(ACTION_ACTIVATE_ANIMATED_PROTECTORS_FINAL);
                break;
            }
            case EVENT_HIDE:
            {
                /* if (me->HasUnitState(UNIT_STATE_CASTING) || shielded)
                 {
                     events.RescheduleEvent(EVENT_HIDE, 0);
                     break;
                 }

                 Talk(TALK_HIDE);
                 me->CastSpell(me, SPELL_HIDE);
                 hidden = true;
                 me->RemoveAura(SPELL_SCARY_FOG_CIRCLE);*/
                break;
            }
            case EVENT_HIDE_NEW:
                Talk(TALK_HIDE);
                {
                    uint8 pos = urand(0, 3);

                    me->NearTeleportTo(hidePositions[pos].GetPositionX(),
                        hidePositions[pos].GetPositionY(),
                        hidePositions[pos].GetPositionZ(),
                        hidePositions[pos].GetOrientation(), true);
                }

                //me->CastSpell(me, SPELL_HIDE_SUMMON, true);
                me->RemoveAura(SPELL_SCARY_FOG_CIRCLE);
                me->SetDisplayId(11686);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->AddAura(42716, me);
                events.ScheduleEvent(EVENT_HIDE_REVEAL, 19000, 0, 0);
                break;
            case EVENT_HIDE_REVEAL:
            {
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                if (me->GetMap()->IsHeroic())
                    me->CastSpell(me, SPELL_SCARY_FOG_CIRCLE, true);

                // Only have Lei Shi (hidden) in summons
                summons.DespawnAll();
                ScheduleSpecialSpell();
                me->RestoreDisplayId();
                me->RemoveAura(42716);
            }
            break;
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lei_shiAI(creature);
    }
};

// Animated Protector - 62995
class mob_animated_protector : public CreatureScript
{
public:
    mob_animated_protector() : CreatureScript("mob_animated_protector") { }

    struct mob_animated_protectorAI : public ScriptedAI
    {
        mob_animated_protectorAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void JustDied(Unit* /*killer*/)
        {
            if (Creature* leiShi = me->FindNearestCreature(NPC_LEI_SHI, 500.0f))
                leiShi->AI()->DoAction(ACTION_ANIMATED_PROTECTOR_DIED);
        }

        void UpdateAI(uint32 /*diff*/)
        {
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_animated_protectorAI(creature);
    }
};

// Lei Shi (hidden) - 63099
class mob_lei_shi_hidden : public CreatureScript
{
    enum
    {
        SPELL_HIDE_VISUAL = 132363,
        SPELL_HIDE_PROC = 123233,
        SPELL_HIDE_TRIGGER = 132362,
    };
public:
    mob_lei_shi_hidden() : CreatureScript("mob_lei_shi_hidden") { }

    struct mob_lei_shi_hiddenAI : public ScriptedAI
    {
        mob_lei_shi_hiddenAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void SpellHitTarget(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_HIDE_TRIGGER)
                caster->CastSpell(caster, SPELL_HIDE_VISUAL, true);
        }

        void Reset()
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);

            events.Reset();
            events.ScheduleEvent(EVENT_HIDDEN_SPRAY, 400);

            DoCast(me, SPELL_HIDE_PROC, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_HIDDEN_SPRAY:
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                {
                    events.ScheduleEvent(EVENT_HIDDEN_SPRAY, 0);
                    break;
                }

                uint64 leiShiGuid = 0;
                if (pInstance)
                    leiShiGuid = pInstance->GetData64(NPC_LEI_SHI);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f))
                    me->CastSpell(target, SPELL_SPRAY, false);
                events.ScheduleEvent(EVENT_HIDDEN_SPRAY, 400);
                break;
            }
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_lei_shi_hiddenAI(creature);
    }
};

class npc_lei_shi_reflection : public CreatureScript
{
    enum eEvents : uint32
    {
        EVENT_NONE,
        EVENT_RIPPLE_1,
        EVENT_RIPPLE_2,
        EVENT_APPEAR
    };
public:
    npc_lei_shi_reflection() : CreatureScript("npc_lei_shi_reflection") {}

    struct npc_lei_shi_reflectionAI : public ScriptedAI
    {
        npc_lei_shi_reflectionAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        EventMap events;

        void DoAction(int32 iAction) override
        {
            if (iAction == ACTION_LEISHI_INTRO)
            {
                me->ClearUnitState(UNIT_STATE_STUNNED);
                events.ScheduleEvent(EVENT_RIPPLE_1, 2000);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RIPPLE_1:
                    DoCast(SPELL_CLOUDED_IMPACT);
                    Talk(EMOTE_RIPPLE);
                    events.ScheduleEvent(EVENT_RIPPLE_2, 14000);
                    break;
                case EVENT_RIPPLE_2:
                    DoCast(SPELL_CLOUDED_IMPACT);
                    Talk(EMOTE_RIPPLE_2);
                    events.ScheduleEvent(EVENT_APPEAR, 10000);
                    break;
                case EVENT_APPEAR:
                    if (me->GetInstanceScript())
                    {
                        if (Creature* pLeiShi = me->FindNearestCreature(NPC_LEI_SHI, 500.0f))
                        {
                            Talk(EMOTE_APPEAR);

                            if (pLeiShi->AI())
                                pLeiShi->AI()->DoAction(ACTION_LEISHI_INTRO);
                        }
                    }
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lei_shi_reflectionAI(pCreature);
    }
};

// Get Away ! - 123461
class bfa_spell_toes_get_away : public SpellScriptLoader
{
public:
    bfa_spell_toes_get_away() : SpellScriptLoader("bfa_spell_toes_get_away") { }

    class bfa_spell_toes_get_away_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_get_away_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature())
                    if (caster->ToCreature()->AI())
                        caster->ToCreature()->AI()->DoAction(ACTION_TERMINATE_GET_AWAY_PHASE);
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_get_away_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_get_away_AuraScript();
    }
};

// Hide - 123244
class bfa_spell_toes_hide : public SpellScriptLoader
{
public:
    bfa_spell_toes_hide() : SpellScriptLoader("bfa_spell_toes_hide") { }

    class bfa_spell_toes_hide_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_hide_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {

                uint8 pos = urand(0, 3);

                caster->NearTeleportTo(hidePositions[pos].GetPositionX(),
                    hidePositions[pos].GetPositionY(),
                    hidePositions[pos].GetPositionZ(),
                    hidePositions[pos].GetOrientation());

                caster->CastSpell(caster, SPELL_HIDE_STACKS);
                caster->CastSpell(caster, SPELL_HIDE_SUMMON);

                caster->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                caster->SetDisplayId(11686);
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->RemoveAura(SPELL_HIDE_STACKS);
                caster->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                caster->RestoreDisplayId();
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(bfa_spell_toes_hide_AuraScript::OnApply, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_hide_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_hide_AuraScript();
    }
};

// Get Away damage - 123467
class bfa_spell_toes_get_away_dmg : public SpellScriptLoader
{
public:
    bfa_spell_toes_get_away_dmg() : SpellScriptLoader("bfa_spell_toes_get_away_dmg") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void ModifyDamage(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            Player* victim = GetHitPlayer();

            if (!caster || !victim)
                return;

            if (victim->isMoving() && !victim->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_BACKWARD) && victim->isInFront(caster))
                SetHitDamage(GetHitDamage() / 2);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_toes_impl::ModifyDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};


// Hide (stacks) - 123233
class bfa_spell_toes_hide_stacks : public SpellScriptLoader
{
public:
    bfa_spell_toes_hide_stacks() : SpellScriptLoader("bfa_spell_toes_hide_stacks") { }

    class bfa_spell_toes_hide_stacks_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_hide_stacks_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature())
                    if (caster->ToCreature()->AI())
                        caster->ToCreature()->AI()->DoAction(ACTION_TERMINATE_HIDE_PHASE);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_hide_stacks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_hide_stacks_AuraScript();
    }
};

// Scary Fog (DoT) - 123705
class bfa_spell_toes_scary_fog_dot : public SpellScriptLoader
{
public:
    bfa_spell_toes_scary_fog_dot() : SpellScriptLoader("bfa_spell_toes_scary_fog_dot") { }

    class bfa_spell_toes_scary_fog_dot_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_scary_fog_dot_SpellScript);

        void CorrectRange(std::list<WorldObject*>& targets)
        {
            targets.clear();

            if (Unit* pCaster = GetCaster())
            {
                Map::PlayerList const& players = pCaster->GetMap()->GetPlayers();

                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        if (player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) >= HEROIC_DIST_TO_VORTEX)
                            targets.push_back(player);
                    }
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_scary_fog_dot_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_scary_fog_dot_SpellScript();
    }

    class bfa_spell_toes_scary_fog_dot_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_scary_fog_dot_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_SCARY_FOG_STACKS, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_toes_scary_fog_dot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_scary_fog_dot_AuraScript();
    }
};

// Scary Fog (stacks) - 123712
/*class bfa_spell_toes_scary_fog_stacks : public SpellScriptLoader
{
public:
    bfa_spell_toes_scary_fog_stacks() : SpellScriptLoader("bfa_spell_toes_scary_fog_stacks") { }

    class bfa_spell_toes_scary_fog_stacks_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_scary_fog_stacks_SpellScript);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            targets.push_back(caster);

            for (auto itr : targets)
            {
                Unit* currentAoETarget = itr->ToUnit();
                if (currentAoETarget->GetEntry() == NPC_LEI_SHI_HIDDEN)
                    continue;

                uint32 stacks = 0;
                // count stacks from all nearby players (including self)
                Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        if (player->IsAlive() && player->GetDistance2d(currentAoETarget) <= 2.0f)
                            if (auto aura = player->GetAura(SPELL_SCARY_FOG_DOT))
                                stacks += aura->GetStackAmount();

                if (auto aura = currentAoETarget->GetAura(SPELL_SCARY_FOG_STACKS))
                {
                    aura->SetStackAmount(stacks);
                    aura->RefreshDuration();
                }
                else if (auto aura = caster->AddAura(SPELL_SCARY_FOG_STACKS, currentAoETarget))
                    aura->SetStackAmount(stacks);
            }

            targets.clear();
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_scary_fog_stacks_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_scary_fog_stacks_SpellScript();
    }
};*/

// Get Away - 123461
/*
class bfa_spell_get_away_pushback : public SpellScriptLoader
{
public:
    bfa_spell_get_away_pushback() : SpellScriptLoader("bfa_spell_get_away_pushback") { }

    class bfa_spell_get_away_pushback_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_get_away_pushback_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                Map::PlayerList const& players = caster->GetMap()->GetPlayers();

                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        if (Player* player = i->GetSource())
                            ForcePlayersMove(player);
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
            {
                Map::PlayerList const& players = caster->GetMap()->GetPlayers();

                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                        if (Player* player = i->GetSource())
                            ForcePlayersMoveStop(player);
            }
        }

        void ForcePlayersMove(Player* player)
        {
            ObjectGuid plrGuid = player->GetGUID();
            WorldPacket data(SMSG_CLIENT_MOVE_APPLY_MOVEMENT_FORCE);
            float xOffset = -3.0f, yOffset = 4.0f, zOffset = 0.0f; // aici trebuie sa umlbi pentru DIRECTIE... e unghiul format din X Y si Z.. Z nu trebuie sa umbli, aia e pentru miscare pe verticala.. te joci cu numerele alea pana iti dai seama. trebuie valori mici.. cam intre -10 si 10 cred

            data.WriteBit(plrGuid[2]);
            data.WriteBit(plrGuid[3]);
            data.WriteBits(0, 2);
            data.WriteBit(plrGuid[7]);
            data.WriteBit(plrGuid[5]);
            data.WriteBit(plrGuid[0]);
            data.WriteBit(plrGuid[1]);
            data.WriteBit(plrGuid[6]);
            data.WriteBit(plrGuid[4]);
            data.FlushBits();
            data.WriteByteSeq(plrGuid[6]);
            data << float(yOffset); // Y offset
            data.WriteByteSeq(plrGuid[4]);
            data << float(zOffset); // Z offset
            data << int32(0);
            data << int32(0x10001000); // movement ID ?
            data.WriteByteSeq(plrGuid[5]);
            data << float(4.0f); // magnitude aici e viteza, ar trebui sa fie ok 8.0f
            data.WriteByteSeq(plrGuid[0]);
            data.WriteByteSeq(plrGuid[7]);
            data.WriteByteSeq(plrGuid[1]);
            data.WriteByteSeq(plrGuid[3]);
            data.WriteByteSeq(plrGuid[2]);
            data << int32(0);
            data << float(xOffset); // X offset
            player->GetSession()->SendPacket(&data);
        }

        void ForcePlayersMoveStop(Player* player)
        {
            ObjectGuid plrGuid = player->GetGUID();
            WorldPacket data(SMSG_CLIENT_MOVE_REMOVE_MOVEMENT_FORCE);

            data.WriteBit(plrGuid[1]);
            data.WriteBit(plrGuid[2]);
            data.WriteBit(plrGuid[4]);
            data.WriteBit(plrGuid[7]);
            data.WriteBit(plrGuid[6]);
            data.WriteBit(plrGuid[0]);
            data.WriteBit(plrGuid[5]);
            data.WriteBit(plrGuid[3]);
            data.WriteByteSeq(plrGuid[4]);
            data.WriteByteSeq(plrGuid[7]);
            data.WriteByteSeq(plrGuid[0]);
            data << int32(0);
            data.WriteByteSeq(plrGuid[1]);
            data.WriteByteSeq(plrGuid[3]);
            data.WriteByteSeq(plrGuid[5]);
            data << int32(0x10001000); // movement ID ?
            data.WriteByteSeq(plrGuid[6]);
            data.WriteByteSeq(plrGuid[2]);
            player->GetSession()->SendPacket(&data);
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(bfa_spell_get_away_pushback_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_get_away_pushback_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_get_away_pushback_AuraScript();
    }
};*/

void AddSC_boss_lei_shi()
{
    new boss_lei_shi();
    new mob_animated_protector();
    new mob_lei_shi_hidden();
    new npc_lei_shi_reflection();
    new bfa_spell_toes_get_away();
    new bfa_spell_toes_get_away_dmg();
    new bfa_spell_toes_hide();
    new bfa_spell_toes_hide_stacks();
    new bfa_spell_toes_scary_fog_dot();
    //ew bfa_spell_toes_scary_fog_stacks();
    //new bfa_spell_get_away_pushback();
}
