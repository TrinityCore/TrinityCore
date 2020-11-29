// @tswow-begin
#include "TotemCreature.h"

TotemCreature::TotemCreature(SummonPropertiesEntry const* properties, Unit* owner)
    : Minion(properties, owner, false)
{
    this->m_isTempCreature = true;
    this->InitCharmInfo();
    // TODO: Can we store this?
    this->SetReactState(REACT_DEFENSIVE);
}
// @tswow-end