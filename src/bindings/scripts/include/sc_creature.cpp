/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"
#include "Item.h"
#include "Spell.h"

// Spell summary for ScriptedAI::SelectSpell
struct TSpellSummary {
    uint8 Targets;    // set of enum SelectTarget
    uint8 Effects;    // set of enum SelectEffect
} *SpellSummary;

bool ScriptedAI::IsVisible(Unit* who) const
{
    if (!who)
        return false;

    return (m_creature->GetDistance(who) < VISIBLE_RANGE) && who->isVisibleForOrDetect(m_creature,true);
}

void ScriptedAI::MoveInLineOfSight(Unit *who)
{
    if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
    {
        if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
            return;

        float attackRadius = m_creature->GetAttackDistance(who);
        if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
        {
            DoStartAttackAndMovement(who);
            who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

            if (!InCombat)
            {
                InCombat = true;
                Aggro(who);
            }
        }
    }
}

void ScriptedAI::AttackStart(Unit* who)
{
    if (!who)
        return;

    if (who->isTargetableForAttack())
    {
        //Begin attack
        DoStartAttackAndMovement(who);

        if (!InCombat)
        {
            InCombat = true;
            Aggro(who);
        }
    }
}

void ScriptedAI::UpdateAI(const uint32 diff)
{
    //Check if we have a current target
    if( m_creature->isAlive() && m_creature->SelectHostilTarget() && m_creature->getVictim())
    {
        if( m_creature->isAttackReady() )
        {
            //If we are within range melee the target
            if( m_creature->IsWithinDistInMap(m_creature->getVictim(), ATTACK_DISTANCE))
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
        }
    }
}

void ScriptedAI::EnterEvadeMode()
{
    m_creature->InterruptNonMeleeSpells(true);
    m_creature->RemoveAllAuras();
    m_creature->DeleteThreatList();
    m_creature->CombatStop();
    m_creature->LoadCreaturesAddon();

    if( m_creature->isAlive() )
        m_creature->GetMotionMaster()->MoveTargetedHome();

    m_creature->SetLootRecipient(NULL);

    InCombat = false;
    Reset();
}

void ScriptedAI::JustRespawned()
{
    InCombat = false;
    Reset();
}

void ScriptedAI::DoStartAttackAndMovement(Unit* victim, float distance, float angle)
{
    if (!victim)
        return;

    if ( m_creature->Attack(victim, true) )
    {
        m_creature->GetMotionMaster()->MoveChase(victim, distance, angle);
        m_creature->AddThreat(victim, 0.0f);
    }
}

void ScriptedAI::DoStartAttackNoMovement(Unit* victim)
{
    if (!victim)
        return;

    if ( m_creature->Attack(victim, true) )
    {
        m_creature->AddThreat(victim, 0.0f);
    }
}


