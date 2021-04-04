#include "TSDamageInfo.h"
#include "TSUnit.h"
#include "Unit.h"

TSMeleeDamageInfo::TSMeleeDamageInfo(CalcDamageInfo * info)
: _info(info)
{}

TSUnit TSMeleeDamageInfo::GetAttacker()
{
    return TSUnit(_info->Attacker);
}

TSUnit TSMeleeDamageInfo::GetTarget()
{
    return TSUnit(_info->Target);
}

uint32 TSMeleeDamageInfo::GetSchool1()
{
    return _info->Damages[0].DamageSchoolMask;
}

uint32 TSMeleeDamageInfo::GetSchool2()
{
    return _info->Damages[1].DamageSchoolMask;
}

uint32 TSMeleeDamageInfo::GetDamage1()
{
    return _info->Damages[0].Damage;
}

uint32 TSMeleeDamageInfo::GetDamage2()
{
    return _info->Damages[1].Damage;
}

uint32 TSMeleeDamageInfo::GetAbsorb1()
{
    return _info->Damages[0].Absorb;
}

uint32 TSMeleeDamageInfo::GetAbsorb2()
{
    return _info->Damages[1].Absorb;
}

uint32 TSMeleeDamageInfo::GetResist1()
{
    return _info->Damages[0].Resist;
}

uint32 TSMeleeDamageInfo::GetResist2()
{
    return _info->Damages[1].Resist;
}

uint32 TSMeleeDamageInfo::GetBlocked()
{
    return _info->Blocked;
}

uint32 TSMeleeDamageInfo::GetHitInfo()
{
    return _info->HitInfo;
}

uint32 TSMeleeDamageInfo::GetTargetState()
{
    return _info->TargetState;
}

uint32 TSMeleeDamageInfo::GetAttackType()
{
    return _info->AttackType;
}

uint32 TSMeleeDamageInfo::GetProcAttacker()
{
    return _info->ProcAttacker;
}

uint32 TSMeleeDamageInfo::GetProcVictim()
{
    return _info->ProcVictim;
}

uint32 TSMeleeDamageInfo::GetCleanDamage()
{
    return _info->CleanDamage;
}

uint8 TSMeleeDamageInfo::GetMeleeHitOutcome()
{
    return _info->HitOutCome;
}

TSSpellDamageInfo::TSSpellDamageInfo(SpellNonMeleeDamage * info)
: _info(info)
{}

TSUnit TSSpellDamageInfo::GetAttacker()
{
    return TSUnit(_info->attacker);
}

TSUnit TSSpellDamageInfo::GetTarget()
{
    return TSUnit(_info->target);
}

uint32 TSSpellDamageInfo::GetSpellID()
{
    return _info->SpellID;
}

uint32 TSSpellDamageInfo::GetDamage()
{
    return _info->damage;
}

uint32 TSSpellDamageInfo::GetOverkill()
{
    return _info->overkill;
}

uint32 TSSpellDamageInfo::GetSchoolMask()
{
    return _info->schoolMask;
}

uint32 TSSpellDamageInfo::GetAbsorb()
{
    return _info->absorb;
}

uint32 TSSpellDamageInfo::GetResist()
{
    return _info->resist;
}

bool TSSpellDamageInfo::GetPeriodicLog()
{
    return _info->periodicLog;
}

bool TSSpellDamageInfo::GetUnused()
{
    return _info->unused;
}

uint32 TSSpellDamageInfo::GetBlocked()
{
    return _info->blocked;
}

uint32 TSSpellDamageInfo::GetHitInfo()
{
    return _info->HitInfo;
}

uint32 TSSpellDamageInfo::GetCleanDamage()
{
    return _info->cleanDamage;
}

bool TSSpellDamageInfo::GetFullBlock()
{
    return _info->fullBlock;
}