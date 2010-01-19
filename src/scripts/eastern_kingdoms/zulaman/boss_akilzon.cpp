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

#include "ScriptedPch.h"
#include "zulaman.h"
#include "Weather.h"

#define SPELL_STATIC_DISRUPTION     43622
#define SPELL_STATIC_VISUAL         45265
#define SPELL_CALL_LIGHTNING        43661 //Missing timer
#define SPELL_GUST_OF_WIND          43621
#define SPELL_ELECTRICAL_STORM      43648
#define SPELL_BERSERK               45078
#define SPELL_ELECTRICAL_DAMAGE     43657
#define SPELL_ELECTRICAL_OVERLOAD   43658
#define SPELL_EAGLE_SWOOP           44732

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

struct TRINITY_DLL_DECL boss_akilzonAI : public ScriptedAI
{
    boss_akilzonAI(Creature *c) : ScriptedAI(c)
    {
        SpellEntry *TempSpell = GET_SPELL(SPELL_ELECTRICAL_DAMAGE);
        if (TempSpell)
            TempSpell->EffectBasePoints[1] = 49;//disable bugged lightning until fixed in core
        pInstance = c->GetInstanceData();
    }
    ScriptedInstance *pInstance;

    uint64 BirdGUIDs[8];
    uint64 TargetGUID;
    uint64 CycloneGUID;
    uint64 CloudGUID;

    uint32 StaticDisruption_Timer;
    uint32 GustOfWind_Timer;
    uint32 CallLighting_Timer;
    uint32 ElectricalStorm_Timer;
    uint32 SummonEagles_Timer;
    uint32 Enrage_Timer;

    uint32 StormCount;
    uint32 StormSequenceTimer;

