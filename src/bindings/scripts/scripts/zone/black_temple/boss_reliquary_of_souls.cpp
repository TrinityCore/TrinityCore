/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Reliquary_of_Souls
SD%Complete: 90
SDComment: Persistent Area Auras for each Essence (Aura of Suffering, Aura of Desire, Aura of Anger) requires core support.
SDCategory: Black Temple
EndScriptData */

#include "precompiled.h"
#include "def_black_temple.h"

//Sound'n'speech
//Suffering
#define SUFF_SAY_FREED      "Pain and suffering are all that await you!"
#define SUFF_SOUND_FREED    11415
#define SUFF_SAY_AGGRO      "Don't leave me alone!"
#define SUFF_SOUND_AGGRO    11416
#define SUFF_SAY_SLAY1      "Look at what you make me do!"
#define SUFF_SOUND_SLAY1    11417
#define SUFF_SAY_SLAY2      "I didn't ask for this!"
#define SUFF_SOUND_SLAY2    11418
#define SUFF_SAY_SLAY3      "The pain is only beginning!"
#define SUFF_SOUND_SLAY3    11419
#define SUFF_SAY_RECAP      "I don't want to go back!"
#define SUFF_SOUND_RECAP    11420
#define SUFF_SAY_AFTER      "Now what do I do?"
#define SUFF_SOUND_AFTER    11421

//Desire
#define DESI_SAY_FREED      "You can have anything you desire... for a price."
#define DESI_SOUND_FREED    11408
#define DESI_SAY_SLAY1      "Fulfilment is at hand!"
#define DESI_SOUND_SLAY1    11409
#define DESI_SAY_SLAY2      "Yes... you'll stay with us now..."
#define DESI_SOUND_SLAY2    11410
#define DESI_SAY_SLAY3      "Your reach exceeds your grasp."
#define DESI_SOUND_SLAY3    11412
#define DESI_SAY_SPEC       "Be careful what you wish for..."
#define DESI_SOUND_SPEC     11411
#define DESI_SAY_RECAP      "I'll be waiting..."
#define DESI_SOUND_RECAP    11413
#define DESI_SAY_AFTER      "I won't be far..."
#define DESI_SOUND_AFTER    11414

//Anger
#define ANGER_SAY_FREED     "Beware... I live."
#define ANGER_SOUND_FREED   11399
#define ANGER_SAY_FREED2    "So... foolish."
#define ANGER_SOUND_FREED2  11400
#define ANGER_SOUND_SLAY1   11401
#define ANGER_SAY_SLAY2     "Enough. No more."
#define ANGER_SOUND_SLAY2   11402
#define ANGER_SAY_SPEC      "On your knees!"
#define ANGER_SOUND_SPEC    11403
#define ANGER_SAY_BEFORE    "Beware, coward."
#define ANGER_SOUND_BEFORE  11405
#define ANGER_SAY_DEATH     "I won't... be... ignored."
#define ANGER_SOUND_DEATH   11404

//Spells
#define AURA_OF_SUFFERING               41292
#define AURA_OF_SUFFERING_ARMOR         42017
#define ESSENCE_OF_SUFFERING_PASSIVE    41296
#define SPELL_ENRAGE                    41305
#define SPELL_SOUL_DRAIN                41303
#define SPELL_FIXATE                    41295

#define AURA_OF_DESIRE                  41350
#define SPELL_RUNE_SHIELD               41431
#define SPELL_DEADEN                    41410
#define SPELL_SOUL_SHOCK                41426

#define AURA_OF_ANGER                   41337
#define SPELL_SELF_SEETHE               41364
#define SPELL_ENEMY_SEETHE              41520
#define SPELL_SOUL_SCREAM               41545
#define SPELL_SPITE                     41377

#define ENSLAVED_SOUL_PASSIVE           41535
#define SPELL_SOUL_RELEASE              41542
#define SPELL_RESTORE_MANA              32848
#define SPELL_RESTORE_HEALTH            25329

#define CREATURE_ENSLAVED_SOUL          23469

struct Position
{
    float x,y;
};

static Position Coords[]=
{
    {450.4, 212.3},
    {542.1, 212.3},
    {542.1, 168.3},
    {542.1, 137.4},
    {450.4, 137.4},
    {450.4, 168.3}
};

