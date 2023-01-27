#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"

class AreaTrigger_at_mandori : public AreaTriggerScript
{
    public:
        AreaTrigger_at_mandori() : AreaTriggerScript("AreaTrigger_at_mandori")
        {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
           if (player->GetPositionX() < 710.0f)
               return true;

           if (player->GetQuestStatus(29792) != QUEST_STATUS_INCOMPLETE)
               return true;

           uint64 playerGuid = player->GetGUID();

            Creature* Aysa = player->SummonCreature(59986, 698.04f, 3601.79f, 142.82f, 3.254830f, TEMPSUMMON_MANUAL_DESPAWN, 0, playerGuid); // Aysa
            Creature* Ji   = player->SummonCreature(59988, 698.06f, 3599.34f, 142.62f, 2.668790f, TEMPSUMMON_MANUAL_DESPAWN, 0, playerGuid); // Ji
            Creature* Jojo = player->SummonCreature(59989, 702.78f, 3603.58f, 142.01f, 3.433610f, TEMPSUMMON_MANUAL_DESPAWN, 0, playerGuid); // Jojo

            if (!Aysa || !Ji || !Jojo)
                return true;
            
            Aysa->AI()->SetGUID(playerGuid);
              Ji->AI()->SetGUID(playerGuid);
            Jojo->AI()->SetGUID(playerGuid);

            player->RemoveAurasDueToSpell(59073);
            player->RemoveAurasDueToSpell(59074);

            return true;
        }
};

class mob_mandori_escort : public CreatureScript
{
    public:
        mob_mandori_escort() : CreatureScript("mob_mandori_escort") { }

    struct mob_mandori_escortAI : public npc_escortAI
    {        
        mob_mandori_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        enum escortEntry
        {
            NPC_AYSA    = 59986,
            NPC_JI      = 59988,
            NPC_JOJO    = 59989
        };
        
        uint32 IntroTimer;
        uint32 doorEventTimer;

        uint8  IntroState;
        uint8  doorEventState;

        uint64 playerGuid;
        
        uint64 mandoriDoorGuid;
        uint64 peiwuDoorGuid;

        void Reset()
        {
            IntroTimer      = 250;
            doorEventTimer  = 0;

            IntroState      = 0;
            doorEventState  = 0;

            playerGuid      = 0;
            mandoriDoorGuid = 0;
            peiwuDoorGuid   = 0;

            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(uint64 guid, int32 type)
        {
            playerGuid = guid;

            if (!Is(NPC_AYSA))
                return;

            if (GameObject* mandoriDoor = me->SummonGameObject(211294, 695.26f, 3600.99f, 142.38f, 3.04f, 0.0f, 0.0f, 0.0f, 0.0f, RESPAWN_IMMEDIATELY, playerGuid))
                mandoriDoorGuid = mandoriDoor->GetGUID();

            if (GameObject* peiwuDoor = me->SummonGameObject(211298, 566.52f, 3583.46f, 92.16f, 3.14f, 0.0f, 0.0f, 0.0f, 0.0f, RESPAWN_IMMEDIATELY, playerGuid))
                peiwuDoorGuid = peiwuDoor->GetGUID();
        }

        bool Is(uint32 npc_entry)
        {
            return me->GetEntry() == npc_entry;
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 5:
                    SetEscortPaused(true);

                    // Jojo reach the waypoint 1 sec after the others
                    if (!Is(NPC_JOJO))
                        doorEventTimer = 2000;
                    else
                        doorEventTimer = 1000;
                    break;
                default:
                    break;
            }
        }

        void LastWaypointReached()
        {
            if (Is(NPC_JI))
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    player->AddAura(68482, player); // Phase 8192
            
            if (Is(NPC_AYSA))
            {
                if (GameObject* mandoriDoor = me->GetMap()->GetGameObject(mandoriDoorGuid))
                    mandoriDoor->Delete();
                if (GameObject* peiwuDoor = me->GetMap()->GetGameObject(peiwuDoorGuid))
                    peiwuDoor->Delete();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    switch (++IntroState)
                    {
                        case 1:
                            if (Is(NPC_AYSA))
                                me->MonsterYell("Let's go !", LANG_UNIVERSAL, playerGuid);
                            IntroTimer = 1000;
                            break;
                        case 2:
                            if (Is(NPC_AYSA))
                            {
                                if (GameObject* mandoriDoor = me->GetMap()->GetGameObject(mandoriDoorGuid))
                                    mandoriDoor->SetGoState(GO_STATE_ACTIVE);

                                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                                    player->KilledMonsterCredit(59946);
                            }
                            IntroTimer = 1000;
                            break;
                        case 3:
                            Start(false, true);
                            IntroTimer = 0;
                            break;
                    }
                }
                else
                    IntroTimer -= diff;
            }

