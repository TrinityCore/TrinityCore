/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Kaelthas
SD%Complete: 60
SDComment: SQL, weapon scripts, mind control, need correct spells(interruptible/uninterruptible), phoenix spawn location & animation, phoenix behaviour & spawn during gravity lapse
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_eye.h"
#include "WorldPacket.h"
#include "Opcodes.h"

enum Yells
{
    // Kael'thas Speech
    SAY_INTRO                           = 0,
    SAY_INTRO_CAPERNIAN                 = 1,
    SAY_INTRO_TELONICUS                 = 2,
    SAY_INTRO_THALADRED                 = 3,
    SAY_INTRO_SANGUINAR                 = 4,
    SAY_PHASE2_WEAPON                   = 5,
    SAY_PHASE3_ADVANCE                  = 6,
    SAY_PHASE4_INTRO2                   = 7,
    SAY_PHASE5_NUTS                     = 8,
    SAY_SLAY                            = 9,
    SAY_MINDCONTROL                     = 10,
    SAY_GRAVITYLAPSE                    = 11,
    SAY_SUMMON_PHOENIX                  = 12,
    SAY_DEATH                           = 13,

    // Thaladred the Darkener speech
    SAY_THALADRED_AGGRO                 = 0,
    SAY_THALADRED_DEATH                 = 1,
    EMOTE_THALADRED_GAZE                = 2,

    //Lord Sanguinar speech
    SAY_SANGUINAR_AGGRO                 = 0,
    SAY_SANGUINAR_DEATH                 = 1,

    // Grand Astromancer Capernian speech
    SAY_CAPERNIAN_AGGRO                 = 0,
    SAY_CAPERNIAN_DEATH                 = 1,

    // Master Engineer Telonicus speech
    SAY_TELONICUS_AGGRO                 = 0,
    SAY_TELONICUS_DEATH                 = 1
};

enum Spells
{
    // Phase 2 spells
    SPELL_SUMMON_WEAPONS                = 36976,
    SPELL_SUMMON_WEAPONA                = 36958,
    SPELL_SUMMON_WEAPONB                = 36959,
    SPELL_SUMMON_WEAPONC                = 36960,
    SPELL_SUMMON_WEAPOND                = 36961,
    SPELL_SUMMON_WEAPONE                = 36962,
    SPELL_SUMMON_WEAPONF                = 36963,
    SPELL_SUMMON_WEAPONG                = 36964,
    SPELL_RES_VISUAL                    = 24171,

    // Phase 4 spells
    SPELL_FIREBALL                      = 22088,           //wrong but works with CastCustomSpell
    SPELL_PYROBLAST                     = 36819,
    SPELL_FLAME_STRIKE                  = 36735,
    SPELL_FLAME_STRIKE_VIS              = 36730,
    SPELL_FLAME_STRIKE_DMG              = 36731,
    SPELL_ARCANE_DISRUPTION             = 36834,
    SPELL_SHOCK_BARRIER                 = 36815,
    SPELL_PHOENIX_ANIMATION             = 36723,
    SPELL_MIND_CONTROL                  = 32830,

    // Phase 5 spells
    SPELL_EXPLODE                       = 36092,
    SPELL_FULLPOWER                     = 36187,
    SPELL_KNOCKBACK                     = 11027,
    SPELL_GRAVITY_LAPSE                 = 34480,
    SPELL_GRAVITY_LAPSE_AURA            = 39432,
    SPELL_NETHER_BEAM                   = 35873,

    // Thaladred the Darkener spells
    SPELL_PSYCHIC_BLOW                  = 10689,
    SPELL_SILENCE                       = 30225,
    // Lord Sanguinar spells
    SPELL_BELLOWING_ROAR                = 40636,
    // Grand Astromancer Capernian spells

    SPELL_CAPERNIAN_FIREBALL            = 36971,
    SPELL_CONFLAGRATION                 = 37018,
    SPELL_ARCANE_EXPLOSION              = 36970,
    //Master Engineer Telonicus spells
    SPELL_BOMB                          = 37036,
    SPELL_REMOTE_TOY                    = 37027,
    //Nether Vapor spell
    SPELL_NETHER_VAPOR                  = 35859,
    //Phoenix spell
    SPELL_BURN                          = 36720,
    SPELL_EMBER_BLAST                   = 34341,
    SPELL_REBIRTH                       = 41587
};

enum Creatures
{
    NPC_PHOENIX                         = 21362,
    NPC_PHOENIX_EGG                     = 21364
};

enum Models
{
    //Phoenix egg and phoenix model
    MODEL_ID_PHOENIX                    = 19682,
    MODEL_ID_PHOENIX_EGG                = 20245
};

enum Misc
{
    MAX_ADVISORS                        = 4
};

uint32 m_auiSpellSummonWeapon[]=
{
    SPELL_SUMMON_WEAPONA, SPELL_SUMMON_WEAPONB, SPELL_SUMMON_WEAPONC, SPELL_SUMMON_WEAPOND,
    SPELL_SUMMON_WEAPONE, SPELL_SUMMON_WEAPONF, SPELL_SUMMON_WEAPONG
};

