/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
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
SDName: Instance_Temple_of_Ahnqiraj
SD%Complete: 80
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "temple_of_ahnqiraj.h"

static constexpr uint32 CTHUN_WHISPER_MUTE_DURATION = 60000 * 10;
static constexpr uint32 CTHUN_FIRST_WHISPER         = 90000;
static constexpr uint32 CTHUN_WHISPER_FREQ_MIN      = 30000;
static constexpr uint32 CTHUN_WHISPER_FREQ_MAX      = 60000;

enum eTwinsDeathTexts {
    SAY_VEKLOR_DEATH    = -1531024, //my brother...nO!
    SAY_VEKNILASH_DEATH = -1531031 // Vek'loor, i feel your pain! 
};
static const SIDialogueEntry twinsDeathDialogue[] =
{
    { SAY_VEKNILASH_DEATH,  NPC_VEKNILASH, 3000 }, //todo: 3000 is just a guess
    { SAY_VEKLOR_DEATH,     NPC_VEKLOR,    0 }, 
    { 0, 0, 0 }
};

enum eTwinsDialogueEntries
{
    EMOTE_EYE_INTRO         = -1531012,
    EVENT_EYE_TURN_AROUND   = 1,
    EVENT_EMPERORS_RISE     = 2,
    SAY_EMPERORS_INTRO_1    = -1531013, // Only flesh and bone. .. 
    SAY_EMPERORS_INTRO_2    = -1531014, // Where are your manners...
    SAY_EMPERORS_INTRO_3    = -1531015, // There will be pain...
    SAY_EMPERORS_INTRO_4    = -1531016, // Oh so much pain...
    SAY_EMPERORS_INTRO_5    = -1531017, // Come, little ones...
    SAY_EMPERORS_INTRO_6    = -1531018, // The feast of souls...
};

// Sources:
// https://www.youtube.com/watch?v=anDqSl-_y9Y
// https://www.youtube.com/watch?v=drIsWEJkkHs
// Before start:  The eye should be turned away from the trigger, and emperors should be kneeling. 
//           +0:  Trigger reached - emote happens
//           +2:  The eye turns around and the emperors rise up to standing state.
//           +7:  The eye despawns and emperors begins the dialogue
static const SIDialogueEntry aIntroDialogue[] =
{
    { EMOTE_EYE_INTRO,       NPC_MASTERS_EYE, 2000 }, // Trigger reached, emote happens. last 2 seconds
    { EVENT_EYE_TURN_AROUND, NPC_MASTERS_EYE, 1000 }, // Eye turns around, 
    { EVENT_EMPERORS_RISE,   NPC_MASTERS_EYE, 5000 }, // emperors rise up one second later
    { SAY_EMPERORS_INTRO_1,  NPC_VEKLOR,      7000 }, // Eye despawns, first line of dialogue 5 seconds later
    { SAY_EMPERORS_INTRO_2,  NPC_VEKNILASH,   8000 },
    { SAY_EMPERORS_INTRO_3,  NPC_VEKLOR,      3000 },
    { SAY_EMPERORS_INTRO_4,  NPC_VEKNILASH,   3000 },
    { SAY_EMPERORS_INTRO_5,  NPC_VEKLOR,      3000 },
    { SAY_EMPERORS_INTRO_6,  NPC_VEKNILASH,   0 },
    { 0, 0, 0 }
};
TwinsIntroDialogue::TwinsIntroDialogue() :
    DialogueHelper(aIntroDialogue),
    m_StartedOrDone(false)
{

}

void TwinsIntroDialogue::Start()
{
    m_StartedOrDone = true;
    if (!m_pInstance) {
        sLog.outError("TwinsIntroDialogue missing instance. Cannot start.");
        return;
    }
    Creature* pEye = m_pInstance->GetSingleCreatureFromStorage(NPC_MASTERS_EYE);
    Creature* pVL = m_pInstance->GetSingleCreatureFromStorage(NPC_VEKLOR);
    Creature* pVN = m_pInstance->GetSingleCreatureFromStorage(NPC_VEKNILASH);

    // If we're missing one of the creatures needed in this little event, we just skip it.
    if (!pEye || !pVL || !pVN) {
        sLog.outError("Missing one or more of the required creatures to start TwinsIntroDialogue. Not starting.");
        if (pEye)
            pEye->ForcedDespawn(1000);
        return;
    }
    StartNextDialogueText(EMOTE_EYE_INTRO);
}

