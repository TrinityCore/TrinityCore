/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Kaelthas
SD%Complete: 60
SDComment: SQL, weapon scripts, mind control, need correct spells(interruptible/uninterruptible), phoenix spawn location & animation, phoenix behaviour & spawn during gravity lapse
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptedPch.h"
#include "the_eye.h"
#include "WorldPacket.h"

enum eEnums
{
    //kael'thas Speech
    SAY_INTRO                           = -1550016,
    SAY_INTRO_CAPERNIAN                 = -1550017,
    SAY_INTRO_TELONICUS                 = -1550018,
    SAY_INTRO_THALADRED                 = -1550019,
    SAY_INTRO_SANGUINAR                 = -1550020,
    SAY_PHASE2_WEAPON                   = -1550021,
    SAY_PHASE3_ADVANCE                  = -1550022,
    SAY_PHASE4_INTRO2                   = -1550023,
    SAY_PHASE5_NUTS                     = -1550024,
    SAY_SLAY1                           = -1550025,
    SAY_SLAY2                           = -1550026,
    SAY_SLAY3                           = -1550027,
    SAY_MINDCONTROL1                    = -1550028,
    SAY_MINDCONTROL2                    = -1550029,
    SAY_GRAVITYLAPSE1                   = -1550030,
    SAY_GRAVITYLAPSE2                   = -1550031,
    SAY_SUMMON_PHOENIX1                 = -1550032,
    SAY_SUMMON_PHOENIX2                 = -1550033,
    SAY_DEATH                           = -1550034,

    //Thaladred the Darkener speech
    SAY_THALADRED_AGGRO                 = -1550035,
    SAY_THALADRED_DEATH                 = -1550036,
    EMOTE_THALADRED_GAZE                = -1550037,

    //Lord Sanguinar speech
    SAY_SANGUINAR_AGGRO                 = -1550038,
    SAY_SANGUINAR_DEATH                 = -1550039,

    //Grand Astromancer Capernian speech
    SAY_CAPERNIAN_AGGRO                 = -1550040,
    SAY_CAPERNIAN_DEATH                 = -1550041,

    //Master Engineer Telonicus speech
    SAY_TELONICUS_AGGRO                 = -1550042,
    SAY_TELONICUS_DEATH                 = -1550043,

    //Phase 2 spells
    SPELL_SUMMON_WEAPONS                = 36976,
    SPELL_SUMMON_WEAPONA                = 36958,
    SPELL_SUMMON_WEAPONB                = 36959,
    SPELL_SUMMON_WEAPONC                = 36960,
    SPELL_SUMMON_WEAPOND                = 36961,
    SPELL_SUMMON_WEAPONE                = 36962,
    SPELL_SUMMON_WEAPONF                = 36963,
    SPELL_SUMMON_WEAPONG                = 36964,
    SPELL_RES_VISUAL                    = 24171,

    //Phase 4 spells
    SPELL_FIREBALL                      = 22088,           //wrong but works with CastCustomSpell
    SPELL_PYROBLAST                     = 36819,
    SPELL_FLAME_STRIKE                  = 36735,
    SPELL_FLAME_STRIKE_VIS              = 36730,
    SPELL_FLAME_STRIKE_DMG              = 36731,
    SPELL_ARCANE_DISRUPTION             = 36834,
    SPELL_SHOCK_BARRIER                 = 36815,
    SPELL_PHOENIX_ANIMATION             = 36723,
    SPELL_MIND_CONTROL                  = 32830,

    //Phase 5 spells
    SPELL_EXPLODE                       = 36092,
    SPELL_FULLPOWER                     = 36187,
    SPELL_KNOCKBACK                     = 11027,
    SPELL_GRAVITY_LAPSE                 = 34480,
    SPELL_GRAVITY_LAPSE_AURA            = 39432,
    SPELL_NETHER_BEAM                   = 35873,

    //Thaladred the Darkener spells
    SPELL_PSYCHIC_BLOW                  = 10689,
    SPELL_SILENCE                       = 30225,
    //Lord Sanguinar spells
    SPELL_BELLOWING_ROAR                = 40636,
    //Grand Astromancer Capernian spells

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
    SPELL_REBIRTH                       = 41587,

    //Creature IDs
    NPC_PHOENIX                         = 21362,
    NPC_PHOENIX_EGG                     = 21364,

    //Phoenix egg and phoenix model
    MODEL_ID_PHOENIX                    = 19682,
    MODEL_ID_PHOENIX_EGG                = 20245,

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
    advisorbase_ai(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        m_bDoubled_Health = false;
    }

    ScriptedInstance* m_pInstance;
    bool FakeDeath;
    bool m_bDoubled_Health;
    uint32 DelayRes_Timer;
    uint64 DelayRes_Target;

