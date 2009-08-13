#include "precompiled.h"
#include "def_vault_of_archavon.h"

#define EMOTE_OVERCHARGE_TEMPEST_MINION -1590000
#define EMOTE_MINION_RESPAWN            -1590001

//Spells Emalon
#define SPELL_CHAIN_LIGHTNING      HEROIC(64213,64215)                         
#define SPELL_LIGHTNING_NOVA       HEROIC(64216,65279)                        
#define SPELL_OVERCHARGE           64218                            
#define SPELL_BERSERK              47008     

//Spells Tempest Minions
#define SPELL_OVERCHARGED          64217
#define SPELL_OVERCHARGED_BLAST    64219
#define SPELL_SHOCK                64363

//4 Warders spawned
#define TEMPEST_MINIONS            33998

#define EVENT_CHAIN_LIGHTNING      1  //5s cd
#define EVENT_OVERCHARGE           2  //45s cd
#define EVENT_LIGHTNING_NOVA       3  //40s cd
#define EVENT_BERSERK              4  //360s cd 
#define EVENT_SHOCK                5  //20s cd

struct Location
{
    float x, y, z, o;
};

static Location MinionLocation[]=
{
    -231.713,-281.96,91.466,1.53213,
    -205.585,-281.549,91.4661,1.75204,
    -205.651,-296.394,91.4661,1.69549,
    -232.235,-296.433,91.4998,1.44417
};

struct TRINITY_DLL_DECL boss_emalonAI : public ScriptedAI
{
    boss_emalonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    EventMap events;
    std::list<uint64> MinionList;

    void Reset()
    {
        events.Reset();
        DespawnAllMinions();
        SummonAllMinions();

        if(pInstance)
           pInstance->SetData(DATA_EMALON_EVENT, NOT_STARTED);
    }

    void DespawnAllMinions()
    {
        if(!MinionList.empty())
        {
            for(std::list<uint64>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); itr++)
            {
                if(Creature *Minion = Unit::GetCreature(*m_creature, (*itr)))
                   Minion->DisappearAndDie();
            }
        }
        
