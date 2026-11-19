-- Jin'thala
SET @ENTRY := 37951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,24750,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,2,3,19,0,100,0,24758,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,4,5,19,0,100,0,24770,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,6,7,19,0,100,0,24776,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,8,9,19,0,100,0,24782,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,10,11,19,0,100,0,24607,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,12,13,19,0,100,0,24764,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,14,15,19,0,100,0,26272,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'"),
(@ENTRY,0,16,17,19,0,100,0,31159,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Say 0"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,11,71035,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jin''thala - On Quest Accept - Invoker Cast 'Troll Introduction Tracking Quest'");

-- Jin'thala
SET @ENTRY := 37951;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, '$n. Zuni. Ya''ll find ya trainer in the trainin'' grounds to the east. Bring pride to the Darkspear.', 12, 0, 100, 1, 0, 0, 37821, 0, 'Jin''thala');

DELETE FROM `playercreateinfo_cast_spell` WHERE `spell`=71033;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`,`classMask`,`spell`,`note`) VALUES
(128,2015,71033, 'Troll - Calm of the Novice');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=71035;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(71035,93342,1, 'Troll Introduction Tracking Quest - Zuni Lvl 1 Trigger Aura');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=93342;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-93342,71037,0, 'Zuni Lvl 1 Trigger Aura - Zuni Lvl 1 Trigger');

DELETE FROM `spell_target_position` WHERE `ID`=71241;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(71241,0,1,-1173.453,-5266.401,0.9423928,23911);

UPDATE `creature` SET `unit_flags`=537166080,`dynamicflags`=64 WHERE `guid` IN (308758,308777,308781,308783);

DELETE FROM `creature_addon` WHERE `guid` IN (308758,308777,308781,308783,308770,308773,308973);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(308758,0,0,0,1,0, '29266'),(308777,0,0,0,1,0, '29266'),(308781,0,0,0,1,0, '29266'),(308783,0,0,0,1,0, '29266'),(308770,0,0,0,1,375, '18950'),(308773,0,0,1,257,0, '18950');

DELETE FROM `creature_template_addon` WHERE `entry` IN (38217,37988);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(38217,0,0,0,257,0, '18950'),(37988,0,0,1,0,0, '');

-- Zuni Lvl 1 SAI
SET @ENTRY := 37988;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,2,25,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.2298513,"Zuni Lvl 1 - On Reset - Turn to"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - On Reset - Set Event Phase 1"),
(@ENTRY,0,3,4,8,1,100,0,71037,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - On Spellhit - Play script"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - On Reset - Set Event Phase 0"),
(@ENTRY,0,5,6,40,0,100,0,5,@ENTRY,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached WP5 - Turn to invoker"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached 5 - Say 1"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"S.A.F.E. Operative - On Reached 5 - Despawn in 20 seconds"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - On Reached 5 - Play script"),
(@ENTRY*100,9,0,0,0,0,100,0,4000,4000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - Script - REMOVE_UNIT_FIELD_BYTES_1"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zuni Lvl 1 - Script - Turn to invoker"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Zuni Lvl 1 - Script - Say 0"),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,0,0,53,1,37988,0,0,0,0,1,0,0,0,0,0,0,0,"Zuni Lvl 1 - Script - Move path"),
(@ENTRY*100+1,9,0,0,0,0,100,0,7000,7000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.490659,"S.A.F.E. Operative - Script - Turn to");

-- Zuni Lvl 1
SET @ENTRY := 37988;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Ya, mon. Let''s crack some tiki target skulls!', 12, 0, 100, 5, 0, 21366, 37818, 0, 'Jin''thala Lvl 1'),
(@ENTRY, 1, 0, 'Ya trainer should be somewhere in the grounds ''ere. I''ll catch you lata, mon.', 12, 0, 100, 1, 0, 21367, 39087, 0, 'Jin''thala Lvl 1');

-- Pathing for  Entry: 37988 'Zuni Lvl 1' 
SET @ENTRY := 37988;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-1172.816,-5299.052,5.201296,''),
(@ENTRY,2,-1176.122,-5326.733,13.68535,''),
(@ENTRY,3,-1172.396,-5343.75,15.38646,''),
(@ENTRY,4,-1164.625,-5369.522,14.25021,''),
(@ENTRY,5,-1162.043,-5391.747,12.06027,'');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=71037 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 71037, 0, 0, 31, 0, 3, 37988, 0, 0, 0, 0, '', 'Spell Zuni Lvl 1 Trigger (effect 0) will hit the potential target of the spell if target is unit Zuni Lvl 1.');
