/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Eredar_Twins
SD%Complete: 100
SDComment:
EndScriptData */

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

enum Quotes
{
    //Alytesh
    YELL_CANFLAGRATION          =   -1580044,
    YELL_SISTER_SACROLASH_DEAD  =   -1580045,
    YELL_ALY_KILL_1             =   -1580046,
    YELL_ALY_KILL_2             =   -1580047,
    YELL_ALY_DEAD               =   -1580048,
    YELL_BERSERK                =   -1580049,

    //Sacrolash
    YELL_SHADOW_NOVA            =   -1580050,
    YELL_SISTER_ALYTHESS_DEAD   =   -1580051,
    YELL_SAC_KILL_1             =   -1580052,
    YELL_SAC_KILL_2             =   -1580053,
    SAY_SAC_DEAD                =   -1580054,
    YELL_ENRAGE                 =   -1580055,

    //Intro
    YELL_INTRO_SAC_1            =   -1580056,
    YELL_INTRO_ALY_2            =   -1580057,
    YELL_INTRO_SAC_3            =   -1580058,
    YELL_INTRO_ALY_4            =   -1580059,
    YELL_INTRO_SAC_5            =   -1580060,
    YELL_INTRO_ALY_6            =   -1580061,
    YELL_INTRO_SAC_7            =   -1580062,
    YELL_INTRO_ALY_8            =   -1580063,

    //Emote
    EMOTE_SHADOW_NOVA           =   -1580064,
    EMOTE_CONFLAGRATION         =   -1580065
};

enum Spells
{
    //Lady Sacrolash spells
    SPELL_DARK_TOUCHED      =   45347,
    SPELL_SHADOW_BLADES     =   45248, //10 secs
    SPELL_DARK_STRIKE       =   45271,
    SPELL_SHADOW_NOVA       =   45329, //30-35 secs
    SPELL_CONFOUNDING_BLOW  =   45256, //25 secs

    //Shadow Image spells
    SPELL_SHADOW_FURY       =   45270,
    SPELL_IMAGE_VISUAL      =   45263,

    //Misc spells
    SPELL_ENRAGE            =   46587,
    SPELL_EMPOWER           =   45366,
    SPELL_DARK_FLAME        =   45345,

    //Grand Warlock Alythess spells
    SPELL_PYROGENICS        =   45230, //15secs
    SPELL_FLAME_TOUCHED     =   45348,
    SPELL_CONFLAGRATION     =   45342, //30-35 secs
    SPELL_BLAZE             =   45235, //on main target every 3 secs
    SPELL_FLAME_SEAR        =   46771,
    SPELL_BLAZE_SUMMON      =   45236, //187366 GO
    SPELL_BLAZE_BURN        =   45246
};

