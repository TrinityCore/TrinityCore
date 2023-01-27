/*
 * Dun Morogh
 */

#include "scriptPCH.h"
#include "dun_morogh.h"

/*######
## npc_narm_faulk
######*/

#define SAY_HEAL    -1000187

struct npc_narm_faulkAI : ScriptedAI
{
    uint32 lifeTimer;
    bool spellHit;

    npc_narm_faulkAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_narm_faulkAI::Reset();
    }

    void Reset() override
    {
        lifeTimer = 120000;
        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
        spellHit = false;
    }

    void MoveInLineOfSight(Unit *who) override { }

    void UpdateAI(uint32 const diff) override
    {
        if (m_creature->IsStandingUp())
        {
            if (lifeTimer < diff)
                m_creature->AI()->EnterEvadeMode();
            else
                lifeTimer -= diff;
        }
    }

    void SpellHit(Unit *Hitter, SpellEntry const* Spellkind) override
    {
        if (Spellkind->Id == 8593 && !spellHit)
        {
            DoCastSpellIfCan(m_creature, 32343);
            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
            //m_creature->RemoveAllAuras();
            DoScriptText(SAY_HEAL, m_creature, Hitter);
            spellHit = true;
        }
    }
};

CreatureAI* GetAI_npc_narm_faulk(Creature* pCreature)
{
    return new npc_narm_faulkAI(pCreature);
}

/*
* Angus (Mortar Team event support)
*/

npc_angusAI::npc_angusAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventProcessed = false;
    m_bActionPosReached = false;
    m_bReturningHome = false;
    m_bSubEventProcessed = false;
    m_uiDoTimer = 0;
    m_uiAction = 0;

    npc_angusAI::Reset();
}

void npc_angusAI::Reset() { }

void npc_angusAI::StartEvent()
{
    m_bEventProcessed = true;
    m_creature->GetMotionMaster()->MovePoint(0, AngusMove[0][0], AngusMove[0][1], AngusMove[0][2], MOVE_PATHFINDING, 0, 1.778f);
}

void npc_angusAI::FinishEvent()
{
    m_bActionPosReached = false;
    m_bReturningHome = true;
    m_creature->GetMotionMaster()->MovePoint(EPOS_ANGUS, AngusMove[EPOS_ANGUS][0], AngusMove[EPOS_ANGUS][1], AngusMove[EPOS_ANGUS][2], MOVE_PATHFINDING);
}

void npc_angusAI::StartSubEvent()
{
    m_bSubEventProcessed = true;
}

void npc_angusAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    if (m_bActionPosReached)
        return;

    if (uiPointId == EPOS_ANGUS && !m_bReturningHome)
    {
        m_bActionPosReached = true;
        return;
    }

    if (!uiPointId && m_bReturningHome)
    {
        m_bReturningHome = false;
        m_bEventProcessed = false;
        m_bSubEventProcessed = false;
        m_uiDoTimer = 0;
        m_uiAction = 0;
        return;
    }

    float orient = m_bReturningHome ? (uiPointId == 1 ? 1.778f : -10.0f) : uiPointId == EPOS_ANGUS - 1 ? 1.76f : -10.0f;
    uint8 nPoint = m_bReturningHome ? uiPointId - 1 : uiPointId + 1;

    m_creature->GetMotionMaster()->MovePoint(nPoint, AngusMove[nPoint][0], AngusMove[nPoint][1], AngusMove[nPoint][2], MOVE_PATHFINDING, 0, orient);
}

void npc_angusAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bSubEventProcessed)
    {
        ScriptedAI::UpdateAI(uiDiff);
        return;
    }

    if (m_uiDoTimer < uiDiff)
    {
        switch (m_uiAction)
        {
            case 0:
                m_creature->SetFacingTo(2.76f);
                m_creature->SetOrientation(2.76f);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 1:
                m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);
                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 2:
                break;
        }
    }
    else
        m_uiDoTimer -= uiDiff;
}

CreatureAI* GetAI_npc_angus(Creature* pCreature)
{
    return new npc_angusAI(pCreature);
}

/*
* Rifleman Middlecamp (Mortar Team event support)
*/

npc_rifleman_middlecampAI::npc_rifleman_middlecampAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventProcessed = false;
    m_bActionPosReached = false;
    m_bSubEventProcessed = false;
    m_bReturningHome = false;
    m_uiDoTimer = 0;
    m_uiAction = 0;

    npc_rifleman_middlecampAI::Reset();
}

void npc_rifleman_middlecampAI::Reset() { }

void npc_rifleman_middlecampAI::StartEvent()
{
    m_bEventProcessed = true;
    m_creature->GetMotionMaster()->MovePoint(0, MiddlecampMove[0][0], MiddlecampMove[0][1], MiddlecampMove[0][2], MOVE_PATHFINDING, 0, 5.587f);
}

