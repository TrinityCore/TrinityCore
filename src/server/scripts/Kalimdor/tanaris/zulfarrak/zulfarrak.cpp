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
SDName: Zulfarrak
SD%Complete: 50
SDComment: Consider it temporary, no instance script made for this instance yet.
SDCategory: Zul'Farrak
EndScriptData */

/* ContentData
npc_sergeant_bly
npc_weegli_blastfuse
EndContentData */

#include "scriptPCH.h"
#include "zulfarrak.h"

/*######
## npc_sergeant_bly
######*/

enum blyAndCrewFactions
{
    FACTION_HOSTILE           = 14,
    FACTION_FRIENDLY          = 35,  //while in cages (so the trolls won't attack them while they're caged)
    FACTION_FREED             = 250  //after release (so they'll be hostile towards trolls)
};

enum blySays
{
    SAY_1       = -1209002, // What? How dare you say that to me?!?
    SAY_2       = -1209003, // After all we've been through? Well, I didn't like you anyway!!
    SAY_WEEGLI  = -1209004, // I'm out of here!
};

enum blySpells
{
    SPELL_SHIELD_BASH          = 11972,
    SPELL_REVENGE              = 12170
};

#define GOSSIP_BLY                  "That's it! I'm tired of helping you out.  It's time we settled things on the battlefield!"


struct npc_sergeant_blyAI : public ScriptedAI
{
    npc_sergeant_blyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        postGossipStep = 0;
        Text_Timer = 0;
        PlayerGUID = 0;
        Reset();
    }

    InstanceData* pInstance;

    uint32 postGossipStep;
    uint32 Text_Timer;
    uint32 ShieldBash_Timer;
    uint32 Revenge_Timer;                                   //this is wrong, spell should never be used unless m_creature->GetVictim() dodge, parry or block attack. Trinity support required.
    uint64 PlayerGUID;

    void Reset() override
    {
        ShieldBash_Timer = 5000;
        Revenge_Timer = 8000;

//        m_creature->SetFactionTemplateId(FACTION_FRIENDLY);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!pInstance)
            return;

        if (postGossipStep > 0 && postGossipStep < 4)
        {
            if (Text_Timer < diff)
            {
                switch (postGossipStep)
                {
                    case 1:
                        DoScriptText(SAY_1, m_creature);
                        Text_Timer = 5000;
                        break;
                    case 2:
                        DoScriptText(SAY_2, m_creature);
                        Text_Timer = 5000;
                        break;
                    case 3:
                        m_creature->SetFactionTemplateId(FACTION_HOSTILE);
                        if (Player* pTarget = ((Player*)Unit::GetUnit(*m_creature, PlayerGUID)))
                            AttackStart(pTarget);
                        //weegli doesn't fight - he goes & blows up the door
                        if (Creature* weegli = pInstance->instance->GetCreature(pInstance->GetData64(ENTRY_WEEGLI)))
                        {
                            weegli->AI()->DoAction();
                            DoScriptText(SAY_WEEGLI, weegli);
                        }

                        switchFactionIfAlive(pInstance, ENTRY_RAVEN);
                        switchFactionIfAlive(pInstance, ENTRY_ORO);
                        switchFactionIfAlive(pInstance, ENTRY_MURTA);
                }
                postGossipStep++;
            }
            else
                Text_Timer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (ShieldBash_Timer <= diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHIELD_BASH);
            ShieldBash_Timer = 15000;
        }
        else
            ShieldBash_Timer -= diff;

        if (Revenge_Timer <= diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_REVENGE);
            Revenge_Timer = 10000;
        }
        else
            Revenge_Timer -= diff;

        DoMeleeAttackIfReady();
    }

    void DoAction(uint32 const param) override
    {
        postGossipStep = 1;
        Text_Timer = 0;
    }

    void switchFactionIfAlive(InstanceData* pInstance, uint32 entry)
    {
        if (Creature* crew = pInstance->instance->GetCreature(pInstance->GetData64(entry)))
            if (crew->IsAlive())
                crew->SetFactionTemplateId(FACTION_HOSTILE);
    }
};

