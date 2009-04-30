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
SDName: Azuremyst_Isle
SD%Complete: 75
SDComment: Quest support: 9283, 9537, 9582, 9554, 9531, 9303(special flight path, proper model for mount missing). Injured Draenei cosmetic only
SDCategory: Azuremyst Isle
EndScriptData */

/* ContentData
npc_draenei_survivor
npc_engineer_spark_overgrind
npc_injured_draenei
npc_magwin
npc_susurrus
npc_geezle
mob_nestlewood_owlkin
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"
#include <cmath>

/*######
## npc_draenei_survivor
######*/

#define HEAL1        -1000248
#define HEAL2        -1000249
#define HEAL3        -1000250
#define HEAL4        -1000251

#define HELP1        -1000252
#define HELP2        -1000253
#define HELP3        -1000254
#define HELP4        -1000255

struct TRINITY_DLL_DECL npc_draenei_survivorAI : public ScriptedAI
{
    npc_draenei_survivorAI(Creature *c) : ScriptedAI(c) {}

    uint32 UnSpawnTimer;
    uint32 ResetlifeTimer;
    uint32 SayingTimer;
    uint32 HealSayTimer;
    bool UnSpawn;
    bool say;
    bool HealSay;
    bool isRun;
    bool isMove;

    void Reset()
    {
        UnSpawnTimer = 2500;
        ResetlifeTimer= 60000;
        SayingTimer    = 5000;
        HealSayTimer = 6000;
        say = false;
        isRun = false;
        isMove = false;
        UnSpawn    = false;
        HealSay = false;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
        //cast red shining
        m_creature->CastSpell(m_creature, 29152, false, NULL);
        //set creature health
        m_creature->SetHealth(int(m_creature->GetMaxHealth()*.1));
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 3);
    }

    void Aggro(Unit *who) {}

    void MoveInLineOfSight(Unit *who)                       //MoveInLineOfSight is called if creature could see you, updated all 100 ms
    {
        if (!who)
            return;

        if(who->GetTypeId() == TYPEID_PLAYER && m_creature->IsFriendlyTo(who) && m_creature->IsWithinDistInMap(who, 15) && say && !isRun)
        {
            switch (rand()%4)                               //Random switch between 4 texts
            {
                case 0:
                    DoScriptText(HELP1, m_creature);
                    SayingTimer = 15000;
                    say = false;
                    break;
                case 1:
                    DoScriptText(HELP2, m_creature);
                    SayingTimer = 15000;
                    say = false;
                    break;
                case 2:
                    DoScriptText(HELP3, m_creature);
                    SayingTimer = 15000;
                    say = false;
                    break;
                case 3:
                    DoScriptText(HELP4, m_creature);
                    SayingTimer = 15000;
                    say = false;
                    break;
            }
        }
        else
        {
            isRun = false;
        }
    }

    void UpdateAI(const uint32 diff)                        //Is also called each ms for Creature AI Updates...
    {
        if (m_creature->GetHealth() > 50)
        {
            if(ResetlifeTimer < diff)
            {
                ResetlifeTimer = 60000;
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                //set creature health
                m_creature->SetHealth(int(m_creature->GetMaxHealth()*.1));
                // ley down
                m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,3);
            }
            else ResetlifeTimer -= diff;
        }

        if(HealSay)
        {
            if (HealSayTimer < diff)
            {
                UnSpawn = true;
                isRun = true;
                isMove = true;
            }else HealSayTimer -= diff;
        }

        if(UnSpawn)
        {
            if(isMove)
            {
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MovePoint(0, -4115.053711f, -13754.831055f, 73.508949f);
                isMove = false;
            }

            if (UnSpawnTimer < diff)
            {
                m_creature->StopMoving();
                EnterEvadeMode();
                //set creature health
                m_creature->SetHealth(int(m_creature->GetMaxHealth()*.1));
                return;
            }else UnSpawnTimer -= diff;
        }

        if(SayingTimer < diff)
        {
            say = true;
        }else SayingTimer -= diff;
    }

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)//Called if you cast a spell and do some things if Specified spell is true!
    {
        if (Hitter && Spellkind->Id == 28880)
        {
            m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            m_creature->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);
            m_creature->HandleEmoteCommand(ANIM_RISE);
            switch (rand()%4)                               //This switch doesn't work at all, creature say nothing!
            {
                case 0: DoScriptText(HEAL1, m_creature, Hitter); break;
                case 1: DoScriptText(HEAL2, m_creature, Hitter); break;
                case 2: DoScriptText(HEAL3, m_creature, Hitter); break;
                case 3: DoScriptText(HEAL4, m_creature, Hitter); break;
            }
            HealSay    = true;
        }
    }
};
CreatureAI* GetAI_npc_draenei_survivor(Creature *_Creature)
{
    return new npc_draenei_survivorAI (_Creature);
}

