/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Morogrim_Tidewalker
SD%Complete: 90
SDComment: Water globules don't explode properly
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

#define SPELL_TIDAL_WAVE             37730
#define SPELL_WATERY_GRAVE           38049
#define SPELL_EARTHQUAKE             37764
#define SPELL_WATERY_GRAVE_EXPLOSION 37852

#define SAY_AGGRO                    "Flood of the deep, take you!"
#define SAY_SUMMON1                  "By the Tides, kill them at once!"
#define SAY_SUMMON2                  "Destroy them my subjects!"
#define SAY_SLAY1                    "It is done!"
#define SAY_SLAY2                    "Strugging only makes it worse."
#define SAY_SLAY3                    "Only the strong survive."
#define SAY_SUMMON_BUBL1             "There is nowhere to hide!"
#define SAY_SUMMON_BUBL2             "Soon it will be finished!"
#define SAY_DEATH                    "Great... currents of... Ageon."

#define SOUND_AGGRO                  11321
#define SOUND_SUMMON1                11322
#define SOUND_SUMMON2                11323
#define SOUND_SLAY1                  11326
#define SOUND_SLAY2                  11327
#define SOUND_SLAY3                  11328
#define SOUND_SUMMON_BUBL1           11324
#define SOUND_SUMMON_BUBL2           11325
#define SOUND_DEATH                  11329

#define WATERY_GRAVE_X1              334.64
#define WATERY_GRAVE_Y1              -728.89
#define WATERY_GRAVE_Z1              -14.42
#define WATERY_GRAVE_X2              365.51
#define WATERY_GRAVE_Y2              -737.14
#define WATERY_GRAVE_Z2              -14.44
#define WATERY_GRAVE_X3              366.19
#define WATERY_GRAVE_Y3              -709.59
#define WATERY_GRAVE_Z3              -14.36
#define WATERY_GRAVE_X4              372.93
#define WATERY_GRAVE_Y4              -690.96
#define WATERY_GRAVE_Z4              -14.44

#define EMOTE_WATERY_GRAVE         "sends his enemies to their watery graves!"
#define EMOTE_EARTHQUAKE           "The violent earthquake has alerted nearby murlocs!"
#define EMOTE_WATERY_GLOBULES      "summons Watery Globules!"

#define WATER_GLOBULE              21913
#define TIDEWALKER_LURKER          21920

//Morogrim Tidewalker AI
struct TRINITY_DLL_DECL boss_morogrim_tidewalkerAI : public ScriptedAI
{
    boss_morogrim_tidewalkerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 TidalWave_Timer;
    uint32 WateryGrave_Timer;
    uint32 Earthquake_Timer;
    uint32 WateryGlobules_Timer;

    bool Earthquake;
    bool Phase2;

    void Reset()
    {
        TidalWave_Timer = 10000;
        WateryGrave_Timer = 30000;
        Earthquake_Timer = 40000;
        WateryGlobules_Timer = 0;

        Earthquake = false;
        Phase2 = false;

        if(pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
    }

    void StartEvent()
    {
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);

        if(pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, IN_PROGRESS); 
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
            case 0:
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                DoYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
                break;

            case 1:
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                DoYell(SAY_SLAY2, LANG_UNIVERSAL, NULL);
                break;

            case 2:
                DoPlaySoundToSet(m_creature, SOUND_SLAY3);
                DoYell(SAY_SLAY3, LANG_UNIVERSAL, NULL);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);