bool OnGossipSelect_npc_sergeant_bly(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        if (npc_sergeant_blyAI* ai = dynamic_cast<npc_sergeant_blyAI*>(pCreature->AI()))
        {
            ai->PlayerGUID = pPlayer->GetGUID();
            ai->DoAction(0);
        }
    }
    return true;
}

bool OnGossipHello_npc_sergeant_bly(Player* pPlayer, Creature* pCreature)
{
    if (InstanceData* pInstance = pCreature->GetInstanceData())
    {
        if (pInstance->GetData(EVENT_PYRAMID) == PYRAMID_KILLED_ALL_TROLLS)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(1517, pCreature->GetGUID());
        }
        else if (pInstance->GetData(EVENT_PYRAMID) == PYRAMID_NOT_STARTED)
            pPlayer->SEND_GOSSIP_MENU(1515, pCreature->GetGUID());
        else
            pPlayer->SEND_GOSSIP_MENU(1516, pCreature->GetGUID());
        return true;
    }
    return false;
}

CreatureAI* GetAI_npc_sergeant_bly(Creature* pCreature)
{
    return new npc_sergeant_blyAI(pCreature);
}


void AddSC_npc_sergeant_bly()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "npc_sergeant_bly";
    pNewScript->GetAI = &GetAI_npc_sergeant_bly;
    pNewScript->pGossipHello = &OnGossipHello_npc_sergeant_bly;
    pNewScript->pGossipSelect = &OnGossipSelect_npc_sergeant_bly;
    pNewScript->RegisterSelf();
}

/*######
+## go_troll_cage
+######*/

void initBlyCrewMember(InstanceData* pInstance, uint32 entry, float x, float y, float z)
{
    uint64 creaGUID = pInstance->GetData64(entry);

    if (Creature* crew = pInstance->instance->GetCreature(creaGUID))
    {
        //crew->GetCharmInfo()->SetReactState(REACT_AGGRESSIVE);
        crew->SetCombatStartPosition(x, y, z);
        crew->SetHomePosition(x, y, z, 4.7f);
        crew->GetMotionMaster()->MovePoint(1, x, y, z, MOVE_PATHFINDING | MOVE_WALK_MODE);
        crew->SetFactionTemplateId(FACTION_FREED);
    }
}


bool OnGossipHello_go_troll_cage(Player* pPlayer, GameObject* pGo)
{
    if (InstanceData* pInstance = pGo->GetInstanceData())
    {
        pInstance->SetData(EVENT_PYRAMID, PYRAMID_CAGES_OPEN);
        //set bly & co to aggressive & start moving to top of stairs
        initBlyCrewMember(pInstance, ENTRY_BLY, 1887.17f, 1263.72f, 41.484f);
        initBlyCrewMember(pInstance, ENTRY_RAVEN, 1890.76f, 1265.82f, 41.43f);
        initBlyCrewMember(pInstance, ENTRY_ORO, 1883.3f, 1272.53f, 41.87f);
        initBlyCrewMember(pInstance, ENTRY_WEEGLI, 1883.87f, 1263.49f, 41.55f);
        initBlyCrewMember(pInstance, ENTRY_MURTA, 1886.48f, 1272.76f, 41.76f);
    }
    return false;
}

void AddSC_go_troll_cage()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "go_troll_cage";
    pNewScript->pGOHello = &OnGossipHello_go_troll_cage;
    pNewScript->RegisterSelf();
}
/*######
## npc_weegli_blastfuse
######*/

enum weegliSpells
{
    SPELL_BOMB                 = 8858,
    SPELL_GOBLIN_LAND_MINE     = 21688,
    SPELL_SHOOT                = 6660,
    SPELL_WEEGLIS_BARREL       = 10772
};

enum weegliSays
{
    SAY_WEEGLI_OHNO      = -1209000,
    SAY_WEEGLI_OK_I_GO   = -1209001,
    SAY_CHIEF_UKORZ_DOOR = -1209004
};

