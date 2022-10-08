#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "ScriptedCreature.h"
#include "SceneHelper.h"

enum ScriptedTextJaina
{
    SAY_JAINA_GALAKRAS_INTRO_1  = 0,
    SAY_JAINA_GALAKRAS_INTRO_2  = 1,
    SAY_JAINA_GALAKRAS_INTRO_3  = 2,
    SAY_JAINA_GALAKRAS_INTRO_4  = 3,
    SAY_JAINA_GALAKRAS_SPELL    = 4,
};

enum ScriptedTextWrynn
{
    SAY_WRYNN_GALAKRAS_INTRO_1  = 0,
    SAY_WRYNN_GALAKRAS_INTRO_2  = 1,
    SAY_WRYNN_GALAKRAS_INTRO_3  = 2,
    SAY_WRYNN_GALAKRAS_INTRO_4  = 3,
    SAY_WRYNN_GALAKRAS_INTRO_5  = 4,
    SAY_WRYNN_GALAKRAS_INTRO_6  = 5,
    SAY_WRYNN_GALAKRAS_SPELL    = 6,
};

enum ScriptedTextLorthemar
{
    SAY_LORTHEMAR_GALAKRAS_INTRO_1  = 0,
    SAY_LORTHEMAR_GALAKRAS_INTRO_2  = 1,
    SAY_LORTHEMAR_GALAKRAS_INTRO_3  = 2,
    SAY_LORTHEMAR_GALAKRAS_INTRO_4  = 3,
    SAY_LORTHEMAR_GALAKRAS_INTRO_5  = 4,
    SAY_LORTHEMAR_GALAKRAS_INTRO_6  = 5,
    SAY_LORTHEMAR_GALAKRAS_INTRO_7  = 6,
    SAY_LORTHEMAR_GALAKRAS_INTRO_8  = 7,
};

enum ScriptedTextSylvanas
{
    SAY_SYLVANAS_GALAKRAS_INTRO_1   = 0,
    SAY_SYLVANAS_GALAKRAS_INTRO_2   = 1,
    SAY_SYLVANAS_GALAKRAS_INTRO_3   = 2,
    SAY_SYLVANAS_GALAKRAS_INTRO_4   = 3,
    SAY_SYLVANAS_GALAKRAS_INTRO_5   = 4,
    SAY_SYLVANAS_GALAKRAS_INTRO_6   = 5,
    SAY_SYLVANAS_GALAKRAS_INTRO_7   = 6,
    SAY_SYLVANAS_GALAKRAS_INTRO_8   = 7,
};

enum ScriptedTextVoljin
{
    SAY_VOLJIN_EVENT_1  = 0,
    SAY_VOLJIN_EVENT_2  = 1,
    SAY_VOLJIN_INTRO_1  = 2,
    SAY_VOLJIN_INTRO_2  = 3,
    SAY_VOLJIN_INTRO_3  = 4,
};

enum ScriptedTextBaine
{
    SAY_BAINE_EVENT_1   = 0,
    SAY_BAINE_INTRO_1   = 1,
    SAY_BAINE_INTRO_2   = 2,
    SAY_BAINE_INTRO_3   = 3,
};

enum ScriptedTextAysa
{
    SAY_AYSA_EVENT_1    = 0,
    SAY_AYSA_EVENT_2    = 1,
    SAY_AYSA_EVENT_3    = 2,
    SAY_AYSA_EVENT_4    = 3,
    SAY_AYSA_EVENT_5    = 4,
    SAY_AYSA_EVENT_6    = 5,
    SAY_AYSA_EVENT_7    = 6,

    SAY_KOMAK_EVENT_1   = 0,
    SAY_KOMAK_EVENT_2   = 1,
    SAY_KOMAK_EVENT_3   = 2,
};

enum Spells
{
    // Dragonmaw Bonecrusher
    SPELL_FRACTURE_AOE              = 147201,
    SPELL_FRACTURE_STUN             = 147200,
    SPELL_FRACTURE_CHANNEL          = 147202,
    SPELL_FRACTURE_DMG              = 147203,
    SPELL_SHATTERING_ROAR           = 146897,

    // Dragonmaw Tidal Shaman
    SPELL_CHAIN_HEAL                = 146728,
    SPELL_HEALING_TIDE_TOTEM        = 146722,
    SPELL_HEALING_TIDE_AURA         = 146725,
    SPELL_HEALING_TIDE_HEAL         = 146726,
    SPELL_TIDAL_WAVE_AOE            = 149187,
    SPELL_TIDAL_WAVE_DUMMY          = 148519,
    SPELL_TIDAL_WAVE_DMG            = 149188,

    // Dragonmaw Elite Grunt
    SPELL_THROW_AXE                 = 147669,

    // Dragonmaw Flagbearer
    SPELL_DRAGONMAW_FLAGBEARER      = 145232,

    // Kor'kron Cannon
    SPELL_SPIKE_MINE_DETONATION     = 145752,

    // Blind Blademaster
    SPELL_BLIND_CLEAVE              = 141192,
    SPELL_WANDER                    = 141191,
    SPELL_BLIND_STRIKE              = 141189,
    SPELL_CLEAVE_TRIGGER            = 141197,
    SPELL_CHARGE                    = 141193,
    SPELL_CHARGE_AURA               = 141202,
    SPELL_CHARGE_AURA_TRIGGER       = 141198,
    SPELL_SWIFT_STRIKE              = 141199, // while charge
    SPELL_SWIFT_STRIKE_2            = 141190, // while blind strike
};

enum Events
{
    // Dragonmaw Bonecrusher
    EVENT_FRACTURE = 1,
    EVENT_SHATTERING_ROAR,

    // Dragonmaw Tidal Shaman
    EVENT_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,
    EVENT_TIDAL_WAVE,

    // Dragonmaw Elite Grunt
    EVENT_THROW_AXE,

    // Blind Blademaster
    EVENT_BLIND_CLEAVE,
    EVENT_SWIFT_STRIKE,
};

enum Adds
{
    // Before Galakras
    NPC_DRAGONMAW_BONECRUSHER           = 72354,
    NPC_DRAGONMAW_CANNONEER             = 72365,
    NPC_DRAGONMAW_TIDAL_SHAMAN          = 72367,
    NPC_HEALING_TIDE_TOTEM              = 73086,
    NPC_DRAGONMAW_ELITE_GRUNT           = 72350,
    NPC_DRAGONMAW_FLAGBEARER            = 72351,
    NPC_KORKRON_CANNON                  = 72358,
    NPC_SPIKE_MINE                      = 72656,

    // After Galakras, before Iron Juggernaut
    NPC_DARK_SPEAR_WARRIOR_1            = 73908,
    NPC_DARK_SPEAR_WARRIOR_2            = 73855, // attacks the juggernaut
    NPC_DARK_SPEAR_RECRUIT              = 73936, // moving near sentries 1
    NPC_DARK_SPEAR_SENTRY_1             = 73871, // rides
    NPC_DARK_SPEAR_SENTRY_2             = 73874, // don't rides
    NPC_DARK_SPEAR_MARKSMAN             = 73900,
    NPC_DARK_SPEAR_BATTLEDRUMMER        = 73858,
    NPC_DARK_SPEAR_EMERGENCY_MEDIC      = 73850,
    NPC_DARK_SPEAR_ENGINEER             = 73860,