const float CAPERNIAN_DISTANCE          = 20.0f;            //she casts away from the target
const float KAEL_VISIBLE_RANGE          = 50.0f;

const float afGravityPos[3]             = {795.0f, 0.0f, 70.0f};

#define TIME_PHASE_2_3      120000
#define TIME_PHASE_3_4      180000

//Base AI for Advisors
struct advisorbase_ai : public ScriptedAI
{
    advisorbase_ai(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        m_bDoubled_Health = false;
    }

    InstanceScript* instance;
    bool FakeDeath;
    bool m_bDoubled_Health;
    uint32 DelayRes_Timer;
    uint64 DelayRes_Target;

    void Reset() OVERRIDE
    {
        if (m_bDoubled_Health)
        {
            me->SetMaxHealth(me->GetMaxHealth() / 2);
            m_bDoubled_Health = false;
        }

        FakeDeath = false;
        DelayRes_Timer = 0;
        DelayRes_Target = 0;

        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        //reset encounter
        if (instance && (instance->GetData(DATA_KAELTHASEVENT) == 1 || instance->GetData(DATA_KAELTHASEVENT) == 3))
            if (Creature* Kaelthas = Unit::GetCreature(*me, instance->GetData64(DATA_KAELTHAS)))
                Kaelthas->AI()->EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit* who) OVERRIDE

