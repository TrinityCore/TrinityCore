#include "violet_hold_assault.h"

enum Says
{
    SAY_AGGRO = 2,
    SAY_DEATH = 7,
};

enum Spells
{
    SPELL_FINGER_LASER = 201159, //Delta Finger Laser X-treme!!!
    SPELL_ELEMENTIUM_BOMB = 201240,
    SPELL_OVERLOADED_E_BOMB = 201432,
    SPELL_ROCKET_CHICKEN = 201392,
    SPELL_REINFORCED_ROCKET_CHICKEN = 201438,
    SPELL_MILLIFICENTS_RAGE = 201572,
    SPELL_MILLIFICENTS_ANGRY = 201491,

    //Summons
    SPELL_EXPLOSION = 201291,
    SPELL_DISARMING = 201265,
    SPELL_EJECT_ALL_PASSENGERS = 158747,
    SPELL_SQUIRREL_SEARCH = 201305,
    SPELL_SQUIRREL_CHARGE = 201302,
    SPELL_OVERLOADED = 201434,
    SPELL_OVERLOADED_SUM = 201436,

    SPELL_CHICKEN_SWARM_ROCKETS = 201356,
    SPELL_SWARM_ROCKETS_SEARCH = 201386,
    SPELL_SWARM_ROCKETS_DMG = 201387,
    SPELL_ROCKET_CHICKEN_ROCKET = 201369,
    SPELL_THORIUM_PLATING = 201441,

    //?
    SPELL_MILLIFICENTS_IRE = 208114,
};

enum eEvents
{
    EVENT_FINGER_LASER = 1,
    EVENT_ELEMENTIUM_BOMB = 2,
    EVENT_ROCKET_CHICKEN = 3,

    EVENT_1,
    EVENT_2,
};

enum Misc
{
    DATA_ANGRY,
};

//101976
class boss_millificent_manastorm : public CreatureScript
{
public:
    boss_millificent_manastorm() : CreatureScript("boss_millificent_manastorm") {}

    struct boss_millificent_manastormAI : public BossAI
    {
        boss_millificent_manastormAI(Creature* creature) : BossAI(creature, DATA_MILLIFICENT), enrage(false), timer(0), phase(0), event(false), end(false), check(false)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            removeloot = false;
            angrycomplete = false;
        }

        bool enrage;
        bool removeloot;
        bool angrycomplete;

        uint32 timer;
        uint32 phase;
        uint32 CheckTimer;
        uint8 emoteRec;
        bool event;
        bool end;
        bool check;
        // Creature* image;
        ObjectGuid imageGUID;

        void Initialize()
        {
            CheckTimer = 2000;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_ANGRY:
                return angrycomplete ? 1 : 0;
            }

