UPDATE `creature_template` SET ScriptName='npc_buru_egg' WHERE entry=15514;
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry` IN (15514,15370);
DELETE FROM `creature` WHERE `id`=15521; -- because **** you, thats why
SET @GUID :=310;
DELETE FROM `creature` WHERE `id`=15514;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 15514, 509, 1, 1, -9270.393, 1243.896, -63.76731, 2.722714, 7200, 0, 0),
(@GUID+1, 15514, 509, 1, 1, -9300.067, 1305.085, -63.69709, 4.18879, 7200, 0, 0),
(@GUID+2, 15514, 509, 1, 1, -9263.014, 1295.236, -63.80813, 1.797689, 7200, 0, 0),
(@GUID+3, 15514, 509, 1, 1, -9243.427, 1280.498, -63.59377, 3.822271, 7200, 0, 0),
(@GUID+4, 15514, 509, 1, 1, -9234.326, 1243.826, -63.52806, 3.490659, 7200, 0, 0),
(@GUID+5, 15514, 509, 1, 1, -9300.189, 1266.665, -63.74272, 0.2617994, 7200, 0, 0);
DELETE FROM `linked_respawn` WHERE `linkedGuid`=90873;
INSERT INTO `linked_respawn` (`guid`, `linkedGuid`, `linkType`) VALUES
(@GUID, 90873, 0),
(@GUID+1, 90873, 0),
(@GUID+2, 90873, 0),
(@GUID+3, 90873, 0),
(@GUID+4, 90873, 0),
(@GUID+5, 90873, 0);
DELETE FROM `spell_script_names` WHERE `spell_id`=19593;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(19593, 'spell_egg_explosion');
