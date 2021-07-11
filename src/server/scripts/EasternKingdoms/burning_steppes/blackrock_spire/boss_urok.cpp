#include "scriptPCH.h"

enum
{
    GO_SUMMON_CIRCLE        = 175571,
    GO_AUTEL_OFFRANDES      = 175621,
    GO_CHALLENGE_UROK       = 175584,

    NPC_UROK_MASSACRER      = 10601, // Cac
    NPC_UROK_MAGE           = 10602, // Caster
    NPC_UROK_DOOMHOWL       = 10584, // le Boss

    SPELL_DECLENCHER_DEFIS  = 16447, // Clic droit sur 'GO_CHALLENGE_UROK'
    SPELL_UROK_SUMMONED     = 16473, // Visuel d'eclairs
    SPELL_UROK_ADD_SUMMONED = 16562, // Visuel de teleportation
    SPELL_KILL_UROK_ADD     = 16452,
    SPELL_DESTROY_SPEAR     = 16557,
    SPELL_DESTROY_SPEAR2    = 16558,
    SPELL_STRIKE            = 14516,
    SPELL_BLOODLUST         = 6742,
    SPELL_SLOW              = 13747,
    SPELL_ARCANE_BOLT       = 15979
};

void DefineGoChallenge(Creature * crea, uint64 gobjGUID);

/// Script du GameObject de challenge (GO_CHALLENGE_UROK)
struct go_urok_challengeAI: public GameObjectAI
{
    go_urok_challengeAI(GameObject* go) : GameObjectAI(go), _actived(true), _step(0), _timer(0), _spellTimer(0)
    {
        nbDeadUnderlings=0;
    }

    bool       _actived;
    uint32     _step;
    uint32     _timer;
    uint32     _spellTimer;
    ObjectGuid _runes[6];

    // Fonction appellees toutes les 100ms en moyenne.
    // Permet de gerer les timer de pop des adds par exemple.
    void UpdateAI(uint32 const diff) override
    {
        if (_spellTimer < diff)
            _spellTimer = 0;
        else
            _spellTimer -= diff;

        if (_actived)
        {
            if (_timer < diff)
            {
                switch (_step)
                {
                    case 0:
                        SpawnRune(0, -13.7f, -385.3f, 48.95f, 4.85f);
                        SpawnRune(1, -27.78f, -385.75f, 48.5f, 5.66f);
                        SpawnRune(2, -25.0f, -369.9f, 49.66f, 5.2f);
                        SpawnRune(3, -34.4f, -370.6f, 50.3f, 5.4f);
                        SpawnRune(4, -34.0f, -370.4f, 50.3f, 5.4f);
                        SpawnRune(5, -49.4f, -368.5f, 51.7f, 5.5f);
                        _timer = 3000;
                        break;
                    case 1:
                        SpawnAtRune(0, NPC_UROK_MAGE,0);
                        SpawnAtRune(2, NPC_UROK_MASSACRER,1);
                        SpawnAtRune(3, NPC_UROK_MASSACRER,2);
                        _timer = 10000;
                        break;
                }
                ++_step;
            }
            else
                _timer -= diff;
        }
    }

    void SpawnAtRune(uint32 rune, uint32 entry, int i=0)
    {
        if (GameObject* go = me->GetMap()->GetGameObject(_runes[rune]))
        {
            if (Creature* invoc = me->SummonCreature(entry, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 400000, false))
            {
                invoc->SetRespawnDelay(600000);
                // Visuel d'apparition
                if (entry == NPC_UROK_DOOMHOWL)
                    invoc->SendSpellGo(invoc, SPELL_UROK_SUMMONED);
                else
                {
                    guidCurrentUnderlings[i]=invoc->GetGUID();
                    DefineGoChallenge(invoc, me->GetGUID());
                    invoc->SendSpellGo(invoc, SPELL_UROK_ADD_SUMMONED);
                }
                // Mise en combat avec tout le monde
                Map::PlayerList const& list = me->GetMap()->GetPlayers();
                for (const auto& it : list)
                    if (Player* player = it.getSource())
                        if (player->IsAlive() && !invoc->IsFriendlyTo(player))
                            invoc->AI()->AttackStart(player);
            }
        }
    }

