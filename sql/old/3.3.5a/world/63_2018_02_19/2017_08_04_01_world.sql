-- SpawnGroupMapper auto-generated SQL for map 249 (Onyxia's Lair)

-- Constant setter section - adjust this
-- spawn_group_template (1 entries)
SET @FIRSTGROUPID := 10;
-- Boss state associations
SET @ONYXIA := 0; -- boss state that controls group "Onyxia"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Onyxia's Lair - Onyxia", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 52050),
    (@FIRSTGROUPID+0, 0, 52052),
    (@FIRSTGROUPID+0, 0, 52047),
    (@FIRSTGROUPID+0, 0, 52049),
    (@FIRSTGROUPID+0, 0, 52051),
    (@FIRSTGROUPID+0, 0, 52053),
    (@FIRSTGROUPID+0, 0, 52048),
    (@FIRSTGROUPID+0, 0, 47572);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 249;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (249,@ONYXIA,0x17,@FIRSTGROUPID+0,0x1); -- Spawn Onyxia if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
