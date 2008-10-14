/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Fathomlord_Karathress
SD%Complete: 50
SDComment: Missing Multishot, pet, Totems, Windfury, Whirlwind
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

//Karathress spells
#define SPELL_CATACLYSMIC_BOLT     38441
#define SPELL_POWER_OF_SHARKKIS    38455
#define SPELL_POWER_OF_TIDALVESS   38452
#define SPELL_POWER_OF_CARIBDIS    38451
#define SPELL_ENRAGE               24318
//Sharkkis spells
#define SPELL_LEECHING_THROW       29436
#define SPELL_THE_BEAST_WITHIN     38373
//Tidalvess spells
#define SPELL_FROST_SHOCK          38234
//Caribdis Spells
#define SPELL_WATER_BOLT_VOLLEY    38335
#define SPELL_TIDAL_SURGE          38353
#define SPELL_HEAL                 41386

#define SAY_AGGRO                  "Guards, attention! We have visitors..."
#define SAY_SLAY1                  "I am rid of you."
#define SAY_GAIN_ABILITY1          "I am more powerful than ever!"
#define SAY_GAIN_ABILITY2          "Go on, kill them! I'll be the better for it!"
#define SAY_GAIN_ABILITY3          "More knowledge, more power!"
#define SAY_DEATH                  "Her ... excellency ... awaits!"

#define SOUND_AGGRO                11277
#define SOUND_PLYR_ATTACK          11278
#define SOUND_GAIN_ABILITY1        11279
#define SOUND_GAIN_ABILITY2        11280
#define SOUND_GAIN_ABILITY3        11281
#define SOUND_SLAY1                11282
#define SOUND_SLAY2                11283
#define SOUND_SLAY3                11284
#define SOUND_DEATH                11285

//entry and position for Seer Olum
#define SEER_OLUM                  22820
#define OLUM_X                     446.78f
#define OLUM_Y                     -542.76f
#define OLUM_Z                     -7.54773f
#define OLUM_O                     0.401581f

//Fathom-Lord Karathress AI
struct MANGOS_DLL_DECL boss_fathomlord_karathressAI : public ScriptedAI
{
    boss_fathomlord_karathressAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Advisors[0] = 0;
        Advisors[1] = 0;
        Advisors[2] = 0;
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 CataclysmicBolt_Timer;
    uint32 Enrage_Timer;

    uint64 Advisors[3];