            if (doorEventTimer)
            {
                if (doorEventTimer <= diff)
                {
                    switch (++doorEventState)
                    {
                        case 1:
                            if (Is(NPC_AYSA))
                                me->MonsterSay("The door is blocked!", LANG_UNIVERSAL, playerGuid);
                            doorEventTimer = 2500;
                            break;
                        case 2:
                            if (Is(NPC_JI))
                                me->MonsterSay("They blocked it with a rock on the other side, I can't open it!", LANG_UNIVERSAL, playerGuid);
                            doorEventTimer = 4000;
                            break;
                        case 3:
                            if (Is(NPC_JOJO))
                                me->GetMotionMaster()->MoveCharge(567.99f, 3583.41f, 94.74f);
                            doorEventTimer = 150;
                            break;
                        case 4:
                            if (Is(NPC_AYSA))
                                if (GameObject* peiwuDoor = me->GetMap()->GetGameObject(peiwuDoorGuid))
                                    peiwuDoor->SetGoState(GO_STATE_ACTIVE);
                            doorEventTimer = 2000;
                            break;
                       case 5:
                            if (Is(NPC_AYSA))
                            {
                                me->MonsterSay("Well done, Jojo!", LANG_UNIVERSAL, playerGuid);

                                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                                    player->KilledMonsterCredit(59947);
                            }
                           if (!Is(NPC_JOJO))
                               SetEscortPaused(false);
                            doorEventTimer = 2000;
                            break;
                       case 6:
                           if (Is(NPC_JOJO))
                               SetEscortPaused(false);
                            doorEventTimer = 0;
                            break;
                    }
                }
                else
                    doorEventTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_mandori_escortAI(creature);
    }
};

class npc_korga : public CreatureScript
{
    public:
        npc_korga() : CreatureScript("npc_korga") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == 30589) // Detruire l'epave
                if (Creature* jiEscort = player->SummonCreature(60900, 424.71f, 3635.59f, 92.70f, 2.498430f, TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
                    jiEscort->AI()->SetGUID(player->GetGUID());

            return true;
        }
};

class mob_ji_forest_escort : public CreatureScript
{
public:
    mob_ji_forest_escort() : CreatureScript("mob_ji_forest_escort") { }

    struct mob_ji_forest_escortAI : public npc_escortAI
    {        
        mob_ji_forest_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint64 playerGuid;

        uint32 IntroTimer;

        void Reset()
        {
            playerGuid      = 0;

            IntroTimer      = 100;
        }

        void SetGUID(uint64 guid, int32 type)
        {
            playerGuid = guid;
        }
        
        void WaypointReached(uint32 waypointId)
        {}

        void LastWaypointReached()
        {
            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                player->AddAura(68483, player); // Phase 16384
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ji_forest_escortAI(creature);
    }
    
};

class AreaTrigger_at_rescue_soldiers : public AreaTriggerScript
{
    public:
        AreaTrigger_at_rescue_soldiers() : AreaTriggerScript("AreaTrigger_at_rescue_soldiers")
        {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
           if (player->GetQuestStatus(29794) != QUEST_STATUS_INCOMPLETE)
               return true;

           if (!player->HasAura(129340))
               return true;

           player->RemoveAurasDueToSpell(129340);
           player->KilledMonsterCredit(55999);

            return true;
        }
};

class npc_hurted_soldier : public CreatureScript
{
public:
    npc_hurted_soldier() : CreatureScript("npc_hurted_soldier") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hurted_soldierAI(creature);
    }

    struct npc_hurted_soldierAI : public ScriptedAI
    {
        npc_hurted_soldierAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 checkSavedTimer;
        bool HasBeenSaved;

