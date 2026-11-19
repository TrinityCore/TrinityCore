-- SpawnGroupMapper auto-generated SQL for map 543 (Hellfire Citadel: Ramparts)

-- Constant setter section - adjust this
-- spawn_group_template (4 entries)
SET @FIRSTGROUPID := 48;
-- Boss state associations
SET @WATCHKEEPERGARGOLMAR := 0; -- boss state that controls group "Watchkeeper Gargolmar"
SET @OMORTHEUNSCARRED := 1; -- boss state that controls group "Omor the Unscarred"
SET @VAZRUDEN := 2; -- boss state that controls group "Vazruden & Nazan"
SET @NAZAN := 3; -- boss state that controls group "Vazruden & Nazan"

-- DB modification section - you shouldn't need to touch this
-- Insert spawn group templates
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
    (@FIRSTGROUPID+0, "Hellfire Citadel: Ramparts - Watchkeeper Gargolmar", 0x04),
    (@FIRSTGROUPID+1, "Hellfire Citadel: Ramparts - Final boss trash", 0x04),
    (@FIRSTGROUPID+2, "Hellfire Citadel: Ramparts - Omor the Unscarred", 0x04),
    (@FIRSTGROUPID+3, "Hellfire Citadel: Ramparts - Vazruden & Nazan", 0x04);

-- Insert spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
    (@FIRSTGROUPID+0, 0, 202634),
    (@FIRSTGROUPID+1, 0, 202650),
    (@FIRSTGROUPID+1, 0, 202666),
    (@FIRSTGROUPID+0, 0, 202682),
    (@FIRSTGROUPID+1, 0, 202698),
    (@FIRSTGROUPID+0, 0, 202619),
    (@FIRSTGROUPID+0, 0, 202635),
    (@FIRSTGROUPID+1, 0, 202651),
    (@FIRSTGROUPID+0, 0, 202667),
    (@FIRSTGROUPID+1, 0, 202683),
    (@FIRSTGROUPID+1, 0, 202699),
    (@FIRSTGROUPID+1, 0, 202620),
    (@FIRSTGROUPID+0, 0, 202636),
    (@FIRSTGROUPID+1, 0, 202652),
    (@FIRSTGROUPID+1, 0, 202668),
    (@FIRSTGROUPID+0, 0, 202684),
    (@FIRSTGROUPID+1, 0, 202700),
    (@FIRSTGROUPID+0, 0, 202621),
    (@FIRSTGROUPID+0, 0, 202637),
    (@FIRSTGROUPID+1, 0, 202653),
    (@FIRSTGROUPID+1, 0, 202669),
    (@FIRSTGROUPID+1, 0, 202685),
    (@FIRSTGROUPID+1, 0, 202701),
    (@FIRSTGROUPID+0, 0, 202622),
    (@FIRSTGROUPID+0, 0, 202638),
    (@FIRSTGROUPID+0, 0, 202654),
    (@FIRSTGROUPID+0, 0, 202670),
    (@FIRSTGROUPID+1, 0, 202686),
    (@FIRSTGROUPID+0, 0, 202702),
    (@FIRSTGROUPID+0, 0, 202607),
    (@FIRSTGROUPID+1, 0, 202623),
    (@FIRSTGROUPID+0, 0, 202639),
    (@FIRSTGROUPID+0, 0, 202655),
    (@FIRSTGROUPID+0, 0, 202671),
    (@FIRSTGROUPID+1, 0, 202687),
    (@FIRSTGROUPID+0, 0, 202703),
    (@FIRSTGROUPID+1, 0, 202608),
    (@FIRSTGROUPID+1, 0, 202624),
    (@FIRSTGROUPID+0, 0, 202640),
    (@FIRSTGROUPID+0, 0, 202656),
    (@FIRSTGROUPID+0, 0, 202672),
    (@FIRSTGROUPID+1, 0, 202688),
    (@FIRSTGROUPID+0, 0, 202704),
    (@FIRSTGROUPID+1, 0, 202609),
    (@FIRSTGROUPID+0, 0, 202625),
    (@FIRSTGROUPID+0, 0, 202641),
    (@FIRSTGROUPID+0, 0, 202657),
    (@FIRSTGROUPID+0, 0, 202673),
    (@FIRSTGROUPID+1, 0, 202689),
    (@FIRSTGROUPID+3, 0, 202705),
    (@FIRSTGROUPID+0, 0, 202610),
    (@FIRSTGROUPID+0, 0, 202626),
    (@FIRSTGROUPID+1, 0, 202642),
    (@FIRSTGROUPID+0, 0, 202658),
    (@FIRSTGROUPID+0, 0, 202674),
    (@FIRSTGROUPID+1, 0, 202690),
    (@FIRSTGROUPID+3, 0, 202706),
    (@FIRSTGROUPID+0, 0, 202611),
    (@FIRSTGROUPID+0, 0, 202627),
    (@FIRSTGROUPID+1, 0, 202643),
    (@FIRSTGROUPID+0, 0, 202659),
    (@FIRSTGROUPID+0, 0, 202675),
    (@FIRSTGROUPID+0, 0, 202691),
    (@FIRSTGROUPID+0, 0, 202612),
    (@FIRSTGROUPID+0, 0, 202628),
    (@FIRSTGROUPID+1, 0, 202644),
    (@FIRSTGROUPID+0, 0, 202660),
    (@FIRSTGROUPID+0, 0, 202676),
    (@FIRSTGROUPID+0, 0, 202692),
    (@FIRSTGROUPID+0, 0, 202613),
    (@FIRSTGROUPID+0, 0, 202629),
    (@FIRSTGROUPID+0, 0, 202645),
    (@FIRSTGROUPID+1, 0, 202661),
    (@FIRSTGROUPID+0, 0, 202677),
    (@FIRSTGROUPID+3, 0, 202693),
    (@FIRSTGROUPID+1, 0, 202614),
    (@FIRSTGROUPID+1, 0, 202630),
    (@FIRSTGROUPID+0, 0, 202646),
    (@FIRSTGROUPID+1, 0, 202662),
    (@FIRSTGROUPID+0, 0, 202678),
    (@FIRSTGROUPID+2, 0, 202694),
    (@FIRSTGROUPID+1, 0, 202615),
    (@FIRSTGROUPID+0, 0, 202631),
    (@FIRSTGROUPID+0, 0, 202647),
    (@FIRSTGROUPID+0, 0, 202663),
    (@FIRSTGROUPID+0, 0, 202679),
    (@FIRSTGROUPID+0, 0, 202695),
    (@FIRSTGROUPID+1, 0, 202616),
    (@FIRSTGROUPID+2, 0, 202632),
    (@FIRSTGROUPID+0, 0, 202648),
    (@FIRSTGROUPID+0, 0, 202664),
    (@FIRSTGROUPID+0, 0, 202680),
    (@FIRSTGROUPID+0, 0, 202696),
    (@FIRSTGROUPID+0, 0, 202617),
    (@FIRSTGROUPID+2, 0, 202633),
    (@FIRSTGROUPID+0, 0, 202649),
    (@FIRSTGROUPID+0, 0, 202665),
    (@FIRSTGROUPID+0, 0, 202681),
    (@FIRSTGROUPID+0, 0, 202697),
    (@FIRSTGROUPID+0, 0, 202618);

