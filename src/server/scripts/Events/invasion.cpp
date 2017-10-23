#include <ScriptPCH.h>
#include <ScriptMgr.h>

#include <Player.h>
#include <Creature.h>
#include <Pet.h>
#include <Unit.h>
#include <GameEventMgr.h>

#define INVASION_EVENT_ID           201

#define MAX_GOULE_PER_PYLONE        25
#define MAX_HORREUR_PER_PYLONE      2

enum pyloneSpells
{
    SPELL_LITTLE_SHIELD_FIRE    = 43870,
    SPELL_SHIELD                = 43874,

    SPELL_SUMMON_GOULE          = 67873,
    SPELL_SUMMON_HORREUR        = 70372,

    SPELL_INVOCATION_CIRCLE     = 62019,
};

enum pyloneEvents
{
    EVENT_SPAWN_GOULE           = 1,
    EVENT_SPAWN_HORREUR         = 2,

    EVENT_RESPAWN               = 3,
};

enum pylonenNpc
{
    NPC_GOULE                   = 35590,
    NPC_HORREUR                 = 37698,
};

class npc_invasion_pylone : public CreatureScript
{
    public:
        npc_invasion_pylone() : CreatureScript("npc_invasion_pylone") {}        

        struct npc_invasion_pyloneAI : public ScriptedAI
        {
            npc_invasion_pyloneAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap _events;
            uint8 gouleCountToDie;
            uint8 horreurCountToDie;

            uint8 actualGouleCount;
            uint8 actualHorreurCount;

            uint8 totalMobCount;

            void Reset()
            {
                me->SetVisible(true);

                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, SPELL_INVOCATION_CIRCLE, true);
                me->AddAura(SPELL_LITTLE_SHIELD_FIRE, me);
                me->AddAura(SPELL_SHIELD, me);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                
                gouleCountToDie   = 50;
                horreurCountToDie = 5;

                actualGouleCount = 0;
                actualHorreurCount = 0;

                totalMobCount = 0;

                _events.Reset();

                _events.ScheduleEvent(EVENT_SPAWN_GOULE, 1000);
                _events.ScheduleEvent(EVENT_SPAWN_HORREUR, 25000);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (me->HasAura(SPELL_SHIELD))
                    damage = 0;
                else
                {
                    if (damage >= me->GetHealth())
                    {
                        damage = 0;
                        me->SetVisible(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        _events.CancelEvent(EVENT_SPAWN_GOULE);
                        _events.CancelEvent(EVENT_SPAWN_HORREUR);
                        _events.ScheduleEvent(EVENT_RESPAWN, 300000);
                        me->SetHealth(me->GetMaxHealth());
                    }
                }
            }
            
            void JustSummoned(Creature* summon)
            {
                switch(summon->GetEntry())
                {
                    case NPC_GOULE:
                        ++actualGouleCount;
                        ++totalMobCount;
                        break;
                    case NPC_HORREUR:
                        ++actualHorreurCount;
                        ++totalMobCount;
                        break;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                switch (summon->GetEntry())
                {
                    case NPC_GOULE:
                        if (gouleCountToDie)  --gouleCountToDie;
                        if (actualGouleCount) --actualGouleCount;
                        break;
                    case NPC_HORREUR:
                        if (horreurCountToDie)  --horreurCountToDie;
                        if (actualHorreurCount) --actualHorreurCount;
                        break;
                }

                if (!gouleCountToDie && !horreurCountToDie)
                {
                    me->RemoveAurasDueToSpell(SPELL_LITTLE_SHIELD_FIRE);
                    me->RemoveAurasDueToSpell(SPELL_SHIELD);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                _events.Update(diff);

                switch(uint32 eventId = _events.ExecuteEvent())
                {
                    case EVENT_SPAWN_GOULE:
                        if (actualGouleCount < MAX_GOULE_PER_PYLONE)
                            me->CastSpell(me, SPELL_SUMMON_GOULE, true);

                        _events.ScheduleEvent(eventId, 1000);
                        break;
                    case EVENT_SPAWN_HORREUR:
                        if (actualHorreurCount < MAX_HORREUR_PER_PYLONE)
                            me->CastSpell(me, SPELL_SUMMON_HORREUR, true);

                        _events.ScheduleEvent(eventId, 25000);
                        break;
                    case EVENT_RESPAWN:
                        Reset();
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_invasion_pyloneAI(creature);
        }
};

enum bossSpells
{
    SPELL_SUMMON_INFERNO        = 66252,
    SPELL_FLAMES_WAVE           = 75413,
};

enum bossEvents
{
    EVENT_INFERNO               = 1,
    EVENT_FLAMES_WAVE           = 2,
};

class npc_invasion_boss : public CreatureScript
{
    public:
        npc_invasion_boss() : CreatureScript("npc_invasion_boss") {}        

        struct npc_invasion_bossAI : public ScriptedAI
        {
            npc_invasion_bossAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

            EventMap _events;
            SummonList summons;

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_INFERNO, 15000);
                _events.ScheduleEvent(EVENT_FLAMES_WAVE, 30000);

                summons.DespawnAll();
            }
            
            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                switch(uint32 eventId = _events.ExecuteEvent())
                {
                    case EVENT_INFERNO:
                        me->CastSpell(me, SPELL_SUMMON_INFERNO, true);
                        _events.ScheduleEvent(eventId, 60000);
                        break;
                    case EVENT_FLAMES_WAVE:
                        me->CastSpell(me, SPELL_FLAMES_WAVE, false);
                        _events.ScheduleEvent(eventId, 60000);
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_invasion_bossAI(creature);
        }
};
  
void AddSC_event_invasion()
{
    new npc_invasion_pylone();
    new npc_invasion_boss();
};