    void Reset()
    {
        if (m_bDoubled_Health)
        {
            m_creature->SetMaxHealth(m_creature->GetMaxHealth() / 2);
            m_bDoubled_Health = false;
        }

        FakeDeath = false;
        DelayRes_Timer = 0;
        DelayRes_Target = 0;

        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        //reset encounter
        if (m_pInstance && (m_pInstance->GetData(DATA_KAELTHASEVENT) == 1 || m_pInstance->GetData(DATA_KAELTHASEVENT) == 3))
            if (Creature *Kaelthas = Unit::GetCreature((*m_creature), m_pInstance->GetData64(DATA_KAELTHAS)))
                Kaelthas->AI()->EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || FakeDeath || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void AttackStart(Unit* who)
    {
        if (!who || FakeDeath || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::AttackStart(who);
    }

    void Revive(Unit* Target)
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        // double health for phase 3
        m_creature->SetMaxHealth(m_creature->GetMaxHealth() * 2);
        m_bDoubled_Health = true;
        m_creature->SetHealth(m_creature->GetMaxHealth());
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        DoCast(m_creature, SPELL_RES_VISUAL, false);
        DelayRes_Timer = 2000;
    }

    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if (damage < m_creature->GetHealth())
            return;

        //Prevent glitch if in fake death
        if (FakeDeath && m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) != 0)
        {
            damage = 0;
            return;
        }

        //Don't really die in phase 1 & 3, only die after that
        if (m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) != 0)
        {
            //prevent death
            damage = 0;
            FakeDeath = true;

            m_creature->InterruptNonMeleeSpells(false);
            m_creature->SetHealth(0);
            m_creature->StopMoving();
            m_creature->ClearComboPointHolders();
            m_creature->RemoveAllAurasOnDeath();
            m_creature->ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
            m_creature->ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->ClearAllReactives();
            m_creature->SetUInt64Value(UNIT_FIELD_TARGET,0);
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MoveIdle();
            m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
            JustDied(pKiller);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (DelayRes_Timer)
        {
            if (DelayRes_Timer <= diff)
            {
                DelayRes_Timer = 0;
                FakeDeath = false;

                Unit* Target = Unit::GetUnit((*m_creature), DelayRes_Target);
                if (!Target)
                    Target = m_creature->getVictim();

                DoResetThreat();
                AttackStart(Target);
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MoveChase(Target);
                m_creature->AddThreat(Target, 0.0f);
            } else DelayRes_Timer -= diff;
        }
    }

};

//Kael'thas AI
struct boss_kaelthasAI : public ScriptedAI
{
    boss_kaelthasAI(Creature* pCreature) : ScriptedAI(pCreature), summons(m_creature)
    {
        m_pInstance = pCreature->GetInstanceData();
        memset(&m_auiAdvisorGuid, 0, sizeof(m_auiAdvisorGuid));
    }

    ScriptedInstance* m_pInstance;

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

    void Reset()
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

        if (m_creature->isInCombat())
            PrepareAdvisors();

