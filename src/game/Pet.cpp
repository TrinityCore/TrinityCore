/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Log.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Pet.h"
#include "MapManager.h"
#include "Formulas.h"
#include "SpellAuras.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "Util.h"

char const* petTypeSuffix[MAX_PET_TYPE] =
{
    "'s Minion",                                            // SUMMON_PET
    "'s Pet",                                               // HUNTER_PET
    "'s Guardian",                                          // GUARDIAN_PET
    "'s Companion"                                          // MINI_PET
};

//numbers represent minutes * 100 while happy (you get 100 loyalty points per min while happy)
uint32 const LevelUpLoyalty[6] =
{
    5500,
    11500,
    17000,
    23500,
    31000,
    39500,
};

uint32 const LevelStartLoyalty[6] =
{
    2000,
    4500,
    7000,
    10000,
    13500,
    17500,
};

Pet::Pet(PetType type) : Creature()
{
    m_isPet = true;
    m_name = "Pet";
    m_petType = type;

    m_removed = false;
    m_regenTimer = 4000;
    m_happinessTimer = 7500;
    m_loyaltyTimer = 12000;
    m_duration = 0;
    m_bonusdamage = 0;

    m_loyaltyPoints = 0;
    m_TrainingPoints = 0;
    m_resetTalentsCost = 0;
    m_resetTalentsTime = 0;

    m_auraUpdateMask = 0;

    // pets always have a charminfo, even if they are not actually charmed
    CharmInfo* charmInfo = InitCharmInfo();

    if(type == MINI_PET || type == POSSESSED_PET)                                    // always passive
        SetReactState(REACT_PASSIVE);
    else if(type == GUARDIAN_PET)                           // always aggressive
        SetReactState(REACT_AGGRESSIVE);

    m_spells.clear();
    m_Auras.clear();
    m_CreatureSpellCooldowns.clear();
    m_CreatureCategoryCooldowns.clear();
    m_autospells.clear();
    m_declinedname = NULL;
    //m_isActive = true;
}

Pet::~Pet()
{
    if(m_uint32Values)                                      // only for fully created Object
    {
        for (PetSpellMap::iterator i = m_spells.begin(); i != m_spells.end(); ++i)
            delete i->second;
        ObjectAccessor::Instance().RemoveObject(this);
    }

    delete m_declinedname;
}

void Pet::AddToWorld()
{
    ///- Register the pet for guid lookup
    if(!IsInWorld())
    {   
        ObjectAccessor::Instance().AddObject(this);
        Unit::AddToWorld();
    }
}

void Pet::RemoveFromWorld()
{
    ///- Remove the pet from the accessor
    if(IsInWorld())
    {
        ObjectAccessor::Instance().RemoveObject(this);
        ///- Don't call the function for Creature, normal mobs + totems go in a different storage
        Unit::RemoveFromWorld();
    }
}

