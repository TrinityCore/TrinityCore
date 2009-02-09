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
SDName: HyjalAI
SD%Complete: 90
SDComment:
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "hyjalAI.h"

// Locations for summoning waves in Alliance base
float AllianceBase[4][3]=
{
    {4979.010, -1709.134, 1339.674},
    {4969.123, -1705.904, 1341.363},
    {4970.260, -1698.546, 1341.200},
    {4975.262, -1698.239, 1341.427}
};

// Locations for summoning waves in Horde base
float HordeBase[4][3]=
{
    {5554.399, -2581.419, 1480.820},
    {5538.996, -2577.742, 1479.790},
    {5565.642, -2565.666, 1481.635},
    {5547.218, -2574.589, 1479.194}
};

// used to inform the wave where to move and attack to
float AttackArea[2][3]=
{
    {5042.9189, -1776.2562, 1323.0621}, // Alliance
    {5510.4815, -2676.7112, 1480.4314} // Horde
};

hyjalAI::hyjalAI(Creature *c) : ScriptedAI(c)
{
    pInstance = ((ScriptedInstance*)c->GetInstanceData());
    Reset();
}

void hyjalAI::Reset()
{
    // GUIDs
    PlayerGUID = 0;
    BossGUID[0] = 0;
    BossGUID[1] = 0;

    // Timers
    NextWaveTimer = 10000;
    CheckTimer = 0;
    RetreatTimer = 1000;

    // Misc
    WaveCount = 0;

    // Set faction properly based on creature entry
    switch(m_creature->GetEntry())
    {
        case 17772:
            Faction = 0;
            DoCast(m_creature, SPELL_BRILLIANCE_AURA, true);
            break;

        case 17852:
            Faction = 1;
            break;
    }

    //Bools
    EventBegun = false;
    FirstBossDead = false;
    SecondBossDead = false;
    Summon = false;
    bRetreat = false;
    Debug = false;

    //Flags
    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    //Initialize spells
    memset(Spell, 0, sizeof(Spell));

    //Reset World States
    UpdateWorldState(WORLD_STATE_WAVES, 0);
    UpdateWorldState(WORLD_STATE_ENEMY, 0);
    UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);

    //Reset Instance Data for trash count
    if(pInstance)
        pInstance->SetData(DATA_RESET_TRASH_COUNT, 0);
    else error_log(ERROR_INST_DATA);

    //Visibility
    m_creature->SetVisibility(VISIBILITY_ON);

    //If Jaina evades, reset the visibility of all other creatures in the grid.
    if(CreatureList.empty())
        return;

    for(std::list<uint64>::iterator itr = CreatureList.begin(); itr != CreatureList.end(); ++itr)
        if(Creature* cr = ((Creature*)Unit::GetUnit(*m_creature, *itr)))
            cr->SetVisibility(VISIBILITY_ON);

    CreatureList.clear();
}

void hyjalAI::EnterEvadeMode()
{
    m_creature->InterruptNonMeleeSpells(true);
    m_creature->RemoveAllAuras();
    m_creature->DeleteThreatList();
    m_creature->CombatStop();
    m_creature->LoadCreaturesAddon();

    if(m_creature->isAlive())
        m_creature->GetMotionMaster()->MoveTargetedHome();

    m_creature->SetLootRecipient(NULL);

    InCombat = false;
}

void hyjalAI::Aggro(Unit *who)
{
    for(uint8 i = 0; i < 2; ++i)
        if(Spell[i].Cooldown)
            SpellTimer[i] = Spell[i].Cooldown;

    Talk(ATTACKED);
}

void hyjalAI::SummonCreature(uint32 entry, float Base[4][3])
{
    uint32 random = rand()%4;
    float SpawnLoc[3];
    float AttackLoc[3];

    for(uint8 i = 0; i < 3; ++i)
    {
        SpawnLoc[i] = Base[random][i];
        AttackLoc[i] = AttackArea[Faction][i];
    }

    Creature* pCreature = m_creature->SummonCreature(entry, SpawnLoc[0], SpawnLoc[1], SpawnLoc[2], 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000);
    if(pCreature)
    {
        // Increment Enemy Count to be used in World States and instance script
        ++EnemyCount;

        pCreature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        pCreature->GetMotionMaster()->MovePoint(0, AttackLoc[0],AttackLoc[1],AttackLoc[2]);
        pCreature->AddThreat(m_creature, 0.0f);
        DoZoneInCombat(pCreature);

        // Check if creature is a boss.
        if (pCreature->isWorldBoss())
        {
            if(!FirstBossDead)  BossGUID[0] = pCreature->GetGUID();
            else                BossGUID[1] = pCreature->GetGUID();
            CheckTimer = 5000;
        }
    }
}