void npc_rifleman_middlecampAI::FinishEvent()
{
    m_bActionPosReached = false;
    m_bReturningHome = true;
    m_creature->GetMotionMaster()->MovePoint(EPOS_MIDDLECAMP, MiddlecampMove[EPOS_MIDDLECAMP][0], MiddlecampMove[EPOS_MIDDLECAMP][1], MiddlecampMove[EPOS_MIDDLECAMP][2], MOVE_PATHFINDING);
}

void npc_rifleman_middlecampAI::StartSubEvent()
{
    m_bSubEventProcessed = true;
}

void npc_rifleman_middlecampAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    if (m_bActionPosReached)
        return;

    if (uiPointId == EPOS_MIDDLECAMP && !m_bReturningHome)
    {
        m_bActionPosReached = true;
        return;
    }

    if (!uiPointId && m_bReturningHome)
    {
        m_bReturningHome = false;
        m_bEventProcessed = false;
        m_bSubEventProcessed = false;
        m_uiDoTimer = 0;
        m_uiAction = 0;
        return;
    }

    float orient = m_bReturningHome ? (uiPointId == 1 ? 5.587f : -10.0f) : uiPointId == EPOS_MIDDLECAMP - 1 ? 2.05f : -10.0f;
    uint8 nPoint = m_bReturningHome ? uiPointId - 1 : uiPointId + 1;

    m_creature->GetMotionMaster()->MovePoint(nPoint, MiddlecampMove[nPoint][0], MiddlecampMove[nPoint][1], MiddlecampMove[nPoint][2], MOVE_PATHFINDING, 0, orient);
}

void npc_rifleman_middlecampAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bSubEventProcessed)
    {
        ScriptedAI::UpdateAI(uiDiff);
        return;
    }

    if (m_uiDoTimer < uiDiff)
    {
        switch (m_uiAction)
        {
            case 0:
                DoScriptText(SHOOT1EMOTE1, m_creature);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 1:
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 2:
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_1);
                DoScriptText(SHOOT1EMOTE2, m_creature);
                m_creature->SetSheath(SHEATH_STATE_UNARMED);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 3:
                m_creature->HandleEmote(EMOTE_ONESHOT_QUESTION);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 4:
                DoScriptText(SHOOT2EMOTE1, m_creature);
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_2);
                DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_2);
                m_uiDoTimer = 4000;
                ++m_uiAction;
                break;
            case 5:
                DoScriptText(SHOOT2EMOTE2, m_creature);
                m_creature->SetSheath(SHEATH_STATE_UNARMED);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 6:
                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 30))
                {
                    m_creature->SetFacingToObject(pWheeler);
                    m_creature->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                    pWheeler->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_YES);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_NO);
                }

                m_uiDoTimer = 8000;
                ++m_uiAction;
                break;
            case 7:
                m_creature->SetFacingTo(2.05f);
                m_creature->SetOrientation(2.05f);
                m_uiDoTimer = 10000;
                ++m_uiAction;
                break;
            case 8:
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_4);
                DoScriptText(SHOOT4EMOTE1, m_creature);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 9:
                DoScriptText(SHOOT1EMOTE2, m_creature);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 10:
                m_creature->HandleEmote(EMOTE_ONESHOT_BEG); // roar?
                m_uiDoTimer = 8000;
                ++m_uiAction;
                break;
            case 11:
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_5);
                DoScriptText(SHOOT5EMOTE1, m_creature);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 12:
                DoScriptText(SHOOT2EMOTE2, m_creature);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 13:
                m_creature->HandleEmote(EMOTE_ONESHOT_CRY);
                m_uiDoTimer = 14000;
                ++m_uiAction;
                break;
            case 14:
                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 30))
                {
                    m_creature->SetFacingToObject(pWheeler);
                    m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                }
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 15:
                m_creature->HandleEmote(EMOTE_ONESHOT_LAUGH);
                m_uiDoTimer = 4000;
                ++m_uiAction;
                break;
            case 16:
                m_creature->SetFacingTo(2.05f);
                m_creature->SetOrientation(2.05f);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 17:
                DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_5);
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_8);
                DoScriptText(SHOOT8EMOTE1, m_creature);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 18:
                DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_5);
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_9);
                DoScriptText(SHOOT9EMOTE1, m_creature);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 19:
                DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_5);
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_10);
                DoScriptText(SHOOT10EMOTE1, m_creature);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 20:
                m_creature->HandleEmote(EMOTE_ONESHOT_CHEER_NOSHEATHE);
                DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_1);
                m_uiDoTimer = 6000;
                ++m_uiAction;
                break;
            case 21:
                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 30))
                {
                    m_creature->SetFacingToObject(pWheeler);
                    pWheeler->SetFacingToObject(m_creature);
                    m_creature->HandleEmote(EMOTE_ONESHOT_BOW);
                    pWheeler->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                if (auto pArgus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pArgus->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 22:
                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    m_creature->SetFacingToObject(pShorty);
                }

                ++m_uiAction;
                break;
        }
    }
    else
        m_uiDoTimer -= uiDiff;
}

