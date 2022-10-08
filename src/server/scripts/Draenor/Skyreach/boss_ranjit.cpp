#include "instance_skyreach.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

class boss_ranjit : public CreatureScript
{
public:
    // Entry: 75964
    boss_ranjit() : CreatureScript("boss_ranjit")  {  }

    enum class Spells : uint32
    {
        // Windwall.
        WINDWALL = 153315,      // 2:43:38 - 2-43-52. Random target. Every 14s.
        WINDWALL_AT_1 = 153311,
        WINDWALL_AT_2 = 153314,
        WINDWALL_MISSLE_1 = 153593,
        WINDWALL_MISSILE_2 = 153594,
        WINDWALL_DMG = 153759,
        // Four winds. Arrived after 2 or 3 instances of WindWall.
        FOUR_WINDS = 156793,
        FOUR_WINDS_DMG = 153139,
        FOUR_WINDS_AT_1 = 156634,
        FOUR_WINDS_AT_2 = 156636,
        FOUR_WINDS_VISUAL_1 = 166623,
        FOUR_WINDS_VISUAL_2 = 166664,
        // Fan of blades.
        FAN_OF_BLADES = 153757, // 2:43:34 - 2:43:50, every 16s.
        // Piercing rush.
        PIERCING_RUSH = 165731, // 2:43:29 - 2:43:44, every 15s.
        LensFlare = 154029,
    };

    enum class Texts : int8
    {
        COMBAT_START = 0,
        JUST_DIED = 1,
        FOUR_WINDS_1 = 2,
        FOUR_WINDS_2 = 2,
        KILL_PLAYER_1 = 3,
        KILL_PLAYER_2 = 3,
        VICTORY = 3
    };

    enum class Events : uint32
    {
        WINDWALL = 1,
        FOUR_WINDS = 2,
        PIERCING_RUSH = 3,
        FAN_OF_BLADES = 4,
        LENS_FLARE = 5
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ranjitAI(creature);
    }

    struct boss_ranjitAI : public BossAI
    {
        boss_ranjitAI(Creature* creature) : BossAI(creature, Data::Ranjit),
            m_countWindwalls(0)
        {
            m_TriggerFourWinds[0] = ObjectGuid::Empty;
            m_TriggerFourWinds[1] = ObjectGuid::Empty;

            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        }

        void Reset()
        {
            _Reset();

            m_countWindwalls = 0;
            m_TriggerFourWinds[0] = ObjectGuid::Empty;
            m_TriggerFourWinds[1] = ObjectGuid::Empty;
            summons.DespawnAll();
            if (m_TriggerFourWinds[0] == ObjectGuid::Empty)
            {
                m_TriggerFourWinds[0] = me->SummonCreature(MobEntries::ArakkoaPincerBirdsController, 1165.871f, 1727.601f, 186.f)->GetGUID();
            }
            if (m_TriggerFourWinds[1] == ObjectGuid::Empty)
            {
                m_TriggerFourWinds[1] = me->SummonCreature(MobEntries::ArakkoaPincerBirdsController, 1165.871f, 1727.601f, 189.4522f)->GetGUID();
            }
        }

        void JustReachedHome()
        {
            _JustReachedHome();
            Talk(int8(Texts::VICTORY), me);

            if (instance)
            {
                instance->SetBossState(Data::Ranjit, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();

            Talk(int8(Texts::JUST_DIED), me);

            me->CastSpell(me, RandomSpells::DespawnAreaTriggers, true);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (urand(0, 1))
                Talk(int8(Texts::KILL_PLAYER_1), me);
            else
                Talk(int8(Texts::KILL_PLAYER_2), me);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            events.ScheduleEvent(uint32(Events::WINDWALL), 8000);
            events.ScheduleEvent(uint32(Events::FAN_OF_BLADES), 5000);
            events.ScheduleEvent(uint32(Events::PIERCING_RUSH), 1000);

            Talk(int8(Texts::COMBAT_START), me);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case uint32(Events::FOUR_WINDS):
                me->CastSpell(me->GetVictim(), uint32(Spells::FOUR_WINDS));

                m_countWindwalls = 0;
                if (urand(0, 1))
                    Talk(int8(Texts::FOUR_WINDS_1), me);
                else
                    Talk(int8(Texts::FOUR_WINDS_2), me);

                if (IsHeroic())
                    events.ScheduleEvent(uint32(Events::LENS_FLARE), 14000);
                break;
            case uint32(Events::WINDWALL):
                events.ScheduleEvent(uint32(Events::WINDWALL), urand(19000, 26000));

                if (Player* player = me->SelectRandomPlayerInRange(40.0f, true))
                    me->CastSpell(player, uint32(Spells::WINDWALL));

                if (m_countWindwalls++ == 2)
                    events.ScheduleEvent(uint32(Events::FOUR_WINDS), urand(2000, 3000));
                break;
            case uint32(Events::FAN_OF_BLADES):
                events.ScheduleEvent(uint32(Events::FAN_OF_BLADES), urand(15000, 17000));
                me->CastSpell(me, uint32(Spells::FAN_OF_BLADES));
                break;
            case uint32(Events::PIERCING_RUSH):
                events.ScheduleEvent(uint32(Events::PIERCING_RUSH), urand(13000, 16000));
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                    if (target->IsPlayer())
                        me->CastSpell(target, uint32(Spells::PIERCING_RUSH));
                    else if (Player* player = me->SelectRandomPlayerInRange(40.0f, true))
                        me->CastSpell(player, uint32(Spells::PIERCING_RUSH));
                break;
            case uint32(Events::LENS_FLARE):
                if (Player* player = me->SelectRandomPlayerInRange(80.0f, true))
                    player->CastSpell(player, uint32(Spells::LensFlare), true);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

        uint32 m_countWindwalls;
        ObjectGuid m_TriggerFourWinds[2];
    };
};

void AddSC_boss_ranjit()
{
    new boss_ranjit();
}