        if(pInstance)
            pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
    }

    void Aggro(Unit *who) { StartEvent(); }

    void ApplyWateryGrave(Unit *player, uint8 pos)
    {
        float x, y, z;

        switch(pos)
        {
            case 0:
            x = WATERY_GRAVE_X1;
            y = WATERY_GRAVE_Y1;
            z = WATERY_GRAVE_Z1;
            break;

            case 1:
            x = WATERY_GRAVE_X2;
            y = WATERY_GRAVE_Y2;
            z = WATERY_GRAVE_Z2;
            break;
            
            case 2:
            x = WATERY_GRAVE_X3;
            y = WATERY_GRAVE_Y3;
            z = WATERY_GRAVE_Z3;
            break;

            case 3:
            x = WATERY_GRAVE_X4;
            y = WATERY_GRAVE_Y4;
            z = WATERY_GRAVE_Z4;
            break;
        }

        DoTeleportPlayer(player, x, y, z+1, player->GetOrientation());
        DoCast(player, SPELL_WATERY_GRAVE);
    }

    void SummonMurloc(float x, float y, float z)
    {
        Creature *Summoned;

        Summoned = m_creature->SummonCreature(TIDEWALKER_LURKER, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
        if(Summoned)
        {
            Unit *target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if(target)
                Summoned->AI()->AttackStart(target);
        }
    }

    void SummonWaterGlobule(float x, float y, float z)
    {
        Creature *Globule;

        Globule = m_creature->SummonCreature(WATER_GLOBULE, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 30000); //they despawn after 30 seconds
        if(Globule)
        {
            Unit *target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if(target)
                Globule->AI()->AttackStart(target);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Earthquake_Timer
        if(Earthquake_Timer < diff)
        {
            if(!Earthquake)
            {
                DoCast(m_creature->getVictim(), SPELL_EARTHQUAKE);
                Earthquake = true;
                Earthquake_Timer = 10000;
            }
            else
            {
                switch(rand()%2)
                {
                    case 0:
                    DoPlaySoundToSet(m_creature, SOUND_SUMMON1);
                    DoYell(SAY_SUMMON1, LANG_UNIVERSAL, NULL);
                    break;

                    case 1:
                    DoPlaySoundToSet(m_creature, SOUND_SUMMON2);
                    DoYell(SAY_SUMMON2, LANG_UNIVERSAL, NULL);
                    break;
                }

                //north
                SummonMurloc(486.10, -723.64, -7.14);
                SummonMurloc(482.58, -723.78, -7.14);
                SummonMurloc(479.38, -723.91, -7.14);
                SummonMurloc(476.03, -723.86, -7.14);
                SummonMurloc(472.69, -723.69, -7.14);
                SummonMurloc(469.04, -723.63, -7.14);

                //south
                SummonMurloc(311.63, -725.04, -13.15);
                SummonMurloc(307.81, -725.34, -13.15);
                SummonMurloc(303.91, -725.64, -13.06);
                SummonMurloc(300.23, -726, -11.89);
                SummonMurloc(296.82, -726.33, -10.82);
                SummonMurloc(293.64, -726.64, -9.81);

                DoTextEmote(EMOTE_EARTHQUAKE, NULL);

                Earthquake = false;
                Earthquake_Timer = 40000+rand()%5000;
            }
        }else Earthquake_Timer -= diff;

        //TidalWave_Timer
        if(TidalWave_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_TIDAL_WAVE);
            TidalWave_Timer = 20000;
        }else TidalWave_Timer -= diff;

        if(!Phase2)
        {
            //WateryGrave_Timer
            if(WateryGrave_Timer < diff)
            {
                //Teleport 4 players under the waterfalls
                Unit *target;
                for(uint8 i = 0; i < 4; i++)
                {
                    target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                    if(target && (target->GetTypeId() == TYPEID_PLAYER) && !target->HasAura(SPELL_WATERY_GRAVE, 0) && target->IsWithinDistInMap(m_creature, 50))
                        ApplyWateryGrave(target, i);
                }

                switch(rand()%2)
                {
                case 0:
                    DoPlaySoundToSet(m_creature, SOUND_SUMMON_BUBL1);
                    DoYell(SAY_SUMMON_BUBL1, LANG_UNIVERSAL, NULL);
                    break;

                case 1:
                    DoPlaySoundToSet(m_creature, SOUND_SUMMON_BUBL2);
                    DoYell(SAY_SUMMON_BUBL2, LANG_UNIVERSAL, NULL);
                    break;

                case 2:
                    break;
                }

                DoTextEmote(EMOTE_WATERY_GRAVE, NULL);

                WateryGrave_Timer = 30000;
            }else WateryGrave_Timer -= diff;

            //Start Phase2
            if((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
                Phase2 = true;
        }
        else
        {
            //WateryGlobules_Timer
            if(WateryGlobules_Timer < diff)
            {
                SummonWaterGlobule(WATERY_GRAVE_X1, WATERY_GRAVE_Y1, WATERY_GRAVE_Z1);
                SummonWaterGlobule(WATERY_GRAVE_X2, WATERY_GRAVE_Y2, WATERY_GRAVE_Z2);
                SummonWaterGlobule(WATERY_GRAVE_X3, WATERY_GRAVE_Y3, WATERY_GRAVE_Z3);
                SummonWaterGlobule(WATERY_GRAVE_X4, WATERY_GRAVE_Y4, WATERY_GRAVE_Z4);

                DoTextEmote(EMOTE_WATERY_GLOBULES, NULL);

                WateryGlobules_Timer = 25000;
            }else WateryGlobules_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

//Water Globule AI
struct TRINITY_DLL_DECL mob_water_globuleAI : public ScriptedAI
{
    mob_water_globuleAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Check_Timer;

    void Reset()
    {
        Check_Timer = 1000;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setFaction(14);
    }

    void Aggro(Unit *who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            //no attack radius check - it attacks the first target that moves in his los
            if(who->HasStealthAura())
                who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

            DoStartAttackAndMovement(who);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if(Check_Timer < diff)
        {
            if(m_creature->IsWithinDistInMap(m_creature->getVictim(), 5))
            {
                uint32 damage = 4000+rand()%2000;
                m_creature->DealDamage(m_creature->getVictim(), damage, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_FROST, NULL, false);

                //despawn
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
            Check_Timer = 500;
        }else Check_Timer -= diff;

        //do NOT deal any melee damage to the target.
    }
};

CreatureAI* GetAI_boss_morogrim_tidewalker(Creature *_Creature)
{
    return new boss_morogrim_tidewalkerAI (_Creature);
}
CreatureAI* GetAI_mob_water_globule(Creature *_Creature)
{
    return new mob_water_globuleAI (_Creature);
}

void AddSC_boss_morogrim_tidewalker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_morogrim_tidewalker";
    newscript->GetAI = GetAI_boss_morogrim_tidewalker;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_water_globule";
    newscript->GetAI = GetAI_mob_water_globule;
    m_scripts[nrscripts++] = newscript;
}