    // Before Kor'kron Dark Shaman
    NPC_KORKRON_DARK_SHAMAN             = 72451,
    NPC_KORKRON_OVERSEER                = 72421,
    NPC_OGRRIMMAR_PEON                  = 72427,
    NPC_KORKRON_SHADOWMAGE              = 72150,
    NPC_KORKRON_GRUNT                   = 72412,
    NPC_DIRE_WOLF                       = 72452,
    NPC_KORKRON_PROVISIONER             = 72411,
    NPC_TREASURY_GUARD                  = 72434,
};

enum Actions
{
    ACTION_AYSA_START_INTRO = 1,
    ACTION_AYSA_START_EVENT,
    ACTION_AYSA_KOMAK_DIED,
};

Position galakrasNpcPos2[4] =
{
    { 1360.96f, -5404.39f, 10.32f, 1.75f}, // jaina moves at the ship
    { 1360.96f, -5404.39f, 10.32f, 4.89f}, // jaina's orientation

    { 1431.70f, -4898.23f, 11.34f, 1.75f}, // jaina/lor'themar position after intro
    { 1421.77f, -4901.12f, 11.36f, 1.76f}  // wrynn/sylvanas position after intro
};

Position voljinIronJuggernautPos[3] =
{
    {1234.65f, -4402.92f, 25.94f, 0.08f},
    {1250.27f, -4401.60f, 26.04f, 0.08f},
    {1331.09f, -4382.75f, 26.04f, 0.24f}
};

Position baineBloodHoofIronJuggernautPos[3] =
{
    {1234.53f, -4407.77f, 25.64f, 0.06f},
    {1251.90f, -4406.57f, 26.03f, 0.06f},
    {1337.32f, -4388.00f, 26.13f, 0.22f}
};

Position aysaPos[3] =
{
    { 1485.46f, -4412.06f, 25.35f, 0.05f }, // first position
    { 1493.71f, -4411.01f, 23.93f, 0.08f }, // position after intro
    { 1541.17f, -4404.84f, 18.47f, 0.10f }  // position near Ji
};

class npc_siege_of_orgrimmar_jaina_proudmoore_2 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_jaina_proudmoore_2() : CreatureScript("npc_siege_of_orgrimmar_jaina_proudmoore_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_jaina_proudmoore_2AI(creature);
        }

        struct npc_siege_of_orgrimmar_jaina_proudmoore_2AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_jaina_proudmoore_2AI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
                secondGalakrasIntroDone = false;
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FIRST_INTRO_GALAKRAS)
                {
                    ProcessFirstGalakrasIntro();
                }
                else if (action == ACTION_SECOND_INTRO_GALAKRAS)
                {
                    ProcessSecondGalakrasIntro();
                }
                else if (action == ACTION_START_GALAKRAS)
                {
                    ProcessStartGalakras();
                }
                else if (action == ACTION_RESET_GALAKRAS)
                {
                    ProcessResetGalakras();
                }
            }

            void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                player->PlayerTalkClass->SendCloseGossip();

                if (!secondGalakrasIntroDone)
                    return;

                if (player->IsInCombat())
                    return;

                if (gossipListId != 0)
                    return;

                SendStartGalakras();

                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void ProcessFirstGalakrasIntro()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_JAINA_GALAKRAS_INTRO_1, 5000);
                m_SceneHelper.AddSceneActionTalk(SAY_JAINA_GALAKRAS_INTRO_2, 10000);
                m_SceneHelper.AddSceneActionMovePos(galakrasNpcPos2[0], 10000);
                m_SceneHelper.AddSceneActionMovePos(galakrasNpcPos2[1], 4000);
                m_SceneHelper.AddSceneCast(SPELL_MINOR_PORTAL, 1000);

                m_SceneHelper.Activate();
            }

            void ProcessSecondGalakrasIntro()
            {
                if (secondGalakrasIntroDone)
                    return;

                me->CastStop();

                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                me->NearTeleportTo(galakrasNpcPos2[2]);

                secondGalakrasIntroDone = true;
            }

            void SendStartGalakras()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_START_GALAKRAS, DONE);
                }
            }

            void ProcessStartGalakras()
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));

                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_JAINA_GALAKRAS_INTRO_3, 6000);
                m_SceneHelper.AddSceneActionTalk(SAY_JAINA_GALAKRAS_INTRO_4, 15000);

                m_SceneHelper.Activate();
            }

            void ProcessResetGalakras()
            {
                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
            bool secondGalakrasIntroDone;
        };
};

class npc_siege_of_orgrimmar_king_varian_wrynn_2 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_king_varian_wrynn_2() : CreatureScript("npc_siege_of_orgrimmar_king_varian_wrynn_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_king_varian_wrynn_2AI(creature);
        }

        struct npc_siege_of_orgrimmar_king_varian_wrynn_2AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_king_varian_wrynn_2AI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();

                secondGalakrasIntroDone = false;
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FIRST_INTRO_GALAKRAS)
                {
                    ProcessFirstGalakrasIntro();
                }
                else if (action == ACTION_SECOND_INTRO_GALAKRAS)
                {
                    ProcessSecondGalakrasIntro();
                }
                else if (action == ACTION_START_GALAKRAS)
                {
                    ProcessStartGalakras();
                }
                else if (action == ACTION_RESET_GALAKRAS)
                {
                    ProcessResetGalakras();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void ProcessFirstGalakrasIntro()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_1, 8000);
                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_2, 13000);

                m_SceneHelper.Activate();
            }

            void ProcessSecondGalakrasIntro()
            {
                if (secondGalakrasIntroDone)
                    return;

                me->NearTeleportTo(galakrasNpcPos2[3]);

                secondGalakrasIntroDone = true;
            }

            void ProcessStartGalakras()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_3, 1000);
                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_4, 9000);
                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_5, 16000);
                m_SceneHelper.AddSceneActionTalk(SAY_WRYNN_GALAKRAS_INTRO_6, 6000);

                m_SceneHelper.Activate();
            }

            void ProcessResetGalakras()
            {

            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
            bool secondGalakrasIntroDone;
        };
};

class npc_siege_of_orgrimmar_lorthemar_theron_2 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_lorthemar_theron_2() : CreatureScript("npc_siege_of_orgrimmar_lorthemar_theron_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_lorthemar_theron_2AI(creature);
        }

        struct npc_siege_of_orgrimmar_lorthemar_theron_2AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_lorthemar_theron_2AI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
                secondGalakrasIntroDone = false;
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FIRST_INTRO_GALAKRAS)
                {
                    ProcessFirstGalakrasIntro();
                }
                else if (action == ACTION_SECOND_INTRO_GALAKRAS)
                {
                    ProcessSecondGalakrasIntro();
                }
                else if (action == ACTION_START_GALAKRAS)
                {
                    ProcessStartGalakras();
                }
                else if (action == ACTION_RESET_GALAKRAS)
                {
                    ProcessResetGalakras();
                }
            }

            void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                player->PlayerTalkClass->SendCloseGossip();

                if (!secondGalakrasIntroDone)
                    return;

                if (player->IsInCombat())
                    return;

                if (gossipListId != 0)
                    return;

                SendStartGalakras();

                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void ProcessFirstGalakrasIntro()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_1, 8000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_2, 5000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_3, 11000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_4, 12000);

                m_SceneHelper.Activate();
            }

            void ProcessSecondGalakrasIntro()
            {
                if (secondGalakrasIntroDone)
                    return;

                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                me->NearTeleportTo(galakrasNpcPos2[2]);

                secondGalakrasIntroDone = true;
            }

            void SendStartGalakras()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_START_GALAKRAS, DONE);
                }
            }

            void ProcessStartGalakras()
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));

                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_5, 1000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_6, 15000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_7, 7000);
                m_SceneHelper.AddSceneActionTalk(SAY_LORTHEMAR_GALAKRAS_INTRO_8, 6000);

                m_SceneHelper.Activate();
            }

            void ProcessResetGalakras()
            {
                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
            bool secondGalakrasIntroDone;
        };
};

