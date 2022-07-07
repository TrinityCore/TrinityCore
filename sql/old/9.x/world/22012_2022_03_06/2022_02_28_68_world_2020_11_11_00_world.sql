-- Tonk Mine SAI
SET @ID := 15368;
UPDATE `creature_template` SET `speed_run` = 1, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Just Summoned - Run Script"),
(@ID,0,1,2,31,0,100,0,28000,0,0,0,0,11,25099,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Target Spellhit 'Land Mine Trigger' - Cast 'Detonation'"),
(@ID,0,2,3,61,0,100,0,0,0,0,0,0,28,27999,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Link - Remove Aura 'Land Mine Periodic'"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Link - Despawn (2000)"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,11816,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Script - Cast 'Land Mine Arming'"),
(@ID*100+0,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,3000,3000,0,0,0,28,11816,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Script - Remove Aura 'Land Mine Arming'"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,11,27999,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Script - Cast 'Land Mine Periodic'"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tonk Mine - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s will be armed in 3 seconds!",16,0,100,0,0,0,10894,0,"Tonk Mine"),
(@ID,1,0,"%s is now armed!",16,0,100,0,0,0,3543,0,"Tonk Mine");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (25099,28000);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,25099,0,0,31,0,3,19405,0,0,0,0,"","Group 0: Spell 'Land Mine Trigger' (Effect 0) targets creature 'Steam Tonk'"),
-- Dunno if owner should be affected or not
(13,1,28000,0,0,31,0,3,19405,0,0,0,0,"","Group 0: Spell 'Detonation' (Effect 0) targets creature 'Steam Tonk'");

-- Missing spells for tonk
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 19405 AND `Index` IN (1,2);
INSERT INTO `creature_template_spell` (`CreatureID`,`Index`,`Spell`,`VerifiedBuild`) VALUES
(19405,1,25003,0),
(19405,2,25024,0);
