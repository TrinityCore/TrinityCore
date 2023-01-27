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
SDName: Instance_Scarlet_Monastery
SD%Complete: 50
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "scriptPCH.h"
#include "Utilities/EventMap.h"
#include "scarlet_monastery.h"

enum AshbringerEventMisc
{
    NPC_SCARLET_MYRIDON = 4295,
    NPC_SCARLET_DEFENDER = 4298,
    NPC_SCARLET_CENTURION = 4301,
    NPC_SCARLET_SORCERER = 4294,
    NPC_SCARLET_WIZARD = 4300,
    NPC_SCARLET_ABBOT = 4303,
    NPC_SCARLET_MONK = 4540,
    NPC_SCARLET_CHAMPION = 4302,
    NPC_SCARLET_CHAPLAIN = 4299,
    NPC_FAIRBANKS = 4542,
    NPC_COMMANDER_MOGRAINE = 3976,
    NPC_HIGHLORD_MOGRAINE = 16062,

    GO_CHAPEL_DOOR   = 104591,
    GO_HIGH_INQUISITOR_DOOR = 104600,

    ITEM_CORRUPTED_ASHBRINGER = 22691,

    SAY_COMMANDER1  = 12390,
    SAY_COMMANDER2  = 12470,
    SAY_COMMANDER3  = 12472,
    SAY_ASHBRINGER1 = 12469,
    SAY_ASHBRINGER2 = 12471,
    SAY_ASHBRINGER3 = 12473,
    YELL_COMMANDER  = 12389,

    SPELL_AB_EFFECT_000   = 28441,
    SPELL_FORGIVENESS     = 28697,
    SPELL_MOGRAINE_COMETH = 28688
};

enum eEvents
{
    EVENT_KNEEL = 1,
    EVENT_TALK1,
    EVENT_SUMMON,
    EVENT_TALK2,
    EVENT_STAND,
    EVENT_TALK3,
    EVENT_TALK4,
    EVENT_SECOND_DOUBT,
    EVENT_POINT,
    EVENT_ROAR,
    EVENT_TALK5,
    EVENT_SPELL,
    EVENT_FORGIVEN,
    EVENT_DESPAWN
};

struct instance_scarlet_monastery : ScriptedInstance
{
    explicit instance_scarlet_monastery(Map* pMap) :
            ScriptedInstance(pMap),
            m_ashbringerActive(false)
    {
        instance_scarlet_monastery::Initialize();
    }

    uint32 m_auiEncounter[INSTANCE_SM_MAX_ENCOUNTER];

    uint64 m_uiMograineGUID;
    uint64 m_uiWhitemaneGUID;
    uint64 m_uiVorrelGUID;
    uint64 m_uiDoorHighInquisitorGUID;
    uint64 m_uiChapelDoorGUID;
    uint64 m_uiAshbringerWielderGUID;