        void Reset()
        {
            checkSavedTimer = 2500;
            HasBeenSaved = false;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* Clicker)
        {
            me->RemoveAurasDueToSpell(130966); // Feign Death
            me->EnterVehicle(Clicker);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            HasBeenSaved = true;
        }

        void UpdateAI(const uint32 diff)
        {
            if (checkSavedTimer)
            {
                if (checkSavedTimer <= diff)
                {
                    if (HasBeenSaved && !me->GetVehicle())
                    {
                        me->MonsterSay("Thanks you, i'll never forget that.", LANG_UNIVERSAL, 0);
                        me->DespawnOrUnsummon(5000);
                        checkSavedTimer = 0;
                    }
                    else
                        checkSavedTimer = 2500;
                }
                else
                    checkSavedTimer -= diff;
            }
        }
    };
};

enum
{
    QUEST_AN_ANCIENT_EVIL = 29798,
    NPC_VORDRAKA = 56009,
};

class npc_jojo_ironbrow : public CreatureScript
{
public:
    npc_jojo_ironbrow() : CreatureScript("npc_jojo_ironbrow") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_AN_ANCIENT_EVIL)
        {
            if (Creature* const vordraka = player->SummonCreature(NPC_VORDRAKA, 281.74f, 4003.40f, 72.96f, 0.05f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000))
            {
                vordraka->setExplicitSeerGuid(player->GetGUID());
                vordraka->AI()->SetGUID(player->GetGUID());
                vordraka->SetPhaseMask(12, true);
            }
        }

        return true;
    }
};

class boss_vordraka : public CreatureScript
{
public:
    boss_vordraka() : CreatureScript("boss_vordraka") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vordrakaAI(creature);
    }

    struct boss_vordrakaAI : public ScriptedAI
    {
        boss_vordrakaAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 summonerGUID;
        bool summonedAllies;
        EventMap _events;

        enum eEnums
        {
            EVENT_DEEP_ATTACK = 1,
            EVENT_DEEP_SEA_RUPTURE = 2,

            SPELL_DEEP_ATTACK = 117287,
            SPELL_DEEP_SEA_RUPTURE = 117456,

            NPC_DEEPSCALE_AGGRESSOR = 60685,
            NPC_AYSA = 56416,
        };

        void Reset()
        {
            summonedAllies = false;
            _events.ScheduleEvent(EVENT_DEEP_ATTACK, 10000);
            _events.ScheduleEvent(SPELL_DEEP_SEA_RUPTURE, 12500);
        }

        void SetGUID(uint64 guid, int32 /* = 0 */) override
        {
            summonerGUID = guid;
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (who->GetEntry() == NPC_AYSA)
                damage /= 2;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            Player * const player = who->ToPlayer();
            if (!player || me->getVictim())
                return;

            if (player->GetQuestStatus(QUEST_AN_ANCIENT_EVIL) == QUEST_STATUS_INCOMPLETE)
                if (Creature * const aysa = GetClosestCreatureWithEntry(me, NPC_AYSA, 30.f))
                {
                    aysa->AI()->AttackStart(me);
                    AttackStart(aysa);
                    me->AddThreat(aysa, 1000.0f);
                }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*attacker*/)
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 30.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(QUEST_AN_ANCIENT_EVIL) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        player->KilledMonsterCredit(me->GetEntry());
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (!summonedAllies && me->HealthBelowPct(50))
            {
                if (Creature * const aysa = GetClosestCreatureWithEntry(me, NPC_AYSA, 30.f))
                {
                    aysa->AI()->Talk(0);
                    me->AddThreat(aysa, 1000.0f);
                }

                for (int i = 0; i < 3; ++i)
                {
                    Position pos;
                    me->GetRandomNearPosition(pos, 20.f);
                    if (Creature * const summon = me->SummonCreature(NPC_DEEPSCALE_AGGRESSOR, pos, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 120000))
                        if (Player * const player = Unit::GetPlayer(*me, summonerGUID))
                            summon->AI()->AttackStart(player);
                }
                summonedAllies = true;
            }

            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
            case EVENT_DEEP_ATTACK:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
                    me->CastSpell(target, SPELL_DEEP_ATTACK, false);

                _events.ScheduleEvent(EVENT_DEEP_ATTACK, 10000);
                break;
            }
            case EVENT_DEEP_SEA_RUPTURE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
                    me->CastSpell(target, SPELL_DEEP_SEA_RUPTURE, false);

                _events.ScheduleEvent(EVENT_DEEP_ATTACK, 10000);
                break;
            }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_aysa_gunship_crash : public CreatureScript
{
    public:
        mob_aysa_gunship_crash() : CreatureScript("mob_aysa_gunship_crash") { }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == 30767) // Tout risquer
                if (Creature* aysa = player->SummonCreature(60729, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
                    aysa->AI()->SetGUID(player->GetGUID());

            return true;
        }

        struct mob_aysa_gunship_crashAI : public ScriptedAI
        {        
            mob_aysa_gunship_crashAI(Creature* creature) : ScriptedAI(creature)
            {}

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (HealthBelowPct(70))
                    damage = 0;
            }
        };
    
        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_aysa_gunship_crashAI(creature);
        }
};