bool Pet::LoadPetFromDB( Unit* owner, uint32 petentry, uint32 petnumber, bool current )
{
    uint32 ownerid = owner->GetGUIDLow();

    QueryResult *result;

    if(petnumber)
        // known petnumber entry                  0   1      2      3        4      5    6           7              8        9           10    11    12       13         14       15            16      17              18        19                 20                 21              22
        result = CharacterDatabase.PQuery("SELECT id, entry, owner, modelid, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, slot, name, renamed, curhealth, curmana, curhappiness, abdata, TeachSpelldata, savetime, resettalents_cost, resettalents_time, CreatedBySpell, PetType FROM character_pet WHERE owner = '%u' AND id = '%u'",ownerid, petnumber);
    else if(current)
        // current pet (slot 0)                   0   1      2      3        4      5    6           7              8        9           10    11    12       13         14       15            16      17              18        19                 20                 21              22
        result = CharacterDatabase.PQuery("SELECT id, entry, owner, modelid, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, slot, name, renamed, curhealth, curmana, curhappiness, abdata, TeachSpelldata, savetime, resettalents_cost, resettalents_time, CreatedBySpell, PetType FROM character_pet WHERE owner = '%u' AND slot = '0'",ownerid );
    else if(petentry)
        // known petentry entry (unique for summoned pet, but non unique for hunter pet (only from current or not stabled pets)
        //                                        0   1      2      3        4      5    6           7              8        9           10    11    12       13         14       15            16      17              18        19                 20                 21              22
        result = CharacterDatabase.PQuery("SELECT id, entry, owner, modelid, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, slot, name, renamed, curhealth, curmana, curhappiness, abdata, TeachSpelldata, savetime, resettalents_cost, resettalents_time, CreatedBySpell, PetType FROM character_pet WHERE owner = '%u' AND entry = '%u' AND (slot = '0' OR slot = '3') ",ownerid, petentry );
    else
        // any current or other non-stabled pet (for hunter "call pet")
        //                                        0   1      2      3        4      5    6           7              8        9           10    11    12       13         14       15            16      17              18        19                 20                 21              22
        result = CharacterDatabase.PQuery("SELECT id, entry, owner, modelid, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, slot, name, renamed, curhealth, curmana, curhappiness, abdata, TeachSpelldata, savetime, resettalents_cost, resettalents_time, CreatedBySpell, PetType FROM character_pet WHERE owner = '%u' AND (slot = '0' OR slot = '3') ",ownerid);

    if(!result)
        return false;

    Field *fields = result->Fetch();

    // update for case of current pet "slot = 0"
    petentry = fields[1].GetUInt32();
    if(!petentry)
    {
        delete result;
        return false;
    }

    uint32 summon_spell_id = fields[21].GetUInt32();
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(summon_spell_id);

    bool is_temporary_summoned = spellInfo && GetSpellDuration(spellInfo) > 0;

    // check temporary summoned pets like mage water elemental
    if(current && is_temporary_summoned)
    {
        delete result;
        return false;
    }

    Map *map = owner->GetMap();
    uint32 guid = objmgr.GenerateLowGuid(HIGHGUID_PET);
    uint32 pet_number = fields[0].GetUInt32();
    if(!Create(guid, map, petentry, pet_number))
    {
        delete result;
        return false;
    }

    float px, py, pz;
    owner->GetClosePoint(px, py, pz, GetObjectSize(), PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

    Relocate(px, py, pz, owner->GetOrientation());

    if(!IsPositionValid())
    {
        sLog.outError("ERROR: Pet (guidlow %d, entry %d) not loaded. Suggested coordinates isn't valid (X: %f Y: %f)",
            GetGUIDLow(), GetEntry(), GetPositionX(), GetPositionY());
        delete result;
        return false;
    }

    setPetType(PetType(fields[22].GetUInt8()));
    SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,owner->getFaction());
    SetUInt32Value(UNIT_CREATED_BY_SPELL, summon_spell_id);

    CreatureInfo const *cinfo = GetCreatureInfo();
    if(cinfo->type == CREATURE_TYPE_CRITTER)
    {
        AIM_Initialize();
        map->Add((Creature*)this);
        delete result;
        return true;
    }
    if(getPetType()==HUNTER_PET || (getPetType()==SUMMON_PET && cinfo->type == CREATURE_TYPE_DEMON && owner->getClass() == CLASS_WARLOCK))
        m_charmInfo->SetPetNumber(pet_number, true);
    else
        m_charmInfo->SetPetNumber(pet_number, false);
    SetUInt64Value(UNIT_FIELD_SUMMONEDBY, owner->GetGUID());
    SetDisplayId(fields[3].GetUInt32());
    SetNativeDisplayId(fields[3].GetUInt32());
    uint32 petlevel=fields[4].GetUInt32();
    SetUInt32Value(UNIT_NPC_FLAGS , 0);
    SetName(fields[11].GetString());

    switch(getPetType())
    {

        case SUMMON_PET:
            petlevel=owner->getLevel();

            SetUInt32Value(UNIT_FIELD_BYTES_0,2048);
            SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
                                                            // this enables popup window (pet dismiss, cancel)
            break;
        case HUNTER_PET:
            SetUInt32Value(UNIT_FIELD_BYTES_0, 0x02020100);
            SetByteValue(UNIT_FIELD_BYTES_1, 1, fields[8].GetUInt32());
            SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE );
            SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY | UNIT_BYTE2_FLAG_AURAS | UNIT_BYTE2_FLAG_UNK5 );

            if(fields[12].GetBool())
                SetByteValue(UNIT_FIELD_BYTES_2, 2, UNIT_RENAME_NOT_ALLOWED);
            else
                SetByteValue(UNIT_FIELD_BYTES_2, 2, UNIT_RENAME_ALLOWED);

            SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
                                                            // this enables popup window (pet abandon, cancel)
            SetTP(fields[9].GetInt32());
            SetMaxPower(POWER_HAPPINESS,GetCreatePowers(POWER_HAPPINESS));
            SetPower(   POWER_HAPPINESS,fields[15].GetUInt32());
            setPowerType(POWER_FOCUS);
            break;
        default:
            sLog.outError("Pet have incorrect type (%u) for pet loading.",getPetType());
    }
    InitStatsForLevel( petlevel);
    SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, time(NULL));
    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, fields[5].GetUInt32());
    SetUInt64Value(UNIT_FIELD_CREATEDBY, owner->GetGUID());

    SetReactState( ReactStates( fields[6].GetUInt8() ));
    m_loyaltyPoints = fields[7].GetInt32();

    uint32 savedhealth = fields[13].GetUInt32();
    uint32 savedmana = fields[14].GetUInt32();

    // set current pet as current
    if(fields[10].GetUInt32() != 0)
    {
        CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("UPDATE character_pet SET slot = '3' WHERE owner = '%u' AND slot = '0' AND id <> '%u'",ownerid, m_charmInfo->GetPetNumber());
        CharacterDatabase.PExecute("UPDATE character_pet SET slot = '0' WHERE owner = '%u' AND id = '%u'",ownerid, m_charmInfo->GetPetNumber());
        CharacterDatabase.CommitTransaction();
    }

    if(!is_temporary_summoned)
    {
        // permanent controlled pets store state in DB
        Tokens tokens = StrSplit(fields[16].GetString(), " ");

        if(tokens.size() != 20)
        {
            delete result;
            return false;
        }

        int index;
        Tokens::iterator iter;
        for(iter = tokens.begin(), index = 0; index < 10; ++iter, ++index )
        {
            m_charmInfo->GetActionBarEntry(index)->Type = atol((*iter).c_str());
            ++iter;
            m_charmInfo->GetActionBarEntry(index)->SpellOrAction = atol((*iter).c_str());

            // patch for old data where some spells have ACT_DECIDE but should have ACT_CAST
            // so overwrite old state
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(m_charmInfo->GetActionBarEntry(index)->SpellOrAction);
            if (spellInfo && spellInfo->AttributesEx & SPELL_ATTR_EX_UNAUTOCASTABLE_BY_PET) m_charmInfo->GetActionBarEntry(index)->Type = ACT_CAST;
        }

        //init teach spells
        tokens = StrSplit(fields[17].GetString(), " ");
        for (iter = tokens.begin(), index = 0; index < 4; ++iter, ++index)
        {
            uint32 tmp = atol((*iter).c_str());

            ++iter;

            if(tmp)
                AddTeachSpell(tmp, atol((*iter).c_str()));
            else
                break;
        }
    }

    // since last save (in seconds)
    uint32 timediff = (time(NULL) - fields[18].GetUInt32());

    delete result;

    //load spells/cooldowns/auras
    SetCanModifyStats(true);
    _LoadAuras(timediff);

    //init AB
    if(is_temporary_summoned)
    {
        // Temporary summoned pets always have initial spell list at load
        InitPetCreateSpells();
    }
    else
    {
        LearnPetPassives();
        CastPetAuras(current);
    }

    if(getPetType() == SUMMON_PET && !current)              //all (?) summon pets come with full health when called, but not when they are current
    {
        SetHealth(GetMaxHealth());
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    }
    else
    {
        SetHealth(savedhealth > GetMaxHealth() ? GetMaxHealth() : savedhealth);
        SetPower(POWER_MANA, savedmana > GetMaxPower(POWER_MANA) ? GetMaxPower(POWER_MANA) : savedmana);
    }

    AIM_Initialize();
    map->Add((Creature*)this);

    // Spells should be loaded after pet is added to map, because in CanCast is check on it
    _LoadSpells();
    _LoadSpellCooldowns();

    owner->SetPet(this);                                    // in DB stored only full controlled creature
    sLog.outDebug("New Pet has guid %u", GetGUIDLow());

    if(owner->GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)owner)->PetSpellInitialize();
        if(((Player*)owner)->GetGroup())
            ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_PET);
    }

    if(owner->GetTypeId() == TYPEID_PLAYER && getPetType() == HUNTER_PET)
    {
        result = CharacterDatabase.PQuery("SELECT genitive, dative, accusative, instrumental, prepositional FROM character_pet_declinedname WHERE owner = '%u' AND id = '%u'", owner->GetGUIDLow(), GetCharmInfo()->GetPetNumber());

        if(result)
        {
            if(m_declinedname)
                delete m_declinedname;

            m_declinedname = new DeclinedName;
            Field *fields = result->Fetch();
            for(int i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            {
                m_declinedname->name[i] = fields[i].GetCppString();
            }
        }
    }

    return true;
}

