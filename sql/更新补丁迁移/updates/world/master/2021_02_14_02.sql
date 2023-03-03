-- DB update 2021_02_14_01 -> 2021_02_14_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_14_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_14_01 2021_02_14_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613178961634699600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613178961634699600');

/* Add missing npc text for William Pestle  npc=253
   Source: https://youtu.be/4wIP0mdSVUA?t=40s
*/

UPDATE `creature_template` SET `gossip_menu_id`=57031 , `npcflag`=`npcflag`|1 WHERE `entry`=253;
DELETE FROM `npc_text` WHERE `ID`=50028;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50028,'Aha! Good day, good day, Master $C! Come, sit down and have a drink. You have an enterprising look in your eye, and I think you\'ll find speaking to me worth your time....',0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57031 AND `TextID` = 50028;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57031, 50028);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
