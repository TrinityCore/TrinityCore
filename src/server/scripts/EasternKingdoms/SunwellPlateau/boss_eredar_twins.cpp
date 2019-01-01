/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "sunwell_plateau.h"

enum Quotes
{
    YELL_INTRO_SAC_1            = 0,
    YELL_INTRO_SAC_3            = 1,
    YELL_INTRO_SAC_5            = 2,
    YELL_INTRO_SAC_7            = 3,
    YELL_SAC_DEAD               = 4,
    EMOTE_SHADOW_NOVA           = 5,
    YELL_ENRAGE                 = 6,
    YELL_SISTER_ALYTHESS_DEAD   = 7,
    YELL_SAC_KILL               = 8,
    YELL_SHADOW_NOVA            = 9,

    YELL_INTRO_ALY_2            = 0,
    YELL_INTRO_ALY_4            = 1,
    YELL_INTRO_ALY_6            = 2,
    YELL_INTRO_ALY_8            = 3,
    EMOTE_CONFLAGRATION         = 4,
    YELL_ALY_KILL               = 5,
    YELL_ALY_DEAD               = 6,
    YELL_SISTER_SACROLASH_DEAD  = 7,
    YELL_CANFLAGRATION          = 8,
    YELL_BERSERK                = 9
};

enum Spells
{
    //Lady Sacrolash spells
    SPELL_DARK_TOUCHED          = 45347,
    SPELL_SHADOW_BLADES         = 45248, //10 secs
    SPELL_DARK_STRIKE           = 45271,
    SPELL_SHADOW_NOVA           = 45329, //30-35 secs
    SPELL_CONFOUNDING_BLOW      = 45256, //25 secs

    //Shadow Image spells
    SPELL_SHADOW_FURY           = 45270,
    SPELL_IMAGE_VISUAL          = 45263,

    //Misc spells
    SPELL_ENRAGE                = 46587,
    SPELL_EMPOWER               = 45366,
    SPELL_DARK_FLAME            = 45345,

    //Grand Warlock Alythess spells
    SPELL_PYROGENICS            = 45230, //15secs
    SPELL_FLAME_TOUCHED         = 45348,
    SPELL_CONFLAGRATION         = 45342, //30-35 secs
    SPELL_BLAZE                 = 45235, //on main target every 3 secs
    SPELL_FLAME_SEAR            = 46771,
    SPELL_BLAZE_SUMMON          = 45236, //187366 GO
    SPELL_BLAZE_BURN            = 45246
};

class boss_sacrolash : public CreatureScript
{
public:
    boss_sacrolash() : CreatureScript("boss_sacrolash") { }

    struct boss_sacrolashAI : public ScriptedAI
    {
        boss_sacrolashAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            ShadowbladesTimer = 10000;
            ShadownovaTimer = 30000;
            ConfoundingblowTimer = 25000;
            ShadowimageTimer = 20000;
            ConflagrationTimer = 30000;
            EnrageTimer = 360000;
            SisterDeath = false;
            Enraged = false;
        }

        InstanceScript* instance;

        bool SisterDeath;
        bool Enraged;

        uint32 ShadowbladesTimer;
        uint32 ShadownovaTimer;
        uint32 ConfoundingblowTimer;
        uint32 ShadowimageTimer;
        uint32 ConflagrationTimer;
        uint32 EnrageTimer;