class mob_aysa_gunship_crash_escort : public CreatureScript
{
public:
    mob_aysa_gunship_crash_escort() : CreatureScript("mob_aysa_gunship_crash_escort") { }

    struct mob_aysa_gunship_crash_escortAI : public npc_escortAI
    {        
        mob_aysa_gunship_crash_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint64 playerGuid;
        uint64 jiGuid;
        uint64 fireGuid;

        uint32 IntroTimer;
        uint32 discussTimer;

        uint8  discussEvent;

        void Reset()
        {
            playerGuid      = 0;
            jiGuid          = 0;
            fireGuid        = 0;

            IntroTimer      = 100;
            discussTimer    = 0;

            discussEvent    = 0;
        }

        void SetGUID(uint64 guid, int32 type)
        {
            playerGuid = guid;

            if (Creature* ji = me->SummonCreature(60741, 230.31f, 4006.67f, 87.27f, 3.38f, TEMPSUMMON_MANUAL_DESPAWN, 0, guid))
                jiGuid = ji->GetGUID();

            if (GameObject* gob = me->SummonGameObject(215344, 227.75f, 4006.38f, 87.06f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, RESPAWN_IMMEDIATELY, guid))
                fireGuid = gob->GetGUID();
        }

        void WaypointReached(uint32 waypointId)
        {
            if (waypointId == 8)
            {
                SetEscortPaused(true);
                discussTimer = 1000;
            }
        }

        Creature* getJi()
        {
            return me->GetMap()->GetCreature(jiGuid);
        }

        void UpdateAI(const uint32 diff)
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }
            
            if (discussTimer)
            {
                if (discussTimer <= diff)
                {
                    switch (++discussEvent)
                    {
                        case 1:
                            me->MonsterSay("Ji, what are you doing ?! You can't do that !", LANG_UNIVERSAL, playerGuid);
                            if (Creature* ji = getJi())
                                ji->SetFacingToObject(me);
                            discussTimer = 3000;
                            break;
                        case 2:
                            if (Creature* ji = getJi())
                                ji->MonsterSay("We have no choice Aysa.", LANG_UNIVERSAL, playerGuid);
                            discussTimer = 3000;
                            break;
                        case 3:
                            me->MonsterSay("You are going to kill him !", LANG_UNIVERSAL, playerGuid);
                            discussTimer = 3000;
                            break;
                        case 4:
                            if (Creature* ji = getJi())
                                ji->MonsterSay("In our situation, inaction would be the greatest danger.", LANG_UNIVERSAL, playerGuid);
                            discussTimer = 3000;
                            break;
                        case 5:
                            me->MonsterSay("I hope you know what you're doing, Ji...", LANG_UNIVERSAL, playerGuid);
                            discussTimer = 5000;
                            break;
                        case 6:
                            SetEscortPaused(false);
                            
                            if (Creature* ji = getJi())
                                ji->GetMotionMaster()->MovePoint(0, 227.21f, 3981.09f, 85.92f);

                            discussTimer = 1000;
                            break;
                        case 7:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                            {
                                player->KilledMonsterCredit(60727);
                                player->SendMovieStart(117);
                            }
                            discussTimer = 500;
                            break;
                        case 8:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                                player->NearTeleportTo(249.38f, 3939.55f, 65.61f, 1.501471f);
                            
                            if (Creature* ji = getJi())
                                ji->DespawnOrUnsummon();

                            if (GameObject* gob = me->GetMap()->GetGameObject(fireGuid))
                                gob->Delete();

                            discussTimer = 0;
                            break;
                    }
                }
                else
                    discussTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_aysa_gunship_crash_escortAI(creature);
    }
    
};