bool TwinsIntroDialogue::StartedOrDone()
{
    return m_StartedOrDone;
}

void TwinsIntroDialogue::SetDone()
{
    m_StartedOrDone = true;
}

void TwinsIntroDialogue::JustDidDialogueStep(int32 iEntry)
{
    Creature* pEye = m_pInstance->GetSingleCreatureFromStorage(NPC_MASTERS_EYE);
    Creature* pVL = m_pInstance->GetSingleCreatureFromStorage(NPC_VEKLOR);
    Creature* pVN = m_pInstance->GetSingleCreatureFromStorage(NPC_VEKNILASH);
    // If we at any point are missing one of the creatures we skip to the end and stop.
    if (!pEye || !pVL || !pVN) {
        sLog.outError("Missing one or more of the required creatures in TwinsIntroDialogue::JustDidDialogueStep()");
        return;
    }
    switch (iEntry) {
    case EMOTE_EYE_INTRO:

        break;
    case EVENT_EYE_TURN_AROUND:
        pEye->SetFacingTo(1.57f);
        break;
    case EVENT_EMPERORS_RISE:
        pVL->SetStandState(UNIT_STAND_STATE_STAND);
        pVN->SetStandState(UNIT_STAND_STATE_STAND);
        break;
    case SAY_EMPERORS_INTRO_1:
        pEye->ForcedDespawn(1); // Will look like a death to gm, but fade out for players
        break;
    }
}

instance_temple_of_ahnqiraj::instance_temple_of_ahnqiraj(Map* pMap) :
    ScriptedInstance(pMap),
    m_uiBugTrioDeathCount(0),
    m_twinsDeadDialogue(twinsDeathDialogue),
    m_uiCthunWhisperTimer(CTHUN_FIRST_WHISPER),
    m_uiCthunPrevWhisperTimer(CTHUN_FIRST_WHISPER)
{
    Initialize();
};

void instance_temple_of_ahnqiraj::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

    m_twinsIntroDialogue.InitializeDialogueHelper(this);
    m_twinsDeadDialogue.InitializeDialogueHelper(this);
}

bool instance_temple_of_ahnqiraj::IsEncounterInProgress() const
{
    for (uint32 i : m_auiEncounter)
    {
        if (i == IN_PROGRESS || i == SPECIAL)
            return true;
    }

    return false;
}

void instance_temple_of_ahnqiraj::DoHandleTempleAreaTrigger(uint32 uiTriggerId)
{
    if (uiTriggerId == AREATRIGGER_TWIN_EMPERORS && !TwinsDialogueStartedOrDone())
    {
        // Current assumption is the event only start once every soft reset.
        // May need to tweak if-statement to make sure this is the case.
        m_twinsIntroDialogue.Start();
    }
    else if (uiTriggerId == AREATRIGGER_SARTURA)
    {
        if (GetData(TYPE_SARTURA) == NOT_STARTED || GetData(TYPE_SARTURA) == FAIL)
        {
            if (Creature* pSartura = GetSingleCreatureFromStorage(NPC_BATTLEGUARD_SARTURA))
                pSartura->SetInCombatWithZone();
        }
    }
}