    void SpawnBoss()
    {
        SpawnAtRune(5, NPC_UROK_DOOMHOWL);
        DespawnRunes();
    }

    void SpawnRune(uint32 i, float x, float y, float z, float o)
    {
        if (GameObject* go = me->SummonGameObject(GO_SUMMON_CIRCLE, x, y, z, o, 0, 0, 0, 0, 0))
            _runes[i] = go->GetObjectGuid();
    }

    void DespawnRunes()
    {
        for (const auto& guid : _runes)
            if (GameObject* go = me->GetMap()->GetGameObject(guid))
                go->AddObjectToRemoveList();
    }

    Unit* NearestOgre()
    {
        Unit* massacrer = me->FindNearestCreature(NPC_UROK_MASSACRER, 20.0f);
        Unit* mage      = me->FindNearestCreature(NPC_UROK_MAGE, 20.0f);
        Unit* target    = nullptr;
        if (!mage)
            target = massacrer;
        else if (massacrer)
        {
            if (me->GetDistance(massacrer) < me->GetDistance(mage))
                target = massacrer;
            else
                target = mage;
        }
        else
            target = mage;
        // Sinon, massacre=mage=nullptr, aucune cible.
        return target;
    }

    // Clic-droit sur le gameobject.
    bool OnUse(Unit* user) override
    {
        if (_actived)
        {
            // Lancer le sort 10k dmg s'il est pret.
            if (!_spellTimer)
                if (Unit* target = NearestOgre())
                {
                    _spellTimer = 30000;
                    user->CastSpell(target, SPELL_KILL_UROK_ADD, false);
                }
            return true;
        }
        return true;
    }

    void EventBannerDestroyed(uint64 sourceGuid)
    {
        if(!_actived)
            return;
        _actived = false;
        DespawnRunes();
        me->Despawn();
    }
    uint8 runeOrder[10] = {0,2,3,1,4,5,1,2,3,5};
    uint8 nbDeadUnderlings;
    uint64 guidCurrentUnderlings[3];
    void UrokUnderlingDied(uint64 creatureGUID)
    {
        if(! _actived)
            return;
        for(int i=0; i<3; i++)
        {
            if(creatureGUID == guidCurrentUnderlings[i])
            {
                nbDeadUnderlings++;
                if(nbDeadUnderlings<8)
                {
                    uint32 entry = urand(0,1)?  NPC_UROK_MAGE: NPC_UROK_MASSACRER;
                    SpawnAtRune(runeOrder[nbDeadUnderlings+2], entry, i);
                }
                else if (nbDeadUnderlings==8)
                {
                    SpawnBoss();
                }
            }
        }
    }
};

GameObjectAI* GetAIgo_urok_challenge(GameObject *go)
{
    return new go_urok_challengeAI(go);
}

