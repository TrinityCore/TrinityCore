/* Copyright ?2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: boss_Akilzon
SD%Complete: 75%
SDComment: Missing timer for Call Lightning and Sound ID's
SQLUpdate: 
#Temporary fix for Soaring Eagles

EndScriptData */

#include "precompiled.h"
#include "def_zulaman.h"
#include "Spell.h"
#include "Weather.h"

#define SPELL_STATIC_DISRUPTION 43622
#define SPELL_STATIC_VISUAL     45265
#define SPELL_CALL_LIGHTNING     43661 //Missing timer
#define SPELL_GUST_OF_WIND      43621
#define SPELL_ELECTRICAL_STORM  43648
#define SPELL_BERSERK           45078

#define SPELL_EAGLE_SWOOP       44732

//"Your death gonna be quick, strangers. You shoulda never have come to this place..."
#define SAY_ONAGGRO "I be da predator! You da prey..."
#define SAY_ONDEATH "You can't... kill... me spirit!"
#define SAY_ONSLAY1 "Ya got nothin'!"
#define SAY_ONSLAY2 "Stop your cryin'!"
#define SAY_ONSUMMON "Feed, me bruddahs!"
#define SAY_ONENRAGE "All you be doing is wasting my time!"
#define SOUND_ONAGGRO 12013
#define SOUND_ONDEATH 12019
#define SOUND_ONSLAY1 12017
#define SOUND_ONSLAY2 12018
#define SOUND_ONSUMMON 12014
#define SOUND_ONENRAGE 12016

#define MOB_SOARING_EAGLE 24858
#define SE_LOC_X_MAX 400
#define SE_LOC_X_MIN 335
#define SE_LOC_Y_MAX 1435
#define SE_LOC_Y_MIN 1370

#define MOB_TEMP_TRIGGER    23920

