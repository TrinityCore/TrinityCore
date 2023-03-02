-- 
-- Updated Ironforge: Honor Guard Dunstad
UPDATE `creature` SET `position_x`= -4821.111,`position_y`= -970.1805,`position_z`=464.7921,`orientation`= 1.269122 WHERE `guid`=307462;

-- Advisor Belgrum
UPDATE `creature_template` SET `gossip_menu_id`=12794 WHERE `entry`=2918;
DELETE FROM `gossip_menu` WHERE  `MenuId`=12794 AND `TextId`=17982;
INSERT INTO `gossip_menu` (`MenuId`,`TextId`,`VerifiedBuild`) VALUES (12794, 17982, 25996);

DELETE FROM `npc_text` WHERE  `ID`=17982;
INSERT INTO `npc_text` (`ID`,`Probability0`,`BroadcastTextID0`) VALUES (17982, 1, 51469);

-- Corin Twinbellows
UPDATE `creature_template` SET `minlevel`= 110,`maxlevel`=110,`faction`=122,`BaseAttackTime`=2000,`RangeAttackTime`=2000,`unit_flags2`=2048 WHERE `entry`=118889;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=74943;

DELETE FROM `creature_template_addon` WHERE `entry`=118889;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (118889, 235614);

DELETE FROM `creature_template_scaling` WHERE `Entry`=118889;
INSERT INTO `creature_template_scaling` (`Entry`,`LevelScalingMin`,`LevelScalingMax`,`VerifiedBuild`) VALUES 
(118889, 110, 110, 25996);

-- Delete Guard (ID 5595) / Add Corin Twinbellows (ID 118889)
DELETE FROM `creature` WHERE  `guid` IN (307473, 307460, 307465, 307464, 307517, 307516, 307515, 307514, 307472, 307510, 307509, 307458, 307457);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(307473, 118889, 0, 0, 0, 1, 169, 0, 0, 0, -4833.832, -1052.455, 502.2732, 3.286509, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25996);