CreatureAI* GetAI_npc_rifleman_middlecamp(Creature* pCreature)
{
    return new npc_rifleman_middlecampAI(pCreature);
}

/*
* Rifleman Wheeler (Mortar Team event support)
*/

npc_rifleman_wheelerAI::npc_rifleman_wheelerAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventProcessed = false;
    m_bActionPosReached = false;
    m_bSubEventProcessed = false;
    m_bReturningHome = false;
    m_uiDoTimer = 22000;
    m_uiAction = 0;

    npc_rifleman_wheelerAI::Reset();
}

void npc_rifleman_wheelerAI::Reset() { }

void npc_rifleman_wheelerAI::StartEvent()
{
    m_bEventProcessed = true;
    m_creature->GetMotionMaster()->MovePoint(0, WheelerMove[0][0], WheelerMove[0][1], WheelerMove[0][2], MOVE_PATHFINDING, 0, 4.66f);
}

void npc_rifleman_wheelerAI::FinishEvent()
{
    m_bActionPosReached = false;
    m_bReturningHome = true;
    m_creature->GetMotionMaster()->MovePoint(EPOS_WHEELER, WheelerMove[EPOS_WHEELER][0], WheelerMove[EPOS_WHEELER][1], WheelerMove[EPOS_WHEELER][2], MOVE_PATHFINDING);
}

void npc_rifleman_wheelerAI::StartSubEvent()
{
    m_bSubEventProcessed = true;
}

void npc_rifleman_wheelerAI::PokeMortarGuys() const
{
    auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 50);
    auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 50);
    auto pKlemmy = m_creature->FindNearestCreature(NPC_SPOTTER_KLEMMY, 80);

    if (!pShorty || !pAngus || !pKlemmy)
    {
        return;
    }

    auto pShortyAI = static_cast<npc_shortyAI*>(pShorty->AI());
    auto pAngusAI = static_cast<npc_angusAI*>(pAngus->AI());
    auto pKlemmyAI = static_cast<npc_spotter_klemmyAI*>(pKlemmy->AI());

    if (!pShortyAI || !pAngusAI || !pKlemmyAI)
    {
        return;
    }

    pShortyAI->StartSubEvent();
    pAngusAI->StartSubEvent();
    pKlemmyAI->StartSubEvent();
}

void npc_rifleman_wheelerAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    if (m_bActionPosReached)
        return;

    if (uiPointId == EPOS_WHEELER && !m_bReturningHome)
    {
        m_bActionPosReached = true;
        return;
    }

    if (!uiPointId && m_bReturningHome)
    {
        m_bReturningHome = false;
        m_bEventProcessed = false;
        m_bSubEventProcessed = false;
        m_uiDoTimer = 22000;
        m_uiAction = 0;
        return;
    }

    float orient = m_bReturningHome ? (uiPointId == 1 ? 4.66f : -10.0f) : uiPointId == EPOS_WHEELER - 1 ? 2.39f : -10.0f;
    uint8 nPoint = m_bReturningHome ? uiPointId - 1 : uiPointId + 1;

    m_creature->GetMotionMaster()->MovePoint(nPoint, WheelerMove[nPoint][0], WheelerMove[nPoint][1], WheelerMove[nPoint][2], MOVE_PATHFINDING, 0, orient);
}

void npc_rifleman_wheelerAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bSubEventProcessed)
    {
        ScriptedAI::UpdateAI(uiDiff);
        return;
    }

    if (m_uiDoTimer < uiDiff)
    {
        switch (m_uiAction)
        {
            case 0:
                DoScriptText(SHOOT3EMOTE1, m_creature);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 1:
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_3);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 2:
                DoScriptText(SHOOT3EMOTE2, m_creature);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 3:
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 30))
                {
                    m_creature->SetFacingToObject(pMiddlecamp);
                    m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                    DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_4);
                }

                if (auto pArgus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pArgus->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 4:
                m_creature->HandleEmote(EMOTE_ONESHOT_FLEX);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 5:
                m_creature->SetOrientation(2.39f);
                m_uiDoTimer = 7000;
                ++m_uiAction;
                break;
            case 6:
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 30))
                {
                    m_creature->SetFacingToObject(pMiddlecamp);
                    m_creature->HandleEmote(EMOTE_ONESHOT_QUESTION);
                    DoPlaySoundToSet(m_creature, SOUND_RIFLEMAN_3);
                }

                m_uiDoTimer = 4000;
                ++m_uiAction;
                break;
            case 7:
                m_creature->SetFacingTo(2.39f);
                m_creature->SetOrientation(2.39f);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 8:
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_6);
                m_uiDoTimer = 11000;
                ++m_uiAction;
                break;
            case 9: // 56 s
                DoScriptText(SHOOT6EMOTE1, m_creature);
                DoCastSpellIfCan(m_creature, SPELL_SHOOT_7);
                DoScriptText(SHOOT7EMOTE1, m_creature);
                m_uiDoTimer = 5000;
                ++m_uiAction;
                break;
            case 10:
                DoScriptText(SHOOT7EMOTE2, m_creature);
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 30))
                {
                    m_creature->SetFacingToObject(pMiddlecamp);
                    m_creature->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                }

                m_uiDoTimer = 19000;
                ++m_uiAction;
                break;
            case 11:
                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    m_creature->SetFacingToObject(pShorty);
                }

                PokeMortarGuys();
                ++m_uiAction;
                break;
        }
    }
    else
        m_uiDoTimer -= uiDiff;
}