class npc_siege_of_orgrimmar_sylvanas_windrunner_2 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_sylvanas_windrunner_2() : CreatureScript("npc_siege_of_orgrimmar_sylvanas_windrunner_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_sylvanas_windrunner_2AI(creature);
        }

        struct npc_siege_of_orgrimmar_sylvanas_windrunner_2AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_sylvanas_windrunner_2AI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
                secondGalakrasIntroDone = false;
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FIRST_INTRO_GALAKRAS)
                {
                    ProcessFirstGalakrasIntro();
                }
                else if (action == ACTION_SECOND_INTRO_GALAKRAS)
                {
                    ProcessSecondGalakrasIntro();
                }
                else if (action == ACTION_START_GALAKRAS)
                {
                    ProcessStartGalakras();
                }
                else if (action == ACTION_RESET_GALAKRAS)
                {
                    ProcessResetGalakras();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void ProcessFirstGalakrasIntro()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_1, 18000);
                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_2, 12000);
                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_3, 12000);
                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_7, 8000);

                m_SceneHelper.Activate();
            }

            void ProcessSecondGalakrasIntro()
            {
                if (secondGalakrasIntroDone)
                    return;

                me->NearTeleportTo(galakrasNpcPos2[3]);

                secondGalakrasIntroDone = true;
            }

            void ProcessStartGalakras()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_4, 4000);
                m_SceneHelper.AddSceneActionTalk(SAY_SYLVANAS_GALAKRAS_INTRO_5, 6000);

                m_SceneHelper.Activate();
            }

            void ProcessResetGalakras()
            {

            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
            bool secondGalakrasIntroDone;
        };
};

class npc_siege_of_orgrimmar_aethas_sunreaver : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_aethas_sunreaver() : CreatureScript("npc_siege_of_orgrimmar_aethas_sunreaver") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_aethas_sunreaverAI(creature);
        }

        struct npc_siege_of_orgrimmar_aethas_sunreaverAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_aethas_sunreaverAI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_FIRST_INTRO_GALAKRAS)
                {
                    m_SceneHelper.Clear();

                    m_SceneHelper.AddSceneCast(SPELL_MINOR_PORTAL, 8000);

                    m_SceneHelper.Activate();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
        };
};

class npc_siege_of_orgrimmar_dragonmaw_bonecrusher : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_dragonmaw_bonecrusher() : CreatureScript("npc_siege_of_orgrimmar_dragonmaw_bonecrusher") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_dragonmaw_bonecrusherAI(creature);
        }

        struct npc_siege_of_orgrimmar_dragonmaw_bonecrusherAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_dragonmaw_bonecrusherAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_FRACTURE, urand(8000, 12000));
                events.ScheduleEvent(EVENT_SHATTERING_ROAR, urand(2000, 4000));
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FRACTURE:
                            DoCastAOE(SPELL_FRACTURE_AOE);
                            events.ScheduleEvent(EVENT_FRACTURE, urand(25000, 30000));
                            break;
                        case EVENT_SHATTERING_ROAR:
                            DoCastAOE(SPELL_SHATTERING_ROAR);
                            events.ScheduleEvent(EVENT_SHATTERING_ROAR, urand(12000, 20000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_dragonmaw_tidal_shaman : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_dragonmaw_tidal_shaman() : CreatureScript("npc_siege_of_orgrimmar_dragonmaw_tidal_shaman") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_dragonmaw_tidal_shamanAI(creature);
        }

        struct npc_siege_of_orgrimmar_dragonmaw_tidal_shamanAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_dragonmaw_tidal_shamanAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_CHAIN_HEAL, urand(5000, 12000));
                events.ScheduleEvent(EVENT_HEALING_TIDE_TOTEM, urand(10000, 20000));
                events.ScheduleEvent(EVENT_TIDAL_WAVE, 1000);
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIDAL_WAVE:
                            DoCastAOE(SPELL_TIDAL_WAVE_AOE);
                            events.ScheduleEvent(EVENT_TIDAL_WAVE, 2000);
                            break;
                        case EVENT_HEALING_TIDE_TOTEM:
                            DoCast(me, SPELL_HEALING_TIDE_TOTEM);
                            events.ScheduleEvent(EVENT_HEALING_TIDE_TOTEM, urand(25000, 35000));
                            break;
                        case EVENT_CHAIN_HEAL:
                            DoCast(me, SPELL_CHAIN_HEAL);
                            events.ScheduleEvent(EVENT_CHAIN_HEAL, urand(10000, 15000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_healing_tide_totem : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_healing_tide_totem() : CreatureScript("npc_siege_of_orgrimmar_healing_tide_totem") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_healing_tide_totemAI(creature);
        }

        struct npc_siege_of_orgrimmar_healing_tide_totemAI : public Scripted_NoMovementAI
        {
            npc_siege_of_orgrimmar_healing_tide_totemAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->AddAura(SPELL_HEALING_TIDE_AURA, me);
            }

            void UpdateAI(const uint32 diff) override
            {

            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_dragonmaw_elite_grunt : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_dragonmaw_elite_grunt() : CreatureScript("npc_siege_of_orgrimmar_dragonmaw_elite_grunt") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_dragonmaw_elite_gruntAI(creature);
        }

        struct npc_siege_of_orgrimmar_dragonmaw_elite_gruntAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_dragonmaw_elite_gruntAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_THROW_AXE, 1000);
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_THROW_AXE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true))
                            {
                                DoCast(target, SPELL_THROW_AXE);
                            }
                            events.ScheduleEvent(EVENT_THROW_AXE, urand(7000, 12000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_dragonmaw_flagbearer : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_dragonmaw_flagbearer() : CreatureScript("npc_siege_of_orgrimmar_dragonmaw_flagbearer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_dragonmaw_flagbearerAI(creature);
        }

        struct npc_siege_of_orgrimmar_dragonmaw_flagbearerAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_dragonmaw_flagbearerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->AddAura(SPELL_DRAGONMAW_FLAGBEARER, me);
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korkron_cannon : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_korkron_cannon() : CreatureScript("npc_siege_of_orgrimmar_korkron_cannon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_cannonAI(creature);
        }

        // prevent menu
        bool OnGossipHello(Player* player, Creature* creature) override
        {
            return true;
        }

        struct npc_siege_of_orgrimmar_korkron_cannonAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_cannonAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();

                isMineActivated = false;
            }

            void Reset()
            {
                me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
            }

            void sGossipHello(Player* player) override
            {
                if (player->IsInCombat())
                    return;

                if (isMineActivated)
                    return;

                if (Creature* pMine = me->SummonCreature(NPC_SPIKE_MINE, *me, TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    pMine->CastSpell(pMine, SPELL_SPIKE_MINE_DETONATION, false);
                }

                SendCannonDestroyed();

                //me->DespawnOrUnsummon(6000);
                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));

                isMineActivated = true;
            }

        private:

            void SendCannonDestroyed()
            {
                if (pInstance)
                {
                    pInstance->SetData(DATA_KORKRON_CANNON_DESTROYED, DONE);
                }
            }

        private:

            InstanceScript* pInstance;
            bool isMineActivated;
        };
};

