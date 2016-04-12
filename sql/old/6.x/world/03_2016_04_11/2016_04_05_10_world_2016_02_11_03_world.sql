-- DB/Quest: Souls at Unrest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=48974;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 48974, 0, 0, 31, 1, 3, 26891, 0, 0, 0, 0, '', 'Burn Corpse - only targets Undead Miner'),
(17, 0, 48974, 0, 0, 36, 1, 0, 0, 0, 1, 0, 0, '', 'Burn Corpse - only targets dead Undead Miner');

-- Undead Miner SAI
SET @ENTRY := 26891;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,8,0,100,0,48974,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Undead Miner - On Spellhit 'Burn Corpse' - Despawn In 2000 ms");
