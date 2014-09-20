#include "ScriptMgr.h"
#include "LFGMgr.h"
#include "Group.h"
#include "Player.h"

/*######
## BrewFest Event
######*/

enum CorenDirebrew
{
    SPELL_DISARM                = 47310,
    SPELL_DISARM_PRECAST        = 47407,
    SPELL_MOLE_MACHINE_EMERGE   = 50313, 
    NPC_ILSA_DIREBREW           = 26764,
    NPC_URSULA_DIREBREW         = 26822,
    NPC_DIREBREW_MINION         = 26776,
    EQUIP_ID_TANKARD            = 48663,
    FACTION_HOSTILE_CORE        = 736
};

#define GOSSIP_TEXT_INSULT "Insult Coren Direbrew's brew."

static Position _pos[]=
{
    {890.87f, -133.95f, -48.0f, 1.53f},
    {892.47f, -133.26f, -48.0f, 2.16f},
    {893.54f, -131.81f, -48.0f, 2.75f}
};

class npc_coren_direbrew : public CreatureScript
{
    public:
        npc_coren_direbrew() : CreatureScript("npc_coren_direbrew") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INSULT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(15858, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                creature->setFaction(FACTION_HOSTILE_CORE);
                creature->AI()->AttackStart(player);
                creature->AI()->DoZoneInCombat();
                player->CLOSE_GOSSIP_MENU();
            }

