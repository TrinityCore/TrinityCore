/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Alita
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"
#include "../../../custom/npc_j_eevee.h"

enum
{
    GOBJ_WHEEL              = 179672,
    GOBJ_CANDLE             = 179673,
    GOBJ_BELL               = 179674,
    GOBJ_FEL_FIRE           = /*179676,*/179681,
    GOBJ_DREADSTEED_PORTAL  = 179681,
    GOBJ_RITUAL_CIRCLE      = 179668,
    GOBJ_PEDESTAL           = 300050,
    GOBJ_DARK_CIRCLE        = 300051,

    GOBJ_RUNE_TYPE_1        = 179669, //99776, 99779, 99782
    GOBJ_RUNE_TYPE_2        = 179670, //99775, 99778, 99781
    GOBJ_RUNE_TYPE_3        = 179671, //99774, 99777, 99780

    GOBJ_GUID_RUNE_1        = 99774,
    GOBJ_GUID_RUNE_2        = 99775,
    GOBJ_GUID_RUNE_3        = 99776,
    GOBJ_GUID_RUNE_4        = 99777,
    GOBJ_GUID_RUNE_5        = 99778,
    GOBJ_GUID_RUNE_6        = 99779,
    GOBJ_GUID_RUNE_7        = 99780,
    GOBJ_GUID_RUNE_8        = 99781,
    GOBJ_GUID_RUNE_9        = 99782,

    NPC_J_EEVEE             = 14500,
    NPC_XOROTHIAN_IMP       = 14482,
    NPC_DREAD_GUARD         = 14483,
    NPC_XOROTHIAN_DREADSTEED = 14502,
    NPC_LORD_HEL_NURATH     = 14506,
    NPC_DREADSTEED_SPIRIT   = 14504,

    SPELL_WHEEL_AURA        = 23120,
    SPELL_BELL_AURA         = 23117,
    SPELL_CANDLE_AURA       = 23226,

    SAY_HEL_NURATH          = -1780201,
    SAY_IMP_DESPAWN         = -1780202,
    SAY_DREAD_GUARD_DESPAWN = -1780203
};

struct EventLocations
{
    float m_fX, m_fY, m_fZ, m_fO;
    int m_wait;
};

struct NodeInfo
{
    uint64 highGuid;
    bool up;
};