CreatureAI* GetAI_npc_rifleman_wheeler(Creature* pCreature)
{
    return new npc_rifleman_wheelerAI(pCreature);
}

/*
* Shorty (Mortar Team event support)
*/

npc_shortyAI::npc_shortyAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventProcessed = false;
    m_bActionPosReached = false;
    m_bReturningHome = false;
    m_bEventProcessed = false;
    m_bSubEventProcessed = false;
    m_uiDoTimer = 0;
    m_uiAction = 0;

    npc_shortyAI::Reset();
}

void npc_shortyAI::Reset() { }

void npc_shortyAI::StartEvent()
{
    m_bEventProcessed = true;
    m_creature->GetMotionMaster()->MovePoint(0, ShortyMove[0][0], ShortyMove[0][1], ShortyMove[0][2], MOVE_PATHFINDING, 3.0f, 2.473f);
}

void npc_shortyAI::FinishEvent()
{
    m_bActionPosReached = false;
    m_bReturningHome = true;
    m_creature->GetMotionMaster()->MovePoint(EPOS_SHORTY, ShortyMove[EPOS_SHORTY][0], ShortyMove[EPOS_SHORTY][1], ShortyMove[EPOS_SHORTY][2], MOVE_PATHFINDING, 3.0f);
}

void npc_shortyAI::StartSubEvent()
{
    m_bSubEventProcessed = true;
}

void npc_shortyAI::PokeRiflemen() const
{
    auto pRiflemanMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 30);
    auto pRiflemanWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 30);

    if (!pRiflemanMiddlecamp || !pRiflemanWheeler)
    {
        return;
    }

    auto pRiflemanMiddlecampAI = static_cast<npc_rifleman_middlecampAI*>(pRiflemanMiddlecamp->AI());
    auto pRiflemanWheelerAI = static_cast<npc_rifleman_wheelerAI*>(pRiflemanWheeler->AI());

    if (!pRiflemanMiddlecampAI || !pRiflemanWheelerAI)
    {
        return;
    }

    pRiflemanMiddlecampAI->StartSubEvent();
    pRiflemanWheelerAI->StartSubEvent();
}

void npc_shortyAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    if (m_bActionPosReached)
        return;

    if (uiPointId == EPOS_SHORTY && !m_bReturningHome)
    {
        PokeRiflemen();
        m_bActionPosReached = true;
        return;
    }

    if (!uiPointId && m_bReturningHome)
    {
        m_bReturningHome = false;
        m_bEventProcessed = false;
        m_bSubEventProcessed = false;
        m_uiDoTimer = 0;
        m_uiAction = 0;
        return;
    }

    float orient = m_bReturningHome ? (uiPointId == 1 ? 2.473f : -10.0f) : uiPointId == EPOS_SHORTY - 1 ? 2.09f : -10.0f;
    uint8 nPoint = m_bReturningHome ? uiPointId - 1 : uiPointId + 1;

    m_creature->GetMotionMaster()->MovePoint(nPoint, ShortyMove[nPoint][0], ShortyMove[nPoint][1], ShortyMove[nPoint][2], MOVE_PATHFINDING, 3.0f, orient);
}