void Pet::SavePetToDB(PetSaveMode mode)
{
    if(!GetEntry())
        return;

    // save only fully controlled creature
    if(!isControlled())
        return;

    uint32 curhealth = GetHealth();
    uint32 curmana = GetPower(POWER_MANA);

    switch(mode)
    {
        case PET_SAVE_IN_STABLE_SLOT_1:
        case PET_SAVE_IN_STABLE_SLOT_2:
        case PET_SAVE_NOT_IN_SLOT:
        {
            RemoveAllAuras();

            //only alive hunter pets get auras saved, the others don't
            if(!(getPetType() == HUNTER_PET && isAlive()))
                m_Auras.clear();
        }
        default:
            break;
    }

    _SaveSpells();
    _SaveSpellCooldowns();
    _SaveAuras();

    switch(mode)
    {
        case PET_SAVE_AS_CURRENT:
        case PET_SAVE_IN_STABLE_SLOT_1:
        case PET_SAVE_IN_STABLE_SLOT_2:
        case PET_SAVE_NOT_IN_SLOT:
        {
            uint32 loyalty =1;
            if(getPetType()!=HUNTER_PET)
                loyalty = GetLoyaltyLevel();

            uint32 owner = GUID_LOPART(GetOwnerGUID());
            std::string name = m_name;
            CharacterDatabase.escape_string(name);
            CharacterDatabase.BeginTransaction();
            // remove current data
            CharacterDatabase.PExecute("DELETE FROM character_pet WHERE owner = '%u' AND id = '%u'", owner,m_charmInfo->GetPetNumber() );

            // prevent duplicate using slot (except PET_SAVE_NOT_IN_SLOT)
            if(mode!=PET_SAVE_NOT_IN_SLOT)
                CharacterDatabase.PExecute("UPDATE character_pet SET slot = 3 WHERE owner = '%u' AND slot = '%u'", owner, uint32(mode) );

            // prevent existence another hunter pet in PET_SAVE_AS_CURRENT and PET_SAVE_NOT_IN_SLOT
            if(getPetType()==HUNTER_PET && (mode==PET_SAVE_AS_CURRENT||mode==PET_SAVE_NOT_IN_SLOT))
                CharacterDatabase.PExecute("DELETE FROM character_pet WHERE owner = '%u' AND (slot = '0' OR slot = '3')", owner );
            // save pet
            std::ostringstream ss;
            ss  << "INSERT INTO character_pet ( id, entry,  owner, modelid, level, exp, Reactstate, loyaltypoints, loyalty, trainpoint, slot, name, renamed, curhealth, curmana, curhappiness, abdata,TeachSpelldata,savetime,resettalents_cost,resettalents_time,CreatedBySpell,PetType) "
                << "VALUES ("
                << m_charmInfo->GetPetNumber() << ", "
                << GetEntry() << ", "
                << owner << ", "
                << GetNativeDisplayId() << ", "
                << getLevel() << ", "
                << GetUInt32Value(UNIT_FIELD_PETEXPERIENCE) << ", "
                << uint32(GetReactState()) << ", "
                << m_loyaltyPoints << ", "
                << GetLoyaltyLevel() << ", "
                << m_TrainingPoints << ", "
                << uint32(mode) << ", '"
                << name.c_str() << "', "
                << uint32((GetByteValue(UNIT_FIELD_BYTES_2, 2) == UNIT_RENAME_ALLOWED)?0:1) << ", "
                << (curhealth<1?1:curhealth) << ", "
                << curmana << ", "
                << GetPower(POWER_HAPPINESS) << ", '";

            for(uint32 i = 0; i < 10; i++)
                ss << uint32(m_charmInfo->GetActionBarEntry(i)->Type) << " " << uint32(m_charmInfo->GetActionBarEntry(i)->SpellOrAction) << " ";
            ss << "', '";

            //save spells the pet can teach to it's Master
            {
                int i = 0;
                for(TeachSpellMap::iterator itr = m_teachspells.begin(); i < 4 && itr != m_teachspells.end(); ++i, ++itr)
                    ss << itr->first << " " << itr->second << " ";
                for(; i < 4; ++i)
                    ss << uint32(0) << " " << uint32(0) << " ";
            }

            ss  << "', "
                << time(NULL) << ", "
                << uint32(m_resetTalentsCost) << ", "
                << uint64(m_resetTalentsTime) << ", "
                << GetUInt32Value(UNIT_CREATED_BY_SPELL) << ", "
                << uint32(getPetType()) << ")";

            CharacterDatabase.Execute( ss.str().c_str() );

            CharacterDatabase.CommitTransaction();
            break;
        }
        case PET_SAVE_AS_DELETED:
        {
            RemoveAllAuras();
            DeleteFromDB(m_charmInfo->GetPetNumber());
            break;
        }
        default:
            sLog.outError("Unknown pet save/remove mode: %d",mode);
    }
}

void Pet::DeleteFromDB(uint32 guidlow)
{
    CharacterDatabase.PExecute("DELETE FROM character_pet WHERE id = '%u'", guidlow);
    CharacterDatabase.PExecute("DELETE FROM character_pet_declinedname WHERE id = '%u'", guidlow);
    CharacterDatabase.PExecute("DELETE FROM pet_aura WHERE guid = '%u'", guidlow);
    CharacterDatabase.PExecute("DELETE FROM pet_spell WHERE guid = '%u'", guidlow);
    CharacterDatabase.PExecute("DELETE FROM pet_spell_cooldown WHERE guid = '%u'", guidlow);
}

void Pet::setDeathState(DeathState s)                       // overwrite virtual Creature::setDeathState and Unit::setDeathState
{
    Creature::setDeathState(s);
    if(getDeathState()==CORPSE)
    {
        //remove summoned pet (no corpse)
        if(getPetType()==SUMMON_PET)
            Remove(PET_SAVE_NOT_IN_SLOT);
        // other will despawn at corpse desppawning (Pet::Update code)
        else
        {
            // pet corpse non lootable and non skinnable
            SetUInt32Value( UNIT_DYNAMIC_FLAGS, 0x00 );
            RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

             //lose happiness when died and not in BG/Arena
            MapEntry const* mapEntry = sMapStore.LookupEntry(GetMapId());
            if(!mapEntry || (mapEntry->map_type != MAP_ARENA && mapEntry->map_type != MAP_BATTLEGROUND))
                ModifyPower(POWER_HAPPINESS, -HAPPINESS_LEVEL_SIZE);

            SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_ROTATE);
        }
    }
    else if(getDeathState()==ALIVE)
    {
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_ROTATE);
        CastPetAuras(true);
    }
}

void Pet::Update(uint32 diff)
{
    if(m_removed)                                           // pet already removed, just wait in remove queue, no updates
        return;

    switch( m_deathState )
    {
        case CORPSE:
        {
            if( m_deathTimer <= diff )
            {
                assert(getPetType()!=SUMMON_PET && "Must be already removed.");
                Remove(PET_SAVE_NOT_IN_SLOT);               //hunters' pets never get removed because of death, NEVER!
                return;
            }
            break;
        }
        case ALIVE:
        {
            // unsummon pet that lost owner
            Unit* owner = GetOwner();
            if(!owner || (!IsWithinDistInMap(owner, OWNER_MAX_DISTANCE) && !isPossessed()) || isControlled() && !owner->GetPetGUID())
            {
                Remove(PET_SAVE_NOT_IN_SLOT, true);
                return;
            }

            if(isControlled())
            {
                if( owner->GetPetGUID() != GetGUID() )
                {
                    Remove(getPetType()==HUNTER_PET?PET_SAVE_AS_DELETED:PET_SAVE_NOT_IN_SLOT);
                    return;
                }
            }

            if(m_duration > 0)
            {
                if(m_duration > diff)
                    m_duration -= diff;
                else
                {
                    Remove(getPetType() != SUMMON_PET ? PET_SAVE_AS_DELETED:PET_SAVE_NOT_IN_SLOT);
                    return;
                }
            }

            if(getPetType() != HUNTER_PET)
                break;

            //regenerate Focus
            if(m_regenTimer <= diff)
            {
                RegenerateFocus();
                m_regenTimer = 4000;
            }
            else
                m_regenTimer -= diff;

            if(m_happinessTimer <= diff)
            {
                LooseHappiness();
                m_happinessTimer = 7500;
            }
            else
                m_happinessTimer -= diff;

            if(m_loyaltyTimer <= diff)
            {
                TickLoyaltyChange();
                m_loyaltyTimer = 12000;
            }
            else
                m_loyaltyTimer -= diff;

            break;
        }
        default:
            break;
    }
    Creature::Update(diff);
}

void Pet::RegenerateFocus()
{
    uint32 curValue = GetPower(POWER_FOCUS);
    uint32 maxValue = GetMaxPower(POWER_FOCUS);

    if (curValue >= maxValue)
        return;

    float addvalue = 24 * sWorld.getRate(RATE_POWER_FOCUS);

    AuraList const& ModPowerRegenPCTAuras = GetAurasByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
    for(AuraList::const_iterator i = ModPowerRegenPCTAuras.begin(); i != ModPowerRegenPCTAuras.end(); ++i)
        if ((*i)->GetModifier()->m_miscvalue == POWER_FOCUS)
            addvalue *= ((*i)->GetModifierValue() + 100) / 100.0f;

    ModifyPower(POWER_FOCUS, (int32)addvalue);
}

void Pet::LooseHappiness()
{
    uint32 curValue = GetPower(POWER_HAPPINESS);
    if (curValue <= 0)
        return;
    int32 addvalue = (140 >> GetLoyaltyLevel()) * 125;      //value is 70/35/17/8/4 (per min) * 1000 / 8 (timer 7.5 secs)
    if(isInCombat())                                        //we know in combat happiness fades faster, multiplier guess
        addvalue = int32(addvalue * 1.5);
    ModifyPower(POWER_HAPPINESS, -addvalue);
}