struct TRINITY_DLL_DECL npc_enslaved_soulAI : public ScriptedAI
{
    npc_enslaved_soulAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint64 ReliquaryGUID;

    void Reset()
    {
        ReliquaryGUID = 0;
    }

    void Aggro(Unit* who) {}

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth())
        {
            if(done_by->GetTypeId() == TYPEID_PLAYER)
            {
                done_by->CastSpell(done_by, SPELL_RESTORE_HEALTH, true);
                if(done_by->GetMaxPower(POWER_MANA) > 0)
                {
                    if((done_by->GetPower(POWER_MANA) / done_by->GetMaxPower(POWER_MANA)) < 70)
                    {
                        uint32 mana = done_by->GetPower(POWER_MANA) + (uint32)(done_by->GetMaxPower(POWER_MANA)*0.3);
                        done_by->SetPower(POWER_MANA, mana);
                    }else done_by->SetPower(POWER_MANA, done_by->GetMaxPower(POWER_MANA));
                }
            }
            DoCast(done_by, SPELL_SOUL_RELEASE);
        }
    }

    void JustDied(Unit *killer);
};

struct TRINITY_DLL_DECL boss_reliquary_of_soulsAI : public ScriptedAI
{
    boss_reliquary_of_soulsAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint64 SufferingGUID;
    uint64 DesireGUID;
    uint64 AngerGUID;

    uint32 SoulDeathCount;
    // 0 = Out of Combat, 1 = Not started, 2 = Suffering, 3 = Souls, 4 = Desire, 5 = Souls, 6 = Anger
    uint32 Phase;
    uint32 SummonEssenceTimer;
    uint32 DespawnEssenceTimer;
    uint32 SoulCount;
    uint32 SummonSoulTimer;
    uint32 AnimationTimer;

    bool IsDead;
    bool EndingPhase;

    void Reset()
    {
        if(pInstance)
            pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, NOT_STARTED);

        DespawnEssences();

        SufferingGUID = 0;
        DesireGUID = 0;
        AngerGUID = 0;

        SoulDeathCount = 0;
        Phase = 0;
        SummonEssenceTimer = 8000;
        DespawnEssenceTimer = 2000;
        SoulCount = 0;
        SummonSoulTimer = 1000;
        AnimationTimer = 8000;

