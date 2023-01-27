/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Anubrekhan
SD%Complete: 90
SDComment: Check timers for corpse explosion of Crypt Guards. Currently not correct.
           Locust Swarm timers could use more sources.
           Damage and armor of boss, crypt guards and corpse scarabs needs research.
           Anubs hitbox is probably too small.
SDCategory: Naxxramas
EndScriptData */

#include "scriptPCH.h"
#include "naxxramas.h"
#include <vector>

// todo:
/*
Armor check:
https://www.youtube.com/watch?v=rmowgw2SZCA&t=60s
*/

enum AnubrekhanData
{
    SAY_GREET                   = 13004,
    SAY_AGGRO1                  = 13000,
    SAY_AGGRO2                  = 13002,
    SAY_AGGRO3                  = 13003,
    SAY_TAUNT1                  = 13006,
    SAY_TAUNT2                  = 13007,
    SAY_TAUNT3                  = 13008,
    SAY_TAUNT4                  = 13009,
    SAY_SLAY                    = 13005,

    EMOTE_GENERIC_ENRAGE        = 7798, // used by crypt guards

    SPELL_IMPALE                = 28783,        //May be wrong spell id. Causes more dmg than I expect
    SPELL_LOCUSTSWARM           = 28785,        //This is a self buff that triggers the dmg debuff

    SPELL_SELF_SPAWN_5          = 29105,        // These spells should spawn corpse scarabs, but only show the explosion anim.
    SPELL_SELF_SPAWN_10         = 28864,        // If we fix them to spawn scarbs, code must be changed to not manually spawn them too.

    SPELL_CRYPTGUARD_ENRAGE     = 28747,        // 50% attackspeed increase and 100 extra dmg on attack. PROBABLY WRONG SPELL!!!
    SPELL_CRYPTGUARD_CLEAVE     = 26350,        // could be wrong spell. 
    SPELL_CRYPTGUARD_WEB        = 28991,
    SPELL_CRYPTGUARD_ACID       = 28969,

    MOB_CRYPT_GUARD             = 16573,
    MOB_CORPSE_SCARAB           = 16698
};

static float const CGs[3][4] = 
{
    { 3291.26f, -3502.08f, 287.26f, 2.14f },
    { 3285.29f, -3446.64f, 287.26f, 4.2f },
    { 3316.46f, -3476.23f, 287.26f, 3.18f } // this third entry is used as spawn loc during fight.
};

static constexpr uint32 CRYPTGUARD_CLEAVE_CD    = 6000;  // Todo: find correct timer
static constexpr uint32 CRYPTGUARD_WEB_CD       = 12000; // 10 second duration, so 12sec cd makes sense. 
                                                         // From videos you can see there is 1-2sec between consecutive nets.
static constexpr uint32 CRYPTGUARD_ACID_CD      = 5000;  // Todo: find correct timer. 

/*
Impale timer research:
video: https://www.youtube.com/watch?v=rmowgw2SZCA&t=60s
Watch his stopatch in center of screen.
2:05

2:40
2:54 +14
3:07 +13
3:20 +13

4:38

4:50 +12

6:06
6:23 +17

7:44

8:55

9:27
9:43 +16

10:22

11:03
11:15 +12
11:29 +14

12:13
12:38 +25 (missing one?)
12:54 +16
13:09 +15

13:32

14:15
14:28+13

Best guess so far is random between 12 and 18 seconds based on this video.
Timer does not seem to reset after locust swarm, but rather continue from whatever it was when locust started.
*/

static uint32 IMPALE_CD() { return urand(12000, 18000); }

