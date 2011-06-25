#include "ScriptPCH.h"
#include "shattered_halls.h"

#define SPELL_EXECUTION_TIMER_BUFF_1            39288
#define SPELL_EXECUTION_TIMER_BUFF_2            39289
#define SPELL_EXECUTION_TIMER_BUFF_3            39290
// Horde Victims
#define ENTRY_SCOUT_ORGARR                      17297
#define ENTRY_KORAG                             17295
#define ENTRY_CAPT_BONESHATTER                  17296
// Allianz Victims
#define ENTRY_RIFLEMAN_BROWNBEARD               17289
#define ENTRY_PROVATE_JACINT                    17292
#define ENTRY_CAPT_ALINA                        17290

float ExecutionerPos[3] = {164.53f,-82.73f,1.93f};
float VictimPos[3][3] =
{
    {149.77f,-77.59f,1.93f},
    {143.97f,-84.15f,1.93f},
    {149.77f,-90.33f,1.93f}
};

class mob_shattered_hand_executioner : public CreatureScript
{
public:
    mob_shattered_hand_executioner() : CreatureScript("mob_shattered_hand_executioner") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new mob_shattered_hand_executionerAI (_Creature);
    }

    struct  mob_shattered_hand_executionerAI : public ScriptedAI
    {   
        mob_shattered_hand_executionerAI(Creature *c) : ScriptedAI(c)
        {
            for(int i = 0; i < 3; i++)
                victim[i] = 0;

            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        bool eventstarted;
        uint32 phase;

        uint32 check_timer;

        uint64 victim[3];

        uint32 GetFactionOfPlayersInInstance()
        {
            uint32 faction = 1;

            Map *map = me->GetMap();
            if(map->IsDungeon())
            {
                InstanceMap::PlayerList const &PlayerList = ((InstanceMap*)map)->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* i_pl = i->getSource())
                    {
                        faction = i_pl->getFaction();
                        return faction;
                    }
                }
            }
            return 0;
        }

        void SpawnVictims(uint32 phase)
        {
            uint32 faction = GetFactionOfPlayersInInstance();
            bool isHorde = (faction == 1610 ||faction == 2 ||faction == 6 ||faction == 116 ||faction == 5) ;

            //error_log("Spawn ... für Phase %d ", phase);
            Creature* temp;
            if(phase < 3)
                eventstarted = true;

            if(phase > 2 && victim[0] == 0)
            {
                temp = me->SummonCreature(isHorde ? ENTRY_SCOUT_ORGARR : ENTRY_RIFLEMAN_BROWNBEARD,VictimPos[0][0],VictimPos[0][1],VictimPos[0][2],0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10000);
                temp->setActive(true);
                victim[0] = temp->GetGUID();
            }

            if(phase > 1 && victim[1] == 0)
            {
                temp = me->SummonCreature(isHorde ? ENTRY_KORAG : ENTRY_PROVATE_JACINT,VictimPos[1][0],VictimPos[1][1],VictimPos[1][2],0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10000);
                temp->setActive(true);
                victim[1] = temp->GetGUID();
            }

            if(phase > 0 && victim[2] == 0)
            {
                temp = me->SummonCreature(isHorde ? ENTRY_CAPT_BONESHATTER : ENTRY_CAPT_ALINA,VictimPos[2][0],VictimPos[2][1],VictimPos[2][2],0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10000);
                temp->setActive(true);
                victim[2] = temp->GetGUID();
            }

            //error_log("Victim 1 gespawnt GUID %d ",victim[0]);
            //error_log("Victim 2 gespawnt GUID %d ",victim[1]);
            //error_log("Victim 3 gespawnt GUID %d ",victim[2]);
        }

        void executeVictim()
        {
            if(me->getVictim())
                return;

            uint64 tVictim;
            switch (phase)
            {
            case 3: tVictim = victim[0]; break;
            case 2: tVictim = victim[1]; break;
            case 1: tVictim = victim[2]; break;
            }
            //error_log("Victim Checked %d %d",phase, tVictim);
            Unit* temp = Unit::GetUnit((*me),tVictim);
            if(temp)
            {
                //error_log("Victim Attack Entry: %d GUID: %d",temp->GetEntry(),temp->GetGUID());
                //me->getThreatManager().addThreat(temp,0.0f);
                me->AI()->AttackStart(temp);
            }
            //executing = true; 
                        //me->AI()->AttackStart(temp);
        }

        void Reset()
        {
            me->setActive(true);
            phase = 0;

            if(pInstance)
            {
                phase = pInstance->GetData(EXECUTION_PHASE);

                //error_log("Phase %d Loaded ", phase);
                SpawnVictims(phase);
                uint32 status = pInstance->GetData(TIMER_STATE);

                eventstarted = true;
                if(phase == 3 && status == TIMER_NOTSTARTED)
                    eventstarted = false;
                //if(status == TIMER_NEXTPHASE)
                    //executeVictim();
            }
            check_timer = 5000;
        }

        void KilledUnit(Unit* killed_victim)
        {
            if( killed_victim->GetTypeId() == TYPEID_UNIT)
            {
                switch(phase)
                {
                case 3:
                    if((killed_victim->GetEntry() == ENTRY_SCOUT_ORGARR || killed_victim->GetEntry() == ENTRY_RIFLEMAN_BROWNBEARD) && victim[0] == killed_victim->GetGUID())
                    {
                        phase = 2;
                        SetInstanceWideBuff(phase);
                        pInstance->SetData(EXECUTION_PHASE,phase);
                    }
                    break;
                case 2:
                    if((killed_victim->GetEntry() == ENTRY_KORAG || killed_victim->GetEntry() == ENTRY_PROVATE_JACINT) && victim[1] == killed_victim->GetGUID())
                    {
                        phase = 1;
                        SetInstanceWideBuff(phase);
                        pInstance->SetData(EXECUTION_PHASE,phase);
                    }
                    break;
                case 1:
                    if((killed_victim->GetEntry() == ENTRY_CAPT_BONESHATTER || killed_victim->GetEntry() == ENTRY_CAPT_ALINA ) && victim[2] == killed_victim->GetGUID())
                    {
                        phase = 0;
                        pInstance->SetData(EXECUTION_PHASE,phase);
                        //me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        //me->RemoveCorpse();
                    }
                    break;
                }
            }
        }

        void JustDied(Unit* Killer)
        {
            if(!eventstarted || phase < 1 )
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void EnterCombat(Unit *who){}

        void SetInstanceWideBuff(uint32 buffphase)
        {
            Map *map = me->GetMap();
            if(map->IsDungeon())
            {
                InstanceMap::PlayerList const &PlayerList = ((InstanceMap*)map)->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* i_pl = i->getSource())
                        if(i_pl->isAlive())
                        {
                            switch (buffphase)
                            {
                                case 3: i_pl->CastSpell(i_pl,SPELL_EXECUTION_TIMER_BUFF_1,true); break;
                                case 2: i_pl->CastSpell(i_pl,SPELL_EXECUTION_TIMER_BUFF_2,true); break;
                                case 1: i_pl->CastSpell(i_pl,SPELL_EXECUTION_TIMER_BUFF_3,true); break;
                            }
                        }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!eventstarted)
            {
                if(pInstance)
                {
                    uint32 status = pInstance->GetData(TIMER_STATE);
                    if(status != TIMER_NOTSTARTED)
                    {
                        SetInstanceWideBuff(3);
                        eventstarted = true;
                    }
                }
            }

            if(check_timer <= diff)
            {
                if(pInstance)
                {
                    uint32 status = pInstance->GetData(TIMER_STATE);
                    //error_log("Checked %d %d",status, phase);
                    if(status == TIMER_NEXTPHASE)
                        executeVictim();
                }
                check_timer = 5000;
            }else check_timer -= diff;

            if (!UpdateVictim() )
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_shattred_halls()
{
    new mob_shattered_hand_executioner();
}