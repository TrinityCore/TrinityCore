#include "UnitBehavior.h"
#include "GameTime.h"
#include "ThreatManager.h"

UnitBehavior::UnitBehavior(Unit* owner) : _owner(owner)
{
}

void UnitBehavior::Update()
{
    if (!_owner->IsEngaged())
    {
        if (!ShouldAutoEngage())
            return;
        LookForAutoEngage();
    }

    // intentional duplicate conditional
    // we may now be engaged, even though we weren't before!
    if (_owner->IsEngaged())
    {
        if (ShouldTargetFromThreat())
            UpdatePrimaryTargetFromThreat();
        UpdateAutoAttackState();
    }
}

void UnitBehavior::LookForAutoEngage()
{
    // @todo
}

void UnitBehavior::UpdatePrimaryTargetFromThreat()
{
    ThreatManager& threat = _owner->GetThreatManager();
    // @todo update threat victim
    Unit* const target = threat.GetCurrentVictim();
    if (!target && ShouldEvadeWithoutTargets())
    {
        // @todo enter evade mode
        return;
    }
    SetPrimaryTarget(target);
}

void UnitBehavior::UpdateAutoAttackState()
{
    Unit* const toAttack = ShouldAutoAttack() ? GetPrimaryTarget() : nullptr;
        // @todo split "Victim" and "auto-attack target"
    if (_owner->GetVictim() != toAttack)
    {
        if (toAttack)
            _owner->Attack(toAttack, true);
        else
            _owner->AttackStop();
    }
}