#define GOSSIP_WEEGLI               "Will you blow up that door now?"


struct npc_weegli_blastfuseAI : public ScriptedAI
{
    npc_weegli_blastfuseAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        destroyingDoor = false;
        runAway = false;
        Bomb_Timer = 10000;
        LandMine_Timer = 30000;
        explosiveGUID = 0;
        disappear = false;
        regen = false;
    }

    uint64 explosiveGUID;
    uint32 Bomb_Timer;
    uint32 LandMine_Timer;
    bool destroyingDoor;
    bool runAway;
    bool disappear;
    bool regen;
    ScriptedInstance* pInstance;

    void Reset() override
    {
        /*if (pInstance)
            pInstance->SetData(0, NOT_STARTED);*/
    }

    void AttackStart(Unit *victim) override
    {
        ScriptedAI::AttackStart(victim);
        //AttackStartCaster(victim,10);//keep back & toss bombs/shoot
    }

    void JustDied(Unit * /*victim*/) override
    {
        /*if (pInstance)
            pInstance->SetData(0, DONE);*/
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!regen && pInstance->GetData(EVENT_PYRAMID) == PYRAMID_KILLED_ALL_TROLLS)
        {
            regen = true;

            Creature* pOro = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_ORO));
            if (pOro->IsAlive())
                pOro->SetHealthPercent(100.0f);

            Creature* pMurta = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_MURTA));
            if (pMurta->IsAlive())
                pMurta->SetHealthPercent(100.0f);

            Creature* pBly = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_BLY));
            if (pBly->IsAlive())
                pBly->SetHealthPercent(100.0f);

            Creature* pRaven = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_RAVEN));
            if (pRaven->IsAlive())
                pRaven->SetHealthPercent(100.0f);

            if (m_creature->IsAlive())
                m_creature->SetHealthPercent(100.0f);
        }


        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;


        if (pInstance->GetData(EVENT_PYRAMID) != PYRAMID_KILLED_ALL_TROLLS)
        {
            Creature* pOro = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_ORO));
            if (!pOro->SelectHostileTarget() || !pOro->GetVictim())
                ((CreatureAI*)pOro->AI())->AttackStart(m_creature->GetVictim());

            Creature* pMurta = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_MURTA));
            if (!pMurta->SelectHostileTarget() || !pMurta->GetVictim())
                ((CreatureAI*)pMurta->AI())->AttackStart(m_creature->GetVictim());

            Creature* pBly = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_BLY));
            if (!pBly->SelectHostileTarget() || !pBly->GetVictim())
                ((CreatureAI*)pBly->AI())->AttackStart(m_creature->GetVictim());
        }

        if (Bomb_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BOMB);
            Bomb_Timer = 10000;
        }
        else
            Bomb_Timer -= diff;

        if (m_creature->IsAttackReady() && !m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHOOT);
            m_creature->SetSheath(SHEATH_STATE_RANGED);
        }
        else
        {
            m_creature->SetSheath(SHEATH_STATE_MELEE);
            DoMeleeAttackIfReady();
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (pInstance)
        {
            if (pInstance->GetData(EVENT_PYRAMID) == PYRAMID_CAGES_OPEN)
            {
                if (id == 1)
                {
                    pInstance->SetData(EVENT_PYRAMID, PYRAMID_ARRIVED_AT_STAIR);
                    DoScriptText(SAY_WEEGLI_OHNO, m_creature);
                    m_creature->SetCombatStartPosition(1882.69f, 1272.28f, 41.87f);
                    m_creature->SetWalk(false);
                    m_creature->GetMotionMaster()->MovePoint(2, 1883.27f, 1268.72f, 41.73f);
                }
            }
            else if (pInstance->GetData(EVENT_PYRAMID) == PYRAMID_WAVE_1 && id == 2)
            {
                m_creature->GetMotionMaster()->MovePoint(3, 1888.55f, 1272.19f, 41.67f);
                m_creature->SetCombatStartPosition(1888.55f, 1272.19f, 41.67f);
                m_creature->SetHomePosition(1888.55f, 1272.19f, 41.67f, 4.7f);
                m_creature->SetWalk(true);
            }
            else
            {
                if (destroyingDoor)
                {
                    GameObject* go = m_creature->SummonGameObject(144065, 1856.314209f, 1144.990479f, 15.486275f, 5.6635f, 0, 0, 0, 0, -1, false);
                    explosiveGUID = go->GetGUID();
                    destroyingDoor = false;
                    RunAfterExplosion1();
                }
                if (runAway && id == 1)
                {
                    if (GameObject* pBoom = m_creature->GetMap()->GetGameObject(explosiveGUID))
                    {
                        pBoom->SetSpellId(13259);
                        pBoom->UseDoorOrButton(explosiveGUID);
                    }
                    uint64 EndDoorGUID = pInstance->GetData64(GO_END_DOOR);
                    pInstance->DoUseDoorOrButton(EndDoorGUID, 0, true);
                    pInstance->SetData(EVENT_END_DOOR, DONE);
                    if (Creature* pChief = m_creature->GetMap()->GetCreature(pInstance->GetData64(ENTRY_UKORZ)))
                        DoScriptText(SAY_CHIEF_UKORZ_DOOR, pChief);
                    RunAfterExplosion2();
                    runAway = false;
                }
                if (disappear && id == 2)
                    m_creature->ForcedDespawn();
            }
        }
    }

    void DoAction(uint32 const param) override
    {
        sLog.outString("DoAction de npc_weegli_blastfuse : Destruction porte");
        DestroyDoor();
    }

    void DestroyDoor()
    {
        if (m_creature->IsAlive())
        {
            m_creature->SetFactionTemplateId(FACTION_FRIENDLY);
            m_creature->SetWalk(false);
            m_creature->GetMotionMaster()->MovePoint(0, 1858.57f, 1146.35f, 14.745f);
            m_creature->SetCombatStartPosition(1858.57f, 1146.35f, 14.745f); // in case he gets interrupted
            DoScriptText(SAY_WEEGLI_OK_I_GO, m_creature);
            destroyingDoor = true;
        }
    }

    void RunAfterExplosion1()
    {
        if (m_creature->IsAlive())
        {
            m_creature->GetMotionMaster()->MovePoint(1, 1863.77f, 1176.99f, 9.993f);
            m_creature->SetCombatStartPosition(1863.77f, 1176.99f, 9.993f); // in case he gets interrupted

            runAway = true;
        }
    }

    void RunAfterExplosion2()
    {
        if (m_creature->IsAlive())
        {
            m_creature->GetMotionMaster()->MovePoint(2, 1827.1f, 1184.0f, 8.993f);
            m_creature->SetCombatStartPosition(1827.1f, 1184.0f, 8.993f); // in case he gets interrupted
            disappear = true;
        }
    }

};