class go_siege_of_orgrimmar_minor_portal : public GameObjectScript
{
    public:
        go_siege_of_orgrimmar_minor_portal() : GameObjectScript("go_siege_of_orgrimmar_minor_portal") { }

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_siege_of_orgrimmar_minor_portalAI(go);
        }

        struct go_siege_of_orgrimmar_minor_portalAI : public GameObjectAI
        {
            go_siege_of_orgrimmar_minor_portalAI(GameObject* go) : GameObjectAI(go)
            {

            }

            // all summoned gameobjects with spellid despawns after using
            // use this function to prevent despawn
            bool GossipHello(Player* player, bool /*reportUse*/) override
            {
                player->CastSpell(player, SPELL_MINOR_PORTAL_TELEPORT_PLAYER, true);

                return true;
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_voljin_1 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_voljin_1() : CreatureScript("npc_siege_of_orgrimmar_voljin_1") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_voljin_1AI(creature);
        }

        struct npc_siege_of_orgrimmar_voljin_1AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_voljin_1AI(Creature* creature) : ScriptedAI(creature),
                m_IsFirstStartDone(false), m_IsIntroDone(false), m_SceneHelper(creature->GetGUID(), creature->GetMap())
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_IRON_JUGGERNAUT_INTRO)
                {
                    ProcessIronJuggernautIntro();
                }
                else if (action == ACTION_IRON_JUGGERNAUT_START)
                {
                    ProcessIronJuggernautStart();
                }
                else if (action == ACTION_IRON_JUGGERNAUT_DEAD)
                {
                    ProcessIronJuggernautDead();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                m_SceneHelper.UpdateSceneHelper(diff);
            }

        private:

            void ProcessIronJuggernautIntro()
            {
                if (m_IsIntroDone)
                    return;

                m_IsIntroDone = true;

                if (!pInstance || pInstance->GetBossState(DATA_IRON_JUGGERNAUT) != NOT_STARTED)
                    return;

                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_VOLJIN_INTRO_1, 15000);
                m_SceneHelper.AddSceneActionTalk(SAY_VOLJIN_INTRO_2, 31000);

                m_SceneHelper.Activate();
            }

            void ProcessIronJuggernautStart()
            {
                if (m_IsFirstStartDone)
                    return;

                m_IsFirstStartDone = true;

                std::vector<Position> moves;
                moves.push_back(voljinIronJuggernautPos[0]);
                moves.push_back(voljinIronJuggernautPos[1]);

                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_VOLJIN_EVENT_1, 100);

                //move to wp
                //m_SceneHelper.AddSceneActionMove(moves, false, 100);

                m_SceneHelper.Activate();

            }

            void ProcessIronJuggernautDead()
            {
                m_SceneHelper.Clear();

                m_SceneHelper.AddSceneActionTalk(SAY_VOLJIN_EVENT_2, 100);
                m_SceneHelper.AddSceneActionMovePos(voljinIronJuggernautPos[2], 100);

                m_SceneHelper.Activate();
            }

        private:

            InstanceScript* pInstance;
            SceneHelper m_SceneHelper;
            bool m_IsFirstStartDone;
            bool m_IsIntroDone;
        };
};

/*class npc_siege_of_orgrimmar_baine_bloodhoof_1 : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_baine_bloodhoof_1() : CreatureScript("npc_siege_of_orgrimmar_baine_bloodhoof_1") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_baine_bloodhoof_1AI(creature);
        }

        struct npc_siege_of_orgrimmar_baine_bloodhoof_1AI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_baine_bloodhoof_1AI(Creature* creature) : ScriptedAI(creature),
                sceneHelper(creature->GetGUID(), creature->GetMap()),
                m_IsFirstStartDone(false), m_IsIntroDone(false)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                SetCanSeeEvenInPassiveMode(true);

                pInstance = creature->GetInstanceScript();
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (m_IsIntroDone)
                    return;

                if (who->IsPlayer())
                {
                    if (me->GetDistance(who) <= 100.0f)
                    {
                        DoAction(ACTION_IRON_JUGGERNAUT_INTRO);
                    }
                }
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_IRON_JUGGERNAUT_INTRO)
                {
                    ProcessIronJuggernautIntro();
                }
                else if (action == ACTION_IRON_JUGGERNAUT_START)
                {
                    ProcessIronJuggernautStart();
                }
                else if (action == ACTION_IRON_JUGGERNAUT_DEAD)
                {
                    ProcessIronJuggernautDead();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                sceneHelper.Update(diff);
            }

        private:

            void ProcessIronJuggernautIntro()
            {
                if (m_IsIntroDone)
                    return;

                m_IsIntroDone = true;

                if (!pInstance || pInstance->GetBossState(DATA_IRON_JUGGERNAUT) != NOT_STARTED)
                    return;

                if (Creature* pVoljin = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_VOLJIN_1)))
                {
                    pVoljin->AI()->DoAction(ACTION_IRON_JUGGERNAUT_INTRO);
                }

                //sceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_1, 1000);
                //sceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_2, 25000);
                //sceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_3, 38000);
            }

            void ProcessIronJuggernautStart()
            {
                if (m_IsFirstStartDone)
                    return;

                m_IsFirstStartDone = true;

                std::vector<Position> moves;
                moves.push_back(baineBloodHoofIronJuggernautPos[0]);
                moves.push_back(baineBloodHoofIronJuggernautPos[1]);

                // move wp to db
                //m_SceneHelper.AddSceneActionMove(moves, false, 100);
                //sceneHelper.AddSceneActionTalk(SAY_BAINE_EVENT_1, 4000);

            }

            void ProcessIronJuggernautDead()
            {
                //m_SceneHelper.AddSceneActionMove(baineBloodHoofIronJuggernautPos[2], false, 100);
            }

        private:

            InstanceScript* pInstance;
            bool m_IsFirstStartDone;
            bool m_IsIntroDone;
            SceneHelper sceneHelper;
        };
};*/

