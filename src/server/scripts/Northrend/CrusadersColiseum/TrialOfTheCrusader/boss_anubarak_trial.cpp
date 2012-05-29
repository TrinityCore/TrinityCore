/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_anubarak_trial
SD%Complete: ??%
SDComment: based on /dev/rsa
SDCategory:
EndScriptData */

// Known bugs:
// Anubarak - underground phase partially not worked
//          - tele after impale hit a permafrost doesn't work (the entire tele spell should be better)
// Burrow   - visual is vanishing
// Burrower - Spider Frenzy not working as it should (frenzy not stacking)
// Scarab   - Kill credit isn't crediting?
// FrostSph - often they are casting Permafrost a little above the ground

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"

enum Yells
{
    SAY_INTRO               = -1649055,
    SAY_AGGRO               = -1649056,
    SAY_KILL1               = -1649057,
    SAY_KILL2               = -1649058,
    SAY_DEATH               = -1649059,
    EMOTE_SPIKE             = -1649060,
    SAY_BURROWER            = -1649061,
    EMOTE_LEECHING_SWARM    = -1649062,
    SAY_LEECHING_SWARM      = -1649063,
};

enum Summons
{
    NPC_FROST_SPHERE     = 34606,
    NPC_BURROW           = 34862,
    NPC_BURROWER         = 34607,
    NPC_SCARAB           = 34605,
    NPC_SPIKE            = 34660,
};

enum BossSpells
{
    SPELL_FREEZE_SLASH      = 66012,
    SPELL_PENETRATING_COLD  = 66013,
    SPELL_LEECHING_SWARM    = 66118,
    SPELL_LEECHING_HEAL     = 66125,
    SPELL_LEECHING_DAMAGE   = 66240,
    SPELL_MARK              = 67574,
    SPELL_SPIKE_CALL        = 66169,
    SPELL_SUBMERGE_ANUBARAK = 65981,
    SPELL_CLEAR_ALL_DEBUFFS = 34098,
    SPELL_EMERGE_ANUBARAK   = 65982,
    SPELL_SUMMON_BEATLES    = 66339,
    SPELL_SUMMON_BURROWER   = 66332,

    // Burrow
    SPELL_CHURNING_GROUND   = 66969,

    // Scarab
    SPELL_DETERMINATION     = 66092,
    SPELL_ACID_MANDIBLE     = 65774, //Passive - Triggered

    // Burrower
    SPELL_SPIDER_FRENZY     = 66128,
    SPELL_EXPOSE_WEAKNESS   = 67720, //Passive - Triggered
    SPELL_SHADOW_STRIKE     = 66134,
    SPELL_SUBMERGE_EFFECT   = 53421,
    SPELL_EMERGE_EFFECT     = 66947,

    SUMMON_SCARAB           = NPC_SCARAB,
    SUMMON_FROSTSPHERE      = NPC_FROST_SPHERE,
    SPELL_BERSERK           = 26662,

    //Frost Sphere
    SPELL_FROST_SPHERE      = 67539,
    SPELL_PERMAFROST        = 66193,
    SPELL_PERMAFROST_VISUAL = 65882,

    //Spike
    SPELL_SUMMON_SPIKE      = 66169,
    SPELL_SPIKE_SPEED1      = 65920,
    SPELL_SPIKE_TRAIL       = 65921,
    SPELL_SPIKE_SPEED2      = 65922,
    SPELL_SPIKE_SPEED3      = 65923,
    SPELL_SPIKE_FAIL        = 66181,
    SPELL_SPIKE_TELE        = 66170,
};

#define SPELL_PERMAFROST_HELPER RAID_MODE<uint32>(66193, 67855, 67856, 67857)

enum SummonActions
{
    ACTION_SHADOW_STRIKE,
    ACTION_SCARAB_SUBMERGE,
};

const Position SphereSpawn[6] =
{
    { 786.6439f, 108.2498f, 155.6701f, 0 },
    { 806.8429f, 150.5902f, 155.6701f, 0 },
    { 759.1386f, 163.9654f, 155.6701f, 0 },
    { 744.3701f, 119.5211f, 155.6701f, 0 },
    { 710.0211f, 120.8152f, 155.6701f, 0 },
    { 706.6383f, 161.5266f, 155.6701f, 0 },
};

enum MovementPoints
{
    POINT_FALL_GROUND           = 1
};