        IsDead = false;
        EndingPhase = false;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,0);
        m_creature->GetMotionMaster()->Clear(false);
    }

    void Aggro(Unit* who) { }

    void AttackStart(Unit* who) { }

    void MoveInLineOfSight(Unit *who)
    {
        if (who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if(!InCombat)
                {
                    if(pInstance)
                        pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, IN_PROGRESS);

                    Phase = 1;
                                                            // I R ANNNGRRRY!
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,375);
                    SummonEssenceTimer = 8000;
                    AnimationTimer = 5100;
                    m_creature->AddThreat(who, 1.0f);

                    InCombat = true;
                }
            }
        }
    }

    void SummonSoul()
    {
        uint32 random = rand()%6;
        float x = Coords[random].x;
        float y = Coords[random].y;
        Creature* Soul = m_creature->SummonCreature(CREATURE_ENSLAVED_SOUL, x, y, m_creature->GetPositionZ(), m_creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
        Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
        if (target && Soul)
        {
            ((npc_enslaved_soulAI*)Soul->AI())->ReliquaryGUID = m_creature->GetGUID();
            Soul->CastSpell(Soul, ENSLAVED_SOUL_PASSIVE, true);
            Soul->AddThreat(target, 1.0f);
            SoulCount++;
        }
    }

    void MergeThreatList(Creature* target)
    {
        if(!target) return;

        std::list<HostilReference*>& m_threatlist = target->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator itr = m_threatlist.begin();
        for( ; itr != m_threatlist.end(); itr++)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*itr)->getUnitGuid());
            if(pUnit)
            {
                m_creature->AddThreat(pUnit, 1.0f);         // This is so that we make sure the unit is in Reliquary's threat list before we reset the unit's threat.
                m_creature->getThreatManager().modifyThreatPercent(pUnit, -100);
                float threat = target->getThreatManager().getThreat(pUnit);
                m_creature->AddThreat(pUnit, threat);       // This makes it so that the unit has the same amount of threat in Reliquary's threatlist as in the target creature's (One of the Essences).
            }
        }
    }

    void DespawnEssences()
    {
        // Despawn Essences
        Unit* Essence = NULL;
        if(SufferingGUID)
            Essence = ((Creature*)Unit::GetUnit((*m_creature), SufferingGUID));
        else if(DesireGUID)
            Essence = ((Creature*)Unit::GetUnit((*m_creature), DesireGUID));
        else if(AngerGUID)
            Essence = ((Creature*)Unit::GetUnit((*m_creature), AngerGUID));
        if(Essence && Essence->isAlive())
            Essence->setDeathState(JUST_DIED);
    }

    void JustDied(Unit* killer)
    {
        if(pInstance)
            pInstance->SetData(DATA_RELIQUARYOFSOULSEVENT, DONE);

        InCombat = false;
    }

    void UpdateAI(const uint32 diff)
    {
        if(!Phase)
            return;

        // Reset if event is begun and we don't have a threatlist
        if(Phase && m_creature->getThreatManager().getThreatList().empty())
            EnterEvadeMode();

        if(Phase == 1)
        {
            if(AnimationTimer < diff)
            {
                // Release the cube
                m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,374);
                AnimationTimer = 8300;
            }else AnimationTimer -= diff;

            if(SummonEssenceTimer < diff)
            {
                // Ribs: open
                m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,373);
                Creature* EssenceSuffering = NULL;
                EssenceSuffering = m_creature->SummonCreature(23418, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 1.57, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);

                if(EssenceSuffering)
                {
                    EssenceSuffering->Yell(SUFF_SAY_FREED, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(m_creature, SUFF_SOUND_FREED);
                    Unit* target = SelectUnit(SELECT_TARGET_TOPAGGRO, 0);
                    if(target)
                    {
                        EssenceSuffering->AddThreat(target, 1.0f);
                        EssenceSuffering->AI()->AttackStart(target);
                    }
                    SufferingGUID = EssenceSuffering->GetGUID();
                }

                EndingPhase = false;
                Phase = 2;
            }else SummonEssenceTimer -= diff;
        }

        if(Phase == 2)
        {
            if(SufferingGUID)
            {
                Creature* EssenceSuffering = NULL;
                EssenceSuffering = ((Creature*)Unit::GetUnit((*m_creature), SufferingGUID));

                if(!EssenceSuffering || (!EssenceSuffering->isAlive()))
                    EnterEvadeMode();

                if(!EndingPhase)
                {
                    if(EssenceSuffering)
                    {
                        if(EssenceSuffering->GetHealth() < (EssenceSuffering->GetMaxHealth()*0.1))
                        {
                            MergeThreatList(EssenceSuffering);
                            EssenceSuffering->RemoveAllAuras();
                            EssenceSuffering->DeleteThreatList();
                            EssenceSuffering->GetMotionMaster()->MoveFollow(m_creature,0.0f,0.0f);
                            EssenceSuffering->Yell(SUFF_SAY_RECAP,LANG_UNIVERSAL,0);
                            DoPlaySoundToSet(m_creature, SUFF_SOUND_RECAP);
                            EssenceSuffering->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            DespawnEssenceTimer = 4000;
                            AnimationTimer = 2200;
                            EndingPhase = true;
                        }
                    }
                }

                if((EndingPhase) && (EssenceSuffering) && (EssenceSuffering->isAlive()))
                {
                    if(AnimationTimer < diff)
                    {
                        // Return
                        EssenceSuffering->SetUInt32Value(UNIT_NPC_EMOTESTATE,374);
                        AnimationTimer = 10000;
                    }else AnimationTimer -= diff;

                    if(DespawnEssenceTimer < diff)
                    {
                        EssenceSuffering->DeleteThreatList();
                        EssenceSuffering->Yell(SUFF_SAY_AFTER,LANG_UNIVERSAL,0);
                        DoPlaySoundToSet(m_creature, SUFF_SOUND_AFTER);
                        EssenceSuffering->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
                        EssenceSuffering->setFaction(35);
                        m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,0);
                        SummonEssenceTimer = 20000;         //60000;
                        AnimationTimer = 18200;             //58100;
                        SoulDeathCount = 0;
                        SoulCount = 0;
                        SummonSoulTimer = 1000;
                        EndingPhase = false;
                        Phase = 3;
                        SufferingGUID = 0;
                    }else DespawnEssenceTimer -= diff;
                }
            }
        }

        if(Phase == 3)
        {
            if(SoulCount < 36)
            {
                if(SummonSoulTimer < diff)
                {
                    SummonSoul();
                    SummonSoulTimer = 500;
                }else SummonSoulTimer -= diff;
            }

            if(SoulDeathCount >= SoulCount)
            {
                if(AnimationTimer < diff)
                {
                    // Release the cube
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,374);
                    AnimationTimer = 10000;
                }else AnimationTimer -= diff;

                if(SummonEssenceTimer < diff)
                {
                    // Ribs: open
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,373);
                    Creature* EssenceDesire = NULL;
                    EssenceDesire = m_creature->SummonCreature(23419, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 1.57, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);

                    if(EssenceDesire)
                    {
                        EssenceDesire->Yell(DESI_SAY_FREED, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, DESI_SOUND_FREED);
                        Unit* target = NULL;
                        target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                        if(target)
                        {
                            EssenceDesire->AddThreat(target, 1.0f);
                            EssenceDesire->AI()->AttackStart(target);
                        }
                        DesireGUID = EssenceDesire->GetGUID();
                        SoulDeathCount = 0;
                    }

                    Phase = 4;
                }else SummonEssenceTimer -= diff;
            }
        }

        if(Phase == 4)
        {
            if(DesireGUID)
            {
                Creature* EssenceDesire = NULL;
                EssenceDesire = ((Creature*)Unit::GetUnit((*m_creature), DesireGUID));

                if(!EssenceDesire || !EssenceDesire->isAlive())
                    EnterEvadeMode();

                if(!EndingPhase && EssenceDesire)
                {
                    if(EssenceDesire->GetHealth() < (EssenceDesire->GetMaxHealth()*0.1))
                    {
                        MergeThreatList(EssenceDesire);
                        EssenceDesire->GetMotionMaster()->MoveFollow(m_creature,0.0f,0.0f);
                        EssenceDesire->RemoveAllAuras();
                        EssenceDesire->DeleteThreatList();
                        EssenceDesire->Yell(DESI_SAY_RECAP,LANG_UNIVERSAL,0);
                        DoPlaySoundToSet(m_creature, DESI_SOUND_RECAP);
                        EssenceDesire->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DespawnEssenceTimer = 4000;
                        AnimationTimer = 2200;
                        EndingPhase = true;
                    }
                }

                if(EndingPhase && EssenceDesire)
                {
                    if(EssenceDesire->isAlive())
                    {
                        if(AnimationTimer < diff)
                        {
                            // Return
                            EssenceDesire->SetUInt32Value(UNIT_NPC_EMOTESTATE,374);
                            AnimationTimer = 10000;
                        }else AnimationTimer -= diff;

                        if(DespawnEssenceTimer < diff)
                        {
                            EssenceDesire->DeleteThreatList();
                            EssenceDesire->setFaction(35);
                            EssenceDesire->Yell(DESI_SAY_AFTER, LANG_UNIVERSAL, 0);
                            DoPlaySoundToSet(m_creature, DESI_SOUND_AFTER);
                            EssenceDesire->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11686);
                            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,0);
                            SummonEssenceTimer = 20000;
                            AnimationTimer = 18200;
                            SoulDeathCount = 0;
                            SoulCount = 0;
                            SummonSoulTimer = 1000;
                            EndingPhase = false;
                            Phase = 5;
                            DesireGUID = 0;
                        }else DespawnEssenceTimer -= diff;
                    }
                }
            }
        }

        if(Phase == 5)
        {
            if(SoulCount < 36)
            {
                if(SummonSoulTimer < diff)
                {
                    SummonSoul();
                    SummonSoulTimer = 500;
                }else SummonSoulTimer -= diff;
            }

            if(SoulDeathCount >= SoulCount)
            {
                if(AnimationTimer < diff)
                {
                    // Release the cube
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,374);
                    AnimationTimer = 10000;
                }else AnimationTimer -= diff;

                if(SummonEssenceTimer < diff)
                {
                    // Ribs: open
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE,373);
                    Creature* EssenceAnger = NULL;
                    EssenceAnger = m_creature->SummonCreature(23420, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 1.57, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 45000);

                    if(EssenceAnger)
                    {
                        Unit* target = SelectUnit(SELECT_TARGET_TOPAGGRO, 0);
                        if(target)
                        {
                            EssenceAnger->AddThreat(target, 1.0f);
                            EssenceAnger->AI()->AttackStart(target);
                        }
                        AngerGUID = EssenceAnger->GetGUID();
                        DoPlaySoundToSet(m_creature, ANGER_SOUND_FREED);
                        EssenceAnger->Yell(ANGER_SAY_FREED, LANG_UNIVERSAL, 0);
                        SoulDeathCount = 0;
                    }

                    Phase = 6;
                }else SummonEssenceTimer -= diff;
            }
        }

        if(Phase == 6)
        {
            if(AngerGUID)
            {
                Creature* EssenceAnger = NULL;
                EssenceAnger = ((Creature*)Unit::GetUnit((*m_creature), AngerGUID));

                if(!EssenceAnger)
                    EnterEvadeMode();

                if(m_creature->isAlive() && EssenceAnger)
                {
                    if(!EssenceAnger->isAlive())
                    {
                        AngerGUID = 0;
                        m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    }
                }
            }
        }
    }
};