void instance_temple_of_ahnqiraj::OnObjectCreate(GameObject* pGo)
{
    switch (pGo->GetEntry())
    {
    case GO_SKERAM_GATE:
        if (m_auiEncounter[TYPE_SKERAM] == DONE)
            pGo->UseDoorOrButton(0, false);
    break;
    case GO_TWINS_ENTER_DOOR:
        if (m_auiEncounter[TYPE_HUHURAN] == DONE)
            pGo->UseDoorOrButton(0, false);
    break;
    case GO_TWINS_EXIT_DOOR:
        if (m_auiEncounter[TYPE_TWINS] == DONE)
            pGo->UseDoorOrButton(0, false);
        break;
    case GO_GRASP_OF_CTHUN:
        graspsOfCthun.push_back(pGo->GetObjectGuid());
        if (m_auiEncounter[TYPE_CTHUN] == DONE) {
            pGo->SetVisible(false);
        }
        break;
    default:
        return;
    }
    m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
}

void instance_temple_of_ahnqiraj::OnCreatureRespawn(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
    case NPC_ANUBISATH_SENTINEL:
    case NPC_OBSIDIAN_ERADICATOR:
        if (m_auiEncounter[TYPE_SKERAM] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_QIRAJI_BRAINWASHER:
    case NPC_VEKNISS_GUARDIAN:
    case NPC_VEKNISS_WARRIOR:
    case NPC_SARTURA_S_ROYAL_GUARD:
        if (m_auiEncounter[TYPE_SARTURA] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_VEKNISS_DRONE:
    case NPC_VEKNISS_SOLDIER:
        if (m_auiEncounter[TYPE_FANKRISS] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_VEKNISS_HIVE_CRAWLER:
    case NPC_VEKNISS_WASP:
    case NPC_QIRAJI_LASHER:
    case NPC_VEKNISS_STINGER:
        if (m_auiEncounter[TYPE_HUHURAN] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_ANUBISATH_DEFENDER:
    case NPC_QIRAJI_SCARAB:
    case NPC_QIRAJI_SCORPION:
        if (m_auiEncounter[TYPE_TWINS] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_OURO_SCARAB:
        if (m_auiEncounter[TYPE_OURO] != IN_PROGRESS)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_QIRAJI_MINDSLAYER:
    case NPC_QIRAJI_SLAYER:
    case NPC_QIRAJI_CHAMPION:
    case NPC_ANUBISATH_WARDER:
    case NPC_OBSIDIAN_NULLIFIER:
        if (m_auiEncounter[TYPE_CTHUN] == DONE)
            pCreature->AddObjectToRemoveList();
        break;
    case NPC_MASTERS_EYE:
        // Despawn C'thun eye at twins if twins are already dead
        if (TwinsDialogueStartedOrDone()) {
            pCreature->AddObjectToRemoveList();
            //pCreature->ForcedDespawn(1);
        }
        break;
    }
}

void instance_temple_of_ahnqiraj::OnCreatureCreate(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
    case NPC_PRINCESS_YAUJ:
    case NPC_VEM:
    case NPC_KRI:
    case NPC_BATTLEGUARD_SARTURA:
    case NPC_VEKLOR:
    case NPC_VEKNILASH:
    case NPC_EYE_OF_C_THUN:
    case NPC_CTHUN:
    case NPC_MASTERS_EYE:
    case NPC_OURO_SPAWNER:
    case NPC_CTHUN_PORTAL:
        m_mNpcEntryGuidStore[pCreature->GetEntry()] = pCreature->GetObjectGuid();
        break;
    case NPC_QIRAJI_SLAYER: // Randomize C'thun trash packs
        
        if (urand(0, 1))
        {
            pCreature->SetEntry(15246);
            pCreature->UpdateEntry(15246);
            pCreature->AIM_Initialize();
        }
        break;
    case NPC_QIRAJI_MINDSLAYER:
        if (urand(0, 1))
        {
            pCreature->SetEntry(15250);
            pCreature->UpdateEntry(15250);
            pCreature->AIM_Initialize();
        }
        break;
    case NPC_SARTURA_S_ROYAL_GUARD:
        m_lRoyalGuardGUIDList.push_back(pCreature->GetObjectGuid());
        break;
    case NPC_CAELESTRASZ:
        pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        break;
    }
    // Delete some creatures
    OnCreatureRespawn(pCreature);
}

void instance_temple_of_ahnqiraj::SetData(uint32 uiType, uint32 uiData)
{
    switch (uiType)
    {
    case TYPE_SKERAM:
        m_auiEncounter[uiType] = uiData;
        if (uiData == DONE) {
            if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_SKERAM_GATE))
                DoOpenDoor(pGo->GetGUID());
        }
        break;
    case TYPE_BUG_TRIO:
        if (uiData == SPECIAL)
        {
            ++m_uiBugTrioDeathCount;
            if (m_uiBugTrioDeathCount >= 3)
                SetData(TYPE_BUG_TRIO, DONE);
            // don't store any special data
            break;
        }
        if (uiData == IN_PROGRESS)
            m_uiBugTrioDeathCount = 0;
        m_auiEncounter[uiType] = uiData;
        break;
    case TYPE_SARTURA:
    case TYPE_FANKRISS:
    case TYPE_VISCIDUS:
        m_auiEncounter[uiType] = uiData;
        break;
    case TYPE_HUHURAN:
        m_auiEncounter[uiType] = uiData;
        if (uiData == DONE) {
            if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_TWINS_ENTER_DOOR))
                DoOpenDoor(pGo->GetGUID());
        }
        break;
    case TYPE_TWINS:
        // Either of the twins can set data, so return to avoid double changing
        if (m_auiEncounter[uiType] ==  uiData)
            return;
        m_auiEncounter[uiType] = uiData;
        if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_TWINS_ENTER_DOOR)) {
            if (uiData != IN_PROGRESS) {
                DoOpenDoor(pGo->GetGUID());
            }
        }
        if (uiData == DONE) {
            if (GameObject* pGo = GetSingleGameObjectFromStorage(GO_TWINS_EXIT_DOOR)) {
                DoOpenDoor(pGo->GetGUID());
            }
            m_twinsDeadDialogue.StartNextDialogueText(SAY_VEKNILASH_DEATH);
        }
        break;
    case TYPE_OURO:
        switch (uiData)
        {
        case FAIL:
            // Respawn the Ouro spawner on fail
            if (Creature* pSpawner = GetSingleCreatureFromStorage(NPC_OURO_SPAWNER))
                pSpawner->Respawn();
            break;
        }
        m_auiEncounter[uiType] = uiData;
        break;
    case TYPE_CTHUN:
        m_auiEncounter[uiType] = uiData;
        for (const auto& guid : graspsOfCthun)
        {
            if (GameObject* pGo = GetGameObject(guid))
                pGo->SetVisible(uiData != DONE);
        }
        break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        for (uint32 i : m_auiEncounter)
            saveStream << i << " ";

        m_strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_temple_of_ahnqiraj::Load(char const* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
       for (uint32 & i : m_auiEncounter)
    {
        loadStream >> i;
        if (i == IN_PROGRESS)
            i = NOT_STARTED;
    }
    
    if (m_auiEncounter[TYPE_TWINS] == DONE) {
        m_twinsIntroDialogue.SetDone();
    }
    
    OUT_LOAD_INST_DATA_COMPLETE;
}