void hyjalAI::SummonNextWave(Wave wave[18], uint32 Count, float Base[4][3])
{
    // 1 in 4 chance we give a rally yell. Not sure if the chance is offilike.
    if (rand()%4 == 0)
        Talk(RALLY);

    if(!pInstance)
    {
        error_log(ERROR_INST_DATA);
        return;
    }

    EnemyCount = pInstance->GetData(DATA_TRASH);
    for(uint8 i = 0; i < 18; ++i)
    {
        if(wave[Count].Mob[i])
            SummonCreature(wave[Count].Mob[i], Base);
    }

    if(!wave[Count].IsBoss)
    {
        uint32 stateValue = Count+1;
        if(FirstBossDead)
            stateValue -= 9;                                // Subtract 9 from it to give the proper wave number if we are greater than 8
        UpdateWorldState(WORLD_STATE_WAVES, stateValue);    // Set world state to our current wave number
        UpdateWorldState(WORLD_STATE_ENEMY, 1);             // Enable world state

        pInstance->SetData(DATA_TRASH, EnemyCount);         // Send data for instance script to update count

        if(!Debug)
            NextWaveTimer = wave[Count].WaveTimer;
        else
        {
            NextWaveTimer = 15000;
            debug_log("TSCR: HyjalAI: debug mode is enabled. Next Wave in 15 seconds");
        }
    }
    else
    {
        UpdateWorldState(WORLD_STATE_WAVES, 0);             // Set world state for waves to 0 to disable it.
        UpdateWorldState(WORLD_STATE_ENEMY, 1);
        UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 1);        // Set World State for enemies invading to 1.
        Summon = false;
    }
    CheckTimer = 5000;
}

void hyjalAI::StartEvent(Player* player)
{
    if(!player)
        return;

    Talk(BEGIN);

    EventBegun = true;
    Summon = true;

    NextWaveTimer = 15000;
    CheckTimer = 5000;
    PlayerGUID = player->GetGUID();

    m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    UpdateWorldState(WORLD_STATE_WAVES, 0);
    UpdateWorldState(WORLD_STATE_ENEMY, 0);
    UpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);
}

uint32 hyjalAI::GetInstanceData(uint32 Event)
{
    if(pInstance)
        return pInstance->GetData(Event);
    else error_log(ERROR_INST_DATA);

    return 0;
}

void hyjalAI::Talk(uint32 id)
{
    std::list<uint8> index;
    for(uint8 i = 0; i < 10; i++)
    {
        if(Faction == 0)                                    // Alliance
        {
            if(JainaQuotes[i].id == id)
                index.push_back(i);
        }
        else if(Faction == 1)                               // Horde
        {
            if(ThrallQuotes[i].id == id)
                index.push_back(i);
        }
    }

    if(index.empty())
        return;                                             // No quotes found, no use to continue

    uint8 ind = *(index.begin()) + rand()%index.size();

    int32 YellId = 0;
    if(Faction == 0)                                        // Alliance
    {
        YellId = JainaQuotes[ind].textid;
    }
    else if(Faction == 1)                                   // Horde
    {
        YellId = ThrallQuotes[ind].textid;
    }

    if (YellId)
        DoScriptText(YellId, m_creature);
}

void hyjalAI::UpdateWorldState(uint32 id, uint32 state)
{
    Map * map = m_creature->GetMap();

    if(!map->IsDungeon())
        return;

    Map::PlayerList const& players = map->GetPlayers();

    if (!players.isEmpty())
    {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* player = itr->getSource())
                    player->SendUpdateWorldState(id,state);
            }
    }else debug_log("TSCR: HyjalAI: UpdateWorldState, but PlayerList is empty");

     //remove everything above this line only when/if the core patch for this is accepted and needed
    //m_creature->GetMap()->UpdateWorldState(field, value);
}

