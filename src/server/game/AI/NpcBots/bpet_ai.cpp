#include "bpet_ai.h"
#include "bot_GridNotifiers.h"
#include "botmgr.h"
#include "Containers.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "PointMovementGenerator.h"
#include "SpellAuraEffects.h"
#include "Transport.h"
#include "World.h"
/*
NpcBot Pet System by Trickerer (https://github.com/trickerer/Trinity-Bots; onlysuffering@gmail.com)
*/

static constexpr uint32 SHAMAN_MAX_PET_POSITIONS = 2;
static constexpr uint32 DRUID_MAX_PET_POSITIONS = 3;
static constexpr uint32 DK_MAX_PET_POSITIONS = 10;
static constexpr uint32 DARK_RANGER_MAX_PET_POSITIONS = 5;
static constexpr uint32 NECROMANCER_MAX_PET_POSITIONS = 12;
static constexpr uint32 CRYPT_LORD_MAX_PET_POSITIONS = 6;
float constexpr ShamanPetPositionAnglesByPosNumber[SHAMAN_MAX_PET_POSITIONS] =
{
    0.f,//left
    float(M_PI)//right
};
float constexpr DruidPetPositionAnglesByPosNumber[DRUID_MAX_PET_POSITIONS] =
{
    0.f,//left
    float(M_PI)/2,//back
    float(M_PI)//right
};
float constexpr DKPetPositionAnglesByPosNumber[DK_MAX_PET_POSITIONS] =
{
    0.f,
    float(M_PI),
    0.3490658f,//1*M_PI/9
    0.6981317f,//2*M_PI/9
    1.0471975f,//3*M_PI/9
    1.3962634f,//4*M_PI/9
    1.7453292f,//5*M_PI/9
    2.0943951f,//6*M_PI/9
    2.4434609f,//7*M_PI/9
    2.7925268f //8*M_PI/9
};
float constexpr DarkRangerPetPositionAnglesByPosNumber[DARK_RANGER_MAX_PET_POSITIONS] =
{
    0.f,
    float(M_PI),
    0.7853981f,//1*M_PI/4
    1.5707963f,//2*M_PI/4
    2.3561944f //3*M_PI/4
};
float constexpr NecromancerPetPositionAnglesByPosNumber[NECROMANCER_MAX_PET_POSITIONS] =
{
    0.f,
    float(M_PI),
    float(1 *M_PI/11),
    float(2 *M_PI/11),
    float(3 *M_PI/11),
    float(4 *M_PI/11),
    float(5 *M_PI/11),
    float(6 *M_PI/11),
    float(7 *M_PI/11),
    float(8 *M_PI/11),
    float(9 *M_PI/11),
    float(10*M_PI/11)
};
float constexpr CryptLordPetPositionAnglesByPosNumber[CRYPT_LORD_MAX_PET_POSITIONS] =
{
    0.7853981f,//1*M_PI/4
    2.3561944f,//3*M_PI/4
    0.0f,
    float(M_PI),
    5.4977875f,//7*M_PI/4
    3.9269910f //5*M_PI/4
};

extern uint8 GroupIconsFlags[TARGET_ICONS_COUNT];

static uint16 __rand; //calculated for each bot separately once every updateAI tick

extern bool _botPvP;
extern uint8 _healTargetIconFlags;

bot_pet_ai::bot_pet_ai(Creature* creature) : CreatureAI(creature)
{
    m_botCommandState = BOT_COMMAND_FOLLOW;
    regenTimer = 0;
    waitTimer = 0;
    _moveBehindTimer = 0;
    indoorsTimer = 0;
    outdoorsTimer = 0;
    GC_Timer = 0;
    lastdiff = 0;
    _energyFraction = 0.f;
    _updateTimerMedium = 0;
    _updateTimerEx1 = urand(12000, 15000);
    checkAurasTimer = 0;

    _wanderer = false;

    _auraRaidUpdateMask = 0;

    myType = 0;
    petOwner = nullptr;
    canUpdate = true;
}
bot_pet_ai::~bot_pet_ai()
{
    while (!_spells.empty())
    {
        BotPetSpellMap::iterator itr = _spells.begin();
        delete itr->second;
        _spells.erase(itr);
    }
}

uint16 bot_pet_ai::Rand() const
{
    return __rand;
}
//0-178
void bot_pet_ai::GenerateRand() const
{
    __rand = urand(0, IAmFree() ? 100 : 100 + (petOwner->GetBotOwner()->GetNpcBotsCount() - 1) * 2);
}

bool bot_pet_ai::_checkImmunities(Unit const* target, SpellInfo const* spellInfo) const
{
    return target && spellInfo && !target->IsImmunedToDamage(spellInfo);
}
//Follow point calculation
void bot_pet_ai::_calculatePos(Position& pos) const
{
    switch (myType)
    {
        case BOT_PET_LOCUST_SWARM:
            pos.Relocate(me);
            return;
        default:
            break;
    }

    float x,y,z;
    //destination
    petOwner->GetPosition(x, y, z);
    //relative angle
    uint32 movFlags = petOwner->m_movementInfo.GetMovementFlags();
    float o = petOwner->GetOrientation() + PET_FOLLOW_ANGLE;
    uint8 posNum = petOwner->GetBotAI()->GetPetPositionNumber(me);
    if (petOwner->GetBotClass() == BOT_CLASS_DEATH_KNIGHT)
        o += DKPetPositionAnglesByPosNumber[posNum];
    else if (petOwner->GetBotClass() == BOT_CLASS_DRUID)
        o += DruidPetPositionAnglesByPosNumber[posNum];
    else if (petOwner->GetBotClass() == BOT_CLASS_SHAMAN)
        o += ShamanPetPositionAnglesByPosNumber[posNum];
    else if (petOwner->GetBotClass() == BOT_CLASS_DARK_RANGER)
        o += DarkRangerPetPositionAnglesByPosNumber[posNum];
    else if (petOwner->GetBotClass() == BOT_CLASS_NECROMANCER)
        o += NecromancerPetPositionAnglesByPosNumber[posNum];
    else if (petOwner->GetBotClass() == BOT_CLASS_CRYPT_LORD)
        o += CryptLordPetPositionAnglesByPosNumber[posNum];

    o = Position::NormalizeOrientation(o);
    //distance
    x += (PET_FOLLOW_DIST + me->GetCombatReach() + petOwner->GetCombatReach()) * std::cos(o);
    y += (PET_FOLLOW_DIST + me->GetCombatReach() + petOwner->GetCombatReach()) * std::sin(o);
    if (movFlags & MOVEMENTFLAG_FORWARD)
    {
        static float const aheadDist = 6.f;
        x = x + aheadDist * std::cos(petOwner->GetOrientation());
        y = y + aheadDist * std::sin(petOwner->GetOrientation());
    }
    if (!petOwner->GetTransport())
        me->UpdateGroundPositionZ(x, y, z);
    if (me->GetPositionZ() < z)
        z += 0.5f; //prevent going underground

    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;
}
void bot_pet_ai::SetBotCommandState(uint32 st, bool force, Position* newpos)
{
    if (!(st & (BOT_COMMAND_INACTION)))
    {
        if (!me->IsAlive() || JumpingOrFalling())
            return;
    }

    switch (myType)
    {
        case BOT_PET_LOCUST_SWARM:
            return;
        default:
            break;
    }

    if ((st & BOT_COMMAND_FOLLOW) && !IsChanneling() &&
        ((!me->isMoving() && !IsCasting() && petOwner->GetBotOwner()->IsAlive()) || force))
    {
        if (CCed(me, true)) return;
        if (me->isMoving() && Rand() > 10) return;

        float x,y,z;
        bool dest_valid = petOwner->GetMotionMaster()->GetDestination(x, y, z);
        float pdist = dest_valid ? me->GetDistance(x, y, z) : 0.0f;
        if (dest_valid && (pdist < 6.f || pdist > 20.f))
        {
            if (!me->HasUnitState(UNIT_STATE_FOLLOW))
                me->GetMotionMaster()->MoveFollow(petOwner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
        else
        {
            if (!newpos)
                _calculatePos(movepos);
            else
            {
                movepos.m_positionX = newpos->m_positionX;
                movepos.m_positionY = newpos->m_positionY;
                movepos.m_positionZ = newpos->m_positionZ;
            }

            float speed = 0.0f;
            if (!IAmFree() && !(petOwner->IsWalking() || HasBotCommandState(BOT_COMMAND_WALK)))
            {
                const float baserunspeed = petOwner->GetSpeed(MOVE_RUN);
                if (pdist > 50.0f)
                    speed = baserunspeed * 2.0f;
                else if (pdist > 30.0f)
                    speed = baserunspeed * 1.5f;
                else if (pdist > 10.0f)
                    speed = baserunspeed * 1.25f;
            }
            me->GetMotionMaster()->Add(new PointMovementGenerator<Creature>(1, movepos.m_positionX, movepos.m_positionY, movepos.m_positionZ, true, speed));
        }
        RemoveBotCommandState(BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ATTACK | BOT_COMMAND_COMBATRESET);
    }
    else if (st & BOT_COMMAND_INACTION)
    {
        uint32 removeMask = BOT_COMMAND_INACTION & GetBotCommandState();
        st &= ~removeMask;
        RemoveBotCommandState(removeMask | BOT_COMMAND_MASK_NOCAST_ANY | BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ATTACK);
        me->AttackStop();
        me->InterruptNonMeleeSpells(true);
    }
    else if (st & BOT_COMMAND_FULLSTOP)
    {
        RemoveBotCommandState(BOT_COMMAND_FOLLOW | BOT_COMMAND_STAY | BOT_COMMAND_ATTACK);
        me->AttackStop();
        me->InterruptNonMeleeSpells(true);
        if (me->isMoving())
            me->BotStopMovement();
    }
    else if (st & BOT_COMMAND_STAY)
    {
        RemoveBotCommandState(BOT_COMMAND_FOLLOW | BOT_COMMAND_FULLSTOP);
        if (me->isMoving())
            me->BotStopMovement();
    }
    else if (st & BOT_COMMAND_ATTACK)
    {
        RemoveBotCommandState(BOT_COMMAND_FOLLOW);
    }
    else if (st & BOT_COMMAND_COMBATRESET)
    {
        RemoveBotCommandState(BOT_COMMAND_ATTACK);
    }
    m_botCommandState |= st;
}

void bot_pet_ai::RemoveBotCommandState(uint32 st)
{
    m_botCommandState &= ~st;
}
// CURES
//cycle through the group sending members for cure
void bot_pet_ai::CureGroup(uint32 cureSpell, uint32 diff)
{
    if (!cureSpell) return;
    if (GC_Timer > diff) return;
    if (IsCasting()) return;

    if (IAmFree())
    {
        std::list<Unit*> cureTargets;

        if (_canCureTarget(me, cureSpell))
            cureTargets.push_back(me);
        if (_canCureTarget(petOwner, cureSpell))
            cureTargets.push_back(petOwner);

        if (!cureTargets.empty())
            me->CastSpell(Trinity::Containers::SelectRandomContainerElement(cureTargets), cureSpell, false);

        return;
    }

    if (!me->GetMap()->IsRaid() && Rand() > 35)
        return;

    std::list<Unit*> targets;
    Group const* pGroup = petOwner->GetBotOwner()->GetGroup();
    BotMap const* map;
    Unit* u;
    if (!pGroup)
    {
        if (_canCureTarget(petOwner->GetBotOwner(), cureSpell))
            targets.push_back(petOwner->GetBotOwner());

        map = petOwner->GetBotOwner()->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            u = itr->second;
            if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
            if (_canCureTarget(u, cureSpell))
                targets.push_back(u);
        }

        for (Unit::ControlList::const_iterator itr = petOwner->GetBotOwner()->m_Controlled.begin(); itr != petOwner->GetBotOwner()->m_Controlled.end(); ++itr)
        {
            u = *itr;
            if (!u || !u->IsPet() || !u->IsAlive() || me->GetDistance(u) > 30) continue;

            if (_canCureTarget(u, cureSpell))
                targets.push_back(u);
        }
    }
    else
    {
        bool Bots = false;
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (!tPlayer || (!tPlayer->IsAlive() && !tPlayer->HaveBot())) continue;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;
            if (!Bots && tPlayer->HaveBot())
                Bots = true;
            if (_canCureTarget(tPlayer, cureSpell))
                targets.push_back(tPlayer);
        }
        if (!Bots) return;
        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* tPlayer = itr->GetSource();
            if (tPlayer == nullptr) continue;
            if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
            if (me->GetMap() != tPlayer->FindMap()) continue;

            if (tPlayer->HaveBot())
            {
                map = tPlayer->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                {
                    u = bitr->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive()) continue;
                    if (_canCureTarget(u, cureSpell))
                        targets.push_back(u);
                }
            }

            for (Unit::ControlList::const_iterator citr = tPlayer->m_Controlled.begin(); citr != tPlayer->m_Controlled.end(); ++citr)
            {
                u = *citr;
                if (!u || !u->IsPet() || !u->IsAlive() || me->GetDistance(u) > 30) continue;

                if (_canCureTarget(u, cureSpell))
                    targets.push_back(u);
            }
        }
    }

    if (!targets.empty())
        me->CastSpell(Trinity::Containers::SelectRandomContainerElement(targets), cureSpell, false);
}

