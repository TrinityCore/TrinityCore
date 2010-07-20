/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: boss_Halazzi
SD%Complete: 80
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "ScriptPCH.h"
#include "zulaman.h"
//#include "spell.h"

#define YELL_AGGRO "Get on your knees and bow to da fang and claw!"
#define SOUND_AGGRO                    12020
#define YELL_SABER_ONE "You gonna leave in pieces!"
#define YELL_SABER_TWO "Me gonna carve ya now!"
#define YELL_SPLIT "Me gonna carve ya now!"
#define SOUND_SPLIT                    12021
#define YELL_MERGE "Spirit, come back to me!"
#define SOUND_MERGE                    12022
#define YELL_KILL_ONE "You cant fight the power!"
#define SOUND_KILL_ONE                12026
#define YELL_KILL_TWO "You gonna fail!"
#define SOUND_KILL_TWO                12027
#define YELL_DEATH "Chaga... choka'jinn."
#define SOUND_DEATH                    12028
#define YELL_BERSERK "Whatch you be doing? Pissin' yourselves..."
#define SOUND_BERSERK                12025

#define SPELL_DUAL_WIELD                29651
#define SPELL_SABER_LASH                43267
#define SPELL_FRENZY                    43139
#define SPELL_FLAMESHOCK                43303
#define SPELL_EARTHSHOCK                43305
#define SPELL_TRANSFORM_SPLIT           43142
#define SPELL_TRANSFORM_SPLIT2          43573
#define SPELL_TRANSFORM_MERGE           43271
#define SPELL_SUMMON_LYNX               43143
#define SPELL_SUMMON_TOTEM              43302
#define SPELL_BERSERK                   45078

#define MOB_SPIRIT_LYNX                 24143
#define SPELL_LYNX_FRENZY               43290
#define SPELL_SHRED_ARMOR               43243

#define MOB_TOTEM                       24224
#define SPELL_LIGHTNING                 43301

enum PhaseHalazzi
{
    PHASE_NONE = 0,
    PHASE_LYNX = 1,
    PHASE_SPLIT = 2,
    PHASE_HUMAN = 3,
    PHASE_MERGE = 4,
    PHASE_ENRAGE = 5
};