    {
        if (!who || FakeDeath || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void AttackStart(Unit* who) OVERRIDE
    {
        if (!who || FakeDeath || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::AttackStart(who);
    }

    void Revive(Unit* /*Target*/)
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        // double health for phase 3
        me->SetMaxHealth(me->GetMaxHealth() * 2);
        m_bDoubled_Health = true;
        me->SetFullHealth();
        me->SetStandState(UNIT_STAND_STATE_STAND);

        DoCast(me, SPELL_RES_VISUAL, false);
        DelayRes_Timer = 2000;
    }

    void DamageTaken(Unit* killer, uint32 &damage) OVERRIDE
    {
        if (damage < me->GetHealth())
            return;

        //Prevent glitch if in fake death
        if (FakeDeath && instance && instance->GetData(DATA_KAELTHASEVENT) != 0)
        {
            damage = 0;
            return;
        }

        //Don't really die in phase 1 & 3, only die after that
        if (instance && instance->GetData(DATA_KAELTHASEVENT) != 0)
        {
            //prevent death
            damage = 0;
            FakeDeath = true;

            me->InterruptNonMeleeSpells(false);
            me->SetHealth(0);
            me->StopMoving();
            me->ClearComboPointHolders();
            me->RemoveAllAurasOnDeath();
            me->ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
            me->ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->ClearAllReactives();
            me->SetTarget(0);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveIdle();
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            JustDied(killer);
        }
    }

    void UpdateAI(uint32 diff) OVERRIDE
    {
        if (DelayRes_Timer)
        {
            if (DelayRes_Timer <= diff)
            {
                DelayRes_Timer = 0;
                FakeDeath = false;

                Unit* Target = Unit::GetUnit(*me, DelayRes_Target);
                if (!Target)
                    Target = me->GetVictim();

                DoResetThreat();
                AttackStart(Target);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(Target);
                me->AddThreat(Target, 0.0f);
            } else DelayRes_Timer -= diff;
        }
    }
};

class boss_kaelthas : public CreatureScript
{
    public:

        boss_kaelthas()
            : CreatureScript("boss_kaelthas")
        {
        }
        //Kael'thas AI
        struct boss_kaelthasAI : public ScriptedAI
        {
            boss_kaelthasAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
                memset(&m_auiAdvisorGuid, 0, sizeof(m_auiAdvisorGuid));
            }

            InstanceScript* instance;

            uint32 Fireball_Timer;
            uint32 ArcaneDisruption_Timer;
            uint32 Phoenix_Timer;
            uint32 ShockBarrier_Timer;
            uint32 GravityLapse_Timer;
            uint32 GravityLapse_Phase;
            uint32 NetherBeam_Timer;
            uint32 NetherVapor_Timer;
            uint32 FlameStrike_Timer;
            uint32 MindControl_Timer;
            uint32 Phase;
            uint32 PhaseSubphase;                                   //generic
            uint32 Phase_Timer;                                     //generic timer
            uint32 PyrosCasted;

            bool InGravityLapse;
            bool IsCastingFireball;
            bool ChainPyros;

            SummonList summons;

            uint64 m_auiAdvisorGuid[MAX_ADVISORS];

            void Reset() OVERRIDE
            {
                Fireball_Timer = 5000+rand()%10000;
                ArcaneDisruption_Timer = 45000;
                MindControl_Timer = 40000;
                Phoenix_Timer = 50000;
                ShockBarrier_Timer = 60000;
                FlameStrike_Timer = 30000;
                GravityLapse_Timer = 20000;
                GravityLapse_Phase = 0;
                NetherBeam_Timer = 8000;
                NetherVapor_Timer = 10000;
                PyrosCasted = 0;
                Phase = 0;
                InGravityLapse = false;
                IsCastingFireball = false;
                ChainPyros = false;

                if (me->IsInCombat())
                    PrepareAdvisors();

                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (instance)
                    instance->SetData(DATA_KAELTHASEVENT, 0);
            }

            void PrepareAdvisors()
            {
                for (uint8 i = 0; i < MAX_ADVISORS; ++i)
                {
                    if (Creature* creature = Unit::GetCreature(*me, m_auiAdvisorGuid[i]))
                    {
                        creature->Respawn();
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        creature->setFaction(me->getFaction());
                        creature->AI()->EnterEvadeMode();
                    }
                }
            }

            void StartEvent()
            {
                if (!instance)
                    return;

                m_auiAdvisorGuid[0] = instance->GetData64(DATA_THALADREDTHEDARKENER);
                m_auiAdvisorGuid[1] = instance->GetData64(DATA_LORDSANGUINAR);
                m_auiAdvisorGuid[2] = instance->GetData64(DATA_GRANDASTROMANCERCAPERNIAN);
                m_auiAdvisorGuid[3] = instance->GetData64(DATA_MASTERENGINEERTELONICUS);

                if (!m_auiAdvisorGuid[0] || !m_auiAdvisorGuid[1] || !m_auiAdvisorGuid[2] || !m_auiAdvisorGuid[3])
                {
                    TC_LOG_ERROR(LOG_FILTER_TSCR, "Kael'Thas One or more advisors missing, Skipping Phases 1-3");

                    Talk(SAY_PHASE4_INTRO2);

                    Phase = 4;

                    instance->SetData(DATA_KAELTHASEVENT, 4);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        AttackStart(target);
                }
                else
                {
                    PrepareAdvisors();

                    Talk(SAY_INTRO);

                    instance->SetData(DATA_KAELTHASEVENT, 1);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    PhaseSubphase = 0;
                    Phase_Timer = 23000;
                    Phase = 1;
                }
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (!me->HasUnitState(UNIT_STATE_STUNNED) && me->CanCreatureAttack(who))
                {
                    if (!me->CanFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                        return;

                    float attackRadius = me->GetAttackDistance(who);
                    if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                    {
                        if (!me->GetVictim() && Phase >= 4)
                        {
                            who->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                            AttackStart(who);
                        }
                        else if (me->GetMap()->IsDungeon())
                        {
                            if (instance && !instance->GetData(DATA_KAELTHASEVENT) && !Phase)
                                StartEvent();

                            who->SetInCombatWith(me);
                            me->AddThreat(who, 0.0f);
                        }
                    }
                }
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                if (instance && !instance->GetData(DATA_KAELTHASEVENT) && !Phase)
                    StartEvent();
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                // if not phoenix, then it's one of the 7 weapons
                if (summoned->GetEntry() != NPC_PHOENIX)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summoned->AI()->AttackStart(target);

                    summons.Summon(summoned);
                }
            }

            void SummonedCreatureDespawn(Creature* summon) OVERRIDE
            {
                summons.Despawn(summon);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                Talk(SAY_DEATH);

                summons.DespawnAll();

                if (instance)
                    instance->SetData(DATA_KAELTHASEVENT, 0);

                for (uint8 i = 0; i < MAX_ADVISORS; ++i)
                {
                    if (Unit* pAdvisor = Unit::GetUnit(*me, m_auiAdvisorGuid[i]))
                        pAdvisor->Kill(pAdvisor);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                //Phase 1
                switch (Phase)
                {
                    case 1:
                    {
                        Unit* target = NULL;
                        Creature* Advisor = NULL;

                        //Subphase switch
                        switch (PhaseSubphase)
                        {
                            //Subphase 1 - Start
                            case 0:
                                if (Phase_Timer <= diff)
                                {
                                    Talk(SAY_INTRO_THALADRED);

                                    //start advisor within 7 seconds
                                    Phase_Timer = 7000;
                                    ++PhaseSubphase;
                                } else Phase_Timer -= diff;
                                break;

                            //Subphase 1 - Unlock advisor
                            case 1:
                                if (Phase_Timer <= diff)
                                {
                                    Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[0]));

                                    if (Advisor)
                                    {
                                        Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        Advisor->setFaction(me->getFaction());

                                        target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                        if (target)
                                            Advisor->AI()->AttackStart(target);
                                    }

                                    ++PhaseSubphase;
                                } else Phase_Timer -= diff;
                                break;

                            //Subphase 2 - Start
                            case 2:
                                Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[0]));

                                if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                                {
                                    Talk(SAY_INTRO_SANGUINAR);

                                    //start advisor within 12.5 seconds
                                    Phase_Timer = 12500;
                                    ++PhaseSubphase;
                                }
                                break;

                            //Subphase 2 - Unlock advisor
                            case 3:
                                if (Phase_Timer <= diff)
                                {
                                    Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[1]));

                                    if (Advisor)
                                    {
                                        Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        Advisor->setFaction(me->getFaction());

                                        target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                        if (target)
                                            Advisor->AI()->AttackStart(target);
                                    }

                                    ++PhaseSubphase;
                                } else Phase_Timer -= diff;
                                break;

                            //Subphase 3 - Start
                            case 4:
                                Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[1]));

                                if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                                {
                                    Talk(SAY_INTRO_CAPERNIAN);

                                    //start advisor within 7 seconds
                                    Phase_Timer = 7000;
                                    ++PhaseSubphase;
                                }
                                break;

                            //Subphase 3 - Unlock advisor
                            case 5:
                                if (Phase_Timer <= diff)
                                {
                                    Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[2]));

                                    if (Advisor)
                                    {
                                        Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        Advisor->setFaction(me->getFaction());

                                        target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                        if (target)
                                            Advisor->AI()->AttackStart(target);
                                    }

                                    ++PhaseSubphase;
                                } else Phase_Timer -= diff;
                                break;

                            //Subphase 4 - Start
                            case 6:
                                Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[2]));

                                if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                                {
                                    Talk(SAY_INTRO_TELONICUS);

                                    //start advisor within 8.4 seconds
                                    Phase_Timer = 8400;
                                    ++PhaseSubphase;
                                }
                                break;

                            //Subphase 4 - Unlock advisor
                            case 7:
                                if (Phase_Timer <= diff)
                                {
                                    Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[3]));

                                    if (Advisor)
                                    {
                                        Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        Advisor->setFaction(me->getFaction());

                                        target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                                        if (target)
                                            Advisor->AI()->AttackStart(target);
                                    }

                                    Phase_Timer = 3000;
                                    ++PhaseSubphase;
                                } else Phase_Timer -= diff;
                                break;

                            //End of phase 1
                            case 8:
                                Advisor = (Unit::GetCreature(*me, m_auiAdvisorGuid[3]));

                                if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                                {
                                    Phase = 2;
                                    if (instance)
                                        instance->SetData(DATA_KAELTHASEVENT, 2);

                                    Talk(SAY_PHASE2_WEAPON);

                                    PhaseSubphase = 0;
                                    Phase_Timer = 3500;
                                    DoCast(me, SPELL_SUMMON_WEAPONS);
                                }
                                break;
                        }
                    }
                    break;

                    case 2:
                    {
                        if (PhaseSubphase == 0)
                        {
                            if (Phase_Timer <= diff)
                            {
                                PhaseSubphase = 1;
                            }
                            else
                                Phase_Timer -= diff;
                        }

                        //Spawn weapons
                        if (PhaseSubphase == 1)
                        {
                            DoCast(me, SPELL_SUMMON_WEAPONS, false);

                            uint8 uiMaxWeapon = sizeof(m_auiSpellSummonWeapon)/sizeof(uint32);

                            for (uint32 i = 0; i < uiMaxWeapon; ++i)
                                DoCast(me, m_auiSpellSummonWeapon[i], true);

                            PhaseSubphase = 2;
                            Phase_Timer = TIME_PHASE_2_3;
                        }

                        if (PhaseSubphase == 2)
                        {
                            if (Phase_Timer <= diff)
                            {
                                Talk(SAY_PHASE3_ADVANCE);
                                if (instance)
                                    instance->SetData(DATA_KAELTHASEVENT, 3);
                                Phase = 3;
                                PhaseSubphase = 0;
                            }
                            else
                                Phase_Timer -= diff;
                        }
                    }
                    break;

                    case 3:
                    {
                        if (PhaseSubphase == 0)
                        {
                            //Respawn advisors
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                            Creature* Advisor;
                            for (uint8 i = 0; i < MAX_ADVISORS; ++i)
                            {
                                Advisor = Unit::GetCreature(*me, m_auiAdvisorGuid[i]);

                                if (!Advisor)
                                    TC_LOG_ERROR(LOG_FILTER_TSCR, "SD2: Kael'Thas Advisor %u does not exist. Possibly despawned? Incorrectly Killed?", i);
                                else
                                    CAST_AI(advisorbase_ai, Advisor->AI())->Revive(target);
                            }

                            PhaseSubphase = 1;
                            Phase_Timer = TIME_PHASE_3_4;
                        }

                        if (Phase_Timer <= diff)
                        {
                            Talk(SAY_PHASE4_INTRO2);
                            Phase = 4;

                            if (instance)
                                instance->SetData(DATA_KAELTHASEVENT, 4);

                            // Sometimes people can collect Aggro in Phase 1-3. Reset threat before releasing Kael.
                            DoResetThreat();

                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                AttackStart(target);

                            Phase_Timer = 30000;
                        }
                        else
                            Phase_Timer -= diff;
                    }
                    break;

                    case 4:
                    case 5:
                    case 6:
                    {
                        //Return since we have no target
                        if (!UpdateVictim())
                            return;

                        //Fireball_Timer
                        if (!InGravityLapse && !ChainPyros && Phase != 5)
                        {
                            if (Fireball_Timer <= diff)
                            {
                                if (!IsCastingFireball)
                                {
                                    if (!me->IsNonMeleeSpellCasted(false))
                                    {
                                        //interruptable
                                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, false);
                                        int32 dmg = 20000+rand()%5000;
                                        me->CastCustomSpell(me->GetVictim(), SPELL_FIREBALL, &dmg, 0, 0, false);
                                        IsCastingFireball = true;
                                        Fireball_Timer = 2500;
                                    }
                                }
                                else
                                {
                                    //apply resistance
                                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                                    IsCastingFireball = false;
                                    Fireball_Timer = 5000+rand()%10000;
                                }
                            }
                            else
                                Fireball_Timer -= diff;

                            //ArcaneDisruption_Timer
                            if (ArcaneDisruption_Timer <= diff)
                            {
                                DoCastVictim(SPELL_ARCANE_DISRUPTION, true);
                                ArcaneDisruption_Timer = 60000;
                            }
                            else
                                ArcaneDisruption_Timer -= diff;

                            if (FlameStrike_Timer <= diff)
                            {
                                if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(unit, SPELL_FLAME_STRIKE);

                                FlameStrike_Timer = 30000;
                            }
                            else
                                FlameStrike_Timer -= diff;

                            if (MindControl_Timer <= diff)
                            {
                                if (me->getThreatManager().getThreatList().size() >= 2)
                                    for (uint32 i = 0; i < 3; ++i)
                                {
                                    TC_LOG_DEBUG(LOG_FILTER_TSCR, "Kael'Thas mind control not supported.");
                                    //DoCast(unit, SPELL_MIND_CONTROL);
                                }

                                MindControl_Timer = 60000;
                            }
                            else
                                MindControl_Timer -= diff;
                        }

                        //Phoenix_Timer
                        if (Phoenix_Timer <= diff)
                        {
                            DoCast(me, SPELL_PHOENIX_ANIMATION);
                            Talk(SAY_SUMMON_PHOENIX);

                            Phoenix_Timer = 60000;
                        }
                        else
                            Phoenix_Timer -= diff;

                        //Phase 4 specific spells
                        if (Phase == 4)
                        {
                            if (HealthBelowPct(50))
                            {
                                if (instance)
                                    instance->SetData(DATA_KAELTHASEVENT, 4);
                                Phase = 5;
                                Phase_Timer = 10000;

                                Talk(SAY_PHASE5_NUTS);

                                me->StopMoving();
                                me->GetMotionMaster()->Clear();
                                me->GetMotionMaster()->MoveIdle();
                                me->SetPosition(afGravityPos[0], afGravityPos[1], afGravityPos[2], 0);
                                me->MonsterMoveWithSpeed(afGravityPos[0], afGravityPos[1], afGravityPos[2], 1);

                                me->InterruptNonMeleeSpells(false);
                                DoCast(me, SPELL_FULLPOWER);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            }

                            //ShockBarrier_Timer
                            if (ShockBarrier_Timer <= diff)
                            {
                                DoCast(me, SPELL_SHOCK_BARRIER);
                                ChainPyros = true;
                                PyrosCasted = 0;
                                ShockBarrier_Timer = 60000;
                            }
                            else
                                ShockBarrier_Timer -= diff;

                            //Chain Pyros (3 of them max)
                            if (ChainPyros && !me->IsNonMeleeSpellCasted(false))
                            {
                                if (PyrosCasted < 3)
                                {
                                    DoCastVictim(SPELL_PYROBLAST);
                                    ++PyrosCasted;
                                }
                                else
                                {
                                    ChainPyros = false;
                                    Fireball_Timer = 2500;
                                    ArcaneDisruption_Timer = 60000;
                                }
                            }
                        }

                        if (Phase == 5)
                        {
                            if (Phase_Timer <= diff)
                            {
                                me->InterruptNonMeleeSpells(false);
                                me->RemoveAurasDueToSpell(SPELL_FULLPOWER);

                                DoCast(me, SPELL_EXPLODE);

                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Phase = 6;
                                AttackStart(me->GetVictim());
                            }
                            else
                                Phase_Timer -= diff;
                        }

                        //Phase 5
                        if (Phase == 6)
                        {
                            //GravityLapse_Timer
                            if (GravityLapse_Timer <= diff)
                            {
                                ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
                                ThreatContainer::StorageType::const_iterator i = threatlist.begin();

                                switch (GravityLapse_Phase)
                                {
                                    case 0:
                                        me->StopMoving();
                                        me->GetMotionMaster()->Clear();
                                        me->GetMotionMaster()->MoveIdle();
                                        me->SetPosition(afGravityPos[0], afGravityPos[1], afGravityPos[2], 0);
                                        me->MonsterMoveWithSpeed(afGravityPos[0], afGravityPos[1], afGravityPos[2], 0);

                                        // 1) Kael'thas will portal the whole raid right into his body
                                        for (i = threatlist.begin(); i != threatlist.end(); ++i)
                                        {
                                            Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid());
                                            if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                                            {
                                                //Use work around packet to prevent player from being dropped from combat
                                                DoTeleportPlayer(unit, afGravityPos[0], afGravityPos[1], afGravityPos[2], unit->GetOrientation());
                                            }
                                        }

                                        GravityLapse_Timer = 500;
                                        ++GravityLapse_Phase;
                                        InGravityLapse = true;
                                        ShockBarrier_Timer = 1000;
                                        NetherBeam_Timer = 5000;
                                        break;

                                    case 1:
                                        Talk(SAY_GRAVITYLAPSE);

                                        // 2) At that point he will put a Gravity Lapse debuff on everyone
                                        for (i = threatlist.begin(); i != threatlist.end(); ++i)
                                        {
                                            if (Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                                            {
                                                DoCast(unit, SPELL_KNOCKBACK, true);
                                                //Gravity lapse - needs an exception in Spell system to work

                                                unit->CastSpell(unit, SPELL_GRAVITY_LAPSE, true, 0, 0, me->GetGUID());
                                                unit->CastSpell(unit, SPELL_GRAVITY_LAPSE_AURA, true, 0, 0, me->GetGUID());

                                                //Using packet workaround
                                                WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                                                data.append(unit->GetPackGUID());
                                                data << uint32(0);
                                                unit->SendMessageToSet(&data, true);
                                            }
                                        }
                                        GravityLapse_Timer = 10000;
                                        ++GravityLapse_Phase;
                                        break;

                                    case 2:
                                        //Cast nether vapor aura on self
                                        me->InterruptNonMeleeSpells(false);
                                        DoCast(me, SPELL_NETHER_VAPOR);

                                        GravityLapse_Timer = 20000;
                                        ++GravityLapse_Phase;
                                        break;

                                    case 3:
                                        //Remove flight
                                        for (i = threatlist.begin(); i != threatlist.end(); ++i)
                                        {
                                            if (Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                                            {
                                                //Using packet workaround
                                                WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                                                data.append(unit->GetPackGUID());
                                                data << uint32(0);
                                                unit->SendMessageToSet(&data, true);
                                            }
                                        }

                                        me->RemoveAurasDueToSpell(SPELL_NETHER_VAPOR);
                                        InGravityLapse = false;
                                        GravityLapse_Timer = 60000;
                                        GravityLapse_Phase = 0;
                                        AttackStart(me->GetVictim());
                                        break;
                                }
                            }
                            else
                                GravityLapse_Timer -= diff;

                            if (InGravityLapse)
                            {
                                //ShockBarrier_Timer
                                if (ShockBarrier_Timer <= diff)
                                {
                                    DoCast(me, SPELL_SHOCK_BARRIER);
                                    ShockBarrier_Timer = 20000;
                                }
                                else
                                    ShockBarrier_Timer -= diff;

                                //NetherBeam_Timer
                                if (NetherBeam_Timer <= diff)
                                {
                                    if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                        DoCast(unit, SPELL_NETHER_BEAM);

                                    NetherBeam_Timer = 4000;
                                }
                                else
                                    NetherBeam_Timer -= diff;
                            }
                        }

                        if (!InGravityLapse)
                            DoMeleeAttackIfReady();
                    }
                }
            }
        };
        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_kaelthasAI(creature);
        }
};

