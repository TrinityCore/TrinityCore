#include "court_of_stars.h"

enum Says
{
    SAY_AGGRO_BAD = 3,
    SAY_KILL = 4,
    SAY_AGGRO = 5,
    SAY_DEATH = 6,
    SAY_BURNING = 7
};

enum Spells
{
    SPELL_BURNING_INTENSITY = 207906,
    SPELL_WITHERING_SOUL = 208165,
    SPELL_INFERNAL_ERUPTION = 207881,

    SPELL_BOND_OF_FLAME_AT = 209723, //Boss
    SPELL_BOND_OF_STRENGTH_AT = 207819, //NPC_JAZSHARIU
    SPELL_BOND_OF_CRUELTY_AT = 209717, //NPC_BAALGAR_THE_WATCHFUL
    SPELL_BOND_OF_CUNNING_AT = 209712, //NPC_IMACUTYA

    //Christmas
    SPELL_CHRISTMAS_CAP = 220861
};

enum eEvents
{
    EVENT_BURNING_INTENSITY = 1,
    EVENT_WITHERING_SOUL = 2,
    EVENT_INFERNAL_ERUPTION = 3,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

Position const mBossPos[3] =
{
    {1081.21f, 3313.43f, 25.05f, 0.23f}, //NPC_JAZSHARIU
    {1083.43f, 3307.68f, 24.98f, 0.81f}, //NPC_BAALGAR_THE_WATCHFUL
    {1088.88f, 3306.01f, 25.05f, 1.43f}  //NPC_IMACUTYA
};

Position const patrolPos[3] =
{
    {1161.85f, 3279.33f, 20.00f, 3.82f}, //NPC_FELBOUND_ENFORCER
    {1041.14f, 3388.77f, 19.96f, 3.27f},
    {1182.30f, 3350.27f, 20.00f, 1.57f}
};

Position const gCheckPos[3] =
{
    {1133.87f, 3278.71f, 20.1f},
    {1156.15f, 3327.12f, 20.9f},
    {1053.71f, 3357.99f, 19.84f}
};

//104217
class boss_talixae_flamewreath : public CreatureScript
{
public:
    boss_talixae_flamewreath() : CreatureScript("boss_talixae_flamewreath") {}

    struct boss_talixae_flamewreathAI : public BossAI
    {
        boss_talixae_flamewreathAI(Creature* creature) : BossAI(creature, DATA_TALIXAE), summons(me)
        {
            SummonEventCreature();
        }

        SummonList summons;
        ObjectGuid guardsGUID[3];

        uint8 pDiedCount;
        uint8 guardsDiedCount;

        void SummonEventCreature()
        {
            pDiedCount = 0;
            guardsDiedCount = 0;

            if (Creature* guard = me->SummonCreature(NPC_JAZSHARIU, mBossPos[0]))
                guardsGUID[2] = guard->GetGUID();
            if (Creature* guard = me->SummonCreature(NPC_BAALGAR_THE_WATCHFUL, mBossPos[1]))
                guardsGUID[1] = guard->GetGUID();
            if (Creature* guard = me->SummonCreature(NPC_IMACUTYA, mBossPos[2]))
                guardsGUID[0] = guard->GetGUID();

            for (int8 i = 0; i < 3; i++)
                me->SummonCreature(NPC_FELBOUND_ENFORCER, patrolPos[i]);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            switch (summon->GetEntry())
            {
            case NPC_FELBOUND_ENFORCER:
            {
                summon->AI()->Talk(0);
                for (uint8 i = pDiedCount; i < 3; i++)
                {
                    if (Creature* guard = me->GetCreature(*me, guardsGUID[i]))
                        if (guard && guard->IsAlive())
                        {
                            for (uint8 n = 0; n < 3; n++)
                                if (summon->GetDistance(gCheckPos[n]) < 40.0f)
                                {
                                    Talk(pDiedCount);
                                    pDiedCount++;
                                    guard->SetHomePosition(gCheckPos[n]);
                                    guard->GetMotionMaster()->MovePoint(1, gCheckPos[n]);
                                }
                            return;
                        }
                }
                break;
            }
            case NPC_JAZSHARIU:
            case NPC_BAALGAR_THE_WATCHFUL:
            case NPC_IMACUTYA:
                guardsDiedCount++;
                if (guardsDiedCount == 3)
                    me->RemoveAurasDueToSpell(SPELL_BOND_OF_FLAME_AT);
                break;
            }
        }