void ScriptedAI::DoMeleeAttackIfReady()
{
    //Make sure our attack is ready and we aren't currently casting before checking distance
    if( m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
    {
        //If we are within range melee the target
        if( m_creature->IsWithinDistInMap(m_creature->getVictim(), ATTACK_DISTANCE))
        {
            m_creature->AttackerStateUpdate(m_creature->getVictim());
            m_creature->resetAttackTimer();
        }
    }
}

void ScriptedAI::DoStopAttack()
{
    if( m_creature->getVictim() != NULL )
    {
        m_creature->AttackStop();
    }
}

void ScriptedAI::DoCast(Unit* victim, uint32 spellId, bool triggered)
{
    if (!victim || m_creature->IsNonMeleeSpellCasted(false))
        return;

    m_creature->StopMoving();
    m_creature->CastSpell(victim, spellId, triggered);
}

void ScriptedAI::DoCastSpell(Unit* who,SpellEntry const *spellInfo, bool triggered)
{
    if (!who || m_creature->IsNonMeleeSpellCasted(false))
        return;

    m_creature->StopMoving();
    m_creature->CastSpell(who, spellInfo, triggered);
}

void ScriptedAI::DoSay(const char* text, uint32 language, Unit* target)
{
    if (target)m_creature->Say(text, language, target->GetGUID());
    else m_creature->Say(text, language, 0);
}

void ScriptedAI::DoYell(const char* text, uint32 language, Unit* target)
{
    if (target)m_creature->Yell(text, language, target->GetGUID());
    else m_creature->Yell(text, language, 0);
}

void ScriptedAI::DoTextEmote(const char* text, Unit* target, bool IsBossEmote)
{
    if (target)m_creature->TextEmote(text, target->GetGUID(), IsBossEmote);
    else m_creature->TextEmote(text, 0, IsBossEmote);
}

void ScriptedAI::DoWhisper(const char* text, Unit* reciever, bool IsBossWhisper)
{
    if (!reciever || reciever->GetTypeId() != TYPEID_PLAYER)
        return;

    m_creature->Whisper(text, reciever->GetGUID(), IsBossWhisper);
}

void ScriptedAI::DoPlaySoundToSet(Unit* unit, uint32 sound)
{
    if (!unit)
        return;

    if (!GetSoundEntriesStore()->LookupEntry(sound))
    {
        error_log("SD2: Invalid soundId %u used in DoPlaySoundToSet (by unit TypeId %u, guid %u)", sound, unit->GetTypeId(), unit->GetGUID());
        return;
    }

    unit->SendPlaySound(sound, false);
}

Creature* ScriptedAI::DoSpawnCreature(uint32 id, float x, float y, float z, float angle, uint32 type, uint32 despawntime)
{
    return m_creature->SummonCreature(id,m_creature->GetPositionX() + x,m_creature->GetPositionY() + y,m_creature->GetPositionZ() + z, angle, (TempSummonType)type, despawntime);
}

Unit* ScriptedAI::SelectUnit(SelectAggroTarget target, uint32 position)
{
    //ThreatList m_threatlist;
    std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
    std::list<HostilReference*>::iterator i = m_threatlist.begin();
    std::list<HostilReference*>::reverse_iterator r = m_threatlist.rbegin();

    if (position >= m_threatlist.size() || !m_threatlist.size())
        return NULL;

    switch (target)
    {
    case SELECT_TARGET_RANDOM:
        advance ( i , position +  (rand() % (m_threatlist.size() - position ) ));
        return Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
        break;

    case SELECT_TARGET_TOPAGGRO:
        advance ( i , position);
        return Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
        break;

    case SELECT_TARGET_BOTTOMAGGRO:
        advance ( r , position);
        return Unit::GetUnit((*m_creature),(*r)->getUnitGuid());
        break;
    }

    return NULL;
}

SpellEntry const* ScriptedAI::SelectSpell(Unit* Target, int32 School, int32 Mechanic, SelectTarget Targets, uint32 PowerCostMin, uint32 PowerCostMax, float RangeMin, float RangeMax, SelectEffect Effects)
{
    //No target so we can't cast
    if (!Target)
        return false;

    //Silenced so we can't cast
    if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
        return false;

    //Using the extended script system we first create a list of viable spells
    SpellEntry const* Spell[4];
    Spell[0] = 0;
    Spell[1] = 0;
    Spell[2] = 0;
    Spell[3] = 0;

    uint32 SpellCount = 0;

    SpellEntry const* TempSpell;
    SpellRangeEntry const* TempRange;

    //Check if each spell is viable(set it to null if not)
    for (uint32 i = 0; i < 4; i++)
    {
        TempSpell = GetSpellStore()->LookupEntry(m_creature->m_spells[i]);

        //This spell doesn't exist
        if (!TempSpell)
            continue;

        // Targets and Effects checked first as most used restrictions
        //Check the spell targets if specified
        if ( Targets && !(SpellSummary[m_creature->m_spells[i]].Targets & (1 << (Targets-1))) )
            continue;

        //Check the type of spell if we are looking for a specific spell type
        if ( Effects && !(SpellSummary[m_creature->m_spells[i]].Effects & (1 << (Effects-1))) )
            continue;

        //Check for school if specified
        if (School >= 0 && TempSpell->SchoolMask & School)
            continue;

        //Check for spell mechanic if specified
        if (Mechanic >= 0 && TempSpell->Mechanic != Mechanic)
            continue;

        //Make sure that the spell uses the requested amount of power
        if (PowerCostMin &&  TempSpell->manaCost < PowerCostMin)
            continue;

        if (PowerCostMax && TempSpell->manaCost > PowerCostMax)
            continue;

        //Continue if we don't have the mana to actually cast this spell
        if (TempSpell->manaCost > m_creature->GetPower((Powers)TempSpell->powerType))
            continue;

        //Get the Range
        TempRange = GetSpellRangeStore()->LookupEntry(TempSpell->rangeIndex);

        //Spell has invalid range store so we can't use it
        if (!TempRange)
            continue;

        //Check if the spell meets our range requirements
        if (RangeMin && TempRange->maxRange < RangeMin)
            continue;
        if (RangeMax && TempRange->maxRange > RangeMax)
            continue;

        //Check if our target is in range
        if (m_creature->IsWithinDistInMap(Target, TempRange->minRange) || !m_creature->IsWithinDistInMap(Target, TempRange->maxRange))
            continue;

        //All good so lets add it to the spell list
        Spell[SpellCount] = TempSpell;
        SpellCount++;
    }

    //We got our usable spells so now lets randomly pick one
    if (!SpellCount)
        return NULL;

    return Spell[rand()%SpellCount];
}

bool ScriptedAI::CanCast(Unit* Target, SpellEntry const *Spell, bool Triggered)
{
    //No target so we can't cast
    if (!Target || !Spell)
        return false;

    //Silenced so we can't cast
    if (!Triggered && m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
        return false;

    //Check for power
    if (!Triggered && m_creature->GetPower((Powers)Spell->powerType) < Spell->manaCost)
        return false;

    SpellRangeEntry const *TempRange = NULL;

    TempRange = GetSpellRangeStore()->LookupEntry(Spell->rangeIndex);

    //Spell has invalid range store so we can't use it
    if (!TempRange)
        return false;

    //Unit is out of range of this spell
    if (m_creature->GetDistance(Target) > TempRange->maxRange || m_creature->GetDistance(Target) < TempRange->minRange)
        return false;

    return true;
}

void FillSpellSummary()
{
    SpellSummary = new TSpellSummary[GetSpellStore()->GetNumRows()];

    SpellEntry const* TempSpell;

    for (int i=0; i < GetSpellStore()->GetNumRows(); i++ )
    {
        SpellSummary[i].Effects = 0;
        SpellSummary[i].Targets = 0;

        TempSpell = GetSpellStore()->LookupEntry(i);
        //This spell doesn't exist
        if (!TempSpell)
            continue;

        for (int j=0; j<3; j++)
        {
            //Spell targets self
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_SELF )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SELF-1);

            //Spell targets a single enemy
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_CHAIN_DAMAGE ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_CURRENT_ENEMY_COORDINATES )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SINGLE_ENEMY-1);

            //Spell targets AoE at enemy
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_AROUND_CASTER ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA_CHANNELED )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_AOE_ENEMY-1);

            //Spell targets an enemy
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_CHAIN_DAMAGE ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_CURRENT_ENEMY_COORDINATES ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_AROUND_CASTER ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_ENEMY_IN_AREA_CHANNELED )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_ANY_ENEMY-1);

            //Spell targets a single friend(or self)
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_SELF ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_SINGLE_FRIEND ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_SINGLE_PARTY )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SINGLE_FRIEND-1);

            //Spell targets aoe friends
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_PARTY_AROUND_CASTER ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_AREAEFFECT_PARTY ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_AROUND_CASTER)
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_AOE_FRIEND-1);

            //Spell targets any friend(or self)
            if ( TempSpell->EffectImplicitTargetA[j] == TARGET_SELF ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_SINGLE_FRIEND ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_SINGLE_PARTY ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_PARTY_AROUND_CASTER ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_AREAEFFECT_PARTY ||
                TempSpell->EffectImplicitTargetA[j] == TARGET_ALL_AROUND_CASTER)
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_ANY_FRIEND-1);

            //Make sure that this spell includes a damage effect
            if ( TempSpell->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE || 
                TempSpell->Effect[j] == SPELL_EFFECT_INSTAKILL || 
                TempSpell->Effect[j] == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE || 
                TempSpell->Effect[j] == SPELL_EFFECT_HEALTH_LEECH )
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_DAMAGE-1);

            //Make sure that this spell includes a healing effect (or an apply aura with a periodic heal)
            if ( TempSpell->Effect[j] == SPELL_EFFECT_HEAL || 
                TempSpell->Effect[j] == SPELL_EFFECT_HEAL_MAX_HEALTH || 
                TempSpell->Effect[j] == SPELL_EFFECT_HEAL_MECHANICAL ||
                (TempSpell->Effect[j] == SPELL_EFFECT_APPLY_AURA  && TempSpell->EffectApplyAuraName[j]== 8 ))
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_HEALING-1);

            //Make sure that this spell applies an aura
            if ( TempSpell->Effect[j] == SPELL_EFFECT_APPLY_AURA )
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_AURA-1);
        }
    }
}