struct urokUnderlingAI : public ScriptedAI
{
    urokUnderlingAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        timer=0;
    }
    void Reset() override
    {
        timer=0;
        abilityReset();
    }
    virtual void abilityReset(){}
    uint32 timer;
    uint64 guidMound;
    void JustDied(Unit* pKiller) override
    {
        if(GameObject* gobj=m_creature->GetMap()->GetGameObject(guidMound))
        {
            if (go_urok_challengeAI* pMoundAI = dynamic_cast<go_urok_challengeAI*>(gobj->AI()))
            {
                pMoundAI->UrokUnderlingDied(m_creature->GetGUID());
            }
        }
    }
    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;
        if (uiPointId != 2)
            return;
        HitBanner();
    }
    void AttackStart(Unit * unit) override
    {
      if( m_creature->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            return;
        ScriptedAI::AttackStart(unit);
    }
    void BannerDestroyed()
    {
        if(GameObject* pGo=m_creature->FindNearestGameObject(GO_CHALLENGE_UROK, 40))
        {
            if (go_urok_challengeAI* pPedestalAI = dynamic_cast<go_urok_challengeAI*>((pGo)->AI()))
                pPedestalAI->EventBannerDestroyed(m_creature->GetGUID());
        }
    }

    bool HitBanner()
    {
         if(GameObject* pGo=m_creature->FindNearestGameObject(GO_CHALLENGE_UROK, CONTACT_DISTANCE+1))
         {
            float x, y, z;
            pGo->GetPosition(x, y, z);
            m_creature->CastSpell(x, y, z, SPELL_DESTROY_SPEAR, false);
            timer=11000;
            return true;
          }
          return false;
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if ( timer < uiDiff)
            {
                if(!HitBanner())
                {
                    if (GameObject* pGo = m_creature->FindNearestGameObject(GO_CHALLENGE_UROK, 50))
                    {
                        float fX, fY, fZ;
                        pGo->GetContactPoint(m_creature, fX, fY, fZ, CONTACT_DISTANCE);
                        m_creature->GetMotionMaster()->MovePoint(2, fX, fY, fZ, MOVE_PATHFINDING);
                        timer=10000;
                    }
                }
            }
            else
                timer -= uiDiff;
            return;
        }
        abilityCombatUpdate(uiDiff);
        DoMeleeAttackIfReady();
    }
    virtual void abilityCombatUpdate(uint32 uiDiff){}
    void SetMoundGuid(uint64 moundGuid)
    {
        guidMound=moundGuid;
    }
};
struct urokEnforcerAI : public urokUnderlingAI
{
    urokEnforcerAI(Creature* pCreature) : urokUnderlingAI(pCreature)
    {
        abilityReset();
    }
    void abilityReset() override
    {
        m_uiStrike_Timer = 1000;
    }
    uint32 m_uiStrike_Timer;
    void abilityCombatUpdate(uint32 uiDiff) override
    {
        if (m_uiStrike_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_STRIKE ) == CAST_OK)
                m_uiStrike_Timer = urand(10000, 18000);
        }
        else
            m_uiStrike_Timer -= uiDiff;
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_urok_enforcer(Creature* pCreature)
{
    return new urokEnforcerAI(pCreature);
}
struct urokOgreMagusAI : public urokUnderlingAI
{
    urokOgreMagusAI(Creature* pCreature) : urokUnderlingAI(pCreature)
    {
    }

    void abilityCombatUpdate(uint32 uiDiff) override
    {
        if (!m_CreatureSpells.empty())
            UpdateSpellsList(uiDiff);

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_urok_ogre_magus(Creature* pCreature)
{
    return new urokOgreMagusAI(pCreature);
}
//event 4777
bool ProcessEventId_event_banner_destroyed(uint32 eventId, Object* source, Object* target, bool isStart)
{
    //we go through the source because target is null.... maybe because it is a summoned object.
    if(!target)
    {
        if(source && source->IsCreature())
        {
            if (urokUnderlingAI* underlingAI = dynamic_cast<urokUnderlingAI*>( ((Creature*)source)->AI() ) )
            {
                underlingAI->BannerDestroyed();
            }
        }
    }
    else if (ObjectGuid targetGuid = target->GetObjectGuid())
    {
        if (targetGuid.IsGameObject())
        {
            if (go_urok_challengeAI* pPedestalAI = dynamic_cast<go_urok_challengeAI*>(((GameObject*) target)->AI()))
                pPedestalAI->EventBannerDestroyed(source->GetGUID());
        }
    }
    return true;//to always override what could be in DB.
}
void DefineGoChallenge(Creature * crea, uint64 gobjGUID)
{
    if (urokUnderlingAI* underlingAI = dynamic_cast<urokUnderlingAI*>(crea->AI()))
    {
        underlingAI->SetMoundGuid(gobjGUID);
    }
}
void AddSC_boss_urok() // Permet l'intégration dans la DB.
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_urok_challenge";
    newscript->GOGetAI = &GetAIgo_urok_challenge;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_urok_enforcer";
    newscript->GetAI = &GetAI_npc_urok_enforcer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_urok_ogre_magus";
    newscript->GetAI = &GetAI_npc_urok_ogre_magus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "event_banner_destroyed";
    newscript->pProcessEventId = &ProcessEventId_event_banner_destroyed;
    newscript->RegisterSelf();
}