struct go_pedestal_of_immol_tharAI: public GameObjectAI
{
    go_pedestal_of_immol_tharAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        m_pInstance = (instance_dire_maul*) pGo->GetInstanceData();
        //make sure immolthar is dead
        //m_pInstance->SetData(TYPE_IMMOL_THAR, DONE);  ?
        reset();
    }
    void reset()
    {
        guidRitualCircle = 0;
        eventPhase = 0;
        gobjTimer = 9000;
        gobjStep = 0;

        waveTimer = 0;
        waveStep = 0;

        nodeTimer = urand(15000, 30000);
        nodeTimeTracker = 390000 - nodeTimer;
        nodeNb = 0;
    }
    void GenerateGlyphAndNodeGuids() //glyphs=runes
    {
        uint64 guid = 0;
        GameObject* gobj;
        for (int i = 0; i < 9; i++)
        {
            guid = ObjectGuid(HIGHGUID_GAMEOBJECT, GOBJ_RUNE_TYPE_3 - (i % 3), uint32(GOBJ_GUID_RUNE_1 + i));
            if (gobj = me->GetMap()->GetGameObject(guid))
                guidGlyphTab[i] = guid;
            else
                sLog.outString("Dreadsteed Ritual : cannot find Rune %u", guidGlyphTab[i]);

        }
        for (int i = 0; i < 3; i++)
        {
            if (gobj = me->FindNearestGameObject(GOBJ_WHEEL + i, 30.000000))
            {
                nodes[i].highGuid = gobj->GetGUID();
                nodes[i].up = false;
            }
            else
                sLog.outString("Dreadsteed Ritual : cannot find Node %u", guidGlyphTab[i]);

        }
        if (gobj = me->FindNearestGameObject(GOBJ_RITUAL_CIRCLE, 30.000000))
            guidRitualCircle = gobj->GetGUID();
    }
    instance_dire_maul* m_pInstance;
    NodeInfo nodes[3];
    uint64 guidGlyphTab[9];
    uint64 guidFlameTab[18];
    uint64 guidRitualCircle;
    uint32 gobjTimer;
    uint32 gobjStep;
    uint32 waveTimer;
    uint32 waveStep;
    uint32 nodeTimer;
    uint32 nodeNb;
    uint32 nodeTimeTracker;
    uint32 miniTimer; //for 1-2sec intervals not used yet
    uint8 eventPhase; //0: nothing happened, default. 1: phase with jeevee setting the gobjs 2: phase with demon waves 3: waiting for item use for next 4: dreadsteed&owner

    bool EventStart(uint64 playerGuid)
    {
        if (eventPhase!=0)
            return false;
        if (m_pInstance)
            m_pInstance->SetData64(DATA_DREADSTEED_RITUAL_PLAYER, playerGuid);
        GenerateGlyphAndNodeGuids();
        eventPhase = 1;
        if (Creature* jeevee = me->SummonCreature(NPC_J_EEVEE, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 420000))
        {
            if (npc_j_eevee_dreadsteedAI* jeeveeAI = dynamic_cast<npc_j_eevee_dreadsteedAI*>(jeevee->AI()))
            {
                jeeveeAI->ShoutFreedom();
                jeeveeAI->SetPlayerGuid(playerGuid);
            }
        }
        return true;
    }
    void EventSecondPartStart()
    {
        if(eventPhase!=3)
            return;
        eventPhase = 4;
        waveTimer = 8000;
        waveStep = 0;
        if (GameObject* gobj = me->GetMap()->GetGameObject(guidRitualCircle))
        {
            gobj->SetGoState(GO_STATE_READY);
            gobj->SetSpawnedByDefault(false);
            gobj->SetLootState(GO_READY);
            gobj->SetRespawnTime(1);
        }
        if (GameObject* gobj = me->FindNearestGameObject(GOBJ_DREADSTEED_PORTAL, 10.000000))
        {
            gobj->SetSpawnedByDefault(true);
            gobj->Refresh();
        }
        gobjTimer = 10000;
    }
    void PhaseTwoEndedSuccess()
    {
        if (GameObject* gobj = me->GetMap()->GetGameObject(guidRitualCircle))
            gobj->SetGoState(GO_STATE_ACTIVE);

        //write it in m_pInstance?
        GameObject* gobj;
        for (uint64 guid : guidFlameTab)
        {
            if (gobj = me->GetMap()->GetGameObject(guid))
                gobj->Despawn();
        }
        eventPhase++;

        std::list<Creature*> lCrea;
        me->GetCreatureListWithEntryInGrid(lCrea, NPC_XOROTHIAN_IMP, 30.0f);
        for (const auto& it : lCrea)
        {
            if (it->IsAlive())
                DoScriptText(SAY_IMP_DESPAWN, it);
            it->DisappearAndDie();
        }
        me->GetCreatureListWithEntryInGrid(lCrea, NPC_DREAD_GUARD, 30.0f);
        for (const auto& it : lCrea)
        {
            if (it->IsAlive())
                DoScriptText(SAY_DREAD_GUARD_DESPAWN, it);
            it->DisappearAndDie();
        }
    }
    void EventEndedFail()
    {
        eventPhase = 0;
        GameObject* gobj;
        for (uint64 guid : guidFlameTab)
        {
            if (gobj = me->GetMap()->GetGameObject(guid))
                gobj->Despawn();
        }
        for (uint64 guid : guidGlyphTab)
        {
            if (gobj = me->GetMap()->GetGameObject(guid))
            {
                gobj->SetSpawnedByDefault(false);
                gobj->Refresh();
            }
        }
        if (gobj = me->GetMap()->GetGameObject(guidRitualCircle))
        {
            gobj->SetGoState(GO_STATE_READY);
            gobj->SetSpawnedByDefault(false);
            gobj->Refresh();
        }
        for (const auto& node : nodes)
        {
            if (gobj = me->GetMap()->GetGameObject(node.highGuid))
            {
                gobj->SetSpawnedByDefault(false);
                gobj->Refresh();
            }
        }
        std::list<Creature*> lCrea;
        me->GetCreatureListWithEntryInGrid(lCrea, NPC_XOROTHIAN_IMP, 30.0f);
        for (const auto& it : lCrea)
        {
            if (it->IsAlive())
                DoScriptText(SAY_IMP_DESPAWN, it);
            it->DisappearAndDie();
        }
        me->GetCreatureListWithEntryInGrid(lCrea, NPC_DREAD_GUARD, 30.0f);
        for (const auto& it : lCrea)
        {
            if (it->IsAlive())
                DoScriptText(SAY_DREAD_GUARD_DESPAWN, it);
            it->DisappearAndDie();
        }
        reset();
    }
    void gobjNextStep()
    {
        GameObject* gobj;
        //switch event phase
        switch (eventPhase)
        {
            case 1:
                switch (gobjStep)
                {
                    case 0:
                        //spawn Bell.
                        if (gobj = me->GetMap()->GetGameObject(nodes[2].highGuid))
                        {
                            gobj->SetSpawnedByDefault(true);
                            gobj->Refresh();
                            gobj->SetGoState(GO_STATE_ACTIVE);
                            gobj->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                            nodes[2].up = true;
                        }
                        gobjTimer = 5000;
                        gobjStep++;
                        break;
                    case 1:
                        //spawn Wheel
                        if (gobj = me->GetMap()->GetGameObject(nodes[0].highGuid))
                        {
                            gobj->SetSpawnedByDefault(true);
                            gobj->Refresh();
                            gobj->SetGoState(GO_STATE_ACTIVE);
                            gobj->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                            nodes[0].up = true;
                        }
                        gobjTimer = 6000;
                        gobjStep++;
                        break;
                    case 2:
                        //spawn Candle
                        if (gobj = me->GetMap()->GetGameObject(nodes[1].highGuid))
                        {
                            gobj->SetSpawnedByDefault(true);
                            gobj->Refresh();
                            gobj->SetGoState(GO_STATE_ACTIVE);
                            gobj->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                            nodes[1].up = true;
                        }
                        gobjTimer = 7000;
                        gobjStep++;
                        break;
                    case 3:
                        gobjTimer = 0;
                        eventPhase++;
                        gobjStep = 0;
                        break;
                }
                break;
            case 2:
                switch (gobjStep)
                {
                    case 0:
                        //spawn flammes & circle
                        for (int i = 1; i <= 18; i++)
                        {
                            float angle = (i * 2 * M_PI / 18) + 0.2; //+0.2 to see
                            float x, y, z;
                            me->GetPosition(x, y, z);
                            x += 56.7f * cos(angle);
                            y += 56.7f * sin(angle);
                            if (gobj = me->SummonGameObject(GOBJ_FEL_FIRE, x, y, -29.8f, 0, 0, 0, 0, 0, 480000))
                                guidFlameTab[i - 1] = gobj->GetGUID();
                        }
                        if (gobj = me->GetMap()->GetGameObject(guidRitualCircle))
                        {
                            gobj->SetGoState(GO_STATE_READY);
                            gobj->SetSpawnedByDefault(true);// circle
                            gobj->Refresh();
                        }
                        gobjTimer = 45000;
                        gobjStep++;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        if (gobj = me->GetMap()->GetGameObject(guidGlyphTab[gobjStep - 1]))
                        {
                            gobj->SetSpawnedByDefault(true);
                            gobj->Refresh();
                        }
                        gobjTimer = 45000;
                        gobjStep++;
                        break;
                    case 9:
                        //last glyph
                        if (gobj = me->GetMap()->GetGameObject(guidGlyphTab[8]))
                        {
                            gobj->SetSpawnedByDefault(true);
                            gobj->Refresh();
                            gobj->SendGameObjectCustomAnim();
                        }
                        gobjTimer = 0;
                        gobjStep++;
                        break;
                    case 10:
                        //well basicaly  pause basicaly before p3. wait for 3 nodes to be back up
                        uint8 nbOkNodes = 0;
                        for (const auto& node : nodes)
                        {
                            if (node.up)
                                nbOkNodes++;
                        }
                        if (nbOkNodes == 3)
                            PhaseTwoEndedSuccess();
                        gobjTimer = 20000;
                        break;
                }
                break;
            case 4:
                if (gobj = me->FindNearestGameObject(GOBJ_DREADSTEED_PORTAL, 10.000000))
                {
                    gobj->SetSpawnedByDefault(false);
                    gobj->Refresh();
                }
                gobjStep++;
                break;
        }
    }
    void SummonImp()
    {
        uint8 i = urand(0, 17);
        if (Creature* crea = me->SummonCreature(NPC_XOROTHIAN_IMP, spawnPoints[i].m_fX, spawnPoints[i].m_fY, spawnPoints[i].m_fZ, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000))
        {
            crea->SetFacingToObject(me);
            crea->SetWalk(false);
            float x, y, z;
            me->GetPosition(x, y, z);
            crea->SetHomePosition(x, y, z, 0);
            crea->GetMotionMaster()->Clear();
            crea->GetMotionMaster()->Initialize();
            crea->GetMotionMaster()->MovePoint(1, x, y, z, true);
        }
    }
    void SummonGuard()
    {
        uint8 i = urand(0, 17);
        if (Creature* crea = me->SummonCreature(NPC_DREAD_GUARD, spawnPoints[i].m_fX, spawnPoints[i].m_fY, spawnPoints[i].m_fZ, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000))
        {
            crea->SetFacingToObject(me);
            //crea->SetWalk(false);
            float x, y, z;
            me->GetPosition(x, y, z);
            crea->SetHomePosition(x, y, z, 0);
            crea->GetMotionMaster()->Clear();
            crea->GetMotionMaster()->Initialize();
            crea->GetMotionMaster()->MovePoint(1, x, y, z, true);
        }
    }
    EventLocations spawnPoints[18];//not using m_wait though
    void WaveSpawn()
    {
        float x, y, z;
        me->GetPosition(x, y, z);
        Creature* crea;
        if (eventPhase == 2)
        {
            switch (waveStep) //TODO
            {
                case 0:
                    for (int i = 1; i <= 18; i++)
                    {
                        float angle = (i * 2 * M_PI / 18) + 0.2;
                        x += 63.0f * cos(angle);
                        y += 63.0f * sin(angle);

                        spawnPoints[i - 1].m_fX = x;
                        spawnPoints[i - 1].m_fY = y;
                        spawnPoints[i - 1].m_fZ = -28; //need to check z.
                        if (crea = me->SummonCreature(NPC_XOROTHIAN_IMP, x, y, -28, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000))
                        {
                            crea->SetFacingToObject(me);
                            me->GetPosition(x, y, z);
                            crea->SetHomePosition(x, y, z, 0);
                            crea->GetMotionMaster()->Clear();
                            crea->GetMotionMaster()->Initialize();
                            crea->GetMotionMaster()->MovePoint(1, x, y, z, true);
                        }
                    }
                    waveTimer = 60000;
                    waveStep++;
                    break;
                case 1:
                    SummonImp();
                    SummonImp();
                    SummonGuard();
                    //+1 +1
                    waveTimer = 11000;
                    waveStep++;
                    break;
                case 2:
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    waveTimer = 9000;
                    waveStep++;
                    break;
                case 3:
                    SummonImp();
                    SummonGuard();
                    waveTimer = 10000;
                    waveStep++;
                    break;
                case 4:
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    waveTimer = 28000;
                    waveStep++;
                    break;
                case 5:
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    waveTimer = 20000;
                    waveStep++;
                    break;
                case 6:
                    SummonImp();
                    SummonGuard();
                    waveTimer = 8000;
                    waveStep++;
                    break;
                case 7:
                    SummonImp();
                    SummonImp();
                    waveTimer = 19000;
                    waveStep++;
                    break;
                case 8: //2:51
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    waveTimer = 12000;
                    waveStep++;
                    break;
                case 9://3:42
                    SummonGuard();
                    waveTimer = 20000;
                    waveStep++;
                    break;
                case 10:
                    SummonImp();
                    waveTimer = 23000;
                    waveStep++;
                    break;
                case 11:
                    SummonImp();
                    waveTimer = 5000;
                    waveStep++;
                    break;
                case 12:
                    SummonGuard();
                    //+1guard+1+1+x+1+1
                    waveTimer = 25000;
                    waveStep++;
                    break;
                case 13:
                    SummonImp();
                    SummonImp();
                    SummonImp();
                    //+1+1
                    waveTimer = 28000;
                    waveStep++;
                    break;
                case 14:
                    SummonGuard();
                    //+1+1+3
                    waveTimer = 39000;
                    waveStep++;
                    break;
                case 15:
                    SummonImp();
                    waveTimer = 4000;
                    waveStep++;
                    break;
                case 16://5:23
                    SummonGuard();
                    //+1+2+1
                    waveTimer = 20000;
                    waveStep++;
                    break;
                case 17:
                    SummonImp();
                    //+1
                    waveTimer = 20000;
                    waveStep++;
                    break;
                case 18://6:19
                    SummonImp();
                    waveTimer = 12000;
                    waveStep++;
                    break;
                case 19:
                    SummonImp();
                    SummonGuard();
                    waveTimer = 50000;
                    waveStep++;
                    break;
                case 20://6:29
                    SummonImp();
                    SummonGuard();
                    waveTimer = 20000;
                    waveStep++;
                    break;
                case 21:
                    SummonImp();
                    waveTimer = 4000;
                    waveStep++;
                    break;
                case 22:
                    SummonImp();
                    waveTimer = 8000;
                    waveStep++;
                    break;
                case 23:
                    waveTimer = 0;
                    break;
            }
        }
        else if (eventPhase == 4)
        {
            switch (waveStep)
            {
                case 0:
                    //pop horse
                    if (crea = me->SummonCreature(NPC_XOROTHIAN_DREADSTEED, x, y, z, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
                    {
                    }
                    waveTimer = 10000;
                    waveStep++;
                    break;
                case 1:
                    if (crea = me->SummonCreature(NPC_LORD_HEL_NURATH, x, y, z, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
                        DoScriptText(SAY_HEL_NURATH, crea);
                    waveTimer = 210000;
                    waveStep++;
                    break;
            }
        }
    }
    void BreakNode()
    {
        uint8 nbOkNodes = 0;
        for (const auto& node : nodes)
        {
            if (node.up)
                nbOkNodes++;
        }
        if (nbOkNodes < 2)
        {
            EventEndedFail();
            return;
        }
        uint8 nodeToBreak = urand(0, nbOkNodes - 1);
        if (nbOkNodes == 2)
        {
            uint8 count = 0;
            for (uint8 i = 0; i < 3; i++)
            {
                if (nodes[i].up)
                {
                    if (nodeToBreak == count)
                    {
                        nodeToBreak = i;
                        break;
                    }
                    count++;
                }
            }
        }
        GameObject* gobj = nullptr;
        switch (nodeNb)
        {
            case 0:
            case 1:
            case 2:
            case 3:
                nodeTimer = urand(35000, 45000);
                nodeTimeTracker -= nodeTimer;
                nodes[nodeToBreak].up = false;
                if (gobj = me->GetMap()->GetGameObject(nodes[nodeToBreak].highGuid))
                {
                    gobj->SetGoState(GO_STATE_READY);
                    gobj->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                if ((nodeTimeTracker > (7 - nodeNb) * 41000 + 71000) && urand(0, 1))
                    nodeTimer = 70000;
                else
                    nodeTimer = 41000;
                nodeTimeTracker -= nodeTimer;
                nodes[nodeToBreak].up = false;
                if (gobj = me->GetMap()->GetGameObject(nodes[nodeToBreak].highGuid))
                {
                    gobj->SetGoState(GO_STATE_READY);
                    gobj->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
                break;
            default :
                nodeTimer = 41000;
                nodes[nodeToBreak].up = false;
                if (gobj = me->GetMap()->GetGameObject(nodes[nodeToBreak].highGuid))
                {
                    gobj->SetGoState(GO_STATE_READY);
                    gobj->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
        }
        nodeNb++;
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (eventPhase == 1 || eventPhase == 2 || eventPhase == 4) //and phase < ended
        {
            if (gobjTimer < uiDiff)
                gobjNextStep();
            else
                gobjTimer -= uiDiff;
        }
        if (eventPhase == 2 || eventPhase == 4) //and phase < ended
        {
            if (waveTimer < uiDiff)
                WaveSpawn();
            else
                waveTimer -= uiDiff;
        }
        if (eventPhase == 2) //and phase < ended
        {
            if (nodeTimer < uiDiff)
                BreakNode();
            else
                nodeTimer -= uiDiff;
        }

    }
    //keep an eye on nodes
    void NodeUpped(GameObject* pGo)
    {
        for (auto& node : nodes)
        {
            if (node.highGuid == pGo->GetGUID())
            {
                node.up = true;
                break;
            }
        }
    }
};

GameObjectAI* GetAIgo_pedestal_of_immol_thar(GameObject *pGo)
{
    return new go_pedestal_of_immol_tharAI(pGo);
}

bool ProcessEventId_event_dreadsteed_ritual_start(uint32 eventId, Object* source, Object* target, bool isStart)
{
    if (!target || !source)
        return true;

    if (go_pedestal_of_immol_tharAI* pPedestalAI = dynamic_cast<go_pedestal_of_immol_tharAI*>(((GameObject*) target)->AI()))
        pPedestalAI->EventStart(source->GetGUID());
    return true;//to always override what could be in DB.
}

bool GOHello_go_ritual_node(Player* pPlayer, GameObject* pGo)
{
    pGo->SetGoState(GO_STATE_ACTIVE);
    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    if (GameObject* pPedestal = pGo->FindNearestGameObject(GOBJ_PEDESTAL, 30.000000))
    {
        if (go_pedestal_of_immol_tharAI* pPedestalAI = dynamic_cast<go_pedestal_of_immol_tharAI*>(pPedestal->AI()))
            pPedestalAI->NodeUpped(pGo);
    }
    else
        sLog.outString("Dreadsteed Ritual : GOBJ_PEDESTAL not found");
    return true;
}

struct go_ritual_nodeAI: public GameObjectAI
{
    go_ritual_nodeAI(GameObject* pGo, uint32 refreshTimer, uint32 spellId) : GameObjectAI(pGo)
    {
        timer = 0;
        refreshTime = refreshTimer;
        spell = spellId;
    }
    uint32 timer;
    uint32 refreshTime;
    uint32 spell;

    void UpdateAI(uint32 const uiDiff) override
    {
        if (me->GetGoState() == GO_STATE_ACTIVE && me->isSpawned())
        {
            if (timer < uiDiff)
            {
                if (instance_dire_maul* instance = (instance_dire_maul*)me->GetInstanceData())
                {
                    if (GameObject* candleAura = instance->GetGameObject(instance->GetData64(GO_RITUAL_CANDLE_AURA)))
                    {
                        if (Unit* target = instance->GetMap()->GetPlayer(instance->GetData64(DATA_DREADSTEED_RITUAL_PLAYER)))
                        {
                            if (spell == SPELL_CANDLE_AURA)
                                candleAura->CastSpell(target, spell, true);
                            else
                                me->CastSpell(target, spell, true);
                        }
                    }
                }

                timer = refreshTime/*5000*/;
            }
            else
                timer -= uiDiff;
        }
        else
            timer = 0;
    }
};

GameObjectAI* GetAIgo_ritual_wheel(GameObject *pGo)
{
    return new go_ritual_nodeAI(pGo, 5000, SPELL_WHEEL_AURA);
}

GameObjectAI* GetAIgo_ritual_candle(GameObject *pGo)
{
    return new go_ritual_nodeAI(pGo, 5000, SPELL_CANDLE_AURA);
}

GameObjectAI* GetAIgo_ritual_bell(GameObject *pGo)
{
    return new go_ritual_nodeAI(pGo, 5000, SPELL_BELL_AURA);
}

bool ProcessEventId_event_dreadsteed_ritual_second_part(uint32 eventId, Object* source, Object* target, bool isStart)
{
    if (!target)
        return true;

    if (GameObject* pedestal = ((GameObject*) target)->FindNearestGameObject(GOBJ_PEDESTAL, 10.000))
        if (go_pedestal_of_immol_tharAI* pPedestalAI = dynamic_cast<go_pedestal_of_immol_tharAI*>(pedestal->AI()))
            pPedestalAI->EventSecondPartStart();

    return true;
}

enum
{
    //spells are absolutely certain.
    SPELL_BERSERKER_CHARGE          = 16636, //OK
    SPELL_FLAME_BUFFET              = 22713, //OK
    SPELL_SUMMON_DREADSTEED_SPIRIT  = 23159, //marche en étant mort?
    SPELL_SHADOW_WORD               = 17146, //OK
    SPELL_VEIL_OF_SHADOW            = 23224, //OK
    SPELL_SLEEP                     = 20989, //OK
    SPELL_KNOCK_AWAY                = 18670 //OK
};

struct boss_lordHelNurathAI : public ScriptedAI
{
    boss_lordHelNurathAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiShadowWord_Timer;
    uint32 m_uiVielOfShadow_Timer;
    uint32 m_uiSleep_Timer;
    uint32 m_uiKnockAway_Timer;

    void Reset() override
    {
        m_uiShadowWord_Timer = 28000;
        m_uiVielOfShadow_Timer = 16000;
        m_uiSleep_Timer = 21000;
        m_uiKnockAway_Timer = 20000; //less than 20s
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        if (m_uiShadowWord_Timer < uiDiff)
        {
            //penser à vérifier qu'il change de target si la cible est sleep
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOW_WORD) == CAST_OK)
                m_uiShadowWord_Timer = urand(10000, 30000);
        }
        else
            m_uiShadowWord_Timer -= uiDiff;

        if (m_uiVielOfShadow_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VEIL_OF_SHADOW) == CAST_OK)
                m_uiVielOfShadow_Timer = urand(20000, 85000);
        }
        else
            m_uiVielOfShadow_Timer -= uiDiff;
        if (m_uiSleep_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_SLEEP) == CAST_OK)
                m_uiSleep_Timer = urand(15000, 36000);
        }
        else
            m_uiSleep_Timer -= uiDiff;
        if (m_uiKnockAway_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                m_uiKnockAway_Timer = urand(6000, 10000);
        }
        else
            m_uiKnockAway_Timer -= uiDiff;
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_lord_hel_nurath(Creature* pCreature)
{
    return new boss_lordHelNurathAI(pCreature);
}

struct boss_xorothianDreadsteedAI : public ScriptedAI
{
    boss_xorothianDreadsteedAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCharge_Timer;
    uint32 m_uiFlameBuffet_Timer;

    void Reset() override
    {
        m_uiCharge_Timer = 8000;
        m_uiFlameBuffet_Timer = 10000;
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        if (m_uiCharge_Timer < uiDiff)
        {
            //penser à vérifier qu'il change de target si la cible est sleep
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_BERSERKER_CHARGE) == CAST_OK)
                m_uiCharge_Timer = urand(10000, 18000);
        }
        else
            m_uiCharge_Timer -= uiDiff;

        if (m_uiFlameBuffet_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAME_BUFFET) == CAST_OK)
                m_uiFlameBuffet_Timer = urand(7000, 12000);
        }
        else
            m_uiFlameBuffet_Timer -= uiDiff;
        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* Killer) override
    {
        m_creature->CastSpell(m_creature, SPELL_SUMMON_DREADSTEED_SPIRIT, true);
    }
};

