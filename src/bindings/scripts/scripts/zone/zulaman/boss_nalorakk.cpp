/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Nalorakk
SD%Complete: 80
SDComment: Todo: Trash Waves
SDCategory: Zul'Aman
EndScriptData */

#include "precompiled.h"
#include "def_zulaman.h"

//TODO: Trash Waves

//Unimplemented SoundIDs
/*
#define SOUND_NALORAKK_WAVE1    12066
#define SOUND_NALORAKK_WAVE2    12067
#define SOUND_NALORAKK_WAVE3    12068
#define SOUND_NALORAKK_WAVE4    12069

#define SOUND_NALORAKK_EVENT1   12078
#define SOUND_NALORAKK_EVENT2   12079
*/


//General defines
#define YELL_AGGRO              "You be dead soon enough!"
#define SOUND_YELL_AGGRO        12070
#define YELL_KILL_ONE           "Mua-ha-ha! Now whatchoo got to say?"
#define SOUND_YELL_KILL_ONE     12075
#define YELL_KILL_TWO           "Da Amani gonna rule again!"
#define SOUND_YELL_KILL_TWO     12076
#define YELL_DEATH              "I... be waitin' on da udda side...."
#define SOUND_YELL_DEATH        12077
#define YELL_BERSERK            "You had your chance, now it be too late!" //Never seen this being used, so just guessing from what I hear.
#define SOUND_YELL_BERSERK      12074

#define SPELL_BERSERK           45078

//Defines for Troll form
#define SPELL_BRUTALSWIPE       42384
#define SPELL_MANGLE            42389
#define SPELL_MANGLEEFFECT      44955
#define SPELL_SURGE             42402
#define SPELL_BEARFORM          42377

#define YELL_SURGE              "I bring da pain!"
#define SOUND_YELL_SURGE        12071

#define YELL_SHIFTEDTOTROLL     "Make way for Nalorakk!"
#define SOUND_YELL_TOTROLL      12073

//Defines for Bear form
#define SPELL_LACERATINGSLASH   42395
#define SPELL_RENDFLESH         42397
#define SPELL_DEAFENINGROAR     42398

#define YELL_SHIFTEDTOBEAR      "You call on da beast, you gonna get more dan you bargain for!"
#define SOUND_YELL_TOBEAR       12072


struct TRINITY_DLL_DECL boss_nalorakkAI : public ScriptedAI
{
    boss_nalorakkAI(Creature *c) : ScriptedAI(c) {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 BrutalSwipe_Timer;
    uint32 Mangle_Timer;
    uint32 Surge_Timer;

    uint32 LaceratingSlash_Timer;
    uint32 RendFlesh_Timer;
    uint32 DeafeningRoar_Timer;

    uint32 ShapeShift_Timer;
    uint32 Berserk_Timer;

    uint64 ChargeTargetGUID;
    uint64 TankGUID;

    bool inBearForm;

    void Reset()
    {
        if(pInstance)
            pInstance->SetData(DATA_NALORAKKEVENT, NOT_STARTED);

        Surge_Timer = 15000 + rand()%5000;
        BrutalSwipe_Timer = 7000 + rand()%5000;
        Mangle_Timer = 10000 + rand()%5000;
        ShapeShift_Timer = 45000 + rand()%5000;
        Berserk_Timer = 600000;

        ChargeTargetGUID = 0;
        TankGUID = 0;

        inBearForm = false;
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY + 1, 5122);
    }

