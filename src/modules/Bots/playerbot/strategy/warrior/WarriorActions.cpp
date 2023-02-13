#include "botpch.h"
#include "../../playerbot.h"
#include "WarriorActions.h"

using namespace ai;

NextAction** CastDisarmAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastDebuffSpellAction::getPrerequisites());
}

NextAction** CastRevengeAction::getPrerequisites()
{
    return NextAction::merge( NextAction::array(0, new NextAction("defensive stance"), NULL), CastMeleeSpellAction::getPrerequisites());
}

NextAction** CastRampageAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("berserker stance"), NULL), CastMeleeSpellAction::getPrerequisites());
}
