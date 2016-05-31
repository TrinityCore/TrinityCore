SET @CGUID := 6747;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 22418, 534, 1, 1, 5502.288, -3525.471, 1607.909, 2.617994, 7200, 0, 0);

DELETE FROM `creature_text` WHERE `entry`=17968 AND `groupid`=8;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17968, 8, 0, 'All of your efforts have been in vain, for the draining of the World Tree has already begun!  Soon the heart of your world will beat no more!', 14, 0, 100, 0, 0, 10986, 20432, 3, 'Archimonde - Intro');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (39140,39141,39142);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,39140,0,0,31,0,3,22418,0,0,0, '', 'Drain World Tree Visual'),
(13,1,39141,0,0,31,0,3,17968,0,0,0, '', 'Drain World Tree Visual 2'),
(13,1,39142,0,0,31,0,3,22418,0,0,0, '', 'Drain World Tree Dummy');

DELETE FROM `spell_script_names` WHERE `spell_id`=39142;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39142, 'spell_archimonde_drain_world_tree_dummy');
