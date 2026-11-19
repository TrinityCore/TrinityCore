-- Thornling SAI (Source: Sniffs & https://www.youtube.com/watch?v=uySnF_Ks8VA & https://www.youtube.com/watch?v=YDB9P2sEqug)
SET @ID := 14362;
UPDATE `creature_template` SET `speed_walk` = 1, `RangeAttackTime` = 2000, `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,1436200,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Just Summoned - Run Script"),

-- Besides root and prevent melee flag we also have to make him passive or he'll act like normal creature
-- There's no passive flag for him in CreatureDifficulty, unfortunately
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,11,22788,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Cast 'Grow'"),
(@ID*100+0,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Say Line 1"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,11,22788,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Cast 'Grow'"),
(@ID*100+0,9,5,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Say Line 2"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,11,22788,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Cast 'Grow'"),
-- Not 22787, no stun flag or spell cast itself
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,11,22781,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thornling - On Script - Cast 'Thornling'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s begins to grow!",16,0,100,0,0,0,9374,0,"Thornling"),
(@ID,1,0,"%s continues to grow!",16,0,100,0,0,0,9375,0,"Thornling"),
(@ID,2,0,"%s has grown to full size!",16,0,100,0,0,0,9376,0,"Thornling");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = @ID;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(@ID,1,1,0,1,0,0);

UPDATE `creature_model_info` SET `BoundingRadius` = 0.2, `CombatReach` = 0.3 WHERE `DisplayID` = 14392;
