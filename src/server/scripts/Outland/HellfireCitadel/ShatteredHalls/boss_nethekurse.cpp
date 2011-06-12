/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Grand_Warlock_Nethekurse
SD%Complete: 75
SDComment: encounter not fully completed. missing part where boss kill minions.
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_grand_warlock_nethekurse
mob_fel_orc_convert
mob_lesser_shadow_fissure
EndContentData */

#include "ScriptPCH.h"
#include "shattered_halls.h"

struct Say
{
    int32 id;
};

static Say PeonAttacked[]=
{
    {-1540001},
    {-1540002},
    {-1540003},
    {-1540004},
};
static Say PeonDies[]=
{
    {-1540005},
    {-1540006},
    {-1540007},
    {-1540008},
};

enum eSays
{
    SAY_INTRO          = -1540000,
    SAY_TAUNT_1        = -1540009,
    SAY_TAUNT_2        = -1540010,
    SAY_TAUNT_3        = -1540011,
    SAY_AGGRO_1        = -1540012,
    SAY_AGGRO_2        = -1540013,
    SAY_AGGRO_3        = -1540014,
    SAY_SLAY_1         = -1540015,
    SAY_SLAY_2         = -1540016,
    SAY_DIE            = -1540017,
};

enum eSpells
{
    SPELL_DEATH_COIL           = 30500,
    SPELL_DARK_SPIN            = 30502, // core bug spell attack caster :D
    SPELL_SHADOW_FISSURE       = 30496, // Summon the ShadowFissure NPC
    SPELL_SHADOW_CLEAVE        = 30495,
    H_SPELL_SHADOW_SLAM        = 35953,
    SPELL_HEMORRHAGE           = 30478,
    SPELL_CONSUMPTION          = 30497,
    SPELL_TEMPORARY_VISUAL     = 39312, // this is wrong, a temporary solution. spell consumption already has the purple visual, but doesn't display as it should
};

class boss_grand_warlock_nethekurse : public CreatureScript
{
    public:

        boss_grand_warlock_nethekurse()
            : CreatureScript("boss_grand_warlock_nethekurse")
        {
        }

        struct boss_grand_warlock_nethekurseAI : public ScriptedAI
        {
            boss_grand_warlock_nethekurseAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            bool IntroOnce;
            bool IsIntroEvent;
            bool IsMainEvent;
            bool SpinOnce;
            //bool HasTaunted;
            bool Phase;

            uint32 PeonEngagedCount;
            uint32 PeonKilledCount;

            uint32 IntroEvent_Timer;
            uint32 DeathCoil_Timer;
            uint32 ShadowFissure_Timer;
            uint32 Cleave_Timer;

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                IsIntroEvent = false;
                IntroOnce = false;
                IsMainEvent = false;
                //HasTaunted = false;
                SpinOnce = false;
                Phase = false;

                PeonEngagedCount = 0;
                PeonKilledCount = 0;

                IntroEvent_Timer = 90000;                           //how long before getting bored and kills his minions?
                DeathCoil_Timer = 20000;
                ShadowFissure_Timer = 8000;
                Cleave_Timer = 5000;
            }

            void DoYellForPeonAggro()
            {
                if (PeonEngagedCount >= 4)
                    return;

                DoScriptText(PeonAttacked[PeonEngagedCount].id, me);
                ++PeonEngagedCount;
            }