/*
Locust Swarm - Every 70-120 seconds, Anub'rekhan casts a spell that causes AoE damage in a wide radius (30 yards) around him
(the AoE remains centered on Anub'Rekhan as he moves), he will also slow to 40% of normal run speed. Remaining in the radius of
effect will cause a DoT debuff to stack repeatedly, dealing a large amount of damage, around 1200 damage/2sec per stack and 
silencing those afflicted. When he casts this spell, another Crypt Guard will also spawn at his initial engage point. 

As of Patch 1.12, Anub'Rekhan is immune to Curse of Tongues.
Note: The Locust Swarm attack has an approximately 90 second cooldown, however the first cast is not at a set time, 
between 80 seconds and 2 minutes. As well, the Locust Swarm is not a normal silence. 
Unlike a normal silence, it prevents the use of all abilities (even auto-attack). 
This means that the MT cannot use Shield Wall or Last Stand to save himself if he gets stacked too high. Items, however,
are still able to be used (this includes Lifegiving Gem).
----------------------------
As can be seen in snippet above, wowwiki seems to believe its 80-120sec for initial locust, (slightly unclear)
90sec for any after that
Video evidence:
https://www.youtube.com/watch?v=rmowgw2SZCA&t=60s
Watch his stopatch in center of screen.
1:40 start cast
2:00 ended?

3:22 start cast
3:47 ended?

5:01 start cast (+74sec, 99 since prev start)
5:25 ended?

6:34 start cast (+69sec, 93 since prev start)
6:58 ended?

8:16 start cast (+78sec, 102 since prev start)
8:40 ended?

9:55 start cast (+75sec, 99 since prev start)
10:20 ended?

11:35 start cast (+75sec, 100 since prev start)

13:12 start cast (93 since prev start)

Based on those values, 90-110 or something like that does not seem far fetched as a cooldown.
Cast time is 3 seconds. Duration is 20 seconds.
*/

static uint32 LOCUST_SWARM_CD(bool initial) { return initial ? urand(80000, 120000) : urand(90000, 110000); }

struct boss_anubrekhanAI : public ScriptedAI
{
    instance_naxxramas* m_pInstance;

    uint32 m_uiImpaleTimer;
    uint32 m_uiLocustSwarmTimer;
    uint32 m_uiCorpseExplosionTimer;
    uint32 m_uiRestoreTargetTimer;
    bool m_firstBlood;
    EventMap events;

    std::vector<ObjectGuid> deadCryptGuards;
    std::vector<ObjectGuid> summonedCryptGuards;

    boss_anubrekhanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        if (!m_pInstance)
            sLog.outError("boss_anubrekhanAI::ctor failed to cast instanceData to instance_naxxramas");