void npc_shortyAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bSubEventProcessed)
    {
        //ScriptedAI::UpdateAI(uiDiff);
        return;
    }

    if (m_uiDoTimer < uiDiff)
    {
        switch (m_uiAction)
        {
            case 0:
                m_creature->SetFacingTo(2.82f);
                m_creature->SetOrientation(2.82f);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 1:
                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_5);
                m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);
                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 2:
                m_creature->SetFacingTo(4.37f);
                m_creature->SetOrientation(4.37f);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 3:
                m_creature->HandleEmote(EMOTE_STATE_USESTANDING);
                m_uiDoTimer = 4000;
                ++m_uiAction;
                break;
            case 4:
                m_creature->HandleEmote(EMOTE_STATE_NONE);
                m_creature->SetFacingTo(2.82f);
                m_creature->SetOrientation(2.82f);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 5:
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 50))
                {
                    pMiddlecamp->SetFacingTo(2.99f);
                }

                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 50))
                {
                    pWheeler->SetFacingTo(2.97f);
                }

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_POINT);
                }

                DoCastSpellIfCan(m_creature, SPELL_MORTAR_ANIMATE);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 6:
                DoCastSpellIfCan(m_creature, SPELL_MORTAR_SHOT);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 7:
                m_creature->HandleEmote(EMOTE_ONESHOT_TALK);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 8:
                m_creature->SetFacingTo(4.37f);
                m_creature->SetOrientation(4.37f);            
                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_2);

                if (auto pKlemmy = m_creature->FindNearestCreature(NPC_SPOTTER_KLEMMY, 80))
                {
                    if (auto pKlemmyAI = static_cast<npc_spotter_klemmyAI*>(pKlemmy->AI()))
                        pKlemmyAI->StartSubEvent();
                }

                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 9:
                m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 10:
                m_creature->SetFacingTo(2.82f);
                m_creature->SetOrientation(2.82f);
                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 11:
                m_creature->SetFacingTo(4.37f);
                m_creature->SetOrientation(4.37f);
                m_uiDoTimer = 2000;
                ++m_uiAction;
                break;
            case 12:
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_3);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 13:
                //m_creature->HandleEmote(EMOTE_STATE_USESTANDING); // does not work while kneeling; no choice?
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 14:
                m_creature->HandleEmote(EMOTE_STATE_NONE);
                m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                m_creature->SetFacingTo(2.82f);
                m_creature->SetOrientation(2.82f);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 15:
                m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_4);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 16:
                DoCastSpellIfCan(m_creature, SPELL_MORTAR_ANIMATE);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 17:
                DoCastSpellIfCan(m_creature, SPELL_MORTAR_SHOT);
                m_uiDoTimer = 1000;
                ++m_uiAction;
                break;
            case 18:
                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->SetFacingToObject(m_creature);
                    pAngus->HandleEmote(EMOTE_ONESHOT_TALK);
                    m_creature->SetFacingToObject(pAngus);
                    m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                }

                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_1);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 19:
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 50))
                {
                    pMiddlecamp->SetFacingToObject(m_creature);
                    pMiddlecamp->HandleEmote(EMOTE_ONESHOT_APPLAUD);
                }

                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 50))
                {
                    pWheeler->SetFacingToObject(m_creature);
                    pWheeler->HandleEmote(EMOTE_ONESHOT_CHEER);
                }

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->SetFacingTo(2.76f);
                    pAngus->SetOrientation(2.76f);
                }

                m_creature->SetFacingTo(2.82f);
                m_creature->SetOrientation(2.82f);

                if (auto pKlemmy = m_creature->FindNearestCreature(NPC_SPOTTER_KLEMMY, 80))
                {
                    if (auto pKlemmyAI = static_cast<npc_spotter_klemmyAI*>(pKlemmy->AI()))
                        pKlemmyAI->StartSubEvent();
                }

                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 20:
                DoPlaySoundToSet(m_creature, SOUND_MORTAR_TEAM_6);
                DoCastSpellIfCan(m_creature, SPELL_MORTAR_ANIMATE);

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_EXCLAMATION);
                }

                m_creature->HandleEmote(EMOTE_ONESHOT_ROAR);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 21:
                DoCastSpellIfCan(m_creature, SPELL_MORTAR_SHOT);

                if (auto pKlemmy = m_creature->FindNearestCreature(NPC_SPOTTER_KLEMMY, 80))
                {
                    if (auto pKlemmyAI = static_cast<npc_spotter_klemmyAI*>(pKlemmy->AI()))
                        pKlemmyAI->StartSubEvent();
                }

                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
        }
    }
    else
        m_uiDoTimer -= uiDiff;
}

CreatureAI* GetAI_npc_shorty(Creature* pCreature)
{
    return new npc_shortyAI(pCreature);
}

/*
* Spotter Klemmy (Mortar Team event support)
*/

npc_spotter_klemmyAI::npc_spotter_klemmyAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventProcessed = false;
    m_bActionPosReached = false;
    m_bReturningHome = false;
    m_bEventProcessed = false;
    m_bSubEventProcessed = false;
    m_bSubMoveProcessed = false;
    m_uiDoTimer = 0;
    m_uiAction = 0;

    npc_spotter_klemmyAI::Reset();
}

void npc_spotter_klemmyAI::Reset() { }

void npc_spotter_klemmyAI::StartEvent()
{
    m_bEventProcessed = true;
    m_creature->SetWalk(false);
    m_creature->GetMotionMaster()->MovePoint(0, KlemmyMove[0][0], KlemmyMove[0][1], KlemmyMove[0][2], MOVE_PATHFINDING, 0, 3.321f);
}

void npc_spotter_klemmyAI::FinishEvent()
{
    m_bActionPosReached = false;
    m_bReturningHome = true;
    m_creature->RemoveGuardians();
    m_creature->SetWalk(false);
    m_creature->GetMotionMaster()->MovePoint(EPOS_KLEMMY, KlemmyMove[EPOS_KLEMMY][0], KlemmyMove[EPOS_KLEMMY][1], KlemmyMove[EPOS_KLEMMY][2], MOVE_PATHFINDING);
}