// determines if unit has something to cure
bool bot_pet_ai::_canCureTarget(Unit const* target, uint32 cureSpell) const
{
    if (me->GetLevel() < 10 || target->GetLevel() < 10) return false;
    if (target->HasUnitState(UNIT_STATE_ISOLATED)) return false;
    if (target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->IsTempBot()) return false;

    SpellInfo const* info = sSpellMgr->GetSpellInfo(cureSpell);
    if (!info)
        return false;

    if (me->GetDistance(target) > CalcSpellMaxRange(cureSpell, false))
        return false;

    uint32 dispelMask = 0;
    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
        if (info->_effects[i].Effect == SPELL_EFFECT_DISPEL)
            dispelMask |= SpellInfo::GetDispelMask(DispelType(info->_effects[i].MiscValue));

    if (dispelMask == 0)
        return false;

    std::list<Aura const*> dispel_list;
    _getBotDispellableAuraList(target, me, dispelMask, dispel_list);

    return !(dispel_list.empty());
}

void bot_pet_ai::_getBotDispellableAuraList(Unit const* target, Unit const* caster, uint32 dispelMask, std::list<Aura const*> &dispelList) const
{
    //Unholy Blight prevents diseases from being dispelled
    if ((dispelMask & (1<<DISPEL_DISEASE)) &&
        target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 1494, 0))
        dispelMask &= ~(1<<DISPEL_DISEASE);

    Unit::AuraMap const& auras = target->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura const* aura = itr->second;

        if (aura->IsPassive())
            continue;

        AuraApplication const* aurApp = aura->GetApplicationOfTarget(target->GetGUID());
        if (!aurApp)
            continue;

        if (aura->GetSpellInfo()->GetDispelMask() & dispelMask)
        {
            //do not dispel positive auras from enemies and negative ones from friends
            if (aurApp->IsPositive() == target->IsFriendlyTo(caster))
                continue;

            //skip Vampiric Touch to prevent being CCed just heal it out
            if (aura->GetSpellInfo()->IsRankOf(sSpellMgr->GetSpellInfo(34914)))
                continue;

            if (((aura->GetSpellInfo()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES) ? aura->GetCharges() : aura->GetStackAmount()) > 0)
                dispelList.push_back(aura);
        }
    }
}

uint32 bot_pet_ai::GetData(uint32 data) const
{
    switch (data)
    {
        case BOTPETAI_MISC_DURATION:
            return 0;
        case BOTPETAI_MISC_DURATION_MAX:
            return 0;
        case BOTPETAI_MISC_MAXLEVEL:
            return petOwner->GetLevel();
        case BOTPETAI_MISC_FIXEDLEVEL:
            return 0;
        case BOTPETAI_MISC_CARRY:
            return 0;
        case BOTPETAI_MISC_CAPACITY:
            return 0;
        case BOTPETAI_MISC_MAX_ATTACKERS:
            return 0;
        default:
            TC_LOG_DEBUG("entities.unit", "bot_pet_ai::GetData(): unk data type {}!", data);
            return 0;
    }
}

