-- Fix {Q/A} The Shining Light ID: 11288
-- Makes it blizzlike timed 10 minutes
UPDATE `quest_template` SET `LimitTime`=600 WHERE `id`=11288;
-- Decomposing Ghoul SAI
SET @Ghoul := 24177;
SET @SpellTrigger := 43202;
SET @Spell := 43203;
SET @Ares  := 24189;
UPDATE `creature_template` SET `AIname`='SmartAI' WHERE `entry`=@Ghoul;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Ghoul;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ghoul,0,0,0,1,0,100,0,20000,300000,50000,350000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - Occ - Say random text'),
(@Ghoul,0,1,2,8,0,100,0,@Spell,0,0,0,18,33685506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - On hit by spell - Set unit flag for not targetable'),
(@Ghoul,0,2,3,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - Linked with previous event - Switch faction to clear aggro'),
(@Ghoul,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - Linked with previous event - Say random text'),
(@Ghoul,0,4,5,1,0,100,0,3500,3500,3500,3500,19,33685506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - OOC for 3,5 sec - Remove unit flag'),
(@Ghoul,0,5,0,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Decomposing Ghoul - Linked with previous event - Change faction back to 14');
-- Add SAI for Ares - quest giver
UPDATE `creature_template` SET `AIname`='SmartAI' WHERE `entry`=@Ares;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Ares;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ares,0,0,0,19,0,100,0,11288,0,0,0,85,@SpellTrigger,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ares - On target quest accepted 11288 - Cast spell Shining Light');
-- Decomposing Ghoul texts
DELETE FROM `creature_text` WHERE `entry`=@Ghoul;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Ghoul,0,1,'Light... light so bright...',12,0,50,0,0,0,'Decomposing Ghoul - On spell hit'),
(@Ghoul,0,2,'ARGHHHH...',12,0,50,0,0,0,'Decomposing Ghoul - On spell hit'),
(@Ghoul,0,3,'Away... go...',12,0,50,0,0,0,'Decomposing Ghoul - On spell hit'),
(@Ghoul,0,4,'Bad light... hurt...',12,0,50,0,0,0,'Decomposing Ghoul - On spell hit'),
(@Ghoul,0,5,'BURNS! IT BURNS!',12,0,50,0,0,0,'Decomposing Ghoul - On spell hit'),
(@Ghoul,1,1,'So... Hungry...',12,0,50,0,0,0,'Decomposing Ghoul - OOC'),
(@Ghoul,1,2,'Closer... come closer...',12,0,50,0,0,0,'Decomposing Ghoul - OOC'),
(@Ghoul,1,3,'FEED ME...',12,0,50,0,0,0,'Decomposing Ghoul - OOC'),
(@Ghoul,1,4,'FOOD! EAT YOU!',12,0,50,0,0,0,'Decomposing Ghoul - OOC'),
(@Ghoul,1,5,'BRAINNNS!',12,0,50,0,0,0,'Decomposing Ghoul - OOC');
-- Add conditions for spell Shining Light to hit only Ghouls
DELETE FROM `conditions` WHERE `SourceEntry`=@Spell AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,@Spell,0,0,31,0,3,@Ghoul,0,0,0,'', 'Shinning Light can only hit Decomposing Ghouls');
-- Add conditions for spell Shining Light to be available only, if on quest
DELETE FROM `conditions` WHERE `SourceEntry`=@Spell AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,@Spell,0,0,9,0,11288,0,0,0,0,'', 'Shinning Light can only hit targets on the quest');