void instance_temple_of_ahnqiraj::UpdateCThunWhisper(uint32 diff)
{
    uint32 cthunStatus = GetData(TYPE_CTHUN);
    if (cthunStatus == DONE) {
        return;
    }
    if (m_uiCthunWhisperTimer >= diff) {
        m_uiCthunWhisperTimer -= diff;
        return;
    }
    m_uiCthunWhisperTimer = urand(CTHUN_WHISPER_FREQ_MIN, CTHUN_WHISPER_FREQ_MAX);
    
    // Updating muted players
    for (auto it = cthunWhisperMutes.begin(); it != cthunWhisperMutes.end(); ) {
        it->second -= std::min(m_uiCthunPrevWhisperTimer, it->second);
        
        if (it->second < CTHUN_WHISPER_FREQ_MAX)
            it = cthunWhisperMutes.erase(it);
        else
            ++it;
    }
    m_uiCthunPrevWhisperTimer = m_uiCthunWhisperTimer;
    
    if (cthunStatus == IN_PROGRESS) {
        return;
    }

    Creature* pCthun = GetSingleCreatureFromStorage(NPC_CTHUN);
    if (!pCthun)
        return;

    std::list<Player*> candidates;
    std::list<Player*>::iterator j;
    Map::PlayerList const& PlayerList = GetMap()->GetPlayers();
    if (PlayerList.isEmpty())
        return;

    for (const auto& itr : PlayerList)
    {
        if (Player* player = itr.getSource())
        {
            if (!player->IsDead()) {
                auto find_it = std::find_if(cthunWhisperMutes.begin(), cthunWhisperMutes.end(), 
                    [player](std::pair<ObjectGuid, uint32> const& e) {return e.first == player->GetObjectGuid(); });
                if (find_it == cthunWhisperMutes.end()) {
                    candidates.push_back(player);
                }
            }
        }
    }
    
    if (candidates.empty())
        return;

    j = candidates.begin();
    std::advance(j, urand(0, candidates.size() - 1));
    Player* targetPlayer = *j;
    // ToDo: also cast the C'thun Whispering charm spell - requires additional research
    DoScriptText(irand(SAY_CTHUN_WHISPER_8, SAY_CTHUN_WHISPER_1), pCthun, targetPlayer);

    cthunWhisperMutes.push_back(std::make_pair(targetPlayer->GetGUID(), CTHUN_WHISPER_MUTE_DURATION));
}