void Pet::ModifyLoyalty(int32 addvalue)
{
    uint32 loyaltylevel = GetLoyaltyLevel();

    if(addvalue > 0)                                        //only gain influenced, not loss
        addvalue = int32((float)addvalue * sWorld.getRate(RATE_LOYALTY));

    if(loyaltylevel >= BEST_FRIEND && (addvalue + m_loyaltyPoints) > int32(GetMaxLoyaltyPoints(loyaltylevel)))
        return;

    m_loyaltyPoints += addvalue;

    if(m_loyaltyPoints < 0)
    {
        if(loyaltylevel > REBELLIOUS)
        {
            //level down
            --loyaltylevel;
            SetLoyaltyLevel(LoyaltyLevel(loyaltylevel));
            m_loyaltyPoints = GetStartLoyaltyPoints(loyaltylevel);
            SetTP(m_TrainingPoints - int32(getLevel()));
        }
        else
        {
            m_loyaltyPoints = 0;
            Unit* owner = GetOwner();
            if(owner && owner->GetTypeId() == TYPEID_PLAYER)
            {
                WorldPacket data(SMSG_PET_BROKEN, 0);
                ((Player*)owner)->GetSession()->SendPacket(&data);

                //run away
                ((Player*)owner)->RemovePet(this,PET_SAVE_AS_DELETED);
            }
        }
    }
    //level up
    else if(m_loyaltyPoints > int32(GetMaxLoyaltyPoints(loyaltylevel)))
    {
        ++loyaltylevel;
        SetLoyaltyLevel(LoyaltyLevel(loyaltylevel));
        m_loyaltyPoints = GetStartLoyaltyPoints(loyaltylevel);
        SetTP(m_TrainingPoints + getLevel());
    }
}

void Pet::TickLoyaltyChange()
{
    int32 addvalue;

    switch(GetHappinessState())
    {
        case HAPPY:   addvalue =  20; break;
        case CONTENT: addvalue =  10; break;
        case UNHAPPY: addvalue = -20; break;
        default:
            return;
    }
    ModifyLoyalty(addvalue);
}

void Pet::KillLoyaltyBonus(uint32 level)
{
    if(level > 100)
        return;

                                                            //at lower levels gain is faster | the lower loyalty the more loyalty is gained
    uint32 bonus = uint32(((100 - level) / 10) + (6 - GetLoyaltyLevel()));
    ModifyLoyalty(bonus);
}

HappinessState Pet::GetHappinessState()
{
    if(GetPower(POWER_HAPPINESS) < HAPPINESS_LEVEL_SIZE)
        return UNHAPPY;
    else if(GetPower(POWER_HAPPINESS) >= HAPPINESS_LEVEL_SIZE * 2)
        return HAPPY;
    else
        return CONTENT;
}

void Pet::SetLoyaltyLevel(LoyaltyLevel level)
{
    SetByteValue(UNIT_FIELD_BYTES_1, 1, level);
}

bool Pet::CanTakeMoreActiveSpells(uint32 spellid)
{
    uint8  activecount = 1;
    uint32 chainstartstore[ACTIVE_SPELLS_MAX];

    if(IsPassiveSpell(spellid))
        return true;

    chainstartstore[0] = spellmgr.GetFirstSpellInChain(spellid);

    for (PetSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
    {
        if(IsPassiveSpell(itr->first))
            continue;

        uint32 chainstart = spellmgr.GetFirstSpellInChain(itr->first);

        uint8 x;

        for(x = 0; x < activecount; x++)
        {
            if(chainstart == chainstartstore[x])
                break;
        }

        if(x == activecount)                                //spellchain not yet saved -> add active count
        {
            ++activecount;
            if(activecount > ACTIVE_SPELLS_MAX)
                return false;
            chainstartstore[x] = chainstart;
        }
    }
    return true;
}

bool Pet::HasTPForSpell(uint32 spellid)
{
    int32 neededtrainp = GetTPForSpell(spellid);
    if((m_TrainingPoints - neededtrainp < 0 || neededtrainp < 0) && neededtrainp != 0)
        return false;
    return true;
}

int32 Pet::GetTPForSpell(uint32 spellid)
{
    uint32 basetrainp = 0;

    SkillLineAbilityMap::const_iterator lower = spellmgr.GetBeginSkillLineAbilityMap(spellid);
    SkillLineAbilityMap::const_iterator upper = spellmgr.GetEndSkillLineAbilityMap(spellid);
    for(SkillLineAbilityMap::const_iterator _spell_idx = lower; _spell_idx != upper; ++_spell_idx)
    {
        if(!_spell_idx->second->reqtrainpoints)
            return 0;

        basetrainp = _spell_idx->second->reqtrainpoints;
        break;
    }

    uint32 spenttrainp = 0;
    uint32 chainstart = spellmgr.GetFirstSpellInChain(spellid);

    for (PetSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
    {
        if(itr->second->state == PETSPELL_REMOVED)
            continue;

        if(spellmgr.GetFirstSpellInChain(itr->first) == chainstart)
        {
            SkillLineAbilityMap::const_iterator _lower = spellmgr.GetBeginSkillLineAbilityMap(itr->first);
            SkillLineAbilityMap::const_iterator _upper = spellmgr.GetEndSkillLineAbilityMap(itr->first);

            for(SkillLineAbilityMap::const_iterator _spell_idx2 = _lower; _spell_idx2 != _upper; ++_spell_idx2)
            {
                if(_spell_idx2->second->reqtrainpoints > spenttrainp)
                {
                    spenttrainp = _spell_idx2->second->reqtrainpoints;
                    break;
                }
            }
        }
    }

    return int32(basetrainp) - int32(spenttrainp);
}

uint32 Pet::GetMaxLoyaltyPoints(uint32 level)
{
    return LevelUpLoyalty[level - 1];
}

uint32 Pet::GetStartLoyaltyPoints(uint32 level)
{
    return LevelStartLoyalty[level - 1];
}

void Pet::SetTP(int32 TP)
{
    m_TrainingPoints = TP;
    SetUInt32Value(UNIT_TRAINING_POINTS, (uint32)GetDispTP());
}

int32 Pet::GetDispTP()
{
    if(getPetType()!= HUNTER_PET)
        return(0);
    if(m_TrainingPoints < 0)
        return -m_TrainingPoints;
    else
        return -(m_TrainingPoints + 1);
}

void Pet::Remove(PetSaveMode mode, bool returnreagent)
{
    Unit* owner = GetOwner();

    if(owner)
    {
        if(owner->GetTypeId()==TYPEID_PLAYER)
        {
            ((Player*)owner)->RemovePet(this,mode,returnreagent);
            return;
        }

        // only if current pet in slot
        if(owner->GetPetGUID()==GetGUID())
            owner->SetPet(0);
    }

    CleanupsBeforeDelete();
    AddObjectToRemoveList();
    m_removed = true;
}

void Pet::GivePetXP(uint32 xp)
{
    if(getPetType() != HUNTER_PET)
        return;

    if ( xp < 1 )
        return;

    if(!isAlive())
        return;

    uint32 level = getLevel();

    // XP to money conversion processed in Player::RewardQuest
    if(level >= sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL))
        return;

    uint32 curXP = GetUInt32Value(UNIT_FIELD_PETEXPERIENCE);
    uint32 nextLvlXP = GetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP);
    uint32 newXP = curXP + xp;

    if(newXP >= nextLvlXP && level+1 > GetOwner()->getLevel())
    {
        SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, nextLvlXP-1);
        return;
    }

    while( newXP >= nextLvlXP && level < sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL) )
    {
        newXP -= nextLvlXP;

        SetLevel( level + 1 );
        SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(level+1))/4));

        level = getLevel();
        nextLvlXP = GetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP);
        GivePetLevel(level);
    }

    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, newXP);

    if(getPetType() == HUNTER_PET)
        KillLoyaltyBonus(level);
}

void Pet::GivePetLevel(uint32 level)
{
    if(!level)
        return;

    InitStatsForLevel( level);

    SetTP(m_TrainingPoints + (GetLoyaltyLevel() - 1));
}