//This is used to sort the players by distance in preparation for the Fixate cast.
struct TargetDistanceOrder : public std::binary_function<const Unit, const Unit, bool>
{
    const Unit* MainTarget;
    TargetDistanceOrder(const Unit* Target) : MainTarget(Target) {};
    // functor for operator "<"
    bool operator()(const Unit* _Left, const Unit* _Right) const
    {
        return (MainTarget->GetDistance(_Left) < MainTarget->GetDistance(_Right));
    }
};

struct TRINITY_DLL_DECL boss_essence_of_sufferingAI : public ScriptedAI
{
    boss_essence_of_sufferingAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint64 StatAuraGUID;

    uint32 AggroYellTimer;
    uint32 FixateTimer;
    uint32 EnrageTimer;
    uint32 SoulDrainTimer;

    void Reset()
    {
        StatAuraGUID = 0;

        AggroYellTimer = 5000;
        FixateTimer = 5000;
        EnrageTimer = 30000;
        SoulDrainTimer = 150000;
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if((damage >= m_creature->GetHealth()) && (done_by != m_creature))
        {
            damage = 0;
            // 10% of total health, signalling time to return
            m_creature->SetHealth(m_creature->GetMaxHealth()/10);
            if(StatAuraGUID)
            {
                Unit* pUnit = Unit::GetUnit((*m_creature), StatAuraGUID);
                if(pUnit)
                    pUnit->RemoveAurasDueToSpell(AURA_OF_SUFFERING_ARMOR);
            }
        }
    }

