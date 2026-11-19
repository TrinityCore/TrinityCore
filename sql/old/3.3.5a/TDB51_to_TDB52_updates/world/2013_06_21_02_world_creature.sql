UPDATE `creature` SET `modelid`=0, `curhealth`=1, `curmana`=0 WHERE `id`=2591;
UPDATE `creature` SET `modelid`=0, `curhealth`=1, `curmana`=0 WHERE `id`=4844;
UPDATE `creature` SET `modelid`=0, `curhealth`=1 WHERE `id`=5471;
UPDATE `creature` SET `modelid`=0, `curhealth`=1 WHERE `id`=5615;
UPDATE `creature` SET `modelid`=0, `curhealth`=1, `MovementType`=0 WHERE `guid` IN (200617,200618);
UPDATE `creature` SET `modelid`=0, `curhealth`=1, `curmana`=0 WHERE `id`=14876;
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (14564,14556,151934,151935,151936,151947,151948,151949,151995,151996,151997,151998,201735,201757,201764,28686,152002,152003,151979,151959,151940,151937,209098,209097,202337,78554,78555,200615,42880,152311,152315);
DELETE FROM `creature_addon` WHERE `guid` IN (7690,23130,23466,23467,14564,128582);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES 
(7690,76900,1,0, ''),
(23130,231300,1,0, ''),
(23466,234660,1,0, ''),
(23467,234670,1,0, ''),
(128582,1285820,1,0, '');