void npc_spotter_klemmyAI::StartSubEvent()
{
    m_bSubEventProcessed = true;
}

void npc_spotter_klemmyAI::MovementInform(uint32 uiType, uint32 uiPointId)
{
    if (!m_bEventProcessed || uiType != POINT_MOTION_TYPE)
        return;

    switch (uiPointId)
    {
        case 100:
            if (!m_uiAction)
            {
                DoCastSpellIfCan(m_creature, SPELL_TARGET_DUMMY_1);
                m_bSubMoveProcessed = false;
                m_uiDoTimer = 3000;
                ++m_uiAction;            
            }

            break;
        case 101:
            if (m_uiAction == 1)
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_WAVE);
                m_bSubMoveProcessed = false;
                m_uiDoTimer = 1000;
                ++m_uiAction;            
            }

            break;
        case 102:
            if (m_uiAction == 3)
            {
                DoCastSpellIfCan(m_creature, SPELL_TARGET_DUMMY_2);
                m_bSubMoveProcessed = false;
                m_uiDoTimer = 1000;
                ++m_uiAction;
            }

            break;
        case 103:
            if (m_uiAction == 4)
            {
                m_creature->HandleEmote(EMOTE_ONESHOT_SALUTE);
                m_bSubMoveProcessed = false;
                m_creature->SetWalk(false);
                m_uiDoTimer = 3000;
                ++m_uiAction;
            }

            break;
        case 104:
            if (m_uiAction == 5)
            {
                m_creature->SetWalk(true);
                m_bSubMoveProcessed = false;

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 80))
                {
                    if (auto pShortyAI = static_cast<npc_shortyAI*>(pShorty->AI()))
                        pShortyAI->StartSubEvent();
                }

                m_bSubEventProcessed = false;
                ++m_uiAction;
            }

            break;
        case 105:
            if (m_uiAction == 6)
            {
                m_bSubMoveProcessed = false;

                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 50))
                {
                    pMiddlecamp->SetFacingToObject(m_creature);
                }

                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 50))
                {
                    pWheeler->SetFacingToObject(m_creature);
                }

                DoCastSpellIfCan(m_creature, SPELL_TARGET_DUMMY_3);
                m_uiDoTimer = 1000;
                ++m_uiAction;
            }

            break;
        case 106:
            if (m_uiAction == 7)
            {
                m_bSubMoveProcessed = false;
                m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                m_uiDoTimer = 1000;
                ++m_uiAction;
            }

            break;
        case 107:
            if (m_uiAction == 10)
            {
                m_creature->GetMotionMaster()->MovePoint(108, KlemmySubMove[4][0], KlemmySubMove[4][1], KlemmySubMove[4][2], MOVE_PATHFINDING);
            }

            break;
        case 108:
            if (m_uiAction == 10)
            {
                m_creature->GetMotionMaster()->MovePoint(109, KlemmySubMove[5][0], KlemmySubMove[5][1], KlemmySubMove[5][2], MOVE_PATHFINDING);
            }

            break;
        case 109:
            if (m_uiAction == 10)
            {
                m_bSubMoveProcessed = false;
                m_uiDoTimer = 2000;
                ++m_uiAction;
            }

            break;
    }

    if (m_bActionPosReached)
        return;

    if (uiPointId == EPOS_KLEMMY && !m_bReturningHome)
    {
        m_creature->SetWalk(true);
        m_bActionPosReached = true;
        return;
    }

    if (!uiPointId && m_bReturningHome)
    {
        m_bReturningHome = false;
        m_bEventProcessed = false;
        m_bSubEventProcessed = false;
        m_bSubMoveProcessed = false;
        m_creature->SetWalk(true);
        m_uiDoTimer = 0;
        m_uiAction = 0;
        return;
    }

    float orient = m_bReturningHome ? (uiPointId == 1 ? 3.321f : -10.0f) : uiPointId == EPOS_KLEMMY - 1 ? 5.81f : -10.0f;
    uint8 nPoint = m_bReturningHome ? uiPointId - 1 : uiPointId + 1;

    m_creature->GetMotionMaster()->MovePoint(nPoint, KlemmyMove[nPoint][0], KlemmyMove[nPoint][1], KlemmyMove[nPoint][2], MOVE_PATHFINDING, 0, orient);
}

