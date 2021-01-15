DELETE FROM `gameobject_template` WHERE `entry` IN (184718,184722);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `data0`, `data1`, `data2`, `data3`, `size`, `VerifiedBuild`) VALUES
(184718, 6, 327, 'Cauldron Summoner', 0, 0, 0, 36549, 1, -18019),
(184722, 6, 327, 'Cauldron Bug Summoner', 0, 0, 0, 36552, 1, -18019);

DELETE FROM `gameobject` WHERE  `guid` IN(25566,25567) AND `id` IN(184721,184717,184722,184718);

INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(25566, 184718, 530, 1, 1, -970.813, 2172, 15.5428, -2.33874, 0, 0, 0.920505, -0.390731, 0, 100, 1, 0),
(25567, 184722, 530, 1, 1, -970.813, 2172, 15.5428, -2.33874, 0, 0, 0.920505, -0.390731, 0, 100, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36546;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 36546, 0, 0, 31, 0, 5, 184715, 0, 0, 0, 0, '', 'Boil Bleeding Hollow Blood - Cursed Cauldron'),
(13, 2, 36546, 0, 0, 31, 0, 5, 184722, 0, 0, 0, 0, '', 'Boil Bleeding Hollow Blood - Cauldron Bug Summoner');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(21308,21306);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21308,21306) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21308, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 36555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab Summoner - On Spawn - Cast Summon Cursed Scarabs'),
(21306, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 89, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Set Random Movement'),
(21306, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Set Run On'),
(21306, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36556, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Cursed Scarab Periodic'),
(21306, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36559, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Cursed Scarab Despawn Timer'),
(21306, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 31309, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spawn - Cast Spirit Particles (red, big)'),
(21306, 0, 5, 0, 8, 0, 100, 0, 36560, 0, 0, 0, 41, 40000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - On Spellhit (Cursed Scarab Despawn Periodic Trigger) - Despawn'),
(21306, 0, 6, 7, 1, 0, 100, 1, 5000, 90000, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Set faction'),
(21306, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Set Hostile'),
(21306, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Cursed Scarab - OOC - Attack Sumoner');
