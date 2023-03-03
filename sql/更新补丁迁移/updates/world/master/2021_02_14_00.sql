-- DB update 2021_02_13_03 -> 2021_02_14_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_13_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_13_03 2021_02_14_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613146762649566200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613146762649566200');

/* Add missing npc text for Verna Furlbrow  npc=238
   Source: https://youtu.be/jZs1NlQNGJ4?t=1124
*/
UPDATE `creature_template` SET `gossip_menu_id`=57030 , `npcflag`=`npcflag`|1 WHERE `entry`=238;
DELETE FROM `npc_text` WHERE `ID`=50027;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50027,'Sometimes I think there\'s a big gray cloud in the sky, just raining down bad luck upon us. First, we\'re driven off our land, and now we can\'t even get out of Westfall. Everything\'s a mess. Something needs to be done.',0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57030 AND `TextID` = 50027;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57030, 50027);

/* Change Old Blanchy to Friendly to Alliance and Horde and remove faction from tooltip
   Source: https://youtu.be/jZs1NlQNGJ4?t=1124
*/

UPDATE `creature_template` SET `faction` = 35 WHERE (`entry` = 582);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