        summons.DespawnAll();

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        if (m_pInstance)
            m_pInstance->SetData(DATA_KAELTHASEVENT, 0);
    }

    void PrepareAdvisors()
    {
        for (uint8 i = 0; i < MAX_ADVISORS; ++i)
        {
            if (Creature *pCreature = Unit::GetCreature((*m_creature), m_auiAdvisorGuid[i]))
            {
                pCreature->Respawn();
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pCreature->setFaction(m_creature->getFaction());
                pCreature->AI()->EnterEvadeMode();
            }
        }
    }

    void StartEvent()
    {
        if (!m_pInstance)
            return;

        m_auiAdvisorGuid[0] = m_pInstance->GetData64(DATA_THALADREDTHEDARKENER);
        m_auiAdvisorGuid[1] = m_pInstance->GetData64(DATA_LORDSANGUINAR);
        m_auiAdvisorGuid[2] = m_pInstance->GetData64(DATA_GRANDASTROMANCERCAPERNIAN);
        m_auiAdvisorGuid[3] = m_pInstance->GetData64(DATA_MASTERENGINEERTELONICUS);

        if (!m_auiAdvisorGuid[0] || !m_auiAdvisorGuid[1] || !m_auiAdvisorGuid[2] || !m_auiAdvisorGuid[3])
        {
            error_log("TSCR: Kael'Thas One or more advisors missing, Skipping Phases 1-3");

            DoScriptText(SAY_PHASE4_INTRO2, m_creature);

            Phase = 4;

            m_pInstance->SetData(DATA_KAELTHASEVENT, 4);

            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                AttackStart(pTarget);

        }
        else
        {
            PrepareAdvisors();

            DoScriptText(SAY_INTRO, m_creature);

            m_pInstance->SetData(DATA_KAELTHASEVENT, 1);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            PhaseSubphase = 0;
            Phase_Timer = 23000;
            Phase = 1;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->hasUnitState(UNIT_STAT_STUNNED) && who->isTargetableForAttack() &&
            m_creature->IsHostileTo(who) && who->isInAccessiblePlaceFor(m_creature))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if (!m_creature->getVictim() && Phase >= 4)
                {
                    who->RemoveAurasDueToSpell(SPELL_AURA_MOD_STEALTH);
                    AttackStart(who);
                }
                else if (m_creature->GetMap()->IsDungeon())
                {
                    if (m_pInstance && !m_pInstance->GetData(DATA_KAELTHASEVENT) && !Phase)
                        StartEvent();

                    who->SetInCombatWith(m_creature);
                    m_creature->AddThreat(who, 0.0f);
                }
            }
        }
    }

    void Aggro(Unit *who)
    {
        if (m_pInstance && !m_pInstance->GetData(DATA_KAELTHASEVENT) && !Phase)
            StartEvent();
    }

    void KilledUnit()
    {
        DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2,SAY_SLAY3), m_creature);
    }

    void JustSummoned(Creature* pSummoned)
    {
        // if not phoenix, then it's one of the 7 weapons
        if (pSummoned->GetEntry() != NPC_PHOENIX)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                pSummoned->AI()->AttackStart(pTarget);

            summons.Summon(pSummoned);
        }
    }

    void SummonedCreatureDespawn(Creature *summon) {summons.Despawn(summon);}

    void JustDied(Unit* Killer)
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        DoScriptText(SAY_DEATH, m_creature);

        summons.DespawnAll();

        if (m_pInstance)
            m_pInstance->SetData(DATA_KAELTHASEVENT, 0);

        for (uint8 i = 0; i < MAX_ADVISORS; ++i)
        {
            if (Unit* pAdvisor = Unit::GetUnit((*m_creature), m_auiAdvisorGuid[i]))
                pAdvisor->Kill(pAdvisor);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Phase 1
        switch (Phase)
        {
            case 1:
            {
                Unit *pTarget = NULL;
                Creature* Advisor = NULL;

                //Subphase switch
                switch(PhaseSubphase)
                {
                    //Subphase 1 - Start
                    case 0:
                        if (Phase_Timer <= diff)
                        {
                            DoScriptText(SAY_INTRO_THALADRED, m_creature);

                            //start advisor within 7 seconds
                            Phase_Timer = 7000;
                            ++PhaseSubphase;
                        } else Phase_Timer -= diff;
                        break;

                    //Subphase 1 - Unlock advisor
                    case 1:
                        if (Phase_Timer <= diff)
                        {
                            Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[0]));

                            if (Advisor)
                            {
                                Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Advisor->setFaction(m_creature->getFaction());

                                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                                if (pTarget)
                                    Advisor->AI()->AttackStart(pTarget);
                            }

                            ++PhaseSubphase;
                        } else Phase_Timer -= diff;
                        break;

                    //Subphase 2 - Start
                    case 2:
                        Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[0]));

                        if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                        {
                            DoScriptText(SAY_INTRO_SANGUINAR, m_creature);

                            //start advisor within 12.5 seconds
                            Phase_Timer = 12500;
                            ++PhaseSubphase;
                        }
                        break;

                    //Subphase 2 - Unlock advisor
                    case 3:
                        if (Phase_Timer <= diff)
                        {
                            Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[1]));

                            if (Advisor)
                            {
                                Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Advisor->setFaction(m_creature->getFaction());

                                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                                if (pTarget)
                                    Advisor->AI()->AttackStart(pTarget);
                            }

                            ++PhaseSubphase;
                        } else Phase_Timer -= diff;
                        break;

                    //Subphase 3 - Start
                    case 4:
                        Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[1]));

                        if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                        {
                            DoScriptText(SAY_INTRO_CAPERNIAN, m_creature);

                            //start advisor within 7 seconds
                            Phase_Timer = 7000;
                            ++PhaseSubphase;
                        }
                        break;

                    //Subphase 3 - Unlock advisor
                    case 5:
                        if (Phase_Timer <= diff)
                        {
                            Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[2]));

                            if (Advisor)
                            {
                                Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Advisor->setFaction(m_creature->getFaction());

                                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                                if (pTarget)
                                    Advisor->AI()->AttackStart(pTarget);
                            }

                            ++PhaseSubphase;
                        } else Phase_Timer -= diff;
                        break;

                    //Subphase 4 - Start
                    case 6:
                        Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[2]));

                        if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                        {
                            DoScriptText(SAY_INTRO_TELONICUS, m_creature);

                            //start advisor within 8.4 seconds
                            Phase_Timer = 8400;
                            ++PhaseSubphase;
                        }
                        break;

                    //Subphase 4 - Unlock advisor
                    case 7:
                        if (Phase_Timer <= diff)
                        {
                            Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[3]));

                            if (Advisor)
                            {
                                Advisor->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Advisor->setFaction(m_creature->getFaction());

                                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                                if (pTarget)
                                    Advisor->AI()->AttackStart(pTarget);
                            }

                            Phase_Timer = 3000;
                            ++PhaseSubphase;
                        } else Phase_Timer -= diff;
                        break;

                    //End of phase 1
                    case 8:
                        Advisor = (Unit::GetCreature((*m_creature), m_auiAdvisorGuid[3]));

                        if (Advisor && (Advisor->getStandState() == UNIT_STAND_STATE_DEAD))
                        {
                            Phase = 2;
                            if(m_pInstance)
                                m_pInstance->SetData(DATA_KAELTHASEVENT, 2);

                            DoScriptText(SAY_PHASE2_WEAPON, m_creature);

                            PhaseSubphase = 0;
                            Phase_Timer = 3500;
                            DoCast(m_creature, SPELL_SUMMON_WEAPONS);
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
                    } else Phase_Timer -= diff;
                }

                //Spawn weapons
                if (PhaseSubphase == 1)
                {
                    DoCast(m_creature, SPELL_SUMMON_WEAPONS, false);

                    uint8 uiMaxWeapon = sizeof(m_auiSpellSummonWeapon)/sizeof(uint32);

                    for (uint32 i = 0; i < uiMaxWeapon; ++i)
                        DoCast(m_creature, m_auiSpellSummonWeapon[i], true);

                    PhaseSubphase = 2;
                    Phase_Timer = TIME_PHASE_2_3;
                }

                if (PhaseSubphase == 2)
                {
                    if (Phase_Timer <= diff)
                    {
                        DoScriptText(SAY_PHASE3_ADVANCE, m_creature);
                        if(m_pInstance)
                            m_pInstance->SetData(DATA_KAELTHASEVENT, 3);
                        Phase = 3;
                        PhaseSubphase = 0;
                    } else Phase_Timer -= diff;
                }
            }
            break;

            case 3:
            {
                if (PhaseSubphase == 0)
                {
                    //Respawn advisors
                    Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

                    Creature *Advisor;
                    for (uint8 i = 0; i < MAX_ADVISORS; ++i)
                    {
                        Advisor = Unit::GetCreature((*m_creature), m_auiAdvisorGuid[i]);

                        if (!Advisor)
                            error_log("SD2: Kael'Thas Advisor %u does not exist. Possibly despawned? Incorrectly Killed?", i);
                        else
                            CAST_AI(advisorbase_ai, Advisor->AI())->Revive(pTarget);
                    }

                    PhaseSubphase = 1;
                    Phase_Timer = TIME_PHASE_3_4;
                }

                if (Phase_Timer <= diff)
                {
                    DoScriptText(SAY_PHASE4_INTRO2, m_creature);
                    Phase = 4;

                    if(m_pInstance)
                        m_pInstance->SetData(DATA_KAELTHASEVENT, 4);

                    // Sometimes people can collect Aggro in Phase 1-3. Reset threat before releasing Kael.
                    DoResetThreat();

                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        AttackStart(pTarget);

                    Phase_Timer = 30000;
                } else Phase_Timer -= diff;
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
                            if (!m_creature->IsNonMeleeSpellCasted(false))
                            {
                                //interruptable
                                m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, false);
                                int32 dmg = 20000+rand()%5000;
                                m_creature->CastCustomSpell(m_creature->getVictim(), SPELL_FIREBALL, &dmg, 0, 0, false);
                                IsCastingFireball = true;
                                Fireball_Timer = 2500;
                            }
                        }
                        else
                        {
                            //apply resistance
                            m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                            IsCastingFireball = false;
                            Fireball_Timer = 5000+rand()%10000;
                        }
                    } else Fireball_Timer -= diff;

                    //ArcaneDisruption_Timer
                    if (ArcaneDisruption_Timer <= diff)
                    {
                        DoCast(m_creature->getVictim(), SPELL_ARCANE_DISRUPTION, true);
                        ArcaneDisruption_Timer = 60000;
                    } else ArcaneDisruption_Timer -= diff;

                    if (FlameStrike_Timer <= diff)
                    {
                        if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pUnit, SPELL_FLAME_STRIKE);

                        FlameStrike_Timer = 30000;
                    } else FlameStrike_Timer -= diff;

                    if (MindControl_Timer <= diff)
                    {
                        if (m_creature->getThreatManager().getThreatList().size() >= 2)
                            for (uint32 i = 0; i < 3; ++i)
                        {
                            debug_log("SD2: Kael'Thas mind control not supported.");
                            //DoCast(pUnit, SPELL_MIND_CONTROL);
                        }

                        MindControl_Timer = 60000;
                    } else MindControl_Timer -= diff;
                }

                //Phoenix_Timer
                if (Phoenix_Timer <= diff)
                {
                    DoCast(m_creature, SPELL_PHOENIX_ANIMATION);
                    DoScriptText(RAND(SAY_SUMMON_PHOENIX1,SAY_SUMMON_PHOENIX2), m_creature);

                    Phoenix_Timer = 60000;
                } else Phoenix_Timer -= diff;

                //Phase 4 specific spells
                if (Phase == 4)
                {
                    if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 50)
                    {
                        if(m_pInstance)
                            m_pInstance->SetData(DATA_KAELTHASEVENT, 4);
                        Phase = 5;
                        Phase_Timer = 10000;

                        DoScriptText(SAY_PHASE5_NUTS, m_creature);

                        m_creature->StopMoving();
                        m_creature->GetMotionMaster()->Clear();
                        m_creature->GetMotionMaster()->MoveIdle();
                        m_creature->GetMap()->CreatureRelocation(m_creature, afGravityPos[0], afGravityPos[1], afGravityPos[2], 0);
                        m_creature->SendMonsterMove(afGravityPos[0], afGravityPos[1], afGravityPos[2], 0, 0, 0);

                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(m_creature, SPELL_FULLPOWER);
                        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }

                    //ShockBarrier_Timer
                    if (ShockBarrier_Timer <= diff)
                    {
                        DoCast(m_creature, SPELL_SHOCK_BARRIER);
                        ChainPyros = true;
                        PyrosCasted = 0;
                        ShockBarrier_Timer = 60000;
                    } else ShockBarrier_Timer -= diff;

                    //Chain Pyros (3 of them max)
                    if (ChainPyros && !m_creature->IsNonMeleeSpellCasted(false))
                    {
                        if (PyrosCasted < 3)
                        {
                            DoCast(m_creature->getVictim(), SPELL_PYROBLAST);
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
                        m_creature->InterruptNonMeleeSpells(false);
                        m_creature->RemoveAurasDueToSpell(SPELL_FULLPOWER);

                        DoCast(m_creature, SPELL_EXPLODE);

                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        Phase = 6;
                        AttackStart(m_creature->getVictim());
                    } else Phase_Timer -= diff;
                }

                //Phase 5
                if (Phase == 6)
                {

                    //GravityLapse_Timer
                    if (GravityLapse_Timer <= diff)
                    {
                        std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                        switch (GravityLapse_Phase)
                        {
                            case 0:
                                m_creature->StopMoving();
                                m_creature->GetMotionMaster()->Clear();
                                m_creature->GetMotionMaster()->MoveIdle();
                                m_creature->GetMap()->CreatureRelocation(m_creature, afGravityPos[0], afGravityPos[1], afGravityPos[2], 0);
                                m_creature->SendMonsterMove(afGravityPos[0], afGravityPos[1], afGravityPos[2], 0, MOVEMENTFLAG_NONE, 0);

                                // 1) Kael'thas will portal the whole raid right into his body
                                for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end(); ++i)
                                {
                                    Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
                                    if (pUnit && (pUnit->GetTypeId() == TYPEID_PLAYER))
                                    {
                                        //Use work around packet to prevent player from being dropped from combat
                                        DoTeleportPlayer(pUnit, afGravityPos[0], afGravityPos[1], afGravityPos[2], pUnit->GetOrientation());
                                    }
                                }

                                GravityLapse_Timer = 500;
                                ++GravityLapse_Phase;
                                InGravityLapse = true;
                                ShockBarrier_Timer = 1000;
                                NetherBeam_Timer = 5000;
                                break;

                            case 1:
                                DoScriptText(RAND(SAY_GRAVITYLAPSE1,SAY_GRAVITYLAPSE2), m_creature);

                                // 2) At that point he will put a Gravity Lapse debuff on everyone
                                for (i = m_creature->getThreatManager().getThreatList().begin(); i != m_creature->getThreatManager().getThreatList().end(); ++i)
                                {
                                    if (Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid()))
                                    {
                                        DoCast(pUnit, SPELL_KNOCKBACK, true);
                                        //Gravity lapse - needs an exception in Spell system to work

                                        pUnit->CastSpell(pUnit, SPELL_GRAVITY_LAPSE, true, 0, 0, m_creature->GetGUID());
                                        pUnit->CastSpell(pUnit, SPELL_GRAVITY_LAPSE_AURA, true, 0, 0, m_creature->GetGUID());

                                        //Using packet workaround
                                        WorldPacket data(12);
                                        data.SetOpcode(SMSG_MOVE_SET_CAN_FLY);
                                        data.append(pUnit->GetPackGUID());
                                        data << uint32(0);
                                        pUnit->SendMessageToSet(&data, true);
                                    }
                                }
                                GravityLapse_Timer = 10000;
                                ++GravityLapse_Phase;
                                break;

                            case 2:
                                //Cast nether vapor aura on self
                                m_creature->InterruptNonMeleeSpells(false);
                                DoCast(m_creature, SPELL_NETHER_VAPOR);

                                GravityLapse_Timer = 20000;
                                ++GravityLapse_Phase;
                                break;

                            case 3:
                                //Remove flight
                                for (i = m_creature->getThreatManager().getThreatList().begin(); i!= m_creature->getThreatManager().getThreatList().end(); ++i)
                                {
                                    if (Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid()))
                                    {
                                        //Using packet workaround
                                        WorldPacket data(12);
                                        data.SetOpcode(SMSG_MOVE_UNSET_CAN_FLY);
                                        data.append(pUnit->GetPackGUID());
                                        data << uint32(0);
                                        pUnit->SendMessageToSet(&data, true);
                                    }
                                }

                                m_creature->RemoveAurasDueToSpell(SPELL_NETHER_VAPOR);
                                InGravityLapse = false;
                                GravityLapse_Timer = 60000;
                                GravityLapse_Phase = 0;
                                AttackStart(m_creature->getVictim());
                                break;
                        }
                    } else GravityLapse_Timer -= diff;

                    if (InGravityLapse)
                    {
                        //ShockBarrier_Timer
                        if (ShockBarrier_Timer <= diff)
                        {
                            DoCast(m_creature, SPELL_SHOCK_BARRIER);
                            ShockBarrier_Timer = 20000;
                        } else ShockBarrier_Timer -= diff;

                        //NetherBeam_Timer
                        if (NetherBeam_Timer <= diff)
                        {
                            if (Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0))
                                DoCast(pUnit, SPELL_NETHER_BEAM);

                            NetherBeam_Timer = 4000;
                        } else NetherBeam_Timer -= diff;
                    }
                }

                if (!InGravityLapse)
                    DoMeleeAttackIfReady();
            }
        }
    }
};