class boss_sacrolash : public CreatureScript
{
public:
    boss_sacrolash() : CreatureScript("boss_sacrolash") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sacrolashAI (pCreature);
    };

    struct boss_sacrolashAI : public ScriptedAI
    {
        boss_sacrolashAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        bool SisterDeath;
        bool Enraged;

        uint32 ShadowbladesTimer;
        uint32 ShadownovaTimer;
        uint32 ConfoundingblowTimer;
        uint32 ShadowimageTimer;
        uint32 ConflagrationTimer;
        uint32 EnrageTimer;

        void Reset()
        {
            Enraged = false;

            if (pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me), pInstance->GetData64(DATA_ALYTHESS));
                if (Temp)
                {
                    if (Temp->isDead())
                        CAST_CRE(Temp)->Respawn();
                    else if (Temp->getVictim())
                        me->getThreatManager().addThreat(Temp->getVictim(), 0.0f);
                }
            }

            if (!me->isInCombat())
            {
                ShadowbladesTimer = 10000;
                ShadownovaTimer = 30000;
                ConfoundingblowTimer = 25000;
                ShadowimageTimer = 20000;
                ConflagrationTimer = 30000;
                EnrageTimer = 360000;

                SisterDeath = false;
            }

            if (pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit * who)
        {
            DoZoneInCombat();

            if (pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me), pInstance->GetData64(DATA_ALYTHESS));
                if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                    CAST_CRE(Temp)->AI()->AttackStart(who);
            }

            if (pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            if (rand()%4 == 0)
                DoScriptText(RAND(YELL_SAC_KILL_1, YELL_SAC_KILL_2), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            // only if ALY death
            if (SisterDeath)
            {
                DoScriptText(SAY_SAC_DEAD, me);

                if (pInstance)
                    pInstance->SetData(DATA_EREDAR_TWINS_EVENT, DONE);
            }
            else
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry* spell)
        {
            switch(spell->Id)
            {
            case SPELL_SHADOW_BLADES:
            case SPELL_SHADOW_NOVA:
            case SPELL_CONFOUNDING_BLOW:
            case SPELL_SHADOW_FURY:
                HandleTouchedSpells(pTarget, SPELL_DARK_TOUCHED);
                break;
            case SPELL_CONFLAGRATION:
                HandleTouchedSpells(pTarget, SPELL_FLAME_TOUCHED);
                break;
            }
        }

        void HandleTouchedSpells(Unit *pTarget, uint32 TouchedType)
        {
            switch(TouchedType)
            {
            case SPELL_FLAME_TOUCHED:
                if (!pTarget->HasAura(SPELL_DARK_FLAME))
                {
                    if (pTarget->HasAura(SPELL_DARK_TOUCHED))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                        pTarget->CastSpell(pTarget, SPELL_DARK_FLAME, true);
                    } else pTarget->CastSpell(pTarget, SPELL_FLAME_TOUCHED, true);
                }
                break;
            case SPELL_DARK_TOUCHED:
                if (!pTarget->HasAura(SPELL_DARK_FLAME))
                {
                    if (pTarget->HasAura(SPELL_FLAME_TOUCHED))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                        pTarget->CastSpell(pTarget, SPELL_DARK_FLAME, true);
                    } else pTarget->CastSpell(pTarget, SPELL_DARK_TOUCHED, true);
                }
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!SisterDeath)
            {
                if (pInstance)
                {
                    Unit* Temp = NULL;
                    Temp = Unit::GetUnit((*me), pInstance->GetData64(DATA_ALYTHESS));
                    if (Temp && Temp->isDead())
                    {
                        DoScriptText(YELL_SISTER_ALYTHESS_DEAD, me);
                        DoCast(me, SPELL_EMPOWER);
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        SisterDeath = true;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            if (SisterDeath)
            {
                if (ConflagrationTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        Unit *pTarget = NULL;
                        pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (pTarget)
                            DoCast(pTarget, SPELL_CONFLAGRATION);
                        ConflagrationTimer = 30000+(rand()%5000);
                    }
                } else ConflagrationTimer -= diff;
            }
            else
            {
                if (ShadownovaTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        Unit *pTarget = NULL;
                        pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (pTarget)
                            DoCast(pTarget, SPELL_SHADOW_NOVA);

                        if (!SisterDeath)
                        {
                            if (pTarget)
                                DoScriptText(EMOTE_SHADOW_NOVA, me, pTarget);
                            DoScriptText(YELL_SHADOW_NOVA, me);
                        }
                        ShadownovaTimer = 30000+(rand()%5000);
                    }
                } else ShadownovaTimer -=diff;
            }

            if (ConfoundingblowTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    Unit *pTarget = NULL;
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (pTarget)
                        DoCast(pTarget, SPELL_CONFOUNDING_BLOW);
                    ConfoundingblowTimer = 20000 + (rand()%5000);
                }
            } else ConfoundingblowTimer -=diff;

            if (ShadowimageTimer <= diff)
            {
                Unit *pTarget = NULL;
                Creature* temp = NULL;
                for (uint8 i = 0; i<3; ++i)
                {
                    pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    temp = DoSpawnCreature(MOB_SHADOW_IMAGE, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 10000);
                    if (temp && pTarget)
                    {
                        temp->AddThreat(pTarget, 1000000);//don't change target(healers)
                        temp->AI()->AttackStart(pTarget);
                    }
                }
                ShadowimageTimer = 20000;
            } else ShadowimageTimer -=diff;

            if (ShadowbladesTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me, SPELL_SHADOW_BLADES);
                    ShadowbladesTimer = 10000;
                }
            } else ShadowbladesTimer -=diff;

            if (EnrageTimer < diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                DoScriptText(YELL_ENRAGE, me);
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            } else EnrageTimer -= diff;

            if (me->isAttackReady() && !me->IsNonMeleeSpellCasted(false))
            {
                //If we are within range melee the target
                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    HandleTouchedSpells(me->getVictim(), SPELL_DARK_TOUCHED);
                    me->AttackerStateUpdate(me->getVictim());
                    me->resetAttackTimer();
                }
            }
        }
    };

};

