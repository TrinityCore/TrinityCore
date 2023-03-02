/*
 *  Copyright (C) 2017 - Elysium Project <http://elysium-project.org/>
 *
 *  Script rewritten by Zerix.
 *
 *  Notes: This is a proof of concept that writing scripts for SD2 can look, and feel better.
 *      Event based timers not only look cleaner, but they are easier to read and write for new/inexperienced
 *      developers.
 *  
 */

#include "scriptPCH.h"
#include "Utilities/EventMap.h"
#include "molten_core.h"

enum eSpells
{
    SpellImpendingDoom = 19702,             // Inflicts 2000 Shadow damage to nearby enemies after 10 sec. Radius: 40 yards.
    SpellCurse         = 19703,             // Curses nearby enemies, increasing the costs of their spells and abilities by 100% for 5 min. Radius: 40 yards.
    SpellShadowShock   = 19460              // Instantly lashes nearby enemies with dark magic, inflicting Shadow damage. Radius: 20 yards.
};

enum eEvents
{
    EventImpendingDoom = 1,
    EventCurse = 2,
    EventShadowShock = 3
};

struct boss_lucifronAI : public ScriptedAI
{
    explicit boss_lucifronAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_Instance = static_cast<ScriptedInstance*>(pCreature->GetInstanceData());
        boss_lucifronAI::Reset();
    }

    void Reset() override
    {
        m_Events.Reset(); // wipe existing events or old timers are executed again on subsequent attempts
        m_Events.ScheduleEvent(eEvents::EventImpendingDoom, Seconds(10));       // Zerix: 10s Initial Cast, Repeats every 20s.
        m_Events.ScheduleEvent(eEvents::EventCurse, Seconds(20));               // Zerix: 20s Initial Cast, Repeats every 15s.
        m_Events.ScheduleEvent(eEvents::EventShadowShock, Seconds(6));          // Zerix: 6s Initial Cast, Repeats every 6s.

        if (m_Instance && m_creature->IsAlive())
            m_Instance->SetData(TYPE_LUCIFRON, NOT_STARTED);
    }

    void Aggro(Unit* /*p_Who*/) override
    {
        if (m_Instance)
            m_Instance->SetData(TYPE_LUCIFRON, IN_PROGRESS);

        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        if (m_Instance)
            m_Instance->SetData(TYPE_LUCIFRON, DONE);
    }

    void UpdateAI(uint32 const p_Diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        m_Events.Update(p_Diff);
        while (auto l_EventId = m_Events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case eEvents::EventImpendingDoom:
                {
                    if (DoCastSpellIfCan(m_creature, eSpells::SpellImpendingDoom) == CAST_OK)
                        m_Events.Repeat(Seconds(20));
                    else
                        m_Events.Repeat(Milliseconds(100));
                    break;
                }
                case eEvents::EventCurse:
                {
                    if (DoCastSpellIfCan(m_creature, eSpells::SpellCurse) == CAST_OK)
                        m_Events.Repeat(Seconds(15));
                    else
                        m_Events.Repeat(Milliseconds(100));
                    break;
                }
                case eEvents::EventShadowShock:
                {
                    if (auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                        if (DoCastSpellIfCan(l_Target, eSpells::SpellShadowShock) == CAST_OK)
                            m_Events.Repeat(Seconds(6));
                    break;
                }
                default: break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap m_Events;
    ScriptedInstance* m_Instance;
};

CreatureAI* GetAI_boss_lucifron(Creature* pCreature)
{
    return new boss_lucifronAI(pCreature);
}

void AddSC_boss_lucifron()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_lucifron";
    newscript->GetAI = &GetAI_boss_lucifron;
    newscript->RegisterSelf();
}
