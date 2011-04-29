/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Dark_Portal
SD%Complete: 30
SDComment: Misc NPC's and mobs for instance. Most here far from complete.
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

/* ContentData
npc_medivh_bm
npc_time_rift
npc_saat
EndContentData */

#include "ScriptPCH.h"
#include "dark_portal.h"

#define SAY_ENTER               -1269020                    //where does this belong?
#define SAY_INTRO               -1269021
#define SAY_WEAK75              -1269022
#define SAY_WEAK50              -1269023
#define SAY_WEAK25              -1269024
#define SAY_DEATH               -1269025
#define SAY_WIN                 -1269026
#define SAY_ORCS_ENTER          -1269027
#define SAY_ORCS_ANSWER         -1269028

#define SPELL_CHANNEL           31556
#define SPELL_PORTAL_RUNE       32570                       //aura(portal on ground effect)

#define SPELL_BLACK_CRYSTAL     32563                       //aura
#define SPELL_PORTAL_CRYSTAL    32564                       //summon

#define SPELL_BANISH_PURPLE     32566                       //aura
#define SPELL_BANISH_GREEN      32567                       //aura

#define SPELL_CORRUPT           31326
#define SPELL_CORRUPT_AEONUS    37853

#define C_COUNCIL_ENFORCER      17023

class npc_medivh_bm : public CreatureScript
{
public:
    npc_medivh_bm() : CreatureScript("npc_medivh_bm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_medivh_bmAI (pCreature);
    }

    struct npc_medivh_bmAI : public ScriptedAI
    {
        npc_medivh_bmAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 SpellCorrupt_Timer;
        uint32 Check_Timer;

        bool Life75;
        bool Life50;
        bool Life25;

        void Reset()
        {
            SpellCorrupt_Timer = 0;

            if (!pInstance)
                return;

            if (pInstance->GetData(TYPE_MEDIVH) == IN_PROGRESS)
                DoCast(me, SPELL_CHANNEL, true);
            else if (me->HasAura(SPELL_CHANNEL))
                me->RemoveAura(SPELL_CHANNEL);

            DoCast(me, SPELL_PORTAL_RUNE, true);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!pInstance)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
            {
                if (pInstance->GetData(TYPE_MEDIVH) == IN_PROGRESS || pInstance->GetData(TYPE_MEDIVH) == DONE)
                    return;

                DoScriptText(SAY_INTRO, me);
                pInstance->SetData(TYPE_MEDIVH, IN_PROGRESS);
                DoCast(me, SPELL_CHANNEL, false);
                Check_Timer = 5000;
                     }
            else if (who->GetTypeId() == TYPEID_UNIT && me->IsWithinDistInMap(who, 15.0f))
            {
                if (pInstance->GetData(TYPE_MEDIVH) != IN_PROGRESS)
                    return;

                uint32 entry = who->GetEntry();
                if (entry == C_ASSAS || entry == C_WHELP || entry == C_CHRON || entry == C_EXECU || entry == C_VANQU)
                {
                    who->StopMoving();
                    who->CastSpell(me, SPELL_CORRUPT, false);
                }
                else if (entry == C_AEONUS)
                {
                    who->StopMoving();
                    who->CastSpell(me, SPELL_CORRUPT_AEONUS, false);
                }
            }
        }

        void AttackStart(Unit * /*who*/)
        {
            //if (pInstance && pInstance->GetData(TYPE_MEDIVH) == IN_PROGRESS)
            //return;

            //ScriptedAI::AttackStart(who);
        }

        void EnterCombat(Unit * /*who*/) {}

        void SpellHit(Unit* /*caster*/, const SpellEntry* spell)
        {
            if (SpellCorrupt_Timer)
                return;

            if (spell->Id == SPELL_CORRUPT_AEONUS)
                SpellCorrupt_Timer = 1000;

            if (spell->Id == SPELL_CORRUPT)
                SpellCorrupt_Timer = 3000;
        }

        void JustDied(Unit* Killer)
        {
            if (Killer->GetEntry() == me->GetEntry())
                return;

            DoScriptText(SAY_DEATH, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!pInstance)
                return;

            if (SpellCorrupt_Timer)
            {
                if (SpellCorrupt_Timer <= diff)
                {
                        pInstance->SetData(TYPE_MEDIVH, SPECIAL);

                    if (me->HasAura(SPELL_CORRUPT_AEONUS))
                        SpellCorrupt_Timer = 1000;
                    else if (me->HasAura(SPELL_CORRUPT))
                        SpellCorrupt_Timer = 3000;
                    else
                        SpellCorrupt_Timer = 0;
                } else SpellCorrupt_Timer -= diff;
            }

            if (Check_Timer)
            {
                if (Check_Timer <= diff)
                {
                    uint32 pct = pInstance->GetData(DATA_SHIELD);

                    Check_Timer = 5000;

                    if (Life25 && pct <= 25)
                    {
                        DoScriptText(SAY_WEAK25, me);
                        Life25 = false;
                    }
                    else if (Life50 && pct <= 50)
                    {
                        DoScriptText(SAY_WEAK50, me);
                        Life50 = false;
                    }
                    else if (Life75 && pct <= 75)
                    {
                        DoScriptText(SAY_WEAK75, me);
                        Life75 = false;
                    }

                    //if we reach this it means event was running but at some point reset.
                    if (pInstance->GetData(TYPE_MEDIVH) == NOT_STARTED)
                    {
                        me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        me->RemoveCorpse();
                        me->Respawn();
                        return;
                    }

                    if (pInstance->GetData(TYPE_RIFT) == DONE)
                    {
                        DoScriptText(SAY_WIN, me);
                        Check_Timer = 0;

                        if (me->HasAura(SPELL_CHANNEL))
                            me->RemoveAura(SPELL_CHANNEL);

                        //TODO: start the post-event here
                        pInstance->SetData(TYPE_MEDIVH, DONE);
                    }
                } else Check_Timer -= diff;
            }

            //if (!UpdateVictim())
            //return;

            //DoMeleeAttackIfReady();
        }
    };

};