        MinionList.clear();
    }

    void JustSummoned(Creature *Summoned)
    {
        MinionList.push_back(Summoned->GetGUID());
        if(Unit* target = m_creature->getVictim())
           Summoned->AI()->AttackStart(target);
    }

    void SummonAllMinions()
    {
        if(MinionList.empty())
           for(uint8 i = 0; i < 4; ++i)
               SummonMinion(m_creature, MinionLocation[i].x, MinionLocation[i].y, MinionLocation[i].z, MinionLocation[i].o);
    }

    static void SummonMinion(Creature *Summoner, float x, float y, float z, float o)
    {
        Summoner->SummonCreature(TEMPEST_MINIONS, x, y, z, o, TEMPSUMMON_DEAD_DESPAWN, 0);
    }

    void KilledUnit(Unit* Victim){}

    void JustDied(Unit* Killer)
    {
        DespawnAllMinions();
        if (pInstance)
            pInstance->SetData(DATA_EMALON_EVENT, DONE);
    }

    void EnterCombat(Unit *who)
    {
        if(!MinionList.empty())
        {
            for(std::list<uint64>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
            {
                Creature* Minion = (Unit::GetCreature(*m_creature, *itr));            
                Minion->AI()->AttackStart(who);
            }
        }

        DoZoneInCombat();
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 5000);
        events.ScheduleEvent(EVENT_OVERCHARGE, 45000);
        events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 30000);
        events.ScheduleEvent(EVENT_BERSERK, 360000);
        events.ScheduleEvent(EVENT_SHOCK, 20000);

        if(pInstance)
           pInstance->SetData(DATA_EMALON_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        events.Update(diff);

        if(me->hasUnitState(UNIT_STAT_CASTING))
           return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_CHAIN_LIGHTNING:
                    if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                       DoCast(target, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 20000);
                    return;
                case EVENT_OVERCHARGE:
                    for(std::list<uint64>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    {
                        Creature* Minion = (Unit::GetCreature(*m_creature, *itr));            
                        if(Minion && Minion->isAlive() && !Minion->HasAura(SPELL_OVERCHARGED))
                        {
                            Minion->CastSpell(me, SPELL_OVERCHARGED, true);
                            Minion->SetHealth(Minion->GetMaxHealth());
                            DoScriptText(EMOTE_OVERCHARGE_TEMPEST_MINION, m_creature);
                            events.ScheduleEvent(EVENT_OVERCHARGE, 45000);
                            return;
                        }    
                    }
                case EVENT_LIGHTNING_NOVA:
                    DoCast(me->getVictim(), SPELL_LIGHTNING_NOVA);
                    events.ScheduleEvent(EVENT_LIGHTNING_NOVA, 25000);
                    return;
                case EVENT_SHOCK:
                    for(std::list<uint64>::const_iterator itr = MinionList.begin(); itr != MinionList.end(); ++itr)
                    {
                        Creature* Minion = (Unit::GetCreature(*m_creature, *itr));            
                        if(Minion && Minion->isAlive())
                        {
                            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            {
                                Minion->CastSpell(target, SPELL_SHOCK, true);
                                events.ScheduleEvent(EVENT_SHOCK, 20000);
                                return;
                            }
                        }
                    }
                case EVENT_BERSERK:
                    DoCast(m_creature, SPELL_BERSERK);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
##  Mob Tempest Minions
######*/
struct TRINITY_DLL_DECL mob_tempest_minionAI : public ScriptedAI
{
    mob_tempest_minionAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        EmalonGUID = pInstance ? pInstance->GetData64(DATA_EMALON) : 0;
        Emalon = Unit::GetCreature(*m_creature, EmalonGUID);
    }

    ScriptedInstance* pInstance;
    EventMap events;
    uint64 EmalonGUID;
    std::list<Creature*> MinionList;
    Creature* Emalon;
    uint32 SPELL_OVERCHARGED_Timer;
    bool AlreadyOvercharged;

    void Reset()
    {
        events.Reset();
        AlreadyOvercharged = false;
        SPELL_OVERCHARGED_Timer = 0;
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
        if(Emalon)
           Emalon->AI()->AttackStart(who);
    }

    void JustDied(Unit* Killer)
    {
        m_creature->DisappearAndDie();
        if(Emalon)
        {
            boss_emalonAI::SummonMinion(Emalon, Emalon->GetPositionX(), Emalon->GetPositionY(), Emalon->GetPositionZ(), Emalon->GetOrientation());
            DoScriptText(EMOTE_MINION_RESPAWN, m_creature);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
           return;

        if(Aura *OverchargedAura = m_creature->GetAura(SPELL_OVERCHARGED))
        {
            if(OverchargedAura->GetStackAmount() < 10)
            {
                if (SPELL_OVERCHARGED_Timer < diff)
                {
                    DoCast(me, SPELL_OVERCHARGED);
                    SPELL_OVERCHARGED_Timer = 2000;
                }else SPELL_OVERCHARGED_Timer -=diff;
            }
            else
            {
                if(OverchargedAura->GetStackAmount() == 10 && (AlreadyOvercharged == false))
                {
                    DoCast(me,SPELL_OVERCHARGED_BLAST);
                    AlreadyOvercharged = true;
                }
            }
        }
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_tempest_minion(Creature *_Creature)
{
    return new mob_tempest_minionAI (_Creature);
}

CreatureAI* GetAI_boss_emalon(Creature *_Creature)
{
    return new boss_emalonAI (_Creature);
}

void AddSC_boss_emalon()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_emalon";
    newscript->GetAI = &GetAI_boss_emalon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_tempest_minion";
    newscript->GetAI = &GetAI_mob_tempest_minion;
    newscript->RegisterSelf();
}
