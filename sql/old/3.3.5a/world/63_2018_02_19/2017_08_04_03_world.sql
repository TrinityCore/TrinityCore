-- SpawnGroupMapper auto-generated SQL for map 544 (Magtheridon's Lair)

-- Constant setter section - adjust this
-- spawn_group_template (1 entries)
SET @FIRSTGROUPID := 13;
-- Boss state associations
SET @MAGTHERIDON := 0; -- boss state that controls group "Magtheridon"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Magtheridon's Lair - Magtheridon", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 91247),
    (@FIRSTGROUPID+0, 0, 90988),
    (@FIRSTGROUPID+0, 0, 90992),
    (@FIRSTGROUPID+0, 0, 91248),
    (@FIRSTGROUPID+0, 0, 90985),
    (@FIRSTGROUPID+0, 0, 90989),
    (@FIRSTGROUPID+0, 0, 90993),
    (@FIRSTGROUPID+0, 0, 91249),
    (@FIRSTGROUPID+0, 0, 90986),
    (@FIRSTGROUPID+0, 0, 90990),
    (@FIRSTGROUPID+0, 0, 91254),
    (@FIRSTGROUPID+0, 0, 90987),
    (@FIRSTGROUPID+0, 0, 90991);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 544;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (544,@MAGTHERIDON,0x17,@FIRSTGROUPID+0,0x1); -- Spawn Magtheridon if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