bool OnGossipSelect_npc_weegli_blastfuse(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        //here we make him run to door, set the charge and run away off to nowhere
        pCreature->AI()->DoAction();
    }
    return true;
}

bool OnGossipHello_npc_weegli_blastfuse(Player* pPlayer, Creature* pCreature)
{
    if (InstanceData* pInstance = pCreature->GetInstanceData())
    {
        switch (pInstance->GetData(EVENT_PYRAMID))
        {
            case PYRAMID_KILLED_ALL_TROLLS:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WEEGLI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(1514, pCreature->GetGUID());  //if event can proceed to end
                break;
            case PYRAMID_NOT_STARTED:
                pPlayer->SEND_GOSSIP_MENU(1511, pCreature->GetGUID());  //if event not started
                break;
            default:
                pPlayer->SEND_GOSSIP_MENU(1513, pCreature->GetGUID());  //if event are in progress
        }
        return true;
    }
    return false;
}

CreatureAI* GetAI_npc_weegli_blastfuse(Creature* pCreature)
{
    return new npc_weegli_blastfuseAI(pCreature);
}

void AddSC_npc_weegli_blastfuse()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "npc_weegli_blastfuse";
    pNewScript->GetAI = &GetAI_npc_weegli_blastfuse;
    pNewScript->pGossipHello = &OnGossipHello_npc_weegli_blastfuse;
    pNewScript->pGossipSelect = &OnGossipSelect_npc_weegli_blastfuse;
    pNewScript->RegisterSelf();
}

