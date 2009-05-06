/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Noth
SD%Complete: 40
SDComment: Missing Balcony stage
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"
#include "def_naxxramas.h"

#define SAY_AGGRO               RAND(-1533075,-1533076,-1533077)
#define SAY_SUMMON              -1533078
#define SAY_SLAY                RAND(-1533079,-1533080)
#define SAY_DEATH               -1533081

#define SOUND_DEATH      8848

#define SPELL_CURSE_PLAGUEBRINGER       HEROIC(29213,54835)
#define SPELL_BLINK                     RAND(29208,29209,29210,29211)
#define SPELL_CRIPPLE                   HEROIC(29212,54814)

#define MOB_WARRIOR         16984
#define MOB_CHAMPION        16983
#define MOB_GUARDIAN        16981

// Teleport position of Noth on his balcony
#define TELE_X 2631.370
#define TELE_Y -3529.680
#define TELE_Z 274.040
#define TELE_O 6.277

// IMPORTANT: BALCONY TELEPORT NOT ADDED YET! WILL BE ADDED SOON!
// Dev note 26.12.2008: When is soon? :)

enum Events
{
    EVENT_BERSERK   = 1,
    EVENT_CURSE,
    EVENT_BLINK,
    EVENT_WARRIOR,
};

struct TRINITY_DLL_DECL boss_nothAI : public ScriptedAI
{
    boss_nothAI(Creature *c) : ScriptedAI(c), summons(me)
    {
        instance = ((ScriptedInstance*)c->GetInstanceData());
    }

    EventMap events;
    SummonList summons;
    ScriptedInstance *instance;

    void Reset()
    {
        events.Reset();
        summons.DespawnAll();
        instance->SetBossState(BOSS_NOTH, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, me);
        DoZoneInCombat();

        events.ScheduleEvent(EVENT_CURSE, 20000+rand()%10000);
        events.ScheduleEvent(EVENT_WARRIOR, 30000);
        if(HeroicMode)
            events.ScheduleEvent(EVENT_BLINK, 20000+rand()%10000);

        instance->SetBossState(BOSS_NOTH, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        DoScriptText(SAY_SLAY, me);
    }

    void JustSummoned(Creature *summon)
    {
        summons.Summon(summon);
        DoZoneInCombat(summon);
    }

    void SummonedCreatureDespawn(Creature *summon) { summons.Despawn(summon); }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, me);
        instance->SetBossState(BOSS_NOTH, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_CURSE:
                    DoCastAOE(SPELL_CURSE_PLAGUEBRINGER);
                    events.ScheduleEvent(EVENT_CURSE, 20000+rand()%10000);
                    return;
                case EVENT_WARRIOR:
                    DoScriptText(SAY_SUMMON, me);
                    for(uint8 i = 0; i < 6; i++)
                        m_creature->SummonCreature(MOB_WARRIOR,2684.804,-3502.517,261.313,0,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,80000);
                    events.ScheduleEvent(EVENT_WARRIOR, 30000);
                    return;
                case EVENT_BLINK:
                    DoCastAOE(SPELL_CRIPPLE, true);
                    DoCastAOE(SPELL_BLINK);
                    DoResetThreat();
                    events.ScheduleEvent(EVENT_BLINK, 20000+rand()%10000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_noth(Creature *_Creature)
{
    return new boss_nothAI (_Creature);
}

void AddSC_boss_noth()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_noth";
    newscript->GetAI = &GetAI_boss_noth;
    newscript->RegisterSelf();
}
