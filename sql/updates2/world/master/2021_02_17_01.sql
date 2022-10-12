-- DB update 2021_02_17_00 -> 2021_02_17_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_17_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_17_00 2021_02_17_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613512073209092300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613512073209092300');

/* Commander Althea Ebonlocke Gossip
*/

UPDATE `creature_template` SET `gossip_menu_id`=57032 , `npcflag`=`npcflag`|1 WHERE `entry`=264;
DELETE FROM `npc_text` WHERE `ID`=50029;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50029,'At ease, $c. If you are just passing though I suggest you stick to the roads and only travel by day. If your business is here in Darkshire, consider lending your abilities to the Night Watch. Our skill is unquestionable but our numbers are small.',0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57032 AND `TextID` = 50029;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57032, 50029);

/* Councilman Millstipe Position
*/

DELETE FROM `creature` WHERE (`id` = 270) AND (`guid` IN (4189));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(4189, 270, 0, 0, 0, 1, 1, 1724, 0, -10576.950195, -1108.368408, 30.069258, 4.784207, 300, 0, 0, 896, 0, 0, 0, 0, 0, '', 0);

/* Ambassador Berrybuck Text
*/

UPDATE `creature_text` SET `Text`='The news from Stormwind does not bode well....' WHERE  `CreatureID`=271 AND `GroupID`=0 AND `ID`=1;
UPDATE `broadcast_text` SET `MaleText`='The news from Stormwind does not bode well....' WHERE  `ID`=71;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
