-- The way how credit spells are used is guessed
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 134, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 25397 WHERE `Id` = 45498; -- Elder Kesuk Credit
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 134, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 25398 WHERE `Id` = 45499; -- Elder Sagani Credit
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 134, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 25399 WHERE `Id` = 45500; -- Elder Takret Credit
-- Not used
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 134, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 25400 WHERE `Id` = 45501; -- Elder Yakone Credit

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (25397,25398,25399));
DELETE FROM `spawn_group` WHERE `groupId` = 2 AND `spawnType` = 0 AND `spawnId` IN (SELECT `guid` FROM `creature` WHERE `id` IN (25397,25398,25399));
DELETE FROM `creature` WHERE `id` IN (25397,25398,25399);

UPDATE `creature_template` SET `minlevel` = 71, `unit_flags` = 32768, `flags_extra` = `flags_extra`|512 WHERE `entry` = 25397;
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry` = 25398;
UPDATE `creature_template` SET `unit_flags` = 32768, `flags_extra` = `flags_extra`|512 WHERE `entry` = 25399;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25397,25398,25399) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2539700,2539701,2539800,2539801,2539900,2539901) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25397,0,0,0,63,0,100,0,0,0,0,0,0,80,2539700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Just Created - Run Script"),
(25397,0,1,0,40,0,100,0,1,0,0,0,0,80,2539701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Waypoint 1 Reached - Run Script"),
(25397,0,2,0,40,0,100,0,2,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Waypoint 2 Reached - Delayed Despawn"),

(2539700,9,0,0,0,0,100,0,1000,1000,0,0,0,53,0,25397,0,0,0,2,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Script - Start Waypoint"),

(2539701,9,0,0,0,0,100,0,2000,2000,0,0,0,11,33345,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Script - Cast 'Yellow Banish State'"),
(2539701,9,1,0,0,0,100,0,0,0,0,0,0,3,0,28320,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Script - Morph To Model 28320"),
(2539701,9,2,0,0,0,100,0,1000,1000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Kesuk - On Script - Disable Gravity"),

(25398,0,0,0,63,0,100,0,0,0,0,0,0,80,2539800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Just Created - Run Script"),
(25398,0,1,0,40,0,100,0,1,0,0,0,0,80,2539801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Waypoint 1 Reached - Run Script"),
(25398,0,2,0,40,0,100,0,2,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Waypoint 2 Reached - Delayed Despawn"),

(2539800,9,0,0,0,0,100,0,1000,1000,0,0,0,53,0,25398,0,0,0,2,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Script - Start Waypoint"),

(2539801,9,0,0,0,0,100,0,2000,2000,0,0,0,11,33345,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Script - Cast 'Yellow Banish State'"),
(2539801,9,1,0,0,0,100,0,0,0,0,0,0,3,0,28320,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Script - Morph To Model 28320"),
(2539801,9,2,0,0,0,100,0,1000,1000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Sagani - On Script - Disable Gravity"),

(25399,0,0,0,63,0,100,0,0,0,0,0,0,80,2539900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Just Created - Run Script"),
(25399,0,1,0,40,0,100,0,1,0,0,0,0,80,2539901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Waypoint 1 Reached - Run Script"),
(25399,0,2,0,40,0,100,0,2,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Waypoint 2 Reached - Delayed Despawn"),

(2539900,9,0,0,0,0,100,0,1000,1000,0,0,0,53,0,25399,0,0,0,2,1,0,0,0,0,0,0,0,0,"Elder Takret - On Script - Start Waypoint"),

(2539901,9,0,0,0,0,100,0,2000,2000,0,0,0,11,33345,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Script - Cast 'Yellow Banish State'"),
(2539901,9,1,0,0,0,100,0,0,0,0,0,0,3,0,28320,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Script - Morph To Model 28320"),
(2539901,9,2,0,0,0,100,0,1000,1000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Takret - On Script - Disable Gravity");

DELETE FROM `waypoints` WHERE `entry` IN (25397,25398,25399);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(25397,1,3643.4163,5632.8496,34.272816,0,3000,"Elder Kesuk"),
(25397,2,3644.069,5645.058,51.32434,0,0,"Elder Kesuk"),
(25398,1,3584.8965,5529.166,27.187576,0,3000,"Elder Sagani"),
(25398,2,3588.6294,5532.7065,37.23884,0,0,"Elder Sagani"),
(25399,1,3707.2065,5561.1426,34.714035,0,3000,"Elder Takret"),
(25399,2,3709.6587,5552.678,52.91427,0,0,"Elder Takret");

--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 45536;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45536,0,0,31,0,3,25431,0,0,0,0,"","Group 0: Spell 'Complete Ancestor Ritual' (Effect 0) targets creature 'Kaskala Ancestor'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25431;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25431 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2543100,2543101,2543102) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25431,0,0,0,8,0,100,0,45536,0,0,0,0,80,2543100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Spellhit 'Complete Ancestor Ritual' - Run Script"),
(25431,0,1,0,8,0,100,0,45536,0,0,0,0,80,2543101,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Spellhit 'Complete Ancestor Ritual' - Run Script"),
(25431,0,2,0,8,0,100,0,45536,0,0,0,0,80,2543102,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Spellhit 'Complete Ancestor Ritual' - Run Script"),

(2543100,9,0,0,0,0,100,0,0,0,0,0,0,12,25397,3,60000,0,0,0,8,0,0,0,0,3640.4463,5619.086,33.224483,1.500983119010925292,"Kaskala Ancestor - On Script - Summon Creature 'Elder Kesuk'"),
(2543100,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45498,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Script - Cast 'Elder Kesuk Credit'"),

(2543101,9,0,0,0,0,100,0,0,0,0,0,0,12,25398,3,60000,0,0,0,8,0,0,0,0,3573.9446,5513.4355,27.129955,0.907571196556091308,"Kaskala Ancestor - On Script - Summon Creature 'Elder Sagani'"),
(2543101,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45499,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Script - Cast 'Elder Sagani Credit'"),

(2543102,9,0,0,0,0,100,0,0,0,0,0,0,12,25399,3,60000,0,0,0,8,0,0,0,0,3696.6863,5580.9136,32.97882,5.375614166259765625,"Kaskala Ancestor - On Script - Summon Creature 'Elder Takret'"),
(2543102,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45500,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kaskala Ancestor - On Script - Cast 'Elder Takret Credit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 25431 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,25431,0,0,30,0,191088,30,0,0,0,0,"","Group 0: Execute SAI (Action 0) if object 'Elder Kesuk' is within 30 yards"),
(22,2,25431,0,0,30,0,191089,30,0,0,0,0,"","Group 0: Execute SAI (Action 1) if object 'Elder Sagani' is within 30 yards"),
(22,3,25431,0,0,30,0,191090,30,0,0,0,0,"","Group 0: Execute SAI (Action 2) if object 'Elder Takret' is within 30 yards");