    bool isRaining;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, NOT_STARTED);

        StaticDisruption_Timer = urand(10000,20000); //10 to 20 seconds (bosskillers)
        GustOfWind_Timer = urand(20000,30000); //20 to 30 seconds(bosskillers)
        CallLighting_Timer = urand(10000,20000); //totaly random timer. can't find any info on this
        ElectricalStorm_Timer = 60000; //60 seconds(bosskillers)
        Enrage_Timer = 10*MINUTE*IN_MILISECONDS; //10 minutes till enrage(bosskillers)
        SummonEagles_Timer = 99999;

        TargetGUID = 0;
        CloudGUID = 0;
        CycloneGUID = 0;
        DespawnSummons();
        for (uint8 i = 0; i < 8; ++i)
            BirdGUIDs[i] = 0;

        StormCount = 0;
        StormSequenceTimer = 0;

        isRaining = false;

        SetWeather(WEATHER_STATE_FINE, 0.0f);
    }

    void EnterCombat(Unit *who)
    {
        m_creature->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_ONAGGRO);
        //DoZoneInCombat();
        if (pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, IN_PROGRESS);
    }

    void JustDied(Unit* Killer)
    {
        m_creature->MonsterYell(SAY_ONDEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_ONDEATH);
        if (pInstance)
            pInstance->SetData(DATA_AKILZONEVENT, DONE);
        DespawnSummons();
    }

    void KilledUnit(Unit* victim)
    {
        switch (urand(0,1))
        {
            case 0:
                m_creature->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_ONSLAY1);
                break;
            case 1:
                m_creature->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_ONSLAY2);
                break;
        }
    }

    void DespawnSummons()
    {
        for (uint8 i = 0; i < 8; ++i)
        {
            Unit* bird = Unit::GetUnit(*m_creature,BirdGUIDs[i]);
            if (bird && bird->isAlive())
            {
                bird->SetVisibility(VISIBILITY_OFF);
                bird->setDeathState(JUST_DIED);
            }
        }
    }

    void SetWeather(uint32 weather, float grade)
    {
        Map* pMap = m_creature->GetMap();
        if (!pMap->IsDungeon())
            return;

        WorldPacket data(SMSG_WEATHER, (4+4+4));
        data << uint32(weather) << float(grade) << uint8(0);

        pMap->SendToPlayers(&data);
    }

    void HandleStormSequence(Unit *Cloud) // 1: begin, 2-9: tick, 10: end
    {
        if (StormCount < 10 && StormCount > 1)
        {
            // deal damage
            int32 bp0 = 800;
            for (uint8 i = 2; i < StormCount; ++i)
                bp0 *= 2;

            CellPair p(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
            Cell cell(p);
            cell.data.Part.reserved = ALL_DISTRICT;
            cell.SetNoCreate();

            std::list<Unit *> tempUnitMap;

            {
                Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(m_creature, m_creature, 999);
                Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(m_creature, tempUnitMap, u_check);

                TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
                TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

                CellLock<GridReadGuard> cell_lock(cell, p);
                cell_lock->Visit(cell_lock, world_unit_searcher, *(m_creature->GetMap()));
                cell_lock->Visit(cell_lock, grid_unit_searcher, *(m_creature->GetMap()));
            }
            //dealdamege
            for (std::list<Unit*>::iterator i = tempUnitMap.begin(); i != tempUnitMap.end(); ++i)
            {
                if (!Cloud->IsWithinDist(*i, 6, false))
                {
                    Cloud->CastCustomSpell(*i, 43137, &bp0, NULL, NULL, true, 0, 0, m_creature->GetGUID());
                }
            }
            // visual
            float x,y,z;
            z = m_creature->GetPositionZ();
            for (uint8 i = 0; i < 5+rand()%5; ++i)
            {
                x = 343+rand()%60;
                y = 1380+rand()%60;
                if (Unit *trigger = m_creature->SummonTrigger(x, y, z, 0, 2000))
                {
                    trigger->setFaction(35);
                    trigger->SetMaxHealth(100000);
                    trigger->SetHealth(100000);
                    trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    if (Cloud)
                        Cloud->CastCustomSpell(trigger, /*43661*/43137, &bp0, NULL, NULL,true, 0, 0, Cloud->GetGUID());
                }
            }
        }
        ++StormCount;
        if (StormCount > 10)
        {
            StormCount = 0; // finish
            SummonEagles_Timer = 5000;
            m_creature->InterruptNonMeleeSpells(false);
            CloudGUID = 0;
            if (Cloud)
                Cloud->DealDamage(Cloud, Cloud->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            SetWeather(WEATHER_STATE_FINE, 0.0f);
            isRaining = false;
        }
        StormSequenceTimer = 1000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (StormCount)
        {
            Unit *pTarget = Unit::GetUnit(*m_creature, CloudGUID);
            if (!pTarget || !pTarget->isAlive())
            {
                EnterEvadeMode();
                return;
            }
            else if (Unit* Cyclone = Unit::GetUnit(*m_creature, CycloneGUID))
                Cyclone->CastSpell(pTarget, 25160, true); // keep casting or...

            if (StormSequenceTimer <= diff)
                HandleStormSequence(pTarget);
            else
                StormSequenceTimer -= diff;

            return;
        }

        if (Enrage_Timer <= diff)
        {
            m_creature->MonsterYell(SAY_ONENRAGE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONENRAGE);
            DoCast(m_creature, SPELL_BERSERK, true);
            Enrage_Timer = 600000;
        } else Enrage_Timer -= diff;

        if (StaticDisruption_Timer <= diff)
        {
            Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if (!pTarget) pTarget = m_creature->getVictim();
            TargetGUID = pTarget->GetGUID();
            DoCast(pTarget, SPELL_STATIC_DISRUPTION, false);
            m_creature->SetInFront(m_creature->getVictim());
            StaticDisruption_Timer = (10+rand()%8)*1000; // < 20s

            /*if (float dist = m_creature->IsWithinDist3d(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 5.0f) dist = 5.0f;
            SDisruptAOEVisual_Timer = 1000 + floor(dist / 30 * 1000.0f);*/
        } else StaticDisruption_Timer -= diff;

        if (GustOfWind_Timer <= diff)
        {
            Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if (!pTarget) pTarget = m_creature->getVictim();
            DoCast(pTarget, SPELL_GUST_OF_WIND);
            GustOfWind_Timer = (20+rand()%10)*1000; //20 to 30 seconds(bosskillers)
        } else GustOfWind_Timer -= diff;

        if (CallLighting_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CALL_LIGHTNING);
            CallLighting_Timer = (12 + rand()%5)*1000; //totaly random timer. can't find any info on this
        } else CallLighting_Timer -= diff;

        if (!isRaining && ElectricalStorm_Timer < 8000 + rand()%5000)
        {
            SetWeather(WEATHER_STATE_HEAVY_RAIN, 0.9999f);
            isRaining = true;
        }

        if (ElectricalStorm_Timer <= diff) {
            Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
            if (!pTarget)
            {
                EnterEvadeMode();
                return;
            }
            pTarget->CastSpell(pTarget, 44007, true);//cloud visual
            DoCast(pTarget, SPELL_ELECTRICAL_STORM, false);//storm cyclon + visual
            float x,y,z;
            pTarget->GetPosition(x,y,z);
            if (pTarget)
            {
                pTarget->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                pTarget->SendMonsterMove(x,y,m_creature->GetPositionZ()+15,0);
            }
            Unit *Cloud = m_creature->SummonTrigger(x, y, m_creature->GetPositionZ()+16, 0, 15000);
            if (Cloud)
            {
                CloudGUID = Cloud->GetGUID();
                Cloud->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                Cloud->StopMoving();
                Cloud->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                Cloud->setFaction(35);
                Cloud->SetMaxHealth(9999999);
                Cloud->SetHealth(9999999);
                Cloud->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
            ElectricalStorm_Timer = 60000; //60 seconds(bosskillers)
            StormCount = 1;
            StormSequenceTimer = 0;
        } else ElectricalStorm_Timer -= diff;

        if (SummonEagles_Timer <= diff)
        {
            m_creature->MonsterYell(SAY_ONSUMMON, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_ONSUMMON);

            float x, y, z;
            m_creature->GetPosition(x, y, z);

            for (uint8 i = 0; i < 8; ++i)
            {
                Unit* bird = Unit::GetUnit(*m_creature,BirdGUIDs[i]);
                if (!bird) //they despawned on die
                {
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    {
                        x = pTarget->GetPositionX() + irand(-10,10);
                        y = pTarget->GetPositionY() + irand(-10,10);
                        z = pTarget->GetPositionZ() + urand(16,20);
                        if (z > 95)
                            z = 95 - urand(0,5);
                    }
                    Creature *pCreature = m_creature->SummonCreature(MOB_SOARING_EAGLE, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    if (pCreature)
                    {
                        pCreature->AddThreat(m_creature->getVictim(), 1.0f);
                        pCreature->AI()->AttackStart(m_creature->getVictim());
                        BirdGUIDs[i] = pCreature->GetGUID();
                    }
                }
            }
            SummonEagles_Timer = 999999;
        } else SummonEagles_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_soaring_eagleAI : public ScriptedAI
{
    mob_soaring_eagleAI(Creature *c) : ScriptedAI(c) {}

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

    void EnterCombat(Unit *who) {DoZoneInCombat();}

    void MoveInLineOfSight(Unit* who) {}

    void MovementInform(uint32, uint32)
    {
        arrived = true;
        if (TargetGUID)
        {
            if (Unit *pTarget = Unit::GetUnit(*m_creature, TargetGUID))
                DoCast(pTarget, SPELL_EAGLE_SWOOP, true);
            TargetGUID = 0;
            m_creature->SetSpeed(MOVE_RUN, 1.2f);
            EagleSwoop_Timer = 5000 + rand()%5000;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (EagleSwoop_Timer <= diff)
            EagleSwoop_Timer = 0;
        else
            EagleSwoop_Timer -= diff;

        if (arrived)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                float x, y, z;
                if (EagleSwoop_Timer)
                {
                    x = pTarget->GetPositionX() + irand(-10,10);
                    y = pTarget->GetPositionY() + irand(-10,10);
                    z = pTarget->GetPositionZ() + urand(10,15);
                    if (z > 95)
                        z = 95 - urand(0,5);
                }
                else
                {
                    pTarget->GetContactPoint(m_creature, x, y, z);
                    z += 2;
                    m_creature->SetSpeed(MOVE_RUN, 5.0f);
                    TargetGUID = pTarget->GetGUID();
                }
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
                arrived = false;
            }
        }
    }
};

//Soaring Eagle
CreatureAI* GetAI_mob_soaring_eagle(Creature* pCreature)
{
    return new mob_soaring_eagleAI(pCreature);
}

CreatureAI* GetAI_boss_akilzon(Creature* pCreature)
{
    return new boss_akilzonAI(pCreature);
}

void AddSC_boss_akilzon()
{
    Script *newscript = NULL;

    newscript = new Script;
    newscript->Name = "boss_akilzon";
    newscript->GetAI = &GetAI_boss_akilzon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_akilzon_eagle";
    newscript->GetAI = &GetAI_mob_soaring_eagle;
    newscript->RegisterSelf();
}