struct boss_halazziAI : public ScriptedAI
{
    boss_halazziAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        // need to find out what controls totem's spell cooldown
        SpellEntry *TempSpell = GET_SPELL(SPELL_LIGHTNING);
        if (TempSpell && TempSpell->CastingTimeIndex != 5)
            TempSpell->CastingTimeIndex = 5; // 2000 ms casting time
    }

    ScriptedInstance *pInstance;

    uint32 FrenzyTimer;
    uint32 SaberlashTimer;
    uint32 ShockTimer;
    uint32 TotemTimer;
    uint32 CheckTimer;
    uint32 BerserkTimer;

    uint32 TransformCount;

    PhaseHalazzi Phase;

    uint64 LynxGUID;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_HALAZZIEVENT, NOT_STARTED);

        TransformCount = 0;
        BerserkTimer = 600000;
        CheckTimer = 1000;

        DoCast(me, SPELL_DUAL_WIELD, true);

        Phase = PHASE_NONE;
        EnterPhase(PHASE_LYNX);
    }

    void EnterCombat(Unit * /*who*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_HALAZZIEVENT, IN_PROGRESS);

        me->MonsterYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(me, SOUND_AGGRO);

        EnterPhase(PHASE_LYNX);
    }

    void JustSummoned(Creature* summon)
    {
        summon->AI()->AttackStart(me->getVictim());
        if (summon->GetEntry() == MOB_SPIRIT_LYNX)
            LynxGUID = summon->GetGUID();
    }

    void DamageTaken(Unit * /*done_by*/, uint32 &damage)
    {
        if (damage >= me->GetHealth() && Phase != PHASE_ENRAGE)
            damage = 0;
    }

    void SpellHit(Unit*, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_TRANSFORM_SPLIT2)
            EnterPhase(PHASE_HUMAN);
    }

    void AttackStart(Unit *who)
    {
        if (Phase != PHASE_MERGE) ScriptedAI::AttackStart(who);
    }

    void EnterPhase(PhaseHalazzi NextPhase)
    {
        switch(NextPhase)
        {
        case PHASE_LYNX:
        case PHASE_ENRAGE:
            if (Phase == PHASE_MERGE)
            {
                DoCast(me, SPELL_TRANSFORM_MERGE, true);
                me->Attack(me->getVictim(), true);
                me->GetMotionMaster()->MoveChase(me->getVictim());
            }
            if (Creature *Lynx = Unit::GetCreature(*me, LynxGUID))
                Lynx->DisappearAndDie();
            me->SetMaxHealth(600000);
            me->SetHealth(600000 - 150000 * TransformCount);
            FrenzyTimer = 16000;
            SaberlashTimer = 20000;
            ShockTimer = 10000;
            TotemTimer = 12000;
            break;
        case PHASE_SPLIT:
            me->MonsterYell(YELL_SPLIT, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(me, SOUND_SPLIT);
            DoCast(me, SPELL_TRANSFORM_SPLIT, true);
            break;
        case PHASE_HUMAN:
            //DoCast(me, SPELL_SUMMON_LYNX, true);
            DoSpawnCreature(MOB_SPIRIT_LYNX, 5,5,0,0, TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SetMaxHealth(400000);
            me->SetHealth(400000);
            ShockTimer = 10000;
            TotemTimer = 12000;
            break;
        case PHASE_MERGE:
            if (Unit *pLynx = Unit::GetUnit(*me, LynxGUID))
            {
                me->MonsterYell(YELL_MERGE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_MERGE);
                pLynx->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pLynx->GetMotionMaster()->Clear();
                pLynx->GetMotionMaster()->MoveFollow(me, 0, 0);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(pLynx, 0, 0);
                ++TransformCount;
            }
            break;
        default:
            break;
        }
        Phase = NextPhase;
    }

     void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (BerserkTimer <= diff)
        {
            me->MonsterYell(YELL_BERSERK, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(me, SOUND_BERSERK);
            DoCast(me, SPELL_BERSERK, true);
            BerserkTimer = 60000;
        } else BerserkTimer -= diff;

        if (Phase == PHASE_LYNX || Phase == PHASE_ENRAGE)
        {
            if (SaberlashTimer <= diff)
            {
                // A tank with more than 490 defense skills should receive no critical hit
                //DoCast(me, 41296, true);
                DoCast(me->getVictim(), SPELL_SABER_LASH, true);
                //me->RemoveAurasDueToSpell(41296);
                SaberlashTimer = 30000;
            } else SaberlashTimer -= diff;

            if (FrenzyTimer <= diff)
            {
                DoCast(me, SPELL_FRENZY);
                FrenzyTimer = urand(10000,15000);
            } else FrenzyTimer -= diff;

            if (Phase == PHASE_LYNX)
                if (CheckTimer <= diff)
                {
                    if (me->GetHealth() * 4 < me->GetMaxHealth() * (3 - TransformCount))
                        EnterPhase(PHASE_SPLIT);
                    CheckTimer = 1000;
                } else CheckTimer -= diff;
        }

        if (Phase == PHASE_HUMAN || Phase == PHASE_ENRAGE)
        {
            if (TotemTimer <= diff)
            {
                DoCast(me, SPELL_SUMMON_TOTEM);
                TotemTimer = 20000;
            } else TotemTimer -= diff;

            if (ShockTimer <= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                {
                    if (pTarget->IsNonMeleeSpellCasted(false))
                        DoCast(pTarget, SPELL_EARTHSHOCK);
                    else
                        DoCast(pTarget, SPELL_FLAMESHOCK);
                    ShockTimer = 10000 + rand()%5000;
                }
            } else ShockTimer -= diff;

            if (Phase == PHASE_HUMAN)
                if (CheckTimer <= diff)
                {
                    if (((me->GetHealth()*100) / me->GetMaxHealth() <= 20)/*me->GetHealth() * 10 < me->GetMaxHealth()*/)
                        EnterPhase(PHASE_MERGE);
                    else
                    {
                        Unit *Lynx = Unit::GetUnit(*me, LynxGUID);
                        if (Lynx && ((Lynx->GetHealth()*100) / Lynx->GetMaxHealth() <= 20)/*Lynx->GetHealth() * 10 < Lynx->GetMaxHealth()*/)
                            EnterPhase(PHASE_MERGE);
                    }
                    CheckTimer = 1000;
                } else CheckTimer -= diff;
        }

        if (Phase == PHASE_MERGE)
        {
            if (CheckTimer <= diff)
            {
                Unit *Lynx = Unit::GetUnit(*me, LynxGUID);
                if (Lynx)
                {
                    Lynx->GetMotionMaster()->MoveFollow(me, 0, 0);
                    me->GetMotionMaster()->MoveFollow(Lynx, 0, 0);
                    if (me->IsWithinDistInMap(Lynx, 6.0f))
                    {
                        if (TransformCount < 3)
                            EnterPhase(PHASE_LYNX);
                        else
                            EnterPhase(PHASE_ENRAGE);
                    }
                }
                CheckTimer = 1000;
            } else CheckTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void KilledUnit(Unit* /*victim*/)
    {
        switch (urand(0,1))
        {
            case 0:
                me->MonsterYell(YELL_KILL_ONE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_KILL_ONE);
                break;

            case 1:
                me->MonsterYell(YELL_KILL_TWO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_KILL_TWO);
                break;
        }
    }

    void JustDied(Unit* /*Killer*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_HALAZZIEVENT, DONE);

        me->MonsterYell(YELL_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(me, SOUND_DEATH);
    }
};

// Spirits Lynx AI

struct boss_spiritlynxAI : public ScriptedAI
{
    boss_spiritlynxAI(Creature *c) : ScriptedAI(c) {}

    uint32 FrenzyTimer;
    uint32 shredder_timer;

    void Reset()
    {
        FrenzyTimer = urand(30000,50000);  //frenzy every 30-50 seconds
        shredder_timer = 4000;
    }

    void DamageTaken(Unit * /*done_by*/, uint32 &damage)
    {
        if (damage >= me->GetHealth())
            damage = 0;
    }

    void AttackStart(Unit *who)
    {
        if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            ScriptedAI::AttackStart(who);
    }

    void EnterCombat(Unit * /*who*/) {/*DoZoneInCombat();*/}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (FrenzyTimer <= diff)
        {
            DoCast(me, SPELL_LYNX_FRENZY);
            FrenzyTimer = urand(30000,50000);  //frenzy every 30-50 seconds
        } else FrenzyTimer -= diff;

        if (shredder_timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SHRED_ARMOR);
            shredder_timer = 4000;
        } else shredder_timer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_halazziAI(Creature* pCreature)
{
    return new boss_halazziAI (pCreature);
}

CreatureAI* GetAI_boss_spiritlynxAI(Creature* pCreature)
{
    return new boss_spiritlynxAI (pCreature);
}

void AddSC_boss_halazzi()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_halazzi";
    newscript->GetAI = &GetAI_boss_halazziAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_halazzi_lynx";
    newscript->GetAI = &GetAI_boss_spiritlynxAI;
    newscript->RegisterSelf();
}

