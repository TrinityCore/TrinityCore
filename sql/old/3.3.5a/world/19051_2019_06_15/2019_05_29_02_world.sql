-- 
SET @GUID       := 107135;
DELETE FROM `creature` WHERE `id`  IN(34519,34520);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID+0, 34520, 571, 1, 1, 5713.269, 649.1719, 648.8437, 3.752458, 120, 0, 0), -- 34520 (Area: 4739)
(@GUID+1, 34520, 571, 1, 1, 5710.966, 641.757, 648.8568, 1.745329, 120, 0, 0), -- 34520 (Area: 4739) (Auras: 65617 - 65617)
(@GUID+2, 34520, 571, 1, 1, 5706.833, 647.6268, 648.8349, 5.67232, 120, 0, 0), -- 34520 (Area: 4739)
(@GUID+3, 34519, 571, 1, 1, 5710.15, 642.3246, 648.89, 5.406746, 120, 0, 0); -- 34519 (Area: 4739) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid`=@GUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+1, 0, 0, 0, 1, 0, '65617');

UPDATE `creature_template` SET `AIName`='SmartAI', `scriptname`='' WHERE `entry`IN (34520,34519);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry`IN (34519);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(34520,34519,-@GUID,-@GUID-1,-@GUID-2) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-@GUID,0,0,1,1,0,100,0,15000,20000,15000,20000,11,65611,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Cast Throw Ragdoll'),
(-@GUID,0,1,0,61,0,100,0,0,0,0,0,28,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Remove Aura Hold Ragdoll State'),
(-@GUID,0,2,4,8,0,100,0,65614,0,0,0,75,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Cast Hold ragdoll state'),
(-@GUID,0,3,0,1,0,100,0,5000,20000,15000,30000,10,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Random Emote'),
(-@GUID,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,34519,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Set Data'),
(-@GUID-1,0,0,1,1,0,100,0,15000,20000,15000,20000,11,65613,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Cast Throw Ragdoll'),
(-@GUID-1,0,1,0,61,0,100,0,0,0,0,0,28,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Remove Aura Hold Ragdoll State'),
(-@GUID-1,0,2,4,8,0,100,0,65611,0,0,0,75,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Cast Hold ragdoll state'),
(-@GUID-1,0,3,0,1,0,100,0,5000,20000,15000,30000,10,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Random Emote'),
(-@GUID-1,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,34519,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Set Data'),
(-@GUID-2,0,0,1,1,0,100,0,15000,20000,15000,20000,11,65614,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Cast Throw Ragdoll'),
(-@GUID-2,0,1,0,61,0,100,0,0,0,0,0,28,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Remove Aura Hold Ragdoll State'),
(-@GUID-2,0,2,4,8,0,100,0,65613,0,0,0,75,65617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Cast Hold ragdoll state'),
(-@GUID-2,0,3,0,1,0,100,0,5000,20000,15000,30000,10,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wolver Orphan - OOC - Random Emote'),
(-@GUID-2,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,34519,0,0,0,0,0,0,'Wolver Orphan - On Spellhit (Throw Ragdoll) - Set Data'),
(34519,0,0,0,1,0,100,0,5000,20000,45000,90000,1,0,8000,0,0,0,0,19,34520,0,0,0,0,0,0,'Oracle Orphan - OOC - Say Line 0'),
(34519,0,1,0,52,0,100,0,0,34520,0,0,1,0,8000,0,0,0,0,1,0,0,0,0,0,0,0,'Oracle Orphan - On Text Over Line 0 (Wolvar) - Say Line 0'),
(34519,0,2,0,52,0,100,0,0,34519,0,0,1,1,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Oracle Orphan - On Text Over Line 0  - Say Line 1'),
(34519,0,3,0,52,0,100,0,1,34519,0,0,1,2,7000,0,0,0,0,1,0,0,0,0,0,0,0,'Oracle Orphan - On Text Over Line 1  - Say Line 2'),
(34519,0,4,0,52,0,100,0,2,34519,0,0,1,0,7000,0,0,0,0,19,34365,0,0,0,0,0,0,'Oracle Orphan - On Text Over Line 2  - Say Line 0 (Matron)'),
(34519,0,5,0,38,0,100,0,1,1,0,0,69,1,0,0.5,1,0,0,7,0,0,0,0,0,0,0,'Oracle Orphan - On Data set  - Move top pos');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13,17) AND `SourceEntry` IN(65611,65613,65614);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 65611, 0, 0, 31, 0, 3, 34520, @GUID+1, 0, 0, 0, '', 'Wolvar Orphan'),
(13, 1, 65613, 0, 0, 31, 0, 3, 34520, @GUID+2, 0, 0, 0, '', 'Wolvar Orphan'),
(13, 1, 65614, 0, 0, 31, 0, 3, 34520, @GUID+0, 0, 0, 0, '', 'Wolvar Orphan');

DELETE FROM `creature_text` WHERE `CreatureID`IN(34520,34519,34365);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(34520, 0, 0, 'If you want, go get, big-tongue baby!', 12, 0, 100, 0, 0, 0, 34704, 0, 'Wolvar Orphan'),
(34519, 0, 0, 'Give toy back!', 12, 0, 100, 1, 0, 0, 34705, 0, 'Oracle Orphan'),
(34519, 1, 0, 'Stop!', 12, 0, 100, 1, 0, 0, 34706, 0, 'Oracle Orphan'),
(34519, 2, 0, 'We tell orphan matron on you!', 12, 0, 100, 0, 0, 0, 34714, 0, 'Oracle Orphan'),
(34365, 0, 2, 'Children, please behave yourselves! No one will want to adopt you if you keep acting like that!', 12, 0, 100, 0, 0, 0, 34715, 0, 'Orphan Matron Aria');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN(34520,-@GUID,-@GUID-1,-@GUID-2);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, -@GUID, 0, 0, 1, 1, 65617, 0, 0, 0, 0, 0, '', 'Wolver Orphan only run SAI if has aura Hold Ragdoll State'),
(22, 1, -@GUID-1, 0, 0, 1, 1, 65617, 0, 0, 0, 0, 0, '', 'Wolver Orphan only run SAI if has aura Hold Ragdoll State'),
(22, 1, -@GUID-2, 0, 0, 1, 1, 65617, 0, 0, 0, 0, 0, '', 'Wolver Orphan only run SAI if has aura Hold Ragdoll State');

DELETE FROM `game_event_creature` WHERE `eventEntry`=10 AND `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(10, @GUID),
(10, @GUID+1),
(10, @GUID+2),
(10, @GUID+3);

UPDATE `creature` SET `equipment_id`=0 WHERE `id`  IN(22833);