//Thaladred the Darkener AI
class boss_thaladred_the_darkener : public CreatureScript
{
    public:

        boss_thaladred_the_darkener()
            : CreatureScript("boss_thaladred_the_darkener")
        {
        }
        struct boss_thaladred_the_darkenerAI : public advisorbase_ai
        {
            boss_thaladred_the_darkenerAI(Creature* creature) : advisorbase_ai(creature) {}

            uint32 Gaze_Timer;
            uint32 Silence_Timer;
            uint32 PsychicBlow_Timer;

            void Reset() OVERRIDE
            {
                Gaze_Timer = 100;
                Silence_Timer = 20000;
                PsychicBlow_Timer = 10000;

                advisorbase_ai::Reset();
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (!who || FakeDeath)
                    return;

                Talk(SAY_THALADRED_AGGRO);
                me->AddThreat(who, 5000000.0f);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance && instance->GetData(DATA_KAELTHASEVENT) == 3)
                    Talk(SAY_THALADRED_DEATH);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                advisorbase_ai::UpdateAI(diff);

                //Faking death, don't do anything
                if (FakeDeath)
                    return;

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Gaze_Timer
                if (Gaze_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoResetThreat();
                        me->AddThreat(target, 5000000.0f);
                        Talk(EMOTE_THALADRED_GAZE, target->GetGUID());
                        Gaze_Timer = 8500;
                    }
                }
                else
                    Gaze_Timer -= diff;

