/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "hyjal.h"
#include "hyjal_trash.h"

#define SPELL_RAIN_OF_FIRE 31340
#define SPELL_DOOM 31347
#define SPELL_HOWL_OF_AZGALOR 31344
#define SPELL_CLEAVE 31345
#define SPELL_BERSERK 26662

#define SAY_ONDEATH "Your time is almost... up"
#define SOUND_ONDEATH 11002

#define SAY_ONSLAY1 "Reesh, hokta!"
#define SAY_ONSLAY2 "Don't fight it"
#define SAY_ONSLAY3 "No one is going to save you"
#define SOUND_ONSLAY1 11001
#define SOUND_ONSLAY2 11048
#define SOUND_ONSLAY3 11047

#define SAY_DOOM1 "Just a taste... of what awaits you"
#define SAY_DOOM2 "Suffer you despicable insect!"
#define SOUND_DOOM1 11046
#define SOUND_DOOM2 11000

#define SAY_ONAGGRO "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!"
#define SOUND_ONAGGRO 10999

struct boss_azgalorAI : public hyjal_trashAI
{
    boss_azgalorAI(Creature *c) : hyjal_trashAI(c)
    {
        pInstance = c->GetInstanceData();
        pGo = false;
        pos = 0;
        SpellEntry *TempSpell = GET_SPELL(SPELL_HOWL_OF_AZGALOR);
        if (TempSpell)
            TempSpell->EffectRadiusIndex[0] = 12;//100yards instead of 50000?!
    }

    uint32 RainTimer;
    uint32 DoomTimer;
    uint32 HowlTimer;
    uint32 CleaveTimer;
    uint32 EnrageTimer;
    bool enraged;

    bool pGo;
    uint32 pos;

    void Reset()
    {
        damageTaken = 0;
        RainTimer = 20000;
        DoomTimer = 50000;
        HowlTimer = 30000;
        CleaveTimer = 10000;
        EnrageTimer = 600000;
        enraged = false;

        if (pInstance && IsEvent)
            pInstance->SetData(DATA_AZGALOREVENT, NOT_STARTED);
    }

    void EnterCombat(Unit * /*who*/)
    {
        if (pInstance && IsEvent)
            pInstance->SetData(DATA_AZGALOREVENT, IN_PROGRESS);
        DoPlaySoundToSet(me, SOUND_ONAGGRO);
        me->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, NULL);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        switch (urand(0,2))
        {
            case 0:
                DoPlaySoundToSet(me, SOUND_ONSLAY1);
                me->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, NULL);
                break;
            case 1:
                DoPlaySoundToSet(me, SOUND_ONSLAY2);
                me->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, NULL);
                break;
            case 2:
                DoPlaySoundToSet(me, SOUND_ONSLAY3);
                me->MonsterYell(SAY_ONSLAY3, LANG_UNIVERSAL, NULL);
                break;
        }
    }

    void WaypointReached(uint32 i)
    {
        pos = i;
        if (i == 7 && pInstance)
        {
            Unit *pTarget = Unit::GetUnit((*me), pInstance->GetData64(DATA_THRALL));
            if (pTarget && pTarget->isAlive())
                me->AddThreat(pTarget,0.0);
        }
    }

    void JustDied(Unit *victim)
    {
        hyjal_trashAI::JustDied(victim);
        if (pInstance && IsEvent)
            pInstance->SetData(DATA_AZGALOREVENT, DONE);
        DoPlaySoundToSet(me, SOUND_ONDEATH);
    }

    void UpdateAI(const uint32 diff)
    {
        if (IsEvent)
        {
            //Must update npc_escortAI
            npc_escortAI::UpdateAI(diff);
            if (!pGo)
            {
                pGo = true;
                if (pInstance)
                {
                    AddWaypoint(0, 5492.91,    -2404.61,    1462.63);
                    AddWaypoint(1, 5531.76,    -2460.87,    1469.55);
                    AddWaypoint(2, 5554.58,    -2514.66,    1476.12);
                    AddWaypoint(3, 5554.16,    -2567.23,    1479.90);
                    AddWaypoint(4, 5540.67,    -2625.99,    1480.89);
                    AddWaypoint(5, 5508.16,    -2659.2,    1480.15);
                    AddWaypoint(6, 5489.62,    -2704.05,    1482.18);
                    AddWaypoint(7, 5457.04,    -2726.26,    1485.10);
                    Start(false, true);
                    SetDespawnAtEnd(false);
                }
            }
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (RainTimer <= diff)
        {
            DoCast(SelectTarget(SELECT_TARGET_RANDOM,0,30,true), SPELL_RAIN_OF_FIRE);
            RainTimer = 20000+rand()%15000;
        } else RainTimer -= diff;

        if (DoomTimer <= diff)
        {
            DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), SPELL_DOOM);//never on tank
            DoomTimer = 45000+rand()%5000;
        } else DoomTimer -= diff;

        if (HowlTimer <= diff)
        {
            DoCast(me, SPELL_HOWL_OF_AZGALOR);
            HowlTimer = 30000;
        } else HowlTimer -= diff;

        if (CleaveTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_CLEAVE);
            CleaveTimer = 10000+rand()%5000;
        } else CleaveTimer -= diff;

        if (EnrageTimer < diff && !enraged)
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_BERSERK, true);
            enraged = true;
            EnrageTimer = 600000;
        } else EnrageTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_azgalor(Creature* pCreature)
{
    return new boss_azgalorAI (pCreature);
}

#define SPELL_THRASH 12787
#define SPELL_CRIPPLE 31406
#define SPELL_WARSTOMP 31408

struct mob_lesser_doomguardAI : public hyjal_trashAI
{
    mob_lesser_doomguardAI(Creature *c) : hyjal_trashAI(c)
    {
        pInstance = c->GetInstanceData();
        if (pInstance)
            AzgalorGUID = pInstance->GetData64(DATA_AZGALOR);
    }

    uint32 CrippleTimer;
    uint32 WarstompTimer;
    uint32 CheckTimer;
    uint64 AzgalorGUID;
    ScriptedInstance* pInstance;

    void Reset()
    {
        CrippleTimer = 50000;
        WarstompTimer = 10000;
        DoCast(me, SPELL_THRASH);
        CheckTimer = 5000;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void KilledUnit(Unit * /*victim*/)
    {
    }

    void WaypointReached(uint32 /*i*/)
    {
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (me->IsWithinDist(who, 50) && !me->isInCombat() && me->IsHostileTo(who))
            AttackStart(who);
    }

    void JustDied(Unit * /*victim*/)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (CheckTimer <= diff)
        {
            if (AzgalorGUID)
            {
                Creature* boss = Unit::GetCreature((*me),AzgalorGUID);
                if (!boss || (boss && boss->isDead()))
                {
                    me->setDeathState(JUST_DIED);
                    me->RemoveCorpse();
                    return;
                }
            }
            CheckTimer = 5000;
        } else CheckTimer -= diff;

        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (WarstompTimer <= diff)
        {
            DoCast(me, SPELL_WARSTOMP);
            WarstompTimer = 10000+rand()%5000;
        } else WarstompTimer -= diff;

        if (CrippleTimer <= diff)
        {
            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_CRIPPLE);
            CrippleTimer = 25000+rand()%5000;
        } else CrippleTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_lesser_doomguard(Creature* pCreature)
{
    return new mob_lesser_doomguardAI (pCreature);
}

void AddSC_boss_azgalor()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_azgalor";
    newscript->GetAI = &GetAI_boss_azgalor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_lesser_doomguard";
    newscript->GetAI = &GetAI_mob_lesser_doomguard;
    newscript->RegisterSelf();
}