    void Aggro(Unit *who)
    {
        if(pInstance)
            pInstance->SetData(DATA_NALORAKKEVENT, IN_PROGRESS);

        DoYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_YELL_AGGRO);
//        DoZoneInCombat();
    }

    void JustDied(Unit* Killer)    
    {	
        if(pInstance)
            pInstance->SetData(DATA_NALORAKKEVENT, DONE);

        DoYell(YELL_DEATH,LANG_UNIVERSAL,NULL);		
        DoPlaySoundToSet(m_creature, SOUND_YELL_DEATH);  
    }

    void KilledUnit(Unit* victim)    
    {
        switch(rand()%2)
        {
        case 0:
            DoYell(YELL_KILL_ONE, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_YELL_KILL_ONE);
            break;
        case 1:
            DoYell(YELL_KILL_TWO, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_YELL_KILL_TWO);
            break;        
        }
    }

    void MovementInform(uint32, uint32)
    {
        if(ChargeTargetGUID)
        {
            if(Unit* target = Unit::GetUnit(*m_creature, ChargeTargetGUID))
                m_creature->CastSpell(target, SPELL_SURGE, true);
            ChargeTargetGUID = 0;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(TankGUID)
        {
            if(!ChargeTargetGUID)
            {
                m_creature->SetSpeed(MOVE_RUN, 1.2f);
                m_creature->GetMotionMaster()->Clear();
                if(Unit* target = Unit::GetUnit(*m_creature, TankGUID))
                    m_creature->GetMotionMaster()->MoveChase(target);
                TankGUID = 0;
            }
            return;
        }

        if(!m_creature->SelectHostilTarget() && !m_creature->getVictim())
            return;

        if(Berserk_Timer < diff)
        {
            DoCast(m_creature, SPELL_BERSERK, true);
            DoYell(YELL_BERSERK, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_YELL_BERSERK);
            Berserk_Timer = 600000;
        }else Berserk_Timer -= diff;

        if(ShapeShift_Timer < diff)
        {
            if(inBearForm)
            {
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY + 1, 5122);
                DoYell(YELL_SHIFTEDTOTROLL, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_TOTROLL);
                m_creature->RemoveAurasDueToSpell(SPELL_BEARFORM);
                Surge_Timer = 15000 + rand()%5000;
                BrutalSwipe_Timer = 7000 + rand()%5000;
                Mangle_Timer = 10000 + rand()%5000;
                ShapeShift_Timer = 45000 + rand()%5000;
                inBearForm = false;
            }
            else
            {
                m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY + 1, 0);
                DoYell(YELL_SHIFTEDTOBEAR, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_TOBEAR);
                DoCast(m_creature, SPELL_BEARFORM, true);
                LaceratingSlash_Timer = 2000; // dur 18s
                RendFlesh_Timer = 3000;  // dur 5s
                DeafeningRoar_Timer = 5000 + rand()%5000;  // dur 2s
                ShapeShift_Timer = 20000 + rand()%5000; // dur 30s
                inBearForm = true;
            }
        }else ShapeShift_Timer -= diff;

        if(!inBearForm)
        {
            if(BrutalSwipe_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_BRUTALSWIPE);
                BrutalSwipe_Timer = 7000 + rand()%5000;
            }else BrutalSwipe_Timer -= diff;

            if(Mangle_Timer < diff)
            {
                if(!m_creature->getVictim()->HasAura(SPELL_MANGLEEFFECT, 0))
                {
                    DoCast(m_creature->getVictim(), SPELL_MANGLE);
                    Mangle_Timer = 1000;
                }
                else Mangle_Timer = 10000 + rand()%5000;
            }else Mangle_Timer -= diff;

            if(Surge_Timer < diff)
            {
                DoYell(YELL_SURGE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_SURGE);

                Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if(!target) target = m_creature->getVictim();
                TankGUID = m_creature->getVictim()->GetGUID();
                ChargeTargetGUID = target->GetGUID();

                float x, y, z;
                target->GetContactPoint(m_creature, x, y, z);
                m_creature->SetSpeed(MOVE_RUN, 5.0f);
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MovePoint(0, x, y, z);

                Surge_Timer = 15000 + rand()%5000;
                return;
            }else Surge_Timer -= diff;
        }
        else {
            if(LaceratingSlash_Timer < diff)
            {
                if(!m_creature->getVictim()->HasAura(SPELL_MANGLEEFFECT, 0))
                    DoCast(m_creature->getVictim(), SPELL_LACERATINGSLASH);
                else
                {
                    int32 bp0 = 3470;
                    m_creature->CastCustomSpell(m_creature->getVictim(), SPELL_LACERATINGSLASH, &bp0, NULL, NULL, false);
                }
                LaceratingSlash_Timer = 18000 + rand()%5000;
            }else LaceratingSlash_Timer -= diff;

            if(RendFlesh_Timer < diff)
            {
                if(!m_creature->getVictim()->HasAura(SPELL_MANGLEEFFECT, 0))
                    DoCast(m_creature->getVictim(), SPELL_RENDFLESH);
                else
                {
                    int32 bp1 = 4670;
                    m_creature->CastCustomSpell(m_creature->getVictim(), SPELL_RENDFLESH, NULL, &bp1, NULL, false);
                }
                RendFlesh_Timer = 5000 + rand()%5000;
            }else RendFlesh_Timer -= diff;

            if(DeafeningRoar_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_DEAFENINGROAR);
                DeafeningRoar_Timer = 15000 + rand()%5000;
            }else DeafeningRoar_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_nalorakk(Creature *_Creature)
{
    return new boss_nalorakkAI (_Creature);
}

void AddSC_boss_nalorakk()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_nalorakk";
    newscript->GetAI = GetAI_boss_nalorakk;
    m_scripts[nrscripts++] = newscript;
}