struct Wave
{
    uint32 PortalMob[4];                                    //spawns for portal waves (in order)
};

static Wave PortalWaves[]=
{
    { {C_ASSAS, C_WHELP, C_CHRON, 0} },
    { {C_EXECU, C_CHRON, C_WHELP, C_ASSAS} },
    { {C_EXECU, C_VANQU, C_CHRON, C_ASSAS} }
};

class npc_time_rift : public CreatureScript
{
public:
    npc_time_rift() : CreatureScript("npc_time_rift") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_time_riftAI (pCreature);
    }

    struct npc_time_riftAI : public ScriptedAI
    {
        npc_time_riftAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 TimeRiftWave_Timer;
        uint8 mRiftWaveCount;
        uint8 mPortalCount;
        uint8 mWaveId;

        void Reset()
        {

            TimeRiftWave_Timer = 15000;
            mRiftWaveCount = 0;

            if (!pInstance)
                return;

            mPortalCount = pInstance->GetData(DATA_PORTAL_COUNT);

            if (mPortalCount < 6)
                mWaveId = 0;
            else if (mPortalCount > 12)
                mWaveId = 2;
            else mWaveId = 1;

        }
        void EnterCombat(Unit * /*who*/) {}

        void DoSummonAtRift(uint32 creature_entry)
        {
            if (!creature_entry)
                return;

            if (pInstance && pInstance->GetData(TYPE_MEDIVH) != IN_PROGRESS)
            {
                me->InterruptNonMeleeSpells(true);
                me->RemoveAllAuras();
                return;
            }

            Position pos;
            me->GetRandomNearPosition(pos, 10.0f);

            //normalize Z-level if we can, if rift is not at ground level.
            pos.m_positionZ = std::max(me->GetMap()->GetHeight(pos.m_positionX, pos.m_positionY, MAX_HEIGHT), me->GetMap()->GetWaterLevel(pos.m_positionX, pos.m_positionY));

            if (Unit *Summon = DoSummon(creature_entry, pos, 30000, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT))
                if (Unit *temp = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_MEDIVH) : 0))
                    Summon->AddThreat(temp, 0.0f);
        }

        void DoSelectSummon()
        {
            uint32 entry = 0;

            if ((mRiftWaveCount > 2 && mWaveId < 1) || mRiftWaveCount > 3)
                mRiftWaveCount = 0;

            entry = PortalWaves[mWaveId].PortalMob[mRiftWaveCount];
            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: npc_time_rift: summoning wave Creature (Wave %u, Entry %u).", mRiftWaveCount, entry);

            ++mRiftWaveCount;

            if (entry == C_WHELP)
            {
                for (uint8 i = 0; i < 3; ++i)
                    DoSummonAtRift(entry);
            } else DoSummonAtRift(entry);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!pInstance)
                return;

            if (TimeRiftWave_Timer <= diff)
            {
                DoSelectSummon();
                TimeRiftWave_Timer = 15000;
            } else TimeRiftWave_Timer -= diff;

            if (me->IsNonMeleeSpellCasted(false))
                return;

            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: npc_time_rift: not casting anylonger, i need to die.");
            me->setDeathState(JUST_DIED);

            if (pInstance->GetData(TYPE_RIFT) == IN_PROGRESS)
                pInstance->SetData(TYPE_RIFT, SPECIAL);
        }
    };

};

#define SAY_SAAT_WELCOME        -1269019

#define GOSSIP_ITEM_OBTAIN      "[PH] Obtain Chrono-Beacon"
#define SPELL_CHRONO_BEACON     34975
#define ITEM_CHRONO_BEACON      24289

class npc_saat : public CreatureScript
{
public:
    npc_saat() : CreatureScript("npc_saat") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->CastSpell(pPlayer, SPELL_CHRONO_BEACON, false);
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_OPENING_PORTAL) == QUEST_STATUS_INCOMPLETE && !pPlayer->HasItemCount(ITEM_CHRONO_BEACON, 1))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_OBTAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(10000, pCreature->GetGUID());
            return true;
        }
        else if (pPlayer->GetQuestRewardStatus(QUEST_OPENING_PORTAL) && !pPlayer->HasItemCount(ITEM_CHRONO_BEACON, 1))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_OBTAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(10001, pCreature->GetGUID());
            return true;
        }

        pPlayer->SEND_GOSSIP_MENU(10002, pCreature->GetGUID());
        return true;
    }

};

void AddSC_dark_portal()
{
    new npc_medivh_bm();
    new npc_time_rift();
    new npc_saat();
}