class npc_siege_of_orgrimmar_baine_bloodhoof_1 : public CreatureScript
{
public:
    npc_siege_of_orgrimmar_baine_bloodhoof_1() : CreatureScript("npc_siege_of_orgrimmar_baine_bloodhoof_1") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_siege_of_orgrimmar_baine_bloodhoof_1AI(creature);
    }

    struct npc_siege_of_orgrimmar_baine_bloodhoof_1AI : public ScriptedAI
    {
        npc_siege_of_orgrimmar_baine_bloodhoof_1AI(Creature* creature) : ScriptedAI(creature),
            m_SceneHelper(creature->GetGUID(), creature->GetMap()),
            m_IsFirstStartDone(false), m_IsIntroDone(false)
        {
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
            SetCanSeeEvenInPassiveMode(true);

            pInstance = creature->GetInstanceScript();

        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (m_IsIntroDone)
                return;

            if (who->IsPlayer())
            {
                if (me->GetDistance(who) <= 100.0f)
                {
                    DoAction(ACTION_IRON_JUGGERNAUT_INTRO);
                }
            }

            m_IsIntroDone = true;

            m_SceneHelper.Clear();

            Talk(0);
            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_1, 1000);
            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_2, 25000);
            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_3, 38000);

            m_SceneHelper.Activate();
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_IRON_JUGGERNAUT_INTRO)
            {
                ProcessIronJuggernautIntro();
            }
            else if (action == ACTION_IRON_JUGGERNAUT_START)
            {
                ProcessIronJuggernautStart();
            }
            else if (action == ACTION_IRON_JUGGERNAUT_DEAD)
            {
                ProcessIronJuggernautDead();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_SceneHelper.UpdateSceneHelper(diff);
        }

    private:

        void ProcessIronJuggernautIntro()
        {
            if (m_IsIntroDone)
                return;

            m_IsIntroDone = true;

            if (!pInstance || pInstance->GetBossState(DATA_IRON_JUGGERNAUT) != NOT_STARTED)
                return;

            if (Creature* pVoljin = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_VOLJIN_1)))
            {
                pVoljin->AI()->DoAction(ACTION_IRON_JUGGERNAUT_INTRO);
            }

            m_SceneHelper.Clear();

            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_1, 1000);
            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_2, 25000);
            m_SceneHelper.AddSceneActionTalk(SAY_BAINE_INTRO_3, 38000);

            m_SceneHelper.Activate();
        }

        void ProcessIronJuggernautStart()
        {
            if (m_IsFirstStartDone)
                return;

            m_IsFirstStartDone = true;

            m_SceneHelper.Clear();

            std::vector<Position> moves;
            moves.push_back(baineBloodHoofIronJuggernautPos[0]);
            moves.push_back(baineBloodHoofIronJuggernautPos[1]);

            //m_SceneHelper.AddSceneActionMove(moves, false, 100);
            //m_SceneHelper.AddSceneActionTalk(SAY_BAINE_EVENT_1, 4000);

            m_SceneHelper.Activate();
        }

        void ProcessIronJuggernautDead()
        {
            m_SceneHelper.Clear();

            //m_SceneHelper.AddSceneActionMove(baineBloodHoofIronJuggernautPos[2], false, 100);

            m_SceneHelper.Activate();
        }

    private:

        InstanceScript* pInstance;
        SceneHelper m_SceneHelper;
        bool m_IsFirstStartDone;
        bool m_IsIntroDone;
    };
};

/*class npc_siege_of_orgrimmar_baine_bloodhoof_1 : public CreatureScript
{
public:
    npc_siege_of_orgrimmar_baine_bloodhoof_1() : CreatureScript("npc_siege_of_orgrimmar_baine_bloodhoof_1") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_siege_of_orgrimmar_baine_bloodhoof_1AI(creature);
    }

    struct npc_siege_of_orgrimmar_baine_bloodhoof_1AI : public ScriptedAI
    {
        npc_siege_of_orgrimmar_baine_bloodhoof_1AI(Creature* creature) : ScriptedAI(creature), m_SceneHelper(creature->GetGUID(), creature->GetMap())
        {}

        void testtestestsetestestsetwestsetsetsetsetset(uint32 diff)
        {

        }

        void UpdateAI(uint32 diff) override
        {
            //m_SceneHelper.UpdateSceneHelper(diff);
            ptr->UpdateSceneHelper(diff);
            ptr->AddSceneActionTalk(5, 5);
            ptr->Clear();
        }

    private:
        SceneHelper m_SceneHelper;
        SceneHelper* ptr = &m_SceneHelper;
    };
};*/