                //Silence_Timer
                if (Silence_Timer <= diff)
                {
                    DoCastVictim(SPELL_SILENCE);
                    Silence_Timer = 20000;
                }
                else
                    Silence_Timer -= diff;

                //PsychicBlow_Timer
                if (PsychicBlow_Timer <= diff)
                {
                    DoCastVictim(SPELL_PSYCHIC_BLOW);
                    PsychicBlow_Timer = 20000+rand()%5000;
                }
                else
                    PsychicBlow_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_thaladred_the_darkenerAI(creature);
        }
};

//Lord Sanguinar AI
class boss_lord_sanguinar : public CreatureScript
{
    public:

        boss_lord_sanguinar()
            : CreatureScript("boss_lord_sanguinar")
        {
        }
        struct boss_lord_sanguinarAI : public advisorbase_ai
        {
            boss_lord_sanguinarAI(Creature* creature) : advisorbase_ai(creature) {}

            uint32 Fear_Timer;

            void Reset() OVERRIDE
            {
                Fear_Timer = 20000;
                advisorbase_ai::Reset();
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (!who || FakeDeath)
                    return;

                Talk(SAY_SANGUINAR_AGGRO);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance && instance->GetData(DATA_KAELTHASEVENT) == 3)
                    Talk(SAY_SANGUINAR_DEATH);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                advisorbase_ai::UpdateAI(diff);