            return true;
        }

        struct npc_coren_direbrewAI : public ScriptedAI
        {
            npc_coren_direbrewAI(Creature* c) : ScriptedAI(c), _summons(me)
            {
            }

            void Reset() override
            {
                me->RestoreFaction();
                me->SetCorpseDelay(1800); // 30 minutes

                _addTimer = 20000;
                _disarmTimer = urand(10, 15) *IN_MILLISECONDS;

                _spawnedIlsa = false;
                _spawnedUrsula = false;
                _summons.DespawnAll();

                for (uint8 i = 0; i < 3; ++i)
                    if (Creature* creature = me->SummonCreature(NPC_DIREBREW_MINION, _pos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                        _add[i] = creature->GetGUID();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                SetEquipmentSlots(false, EQUIP_ID_TANKARD, EQUIP_ID_TANKARD, EQUIP_NO_CHANGE);

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (_add[i])
                    {
                        Creature* creature = ObjectAccessor::GetCreature((*me), _add[i]);
                        if (creature && creature->IsAlive())
                        {
                            creature->setFaction(FACTION_HOSTILE_CORE);
                            creature->SetInCombatWithZone();
                        }
                        _add[i].Clear();
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                // disarm
                if (_disarmTimer <= diff)
                {
                    DoCast(SPELL_DISARM_PRECAST);
                    DoCastVictim(SPELL_DISARM, false);
                    _disarmTimer = urand(20, 25) *IN_MILLISECONDS;
                }
                else
                    _disarmTimer -= diff;

                // spawn non-elite adds
                if (_addTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        float posX, posY, posZ;
                        target->GetPosition(posX, posY, posZ);
                        target->CastSpell(target, SPELL_MOLE_MACHINE_EMERGE, true, 0, 0, me->GetGUID());
                        me->SummonCreature(NPC_DIREBREW_MINION, posX, posY, posZ, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);

                        _addTimer = 15000;
                        if (_spawnedIlsa)
                            _addTimer -= 3000;
                        if (_spawnedUrsula)
                            _addTimer -= 3000;
                    }
                }
                else
                    _addTimer -= diff;

                if (!_spawnedIlsa && HealthBelowPct(66))
                {
                    DoSpawnCreature(NPC_ILSA_DIREBREW, 0, 0, 0, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                    _spawnedIlsa = true;
                }

                if (!_spawnedUrsula && HealthBelowPct(33))
                {
                    DoSpawnCreature(NPC_URSULA_DIREBREW, 0, 0, 0, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000);
                    _spawnedUrsula = true;
                }

                DoMeleeAttackIfReady();
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->getFaction() == FACTION_HOSTILE_CORE)
                {
                    summon->setFaction(FACTION_HOSTILE_CORE);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        summon->AI()->AttackStart(target);
                }

                _summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _summons.DespawnAll();

                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                {
                    if (Group* group = players.begin()->GetSource()->GetGroup())
                        if (group->isLFGGroup())
                            sLFGMgr->FinishDungeon(group->GetGUID(), 287);
                }
            }

        private:
            SummonList _summons;
            ObjectGuid _add[3];
            uint32 _addTimer;
            uint32 _disarmTimer;
            bool _spawnedIlsa;
            bool _spawnedUrsula;
        };

        CreatureAI* GetAI(Creature* c) const
        {
            return new npc_coren_direbrewAI(c);
        }
};

/*######
## dark iron brewmaiden
######*/

enum Brewmaiden
{
    SPELL_SEND_FIRST_MUG = 47333,
    SPELL_SEND_SECOND_MUG = 47339,
    //SPELL_CREATE_BREW = 47345,
    SPELL_HAS_BREW_BUFF = 47376,
    //SPELL_HAS_BREW = 47331,
    //SPELL_DARK_BREWMAIDENS_STUN = 47340,
    SPELL_CONSUME_BREW = 47377,
    SPELL_BARRELED = 47442,
    SPELL_CHUCK_MUG = 50276
};

class npc_brewmaiden : public CreatureScript
{
    public:
        npc_brewmaiden() : CreatureScript("npc_brewmaiden") { }

        struct npc_brewmaidenAI : public ScriptedAI
        {
            npc_brewmaidenAI(Creature* c) : ScriptedAI(c)
            {
            }

            void Reset() override
            {
                _brewTimer = 2000;
                _barrelTimer = 5000;
                _chuckMugTimer = 10000;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->SetInCombatWithZone();
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (me->Attack(who, true))
                {
                    me->AddThreat(who, 1.0f);
                    me->SetInCombatWith(who);
                    who->SetInCombatWith(me);

                    if (me->GetEntry() == NPC_URSULA_DIREBREW)
                        me->GetMotionMaster()->MoveFollow(who, 10.0f, 0.0f);
                    else
                        me->GetMotionMaster()->MoveChase(who);
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                // TODO: move to DB

                if (spell->Id == SPELL_SEND_FIRST_MUG)
                    target->CastSpell(target, SPELL_HAS_BREW_BUFF, true);

                if (spell->Id == SPELL_SEND_SECOND_MUG)
                    target->CastSpell(target, SPELL_CONSUME_BREW, true);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_brewTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                        if (target && me->GetDistance(target) > 5.0f)
                        {
                            DoCast(target, SPELL_SEND_FIRST_MUG);
                            _brewTimer = 12000;
                        }
                    }
                }
                else
                    _brewTimer -= diff;

                if (_chuckMugTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_CHUCK_MUG);

                    _chuckMugTimer = 15000;
                }
                else
                    _chuckMugTimer -= diff;

                if (me->GetEntry() == NPC_URSULA_DIREBREW)
                {
                    if (_barrelTimer <= diff)
                    {
                        if (!me->IsNonMeleeSpellCast(false))
                        {
                            DoCastVictim(SPELL_BARRELED);
                            _barrelTimer = urand(15, 18) *IN_MILLISECONDS;
                        }
                    }
                    else
                        _barrelTimer -= diff;
                }
                else
                    DoMeleeAttackIfReady();
            }

        private:
            uint32 _brewTimer;
            uint32 _barrelTimer;
            uint32 _chuckMugTimer;
        };

        CreatureAI* GetAI(Creature* c) const
        {
            return new npc_brewmaidenAI(c);
        }
};

void AddSC_brewfest()
{
    new npc_coren_direbrew();
    new npc_brewmaiden();
}