#define MAX_ENNEMIES_POS   2
#define MAX_HEALER_COUNT   12
#define UPDATE_POWER_TIMER 3000

Position ennemiesPositions[MAX_ENNEMIES_POS] =
{
    {215.0f, 3951.0f, 71.4f},
    {290.0f, 3939.0f, 86.7f}
};

enum eEnums
{
    QUEST_HEALING_SHEN      = 29799,
            
    NPC_HEALER_A            = 60878,
    NPC_HEALER_H            = 60896,
    NPC_ENNEMY              = 60858,

    NPC_SHEN_HEAL_CREDIT    = 56011,

    EVENT_CHECK_PLAYERS     = 1,
    EVENT_UPDATE_POWER      = 2,
    EVENT_SUMMON_ENNEMY     = 3,
    EVENT_SUMMON_HEALER     = 4,

    SPELL_SHEN_HEALING      = 117783,
    SPELL_HEALER_A          = 117784,
    SPELL_HEALER_H          = 117932,
};

class npc_ji_end_event : public CreatureScript
{
public:
    npc_ji_end_event() : CreatureScript("npc_ji_end_event") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ji_end_eventAI(creature);
    }

    struct npc_ji_end_eventAI : public ScriptedAI
    {
        npc_ji_end_eventAI(Creature* creature) : ScriptedAI(creature), _summons(creature)
        {}

        EventMap   _events;
        SummonList _summons;

        bool       inProgress;
        uint8      healerCount;
        uint8      ennemiesCount;
        uint16     actualPower;

        void Reset()
        {
            _summons.DespawnAll();

            healerCount   = 0;
            ennemiesCount = 0;
            actualPower   = 0;

            inProgress = false;

            _events.Reset();
            _events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
        }

        bool CheckPlayers()
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 100.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(QUEST_HEALING_SHEN) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        return true;

            return false;
        }

        void UpdatePower()
        {
            actualPower = (actualPower + healerCount <= 700) ? actualPower + healerCount: 700;

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 100.0f);

            for (auto player : playerList)
            {
                if (player->GetQuestStatus(QUEST_HEALING_SHEN) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsAlive())
                    {
                        if (actualPower < 700) // IN_PROGRESS
                        {
                            if (!player->HasAura(SPELL_SHEN_HEALING))
                                player->CastSpell(player, SPELL_SHEN_HEALING, true);

                            player->SetPower(POWER_ALTERNATE_POWER, actualPower);
                        }
                        else
                        {
                            if (player->HasAura(SPELL_SHEN_HEALING))
                                player->RemoveAurasDueToSpell(SPELL_SHEN_HEALING);

                            player->KilledMonsterCredit(NPC_SHEN_HEAL_CREDIT);
                        }
                    }
                }
            }

            if (actualPower >= 700)
                Reset();
        }

        void SummonEnnemy()
        {
            uint8 pos = rand() % MAX_ENNEMIES_POS;
            float posJumpX = frand(228.0f, 270.0f);
            float posJumpY = frand(3949.0f, 3962.0f);

            if (Creature* ennemy = me->SummonCreature(NPC_ENNEMY, ennemiesPositions[pos].GetPositionX(), ennemiesPositions[pos].GetPositionY(), ennemiesPositions[pos].GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN))
                ennemy->GetMotionMaster()->MoveJump(posJumpX, posJumpY, me->GetMap()->GetHeight(me->GetPhaseMask(), posJumpX, posJumpY, 100.0f), 20.0f, 20.0f);
        }

        void SummonHealer()
        {
            uint32 entry = rand() % 2 ? NPC_HEALER_A: NPC_HEALER_H;
            float posX = frand(228.0f, 270.0f);
            float posY = frand(3949.0f, 3962.0f);

            me->SummonCreature(entry, posX, posY, me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, 100.0f), 1.37f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void JustSummoned(Creature* summon)
        {
            _summons.Summon(summon);

            switch (summon->GetEntry())
            {
                case NPC_HEALER_A:
                case NPC_HEALER_H:
                    ++healerCount;
                    break;
                case NPC_ENNEMY:
                    ++ennemiesCount;
                    break;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
        {
            _summons.Despawn(summon);

            switch (summon->GetEntry())
            {
                case NPC_HEALER_A:
                case NPC_HEALER_H:
                    --healerCount;
                    break;
                case NPC_ENNEMY:
                    --ennemiesCount;
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
                case EVENT_CHECK_PLAYERS:
                {
                    bool playerNearWithQuest = CheckPlayers();

                    if (inProgress && !playerNearWithQuest)
                    {
                        inProgress = false;
                        Reset();
                    }
                    else if (!inProgress && playerNearWithQuest)
                    {
                        inProgress = true;
                        _events.ScheduleEvent(EVENT_UPDATE_POWER,  UPDATE_POWER_TIMER);
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 5000);
                        _events.ScheduleEvent(EVENT_SUMMON_HEALER, 5000);
                    }
                    _events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                    break;
                }
                case EVENT_UPDATE_POWER:
                    UpdatePower();
                    _events.ScheduleEvent(EVENT_UPDATE_POWER, UPDATE_POWER_TIMER);
                    break;
                case EVENT_SUMMON_ENNEMY:
                    if (ennemiesCount < (healerCount / 2))
                    {
                        SummonEnnemy();
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 5000);
                    }
                    else
                        _events.ScheduleEvent(EVENT_SUMMON_ENNEMY, 7500);
                    break;
                case EVENT_SUMMON_HEALER:
                    if (healerCount < MAX_HEALER_COUNT)
                        SummonHealer();

                    _events.ScheduleEvent(EVENT_SUMMON_HEALER, 12500);
                    break;
            }
        }
    };
};