        void Reset() override
        {
            _Reset();

            if (guardsDiedCount < 3)
                DoCast(me, SPELL_BOND_OF_FLAME_AT, true);
            if (me->HasAura(SPELL_CHRISTMAS_CAP))
                me->RemoveAura(SPELL_CHRISTMAS_CAP);
            
        }

        void JustEngagedWith(Unit* who) override
        {
            if (guardsDiedCount < 3)
                Talk(SAY_AGGRO_BAD);
            else
                Talk(SAY_AGGRO);

            _JustEngagedWith();

            for (int8 i = 0; i < 3; i++)
                if (Creature* guard = me->GetCreature(*me, guardsGUID[i]))
                    if (guard && guard->IsAlive())
                        guard->AI()->DoZoneInCombat(guard, 100.0f);

            events.RescheduleEvent(EVENT_BURNING_INTENSITY, 6000);
            events.RescheduleEvent(EVENT_WITHERING_SOUL, 12000);
            events.RescheduleEvent(EVENT_INFERNAL_ERUPTION, 20000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            if (Creature* lilet = me->FindNearestCreature(106468, 100.0f, true))
                lilet->AI()->Talk(0);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
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
                case EVENT_BURNING_INTENSITY:
                    DoCast(SPELL_BURNING_INTENSITY);
                    Talk(SAY_BURNING);
                    break;
                case EVENT_WITHERING_SOUL:
                    DoCast(SPELL_WITHERING_SOUL);
                    events.RescheduleEvent(EVENT_WITHERING_SOUL, 15000);
                    break;
                case EVENT_INFERNAL_ERUPTION:
                    DoCast(SPELL_INFERNAL_ERUPTION);
                    events.RescheduleEvent(EVENT_INFERNAL_ERUPTION, 32000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_talixae_flamewreathAI(creature);
    }
};

//104273, 104274, 104275
class npc_talixae_guards : public CreatureScript
{
public:
    npc_talixae_guards() : CreatureScript("npc_talixae_guards") {}

    struct npc_talixae_guardsAI : public ScriptedAI
    {
        npc_talixae_guardsAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset() override
        {
            events.Reset();

            switch (me->GetEntry())
            {
            case NPC_JAZSHARIU:
                DoCast(me, SPELL_BOND_OF_STRENGTH_AT, true);
                break;
            case NPC_BAALGAR_THE_WATCHFUL:
                DoCast(me, SPELL_BOND_OF_CRUELTY_AT, true);
                break;
            case NPC_IMACUTYA:
                DoCast(me, SPELL_BOND_OF_CUNNING_AT, true);
                break;
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            if (me->GetEntry() == 104275)
                events.RescheduleEvent(EVENT_1, 3000); // 209378 17
            if (me->GetEntry() == 104274)
                events.RescheduleEvent(EVENT_2, 3000); // 207980 13
            if (me->GetEntry() == 104273)
                events.RescheduleEvent(EVENT_3, 7000); // 207979 11
        }

        void UpdateAI(uint32 diff) override
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
                case EVENT_1:
                    DoCast(209378);
                    events.RescheduleEvent(EVENT_1, 17000);
                    break;
                case EVENT_2:
                    DoCast(207980);
                    events.RescheduleEvent(EVENT_2, 13000);
                    break;
                case EVENT_3:
                    DoCast(207979);
                    events.RescheduleEvent(EVENT_3, 11000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_talixae_guardsAI(creature);
    }
};

void AddSC_boss_talixae_flamewreath()
{
    new boss_talixae_flamewreath();
    new npc_talixae_guards();
}