            return 0;
        }

        void Reset() override
        {
            enrage = false;
            angrycomplete = false;

            timer = 0;
            phase = 0;
            event = false;
            end = false;
            check = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
          //  ZoneTalk(SAY_AGGRO, nullptr);
            events.RescheduleEvent(EVENT_FINGER_LASER, 6000); //47:53, 48:00, 48:09, 48:19, 48:27
            events.RescheduleEvent(EVENT_ELEMENTIUM_BOMB, 7000); //47:54, 48:15, 48:33, 48:51
            events.RescheduleEvent(EVENT_ROCKET_CHICKEN, 24000); //48:11, 48:30, 48:48
            phase = 4;
            timer = 5000;
            event = true;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (removeloot)
                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (me->HealthBelowPct(50) && !enrage)
            {
                enrage = true;
                if (!ObjectAccessor::GetCreature(*me, imageGUID))
                    DoCast(me, SPELL_MILLIFICENTS_RAGE, true);
                phase = 8;
                timer = 1000;
                event = true;

            }

            if (me->HealthBelowPct(9) && !end)
            {
                if (Creature* image = ObjectAccessor::GetCreature(*me, imageGUID))
                {
                    end = true;
                    me->AttackStop();
                    // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                 //   image->AI()->ZoneTalk(7, nullptr);
                    DoCast(202310); // stun
                    phase = 13;
                    timer = 5000;
                    event = true;

                }

                if (me->AI()->GetData(DATA_ANGRY) && end)
                    instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 208122);
            }
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_REMOVE_LOOT)
                removeloot = true;

            if (action == 1)
            {
                timer = 6000;
                phase = 1;
                if (Creature* image = me->SummonCreature(102040, 4627.0f, 4060.36f, 82.63f, 5.46f))
                {
                    image->CastSpell(image, 201239);
                    imageGUID = image->GetGUID();
                }
               // ZoneTalk(0, nullptr);
                event = true;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 2 && !check)
            {
                check = true;
                DoCast(201581);
               // if (Creature* image = ObjectAccessor::GetCreature(*me, imageGUID))
                   // image->AI()->ZoneTalk(8, nullptr);
                    //me->SummonGameObject(246430, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, DAY);
            }
        }

        void ReceiveEmote(Player* player, uint32 textEmote) override
        {
            if (textEmote == TEXT_EMOTE_LAUGH && !angrycomplete)
            {
                ++emoteRec;
                if (emoteRec >= 5)
                {
                    DoCast(player, SPELL_MILLIFICENTS_ANGRY, true);
                    DoCast(player, SPELL_MILLIFICENTS_RAGE, true);
                    angrycomplete = true;
                }
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == 201581)
            {
                me->GetMotionMaster()->MovePoint(2, 4555.65f, 4014.96f, 83.67f);
                phase = 15;
                timer = 13000;
                event = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (event)
            {
                if (Creature* image = ObjectAccessor::GetCreature(*me, imageGUID))
                {
                    switch (phase)
                    {
                    case 1:
                        if (timer < diff) {
                         //   image->AI()->ZoneTalk(0, nullptr);
                            phase++;
                            timer = 8000;
                        }
                        else timer -= diff;
                        break;
                    case 2:
                        if (timer < diff) {
                          //  ZoneTalk(1, nullptr);
                            phase++;
                            timer = 7000;
                        }
                        else timer -= diff;
                        break;
                    case 3:
                        if (timer < diff) {
                         //   image->AI()->ZoneTalk(1, nullptr);
                            phase = 0;
                            timer = 8000;
                            event = false;
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                        }
                        else timer -= diff;
                        break;
                    case 4:
                        if (timer < diff) {
                          //  ZoneTalk(3, nullptr);
                            phase++;
                            timer = 5000;
                        }
                        else timer -= diff;
                        break;
                    case 5:
                        if (timer < diff) {
                          //  image->AI()->ZoneTalk(2, nullptr);
                            phase++;
                            timer = 13000;
                        }
                        else timer -= diff;
                        break;
                    case 6:
                        if (timer < diff) {
                           // ZoneTalk(4, nullptr);  // Here comes the heat!
                            phase++;
                            timer = 5000;
                        }
                        else timer -= diff;
                        break;
                    case 7:
                        if (timer < diff) {
                           // image->AI()->ZoneTalk(3, nullptr);
                            phase = 0;
                            timer = 6000;
                            event = false;
                        }
                        else timer -= diff;
                        break;
                    case 8:
                        if (timer < diff) {
                          //  image->AI()->ZoneTalk(4, nullptr);
                            phase++;
                            timer = 6000;
                        }
                        else timer -= diff;
                        break;
                    case 9:
                        if (timer < diff) {
                         //   ZoneTalk(5, nullptr);
                            DoCast(me, SPELL_MILLIFICENTS_RAGE, true);
                            phase++;
                            timer = 5000;
                        }
                        else timer -= diff;
                        break;
                    case 10:
                        if (timer < diff) {
                          //  image->AI()->ZoneTalk(5, nullptr);
                            phase++;
                            timer = 6000;
                        }
                        else timer -= diff;
                        break;
                    case 11:
                        if (timer < diff) {
                           // ZoneTalk(6, nullptr);
                            phase++;
                            timer = 4000;
                        }
                        else timer -= diff;
                        break;
                    case 12:
                        if (timer < diff) {
                          //  image->AI()->ZoneTalk(6, nullptr);
                            phase = 0;
                            timer = 6000;
                            event = false;
                        }
                        else timer -= diff;
                        break;
                    case 13:
                        if (timer < diff) {
                         //   ZoneTalk(7, nullptr);
                            me->RemoveAurasDueToSpell(SPELL_MILLIFICENTS_RAGE);
                            phase++;
                            timer = 500;
                        }
                        else timer -= diff;
                        break;
                    case 14:
                        if (timer < diff) {
                            me->GetMotionMaster()->MovePoint(2, 4596.99f, 4014.73f, 83.31f);
                            phase = 0;
                            timer = 5000;
                            event = false;
                        }
                        else timer -= diff;
                        break;
                    case 15:
                        if (timer < diff) {
                          //  image->AI()->ZoneTalk(9, nullptr);
                            image->GetMotionMaster()->MovePoint(0, 4596.92f, 4015.52f, 83.31f);
                            phase++;
                            timer = 12000;
                        }
                        else timer -= diff;
                        break;
                    case 16:
                        if (timer < diff) {
                            image->SetOrientation(0.07f);
                           // image->AI()->ZoneTalk(10, nullptr);
                            image->DespawnOrUnsummon(6000);
                            instance->SetBossState(DATA_MILLIFICENT, DONE);
                            me->SetVisible(false);
                            phase = 0;
                            timer = 5000;
                            event = false;
                        }
                        else timer -= diff;
                        break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (end)
                return;

            if (CheckTimer <= diff)
            {
                if (me->IsInCombat() && me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC && !angrycomplete)
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->HasAura(176180) && !player->HasAura(201491))
                            {
                                angrycomplete = true;
                                me->AddAura(201491, player);
                                DoCast(me, SPELL_MILLIFICENTS_RAGE, true);
                            }

                }
                CheckTimer = 2000;
            }
            else CheckTimer -= diff;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FINGER_LASER:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(pTarget, SPELL_FINGER_LASER);
                    events.RescheduleEvent(EVENT_FINGER_LASER, 7000);
                    break;
                case EVENT_ELEMENTIUM_BOMB:
                    if (!me->HasAura(SPELL_MILLIFICENTS_RAGE))
                        DoCast(SPELL_ELEMENTIUM_BOMB);
                    else
                        DoCast(SPELL_OVERLOADED_E_BOMB);
                    events.RescheduleEvent(EVENT_ELEMENTIUM_BOMB, 18000);
                    break;
                case EVENT_ROCKET_CHICKEN:
                    if (!me->HasAura(SPELL_MILLIFICENTS_RAGE))
                        DoCast(SPELL_ROCKET_CHICKEN);
                    else
                        DoCast(SPELL_REINFORCED_ROCKET_CHICKEN);
                    events.RescheduleEvent(EVENT_ROCKET_CHICKEN, 18000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_millificent_manastormAI(creature);
    }
};

//102043, 102136
class npc_millificent_elementium_squirrel_bomb : public CreatureScript
{
public:
    npc_millificent_elementium_squirrel_bomb() : CreatureScript("npc_millificent_elementium_squirrel_bomb") {}

    bool OnGossipHello(Player* player, Creature* me)
    {
        player->CastSpell(me, SPELL_DISARMING);
        return true;
    }

    struct npc_millificent_elementium_squirrel_bombAI : public ScriptedAI
    {
        npc_millificent_elementium_squirrel_bombAI(Creature* creature) : ScriptedAI(creature), disarmed(false), diedTimer(0)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
        }

        bool disarmed;
        uint16 diedTimer;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(SPELL_EXPLOSION);
            disarmed = false;
            diedTimer = 10500;

            if (me->GetEntry() == 102136)
                DoCast(me, SPELL_OVERLOADED, true);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_DISARMING)
            {
                me->RemoveAurasDueToSpell(SPELL_OVERLOADED);
                me->InterruptNonMeleeSpells(false);
                //DoCast(me, SPELL_EJECT_ALL_PASSENGERS, true);

                diedTimer = 2000;
                disarmed = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (diedTimer)
            {
                if (diedTimer <= diff)
                {
                    if (!disarmed)
                    {
                        for (int8 i = 0; i < 3; i++)
                            DoCast(me, SPELL_OVERLOADED_SUM, true);
                    }
                    diedTimer = 0;
                    Unit::Kill(me, me);
                }
                else
                    diedTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_millificent_elementium_squirrel_bombAI(creature);
    }
};

//102103, 102139
class npc_millificent_thorium_rocket_chicken : public CreatureScript
{
public:
    npc_millificent_thorium_rocket_chicken() : CreatureScript("npc_millificent_thorium_rocket_chicken") {}

    struct npc_millificent_thorium_rocket_chickenAI : public ScriptedAI
    {
        npc_millificent_thorium_rocket_chickenAI(Creature* creature) : ScriptedAI(creature), rocketCastTimer(0)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint16 rocketCastTimer;

        void Reset() override
        {
            rocketCastTimer = 2000;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            DoZoneInCombat(me, 120.0f);
            DoCast(me, SPELL_CHICKEN_SWARM_ROCKETS, true);

            if (me->GetEntry() == 102139)
                DoCast(me, SPELL_THORIUM_PLATING, true);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_SWARM_ROCKETS_SEARCH)
                DoCast(me, SPELL_SWARM_ROCKETS_DMG, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (rocketCastTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                {
                    me->SetFacingToObject(pTarget);
                    DoCast(pTarget, SPELL_ROCKET_CHICKEN_ROCKET);
                }
                rocketCastTimer = 4000;
            }
            else
                rocketCastTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_millificent_thorium_rocket_chickenAI(creature);
    }
};

//102137 
class npc_millificent_mechanical_bomb_squirrel : public CreatureScript
{
public:
    npc_millificent_mechanical_bomb_squirrel() : CreatureScript("npc_millificent_mechanical_bomb_squirrel") {}

    struct npc_millificent_mechanical_bomb_squirrelAI : public ScriptedAI
    {
        npc_millificent_mechanical_bomb_squirrelAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(EVENT_1, 100);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_SQUIRREL_SEARCH)
                DoCast(target, SPELL_SQUIRREL_CHARGE, true);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1003)
                events.RescheduleEvent(EVENT_2, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    DoCast(me, SPELL_SQUIRREL_SEARCH, true);
                    events.RescheduleEvent(EVENT_2, 3000);
                    break;
                case EVENT_2:
                    me->Kill(me, false);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_millificent_mechanical_bomb_squirrelAI(creature);
    }
};

void AddSC_boss_millificient_manastorm()
{
    new boss_millificent_manastorm();
    new npc_millificent_elementium_squirrel_bomb();
    new npc_millificent_thorium_rocket_chicken();
    new npc_millificent_mechanical_bomb_squirrel();
}
