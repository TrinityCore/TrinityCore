/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org>
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

#include "ScriptedPch.h"
#include "nexus.h"

enum Spells
{
    SPELL_ICE_NOVA                                = 47772,
    H_SPELL_ICE_NOVA                              = 56935,
    SPELL_FIREBOMB                                = 47773,
    H_SPELL_FIREBOMB                              = 56934,
    SPELL_GRAVITY_WELL                            = 47756,
    SPELL_TELESTRA_BACK                           = 47714,

    SPELL_FIRE_MAGUS_VISUAL                       = 47705,
    SPELL_FROST_MAGUS_VISUAL                      = 47706,
    SPELL_ARCANE_MAGUS_VISUAL                     = 47704
};
enum Creatures
{
    MOB_FIRE_MAGUS                                = 26928,
    MOB_FROST_MAGUS                               = 26930,
    MOB_ARCANE_MAGUS                              = 26929
};
enum Yells
{
    SAY_AGGRO                                     = -1576000,
    SAY_KILL                                      = -1576001,
    SAY_DEATH                                     = -1576002,
    SAY_MERGE                                     = -1576003,
    SAY_SPLIT_1                                   = -1576004,
    SAY_SPLIT_2                                   = -1576005,
};
enum Achievements
{
    ACHIEV_SPLIT_PERSONALITY                      = 2150,
    ACHIEV_TIMER                                  = 5*IN_MILISECONDS
};

const Position  CenterOfRoom = {504.80, 89.07, -16.12, 6.27};

struct boss_magus_telestraAI : public ScriptedAI
{
    boss_magus_telestraAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint64 uiFireMagusGUID;
    uint64 uiFrostMagusGUID;
    uint64 uiArcaneMagusGUID;

    bool bFireMagusDead;
    bool bFrostMagusDead;
    bool bArcaneMagusDead;
    bool bIsWaitingToAppear;
    bool bIsAchievementTimerRunning;

    uint32 uiIsWaitingToAppearTimer;
    uint32 uiIceNovaTimer;
    uint32 uiFireBombTimer;
    uint32 uiGravityWellTimer;
    uint32 uiCooldown;
    uint32 uiAchievementTimer;

    uint8 Phase;
    uint8 uiAchievementProgress;