//Thaladred the Darkener AI
struct boss_thaladred_the_darkenerAI : public advisorbase_ai
{
    boss_thaladred_the_darkenerAI(Creature* pCreature) : advisorbase_ai(pCreature) {}

    uint32 Gaze_Timer;
    uint32 Silence_Timer;
    uint32 PsychicBlow_Timer;

    void Reset()
    {
        Gaze_Timer = 100;
        Silence_Timer = 20000;
        PsychicBlow_Timer = 10000;

        advisorbase_ai::Reset();
    }

    void Aggro(Unit *who)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (!who || FakeDeath)
            return;

        DoScriptText(SAY_THALADRED_AGGRO, m_creature);
        m_creature->AddThreat(who, 5000000.0f);
    }

    void JustDied(Unit* pKiller)
    {
        if (m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) == 3)
            DoScriptText(SAY_THALADRED_DEATH, m_creature);
    }

    void UpdateAI(const uint32 diff)
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
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                DoResetThreat();
                m_creature->AddThreat(pTarget, 5000000.0f);
                DoScriptText(EMOTE_THALADRED_GAZE, m_creature, pTarget);
                Gaze_Timer = 8500;
            }
        } else Gaze_Timer -= diff;

        //Silence_Timer
        if (Silence_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SILENCE);
            Silence_Timer = 20000;
        } else Silence_Timer -= diff;

        //PsychicBlow_Timer
        if (PsychicBlow_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_PSYCHIC_BLOW);
            PsychicBlow_Timer = 20000+rand()%5000;
        } else PsychicBlow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Lord Sanguinar AI
