-- SpawnGroupMapper auto-generated SQL for map 632 (The Forge of Souls)

-- Constant setter section - adjust this
-- spawn_group_template (2 entries)
SET @FIRSTGROUPID := 37;
-- Boss state associations
SET @BRONJAHM := 0; -- boss state that controls group "Bronjahm"
SET @DEVOUREROFSOULS := 1; -- boss state that controls group "Devourer of Souls"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "The Forge of Souls - Bronjahm", 0x04),
    (@FIRSTGROUPID+1, "The Forge of Souls - Devourer of Souls", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 201698),
    (@FIRSTGROUPID+1, 0, 201714),
    (@FIRSTGROUPID+0, 0, 201762),
    (@FIRSTGROUPID+0, 0, 201699),
    (@FIRSTGROUPID+0, 0, 201763),
    (@FIRSTGROUPID+1, 0, 201700),
    (@FIRSTGROUPID+1, 0, 201732),
    (@FIRSTGROUPID+1, 0, 201748),
    (@FIRSTGROUPID+0, 0, 201764),
    (@FIRSTGROUPID+1, 0, 201796),
    (@FIRSTGROUPID+0, 0, 201733),
    (@FIRSTGROUPID+0, 0, 201749),
    (@FIRSTGROUPID+0, 0, 201686),
    (@FIRSTGROUPID+0, 0, 201734),
    (@FIRSTGROUPID+0, 0, 201766),
    (@FIRSTGROUPID+1, 0, 201687),
    (@FIRSTGROUPID+0, 0, 201719),
    (@FIRSTGROUPID+0, 0, 201735),
    (@FIRSTGROUPID+0, 0, 201751),
    (@FIRSTGROUPID+0, 0, 201783),
    (@FIRSTGROUPID+0, 0, 201688),
    (@FIRSTGROUPID+1, 0, 201736),
    (@FIRSTGROUPID+0, 0, 201705),
    (@FIRSTGROUPID+1, 0, 201737),
    (@FIRSTGROUPID+0, 0, 201753),
    (@FIRSTGROUPID+0, 0, 201706),
    (@FIRSTGROUPID+0, 0, 201786),
    (@FIRSTGROUPID+0, 0, 201707),
    (@FIRSTGROUPID+0, 0, 201676),
    (@FIRSTGROUPID+0, 0, 201677),
    (@FIRSTGROUPID+0, 0, 201693),
    (@FIRSTGROUPID+0, 0, 201725),
    (@FIRSTGROUPID+1, 0, 201757),
    (@FIRSTGROUPID+0, 0, 201678),
    (@FIRSTGROUPID+0, 0, 201726),
    (@FIRSTGROUPID+0, 0, 201742),
    (@FIRSTGROUPID+0, 0, 201758),
    (@FIRSTGROUPID+1, 0, 201790),
    (@FIRSTGROUPID+0, 0, 201695),
    (@FIRSTGROUPID+0, 0, 201711),
    (@FIRSTGROUPID+0, 0, 201791),
    (@FIRSTGROUPID+0, 0, 201712),
    (@FIRSTGROUPID+0, 0, 201776),
    (@FIRSTGROUPID+0, 0, 201792),
    (@FIRSTGROUPID+0, 0, 201697),
    (@FIRSTGROUPID+0, 0, 201713);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 632;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (632,@BRONJAHM,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Bronjahm if state is not DONE
    (632,@DEVOUREROFSOULS,0x17,@FIRSTGROUPID+1,0x1); -- Spawn Devourer of Souls if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+1 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
