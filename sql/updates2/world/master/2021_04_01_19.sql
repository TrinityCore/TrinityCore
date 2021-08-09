-- DB update 2021_04_01_18 -> 2021_04_01_19
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_18';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_18 2021_04_01_19 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617197895526268300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617197895526268300');
-- ----------------------------------The Ancient Statuette Fixes-------------------------------------------------

-- Talen
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3846 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 384600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(3846,0,0,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Talen - Between 0-15% Health - Flee For Assist'),
(3846,0,1,0,20,0,100,0,1007,0,0,0,0,80,384600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Quest \'The Ancient Statuette\' Finished - Run Script'),
(384600,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Remove Npc Flag Questgiver'),
(384600,9,1,0,0,0,100,0,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Remove Flag Standstate \'Sit Down\''),
(384600,9,2,0,0,0,100,0,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Sheath \'Unarmed\''),
(384600,9,3,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,6.16678,'Talen - On Script - Set Orientation'),
(384600,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Say Line 0'),
(384600,9,5,0,0,0,100,0,4000,4000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Set Flag Standstate \'Kneel\''),
(384600,9,6,0,0,0,100,0,1000,1000,0,0,0,50,18603,12,0,0,0,0,8,0,0,0,0,3471.69,846.893,5.39909,4.67058,'Talen - On Script - Summon Gameobject \'Ancient Statuette\''),
(384600,9,7,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Say Line 1'),
(384600,9,8,0,0,0,100,0,8000,8000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Say Line 2'),
(384600,9,9,0,0,0,100,0,4000,4000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Remove Flag Standstate \'Kneel\''),
(384600,9,10,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Set Orientation'),
(384600,9,11,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Say Line 3'),
(384600,9,12,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Add Npc Flag Questgiver'),
(384600,9,13,0,0,0,100,0,20000,20000,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Set Flag Standstate Sit Down'),
(384600,9,14,0,0,0,100,0,1000,1000,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Talen - On Script - Sheath \'Melee\'');

-- Ruuzel and Bodyguards
UPDATE `creature` SET `MovementType` = 2,`position_x` = 4157.59,`position_y` = 1272.73,`position_z` = 3.22775 WHERE `guid` = 32617;
UPDATE `creature` SET `position_x` = 4139.376,`position_y` = 1272.271,`position_z` = 3.659 WHERE `guid` = 32762;
UPDATE `creature` SET `position_x` = 4140.003,`position_y` = 1268.586,`position_z` = 3.804 WHERE `guid` = 32728;

DELETE FROM `creature_addon` where guid = 32617;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`isLarge`,`auras`) VALUES
(32617,326170,0,0,4097,0,1,'');

DELETE FROM `creature_formations` where leaderGUID = 32617;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES 
(32617,32617,0,0,515,0,0),
(32617,32762,3,120,515,0,0),
(32617,32728,3,210,515,0,0);

DELETE FROM `waypoint_data` where ID = 326170;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(326170,1,4157.59,1272.73,3.22775,0,0,0,0,100,0),
(326170,2,4118.6,1268.22,1.93513,0,0,0,0,100,0),
(326170,3,4100.35,1277.8,1.42555,0,0,0,0,100,0),
(326170,4,4090.54,1314.88,2.11756,0,0,0,0,100,0),
(326170,5,4098.61,1352.27,2.58844,0,0,0,0,100,0),
(326170,6,4116.9,1363.47,1.69482,0,0,0,0,100,0),
(326170,7,4133.67,1375.35,2.18856,0,0,0,0,100,0),
(326170,8,4176.57,1370.93,2.58461,0,0,0,0,100,0),
(326170,9,4221.99,1339.24,2.22232,0,0,0,0,100,0),
(326170,10,4225.52,1317.01,1.90514,0,0,0,0,100,0),
(326170,11,4206.5,1285.38,1.3025,0,0,0,0,100,0),
(326170,12,4185.92,1278.95,1.27956,0,0,0,0,100,0),
(326170,13,4168.32,1281.27,3.36765,0,0,0,0,100,0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
