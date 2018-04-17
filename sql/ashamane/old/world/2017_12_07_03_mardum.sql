UPDATE creature_template SET scriptname = "npc_mardum_fel_lord_caza" WHERE entry = 96441;
UPDATE `creature_template` SET `flags_extra` = 128 WHERE entry IN (100061, 100257);
UPDATE creature_template SET inhabittype = 4 WHERE entry IN (96276, 96732, 98191, 24021, 37490);

DELETE FROM creature WHERE guid IN (20541651, 20549017);
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) values('20549017','98986','1481','7705','7912','1','0','0','0','0','1880.78','1139.95','80.3036','2.64984','300','0','0','627000','24394','0','0','0','0','0','0','','0');

UPDATE creature_template SET lootid = 98986 WHERE entry = 98986 AND lootid = 0;
DELETE FROM `creature_loot_template` WHERE `entry` = '98986';
INSERT INTO `creature_loot_template` (`entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
('98986', '129196', '0', '1', '0', '1', '0', '1', '1', ''),
('98986', '129957', '0', '100', '1', '1', '0', '1', '1', ''),
('98986', '130264', '0', '2', '0', '1', '0', '1', '1', ''),
('98986', '130265', '0', '0.1261246', '0', '1', '0', '1', '1', ''),
('98986', '130266', '0', '0.1261246', '0', '1', '0', '1', '1', ''),
('98986', '130267', '0', '85', '0', '1', '0', '1', '1', ''),
('98986', '130268', '0', '11', '0', '1', '0', '1', '1', ''),
('98986', '130317', '0', '4', '0', '1', '0', '1', '1', '');

DELETE FROM creature WHERE guid IN (20542224, 20542071, 20541825);
DELETE FROM creature_addon WHERE guid NOT IN (SELECT guid FROM creature);

UPDATE gameobject_template SET scriptname = "go_mardum_illidari_banner" WHERE entry IN (243968, 243967, 243965);

delete from gameobject where guid = 20375494;
insert into `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) values('20375494','243965','1481','0','0','1','0','0','1816.61','1540.2','86.1921','5.29272','-0','-0','-0.475237','0.879858','300','255','1','','0');