struct TRINITY_DLL_DECL boss_akilzonAI : public ScriptedAI
{
    boss_akilzonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }
    ScriptedInstance *pInstance;

    uint64 TargetGUID;
    uint64 CycloneGUID;
    uint64 CloudGUID;

    uint32 StaticDisruption_Timer;
    uint32 GustOfWind_Timer;
    uint32 CallLighting_Timer;
    uint32 ElectricalStorm_Timer;
    uint32 SDisruptAOEVisual_Timer;
    uint32 SummonEagles_Timer;
    uint32 Enrage_Timer;

    uint32 StormCount;
    uint32 StormSequenceTimer;

    bool isRaining;

    void Reset()
    {
        if(pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, NOT_STARTED);

        StaticDisruption_Timer = (10+rand()%10)*1000; //10 to 20 seconds (bosskillers)
        GustOfWind_Timer = (20+rand()%10)*1000; //20 to 30 seconds(bosskillers)
        CallLighting_Timer = (10+rand()%10)*1000; //totaly random timer. can't find any info on this
        ElectricalStorm_Timer = 60*1000; //60 seconds(bosskillers)
        Enrage_Timer = 10*60*1000; //10 minutes till enrage(bosskillers)
        SDisruptAOEVisual_Timer = 99999;
        SummonEagles_Timer = 99999;

        TargetGUID = 0;
        CloudGUID = 0;
        CycloneGUID = 0;

        StormCount = 0;
        StormSequenceTimer = 0;

        isRaining = false;

        DespawnSummons(MOB_SOARING_EAGLE);
        SetWeather(WEATHER_STATE_FINE, 0.0f);        
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_ONAGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_ONAGGRO);
        DoZoneInCombat();
        if(pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, IN_PROGRESS);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_ONDEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_ONDEATH);
        if(pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, DONE);
        DespawnSummons(MOB_SOARING_EAGLE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
        case 0:
            DoYell(SAY_ONSLAY1, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONSLAY1);
            break;
        case 1:
            DoYell(SAY_ONSLAY2, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONSLAY2);
            break;
        }
    }

    void DespawnSummons(uint32 entry)
    {
        std::list<Creature*> templist;
        float x, y, z;
        m_creature->GetPosition(x, y, z);

        {
            CellPair pair(Trinity::ComputeCellPair(x, y));
            Cell cell(pair);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            Trinity::AllCreaturesOfEntryInRange check(m_creature, entry, 100);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(templist, check);

            TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);

            CellLock<GridReadGuard> cell_lock(cell, pair);
            cell_lock->Visit(cell_lock, cSearcher, *(m_creature->GetMap()));
        }

        for(std::list<Creature*>::iterator i = templist.begin(); i != templist.end(); ++i)
        {
            (*i)->SetVisibility(VISIBILITY_OFF);
            (*i)->setDeathState(JUST_DIED);
        }
    }

    Player* SelectRandomPlayer(float range = 0.0f, bool alive = true)
    {
        Map *map = m_creature->GetMap();
        if (!map->IsDungeon()) return NULL;

        InstanceMap::PlayerList PlayerList = ((InstanceMap*)map)->GetPlayers();
        InstanceMap::PlayerList::iterator i;
        while(PlayerList.size())
        {
            i = PlayerList.begin();
            advance(i, rand()%PlayerList.size());
            if((range == 0.0f || m_creature->IsWithinDistInMap(*i, range))
                && (!alive || (*i)->isTargetableForAttack()))
                return *i;
            else
                PlayerList.erase(i);
        }
        return NULL;
    }

    void SetWeather(uint32 weather, float grade)
    {
        Map *map = m_creature->GetMap();
        if (!map->IsDungeon()) return;

        WorldPacket data(SMSG_WEATHER, (4+4+4));
        data << uint32(weather) << (float)grade << uint8(0);

        ((InstanceMap*)map)->SendToPlayers(&data);
    }

    void HandleStormSequence(Unit *Cloud) // 1: begin, 2-9: tick, 10: end
    {
        if(StormCount < 10 && StormCount > 1)
        {
            // deal damage
            int32 bp0 = 800;
            for(uint8 i = 2; i < StormCount; ++i)
                bp0 *= 2;

            CellPair p(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
            Cell cell(p);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            std::list<Unit *> tempUnitMap;

            {
                Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(m_creature, m_creature, 999);
                Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(tempUnitMap, u_check);

                TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
                TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

                CellLock<GridReadGuard> cell_lock(cell, p);
                cell_lock->Visit(cell_lock, world_unit_searcher, *(m_creature->GetMap()));
                cell_lock->Visit(cell_lock, grid_unit_searcher, *(m_creature->GetMap()));
            }

            for(std::list<Unit*>::iterator i = tempUnitMap.begin(); i != tempUnitMap.end(); ++i)
            {
                if(!Cloud->IsWithinDistInMap(*i, 15))
                {
                    float x, y, z;
                    (*i)->GetPosition(x, y, z);
                    x = rand()%2 ? x + rand()%5 : x - rand()%5;
                    y = rand()%2 ? y + rand()%5 : y - rand()%5;
                    z = Cloud->GetPositionZ() + 2 - rand()%4; 
                    if(Unit *trigger = m_creature->SummonCreature(MOB_TEMP_TRIGGER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 2000))
                    {
                        trigger->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                        trigger->StopMoving();
                        trigger->CastSpell(trigger, 37248, true);
                        trigger->CastCustomSpell(*i, 43137, &bp0, NULL, NULL, true, 0, 0, m_creature->GetGUID());
                    }
                }
            }

            // visual
            float x, y, z;
            for(uint8 i = 0; i < StormCount; ++i)
            {
                Cloud->GetPosition(x, y, z);
                x = rand()%2 ? x + rand()%10 : x - rand()%10;
                y = rand()%2 ? y + rand()%10 : y - rand()%10;
                z = z + 2 - rand()%4; 
                if(Unit *trigger = m_creature->SummonCreature(MOB_TEMP_TRIGGER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 2000))
                {
                    trigger->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                    trigger->StopMoving();
                    trigger->CastSpell(trigger, 37248, true);
                }
                Cloud->GetPosition(x, y, z);
                x = rand()%2 ? x + 10 + rand()%10 : x - 10 - rand()%10;
                y = rand()%2 ? y + 10 + rand()%10 : y - 10 - rand()%10;
                if(Unit *trigger = m_creature->SummonCreature(MOB_TEMP_TRIGGER, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 2000))
                {
                    trigger->SetMaxHealth(9999999);
                    trigger->SetHealth(9999999);
                    trigger->CastSpell(trigger, 43661, true);
                }
            }
        }

        StormCount++;
        if(StormCount > 10)
        {
            StormCount = 0; // finish
            SummonEagles_Timer = 5000;
            m_creature->InterruptNonMeleeSpells(false);
            Cloud->RemoveAurasDueToSpell(45213);
            CloudGUID = 0;
            if(Unit* Cyclone = Unit::GetUnit(*m_creature, CycloneGUID))
                Cyclone->RemoveAurasDueToSpell(25160);
            SetWeather(WEATHER_STATE_FINE, 0.0f);
            isRaining = false;
        }

        StormSequenceTimer = 1000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() && !m_creature->getVictim())
            return;

        if(StormCount)
        {
            Unit* target = Unit::GetUnit(*m_creature, CloudGUID);
            if(!target || !target->isAlive())
            {
                EnterEvadeMode();
                return;
            }
            else if(Unit* Cyclone = Unit::GetUnit(*m_creature, CycloneGUID))
                Cyclone->CastSpell(target, 25160, true); // keep casting or...

            if(StormSequenceTimer < diff) {
                HandleStormSequence(target);
            }else StormSequenceTimer -= diff;
            return;
        }

        if (Enrage_Timer < diff) {
            DoYell(SAY_ONENRAGE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONENRAGE);
            m_creature->CastSpell(m_creature, SPELL_BERSERK, true);
            Enrage_Timer = 600000;
        }else Enrage_Timer -= diff;

        if (StaticDisruption_Timer < diff) {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if(!target) target = m_creature->getVictim();
            TargetGUID = target->GetGUID();
            m_creature->CastSpell(target, SPELL_STATIC_DISRUPTION, false);
            m_creature->SetInFront(m_creature->getVictim());
            StaticDisruption_Timer = (10+rand()%8)*1000; // < 20s

            float dist = m_creature->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
            if (dist < 5.0f) dist = 5.0f;
            SDisruptAOEVisual_Timer = 1000 + floor(dist / 30 * 1000.0f);
        }else StaticDisruption_Timer -= diff;

        if (SDisruptAOEVisual_Timer < diff) {
            Unit* SDVictim = Unit::GetUnit((*m_creature), TargetGUID);
            if(SDVictim && SDVictim->isAlive())
                SDVictim->CastSpell(SDVictim, SPELL_STATIC_VISUAL, true);
            SDisruptAOEVisual_Timer = 99999;
            TargetGUID = 0;
        }else SDisruptAOEVisual_Timer -= diff;

        if (GustOfWind_Timer < diff) {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if(!target) target = m_creature->getVictim();
            DoCast(target, SPELL_GUST_OF_WIND);
            GustOfWind_Timer = (20+rand()%10)*1000; //20 to 30 seconds(bosskillers)
        } else GustOfWind_Timer -= diff;

        if (CallLighting_Timer < diff) {
            DoCast(m_creature->getVictim(), SPELL_CALL_LIGHTNING);
            CallLighting_Timer = (12 + rand()%5)*1000; //totaly random timer. can't find any info on this
        } else CallLighting_Timer -= diff;

        if (!isRaining && ElectricalStorm_Timer < 8000 + rand()%5000) {
            SetWeather(WEATHER_STATE_HEAVY_RAIN, 0.9999f);
            isRaining = true;
        }

        if (ElectricalStorm_Timer < diff) {
            Unit* target = SelectRandomPlayer(50);
            if(!target) target = m_creature->getVictim();
            float x, y, z;
            target->GetPosition(x, y, z);
            Unit *Cloud = m_creature->SummonCreature(MOB_TEMP_TRIGGER, x, y, m_creature->GetPositionZ() + 10, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
            if(Cloud)
            {
                CloudGUID = Cloud->GetGUID();
                Cloud->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                Cloud->StopMoving();
                Cloud->SetFloatValue(OBJECT_FIELD_SCALE_X, 3.0f);
                Cloud->setFaction(35);
                Cloud->SetMaxHealth(9999999);
                Cloud->SetHealth(9999999);
                Cloud->CastSpell(Cloud, 45213, true); // cloud visual
                m_creature->StopMoving();
                Cloud->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_creature->CastSpell(Cloud, 43501, false); // siphon soul
            }
            Unit *Cyclone = m_creature->SummonCreature(MOB_TEMP_TRIGGER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
            if(Cyclone)
            {
                Cyclone->CastSpell(Cyclone, 25160, true); // wind visual
                CycloneGUID = Cyclone->GetGUID();
            }
            ElectricalStorm_Timer = 60000; //60 seconds(bosskillers)
            StormCount = 1;
            StormSequenceTimer = 0;
        } else ElectricalStorm_Timer -= diff;

        if (SummonEagles_Timer < diff) 
        {
            DoYell(SAY_ONSUMMON, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONSUMMON);

            float x, y, z;
            m_creature->GetPosition(x, y, z);
            for (uint8 i = 0; i < 6 + rand()%3; i++) 
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    x = target->GetPositionX() + 10 - rand()%20;
                    y = target->GetPositionY() + 10 - rand()%20;
                    z = target->GetPositionZ() + 6 + rand()%5 + 10;
                    if(z > 95) z = 95 - rand()%5;
                }

                Creature *pCreature = m_creature->SummonCreature(MOB_SOARING_EAGLE, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                if (pCreature)
                {
                    pCreature->AddThreat(m_creature->getVictim(), 1.0f);
                    pCreature->AI()->AttackStart(m_creature->getVictim());
                }
            }
            SummonEagles_Timer = 999999;
        } else SummonEagles_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_soaring_eagleAI : public ScriptedAI
{
    mob_soaring_eagleAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 EagleSwoop_Timer;
    bool arrived;
    uint32 TargetGUID;

    void Reset()
    {
        EagleSwoop_Timer = 5000 + rand()%5000;
        arrived = true;
        TargetGUID = 0;
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
    }

    void Aggro(Unit *who) {DoZoneInCombat();}

    void AttackStart(Unit *who)
    {
        if (!InCombat)
        {
            Aggro(who);
            InCombat = true;
        }
    }

    void MoveInLineOfSight(Unit *) {}

    void MovementInform(uint32, uint32)
    {
        arrived = true;
        if(TargetGUID)
        {
            if(Unit* target = Unit::GetUnit(*m_creature, TargetGUID))
                m_creature->CastSpell(target, SPELL_EAGLE_SWOOP, true);
            TargetGUID = 0;
            m_creature->SetSpeed(MOVE_RUN, 1.2f);
            EagleSwoop_Timer = 5000 + rand()%5000;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(EagleSwoop_Timer < diff) EagleSwoop_Timer = 0;
        else EagleSwoop_Timer -= diff;

        if(arrived)
        {
            if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                float x, y, z;
                if(EagleSwoop_Timer)
                {
                    x = target->GetPositionX() + 10 - rand()%20;
                    y = target->GetPositionY() + 10 - rand()%20;
                    z = target->GetPositionZ() + 10 + rand()%5;
                    if(z > 95) z = 95 - rand()%5;
                }
                else
                {
                    target->GetContactPoint(m_creature, x, y, z);
                    z += 2;
                    m_creature->SetSpeed(MOVE_RUN, 5.0f);
                    TargetGUID = target->GetGUID();
                }
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
                arrived = false;
            }
        }
    }
};

//Soaring Eagle
CreatureAI* GetAI_mob_soaring_eagle(Creature *_Creature)
{
    return new mob_soaring_eagleAI(_Creature);
}

CreatureAI* GetAI_boss_akilzon(Creature *_Creature)
{
    return new boss_akilzonAI(_Creature);
}

void AddSC_boss_akilzon()
{
    Script *newscript = NULL;

    newscript = new Script;
    newscript->Name="boss_akilzon";
    newscript->GetAI = GetAI_boss_akilzon;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_akilzon_eagle";
    newscript->GetAI = GetAI_mob_soaring_eagle;
    m_scripts[nrscripts++] = newscript;
}