/*######
## npc_engineer_spark_overgrind
######*/

#define SAY_TEXT        -1000256
#define SAY_EMOTE       -1000257
#define ATTACK_YELL     -1000258

#define GOSSIP_FIGHT    "Traitor! You will be brought to justice!"

#define SPELL_DYNAMITE  7978

struct TRINITY_DLL_DECL npc_engineer_spark_overgrindAI : public ScriptedAI
{
    npc_engineer_spark_overgrindAI(Creature *c) : ScriptedAI(c) {}

    uint32 Dynamite_Timer;
    uint32 Emote_Timer;

    void Reset()
    {
        Dynamite_Timer = 8000;
        Emote_Timer = 120000 + rand()%30000;
        m_creature->setFaction(875);
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if( !InCombat )
        {
            if (Emote_Timer < diff)
            {
                DoScriptText(SAY_TEXT, m_creature);
                DoScriptText(SAY_EMOTE, m_creature);
                Emote_Timer = 120000 + rand()%30000;
            }else Emote_Timer -= diff;
        }

        if(!UpdateVictim())
            return;

        if (Dynamite_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_DYNAMITE);
            Dynamite_Timer = 8000;
        } else Dynamite_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_engineer_spark_overgrind(Creature *_Creature)
{
    return new npc_engineer_spark_overgrindAI (_Creature);
}

bool GossipHello_npc_engineer_spark_overgrind(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(9537) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(0, GOSSIP_FIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_engineer_spark_overgrind(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF )
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->setFaction(14);
        DoScriptText(ATTACK_YELL, _Creature, player);
        ((npc_engineer_spark_overgrindAI*)_Creature->AI())->AttackStart(player);
    }
    return true;
}

/*######
## npc_injured_draenei
######*/

struct TRINITY_DLL_DECL npc_injured_draeneiAI : public ScriptedAI
{
    npc_injured_draeneiAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
        m_creature->SetHealth(int(m_creature->GetMaxHealth()*.15));
        switch (rand()%2)
        {
            case 0: m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 1); break;
            case 1: m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 3); break;
        }
    }

    void Aggro(Unit *who) {}

    void MoveInLineOfSight(Unit *who)
    {
        return;                                             //ignore everyone around them (won't aggro anything)
    }

    void UpdateAI(const uint32 diff)
    {
        return;
    }

};
CreatureAI* GetAI_npc_injured_draenei(Creature *_Creature)
{
    return new npc_injured_draeneiAI (_Creature);
}

/*######
## npc_magwin
######*/

#define SAY_START               -1000111
#define SAY_AGGRO               -1000112
#define SAY_PROGRESS            -1000113
#define SAY_END1                -1000114
#define SAY_END2                -1000115
#define EMOTE_HUG               -1000116

#define QUEST_A_CRY_FOR_HELP    9528

struct TRINITY_DLL_DECL npc_magwinAI : public npc_escortAI
{
    npc_magwinAI(Creature *c) : npc_escortAI(c) {}


