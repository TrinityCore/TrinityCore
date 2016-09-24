#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "Formations.h"
#include "formations/Arrow.h"

using namespace ai;

WorldLocation Formation::NullLocation = WorldLocation();

namespace ai
{
    class MeleeFormation : public FollowFormation
    {
    public:
        MeleeFormation(PlayerbotAI* ai) : FollowFormation(ai, "melee") {}
        virtual string GetTargetName() { return "master target"; }
    };

    class QueueFormation : public FollowFormation
    {
    public:
        QueueFormation(PlayerbotAI* ai) : FollowFormation(ai, "queue") {}
        virtual string GetTargetName() { return "line target"; }
    };

    class NearFormation : public MoveFormation
    {
    public:
        NearFormation(PlayerbotAI* ai) : MoveFormation(ai, "near") {}
        virtual WorldLocation GetLocation()
        {
            Player* master = GetMaster();
            if (!master)
                return WorldLocation();

            float range = sPlayerbotAIConfig.followDistance;
            float angle = GetFollowAngle();
            float x = master->GetPositionX() + cos(angle) * range;
            float y = master->GetPositionY() + sin(angle) * range;
            float z = master->GetPositionZ();
            float ground = master->GetMap()->GetHeight(x, y, z + 0.5f);
            if (ground <= INVALID_HEIGHT)
                return Formation::NullLocation;

            return WorldLocation(master->GetMapId(), x, y, ground + 0.5f);
        }

        virtual float GetMaxDistance() { return sPlayerbotAIConfig.followDistance; }
    };


    class ChaosFormation : public MoveFormation
    {
    public:
        ChaosFormation(PlayerbotAI* ai) : MoveFormation(ai, "chaos") {}
        virtual WorldLocation GetLocation()
        {
            Player* master = GetMaster();
            if (!master)
                return WorldLocation();

            float range = sPlayerbotAIConfig.lootDistance * (float)(rand() % 10) / 10;
			float angle = GetFollowAngle();
            float x = master->GetPositionX() + cos(angle) * range;
            float y = master->GetPositionY() + sin(angle) * range;
            float z = master->GetPositionZ();
            float ground = master->GetMap()->GetHeight(x, y, z + 0.5f);
            if (ground <= INVALID_HEIGHT)
                return Formation::NullLocation;

            return WorldLocation(master->GetMapId(), x, y, ground + 0.5f);
        }

        virtual float GetMaxDistance() { return sPlayerbotAIConfig.lootDistance; }
    };

    class CircleFormation : public MoveFormation
    {
    public:
        CircleFormation(PlayerbotAI* ai) : MoveFormation(ai, "circle") {}
        virtual WorldLocation GetLocation()
        {
            float range = 2.0f;

            Unit* target = AI_VALUE(Unit*, "current target");
            Player* master = GetMaster();
            if (!target)
                target = master;

            if (!target)
				return Formation::NullLocation;

            switch (bot->getClass())
            {
            case CLASS_HUNTER:
            case CLASS_MAGE:
            case CLASS_PRIEST:
            case CLASS_WARLOCK:
                range = sPlayerbotAIConfig.fleeDistance;
                break;
            case CLASS_DRUID:
                if (!ai->IsTank(bot))
                    range = sPlayerbotAIConfig.fleeDistance;
                break;
            case CLASS_SHAMAN:
                if (ai->IsHeal(bot))
                    range = sPlayerbotAIConfig.fleeDistance;
                break;
            }

            float x = target->GetPositionX();
            float y = target->GetPositionY();
            float z = target->GetPositionZ();
            float ground = target->GetMap()->GetHeight(x, y, z + 0.5f);
            if (ground <= INVALID_HEIGHT)
                return Formation::NullLocation;

            float angle = GetFollowAngle();
            return WorldLocation(bot->GetMapId(), x + cos(angle) * range, y + sin(angle) * range, ground + 0.5f);
        }
    };

    class LineFormation : public MoveFormation
    {
    public:
        LineFormation(PlayerbotAI* ai) : MoveFormation(ai, "line") {}
        virtual WorldLocation GetLocation()
        {
            Group* group = bot->GetGroup();
            if (!group)
                return Formation::NullLocation;

            float range = 2.0f;

            Player* master = GetMaster();
            if (!master)
                return Formation::NullLocation;

            float x = master->GetPositionX();
            float y = master->GetPositionY();
            float z = master->GetPositionZ();
            float orientation = master->GetOrientation();

            vector<Player*> players;
            GroupReference *gref = group->GetFirstMember();
            while( gref )
            {
                Player* member = gref->GetSource();
                if (member != master)
                    players.push_back(member);

                gref = gref->next();
            }

            players.insert(players.begin() + group->GetMembersCount() / 2, master);

            return MoveLine(players, 0.0f, x, y, z, orientation, range);
        }
    };

