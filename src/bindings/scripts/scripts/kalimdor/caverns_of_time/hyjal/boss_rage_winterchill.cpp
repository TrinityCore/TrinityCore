
#include "precompiled.h"
#include "def_hyjal.h"
#include "hyjal_trash.h"

#define SPELL_FROST_ARMOR 31256
#define SPELL_DEATH_AND_DECAY 31258

#define SPELL_FROST_NOVA 31250
#define SPELL_ICEBOLT 31249

#define SAY_ONDEATH "You have won this battle, but not... the... war"
#define SOUND_ONDEATH 11026

#define SAY_ONSLAY1 "All life must perish!"
#define SAY_ONSLAY2 "Victory to the Legion!"
#define SOUND_ONSLAY1 11025
#define SOUND_ONSLAY2 11057

#define SAY_DECAY1 "Crumble and rot!"
#define SAY_DECAY2 "Ashes to ashes, dust to dust"
#define SOUND_DECAY1 11023
#define SOUND_DECAY2 11055

#define SAY_NOVA1 "Succumb to the icy chill... of death!"
#define SAY_NOVA2 "It will be much colder in your grave"
#define SOUND_NOVA1 11024
#define SOUND_NOVA2 11058

#define SAY_ONAGGRO "The Legion's final conquest has begun! Once again the subjugation of this world is within our grasp. Let none survive!"
#define SOUND_ONAGGRO 11022

struct TRINITY_DLL_DECL boss_rage_winterchillAI : public hyjal_trashAI
{
    boss_rage_winterchillAI(Creature *c) : hyjal_trashAI(c)
    {
        pInstance = c->GetInstanceData();
        pGo = false;
        pos = 0;
    }

    uint32 FrostArmorTimer;
    uint32 DecayTimer;
    uint32 NovaTimer;
    uint32 IceboltTimer;
    bool pGo;
    uint32 pos;

    void Reset()
    {
        damageTaken = 0;
        FrostArmorTimer = 37000;
        DecayTimer = 45000;
        NovaTimer = 15000;
        IceboltTimer = 10000;

        if (pInstance && IsEvent)
            pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        if (pInstance && IsEvent)
            pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, IN_PROGRESS);
        DoPlaySoundToSet(m_creature, SOUND_ONAGGRO);
        m_creature->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, 0);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoPlaySoundToSet(m_creature, SOUND_ONSLAY1);
                m_creature->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature, SOUND_ONSLAY2);
                m_creature->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, NULL);
                break;
        }
    }

    void WaypointReached(uint32 i)
    {
        pos = i;
        if (i == 7 && pInstance)
        {
            Unit* target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_JAINAPROUDMOORE));
            if (target && target->isAlive())
                m_creature->AddThreat(target,0.0);
        }
    }

    void JustDied(Unit *victim)
    {
        hyjal_trashAI::JustDied(victim);
        if (pInstance && IsEvent)
            pInstance->SetData(DATA_RAGEWINTERCHILLEVENT, DONE);
        DoPlaySoundToSet(m_creature, SOUND_ONDEATH);
        m_creature->MonsterYell(SAY_ONDEATH, LANG_UNIVERSAL, NULL);
    }

    void UpdateAI(const uint32 diff)
    {
        if (IsEvent)
        {
            //Must update npc_escortAI
            npc_escortAI::UpdateAI(diff);
            if (!pGo)
            {
                pGo = true;
                if (pInstance)
                {
                    AddWaypoint(0, 4896.08,    -1576.35,    1333.65);
                    AddWaypoint(1, 4898.68,    -1615.02,    1329.48);
                    AddWaypoint(2, 4907.12,    -1667.08,    1321.00);
                    AddWaypoint(3, 4963.18,    -1699.35,    1340.51);
                    AddWaypoint(4, 4989.16,    -1716.67,    1335.74);
                    AddWaypoint(5, 5026.27,    -1736.89,    1323.02);
                    AddWaypoint(6, 5037.77,    -1770.56,    1324.36);
                    AddWaypoint(7, 5067.23,    -1789.95,    1321.17);
                    Start(false, true);
                    SetDespawnAtEnd(false);
                }
            }
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (FrostArmorTimer < diff)
        {
            DoCast(m_creature, SPELL_FROST_ARMOR);
            FrostArmorTimer = 40000+rand()%20000;
        }else FrostArmorTimer -= diff;
        if (DecayTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_DEATH_AND_DECAY);
            DecayTimer = 60000+rand()%20000;
            switch(rand()%2)
            {
                case 0:
                    DoPlaySoundToSet(m_creature, SOUND_DECAY1);
                    m_creature->MonsterYell(SAY_DECAY1, LANG_UNIVERSAL, NULL);
                    break;
                case 1:
                    DoPlaySoundToSet(m_creature, SOUND_DECAY2);
                    m_creature->MonsterYell(SAY_DECAY2, LANG_UNIVERSAL, NULL);
                    break;
            }
        }else DecayTimer -= diff;
        if (NovaTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROST_NOVA);
            NovaTimer = 30000+rand()%15000;
            switch(rand()%2)
            {
                case 0:
                    DoPlaySoundToSet(m_creature, SOUND_NOVA1);
                    m_creature->MonsterYell(SAY_NOVA1, LANG_UNIVERSAL, NULL);
                    break;
                case 1:
                    DoPlaySoundToSet(m_creature, SOUND_NOVA2);
                    m_creature->MonsterYell(SAY_NOVA2, LANG_UNIVERSAL, NULL);
                    break;
            }
        }else NovaTimer -= diff;
        if (IceboltTimer < diff)
        {
            DoCast(SelectTarget(SELECT_TARGET_RANDOM,0,40,true), SPELL_ICEBOLT);
            IceboltTimer = 11000+rand()%20000;
        }else IceboltTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_rage_winterchill(Creature* pCreature)
{
    return new boss_rage_winterchillAI (pCreature);
}

void AddSC_boss_rage_winterchill()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_rage_winterchill";
    newscript->GetAI = &GetAI_boss_rage_winterchill;
    newscript->RegisterSelf();
}
