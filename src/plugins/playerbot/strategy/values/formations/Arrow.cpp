#include "../../../../pchdef.h"
#include "../../../playerbot.h"
#include "../Formations.h"
#include "Arrow.h"

using namespace ai;

WorldLocation ArrowFormation::GetLocation()
{
    Build();

    int tankLines = 1 + tanks.Size() / 6;
    int meleeLines = 1 + melee.Size() / 6;
    int rangedLines = 1 + ranged.Size() / 6;
    int healerLines = 1 + healers.Size() / 6;
    float offset = 0;

    Player* master = ai->GetMaster();
    float orientation = master->GetOrientation();
    MultiLineUnitPlacer placer(orientation);

    tanks.PlaceUnits(&placer);

    offset = tankLines * sPlayerbotAIConfig.followDistance;
    melee.PlaceUnits(&placer);
    melee.Move(-cos(orientation) * offset, -sin(orientation) * offset);

    offset += meleeLines * sPlayerbotAIConfig.followDistance + sPlayerbotAIConfig.tooCloseDistance;
    ranged.PlaceUnits(&placer);
    ranged.Move(-cos(orientation) * offset, -sin(orientation) * offset);

    offset += rangedLines * sPlayerbotAIConfig.followDistance;
    healers.PlaceUnits(&placer);
    healers.Move(-cos(orientation) * offset, -sin(orientation) * offset);

    float x = master->GetPositionX() - masterUnit->GetX() + botUnit->GetX();
    float y = master->GetPositionY() - masterUnit->GetY() + botUnit->GetY();
    float z = master->GetPositionZ();

    float ground = master->GetMap()->GetHeight(x, y, z + 0.5f);
    if (ground <= INVALID_HEIGHT)
        return Formation::NullLocation;

    return WorldLocation(master->GetMapId(), x, y, 0.05f + ground);


}

void ArrowFormation::Build()
{
    if (built)
        return;

    FillSlotsExceptMaster();
    AddMasterToSlot();

    built = true;
}

FormationSlot* ArrowFormation::FindSlot(Player* member)
{
    if (ai->IsTank(member))
        return &tanks;
    else if (ai->IsHeal(member))
        return &healers;
    else if (ai->IsRanged(member))
        return &ranged;
    else
        return &melee;
}

void ArrowFormation::FillSlotsExceptMaster()
{
    Group* group = bot->GetGroup();
    GroupReference *gref = group->GetFirstMember();
    uint32 index = 0;
    while (gref)
    {
        Player* member = gref->GetSource();

        if (member == bot)
            FindSlot(member)->AddLast(botUnit = new FormationUnit(index, false));
        else if (member != ai->GetMaster())
            FindSlot(member)->AddLast(new FormationUnit(index, false));

        gref = gref->next();
        index++;
    }
}

void ArrowFormation::AddMasterToSlot()
{
    Group* group = bot->GetGroup();
    GroupReference *gref = group->GetFirstMember();
    uint32 index = 0;
    while (gref)
    {
        Player* member = gref->GetSource();

        if (member == ai->GetMaster())
        {
            FindSlot(member)->InsertAtCenter(masterUnit = new FormationUnit(index, true));
            break;
        }

        gref = gref->next();
        index++;
    }
}

void FormationSlot::PlaceUnits(UnitPlacer* placer)
{
    uint32 index = 0;
    uint32 count = units.size();
    for (vector<FormationUnit*>::iterator i = units.begin(); i != units.end(); ++i)
    {
        FormationUnit* unit = *i;
        unit->SetLocation(placer->Place(unit, index, count));
        index++;
    }
}

UnitPosition MultiLineUnitPlacer::Place(FormationUnit *unit, uint32 index, uint32 count)
{
    SingleLineUnitPlacer placer(orientation);
    if (count <= 6)
        return placer.Place(unit, index, count);

    int lineNo = index / 6;
    int indexInLine = index % 6;
    int lineSize = max(count - lineNo * 6, uint32(6));
    float x = cos(orientation) * sPlayerbotAIConfig.followDistance * lineNo;
    float y = sin(orientation) * sPlayerbotAIConfig.followDistance * lineNo;
    return placer.Place(unit, indexInLine, lineSize);
}

UnitPosition SingleLineUnitPlacer::Place(FormationUnit *unit, uint32 index, uint32 count)
{
    float angle = orientation - M_PI / 2.0f;
    float x = cos(angle) * sPlayerbotAIConfig.followDistance * ((float)index - (float)count / 2);
    float y = sin(angle) * sPlayerbotAIConfig.followDistance * ((float)index - (float)count / 2);
    return UnitPosition(x, y);
}

void FormationSlot::Move(float dx, float dy)
{
    for (vector<FormationUnit*>::iterator i = units.begin(); i != units.end(); ++i)
    {
        FormationUnit* unit = *i;
        unit->SetLocation(unit->GetX() + dx, unit->GetY() + dy);
    }
}

FormationSlot::~FormationSlot()
{
    for (vector<FormationUnit*>::iterator i = units.begin(); i != units.end(); ++i)
    {
        FormationUnit* unit = *i;
        delete unit;
    }
    units.clear();
}