            void DoYellForPeonDeath()
            {
                if (PeonKilledCount >= 4)
                    return;

                DoScriptText(PeonDies[PeonKilledCount].id, me);
                ++PeonKilledCount;

                if (PeonKilledCount == 4)
                {
                    IsIntroEvent = false;
                    IsMainEvent = true;
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            void DoTauntPeons()
            {
                DoScriptText(RAND(SAY_TAUNT_1, SAY_TAUNT_2, SAY_TAUNT_3), me);

                //TODO: kill the peons first
                IsIntroEvent = false;
                PeonEngagedCount = 4;
                PeonKilledCount = 4;
                IsMainEvent = true;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void AttackStart(Unit* who)
            {
                if (IsIntroEvent || !IsMainEvent)
                    return;

                if (me->Attack(who, true))
                {
                    if (Phase)
                        DoStartNoMovement(who);
                    else
                        DoStartMovement(who);
                }
            }

            void MoveInLineOfSight(Unit *who)
            {
                if (!IntroOnce && me->IsWithinDistInMap(who, 50.0f))
                    {
                    if (who->GetTypeId() != TYPEID_PLAYER)
                        return;

                        DoScriptText(SAY_INTRO, me);
                        IntroOnce = true;
                        IsIntroEvent = true;

                        if (pInstance)
                            pInstance->SetData(TYPE_NETHEKURSE, IN_PROGRESS);
                    }

                    if (IsIntroEvent || !IsMainEvent)
                        return;

                    ScriptedAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2, SAY_AGGRO_3), me);
            }

            void JustSummoned(Creature *summoned)
            {
                summoned->setFaction(16);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                //triggered spell of consumption does not properly show it's SpellVisual, wrong spellid?
                summoned->CastSpell(summoned, SPELL_TEMPORARY_VISUAL, true);
                summoned->CastSpell(summoned, SPELL_CONSUMPTION, false, 0, 0, me->GetGUID());
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DIE, me);

                if (!pInstance)
                    return;

                pInstance->SetData(TYPE_NETHEKURSE, DONE);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_NETHEKURSE_DOOR), true);
            }

            void UpdateAI(const uint32 diff)
            {
                if (IsIntroEvent)
                {
                    if (!pInstance)
                        return;

                    if (pInstance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS)
                    {
                        if (IntroEvent_Timer <= diff)
                            DoTauntPeons();
                        else
                            IntroEvent_Timer -= diff;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (!IsMainEvent)
                    return;

                if (Phase)
                {
                    if (!SpinOnce)
                    {
                        DoCast(me->getVictim(), SPELL_DARK_SPIN);
                        SpinOnce = true;
                    }

                    if (Cleave_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_SHADOW_CLEAVE);
                        Cleave_Timer = 6000+rand()%2500;
                    }
                    else
                        Cleave_Timer -= diff;
                }
                else
                {
                    if (ShadowFissure_Timer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_SHADOW_FISSURE);
                        ShadowFissure_Timer = urand(7500, 15000);
                    }
                    else
                        ShadowFissure_Timer -= diff;

                    if (DeathCoil_Timer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_DEATH_COIL);
                        DeathCoil_Timer = urand(15000, 20000);
                    }
                    else
                        DeathCoil_Timer -= diff;

                    if (!HealthAbovePct(20))
                        Phase = true;

                    DoMeleeAttackIfReady();
                }
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_grand_warlock_nethekurseAI (Creature);
        }
};

class mob_fel_orc_convert : public CreatureScript
{
    public:

        mob_fel_orc_convert()
            : CreatureScript("mob_fel_orc_convert")
        {
        }

        struct mob_fel_orc_convertAI : public ScriptedAI
        {
            mob_fel_orc_convertAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 Hemorrhage_Timer;

            void Reset()
            {
                me->SetNoCallAssistance(true);              //we don't want any assistance (WE R HEROZ!)
                Hemorrhage_Timer = 3000;
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (pInstance)
                {
                    if (pInstance->GetData64(DATA_NETHEKURSE))
                    {
                        Creature *pKurse = Unit::GetCreature(*me, pInstance->GetData64(DATA_NETHEKURSE));
                        if (pKurse && me->IsWithinDist(pKurse, 45.0f))
                        {
                            CAST_AI(boss_grand_warlock_nethekurse::boss_grand_warlock_nethekurseAI, pKurse->AI())->DoYellForPeonAggro();

                            if (pInstance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS)
                                return;
                            else
                                pInstance->SetData(TYPE_NETHEKURSE, IN_PROGRESS);
                        }
                    }
                }
            }

            void JustDied(Unit* /*Killer*/)
            {
                if (pInstance)
                {
                    if (pInstance->GetData(TYPE_NETHEKURSE) != IN_PROGRESS)
                        return;
                    if (pInstance->GetData64(DATA_NETHEKURSE))
                        if (Creature *pKurse = Unit::GetCreature(*me, pInstance->GetData64(DATA_NETHEKURSE)))
                            CAST_AI(boss_grand_warlock_nethekurse::boss_grand_warlock_nethekurseAI, pKurse->AI())->DoYellForPeonDeath();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (Hemorrhage_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_HEMORRHAGE);
                    Hemorrhage_Timer = 15000;
                } else Hemorrhage_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_fel_orc_convertAI (Creature);
        }
};

//NOTE: this Creature are also summoned by other spells, for different creatures
class mob_lesser_shadow_fissure : public CreatureScript
{
    public:

        mob_lesser_shadow_fissure()
            : CreatureScript("mob_lesser_shadow_fissure")
        {
        }

        struct mob_lesser_shadow_fissureAI : public ScriptedAI
        {
            mob_lesser_shadow_fissureAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void Reset() { }
            void MoveInLineOfSight(Unit* /*who*/) {}
            void AttackStart(Unit* /*who*/) {}
            void EnterCombat(Unit* /*who*/) {}
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new mob_lesser_shadow_fissureAI (pCreature);
        }
};

void AddSC_boss_grand_warlock_nethekurse()
{
    new boss_grand_warlock_nethekurse();
    new mob_fel_orc_convert();
    new mob_lesser_shadow_fissure();
}