    void Aggro(Unit *who)
    {
        DoZoneInCombat();
        DoCast(who, AURA_OF_SUFFERING, true);
        DoCast(m_creature, ESSENCE_OF_SUFFERING_PASSIVE, true);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SUFF_SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SUFF_SOUND_SLAY1);
                break;
            case 1:
                DoYell(SUFF_SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SUFF_SOUND_SLAY2);
                break;
            case 2:
                DoYell(SUFF_SAY_SLAY3,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SUFF_SOUND_SLAY3);
                break;
        }
    }

    void JustDied(Unit* killer)
    {
    }

    void CastFixate()
    {
        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        if(m_threatlist.empty())
            return;                                         // No point continuing if empty threatlist.
        std::list<Unit*> targets;
        std::list<HostilReference*>::iterator itr = m_threatlist.begin();
        for( ; itr != m_threatlist.end(); ++itr)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*itr)->getUnitGuid());
                                                            // Only alive players
            if(pUnit && pUnit->isAlive() && (pUnit->GetTypeId() == TYPEID_PLAYER))
                targets.push_back(pUnit);
        }
        if(targets.empty())
            return;                                         // No targets added for some reason. No point continuing.
        targets.sort(TargetDistanceOrder(m_creature));      // Sort players by distance.
        targets.resize(1);                                  // Only need closest target.
        Unit* target = targets.front();                     // Get the first target.
                                                            // Add threat equivalent to threat on victim.
        m_creature->AddThreat(target, m_creature->getThreatManager().getThreat(m_creature->getVictim()));
        DoCast(target, SPELL_FIXATE);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(m_creature->GetHealth() <= (m_creature->GetMaxHealth()*0.1))
        {
            if(StatAuraGUID)
            {
                Unit* pUnit = NULL;
                pUnit = Unit::GetUnit((*m_creature), StatAuraGUID);
                if(pUnit)
                    pUnit->RemoveAurasDueToSpell(AURA_OF_SUFFERING_ARMOR);
            }
        }

        if(m_creature->GetHealth() <= (m_creature->GetMaxHealth()*0.1))
        {
            if(m_creature->getVictim())
                m_creature->DeleteThreatList();             // Delete our threatlist if below 10% as we should no longer attack.
            return;
        }

        // Prevent overlapping yells
        if(AggroYellTimer)
            if(AggroYellTimer < diff)
        {
            DoYell(SUFF_SAY_AGGRO, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SUFF_SOUND_AGGRO);
            AggroYellTimer = 0;
        }else AggroYellTimer -= diff;

        //Supposed to be cast on nearest target
        if(FixateTimer < diff)
        {
            CastFixate();
            FixateTimer = 5000;
        }else FixateTimer -= diff;

        if(EnrageTimer < diff)
        {
            DoCast(m_creature, SPELL_ENRAGE);
            EnrageTimer = 60000;
        }else EnrageTimer -= diff;

        if(SoulDrainTimer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if(target)
                DoCast(target, SPELL_SOUL_DRAIN);
            SoulDrainTimer = 60000;
        }else SoulDrainTimer -= diff;

        DoMeleeAttackIfReady();
    }
};
struct TRINITY_DLL_DECL boss_essence_of_desireAI : public ScriptedAI
{
    boss_essence_of_desireAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 AggroYellTimer;
    uint32 RuneShieldTimer;
    uint32 DeadenTimer;
    uint32 SoulShockTimer;

