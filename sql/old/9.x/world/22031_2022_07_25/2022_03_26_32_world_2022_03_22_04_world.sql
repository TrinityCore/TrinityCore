--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26359 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26359,0,0,0,8,0,100,0,47431,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ice Heart Jormungar Spawn - On Spellhit 'Capture Jormungar Spawn' - Despawn"),
(26359,0,1,0,0,0,100,0,5000,15000,10000,15000,0,11,43358,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ice Heart Jormungar Spawn - In Combat - Cast 'Gut Rip'");

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 190510;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 190510 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(190510,1,0,0,60,0,100,0,3000,3000,3000,3000,0,147,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Jormungar Spawn - On Update - Activate Object (Animate Custom0)");

-- Previous condition allowed to use item only in specific zone, it's wrong at least because it allows to use it even without target
-- Custom error specifies that it can be used only on Ice Heart Jormungar Spawn but that error looks unused because
-- when used on wrong target it only throws Invalid target error, nothing else. Keeping for now
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 47431;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,47431,0,0,31,1,3,26359,0,0,172,21,"","Group 0: Spell 'Capture Jormungar Spawn' targets creature 'Ice Heart Jormungar Spawn'");
