-- Necrolord Sipe (Area: Old Town)
DELETE FROM `creature` WHERE `guid`= 452603 AND `id`= 73190;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(452399, 73190, 0, 0, 0, 1, '0', 0, 0, 0, -8758.906, 385.1371, 101.1392, 0.6503221, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420);

DELETE FROM `creature_template_addon` WHERE `entry`= 73190;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`auras`) VALUES
(73190, 0, 51037, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `npc_vendor` WHERE `entry`=73190 AND `ExtendedCost`=5214 AND `type`=1 AND `item` IN (140353,140350,124089);
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`ExtendedCost`,`type`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) VALUES
(73190, 6, 140353, 0, 5214, 1, 0, 0, 23420), -- Vicious Gilnean Warhorse
(73190, 5, 140350, 0, 5214, 1, 0, 0, 23420), -- Vicious War Elekk
(73190, 4, 124089, 0, 5214, 1, 0, 0, 23420); -- Vicious War Mechanostrider

UPDATE `npc_vendor` SET `VerifiedBuild`=23420 WHERE `entry`=73190 AND `item` IN (
116777, -- Vicious War Ram
102514, -- Reins of the Vicious Warsaber
70909); -- Reins of the Vicious War Steed