    void Reset()
    {
        AggroYellTimer = 5000;
        RuneShieldTimer = 60000;
        DeadenTimer = 15000;
        SoulShockTimer = 40000;
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if((damage >= m_creature->GetHealth()) && (done_by != m_creature))
        {
            damage = 0;
            // 10% of total health, signalling time to return
            m_creature->SetHealth(m_creature->GetMaxHealth()/10);
        }
        else
        {
            if(done_by && (done_by->GetTypeId() == TYPEID_PLAYER) && done_by->isAlive())
                done_by->DealDamage(done_by, damage/2, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }
    }

    void Aggro(Unit *who) { DoZoneInCombat(); }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(DESI_SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, DESI_SOUND_SLAY1);
                break;
            case 1:
                DoYell(DESI_SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, DESI_SOUND_SLAY2);
                break;
            case 2:
                DoYell(DESI_SAY_SLAY3,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, DESI_SOUND_SLAY3);
                break;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                //Begin melee attack if we are within range
                DoStartAttackAndMovement(who);

                if (!InCombat)
                {
                    DoCast(who, AURA_OF_DESIRE);
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(m_creature->GetHealth() <= (m_creature->GetMaxHealth()*0.1))
        {
            if(m_creature->getVictim())
                m_creature->DeleteThreatList();             // Delete our threatlist if below 10% as we should no longer attack.
            return;
        }

        if(RuneShieldTimer < diff)
        {
            DoCast(m_creature, SPELL_RUNE_SHIELD);
            RuneShieldTimer = 60000;
        }else RuneShieldTimer -= diff;

        if(DeadenTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_DEADEN);
            DeadenTimer = 30000 + rand()%30001;
        }else DeadenTimer -= diff;

        if(SoulShockTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SOUL_SHOCK);
            SoulShockTimer = 40000;
            if(rand()%2 == 0)
            {
                DoYell(DESI_SAY_SPEC,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, DESI_SOUND_SPEC);
            }

        }else SoulShockTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL boss_essence_of_angerAI : public ScriptedAI
{
    boss_essence_of_angerAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint64 AggroTargetGUID;

    uint32 AggroYellTimer;
    uint32 CheckTankTimer;
    uint32 SoulScreamTimer;
    uint32 SpiteTimer;

    bool CheckedAggro;

    void Reset()
    {
        AggroTargetGUID = 0;

        AggroYellTimer = 5000;
        CheckTankTimer = 5000;
        SoulScreamTimer = 10000;
        SpiteTimer = 30000;

        CheckedAggro = false;
    }

    void Aggro(Unit *who)
    {
        DoZoneInCombat();
        DoCast(m_creature->getVictim(), AURA_OF_ANGER, true);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                //Begin melee attack if we are within range
                DoStartAttackAndMovement(who);

                if (!InCombat)
                {
                    DoCast(who, AURA_OF_ANGER);
                }
            }
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(ANGER_SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,ANGER_SOUND_DEATH);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoPlaySoundToSet(m_creature, ANGER_SOUND_SLAY1);
                break;
            case 1:
                DoYell(ANGER_SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, ANGER_SOUND_SLAY2);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(!CheckedAggro)
        {
            AggroTargetGUID = m_creature->getVictim()->GetGUID();
            CheckedAggro = true;
        }

        if(AggroYellTimer)
            if(AggroYellTimer < diff)
        {
            DoYell(ANGER_SAY_FREED2,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature, ANGER_SOUND_FREED2);
            AggroYellTimer = 0;
        }else AggroYellTimer -= diff;

        if(CheckTankTimer < diff)
        {
            if(m_creature->getVictim()->GetGUID() != AggroTargetGUID)
            {
                DoYell(ANGER_SAY_BEFORE,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, ANGER_SOUND_BEFORE);
                DoCast(m_creature, SPELL_SELF_SEETHE);
                DoCast(m_creature->getVictim(), SPELL_ENEMY_SEETHE, true);
                AggroTargetGUID = m_creature->getVictim()->GetGUID();
            }
            CheckTankTimer = 2000;
        }else CheckTankTimer -= diff;

        if(SoulScreamTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SOUL_SCREAM);
            SoulScreamTimer = 10000;
        }else SoulScreamTimer -= diff;