        void Reset() override
        {
            Enraged = false;

            if (Creature* temp =  ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALYTHESS)))
            {
                if (temp->isDead())
                    temp->Respawn();
                else if (temp->GetVictim())
                    me->getThreatManager().addThreat(temp->GetVictim(), 0.0f);
            }

            if (!me->IsInCombat())
            {
                Initialize();
            }

            instance->SetBossState(DATA_EREDAR_TWINS, NOT_STARTED);
        }

        void EnterCombat(Unit* who) override
        {
            DoZoneInCombat();

            Creature* temp = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ALYTHESS));
            if (temp && temp->IsAlive() && !temp->GetVictim())
                temp->AI()->AttackStart(who);

            instance->SetBossState(DATA_EREDAR_TWINS, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (rand32() % 4 == 0)
                Talk(YELL_SAC_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            // only if ALY death
            if (SisterDeath)
            {
                Talk(YELL_SAC_DEAD);

                instance->SetBossState(DATA_EREDAR_TWINS, DONE);
            }
            else
                me->RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_SHADOW_BLADES:
                case SPELL_SHADOW_NOVA:
                case SPELL_CONFOUNDING_BLOW:
                case SPELL_SHADOW_FURY:
                    HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
                    break;
                case SPELL_CONFLAGRATION:
                    HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
                    break;
            }
        }

        void HandleTouchedSpells(Unit* target, uint32 TouchedType)
        {
            switch (TouchedType)
            {
                case SPELL_FLAME_TOUCHED:
                    if (!target->HasAura(SPELL_DARK_FLAME))
                    {
                        if (target->HasAura(SPELL_DARK_TOUCHED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                            target->CastSpell(target, SPELL_DARK_FLAME, true);
                        } else target->CastSpell(target, SPELL_FLAME_TOUCHED, true);
                    }
                    break;
                case SPELL_DARK_TOUCHED:
                    if (!target->HasAura(SPELL_DARK_FLAME))
                    {
                        if (target->HasAura(SPELL_FLAME_TOUCHED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                            target->CastSpell(target, SPELL_DARK_FLAME, true);
                        } else target->CastSpell(target, SPELL_DARK_TOUCHED, true);
                    }
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!SisterDeath)
            {
                Unit* Temp = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_ALYTHESS));
                if (Temp && Temp->isDead())
                {
                    Talk(YELL_SISTER_ALYTHESS_DEAD);
                    DoCast(me, SPELL_EMPOWER);
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    SisterDeath = true;
                }
            }

            if (!UpdateVictim())
                return;

            if (SisterDeath)
            {
                if (ConflagrationTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_CONFLAGRATION);
                        ConflagrationTimer = 30000 + (rand32() % 5000);
                    }
                } else ConflagrationTimer -= diff;
            }
            else
            {
                if (ShadownovaTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (target)
                            DoCast(target, SPELL_SHADOW_NOVA);

                        if (!SisterDeath)
                        {
                            if (target)
                                Talk(EMOTE_SHADOW_NOVA, target);
                            Talk(YELL_SHADOW_NOVA);
                        }
                        ShadownovaTimer = 30000 + (rand32() % 5000);
                    }
                } else ShadownovaTimer -=diff;
            }

            if (ConfoundingblowTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CONFOUNDING_BLOW);
                    ConfoundingblowTimer = 20000 + (rand32() % 5000);
                }
            } else ConfoundingblowTimer -=diff;

            if (ShadowimageTimer <= diff)
            {
                Unit* target = NULL;
                Creature* temp = NULL;
                for (uint8 i = 0; i<3; ++i)
                {
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    temp = DoSpawnCreature(NPC_SHADOW_IMAGE, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 10000);
                    if (temp && target)
                    {
                        temp->AddThreat(target, 1000000); //don't change target(healers)
                        temp->AI()->AttackStart(target);
                    }
                }
                ShadowimageTimer = 20000;
            } else ShadowimageTimer -=diff;

            if (ShadowbladesTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    DoCast(me, SPELL_SHADOW_BLADES);
                    ShadowbladesTimer = 10000;
                }
            } else ShadowbladesTimer -=diff;

            if (EnrageTimer < diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                Talk(YELL_ENRAGE);
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            } else EnrageTimer -= diff;

            if (me->isAttackReady() && !me->IsNonMeleeSpellCast(false))
            {
                //If we are within range melee the target
                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    HandleTouchedSpells(me->GetVictim(), SPELL_DARK_TOUCHED);
                    me->AttackerStateUpdate(me->GetVictim());
                    me->resetAttackTimer();
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_sacrolashAI>(creature);
    };
};

class boss_alythess : public CreatureScript
{
public:
    boss_alythess() : CreatureScript("boss_alythess") { }

