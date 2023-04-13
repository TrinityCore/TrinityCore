///*================
//    UWoW.biz
//================*/
//
//const Position mfPos[22] =
//{
//    // Snarler spawn
//    { -3924.37f, 6303.53f, 17.59f, 1.88f },
//    { -4011.98f, 6416.34f, 14.75f, 3.73f },
//    { -4097.92f, 6458.10f, 14.80f, 3.19f },
//    { -4170.17f, 6503.14f, 13.41f, 1.55f },
//    { -4266.80f, 6521.71f, 14.39f, 2.68f },
//    { -4318.40f, 6601.40f, 9.853f, 1.47f },
//    { -4056.26f, 6664.42f, 13.22f, 2.99f },
//    { -4009.05f, 6561.04f, 17.15f, 4.37f },
//    { -3932.42f, 6584.56f, 12.91f, 3.70f },
//    { -3838.57f, 6461.64f, 11.91f, 3.92f },
//    { -4268.83f, 6678.51f, 9.731f, 4.84f },
//    // Dreadhowl spawn
//    { -4225.82f, 6556.37f, 14.61f, 5.84f },
//    { -4141.07f, 6523.72f, 16.81f, 6.06f },
//    { -4073.94f, 6580.90f, 16.70f, 0.27f },
//    { -3957.37f, 6617.45f, 12.66f, 0.43f },
//    { -3865.21f, 6524.91f, 18.89f, 2.94f },
//    { -3872.48f, 6498.26f, 17.90f, 3.39f },
//    { -3914.52f, 6398.61f, 13.61f, 4.04f },
//    { -4038.38f, 6514.68f, 13.36f, 3.01f },
//    { -4344.90f, 6583.72f, 10.64f, 1.75f },
//    { -4193.76f, 6122.50f, 13.00f, 6.06f },
//    { -4082.68f, 6121.38f, 17.41f, 5.37f }
//};
//
//Position const SpawnRingsAT[57] =
//{
//    { -4278.502f, 6305.27f, 55.3745f },
//    { -4387.158f, 6218.971f, 85.1059f },
//    { -4384.887f, 6059.405f, 30.4877f },
//    { -4464.976f, 6074.34f, 56.51786f },
//    { -4416.028f, 6263.413f, 30.60862f },
//    { -4411.45f, 6469.171f, 37.86602f },
//    { -4417.354f, 6368.175f, 34.5676f },
//    { -4061.708f, 6240.754f, 55.67439f },
//    { -3976.156f, 6239.41f, 59.68959f },
//    { -4298.453f, 6435.71f, 99.74864f },
//    { -4000.738f, 6319.748f, 61.96915f },
//    { -4123.092f, 6420.391f, 79.5131f },
//    { -4200.064f, 6404.912f, 49.83862f },
//    { -4153.389f, 6421.354f, 49.73269f },
//    { -4177.096f, 6412.299f, 53.74761f },
//    { -3994.031f, 6130.03f, 143.9004f },
//    { -4152.132f, 6029.343f, 112.4916f },
//    { -4276.29f, 6004.999f, 98.62133f },
//    { -4327.917f, 6013.772f, 118.3816f },
//    { -4282.986f, 6089.893f, 74.05066f },
//    { -4204.17f, 6195.492f, 80.76868f },
//    { -4127.677f, 6190.193f, 87.08089f },
//    { -4125.719f, 6353.675f, 70.76109f },
//    { -4219.653f, 6288.33f, 56.897f },
//    { -4088.217f, 6675.956f, 53.79656f },
//    { -4162.233f, 6763.257f, 25.24334f },
//    { -4231.226f, 6586.085f, 93.67531f },
//    { -4265.304f, 6513.369f, 93.58659f },
//    { -4163.147f, 6539.726f, 78.76099f },
//    { -3860.811f, 6494.958f, 97.87495f },
//    { -4015.245f, 6472.497f, 85.551f },
//    { -3931.849f, 6370.7f, 73.34687f },
//    { -3871.005f, 6321.215f, 78.78794f },
//    { -3888.948f, 6244.342f, 71.50654f },
//    { -4311.99f, 5950.87f, 104.305f },
//    { -4237.936f, 5942.774f, 117.577f },
//    { -4196.168f, 5890.585f, 127.7626f },
//    { -4142.12f, 5947.434f, 119.1986f },
//    { -3812.991f, 6369.193f, 118.9729f },
//    { -3861.29f, 6380.367f, 55.15146f },
//    { -3794.465f, 6427.009f, 69.57449f },
//    { -3781.519f, 6438.263f, 61.80006f },
//    { -3754.766f, 6475.822f, 64.21665f },
//    { -3833.854f, 6670.972f, 60.10976f },
//    { -4319.019f, 6655.865f, 24.96414f },
//    { -3760.503f, 6175.529f, 123.6823f },
//    { -4149.393f, 6684.266f, 31.54233f },
//    { -3951.658f, 6719.8f, 37.38012f },
//    { -4147.766f, 6777.004f, 32.39946f },
//    { -3792.443f, 6895.78f, 26.00098f },
//    { -3740.898f, 6846.799f, 56.73854f },
//    { -3777.356f, 6723.497f, 24.15144f },
//    { -3880.603f, 6715.769f, 22.8216f },
//    { -4068.458f, 5933.453f, 115.6255f },
//    { -3969.863f, 5989.153f, 113.2228f },
//    { -3887.325f, 6097.111f, 116.1136f },
//    { -3817.255f, 6127.589f, 126.3984f }
//};
//
//Position const FireworksPosition[80] =
//{
//    { -4544.65f, 6334.98f, 52.1605f, 5.91667f },
//    { -4541.89f, 6325.75f, 41.7596f, 5.91667f },
//    { -4540.63f, 6364.69f, 44.9669f, 0.0f },
//    { -4537.7f, 6400.11f, 36.5094f, 5.96903f },
//    { -4534.14f, 6296.77f, 43.5847f, 5.91667f },
//    { -4533.17f, 6343.92f, 50.1097f, 0.0f },
//    { -4531.12f, 6310.38f, 45.1551f, 0.0f },
//    { -4531.03f, 6280.25f, 54.6476f, 0.0f },
//    { -4529.45f, 6354.64f, 55.1482f, 0.0f },
//    { -4528.64f, 6266.19f, 31.9376f, 5.91667f },
//    { -4527.65f, 6332.33f, 40.1272f, 5.07891f },
//    { -4526.68f, 6363.64f, 44.7062f, 0.0f },
//    { -4525.71f, 6288.72f, 48.1038f, 0.0f },
//    { -4525.63f, 6384.03f, 53.5779f, 0.0f },
//    { -4524.67f, 6316.6f, 48.7323f, 0.0f },
//    { -4520.83f, 6260.86f, 37.8736f, 0.0f },
//    { -4520.3f, 6292.53f, 40.4214f, 5.96903f },
//    { -4519.77f, 6403.69f, 43.1206f, 5.86431f },
//    { -4519.41f, 6272.97f, 51.5572f, 0.0f },
//    { -4519.25f, 6348.09f, 52.1605f, 5.91667f },
//    { -4517.73f, 6338.35f, 34.5586f, 0.0f },
//    { -4516.94f, 6326.41f, 29.2419f, 0.0f },
//    { -4514.63f, 6318.62f, 34.7368f, 0.0f },
//    { -4503.62f, 6465.65f, 44.3478f, 6.02139f },
//    { -4493.34f, 6473.99f, 35.7746f, 5.65487f },
//    { -4492.24f, 6465.79f, 31.6434f, 5.98648f },
//    { -4488.78f, 6481.73f, 38.9686f, 5.53269f },
//    { -4487.85f, 6491.03f, 33.1126f, 5.42798f },
//    { -4482.63f, 6500.52f, 37.9616f, 5.95157f },
//    { -4477.26f, 6491.57f, 31.0258f, 5.68977f },
//    { -4476.76f, 6482.15f, 29.8048f, 5.79449f },
//    { -4473.32f, 6507.6f, 30.3042f, 5.89921f },
//    { -4472.88f, 6498.33f, 40.7714f, 6.02139f },
//    { -4472.76f, 6491.1f, 36.1525f, 5.65487f },
//    { -4467.58f, 6508.39f, 45.1855f, 5.86431f },
//    { -4467.15f, 6501.41f, 36.9703f, 5.95157f },
//    { -4466.62f, 6494.08f, 33.7662f, 5.5676f },
//    { -4465.95f, 6512.94f, 39.878f, 5.79449f },
//    { -4458.28f, 6506.05f, 35.9752f, 5.21854f },
//    { -4333.28f, 6328.26f, 50.6691f, 6.07375f },
//    { -4327.08f, 6312.23f, 50.9248f, 0.837758f },
//    { -4308.33f, 6299.62f, 50.9248f, 0.0349062f },
//    { -4280.79f, 6247.96f, 61.2803f, 0.0f },
//    { -4235.35f, 6299.37f, 59.2793f, 0.471238f },
//    { -4228.04f, 6366.35f, 48.0665f, 5.21854f },
//    { -4224.79f, 6367.33f, 42.3254f, 5.44543f },
//    { -4222.59f, 6369.06f, 54.4394f, 4.62512f },
//    { -4220.52f, 6290.68f, 56.2118f, 1.51844f },
//    { -4199.27f, 6274.16f, 43.235f, 0.261798f },
//    { -4197.99f, 6292.5f, 75.3727f, 0.715585f },
//    { -4193.09f, 6406.92f, 59.2182f, 5.5676f },
//    { -4188.42f, 6410.98f, 63.6761f, 5.5676f },
//    { -4181.77f, 6415.56f, 58.8968f, 4.86947f },
//    { -4169.41f, 6419.68f, 68.0678f, 5.23599f },
//    { -4163.61f, 6270.24f, 62.7918f, 1.20428f },
//    { -4158.45f, 6423.26f, 58.8968f, 5.74214f },
//    { -4149.61f, 6323.87f, 39.8507f, 1.13446f },
//    { -4149.06f, 6321.79f, 37.9468f, 0.575957f },
//    { -4147.95f, 6271.83f, 73.3056f, 1.36136f },
//    { -4147.95f, 6271.83f, 73.3056f, 1.36136f },
//    { -4146.92f, 6406.8f, 67.5933f, 4.99164f },
//    { -4146.72f, 6318.32f, 45.121f, 1.13446f },
//    { -4146.29f, 6426.08f, 68.8216f, 5.74214f },
//    { -4133.4f, 6252.52f, 53.8934f, 1.53589f },
//    { -4124.62f, 6405.38f, 61.2377f, 4.71239f },
//    { -4116.79f, 6264.26f, 53.8934f, 1.13446f },
//    { -4111.1f, 6281.71f, 43.4595f, 0.0f },
//    { -4108.68f, 6400.98f, 81.9603f, 4.24115f },
//    { -4086.59f, 6247.51f, 68.6752f, 1.95477f },
//    { -4085.56f, 6397.07f, 56.9609f, 3.87463f },
//    { -4074.21f, 6378.33f, 49.9692f, 3.52557f },
//    { -4056.88f, 6282.83f, 54.621f, 0.0f },
//    { -4056.38f, 6244.72f, 59.0023f, 1.53589f },
//    { -4051.87f, 6361.73f, 74.6655f, 2.26892f },
//    { -4050.18f, 6240.66f, 64.5838f, 0.0f },
//    { -4049.27f, 6260.36f, 48.8318f, 5.07891f },
//    { -4037.0f, 6311.08f, 46.0511f, 5.07891f },
//    { -4030.94f, 6270.2f, 50.5471f, 5.91667f },
//    { -4029.15f, 6355.71f, 59.4579f, 3.14159f },
//    { -4025.65f, 6291.04f, 65.1026f, 0.0f }
//};
//
//enum Spells
//{
//    SPELL_DARKMOON_DEATHMATCH_TELE_1 = 108919,
//    SPELL_DARKMOON_DEATHMATCH_TELE_2 = 113212,
//    SPELL_DARKMOON_DEATHMATCH_TELE_3 = 113213,
//    SPELL_DARKMOON_DEATHMATCH_TELE_4 = 113216,
//    SPELL_DARKMOON_DEATHMATCH_TELE_5 = 113219,
//    SPELL_DARKMOON_DEATHMATCH_TELE_6 = 113224,
//    SPELL_DARKMOON_DEATHMATCH_TELE_7 = 113227,
//    SPELL_DARKMOON_DEATHMATCH_TELE_8 = 113228,
//    SPELL_RING_TOSS_HIT = 101699,
//    SPELL_RING_TOSS_MISS = 101697,
//    SPELL_RING_TOSS_MISS_2 = 101698,
//    SPELL_LANDING_RESULT_KILL_CREDIT = 100962,
//    SPELL_BULLSEYE = 62173,
//    SPELL_GREAT_SHOT = 62175,
//    SPELL_POOR_SHOT = 62179,
//    SPELL_CANNONBALL = 62244,
//    SPELL_TONK_TARGET = 62265,
//    SPELL_DARKMOON_MAGIC_WINGS = 102116,
//    SPELL_GOSSIP_CREATE_RIFLE = 101991,
//    SPELL_INDICATOR = 43313,
//    SPELL_INDICATOR_QUICK_SHOT = 101010,
//    SPELL_SUMMON_GNOLL = 102036,
//    SPELL_SUMMON_GNOLL_BABY = 102043,
//    SPELL_SUMMON_GNOLL_BONUS = 102044
//};
//
//enum Creatures
//{
//    NPC_DUBENKO = 54490,
//    NPC_TONK_TARGET = 33081,
//    NPC_DARKMOON_FAIRE_CANNON_TARGET = 33068,
//    NPC_DARKMOON_FAIRE_CANNON = 15218,
//    NPC_DARKMOON_FAIRE_TARGET = 24171
//};
//
//enum Events
//{
//    EVENT_SHOTEVENT_ACTIVE = 1,
//    EVENT_SHOTEVENT_PAUSE = 2
//};
//
//// 71992 - Moonfang <Darkmoon Den Mother>
//class boss_darkmoon_moonfang_mother : public CreatureScript
//{
//    enum eSay
//    {
//        SAY_SUMM_SNARLER = 0,
//        SAY_SUMM_DREADHOWL = 1,
//        SAY_SUMM_MOTHER = 2
//    };
//
//    enum eCreatures
//    {
//        NPC_MOONFANG_SNARLER = 56160,
//        NPC_MOONFANG_DREADHOWL = 71982
//    };
//
//    enum eSpells
//    {
//        SPELL_LEAP_FOR_THE_KILL = 144546,
//        SPELL_FANGS_OF_THE_MOON = 144700,
//        SPELL_MOONFANG_TEARS = 144702,
//        SPELL_CALL_THE_PACK = 144602,
//        SPELL_MOONFANG_CURSE = 144590
//    };
//
//public:
//    boss_darkmoon_moonfang_mother() : CreatureScript("boss_darkmoon_moonfang_mother") {}
//
//    struct boss_darkmoon_moonfang_motherAI : public ScriptedAI
//    {
//        boss_darkmoon_moonfang_motherAI(Creature* creature) : ScriptedAI(creature), summons(me)
//        {
//            me->SetVisible(false);
//            prevEvent1 = true;
//            prevEvent2 = false;
//            sDiedCount = 0;
//        }
//
//        EventMap events;
//        SummonList summons;
//
//        bool prevEvent1;
//        bool prevEvent2;
//        uint8 sDiedCount;
//
//        void Reset() override
//        {
//            events.Reset();
//            summons.DespawnAll();
//
//            if (prevEvent1)
//            {
//                SummonMoonfang();
//                ZoneTalk(SAY_SUMM_SNARLER);
//            }
//        }
//
//        void SummonMoonfang()
//        {
//            if (prevEvent1)
//                for (uint8 i = 0; i < 11; i++)
//                    me->SummonCreature(NPC_MOONFANG_SNARLER, mfPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
//
//            if (prevEvent2)
//                for (uint8 i = 11; i < 22; i++)
//                    me->SummonCreature(NPC_MOONFANG_DREADHOWL, mfPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
//        }
//
//        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//        {
//            if (prevEvent1 || prevEvent2)
//                sDiedCount++;
//
//            if (sDiedCount == 11)
//            {
//                prevEvent1 = false;
//                prevEvent2 = true;
//                ZoneTalk(SAY_SUMM_DREADHOWL);
//                SummonMoonfang();
//            }
//
//            if (sDiedCount == 22)
//            {
//                prevEvent2 = false;
//                me->SetVisible(true);
//                ZoneTalk(SAY_SUMM_MOTHER);
//            }
//        }
//
//        void EnterCombat(Unit* /*who*/) override
//        {
//            events.ScheduleEvent(EVENT_1, 0);       // cast leap
//            events.ScheduleEvent(EVENT_2, 10000);   // cast stuns the target
//            events.ScheduleEvent(EVENT_3, 8000);    // cast tears AOE
//            events.ScheduleEvent(EVENT_4, 64000);   // summon moonfangs
//            events.ScheduleEvent(EVENT_5, 180000);  // cast mind control
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            summons.Summon(summon);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim() && me->isInCombat())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
//                        DoCast(target, SPELL_LEAP_FOR_THE_KILL, false);
//
//                    events.ScheduleEvent(EVENT_1, 12000);
//                    break;
//                case EVENT_2:
//                    if (auto target = me->getVictim())
//                        DoCast(target, SPELL_FANGS_OF_THE_MOON, false);
//
//                    events.ScheduleEvent(EVENT_2, 10000);
//                    break;
//                case EVENT_3:
//                    DoCast(SPELL_MOONFANG_TEARS);
//                    events.ScheduleEvent(EVENT_3, 22000);
//                    break;
//                case EVENT_4:
//                    DoCast(SPELL_CALL_THE_PACK);
//                    events.ScheduleEvent(EVENT_4, 64000);
//                    break;
//                case EVENT_5:
//                    DoCast(SPELL_MOONFANG_CURSE);
//                    events.ScheduleEvent(EVENT_5, 180000);
//                    break;
//                default:
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_darkmoon_moonfang_motherAI(creature);
//    }
//};
//
//// Darkmoon Faire Gnolls - 54444, 54466, 54549
//class npc_darkmoon_faire_gnolls : public CreatureScript
//{
//    enum Spells
//    {
//        SPELL_WHACK = 102022,
//        SPELL_GNOLL_KILL_CREDIT = 101835
//    };
//
//public:
//    npc_darkmoon_faire_gnolls() : CreatureScript("npc_darkmoon_faire_gnolls") { }
//
//    struct npc_darkmoon_faire_gnollsAI : public Scripted_NoMovementAI
//    {
//        npc_darkmoon_faire_gnollsAI(Creature* c) : Scripted_NoMovementAI(c)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
//        }
//
//        EventMap events;
//
//        void Reset() override
//        {
//            me->DespawnOrUnsummon(3000);
//        }
//
//        void SpellHit(Unit* pCaster, const SpellInfo* Spell) override
//        {
//            if (Spell->Id == SPELL_WHACK)
//            {
//                DoCast(pCaster, SPELL_GNOLL_KILL_CREDIT);
//                me->Kill(me);
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_darkmoon_faire_gnollsAI(creature);
//    }
//};
//
//// Darkmoon Faire Gnoll Holder - 54547
//struct npc_darkmoon_faire_gnoll_holder : public ScriptedAI
//{
//    npc_darkmoon_faire_gnoll_holder(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    ObjectGuid owner;
//
//    void Reset() override
//    {
//        events.ScheduleEvent(EVENT_1, 3000);
//    }
//
//    void IsSummonedBy(Unit* who) override
//    {
//        owner = who->GetGUID();
//        me->AddPlayerInPersonnalVisibilityList(owner);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//            {
//                std::list<Creature*> creatures;
//                me->GetCreatureListWithEntryInGrid(creatures, 54546, 40.0f);
//                if (!creatures.empty())
//                {
//                    Trinity::Containers::RandomResizeList(creatures, 1);
//                    uint32 Spells[3] =
//                    {
//                        SPELL_SUMMON_GNOLL,
//                        SPELL_SUMMON_GNOLL_BABY,
//                        SPELL_SUMMON_GNOLL_BONUS,
//                    };
//                    uint8 rand = urand(0, 3);
//
//                    if (auto player = ObjectAccessor::GetPlayer(*me, owner))
//                        if (auto target = creatures.front())
//                            player->CastSpell(target, Spells[rand], true);
//                }
//                events.ScheduleEvent(EVENT_1, 2000);
//                break;
//            }
//            }
//        }
//    }
//};
//
//// Rinling - 14841
//struct npc_darkmoon_faire_rinling : public ScriptedAI
//{
//    npc_darkmoon_faire_rinling(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//
//    void Reset() override
//    {
//        events.ScheduleEvent(EVENT_SHOTEVENT_ACTIVE, 3000);
//    }
//
//    void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
//    {
//        if (action == 1)
//        {
//            player->CastSpell(player, SPELL_GOSSIP_CREATE_RIFLE, true);
//            player->CLOSE_GOSSIP_MENU();
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_SHOTEVENT_ACTIVE:
//            {
//                std::list<Creature*> creatures;
//                me->GetCreatureListWithEntryInGrid(creatures, NPC_DARKMOON_FAIRE_TARGET, 15.0f);
//                if (!creatures.empty())
//                {
//                    Trinity::Containers::RandomResizeList(creatures, 1);
//
//                    if (Creature* pTarget = creatures.front())
//                    {
//                        pTarget->CastSpell(pTarget, SPELL_INDICATOR, true);
//                        pTarget->CastSpell(pTarget, SPELL_INDICATOR_QUICK_SHOT, true);
//                    }
//                }
//                events.ScheduleEvent(EVENT_SHOTEVENT_PAUSE, 3000);
//                break;
//            }
//            case EVENT_SHOTEVENT_PAUSE:
//            {
//                std::list<Creature*> creatures;
//                me->GetCreatureListWithEntryInGrid(creatures, NPC_DARKMOON_FAIRE_TARGET, 15.0f);
//                if (!creatures.empty())
//                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
//                        (*iter)->RemoveAura(SPELL_INDICATOR);
//
//                events.ScheduleEvent(EVENT_SHOTEVENT_ACTIVE, 3000);
//                break;
//            }
//            }
//        }
//    }
//};
//
//class spell_darkmoon_cannon_prep : public AuraScript
//{
//    PrepareAuraScript(spell_darkmoon_cannon_prep);
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (Unit* pCaster = GetCaster())
//            pCaster->SetControlled(true, UNIT_STATE_ROOT);
//    }
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (Unit* pCaster = GetCaster())
//        {
//            pCaster->SetControlled(false, UNIT_STATE_ROOT);
//
//            if (Creature* CanonTrigger = pCaster->FindNearestCreature(NPC_DARKMOON_FAIRE_CANNON, 30.0f))
//                CanonTrigger->CastSpell(pCaster, SPELL_DARKMOON_MAGIC_WINGS, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectApply += AuraEffectApplyFn(spell_darkmoon_cannon_prep::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
//        AfterEffectRemove += AuraEffectRemoveFn(spell_darkmoon_cannon_prep::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////62244
//class spell_darkmoon_cannonball : public AuraScript
//{
//    PrepareAuraScript(spell_darkmoon_cannonball);
//
//    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
//    {
//        Unit* pCaster = GetCaster();
//        if (!pCaster)
//            return;
//
//        if (pCaster->IsInWater())
//            if (Creature* CanonTrigger = pCaster->FindNearestCreature(NPC_DARKMOON_FAIRE_CANNON_TARGET, 30.0f))
//            {
//                pCaster->CastSpell(pCaster, GetSpellInfo()->Effects[EFFECT_0]->BasePoints, true);
//
//                if (pCaster->IsInRange(CanonTrigger, 0.0f, 1.0f))
//                {
//                    for (uint8 i = 0; i < 5; ++i)
//                        pCaster->CastSpell(pCaster, SPELL_LANDING_RESULT_KILL_CREDIT, true);
//
//                    pCaster->CastSpell(pCaster, SPELL_BULLSEYE, true);
//                }
//                else if (pCaster->IsInRange(CanonTrigger, 1.0f, 4.0f))
//                {
//                    for (uint8 i = 0; i < 3; ++i)
//                        pCaster->CastSpell(pCaster, SPELL_LANDING_RESULT_KILL_CREDIT, true);
//
//                    pCaster->CastSpell(pCaster, SPELL_GREAT_SHOT, true);
//                }
//                else if (pCaster->IsInRange(CanonTrigger, 4.0f, 15.0f))
//                {
//                    pCaster->CastSpell(pCaster, SPELL_POOR_SHOT, true);
//                }
//
//                pCaster->RemoveAura(SPELL_CANNONBALL);
//            }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_darkmoon_cannonball::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
//// Cannon - 102292
//class spell_darkmoon_faire_cannon : public SpellScript
//{
//    PrepareSpellScript(spell_darkmoon_faire_cannon);
//
//    void HandleHitTarget(SpellEffIndex /*effIndex*/)
//    {
//        PreventHitDefaultEffect(EFFECT_0);
//
//        Unit* caster = GetCaster()->GetOwner();
//        Unit* target = GetHitUnit()->ToCreature();
//
//        if (!caster || !target)
//            return;
//
//        if (target->isAlive() && target->GetEntry() == NPC_TONK_TARGET)
//            caster->CastSpell(caster, SPELL_TONK_TARGET, true);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_darkmoon_faire_cannon::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
//// Ring Toss - 101695
//class spell_darkmoon_ring_toss : public SpellScript
//{
//    PrepareSpellScript(spell_darkmoon_ring_toss);
//
//    void HandleHitTarget(SpellEffIndex /*effIndex*/)
//    {
//        PreventHitDefaultEffect(EFFECT_0);
//
//        Unit* caster = GetCaster();
//        Unit* target = GetHitUnit()->ToCreature();
//        if (!caster || !target)
//            return;
//
//        if (target->GetEntry() == NPC_DUBENKO)
//        {
//            float distance = target->GetDistance2d(GetExplTargetDest()->GetPositionX(), GetExplTargetDest()->GetPositionY());
//
//            if (distance < 0.5f)
//                caster->CastSpell(target, SPELL_RING_TOSS_HIT, true);
//
//            else if (distance < 2.0f)
//                caster->CastSpell(target, SPELL_RING_TOSS_MISS, true);
//
//            else if (distance < 4.0f)
//                caster->CastSpell(target, SPELL_RING_TOSS_MISS_2, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_darkmoon_ring_toss::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
//    }
//};
//
//class spell_darkmoon_deathmatch_teleport : public SpellScript
//{
//    PrepareSpellScript(spell_darkmoon_deathmatch_teleport);
//
//    void HandleScript(SpellEffIndex effIndex)
//    {
//        Player* pTarget = GetHitUnit()->ToPlayer();
//        if (!pTarget)
//            return;
//
//        uint32 Spells[8] =
//        {
//            SPELL_DARKMOON_DEATHMATCH_TELE_1,
//            SPELL_DARKMOON_DEATHMATCH_TELE_2,
//            SPELL_DARKMOON_DEATHMATCH_TELE_3,
//            SPELL_DARKMOON_DEATHMATCH_TELE_4,
//            SPELL_DARKMOON_DEATHMATCH_TELE_5,
//            SPELL_DARKMOON_DEATHMATCH_TELE_6,
//            SPELL_DARKMOON_DEATHMATCH_TELE_7,
//            SPELL_DARKMOON_DEATHMATCH_TELE_8
//        };
//        uint8 rand = urand(0, 8);
//
//        pTarget->CastSpell(pTarget, Spells[rand]);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_darkmoon_deathmatch_teleport::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//    }
//};
//
//class spell_darkmoon_summon_rings : public SpellScript
//{
//    PrepareSpellScript(spell_darkmoon_summon_rings);
//
//    void HandleScript(SpellEffIndex effIndex)
//    {
//        Player* caster = GetHitUnit()->ToPlayer();
//        if (!caster)
//            return;
//
//        for (uint8 i = 0; i < 57; ++i)
//            caster->CastSpell(SpawnRingsAT[i], 170815, false);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_darkmoon_summon_rings::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//    }
//};
//
////46668
//class spell_darkmoon_carousel_whee : public AuraScript
//{
//    PrepareAuraScript(spell_darkmoon_carousel_whee);
//
//    uint32 update;
//
//    bool Validate(SpellInfo const* /*spell*/) override
//    {
//        update = 0;
//        return true;
//    }
//
//    void OnUpdate(uint32 diff)
//    {
//        update += diff;
//
//        if (update >= 5000)
//        {
//            Player* _player = GetCaster()->ToPlayer();
//
//            if (!_player)
//                return;
//
//            if (_player->IsOnVehicle())
//            {
//                if (_player->GetMapId() == 974)
//                {
//                    if (GameObject* Go = GetClosestGameObjectWithEntry(_player, 216666, 15.0f))
//                    {
//                        if (Aura* aura = GetAura())
//                        {
//                            uint32 currentMaxDuration = aura->GetMaxDuration();
//                            uint32 newMaxDurantion = currentMaxDuration + (5 * MINUTE * IN_MILLISECONDS);
//                            newMaxDurantion = newMaxDurantion <= (60 * MINUTE * IN_MILLISECONDS) ? newMaxDurantion : (60 * MINUTE * IN_MILLISECONDS);
//
//                            aura->SetMaxDuration(newMaxDurantion);
//                            aura->SetDuration(newMaxDurantion);
//                        }
//                    }
//                }
//            }
//            update = 0;
//        }
//    }
//
//    void Register() override
//    {
//        OnAuraUpdate += AuraUpdateFn(spell_darkmoon_carousel_whee::OnUpdate);
//    }
//};
//
//class spell_dnd_cancel_shapeshift_and_mounts : public AuraScript
//{
//    PrepareAuraScript(spell_dnd_cancel_shapeshift_and_mounts);
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        Unit* caster = GetCaster();
//        if (!caster)
//            return;
//
//        caster->Dismount();
//    }
//
//    void Register() override
//    {
//        OnEffectApply += AuraEffectApplyFn(spell_dnd_cancel_shapeshift_and_mounts::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
//// 102058
//class spell_darkmoon_ring_toss_power : public AuraScript
//{
//    PrepareAuraScript(spell_darkmoon_ring_toss_power);
//
//    uint16 timer;
//
//    bool Load()
//    {
//        timer = 1000;
//        return true;
//    }
//
//    void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
//    {
//        Unit* caster = GetCaster();
//        if (!caster)
//            return;
//
//        uint32 powerAmt = caster->GetPower(POWER_ALTERNATE);
//
//        if (timer <= diff)
//        {
//            if (powerAmt == 0)
//                caster->RemoveAura(102058);
//
//            timer = 1000;
//        }
//        else
//            timer -= diff;
//    }
//
//    void Register() override
//    {
//        OnEffectUpdate += AuraEffectUpdateFn(spell_darkmoon_ring_toss_power::OnUpdate, EFFECT_1, SPELL_AURA_ENABLE_ALT_POWER);
//    }
//};
//
//uint32 RandGo[5] = { 180735, 180725, 180726, 180729, 180733 };
//
//struct npc_trigger_firework_darkmoon : public ScriptedAI
//{
//    npc_trigger_firework_darkmoon(Creature* creature) : ScriptedAI(creature) {}
//
//    EventMap events;
//
//    void Reset() override
//    {
//        events.ScheduleEvent(EVENT_1, urand(1000, 3500));
//        events.ScheduleEvent(EVENT_2, urand(1200, 3500));
//        events.ScheduleEvent(EVENT_3, urand(1700, 3500));
//        events.ScheduleEvent(EVENT_4, urand(1500, 3500));
//        events.ScheduleEvent(EVENT_5, urand(1000, 3800));
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                me->SummonGameObject(RandGo[urand(0, 4)], FireworksPosition[urand(0, 79)], 0, 0, 0, 0, 0, 1);
//                events.ScheduleEvent(EVENT_1, urand(2350, 6920));
//                break;
//            case EVENT_2:
//                me->SummonGameObject(RandGo[urand(0, 4)], FireworksPosition[urand(0, 79)], 0, 0, 0, 0, 0, 1);
//                events.ScheduleEvent(EVENT_2, urand(3100, 5800));
//                break;
//            case EVENT_3:
//                me->SummonGameObject(RandGo[urand(0, 4)], FireworksPosition[urand(0, 79)], 0, 0, 0, 0, 0, 1);
//                events.ScheduleEvent(EVENT_3, urand(3500, 5100));
//                break;
//            case EVENT_4:
//                me->SummonGameObject(RandGo[urand(0, 4)], FireworksPosition[urand(0, 79)], 0, 0, 0, 0, 0, 1);
//                events.ScheduleEvent(EVENT_4, urand(3230, 3500));
//                break;
//            case EVENT_5:
//                me->SummonGameObject(RandGo[urand(0, 4)], FireworksPosition[urand(0, 79)], 0, 0, 0, 0, 0, 1);
//                events.ScheduleEvent(EVENT_5, urand(5150, 6530));
//                break;
//            }
//        }
//    }
//};
//
//void AddSC_darkmoon()
//{
//    new boss_darkmoon_moonfang_mother();
//    new npc_darkmoon_faire_gnolls();
//    RegisterCreatureAI(npc_darkmoon_faire_gnoll_holder);
//    RegisterCreatureAI(npc_darkmoon_faire_rinling);
//    RegisterAuraScript(spell_darkmoon_cannon_prep);
//    RegisterAuraScript(spell_darkmoon_cannonball);
//    RegisterSpellScript(spell_darkmoon_faire_cannon);
//    RegisterSpellScript(spell_darkmoon_ring_toss);
//    RegisterSpellScript(spell_darkmoon_deathmatch_teleport);
//    RegisterSpellScript(spell_darkmoon_summon_rings);
//    RegisterAuraScript(spell_darkmoon_carousel_whee);
//    RegisterAuraScript(spell_dnd_cancel_shapeshift_and_mounts);
//    RegisterAuraScript(spell_darkmoon_ring_toss_power);
//    RegisterCreatureAI(npc_trigger_firework_darkmoon);
//}