        if(SpiteTimer < diff)
        {
            for(uint8 i = 0; i < 4; i++)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if(target)
                    DoCast(target, SPELL_SPITE);

            }

            SpiteTimer = 30000;
            DoYell(ANGER_SAY_SPEC,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature, ANGER_SOUND_SPEC);
        }else SpiteTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

void npc_enslaved_soulAI::JustDied(Unit *killer)
{
    if(ReliquaryGUID)
    {
        Creature* Reliquary = ((Creature*)Unit::GetUnit((*m_creature), ReliquaryGUID));
        if(Reliquary)
            ((boss_reliquary_of_soulsAI*)Reliquary->AI())->SoulDeathCount++;
    }
}

CreatureAI* GetAI_boss_reliquary_of_souls(Creature *_Creature)
{
    return new boss_reliquary_of_soulsAI (_Creature);
}

CreatureAI* GetAI_boss_essence_of_suffering(Creature *_Creature)
{
    return new boss_essence_of_sufferingAI (_Creature);
}

CreatureAI* GetAI_boss_essence_of_desire(Creature *_Creature)
{
    return new boss_essence_of_desireAI (_Creature);
}

CreatureAI* GetAI_boss_essence_of_anger(Creature *_Creature)
{
    return new boss_essence_of_angerAI (_Creature);
}

CreatureAI* GetAI_npc_enslaved_soul(Creature *_Creature)
{
    return new npc_enslaved_soulAI (_Creature);
}

void AddSC_boss_reliquary_of_souls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_reliquary_of_souls";
    newscript->GetAI = GetAI_boss_reliquary_of_souls;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_essence_of_suffering";
    newscript->GetAI = GetAI_boss_essence_of_suffering;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_essence_of_desire";
    newscript->GetAI = GetAI_boss_essence_of_desire;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_essence_of_anger";
    newscript->GetAI = GetAI_boss_essence_of_anger;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_enslaved_soul";
    newscript->GetAI = GetAI_npc_enslaved_soul;
    m_scripts[nrscripts++] = newscript;
}