bool Pet::CreateBaseAtCreature(Creature* creature)
{
    if(!creature)
    {
        sLog.outError("CRITICAL ERROR: NULL pointer parsed into CreateBaseAtCreature()");
        return false;
    }
    uint32 guid=objmgr.GenerateLowGuid(HIGHGUID_PET);

    sLog.outDebug("SetInstanceID()");
    SetInstanceId(creature->GetInstanceId());

    sLog.outDebug("Create pet");
    uint32 pet_number = objmgr.GeneratePetNumber();
    if(!Create(guid, creature->GetMap(), creature->GetEntry(), pet_number))
        return false;

    Relocate(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());

    if(!IsPositionValid())
    {
        sLog.outError("ERROR: Pet (guidlow %d, entry %d) not created base at creature. Suggested coordinates isn't valid (X: %f Y: %f)",
            GetGUIDLow(), GetEntry(), GetPositionX(), GetPositionY());
        return false;
    }

    CreatureInfo const *cinfo = GetCreatureInfo();
    if(!cinfo)
    {
        sLog.outError("ERROR: CreateBaseAtCreature() failed, creatureInfo is missing!");
        return false;
    }

    if(cinfo->type == CREATURE_TYPE_CRITTER)
    {
        setPetType(MINI_PET);
        return true;
    }
    SetDisplayId(creature->GetDisplayId());
    SetNativeDisplayId(creature->GetNativeDisplayId());
    SetMaxPower(POWER_HAPPINESS, GetCreatePowers(POWER_HAPPINESS));
    SetPower(POWER_HAPPINESS, 166500);
    setPowerType(POWER_FOCUS);
    SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, 0);
    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
    SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(creature->getLevel()))/4));
    SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    SetUInt32Value(UNIT_NPC_FLAGS, 0);

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(creature->GetCreatureInfo()->family);
    if( char* familyname = cFamily->Name[sWorld.GetDefaultDbcLocale()] )
        SetName(familyname);
    else
        SetName(creature->GetName());

    m_loyaltyPoints = 1000;
    if(cinfo->type == CREATURE_TYPE_BEAST)
    {
        SetUInt32Value(UNIT_FIELD_BYTES_0, 0x02020100);
        SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE );
        SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY | UNIT_BYTE2_FLAG_AURAS | UNIT_BYTE2_FLAG_UNK5 );
        SetByteValue(UNIT_FIELD_BYTES_2, 2, UNIT_RENAME_ALLOWED);

        SetUInt32Value(UNIT_MOD_CAST_SPEED, creature->GetUInt32Value(UNIT_MOD_CAST_SPEED) );
        SetLoyaltyLevel(REBELLIOUS);
    }
    return true;
}

bool Pet::InitStatsForLevel(uint32 petlevel)
{
    CreatureInfo const *cinfo = GetCreatureInfo();
    assert(cinfo);

    Unit* owner = GetOwner();
    if(!owner)
    {
        sLog.outError("ERROR: attempt to summon pet (Entry %u) without owner! Attempt terminated.", cinfo->Entry);
        return false;
    }

    uint32 creature_ID = (getPetType() == HUNTER_PET) ? 1 : cinfo->Entry;

    SetLevel(petlevel);

    SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));

    SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(petlevel*50));

    SetAttackTime(BASE_ATTACK, BASE_ATTACK_TIME);
    SetAttackTime(OFF_ATTACK, BASE_ATTACK_TIME);
    SetAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);

    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0);

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cinfo->family);
    if(cFamily && cFamily->minScale > 0.0f && getPetType()==HUNTER_PET)
    {
        float scale;
        if (getLevel() >= cFamily->maxScaleLevel)
            scale = cFamily->maxScale;
        else if (getLevel() <= cFamily->minScaleLevel)
            scale = cFamily->minScale;
        else
          scale = cFamily->minScale + (float)(getLevel() - cFamily->minScaleLevel) / (float)cFamily->maxScaleLevel * (cFamily->maxScale - cFamily->minScale);

        SetFloatValue(OBJECT_FIELD_SCALE_X, scale);
    }
    m_bonusdamage = 0;

    int32 createResistance[MAX_SPELL_SCHOOL] = {0,0,0,0,0,0,0};

    if(cinfo && getPetType() != HUNTER_PET)
    {
        createResistance[SPELL_SCHOOL_HOLY]   = cinfo->resistance1;
        createResistance[SPELL_SCHOOL_FIRE]   = cinfo->resistance2;
        createResistance[SPELL_SCHOOL_NATURE] = cinfo->resistance3;
        createResistance[SPELL_SCHOOL_FROST]  = cinfo->resistance4;
        createResistance[SPELL_SCHOOL_SHADOW] = cinfo->resistance5;
        createResistance[SPELL_SCHOOL_ARCANE] = cinfo->resistance6;
    }

    switch(getPetType())
    {
        case SUMMON_PET:
        {
            if(owner->GetTypeId() == TYPEID_PLAYER)
            {
                switch(owner->getClass())
                {
                    case CLASS_WARLOCK:
                    {

                        //the damage bonus used for pets is either fire or shadow damage, whatever is higher
                        uint32 fire  = owner->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_FIRE);
                        uint32 shadow = owner->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_SHADOW);
                        uint32 val  = (fire > shadow) ? fire : shadow;

                        SetBonusDamage(int32 (val * 0.15f));
                        //bonusAP += val * 0.57;
                        break;
                    }
                    case CLASS_MAGE:
                    {
                                                            //40% damage bonus of mage's frost damage
                        float val = owner->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_FROST) * 0.4;
                        if(val < 0)
                            val = 0;
                        SetBonusDamage( int32(val));
                        break;
                    }
                    default:
                        break;
                }
            }

            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)) );
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)) );

            //SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, float(cinfo->attackpower));

            PetLevelInfo const* pInfo = objmgr.GetPetLevelInfo(creature_ID, petlevel);
            if(pInfo)                                       // exist in DB
            {
                SetCreateHealth(pInfo->health);
                SetCreateMana(pInfo->mana);

                if(pInfo->armor > 0)
                    SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(pInfo->armor));

                for(int stat = 0; stat < MAX_STATS; ++stat)
                {
                    SetCreateStat(Stats(stat), float(pInfo->stats[stat]));
                }
            }
            else                                            // not exist in DB, use some default fake data
            {
                sLog.outErrorDb("Summoned pet (Entry: %u) not have pet stats data in DB",cinfo->Entry);

                // remove elite bonuses included in DB values
                SetCreateHealth(uint32(((float(cinfo->maxhealth) / cinfo->maxlevel) / (1 + 2 * cinfo->rank)) * petlevel) );
                SetCreateMana(  uint32(((float(cinfo->maxmana)   / cinfo->maxlevel) / (1 + 2 * cinfo->rank)) * petlevel) );

                SetCreateStat(STAT_STRENGTH, 22);
                SetCreateStat(STAT_AGILITY, 22);
                SetCreateStat(STAT_STAMINA, 25);
                SetCreateStat(STAT_INTELLECT, 28);
                SetCreateStat(STAT_SPIRIT, 27);
            }
            break;
        }
        case HUNTER_PET:
        {
            SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(petlevel))/4));

            //these formula may not be correct; however, it is designed to be close to what it should be
            //this makes dps 0.5 of pets level
            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)) );
            //damage range is then petlevel / 2
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)) );
            //damage is increased afterwards as strength and pet scaling modify attack power

            //stored standard pet stats are entry 1 in pet_levelinfo
            PetLevelInfo const* pInfo = objmgr.GetPetLevelInfo(creature_ID, petlevel);
            if(pInfo)                                       // exist in DB
            {
                SetCreateHealth(pInfo->health);
                SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(pInfo->armor));
                //SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, float(cinfo->attackpower));

                for( int i = STAT_STRENGTH; i < MAX_STATS; i++)
                {
                    SetCreateStat(Stats(i),  float(pInfo->stats[i]));
                }
            }
            else                                            // not exist in DB, use some default fake data
            {
                sLog.outErrorDb("Hunter pet levelstats missing in DB");

                // remove elite bonuses included in DB values
                SetCreateHealth( uint32(((float(cinfo->maxhealth) / cinfo->maxlevel) / (1 + 2 * cinfo->rank)) * petlevel) );

                SetCreateStat(STAT_STRENGTH, 22);
                SetCreateStat(STAT_AGILITY, 22);
                SetCreateStat(STAT_STAMINA, 25);
                SetCreateStat(STAT_INTELLECT, 28);
                SetCreateStat(STAT_SPIRIT, 27);
            }
            break;
        }
        case GUARDIAN_PET:
            SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
            SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, 1000);

            switch(GetEntry())
            {
                case 1964: //force of nature
                    SetCreateHealth(30 + 30*petlevel);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 2.5f - (petlevel / 2)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 2.5f + (petlevel / 2)));
                    break;
                case 15352: //earth elemental 36213
                    SetCreateHealth(100 + 120*petlevel);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
                    break;
                case 15438: //fire elemental
                    SetCreateHealth(40*petlevel);
                    SetCreateMana(28 + 10*petlevel);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 4 - petlevel));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 4 + petlevel));
                    break;
                default:
            SetCreateMana(28 + 10*petlevel);
            SetCreateHealth(28 + 30*petlevel);

            // FIXME: this is wrong formula, possible each guardian pet have own damage formula
            //these formula may not be correct; however, it is designed to be close to what it should be
            //this makes dps 0.5 of pets level
            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
            //damage range is then petlevel / 2
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
                    break;
            }
            break;
        default:
            sLog.outError("Pet have incorrect type (%u) for levelup.", getPetType());
            break;
    }

    for (int i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
        SetModifierValue(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, float(createResistance[i]));

    UpdateAllStats();

    SetHealth(GetMaxHealth());
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

    return true;
}