void instance_temple_of_ahnqiraj::Update(uint32 uiDiff)
{
    m_twinsIntroDialogue.DialogueUpdate(uiDiff);
    m_twinsDeadDialogue.DialogueUpdate(uiDiff);
 
    UpdateCThunWhisper(uiDiff);

    UpdateStomachOfCthun(uiDiff);
}

bool instance_temple_of_ahnqiraj::TwinsDialogueStartedOrDone()
{
    return m_twinsIntroDialogue.StartedOrDone();
}

uint32 instance_temple_of_ahnqiraj::GetData(uint32 uiType)
{
    return m_auiEncounter[uiType];
}

bool instance_temple_of_ahnqiraj::CheckConditionCriteriaMeet(Player const* player, uint32 map_id, WorldObject const* source, uint32 instance_condition_id) const
{
    if (instance_condition_id >= MAX_ENCOUNTER)
        return false;

    return m_auiEncounter[instance_condition_id] == DONE;
}

bool AreaTrigger_at_temple_ahnqiraj(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (pAt->id == AREATRIGGER_TWIN_EMPERORS || pAt->id == AREATRIGGER_SARTURA)
    {
        if (pPlayer->IsGameMaster() || !pPlayer->IsAlive())
            return false;

        if (instance_temple_of_ahnqiraj* pInstance = (instance_temple_of_ahnqiraj*)pPlayer->GetInstanceData())
            pInstance->DoHandleTempleAreaTrigger(pAt->id);
    }
    if (instance_temple_of_ahnqiraj* pInstance = (instance_temple_of_ahnqiraj*)pPlayer->GetInstanceData())
        pInstance->HandleStomachTriggers(pPlayer, pAt);

    return false;
}

void instance_temple_of_ahnqiraj::AddPlayerToStomach(Unit * p)
{
    if (Creature* pCthun = GetSingleCreatureFromStorage(NPC_CTHUN))
        pCthun->CastSpell(p, SPELL_DIGESTIVE_ACID, true);
    playersInStomach.push_back(std::make_pair(p->GetGUID(), StomachTimers()));
}

instance_temple_of_ahnqiraj::CThunStomachList::iterator instance_temple_of_ahnqiraj::PlayerInStomachIter(Unit * unit)
{
    if (!unit) return playersInStomach.end();

    return std::find_if(playersInStomach.begin(), playersInStomach.end(),
        [unit](std::pair<ObjectGuid, StomachTimers> const& e) {
        return unit->GetObjectGuid() == e.first;
    });
}