    struct boss_alythessAI : public ScriptedAI
    {
        boss_alythessAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            SetCombatMovement(false);

            instance = creature->GetInstanceScript();
            IntroStepCounter = 10;
        }

        void Initialize()
        {
            ConflagrationTimer = 45000;
            BlazeTimer = 100;
            PyrogenicsTimer = 15000;
            ShadownovaTimer = 40000;
            EnrageTimer = 360000;
            FlamesearTimer = 15000;
            IntroYellTimer = 10000;

            SisterDeath = false;
            Enraged = false;
        }

        InstanceScript* instance;

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

        void Reset() override
        {
            Enraged = false;

            if (Creature* temp = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SACROLASH)))
            {
                if (temp->isDead())
                    temp->Respawn();
                else if (temp->GetVictim())
                    me->getThreatManager().addThreat(temp->GetVictim(), 0.0f);
            }

            if (!me->IsInCombat())
            {
                Initialize();
            }

            instance->SetBossState(DATA_EREDAR_TWINS, NOT_STARTED);
        }

        void EnterCombat(Unit* who) override
        {
            DoZoneInCombat();

            Creature* temp = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SACROLASH));
            if (temp && temp->IsAlive() && !temp->GetVictim())
                temp->AI()->AttackStart(who);

            instance->SetBossState(DATA_EREDAR_TWINS, IN_PROGRESS);
        }

        void AttackStart(Unit* who) override
        {
            if (!me->IsInCombat())
                ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || me->GetVictim())
                return;

            if (me->CanCreatureAttack(who))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius) && me->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && me->IsWithinLOSInMap(who))
                {
                    if (!me->IsInCombat())
                    {
                        DoStartNoMovement(who);
                    }
                }
            }
            else if (IntroStepCounter == 10 && me->IsWithinLOSInMap(who)&& me->IsWithinDistInMap(who, 30))
                IntroStepCounter = 0;
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (rand32() % 4 == 0)
                Talk(YELL_ALY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (SisterDeath)
            {
                Talk(YELL_ALY_DEAD);
                instance->SetBossState(DATA_EREDAR_TWINS, DONE);
            }
            else
                me->RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_BLAZE:
                    target->CastSpell(target, SPELL_BLAZE_SUMMON, true);
                    break;
                case SPELL_CONFLAGRATION:
                case SPELL_FLAME_SEAR:
                    HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
                    break;
                case SPELL_SHADOW_NOVA:
                    HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
                    break;
            }
        }

        void HandleTouchedSpells(Unit* target, uint32 TouchedType)
        {
            switch (TouchedType)
            {
                case SPELL_FLAME_TOUCHED:
                    if (!target->HasAura(SPELL_DARK_FLAME))
                    {
                        if (target->HasAura(SPELL_DARK_TOUCHED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                            target->CastSpell(target, SPELL_DARK_FLAME, true);
                        }
                        else
                            target->CastSpell(target, SPELL_FLAME_TOUCHED, true);
                    }
                    break;
                case SPELL_DARK_TOUCHED:
                    if (!target->HasAura(SPELL_DARK_FLAME))
                    {
                        if (target->HasAura(SPELL_FLAME_TOUCHED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                            target->CastSpell(target, SPELL_DARK_FLAME, true);
                        }
                        else
                            target->CastSpell(target, SPELL_DARK_TOUCHED, true);
                    }
                    break;
            }
        }

        uint32 IntroStep(uint32 step)
        {
            Creature* Sacrolash = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SACROLASH));
            switch (step)
            {
                case 0:
                    return 0;
                case 1:
                    if (Sacrolash)
                        Sacrolash->AI()->Talk(YELL_INTRO_SAC_1);
                    return 1000;
                case 2:
                    Talk(YELL_INTRO_ALY_2);
                    return 1000;
                case 3:
                    if (Sacrolash)
                        Sacrolash->AI()->Talk(YELL_INTRO_SAC_3);
                    return 2000;
                case 4:
                    Talk(YELL_INTRO_ALY_4);
                    return 1000;
                case 5:
                    if (Sacrolash)
                        Sacrolash->AI()->Talk(YELL_INTRO_SAC_5);
                    return 2000;
                case 6:
                    Talk(YELL_INTRO_ALY_6);
                    return 1000;
                case 7:
                    if (Sacrolash)
                        Sacrolash->AI()->Talk(YELL_INTRO_SAC_7);
                    return 3000;
                case 8:
                    Talk(YELL_INTRO_ALY_8);
                    return 900000;
            }
            return 10000;
        }

        void UpdateAI(uint32 diff) override
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
                Unit* Temp = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_SACROLASH));
                if (Temp && Temp->isDead())
                {
                    Talk(YELL_SISTER_SACROLASH_DEAD);
                    DoCast(me, SPELL_EMPOWER);
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    SisterDeath = true;
                }
            }
            if (!me->GetVictim())
            {
                Creature* sisiter = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SACROLASH));
                if (sisiter && !sisiter->isDead() && sisiter->GetVictim())
                {
                    me->AddThreat(sisiter->GetVictim(), 0.0f);
                    DoStartNoMovement(sisiter->GetVictim());
                    me->Attack(sisiter->GetVictim(), false);
                }
            }

            if (!UpdateVictim())
                return;

            if (SisterDeath)
            {
                if (ShadownovaTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_NOVA);
                        ShadownovaTimer = 30000 + (rand32() % 5000);
                    }
                } else ShadownovaTimer -=diff;
            }
            else
            {
                if (ConflagrationTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (target)
                            DoCast(target, SPELL_CONFLAGRATION);
                        ConflagrationTimer = 30000 + (rand32() % 5000);

                        if (!SisterDeath)
                        {
                            if (target)
                                Talk(EMOTE_CONFLAGRATION, target);
                            Talk(YELL_CANFLAGRATION);
                        }

                        BlazeTimer = 4000;
                    }
                } else ConflagrationTimer -= diff;
            }

            if (FlamesearTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    DoCast(me, SPELL_FLAME_SEAR);
                    FlamesearTimer = 15000;
                }
            } else FlamesearTimer -=diff;

            if (PyrogenicsTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    DoCast(me, SPELL_PYROGENICS, true);
                    PyrogenicsTimer = 15000;
                }
            } else PyrogenicsTimer -= diff;

            if (BlazeTimer <= diff)
            {
                if (!me->IsNonMeleeSpellCast(false))
                {
                    DoCastVictim(SPELL_BLAZE);
                    BlazeTimer = 3800;
                }
            } else BlazeTimer -= diff;

            if (EnrageTimer < diff && !Enraged)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                Talk(YELL_BERSERK);
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            } else EnrageTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_alythessAI>(creature);
    };
};

