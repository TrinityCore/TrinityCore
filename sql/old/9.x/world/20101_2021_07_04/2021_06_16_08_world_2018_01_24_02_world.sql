-- SpawnGroupMapper auto-generated SQL for map 604 (Gundrak)

-- Constant setter section - adjust this
-- spawn_group_template (5 entries)
SET @FIRSTGROUPID := 32;
-- Boss state associations
SET @SLADRAN := 0; -- boss state that controls group "Slad'ran"
SET @DRAKKARICOLOSSUS := 1; -- boss state that controls group "Drakkari Colossus"
SET @MOORABI := 2; -- boss state that controls group "Moorabi"
SET @GALDARAH := 3; -- boss state that controls group "Gal'darah"
SET @ECKTHEFEROCIOUS := 4; -- boss state that controls group "Eck the Ferocious"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+4;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Gundrak - Slad'ran", 0x04),
    (@FIRSTGROUPID+1, "Gundrak - Drakkari Colossus", 0x04),
    (@FIRSTGROUPID+2, "Gundrak - Moorabi", 0x04),
    (@FIRSTGROUPID+3, "Gundrak - Gal'darah", 0x04),
    (@FIRSTGROUPID+4, "Gundrak - Eck the Ferocious", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+4;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 127019),
    (@FIRSTGROUPID+2, 0, 127051),
    (@FIRSTGROUPID+2, 0, 127067),
    (@FIRSTGROUPID+0, 0, 127020),
    (@FIRSTGROUPID+2, 0, 127052),
    (@FIRSTGROUPID+2, 0, 127068),
    (@FIRSTGROUPID+0, 0, 127021),
    (@FIRSTGROUPID+2, 0, 127053),
    (@FIRSTGROUPID+2, 0, 127069),
    (@FIRSTGROUPID+0, 0, 127006),
    (@FIRSTGROUPID+0, 0, 127022),
    (@FIRSTGROUPID+2, 0, 127054),
    (@FIRSTGROUPID+2, 0, 127070),
    (@FIRSTGROUPID+0, 0, 127007),
    (@FIRSTGROUPID+0, 0, 127023),
    (@FIRSTGROUPID+2, 0, 127055),
    (@FIRSTGROUPID+1, 0, 127071),
    (@FIRSTGROUPID+0, 0, 127008),
    (@FIRSTGROUPID+0, 0, 127024),
    (@FIRSTGROUPID+2, 0, 127056),
    (@FIRSTGROUPID+1, 0, 127072),
    (@FIRSTGROUPID+0, 0, 127009),
    (@FIRSTGROUPID+0, 0, 127025),
    (@FIRSTGROUPID+2, 0, 127057),
    (@FIRSTGROUPID+1, 0, 127073),
    (@FIRSTGROUPID+4, 0, 127201),
    (@FIRSTGROUPID+0, 0, 127010),
    (@FIRSTGROUPID+0, 0, 127026),
    (@FIRSTGROUPID+0, 0, 127042),
    (@FIRSTGROUPID+0, 0, 127058),
    (@FIRSTGROUPID+1, 0, 127074),
    (@FIRSTGROUPID+4, 0, 127202),
    (@FIRSTGROUPID+0, 0, 127011),
    (@FIRSTGROUPID+0, 0, 127027),
    (@FIRSTGROUPID+2, 0, 127043),
    (@FIRSTGROUPID+2, 0, 127059),
    (@FIRSTGROUPID+1, 0, 127075),
    (@FIRSTGROUPID+4, 0, 127203),
    (@FIRSTGROUPID+0, 0, 127012),
    (@FIRSTGROUPID+0, 0, 127028),
    (@FIRSTGROUPID+3, 0, 127044),
    (@FIRSTGROUPID+2, 0, 127060),
    (@FIRSTGROUPID+1, 0, 127076),
    (@FIRSTGROUPID+4, 0, 127204),
    (@FIRSTGROUPID+0, 0, 127013),
    (@FIRSTGROUPID+0, 0, 127029),
    (@FIRSTGROUPID+0, 0, 127045),
    (@FIRSTGROUPID+2, 0, 127061),
    (@FIRSTGROUPID+1, 0, 127077),
    (@FIRSTGROUPID+4, 0, 127205),
    (@FIRSTGROUPID+0, 0, 127014),
    (@FIRSTGROUPID+1, 0, 127046),
    (@FIRSTGROUPID+2, 0, 127062),
    (@FIRSTGROUPID+1, 0, 127078),
    (@FIRSTGROUPID+3, 0, 127110),
    (@FIRSTGROUPID+4, 0, 127206),
    (@FIRSTGROUPID+0, 0, 127015),
    (@FIRSTGROUPID+2, 0, 127047),
    (@FIRSTGROUPID+2, 0, 127063),
    (@FIRSTGROUPID+1, 0, 127079),
    (@FIRSTGROUPID+3, 0, 127111),
    (@FIRSTGROUPID+3, 0, 127207),
    (@FIRSTGROUPID+0, 0, 127016),
    (@FIRSTGROUPID+2, 0, 127048),
    (@FIRSTGROUPID+2, 0, 127064),
    (@FIRSTGROUPID+1, 0, 127080),
    (@FIRSTGROUPID+3, 0, 127112),
    (@FIRSTGROUPID+0, 0, 127017),
    (@FIRSTGROUPID+2, 0, 127049),
    (@FIRSTGROUPID+2, 0, 127065),
    (@FIRSTGROUPID+1, 0, 127081),
    (@FIRSTGROUPID+2, 0, 127113),
    (@FIRSTGROUPID+0, 0, 127018),
    (@FIRSTGROUPID+2, 0, 127050),
    (@FIRSTGROUPID+2, 0, 127066),
    (@FIRSTGROUPID+1, 0, 127082);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 604;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (604,@SLADRAN,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Slad'ran if state is not DONE
    (604,@DRAKKARICOLOSSUS,0x17,@FIRSTGROUPID+1,0x1), -- Spawn Drakkari Colossus if state is not DONE
    (604,@MOORABI,0x17,@FIRSTGROUPID+2,0x1), -- Spawn Moorabi if state is not DONE
    (604,@GALDARAH,0x17,@FIRSTGROUPID+3,0x1), -- Spawn Gal'darah if state is not DONE
    (604,@ECKTHEFEROCIOUS,0x17,@FIRSTGROUPID+4,0x1); -- Spawn Eck the Ferocious if state is not DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+4 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
