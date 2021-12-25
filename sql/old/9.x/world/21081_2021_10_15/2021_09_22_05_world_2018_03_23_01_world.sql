-- Warsong Marksman (ID 25244) corpses on Garrosh's Landing should appear dead in-game, both in portrait and NPC name
UPDATE `creature_addon` SET `bytes1`=0,`auras`='29266' WHERE `guid` IN (110545,110546); -- 2x Warsong Marksman in burning heap of corpses
UPDATE `creature_addon` SET `bytes1`=0,`bytes2`=2,`auras`='29266' WHERE `guid` IN (110540,110541,110544,110547,110551,110552,110553,110554); -- scattered Marksman corpses with ranged weapon
UPDATE `creature` SET `unit_flags`=`unit_flags`|537133824 WHERE `guid` IN (110552, 110547, 110541, 110554, 110545, 110546, 110553, 110544, 110551, 110540, 110370, 110378);
-- Garhal minions
DELETE FROM `creature_addon` WHERE `guid` IN (118803, 118804);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`) VALUES
(118803,0,0),(118804,0,0);