class boss_alythess : public CreatureScript
{
public:
    boss_alythess() : CreatureScript("boss_alythess") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_alythessAI (pCreature);
    };

    struct boss_alythessAI : public Scripted_NoMovementAI
    {
        boss_alythessAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            pInstance = c->GetInstanceScript();
            IntroStepCounter = 10;
        }

        InstanceScript *pInstance;

        bool SisterDeath;
        bool Enraged;

        uint32 IntroStepCounter;
        uint32 IntroYellTimer;

        uint32 ConflagrationTimer;
        uint32 BlazeTimer;
        uint32 PyrogenicsTimer;
        uint32 ShadownovaTimer;
        uint32 FlamesearTimer;
        uint32 EnrageTimer;

        void Reset()
        {
            Enraged = false;

            if (pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me), pInstance->GetData64(DATA_SACROLASH));
                if (Temp)
                {
                    if (Temp->isDead())
                        CAST_CRE(Temp)->Respawn();
                    else if (Temp->getVictim())
                        me->getThreatManager().addThreat(Temp->getVictim(), 0.0f);
                }
            }

            if (!me->isInCombat())
            {
                ConflagrationTimer = 45000;
                BlazeTimer = 100;
                PyrogenicsTimer = 15000;
                ShadownovaTimer = 40000;
                EnrageTimer = 360000;
                FlamesearTimer = 15000;
                IntroYellTimer = 10000;

                SisterDeath = false;
            }

            if (pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit * who)
        {
            DoZoneInCombat();

            if (pInstance)
            {
                Unit* Temp =  Unit::GetUnit((*me), pInstance->GetData64(DATA_SACROLASH));
                if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                    CAST_CRE(Temp)->AI()->AttackStart(who);
            }

            if (pInstance)
                pInstance->SetData(DATA_EREDAR_TWINS_EVENT, IN_PROGRESS);
        }

        void AttackStart(Unit *who)
        {
            if (!me->isInCombat())
            {
                Scripted_NoMovementAI::AttackStart(who);
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || me->getVictim())
                return;

            if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me) && me->IsHostileTo(who))
            {

                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && me->IsWithinLOSInMap(who))
                {
                    if (!me->isInCombat())
                    {
                        DoStartNoMovement(who);
                    }
                }
            }
            else if (IntroStepCounter == 10 && me->IsWithinLOSInMap(who)&& me->IsWithinDistInMap(who, 30))
            {
                IntroStepCounter = 0;
            }
        }

        void KilledUnit(Unit * /*victim*/)
        {
            if (rand()%4 == 0)
            {
                DoScriptText(RAND(YELL_ALY_KILL_1, YELL_ALY_KILL_2), me);
            }
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (SisterDeath)
            {
                DoScriptText(YELL_ALY_DEAD, me);

                if (pInstance)
                    pInstance->SetData(DATA_EREDAR_TWINS_EVENT, DONE);
            }
            else
                me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit *pTarget, const SpellEntry* spell)
        {
            switch(spell->Id)
            {

            case SPELL_BLAZE:
                pTarget->CastSpell(pTarget, SPELL_BLAZE_SUMMON, true);
            case SPELL_CONFLAGRATION:
            case SPELL_FLAME_SEAR:
                HandleTouchedSpells(pTarget, SPELL_FLAME_TOUCHED);
                break;
            case SPELL_SHADOW_NOVA:
                HandleTouchedSpells(pTarget, SPELL_DARK_TOUCHED);
                break;
            }
        }

        void HandleTouchedSpells(Unit *pTarget, uint32 TouchedType)
        {
            switch(TouchedType)
            {
            case SPELL_FLAME_TOUCHED:
                if (!pTarget->HasAura(SPELL_DARK_FLAME))
                {
                    if (pTarget->HasAura(SPELL_DARK_TOUCHED))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                        pTarget->CastSpell(pTarget, SPELL_DARK_FLAME, true);
                    }else
                    {
                        pTarget->CastSpell(pTarget, SPELL_FLAME_TOUCHED, true);
                    }
                }
                break;
            case SPELL_DARK_TOUCHED:
                if (!pTarget->HasAura(SPELL_DARK_FLAME))
                {
                    if (pTarget->HasAura(SPELL_FLAME_TOUCHED))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                        pTarget->CastSpell(pTarget, SPELL_DARK_FLAME, true);
                    } else pTarget->CastSpell(pTarget, SPELL_DARK_TOUCHED, true);
                }
                break;
            }
        }

        uint32 IntroStep(uint32 step)
        {
            Creature* Sacrolash = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_SACROLASH) : 0);
            switch (step)
            {
            case 0: return 0;
            case 1:
                if (Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_1, Sacrolash);
                return 1000;
            case 2: DoScriptText(YELL_INTRO_ALY_2, me); return 1000;
            case 3:
                if (Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_3, Sacrolash);
                return 2000;
            case 4: DoScriptText(YELL_INTRO_ALY_4, me); return 1000;
            case 5:
                if (Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_5, Sacrolash);
                return 2000;
            case 6: DoScriptText(YELL_INTRO_ALY_6, me); return 1000;
            case 7:
                if (Sacrolash)
                    DoScriptText(YELL_INTRO_SAC_7, Sacrolash);
                return 3000;
            case 8: DoScriptText(YELL_INTRO_ALY_8, me); return 900000;
            }
            return 10000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroStepCounter < 9)
            {
                if (IntroYellTimer <= diff)
                {
                    IntroYellTimer = IntroStep(++IntroStepCounter);
                } else IntroYellTimer -= diff;
            }

            if (!SisterDeath)
            {
                if (pInstance)
                {
                    Unit* Temp = NULL;
                    Temp = Unit::GetUnit((*me), pInstance->GetData64(DATA_SACROLASH));
                    if (Temp && Temp->isDead())
                    {
                        DoScriptText(YELL_SISTER_SACROLASH_DEAD, me);
                        DoCast(me, SPELL_EMPOWER);
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        SisterDeath = true;
                    }
                }
            }
            if (!me->getVictim())
            {
                if (pInstance)
                {
                    Creature* sisiter = Unit::GetCreature((*me), pInstance->GetData64(DATA_SACROLASH));
                    if (sisiter && !sisiter->isDead() && sisiter->getVictim())
                    {
                        me->AddThreat(sisiter->getVictim(), 0.0f);
                        DoStartNoMovement(sisiter->getVictim());
                        me->Attack(sisiter->getVictim(), false);
                    }
                }
            }

            if (!UpdateVictim())
                return;

            if (SisterDeath)
            {
                if (ShadownovaTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        Unit *pTarget = NULL;
                        pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (pTarget)
                            DoCast(pTarget, SPELL_SHADOW_NOVA);
                        ShadownovaTimer= 30000+(rand()%5000);
                    }
                } else ShadownovaTimer -=diff;
            }
            else
            {
                if (ConflagrationTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        Unit *pTarget = NULL;
                        pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (pTarget)
                            DoCast(pTarget, SPELL_CONFLAGRATION);
                        ConflagrationTimer = 30000+(rand()%5000);

                        if (!SisterDeath)
                        {
                            if (pTarget)
                                DoScriptText(EMOTE_CONFLAGRATION, me, pTarget);
                            DoScriptText(YELL_CANFLAGRATION, me);
                        }

                        BlazeTimer = 4000;
                    }
                } else ConflagrationTimer -= diff;
            }

            if (FlamesearTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me, SPELL_FLAME_SEAR);
                    FlamesearTimer = 15000;
                }
            } else FlamesearTimer -=diff;

            if (PyrogenicsTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me, SPELL_PYROGENICS, true);
                    PyrogenicsTimer = 15000;
                }
            } else PyrogenicsTimer -= diff;

            if (BlazeTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(me->getVictim(), SPELL_BLAZE);
                    BlazeTimer = 3800;
                }
            } else BlazeTimer -= diff;

            if (EnrageTimer < diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                DoScriptText(YELL_BERSERK, me);
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            } else EnrageTimer -= diff;
        }
    };

};