                //Faking death, don't do anything
                if (FakeDeath)
                    return;

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Fear_Timer
                if (Fear_Timer <= diff)
                {
                    DoCastVictim(SPELL_BELLOWING_ROAR);
                    Fear_Timer = 25000+rand()%10000;                //approximately every 30 seconds
                }
                else
                    Fear_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_lord_sanguinarAI(creature);
        }
};
//Grand Astromancer Capernian AI
class boss_grand_astromancer_capernian : public CreatureScript
{
    public:

        boss_grand_astromancer_capernian()
            : CreatureScript("boss_grand_astromancer_capernian")
        {
        }
        struct boss_grand_astromancer_capernianAI : public advisorbase_ai
        {
            boss_grand_astromancer_capernianAI(Creature* creature) : advisorbase_ai(creature) {}

            uint32 Fireball_Timer;
            uint32 Conflagration_Timer;
            uint32 ArcaneExplosion_Timer;
            uint32 Yell_Timer;
            bool Yell;

            void Reset() OVERRIDE
            {
                Fireball_Timer = 2000;
                Conflagration_Timer = 20000;
                ArcaneExplosion_Timer = 5000;
                Yell_Timer = 2000;
                Yell = false;

                advisorbase_ai::Reset();
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance && instance->GetData(DATA_KAELTHASEVENT) == 3)
                    Talk(SAY_CAPERNIAN_DEATH);
            }