    class ShieldFormation : public MoveFormation
    {
    public:
        ShieldFormation(PlayerbotAI* ai) : MoveFormation(ai, "shield") {}
        virtual WorldLocation GetLocation()
        {
            Group* group = bot->GetGroup();
            if (!group)
                return Formation::NullLocation;

            float range = sPlayerbotAIConfig.followDistance;

            Player* master = GetMaster();
            if (!master)
                return Formation::NullLocation;

            float x = master->GetPositionX();
            float y = master->GetPositionY();
            float z = master->GetPositionZ();
            float orientation = master->GetOrientation();

            vector<Player*> tanks;
            vector<Player*> dps;
            GroupReference *gref = group->GetFirstMember();
            while( gref )
            {
                Player* member = gref->GetSource();
                if (member != master)
                {
                    if (ai->IsTank(member))
                        tanks.push_back(member);
                    else
                        dps.push_back(member);
                }

                gref = gref->next();
            }

            if (ai->IsTank(master))
                tanks.insert(tanks.begin() + (tanks.size() + 1) / 2, master);
            else
                dps.insert(dps.begin() + (dps.size() + 1) / 2, master);

            if (ai->IsTank(bot) && ai->IsTank(master))
            {
                return MoveLine(tanks, 0.0f, x, y, z, orientation, range);
            }
            if (!ai->IsTank(bot) && !ai->IsTank(master))
            {
                return MoveLine(dps, 0.0f, x, y, z, orientation, range);
            }
            if (ai->IsTank(bot) && !ai->IsTank(master))
            {
                float diff = tanks.size() % 2 == 0 ? -sPlayerbotAIConfig.tooCloseDistance / 2.0f : 0.0f;
                return MoveLine(tanks, diff, x + cos(orientation) * range, y + sin(orientation) * range, z, orientation, range);
            }
            if (!ai->IsTank(bot) && ai->IsTank(master))
            {
                float diff = dps.size() % 2 == 0 ? -sPlayerbotAIConfig.tooCloseDistance / 2.0f : 0.0f;
                return MoveLine(dps, diff, x - cos(orientation) * range, y - sin(orientation) * range, z, orientation, range);
            }
            return Formation::NullLocation;
        }
    };
};

float Formation::GetFollowAngle()
{
    Player* master = GetMaster();
    Group* group = master ? master->GetGroup() : bot->GetGroup();
    if (!group)
        return 0.0f;

    int index = 1;
    for (GroupReference *ref = group->GetFirstMember(); ref; ref = ref->next())
    {
        if( ref->GetSource() == master)
            continue;

        if( ref->GetSource() == bot)
            return 2 * M_PI / (group->GetMembersCount() -1) * index;

        index++;
    }
    return 0;
}

FormationValue::FormationValue(PlayerbotAI* ai) : ManualSetValue<Formation*>(ai, new NearFormation(ai), "formation")
{
}

bool SetFormationAction::Execute(Event event)
{
    string formation = event.getParam();

	Value<Formation*>* value = context->GetValue<Formation*>("formation");
    if (formation == "?" || formation.empty())
    {
        ostringstream str; str << "Formation: |cff00ff00" << value->Get()->getName();
        ai->TellMaster(str);
        return true;
    }

    if (formation == "melee")
    {
        if (value->Get()) delete value->Get();
        value->Set(new MeleeFormation(ai));
    }
    else if (formation == "queue")
    {
        if (value->Get()) delete value->Get();
        value->Set(new QueueFormation(ai));
    }
    else if (formation == "chaos")
    {
        if (value->Get()) delete value->Get();
        value->Set(new ChaosFormation(ai));
    }
    else if (formation == "circle")
    {
        if (value->Get()) delete value->Get();
        value->Set(new CircleFormation(ai));
    }
    else if (formation == "line")
    {
        if (value->Get()) delete value->Get();
        value->Set(new LineFormation(ai));
    }
    else if (formation == "shield")
    {
        if (value->Get()) delete value->Get();
        value->Set(new ShieldFormation(ai));
    }
    else if (formation == "arrow")
    {
        if (value->Get()) delete value->Get();
        value->Set(new ArrowFormation(ai));
    }
    else if (formation == "near" || formation == "default")
    {
        if (value->Get()) delete value->Get();
        value->Set(new NearFormation(ai));
    }
    else
    {
        ostringstream str; str << "Invalid formation: |cffff0000" << formation;
        ai->TellMaster(str);
        ai->TellMaster("Please set to any of:|cffffffff melee (default), queue, chaos, circle, line, shield, arrow, near");
        return false;
    }

    ostringstream str; str << "Formation set to: " << formation;
    ai->TellMaster(str);
    return true;
}


WorldLocation MoveFormation::MoveLine(vector<Player*> line, float diff, float cx, float cy, float cz, float orientation, float range)
{
    if (line.size() < 5)
    {
        return MoveSingleLine(line, diff, cx, cy, cz, orientation, range);
    }

    int lines = ceil((double)line.size() / 5.0);
    for (int i = 0; i < lines; i++)
    {
        float radius = range * i;
        float x = cx + cos(orientation) * radius;
        float y = cy + sin(orientation) * radius;
        vector<Player*> singleLine;
        for (int j = 0; j < 5 && !line.empty(); j++)
        {
            singleLine.push_back(line[line.size() - 1]);
            line.pop_back();
        }

        WorldLocation loc = MoveSingleLine(singleLine, diff, x, y,cz, orientation, range);
        if (loc != Formation::NullLocation)
            return loc;
    }

    return Formation::NullLocation;
}

WorldLocation MoveFormation::MoveSingleLine(vector<Player*> line, float diff, float cx, float cy, float cz, float orientation, float range)
{
    float count = line.size();
    float angle = orientation - M_PI / 2.0f;
    float x = cx + cos(angle) * (range * floor(count / 2.0f) + diff);
    float y = cy + sin(angle) * (range * floor(count / 2.0f) + diff);

    int index = 0;
    for (vector<Player*>::iterator i = line.begin(); i != line.end(); i++)
    {
        Player* member = *i;

        if (member == bot)
        {
            float angle = orientation + M_PI / 2.0f;
            float radius = range * index;

            float lx = x + cos(angle) * radius;
            float ly = y + sin(angle) * radius;
            float lz = cz;
            float ground = bot->GetMap()->GetHeight(lx, ly, lz + 0.5f);
            if (ground <= INVALID_HEIGHT)
                return Formation::NullLocation;

            return WorldLocation(bot->GetMapId(), lx, ly, ground + 0.5f);
        }

        index++;
    }

    return Formation::NullLocation;
}
