#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"

enum Adds
{
    // Before Malkorok
    NPC_ORGRIMMAR_PEON                  = 72893,
    NPC_KORKRON_WAR_WOLF                = 72768,
    NPC_KORKRON_GUNNER_1                = 73659, // no loot ?
    NPC_KORKRON_GUNNER_2                = 72784,
    NPC_KORKRON_DARK_FARSEER            = 72770,
    NPC_KORKRON_BLOOD_AXE_1             = 73660, // no loot ?
    NPC_KORKRON_BLOOD_AXE_2             = 72728,
    NPC_DARKSPEAR_VANGUARD_1            = 73728,
    NPC_DARKSPEAR_VANGUARD_2            = 73727,
    NPC_DARKSPEAR_VANGUARD_3            = 73726,

    // After Malkorok
    NPC_STOREROOM_GUARD                 = 73152,
    NPC_KORKRON_SHREDER                 = 73767,
    NPC_KORKRON_IRON_SENTINEL           = 73745,

    // Before Thok the Bloodthirsty
    NPC_MONSTROUS_GASTRAPOD             = 73164,
    NPC_TESLA_COIL                      = 73198,
    NPC_ENRAGED_MUSHAN_BEAST            = 73185,
    NPC_PTERRORDAX                      = 73223,
    NPC_KORKRON_JAILER                  = 73195,
    NPC_CAPTIVE_CAVE_BAT                = 73188,
    NPC_STARVED_YETTI                   = 73184,
};

class npc_siege_of_orgrimmar_enraged_mushan_beast : public CreatureScript
{
    enum Spells
    {
        SPELL_RIOT              = 147989,
        SPELL_CRUSHING_SWIPE    = 148133,
        SPELL_LACERATING_BITE   = 148136,
    };

    public:
        npc_siege_of_orgrimmar_enraged_mushan_beast() : CreatureScript("npc_siege_of_orgrimmar_enraged_mushan_beast") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_enraged_mushan_beastAI(creature);
        }

        struct npc_siege_of_orgrimmar_enraged_mushan_beastAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_enraged_mushan_beastAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {

            }

            void JustDied(Unit* killer)
            {
                events.Reset();

                SendEnragedMushanBeastDone();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        private:

            void SendEnragedMushanBeastDone()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_ENRAGED_MUSHAN_BEAST, DONE);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_pterrordax : public CreatureScript
{
    enum Spells
    {
        SPELL_RIOT              = 147989,
        SPELL_SCREECHING_HOWL   = 148029,
    };

    public:
        npc_siege_of_orgrimmar_pterrordax() : CreatureScript("npc_siege_of_orgrimmar_pterrordax") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_pterrordaxAI(creature);
        }

        struct npc_siege_of_orgrimmar_pterrordaxAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_pterrordaxAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {

            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_starved_yetti : public CreatureScript
{
    enum Spells
    {
        SPELL_RIOT                  = 147989,
        SPELL_WRECKING_BALL_AOE     = 147606,
        SPELL_WRECKING_BALL_DUMMY   = 147952,
        SPELL_WRECKING_BALL_AURA    = 147609,

        SPELL_PING_BOSS             = 144037, // from sniffs
        SPELL_HEAL                  = 149231, // from sniffs
        SPELL_HEAL_DUMMY            = 149230,
        SPELL_HEAL_HEAL             = 149232,
    };

    public:
        npc_siege_of_orgrimmar_starved_yetti() : CreatureScript("npc_siege_of_orgrimmar_starved_yetti") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_starved_yettiAI(creature);
        }

        struct npc_siege_of_orgrimmar_starved_yettiAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_starved_yettiAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {

            }

            void JustDied(Unit* killer)
            {
                events.Reset();

                SendStarvedYettiDone();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        private:

            void SendStarvedYettiDone()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_STARVED_YETTI, DONE);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korkron_jailer : public CreatureScript
{
    enum LocalSpells
    {
        SPELL_ENRAGE                = 145974,
    };

    enum LocalEvents
    {
        EVENT_ENRAGE    = 1,
    };

    enum LocalTimers
    {
        TIMER_ENRAGE_FIRST  = 5 * IN_MILLISECONDS,
        TIMER_ENRAGE        = 20 * IN_MILLISECONDS,
    };

    public:
        npc_siege_of_orgrimmar_korkron_jailer() : CreatureScript("npc_siege_of_orgrimmar_korkron_jailer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_jailerAI(creature);
        }

        struct npc_siege_of_orgrimmar_korkron_jailerAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_jailerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE_FIRST);
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

        private:

            void ExecuteEvent(const uint32 eventId)
            {
                switch (eventId)
                {
                    case EVENT_ENRAGE:
                        DoEnrage();
                        events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE);
                        break;
                }
            }

            void DoEnrage()
            {
                DoCast(me, SPELL_ENRAGE);
            }

        private:

            InstanceScript* pInstance;
        };
};


void AddSC_siege_of_orgrimmar_part_c()
{
    new npc_siege_of_orgrimmar_enraged_mushan_beast();  // 73185
    new npc_siege_of_orgrimmar_pterrordax();            // 73223
    new npc_siege_of_orgrimmar_starved_yetti();         // 73184
    new npc_siege_of_orgrimmar_korkron_jailer();        // 73195
}