    void WaypointReached(uint32 i)
    {
        Player* player = Unit::GetPlayer(PlayerGUID);

        if (!player)
            return;

        switch(i)
        {
        case 0:
            DoScriptText(SAY_START, m_creature, player);
            break;
        case 17:
            DoScriptText(SAY_PROGRESS, m_creature, player);
            break;
        case 28:
            DoScriptText(SAY_END1, m_creature, player);
            break;
        case 29:
            DoScriptText(EMOTE_HUG, m_creature, player);
            DoScriptText(SAY_END2, m_creature, player);
            if (player && player->GetTypeId() == TYPEID_PLAYER)
                ((Player*)player)->GroupEventHappens(QUEST_A_CRY_FOR_HELP,m_creature);
            break;
        }
    }

    void Aggro(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature, who);
    }

    void Reset()
    {
        if (!IsBeingEscorted)
            m_creature->setFaction(80);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID)
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_A_CRY_FOR_HELP);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_magwin(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_A_CRY_FOR_HELP)
    {
        creature->setFaction(113);
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_magwinAI(Creature *_Creature)
{
    npc_magwinAI* magwinAI = new npc_magwinAI(_Creature);

    magwinAI->AddWaypoint(0, -4784.532227, -11051.060547, 3.484263);
    magwinAI->AddWaypoint(1, -4805.509277, -11037.293945, 3.043942);
    magwinAI->AddWaypoint(2, -4827.826172, -11034.398438, 1.741959);
    magwinAI->AddWaypoint(3, -4852.630859, -11033.695313, 2.208656);
    magwinAI->AddWaypoint(4, -4876.791992, -11034.517578, 3.175228);
    magwinAI->AddWaypoint(5, -4895.486816, -11038.306641, 9.390890);
    magwinAI->AddWaypoint(6, -4915.464844, -11048.402344, 12.369793);
    magwinAI->AddWaypoint(7, -4937.288086, -11067.041992, 13.857983);
    magwinAI->AddWaypoint(8, -4966.577637, -11067.507813, 15.754786);
    magwinAI->AddWaypoint(9, -4993.799805, -11056.544922, 19.175295);
    magwinAI->AddWaypoint(10, -5017.836426, -11052.569336, 22.476587);
    magwinAI->AddWaypoint(11, -5039.706543, -11058.459961, 25.831593);
    magwinAI->AddWaypoint(12, -5057.289063, -11045.474609, 26.972496);
    magwinAI->AddWaypoint(13, -5078.828125, -11037.601563, 29.053417);
    magwinAI->AddWaypoint(14, -5104.158691, -11039.195313, 29.440195);
    magwinAI->AddWaypoint(15, -5120.780273, -11039.518555, 30.142139);
    magwinAI->AddWaypoint(16, -5140.833008, -11039.810547, 28.788074);
    magwinAI->AddWaypoint(17, -5161.201660, -11040.050781, 27.879545, 4000);
    magwinAI->AddWaypoint(18, -5171.842285, -11046.803711, 27.183821);
    magwinAI->AddWaypoint(19, -5185.995117, -11056.359375, 20.234867);
    magwinAI->AddWaypoint(20, -5198.485840, -11065.065430, 18.872593);
    magwinAI->AddWaypoint(21, -5214.062500, -11074.653320, 19.215731);
    magwinAI->AddWaypoint(22, -5220.157227, -11088.377930, 19.818476);
    magwinAI->AddWaypoint(23, -5233.652832, -11098.846680, 18.349432);
    magwinAI->AddWaypoint(24, -5250.163086, -11111.653320, 16.438959);
    magwinAI->AddWaypoint(25, -5268.194336, -11125.639648, 12.668313);
    magwinAI->AddWaypoint(26, -5286.270508, -11130.669922, 6.912246);
    magwinAI->AddWaypoint(27, -5317.449707, -11137.392578, 4.963446);
    magwinAI->AddWaypoint(28, -5334.854492, -11154.384766, 6.742664);
    magwinAI->AddWaypoint(29, -5353.874512, -11171.595703, 6.903912, 20000);
    magwinAI->AddWaypoint(30, -5354.240000, -11171.940000, 6.890000);

    return (CreatureAI*)magwinAI;
}

/*######
## npc_susurrus
######*/

bool GossipHello_npc_susurrus(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->HasItemCount(23843,1,true))
        player->ADD_GOSSIP_ITEM(0, "I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_susurrus(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,32474,true);               //apparently correct spell, possible not correct place to cast, or correct caster

        std::vector<uint32> nodes;

        nodes.resize(2);
        nodes[0] = 92;                                      //from susurrus
        nodes[1] = 91;                                      //end at exodar
        player->ActivateTaxiPathTo(nodes,11686);            //TaxiPath 506. Using invisible model, possible Trinity must allow 0(from dbc) for cases like this.
    }
    return true;
}