/*######
## go_shallow_grave
######*/

enum
{
    ZOMBIE = 7286,
    DEAD_HERO = 7276,
    ZOMBIE_CHANCE = 65,
    DEAD_HERO_CHANCE = 10
};

bool OnGossipHello_go_shallow_grave(Player* pPlayer, GameObject* pGo)
{
    // randomly summon a zombie or dead hero the first time a grave is used
    if (pGo->GetUseCount() == 0)
    {
        uint32 randomchance = urand(0, 100);
        if (randomchance < ZOMBIE_CHANCE)
            pGo->SummonCreature(ZOMBIE, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
        else if ((randomchance - ZOMBIE_CHANCE) < DEAD_HERO_CHANCE)
            pGo->SummonCreature(DEAD_HERO, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
    }
    pGo->AddUse();
    return true;
}

void AddSC_go_shallow_grave()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "go_shallow_grave";
    pNewScript->GOOpen = &OnGossipHello_go_shallow_grave;
    pNewScript->RegisterSelf();
}
/*######
## at_zumrah
######*/

enum zumrahConsts
{
    NPC_WITCH_DOCTOR_ZUMRAH = 7271,
    ZUMRAH_HOSTILE_FACTION  = 37,

    SAY_ZUMRAH_TRIGGER      = 3622,
    SAY_ZUMRAH_YELL         = 6221,
    SAY_ZUMRAH_KILLED       = 6222
};

bool OnTrigger_at_zumrah(Player* pPlayer, AreaTriggerEntry const *at)
{
    Creature* pZumrah = pPlayer->FindNearestCreature(NPC_WITCH_DOCTOR_ZUMRAH, 30.0f);

    if (!pZumrah || !pZumrah->IsAlive())
        return false;

    if (pZumrah->GetFactionTemplateId() != ZUMRAH_HOSTILE_FACTION)
    {
        if (InstanceData* pInstance = pZumrah->GetInstanceData())
            pInstance->SetData(EVENT_ZUMRAH, IN_PROGRESS);

        pZumrah->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
        pZumrah->SetFactionTemplateId(ZUMRAH_HOSTILE_FACTION);
        DoScriptText(SAY_ZUMRAH_TRIGGER, pZumrah);
    }

    return true;
}

bool OnGossipHello_go_table_theka(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestStatus(2936) == QUEST_STATUS_INCOMPLETE)
        pPlayer->AreaExploredOrEventHappens(2936);

    pPlayer->SEND_GOSSIP_MENU(1653, pGo->GetGUID());

    return true;
}

struct ward_zumrahAI : public ScriptedAI
{
    ward_zumrahAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSkeletonTimer;

    void Reset() override
    {
        m_uiSkeletonTimer = 5000;
        m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);

        if (m_uiSkeletonTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, 11088, true) == CAST_OK)
                m_uiSkeletonTimer = 5000;
        }
        else
            m_uiSkeletonTimer -= uiDiff;
    }
};

CreatureAI* GetAI_ward_zumrah(Creature* pCreature)
{
    return new ward_zumrahAI(pCreature);
}

void AddSC_at_zumrah()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "at_zumrah";
    pNewScript->pAreaTrigger = &OnTrigger_at_zumrah;
    pNewScript->RegisterSelf();
}

void AddSC_zulfarrak()
{
    AddSC_npc_sergeant_bly();
    AddSC_npc_weegli_blastfuse();
    AddSC_go_shallow_grave();
    AddSC_at_zumrah();
    AddSC_go_troll_cage();

    Script* newscript;

    newscript = new Script;
    newscript->Name = "ward_zumrah";
    newscript->GetAI = &GetAI_ward_zumrah;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_table_theka";
    newscript->pGOHello = &OnGossipHello_go_table_theka;
    newscript->RegisterSelf();
}
