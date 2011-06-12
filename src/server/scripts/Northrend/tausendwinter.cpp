// Copyright 2009-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#include "ScriptPCH.h"
#include "OutdoorPvPMgr.h"
#include "OutdoorPvPTW.h"
#include "GameObjectAI.h"

enum NPC_TW_MISC_SPELLS
{
    SPELL_STRIKE                = 11976,    // TW_NPC_WACHE + TW_NPC_CHAMPION
    SPELL_SLEEPING_SLEEP        = 42648,    // TW_NPC_CHAMPION
    SPELL_ARCANE_MISSILES       = 31743,    // TW_NPC_VERZAUBERER_A
    SPELL_SLOW                  = 31741,    // TW_NPC_VERZAUBERER_A
    SPELL_HEALING_WAVE          = 11986,    // TW_NPC_VERZAUBERER_H
    SPELL_LIGHTNING_BOLT        = 9532,     // TW_NPC_VERZAUBERER_H
    SPELL_QUICK_FLAME_WARD      = 4979,     // TW_NPC_VERZAUBERER_H
    SPELL_MORTAL_STRIKE         = 15708,    // TW_NPC_QUESTGEBER_1 + TW_NPC_QUESTGEBER_2 + TW_NPC_QUESTGEBER_3 + TW_NPC_QUESTGEBER_4
    SPELL_HEAL                  = 34945,    // TW_NPC_QUESTGEBER_5_A
    SPELL_HOLY_NOVA             = 34944,    // TW_NPC_QUESTGEBER_5_A
    SPELL_POWER_WORD_SHIELD     = 17139,    // TW_NPC_QUESTGEBER_5_A
    SPELL_CLEAVE                = 15284     // TW_NPC_QUESTGEBER_5_H + TW_NPC_QUESTGEBER_6
};

enum NPC_TW_MISC_EVENTS
{
    EVENT_STRIKE = 1,
    EVENT_ARCANE_MISSILES,
    EVENT_SLOW,
    EVENT_HEALING_WAVE,
    EVENT_LIGHTNING_BOLT,
    EVENT_QUICK_FLAME_WARD,
    EVENT_MORTAL_STRIKE,
    EVENT_HEAL,
    EVENT_HOLY_NOVA,
    EVENT_CLEAVE,
    EVENT_WASSERCHECK,
    EVENT_SCHLAFCHECK,
    EVENT_TELEPORTCHECK
};

class npc_verwuesteringenieur : public CreatureScript
{
public:
    npc_verwuesteringenieur() : CreatureScript("npc_verwuesteringenieur") { }

    struct npc_verwuesteringenieurAI : public ScriptedAI
    {
        npc_verwuesteringenieurAI(Creature* pCreature) : ScriptedAI(pCreature) { }
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            sLog->outError("TAUSENDWINTER: 'pTW' in der Klasse 'npc_verwuesteringenieur' nicht initialisiert!");
            return false;
        }

        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (!pTW->IstKampf() || pTW->HoleAnzahlFahrzeugeDerWerkstatt(pCreature->GetDBTableGUIDLow()) >= TW_WERKSTATT_FAHRZEUGE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_MAXIMUM_FAHRZEUGE), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
        }
        else
        {
            if (pPlayer->HasAura(SPELL_FAEHNRICH))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_BAUE_KATAPULT), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            }
            else if (pPlayer->HasAura(SPELL_OBERLEUTNANT))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_BAUE_KATAPULT), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_BAUE_VERWUESTER), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_BAUE_BELAGERUNGSMASCHINE), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            }
        }
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        switch(uiAction - GOSSIP_ACTION_INFO_DEF)
        {
            case 0:
                pCreature->CastSpell(pCreature, SPELL_KATAPULT_BAUEN, false, NULL, NULL, pCreature->GetGUID());
                break;
            case 1:
                pCreature->CastSpell(pCreature, SPELL_VERWUESTER_BAUEN, false, NULL, NULL, pCreature->GetGUID());
                break;
            case 2:
                pCreature->CastSpell(pCreature, pPlayer->GetTeamId() ? SPELL_BELAGERUNGSMASCHINE_BAUEN_H : SPELL_BELAGERUNGSMASCHINE_BAUEN_A, false, NULL, NULL, pCreature->GetGUID());
                break;
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_verwuesteringenieurAI (pCreature);
    }
};

