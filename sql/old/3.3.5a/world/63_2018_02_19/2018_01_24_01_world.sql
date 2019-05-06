-- SpawnGroupMapper auto-generated SQL for map 624 (Vault of Archavon)

-- Constant setter section - adjust this
-- spawn_group_template (4 entries)
SET @FIRSTGROUPID := 28;
-- Boss state associations
SET @ARCHAVON := 0; -- boss state that controls group "Archavon"
SET @EMALON := 1; -- boss state that controls group "Emalon"
SET @KORALON := 2; -- boss state that controls group "Koralon"
SET @TORAVON := 3; -- boss state that controls group "Toravon"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Vault of Archavon - Archavon", 0x04),
    (@FIRSTGROUPID+1, "Vault of Archavon - Emalon", 0x04),
    (@FIRSTGROUPID+2, "Vault of Archavon - Koralon", 0x04),
    (@FIRSTGROUPID+3, "Vault of Archavon - Toravon", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+2, 0, 202596),
    (@FIRSTGROUPID+2, 0, 202598),
    (@FIRSTGROUPID+3, 0, 202600),
    (@FIRSTGROUPID+0, 0, 202589),
    (@FIRSTGROUPID+0, 0, 202591),
    (@FIRSTGROUPID+1, 0, 202593),
    (@FIRSTGROUPID+1, 0, 202595),
    (@FIRSTGROUPID+2, 0, 202597),
    (@FIRSTGROUPID+3, 0, 202606),
    (@FIRSTGROUPID+0, 0, 202588),
    (@FIRSTGROUPID+0, 0, 202590),
    (@FIRSTGROUPID+1, 0, 202594),
    (@FIRSTGROUPID+3, 0, 202605);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 624;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (624,@ARCHAVON,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Archavon if state is not DONE
    (624,@EMALON,0x17,@FIRSTGROUPID+1,0x1), -- Spawn Emalon if state is not DONE
    (624,@KORALON,0x17,@FIRSTGROUPID+2,0x1), -- Spawn Koralon if state is not DONE
    (624,@TORAVON,0x17,@FIRSTGROUPID+3,0x1); -- Spawn Toravon if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