class npc_siege_of_orgrimmar_blind_blademaster : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_blind_blademaster() : CreatureScript("npc_siege_of_orgrimmar_blind_blademaster") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_blind_blademasterAI(creature);
        }

        struct npc_siege_of_orgrimmar_blind_blademasterAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_blind_blademasterAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_BLIND_CLEAVE, urand(8000, 15000));
                events.ScheduleEvent(EVENT_SWIFT_STRIKE, urand(1000, 3000));

                SendAysaStart();
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLIND_CLEAVE:
                            DoCastAOE(SPELL_BLIND_CLEAVE);
                            events.ScheduleEvent(EVENT_BLIND_CLEAVE, urand(15000, 25000));
                            break;
                        case EVENT_SWIFT_STRIKE:
                            DoCastVictim(SPELL_SWIFT_STRIKE);
                            events.ScheduleEvent(EVENT_SWIFT_STRIKE, urand(2000, 4000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            void SendAysaStart()
            {
                if (Creature* pAysa = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, 20.f))
                {
                    pAysa->AI()->DoAction(ACTION_AYSA_START_INTRO);
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class AysaEventHelper
{
    private:

        enum LocalEvents
        {
            EVENT_AYSA_INTRO    = 1,
            EVENT_AYSA_TALK_1,
            EVENT_AYSA_TALK_2,

            EVENT_KOMAK_TALK_1,
            EVENT_KOMAK_TALK_2,

            EVENT_KILL_JI_TALK,
            EVENT_KILL_JI_KILL,
            EVENT_KILL_JI_AYSA,

            EVENT_AYSA_TALK_3,
            EVENT_AYSA_TALK_4,
        };

        enum LocalPhases
        {
            PHASE_NONE,         // before intro and event
            PHASE_INTRO,        // intro is done, event is not started
            PHASE_EVENT,        // event is in progress
            PHASE_JI_KILLED,    // event is done, Ji is killed
            PHASE_KOMAK_KILLED, // event is done, Komak is killed
            PHASE_EVENT_DONE,   // all is done
        };

    public:

        explicit AysaEventHelper(Creature* owner) :
            m_Owner(owner), pInstance(owner->GetInstanceScript()),
            m_AysaGuid(ObjectGuid::Empty), m_JiGuid(ObjectGuid::Empty), m_KomakGuid(ObjectGuid::Empty),
            m_Phase(PHASE_NONE), m_UpdateKillTimer(1000)
        { }

        void Initialize()
        {
            ASSERT(pInstance);

            m_AysaGuid = pInstance->GetObjectGuid(DATA_AYSA_CLOUDSINGER);
            m_JiGuid = pInstance->GetObjectGuid(DATA_JI_FIREPAW);
            m_KomakGuid = pInstance->GetObjectGuid(DATA_OVERSEER_KOMAK);

            m_Events.Reset();
        }

        void StartIntro()
        {
            if (m_Phase != PHASE_NONE)
                return;

            m_Phase = PHASE_INTRO;

            m_Events.ScheduleEvent(EVENT_AYSA_INTRO, 1000);
        }

        void StartEvent()
        {
            if (m_Phase != PHASE_INTRO)
                return;

            m_Phase = PHASE_EVENT;

            m_Events.ScheduleEvent(EVENT_KOMAK_TALK_1, 1000);
            m_Events.ScheduleEvent(EVENT_KILL_JI_TALK, 5 * MINUTE * IN_MILLISECONDS);
        }

        void EndEvent()
        {
            if (m_Phase != PHASE_EVENT)
                return;

            m_Phase = PHASE_KOMAK_KILLED;

            m_Events.CancelEvent(EVENT_KILL_JI_TALK);

            MoveAysaToJi();
        }

        void Update(const uint32 diff)
        {
            m_Events.Update(diff);

            UpdateKill(diff);

            if (uint32 eventId = m_Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AYSA_INTRO:
                        AysaMovesIntro();
                        break;
                    case EVENT_KOMAK_TALK_1:
                        if (Creature* pKomak = GetOverseerKomak())
                            pKomak->AI()->Talk(SAY_KOMAK_EVENT_1);
                        m_Events.ScheduleEvent(EVENT_KOMAK_TALK_2, 4000);
                        break;
                    case EVENT_KOMAK_TALK_2:
                        if (Creature* pKomak = GetOverseerKomak())
                            pKomak->AI()->Talk(SAY_KOMAK_EVENT_2);
                        m_Events.ScheduleEvent(EVENT_AYSA_TALK_1, 5000);
                        break;
                    case EVENT_AYSA_TALK_1:
                        if (Creature* pAysa = GetAysaCloudsinger())
                        {
                            pAysa->SetStandState(UNIT_STAND_STATE_STAND);
                            pAysa->AI()->Talk(SAY_AYSA_EVENT_2);
                        }
                        m_Events.ScheduleEvent(EVENT_AYSA_TALK_2, 5000);
                        break;
                    case EVENT_AYSA_TALK_2:
                        if (Creature* pAysa = GetAysaCloudsinger())
                            pAysa->AI()->Talk(SAY_AYSA_EVENT_3);
                        break;
                    case EVENT_KILL_JI_TALK:
                        KomakTalksBeforeKill();
                        break;
                    case EVENT_KILL_JI_KILL:
                        KomakKillsJi();
                        break;
                    case EVENT_KILL_JI_AYSA:
                        AysaAttacksKomak();
                        break;
                    case EVENT_AYSA_TALK_3:
                        if (Creature* pAysa = GetAysaCloudsinger())
                            pAysa->AI()->Talk(SAY_AYSA_EVENT_6);
                        m_Events.ScheduleEvent(EVENT_AYSA_TALK_4, 11000);
                        break;
                    case EVENT_AYSA_TALK_4:
                        if (Creature* pAysa = GetAysaCloudsinger())
                            pAysa->AI()->Talk(SAY_AYSA_EVENT_7);

                        // HACK:
                        // Aysa with Ji should move out of Orgrimmar together.
                        // Need Aysa's vehicleId to make it correctly.
                        if (Creature* pAysa = GetAysaCloudsinger())
                            pAysa->DespawnOrUnsummon(10000);
                        if (Creature* pJi = GetJiFirepaw())
                            pJi->DespawnOrUnsummon(10000);
                        break;
                }

            }
        }

    private:

        void AysaMovesIntro()
        {
            Creature* pAysa = GetAysaCloudsinger();
            if (!pAysa)
                return;

            pAysa->AI()->Talk(SAY_AYSA_EVENT_1);

            Movement::MoveSplineInit init(pAysa);
            for (uint8 i = 0; i < 2; ++i)
            {
                G3D::Vector3 point;
                point.x = aysaPos[i].GetPositionX();
                point.y = aysaPos[i].GetPositionY();
                point.z = aysaPos[i].GetPositionZ();
                init.Path().push_back(point);
            }

            init.SetWalk(false);
            init.Launch();
        }

        void KomakTalksBeforeKill()
        {
            if (m_Phase != PHASE_EVENT)
                return;

            Creature* pKomak = GetOverseerKomak();
            if (!pKomak || !pKomak->IsAlive())
                return;

            // Delay the event if Komak is in combat.
            if (pKomak->IsInCombat() || pKomak->IsInEvadeMode())
            {
                m_Events.ScheduleEvent(EVENT_KILL_JI_TALK, 5000);
                return;
            }

            m_Phase = PHASE_JI_KILLED;

            pKomak->AI()->Talk(SAY_KOMAK_EVENT_3);

            m_Events.ScheduleEvent(EVENT_KILL_JI_KILL, 1000);
            m_Events.ScheduleEvent(EVENT_KILL_JI_AYSA, 1000);
        }

        void KomakKillsJi()
        {
            Creature* pKomak = GetOverseerKomak();
            Creature* pJi = GetJiFirepaw();

            if (pKomak && pJi)
            {
                KillCreature(pKomak, pJi);
            }
        }

        void AysaAttacksKomak()
        {
            Creature* pKomak = GetOverseerKomak();
            Creature* pAysa = GetAysaCloudsinger();

            if (pKomak && pAysa)
            {
                pAysa->AI()->Talk(SAY_AYSA_EVENT_4);
                pAysa->GetMotionMaster()->MoveChase(pKomak);
            }
        }

        // Use this function to check creatures every second but not every update
        void UpdateKill(const uint32 diff)
        {
            if (m_Phase != PHASE_JI_KILLED)
                return;

            if (m_UpdateKillTimer <= diff)
            {
                m_UpdateKillTimer = 1000;

                if (KomakKillsAysa())
                {
                    m_Phase = PHASE_EVENT_DONE;
                }
            }
            else
            {
                m_UpdateKillTimer -= diff;
            }
        }

        bool KomakKillsAysa()
        {
            if (m_Phase != PHASE_JI_KILLED)
                return false;

            Creature* pKomak = GetOverseerKomak();
            Creature* pAysa = GetAysaCloudsinger();
            if (pKomak && pAysa && pKomak->IsWithinMeleeRange(pAysa))
            {
                KillCreature(pKomak, pAysa);
                pAysa->AI()->Talk(SAY_AYSA_EVENT_5);
                return true;
            }

            return false;
        }

        void KillCreature(Creature* attacker, Creature* victim)
        {
            const uint32 damage = 1000000;
            attacker->DealDamage(victim, damage);
            attacker->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, victim, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_HIT, 0);
        }

        void MoveAysaToJi()
        {
            if (Creature* pAysa = GetAysaCloudsinger())
            {
                pAysa->GetMotionMaster()->MovePoint(0, aysaPos[2]);
            }

            m_Events.ScheduleEvent(EVENT_AYSA_TALK_3, 8000);
        }

    private:

        Creature* GetAysaCloudsinger()
        {
            return ObjectAccessor::GetCreature(*m_Owner, m_AysaGuid);
        }

        Creature* GetJiFirepaw()
        {
            return ObjectAccessor::GetCreature(*m_Owner, m_JiGuid);
        }

        Creature* GetOverseerKomak()
        {
            return ObjectAccessor::GetCreature(*m_Owner, m_KomakGuid);
        }

    private:

        Creature* m_Owner;
        InstanceScript* pInstance;
        EventMap m_Events;
        ObjectGuid m_AysaGuid;
        ObjectGuid m_JiGuid;
        ObjectGuid m_KomakGuid;
        LocalPhases m_Phase;
        uint32 m_UpdateKillTimer;
};

class npc_siege_of_orgrimmar_aysa_cloudsinger : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_aysa_cloudsinger() : CreatureScript("npc_siege_of_orgrimmar_aysa_cloudsinger") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_aysa_cloudsingerAI(creature);
        }

        struct npc_siege_of_orgrimmar_aysa_cloudsingerAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_aysa_cloudsingerAI(Creature* creature) : ScriptedAI(creature),
                m_AysaEvent(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_AYSA_START_INTRO)
                {
                    StartIntro();
                }
                else if (action == ACTION_AYSA_START_EVENT)
                {
                    StartEvent();
                }
                else if (action == ACTION_AYSA_KOMAK_DIED)
                {
                    EndEvent();
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                m_AysaEvent.Update(diff);
            }

        private:

            void StartIntro()
            {
                m_AysaEvent.Initialize();
                m_AysaEvent.StartIntro();
            }

            void StartEvent()
            {
                m_AysaEvent.StartEvent();
            }

            void EndEvent()
            {
                m_AysaEvent.EndEvent();
            }

        private:

            InstanceScript* pInstance;
            AysaEventHelper m_AysaEvent;

        };
};