void instance_temple_of_ahnqiraj::TeleportPlayerToCThun(Player* pPlayer)
{
    // Player is ported to center of c'thun with a small, random, offset to knock the player in a random direction.
    AreaTriggerEntry const* cthunAreaTrigger = sObjectMgr.GetAreaTrigger(AREATRIGGER_CTHUN_KNOCKBACK);
    if (cthunAreaTrigger) {
        float x = cthunAreaTrigger->x + cos((frand(0.0f, 360.0f)) * (3.14f / 180.0f)) * 0.1f;
        float y = cthunAreaTrigger->y + sin((frand(0.0f, 360.0f)) * (3.14f / 180.0f)) * 0.1f;
        pPlayer->NearTeleportTo(x, y, cthunAreaTrigger->z, pPlayer->GetOrientation());
    }
    else {
        float x = -8578.0f + cos((frand(0.0f, 360.0f)) * (3.14f / 180.0f)) * 0.1f;
        float y = 1986.8f + sin((frand(0.0f, 360.0f)) * (3.14f / 180.0f)) * 0.1f;
        pPlayer->NearTeleportTo(x, y, 100.4f, pPlayer->GetOrientation());
        sLog.outError("instance_temple_of_ahnqiraj::HandleStomachTriggers attempted to lookup area trigger %d, but it was not found.",
            AREATRIGGER_CTHUN_KNOCKBACK);
    }
}

void instance_temple_of_ahnqiraj::PerformCthunKnockback()
{
    AreaTriggerEntry const* pAt = sObjectMgr.GetAreaTrigger(AREATRIGGER_CTHUN_KNOCKBACK);
    float x, y, z;
    if (pAt) {
        x = pAt->x;
        y = pAt->y;
        z = pAt->z;
    }
    else {
        x = -8578.0f;
        y = 1986.8f;
        z = 100.22f;
    }
    if (Creature* kbCreature = GetMap()->SummonCreature(EXIT_KNOCKBACK_CREATURE, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 1000)) {
        kbCreature->CastSpell(kbCreature, SPELL_EXIT_STOMACH_KNOCKBACK, false);
    }
}

bool instance_temple_of_ahnqiraj::PlayerInStomach(Unit * unit)
{
    if (!unit) return false;

    return PlayerInStomachIter(unit) != playersInStomach.end();
}

void instance_temple_of_ahnqiraj::HandleStomachTriggers(Player * pPlayer, AreaTriggerEntry const * pAt)
{
    if (!pPlayer) return;
    if (pPlayer->IsGameMaster() || !pPlayer->IsAlive())
        return;

    if (pAt->id == AREATRIGGER_STOMACH_GROUND) {
        if (!puntCreatureGuid) {
            if (Creature* pc = GetMap()->SummonCreature(PUNT_CREATURE, pAt->x, pAt->y, pAt->z, 0,
                TEMPSUMMON_TIMED_DESPAWN, 4000)) {
                puntCreatureGuid = pc->GetGUID();
                quakeTimer = 1000;
                puntCountdown = StomachTimers::PUNT_CAST_TIME;
                // Since this is the wrong spell, and it deals damage, we send the visual only, instead of casting it.       
                pc->SendSpellGo(pc, SPELL_QUAKE);

            }
        }
    }
    else if (pAt->id == AREATRIGGER_STOMACH_AIR) {
        TeleportPlayerToCThun(pPlayer);
    }
    else if (pAt->id == AREATRIGGER_CTHUN_KNOCKBACK) {
        // "Disable" the knockback if c'thun is killed
        if (GetData(TYPE_CTHUN) != DONE) {
            PerformCthunKnockback();
            // If the areatrigger was triggered by a player who was ported from stomach
            // we find his timer object and set didKnockback to true, to avoid double-knockback
            // in the UpdateStomachOfCthun function
            auto it = PlayerInStomachIter(pPlayer);
            if (it != playersInStomach.end() && !it->second.didKnockback) {
                it->second.didKnockback = true;
            }
        }
    }
}

