/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: boss_prince_taldaram
SDAuthor: Tartalo & tlexii
SD%Complete: 0
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "ahnkahet.h"

enum Spells
{
    SPELL_BLOODTHIRST                   = 55968, //Trigger Spell + add aura
    SPELL_CONJURE_FLAME_SPHERE          = 55931,
    SPELL_FLAME_SPHERE_SUMMON_1         = 55895,// 1x 30106
    H_SPELL_FLAME_SPHERE_SUMMON_1       = 59511,// 1x 31686
    H_SPELL_FLAME_SPHERE_SUMMON_2       = 59512,// 1x 31687
    SPELL_FLAME_SPHERE_SPAWN_EFFECT     = 55891,
    SPELL_FLAME_SPHERE_VISUAL           = 55928,
    SPELL_FLAME_SPHERE_PERIODIC         = 55926,
    H_SPELL_FLAME_SPHERE_PERIODIC       = 59508,
    SPELL_FLAME_SPHERE_DEATH_EFFECT     = 55947,
    SPELL_BEAM_VISUAL                   = 60342,
    SPELL_EMBRACE_OF_THE_VAMPYR         = 55959,
    H_SPELL_EMBRACE_OF_THE_VAMPYR       = 59513,
    SPELL_VANISH                        = 55964,
    CREATURE_FLAME_SPHERE               = 30106,
    H_CREATURE_FLAME_SPHERE_1           = 31686,
    H_CREATURE_FLAME_SPHERE_2           = 31687
};
enum Misc
{
    DATA_EMBRACE_DMG                    = 20000,
    H_DATA_EMBRACE_DMG                  = 40000,
    DATA_SPHERE_DISTANCE                =    15
};
#define DATA_SPHERE_ANGLE_OFFSET            0.7
#define DATA_GROUND_POSITION_Z             11.4
enum Achievements
{
    ACHIEVEMENT_THE_PARTY_IS_OVER       = 1861
};
enum Yells
{
    SAY_AGGRO                                = -1619021,
    SAY_SLAY_1                               = -1619022,
    SAY_SLAY_2                               = -1619023,
    SAY_DEATH                                = -1619024,
    SAY_FEED_1                               = -1619025,
    SAY_FEED_2                               = -1619026,
    SAY_VANISH_1                             = -1619027,
    SAY_VANISH_2                             = -1619028
};
enum CombatPhase
{
    NORMAL,
    CASTING_FLAME_SPHERES,
    JUST_VANISHED,
    VANISHED,
    FEEDING
};

struct TRINITY_DLL_DECL boss_taldaramAI : public ScriptedAI
{
    boss_taldaramAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    uint32 uiBloodthirstTimer;
    uint32 uiVanishTimer;
    uint32 uiWaitTimer;
    uint32 uiEmbraceTimer;
    uint32 uiEmbraceTakenDamage;
    uint32 uiFlamesphereTimer;
    uint32 uiPhaseTimer;

    uint64 uiSphereGuids[2];

    Unit *pEmbraceTarget;
    Unit *pSphereTarget;

    Creature* pSpheres[3];