void npc_spotter_klemmyAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bSubEventProcessed)
    {
        ScriptedAI::UpdateAI(uiDiff);
        return;
    }

    if (m_bSubMoveProcessed) return;

    if (m_uiDoTimer < uiDiff)
    {
        switch (m_uiAction)
        {
            case 0:
                m_creature->GetMotionMaster()->MovePoint(100, KlemmySubMove[0][0], KlemmySubMove[0][1], KlemmySubMove[0][2], MOVE_PATHFINDING, 0, 6.06f);
                m_bSubMoveProcessed = true;
                break;
            case 1:
                m_creature->GetMotionMaster()->MovePoint(101, KlemmyMove[EPOS_KLEMMY][0], KlemmyMove[EPOS_KLEMMY][1], KlemmyMove[EPOS_KLEMMY][2], MOVE_PATHFINDING, 0, 5.81f);
                m_bSubMoveProcessed = true;
                break;
            case 2:
                m_creature->SetOrientation(4.24f);

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 80))
                {
                    if (auto pShortyAI = static_cast<npc_shortyAI*>(pShorty->AI()))
                        pShortyAI->StartSubEvent();
                }

                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 3:
                m_creature->GetMotionMaster()->MovePoint(102, KlemmySubMove[0][0], KlemmySubMove[0][1], KlemmySubMove[0][2], MOVE_PATHFINDING, 0, 6.06f);
                m_bSubMoveProcessed = true;
                break;
            case 4:
                m_creature->GetMotionMaster()->MovePoint(103, KlemmySubMove[1][0], KlemmySubMove[1][1], KlemmySubMove[1][2], MOVE_PATHFINDING, 0, 5.94f);
                m_bSubMoveProcessed = true;
                break;
            case 5:
                m_creature->GetMotionMaster()->MovePoint(104, KlemmySubMove[2][0], KlemmySubMove[2][1], KlemmySubMove[2][2], MOVE_PATHFINDING, 0, 4.2f);
                m_bSubMoveProcessed = true;
                break;
            case 6:
                m_creature->GetMotionMaster()->MovePoint(105, KlemmySubMove[0][0], KlemmySubMove[0][1], KlemmySubMove[0][2], MOVE_PATHFINDING, 0, 6.06f);
                m_bSubMoveProcessed = true;
                break;
            case 7:
                m_creature->GetMotionMaster()->MovePoint(106, KlemmySubMove[1][0], KlemmySubMove[1][1], KlemmySubMove[1][2], MOVE_PATHFINDING, 0, 5.94f);
                m_bSubMoveProcessed = true;
                break;
            case 8:
                m_creature->HandleEmote(EMOTE_ONESHOT_LAUGH);

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 80))
                {
                    if (auto pShortyAI = static_cast<npc_shortyAI*>(pShorty->AI()))
                        pShortyAI->StartSubEvent();
                }

                m_bSubEventProcessed = false;
                ++m_uiAction;
                break;
            case 9:
                m_creature->SetWalk(false);
                m_creature->GetMotionMaster()->MovePoint(107, KlemmySubMove[3][0], KlemmySubMove[3][1], KlemmySubMove[3][2], MOVE_PATHFINDING);
                m_bSubMoveProcessed = true;

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 80))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_DANCE);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 80))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_DANCE);
                }

                ++m_uiAction;
                break;
            case 10:
                m_creature->HandleEmote(EMOTE_ONESHOT_RUDE);
                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 11:
                m_creature->HandleEmote(EMOTE_ONESHOT_RUDE);

                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 50))
                {
                    pMiddlecamp->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 50))
                {
                    pWheeler->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                m_uiDoTimer = 3000;
                ++m_uiAction;
                break;
            case 12:
                if (auto pMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, 50))
                {
                    pMiddlecamp->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, 50))
                {
                    pWheeler->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, 30))
                {
                    pAngus->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                if (auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, 30))
                {
                    pShorty->HandleEmote(EMOTE_ONESHOT_LAUGH);
                }

                m_uiDoTimer = 5000;
                ++m_uiAction;
                break;
            case 13:
                m_bSubEventProcessed = false;

                if (auto pWatcher = m_creature->FindNearestCreature(NPC_EVENT_WATCHER, 100))
                {
                    if (auto pWatcherAI = static_cast<npc_mortar_team_watcherAI*>(pWatcher->AI()))
                        pWatcherAI->PokeAll(false);
                }

                ++m_uiAction;
                break;
        }
    }
    else
        m_uiDoTimer -= uiDiff;
}

CreatureAI* GetAI_npc_spotter_klemmy(Creature* pCreature)
{
    return new npc_spotter_klemmyAI(pCreature);
}

/*
* Mortar Team Watcher (Mortar Team event support)
*/

npc_mortar_team_watcherAI::npc_mortar_team_watcherAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_bEventStartSent = false;
    m_bEventFinishSent = false;
    m_uiEventTimer = 4 * MINUTE * IN_MILLISECONDS;

    npc_mortar_team_watcherAI::Reset();
}

void npc_mortar_team_watcherAI::Reset() { }