void ScriptedAI::DoZoneInCombat(Unit* pUnit)
{
    if (!pUnit)
        pUnit = m_creature;

    Map *map = pUnit->GetMap();

    if (!map->IsDungeon())                                  //use IsDungeon instead of Instanceable, in case battlegrounds will be instantiated
    {
        error_log("SD2: DoZoneInCombat call for map that isn't an instance (pUnit entry = %d)", pUnit->GetTypeId() == TYPEID_UNIT ? ((Creature*)pUnit)->GetEntry() : 0);
        return;
    }

    if (!pUnit->CanHaveThreatList() || pUnit->getThreatManager().isThreatListEmpty())
    {
        error_log("SD2: DoZoneInCombat called for creature that either cannot have threat list or has empty threat list (pUnit entry = %d)", pUnit->GetTypeId() == TYPEID_UNIT ? ((Creature*)pUnit)->GetEntry() : 0);

        return;
    }

    InstanceMap::PlayerList const &PlayerList = ((InstanceMap*)map)->GetPlayers();
    InstanceMap::PlayerList::const_iterator i;
    for (i = PlayerList.begin(); i != PlayerList.end(); ++i)
    {
        if(!(*i)->isGameMaster())
            pUnit->AddThreat(*i, 0.0f);
    }
}

void ScriptedAI::DoResetThreat()
{
    if (!m_creature->CanHaveThreatList() || m_creature->getThreatManager().isThreatListEmpty())
    {
        error_log("SD2: DoResetThreat called for creature that either cannot have threat list or has empty threat list (m_creature entry = %d)", m_creature->GetEntry());

        return;
    }

    std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
    std::list<HostilReference*>::iterator itr;

    for(itr = m_threatlist.begin(); itr != m_threatlist.end(); ++itr)
    {
        Unit* pUnit = NULL;
        pUnit = Unit::GetUnit((*m_creature), (*itr)->getUnitGuid());
        if(pUnit && m_creature->getThreatManager().getThreat(pUnit))
            m_creature->getThreatManager().modifyThreatPercent(pUnit, -100);
    }
}

