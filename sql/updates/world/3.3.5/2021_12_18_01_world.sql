--
DELETE FROM `gameobject_template` WHERE `entry` = 188477;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(188477,6,335,'DrakTharon - Enter - Trigger 001','','','',1,0,0,15,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',-18019);

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 188477;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 188477 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(188477,1,0,1,70,0,100,0,1,0,0,0,45,1,1,0,0,0,0,10,56504,26626,0,0,0,0,0,0,'DrakTharon - Enter - Trigger 001 - On State Changed - Set Data 1 1 (Scourge Reanimator)'),
(188477,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,56502,26620,0,0,0,0,0,0,'DrakTharon - Enter - Trigger 001 - On State Changed - Set Data 1 1 (Drakkari Guardian)'),
(188477,1,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,56503,26620,0,0,0,0,0,0,'DrakTharon - Enter - Trigger 001 - On State Changed - Set Data 1 1 (Drakkari Guardian)'),
(188477,1,3,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'DrakTharon - Enter - Trigger 001 - On State Changed - Despawn');

DELETE FROM `gameobject` WHERE `guid` = 30034 AND `id` = 188477;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(30034,188477,600,0,0,3,1,-532.311279,-541.258728,2.568511,3.951948,0,0,0,1,86400,255,1,'',0);

-- Scourge Reanimator
-- X: -511.0887 Y: -602.5585 Z: 2.5674403
UPDATE `creature` SET `unit_flags` = 33088 WHERE `guid` = 56504 AND `id` = 26626;
DELETE FROM `waypoints` WHERE `entry` = 2662600;

DELETE FROM `smart_scripts` WHERE `entryorguid` = -56504 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2662600,2662601) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-56504,0,0,0,38,0,100,0,1,1,0,0,0,80,2662600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Data Set 1 1 - Run Script"),
(-56504,0,1,0,34,0,100,0,8,1,0,0,0,80,2662601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Reached Point 1 - Run Script"),

(2662600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 0"),
(2662600,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-533.09265,-591.5711,2.484159,0,"Scourge Reanimator - On Script - Move To Position"),

(2662601,9,0,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 1"),
(2662601,9,1,0,0,0,100,0,0,0,0,0,0,11,48597,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(2662601,9,2,0,0,0,100,0,3000,3000,0,0,0,11,48605,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(2662601,9,3,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Say Line 2"),
(2662601,9,4,0,0,0,100,0,0,0,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Play Emote 11"),
(2662601,9,5,0,0,0,100,0,0,0,0,0,0,11,47506,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Cast 'Teleport'"),
-- Should be moved to OnSpellCast
(2662601,9,6,0,0,0,100,0,1500,1500,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourge Reanimator - On Script - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (48597,48605);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,48597,0,0,31,0,3,26620,56503,0,0,0,"","Group 0: Spell 'Raise Dead' (Effect 0) targets creature 'Drakkari Guardian'"),
(13,1,48605,0,0,31,0,3,26620,56502,0,0,0,"","Group 0: Spell 'Raise Dead' (Effect 0) targets creature 'Drakkari Guardian'");

DELETE FROM `spell_target_position` WHERE `ID` = 47506;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(47506,0,600,-369,-601,2,0,11723);

DELETE FROM `event_scripts` WHERE `id` IN (17739,17740);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `Comment`) VALUES
(17739,0,10,26635,86400000,0,-537.03955,-578.2375,2.0236964,1.710422635078430175,"Event (Spell 'Raise Dead' (48597)) - On Event - Summon Creature 'Risen Drakkari Warrior'"),
(17740,0,10,26635,86400000,0,-543.2898,-581.41125,1.1083593,2.0245819091796875,"Event (Spell 'Raise Dead' (48605)) - On Event - Summon Creature 'Risen Drakkari Warrior'");

-- Drakkari Guardian 1
-- X: -518.00616 Y: -599.11017 Z: 1.1083504
DELETE FROM `smart_scripts` WHERE `entryorguid` = -56503 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-56503,0,0,0,38,0,100,0,1,1,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-537.1106,-579.0993,1.749222,0,"Drakkari Guardian - On Data Set 1 1 - Move To Position"),
(-56503,0,1,0,34,0,100,0,8,1,0,0,0,11,45254,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Guardian - On Reached Point 1 - Cast 'Suicide'"),
(-56503,0,2,0,8,0,100,0,48597,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Guardian - On 'Raise Dead' Spellhit - Delayed Despawn");

-- Drakkari Guardian 2
-- X: -522.7039 Y: -605.90826 Z: 1.2999884
DELETE FROM `smart_scripts` WHERE `entryorguid` = -56502 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-56502,0,0,0,38,0,100,0,1,1,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-543.1817,-582.3423,1.025022,0,"Drakkari Guardian - On Data Set 1 1 - Move To Position"),
(-56502,0,1,0,34,0,100,0,8,1,0,0,0,11,45254,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Guardian - On Reached Point 1 - Cast 'Suicide'"),
(-56502,0,2,0,8,0,100,0,48605,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Guardian - On 'Raise Dead' Spellhit - Delayed Despawn");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26635 AND `source_type` = 0 AND `id` = 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26635,0,5,0,54,0,100,0,0,0,0,0,0,11,48624,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Risen Drakkari Warrior - On Just Summoned - Cast 'Birth Dead Visual'");

UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `guid` IN (56502,56503,56504) AND `id` IN (26620,26626);
