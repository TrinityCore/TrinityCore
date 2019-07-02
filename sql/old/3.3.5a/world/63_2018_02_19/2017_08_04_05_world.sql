-- SpawnGroupMapper auto-generated SQL for map 615 (The Obsidian Sanctum)

-- Constant setter section - adjust this
-- spawn_group_template (4 entries)
SET @FIRSTGROUPID := 15;
-- Boss state associations
SET @TENEBRON := 1; -- boss state that controls group "Tenebron"
SET @SHADRON := 2; -- boss state that controls group "Shadron"
SET @VESPERON := 3; -- boss state that controls group "Vesperon"
SET @SARTHARION := 0; -- boss state that controls group "Sartharion"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "The Obsidian Sanctum - Tenebron", 0x04),
    (@FIRSTGROUPID+1, "The Obsidian Sanctum - Shadron", 0x04),
    (@FIRSTGROUPID+2, "The Obsidian Sanctum - Vesperon", 0x04),
    (@FIRSTGROUPID+3, "The Obsidian Sanctum - Sartharion", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+3, 0, 126398),
    (@FIRSTGROUPID+1, 0, 126414),
    (@FIRSTGROUPID+3, 0, 126399),
    (@FIRSTGROUPID+0, 0, 126415),
    (@FIRSTGROUPID+3, 0, 126400),
    (@FIRSTGROUPID+3, 0, 126416),
    (@FIRSTGROUPID+3, 0, 126401),
    (@FIRSTGROUPID+3, 0, 126417),
    (@FIRSTGROUPID+3, 0, 126402),
    (@FIRSTGROUPID+3, 0, 126418),
    (@FIRSTGROUPID+3, 0, 126403),
    (@FIRSTGROUPID+3, 0, 126419),
    (@FIRSTGROUPID+3, 0, 126404),
    (@FIRSTGROUPID+3, 0, 126420),
    (@FIRSTGROUPID+3, 0, 126405),
    (@FIRSTGROUPID+3, 0, 126421),
    (@FIRSTGROUPID+3, 0, 126406),
    (@FIRSTGROUPID+3, 0, 126407),
    (@FIRSTGROUPID+3, 0, 126408),
    (@FIRSTGROUPID+3, 0, 126409),
    (@FIRSTGROUPID+3, 0, 126410),
    (@FIRSTGROUPID+3, 0, 126411),
    (@FIRSTGROUPID+3, 0, 126396),
    (@FIRSTGROUPID+3, 0, 126412),
    (@FIRSTGROUPID+3, 0, 126397),
    (@FIRSTGROUPID+2, 0, 126413);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 615;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (615,@TENEBRON,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Tenebron if state is not DONE
    (615,@SHADRON,0x17,@FIRSTGROUPID+1,0x1), -- Spawn Shadron if state is not DONE
    (615,@VESPERON,0x17,@FIRSTGROUPID+2,0x1), -- Spawn Vesperon if state is not DONE
    (615,@SARTHARION,0x17,@FIRSTGROUPID+3,0x1); -- Spawn Sartharion if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