class npc_tausendwinter_diverse : public CreatureScript
{
public:
    npc_tausendwinter_diverse() : CreatureScript("npc_tausendwinter_diverse") { }

    struct npc_tausendwinter_diverseAI : public ScriptedAI
    {
        npc_tausendwinter_diverseAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        }

        void Reset()
        {
            events.Reset();
            eventsOOC.Reset();

            switch(me->GetEntry())
            {
                case TW_NPC_VERZAUBERER_A:
                    // Standard Entfernung
                    me->m_isCaster = true;
                    break;
                case TW_NPC_VERZAUBERER_H:
                case TW_NPC_QUESTGEBER_5_A:
                    me->m_isCaster = true;
                    me->m_CasterDefaultMaxCombatRange = 39;
                    break;
            }
            eventsOOC.ScheduleEvent(EVENT_SCHLAFCHECK, urand(5000, 30000));
        }

        void JustReachedHome()
        {
            switch(me->GetEntry())
            {
                case TW_NPC_CHAMPION_A:
                case TW_NPC_CHAMPION_H:
                    if (pTW && !pTW->IstKampf())
                        eventsOOC.RescheduleEvent(EVENT_SCHLAFCHECK, urand(5000, 30000));
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_STRIKE, 5000);
            events.ScheduleEvent(EVENT_ARCANE_MISSILES, 500);
            events.ScheduleEvent(EVENT_SLOW, 100);
            events.ScheduleEvent(EVENT_HEALING_WAVE, 5000);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 500);
            events.ScheduleEvent(EVENT_QUICK_FLAME_WARD, 100);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5000);
            events.ScheduleEvent(EVENT_HEAL, 5000);
            events.ScheduleEvent(EVENT_HOLY_NOVA, 4000);
            events.ScheduleEvent(EVENT_CLEAVE, 5000);

            switch(me->GetEntry())
            {
                case TW_NPC_QUESTGEBER_5_A:
                    DoCast(me, SPELL_POWER_WORD_SHIELD);
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            eventsOOC.Update(uiDiff);

            switch(me->GetEntry())
            {
                case TW_NPC_CHAMPION_A:
                case TW_NPC_CHAMPION_H:
                    if (EVENT_SCHLAFCHECK == eventsOOC.ExecuteEvent())
                        if (pTW)
                            if (pTW->IstKampf())
                            {
                                if (me->HasAura(SPELL_SLEEPING_SLEEP))
                                    me->RemoveAurasDueToSpell(SPELL_SLEEPING_SLEEP);
                            }
                            else
                            {
                                if (!me->HasAura(SPELL_SLEEPING_SLEEP))
                                    DoCast(me, SPELL_SLEEPING_SLEEP);
                            }
                    eventsOOC.RescheduleEvent(EVENT_SCHLAFCHECK, urand(5000,30000));
                    break;
            }

            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            uint32 eventId = events.ExecuteEvent();
            switch(eventId)
            {
                case EVENT_STRIKE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_WACHE_A:
                        case TW_NPC_WACHE_H:
                        case TW_NPC_CHAMPION_A:
                        case TW_NPC_CHAMPION_H:
                            DoCastVictim(SPELL_STRIKE);
                            events.RescheduleEvent(EVENT_STRIKE, 5000);
                            break;
                    }
                case EVENT_ARCANE_MISSILES:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_A:
                            DoCastVictim(SPELL_ARCANE_MISSILES);
                            events.RescheduleEvent(EVENT_ARCANE_MISSILES, 5000);
                            break;
                    }
                case EVENT_SLOW:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_A:
                            DoCastVictim(SPELL_SLOW);
                            events.RescheduleEvent(EVENT_SLOW, 15000);
                            break;
                    }
                case EVENT_HEALING_WAVE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            if (HealthBelowPct(50))
                                DoCast(me, SPELL_HEALING_WAVE);
                            events.RescheduleEvent(EVENT_HEALING_WAVE, 3000);
                            break;
                    }
                case EVENT_LIGHTNING_BOLT:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            DoCastVictim(SPELL_LIGHTNING_BOLT);
                            events.RescheduleEvent(EVENT_LIGHTNING_BOLT, 5000);
                            break;
                    }
                case EVENT_QUICK_FLAME_WARD:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_VERZAUBERER_H:
                            DoCast(me, SPELL_QUICK_FLAME_WARD);
                            events.RescheduleEvent(EVENT_QUICK_FLAME_WARD, 10000);
                            break;
                    }
                case EVENT_MORTAL_STRIKE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_1_A:
                        case TW_NPC_QUESTGEBER_1_H:
                        case TW_NPC_QUESTGEBER_2_A:
                        case TW_NPC_QUESTGEBER_2_H:
                        case TW_NPC_QUESTGEBER_3_A:
                        case TW_NPC_QUESTGEBER_3_H:
                        case TW_NPC_QUESTGEBER_4_A:
                        case TW_NPC_QUESTGEBER_4_H:
                            DoCastVictim(SPELL_MORTAL_STRIKE);
                            events.RescheduleEvent(EVENT_MORTAL_STRIKE, 10000);
                            break;
                    }
                case EVENT_HEAL:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_A:
                            if (HealthBelowPct(50))
                                DoCast(me, SPELL_HEAL);
                            events.RescheduleEvent(EVENT_HEAL, 5000);
                            break;
                    }
                case EVENT_HOLY_NOVA:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_A:
                            DoCast(me, SPELL_HOLY_NOVA);
                            events.RescheduleEvent(EVENT_HOLY_NOVA, 8000);
                            break;
                    }
                case EVENT_CLEAVE:
                    switch(me->GetEntry())
                    {
                        case TW_NPC_QUESTGEBER_5_H:
                        case TW_NPC_QUESTGEBER_6_A:
                        case TW_NPC_QUESTGEBER_6_H:
                            DoCastVictim(SPELL_CLEAVE);
                            events.RescheduleEvent(EVENT_CLEAVE, 10000);
                            break;
                    }
            }
            DoMeleeAttackIfReady();
        }