    void Reset()
    {
        CataclysmicBolt_Timer = 10000;
        Enrage_Timer = 600000;                              //10 minutes

        Creature* Advisor;
        for(uint8 i = 0; i < 3; ++i)
            if(Advisors[i])
        {
            Advisor = ((Creature*)Unit::GetUnit(*m_creature, Advisors[i]));
            if(Advisor)
            {
                if(Advisor->isAlive())
                {
                    Advisor->DealDamage(Advisor, Advisor->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    Advisor->RemoveCorpse();
                    Advisor->Respawn();
                }
                Advisor->AI()->EnterEvadeMode();
            }
        }

        if( pInstance )
            pInstance->SetData(DATA_KARATHRESSEVENT, NOT_STARTED);
    }

    void EventSharkkisDeath()
    {
        DoPlaySoundToSet(m_creature, SOUND_GAIN_ABILITY1);
        DoYell(SAY_GAIN_ABILITY1, LANG_UNIVERSAL, NULL);
        DoCast(m_creature, SPELL_POWER_OF_SHARKKIS);
    }

    void EventTidalvessDeath()
    {
        DoPlaySoundToSet(m_creature, SOUND_GAIN_ABILITY2);
        DoYell(SAY_GAIN_ABILITY2, LANG_UNIVERSAL, NULL);
        DoCast(m_creature, SPELL_POWER_OF_TIDALVESS);
    }

    void EventCaribdisDeath()
    {
        DoPlaySoundToSet(m_creature, SOUND_GAIN_ABILITY3);
        DoYell(SAY_GAIN_ABILITY3, LANG_UNIVERSAL, NULL);
        DoCast(m_creature, SPELL_POWER_OF_CARIBDIS);
    }

    void GetAdvisors()
    {
        if(!pInstance)
            return;

        Advisors[0] = pInstance->GetData64(DATA_SHARKKIS);
        Advisors[1] = pInstance->GetData64(DATA_TIDALVESS);
        Advisors[2] = pInstance->GetData64(DATA_CARIBDIS);
    }

    void StartEvent(Unit *who)
    {
        if(!pInstance)
            return;

        GetAdvisors();

        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);

        pInstance->SetData64(DATA_KARATHRESSEVENT_STARTER, who->GetGUID());
        pInstance->SetData(DATA_KARATHRESSEVENT, IN_PROGRESS);
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
                break;
            case 2:
                DoPlaySoundToSet(m_creature, SOUND_SLAY3);
                break;
        }
    }

    void JustDied(Unit *killer)
    {
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);

        if( pInstance )
            pInstance->SetData(DATA_FATHOMLORDKARATHRESSEVENT, NOT_STARTED);

        //support for quest 10944
        m_creature->SummonCreature(SEER_OLUM, OLUM_X, OLUM_Y, OLUM_Z, OLUM_O, TEMPSUMMON_TIMED_DESPAWN, 3600000);
    }

    void Aggro(Unit *who)
    {
        StartEvent(who);
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_KARATHRESSEVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESSEVENT_STARTER));

            if(target)
            {
                DoStartAttackAndMovement(target);

                GetAdvisors();

                DoPlaySoundToSet(m_creature, SOUND_AGGRO);
                DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_KARATHRESSEVENT))
            EnterEvadeMode();

        //CataclysmicBolt_Timer
        if(CataclysmicBolt_Timer < diff)
        {
            //select a random unit other than the main tank
            Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 1);

            //if there aren't other units, cast on the tank
            if(!target)
                target = m_creature->getVictim();

            int32 dmg = target->GetMaxHealth() / 2;
            m_creature->CastCustomSpell(target, SPELL_CATACLYSMIC_BOLT, &dmg, NULL, NULL, false, NULL, NULL, m_creature->GetGUID());

            CataclysmicBolt_Timer = 10000;
        }else CataclysmicBolt_Timer -= diff;

        //Enrage_Timer
        if(Enrage_Timer < diff)
        {
            DoCast(m_creature, SPELL_ENRAGE);
            Enrage_Timer = 90000;
        }else Enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Fathom-Guard Sharkkis AI
struct MANGOS_DLL_DECL boss_fathomguard_sharkkisAI : public ScriptedAI
{
    boss_fathomguard_sharkkisAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 LeechingThrow_Timer;
    uint32 TheBeastWithin_Timer;

    void Reset()
    {
        LeechingThrow_Timer = 20000;
        TheBeastWithin_Timer = 30000;

        if( pInstance )
            pInstance->SetData(DATA_KARATHRESSEVENT, NOT_STARTED);
    }

    void JustDied(Unit *victim)
    {
        if(pInstance)
        {
            Creature *Karathress = NULL;
            Karathress = (Creature*)(Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESS)));

            if(Karathress)
                ((boss_fathomlord_karathressAI*)Karathress->AI())->EventSharkkisDeath();
        }
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_KARATHRESSEVENT_STARTER, who->GetGUID());
            pInstance->SetData(DATA_KARATHRESSEVENT, IN_PROGRESS);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_KARATHRESSEVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESSEVENT_STARTER));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_KARATHRESSEVENT))
            EnterEvadeMode();

        //LeechingThrow_Timer
        if(LeechingThrow_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_LEECHING_THROW);
            LeechingThrow_Timer = 20000;
        }else LeechingThrow_Timer -= diff;

        //TheBeastWithin_Timer
        if(TheBeastWithin_Timer < diff)
        {
            DoCast(m_creature, SPELL_THE_BEAST_WITHIN);
            TheBeastWithin_Timer = 30000;
        }else TheBeastWithin_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Fathom-Guard Tidalvess AI
struct MANGOS_DLL_DECL boss_fathomguard_tidalvessAI : public ScriptedAI
{
    boss_fathomguard_tidalvessAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 FrostShock_Timer;

    void Reset()
    {
        FrostShock_Timer = 25000;

        if( pInstance )
            pInstance->SetData(DATA_KARATHRESSEVENT, NOT_STARTED);
    }

    void JustDied(Unit *victim)
    {
        if(pInstance)
        {
            Creature *Karathress = NULL;
            Karathress = (Creature*)(Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESS)));

