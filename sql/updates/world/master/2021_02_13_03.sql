-- DB update 2021_02_13_02 -> 2021_02_13_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_13_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_13_02 2021_02_13_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613022348525685800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613022348525685800');

/* Add npc text for Deputy Willem  npc=823
   Source: http://www.youtube.com/watch?v=oLy8hMW-e48&t=6m50s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57020 , `npcflag`=`npcflag`|1 WHERE `entry`=823;
DELETE FROM `npc_text` WHERE `ID`=50016;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50016, "Hello there, $c.  Normally I\'d be out on the beat looking after the folk of Stormwind, but a lot of the Stormwind guards are fighting in the other lands.  So here I am, deputized and offering bounties when I\'d rather be on patrol...", 0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57020 AND `TextID` = 50016;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57020, 50016);

/* Add npc text for Remy "Two Times" npc=241
   Source: http://www.youtube.com/watch?v=4wIP0mdSVUA&t=1m32s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57021 , `npcflag`=`npcflag`|1 WHERE `entry`=241;
DELETE FROM `npc_text` WHERE `ID`=50017;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50017,"Hey there, friend.  My name\'s Remy.$BI\'m from Redridge to the east, and came here looking for business, looking for business.  You got any...got any??",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57021 AND `TextID` = 50017;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57021, 50017);

/* Add npc text for Guard Thomas  npc=261
   Source: http://www.youtube.com/watch?v=RMF2a7Rg1FA&t=3m10s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57022 , `npcflag`=`npcflag`|1 WHERE `entry`=261;
DELETE FROM `npc_text` WHERE `ID`=50018;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50018,"Hello, citizen.  You look like a $g man : woman; with a purpose - do you have business with the Stormwind Army?",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57022 AND `TextID` = 50018;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57022, 50018);

/* Add npc text for Farmer Furlbrow  npc=237
   Source: http://www.youtube.com/watch?v=PNqdaVzV6FI&t=1m4s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57023 , `npcflag`=`npcflag`|1 WHERE `entry`=237;
DELETE FROM `npc_text` WHERE `ID`=50019;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50019,"Nothing but trouble in these parts.  I tried to tell that fool Saldean to get out while he still could but he won\'t hear of it.  But I ain\'t no fool.  Verna and I are gonna mosey on out as soon as we get this wagon fixed.", 0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57023 AND `TextID` = 50019;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57023, 50019);

/* Add npc text for Gryan Stoutmantle  npc=234
   Source: http://www.youtube.com/watch?v=PNqdaVzV6FI&t=1m41s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57024 , `npcflag`=`npcflag`|1 WHERE `entry`=234;
DELETE FROM `npc_text` WHERE `ID`=50020;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50020,"A foul corruption has crept into Westfall.  While I was upholding my duty on the battlefields of Lordaeron these honest farms were overrun and made into hide-outs for thugs and murderers. The People\'s Militia needs your help.",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57024 AND `TextID` = 50020;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57024, 50020);

/* Add npc text for Duthorian Rall  npc=6171
   Source: http://www.youtube.com/watch?v=PNqdaVzV6FI&t=3m26s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57025 , `npcflag`=`npcflag`|1 WHERE `entry`=6171;
DELETE FROM `npc_text` WHERE `ID`=50021;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50021,"You will be tested many times by the darkness that surrounds our lands, $N. But to ensure you are always prepared, we will often ask tasks of you so you are at the height of your own power.$B$BGo with the Light, and remain virtuous.",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57025 AND `TextID` = 50021;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57025, 50021);

/* Add npc text for Talin Keeneye  npc=714
   Source: http://www.youtube.com/watch?v=4wIP0mdSVUA&t=9m53s
*/
UPDATE `creature_template` SET `gossip_menu_id`=472 , `npcflag`=`npcflag`|1 WHERE `entry`=714;
DELETE FROM `npc_text` WHERE `ID`=50022;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50022,"Greetings, $c! Fine day for hunting, wouldn\'t you say? I\'ve been having more than a little luck with boars, myself. Perhaps you\'d like a shot?",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 472 AND `TextID` = 50022;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(472, 50022);

/* Add missing npc text for Sentinel Glynda Nal'Shea  npc=2930
   Source: http://www.youtube.com/watch?v=P8cXHJcb50o&t=1m47s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57026 , `npcflag`=`npcflag`|1 WHERE `entry`=2930;
DELETE FROM `npc_text` WHERE `ID`=50023;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50023,"Corruption sneaks into nature\'s grove. The forest must be protected at all costs.",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57026 AND `TextID` = 50023;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57026, 50023);

/* Add missing npc text for Thundris Windweaver  npc=3649
   Source: http://www.youtube.com/watch?v=P8cXHJcb50o&t=2m8s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57027 , `npcflag`=`npcflag`|1 WHERE `entry`=3649;
DELETE FROM `npc_text` WHERE `ID`=50024;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50024,"Dark forces encroach upon our borders, ancient taints resurface, and new evils emerge to topple the delicate balance of the land. In times of such darkness, we all must be vigilant.",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57027 AND `TextID` = 50024;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57027, 50024);

/* Add missing npc text for Onu npc=3616
   Source: http://www.youtube.com/watch?v=9A4m7LINi8g&t=4m47s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57028 , `npcflag`=`npcflag`|1 WHERE `entry`=3616;
DELETE FROM `npc_text` WHERE `ID`=50025;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50025,"The wind whispers to those who listen...$B$BDo you hear it?",0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57028 AND `TextID` = 50025;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57028, 50025);

/* Add missing npc text for Gaxim Rustfizzle  npc=4077
   Source: http://www.youtube.com/watch?v=r9JUuuii7SU&t=5m55s
*/
UPDATE `creature_template` SET `gossip_menu_id`=57029 , `npcflag`=`npcflag`|1 WHERE `entry`=4077;
DELETE FROM `npc_text` WHERE `ID`=50026;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`) VALUES
(50026,'If I can get the proper ingredients, we can create some explosives that will not only allow me to damage the Venture\'s Co.\'s operations, but also cause a distraction.$B$BI know you\'re impressed, but it gets better... I\'ll tell you more soon enough.',0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 57029 AND `TextID` = 50026;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(57029, 50026);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