bool instance_temple_of_ahnqiraj::KillPlayersInStomach()
{
    for (auto iter = playersInStomach.begin(); iter != playersInStomach.end();) {
        if (Player* p = GetMap()->GetPlayer(iter->first)) {
            // Not killing people with god on, makes debugging easier
            if (p->IsGod()) {
                ++iter;
                continue;
            }

            if (p->IsAlive()) {
                p->DealDamage(p, p->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
            }
            if (p->HasAura(SPELL_DIGESTIVE_ACID)) {
                p->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);
            }
        }
        iter = playersInStomach.erase(iter);
    }

    return playersInStomach.empty();
}

void instance_temple_of_ahnqiraj::UpdateStomachOfCthun(uint32 diff)
{
    // Update the punt creature
    if (Creature* pc = GetMap()->GetCreature(puntCreatureGuid)) {
        // Updating animation
        if (quakeTimer < diff) {
            pc->SendSpellGo(pc, SPELL_QUAKE);
            quakeTimer = 1000;
        }
        else {
            quakeTimer -= diff;
        }
        //Checking if it's time to punt
        if (puntCountdown < diff) {
            pc->CastSpell(pc, SPELL_PUNT_UPWARD, true);
            puntCountdown = std::numeric_limits<uint32>::max();
            puntCreatureGuid = 0;
        }
        else {
            puntCountdown -= diff;
        }
    }
    else {
        puntCreatureGuid = 0;
    }

    // Update the players in the stomach
    if (playersInStomach.empty()) return;

    AreaTriggerEntry const* pot = sObjectMgr.GetAreaTrigger(AREATRIGGER_STOMACH_AIR);
    for (auto it = playersInStomach.begin(); it != playersInStomach.end();) {
        Player* player = GetMap()->GetPlayer(it->first);
        //Player has left instance or something and we remove him from the list. 
        if (!player) {
            it = playersInStomach.erase(it);
            continue;
        }

        StomachTimers& timers = it->second;
        timers.timeSincePortedToStomach += diff;
        
        // playerPositionZ > 0.0 (stomach teleport-out trigger is at ~-30.0f, c'thun is at ~100.f)
        // means the player is outside the stomach as far as the server is concerned.
        if (player->GetPositionZ() > 0.0f) 
        {
            // timeSincePortedToStomach prevents the player from being removed from stomach on first
            // update after being TPed to the stomach, as the server might not realize the player
            // has been teleported during the same update that TeleportPlayerToCThun is called
            if (timers.timeSincePortedToStomach > 4000) 
            {
                if (player->HasAura(SPELL_DIGESTIVE_ACID)) 
                {
                    player->RemoveAurasDueToSpell(SPELL_DIGESTIVE_ACID);
                }

                // HandleStomachTriggers() might be first to the party and perform the knockback,
                // in which case we skip it here. We also use timeSincePortedFromStomach > 0 to delay
                // the knockback one server-update, as it seems the knockback might not always hit 
                // if it's cast on the same update as the player is ported.
                if (!timers.didKnockback && timers.timeSincePortedFromStomach > 0) 
                {
                    PerformCthunKnockback();
                    timers.didKnockback = true;
                }
                else 
                {
                    timers.timeSincePortedFromStomach += diff;
                }

                // ~1.5 sec after being registered as outside the stomach, we remove the player from the list.
                // The delay will prevent tentacles to spawn in the center of c'thun through extremely bad luck, should
                // c'thun attempt to spawn a tentacle on the player just as he is TPed out, before the knockback.
                if (it->second.timeSincePortedFromStomach > 1500) {
                    it = playersInStomach.erase(it);
                    continue;
                }
            }
        }
        else 
        {
            if (timers.acidDebuff < diff)
            {
                if (Creature* pCthun = GetSingleCreatureFromStorage(NPC_CTHUN))
                    pCthun->CastSpell(player, SPELL_DIGESTIVE_ACID, true);
                timers.acidDebuff += StomachTimers::ACID_REFRESH_RATE;
            }
            else
                timers.acidDebuff -= diff;

            // Crude hack for teleporting players from the stomach if the areatrigger
            // in the air above knockback area in stomach of c'thun did not trigger.
            if (pot) {
                if (player->IsLaunched() && player->IsFalling()) {
                    if (player->GetDistance(pot->x, pot->y, pot->z) <= pot->radius) {
                        TeleportPlayerToCThun(player);
                    }
                }
            }
        }
        
        ++it;
    }
}

