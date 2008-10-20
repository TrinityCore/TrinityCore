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
SDName: The_Barrens
SD%Complete: 90
SDComment: Quest support: 2458, 4921, 6981
SDCategory: Barrens
EndScriptData */

/* ContentData
npc_beaten_corpse
npc_sputtervalve
npc_taskmaster_fizzule      remove hack when Trinity implement feature/detect spell kind to not aggro
EndContentData */

#include "precompiled.h"

/*######
## npc_beaten_corpse
######*/

bool GossipHello_npc_beaten_corpse(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(4921) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(4921) == QUEST_STATUS_COMPLETE)
        player->ADD_GOSSIP_ITEM(0,"Examine corpse in detail...",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(3557,_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_beaten_corpse(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if(action == GOSSIP_ACTION_INFO_DEF +1)
    {
        player->SEND_GOSSIP_MENU(3558,_Creature->GetGUID());
        player->KilledMonster( 10668,_Creature->GetGUID() );
    }
    return true;
}

/*######
## npc_sputtervalve
######*/

bool GossipHello_npc_sputtervalve(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( player->GetQuestStatus(6981) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(0,"Can you tell me about this shard?",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_sputtervalve(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if(action == GOSSIP_ACTION_INFO_DEF)
    {
        player->SEND_GOSSIP_MENU(2013,_Creature->GetGUID());
        player->AreaExploredOrEventHappens(6981);
    }
    return true;
}

/*######
## npc_taskmaster_fizzule
######*/

//#define FACTION_HOSTILE_F       430
#define FACTION_HOSTILE_F       16
#define FACTION_FRIENDLY_F      35

#define SPELL_FLARE             10113
#define SPELL_FOLLY             10137

struct TRINITY_DLL_DECL npc_taskmaster_fizzuleAI : public ScriptedAI
{
    npc_taskmaster_fizzuleAI(Creature* c) : ScriptedAI(c) { Reset(); }

    bool IsFriend;
    uint32 Reset_Timer;
    uint32 FlareCount;

    void Reset()
    {
        IsFriend = false;
        Reset_Timer = 120000;
        FlareCount = 0;
        m_creature->setFaction(FACTION_HOSTILE_F);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }

    //This is a hack. Spellcast will make creature aggro but that is not
    //supposed to happen (Trinity not implemented/not found way to detect this spell kind)
    void DoUglyHack()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop();
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if( spell->Id == SPELL_FLARE || spell->Id == SPELL_FOLLY )
        {
            DoUglyHack();
            ++FlareCount;
            if( FlareCount >= 2 )
            {
                m_creature->setFaction(FACTION_FRIENDLY_F);
                IsFriend = true;
            }
        }
    }

    void Aggro(Unit* who) { }

    void UpdateAI(const uint32 diff)
    {
        if( IsFriend )
        {
            if( Reset_Timer < diff )
            {
                EnterEvadeMode();
            } else Reset_Timer -= diff;
        }

        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_taskmaster_fizzule(Creature *_Creature)
{
    return new npc_taskmaster_fizzuleAI (_Creature);
}

bool ReciveEmote_npc_taskmaster_fizzule(Player *player, Creature *_Creature, uint32 emote)
{
    if( emote == TEXTEMOTE_SALUTE )
    {
        if( ((npc_taskmaster_fizzuleAI*)_Creature->AI())->FlareCount >= 2 )
        {
            _Creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            _Creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
        }
    }
    return true;
}
/*#####
## npc_twiggy_flathead
#####*/

#define BIG_WILL 6238
#define AFFRAY_CHALLENGER 6240
#define SAY_BIG_WILL_READY                  "Ready when you are, warrior"
#define SAY_TWIGGY_FLATHEAD_BEGIN           "The Affray has begun, get ready to fight!"
#define SAY_TWIGGY_FLATHEAD_FRAY            "You! Enter the fray!"
#define SAY_TWIGGY_FLATHEAD_DOWN            "Challenger is down!"
#define SAY_TWIGGY_FLATHEAD_OVER            "The Affray is over"

float AffrayChallengerLoc[6][4]=
{
    {-1683, -4326, 2.79, 0},
    {-1682, -4329, 2.79, 0},
    {-1683, -4330, 2.79, 0},
    {-1680, -4334, 2.79, 1.49},
    {-1674, -4326, 2.79, 3.49},
    {-1677, -4334, 2.79, 1.66}
};

struct TRINITY_DLL_DECL npc_twiggy_flatheadAI : public ScriptedAI
{
    npc_twiggy_flatheadAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool EventInProgress;
    bool EventGrate;
    bool EventBigWill;
    bool Challenger_down[6];
    uint32 Wave;
    uint32 Wave_Timer;
    uint32 Challenger_checker;
    uint64 PlayerGUID;
    uint64 AffrayChallenger[6];
    uint64 BigWill;

    void Reset()
    {
        EventInProgress = false;
        EventGrate = false;
        EventBigWill = false;
        Wave_Timer = 600000;
        Challenger_checker = 0;
        Wave = 0;
        PlayerGUID = 0;

        for(uint8 i = 0; i < 6; i++) {
            AffrayChallenger[i] = 0;
            Challenger_down[i] = false;
        }
        BigWill = 0;
    }

    void Aggro(Unit *who) { }

    void MoveInLineOfSight(Unit *who)
    {
        if(!who || (!who->isAlive())) return;

        if (m_creature->IsWithinDistInMap(who, 10.0f) && (who->GetTypeId() == TYPEID_PLAYER) && ((Player*)who)->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE && !EventInProgress)
        {
            PlayerGUID = who->GetGUID();
            EventInProgress = true;
        }
    }

    void KilledUnit(Unit *victim) { }

    void UpdateAI(const uint32 diff)
    {
        if (EventInProgress) {
            Player* pWarrior = NULL;

            if(PlayerGUID)
                pWarrior = ((Player*)Unit::GetUnit((*m_creature), PlayerGUID));

            if(!pWarrior)
                return;

            if(!pWarrior->isAlive() && pWarrior->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE) {
                EventInProgress = false;
                DoYell(SAY_TWIGGY_FLATHEAD_DOWN,LANG_UNIVERSAL,NULL);
                pWarrior->FailQuest(1719);

                for(uint8 i = 0; i < 6; i++) {
                    if (AffrayChallenger[i]) {
                        Creature* pCreature = (Creature*)Unit::GetUnit((*m_creature), AffrayChallenger[i]);
                        if(pCreature) {
                            if(pCreature->isAlive()) {
                                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pCreature->setDeathState(JUST_DIED);
                            }
                        }
                    }
                    AffrayChallenger[i] = 0;
                    Challenger_down[i] = false;
                }

                if (BigWill) {
                    Creature* pCreature = (Creature*)Unit::GetUnit((*m_creature), BigWill);
                    if(pCreature) {
                        if(pCreature->isAlive()) {
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pCreature->setDeathState(JUST_DIED);
                        }
                    }
                }
                BigWill = 0;
            }

            if (!EventGrate && EventInProgress) {
                float x,y,z;
                pWarrior->GetPosition(x, y, z);

                if (x >= -1684 && x <= -1674 && y >= -4334 && y <= -4324) {
                    pWarrior->AreaExploredOrEventHappens(1719);
                    DoYell(SAY_TWIGGY_FLATHEAD_BEGIN,LANG_UNIVERSAL,NULL);

                    for(uint8 i = 0; i < 6; i++) {
                        Creature* pCreature = m_creature->SummonCreature(AFFRAY_CHALLENGER, AffrayChallengerLoc[i][0], AffrayChallengerLoc[i][1], AffrayChallengerLoc[i][2], AffrayChallengerLoc[i][3], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        pCreature->setFaction(35);
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pCreature->HandleEmoteCommand(15);
                        AffrayChallenger[i] = pCreature->GetGUID();
                    }
                    Wave_Timer = 5000;
                    Challenger_checker = 1000;
                    EventGrate = true;
                }
            }
            else if (EventInProgress) {
                if (Challenger_checker < diff) {
                    for(uint8 i = 0; i < 6; i++) {
                        if (AffrayChallenger[i]) {
                            Creature* pCreature = (Creature*)Unit::GetUnit((*m_creature), AffrayChallenger[i]);
                            if((!pCreature || (!pCreature->isAlive())) && !Challenger_down[i]) {
                                DoYell(SAY_TWIGGY_FLATHEAD_DOWN,LANG_UNIVERSAL,NULL);
                                Challenger_down[i] = true;
                            }
                        }
                    }
                    Challenger_checker = 1000;
                } else Challenger_checker -= diff;

                if(Wave_Timer < diff) {
                    if (AffrayChallenger[Wave] && Wave < 6 && !EventBigWill) {
                        DoYell(SAY_TWIGGY_FLATHEAD_FRAY,LANG_UNIVERSAL,NULL);
                        Creature* pCreature = (Creature*)Unit::GetUnit((*m_creature), AffrayChallenger[Wave]);
                        if(pCreature || (pCreature->isAlive())) {
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pCreature->HandleEmoteCommand(15);
                            pCreature->setFaction(14);
                            ((CreatureAI*)pCreature->AI())->AttackStart(pWarrior);
                            Wave++;
                            Wave_Timer = 20000;
                        }
                    }
                    else if (Wave >= 6 && !EventBigWill) {
                        Creature* pCreature = m_creature->SummonCreature(BIG_WILL, -1722, -4341, 6.12, 6.26, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 480000);
                        BigWill = pCreature->GetGUID();
                        //pCreature->GetMotionMaster()->MovePoint(0, -1693, -4343, 4.32);
                        //pCreature->GetMotionMaster()->MovePoint(1, -1684, -4333, 2.78);
                        pCreature->GetMotionMaster()->MovePoint(2, -1682, -4329, 2.79);
                        //pCreature->HandleEmoteCommand(15);
                        pCreature->HandleEmoteCommand(27);
                        EventBigWill = true;
                        Wave_Timer = 1000;
                    }
                    else if (Wave >= 6 && EventBigWill && BigWill) {
                        Creature* pCreature = (Creature*)Unit::GetUnit((*m_creature), BigWill);
                        if (!pCreature->isAlive()) {
                            DoYell(SAY_TWIGGY_FLATHEAD_OVER,LANG_UNIVERSAL,NULL);
                            EventInProgress = false;
                            EventBigWill = false;
                            EventGrate = false;
                            PlayerGUID = 0;
                            Wave = 0;
                        }
                    }
                } else Wave_Timer -= diff;
            }
        }
    }
};
CreatureAI* GetAI_npc_twiggy_flathead(Creature *_Creature)
{
    return new npc_twiggy_flatheadAI (_Creature);
}
void AddSC_the_barrens()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_beaten_corpse";
    newscript->pGossipHello = &GossipHello_npc_beaten_corpse;
    newscript->pGossipSelect = &GossipSelect_npc_beaten_corpse;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_sputtervalve";
    newscript->pGossipHello = &GossipHello_npc_sputtervalve;
    newscript->pGossipSelect = &GossipSelect_npc_sputtervalve;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_taskmaster_fizzule";
    newscript->GetAI = GetAI_npc_taskmaster_fizzule;
    newscript->pReceiveEmote = &ReciveEmote_npc_taskmaster_fizzule;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_twiggy_flathead";
    newscript->GetAI = GetAI_npc_twiggy_flathead;
    m_scripts[nrscripts++] = newscript;
}
