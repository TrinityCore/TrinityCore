-- Add support for {Q} A Tangled Skein ID: 12555
-- rewritten from sniff: thx Pitcrawler
SET @Sprayer :=       28274;
SET @Thrower :=       51165; -- Throws a web
SET @Summon :=        51314; -- Summons Broken Sprayer GO
SET @Explosion :=     53236; -- Explosion on fall
SET @Credit :=        28289; -- Kill Credit
SET @Trigger :=       29457; -- Trigger to permit explosion only when Sprayer reach him
SET @SpellTrigger :=  51173; -- A Tangled Skein: Encasing Webs - Effect that procs from @Thrower
SET @EncasingWebs :=  51168; -- The visual that A Tangled Skein: Encasing Webs - Effect should apply
SET @SummonTrigger := 54496;
SET @Script :=      2827400;
-- Add SAI support for Plague Sprayer
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sprayer; -- they shouldn't be attackable, but unit_flag 2 cause evade
UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=1 WHERE `entry`=@Trigger; -- need this to make trigger (while guardian) stay at ground
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Sprayer,@Trigger) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Script AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Trigger,0,0,0,54,0,100,0,0,0,0,0,75,@EncasingWebs,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Sprayer - On just summoned - Cast Encasing Webs'),
(@Sprayer,0,0,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Sprayer - On spawn/reset - Set react state passive'),
(@Sprayer,0,1,0,8,0,100,1,@Thrower,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Plagued Sprayer - On spell hit by player with thrower - Store invoker as target'),
(@Sprayer,0,2,3,8,0,100,1,@SpellTrigger,0,0,0,11,@SummonTrigger,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Sprayer - On spell hit by item spell - Cast summon trigger'),
(@Sprayer,0,3,0,61,0,100,1,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Sprayer - Linked with previous event - Set run on'),
(@Sprayer,0,4,0,23,0,100,1,@EncasingWebs,1,0,0,69,1,0,0,0,0,0,19,@Trigger,20,0,0,0,0,0, 'Plagued Sprayer - On creature has aura Encasing Webs - Move to closest trigger in 20 yards'),
(@Sprayer,0,5,0,34,0,100,1,8,1,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Sprayer - On point 1 reached - Start action list'),
-- Script
(@Script,9,0,0,0,0,100,0,0,0,0,0,11,@Explosion,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Sprayer - Action 0 - Cast huge explosion on self'),
(@Script,9,1,0,0,0,100,0,300,300,0,0,33,@Credit,0,0,0,0,0,12,1,0,0,0,0,0,0,'Plagued Sprayer - Action 1 - Give credit to stored invoker'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,11,@Summon,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Sprayer - Action 2 - Cast summon broken GO sprayer on self'), -- need small delay for the explosion to be displayed
(@Script,9,3,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Sprayer - Action 3 - Die'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Plagued Sprayer - Action 4 - Set unseen');
-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`=@Thrower AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17,0,@Thrower,0,0,31,1,3,@Sprayer,0,0,0,'', 'Thrower can target only Plague Sprayer');
-- Delete wrong, nonexistant Trigger spawn
DELETE FROM `creature` WHERE `id`=@Trigger;
-- Update creature data for plague sprayers they should have movement type 0
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=@Sprayer;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=28274;