class npc_siege_of_orgrimmar_ji_firepaw : public CreatureScript
{
    public:
        npc_siege_of_orgrimmar_ji_firepaw() : CreatureScript("npc_siege_of_orgrimmar_ji_firepaw") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_ji_firepawAI(creature);
        }

        struct npc_siege_of_orgrimmar_ji_firepawAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_ji_firepawAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
            }

            void JustDied(Unit* who) override
            {
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_overseer_komak : public CreatureScript
{
    private:

        enum LocalEvents
        {
            EVENT_KILL_JI   = 1,
        };

    public:
        npc_siege_of_orgrimmar_overseer_komak() : CreatureScript("npc_siege_of_orgrimmar_overseer_komak") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_overseer_komakAI(creature);
        }

        struct npc_siege_of_orgrimmar_overseer_komakAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_overseer_komakAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                pInstance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim) override
            {

            }

            void JustDied(Unit* killer) override
            {
                events.Reset();

                SendKomakDied();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        private:

            void SendKomakDied()
            {
                if (pInstance)
                {
                    if (Creature* pAysa = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_AYSA_CLOUDSINGER)))
                    {
                        pAysa->AI()->DoAction(ACTION_AYSA_KOMAK_DIED);
                    }
                }
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_overlord_runthak : public CreatureScript
{
    enum Spells
    {
        SPELL_BONECRACKER   = 145568,
    };

    enum Events
    {
        EVENT_BONECRACKER  = 1,
    };

    public:
        npc_siege_of_orgrimmar_overlord_runthak() : CreatureScript("npc_siege_of_orgrimmar_overlord_runthak") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_overlord_runthakAI(creature);
        }

        struct npc_siege_of_orgrimmar_overlord_runthakAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_overlord_runthakAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_BONECRACKER, urand(8000, 12000));
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BONECRACKER:
                            DoCastAOE(SPELL_BONECRACKER);
                            events.ScheduleEvent(EVENT_BONECRACKER, urand(10000, 20000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_hellscream_demolisher : public CreatureScript
{
    enum Spells
    {
        SPELL_HURL_BOULDER  = 145569,
        SPELL_BOULDER       = 145570,
    };

    enum Events
    {
        EVENT_HURL_BOULDER  = 1,
        EVENT_UPDATE_ATTACK_STATE,
    };

    enum AttackStates
    {
        ATTACK_STATE_MELEE,
        ATTACK_STATE_RANGED,
    };

    public:
        npc_siege_of_orgrimmar_hellscream_demolisher() : CreatureScript("npc_siege_of_orgrimmar_hellscream_demolisher") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_hellscream_demolisherAI(creature);
        }

        struct npc_siege_of_orgrimmar_hellscream_demolisherAI : public Scripted_NoMovementAI
        {
            npc_siege_of_orgrimmar_hellscream_demolisherAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                //ApplyAllImmunities(true);

                pInstance = creature->GetInstanceScript();
                me->SetBoundingRadius(5.0f);
                me->SetCombatReach(5.0f);
            }

            void Reset()
            {
                events.Reset();
                m_State = ATTACK_STATE_MELEE;
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_HURL_BOULDER, 1000);
                events.ScheduleEvent(EVENT_UPDATE_ATTACK_STATE, 1000);
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_ATTACK_STATE:
                            UpdateAttackState();
                            events.ScheduleEvent(EVENT_UPDATE_ATTACK_STATE, 1000);
                            break;
                        case EVENT_HURL_BOULDER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                DoCast(target, SPELL_HURL_BOULDER);
                            }
                            events.ScheduleEvent(EVENT_HURL_BOULDER, 5000);
                            break;
                    }
                }

                if (m_State == ATTACK_STATE_MELEE)
                {
                    DoMeleeAttackIfReady();
                }
            }

        private:

            void UpdateAttackState()
            {
                bool canAttackMelee = CheckForMelee();
                if (canAttackMelee)
                {
                    if (m_State != ATTACK_STATE_MELEE)
                    {
                        m_State = ATTACK_STATE_MELEE;
                        events.CancelEvent(EVENT_HURL_BOULDER);
                    }
                }
                else
                {
                    if (m_State != ATTACK_STATE_RANGED)
                    {
                        m_State = ATTACK_STATE_RANGED;
                        events.ScheduleEvent(EVENT_HURL_BOULDER, 1000);
                    }
                }
            }

            bool CheckForMelee()
            {
                if (!me->GetVictim())
                    return false;

                if (me->IsWithinMeleeRange(me->GetVictim()))
                    return true;

                if (Unit* target = me->SelectNearestPlayer(me->GetMeleeRange(me->SelectNearestPlayer(20.0f))))
                {
                    AttackStart(target);
                    return true;
                }

                return false;
            }

        private:

            InstanceScript* pInstance;
            AttackStates m_State;
        };
};

class npc_siege_of_orgrimmar_korkron_shadowmage : public CreatureScript
{
    enum Spells
    {
        SPELL_MIND_SPIKE    = 145550,
        SPELL_SHADOWFLAME   = 145551,
    };

    enum Events
    {
        EVENT_MIND_SPIKE  = 1,
        EVENT_SHADOWFLAME
    };