void ScriptedAI::DoTeleportPlayer(Unit* pUnit, float x, float y, float z, float o)
{
    if(!pUnit || pUnit->GetTypeId() != TYPEID_PLAYER)
    {
        if(pUnit)
            error_log("SD2: Creature %u (Entry: %u) Tried to teleport non-player unit (Type: %u GUID: %u) to x: %f y:%f z: %f o: %f. Aborted.", m_creature->GetGUID(), m_creature->GetEntry(), pUnit->GetTypeId(), pUnit->GetGUID(), x, y, z, o);
        return;
    }

    ((Player*)pUnit)->TeleportTo(pUnit->GetMapId(), x, y, z, o, TELE_TO_NOT_LEAVE_COMBAT);
}

Unit* ScriptedAI::DoSelectLowestHpFriendly(float range, uint32 MinHPDiff)
{
    CellPair p(MaNGOS::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Unit* pUnit = NULL;

    MaNGOS::MostHPMissingInRange u_check(m_creature, range, MinHPDiff);
    MaNGOS::UnitLastSearcher<MaNGOS::MostHPMissingInRange> searcher(pUnit, u_check);

    /*
    typedef TYPELIST_4(GameObject, Creature*except pets*, DynamicObject, Corpse*Bones*) AllGridObjectTypes;
    This means that if we only search grid then we cannot possibly return pets or players so this is safe
    */
    TypeContainerVisitor<MaNGOS::UnitLastSearcher<MaNGOS::MostHPMissingInRange>, GridTypeMapContainer >  grid_unit_searcher(searcher);

    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, grid_unit_searcher, *(m_creature->GetMap()));
    return pUnit;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyCC(float range)
{
    CellPair p(MaNGOS::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    std::list<Creature*> pList;

    MaNGOS::FriendlyCCedInRange u_check(m_creature, range);
    MaNGOS::CreatureListSearcher<MaNGOS::FriendlyCCedInRange> searcher(pList, u_check);

    TypeContainerVisitor<MaNGOS::CreatureListSearcher<MaNGOS::FriendlyCCedInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, grid_creature_searcher, *(m_creature->GetMap()));
    
    return pList;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyMissingBuff(float range, uint32 spellid)
{
    CellPair p(MaNGOS::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    std::list<Creature*> pList;

    MaNGOS::FriendlyMissingBuffInRange u_check(m_creature, range, spellid);
    MaNGOS::CreatureListSearcher<MaNGOS::FriendlyMissingBuffInRange> searcher(pList, u_check);

    TypeContainerVisitor<MaNGOS::CreatureListSearcher<MaNGOS::FriendlyMissingBuffInRange>, GridTypeMapContainer >  grid_creature_searcher(searcher);

    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, grid_creature_searcher, *(m_creature->GetMap()));
    
    return pList;
}

void Scripted_NoMovementAI::MoveInLineOfSight(Unit *who)
{
    if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
    {
        if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
            return;

        float attackRadius = m_creature->GetAttackDistance(who);
        if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
        {
            DoStartAttackNoMovement(who);
            who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

            if (!InCombat)
            {
                InCombat = true;
                Aggro(who);
            }
        }
    }
}

void Scripted_NoMovementAI::AttackStart(Unit* who)
{
    if (!who)
        return;

    if (who->isTargetableForAttack())
    {
        //Begin attack
        DoStartAttackNoMovement(who);

        if (!InCombat)
        {
            InCombat = true;
            Aggro(who);
        }
    }
}