bool Pet::HaveInDiet(ItemPrototype const* item) const
{
    if (!item->FoodType)
        return false;

    CreatureInfo const* cInfo = GetCreatureInfo();
    if(!cInfo)
        return false;

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cInfo->family);
    if(!cFamily)
        return false;

    uint32 diet = cFamily->petFoodMask;
    uint32 FoodMask = 1 << (item->FoodType-1);
    return diet & FoodMask;
}

uint32 Pet::GetCurrentFoodBenefitLevel(uint32 itemlevel)
{
    // -5 or greater food level
    if(getLevel() <= itemlevel + 5)                         //possible to feed level 60 pet with level 55 level food for full effect
        return 35000;
    // -10..-6
    else if(getLevel() <= itemlevel + 10)                   //pure guess, but sounds good
        return 17000;
    // -14..-11
    else if(getLevel() <= itemlevel + 14)                   //level 55 food gets green on 70, makes sense to me
        return 8000;
    // -15 or less
    else
        return 0;                                           //food too low level
}

void Pet::_LoadSpellCooldowns()
{
    m_CreatureSpellCooldowns.clear();
    m_CreatureCategoryCooldowns.clear();

    QueryResult *result = CharacterDatabase.PQuery("SELECT spell,time FROM pet_spell_cooldown WHERE guid = '%u'",m_charmInfo->GetPetNumber());

    if(result)
    {
        time_t curTime = time(NULL);

        WorldPacket data(SMSG_SPELL_COOLDOWN, (8+1+result->GetRowCount()*8));
        data << GetGUID();
        data << uint8(0x0);                                 // flags (0x1, 0x2)

        do
        {
            Field *fields = result->Fetch();

            uint32 spell_id = fields[0].GetUInt32();
            time_t db_time  = (time_t)fields[1].GetUInt64();

            if(!sSpellStore.LookupEntry(spell_id))
            {
                sLog.outError("Pet %u have unknown spell %u in `pet_spell_cooldown`, skipping.",m_charmInfo->GetPetNumber(),spell_id);
                continue;
            }

            // skip outdated cooldown
            if(db_time <= curTime)
                continue;

            data << uint32(spell_id);
            data << uint32(uint32(db_time-curTime)*1000);   // in m.secs

            _AddCreatureSpellCooldown(spell_id,db_time);

            sLog.outDebug("Pet (Number: %u) spell %u cooldown loaded (%u secs).", m_charmInfo->GetPetNumber(), spell_id, uint32(db_time-curTime));
        }
        while( result->NextRow() );

        delete result;

        if(!m_CreatureSpellCooldowns.empty() && GetOwner())
        {
            ((Player*)GetOwner())->GetSession()->SendPacket(&data);
        }
    }
}

void Pet::_SaveSpellCooldowns()
{
    CharacterDatabase.PExecute("DELETE FROM pet_spell_cooldown WHERE guid = '%u'", m_charmInfo->GetPetNumber());

    time_t curTime = time(NULL);

    // remove oudated and save active
    for(CreatureSpellCooldowns::iterator itr = m_CreatureSpellCooldowns.begin();itr != m_CreatureSpellCooldowns.end();)
    {
        if(itr->second <= curTime)
            m_CreatureSpellCooldowns.erase(itr++);
        else
        {
            CharacterDatabase.PExecute("INSERT INTO pet_spell_cooldown (guid,spell,time) VALUES ('%u', '%u', '" I64FMTD "')", m_charmInfo->GetPetNumber(), itr->first, uint64(itr->second));
            ++itr;
        }
    }
}

void Pet::_LoadSpells()
{
    QueryResult *result = CharacterDatabase.PQuery("SELECT spell,slot,active FROM pet_spell WHERE guid = '%u'",m_charmInfo->GetPetNumber());

    if(result)
    {
        do
        {
            Field *fields = result->Fetch();

            addSpell(fields[0].GetUInt16(), fields[2].GetUInt16(), PETSPELL_UNCHANGED, fields[1].GetUInt16());
        }
        while( result->NextRow() );

        delete result;
    }
}

void Pet::_SaveSpells()
{
    for (PetSpellMap::const_iterator itr = m_spells.begin(), next = m_spells.begin(); itr != m_spells.end(); itr = next)
    {
        ++next;
        if (itr->second->type == PETSPELL_FAMILY) continue; // prevent saving family passives to DB
        if (itr->second->state == PETSPELL_REMOVED || itr->second->state == PETSPELL_CHANGED)
            CharacterDatabase.PExecute("DELETE FROM pet_spell WHERE guid = '%u' and spell = '%u'", m_charmInfo->GetPetNumber(), itr->first);
        if (itr->second->state == PETSPELL_NEW || itr->second->state == PETSPELL_CHANGED)
            CharacterDatabase.PExecute("INSERT INTO pet_spell (guid,spell,slot,active) VALUES ('%u', '%u', '%u','%u')", m_charmInfo->GetPetNumber(), itr->first, itr->second->slotId,itr->second->active);

        if (itr->second->state == PETSPELL_REMOVED)
            _removeSpell(itr->first);
        else
            itr->second->state = PETSPELL_UNCHANGED;
    }
}