private:
        EventMap events;
        EventMap eventsOOC;
        Tausendwinter * pTW;
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_tausendwinter_diverseAI (pCreature);
    }
};

class npc_tausendwinter_vehicle : public CreatureScript
{
public:
    npc_tausendwinter_vehicle() : CreatureScript("npc_tausendwinter_vehicle") { }

    struct npc_tausendwinter_vehicleAI : public ScriptedAI
    {
        npc_tausendwinter_vehicleAI(Creature* pCr) : ScriptedAI(pCr)
        {
            if (pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER))
            {
                if (Creature * Ingi = GetClosestCreatureWithEntry(me, TW_NPC_VERWUESTERINGENIEUR_A, 20))
                    pTW->ErhoeheFahrzeuganzahlDerWerkstatt(Ingi->GetDBTableGUIDLow());
                else if (Creature * Ingi = GetClosestCreatureWithEntry(me, TW_NPC_VERWUESTERINGENIEUR_H, 20))
                    pTW->ErhoeheFahrzeuganzahlDerWerkstatt(Ingi->GetDBTableGUIDLow());
            }
            else
                sLog->outError("TAUSENDWINTER: Aktualisieren der Fahrzeuganzahl pro Werkstatt nicht möglich, da kein Zeiger auf TW zur Verfügung steht!");
        }