CreatureAI* GetAI_boss_xorothian_dreadsteed(Creature* pCreature)
{
    return new boss_xorothianDreadsteedAI(pCreature);
}

void AddSC_dreadsteed_ritual()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "event_dreadsteed_ritual_start";
    newscript->pProcessEventId = &ProcessEventId_event_dreadsteed_ritual_start;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "event_dreadsteed_ritual_second_part";
    newscript->pProcessEventId = &ProcessEventId_event_dreadsteed_ritual_second_part;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_ritual_wheel";
    newscript->GOGetAI = &GetAIgo_ritual_wheel;
    newscript->pGOHello = &GOHello_go_ritual_node;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_ritual_candle";
    newscript->GOGetAI = &GetAIgo_ritual_candle;
    newscript->pGOHello = &GOHello_go_ritual_node;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_ritual_bell";
    newscript->GOGetAI = &GetAIgo_ritual_bell;
    newscript->pGOHello = &GOHello_go_ritual_node;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_xorothian_dreadsteed";
    newscript->GetAI = &GetAI_boss_xorothian_dreadsteed;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_lord_hel_nurath";
    newscript->GetAI = &GetAI_boss_lord_hel_nurath;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_pedestal_of_immol_thar";
    newscript->GOGetAI = &GetAIgo_pedestal_of_immol_thar;
    newscript->RegisterSelf();
}
