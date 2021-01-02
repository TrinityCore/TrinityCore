-- Reth'hedron the Subduer
UPDATE `creature` SET `spawntimesecs`=300 WHERE `id`=22357;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22357;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22357 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2235700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- We have to add condition and Say Line 0 only if player is on quest
-- but conditions are not supported for victim target, so we will say only if aura is applied
-- Quite possible it is exactly how it is implemented
-- Phase is added only to say nothing after he's defeated
(22357,0,0,0,4,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Aggro - Set Event Phase 1"),
(22357,0,1,0,0,1,50,0,15000,20000,15000,20000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - In Combat - Say Line 0 (Phase 1)"),
(22357,0,2,0,0,0,100,0,3000,5000,3000,5000,0,11,41280,64,0,0,0,0,2,0,0,0,0,0,0,0,"Reth'hedron the Subduer - In Combat - Cast 'Shadow Bolt'"),
(22357,0,3,0,0,0,100,0,12000,16000,12000,16000,0,11,41281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reth'hedron the Subduer - In Combat - Cast 'Cripple'"),
(22357,0,4,0,0,0,100,0,2000,2000,2000,2000,0,11,41288,0,0,0,0,0,2,0,0,0,0,0,0,0,"Reth'hedron the Subduer - In Combat - Cast 'Reth'hedron Knockdown: The Bolt Trigger'"),
(22357,0,5,6,17,0,100,0,0,0,0,0,0,11,41283,0,512,0,0,0,7,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Summoned Unit - Cast 'Abyssal Toss'"),
(22357,0,6,0,61,0,100,0,0,0,0,0,0,4,10667,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Play Sound 10667"),

(22357,0,7,8,2,0,100,1,0,10,0,0,0,46,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - Between 0-10% Health - Stop Attack (No Repeat)"),
(22357,0,8,9,61,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Set Reactstate Passive"),
(22357,0,9,10,61,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Set Invicibility 1 HP"),
(22357,0,10,11,61,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Set Event Phase 0"),
(22357,0,11,12,61,0,100,0,0,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Disable Evade"),
(22357,0,12,0,61,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,-1502.39,9772.33,200.421,0,"Reth'hedron the Subduer - On Link - Move to Position"),

(22357,0,13,0,34,0,100,0,8,1,0,0,0,80,2235700,1,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Reached Point 1 - Run Script"),

(22357,0,14,15,34,0,100,0,8,2,0,0,0,11,41340,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Reached Point 2 - Cast 'Reth'hedron Quest Complete'"),
(22357,0,15,16,61,0,100,0,0,0,0,0,0,11,41339,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Cast 'Cosmetic - Legion Ring Purple Lightning (Self)'"),
(22357,0,16,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Link - Despawn"),

(2235700,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron the Subduer - On Script - Say Line 1"),
(2235700,9,1,0,0,0,100,0,3000,3000,0,0,0,69,2,0,0,0,0,0,8,0,0,0,-1557.93,9834.34,200.949,0,"Reth'hedron the Subduer - On Script - Move to Position");

DELETE FROM `creature_text` WHERE `CreatureID`=22357;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22357,0,0,"What do you hope to accomplish from this, insect?",14,0,100,0,0,0,21556,0,"Reth'hedron the Subduer"),
(22357,0,1,"I WILL CRUSH YOU LIKE A GNAT!",14,0,100,0,0,0,21557,0,"Reth'hedron the Subduer"),
(22357,0,2,"You cannot stop us!",14,0,100,0,0,0,21558,0,"Reth'hedron the Subduer"),
(22357,0,3,"You are making me angry, mortal!",14,0,100,0,0,0,21559,0,"Reth'hedron the Subduer"),
(22357,0,4,"I will break you in two! Relent, fool!",14,0,100,0,0,0,21560,0,"Reth'hedron the Subduer"),
(22357,0,5,"Flee now while you still have your life!",14,0,100,0,0,0,21561,0,"Reth'hedron the Subduer"),
(22357,1,0,"You will regret this, mortal! Reth'hedron will return... I will have my vengeance!",14,0,100,53,0,0,21606,0,"Reth'hedron the Subduer");

-- Spell "Reth'hedron Knockdown: The Bolt Trigger"
UPDATE `spell_dbc` SET `Effect1`=28, `EffectImplicitTargetA1`=25, `EffectMiscValue1`=23416, `EffectMiscValueB1`=64 WHERE `Id`=41288;

-- Reth'hedron's Target
DELETE FROM `creature_template_movement` WHERE `CreatureId`=23416;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(23416,0,0,1,0,0,0);

UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=128 WHERE `entry`=23416;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23416 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23416,0,0,0,8,0,100,0,41283,0,0,0,0,11,41284,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron's Target - On Spell Hit 'Abyssal Toss' - Cast 'Abyssal Impact'"),
(23416,0,1,0,11,0,100,0,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reth'hedron's Target - On Spawn - Despawn after 30 seconds");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41284;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,41284,0,0,31,0,3,23416,0,1,0,0,"","Spell 'Abyssal Impact' cannot affect Reth'hedron's Target");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22357 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,22357,0,0,1,1,41291,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if creature does have aura 'Soul Cannon'"),
(22,8,22357,0,0,1,1,41291,0,0,0,0,0,"","Group 0: Execute SAI (Action 7) if creature does have aura 'Soul Cannon'");
