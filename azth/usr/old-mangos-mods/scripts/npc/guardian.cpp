#include "precompiled.h"
#include "ZZ_ScriptsPersonali.h"

// OTHER
#define SPELL_DRAIN_LIFE         24300
#define SPELL_STEALTH            1787

// FROST
#define SPELL_FROSTBOLT          29954
#define SPELL_FROST_BOLT_NOVA_H  70277
#define SPELL_CHAINSOFICE        29991

// FIRE
#define SPELL_FIREBALL           29953
#define SPELL_DRAGONSBREATH      29964
#define SPELL_PYROBLAST          31263
#define H_SPELL_RAIN_OF_FIRE     39363

// ARCANE
#define SPELL_ARCMISSLE_CHAIN    29955
#define SPELL_ARCMISSLE          33833

// AOE
#define SPELL_BLIZZARD           31266
#define SPELL_AOE_PYROBLAST      29978
#define SPELL_SUMMON_ELEMENTALS  31264

// HEALING
#define SPELL_HEAL               31739
#define TRANQUILITY              38659
#define CHAIN_HEAL               42027

struct MANGOS_DLL_DECL guardian1_AI : public ScriptedAI
{
    Player *follower;
    Unit* target;

    guardian1_AI(Creature* pCreature) : ScriptedAI(pCreature) 
    {
        follower = NULL;
        target   = NULL;
        Reset();
    }

    uint32 fireTimer;
    uint32 frostTimer;
    uint32 mainspellTimer;
    uint32 otherSpellTimer;
    uint32 elementalTimer;
    uint32 selfcureTimer;
    uint32 cureTimer;

    bool checkUnit(Unit* who)
    {
        return who && who->IsInWorld();
    }

    void changeMovement(Creature* creature)
    {
        if (checkUnit(follower))
            creature->GetMotionMaster()->MoveFollow(follower, PET_FOLLOW_DIST+urand(0,5), PET_FOLLOW_ANGLE*urand(1,6));
        else
        {
            creature->StopMoving();
            creature->GetMotionMaster()->Clear();
            creature->GetMotionMaster()->MoveIdle();
        }
    }