/*######
## npc_geezle
######*/

#define GEEZLE_SAY_1    -1000259
#define SPARK_SAY_2     -1000260
#define SPARK_SAY_3     -1000261
#define GEEZLE_SAY_4    -1000262
#define SPARK_SAY_5     -1000263
#define SPARK_SAY_6     -1000264
#define GEEZLE_SAY_7    -1000265

#define EMOTE_SPARK     -1000266

#define MOB_SPARK       17243
#define GO_NAGA_FLAG    181694

static float SparkPos[3] = {-5030.95, -11291.99, 7.97};

struct TRINITY_DLL_DECL npc_geezleAI : public ScriptedAI
{
    npc_geezleAI(Creature *c) : ScriptedAI(c) {}

    std::list<GameObject*> FlagList;

    uint64 SparkGUID;

    uint32 Step;
    uint32 SayTimer;

    bool EventStarted;

    void Reset()
    {
        SparkGUID = 0;
        Step = 0;
        StartEvent();
    }

    void Aggro(Unit* who){}

    void StartEvent()
    {
        Step = 1;
        EventStarted = true;
        Creature* Spark = m_creature->SummonCreature(MOB_SPARK, SparkPos[0], SparkPos[1], SparkPos[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
        if(Spark)
        {
            SparkGUID = Spark->GetGUID();
            Spark->setActive(true);
            Spark->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Spark->GetMotionMaster()->MovePoint(0, -5080.70, -11253.61, 0.56);
        }
        m_creature->GetMotionMaster()->MovePoint(0, -5092.26, -11252, 0.71);
        SayTimer = 23000;
    }

    uint32 NextStep(uint32 Step)
    {
        Unit* Spark = Unit::GetUnit((*m_creature), SparkGUID);

        switch(Step)
        {
        case 0: return 99999;
        case 1:
            //DespawnNagaFlag(true);
            DoScriptText(EMOTE_SPARK, Spark);
            return 1000;
        case 2:
            DoScriptText(GEEZLE_SAY_1, m_creature, Spark);
            if(Spark)
            {
                Spark->SetInFront(m_creature);
                m_creature->SetInFront(Spark);
            }
            return 5000;
        case 3: DoScriptText(SPARK_SAY_2, Spark); return 7000;
        case 4: DoScriptText(SPARK_SAY_3, Spark); return 8000;
        case 5: DoScriptText(GEEZLE_SAY_4, m_creature, Spark); return 8000;
        case 6: DoScriptText(SPARK_SAY_5, Spark); return 9000;
        case 7: DoScriptText(SPARK_SAY_6, Spark); return 8000;
        case 8: DoScriptText(GEEZLE_SAY_7, m_creature, Spark); return 2000;
        case 9:
            m_creature->GetMotionMaster()->MoveTargetedHome();
            if(Spark)
                Spark->GetMotionMaster()->MovePoint(0, -5030.95, -11291.99, 7.97);
            return 20000;
        case 10:
            if(Spark)
                Spark->DealDamage(Spark,Spark->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            //DespawnNagaFlag(false);
            m_creature->SetVisibility(VISIBILITY_OFF);
        default: return 99999999;
        }
    }

    void DespawnNagaFlag(bool despawn)
    {
        CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        Trinity::AllGameObjectsWithEntryInGrid go_check(GO_NAGA_FLAG);
        Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInGrid> go_search(FlagList, go_check);
        TypeContainerVisitor
            <Trinity::GameObjectListSearcher<Trinity::AllGameObjectsWithEntryInGrid>, GridTypeMapContainer> go_visit(go_search);
        CellLock<GridReadGuard> cell_lock(cell, pair);
        cell_lock->Visit(cell_lock, go_visit, *(m_creature->GetMap()));

        Player* player = NULL;
        if (!FlagList.empty())
        {
            for(std::list<GameObject*>::iterator itr = FlagList.begin(); itr != FlagList.end(); ++itr)
            {
                //TODO: Found how to despawn and respawn
                if(despawn)
                    (*itr)->RemoveFromWorld();
                else
                    (*itr)->Respawn();
            }
        } else error_log("SD2 ERROR: FlagList is empty!");
    }

    void UpdateAI(const uint32 diff)
    {
        if(SayTimer < diff)
        {
            if(EventStarted)
            {
                SayTimer = NextStep(++Step);
            }
        }else SayTimer -= diff;
    }
};

CreatureAI* GetAI_npc_geezleAI(Creature *_Creature)
{
    return new npc_geezleAI(_Creature);
}

/*######
## mob_nestlewood_owlkin
######*/

#define INOCULATION_CHANNEL 29528
#define INOCULATED_OWLKIN   16534

struct TRINITY_DLL_DECL mob_nestlewood_owlkinAI : public ScriptedAI
{
    mob_nestlewood_owlkinAI(Creature *c) : ScriptedAI(c) {}

    uint32 ChannelTimer;
    bool Channeled;
    bool Hitted;

    void Reset()
    {
        ChannelTimer = 0;
        Channeled = false;
        Hitted = false;
    }

    void Aggro(Unit *who){}

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if(!caster)
            return;

        if(caster->GetTypeId() == TYPEID_PLAYER && spell->Id == INOCULATION_CHANNEL)
        {
            ChannelTimer = 3000;
            Hitted = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(ChannelTimer < diff && !Channeled && Hitted)
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
            m_creature->SummonCreature(INOCULATED_OWLKIN, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 180000);
            Channeled = true;
        }else ChannelTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_nestlewood_owlkinAI(Creature *_Creature)
{
    return new mob_nestlewood_owlkinAI (_Creature);
}

void AddSC_azuremyst_isle()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_draenei_survivor";
    newscript->GetAI = &GetAI_npc_draenei_survivor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_engineer_spark_overgrind";
    newscript->GetAI = &GetAI_npc_engineer_spark_overgrind;
    newscript->pGossipHello =  &GossipHello_npc_engineer_spark_overgrind;
    newscript->pGossipSelect = &GossipSelect_npc_engineer_spark_overgrind;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_injured_draenei";
    newscript->GetAI = &GetAI_npc_injured_draenei;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_magwin";
    newscript->GetAI = &GetAI_npc_magwinAI;
    newscript->pQuestAccept = &QuestAccept_npc_magwin;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_susurrus";
    newscript->pGossipHello =  &GossipHello_npc_susurrus;
    newscript->pGossipSelect = &GossipSelect_npc_susurrus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_geezle";
    newscript->GetAI = &GetAI_npc_geezleAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_nestlewood_owlkin";
    newscript->GetAI = &GetAI_mob_nestlewood_owlkinAI;
    newscript->RegisterSelf();

}

