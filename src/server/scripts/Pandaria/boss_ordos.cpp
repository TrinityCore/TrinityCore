#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts
{
    SAY_AGGRO         = 0, 
    SAY_DEATH         = 1,
    SAY_SLAY          = 2, 
    SAY_ANCIENT_FLAME = 3,
    SAY_ETERNAL_AGONY = 4, 
    SAY_POOL_OF_FIRE  = 5,
    SAY_BURNING_SOUL  = 6 
};

enum Spells
{
    SPELL_ANCIENT_FLAME     = 144695,
    SPELL_BURNING_SOUL      = 144689,
    SPELL_ETERNAL_AGONY     = 144696, 
    SPELL_MAGMA_CRUSH       = 144688,
    SPELL_POOL_OF_FIRE      = 144692 
};

enum Events
{
    EVENT_ANCIENT_FLAME    = 1,
    EVENT_BURNING_SOUL     = 2,
    EVENT_POOL_OF_FIRE     = 3,
    EVENT_MAGMA_CRUSH      = 4,
    EVENT_ETERNAL_AGONY    = 5
};

class boss_ordos : public CreatureScript
{
    public:
        boss_ordos() : CreatureScript("boss_ordos") { }

        struct boss_ordosAI : public ScriptedAI
        {
            boss_ordosAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_MAGMA_CRUSH, urand(10000, 13000)); 
                
                _events.ScheduleEvent(EVENT_ANCIENT_FLAME, urand(40000, 45000)); 
                
                _events.ScheduleEvent(EVENT_BURNING_SOUL, urand(20000, 30000)); 
                
                _events.ScheduleEvent(EVENT_POOL_OF_FIRE, urand(30000, 45000));
            }

            void KilledUnit(Unit* victim) override
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
            }
    
            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_ETERNAL_AGONY, 300000);
                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ETERNAL_AGONY:
                            Talk(SAY_ETERNAL_AGONY);
                            DoCastVictim(SPELL_ETERNAL_AGONY);
                            _events.ScheduleEvent(EVENT_ETERNAL_AGONY, urand(10000, 25000));
                            break;
                        case EVENT_ANCIENT_FLAME:
                            Talk(SAY_ANCIENT_FLAME);
                            DoCast(me, SPELL_ANCIENT_FLAME);
                            _events.ScheduleEvent(EVENT_ANCIENT_FLAME, urand(40000, 45000));
                            break;
                        case EVENT_POOL_OF_FIRE:
                            Talk(SAY_POOL_OF_FIRE);
                            DoCast(me, SPELL_POOL_OF_FIRE);
                            _events.ScheduleEvent(EVENT_POOL_OF_FIRE, urand(30000, 40000));
                            break;
                        case EVENT_MAGMA_CRUSH:
                            DoCastVictim(SPELL_MAGMA_CRUSH);
                            _events.ScheduleEvent(EVENT_MAGMA_CRUSH, urand(7000, 27000));
                            break;
                        case EVENT_BURNING_SOUL:
                            Talk(SAY_BURNING_SOUL);
                            DoCastVictim(SPELL_BURNING_SOUL);
                            _events.ScheduleEvent(EVENT_BURNING_SOUL, urand(10000, 25000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_ordosAI(creature);
        }
};

void AddSC_boss_ordos()
{
    new boss_ordos();
}