class npc_bethor_iceshard : public CreatureScript
{
public:
    npc_bethor_iceshard() : CreatureScript("npc_bethor_iceshard")
    {
    }
    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt)
    { 
        if (quest->GetQuestId() == QUEST_THE_PRODIGAL_LICH_RETURNS)
        {
            CAST_AI(npc_bethor_iceshard::npc_bethor_iceshardAI, creature->AI())->startEvent = true;
            CAST_AI(npc_bethor_iceshard::npc_bethor_iceshardAI, creature->AI())->_player = player;
        }
        return true; 
    }
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bethor_iceshardAI(creature);
    }
    struct npc_bethor_iceshardAI : public ScriptedAI
    {
        npc_bethor_iceshardAI(Creature* creature) : ScriptedAI(creature)
        {
        }
        void Reset() override
        {
            startEvent = false;
            _player = NULL;
            timer = 2000;
            summon = NULL;
            phase = 0;
        }
        bool startEvent;
        Player * _player;
        uint32 timer;
        Creature * summon;
        int phase;
        void UpdateAI(uint32 diff) override
        {
            if (startEvent)
            {
                switch (phase)
                {
                case 0:
                    if (timer < diff)
                    {
                        me->CastSpell(me, 7762, false);
                        phase++;
                        timer = 2000;
                        break;
                    }
                    else
                    {
                        timer -= diff;
                    }
                case 1:
                    if (timer < diff)
                    {
                        Position position;
                        position.m_positionX = 1767.448486f;
                        position.m_positionY = 60.790691f;
                        position.m_positionZ = -46.320290f;
                        position.m_orientation = 1.768230f;
                        summon = me->SummonCreature(5666, position, TEMPSUMMON_TIMED_DESPAWN, 20000);
                        summon->SetWalk(true);
                        position.m_positionX = 1766.795288f;
                        position.m_positionY = 63.132595f;
                        position.m_positionZ = -46.320072f;
                        position.m_orientation = 1.803555f;
                        summon->GetMotionMaster()->MovePoint(0, position, false);
                        phase++;
                        timer = 2000;
                    }
                    else
                    {
                        timer -= diff;
                    }
                    break;
                case 2 :
                    if (timer < diff)
                    {
                        me->MonsterSay("It has been a long time, Bethor, my friend.", 0, summon);
                        timer = 3000;
                        phase++;
                    }
                    else
                    {
                        timer -= diff;
                    }
                    break;
                case 3 :
                    if (timer < diff)
                    {
                        summon->MonsterSay("When time permits, we must speak at length. For we have much to discuss.", 0, summon);
                        timer = 13000;
                        phase++;
                    }
                    else
                    {
                        timer -= diff;
                    }
                    break;
                case 4:
                    if (timer < diff)
                    {
                        summon->MonsterSay("And thank you, $Name. Without your aid I may never have found my way to the Forsaken.", 0, summon);
                        timer = 1000;
                        phase++;
                    }
                    else
                    {
                        timer -= diff;
                    }
                    break;
                default:
                    startEvent = false;
                    break;
                }

            }
        }
    };
};
