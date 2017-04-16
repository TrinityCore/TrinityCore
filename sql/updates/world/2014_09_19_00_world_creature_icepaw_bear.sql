-- give Icepaw Bear glowing Ice Paws:
DELETE FROM `creature_template_addon` WHERE `entry` = 29319;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29319,0,0,0,0,'54240'); -- Works  as intended in test, do we need sniff confirmation?
-- make Icepaw Bear attackable, tameable and attacking in aggro range:
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 256 &~ 262144 WHERE `entry` = 29319;