            void AttackStart(Unit* who) OVERRIDE
            {
                if (!who || FakeDeath || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (me->Attack(who, true))
                {
                    me->AddThreat(who, 0.0f);
                    me->SetInCombatWith(who);
                    who->SetInCombatWith(me);

                    me->GetMotionMaster()->MoveChase(who, CAPERNIAN_DISTANCE);
                }
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (!who || FakeDeath)
                    return;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                advisorbase_ai::UpdateAI(diff);

                //Faking Death, don't do anything
                if (FakeDeath)
                    return;

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Yell_Timer
                if (!Yell)
                {
                    if (Yell_Timer <= diff)
                    {
                        Talk(SAY_CAPERNIAN_AGGRO);
                        Yell = true;
                    }
                    else
                        Yell_Timer -= diff;
                }

                //Fireball_Timer
                if (Fireball_Timer <= diff)
                {
                    DoCastVictim(SPELL_CAPERNIAN_FIREBALL);
                    Fireball_Timer = 4000;
                }
                else
                    Fireball_Timer -= diff;

                //Conflagration_Timer
                if (Conflagration_Timer <= diff)
                {
                    Unit* target = NULL;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                    if (target && me->IsWithinDistInMap(target, 30))
                        DoCast(target, SPELL_CONFLAGRATION);
                    else
                        DoCastVictim(SPELL_CONFLAGRATION);

                    Conflagration_Timer = 10000+rand()%5000;
                }
                else
                    Conflagration_Timer -= diff;

                //ArcaneExplosion_Timer
                if (ArcaneExplosion_Timer <= diff)
                {
                    bool InMeleeRange = false;
                    Unit* target = NULL;
                    ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
                    for (ThreatContainer::StorageType::const_iterator i = threatlist.begin(); i!= threatlist.end(); ++i)
                    {
                        Unit* unit = Unit::GetUnit(*me, (*i)->getUnitGuid());
                                                                    //if in melee range
                        if (unit && unit->IsWithinDistInMap(me, 5))
                        {
                            InMeleeRange = true;
                            target = unit;
                            break;
                        }
                    }

                    if (InMeleeRange)
                        DoCast(target, SPELL_ARCANE_EXPLOSION);

                    ArcaneExplosion_Timer = 4000+rand()%2000;
                }
                else
                    ArcaneExplosion_Timer -= diff;

                //Do NOT deal any melee damage.
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_grand_astromancer_capernianAI(creature);
        }
};

//Master Engineer Telonicus AI
class boss_master_engineer_telonicus : public CreatureScript
{
    public:

