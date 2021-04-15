-- SpawnGroupMapper auto-generated SQL for map 616 (The Eye of Eternity)

-- Constant setter section - adjust this
-- spawn_group_template (1 entries)
SET @FIRSTGROUPID := 14;
-- Boss state associations
SET @MALYGOS := 0; -- boss state that controls group "Malygos"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "The Eye of Eternity - Malygos", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 132313);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 616;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (616,@MALYGOS,0x17,@FIRSTGROUPID+0,0x1); -- Spawn Malygos if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+0 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