    void Attacco(Creature* m_creature,Unit *who)
    {
        if(m_creature->Attack(who,false))
        {
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MoveIdle();
            m_creature->AddThreat(who);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);  
        }
    }

    void followerActions(Creature* creature)
    {
        //check attack
        if (follower && creature)
        {
            // se slogga
            if (!follower->IsInWorld())
            {
                follower = NULL;
                Reset();
                return;
            }

            // se attacca
            if( follower->isInCombat() && !creature->getVictim())
            {
                if (follower->getVictim())
                    Attacco(m_creature,follower->getVictim());
            }

            // se invisibile
            if ( follower->HasAuraType(SPELL_AURA_MOD_STEALTH) )
            {
                if (creature->isInCombat())
                    Reset();

                m_creature->CastSpell(m_creature,SPELL_STEALTH,true);
            }
            else if ( m_creature->HasStealthAura() )
                m_creature->RemoveAurasDueToSpell(SPELL_STEALTH);
        }
    }

    void Reset()
    {
        mainspellTimer = 1000;
        otherSpellTimer = 30000;
        elementalTimer = 50000; 
        selfcureTimer  = 10000;
        cureTimer      = 15000;
        fireTimer      = 5000;
        frostTimer     = 7000;
        m_creature->ClearInCombat();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);
        m_creature->LoadCreatureAddon(true);
        changeMovement(m_creature);
    }
    
    void JustDied(Unit* pKiller)
    {
        // remove "guard" script
        //todo: create a common public function in core to remove guard attributes
        follower = NULL;
        target   = NULL;
        Reset();
        m_creature->azGuard = false;
        m_creature->customScriptID = 0;
        m_creature->AIM_Initialize();
    }

    void EnterEvadeMode()
    {
        Reset();
    }

    void AttackStart(Unit* who)
    {
        if (checkUnit(follower) && who && follower->getVictim() == who)
            Attacco(m_creature,who);
    }

    void AttackedBy(Unit* pAttacker)
    {
        if (checkUnit(pAttacker) && !m_creature->getVictim())
            Attacco(m_creature,pAttacker);

    }

    void MoveInLineOfSight(Unit* who)
    {
        if (checkUnit(follower) && who && follower->getVictim() == who)
            Attacco(m_creature,who);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        followerActions(m_creature);

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // MAIN SPELLS
        if (mainspellTimer < uiDiff)
        {
            uint32 spell;
            switch (urand(1,3))
            {
                case 1: spell = SPELL_FROST_BOLT_NOVA_H; break;
                case 2: spell = SPELL_FIREBALL; break;
                case 3: spell = SPELL_ARCMISSLE; break;
            }
            DoCastSpellIfCan(m_creature->getVictim(), spell);
            mainspellTimer = urand(2000, 8000);
        }
        else
            mainspellTimer -= uiDiff;

        // FROST
        if (frostTimer < uiDiff)
        {
            uint32 spell;
            switch (urand(1,3))
            {
                case 1: spell = SPELL_FROSTBOLT; break;
                case 2: spell = SPELL_FROST_BOLT_NOVA_H; break;
                case 3: spell = SPELL_CHAINSOFICE; break;
            }
            DoCastSpellIfCan(m_creature->getVictim(), spell);
            frostTimer = urand(10000, 20000);
        }
        else
            frostTimer -= uiDiff;

        // FIRE
        if (fireTimer < uiDiff)
        {
            uint32 spell;
            switch (urand(1,3))
            {
                case 1: spell = SPELL_FIREBALL; break;
                case 2: spell = SPELL_DRAGONSBREATH; break;
                case 3: spell = SPELL_PYROBLAST; break;
            }
            DoCastSpellIfCan(m_creature->getVictim(), spell);
            fireTimer = urand(10000, 20000);
        }
        else
            fireTimer -= uiDiff;

        // OTHER
        if (otherSpellTimer < uiDiff)
        {
            uint32 spell;
            switch (urand(1,4))
            {
                case 1: spell = SPELL_ARCMISSLE_CHAIN; break;
                case 2: spell = SPELL_DRAIN_LIFE; break;
                case 3: spell = H_SPELL_RAIN_OF_FIRE; break;
                case 4: spell = SPELL_BLIZZARD; break;
            }
            DoCastSpellIfCan(m_creature->getVictim(), spell);
            otherSpellTimer = urand(20000, 50000);
        }
        else
            otherSpellTimer -= uiDiff;

        // SUMMON
        if (elementalTimer < uiDiff)
        {
            DoCast(m_creature, SPELL_SUMMON_ELEMENTALS);
            elementalTimer = urand(150000, 250000);
        }
        else
            elementalTimer -= uiDiff;


        // CURE
        if (selfcureTimer < uiDiff)
        {
            if (m_creature->GetHealthPercent() < 90.0f )
                DoCast(m_creature, SPELL_HEAL);

            selfcureTimer = urand(5000, 20000);
        }
        else
            selfcureTimer -= uiDiff;

        if (cureTimer < uiDiff)
        {
            //Player* target = hw2_scripts->AzerothSelectNearbyFrTarget(m_creature);
            //SelectRandomFriendlyTarget
            Unit* target = follower;

            if ( target )
                DoCast(target, CHAIN_HEAL);
            cureTimer = urand(10000, 60000);
        }
        else
            cureTimer -= uiDiff;
    }

    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        switch(emote)
        {
            case TEXTEMOTE_POINT:
                target = m_creature->SelectRandomUnfriendlyTarget(0,40.0f);
                if (target &&  target->isTargetableForAttack() && m_creature->IsHostileTo(target) && target->isInAccessablePlaceFor(m_creature))
                {                
                    ScriptedAI::AttackStart(target);
                    m_creature->MonsterYell("All'attacco!",LANG_UNIVERSAL,0);
                }
                break;
            case TEXTEMOTE_WAVE:
                follower = pPlayer;
                changeMovement(m_creature);
                m_creature->MonsterSay("Ti seguo",LANG_UNIVERSAL,0);
                break;
            case TEXTEMOTE_BOW:
                follower = NULL;
                changeMovement(m_creature);
                m_creature->MonsterSay("Aspettero' qui",LANG_UNIVERSAL,0);
                break;
            case TEXTEMOTE_ROAR:
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(pPlayer, CHAIN_HEAL);
                m_creature->MonsterYell("Soccorso in arrivo",LANG_UNIVERSAL,0);
                break;
        }
    }

};

CreatureAI* GetAI_guardian1(Creature* pCreature)
{
    return new guardian1_AI(pCreature);
}

void AddSC_guardian()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "guardian_1";
    newscript->GetAI = &GetAI_guardian1;
    newscript->RegisterSelf(GUARD1_ID);
}