struct boss_lord_sanguinarAI : public advisorbase_ai
{
    boss_lord_sanguinarAI(Creature* pCreature) : advisorbase_ai(pCreature) {}

    uint32 Fear_Timer;

    void Reset()
    {
        Fear_Timer = 20000;
        advisorbase_ai::Reset();
    }

    void Aggro(Unit *who)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (!who || FakeDeath)
            return;

        DoScriptText(SAY_SANGUINAR_AGGRO, m_creature);
    }

    void JustDied(Unit* Killer)
    {
        if (m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) == 3)
            DoScriptText(SAY_SANGUINAR_DEATH, m_creature);
    }

    void UpdateAI(const uint32 diff)
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
            DoCast(m_creature->getVictim(), SPELL_BELLOWING_ROAR);
            Fear_Timer = 25000+rand()%10000;                //approximately every 30 seconds
        } else Fear_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Grand Astromancer Capernian AI
struct boss_grand_astromancer_capernianAI : public advisorbase_ai
{
    boss_grand_astromancer_capernianAI(Creature* pCreature) : advisorbase_ai(pCreature) {}

    uint32 Fireball_Timer;
    uint32 Conflagration_Timer;
    uint32 ArcaneExplosion_Timer;
    uint32 Yell_Timer;
    bool Yell;