class npc_shen_healer : public CreatureScript
{
    public:
        npc_shen_healer() : CreatureScript("npc_shen_healer") { }

        struct npc_shen_healerAI : public ScriptedAI
        {        
            npc_shen_healerAI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(me, me->GetEntry() == NPC_HEALER_A ? SPELL_HEALER_A: SPELL_HEALER_H, true);
            }

            void EnterCombat(Unit*)
            {
                return;
            }
        };
    
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_shen_healerAI(creature);
        }
};

#define GOSSIP_CHOOSE_FACTION     "I'm ready to choose my destiny."
#define GOSSIP_TP_STORMIND        "I would like to go to Stormwind"
#define GOSSIP_TP_ORGRI           "I would like to go to Orgrimmar"

class npc_shang_xi_choose_faction : public CreatureScript
{
    public:
        npc_shang_xi_choose_faction() : CreatureScript("npc_shang_xi_choose_faction") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->getRace() == RACE_PANDAREN_NEUTRAL)
            {
                if (player->GetQuestStatus(31450) == QUEST_STATUS_INCOMPLETE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOOSE_FACTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }
            else if (player->getRace() == RACE_PANDAREN_ALLI)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TP_STORMIND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            else if (player->getRace() == RACE_PANDAREN_HORDE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TP_ORGRI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
        {
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
                player->ShowNeutralPlayerFactionSelectUI();
            else if (action == GOSSIP_ACTION_INFO_DEF + 2)
                player->TeleportTo(0, -8866.55f, 671.93f, 97.90f, 5.31f);
            else if (action == GOSSIP_ACTION_INFO_DEF + 3)
                player->TeleportTo(1, 1577.30f, -4453.64f, 15.68f, 1.84f);

            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }
};

void AddSC_WanderingIsland_South()
{
    new AreaTrigger_at_mandori();
    new mob_mandori_escort();
    new npc_korga();
    new mob_ji_forest_escort();
    new AreaTrigger_at_rescue_soldiers();
    new npc_hurted_soldier();
    new npc_jojo_ironbrow();
    new boss_vordraka();
    new mob_aysa_gunship_crash();
    new mob_aysa_gunship_crash_escort();
    new npc_ji_end_event();
    new npc_shen_healer();
    new npc_shang_xi_choose_faction();
}