    bool m_ashbringerActive;
    uint32 m_ashbringerCheckTimer;
    std::set<ObjectGuid> m_ashbringerReactedNpcs;
    EventMap m_events;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiMograineGUID = 0;
        m_uiWhitemaneGUID = 0;
        m_uiVorrelGUID = 0;
        m_uiDoorHighInquisitorGUID = 0;
        m_uiChapelDoorGUID = 0;
        m_uiAshbringerWielderGUID = 0;
        m_ashbringerCheckTimer = 5000;
        m_ashbringerReactedNpcs.clear();
        m_events.Reset();
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case 3976:
                m_uiMograineGUID = pCreature->GetGUID();
                break;
            case 3977:
                m_uiWhitemaneGUID = pCreature->GetGUID();
                break;
            case 3981:
                m_uiVorrelGUID = pCreature->GetGUID();
                break;
        }
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_HIGH_INQUISITOR_DOOR:
                m_uiDoorHighInquisitorGUID = pGo->GetGUID();
                break;
            case GO_CHAPEL_DOOR:
                m_uiChapelDoorGUID = pGo->GetGUID();
                if (m_ashbringerActive)
                {
                    pGo->SetGoState(GO_STATE_ACTIVE);
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                }
                break;
        }
    }

    uint64 GetData64(uint32 data) override
    {
        switch (data)
        {
            case DATA_MOGRAINE:
                return m_uiMograineGUID;
            case DATA_WHITEMANE:
                return m_uiWhitemaneGUID;
            case DATA_VORREL:
                return m_uiVorrelGUID;
            case DATA_DOOR_WHITEMANE:
                return m_uiDoorHighInquisitorGUID;
        }

        return 0;
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        if (uiType == TYPE_MOGRAINE_AND_WHITE_EVENT)
        {
            if (uiData == IN_PROGRESS || uiData == FAIL)
                DoUseDoorOrButton(m_uiDoorHighInquisitorGUID);

            m_auiEncounter[0] = uiData;
        }
    }

    uint32 GetData(uint32 uiData) override
    {
        if (uiData == TYPE_MOGRAINE_AND_WHITE_EVENT)
            return m_auiEncounter[0];

        return 0;
    }

    void OnCreatureSpellHit(Unit* pCaster, Creature* receiver, SpellEntry const* spell) override
    {
        if (!m_ashbringerActive || !pCaster || !receiver || !spell)
            return;
        if (!pCaster->IsPlayer() || spell->Id != SPELL_AB_EFFECT_000)
            return;
        if (receiver->IsDead())
            return;

        switch (receiver->GetEntry())
        {
            case NPC_COMMANDER_MOGRAINE:
            {
                auto it = m_ashbringerReactedNpcs.find(receiver->GetObjectGuid());
                if (it == m_ashbringerReactedNpcs.end())
                    m_ashbringerReactedNpcs.insert(receiver->GetObjectGuid());
                else
                    return;
                receiver->SetFacingToObject(pCaster);
                m_events.ScheduleEvent(EVENT_KNEEL, Seconds(1));
                break;
            }
            case NPC_SCARLET_MYRIDON:
            case NPC_SCARLET_DEFENDER:
            case NPC_SCARLET_CENTURION:
            case NPC_SCARLET_SORCERER:
            case NPC_SCARLET_WIZARD:
            case NPC_SCARLET_ABBOT:
            case NPC_SCARLET_MONK:
            case NPC_SCARLET_CHAMPION:
            case NPC_SCARLET_CHAPLAIN:
            {
                auto it = m_ashbringerReactedNpcs.find(receiver->GetObjectGuid());
                if (it == m_ashbringerReactedNpcs.end())
                    m_ashbringerReactedNpcs.insert(receiver->GetObjectGuid());
                else
                    return;
                receiver->StopMoving(true);
                receiver->SetFacingToObject(pCaster);
                receiver->SetStandState(UNIT_STAND_STATE_KNEEL);
                receiver->AddUnitState(UNIT_STAT_ROOT);
                if (m_uiAshbringerWielderGUID && urand(0, 1))
                {
                    if (Player* pPlayer = GetMap()->GetPlayer(m_uiAshbringerWielderGUID))
                        DoScriptText(PickRandomValue(12378, 12379, 12380, 12381, 12382, 12383, 12384),
                            receiver, pPlayer);
                }
                break;
            }
            default:
                return;
        }
    }

    void Update(uint32 diff) override
    {
        // not bothering to check if player has unequipped weapon, dont know if its a thing
        if (m_ashbringerActive)
        {
            m_events.Update(diff);
            while (uint32 eventId = m_events.ExecuteEvent())
            {
                Creature* pMograine = GetCreature(m_uiMograineGUID);
                if (!pMograine)
                    continue;

                Creature* pHighlord = GetClosestCreatureWithEntry(pMograine, NPC_HIGHLORD_MOGRAINE, 1000.0f);
                switch (eventId)
                {
                    case EVENT_KNEEL:
                        pMograine->SetSheath(SHEATH_STATE_UNARMED);
                        pMograine->SetStandState(UNIT_STAND_STATE_KNEEL);
                        m_events.ScheduleEvent(EVENT_TALK1, Seconds(2));
                        break;
                    case EVENT_TALK1:
                        if (m_uiAshbringerWielderGUID)
                            if (Player* pPlayer = GetMap()->GetPlayer(m_uiAshbringerWielderGUID))
                                DoScriptText(SAY_COMMANDER1, pMograine, pPlayer);
                        m_events.ScheduleEvent(EVENT_SUMMON, Seconds(10));
                        break;
                    case EVENT_SUMMON:
                        if (Creature* pC = pMograine->SummonCreature(NPC_HIGHLORD_MOGRAINE, 1065.130737f, 1399.350586f, 30.763723f, 6.282961f, TEMPSUMMON_TIMED_DESPAWN, 400000))
                        {
                            pC->SetFactionTemporary(35, TEMPFACTION_RESTORE_RESPAWN);
                            pC->SetObjectScale(2.0f);
                            pC->CastSpell(pC, SPELL_MOGRAINE_COMETH, true);
                            // TODO: The coordinates below appear to be guessed, set the correct ones once we have them.
                            pC->GetMotionMaster()->MovePoint(0, 1150.35f, 1398.39f, 32.0f, 0, 2.7f);
                        }
                        m_events.ScheduleEvent(EVENT_TALK2, Seconds(33));
                        break;
                    case EVENT_TALK2:
                        if (pHighlord)
                            DoScriptText(SAY_ASHBRINGER1, pHighlord);
                        m_events.ScheduleEvent(EVENT_STAND, Seconds(4));
                        break;
                    case EVENT_STAND:
                        pMograine->SetSheath(SHEATH_STATE_MELEE);
                        pMograine->HandleEmoteCommand(EMOTE_STATE_STAND);
                        pMograine->SetStandState(UNIT_STAND_STATE_STAND);
                        pMograine->SetFacingToObject(pHighlord);
                        m_events.ScheduleEvent(EVENT_TALK3, Seconds(2));
                        break;
                    case EVENT_TALK3:
                        DoScriptText(SAY_COMMANDER2, pMograine);
                        m_events.ScheduleEvent(EVENT_TALK4, Seconds(4));
                        break;
                    case EVENT_TALK4:
                        if (pHighlord)
                            DoScriptText(SAY_ASHBRINGER2, pHighlord);
                        m_events.ScheduleEvent(EVENT_SECOND_DOUBT, Seconds(4));
                        break;
                    case EVENT_SECOND_DOUBT:
                        if (pHighlord)
                            pHighlord->HandleEmote(EMOTE_ONESHOT_QUESTION);
                        m_events.ScheduleEvent(EVENT_POINT, Seconds(4));
                        break;
                    case EVENT_POINT:
                        if (pHighlord)
                            pHighlord->HandleEmote(EMOTE_ONESHOT_POINT);
                        m_events.ScheduleEvent(EVENT_ROAR, Seconds(3));
                        break;
                    case EVENT_ROAR:
                        if (pHighlord)
                            pHighlord->HandleEmote(EMOTE_ONESHOT_BATTLEROAR);
                        m_events.ScheduleEvent(EVENT_TALK5, Seconds(4));
                        break;
                    case EVENT_TALK5:
                        DoScriptText(SAY_COMMANDER3, pMograine);
                        m_events.ScheduleEvent(EVENT_SPELL, Seconds(4));
                        break;
                    case EVENT_SPELL:
                        if (pHighlord)
                            pHighlord->CastSpell(pMograine, SPELL_FORGIVENESS, false);
                        m_events.ScheduleEvent(EVENT_FORGIVEN, Seconds(4));
                        break;
                    case EVENT_FORGIVEN:
                        if (pHighlord)
                            DoScriptText(SAY_ASHBRINGER3, pHighlord);
                        m_events.ScheduleEvent(EVENT_DESPAWN, Seconds(4));
                        break;
                    case EVENT_DESPAWN:
                        if (pHighlord)
                            ((TemporarySummon*)pHighlord)->UnSummon();
                        m_uiAshbringerWielderGUID = 0;
                        break;
                }
            }

            return;
        }

        if (m_ashbringerCheckTimer < diff)
        {
            m_ashbringerCheckTimer = 5000;
        }
        else
        {
            m_ashbringerCheckTimer -= diff;
            return;
        }

        if (m_ashbringerActive)
            return;

        Map::PlayerList const& lPlayers = instance->GetPlayers();
        if (lPlayers.isEmpty())
            return;

        for (const auto& itr : lPlayers)
        {
            if (Player* pPlayer = itr.getSource())
            {
                // Ignore if player is in GM mode
                if (pPlayer->IsGameMaster())
                    continue;

                Item* item = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                if (!item)
                    continue;

                if (item->GetEntry() == ITEM_CORRUPTED_ASHBRINGER)
                {
                    m_ashbringerActive = true;
                    m_uiAshbringerWielderGUID = pPlayer->GetGUID();
                    std::list<Creature*> ScarletList;
                    GetCreatureListWithEntryInGrid(ScarletList, pPlayer,
                                                   {
                                                           NPC_SCARLET_MYRIDON,
                                                           NPC_SCARLET_DEFENDER,
                                                           NPC_SCARLET_CENTURION,
                                                           NPC_SCARLET_SORCERER,
                                                           NPC_SCARLET_WIZARD,
                                                           NPC_SCARLET_ABBOT,
                                                           NPC_SCARLET_MONK,
                                                           NPC_SCARLET_CHAMPION,
                                                           NPC_SCARLET_CHAPLAIN,
                                                           NPC_FAIRBANKS,
                                                           NPC_COMMANDER_MOGRAINE
                                                   }, 2000.0f);

                    for (Creature* pCreature : ScarletList)
                        pCreature->SetFactionTemplateId(35);

                    // Chapel door should be open if event is activated
                    if (GameObject* chapelDoor = GetGameObject(m_uiChapelDoorGUID))
                    {
                        chapelDoor->SetGoState(GO_STATE_ACTIVE);
                        chapelDoor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                    }

                    // Mograine's first yell.
                    DoOrSimulateScriptTextForThisInstance(YELL_COMMANDER, NPC_COMMANDER_MOGRAINE);
                    break;
                }
            }
        }
    }
};

InstanceData* GetInstanceData_instance_scarlet_monastery(Map* pMap)
{
    return new instance_scarlet_monastery(pMap);
}

void AddSC_instance_scarlet_monastery()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_scarlet_monastery";
    newscript->GetInstanceData = &GetInstanceData_instance_scarlet_monastery;
    newscript->RegisterSelf();
}