    void Reset()
    {
        Fireball_Timer = 2000;
        Conflagration_Timer = 20000;
        ArcaneExplosion_Timer = 5000;
        Yell_Timer = 2000;
        Yell = false;

        advisorbase_ai::Reset();
    }

    void JustDied(Unit* pKiller)
    {
        if (m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) == 3)
            DoScriptText(SAY_CAPERNIAN_DEATH, m_creature);
    }

    void AttackStart(Unit* who)
    {
        if (!who || FakeDeath || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);

            m_creature->GetMotionMaster()->MoveChase(who, CAPERNIAN_DISTANCE);
        }
    }

    void Aggro(Unit *who)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (!who || FakeDeath)
            return;
    }

    void UpdateAI(const uint32 diff)
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
                DoScriptText(SAY_CAPERNIAN_AGGRO, m_creature);
                Yell = true;
            } else Yell_Timer -= diff;
        }

        //Fireball_Timer
        if (Fireball_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CAPERNIAN_FIREBALL);
            Fireball_Timer = 4000;
        } else Fireball_Timer -= diff;

        //Conflagration_Timer
        if (Conflagration_Timer <= diff)
        {
            Unit *pTarget = NULL;
            pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if (pTarget && m_creature->IsWithinDistInMap(pTarget, 30))
                DoCast(pTarget, SPELL_CONFLAGRATION);
            else
                DoCast(m_creature->getVictim(), SPELL_CONFLAGRATION);

            Conflagration_Timer = 10000+rand()%5000;
        } else Conflagration_Timer -= diff;

        //ArcaneExplosion_Timer
        if (ArcaneExplosion_Timer <= diff)
        {
            bool InMeleeRange = false;
            Unit *pTarget = NULL;
            std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
            for (std::list<HostilReference*>::iterator i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
            {
                Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
                                                            //if in melee range
                if (pUnit && pUnit->IsWithinDistInMap(m_creature, 5))
                {
                    InMeleeRange = true;
                    pTarget = pUnit;
                    break;
                }
            }

            if (InMeleeRange)
                DoCast(pTarget, SPELL_ARCANE_EXPLOSION);

            ArcaneExplosion_Timer = 4000+rand()%2000;
        } else ArcaneExplosion_Timer -= diff;

        //Do NOT deal any melee damage.
    }
};