        CheckSpawnInitialCryptGuards();
        Reset();
    }

    void CheckSpawnInitialCryptGuards()
    {
        if (m_pInstance->GetData(TYPE_ANUB_REKHAN) == DONE)
            return;

        for (int i = 0; i < 2; i++)
        {
            // While the crypt guard will be despawned manually after CRYPTGUARD_DESPAWN time, when it explodes,
            // we make it a TEMPSUMMON_CORPSE_TIMED_DESPAWN with a slightly longer duration, because if anub is killed
            // before the last crypt guard dies, anubs updateAI will not be able to manually explode and despawn it.
            if (Creature* c = m_creature->SummonCreature(MOB_CRYPT_GUARD, CGs[i][0], CGs[i][1], CGs[i][2], CGs[i][3], TEMPSUMMON_MANUAL_DESPAWN))
            {
                summonedCryptGuards.push_back(c->GetObjectGuid());
            }
            else 
            {
                sLog.outError("boss_anubrekhanAI::CheckSpawnInitialCryptGuards failed to spawn initial crypt guard");
            }
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() != MOB_CRYPT_GUARD)
            return;
        deadCryptGuards.push_back(pSummoned->GetObjectGuid());
    }

    void Reset() override
    {
        m_uiImpaleTimer = IMPALE_CD();
        m_uiLocustSwarmTimer = LOCUST_SWARM_CD(true);
        m_uiCorpseExplosionTimer = urand(20000, 80000);
        m_firstBlood = false;
        m_uiRestoreTargetTimer = 0;

        std::list<Creature*> scarabs;
        GetCreatureListWithEntryInGrid(scarabs, m_creature, MOB_CORPSE_SCARAB, 300.0f);
        for (auto it = scarabs.begin(); it != scarabs.end();)
        {
            if (scarabs.size() < 31)
                break;
            Creature* pC = *it;
            static_cast<TemporarySummon*>(pC)->UnSummon();
            it = scarabs.erase(it);
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_ANUB_REKHAN, FAIL);

        // despawn any summoned cryptguards that stil exist
        for (auto it = summonedCryptGuards.begin(); it != summonedCryptGuards.end();)
        {
            if (Creature* cg = m_pInstance->GetCreature((*it)))
            {
                if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(cg)) {
                    tmpSumm->UnSummon();
                }
            }
            it = summonedCryptGuards.erase(it);
        }

        // despawn any remaining corpses
        for (auto it = deadCryptGuards.begin(); it != deadCryptGuards.end();)
        {
            if (Creature* cg = m_pInstance->GetCreature((*it)))
            {
                if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(cg)) {
                    tmpSumm->UnSummon();
                }
            }

            it = deadCryptGuards.erase(it);
        }

        // respawn the two initial guards
        CheckSpawnInitialCryptGuards();
    }

    void KilledUnit(Unit* pVictim) override
    {
        // Scarabs are summoned by instance script when a player dies.
        // See instance_naxxramas::OnPlayerDeath(Player*)
        if (pVictim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (!m_firstBlood) 
        {
            DoScriptText(SAY_SLAY, m_creature);
            m_firstBlood = true;
            return;
        }

        if (urand(0, 4))
            return;
    }

    void Aggro(Unit* pWho) override
    {
        if (!m_pInstance)
            return;
        m_pInstance->SetData(TYPE_ANUB_REKHAN, IN_PROGRESS);
        // Setting in combat with zone and pulling the two crypt-guards
        m_creature->SetInCombatWithZone();

        for (const auto& guid : summonedCryptGuards)
        {
            if (Creature* cg = m_pInstance->GetCreature(guid))
            {
                cg->AI()->AttackStart(pWho);
                cg->SetInCombatWithZone();
            }
        }

        DoScriptText(PickRandomValue(SAY_AGGRO1, SAY_AGGRO2, SAY_AGGRO3), m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_ANUB_REKHAN, DONE);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (pWho->GetTypeId() == TYPEID_PLAYER 
            && !m_creature->IsInCombat() 
            && m_creature->IsWithinDistInMap(pWho, 55.0f) 
            && !pWho->HasAuraType(SPELL_AURA_FEIGN_DEATH))
        {
            AttackStart(pWho);
        }

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    bool ExplodeOneDeadCryptGuard()
    {
        if (deadCryptGuards.empty())
            return false;

        int idx = urand(0, deadCryptGuards.size() - 1);
        ObjectGuid deadCryptGuard = deadCryptGuards[idx];
        auto it = deadCryptGuards.begin() + idx;
        deadCryptGuards.erase(it);

        if (Creature* cg = m_pInstance->GetCreature(deadCryptGuard))
        {
            // The cryptguard casts SPELL_SELF_SPAWN_10 on itself. The spell is bugged and
            // wont spawn any adds, but it will show the visual.
            //cg->AI()->DoCast(cg, SPELL_SELF_SPAWN_10, true);
            cg->SendSpellGo(cg, SPELL_SELF_SPAWN_10);
            // Manually summoning 10 corpse scarabs under the Crypt Guard
            for (int i = 0; i < 10; i++)
            {
                // The summoned corpse scarab will attack a random target, and add 5k threat to it.
                // The threat amount is a guess, but it can be seen in videos, and it's mentioned on wowhead,
                // that the scarab will "stick" to it's chosen target for quite a while, if not until dead.
                if (Creature* cs = m_creature->SummonCreature(MOB_CORPSE_SCARAB, cg->GetPositionX(), cg->GetPositionY(), cg->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN))
                {
                    cs->SetInCombatWithZone();
                    if (Unit* csTarget = cs->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        cs->AI()->AttackStart(csTarget);
                        cs->AddThreat(csTarget, 5000);
                    }
                }
            }

            // Despawning the Crypt guard
            if (TemporarySummon* tmpSumm = static_cast<TemporarySummon*>(cg)) {
                tmpSumm->UnSummon(250);
                return true;
            }
        }
        return false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_pInstance->HandleEvadeOutOfHome(m_creature))
            return;

        if (m_uiRestoreTargetTimer)
        {
            if (m_uiRestoreTargetTimer <= uiDiff)
            {
                m_creature->SetInFront(m_creature->GetVictim());
                m_creature->SetTargetGuid(m_creature->GetVictim()->GetObjectGuid());
                m_uiRestoreTargetTimer = 0;
            }
            else
                m_uiRestoreTargetTimer -= uiDiff;
        }

        // Impale
        // todo: Not sure if the timer should keep running, be paused or reset during locust swarm.
        //       Currently the timer will simply be paused when locust swarm is active, or being cast
        if (!m_creature->HasAura(SPELL_LOCUSTSWARM) && !m_creature->IsNonMeleeSpellCasted())
        {
            if (m_uiImpaleTimer < uiDiff)
            {
                // Do NOT cast it when we are afflicted by locust swarm
                // todo: Not sure if the timer should keep running, be paused or reset during locust swarm.
                //       Currently the impale wil be cast instantly after locust, most likely not right.
                if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    m_creature->SetInFront(target);
                    m_creature->SetTargetGuid(target->GetObjectGuid());
                    m_uiRestoreTargetTimer = 1000;
                    m_uiImpaleTimer = IMPALE_CD();

                    if (Creature* pC = m_creature->SummonCreature(533003, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(target),
                        TEMPSUMMON_TIMED_DESPAWN, 4000))
                    {
                        pC->CastSpell(pC, SPELL_IMPALE, true);
                    }
                }
            }
            else
                m_uiImpaleTimer -= uiDiff;
        }

        if (m_uiCorpseExplosionTimer < uiDiff)
        {
            if(ExplodeOneDeadCryptGuard())
                m_uiCorpseExplosionTimer = urand(20000, 80000);
            else
                m_uiCorpseExplosionTimer = urand(10000, 20000);
        }
        else
            m_uiCorpseExplosionTimer -= uiDiff;

        // Locust Swarm
        if (m_uiLocustSwarmTimer < uiDiff)
        {
            // restore target at once if we have just done an impale
            if (m_uiRestoreTargetTimer)
            {
                m_creature->SetInFront(m_creature->GetVictim());
                m_creature->SetTargetGuid(m_creature->GetVictim()->GetObjectGuid());
                m_uiRestoreTargetTimer = 0;
            }

            // Reset cd and summon a new crypt guard at the initial possition of anub'rekhan on successfull cast
            if (DoCastSpellIfCan(m_creature, SPELL_LOCUSTSWARM) == CanCastResult::CAST_OK)
            {
                m_uiLocustSwarmTimer = LOCUST_SWARM_CD(false);
                if (Creature* pCryptGuard = m_creature->SummonCreature(MOB_CRYPT_GUARD, CGs[2][0], CGs[2][1], CGs[2][2], CGs[2][3],
                    TEMPSUMMON_MANUAL_DESPAWN))
                {
                    summonedCryptGuards.push_back(pCryptGuard->GetObjectGuid());

                    pCryptGuard->SetInCombatWithZone();
                    if (Unit* pCryptTarget = pCryptGuard->SelectAttackingTarget(AttackingTarget::ATTACKING_TARGET_RANDOM, 0))
                    {
                        pCryptGuard->AI()->AttackStart(pCryptTarget);
                    }
                }
            }
        }
        else
            m_uiLocustSwarmTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

struct mob_cryptguardsAI : public ScriptedAI
{
    instance_naxxramas* m_pInstance;
    bool isEnraged;
    uint32 webTimer;
    uint32 acidSpitTimer;
    uint32 cleaveTimer;

    mob_cryptguardsAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();
    }

    void Reset() override
    {
        isEnraged = false;

        webTimer        = CRYPTGUARD_WEB_CD;
        acidSpitTimer   = CRYPTGUARD_ACID_CD;
        cleaveTimer     = CRYPTGUARD_CLEAVE_CD;
    }

    void Aggro(Unit* pWho) override
    {
        // Make sure anub is pulled too. Anub will take care of pulling the other crypt-guard
        if (Creature* anub = m_pInstance->GetSingleCreatureFromStorage(NPC_ANUB_REKHAN))
        {
            anub->AI()->AttackStart(pWho);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Crypt guards enrage at 50%
        if (!isEnraged && m_creature->GetHealthPercent() <= 50.0f)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_CRYPTGUARD_ENRAGE) == CanCastResult::CAST_OK)
            {
                DoScriptText(EMOTE_GENERIC_ENRAGE, m_creature);
                isEnraged = true;
            }
        }

        if (webTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_CRYPTGUARD_WEB) == CanCastResult::CAST_OK)
            {
                DoResetThreat();
                webTimer = CRYPTGUARD_WEB_CD;
            }
        }
        else
        {
            webTimer -= diff;
        }

        if (cleaveTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CRYPTGUARD_CLEAVE) == CanCastResult::CAST_OK)
            {
                cleaveTimer = CRYPTGUARD_CLEAVE_CD;
            }
        }
        else
        {
            cleaveTimer -= diff;
        }

        if (acidSpitTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CRYPTGUARD_ACID) == CanCastResult::CAST_OK)
            {
                acidSpitTimer = CRYPTGUARD_ACID_CD;
            }
        }
        else
        {
            acidSpitTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

struct anub_doorAI : public GameObjectAI
{
    bool haveDoneIntro;
    instance_naxxramas* m_pInstance;

    anub_doorAI(GameObject* pGo) : GameObjectAI(pGo), haveDoneIntro(false)
    {
        m_pInstance = (instance_naxxramas*)me->GetInstanceData();
        if (!m_pInstance)
            sLog.outError("anub_doorAI could not find instanceData");
    }

    bool OnUse(Unit* user) override
    {
        if (haveDoneIntro)
            return false;

        haveDoneIntro = true;

        if (!m_pInstance)
        {
            sLog.outInfo("[boss_anubrekhan/anub_doorAI][Inst %03u] ERROR: No instance", user->GetInstanceId());
            return false;
        }

        // Not entirely sure if anub should be able to do all of these SAY_TAUNT* texts on door-open.
        // Wowwiki seems quite sure of it, but it makes more sense if it's just the GREET being used
        // on door open, while the rest are said at random points during the fight?
        if (Creature* anubRekhan = m_pInstance->GetSingleCreatureFromStorage(NPC_ANUB_REKHAN))
        {
            if (anubRekhan->IsAlive())
                DoScriptText(PickRandomValue(SAY_GREET, SAY_TAUNT1, SAY_TAUNT2, SAY_TAUNT3, SAY_TAUNT4), anubRekhan);
        }
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        return false;
    }
};

CreatureAI* GetAI_boss_anubrekhan(Creature* pCreature)
{
    return new boss_anubrekhanAI(pCreature);
}

CreatureAI* GetAI_mob_cryptguards(Creature* pCreature)
{
    return new mob_cryptguardsAI(pCreature);
}

GameObjectAI* GetAI_anub_door(GameObject* pGo)
{
    return new anub_doorAI(pGo);
}

void AddSC_boss_anubrekhan()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_anubrekhan";
    NewScript->GetAI = &GetAI_boss_anubrekhan;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "mob_cryptguards";
    NewScript->GetAI = &GetAI_mob_cryptguards;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "go_anub_door";
    NewScript->GOGetAI = &GetAI_anub_door;
    NewScript->RegisterSelf();  
}
