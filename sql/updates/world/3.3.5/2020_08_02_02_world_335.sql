-- Fix Sethekk Spirit's level and add missing emotes to some creatures from Sethekk Halls
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60 WHERE `entry` = 18703;
UPDATE `creature_template` SET `minlevel` = 63, `maxlevel` = 63 WHERE `entry` = 20700;
DELETE FROM `creature_addon` WHERE `guid` IN (83294,83259,14547,14544);
INSERT INTO `creature_addon` (`guid`,`emote`) VALUES
(83294,333),
(83259,333),
(14547,333),
(14544,333);