void Pet::_LoadAuras(uint32 timediff)
{
    m_Auras.clear();
    for (int i = 0; i < TOTAL_AURAS; i++)
        m_modAuras[i].clear();

    // all aura related fields
    for(int i = UNIT_FIELD_AURA; i <= UNIT_FIELD_AURASTATE; ++i)
        SetUInt32Value(i, 0);

    QueryResult *result = CharacterDatabase.PQuery("SELECT caster_guid,spell,effect_index,stackcount,amount,maxduration,remaintime,remaincharges FROM pet_aura WHERE guid = '%u'",m_charmInfo->GetPetNumber());

    if(result)
    {
        do
        {
            Field *fields = result->Fetch();
            uint64 caster_guid = fields[0].GetUInt64();
            uint32 spellid = fields[1].GetUInt32();
            uint32 effindex = fields[2].GetUInt32();
            uint32 stackcount= fields[3].GetUInt32();
            int32 damage     = (int32)fields[4].GetUInt32();
            int32 maxduration = (int32)fields[5].GetUInt32();
            int32 remaintime = (int32)fields[6].GetUInt32();
            int32 remaincharges = (int32)fields[7].GetUInt32();

            SpellEntry const* spellproto = sSpellStore.LookupEntry(spellid);
            if(!spellproto)
            {
                sLog.outError("Unknown aura (spellid %u, effindex %u), ignore.",spellid,effindex);
                continue;
            }

            if(effindex >= 3)
            {
                sLog.outError("Invalid effect index (spellid %u, effindex %u), ignore.",spellid,effindex);
                continue;
            }

            // negative effects should continue counting down after logout
            if (remaintime != -1 && !IsPositiveEffect(spellid, effindex))
            {
                if(remaintime  <= int32(timediff))
                    continue;

                remaintime -= timediff;
            }

            // prevent wrong values of remaincharges
            if(spellproto->procCharges)
            {
                if(remaincharges <= 0 || remaincharges > spellproto->procCharges)
                    remaincharges = spellproto->procCharges;
            }
            else
                remaincharges = -1;

            /// do not load single target auras (unless they were cast by the player)
            if (caster_guid != GetGUID() && IsSingleTargetSpell(spellproto))
                continue;

            for(uint32 i=0; i<stackcount; i++)
            {
                Aura* aura = CreateAura(spellproto, effindex, NULL, this, NULL);

                if(!damage)
                    damage = aura->GetModifier()->m_amount;
                aura->SetLoadedState(caster_guid,damage,maxduration,remaintime,remaincharges);
                AddAura(aura);
            }
        }
        while( result->NextRow() );

        delete result;
    }
}

void Pet::_SaveAuras()
{
    CharacterDatabase.PExecute("DELETE FROM pet_aura WHERE guid = '%u'", m_charmInfo->GetPetNumber());

    AuraMap const& auras = GetAuras();
    if (auras.empty())
        return;

    spellEffectPair lastEffectPair = auras.begin()->first;
    uint32 stackCounter = 1;

    for(AuraMap::const_iterator itr = auras.begin(); ; ++itr)
    {
        if(itr == auras.end() || lastEffectPair != itr->first)
        {
            AuraMap::const_iterator itr2 = itr;
            // save previous spellEffectPair to db
            itr2--;
            SpellEntry const *spellInfo = itr2->second->GetSpellProto();
            /// do not save single target auras (unless they were cast by the player)
            if (!(itr2->second->GetCasterGUID() != GetGUID() && IsSingleTargetSpell(spellInfo)))
            {
                if(!itr2->second->IsPassive())
                {
                    // skip all auras from spell that apply at cast SPELL_AURA_MOD_SHAPESHIFT or pet area auras.
                    uint8 i;
                    for (i = 0; i < 3; i++)
                        if (spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_STEALTH ||
                            spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AREA_AURA_OWNER ||
                            spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AREA_AURA_PET )
                            break;

                    if (i == 3)
                    {
                        CharacterDatabase.PExecute("INSERT INTO pet_aura (guid,caster_guid,spell,effect_index,stackcount,amount,maxduration,remaintime,remaincharges) "
                            "VALUES ('%u', '" I64FMTD "', '%u', '%u', '%u', '%d', '%d', '%d', '%d')",
                            m_charmInfo->GetPetNumber(), itr2->second->GetCasterGUID(),(uint32)itr2->second->GetId(), (uint32)itr2->second->GetEffIndex(), (uint32)itr2->second->GetStackAmount(), itr2->second->GetModifier()->m_amount,int(itr2->second->GetAuraMaxDuration()),int(itr2->second->GetAuraDuration()),int(itr2->second->m_procCharges));
                    }
                }
            }
            if(itr == auras.end())
                break;
        }

        if (lastEffectPair == itr->first)
            stackCounter++;
        else
        {
            lastEffectPair = itr->first;
            stackCounter = 1;
        }
    }
}

bool Pet::addSpell(uint16 spell_id, uint16 active, PetSpellState state, uint16 slot_id, PetSpellType type)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);
    if (!spellInfo)
    {
        // do pet spell book cleanup
        if(state == PETSPELL_UNCHANGED)                     // spell load case
        {
            sLog.outError("Pet::addSpell: Non-existed in SpellStore spell #%u request, deleting for all pets in `pet_spell`.",spell_id);
            CharacterDatabase.PExecute("DELETE FROM pet_spell WHERE spell = '%u'",spell_id);
        }
        else
            sLog.outError("Pet::addSpell: Non-existed in SpellStore spell #%u request.",spell_id);

        return false;
    }

    // same spells don't have autocast option
    if (spellInfo->AttributesEx & SPELL_ATTR_EX_UNAUTOCASTABLE_BY_PET)
        active = ACT_CAST;

    PetSpellMap::iterator itr = m_spells.find(spell_id);
    if (itr != m_spells.end())
    {
        if (itr->second->state == PETSPELL_REMOVED)
        {
            delete itr->second;
            m_spells.erase(itr);
            state = PETSPELL_CHANGED;
        }
        else if (state == PETSPELL_UNCHANGED && itr->second->state != PETSPELL_UNCHANGED)
        {
            // can be in case spell loading but learned at some previous spell loading
            itr->second->state = PETSPELL_UNCHANGED;
            return false;
        }
        else
            return false;
    }

    uint32 oldspell_id = 0;

    PetSpell *newspell = new PetSpell;
    newspell->state = state;
    newspell->type = type;

    if(active == ACT_DECIDE)                                //active was not used before, so we save it's autocast/passive state here
    {
        if(IsPassiveSpell(spell_id))
            newspell->active = ACT_PASSIVE;
        else
            newspell->active = ACT_DISABLED;
    }
    else
        newspell->active = active;

    uint32 chainstart = spellmgr.GetFirstSpellInChain(spell_id);

    for (PetSpellMap::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
    {
        if(itr->second->state == PETSPELL_REMOVED) continue;

        if(spellmgr.GetFirstSpellInChain(itr->first) == chainstart)
        {
            slot_id = itr->second->slotId;
            newspell->active = itr->second->active;

            if(newspell->active == ACT_ENABLED)
                ToggleAutocast(itr->first, false);

            oldspell_id = itr->first;
            removeSpell(itr->first);
        }
    }

    uint16 tmpslot=slot_id;

    if (tmpslot == 0xffff)
    {
        uint16 maxid = 0;
        PetSpellMap::iterator itr;
        for (itr = m_spells.begin(); itr != m_spells.end(); ++itr)
        {
            if(itr->second->state == PETSPELL_REMOVED) continue;
            if (itr->second->slotId > maxid) maxid = itr->second->slotId;
        }
        tmpslot = maxid + 1;
    }

    newspell->slotId = tmpslot;
    m_spells[spell_id] = newspell;

    if (IsPassiveSpell(spell_id))
        CastSpell(this, spell_id, true);
    else if(state == PETSPELL_NEW)
        m_charmInfo->AddSpellToAB(oldspell_id, spell_id, (ActiveStates)active);

    if(newspell->active == ACT_ENABLED)
        ToggleAutocast(spell_id, true);

    return true;
}

bool Pet::learnSpell(uint16 spell_id)
{
    // prevent duplicated entires in spell book
    if (!addSpell(spell_id))
        return false;

    Unit* owner = GetOwner();
    if(owner->GetTypeId()==TYPEID_PLAYER)
        ((Player*)owner)->PetSpellInitialize();
    return true;
}

void Pet::removeSpell(uint16 spell_id)
{
    PetSpellMap::iterator itr = m_spells.find(spell_id);
    if (itr == m_spells.end())
        return;

    if(itr->second->state == PETSPELL_REMOVED)
        return;

    if(itr->second->state == PETSPELL_NEW)
    {
        delete itr->second;
        m_spells.erase(itr);
    }
    else
        itr->second->state = PETSPELL_REMOVED;

    RemoveAurasDueToSpell(spell_id);
}

