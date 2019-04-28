#include "ScriptMgr.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "CreatureAIImpl.h"

enum Spells
{
    SPELL_FLASH_HEAL            = 100015,
    SPELL_SMITE                 = 100016,
    SPELL_POWER_WORD_SHIELD     = 100017,
    SPELL_HOLY_FIRE             = 100018,
    SPELL_MASS_HEAL             = 100019,
    SPELL_WEAKENED_SOUL         = 6788,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_PAIN_SUPPRESSION      = 100020,
    SPELL_MANA_POTION           = 100022,
    SPELL_HEALTH_POTION         = 100023,
    SPELL_SPIRIT_HEALER_VISUAL  = 70571,
    SPELL_REJUVENATION          = 100024
};

enum Misc
{
    NPC_LIGHTWELL               = 100013,
    NPC_SPIRIT_HEALER           = 100015,
    NPC_INVISIBLE_STALKER       = 32780
};

enum Casting
{
    CASTING_HEAL                = 1,
    CASTING_SMITE,
    CASTING_POWER_WORD_SHIELD,
    CASTING_HOLY_FIRE
};

class npc_priest : public CreatureScript
{
    public:
    npc_priest() : CreatureScript("npc_priest") {}

    struct npc_priestAI : public ScriptedAI
    {
        npc_priestAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            resTarget = nullptr;
            isSaved = false;
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                DoStartMovement(who, 35.f);

                events.ScheduleEvent(CASTING_HEAL, .5f);
                events.ScheduleEvent(CASTING_POWER_WORD_SHIELD, .5f);
                events.ScheduleEvent(CASTING_SMITE, .5f);
                events.ScheduleEvent(CASTING_HOLY_FIRE, 8s, 14s);
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature * spiritHealder = DoSummon(NPC_SPIRIT_HEALER, me->GetPosition(), 13000, TEMPSUMMON_TIMED_DESPAWN))
            {
                if (Creature * fx = DoSummon(NPC_INVISIBLE_STALKER, me->GetPosition(), 13000, TEMPSUMMON_TIMED_DESPAWN))
                {
                    fx->AddAura(SPELL_SPIRIT_HEALER_VISUAL, fx);
                    fx->SetObjectScale(1.5f);
                }

                double angle = 72;
                for (int i = 0; i < 5; ++i)
                {
                    Position pos = GetPositionAround(spiritHealder, angle, spiritHealder->GetObjectScale() * 3.f);
                    if (Creature * lightwell = DoSummon(NPC_LIGHTWELL, pos, 13000, TEMPSUMMON_TIMED_DESPAWN))
                        lightwell->CastSpell(lightwell, SPELL_MASS_HEAL);
                    angle += 72;
                }
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!isSaved && !me->HasAura(SPELL_PAIN_SUPPRESSION) && HealthBelowPct(10))
            {
                DoCast(SPELL_PAIN_SUPPRESSION);
                DoCast(SPELL_MANA_POTION);
                DoCast(SPELL_HEALTH_POTION);

                isSaved = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetPowerPct(POWER_MANA) <= 3.f)
                DoStartMovement(me->GetVictim());

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_SMITE:
                        DoCastVictim(SPELL_SMITE);
                        events.RescheduleEvent(CASTING_SMITE, 1180);
                        break;

                    case CASTING_HOLY_FIRE:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_HOLY_FIRE);
                        events.RescheduleEvent(CASTING_HOLY_FIRE, 5s, 8s);
                        break;

                    case CASTING_POWER_WORD_SHIELD:
                    {
                        Unit* target = DoSelectLowestHpFriendly(40.0f);
                        if (target && !target->HasAura(SPELL_WEAKENED_SOUL))
                        {
                            DoCast(target, SPELL_POWER_WORD_SHIELD);
                            DoCast(target, SPELL_WEAKENED_SOUL);
                        }
                        events.RescheduleEvent(CASTING_POWER_WORD_SHIELD, 2s);
                        break;
                    }

                    case CASTING_HEAL:
                        if (Unit * target = DoSelectLowestHpFriendly(40.0f))
                            DoCast(target, RAND(SPELL_REJUVENATION, SPELL_FLASH_HEAL));
                        events.RescheduleEvent(CASTING_HEAL, 3s);
                        break;
                }
            }
        }

        private:
        EventMap events;
        Creature* resTarget;
        bool isSaved;

        Position GetPositionAround(Unit * target, double angle, float radius)
        {
            double ang = angle * (M_PI / 180);
            Position pos;
            pos.m_positionX = target->GetPositionX() + radius * sin(ang);
            pos.m_positionY = target->GetPositionY() + radius * cos(ang);
            pos.m_positionZ = target->GetPositionZ();
            return pos;
        }
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_priestAI(creature);
    }
};

void AddSC_npc_priest()
{
    new npc_priest();
}