        EventMap events;
        Tausendwinter * pTW;

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_WASSERCHECK, 10000);
            events.ScheduleEvent(EVENT_TELEPORTCHECK, 10000);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (!pTW)
            {
                sLog->outError("TAUSENDWINTER: Aktualisieren der Fahrzeuganzahl pro Werkstatt nicht möglich, da kein Zeiger auf TW zur Verfügung steht!");
                return;
            }

            if (pTW->IstKampf())
                pTW->SenkeFahrzeuganzahlEinerWerkstatt();
        }

        void Teleportieren()
        {
            if (GameObject * pGO = GetClosestGameObjectWithEntry(me, TW_GO_TELEPORTER_FUER_FAHRZEUGE, float(TW_FAHRZEUG_TELEPORTER_RADIUS)))
            {
                if (pGO->GetPositionY() < float(TW_FAHRZEUG_TELEPORTERGRENZE_Y))
                {
                    me->ToUnit()->SetPosition(FahrzeugTeleportKoords[FTeleOst][FTeleX], FahrzeugTeleportKoords[FTeleOst][FTeleY], FahrzeugTeleportKoords[FTeleOst][FTeleZ], 0, true);
                    me->ToUnit()->Relocate(FahrzeugTeleportKoords[FTeleOst][FTeleX], FahrzeugTeleportKoords[FTeleOst][FTeleY], FahrzeugTeleportKoords[FTeleOst][FTeleZ]);
                    me->ToUnit()->SendMonsterMove(FahrzeugTeleportKoords[FTeleOst][FTeleX], FahrzeugTeleportKoords[FTeleOst][FTeleY], FahrzeugTeleportKoords[FTeleOst][FTeleZ], 0);
                }
                else
                {
                    me->ToUnit()->SetPosition(FahrzeugTeleportKoords[FTeleWest][FTeleX], FahrzeugTeleportKoords[FTeleWest][FTeleY], FahrzeugTeleportKoords[FTeleWest][FTeleZ], 0, true);
                    me->ToUnit()->Relocate(FahrzeugTeleportKoords[FTeleWest][FTeleX], FahrzeugTeleportKoords[FTeleWest][FTeleY], FahrzeugTeleportKoords[FTeleWest][FTeleZ]);
                    me->ToUnit()->SendMonsterMove(FahrzeugTeleportKoords[FTeleWest][FTeleX], FahrzeugTeleportKoords[FTeleWest][FTeleY], FahrzeugTeleportKoords[FTeleWest][FTeleZ], 0);
                }
                me->UpdateObjectVisibility();
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            events.Update(uiDiff);

            uint32 eventId = events.ExecuteEvent();
            switch(eventId)
            {
                case EVENT_WASSERCHECK:
                    if (!me->IsInWater())
                    {
                        if (me->HasAura(SPELL_WASSER_AUS_TAUSENDWINTER))
                            me->RemoveAurasDueToSpell(SPELL_WASSER_AUS_TAUSENDWINTER);

                        events.RescheduleEvent(EVENT_WASSERCHECK, 2000);
                    }
                    else
                    {
                        if (!me->HasAura(SPELL_WASSER_AUS_TAUSENDWINTER))
                            DoCast(me, SPELL_WASSER_AUS_TAUSENDWINTER, true);

                        events.RescheduleEvent(EVENT_WASSERCHECK, 1000);
                    }
                    break;

                case EVENT_TELEPORTCHECK:
                    Teleportieren();
                    events.RescheduleEvent(EVENT_TELEPORTCHECK, 5000);
                    break;
            }
        }
    };

    ScriptedAI* GetAI(Creature* pCr) const
    {
        return new npc_tausendwinter_vehicleAI (pCr);
    }

};

class go_tausendwinter_diverse : public GameObjectScript
{
public:
    go_tausendwinter_diverse() : GameObjectScript("go_tausendwinter_diverse") { }

