-- SpawnGroupMapper auto-generated SQL for map 565 (Gruul's Lair)

-- Constant setter section - adjust this
-- spawn_group_template (2 entries)
SET @FIRSTGROUPID := 11;
-- Boss state associations
SET @HIGHKINGMAULGAR := 0; -- boss state that controls group "High King Maulgar"
SET @GRUUL := 1; -- boss state that controls group "Gruul"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Gruul's Lair - High King Maulgar", 0x04),
    (@FIRSTGROUPID+1, "Gruul's Lair - Gruul", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+1, 0, 83206),
    (@FIRSTGROUPID+0, 0, 48348),
    (@FIRSTGROUPID+1, 0, 72432),
    (@FIRSTGROUPID+0, 0, 81643),
    (@FIRSTGROUPID+1, 0, 65618),
    (@FIRSTGROUPID+1, 0, 81647),
    (@FIRSTGROUPID+1, 0, 81649),
    (@FIRSTGROUPID+0, 0, 81651),
    (@FIRSTGROUPID+1, 0, 86065),
    (@FIRSTGROUPID+0, 0, 7483),
    (@FIRSTGROUPID+1, 0, 69871),
    (@FIRSTGROUPID+0, 0, 81642),
    (@FIRSTGROUPID+1, 0, 81644),
    (@FIRSTGROUPID+0, 0, 81646),
    (@FIRSTGROUPID+1, 0, 81648),
    (@FIRSTGROUPID+1, 0, 81650),
    (@FIRSTGROUPID+0, 0, 81652),
    (@FIRSTGROUPID+0, 0, 81645);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 565;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (565,@HIGHKINGMAULGAR,0x17,@FIRSTGROUPID+0,0x1), -- Spawn High King Maulgar if state is not DONE
    (565,@GRUUL,0x17,@FIRSTGROUPID+1,0x1); -- Spawn Gruul if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