    public:
        npc_siege_of_orgrimmar_korkron_shadowmage() : CreatureScript("npc_siege_of_orgrimmar_korkron_shadowmage") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_shadowmageAI(creature);
        }

        struct npc_siege_of_orgrimmar_korkron_shadowmageAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_shadowmageAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, false);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_MIND_SPIKE, 1);
                events.ScheduleEvent(EVENT_SHADOWFLAME, urand(8000, 12000));
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MIND_SPIKE:
                            DoCastVictim(SPELL_MIND_SPIKE);
                            events.ScheduleEvent(EVENT_MIND_SPIKE, 2000);
                            break;
                        case EVENT_SHADOWFLAME:
                            DoCastVictim(SPELL_SHADOWFLAME);
                            events.ScheduleEvent(EVENT_SHADOWFLAME, urand(10000, 15000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korkron_arcweaver : public CreatureScript
{
    enum Spells
    {
        SPELL_ARCANE_SHOCK              = 145564,
        SPELL_MAGICSTRIKE               = 145563,
        SPELL_UNSTABLE_BLINK            = 143433,
    };

    enum Events
    {
        EVENT_ARCANE_SHOCK   = 1,
        EVENT_MAGICSTRIKE,
        EVENT_UNSTABLE_BLINK,
    };

    public:
        npc_siege_of_orgrimmar_korkron_arcweaver() : CreatureScript("npc_siege_of_orgrimmar_korkron_arcweaver") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_arcweaverAI(creature);
        }

        struct npc_siege_of_orgrimmar_korkron_arcweaverAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_arcweaverAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, false);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* victim)
            {
                events.ScheduleEvent(EVENT_ARCANE_SHOCK, 1);
                events.ScheduleEvent(EVENT_MAGICSTRIKE, urand(5000, 10000));
                // when npc blinks it can teleport into textures
                // don't use this spell now
                // events.ScheduleEvent(EVENT_UNSTABLE_BLINK, urand(20000, 25000));
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARCANE_SHOCK:
                            DoCastVictim(SPELL_ARCANE_SHOCK);
                            events.ScheduleEvent(EVENT_ARCANE_SHOCK, 1500);
                            break;
                        case EVENT_MAGICSTRIKE:
                            DoCastAOE(SPELL_MAGICSTRIKE);
                            events.ScheduleEvent(EVENT_MAGICSTRIKE, urand(15000, 20000));
                            break;
                        case EVENT_UNSTABLE_BLINK:
                            DoCast(SPELL_UNSTABLE_BLINK);
                            events.ScheduleEvent(EVENT_UNSTABLE_BLINK, urand(20000, 25000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_siege_of_orgrimmar_korkron_assassin : public CreatureScript
{
    enum Spells
    {
        SPELL_ASSASSINS_MARK            = 145561,
        SPELL_BACKSTAB                  = 145562,
        SPELL_STEALTH                   = 118969,
    };

    enum Events
    {
        EVENT_BACKSTAB   = 1,
    };

    public:
        npc_siege_of_orgrimmar_korkron_assassin() : CreatureScript("npc_siege_of_orgrimmar_korkron_assassin") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_siege_of_orgrimmar_korkron_assassinAI(creature);
        }

        struct npc_siege_of_orgrimmar_korkron_assassinAI : public ScriptedAI
        {
            npc_siege_of_orgrimmar_korkron_assassinAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, false);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();

                me->AddAura(SPELL_STEALTH, me);
            }

            void EnterCombat(Unit* victim)
            {
                DoCast(victim, SPELL_ASSASSINS_MARK);
                me->ClearUnitState(UNIT_STATE_CASTING);

                events.ScheduleEvent(EVENT_BACKSTAB, 2000);
            }

            void JustDied(Unit* killer)
            {
                events.Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BACKSTAB:
                            if (Unit* target = me->GetVictim())
                            {
                                if (target->isInBack(me))
                                {
                                    DoCast(target, SPELL_BACKSTAB);
                                }
                            }
                            events.ScheduleEvent(EVENT_BACKSTAB, urand(2000, 3000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            InstanceScript* pInstance;
        };
};

class spell_siege_of_orgrimmar_fracture_aoe : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_fracture_aoe() : SpellScriptLoader("spell_siege_of_orgrimmar_fracture_aoe") { }

        class spell_siege_of_orgrimmar_fracture_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_fracture_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_FRACTURE_STUN, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_FRACTURE_CHANNEL, false);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_of_orgrimmar_fracture_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_siege_of_orgrimmar_fracture_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_fracture_aoe_SpellScript();
        }
};

class spell_siege_of_orgrimmar_tidal_wave_aoe : public SpellScriptLoader
{
    public:
        spell_siege_of_orgrimmar_tidal_wave_aoe() : SpellScriptLoader("spell_siege_of_orgrimmar_tidal_wave_aoe") { }

        class spell_siege_of_orgrimmar_tidal_wave_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_siege_of_orgrimmar_tidal_wave_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_TIDAL_WAVE_DUMMY, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_TIDAL_WAVE_DMG, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_of_orgrimmar_tidal_wave_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_siege_of_orgrimmar_tidal_wave_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_siege_of_orgrimmar_tidal_wave_aoe_SpellScript();
        }
};

class at_aysa_cloudsinger : public AreaTriggerScript
{
    public:

        at_aysa_cloudsinger()
            : AreaTriggerScript("at_aysa_cloudsinger")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool p_Enter) override
        {
            if (p_Enter)
            {
                SendAysaTalk(player);
            }

            return true;
        }

    private:

        void SendAysaTalk(WorldObject* searcher)
        {
            if (InstanceScript* pInstance = searcher->GetInstanceScript())
            {
                if (Creature* pAysa = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_AYSA_CLOUDSINGER)))
                    pAysa->AI()->DoAction(ACTION_AYSA_START_EVENT);
            }
        }
};

void AddSC_siege_of_orgrimmar_part_b()
{
    new npc_siege_of_orgrimmar_jaina_proudmoore_2();    // 72302
    new npc_siege_of_orgrimmar_king_varian_wrynn_2();   // 72311
    new npc_siege_of_orgrimmar_lorthemar_theron_2();    // 72560
    new npc_siege_of_orgrimmar_sylvanas_windrunner_2(); // 72561
    new npc_siege_of_orgrimmar_aethas_sunreaver();      // 73909

    new npc_siege_of_orgrimmar_dragonmaw_bonecrusher(); // 72354
    new npc_siege_of_orgrimmar_dragonmaw_tidal_shaman();// 72367
    new npc_siege_of_orgrimmar_healing_tide_totem();    // 73086
    new npc_siege_of_orgrimmar_dragonmaw_elite_grunt(); // 72350
    new npc_siege_of_orgrimmar_dragonmaw_flagbearer();  // 72351
    new npc_siege_of_orgrimmar_korkron_cannon();        // 72358
    new npc_siege_of_orgrimmar_voljin_1();              // 73942
    new npc_siege_of_orgrimmar_baine_bloodhoof_1();     // 73941

    new npc_siege_of_orgrimmar_blind_blademaster();     // 72131

    new npc_siege_of_orgrimmar_aysa_cloudsinger();      // 72438
    new npc_siege_of_orgrimmar_ji_firepaw();            // 72454
    new npc_siege_of_orgrimmar_overseer_komak();        // 72455

    new npc_siege_of_orgrimmar_overlord_runthak();      // 72191
    new npc_siege_of_orgrimmar_hellscream_demolisher(); // 72194
    new npc_siege_of_orgrimmar_korkron_shadowmage();    // 72150
    new npc_siege_of_orgrimmar_korkron_arcweaver();     // 71771
    new npc_siege_of_orgrimmar_korkron_assassin();      // 71772

    new go_siege_of_orgrimmar_minor_portal();           // 221522

    new spell_siege_of_orgrimmar_fracture_aoe();        // 147201
    new spell_siege_of_orgrimmar_tidal_wave_aoe();      // 149187

    new at_aysa_cloudsinger();                          // 9280
}