    void OnDestroyed(Player * pPl, GameObject * me, uint32 /*eventId*/)
    {
        if (me && pPl)
        {
            switch(me->GetEntry())
            {
                case TW_GO_GOBLINWERKSTATT_FESTUNG_W:
                case TW_GO_GOBLINWERKSTATT_FESTUNG_O:
                case TW_GO_GOBLINWERKSTATT_TEMPEL:
                case TW_GO_GOBLINWERKSTATT_RING:
                case TW_GO_GOBLINWERKSTATT_WESTFUNK:
                case TW_GO_GOBLINWERKSTATT_OSTFUNK:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_WORKSHOP, 0);
                    break;

                case TW_GO_SCHATTENBLICKTURM:
                case TW_GO_WINTERSTURZTURM:
                case TW_GO_FLAMMENAUGENTURM:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_SOUTHERN_TOWER, 0);
                    if (Creature * Trigger = me->SummonTrigger(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+35.0f, 0, 40000))
                        Trigger->CastSpell(Trigger, SPELL_TURM_ZERSTOERT_EFFEKT, false);
                    {
                        AchievementEntry const * pAE = GetAchievementStore()->LookupEntry(TW_ERFOLG_DER_SCHIEFE_TURM_VON_TW);
                        if (!pAE)
                            sLog->outError("TAUSENDWINTER: Kann den Eintrag für den Erfolg %u nicht erstellen!", TW_ERFOLG_DER_SCHIEFE_TURM_VON_TW);
                        else
                            pPl->CompletedAchievement(pAE);
                    }
                    break;

                case TW_GO_FESTUNGSTURM_NW:
                case TW_GO_FESTUNGSTURM_SW:
                case TW_GO_FESTUNGSTURM_SO:
                case TW_GO_FESTUNGSTURM_NO:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_TOWER, 0);
                    if (Creature * Trigger = me->SummonTrigger(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+35.0f, 0, 40000))
                        Trigger->CastSpell(Trigger, SPELL_TURM_ZERSTOERT_EFFEKT, false);
                    {
                        AchievementEntry const * pAE = GetAchievementStore()->LookupEntry(TW_ERFOLG_DER_SCHIEFE_TURM_VON_TW);
                        if (!pAE)
                            sLog->outError("TAUSENDWINTER: Kann den Eintrag für den Erfolg %u nicht erstellen!", TW_ERFOLG_DER_SCHIEFE_TURM_VON_TW);
                        else
                            pPl->CompletedAchievement(pAE);
                    }
                    break;

                case TW_GO_FESTUNGSTOR:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_GATE, 0);
                    break;

                case TW_GO_TAUSENDWINTERWALL_1:
                case TW_GO_TAUSENDWINTERWALL_2:
                case TW_GO_TAUSENDWINTERWALL_3:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_WALL, 0);
                    break;

                case TW_GO_WALL_DER_TWFESTUNG_1:
                case TW_GO_WALL_DER_TWFESTUNG_2:
                case TW_GO_WALL_DER_TWFESTUNG_3:
                case TW_GO_WALL_DER_TWFESTUNG_4:
                case TW_GO_WALL_DER_TWFESTUNG_5:
                case TW_GO_WALL_DER_TWFESTUNG_6:
                case TW_GO_WALL_DER_TWFESTUNG_7:
                case TW_GO_WALL_DER_TWFESTUNG_8:
                case TW_GO_WALL_DER_TWFESTUNG_9:
                case TW_GO_WALL_DER_TWFESTUNG_10:
                case TW_GO_WALL_DER_TWFESTUNG_11:
                case TW_GO_WALL_DER_TWFESTUNG_12:
                case TW_GO_WALL_DER_TWFESTUNG_13:
                case TW_GO_WALL_DER_TWFESTUNG_14:
                case TW_GO_WALL_DER_TWFESTUNG_15:
                case TW_GO_WALL_DER_TWFESTUNG_16:
                case TW_GO_WALL_DER_TWFESTUNG_17:
                case TW_GO_WALL_DER_TWFESTUNG_18:
                case TW_GO_WALL_DER_TWFESTUNG_19:
                case TW_GO_WALL_DER_TWFESTUNG_20:
                    pPl->KilledMonsterCredit(TW_NPC_PVP_KILL_STRUCTURE, 0);
                    break;
            }
        }
    }
};

void AddSC_tausendwinter()
{
    new npc_verwuesteringenieur;
    new npc_tausendwinter_diverse;
    new npc_tausendwinter_vehicle;
    new go_tausendwinter_diverse;
}
