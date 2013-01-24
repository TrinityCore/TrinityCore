-- Image of Commander Ameer <The Protectorate> (22919)
SET @GUID := 43492;

UPDATE `creature_template` SET `npcflag`=`npcflag`|2,`unit_flags`=`unit_flags`&~33554432 WHERE `entry`=22919;

DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`) VALUES
(@GUID,22919,530,3866.55,5978.68,291.792,4.10061,300,6986);

DELETE FROM `creature_questrelation` WHERE `id`=22919;
INSERT INTO `creature_questrelation` (`id`,`quest`) VALUES
(22919,10981), -- Nexus-Prince Shaffar's Personal Chamber
(22919,10975), -- Purging the Chambers of Bash'ir
(22919,10977), -- Stasis Chambers of the Mana-Tombs
(22919,10976); -- The Mark of the Nexus-King

DELETE FROM `creature_involvedrelation` WHERE `id`=22919;
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES
(22919,10981), -- Nexus-Prince Shaffar's Personal Chamber
(22919,10975), -- Purging the Chambers of Bash'ir
(22919,10974), -- Stasis Chambers of Bash'ir
(22919,10977), -- Stasis Chambers of the Mana-Tombs
(22919,10982), -- The Eye of Haramad
(22919,10976); -- The Mark of the Nexus-King