class mob_shadow_image : public CreatureScript
{
public:
    mob_shadow_image() : CreatureScript("mob_shadow_image") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_shadow_imageAI (pCreature);
    };

    struct mob_shadow_imageAI : public ScriptedAI
    {
        mob_shadow_imageAI(Creature *c) : ScriptedAI(c) {}

        uint32 ShadowfuryTimer;
        uint32 KillTimer;
        uint32 DarkstrikeTimer;

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            ShadowfuryTimer = 5000 + (rand()%15000);
            DarkstrikeTimer = 3000;
            KillTimer = 15000;
        }

        void EnterCombat(Unit * /*who*/){}

        void SpellHitTarget(Unit *pTarget, const SpellEntry* spell)
        {
            switch(spell->Id)
            {

            case SPELL_SHADOW_FURY:
            case SPELL_DARK_STRIKE:
                if (!pTarget->HasAura(SPELL_DARK_FLAME))
                {
                    if (pTarget->HasAura(SPELL_FLAME_TOUCHED))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                        pTarget->CastSpell(pTarget, SPELL_DARK_FLAME, true);
                    } else pTarget->CastSpell(pTarget, SPELL_DARK_TOUCHED, true);
                }
                break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->HasAura(SPELL_IMAGE_VISUAL))
                DoCast(me, SPELL_IMAGE_VISUAL);

            if (KillTimer <= diff)
            {
                me->Kill(me);
                KillTimer = 9999999;
            } else KillTimer -= diff;

            if (!UpdateVictim())
                return;

            if (ShadowfuryTimer <= diff)
            {
                DoCast(me, SPELL_SHADOW_FURY);
                ShadowfuryTimer = 10000;
            } else ShadowfuryTimer -=diff;

            if (DarkstrikeTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    //If we are within range melee the target
                    if (me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(me->getVictim(), SPELL_DARK_STRIKE);
                }
                DarkstrikeTimer = 3000;
            } else DarkstrikeTimer -= diff;
        }
    };

};

void AddSC_boss_eredar_twins()
{
    new boss_sacrolash();
    new boss_alythess();
    new mob_shadow_image();
}