void bot_pet_ai::SetPetStats(bool force)
{
    switch (myType)
    {
        //warlock
        case BOT_PET_IMP:
        case BOT_PET_VOIDWALKER:
        case BOT_PET_SUCCUBUS:
        case BOT_PET_FELHUNTER:
        case BOT_PET_FELGUARD:
        //hunter
        //cunning
        case BOT_PET_SPIDER:
        case BOT_PET_SERPENT:
        case BOT_PET_BIRDOFPREY:
        case BOT_PET_BAT:
        case BOT_PET_WINDSERPENT:
        case BOT_PET_RAVAGER:
        case BOT_PET_DRAGONHAWK:
        case BOT_PET_NETHERRAY:
        case BOT_PET_SPOREBAT:
        //ferocity
        case BOT_PET_CARRIONBIRD:
        case BOT_PET_RAPTOR:
        case BOT_PET_WOLF:
        case BOT_PET_TALLSTRIDER:
        case BOT_PET_CAT:
        case BOT_PET_HYENA:
        case BOT_PET_WASP:
        case BOT_PET_TEROMOTH:
        //tenacity
        case BOT_PET_SCORPID:
        case BOT_PET_TURTLE:
        case BOT_PET_GORILLA:
        case BOT_PET_BEAR:
        case BOT_PET_BOAR:
        case BOT_PET_CRAB:
        case BOT_PET_CROCOLISK:
        case BOT_PET_WARPSTALKER:
        //cunning (exotic)
        case BOT_PET_SILITHID:
        case BOT_PET_CHIMAERA:
        //ferocity (exotic)
        case BOT_PET_SPIRITBEAST:
        case BOT_PET_COREHOUND:
        case BOT_PET_DEVILSAUR:
        //tenacity (exotic)
        case BOT_PET_RHINO:
        case BOT_PET_WORM:
        //death knight
        case BOT_PET_GHOUL:
        //case BOT_PET_GARGOYLE:
        //case BOT_PET_DANCING_RUNE_WEAPON:
        //case BOT_PET_AOD_GHOUL:
        //priest
        case BOT_PET_SHADOWFIEND:
        //shaman
        case BOT_PET_SPIRIT_WOLF:
        //mage
        case BOT_PET_WATER_ELEMENTAL:
        //druid
        case BOT_PET_FORCE_OF_NATURE:
        //archmage
        case BOT_PET_AWATER_ELEMENTAL:
        //dreadlord
        case BOT_PET_INFERNAL:
        //dark ranger
        case BOT_PET_DARK_MINION:
        case BOT_PET_DARK_MINION_ELITE:
        //necromancer
        case BOT_PET_NECROSKELETON:
        //sea witch
        case BOT_PET_TORNADO:
        //crypt lord
        case BOT_PET_CARRION_BEETLE1:
        case BOT_PET_CARRION_BEETLE2:
        case BOT_PET_CARRION_BEETLE3:
        case BOT_PET_LOCUST_SWARM:
            break;
        default:
            TC_LOG_ERROR("entities.player", "bot_pet_ai::SetPetStats(): unk pet type {}, aborting", myType);
            return;
    }

    //some time limited summons can only init stats and never change them
    switch (myType)
    {
        case BOT_PET_SHADOWFIEND:
        case BOT_PET_SPIRIT_WOLF:
        //case BOT_PET_WATER_ELEMENTAL:
        case BOT_PET_FORCE_OF_NATURE:
        case BOT_PET_DARK_MINION:
        case BOT_PET_DARK_MINION_ELITE:
        case BOT_PET_NECROSKELETON:
        case BOT_PET_TORNADO:
        case BOT_PET_CARRION_BEETLE1:
        case BOT_PET_CARRION_BEETLE2:
        case BOT_PET_CARRION_BEETLE3:
        case BOT_PET_LOCUST_SWARM:
            if (force == false)
                return;
            break;
        default:
            break;
    }

    uint8 level = GetData(BOTPETAI_MISC_FIXEDLEVEL);
    level = level ? level : std::min<uint8>(petOwner->GetLevel(), GetData(BOTPETAI_MISC_MAXLEVEL));
    if (level != me->GetLevel())
    {
        me->SetLevel(level);
        force = true;
    }

    int32 spdtotal;
    switch (petOwner->GetBotClass())
    {
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_DRUID:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_SEA_WITCH:
            spdtotal = petOwner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC);
            break;
        default:
            spdtotal = 0;
            break;
    }

    if (force)
    {
        InitPetSpells();
        ApplyPetPassives();

        me->RemoveAurasDueToSpell(DAMAGEDONE_PASSIVE);
        me->RemoveAurasDueToSpell(DAMAGETAKEN_PASSIVE);
        me->RemoveAurasDueToSpell(SPELLDAMAGE_PASSIVE);
        me->RemoveAurasDueToSpell(SPELLPENETRATION_PASSIVE);
        me->RemoveAurasDueToSpell(SPELLHASTE_PASSIVE);
        me->RemoveAurasDueToSpell(CRITBONUS_PASSIVE);

        me->CastSpell(me, DAMAGEDONE_PASSIVE, true);
        me->CastSpell(me, DAMAGETAKEN_PASSIVE, true);
        me->CastSpell(me, SPELLDAMAGE_PASSIVE, true);
        me->CastSpell(me, SPELLPENETRATION_PASSIVE, true);
        me->CastSpell(me, SPELLHASTE_PASSIVE, true);
        me->CastSpell(me, CRITBONUS_PASSIVE, true);
    }

    //base stats
    uint32 myarmor = 0;
    if (force)
    {
        uint32 origEntry = bot_ai::GetPetOriginalEntry(myType);
        CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(origEntry);
        ASSERT(cinfo);

        me->SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));

        PetLevelInfo const* pInfo = sObjectMgr->GetPetLevelInfo(origEntry, level);
        if (pInfo)
        {
            me->SetCreateHealth(pInfo->health);
            if (petOwner->GetBotClass() == BOT_CLASS_HUNTER) //hunter pet use focus
            {
                //prevent from modifying powers inside
                if (me->GetPowerType() != POWER_FOCUS)
                {
                    me->SetMaxPower(POWER_FOCUS, 100);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_FOCUS);
                }
            }
            else if (myType == BOT_PET_GHOUL)
            {
                if (me->GetPowerType() != POWER_ENERGY)
                {
                    me->SetMaxPower(POWER_ENERGY, 100);
                    me->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_ENERGY);
                }
            }
            else if (myType == BOT_PET_SHADOWFIEND)
            {
                me->SetCreateHealth(28 + 30*level);
                me->SetCreateMana(28 + 10*level);
                me->SetPowerType(POWER_MANA);
            }
            else if (myType == BOT_PET_SPIRIT_WOLF)
            {
                me->SetCreateHealth(30*level);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_FORCE_OF_NATURE)
            {
                me->SetCreateHealth(30*(level+1));
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_DARK_MINION)
            {
                me->SetCreateHealth(pInfo->health / 4);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_DARK_MINION_ELITE)
            {
                me->SetCreateHealth(pInfo->health / 2);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_NECROSKELETON)
            {
                me->SetCreateHealth(pInfo->health / 5);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_AWATER_ELEMENTAL || myType == BOT_PET_INFERNAL)
            {
                //custom pets / not using mana
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_CARRION_BEETLE1)
            {
                me->SetCreateHealth(pInfo->health / 4);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_CARRION_BEETLE2)
            {
                me->SetCreateHealth(pInfo->health / 4);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else if (myType == BOT_PET_CARRION_BEETLE3)
            {
                me->SetCreateHealth(pInfo->health / 3);
                me->SetByteValue(UNIT_FIELD_BYTES_0, 3, MAX_POWERS);
            }
            else
            {
                me->SetCreateMana(pInfo->mana);
                me->SetPowerType(POWER_MANA);
            }

            if (pInfo->armor > 0)
                myarmor = pInfo->armor;

            for (uint8 i = STAT_STRENGTH; i != MAX_STATS; ++i)
                me->SetCreateStat(Stats(i), pInfo->stats[i]);
        }
        else
        {
            CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, me->GetCreatureTemplate()->unit_class);
            me->SetCreateHealth(stats->BaseHealth[cinfo->expansion]);
            me->SetCreateMana(stats->BaseMana);

            me->SetCreateStat(STAT_STRENGTH, level * 3 + 20);
            me->SetCreateStat(STAT_AGILITY, level * 2 + 20);
            me->SetCreateStat(STAT_STAMINA, level * 5 + 20);
            me->SetCreateStat(STAT_INTELLECT, level * 2 + 25);
            me->SetCreateStat(STAT_SPIRIT,  level * 2 + 30);
            TC_LOG_ERROR("entities.unit", "SetPetStats(): pInfo is NULL, setting default stats for pet {}", myType);
        }
    }

    //STAT INHERITANCE
    //STAT -- 'mod' -- description
    // WARLOCK
    //AP      x0.57 -- attack power from spd
    //Armor   x0.35 -- armor
    //Resist  x0.4  -- resistances
    //Stamina x0.75 -- stamina
    //Int     x0.3  -- int
    //Spd     x0.15 -- spd
    //Sppen   x1.00 -- sppenetration
    // HUNTER
    //AP      x0.22 -- attack power/spd from ranged AP (0.338 wild hunt)
    //Stamina x0.4  -- health (0.63 wild hunt)
    //Spd   x0.1287 -- spd from ranged AP (0.18 wild hunt)
    //rest is same as warlock
    // DK
    //AP      x1.52 -- attack power from master's strength
    //Stamina x0.88 -- health
    //rest is same as warlock
    // PRIEST
    //Damage from spd
    // SHAMAN
    //AP      x0.6  -- attack power glyphed
    //Stamina x0.75 -- health
    // MAGE
    //Stamina x0.75 -- health
    //Spd     x0.40 -- spd
    //Int     x0.3  -- int
    // DRUID
    //Stamina x0.45 -- health
    //
    // SHAMAN
    //
    // ARCHMAGE
    //Stamina x2.5  -- stamina
    //Spd     x1.0  -- spd
    //rest is same as warlock
    // DREADLORD
    //AP      x1.00 -- attack power from spd
    //Resist  x2.0  -- resistances
    //Stamina x2.5  -- stamina
    //Spd     x1.0  -- spd
    // DARK RANGER
    //AP      x0.50 -- attack power
    //Resist  x0.3  -- resistances
    //Stamina x0.8  -- stamina
    //rest is same as warlock
    // NECROMANCER
    //AP      x0.40 -- attack power
    //Resist  x0.25 -- resistances
    //Stamina x0.8  -- stamina
    //rest is same as warlock
    // SEA WITCH
    //Spd     x1.0  -- spd
    //rest is same as warlock
    // CRYPT LORD
    //AP      x0.40 -- attack power
    //Resist  x1.0  -- resistances
    //Stamina x1.5  -- stamina
    //Spd     x1.0  -- spd

    //attack power
    if (force)
    {
        if (myType == BOT_PET_SHADOWFIEND)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level * 3 + spdtotal * 0.3f));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level * 5 + spdtotal * 0.3f));
        }
        else if (myType == BOT_PET_SPIRIT_WOLF)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level * 3));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level * 5));
        }
        else if (myType == BOT_PET_FORCE_OF_NATURE)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level * 2) + spdtotal * 0.15f);
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level * 3) + spdtotal * 0.15f);
        }
        else if (myType == BOT_PET_DARK_MINION)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level + level / 2));
        }
        else if (myType == BOT_PET_DARK_MINION_ELITE)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level * 3));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level * 4));
        }
        else if (myType == BOT_PET_NECROSKELETON)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level + level / 3));
        }
        else if (myType == BOT_PET_CARRION_BEETLE1)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level / 2 + 2));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level / 4 * 3 + 2));
        }
        else if (myType == BOT_PET_CARRION_BEETLE2)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level / 4 * 3 + 8));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level + level / 2 + 8));
        }
        else if (myType == BOT_PET_CARRION_BEETLE3)
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level + level / 2 + 10));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level + level / 4 * 3 + 15));
        }
        else
        {
            me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(level - (level / 4)));
            me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(level + (level / 4)));
        }
    }
    float atpower = /*IAmFree() ? 1000.f :*/ 0.f; //+1000/+0 base pet ap
    switch (myType)
    {
        case BOT_PET_IMP:
            atpower += me->GetTotalStatValue(STAT_STRENGTH) - 10.0f;
            break;
        case BOT_PET_GHOUL:
            atpower += me->GetTotalStatValue(STAT_STRENGTH) - 10.0f;
            atpower += 1.52f * petOwner->GetTotalStatValue(STAT_STRENGTH);
            atpower += 0.3f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            atpower += level * 8;
            break;
        case BOT_PET_DARK_MINION:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 20.0f;
            atpower += 0.3f * petOwner->GetTotalAttackPowerValue(RANGED_ATTACK);
            break;
        case BOT_PET_DARK_MINION_ELITE:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 20.0f;
            atpower += 0.4f * petOwner->GetTotalAttackPowerValue(RANGED_ATTACK);
            break;
        case BOT_PET_NECROSKELETON:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 20.0f;
            break;
        case BOT_PET_CARRION_BEETLE1:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 20.0f;
            atpower += 0.15f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            break;
        case BOT_PET_CARRION_BEETLE2:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 15.0f;
            atpower += 0.20f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            break;
        case BOT_PET_CARRION_BEETLE3:
            atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 10.0f;
            atpower += 0.25f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            break;
        default:
            //atpower += 2 * me->GetTotalStatValue(STAT_STRENGTH) - 20.0f;
            break;
    }
    switch (petOwner->GetBotClass())
    {
        case BOT_CLASS_HUNTER:
            atpower += (level >= 80 ? 0.338f : 0.22f) * petOwner->GetTotalAttackPowerValue(RANGED_ATTACK);
            //Hunter vs. Wild
            if (level >= 30 && Spec() == BOT_SPEC_HUNTER_SURVIVAL)
                atpower += 0.3f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            //Animal Handler
            if (level >= 35 && Spec() == BOT_SPEC_HUNTER_BEASTMASTERY)
                atpower *= 1.1f;
            break;
        case BOT_CLASS_SHAMAN:
            //Glyph of Feral Spirit
            atpower += 0.6f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            break;
        case BOT_CLASS_DRUID:
            atpower += 300 + 0.3f * petOwner->GetTotalAttackPowerValue(BASE_ATTACK);
            break;
        case BOT_CLASS_WARLOCK:
            atpower += 0.57f * spdtotal;
            //TC_LOG_ERROR("entities.player", "SetPetStat(): atpower += 0.57 of {} = {}2f", spdtotal, atpower);
            break;
        case BOT_CLASS_DREADLORD:
            atpower += spdtotal * 6;
            break;
        case BOT_CLASS_NECROMANCER:
            atpower += 0.75f * spdtotal;
            break;
        default:
            break;
    }
    me->SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, atpower);
    me->UpdateAttackPowerAndDamage();
    //armor
    myarmor = std::max<uint32>(myarmor, level*50);
    myarmor += me->GetStat(STAT_AGILITY)*2 + petOwner->GetArmor()*0.35f;
    //armor bonuses
    if (petOwner->GetBotClass() == BOT_CLASS_HUNTER)
    {
        //5% innate
        myarmor += myarmor / 20;
        //Thick Hide
        if (level >= 15)
            myarmor += myarmor / 5;
        //Natural Armor
        if (level >= 20)
            myarmor += myarmor / 10;
        //Pet Barding
        if (level >= 32)
            myarmor += myarmor / 10;
    }
    if (petOwner->GetBotClass() == BOT_CLASS_DARK_RANGER || petOwner->GetBotClass() == BOT_CLASS_NECROMANCER)
    {
        //even though skeletons have shields their armor needs to be very low
        myarmor = myarmor / 4;
    }
    else if (petOwner->GetBotClass() == BOT_CLASS_CRYPT_LORD)
    {
        myarmor /= 3;
    }
    me->SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, float(myarmor));
    me->UpdateArmor();
    //resistances
    for (uint8 i = SPELL_SCHOOL_HOLY; i != MAX_SPELL_SCHOOL; ++i)
    {
        float petResist;
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_DREADLORD:
                petResist = (petOwner->GetBotAI()->GetBotResistanceBonus(SpellSchools(i)) + petOwner->GetResistance(SpellSchools(i)))*2.0f;
                break;
            case BOT_CLASS_DARK_RANGER:
            case BOT_CLASS_NECROMANCER:
                petResist = (petOwner->GetBotAI()->GetBotResistanceBonus(SpellSchools(i)) + petOwner->GetResistance(SpellSchools(i)))*0.3f;
                break;
            case BOT_CLASS_CRYPT_LORD:
                petResist = (petOwner->GetBotAI()->GetBotResistanceBonus(SpellSchools(i)) + petOwner->GetResistance(SpellSchools(i)))*1.0f;
                break;
            default:
                petResist = (petOwner->GetBotAI()->GetBotResistanceBonus(SpellSchools(i)) + petOwner->GetResistance(SpellSchools(i)))*0.4f;
                break;
        }
        me->SetStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, petResist);
        me->UpdateResistances(i);
    }
    //crit physical
    if (AuraEffect* critbonus = me->GetAuraEffect(CRITBONUS_PASSIVE, 1, me->GetGUID()))
    {
        int32 amount = 5; //base crit
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                //Demonic Tactics part 1 (pet)
                amount += level >= 45 ? 10 : 0;
                //Improved Demonic Tactics (pshysical)
                amount += level >= 50 ? petOwner->GetCreatureCritChance() * 0.3f : 0;
                break;
            case BOT_CLASS_HUNTER:
                //Ferocity
                if (level >= 20)
                    amount += 10;
                //Spider's Bite
                if (level >= 44)
                    amount += 9;
                break;
            case BOT_CLASS_DREADLORD:
                amount += petOwner->GetCreatureCritChance() * 0.5f;
                break;
            case BOT_CLASS_DARK_RANGER:
            case BOT_CLASS_NECROMANCER:
            case BOT_CLASS_CRYPT_LORD:
                amount += petOwner->GetCreatureCritChance() * 0.35f;
                break;
            default:
                break;
        }
        critbonus->ChangeAmount(amount);
    }
    //crit spell
    if (AuraEffect* critbonus = me->GetAuraEffect(CRITBONUS_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = 5; //base crit
        switch (myType)
        {
            case BOT_PET_IMP:
            case BOT_PET_SUCCUBUS:
                //Master Demonologist part 1.2 (pet)
                //Master Demonologist part 3.2 (pet)
                amount += level >= 35 ? 5 : 0;
                //Improved Demonic Tactics (pshysical)
                amount += level >= 50 ? petOwner->GetCreatureCritChance() * 0.3f : 0;
                break;
            default:
                break;
        }
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                //Demonic Tactics part 2 (pet)
                amount += level >= 45 ? 10 : 0;
                break;
            case BOT_CLASS_HUNTER:
                //Ferocity
                if (level >= 20)
                    amount += 10;
                //Spider's Bite
                if (level >= 44)
                    amount += 9;
                break;
            case BOT_CLASS_ARCHMAGE:
            case BOT_CLASS_SEA_WITCH:
                amount += petOwner->GetCreatureCritChance();
                break;
            default:
                break;
        }
        critbonus->ChangeAmount(amount);
    }
    //damage done physical
    if (AuraEffect* physdam = me->GetAuraEffect(DAMAGEDONE_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = 0;
        switch (myType)
        {
            case BOT_PET_IMP:
                //Empowered Imp part 1
                amount += level >= 50 ? 30 : 0;
                break;
            case BOT_PET_INFERNAL:
                amount += 100;
                break;
            default:
                break;
        }
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                //Unholy Power
                if (myType != BOT_PET_IMP)
                    amount += level >= 30 ? 20 : 0;
                break;
            case BOT_CLASS_HUNTER:
                //Hapiness bonus (always happy) + 5% innate
                amount += 30;
                //Unleashed Fury
                if (level >= 20)
                    amount += 15;
                //Kindred Spirits
                if (level >= 55 && Spec() == BOT_SPEC_HUNTER_BEASTMASTERY)
                    amount += 20;
                //Spiked Collar
                if (level >= 32)
                    amount += 9;
                //Shark Attack
                if (level >= 80)
                    amount += 6;
                break;
            default:
                break;
        }
        //Command (Racial)
        if (petOwner->GetRace() == RACE_ORC)
            amount += 5;
        physdam->ChangeAmount(amount);
    }
    //damage done magic
    if (AuraEffect* spelldam = me->GetAuraEffect(DAMAGEDONE_PASSIVE, 1, me->GetGUID()))
    {
        int32 amount = 0;
        switch (myType)
        {
            case BOT_PET_IMP:
                //Empowered Imp part 1, Master Demonologist part 1.2 (pet), Improved Imp part 1
                amount += level >= 50 ? 65 : level >= 35 ? 35 : level >= 10 ? 30 : 0;
                break;
            case BOT_PET_SUCCUBUS:
                //Master Demonologist part 3 (pet)
                amount += level >= 35 ? 5 : 0;
                break;
            default:
                break;
        }
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_WARLOCK:
                //Unholy Power
                if (myType == BOT_PET_IMP)
                    amount += level >= 30 ? 20 : 0;
                break;
            case BOT_CLASS_HUNTER:
                //Hapiness bonus (always happy) + 5% innate
                amount += 30;
                //Unleashed Fury
                if (level >= 20)
                    amount += 15;
                //Kindred Spirits
                if (level >= 55 && Spec() == BOT_SPEC_HUNTER_BEASTMASTERY)
                    amount += 20;
                //Spiked Collar
                if (level >= 32)
                    amount += 9;
                //Shark Attack
                if (level >= 80)
                    amount += 6;
                break;
            default:
                break;
        }
        //Command (Racial)
        if (petOwner->GetRace() == RACE_ORC)
            amount += 5;
        spelldam->ChangeAmount(amount);
    }
    //spell power
    if (AuraEffect* spelldam = me->GetAuraEffect(SPELLDAMAGE_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = 0;
        switch (petOwner->GetBotClass())
        {
            case BOT_CLASS_HUNTER:
                amount += int32(petOwner->GetTotalAttackPowerValue(RANGED_ATTACK) * (level >= 80 ? 0.18f : 0.1287f));
                break;
            case BOT_CLASS_WARLOCK:
                amount += int32(spdtotal * 0.15f);
                break;
            case BOT_CLASS_MAGE:
                amount += int32(spdtotal * 0.4f);
                break;
            case BOT_CLASS_ARCHMAGE:
                amount += int32(spdtotal * 1.0f);
                break;
            case BOT_CLASS_DREADLORD:
                amount += int32(spdtotal * 1.0f);
                break;
            case BOT_CLASS_SEA_WITCH:
                amount += int32(spdtotal * 1.0f);
                break;
            default:
                break;
        }
        spelldam->ChangeAmount(amount);
    }
    //spell penetration
    if (AuraEffect* spellpenet = me->GetAuraEffect(SPELLPENETRATION_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = int32(petOwner->GetCreatureSpellPenetration());
        spellpenet->ChangeAmount(amount);
    }
    //haste spell
    if (AuraEffect* spellhaste = me->GetAuraEffect(SPELLHASTE_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = 0;
        switch (myType)
        {
            case BOT_PET_IMP:
                //Demonic Power part 2
                amount += level >= 20 ? 25 : 0;
                break;
            case BOT_PET_SUCCUBUS:
                //Improved Succubus part 1
                amount += level >= 20 ? 200 : 0;
                break;
            case BOT_PET_AWATER_ELEMENTAL:
                amount += petOwner->GetBotAI()->GetHaste();
                break;
            default:
                break;
        }
        spellhaste->ChangeAmount(amount);
    }
    //dmgtaken
    if (AuraEffect* dmgtaken = me->GetAuraEffect(DAMAGETAKEN_PASSIVE, 0, me->GetGUID()))
    {
        int32 amount = 0;

        if (petOwner->GetBotClass() == BOT_CLASS_WARLOCK)
        {
            //Demonic Resilience part 2
            if (level >= 40)
                amount += 15;
        }
        if (petOwner->GetBotClass() == BOT_CLASS_HUNTER)
        {
            //Great Resistance (everything)
            if (level >= 44)
                amount += 15;
        }
        if (petOwner->GetBotClass() == BOT_CLASS_DREADLORD)
        {
            amount += 25;
        }
        if (petOwner->GetBotClass() == BOT_CLASS_CRYPT_LORD)
        {
            switch (myType)
            {
                case BOT_PET_CARRION_BEETLE1:
                    amount += 10;
                    break;
                case BOT_PET_CARRION_BEETLE2:
                    amount += 15;
                    break;
                case BOT_PET_CARRION_BEETLE3:
                    amount += 20;
                    break;
                default:
                    break;
            }
        }

        dmgtaken->ChangeAmount(amount);
    }
    //hp
    float stamValue = me->GetTotalStatValue(STAT_STAMINA) - me->GetCreateStat(STAT_STAMINA);
    switch (petOwner->GetBotClass())
    {
        case BOT_CLASS_HUNTER:
            stamValue += (level >= 80 ? 0.63f : 0.4f) * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_WARLOCK:
            stamValue += 0.75f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_DEATH_KNIGHT:
            switch (myType)
            {
                case BOT_PET_GHOUL:
                    stamValue += 0.88f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
                default:
                    stamValue += 0.3f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
            }
            break;
        case BOT_CLASS_SHAMAN:
            stamValue += 0.75f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_MAGE:
            stamValue += 0.75f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_DRUID:
            stamValue += 0.45f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_ARCHMAGE:
            stamValue += 2.50f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_DREADLORD:
            stamValue += 2.50f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_DARK_RANGER:
            switch (myType)
            {
                case BOT_PET_DARK_MINION_ELITE:
                    stamValue += 1.0f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
                default:
                    stamValue += 0.8f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
            }
            break;
        case BOT_CLASS_NECROMANCER:
            stamValue += 0.75f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
            break;
        case BOT_CLASS_CRYPT_LORD:
            switch (myType)
            {
                case BOT_PET_CARRION_BEETLE1:
                    stamValue += 0.25f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
                case BOT_PET_CARRION_BEETLE2:
                    stamValue += 0.40f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
                case BOT_PET_CARRION_BEETLE3:
                    stamValue += 0.70f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_STAMINA);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    float stamMult;
    switch (myType)
    {
        case BOT_PET_IMP:        stamMult = 8.4f;  break;
        case BOT_PET_VOIDWALKER: stamMult = 11.0f; break;
        case BOT_PET_SUCCUBUS:   stamMult = 9.1f;  break;
        case BOT_PET_FELHUNTER:  stamMult = 9.5f;  break;
        case BOT_PET_FELGUARD:   stamMult = 11.0f; break;
        default:                 stamMult = 10.f;  break;
    }
    //stam bonuses
    if (petOwner->GetBotClass() == BOT_CLASS_WARLOCK)
    {
        //Fel Vitality (pet) part 1
        if (level >= 15)
            stamValue *= 1.15f;
        //Glyph of Voidwalker
        if (myType == BOT_PET_VOIDWALKER && level >= 15)
            stamValue *= 1.2f;
    }
    if (petOwner->GetBotClass() == BOT_CLASS_HUNTER)
    {
        //Endurance Training
        if (level >= 10)
            stamValue *= 1.1f;
        //Greater Stamina
        if (level >= 20)
            stamValue *= 1.12f;
        //Blood of the Rhino part 1
        if (level >= 32)
            stamValue *= 1.04f;
    }
    //additional: store stat
    me->SetStat(STAT_STAMINA, int32(stamValue));
    float m_totalhp = stamValue * stamMult + me->GetCreateHealth() + (/*IAmFree() ? level * 125.f :*/ 0); //+10000/+0 hp at 80
    //hp bonuses
    if (petOwner->GetBotClass() == BOT_CLASS_HUNTER)
    {
        //Innate 5%
        m_totalhp *= 1.05f;
    }
    //TC_LOG_ERROR("entities.player", "SetPetStat(): hp stamval {}1f, stammult {}1f, base {}, total {}2f", stamValue, stamMult, botPet->GetCreateHealth(), m_totalhp);
    bool fullhp = me->GetHealth() == me->GetMaxHealth();
    float pct = fullhp ? 100.f : me->GetHealthPct(); // needs for regeneration
    me->SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, m_totalhp);
    me->UpdateMaxHealth();
    me->SetHealth(fullhp ? me->GetMaxHealth() : uint32(0.5f + float(me->GetMaxHealth()) * pct / 100.f)); //restore pct
    //mana
    if (me->GetPowerType() == POWER_MANA)
    {
        float intValue = me->GetTotalStatValue(STAT_INTELLECT) - me->GetCreateStat(STAT_INTELLECT);
        intValue += 0.3f * petOwner->GetBotAI()->GetTotalBotStat(BOT_STAT_MOD_INTELLECT);
        float intMult;
        switch (myType)
        {
            case BOT_PET_IMP:        intMult = 4.95f; break;
            case BOT_PET_VOIDWALKER:
            case BOT_PET_SUCCUBUS:
            case BOT_PET_FELHUNTER:
            case BOT_PET_FELGUARD:   intMult = 11.5f; break;
            default:                 intMult = 15.f;  break;
        }
        //int/mana bonuses
        if (petOwner->GetBotClass() == BOT_CLASS_WARLOCK)
        {
            //Fel Vitality (pet) part 2
            if (level >= 15)
                intValue *= 1.15f;
        }
        //additional: store stat
        me->SetStat(STAT_INTELLECT, int32(intValue));
        float m_totalmana = intValue * intMult/* + me->GetCreatePowerValue(POWER_MANA)*/ + (IAmFree() ? level * 25.f : 0); //+2000/+0 mana at 80
        //TC_LOG_ERROR("entities.player", "SetPetStat(): mana intValue {}1f, intMult {}1f, base {}, total {}2f", intValue, intMult, botPet->GetCreatePowerValue(POWER_MANA), m_totalmana);
        bool fullmana = me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA);
        pct = fullmana ? 100.f : (float(me->GetPower(POWER_MANA)) * 100.f) / float(me->GetMaxPower(POWER_MANA));
        me->SetStatFlatModifier(UNIT_MOD_MANA, BASE_VALUE, m_totalmana);
        me->UpdateMaxPower(POWER_MANA);
        me->SetPower(POWER_MANA, fullmana ? me->GetMaxPower(POWER_MANA) :
            uint32(0.5f + float(me->GetMaxPower(POWER_MANA)) * pct / 100.f)); //restore pct
    }

    if (force)
    {
        me->SetFullHealth();
        if (me->GetPowerType() == POWER_MANA)
            me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
        else if (me->GetPowerType() == POWER_FOCUS)
            me->SetPower(POWER_FOCUS, me->GetMaxPower(POWER_FOCUS));
    }
}
//Force pet to start attack anyone who tries to DAMAGE me or owner
//This means that anyone who attacks party will be attacked by whole bot party (see GetTarget())
void bot_pet_ai::OnOwnerDamagedBy(Unit* attacker)
{
    switch (myType)
    {
        case BOT_PET_TORNADO:
        case BOT_PET_LOCUST_SWARM:
            return;
        default:
            break;
    }

    if (petOwner->GetBotAI()->HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        return;
    if (!petOwner->GetBotAI()->CanBotAttack(attacker))
        return;

    SetBotCommandState(BOT_COMMAND_COMBATRESET);
    me->Attack(attacker, IsPetMelee());
}

bool bot_pet_ai::IsPetMelee() const
{
    return bot_ai::IsPetMelee(myType);
}

uint8 bot_pet_ai::Spec() const
{
    return petOwner->GetBotAI()->GetSpec();
}

//ISINBOTPARTY
//Returns group members (and their npcbots too)
//For now all your puppets are in your group automatically
bool bot_pet_ai::IsInBotParty(Unit const* unit) const
{
    if (!unit) return false;
    if (unit == petOwner->GetBotOwner() || unit == me || unit == petOwner) return true;

    if (IAmFree())
    {
        if (me->GetFaction() == 14 || unit->GetFaction() == 14)
            return false;

        if (me->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) ||
            unit->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        return
            (unit->GetTypeId() == TYPEID_PLAYER || unit->ToCreature()->IsPet() || unit->IsNPCBot() || unit->IsNPCBotPet()) &&
            (unit->GetFaction() == me->GetFaction() ||
            (me->GetReactionTo(unit) >= REP_FRIENDLY && unit->GetReactionTo(me) >= REP_FRIENDLY));
    }

    //cheap check
    if (Group const* gr = petOwner->GetBotOwner()->GetGroup())
    {
        //group member case
        if (gr->IsMember(unit->GetGUID()))
            return true;
        //pointed target case
        for (uint8 i = 0; i != TARGET_ICONS_COUNT; ++i)
            if (BotMgr::GetHealTargetIconFlags() & GroupIconsFlags[i] &&
                !((BotMgr::GetOffTankTargetIconFlags() | BotMgr::GetDPSTargetIconFlags()) & GroupIconsFlags[i]))
                if (ObjectGuid guid = gr->GetTargetIcons()[i])
                    if (guid == unit->GetGUID())
                        return true;
    }

    //Player-controlled creature case
    if (Creature const* cre = unit->ToCreature())
    {
        ObjectGuid ownerGuid = unit->GetOwnerGUID() ? unit->GetOwnerGUID() : unit->GetCreator() ? unit->GetCreator()->GetGUID() : ObjectGuid::Empty;
        //controlled by master
        if (ownerGuid == petOwner->GetBotOwner()->GetGUID())
            return true;
        //npcbot/npcbot's pet case
        if (cre->GetBotOwner() == petOwner->GetBotOwner())
            return true;
        if (ownerGuid && petOwner->GetBotOwner()->GetBotMgr()->GetBot(ownerGuid))
            return true;
        //controlled by group member
        //pets, minions, guardians etc.
        //bot pets too
        if (ownerGuid)
            if (Group const* gr = petOwner->GetBotOwner()->GetGroup())
                if (gr->IsMember(ownerGuid))
                    return true;
    }

    return false;
}

//REFRESHAURA
//Applies/removes/reapplies aura stacks
void bot_pet_ai::RefreshAura(uint32 spellId, int8 count, Unit* target) const
{
    if (count < 0 || count > 10)
    {
        TC_LOG_ERROR("entities.player", "bot_pet_ai::RefreshAura(): count is out of bounds ({}) for bot {} (botclass: {}, entry: {})",
            int32(count), me->GetName(), uint32(petOwner->GetBotClass()), me->GetEntry());
        return;
    }
    if (!spellId)
    {
        TC_LOG_ERROR("entities.player", "bot_pet_ai::RefreshAura(): spellId is 0 for bot {} (botclass: {}, entry: {})",
            me->GetName(), uint32(petOwner->GetBotClass()), me->GetEntry());
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        TC_LOG_ERROR("entities.player", "bot_pet_ai::RefreshAura(): Invalid spellInfo for spell {}! Bot - {} (botclass: {}, entry: {})",
            spellId, me->GetName(), uint32(petOwner->GetBotClass()), me->GetEntry());
        return;
    }

    if (!target)
        target = me;

    target->RemoveAurasDueToSpell(spellId);

    for (int8 i = 0; i < count; ++i)
        target->AddAura(spellInfo, MAX_EFFECT_MASK, target);
}
//GETTARGET
//Returns attack target or 'no target'
//All code above 'x = _getTarget() call must not dereference opponent since it can be invalid
Unit* bot_pet_ai::_getTarget(bool &reset) const
{
    if (petOwner->GetBotAI()->HasBotCommandState(BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION))
        return nullptr;
    if (petOwner->GetBotAI()->GetEngageTimer() > lastdiff)
        return nullptr;

    Unit* mytar = me->GetVictim();
    Unit* u = petOwner->GetVictim();

    if (mytar && me->HasAuraType(SPELL_AURA_MOD_TAUNT))
        return mytar;

    if (u)
    {
        if (opponent && u != opponent)
            reset = true;
        return u;
    }

    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : petOwner->GetBotOwner()->GetBotMgr()->GetBotFollowDist();

    if (followdist == 0)
        return nullptr;

    float foldist = _getAttackDistance(float(followdist));
    if (!IAmFree() && !IsPetMelee())
    {
        float spelldist;
        uint8 rangeMode = petOwner->GetBotOwner()->GetBotMgr()->GetBotAttackRangeMode();
        if (rangeMode == BOT_ATTACK_RANGE_EXACT)
            spelldist = petOwner->GetBotOwner()->GetBotMgr()->GetBotExactAttackRange();
        else
            spelldist = GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG);
        foldist = std::max<float>(foldist, spelldist + 4.f);
    }
    bool dropTarget = false;
    if (!dropTarget && mytar)
    {
        dropTarget = IAmFree() ?
            petOwner->GetDistance(mytar) > foldist :
            (petOwner->GetBotOwner()->GetDistance(mytar) > foldist || (petOwner->GetBotOwner()->GetDistance(mytar) > foldist * 0.75f && !mytar->IsWithinLOSInMap(petOwner, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2)));
    }
    if (dropTarget)
        return nullptr;

    if (mytar && (!IAmFree() || me->GetDistance(mytar) < float(BOT_MAX_CHASE_RANGE)) && me->IsValidAttackTarget(mytar) && !petOwner->GetBotAI()->IsPointedNoDPSTarget(mytar))
    {
        if (me->GetDistance(mytar) > (!IsPetMelee() ? 20.f : 5.f) && m_botCommandState != COMMAND_STAY && m_botCommandState != COMMAND_FOLLOW)
            reset = true;
        return mytar;
    }

    return nullptr;
}
//'CanAttack' function
//Only called in class ai UpdateAI function
bool bot_pet_ai::CheckAttackTarget()
{
    bool reset = false;
    opponent = _getTarget(reset);

    if (!opponent)
    {
        if (me->GetVictim() || me->IsInCombat())
        {
            if (me->GetVictim())
                me->AttackStop();
        }

        return false;
    }
    if (petOwner->GetBotAI()->IsLastOrder(BOT_ORDER_PULL, 0, opponent->GetGUID()))
        return false;

    if (reset)
        SetBotCommandState(BOT_COMMAND_COMBATRESET);//reset AttackStart()

    if (opponent != me->GetVictim())
        me->Attack(opponent, IsPetMelee());

    return true;
}
//POSITION
//Ranged attack position
void bot_pet_ai::CalculateAttackPos(Unit* target, Position& pos) const
{
    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : petOwner->GetBotOwner()->GetBotMgr()->GetBotFollowDist();
    uint8 rangeMode = IAmFree() ? uint8(BOT_ATTACK_RANGE_LONG) : petOwner->GetBotOwner()->GetBotMgr()->GetBotAttackRangeMode();
    uint8 exactRange = rangeMode != BOT_ATTACK_RANGE_EXACT || IAmFree() ? 255 : petOwner->GetBotOwner()->GetBotMgr()->GetBotExactAttackRange();
    Position ppos;
    float //x(0),y(0),z(0),
        dist = (rangeMode == BOT_ATTACK_RANGE_EXACT) ? exactRange :
        followdist >= 40 ? followdist :
        5 + urand(followdist/3, followdist/3 + 5)/*18-23 at 40, 15-20 at 30*/,
        angle = target->GetAbsoluteAngle(me);
    //most ranged classes have some sort of 20yd spell
    if (rangeMode != BOT_ATTACK_RANGE_EXACT)
        dist = std::min<float>(dist, petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS) ? GetSpellAttackRange(rangeMode == BOT_ATTACK_RANGE_LONG) - 4.f : 30.f);

    float clockwise = (me->GetEntry() % 2) ? 1.f : -1.f;
    float angleDelta = frand(0.0f, float(M_PI)*0.10f) * clockwise;

    for (uint8 i = 0; i != 5; ++i)
    {
        ppos = target->GetFirstCollisionPosition(dist, angle - target->GetOrientation());
        //target->GetNearPoint(me, x, y, z, dist, angle);
        if (!target->IsWithinLOS(/*x,y,z*/ppos.m_positionX, ppos.m_positionY, ppos.m_positionZ))
        {
            if (rangeMode != BOT_ATTACK_RANGE_EXACT)
                dist *= i >= 4 ? 0.1f : 0.33f;
            if (i >= 4)
                angle += angleDelta;
        }
    }

    pos.Relocate(ppos);
    //pos.m_positionX = x;
    //pos.m_positionY = y;
    //pos.m_positionZ = z;
}
// Forces bot to chase opponent (if ranged then distance depends on follow distance)
void bot_pet_ai::GetInPosition(bool force, Unit* newtarget, Position* mypos)
{
    if (petOwner->GetBotAI()->HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        return;
    if (CCed(me, true) || JumpingOrFalling())
        return;
    if (!newtarget)
        newtarget = me->GetVictim();
    if (!newtarget)
        return;
    if ((!newtarget->IsInCombat() || me->isMoving()) && !force)
        return;
    if (IsCasting())
        return;

    if (!IAmFree() && petOwner->GetBotOwner()->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
        petOwner->GetBotOwner()->GetBotMgr()->GetBotExactAttackRange() == 0)
    {
        attackpos.m_positionX = newtarget->GetPositionX() - frand(0.5f, 1.5f) * std::cos(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionY = newtarget->GetPositionY() - frand(0.5f, 1.5f) * std::sin(me->GetAbsoluteAngle(newtarget));
        attackpos.m_positionZ = newtarget->GetPositionZ();
        if (me->GetExactDist2d(&attackpos) > 3.5f)
            me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
        return;
    }

    uint8 followdist = IAmFree() ? BotMgr::GetBotFollowDistMax() : petOwner->GetBotOwner()->GetBotMgr()->GetBotFollowDist();
    if (!IsPetMelee())
    {
        //do not allow constant runaway from player
        if (!force && newtarget->GetTypeId() == TYPEID_PLAYER &&
            me->GetDistance(newtarget) < 6 + urand(followdist/4, followdist/3))
            return;

        if (!mypos)
            CalculateAttackPos(newtarget, attackpos);
        else
        {
            attackpos.m_positionX = mypos->m_positionX;
            attackpos.m_positionY = mypos->m_positionY;
            attackpos.m_positionZ = mypos->m_positionZ;
        }
        if (me->GetExactDist2d(&attackpos) > 4.f || !me->IsWithinLOSInMap(newtarget, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
        {
            me->GetMotionMaster()->MovePoint(newtarget->GetMapId(), attackpos);
            if (!me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                me->SetInFront(newtarget);
        }
    }
    else if (!JumpingOrFalling() && ((!me->HasUnitState(UNIT_STATE_CHASE) && !me->isMoving()) || (!me->HasUnitState(UNIT_STATE_CHASE_MOVE) && me->GetDistance(newtarget) > 1.5f)))
    {
        //me->BotStopMovement();
        me->GetMotionMaster()->MoveChase(newtarget);
    }

    if (newtarget != me->GetVictim())
    {
        if (!me->Attack(newtarget, IsPetMelee()))
            me->SetInFront(newtarget);
    }
}

void bot_pet_ai::CheckAttackState()
{
    if (me->GetVictim())
    {
        MoveBehind(me->GetVictim());

        if (petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS) &&
            !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && !me->HasAuraType(SPELL_AURA_MOD_INVISIBILITY))
        {
            //if (!CCed(me->GetVictim()) || me->HasAuraType(SPELL_AURA_MOD_TAUNT))
                DoMeleeAttackIfReady();
        }
    }
}

void bot_pet_ai::MoveBehind(Unit const* target) const
{
    if (_moveBehindTimer > lastdiff || HasBotCommandState(BOT_COMMAND_MASK_UNMOVING) || !IsPetMelee() || CCed(me, true) || JumpingOrFalling())
        return;

    if (target->GetVictim() != me && !CCed(target) && target->IsWithinCombatRange(me, ATTACK_DISTANCE) && target->HasInArc(float(M_PI), me))
    {
        float x,y,z;
        target->GetNearPoint(me, x, y, z, me->GetCombatReach(), me->GetAbsoluteAngle(target));
        me->GetMotionMaster()->MovePoint(me->GetMapId(), x, y, z);
        const_cast<bot_pet_ai*>(this)->_moveBehindTimer = urand(1000, 4000);
    }
}
bool bot_pet_ai::_canRegenerate() const
{
    switch (me->GetEntry())
    {
        case BOT_PET_DARK_MINION:
        case BOT_PET_DARK_MINION_ELITE:
        case BOT_PET_NECROSKELETON:
        case BOT_PET_TORNADO:
        case BOT_PET_CARRION_BEETLE1:
        case BOT_PET_CARRION_BEETLE2:
        case BOT_PET_CARRION_BEETLE3:
        case BOT_PET_LOCUST_SWARM:
            return false;
        default:
            return true;
    }
}
//Health and Powers regeneration
void bot_pet_ai::Regenerate()
{
    regenTimer += lastdiff;

    //every tick
    if (me->GetPowerType() == POWER_FOCUS)
        RegeneratePetFocus();
    else if (me->GetPowerType() == POWER_ENERGY)
        RegeneratePetEnergy();

    if (regenTimer >= REGEN_CD)
    {
        regenTimer -= REGEN_CD;

        // Regen Pet Health
        if (_canRegenerate() && (!me->IsInCombat() || me->IsPolymorphed()) && me->GetHealth() < me->GetMaxHealth())
        {
            int32 add = IAmFree() && !me->GetVictim() ? me->GetMaxHealth() / 32 : 20 + me->GetCreateHealth() / 64;

            if (me->IsPolymorphed())
                add += me->GetMaxHealth() / 6;
            else if (!me->IsInCombat() || me->HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
            {
                if (!me->IsInCombat())
                {
                    Unit::AuraEffectList const& mModHealthRegenPct = me->GetAuraEffectsByType(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);
                    for (Unit::AuraEffectList::const_iterator i = mModHealthRegenPct.begin(); i != mModHealthRegenPct.end(); ++i)
                        AddPct(add, (*i)->GetAmount());

                    add += me->GetTotalAuraModifier(SPELL_AURA_MOD_REGEN) * REGEN_CD / 5000;
                }
                else if (me->HasAuraType(SPELL_AURA_MOD_REGEN_DURING_COMBAT))
                    ApplyPct(add, me->GetTotalAuraModifier(SPELL_AURA_MOD_REGEN_DURING_COMBAT));
            }

            add += me->GetTotalAuraModifier(SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT);

            if (add < 0)
                add = 0;

            me->ModifyHealth(add);
        }
        // Regen Pet Mana (use bot's regen rate) warlock only
        if (me->GetPowerType() == POWER_MANA && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
        {
            float addvalue;
            if (me->IsUnderLastManaUseEffect())
                addvalue = petOwner->GetFloatValue(UNIT_FIELD_POWER_REGEN_INTERRUPTED_FLAT_MODIFIER);
            else
                addvalue = petOwner->GetFloatValue(UNIT_FIELD_POWER_REGEN_FLAT_MODIFIER);

            addvalue *= sWorld->getRate(RATE_POWER_MANA) * float(REGEN_CD) * 0.001f; //regenTimer threshold / 1000
            if (addvalue < 0.0f)
                addvalue = 0.0f;

            me->ModifyPower(POWER_MANA, int32(addvalue));
        }
    }
}

void bot_pet_ai::RegeneratePetFocus()
{
    uint32 curValue = me->GetPower(POWER_FOCUS);
    uint32 maxValue = me->GetMaxPower(POWER_FOCUS);

    // Regen Pet Focus
    if (curValue < maxValue)
    {
        float addvalue = 0.005f * lastdiff * sWorld->getRate(RATE_POWER_FOCUS); //5 per sec

        //Bestial Discipline
        if (petOwner->GetLevel() >= 30)
            addvalue *= 2;

        addvalue += _energyFraction;

        if (addvalue == 0x0) //only if world rate for focus is 0
            return;

        uint32 integerValue = uint32(fabs(addvalue));

        curValue += integerValue;

        if (curValue > maxValue)
        {
            curValue = maxValue;
            _energyFraction = 0.f;
        }
        else
            _energyFraction = addvalue - float(integerValue);

        if (curValue == maxValue || regenTimer >= REGEN_CD)
            me->SetPower(POWER_FOCUS, curValue);
        else
            me->UpdateUInt32Value(UNIT_FIELD_POWER1 + uint16(POWER_FOCUS), curValue);
    }
}

void bot_pet_ai::RegeneratePetEnergy()
{
    uint32 curValue = me->GetPower(POWER_ENERGY);
    uint32 maxValue = me->GetMaxPower(POWER_ENERGY);

    if (curValue < maxValue)
    {
        float addvalue = 0.01f * lastdiff * sWorld->getRate(RATE_POWER_ENERGY); //10 per sec

        if (addvalue == 0x0) //only if world rate for enegy is 0
            return;

        addvalue += _energyFraction;

        uint32 integerValue = uint32(fabs(addvalue));

        curValue += integerValue;

        if (curValue > maxValue)
        {
            curValue = maxValue;
            _energyFraction = 0.f;
        }
        else
            _energyFraction = addvalue - float(integerValue);

        if (curValue == maxValue || regenTimer >= REGEN_CD)
            me->SetPower(POWER_ENERGY, curValue);
        else
            me->UpdateUInt32Value(UNIT_FIELD_POWER1 + uint16(POWER_ENERGY), curValue);
    }
}
//////////
//SPELLMAP
//////////
//Using first-rank spell as source, returns spellId of max rank allowed for given caster
//If you want bot to use this spell through doCast() go InitSpellMap(uint32) instead
uint32 bot_pet_ai::InitSpell(Unit const* caster, uint32 spell)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(spell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "InitSpell(): No SpellInfo found for spell {}", spell);
        return 0; //weird spell with no info, disable it
    }

    uint8 lvl = caster->GetLevel();
    if (lvl < info->BaseLevel) //only 1st rank spells check
        return 0; //cannot use this spell

    if (SpellInfo const* spInfo = info->GetNextRankSpell())
    {
        if (lvl < spInfo->BaseLevel)
            return spell; //cannot use next rank, use this one
        else
            return InitSpell(caster, spInfo->Id); //can use next rank, forward check
    }

    return spell; //max rank, use this
}
//Using first-rank spell as source, puts spell of max rank allowed for given caster in spellmap
void bot_pet_ai::InitSpellMap(uint32 basespell, bool forceadd, bool forwardRank)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(basespell);
    if (!info)
    {
        TC_LOG_ERROR("entities.player", "bot_pet_ai::InitSpellMap(): No SpellInfo found for base spell {}", basespell);
        return; //invalid spell id
    }

    uint8 lvl = me->GetLevel();
    uint32 spellId = forceadd ? basespell : 0;

    while (info != nullptr && forwardRank && (forceadd || lvl >= info->BaseLevel))
    {
        spellId = info->Id; //can use this spell
        info = info->GetNextRankSpell(); //check next rank
    }

    BotPetSpell* newSpell = _spells[basespell];
    if (!newSpell)
    {
        newSpell = new BotPetSpell();
        _spells[basespell] = newSpell;
    }

    newSpell->spellId = spellId;
}
//Using first-rank spell as source, return current spell id
uint32 bot_pet_ai::GetSpell(uint32 basespell) const
{
    BotPetSpellMap::const_iterator itr = _spells.find(basespell);
    return itr != _spells.end() && (itr->second->enabled == true || IAmFree()) ? itr->second->spellId : 0;
}
//Using first-rank spell as source, returns cooldown on current spell
uint32 bot_pet_ai::GetSpellCooldown(uint32 basespell) const
{
    BotPetSpellMap::const_iterator itr = _spells.find(basespell);
    return itr != _spells.end() ? itr->second->cooldown : 0;
}
bool bot_pet_ai::IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD) const
{
    if (checkGCD && GC_Timer > diff)
        return false;

    BotPetSpellMap::const_iterator itr = _spells.find(basespell);
    return itr == _spells.end() ? true :
        ((itr->second->enabled == true || IAmFree()) && itr->second->spellId != 0 && itr->second->cooldown <= diff);
}
//Using first-rank spell as source, sets cooldown for current spell
void bot_pet_ai::SetSpellCooldown(uint32 basespell, uint32 msCooldown)
{
    //if (!msCooldown)
    //    return;

    BotPetSpellMap::iterator itr = _spells.find(basespell);
    if (itr != _spells.end())
    {
        itr->second->cooldown = msCooldown;
        return;
    }
    else if (!msCooldown)
        return;

    InitSpellMap(basespell, true, false);
    SetSpellCooldown(basespell, msCooldown);
}
//Using first-rank spell as source, sets cooldown for spells of that category
void bot_pet_ai::SetSpellCategoryCooldown(SpellInfo const* spellInfo, uint32 msCooldown)
{
    if (!msCooldown)
        return;

    uint32 category = spellInfo->GetCategory();
    if (!category)
        return;

    SpellInfo const* info;
    for (BotPetSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        //skip spell which has triggered this category cooldown
        if (itr->first == spellInfo->Id && itr->second->cooldown >= msCooldown)
            continue;

        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        if (info && itr->first == spellInfo->Id && info->GetCategory() != category)
        {
            if (itr->first != 7814) // Lash of Pain
            {
                TC_LOG_ERROR("scripts", "Warning: SetSpellCategoryCooldown: {} has baseId {} but category {}, not {}!",
                    info->Id, itr->first, info->GetCategory(), category);
            }
        }

        if (info && (info->GetCategory() == category || itr->first == spellInfo->Id) && itr->second->cooldown < msCooldown)
            itr->second->cooldown = msCooldown;
    }
}
//Handles spell cooldowns for spell with IsCooldownStartedOnEvent() == true
void bot_pet_ai::ReleaseSpellCooldown(uint32 basespell)
{
    SpellInfo const* baseInfo = sSpellMgr->GetSpellInfo(basespell);

    if (!baseInfo->IsCooldownStartedOnEvent())
    {
        TC_LOG_ERROR("spells", "bot_pet_ai::ReleaseSpellCooldown is called for wrong spell {}!", basespell);
        return;
    }

    uint32 rec = baseInfo->RecoveryTime;
    uint32 catrec = baseInfo->CategoryRecoveryTime;

    SetSpellCooldown(baseInfo->Id, rec > 0 ? rec : 0);
    SetSpellCategoryCooldown(baseInfo, catrec > 0 && !(baseInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS) ? catrec : 0);
}
//Using first-rank spell as source, disables certain spell for this bot
void bot_pet_ai::RemoveSpell(uint32 basespell)
{
    BotPetSpell* newSpell;
    BotPetSpellMap::iterator itr = _spells.find(basespell);
    if (itr == _spells.end())
    {
        newSpell = new BotPetSpell();
        _spells[basespell] = newSpell;
    }
    else
        newSpell = itr->second;

    newSpell->spellId = 0;
    newSpell->cooldown = 0;
}
//See CommonTimers(uint32)
void bot_pet_ai::SpellTimers(uint32 diff)
{
    // spell must be initialized!!!
    for (BotPetSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        if (itr->second->cooldown >= diff)
            itr->second->cooldown -= diff;
        else if (itr->second->cooldown > 0)
            itr->second->cooldown = 0;
    }
}
//Bots cannot dodge/parry from behind so try to condense enemies at front
//opponent is always valid
void bot_pet_ai::AdjustTankingPosition() const
{
    if (/*!IsTank() || */!me->IsInCombat() || IsCasting() ||
        JumpingOrFalling() || CCed(me, true) || Rand() > 10 + 20*me->GetMap()->IsDungeon() ||
        HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        return;

    Unit::AttackerSet const& myattackers = me->getAttackers();
    if (myattackers.size() < 2)
        return;

    //TC_LOG_ERROR("entities.player", "AdjustTankingPosition() by {}", me->GetName());

    uint32 bCount = 0;
    for (Unit::AttackerSet::const_iterator itr = myattackers.begin(); itr != myattackers.end(); ++itr)
    {
        if (/*!CCed(*itr) && */(*itr)->GetDistance(me) < 5 && !me->HasInArc(float(M_PI), *itr))
            ++bCount;
            //if (++bCount)
            //    break;
    }

    if (bCount == 0)
        return;

    //TC_LOG_ERROR("entities.player", "AdjustTankingPosition(): atts {}, behind {}", uint32(myattackers.size()), bCount);

    //calculate new position
    float x = me->GetPositionX();
    float y = me->GetPositionY();
    float z = me->GetPositionZ();
    float ori = me->GetOrientation();
    float const moveDist = -1.f * std::max<float>(opponent->GetCombatReach() * 0.6f, 3.f);
    float moveX = 0.f;
    float moveY = 0.f;
    for (uint8 i = 0; i != 3; ++i)
    {
        if (i)
        {
            ori = Position::NormalizeOrientation(ori + (i+1)*(M_PI*0.5f));
        }

        //move back
        moveX = moveDist * std::cos(ori);
        moveY = moveDist * std::sin(ori);

        if (me->IsWithinLOS(x+moveX, y+moveY, z))
            break;

        if (i == 2)
        {
            moveX *= 0.2f;
            moveY *= 0.2f;
        }
    }

    x += moveX;
    y += moveY;

    me->UpdateAllowedPositionZ(x, y, z);
    if (me->GetPositionZ() < z)
        z += 0.75f; //prevent going underground

    //if (CCed(opponent, true))
    //    me->AttackStop();
    //me->SetOrientation(ori);
    me->GetMotionMaster()->MovePoint(me->GetMapId(), x, y, z);
}
//SpellHit()... OnSpellHit()
void bot_pet_ai::OnSpellHit(Unit* caster, SpellInfo const* spell)
{
    //uint32 const spellId = spell->Id;

    if (spell->HasAura(SPELL_AURA_MOD_TAUNT) || spell->HasEffect(SPELL_EFFECT_ATTACK_ME))
        if (caster && me->Attack(caster, true))
            me->GetMotionMaster()->MoveChase(caster);

    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
    {
        uint32 const auraname = spell->_effects[i].ApplyAuraName;

        //update stats
        if (auraname == SPELL_AURA_MOD_STAT || auraname == SPELL_AURA_MOD_PERCENT_STAT ||
            auraname == SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER || auraname == SPELL_AURA_MOD_ATTACK_POWER_PCT ||
            auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT || auraname == SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR ||
            auraname == SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT ||
            auraname == SPELL_AURA_MOD_RATING || auraname == SPELL_AURA_MOD_RATING_FROM_STAT)
            shouldUpdateStats = true;
        else if (auraname == SPELL_AURA_MOD_INCREASE_HEALTH ||
            auraname == SPELL_AURA_MOD_INCREASE_HEALTH_2 ||
            auraname == SPELL_AURA_230 ||
            auraname == SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT)
            shouldUpdateStats = true;
        else if (auraname == SPELL_AURA_MOD_INCREASE_ENERGY || auraname == SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT)
            shouldUpdateStats = true;
    }

    if (!me->GetVictim() && (me->IsHostileTo(caster) || caster->IsHostileTo(me)))
    {
        if (me->CanSeeOrDetect(caster) && (caster->IsInCombat() || me->IsInCombat() || petOwner->IsInCombat()))
            petOwner->GetBotAI()->OwnerAttackedBy(caster);
    }
}
//Update delay
//Skip UpdateAI cycles for randomization of bots' reaction and performance adjustments
bool bot_pet_ai::Wait()
{
    if (waitTimer > lastdiff)
        return true;

    if (IAmFree())
        waitTimer = me->IsInCombat() ? 250 : ((__rand + 100) * 20);
    else if (!me->GetMap()->IsRaid())
        waitTimer = std::min<uint32>(uint32(50 * (petOwner->GetBotOwner()->GetNpcBotsCount() - 1) + __rand + __rand), 500);
    else
        waitTimer = __rand;

    return false;
}
//Spell Mod Hooks
void bot_pet_ai::ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const
{
    //DAMAGE SPELLS damage bonus (DMG_CLASS_MAGIC)
    ApplyClassDamageMultiplierSpell(damage, damageinfo, spellInfo, attackType, crit);
}
//Spell Mod Utilities
float bot_pet_ai::CalcSpellMaxRange(uint32 spellId, bool enemy) const
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    ASSERT(spellInfo);

    return spellInfo->GetMaxRange(!enemy);
}
bool bot_pet_ai::IAmFree() const
{
    return petOwner->IsFreeBot();
}

bool bot_pet_ai::CCed(Unit const* target, bool root)
{
    return bot_ai::CCed(target, root);
}

bool bot_pet_ai::IsTank(Unit const* unit) const
{
    if (Creature const* bot = unit->ToCreature())
        return bot->GetBotAI() && bot->GetBotAI()->HasRole(BOT_ROLE_TANK);
    else if (Player const* player = unit->ToPlayer())
    {
        if (Group const* gr = player->GetGroup())
        {
            if (gr->GetMemberFlags(unit->GetGUID()) & MEMBER_FLAG_MAINTANK)
                return true;
            if (gr->isLFGGroup() && sLFGMgr->GetRoles(unit->GetGUID()) & lfg::PLAYER_ROLE_TANK)
                return true;
        }
    }

    return false;
}
//Unused
bool bot_pet_ai::IsOffTank(Unit const* unit) const
{
    if (Creature const* bot = unit->ToCreature())
        return bot->GetBotAI() && bot->GetBotAI()->HasRole(BOT_ROLE_TANK_OFF);
    else if (Player const* player = unit->ToPlayer())
    {
        if (Group const* gr = player->GetGroup())
        {
            if (gr->isRaidGroup())
            {
                Group::MemberSlotList const& slots = gr->GetMemberSlots();
                for (Group::member_citerator itr = slots.begin(); itr != slots.end(); ++itr)
                    if (itr->guid == unit->GetGUID())
                        return itr->flags & MEMBER_FLAG_MAINASSIST;
            }
        }
    }

    return false;
}

void bot_pet_ai::OnStartAttack(Unit const* /*u*/)
{
    AdjustTankingPosition();
}

bool bot_pet_ai::StartAttack(Unit const* u, bool force)
{
    if (HasBotCommandState(BOT_COMMAND_ATTACK) && !force)
        return false;

    SetBotCommandState(BOT_COMMAND_ATTACK);
    OnStartAttack(u);
    return true;
}

void bot_pet_ai::JustDied(Unit*)
{
    KillEvents(false);
}

void bot_pet_ai::KilledUnit(Unit* u)
{
    GetPetsOwner()->GetBotAI()->KilledUnit(u);
}

void bot_pet_ai::AttackStart(Unit* /*u*/)
{
}

void bot_pet_ai::DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/)
{
    if (victim == me)
        return;

    if (damage)
    {
        if (Creature* cre = victim->ToCreature())
        {
            if (!cre->hasLootRecipient())
                cre->SetLootRecipient(petOwner->GetBotOwner());

            //controlled case is handled in Unit::DealDamage
            if (IAmFree())
                cre->LowerPlayerDamageReq(cre->GetHealth() < damage ?  cre->GetHealth() : damage);
        }
    }
}

void bot_pet_ai::IsSummonedBy(WorldObject* summoner)
{
    //TC_LOG_ERROR("entities.unit", "bot_pet_ai::IsSummonedBy for {} by {}", me->GetName(), summoner->GetName());
    //ASSERT(!petOwner);
    //ASSERT(summoner->GetTypeId() == TYPEID_UNIT);
    petOwner = summoner->ToCreature();
    m_botCommandState = petOwner->GetBotAI()->GetBotCommandState();
    myType = me->GetEntry();
    //myType = petOwner->GetBotAI()->GetAIMiscValue(BOTAI_MISC_PET_TYPE);
    //ASSERT(myType);
    me->setActive(true);
    //me->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
    ASSERT(!me->GetBotAI());
    ASSERT(!me->GetBotPetAI());
    me->SetBotPetAI(this);
    SetPetStats(true);
    if (petOwner->GetTransport())
    {
        petOwner->GetTransport()->AddPassenger(me);
        me->m_movementInfo.transport.pos.Relocate(petOwner->GetTransOffset());
        me->Relocate(bot_ai::GetAbsoluteTransportPosition(petOwner));
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
    }
    //Send group update if not a minion
    if (petOwner->GetBotAI()->GetBotsPet() == me && petOwner->GetBotAI()->GetGroup())
        BotMgr::SetBotGroupUpdateFlag(petOwner, GROUP_UPDATE_PET);
}
//This function is called after Spell::SendSpellCooldown() and Spell::DoAllEffects...() call
void bot_pet_ai::OnBotPetSpellGo(Spell const* spell, bool ok)
{
    if (!ok)
        return;

    SpellInfo const* curInfo = spell->GetSpellInfo();

    //Set cooldown
    if (!curInfo->IsCooldownStartedOnEvent() && !curInfo->IsPassive())
    {
        uint32 rec = curInfo->RecoveryTime;
        uint32 catrec = curInfo->CategoryRecoveryTime;

        SetSpellCooldown(curInfo->GetFirstRankSpell()->Id, rec);
        SetSpellCategoryCooldown(curInfo->GetFirstRankSpell(), catrec);
    }

    if ((!curInfo->CastTimeEntry || !curInfo->CastTimeEntry->Base) &&
        curInfo->StartRecoveryTime)
    {
        GC_Timer = curInfo->StartRecoveryTime;
        GC_Timer = std::max<uint32>(GC_Timer, 1000);
        GC_Timer = std::min<uint32>(GC_Timer, 1500);
    }

    OnPetClassSpellGo(curInfo);
}

void bot_pet_ai::OnBotPetSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs)
{
    SpellInfo const* info;

    for (BotPetSpellMap::iterator itr = _spells.begin(); itr != _spells.end(); ++itr)
    {
        info = sSpellMgr->GetSpellInfo(itr->second->spellId);
        if (!info || !(info->GetSchoolMask() & schoolMask)) continue;
        if (info->IsCooldownStartedOnEvent()) continue;
        if (info->PreventionType != SPELL_PREVENTION_TYPE_SILENCE) continue;

        itr->second->cooldown += unTimeMs;
        //TC_LOG_ERROR("entities.player", "OnBotPetSpellInterrupted(): Adding cooldown ({}, new: {}) to spell {} (id: {}, schoolmask: {}), reqSchoolMask = {}",
        //    unTimeMs, itr->second.second, info->SpellName[0], info->Id, info->SchoolMask, schoolMask);
    }

    GC_Timer = 0; //reset global cooldown since cast is canceled
}
//GLOBAL UPDATE
//opponent unsafe
bool bot_pet_ai::GlobalUpdate(uint32 diff)
{
    if (!petOwner)
    {
        TC_LOG_ERROR("entities.unit", "botpet:GlobalUpdate(): no owner!");
        return false;
    }

    if (!BotMgr::IsNpcBotModEnabled())
        return false;

    ReduceCD(diff);

    lastdiff = diff;

    if (_updateTimerMedium <= diff)
    {
        _updateTimerMedium = 500;

        //Medium-timed updates
        if (!IAmFree())
        {
            //update pvp state
            if (me->GetByteValue(UNIT_FIELD_BYTES_2, 1) != petOwner->GetByteValue(UNIT_FIELD_BYTES_2, 1))
                me->SetByteValue(UNIT_FIELD_BYTES_2, 1, petOwner->GetByteValue(UNIT_FIELD_BYTES_2, 1));
        }
        if (myType == BOT_PET_LOCUST_SWARM)
        {
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 2.0f * DEFAULT_PLAYER_BOUNDING_RADIUS * me->GetObjectScale());
            me->SetFloatValue(UNIT_FIELD_COMBATREACH,  2.0f * DEFAULT_PLAYER_COMBAT_REACH * me->GetObjectScale());
        }
    }

    if (!me->IsAlive())
        return false;

    //Check current cast state: interrupt casts that became pointless
    if (me->HasUnitState(UNIT_STATE_CASTING) && urand(1,100) <= 75)
    {
        bool interrupt;
        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
        {
            interrupt = false;
            Spell* spell = me->GetCurrentSpell(CurrentSpellTypes(i));
            if (!spell)
                continue;
            if (spell->m_targets.GetObjectTargetGUID().IsAnyTypeCreature())
                spell->m_targets.Update(me);
            Unit const* target = spell->m_targets.GetUnitTarget();
            if (!target)
                continue;
            SpellInfo const* info = spell->GetSpellInfo();
            if (!info->CastTimeEntry)
                continue;
            if (!info->IsPositive())
            {
                if (!target->IsAlive())
                    interrupt = true;
                //control interruptions should be checked inside pet class ai
                //else if ((info->Mechanic == MECHANIC_POLYMORPH || info->Mechanic == MECHANIC_SHACKLE ||
                //    info->Mechanic == MECHANIC_DISORIENTED || info->Mechanic == MECHANIC_SLEEP ||
                //    info->Mechanic == MECHANIC_CHARM || info->Mechanic == MECHANIC_BANISH ||
                //    info->Mechanic == MECHANIC_STUN || info->Mechanic == MECHANIC_FREEZE) &&
                //    !target->getAttackers().empty() && !IsCasting(target))
                //    interrupt = true; //useless control
                else if (target->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && !IsCasting(target) &&
                    (info->AuraInterruptFlags & AURA_INTERRUPT_FLAG_TAKE_DAMAGE))
                    interrupt = true; //useless control breaks immediately
            }

            if (interrupt)
            {
                me->InterruptSpell(CurrentSpellTypes(i));
                GC_Timer = 0;
                break;
            }
        }
    }

    if (_updateTimerEx1 <= diff && !IAmFree())
    {
        _updateTimerEx1 = urand(2000, 2500);

        //Ex1-timed updates

        //DEBUG
        /*
        Sometimes bots are affected by zone (instance) scripts
        Good example is CoT: Battle for Mount Hyjal
        */
        //Faction
        //ensure master is not controlled
        ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(petOwner->GetBotOwner()->GetRace());
        uint32 fac = rEntry ? rEntry->FactionID : 0;
        if (me->GetFaction() != petOwner->GetBotOwner()->GetFaction() && petOwner->GetBotOwner()->GetFaction() == fac)
        {
            //std::ostringstream msg;
            //msg << "Something changed my faction (now " << me->GetFaction() << "), changing back to " << fac << "!";
            //BotWhisper(msg.str().c_str());
            me->SetFaction(fac);
        }
        //Visibility
        if (!me->IsVisible() && petOwner->GetBotOwner()->IsVisible())
        {
            //BotWhisper("Something changed my visibility status! Making visible...");
            me->SetVisible(true);
        }
        if (me->IsVisible() && !petOwner->GetBotOwner()->IsVisible())
        {
            //BotWhisper("Something changed my visibility status! Making invisible...");
            me->SetVisible(false);
        }
        //Phase
        if (me->GetPhaseMask() != petOwner->GetBotOwner()->GetPhaseMask())
        {
            //BotWhisper("Somehow we are not is same phase! Fixing that...");
            me->SetPhaseMask(petOwner->GetBotOwner()->GetPhaseMask(), true);
        }
        if (me->GetTransport() != petOwner->GetBotOwner()->GetTransport())
        {
            if (petOwner->GetBotOwner()->GetTransport())
            {
                if (me->GetDistance2d(petOwner->GetBotOwner()) < 20.f)
                {
                    petOwner->GetBotOwner()->GetTransport()->AddPassenger(me);
                    me->m_movementInfo.transport.pos.Relocate(petOwner->GetBotOwner()->GetTransOffset());
                    me->Relocate(bot_ai::GetAbsoluteTransportPosition(petOwner->GetBotOwner()));
                    me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                }
            }
            else
            {
                switch (me->GetEntry())
                {
                    case BOT_PET_TORNADO:
                    case BOT_PET_LOCUST_SWARM:
                        break;
                    default:
                        me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                    break;
                }
                me->GetTransport()->RemovePassenger(me);
            }
        }
        //end DEBUG
    }

    Regenerate();

    //update flags
    if (!me->IsInCombat())
    {
        if (me->HasUnitFlag(UNIT_FLAG_PET_IN_COMBAT))
            me->RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
    }

    //update movement orders if near owner, otherwise get close
    bool closeToOwner = false;
    if (!opponent && !IsCasting())
    {
        _calculatePos(movepos);
        if (me->GetExactDist(&movepos) > 5.f)
            SetBotCommandState(BOT_COMMAND_FOLLOW, true, &movepos);
        else
            closeToOwner = !me->isMoving();
    }
    if (closeToOwner || me->IsInCombat())
    {
        uint8 st = (petOwner->GetBotAI()->GetBotCommandState() & BOT_COMMAND_MASK_UNMOVING);
        if (st && GetBotCommandState() != st)
        {
            SetBotCommandState(st);
            return !(st & BOT_COMMAND_FULLSTOP);
        }
    }

    if (HasBotCommandState(BOT_COMMAND_FULLSTOP))
        return false;

    if (!HasBotCommandState(BOT_COMMAND_INACTION))
        CheckAttackState();

    //second alive check - CheckAttackState() can cause bot to die
    if (!me->IsAlive())
        return false;

    if (checkAurasTimer <= lastdiff)
    {
        Unit* victim = me->GetVictim();
        checkAurasTimer += uint32(__rand + __rand + (IAmFree() ? 1000 : 40 * (1 + petOwner->GetBotOwner()->GetNpcBotsCount())));

        if (!HasBotCommandState(BOT_COMMAND_MASK_UNCHASE) && victim && !CCed(me, true) &&
            !me->isMoving() && !IsCasting() && myType != BOT_PET_TORNADO && myType != BOT_PET_LOCUST_SWARM)
        {
            if (!IAmFree() && petOwner->GetBotOwner()->GetBotMgr()->GetBotAttackRangeMode() == BOT_ATTACK_RANGE_EXACT &&
                petOwner->GetBotOwner()->GetBotMgr()->GetBotExactAttackRange() == 0)
            {
                GetInPosition(true, victim);
            }
            else if (IsPetMelee())
            {
                if (me->GetDistance(victim) > 1.5f)
                    GetInPosition(true, victim);
            }
            else
            {
                CalculateAttackPos(victim, attackpos);
                if (me->GetExactDist2d(&attackpos) > 4.f || !me->IsWithinLOSInMap(victim, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    GetInPosition(true, victim, &attackpos);
            }
        }
        if (shouldUpdateStats && me->GetPhaseMask() == petOwner->GetBotOwner()->GetPhaseMask())
            SetPetStats(false);
    }

    if (Wait())
        return false;

    if (CCed(me))
        return false;

    GenerateRand();

    if (HasBotCommandState(BOT_COMMAND_INACTION))
        return false;

    return true;
}

void bot_pet_ai::CommonTimers(uint32 diff)
{
    //_petEvents.Update(diff);
    SpellTimers(diff);

    if (GC_Timer > diff)            GC_Timer -= diff;
    if (checkAurasTimer > diff)     checkAurasTimer -= diff;
    if (waitTimer > diff)           waitTimer -= diff;
    if (_moveBehindTimer > diff)    _moveBehindTimer -= diff;

    if (_updateTimerMedium > diff)  _updateTimerMedium -= diff;
    if (_updateTimerEx1 > diff)     _updateTimerEx1 -= diff;
}

void bot_pet_ai::KillEvents(bool /*force*/)
{
    //_petEvents.KillAllEvents(force);
}

bool bot_pet_ai::IsChanneling(Unit const* u/* = nullptr*/) const
{
    if (!u)
        u = me;
    return u->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
}
bool bot_pet_ai::IsCasting(Unit const* u/* = nullptr*/) const
{
    if (!u)
        u = me;
    return (u->HasUnitState(UNIT_STATE_CASTING) || IsChanneling(u) || u->IsNonMeleeSpellCast(false, false, true, false, false));
}
bool bot_pet_ai::JumpingFlyingOrFalling() const
{
    return Jumping() || me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_SPLINE_ELEVATION|MOVEMENTFLAG_FALLING_SLOW);
}
bool bot_pet_ai::JumpingOrFalling() const
{
    return Jumping() || me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_FALLING_SLOW);
}
bool bot_pet_ai::Jumping() const
{
    return me->HasUnitState(UNIT_STATE_JUMPING);
}
bool bot_pet_ai::IsIndoors() const
{
    return indoorsTimer >= INOUTDOORS_ENSURE_TIMER && outdoorsTimer == 0;
}
bool bot_pet_ai::IsOutdoors() const
{
    return outdoorsTimer >= INOUTDOORS_ENSURE_TIMER && indoorsTimer == 0;
}

uint32 bot_pet_ai::GetLostHP(Unit const* unit)
{
    return unit->GetMaxHealth() - unit->GetHealth();
}
uint8 bot_pet_ai::GetHealthPCT(Unit const* u)
{
    if (!u || !u->IsAlive() || u->GetMaxHealth() <= 1)
        return 100;
    return uint8(((float(u->GetHealth()))/u->GetMaxHealth()) * 100);
}
uint8 bot_pet_ai::GetManaPCT(Unit const* u)
{
    if (!u || !u->IsAlive() || u->GetMaxPower(POWER_MANA) <= 1)
        return 100;
    return (u->GetPower(POWER_MANA)*10/(1 + u->GetMaxPower(POWER_MANA)/10));
}