void hyjalAI::Retreat()
{
    CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
    Cell cell(pair);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    // First get all creatures.
    std::list<Creature*> creatures;
    Trinity::AllFriendlyCreaturesInGrid creature_check(m_creature);
    Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid> creature_searcher(creatures, creature_check);
    TypeContainerVisitor
        <Trinity::CreatureListSearcher<Trinity::AllFriendlyCreaturesInGrid>,
        GridTypeMapContainer> creature_visitor(creature_searcher);

    // Then get all Ancient Gem Veins. NOTE: Grid Search will only be able to find those in the grid.
    std::list<GameObject*> goList;
    Trinity::AllGameObjectsWithEntryInGrid go_check(185557);
    Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInGrid> go_search(goList, go_check);
    TypeContainerVisitor
        <Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInGrid>, GridTypeMapContainer> go_visit(go_search);

    CellLock<GridReadGuard> cell_lock(cell, pair);
                                                            // Get Creatures
    cell_lock->Visit(cell_lock, creature_visitor, *(m_creature->GetMap()));
                                                            // Get GOs
    cell_lock->Visit(cell_lock, go_visit, *(m_creature->GetMap()));

    CreatureList.clear();
    if(!creatures.empty())
    {
        for(std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
        {
            (*itr)->CastSpell(*itr, SPELL_TELEPORT_VISUAL, true);
            CreatureList.push_back((*itr)->GetGUID());
        }

        DoCast(m_creature, SPELL_TELEPORT_VISUAL);
        bRetreat = true;
        RetreatTimer = 1000;
    }

    if(!goList.empty())
    {
        for(std::list<GameObject*>::iterator itr = goList.begin(); itr != goList.end(); ++itr)
            (*itr)->SetRespawnTime(5000);
    }
}

void hyjalAI::UpdateAI(const uint32 diff)
{
    if(bRetreat)
    {
        if(RetreatTimer < diff)
        {
            bRetreat = false;
            if(CreatureList.empty())
                return;

            for(std::list<uint64>::iterator itr = CreatureList.begin(); itr != CreatureList.end(); ++itr)
                if(Unit* pUnit = Unit::GetUnit(*m_creature, *itr))
                    pUnit->SetVisibility(VISIBILITY_OFF);

            m_creature->SetVisibility(VISIBILITY_OFF);
        }else RetreatTimer -= diff;
    }

    if(!EventBegun)
        return;

    if(Summon)
    {
        if(pInstance && EnemyCount)
        {
            EnemyCount = pInstance->GetData(DATA_TRASH);
            if(!EnemyCount)
                NextWaveTimer = 5000;
        }

        if(NextWaveTimer < diff)
        {
            if(Faction == 0)
                SummonNextWave(AllianceWaves, WaveCount, AllianceBase);
            else if(Faction == 1)
                SummonNextWave(HordeWaves, WaveCount, HordeBase);
            ++WaveCount;
        }else NextWaveTimer -= diff;
    }

    if(CheckTimer < diff)
    {
        for(uint8 i = 0; i < 2; ++i)
        {
            if(BossGUID[i])
            {
                Unit* pUnit = Unit::GetUnit((*m_creature), BossGUID[i]);
                if(pUnit && (!pUnit->isAlive()))
                {
                    if(BossGUID[i] == BossGUID[0])
                    {
                        Talk(INCOMING);
                        FirstBossDead = true;
                    }
                    else if(BossGUID[i] == BossGUID[1])
                    {
                        Talk(SUCCESS);
                        SecondBossDead = true;
                    }
                    EventBegun = false;
                    CheckTimer = 0;
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    BossGUID[i] = 0;
                    UpdateWorldState(WORLD_STATE_ENEMY, 0); // Reset world state for enemies to disable it
                }
            }
        }
        CheckTimer = 5000;
    }else CheckTimer -= diff;

    if(!UpdateVictim())
        return;

    for(uint8 i = 0; i < 3; ++i)
    {
        if(Spell[i].SpellId)
        {
            if(SpellTimer[i] < diff)
            {
                if(m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                Unit* target = NULL;

                switch(Spell[i].TargetType)
                {
                    case TARGETTYPE_SELF: target = m_creature; break;
                    case TARGETTYPE_RANDOM: target = SelectUnit(SELECT_TARGET_RANDOM, 0); break;
                    case TARGETTYPE_VICTIM: target = m_creature->getVictim(); break;
                }

                if(target && target->isAlive())
                {
                    DoCast(target, Spell[i].SpellId);
                    SpellTimer[i] = Spell[i].Cooldown;
                }
            }else SpellTimer[i] -= diff;
        }
    }

    DoMeleeAttackIfReady();
}