//Master Engineer Telonicus AI
struct boss_master_engineer_telonicusAI : public advisorbase_ai
{
    boss_master_engineer_telonicusAI(Creature* pCreature) : advisorbase_ai(pCreature) {}

    uint32 Bomb_Timer;
    uint32 RemoteToy_Timer;

    void Reset()
    {
        Bomb_Timer = 10000;
        RemoteToy_Timer = 5000;

        advisorbase_ai::Reset();
    }

    void JustDied(Unit* pKiller)
    {
        if (m_pInstance && m_pInstance->GetData(DATA_KAELTHASEVENT) == 3)
            DoScriptText(SAY_TELONICUS_DEATH, m_creature);
    }

    void Aggro(Unit *who)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (!who || FakeDeath)
            return;

        DoScriptText(SAY_TELONICUS_AGGRO, m_creature);
    }

    void UpdateAI(const uint32 diff)
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
            DoCast(m_creature->getVictim(), SPELL_BOMB);
            Bomb_Timer = 25000;
        } else Bomb_Timer -= diff;

        //RemoteToy_Timer
        if (RemoteToy_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, SPELL_REMOTE_TOY);

            RemoteToy_Timer = 10000+rand()%5000;
        } else RemoteToy_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Flame Strike AI
struct mob_kael_flamestrikeAI : public Scripted_NoMovementAI
{
    mob_kael_flamestrikeAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) {}

    uint32 Timer;
    bool Casting;
    bool KillSelf;

    void Reset()
    {
        Timer = 5000;
        Casting = false;
        KillSelf = false;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->setFaction(14);
    }

    void MoveInLineOfSight(Unit *who) {}

    void EnterCombat(Unit *who) {return;}

    void UpdateAI(const uint32 diff)
    {
        if (!Casting)
        {
            DoCast(m_creature, SPELL_FLAME_STRIKE_VIS);
            Casting = true;
        }

        //Timer
        if (Timer <= diff)
        {
            if (!KillSelf)
            {
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(m_creature, SPELL_FLAME_STRIKE_DMG);
            } else m_creature->Kill(m_creature);

            KillSelf = true;
            Timer = 1000;
        } else Timer -= diff;
    }
};

