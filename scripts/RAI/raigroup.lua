local RaiGroup = {}

function RaiGroup:new()
  --[[
    OVERVIEW

    PrepareCreatureGroup()

    SetCreatureData()
    StartPatrolling()
    GUIDPartOfGroupMembers()
    IsLeaderAlive()
    PickLeader()
    OnGroupMemberEnterCombat()

    GetGroupMembers()
    GetLeader()
  --]]  

  --[[
    PrepareCreatureGroupData()
    @desc Sets up the internal data for the group for every group member
    @creatures The members the group consists of
  --]]
  function RaiGroup:PrepareCreatureGroup(creatures)
    local leader = creatures[math.random(1, #creatures)]

    for k, creature in ipairs(creatures) do
      RaiGroup:SetCreatureData(creature, creatures, leader)
    end

    RaiGroup:StartPatrolling(creatures[1])
  end

  --[[
    SetCreatureData

    @desc Sets the creature data for the group
    @creature The creature to set the data on
    @members The group members (including leader)
    @leader The group leader
  --]]
  function RaiGroup:SetCreatureData(creature, members, leader)
    local groupInfo = {}
    groupInfo["members"] = {}
    groupInfo["leader"] = leader:GetGUID()

    for k, member in ipairs(members) do 
      table.insert(groupInfo["members"], member:GetGUID())
    end

    creature:SetData("groupInfo", groupInfo)
  end

  --[[
    StartPatrolling
    @desc Makes the group start patrolling
    @creature One creature with group data
  --]]
  function RaiGroup:StartPatrolling(creature)
    local groupInfo = creature:GetData("groupInfo")
    if not groupInfo then return end

    local members = creature:GetCreaturesInRange(70, creature:GetEntry())

    local leader = creature
    leader:SetWalk(true)
    leader:MoveRandom(600)

    for k, v in ipairs(members) do 
      if RaiGroup:GUIDPartOfGroupMembers(v:GetGUID(), groupInfo) then 
        if k == 1 then 
          v:MoveFollow(leader, -5)
        else
          v:MoveFollow(members[k-1])
        end

        v:SetWalk(true)
        v:ClearUnitState(4194304)
      end
    end
  end

  --[[
    GUIDPartOfGroupMembers()
    @desc Returns whether or not the guid is part of the group data
    @guid The guid to check for
    @groupInfo The groupinfo table from a creature
    @return true or false
  --]]

  function RaiGroup:GUIDPartOfGroupMembers(guid, groupInfo)
    for k, realMemberGUID in ipairs(groupInfo["members"]) do 
      if guid == realMemberGUID then 
        return true
      end
    end

    return false
  end

  --[[
    IsLeaderAlive()
    @desc Returns whether or not the leader in the group is alive
    @creature The creature to check for
    @groupInfo the group info table from a creature
    @return true or false
  --]]
  function RaiGroup:IsLeaderAlive(creature, groupInfo)
    local members = creature:GetCreaturesInRange(40, creature:GetEntry())

     for k, member in ipairs(members) do 
      if member:GetGUID() == groupInfo["leader"] then 
        return true
      end
    end

    return false
  end

  --[[
    PickLeader()
    @desc Picks the leader for the group
    @creature The creature which we use for getting nearby creatures
    @groupInfo The group table info
    @leader The new leader of the group
  --]]

  function RaiGroup:PickLeader(creature, groupInfo, leader)
    local realMembers = RaiGroup:GetGroupMembers(creature, groupInfo)

    for k, member in ipairs(realMembers) do 
      RaiGroup:SetCreatureData(member, realMembers, leader)
    end
  end

  --[[
    OnGroupMemberEnterCombat()
    @desc Called when a group member enters combat
    @creature The creature that entered combat
    @return nothing
  --]]
  function RaiGroup:OnGroupMemberEnterCombat(creature)
    local members = RaiGroup:GetGroupMembers(creature, creature:GetData("groupInfo"))
    local leader = RaiGroup:GetLeader(creature, creature:GetData("groupInfo"))

    if leader == nil then 
      leader = creature
    end

    for k, member in ipairs(members) do 
      local victim = creature:GetVictim()
      member:SetHomePosition(leader:GetX(), leader:GetY(), leader:GetZ(), leader:GetO())

      if victim then 
        member:AddThreat(victim, 100)
        member:AttackStart(creature:GetVictim())
      end
    end
  end

  --[[
    GetGroupMembers()
    @desc Gets all group members
    @creature The creature which we fetch members from
    @groupInfo the groupInfo
    @return A table consisting of Creature group members
  --]]
  function RaiGroup:GetGroupMembers(creature, groupInfo)
    local members = creature:GetCreaturesInRange(40, creature:GetEntry())
    local realMembers = {}
    for k, member in ipairs(members) do 
      if RaiGroup:GUIDPartOfGroupMembers(member:GetGUID(), groupInfo) then 
        table.insert(realMembers, member)
      end
    end

    return realMembers
  end

  --[[
    GetLeader()
    @desc Gets the group leader
    @creature The creature which we fetch the leader from
    @groupInfo the groupInfo
    @return the leader or nil
  --]]
  function RaiGroup:GetLeader(creature, groupInfo)
    local creatures = creature:GetCreaturesInRange(70, creature:GetEntry())
    local leader = nil
    for k, cr in ipairs(creatures) do 
      if cr:GetGUID() == groupInfo["leader"] then 
        leader = cr
      end
    end

    return leader
  end

  return RaiGroup
end

return RaiGroup