class npc_shadow_image : public CreatureScript
{
public:
    npc_shadow_image() : CreatureScript("npc_shadow_image") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<npc_shadow_imageAI>(creature);
    };

    struct npc_shadow_imageAI : public ScriptedAI
    {
        npc_shadow_imageAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ShadowfuryTimer = 5000 + (rand32() % 15000);
            DarkstrikeTimer = 3000;
            KillTimer = 15000;
        }

        uint32 ShadowfuryTimer;
        uint32 KillTimer;
        uint32 DarkstrikeTimer;

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_SHADOW_FURY:
                case SPELL_DARK_STRIKE:
                    if (!target->HasAura(SPELL_DARK_FLAME))
                    {
                        if (target->HasAura(SPELL_FLAME_TOUCHED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                            target->CastSpell(target, SPELL_DARK_FLAME, true);
                        } else target->CastSpell(target, SPELL_DARK_TOUCHED, true);
                    }
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->HasAura(SPELL_IMAGE_VISUAL))
                DoCast(me, SPELL_IMAGE_VISUAL);

            if (KillTimer <= diff)
            {
                me->KillSelf();
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
                if (!me->IsNonMeleeSpellCast(false))
                {
                    //If we are within range melee the target
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastVictim(SPELL_DARK_STRIKE);
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
    new npc_shadow_image();
}
