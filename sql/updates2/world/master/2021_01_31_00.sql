-- DB update 2021_01_29_00 -> 2021_01_31_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_01_29_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_01_29_00 2021_01_31_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1607274868483442300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1607274868483442300');

-- Blackwing Mage [12420]
SET @BWL_MAGE = 12420;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=@BWL_MAGE;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BWL_MAGE;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BWL_MAGE, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 0, 11, 17290, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Cast Fireball'),
(@BWL_MAGE, 0, 1, 0, 9, 0, 100, 0, 0, 10, 15000, 25000, 0, 11, 22271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Cast Arcane Explosion on Close');


-- Blackwing Technician event
DELETE FROM `creature` WHERE `guid`=85786 AND `id`=9098;
DELETE FROM `linked_respawn` WHERE `guid` IN (85786);

UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (13020);

UPDATE `creature` SET `unit_flags`=768 WHERE `guid` IN (84605, 84616, 84606, 84603, 84615, 84614);
DELETE FROM `areatrigger_scripts` WHERE `entry`= 3626;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (3626, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-84605, -84616, -84606, -84603, -84615, -84614) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3626) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3626,2,0,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84605,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,1,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84616,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,2,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84606,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,3,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84603,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,4,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84615,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,5,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84614,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(-84605,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84605,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn"),
(-84616,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84616,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn"),
(-84606,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84606,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn"),
(-84603,0,0,0,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84603,0,1,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn"),
(-84615,0,0,1,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84615,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Say text"),
(-84615,0,2,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn"),
(-84614,0,0,0,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - Data set - Start waypoint"),
(-84614,0,1,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Blackwing Technician - On waypoint ended - Despawn");

DELETE FROM `waypoints` WHERE `entry` IN (1399600, 1399601);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1399600, 1, -7466.55, -1015.38, 408.566, "Blackwing Technician"),
(1399600, 2, -7453.62, -1019.73, 408.57, "Blackwing Technician"),
(1399600, 3, -7443.76, -1031.75, 408.613, "Blackwing Technician"),
(1399600, 4, -7436.59, -1037.8, 408.646, "Blackwing Technician"),
(1399600, 5, -7433.49, -1032.99, 408.641, "Blackwing Technician"),
(1399600, 6, -7436.15, -1025.96, 414.025, "Blackwing Technician"),
(1399600, 7, -7441.49, -1017.68, 423.096, "Blackwing Technician"),
(1399600, 8, -7443.33, -1015.06, 423.666, "Blackwing Technician"),
(1399600, 9, -7456.49, -996.301, 423.666, "Blackwing Technician"),
(1399600, 10, -7483.34, -962.278, 423.809, "Blackwing Technician"),
(1399600, 11, -7488.85, -962.927, 423.693, "Blackwing Technician"),
(1399600, 12, -7506.71, -972.992, 423.607, "Blackwing Technician"),
(1399600, 13, -7514.11, -974.566, 423.477, "Blackwing Technician"),
(1399600, 14, -7519.98, -969.585, 423.429, "Blackwing Technician"),
(1399600, 15, -7526.96, -961.592, 427.805, "Blackwing Technician"),
(1399601, 1, -7487.86, -1036.58, 408.562, "Blackwing Technician"),
(1399601, 2, -7490.35, -1046.43, 408.571, "Blackwing Technician"),
(1399601, 3, -7478.75, -1064.94, 408.633, "Blackwing Technician"),
(1399601, 4, -7483.2, -1069.96, 408.636 , "Blackwing Technician"),
(1399601, 5, -7491.67, -1062.21, 415.998, "Blackwing Technician"),
(1399601, 6, -7496.75, -1054.78, 423.665, "Blackwing Technician"),
(1399601, 7, -7512.88, -1032.64, 423.665, "Blackwing Technician"),
(1399601, 8, -7531.46, -1007.4, 423.665, "Blackwing Technician"),
(1399601, 9, -7534.84, -997.096, 423.764, "Blackwing Technician"),
(1399601, 10, -7520.4, -979.642, 423.502, "Blackwing Technician"),
(1399601, 11, -7519.79, -976.306, 423.43, "Blackwing Technician"),
(1399601, 12, -7526.15, -964.647, 426.48, "Blackwing Technician"),
(1399601, 13, -7529.9, -959.013, 427.93, "Blackwing Technician");

DELETE FROM `creature_text` WHERE `CreatureID` IN (13996);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(13996, 0, 0, 'Run! They are coming!', 14, 0, 100, 0, 0, 0, 9031, 'Blackwing Technician');


-- Adds a reference to the spell_vael_burning_adrenaline script for Burning Adrenaline (Vael Fight)
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_vael_burning_adrenaline';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('18173', 'spell_vael_burning_adrenaline');

-- Suppression Room
SET @GO_TURRET = 179784;
UPDATE `gameobject_template` SET `ScriptName` = 'go_suppression_device' WHERE `entry` = @GO_TURRET;
UPDATE `gameobject_template_addon` SET `faction` = 14 WHERE `entry` = @GO_TURRET;

-- Make NPC 11981 (Flamegor) roam
UPDATE `creature` SET `MovementType`=1, `wander_distance`=10 WHERE `id` = 11981;

-- Add waypoints for Ebonroc (14601)
SET @EBONROCGUID = 85780;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `id`=@EBONROCGUID;
DELETE FROM `creature_addon` WHERE `guid`=@EBONROCGUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@EBONROCGUID,@EBONROCGUID*10,0,0,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@EBONROCGUID*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@EBONROCGUID*10, 1, -7358.19, -994.32, 477.167),
(@EBONROCGUID*10, 2, -7368.8, -983.092, 477.167),
(@EBONROCGUID*10, 3, -7378.3, -977.789, 477.168),
(@EBONROCGUID*10, 4, -7392.39, -983.383, 476.911),
(@EBONROCGUID*10, 5, -7405.91, -987.83, 473.768),
(@EBONROCGUID*10, 6, -7418.1, -976.627, 469.941),
(@EBONROCGUID*10, 7, -7414.41, -963.303, 466.541),
(@EBONROCGUID*10, 8, -7418.1, -976.627, 469.941),
(@EBONROCGUID*10, 9, -7405.91, -987.83, 473.768),
(@EBONROCGUID*10, 10, -7392.39, -983.383, 476.911),
(@EBONROCGUID*10, 11, -7378.3, -977.789, 477.168),
(@EBONROCGUID*10, 12, -7368.8, -983.092, 477.167),
(@EBONROCGUID*10, 13, -7358.19, -994.32, 477.167);

-- Add waypoints for Firemaw ( NOT BLIZZLIKE !!! )
SET @FIREMAW = 84572;
UPDATE `creature` SET `wander_distance` = 0, `MovementType`=2 WHERE `id`=@FIREMAW;
DELETE FROM `creature_addon` WHERE `guid` = @FIREMAW;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@FIREMAW, @FIREMAW*10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id` = @FIREMAW * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@FIREMAW*10, 1, -7534.64, -1036.18, 448.907),
(@FIREMAW*10, 2, -7494.43, -1007.4, 448.907),
(@FIREMAW*10, 3, -7466.28, -987.258, 449.73),
(@FIREMAW*10, 4, -7506.56, -923.1, 457.856),
(@FIREMAW*10, 5, -7459.02, -889.93, 465.217),
(@FIREMAW*10, 6, -7442.65, -911.727, 465.355),
(@FIREMAW*10, 7, -7459.02, -889.93, 465.217),
(@FIREMAW*10, 8, -7506.56, -923.1, 457.856),
(@FIREMAW*10, 9, -7466.28, -987.258, 449.73),
(@FIREMAW*10, 10, -7494.43, -1007.4, 448.907),
(@FIREMAW*10, 11, -7534.64, -1036.18, 448.907);

-- scriptname for the bwl shadowflame
SET @SHADOWFLAME_BWL = 22539;
DELETE FROM `spell_script_names` WHERE `spell_id` = @SHADOWFLAME_BWL;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (@SHADOWFLAME_BWL, 'spell_bwl_shadowflame');

-- attaching lever script to gob
UPDATE `gameobject_template` SET `ScriptName`='go_chromaggus_lever' WHERE `entry` = 179148;
DELETE FROM `gameobject` WHERE `guid` IN (75160, 75163, 7228, 7227);

DELETE FROM `broadcast_text` WHERE `ID` = 100003;
INSERT INTO `broadcast_text` (`ID`, `Language`, `MaleText`, `FemaleText`, `EmoteID0`, `EmoteID1`, `EmoteID2`, `EmoteDelay0`, `EmoteDelay1`, `EmoteDelay2`, `SoundId`, `Unk1`, `Unk2`, `VerifiedBuild`) VALUES
(100003, 0, 'Ah...the heroes. You are persistent, aren\'t you? Your ally here attempted to match his power against mine - and paid the price. Now he shall serve me...by slaughtering you. Get up little Red Wyrm, and destroy them!', 'Ah...the heroes. You are persistent, aren\'t you? Your ally here attempted to match his power against mine - and paid the price. Now he shall serve me...by slaughtering you. Get up little Red Wyrm, and destroy them!', 0, 0, 0, 0, 0, 0, 8279, 0, 0, 0);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
