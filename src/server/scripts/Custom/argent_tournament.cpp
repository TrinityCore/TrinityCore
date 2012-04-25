#include "ScriptPCH.h"
/*######
* npc_training_dummy_argent
######*/
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33229;
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33272;
// UPDATE `creature_template` SET `ScriptName`='npc_training_dummy_argent' WHERE `entry`=33243;
enum eTrainingdummy
{
        CREDIT_RANGE               = 33339,
        CREDIT_CHARGE              = 33340,
        CREDIT_MELEE               = 33341,
        NPC_MELEE                  = 33229,
        NPC_CHARGE                 = 33272,
        NPC_RANGE                  = 33243,
        SPELL_ARGENT_MELEE         = 62544,
        SPELL_ARGENT_CHARGE        = 68321,
        SPELL_ARGENT_BREAK_SHIELD  = 62626,  // spell goes't work
        SPELL_DEFEND_AURA          = 62719,  // it's spell spam in console
        SPELL_DEFEND_AURA_1        = 64100,  // it's spell spam in console
        NPC_ADVANCED_TARGET_DUMMY  = 2674,
        NPC_TARGET_DUMMY           = 2673
};

class npc_training_dummy_argent : public CreatureScript
{
public:
        npc_training_dummy_argent(): CreatureScript("npc_training_dummy_argent"){}
                
        struct npc_training_dummy_argentAI : Scripted_NoMovementAI
        {
            npc_training_dummy_argentAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature)
            {
                        Npc_Entry = pCreature->GetEntry();
            }

                        uint64 Npc_Entry;
                        uint32 ResetTimer;
                        uint32 DespawnTimer;
                        uint32 ShielTimer;
            void Reset()
            {
                        me->SetControlled(true,UNIT_STATE_STUNNED);//disable rotate
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);//imune to knock aways like blast wave
                        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                        ResetTimer = 5000;
                        DespawnTimer = 15000;
                        ShielTimer=0;
            }

            void EnterEvadeMode()
            {
                        if (!_EnterEvadeMode())
                                return;
                        Reset();
            }

            void DamageTaken(Unit * /*done_by*/, uint32 &damage)
            {
                        ResetTimer = 5000;
                        damage = 0;
            }

            void EnterCombat(Unit * /*who*/)
            {
                if (Npc_Entry != NPC_ADVANCED_TARGET_DUMMY && Npc_Entry != NPC_TARGET_DUMMY)
                    return;
            }

                void SpellHit(Unit* caster,const SpellEntry* spell)
                {               
                        if(caster->GetCharmerOrOwner())
                        {
                        Player * pPlayer = caster->GetCharmerOrOwner()->ToPlayer();
                        switch (Npc_Entry)
                                {
                                        case NPC_MELEE: // dummy melee
                                                if (pPlayer && spell->Id == SPELL_ARGENT_MELEE && (pPlayer->GetQuestStatus(13828) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13829) == QUEST_STATUS_INCOMPLETE))
                                                        caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_MELEE, 0);
                                                                return;
                                        case NPC_CHARGE: // dummy charge
                                                if (pPlayer && spell->Id == SPELL_ARGENT_CHARGE && (pPlayer->GetQuestStatus(13837) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13839) == QUEST_STATUS_INCOMPLETE))
                                                        caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_CHARGE, 0);
                                                                return;
                                        case NPC_RANGE: // dummy range
                                                if (pPlayer && spell->Id == SPELL_ARGENT_BREAK_SHIELD && (pPlayer->GetQuestStatus(13835) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13838) == QUEST_STATUS_INCOMPLETE))
                                                        caster->GetCharmerOrOwner()->ToPlayer()->KilledMonsterCredit(CREDIT_RANGE, 0);
                                                                return;
                                }
                        }
                }

            void UpdateAI(const uint32 diff)
            {
                        if (ShielTimer <= diff)
                        {
                                if(Npc_Entry == NPC_RANGE)
                                        me->CastSpell(me,SPELL_DEFEND_AURA,true);

                        if(Npc_Entry == NPC_CHARGE && !me->GetAura(SPELL_DEFEND_AURA_1))
                                                me->CastSpell(me,SPELL_DEFEND_AURA_1,true);
                                ShielTimer = 8000;
                        }
                        else
                                ShielTimer -= diff;

                if (!UpdateVictim())
                    return;
                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    me->SetControlled(true,UNIT_STATE_STUNNED);//disable rotate
                        
                if (Npc_Entry != NPC_ADVANCED_TARGET_DUMMY && Npc_Entry != NPC_TARGET_DUMMY)
                {
                        if (ResetTimer <= diff)
                        {
                                EnterEvadeMode();
                                ResetTimer = 5000;
                        }
                        else
                                ResetTimer -= diff;
                                return;
                        }
                        else
                        {
                        if (DespawnTimer <= diff)
                                me->DespawnOrUnsummon();
                        else
                                DespawnTimer -= diff;
                        }
            }
            void MoveInLineOfSight(Unit * /*who*/){return;}
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_training_dummy_argentAI(pCreature);
        }

};

