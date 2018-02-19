-- SpawnGroupMapper auto-generated SQL for map 724 (The Ruby Sanctum)

-- Constant setter section - adjust this
-- spawn_group_template (4 entries)
SET @FIRSTGROUPID := 19;
-- Boss state associations
SET @BALTHARUS := 0; -- boss state that controls group "Baltharus"
SET @SAVIANA := 2; -- boss state that controls group "Saviana"
SET @ZARITHRIAN := 1; -- boss state that controls group "Zarithrian"
SET @HALION := 3; -- boss state that controls group "Halion"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "The Ruby Sanctum - Baltharus", 0x04),
    (@FIRSTGROUPID+1, "The Ruby Sanctum - Saviana", 0x04),
    (@FIRSTGROUPID+2, "The Ruby Sanctum - Zarithrian", 0x04),
    (@FIRSTGROUPID+3, "The Ruby Sanctum - Halion", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+2, 0, 202812),
    (@FIRSTGROUPID+2, 0, 202820),
    (@FIRSTGROUPID+3, 0, 11003),
    (@FIRSTGROUPID+2, 0, 202805),
    (@FIRSTGROUPID+2, 0, 202813),
    (@FIRSTGROUPID+2, 0, 202821),
    (@FIRSTGROUPID+2, 0, 202806),
    (@FIRSTGROUPID+2, 0, 202822),
    (@FIRSTGROUPID+2, 0, 202807),
    (@FIRSTGROUPID+2, 0, 202815),
    (@FIRSTGROUPID+2, 0, 202823),
    (@FIRSTGROUPID+2, 0, 202800),
    (@FIRSTGROUPID+2, 0, 202808),
    (@FIRSTGROUPID+2, 0, 202816),
    (@FIRSTGROUPID+2, 0, 202824),
    (@FIRSTGROUPID+2, 0, 202801),
    (@FIRSTGROUPID+2, 0, 202809),
    (@FIRSTGROUPID+2, 0, 202817),
    (@FIRSTGROUPID+2, 0, 202794),
    (@FIRSTGROUPID+2, 0, 202802),
    (@FIRSTGROUPID+2, 0, 202810),
    (@FIRSTGROUPID+2, 0, 202818),
    (@FIRSTGROUPID+1, 0, 202795),
    (@FIRSTGROUPID+2, 0, 202803),
    (@FIRSTGROUPID+2, 0, 202811),
    (@FIRSTGROUPID+2, 0, 202819),
    (@FIRSTGROUPID+2, 0, 202814),
    (@FIRSTGROUPID+2, 0, 202799),
    (@FIRSTGROUPID+0, 0, 202796),
    (@FIRSTGROUPID+2, 0, 202804);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 724;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (724,@BALTHARUS,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Baltharus if state is not DONE
    (724,@SAVIANA,0x17,@FIRSTGROUPID+1,0x1), -- Spawn Saviana if state is not DONE
    (724,@ZARITHRIAN,0x17,@FIRSTGROUPID+2,0x1), -- Spawn Zarithrian if state is not DONE
    (724,@HALION,0x17,@FIRSTGROUPID+3,0x1); -- Spawn Halion if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
