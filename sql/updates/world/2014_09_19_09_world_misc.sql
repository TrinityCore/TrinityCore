DELETE FROM `creature_addon` WHERE `bytes1`=67108864;
DELETE FROM `creature_template_addon` WHERE `entry` IN (29219,29185);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(29206,67108864,1, '53624'),(29219,67108864,1, ''),(29185,67108864,1, '53624');
UPDATE `creature_template` SET `InhabitType`=4 WHERE entry IN (29708,29805,30442);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (29805,30442);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (97558,97560,97562,97562,97563,97564);
UPDATE `creature_addon` SET `bytes1`=50331648 WHERE guid IN (SELECT guid FROM creature WHERE id=29625);
