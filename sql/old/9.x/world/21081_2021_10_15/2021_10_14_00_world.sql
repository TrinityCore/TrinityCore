-- Magistrix Erona (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `RangeAttackTime`=0, `VerifiedBuild`=40120 WHERE `entry`=15278;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15278 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15516;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `spawntimesecs`=120, `curhealth`=522, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=54984;

DELETE FROM `creature_addon` WHERE `guid`=54984;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(54984, 0, 0, 0, 1, 0, 0, 0, 0, '');

UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=11902 AND `TextId`=16703);

UPDATE `npc_text` SET `VerifiedBuild`=40120 WHERE `ID`=16703;