class boss_anubarak_trial : public CreatureScript
{
public:
    boss_anubarak_trial() : CreatureScript("boss_anubarak_trial") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_anubarak_trialAI(creature);
    };

    struct boss_anubarak_trialAI : public ScriptedAI
    {
        boss_anubarak_trialAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        SummonList Summons;
        std::list<uint64> m_vBurrowGUID;
        uint64 m_aSphereGUID[6];

        uint32 m_uiFreezeSlashTimer;
        uint32 m_uiPenetratingColdTimer;
        uint32 m_uiSummonNerubianTimer;
        uint32 m_uiNerubianShadowStrikeTimer;
        uint32 m_uiSubmergeTimer;
        uint32 m_uiPursuingSpikeTimer;
        uint32 m_uiSummonScarabTimer;
        uint32 m_uiSummonFrostSphereTimer;
        uint32 m_uiBerserkTimer;

        uint8  m_uiStage;
        bool   m_bIntro;
        bool   m_bReachedPhase3;
        uint64 m_uiTargetGUID;
        uint8  m_uiScarabSummoned;

        void Reset()
        {
            m_uiFreezeSlashTimer = 15*IN_MILLISECONDS;
            m_uiPenetratingColdTimer = 20*IN_MILLISECONDS;
            m_uiNerubianShadowStrikeTimer = 30*IN_MILLISECONDS;
            m_uiSummonNerubianTimer = 10*IN_MILLISECONDS;
            m_uiSubmergeTimer = 80*IN_MILLISECONDS;

            m_uiPursuingSpikeTimer = 2*IN_MILLISECONDS;
            m_uiSummonScarabTimer = 2*IN_MILLISECONDS;

            m_uiSummonFrostSphereTimer = 20*IN_MILLISECONDS;

            m_uiBerserkTimer = 10*MINUTE*IN_MILLISECONDS;
            m_uiStage = 0;
            m_uiScarabSummoned = 0;
            m_bIntro = true;
            m_bReachedPhase3 = false;
            m_uiTargetGUID = 0;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            Summons.DespawnAll();
            m_vBurrowGUID.clear();
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                DoScriptText(urand(0, 1) ? SAY_KILL1 : SAY_KILL2, me);
                if (instance)
                    instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
            }
        }

        void MoveInLineOfSight(Unit* /*who*/)
        {
            if (!m_bIntro)
            {
                DoScriptText(SAY_INTRO, me);
                m_bIntro = false;
            }
        }

        void JustReachedHome()
        {
            if (instance)
                instance->SetData(TYPE_ANUBARAK, FAIL);
            //Summon Scarab Swarms neutral at random places
            for (int i=0; i < 10; i++)
                if (Creature* temp = me->SummonCreature(NPC_SCARAB, AnubarakLoc[1].GetPositionX()+urand(0, 50)-25, AnubarakLoc[1].GetPositionY()+urand(0, 50)-25, AnubarakLoc[1].GetPositionZ()))
                    temp->setFaction(31);
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();
            DoScriptText(SAY_DEATH, me);
            if (instance)
                instance->SetData(TYPE_ANUBARAK, DONE);
        }

        void JustSummoned(Creature* summoned)
        {
            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true);
            switch (summoned->GetEntry())
            {
                case NPC_BURROW:
                    m_vBurrowGUID.push_back(summoned->GetGUID());
                    summoned->SetReactState(REACT_PASSIVE);
                    summoned->CastSpell(summoned, SPELL_CHURNING_GROUND, false);
                    break;
                case NPC_SPIKE:
                    summoned->CombatStart(target);
                    DoScriptText(EMOTE_SPIKE, me, target);
                    break;
            }
            Summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summoned)
        {
            switch (summoned->GetEntry())
            {
                case NPC_SPIKE:
                    m_uiPursuingSpikeTimer = 2*IN_MILLISECONDS;
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetInCombatWithZone();
            if (instance)
                instance->SetData(TYPE_ANUBARAK, IN_PROGRESS);
            //Despawn Scarab Swarms neutral
            EntryCheckPredicate pred(NPC_SCARAB);
            Summons.DoAction(ACTION_SCARAB_SUBMERGE, pred);
            //Spawn Burrow
            for (int i=0; i < 4; i++)
                me->SummonCreature(NPC_BURROW, AnubarakLoc[i+2]);
            //Spawn Frost Spheres
            for (int i=0; i < 6; i++)
                if (Unit* summoned = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                    m_aSphereGUID[i] = summoned->GetGUID();
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (m_uiStage)
            {
                case 0:
                    if (m_uiFreezeSlashTimer <= uiDiff)
                    {
                        DoCastVictim(SPELL_FREEZE_SLASH);
                        m_uiFreezeSlashTimer = 15*IN_MILLISECONDS;
                    } else m_uiFreezeSlashTimer -= uiDiff;

                    if (m_uiPenetratingColdTimer <= uiDiff)
                    {
                        me->CastCustomSpell(SPELL_PENETRATING_COLD, SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 5));
                        m_uiPenetratingColdTimer = 20*IN_MILLISECONDS;
                    } else m_uiPenetratingColdTimer -= uiDiff;

                    if (m_uiSummonNerubianTimer <= uiDiff && (IsHeroic() || !m_bReachedPhase3))
                    {
                        me->CastCustomSpell(SPELL_SUMMON_BURROWER, SPELLVALUE_MAX_TARGETS, RAID_MODE(1, 2, 2, 4));
                        m_uiSummonNerubianTimer = 45*IN_MILLISECONDS;
                    } else m_uiSummonNerubianTimer -= uiDiff;

                    if (IsHeroic() && m_uiNerubianShadowStrikeTimer <= uiDiff)
                    {
                        EntryCheckPredicate pred(NPC_BURROWER);
                        Summons.DoAction(ACTION_SHADOW_STRIKE, pred);
                        m_uiNerubianShadowStrikeTimer = 30*IN_MILLISECONDS;
                    } else m_uiNerubianShadowStrikeTimer -= uiDiff;

                    if (m_uiSubmergeTimer <= uiDiff && !m_bReachedPhase3 && !me->HasAura(SPELL_BERSERK))
                    {
                        m_uiStage = 1;
                        m_uiSubmergeTimer = 60*IN_MILLISECONDS;
                    } else m_uiSubmergeTimer -= uiDiff;
                    break;
                case 1:
                    DoCast(me, SPELL_SUBMERGE_ANUBARAK);
                    DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    DoScriptText(SAY_BURROWER, me);
                    m_uiScarabSummoned = 0;
                    m_uiSummonScarabTimer = 4*IN_MILLISECONDS;
                    m_uiStage = 2;
                    break;
                case 2:
                    if (m_uiPursuingSpikeTimer <= uiDiff)
                    {
                        DoCast(SPELL_SPIKE_CALL);
                        // Just to make sure it won't happen again in this phase
                        m_uiPursuingSpikeTimer = 90*IN_MILLISECONDS;
                    } else m_uiPursuingSpikeTimer -= uiDiff;

                    if (m_uiSummonScarabTimer <= uiDiff)
                    {
                        /* WORKAROUND
                         * - The correct implementation is more likely the comment below but it needs spell knowledge
                         */
                        std::list<uint64>::iterator i = m_vBurrowGUID.begin();
                        uint32 at = urand(0, m_vBurrowGUID.size()-1);
                        for (uint32 k = 0; k < at; k++)
                            ++i;
                        if (Creature* pBurrow = Unit::GetCreature(*me, *i))
                            pBurrow->CastSpell(pBurrow, 66340, false);
                        m_uiScarabSummoned++;
                        m_uiSummonScarabTimer = 4*IN_MILLISECONDS;
                        if (m_uiScarabSummoned == 4) m_uiSummonScarabTimer = RAID_MODE(4, 20)*IN_MILLISECONDS;

                        /*It seems that this spell have something more that needs to be taken into account
                        //Need more sniff info
                        DoCast(SPELL_SUMMON_BEATLES);
                        // Just to make sure it won't happen again in this phase
                        m_uiSummonScarabTimer = 90*IN_MILLISECONDS;*/
                    } else m_uiSummonScarabTimer -= uiDiff;

                    if (m_uiSubmergeTimer <= uiDiff)
                    {
                        m_uiStage = 3;
                        m_uiSubmergeTimer = 80*IN_MILLISECONDS;
                    } else m_uiSubmergeTimer -= uiDiff;
                    break;
                case 3:
                    m_uiStage = 0;
                    DoCast(SPELL_SPIKE_TELE);
                    Summons.DespawnEntry(NPC_SPIKE);
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_ANUBARAK);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_EMERGE_ANUBARAK);
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    m_uiSummonNerubianTimer = 10*IN_MILLISECONDS;
                    m_uiNerubianShadowStrikeTimer = 30*IN_MILLISECONDS;
                    m_uiSummonScarabTimer = 2*IN_MILLISECONDS;
                    break;
            }

            if (!IsHeroic())
            {
                if (m_uiSummonFrostSphereTimer <= uiDiff)
                {
                    uint8 startAt = urand(0, 5);
                    uint8 i = startAt;
                    do
                    {
                        if (Unit* pSphere = Unit::GetCreature(*me, m_aSphereGUID[i]))
                        {
                            if (!pSphere->HasAura(SPELL_FROST_SPHERE))
                            {
                                if (Creature* summon = me->SummonCreature(NPC_FROST_SPHERE, SphereSpawn[i]))
                                    m_aSphereGUID[i] = summon->GetGUID();
                                break;
                            }
                        }
                        i = (i+1)%6;
                    } while (i != startAt);
                    m_uiSummonFrostSphereTimer = urand(20, 30)*IN_MILLISECONDS;
                } else m_uiSummonFrostSphereTimer -= uiDiff;
            }

            if (HealthBelowPct(30) && m_uiStage == 0 && !m_bReachedPhase3)
            {
                m_bReachedPhase3 = true;
                DoCastAOE(SPELL_LEECHING_SWARM);
                DoScriptText(EMOTE_LEECHING_SWARM, me);
                DoScriptText(SAY_LEECHING_SWARM, me);
            }

            if (m_uiBerserkTimer <= uiDiff && !me->HasAura(SPELL_BERSERK))
            {
                DoCast(me, SPELL_BERSERK);
            } else m_uiBerserkTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_swarm_scarab : public CreatureScript
{
public:
    mob_swarm_scarab() : CreatureScript("mob_swarm_scarab") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_swarm_scarabAI(creature);
    };

    struct mob_swarm_scarabAI : public ScriptedAI
    {
        mob_swarm_scarabAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiDeterminationTimer;

        void Reset()
        {
            me->SetCorpseDelay(0);
            m_uiDeterminationTimer = urand(5*IN_MILLISECONDS, 60*IN_MILLISECONDS);
            DoCast(me, SPELL_ACID_MANDIBLE);
            me->SetInCombatWithZone();
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                me->AddThreat(target, 20000.0f);
            if (!me->isInCombat())
                me->DisappearAndDie();
        }

        void DoAction(const int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_SCARAB_SUBMERGE:
                    DoCast(SPELL_SUBMERGE_EFFECT);
                    me->DespawnOrUnsummon(1000);
                    break;
            }
        }

        void JustDied(Unit* killer)
        {
            DoCast(killer, RAID_MODE(SPELL_TRAITOR_KING_10, SPELL_TRAITOR_KING_25));
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            /* Bosskillers don't recognize */
            if (m_uiDeterminationTimer <= uiDiff)
            {
                DoCast(me, SPELL_DETERMINATION);
                m_uiDeterminationTimer = urand(10*IN_MILLISECONDS, 60*IN_MILLISECONDS);
            } else m_uiDeterminationTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_nerubian_burrower : public CreatureScript
{
public:
    mob_nerubian_burrower() : CreatureScript("mob_nerubian_burrower") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nerubian_burrowerAI(creature);
    };

    struct mob_nerubian_burrowerAI : public ScriptedAI
    {
        mob_nerubian_burrowerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiSpiderFrenzyTimer;
        uint32 m_uiSubmergeTimer;

        void Reset()
        {
            me->SetCorpseDelay(0);
            m_uiSpiderFrenzyTimer = urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS);
            m_uiSubmergeTimer = 30*IN_MILLISECONDS;
            DoCast(me, SPELL_EXPOSE_WEAKNESS);
            DoCast(me, SPELL_SPIDER_FRENZY);
            me->SetInCombatWithZone();
            if (!me->isInCombat())
                me->DisappearAndDie();
        }

        void DoAction(const int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_SHADOW_STRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOW_STRIKE);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if ((m_uiSubmergeTimer <= uiDiff) && HealthBelowPct(80))
            {
                if (me->HasAura(SPELL_SUBMERGE_EFFECT))
                {
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                    DoCast(me, SPELL_EMERGE_EFFECT);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                    me->CombatStart(me->SelectNearestTarget());
                }
                else
                {
                    if (!me->HasAura(SPELL_PERMAFROST_HELPER))
                    {
                        DoCast(me, SPELL_SUBMERGE_EFFECT);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                        me->CombatStop();
                    }
                }
                m_uiSubmergeTimer = 20*IN_MILLISECONDS;
            } else m_uiSubmergeTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_frost_sphere : public CreatureScript
{
    public:
        mob_frost_sphere() : CreatureScript("mob_frost_sphere") { }

        struct mob_frost_sphereAI : public ScriptedAI
        {
            mob_frost_sphereAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _isFalling = false;
                me->SetReactState(REACT_PASSIVE);
                //! Confirmed sniff 3.3.5.a
                me->SetDisableGravity(true);
                me->SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                //! end
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetSpeed(MOVE_RUN, 0.5f, false);
                me->GetMotionMaster()->MoveRandom(20.0f);
                DoCast(SPELL_FROST_SPHERE);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (me->GetHealth() <= damage)
                {
                    damage = 0;
                    if (!_isFalling)
                    {
                        _isFalling = true;
                        me->GetMotionMaster()->MoveIdle();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        //At hit the ground
                        me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                        me->GetMotionMaster()->MoveFall(POINT_FALL_GROUND);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_FALL_GROUND:
                        me->RemoveAurasDueToSpell(SPELL_FROST_SPHERE);
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
                        DoCast(SPELL_PERMAFROST_VISUAL);
                        DoCast(SPELL_PERMAFROST);
                        me->SetObjectScale(2.0f);
                        break;
                }
            }

        private:
            bool _isFalling;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_frost_sphereAI(creature);
        };
};

class mob_anubarak_spike : public CreatureScript
{
public:
    mob_anubarak_spike() : CreatureScript("mob_anubarak_spike") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_anubarak_spikeAI(creature);
    };

    struct mob_anubarak_spikeAI : public ScriptedAI
    {
        mob_anubarak_spikeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 m_uiIncreaseSpeedTimer;
        uint8  m_uiSpeed;
        uint64 m_uiTargetGUID;

        void Reset()
        {
            // For an unknown reason this npc isn't recognize the Aura of Permafrost with this flags =/
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            m_uiTargetGUID = 0;
        }

        bool CanAIAttack(Unit const* victim) const
        {
            return victim->GetTypeId() == TYPEID_PLAYER;
        }

        void EnterCombat(Unit* who)
        {
            m_uiTargetGUID = who->GetGUID();
            DoCast(who, SPELL_MARK);
            me->SetSpeed(MOVE_RUN, 0.5f);
            m_uiSpeed = 0;
            m_uiIncreaseSpeedTimer = 1*IN_MILLISECONDS;
            me->TauntApply(who);
        }

        void DamageTaken(Unit* /*who*/, uint32& uiDamage)
        {
            uiDamage = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            Unit* target = Unit::GetPlayer(*me, m_uiTargetGUID);
            if (!target || !target->isAlive() || !target->HasAura(SPELL_MARK))
            {
                if (Creature* pAnubarak = Unit::GetCreature((*me), instance->GetData64(NPC_ANUBARAK)))
                    pAnubarak->CastSpell(pAnubarak, SPELL_SPIKE_TELE, false);
                me->DisappearAndDie();
                return;
            }

            if (m_uiIncreaseSpeedTimer)
            {
                if (m_uiIncreaseSpeedTimer <= uiDiff)
                {
                    switch (m_uiSpeed)
                    {
                        case 0:
                            DoCast(me, SPELL_SPIKE_SPEED1);
                            DoCast(me, SPELL_SPIKE_TRAIL);
                            m_uiSpeed = 1;
                            m_uiIncreaseSpeedTimer = 7*IN_MILLISECONDS;
                            break;
                        case 1:
                            DoCast(me, SPELL_SPIKE_SPEED2);
                            m_uiSpeed = 2;
                            m_uiIncreaseSpeedTimer = 7*IN_MILLISECONDS;
                            break;
                        case 2:
                            DoCast(me, SPELL_SPIKE_SPEED3);
                            m_uiIncreaseSpeedTimer = 0;
                            break;
                    }
                } else m_uiIncreaseSpeedTimer -= uiDiff;
            }
        }
    };

};

void AddSC_boss_anubarak_trial()
{
    new boss_anubarak_trial();
    new mob_swarm_scarab();
    new mob_nerubian_burrower();
    new mob_anubarak_spike();
    new mob_frost_sphere();
}
