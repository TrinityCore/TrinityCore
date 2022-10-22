DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 232 AND 237;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(232,'The Sunwell - Kalecgos',4),
(233,'The Sunwell - Brutallus',4),
(234,'The Sunwell - Felmyst',4),
(235,'The Sunwell - Eredar Twins',4),
(236,'The Sunwell - M''uru',4),
(237,'The Sunwell - Kil''jaeden',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 232 AND 237;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(580,0,23,232,1),
(580,1,23,233,1),
(580,1,23,234,2), -- dont spawn felmyst before brutallus is dead
(580,2,23,234,1),
(580,3,23,235,1),
(580,4,23,236,1),
(580,5,23,237,1);

DELETE FROM `creature` WHERE `guid`=55421 AND `id`=25038;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(55421, 25038, 580, 4075, 4140, 1, 1, 0, 0, 1460.2911376953125, 628.89984130859375, 46.09189605712890625, 5.281038284301757812, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Felmyst (Area: The Dead Scar - Difficulty: 4) (Auras: 45068 - Felblaze Visual)

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 232 AND 237;
INSERT INTO `spawn_group` SELECT 232, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=54810 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 233, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=54811 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 235, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=53668 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 236, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=53705 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 237, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=56332 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(232,0,54810),
(232,0,53645),
(233,0,54811),
(233,0,54812),
(234,0,55421),
(235,0,53668),
(235,0,53687),
(236,0,53705),
(237,0,56332);

UPDATE `creature_template` SET `flags_extra`=`flags_extra` & ~0x80 WHERE `entry`=25038; -- remove trigger flag from felmyst

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (54810,54811,55421,53668,53705,56332);