//Phoenix AI
struct mob_phoenix_tkAI : public ScriptedAI
{
    mob_phoenix_tkAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 Cycle_Timer;

    void Reset()
    {
        Cycle_Timer = 2000;
        DoCast(m_creature, SPELL_BURN, true);
    }

    void JustDied(Unit* killer)
    {
        //is this spell in use anylonger?
        //DoCast(m_creature, SPELL_EMBER_BLAST, true);
        m_creature->SummonCreature(NPC_PHOENIX_EGG,m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(),m_creature->GetOrientation(),TEMPSUMMON_TIMED_DESPAWN,16000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (Cycle_Timer <= diff)
        {
            //spell Burn should possible do this, but it doesn't, so do this for now.
            uint32 dmg = urand(4500,5500);
            if (m_creature->GetHealth() > dmg)
                m_creature->SetHealth(uint32(m_creature->GetHealth()-dmg));
            Cycle_Timer = 2000;
        } else Cycle_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Phoenix Egg AI
struct mob_phoenix_egg_tkAI : public ScriptedAI
{
    mob_phoenix_egg_tkAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 Rebirth_Timer;

    void Reset()
    {
        Rebirth_Timer = 15000;
    }

    //ignore any
    void MoveInLineOfSight(Unit* who) { return; }

    void AttackStart(Unit* who)
    {
        if (m_creature->Attack(who, false))
        {
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);

            DoStartNoMovement(who);
        }
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AddThreat(m_creature->getVictim(), 0.0f);
        summoned->CastSpell(summoned,SPELL_REBIRTH,false);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!Rebirth_Timer)
            return;

        if (Rebirth_Timer <= diff)
        {
            m_creature->SummonCreature(NPC_PHOENIX,m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(),m_creature->GetOrientation(),TEMPSUMMON_CORPSE_DESPAWN,5000);
            Rebirth_Timer = 0;
        } else Rebirth_Timer -= diff;
    }
};

CreatureAI* GetAI_boss_kaelthas(Creature* pCreature)
{
    return new boss_kaelthasAI(pCreature);
}

CreatureAI* GetAI_boss_thaladred_the_darkener(Creature* pCreature)
{
    return new boss_thaladred_the_darkenerAI(pCreature);
}

CreatureAI* GetAI_boss_lord_sanguinar(Creature* pCreature)
{
    return new boss_lord_sanguinarAI(pCreature);
}

CreatureAI* GetAI_boss_grand_astromancer_capernian(Creature* pCreature)
{
    return new boss_grand_astromancer_capernianAI(pCreature);
}

CreatureAI* GetAI_boss_master_engineer_telonicus(Creature* pCreature)
{
    return new boss_master_engineer_telonicusAI(pCreature);
}

CreatureAI* GetAI_mob_kael_flamestrike(Creature* pCreature)
{
    return new mob_kael_flamestrikeAI(pCreature);
}

CreatureAI* GetAI_mob_phoenix_tk(Creature* pCreature)
{
    return new mob_phoenix_tkAI(pCreature);
}

CreatureAI* GetAI_mob_phoenix_egg_tk(Creature* pCreature)
{
    return new mob_phoenix_egg_tkAI(pCreature);
}

void AddSC_boss_kaelthas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_kaelthas";
    newscript->GetAI = &GetAI_boss_kaelthas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_thaladred_the_darkener";
    newscript->GetAI = &GetAI_boss_thaladred_the_darkener;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_lord_sanguinar";
    newscript->GetAI = &GetAI_boss_lord_sanguinar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_grand_astromancer_capernian";
    newscript->GetAI = &GetAI_boss_grand_astromancer_capernian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_master_engineer_telonicus";
    newscript->GetAI = &GetAI_boss_master_engineer_telonicus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_kael_flamestrike";
    newscript->GetAI = &GetAI_mob_kael_flamestrike;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_phoenix_tk";
    newscript->GetAI = &GetAI_mob_phoenix_tk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_phoenix_egg_tk";
    newscript->GetAI = &GetAI_mob_phoenix_egg_tk;
    newscript->RegisterSelf();
}
