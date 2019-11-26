#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "World.h"
#include "DBCStores.h"
#include "Custom/AI/CustomAI.h"

enum Spells
{
    SPELL_SHADOW_BOLT           = 100028,
    SPELL_FEL_FIREBALL          = 100027,
    SPELL_SUMMON_PET            = 100070,
};

enum Pets
{
    NPC_PET                     = 100070,

    DISPLAYID_IMP               = 4449,
    DISPLAYID_VOID_WALKER       = 1132,
    DISPLAYID_FELHUNTER         = 850,
    DISPLAYID_SUCCUBUS          = 4162
};

/*
*       Crash avec le pet ???
*/

class npc_felcaster : public CreatureScript
{
    public:
    npc_felcaster() : CreatureScript("npc_felcaster") {}

    struct npc_felcasterAI : public CustomAI
    {
        npc_felcasterAI(Creature* creature) : CustomAI(creature), currentPet(nullptr) { }

        void JustEngagedWith(Unit* who) override
        {
            SummonPet(who);

            scheduler
                .Schedule(Seconds(3), [this](TaskContext shadow_bolt)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    shadow_bolt.Repeat(Seconds(10), Seconds(14));
                })
                .Schedule(Seconds(8), [this](TaskContext fel_fireball)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FEL_FIREBALL);
                    fel_fireball.Repeat(Seconds(13), Seconds(25));
                });
        }

        void EnterEvadeMode(EvadeReason /*why*/) override { }

        void JustDied(Unit* killer) override
        {
            if (currentPet)
                currentPet->DespawnOrUnsummon();

            CustomAI::JustDied(killer);
        }

        private:
        Creature* currentPet;

        void SummonPet(Unit* who)
        {
            if (currentPet)
            {
                currentPet->Attack(who, true);
                currentPet->GetMotionMaster()->MoveChase(who, PET_FOLLOW_DIST);
            }
            else
            {
                if (Creature* pet = DoSummon(NPC_PET, me, 2.f, 8000, TEMPSUMMON_CORPSE_TIMED_DESPAWN))
                {
                    CreatureFamilyEntry const* creatureFamily;
                    switch (pet->GetDisplayId())
                    {
                        case DISPLAYID_IMP:
                            creatureFamily = sCreatureFamilyStore.LookupEntry(CREATURE_FAMILY_IMP);
                            pet->SetName(creatureFamily->Name[sWorld->GetDefaultDbcLocale()]);
                            break;
                        case DISPLAYID_VOID_WALKER:
                            creatureFamily = sCreatureFamilyStore.LookupEntry(CREATURE_FAMILY_VOIDWALKER);
                            pet->SetName(creatureFamily->Name[sWorld->GetDefaultDbcLocale()]);
                            break;
                        case DISPLAYID_FELHUNTER:
                            creatureFamily = sCreatureFamilyStore.LookupEntry(CREATURE_FAMILY_FELHUNTER);
                            pet->SetName(creatureFamily->Name[sWorld->GetDefaultDbcLocale()]);
                            break;
                        case DISPLAYID_SUCCUBUS:
                            creatureFamily = sCreatureFamilyStore.LookupEntry(CREATURE_FAMILY_SUCCUBUS);
                            pet->SetName(creatureFamily->Name[sWorld->GetDefaultDbcLocale()]);
                            break;
                        default:
                            break;
                    }

                    pet->Attack(who, true);
                    pet->GetMotionMaster()->MoveChase(who, PET_FOLLOW_DIST);

                    currentPet = pet;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felcasterAI(creature);
    }
};

void AddSC_npc_felcaster()
{
    new npc_felcaster();
}