struct AI_QirajiMindslayer : public ScriptedAI {
    uint32 insanityTimer;
    uint32 mindBlastTimer;
    uint32 mindFlayTimer;

    AI_QirajiMindslayer(Creature* pCreature) :
        ScriptedAI(pCreature)
    {
        Reset();
    }


    void Reset() override
    {
        insanityTimer = 10000;
        mindBlastTimer = 5000;
        mindFlayTimer = urand(12000, 15000);
    }

    void JustDied(Unit* pWho) override
    {
        if (!m_creature->GetInstanceData())
            return;

        // finding closest player and casting manaburn on that target.
        // todo: should we add a player->GetPowerType() == POWER_MANA check too when choosing valid target?
        Player* closestPlayer = nullptr;
        float closestDist = std::numeric_limits<float>::max();
        MapRefManager const &list = m_creature->GetMap()->GetPlayers();
        for (const auto& i : list)
        {
            if (Player* player = i.getSource()) {
                if (player->IsAlive()) { 
                    float dist = m_creature->GetDistance(player);
                    if (dist < closestDist) {
                        closestPlayer = player;
                        closestDist = dist;
                    }
                }
            }
        }
        if (closestPlayer) {
            DoCastSpellIfCan(closestPlayer, 26049, CF_TRIGGERED | CF_INTERRUPT_PREVIOUS);
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->IsNonMeleeSpellCasted()) { // prevents re-targetting of topaggro from happening while channeling mindflay
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;
        }
            
        if (mindFlayTimer < diff) {
            if (Unit* pU = m_creature->SelectAttackingTarget(AttackingTarget::ATTACKING_TARGET_RANDOM, 0, 26044, SELECT_FLAG_PLAYER | SELECT_FLAG_IN_LOS)) {
                if (DoCastSpellIfCan(pU, 26044) == CAST_OK) {
                    mindFlayTimer = urand(12000, 15000);
                }
            }
        }
        else {
            mindFlayTimer -= diff;
        }

        if (mindBlastTimer < diff) {
            if (Unit* pU = m_creature->SelectAttackingTarget(AttackingTarget::ATTACKING_TARGET_TOPAGGRO, 0, 26048, SELECT_FLAG_PLAYER | SELECT_FLAG_IN_LOS)) {
                if (DoCastSpellIfCan(pU, 26048) == CAST_OK) {
                    mindBlastTimer = urand(9000, 12000);
                }
            }
        }
        else {
            mindBlastTimer -= diff;
        }
        
        if (insanityTimer < diff) {
            if (Unit* pU = m_creature->SelectAttackingTarget(AttackingTarget::ATTACKING_TARGET_RANDOM, 0, 26079, SELECT_FLAG_PLAYER | SELECT_FLAG_IN_LOS)) {
                if (DoCastSpellIfCan(pU, 26079) == CAST_OK) {
                    insanityTimer = 10000;
                }
            }
        }
        else {
            insanityTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }

};
InstanceData* GetInstanceData_instance_temple_of_ahnqiraj(Map* pMap)
{
    return new instance_temple_of_ahnqiraj(pMap);
}

CreatureAI* GetAI_qirajiMindslayer(Creature* pCreature)
{
    return new AI_QirajiMindslayer(pCreature);
}

void AddSC_instance_temple_of_ahnqiraj()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_temple_of_ahnqiraj";
    pNewScript->GetInstanceData = &GetInstanceData_instance_temple_of_ahnqiraj;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_temple_ahnqiraj";
    pNewScript->pAreaTrigger = &AreaTrigger_at_temple_ahnqiraj;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_qiraji_mindslayer";
    pNewScript->GetAI = &GetAI_qirajiMindslayer;
    pNewScript->RegisterSelf();

}