    void Reset()
    {
        Phase = 0;
        //These times are probably wrong
        uiIceNovaTimer =  7*IN_MILISECONDS;
        uiFireBombTimer =  0;
        uiGravityWellTimer = 15*IN_MILISECONDS;
        uiCooldown = 0;

        uiFireMagusGUID = 0;
        uiFrostMagusGUID = 0;
        uiArcaneMagusGUID = 0;

        uiAchievementProgress = 0;
        uiAchievementTimer = 0;

        bIsAchievementTimerRunning = false;
        bIsWaitingToAppear = false;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetVisibility(VISIBILITY_ON);

        if (pInstance)
            pInstance->SetData(DATA_MAGUS_TELESTRA_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        if (pInstance)
            pInstance->SetData(DATA_MAGUS_TELESTRA_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
        {
            if (IsHeroic() && uiAchievementProgress == 2)
                pInstance->DoCompleteAchievement(ACHIEV_SPLIT_PERSONALITY);
            pInstance->SetData(DATA_MAGUS_TELESTRA_EVENT, DONE);
        }
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(SAY_KILL, me);
    }

    uint64 SplitPersonality(uint32 entry)
    {
        if (Creature* Summoned = me->SummonCreature(entry, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1*IN_MILISECONDS))
        {
            switch (entry)
            {
                case MOB_FIRE_MAGUS:
                {
                    Summoned->CastSpell(Summoned, SPELL_FIRE_MAGUS_VISUAL, false);
                    break;
                }
                case MOB_FROST_MAGUS:
                {
                    Summoned->CastSpell(Summoned, SPELL_FROST_MAGUS_VISUAL, false);
                    break;
                }
                case MOB_ARCANE_MAGUS:
                {
                    Summoned->CastSpell(Summoned, SPELL_ARCANE_MAGUS_VISUAL, false);
                    break;
                }
            }
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                Summoned->AI()->AttackStart(pTarget);
            return Summoned->GetGUID();
        }
        return 0;
    }

    void SummonedCreatureDespawn(Creature *summon)
    {
        if (summon->isAlive())
            return;

        if (summon->GetGUID() == uiFireMagusGUID)
        {
            bFireMagusDead = true;
            bIsAchievementTimerRunning = true;
        }
        else if (summon->GetGUID() == uiFrostMagusGUID)
        {
            bFrostMagusDead = true;
            bIsAchievementTimerRunning = true;
        }
        else if (summon->GetGUID() == uiArcaneMagusGUID)
        {
            bArcaneMagusDead = true;
            bIsAchievementTimerRunning = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (bIsWaitingToAppear)
        {
            me->StopMoving();
            me->AttackStop();
            if (uiIsWaitingToAppearTimer <= diff)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                bIsWaitingToAppear = false;
            } else uiIsWaitingToAppearTimer -= diff;
            return;
        }

        if ((Phase == 1) ||(Phase == 3))
        {
            if (bIsAchievementTimerRunning)
                uiAchievementTimer += diff;
            if (bFireMagusDead && bFrostMagusDead && bArcaneMagusDead)
            {
                if (uiAchievementTimer <= ACHIEV_TIMER)
                    uiAchievementProgress +=1;
                me->GetMotionMaster()->Clear();
                me->GetMap()->CreatureRelocation(me, CenterOfRoom.GetPositionX(), CenterOfRoom.GetPositionY(), CenterOfRoom.GetPositionZ(), CenterOfRoom.GetOrientation());
                DoCast(me, SPELL_TELESTRA_BACK);
                me->SetVisibility(VISIBILITY_ON);
                if (Phase == 1)
                    Phase = 2;
                if (Phase == 3)
                    Phase = 4;
                uiFireMagusGUID = 0;
                uiFrostMagusGUID = 0;
                uiArcaneMagusGUID = 0;
                bIsWaitingToAppear = true;
                uiIsWaitingToAppearTimer = 4*IN_MILISECONDS;
                DoScriptText(SAY_MERGE, me);
                bIsAchievementTimerRunning = false;
                uiAchievementTimer = 0;
            }
            else
                return;
        }

        if ((Phase == 0) && HealthBelowPct(50))
        {
            Phase = 1;
            me->CastStop();
            me->RemoveAllAuras();
            me->SetVisibility(VISIBILITY_OFF);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            uiFireMagusGUID = SplitPersonality(MOB_FIRE_MAGUS);
            uiFrostMagusGUID = SplitPersonality(MOB_FROST_MAGUS);
            uiArcaneMagusGUID = SplitPersonality(MOB_ARCANE_MAGUS);
            bFireMagusDead = false;
            bFrostMagusDead = false;
            bArcaneMagusDead = false;
            DoScriptText(RAND(SAY_SPLIT_1,SAY_SPLIT_2), me);
            return;
        }

        if (IsHeroic() && (Phase == 2) && HealthBelowPct(10))
        {
            Phase = 3;
            me->CastStop();
            me->RemoveAllAuras();
            me->SetVisibility(VISIBILITY_OFF);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            uiFireMagusGUID = SplitPersonality(MOB_FIRE_MAGUS);
            uiFrostMagusGUID = SplitPersonality(MOB_FROST_MAGUS);
            uiArcaneMagusGUID = SplitPersonality(MOB_ARCANE_MAGUS);
            bFireMagusDead = false;
            bFrostMagusDead = false;
            bArcaneMagusDead = false;
            DoScriptText(RAND(SAY_SPLIT_1,SAY_SPLIT_2), me);
            return;
        }

        if (uiCooldown)
        {
            if (uiCooldown <= diff)
                uiCooldown = 0;
            else
            {
                uiCooldown -= diff;
                return;
            }
        }

        if (uiIceNovaTimer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                DoCast(pTarget, SPELL_ICE_NOVA, false);
                uiCooldown = 1.5*IN_MILISECONDS;
            }
            uiIceNovaTimer = 15*IN_MILISECONDS;
        } else uiIceNovaTimer -= diff;

        if (uiGravityWellTimer <= diff)
        {
            if (Unit *pTarget = me->getVictim())
            {
                DoCast(pTarget, SPELL_GRAVITY_WELL);
                uiCooldown = 6*IN_MILISECONDS;
            }
            uiGravityWellTimer = 15*IN_MILISECONDS;
        } else uiGravityWellTimer -= diff;

        if (uiFireBombTimer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                DoCast(pTarget, SPELL_FIREBOMB, false);
                uiCooldown = 2*IN_MILISECONDS;
            }
            uiFireBombTimer = 2*IN_MILISECONDS;
        } else uiFireBombTimer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_magus_telestra(Creature* pCreature)
{
    return new boss_magus_telestraAI (pCreature);
}

void AddSC_boss_magus_telestra()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_magus_telestra";
    newscript->GetAI = &GetAI_boss_magus_telestra;
    newscript->RegisterSelf();
}