bool Pet::_removeSpell(uint16 spell_id)
{
    PetSpellMap::iterator itr = m_spells.find(spell_id);
    if (itr != m_spells.end())
    {
        delete itr->second;
        m_spells.erase(itr);
        return true;
    }
    return false;
}

void Pet::InitPetCreateSpells()
{
    m_charmInfo->InitPetActionBar();

    m_spells.clear();
    int32 usedtrainpoints = 0, petspellid;
    PetCreateSpellEntry const* CreateSpells = objmgr.GetPetCreateSpellEntry(GetEntry());
    if(CreateSpells)
    {
        for(uint8 i = 0; i < 4; i++)
        {
            if(!CreateSpells->spellid[i])
                break;

            SpellEntry const *learn_spellproto = sSpellStore.LookupEntry(CreateSpells->spellid[i]);
            if(!learn_spellproto)
                continue;

            if(learn_spellproto->Effect[0] == SPELL_EFFECT_LEARN_SPELL || learn_spellproto->Effect[0] == SPELL_EFFECT_LEARN_PET_SPELL)
            {
                petspellid = learn_spellproto->EffectTriggerSpell[0];
                Unit* owner = GetOwner();
                if(owner->GetTypeId() == TYPEID_PLAYER && !((Player*)owner)->HasSpell(learn_spellproto->Id))
                {
                    if(IsPassiveSpell(petspellid))          //learn passive skills when tamed, not sure if thats right
                        ((Player*)owner)->learnSpell(learn_spellproto->Id);
                    else
                        AddTeachSpell(learn_spellproto->EffectTriggerSpell[0], learn_spellproto->Id);
                }
            }
            else
                petspellid = learn_spellproto->Id;

            addSpell(petspellid);

            SkillLineAbilityMap::const_iterator lower = spellmgr.GetBeginSkillLineAbilityMap(learn_spellproto->EffectTriggerSpell[0]);
            SkillLineAbilityMap::const_iterator upper = spellmgr.GetEndSkillLineAbilityMap(learn_spellproto->EffectTriggerSpell[0]);

            for(SkillLineAbilityMap::const_iterator _spell_idx = lower; _spell_idx != upper; ++_spell_idx)
            {
                usedtrainpoints += _spell_idx->second->reqtrainpoints;
                break;
            }
        }
    }

    LearnPetPassives();

    CastPetAuras(false);

    SetTP(-usedtrainpoints);
}

void Pet::CheckLearning(uint32 spellid)
{
                                                            //charmed case -> prevent crash
    if(GetTypeId() == TYPEID_PLAYER || getPetType() != HUNTER_PET)
        return;

    Unit* owner = GetOwner();

    if(m_teachspells.empty() || !owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    TeachSpellMap::iterator itr = m_teachspells.find(spellid);
    if(itr == m_teachspells.end())
        return;

    if(urand(0, 100) < 10)
    {
        ((Player*)owner)->learnSpell(itr->second);
        m_teachspells.erase(itr);
    }
}

uint32 Pet::resetTalentsCost() const
{
    uint32 days = (sWorld.GetGameTime() - m_resetTalentsTime)/DAY;

    // The first time reset costs 10 silver; after 1 day cost is reset to 10 silver
    if(m_resetTalentsCost < 10*SILVER || days > 0)
        return 10*SILVER;
    // then 50 silver
    else if(m_resetTalentsCost < 50*SILVER)
        return 50*SILVER;
    // then 1 gold
    else if(m_resetTalentsCost < 1*GOLD)
        return 1*GOLD;
    // then increasing at a rate of 1 gold; cap 10 gold
    else
        return (m_resetTalentsCost + 1*GOLD > 10*GOLD ? 10*GOLD : m_resetTalentsCost + 1*GOLD);
}

void Pet::ToggleAutocast(uint32 spellid, bool apply)
{
    if(IsPassiveSpell(spellid))
        return;

    //if(const SpellEntry *tempSpell = GetSpellStore()->LookupEntry(spellid))
    //    if(tempSpell->EffectImplicitTargetA[0] != TARGET_SRC_CASTER
    //        && tempSpell->EffectImplicitTargetA[0] != TARGET_UNIT_TARGET_ENEMY)
    //        return;

    PetSpellMap::const_iterator itr = m_spells.find((uint16)spellid);

    int i;

    if(apply)
    {
        for (i = 0; i < m_autospells.size() && m_autospells[i] != spellid; i++);
        if (i == m_autospells.size())
        {
            m_autospells.push_back(spellid);
            itr->second->active = ACT_ENABLED;
            itr->second->state = PETSPELL_CHANGED;
        }
    }
    else
    {
        AutoSpellList::iterator itr2 = m_autospells.begin();
        for (i = 0; i < m_autospells.size() && m_autospells[i] != spellid; i++, itr2++);
        if (i < m_autospells.size())
        {
            m_autospells.erase(itr2);
            itr->second->active = ACT_DISABLED;
            itr->second->state = PETSPELL_CHANGED;
        }
    }
}

bool Pet::Create(uint32 guidlow, Map *map, uint32 Entry, uint32 pet_number)
{
    SetMapId(map->GetId());
    SetInstanceId(map->GetInstanceId());

    Object::_Create(guidlow, pet_number, HIGHGUID_PET);

    m_DBTableGuid = guidlow;
    m_originalEntry = Entry;

    if(!InitEntry(Entry))
        return false;

    SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE );
    SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY | UNIT_BYTE2_FLAG_AURAS | UNIT_BYTE2_FLAG_UNK5 );

    if(getPetType() == MINI_PET)                            // always non-attackable
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

    return true;
}

bool Pet::HasSpell(uint32 spell) const
{
    return (m_spells.find(spell) != m_spells.end());
}

// Get all passive spells in our skill line
void Pet::LearnPetPassives()
{
    CreatureInfo const* cInfo = GetCreatureInfo();
    if(!cInfo)
        return;

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cInfo->family);
    if(!cFamily)
        return;

    PetFamilySpellsStore::const_iterator petStore = sPetFamilySpellsStore.find(cFamily->ID);
    if(petStore != sPetFamilySpellsStore.end())
    {
        // For general hunter pets skill 270
        // Passive 01~10, Passive 00 (20782, not used), Ferocious Inspiration (34457)
        // Scale 01~03 (34902~34904, bonus from owner, not used)
        for(PetFamilySpellsSet::const_iterator petSet = petStore->second.begin(); petSet != petStore->second.end(); ++petSet)
            addSpell(*petSet, ACT_DECIDE, PETSPELL_NEW, 0xffff, PETSPELL_FAMILY);
    }
}

void Pet::CastPetAuras(bool current)
{
    Unit* owner = GetOwner();
    if(!owner)
        return;

    if(getPetType() != HUNTER_PET && (getPetType() != SUMMON_PET || owner->getClass() != CLASS_WARLOCK))
        return;

    for(PetAuraSet::iterator itr = owner->m_petAuras.begin(); itr != owner->m_petAuras.end();)
    {
        PetAura const* pa = *itr;
        ++itr;

        if(!current && pa->IsRemovedOnChangePet())
            owner->RemovePetAura(pa);
        else
            CastPetAura(pa);
    }
}

void Pet::CastPetAura(PetAura const* aura)
{
    uint16 auraId = aura->GetAura(GetEntry());
    if(!auraId)
        return;

    if(auraId == 35696)                                       // Demonic Knowledge
    {
        int32 basePoints = int32(aura->GetDamage() * (GetStat(STAT_STAMINA) + GetStat(STAT_INTELLECT)) / 100);
        CastCustomSpell(this, auraId, &basePoints, NULL, NULL, true);
    }
    else
        CastSpell(this, auraId, true);
}