/*######
## npc_lake_frog
## UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `entry` IN (33211,33224);
######*/

#define NPC_MAIDEN 33220
#define TRANSFORM_MAIDEN 62550
#define WARTS_SPELL 62581
#define LIP_BALM_SPELL 62574
#define FROG_LOVE 62537
#define SUMMON_ASHOOD_BRAND_SPELL 62554
#define MAIDEN_SAY "Неужели это может быть? Свободна после всех этих многих лет?"

struct A_BLADE_FIT_FOR_A_CHAMPION_QUEST
{ 
  uint32 quest_id; 
};

A_BLADE_FIT_FOR_A_CHAMPION_QUEST new_quest[] = {13603, 13666, 13673, 13741, 13746, 13752, 13757, 13762, 13768, 13773, 13778, 13783};

class npc_lake_frog : public CreatureScript
{
public:
    npc_lake_frog() : CreatureScript("npc_lake_frog") { }

    struct npc_lake_frogAI : public ScriptedAI
    {
        npc_lake_frogAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        void ReceiveEmote(Player* pPlayer, uint32 emote)
        {
            switch (emote)
            {
                case TEXT_EMOTE_KISS:

                    if (me->HasAura(FROG_LOVE))
                        return;

                    if (!pPlayer->HasAura(LIP_BALM_SPELL))
                    {
                        me->CastSpell(pPlayer, WARTS_SPELL, true);
                        return;
                    }

                    if (pPlayer->GetQuestStatus(13603) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13666) == QUEST_STATUS_INCOMPLETE ||
                        pPlayer->GetQuestStatus(13673) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13741) == QUEST_STATUS_INCOMPLETE ||
                        pPlayer->GetQuestStatus(13746) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13752) == QUEST_STATUS_INCOMPLETE ||
                        pPlayer->GetQuestStatus(13757) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13762) == QUEST_STATUS_INCOMPLETE ||
                        pPlayer->GetQuestStatus(13768) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13773) == QUEST_STATUS_INCOMPLETE ||
                        pPlayer->GetQuestStatus(13778) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(13783) == QUEST_STATUS_INCOMPLETE )
                    {
                        if (rand()%4 == 1)
                        {
                            me->CastSpell(me, TRANSFORM_MAIDEN, true);
                            me->MonsterSay(MAIDEN_SAY, LANG_UNIVERSAL, 0);
                            me->UpdateEntry(NPC_MAIDEN); //For gossip
                            me->DespawnOrUnsummon(30000);
                        }
                        else
                            me->CastSpell(me, FROG_LOVE, true);
                    }

                    break;
            }
        }
    };

    CreatureAI *GetAI(Creature* pCreature) const
    {
        return new npc_lake_frogAI(pCreature);
    }
};

void AddSC_ArgentTournament()
{
    new npc_training_dummy_argent;
    new npc_lake_frog;
}