    CombatPhase Phase;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiBloodthirstTimer = 10000;
        uiVanishTimer = (25 + rand()%10)*1000;
        uiEmbraceTimer = 20000;
        uiFlamesphereTimer = 5000;
        uiEmbraceTakenDamage = 0;
        Phase = NORMAL;
        uiPhaseTimer = 0;
        pEmbraceTarget = NULL;
        if (pInstance)
            pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, IN_PROGRESS);
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (uiPhaseTimer <= diff)
        {
            switch (Phase)
            {
                case CASTING_FLAME_SPHERES:
                    //DoCast(m_creature, SPELL_FLAME_SPHERE_SUMMON_1);
                    pSpheres[0] = DoSpawnCreature(CREATURE_FLAME_SPHERE, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                    pSphereTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                    if (pSphereTarget && pSpheres[0])
                    {
                        float angle,x,y;
                        angle = pSpheres[0]->GetAngle(pSphereTarget);
                        x = pSpheres[0]->GetPositionX() + DATA_SPHERE_DISTANCE * cos(angle);
                        y = pSpheres[0]->GetPositionY() + DATA_SPHERE_DISTANCE * sin(angle);
                        pSpheres[0]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[0]->GetPositionZ());
                    }
                    if (HeroicMode)
                    {
                        //DoCast(m_creature, H_SPELL_FLAME_SPHERE_SUMMON_1);
                        pSpheres[1] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_1, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                        //DoCast(m_creature, H_SPELL_FLAME_SPHERE_SUMMON_2);
                        pSpheres[2] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_2, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                        if (pSphereTarget && pSpheres[1] && pSpheres[2])
                        {
                            float angle,x,y;
                            angle = pSpheres[1]->GetAngle(pSphereTarget) + DATA_SPHERE_ANGLE_OFFSET;
                            x = pSpheres[1]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * cos(angle);
                            y = pSpheres[1]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * sin(angle);
                            pSpheres[1]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[1]->GetPositionZ());
                            angle = pSpheres[2]->GetAngle(pSphereTarget) - DATA_SPHERE_ANGLE_OFFSET;
                            x = pSpheres[2]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * cos(angle);
                            y = pSpheres[2]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * sin(angle);
                            pSpheres[2]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[2]->GetPositionZ());
                        }
                    }

                    Phase = NORMAL;
                    uiPhaseTimer = 0;
                break;
                case JUST_VANISHED:
                    if(pEmbraceTarget)
                    {
                        m_creature->GetMotionMaster()->Clear();
                        m_creature->SetSpeed(MOVE_WALK, 2.0f, true);
                        m_creature->GetMotionMaster()->MoveChase(pEmbraceTarget);
                    }
                    Phase = VANISHED;
                    uiPhaseTimer = 1300;
                break;
                case VANISHED:
                    if(pEmbraceTarget)
                        DoCast(pEmbraceTarget, HEROIC(SPELL_EMBRACE_OF_THE_VAMPYR, H_SPELL_EMBRACE_OF_THE_VAMPYR));
                        m_creature->GetMotionMaster()->Clear();
                        m_creature->SetSpeed(MOVE_WALK, 1.0f, true);
                        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                    Phase = FEEDING;
                    uiPhaseTimer = 20000;
                break;
                case FEEDING:
                    Phase = NORMAL;
                    uiPhaseTimer = 0;
                    pEmbraceTarget = NULL;
                break;
                case NORMAL:
                    if (uiBloodthirstTimer <= diff)
                    {
                        DoCast(m_creature->getVictim(), SPELL_BLOODTHIRST);
                        uiBloodthirstTimer = 10000;
                    } else uiBloodthirstTimer -= diff;

                    if (uiFlamesphereTimer <= diff)
                    {
                        DoCast(m_creature, SPELL_CONJURE_FLAME_SPHERE);
                        Phase = CASTING_FLAME_SPHERES;
                        uiPhaseTimer = 3000 + diff;
                        uiFlamesphereTimer = 15000;
                    } else uiFlamesphereTimer -= diff;

                    if (uiVanishTimer <= diff)
                    {
                        //Count alive players
                        Unit *pTarget = NULL;
                        std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
                        std::vector<Unit *> target_list;
                        for (std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                        {
                            pTarget = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                            // exclude pets & totems
                            if (pTarget && pTarget->GetTypeId() == TYPEID_PLAYER && pTarget->isAlive())
                                target_list.push_back(pTarget);
                            pTarget = NULL;
                        }
                        //He only vanishes if there are 3 or more alive players
                        if (target_list.size() > 2)
                        {
                            DoScriptText(RAND(SAY_VANISH_1,SAY_VANISH_2), m_creature);
                            DoCast(m_creature, SPELL_VANISH);
                            Phase = JUST_VANISHED;
                            uiPhaseTimer = 500;
                            pEmbraceTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                        }
                        uiVanishTimer = urand(25000,35000);
                    } else uiVanishTimer -= diff;

                    DoMeleeAttackIfReady();
                break;
            }
        } else uiPhaseTimer -= diff;
    }

    void DamageTaken(Unit* done_by, uint32 &damage)
    {
        if (Phase == FEEDING && pEmbraceTarget && pEmbraceTarget->isAlive())
        {
          uiEmbraceTakenDamage += damage;
          if (uiEmbraceTakenDamage > (HeroicMode ? H_DATA_EMBRACE_DMG : DATA_EMBRACE_DMG))
          {
              Phase = NORMAL;
              uiPhaseTimer = 0;
              pEmbraceTarget = NULL;
              m_creature->CastStop();
          }
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, DONE);

            //The Party's Over achievement:
            AchievementEntry const *AchievThePartyIsOver = GetAchievementStore()->LookupEntry(ACHIEVEMENT_THE_PARTY_IS_OVER);
            Map* pMap = m_creature->GetMap();
            if (pMap && pMap->IsDungeon() && HeroicMode && AchievThePartyIsOver)
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                if (players.getSize() < 5)
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievThePartyIsOver);
            }
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        if (Phase == FEEDING && pEmbraceTarget && victim == pEmbraceTarget)
        {
            Phase = NORMAL;
            uiPhaseTimer = 0;
            pEmbraceTarget = NULL;
        }
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    bool CheckSpheres()
    {
        if(!pInstance)
            return false;
        uiSphereGuids[0] = pInstance->GetData64(DATA_SPHERE1);
        uiSphereGuids[1] = pInstance->GetData64(DATA_SPHERE2);

        GameObject *pSpheres[2];
        for (uint8 i=0; i < 2; ++i)
        {
            pSpheres[i] = pInstance->instance->GetGameObject(uiSphereGuids[i]);
            if (!pSpheres[i])
                return false;
            if (pSpheres[i]->GetGoState() != GO_STATE_ACTIVE)
                return false;
        }
        RemovePrison();
        return true;
    }

    void RemovePrison()
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveAurasDueToSpell(SPELL_BEAM_VISUAL);
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_WALK_MODE);
        m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), DATA_GROUND_POSITION_Z, m_creature->GetOrientation());
        uint64 prison_GUID = pInstance->GetData64(DATA_PRINCE_TALDARAM_PLATFORM);
        pInstance->HandleGameObject(prison_GUID,true);
    }
};