void npc_mortar_team_watcherAI::PokeAll(bool start)
{
    // creatures lookup
    auto pAngus = m_creature->FindNearestCreature(NPC_ANGUS, DEFAULT_VISIBILITY_DISTANCE);
    auto pShorty = m_creature->FindNearestCreature(NPC_SHORTY, DEFAULT_VISIBILITY_DISTANCE);
    auto pRiflemanWheeler = m_creature->FindNearestCreature(NPC_RIFLEMAN_WHEELER, DEFAULT_VISIBILITY_DISTANCE);
    auto pRiflemanMiddlecamp = m_creature->FindNearestCreature(NPC_RIFLEMAN_MIDDLECAMP, DEFAULT_VISIBILITY_DISTANCE);
    auto pSpotterKlemmy = m_creature->FindNearestCreature(NPC_SPOTTER_KLEMMY, DEFAULT_VISIBILITY_DISTANCE);

    if (!pAngus || !pShorty || !pRiflemanWheeler || !pRiflemanMiddlecamp || !pSpotterKlemmy)
    {
        return;
    }

    // creatures' AI trycast
    auto pAngusAI = static_cast<npc_angusAI*>(pAngus->AI());
    auto pShortyAI = static_cast<npc_shortyAI*>(pShorty->AI());
    auto pRiflemanWheelerAI = static_cast<npc_rifleman_wheelerAI*>(pRiflemanWheeler->AI());
    auto pRiflemanMiddlecampAI = static_cast<npc_rifleman_middlecampAI*>(pRiflemanMiddlecamp->AI());
    auto pSpotterKlemmyAI = static_cast<npc_spotter_klemmyAI*>(pSpotterKlemmy->AI());

    if (!pAngusAI || !pShortyAI || !pRiflemanWheelerAI || !pRiflemanMiddlecampAI || !pSpotterKlemmyAI)
    {
        return;
    }

    if (start)
    {
        pAngusAI->StartEvent();
        pShortyAI->StartEvent();
        pRiflemanWheelerAI->StartEvent();
        pRiflemanMiddlecampAI->StartEvent();
        pSpotterKlemmyAI->StartEvent();
        m_bEventStartSent = true;
    }
    else
    {
        pAngusAI->FinishEvent();
        pShortyAI->FinishEvent();
        pRiflemanWheelerAI->FinishEvent();
        pRiflemanMiddlecampAI->FinishEvent();
        pSpotterKlemmyAI->FinishEvent();
        m_bEventFinishSent = true;
    }
}

void npc_mortar_team_watcherAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_bEventStartSent)
    {
        PokeAll();
    }

    if (!m_bEventFinishSent)
    {
        if (m_uiEventTimer < uiDiff)
        {
            PokeAll(false);
        }
        else
            m_uiEventTimer -= uiDiff;
    }
}

CreatureAI* GetAI_npc_mortar_team_watcher(Creature* pCreature)
{
    return new npc_mortar_team_watcherAI(pCreature);
}

/*
 * Dwarver Mortar (Mortar Team event support)
 */

struct go_mortarAI : GameObjectAI
{
    explicit go_mortarAI(GameObject* pGo) : GameObjectAI(pGo) { }

    bool OnUse(Unit* pCaster) override
    {
        me->SendGameObjectCustomAnim();

        return true;
    }
};

GameObjectAI* GetAI_go_mortar(GameObject* pGo)
{
    return new go_mortarAI(pGo);
}

/*
* Mortar Team Target Dummy (Mortar Team event support)
*/

npc_mortar_team_target_dummyAI::npc_mortar_team_target_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    npc_mortar_team_target_dummyAI::Reset();
}

void npc_mortar_team_target_dummyAI::Reset() { }

void npc_mortar_team_target_dummyAI::SpellHit(Unit*, SpellEntry const* pSpell)
{
    if (pSpell->Id == SPELL_MORTAR_SHOT)
    {
        m_creature->DoKillUnit(m_creature);
    }
}

void npc_mortar_team_target_dummyAI::UpdateAI(uint32 const uiDiff) { }

CreatureAI* GetAI_npc_mortar_team_target_dummy(Creature* pCreature)
{
    return new npc_mortar_team_target_dummyAI(pCreature);
}

void AddSC_dun_morogh()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_narm_faulk";
    newscript->GetAI = &GetAI_npc_narm_faulk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mortar_team_watcher";
    newscript->GetAI = &GetAI_npc_mortar_team_watcher;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_angus";
    newscript->GetAI = &GetAI_npc_angus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_shorty";
    newscript->GetAI = &GetAI_npc_shorty;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rifleman_wheeler";
    newscript->GetAI = &GetAI_npc_rifleman_wheeler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rifleman_middlecamp";
    newscript->GetAI = &GetAI_npc_rifleman_middlecamp;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_spotter_klemmy";
    newscript->GetAI = &GetAI_npc_spotter_klemmy;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_mortar";
    newscript->GOGetAI = &GetAI_go_mortar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mortar_team_target_dummy";
    newscript->GetAI = &GetAI_npc_mortar_team_target_dummy;
    newscript->RegisterSelf();
}