        boss_master_engineer_telonicus()
            : CreatureScript("boss_master_engineer_telonicus")
        {
        }
        struct boss_master_engineer_telonicusAI : public advisorbase_ai
        {
            boss_master_engineer_telonicusAI(Creature* creature) : advisorbase_ai(creature) {}

            uint32 Bomb_Timer;
            uint32 RemoteToy_Timer;

            void Reset() OVERRIDE
            {
                Bomb_Timer = 10000;
                RemoteToy_Timer = 5000;

                advisorbase_ai::Reset();
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance && instance->GetData(DATA_KAELTHASEVENT) == 3)
                    Talk(SAY_TELONICUS_DEATH);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (!who || FakeDeath)
                    return;

                Talk(SAY_TELONICUS_AGGRO);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                advisorbase_ai::UpdateAI(diff);

                //Faking Death, do nothing
                if (FakeDeath)
                    return;

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Bomb_Timer
                if (Bomb_Timer <= diff)
                {
                    DoCastVictim(SPELL_BOMB);
                    Bomb_Timer = 25000;
                }
                else
                    Bomb_Timer -= diff;

                //RemoteToy_Timer
                if (RemoteToy_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_REMOTE_TOY);

                    RemoteToy_Timer = 10000+rand()%5000;
                }
                else
                    RemoteToy_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_master_engineer_telonicusAI(creature);
        }
};

//Flame Strike AI
class npc_kael_flamestrike : public CreatureScript
{
    public:

        npc_kael_flamestrike()
            : CreatureScript("npc_kael_flamestrike")
        {
        }
        struct npc_kael_flamestrikeAI : public ScriptedAI
        {
            npc_kael_flamestrikeAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            uint32 Timer;
            bool Casting;
            bool KillSelf;

            void Reset() OVERRIDE
            {
                Timer = 5000;
                Casting = false;
                KillSelf = false;

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->setFaction(14);
            }

            void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


            void EnterCombat(Unit* /*who*/) OVERRIDE {}

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!Casting)
                {
                    DoCast(me, SPELL_FLAME_STRIKE_VIS);
                    Casting = true;
                }

                //Timer
                if (Timer <= diff)
                {
                    if (!KillSelf)
                    {
                        me->InterruptNonMeleeSpells(false);
                        DoCast(me, SPELL_FLAME_STRIKE_DMG);
                    }
                    else
                        me->Kill(me);

                    KillSelf = true;
                    Timer = 1000;
                }
                else
                    Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_kael_flamestrikeAI(creature);
        }
};

//Phoenix AI
class npc_phoenix_tk : public CreatureScript
{
    public:

        npc_phoenix_tk()
            : CreatureScript("npc_phoenix_tk")
        {
        }
        struct npc_phoenix_tkAI : public ScriptedAI
        {
            npc_phoenix_tkAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 Cycle_Timer;

            void Reset() OVERRIDE
            {
                Cycle_Timer = 2000;
                DoCast(me, SPELL_BURN, true);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                //is this spell in use anylonger?
                //DoCast(me, SPELL_EMBER_BLAST, true);
                me->SummonCreature(NPC_PHOENIX_EGG, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 16000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                if (Cycle_Timer <= diff)
                {
                    //spell Burn should possible do this, but it doesn't, so do this for now.
                    uint32 dmg = urand(4500, 5500);
                    if (me->GetHealth() > dmg)
                        me->ModifyHealth(-int32(dmg));
                    Cycle_Timer = 2000;
                }
                else
                    Cycle_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_phoenix_tkAI(creature);
        }
};

//Phoenix Egg AI
class npc_phoenix_egg_tk : public CreatureScript
{
    public:

        npc_phoenix_egg_tk()
            : CreatureScript("npc_phoenix_egg_tk")
        {
        }
        struct npc_phoenix_egg_tkAI : public ScriptedAI
        {
            npc_phoenix_egg_tkAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 Rebirth_Timer;

            void Reset() OVERRIDE
            {
                Rebirth_Timer = 15000;
            }

            //ignore any
            void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


            void AttackStart(Unit* who) OVERRIDE
            {
                if (me->Attack(who, false))
                {
                    me->SetInCombatWith(who);
                    who->SetInCombatWith(me);

                    DoStartNoMovement(who);
                }
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summoned->AddThreat(me->GetVictim(), 0.0f);
                summoned->CastSpell(summoned, SPELL_REBIRTH, false);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!Rebirth_Timer)
                    return;

                if (Rebirth_Timer <= diff)
                {
                    me->SummonCreature(NPC_PHOENIX, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 5000);
                    Rebirth_Timer = 0;
                }
                else
                    Rebirth_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_phoenix_egg_tkAI(creature);
        }
};

void AddSC_boss_kaelthas()
{
    new boss_kaelthas();
    new boss_thaladred_the_darkener();
    new boss_lord_sanguinar();
    new boss_grand_astromancer_capernian();
    new boss_master_engineer_telonicus();
    new npc_kael_flamestrike();
    new npc_phoenix_tk();
    new npc_phoenix_egg_tk();
}