-- Link information for instance script
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 543;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
    (543,@WATCHKEEPERGARGOLMAR,0x17,@FIRSTGROUPID+0,0x1), -- Spawn Watchkeeper Gargolmar if state is not DONE
    (543,@OMORTHEUNSCARRED,0x17,@FIRSTGROUPID+1,0x1), -- Spawn Final boss trash if state is not DONE
    (543,@VAZRUDEN,0x08,@FIRSTGROUPID+1,0x2), -- Do not spawn Final boss trash if state is DONE
    (543,@NAZAN,0x08,@FIRSTGROUPID+1,0x2), -- Do not spawn Final boss trash if state is DONE
    (543,@OMORTHEUNSCARRED,0x17,@FIRSTGROUPID+2,0x1), -- Spawn Omor the Unscarred if state is not DONE
    (543,@VAZRUDEN,0x17,@FIRSTGROUPID+3,0x1), -- Spawn Vazruden & Nazan if state is not DONE
    (543,@NAZAN,0x08,@FIRSTGROUPID+3,0x2); -- Do not spawn Vazruden & Nazan if state is DONE

-- Remove legacy linked_respawn entries
DELETE lr FROM `linked_respawn` lr INNER JOIN `spawn_group` sg ON sg.`groupId` BETWEEN @FIRSTGROUPID+0 AND @FIRSTGROUPID+3 AND sg.`spawnType` = (lr.linkType >> 1) AND sg.`spawnId`=lr.`guid`;