struct TRINITY_DLL_DECL mob_taldaram_flamesphereAI : public ScriptedAI
{
    mob_taldaram_flamesphereAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiDespawnTimer;
    ScriptedInstance* pInstance;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
        m_creature->setFaction(16);
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
        DoCast(m_creature, SPELL_FLAME_SPHERE_VISUAL);
        DoCast(m_creature, SPELL_FLAME_SPHERE_SPAWN_EFFECT);
        DoCast(m_creature, HEROIC(SPELL_FLAME_SPHERE_PERIODIC, H_SPELL_FLAME_SPHERE_PERIODIC));
        uiDespawnTimer = 10000;
    }

    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who) {}

    void JustDied(Unit* slayer)
    {
        DoCast(m_creature, SPELL_FLAME_SPHERE_DEATH_EFFECT);
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiDespawnTimer <= diff)
            m_creature->DisappearAndDie();
        else
            uiDespawnTimer -= diff;
    }
};

CreatureAI* GetAI_boss_taldaram(Creature* pCreature)
{
    return new boss_taldaramAI (pCreature);
}

CreatureAI* GetAI_mob_taldaram_flamesphere(Creature* pCreature)
{
    return new mob_taldaram_flamesphereAI (pCreature);
}

bool GOHello_prince_taldaram_sphere(Player *pPlayer, GameObject *pGO)
{
    ScriptedInstance *pInstance = pGO->GetInstanceData();

    Creature *pPrinceTaldaram = Unit::GetCreature(*pGO, pInstance ? pInstance->GetData64(DATA_PRINCE_TALDARAM) : 0);
    if (pPrinceTaldaram && pPrinceTaldaram->isAlive())
    {
        // maybe these are hacks :(
        pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        pGO->SetGoState(GO_STATE_ACTIVE);

        switch(pGO->GetEntry())
        {
            case 193093: pInstance->SetData(DATA_SPHERE1_EVENT,IN_PROGRESS); break;
            case 193094: pInstance->SetData(DATA_SPHERE2_EVENT,IN_PROGRESS); break;
        }

        CAST_AI(boss_taldaramAI, pPrinceTaldaram->AI())->CheckSpheres();
    }
    return true;
}

void AddSC_boss_taldaram()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_taldaram";
    newscript->GetAI = &GetAI_boss_taldaram;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_taldaram_flamesphere";
    newscript->GetAI = &GetAI_mob_taldaram_flamesphere;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "prince_taldaram_sphere";
    newscript->pGOHello = &GOHello_prince_taldaram_sphere;
    newscript->RegisterSelf();
}