            if(Karathress)
                ((boss_fathomlord_karathressAI*)Karathress->AI())->EventTidalvessDeath();
        }
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_KARATHRESSEVENT_STARTER, who->GetGUID());
            pInstance->SetData(DATA_KARATHRESSEVENT, IN_PROGRESS);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_KARATHRESSEVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESSEVENT_STARTER));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_KARATHRESSEVENT))
            EnterEvadeMode();

        //FrostShock_Timer
        if(FrostShock_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROST_SHOCK);
            FrostShock_Timer = 25000+rand()%5000;
        }else FrostShock_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Fathom-Guard Caribdis AI
struct MANGOS_DLL_DECL boss_fathomguard_caribdisAI : public ScriptedAI
{
    boss_fathomguard_caribdisAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 WaterBoltVolley_Timer;
    uint32 TidalSurge_Timer;
    uint32 Heal_Timer;

    void Reset()
    {
        WaterBoltVolley_Timer = 35000;
        TidalSurge_Timer = 15000+rand()%5000;
        Heal_Timer = 55000;

        if(pInstance)
            pInstance->SetData(DATA_KARATHRESSEVENT, NOT_STARTED);
    }

    void JustDied(Unit *victim)
    {
        if(pInstance)
        {
            Creature *Karathress = NULL;
            Karathress = (Creature*)(Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESS)));

            if(Karathress)
                ((boss_fathomlord_karathressAI*)Karathress->AI())->EventCaribdisDeath();
        }
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
        {
            pInstance->SetData64(DATA_KARATHRESSEVENT_STARTER, who->GetGUID());
            pInstance->SetData(DATA_KARATHRESSEVENT, IN_PROGRESS);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Only if not incombat check if the event is started
        if(!InCombat && pInstance && pInstance->GetData(DATA_KARATHRESSEVENT))
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESSEVENT_STARTER));

            if(target)
            {
                DoStartAttackAndMovement(target);
            }
        }

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //someone evaded!
        if(pInstance && !pInstance->GetData(DATA_KARATHRESSEVENT))
            EnterEvadeMode();

        //WaterBoltVolley_Timer
        if(WaterBoltVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_WATER_BOLT_VOLLEY);
            WaterBoltVolley_Timer = 30000;
        }else WaterBoltVolley_Timer -= diff;

        //TidalSurge_Timer
        if(TidalSurge_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_TIDAL_SURGE);
            TidalSurge_Timer = 15000+rand()%5000;
        }else TidalSurge_Timer -= diff;

        //Heal_Timer
        if(Heal_Timer < diff)
        {
            // It can be cast on any of the mobs
            Unit *pUnit = NULL;

            if(pInstance)
            {
                switch(rand()%4)
                {
                    case 0:
                        pUnit = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_KARATHRESS));
                        break;
                    case 1:
                        pUnit = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_SHARKKIS));
                        break;
                    case 2:
                        pUnit = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_TIDALVESS));
                        break;
                    case 3:
                        pUnit = m_creature;
                        break;
                }
            }else pUnit = m_creature;

            if(pUnit && pUnit->isAlive())
                DoCast(pUnit, SPELL_HEAL);

            Heal_Timer = 60000;
        }else Heal_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_fathomlord_karathress(Creature *_Creature)
{
    return new boss_fathomlord_karathressAI (_Creature);
}

CreatureAI* GetAI_boss_fathomguard_sharkkis(Creature *_Creature)
{
    return new boss_fathomguard_sharkkisAI (_Creature);
}

CreatureAI* GetAI_boss_fathomguard_tidalvess(Creature *_Creature)
{
    return new boss_fathomguard_tidalvessAI (_Creature);
}

CreatureAI* GetAI_boss_fathomguard_caribdis(Creature *_Creature)
{
    return new boss_fathomguard_caribdisAI (_Creature);
}

void AddSC_boss_fathomlord_karathress()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_fathomlord_karathress";
    newscript->GetAI = GetAI_boss_fathomlord_karathress;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_fathomguard_sharkkis";
    newscript->GetAI = GetAI_boss_fathomguard_sharkkis;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_fathomguard_tidalvess";
    newscript->GetAI = GetAI_boss_fathomguard_tidalvess;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_fathomguard_caribdis";
    newscript->GetAI = GetAI_boss_fathomguard_caribdis;
    m_scripts[nrscripts++] = newscript;
}
