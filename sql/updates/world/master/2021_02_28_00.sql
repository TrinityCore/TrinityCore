-- DB update 2021_02_27_00 -> 2021_02_28_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_27_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_27_00 2021_02_28_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614138891078013900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614138891078013900');

UPDATE `smart_scripts` 
SET `event_type` =67, `event_param1` =15000, `event_param2` =15000, `event_flags` =0 
WHERE `entryorguid` IN (3,36,92,114,822,1128,1199,1201,1537,1543,1547,1548,1549,1770,1869,1934,1935,1972,2248,2347,2473,2474,2723,2735,2736,2780,2781,2782,4130,4872,5246,5253,5292,5293,5300,5461,5850,5853,7032,8447,9218,9219,11698,15655)
AND (`source_type`) = 0 -- select only creatures
AND (`action_type`) = 11 -- select only action Cast
AND (`action_param1`) = 13496; -- select only Spell 'Dazed'

UPDATE `smart_scripts` SET `comment` ='Flesh Eater - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =3 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Harvest Golem - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =36 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Rock Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =92 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Harvest Watcher - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =114 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Young Forest Bear - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =822 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Young Black Bear - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1128 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Juvenile Snow Leopard - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1199 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Snow Leopard - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1201 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Scarlet Zealot - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1537 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Vile Fin Puddlejumper - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1543 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Decrepit Darkhound - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1547 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Cursed Darkhound - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1548 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Ravenous Darkhound - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1549 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Moonrage Darkrunner - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1770 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Ravenclaw Champion - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1869 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Tirisfal Farmer - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1934 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Tirisfal Farmhand - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1935 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Grimson the Pale - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =1972 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Cave Yeti - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2248 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Wild Gryphon - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2347 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Granistad - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2473 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Kurdos - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2474 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Stone Golem - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2723 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Lesser Rock Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2735 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Greater Rock Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2736 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Caretaker Nevlin - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2780 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Caretaker Weston - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2781 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Caretaker Alaric - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =2782 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Silithid Searcher - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =4130 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Obsidian Golem - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =4872 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Zukk ash Worker - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5246 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Woodpaw Brute - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5253 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Feral Scar Yeti - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5292 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Hulking Feral Scar - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5293 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Frayfeather Hippogryph - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5300 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Sea Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5461 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Blazing Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5850 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Tempered War Golem - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =5853 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Greater Obsidian Elemental - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =7032 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Clunk - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =8447 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Spirestone Battle Lord - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =9218 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Spirestone Butcher - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =9219 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Hive Ashi Stinger - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =11698 AND `source_type` =0;
UPDATE `smart_scripts` SET `comment` ='Rotlimb Cannibal - On Behind Target - Cast \'Dazed\'' WHERE `entryorguid` =15655 AND `source_type` =0;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
