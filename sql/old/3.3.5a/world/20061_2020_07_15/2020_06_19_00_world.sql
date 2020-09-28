-- 
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4762;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4762,"SmartTrigger");

DELETE FROM `creature` WHERE `id` = 24137;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (24137,23746);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24137,-126049) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4762 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4762,2,0,0,46,0,100,0,4762,0,0,0,0,45,1,1,0,0,0,0,19,23746,0,0,0,0,0,0,0,"Areatrigger (Utgarde Keep) - On Trigger - Set data"),
(-126049,0,0,0,38,0,100,1,1,1,0,0,0,12,24137,8,0,0,0,0,8,0,0,0,0,207.48018,-68.84115,23.854694,3.333578,"Zul'Aman Exterior InvisMan - On data set - Summon creature"),
(24137,0,0,1,11,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Ranger Marrah - On Respawn - Remove NPC Flag Questgiver and gossip"),
(24137,0,1,0,61,0,100,1,0,1,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,183.85152,-76.50118,15.842874,3.45508,"Dark Ranger Marrah - On Data Set 0 1 - Move To Position (No Repeat)"),
(24137,0,2,3,34,0,100,0,8,1,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Ranger Marrah - On Reached Point 1 - Remove Flag Standstate Sit Down"),
(24137,0,3,4,61,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Ranger Marrah - On Link - Add NPC Flag Questgiver and gossip"),
(24137,0,4,0,61,0,100,0,0,0,0,0,0,28,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Ranger Marrah - On Link - Remove Aura 'Stealth'");
DELETE FROM conditions WHERE SourceTypeOrReferenceId=22 AND SourceId=2 AND SourceEntry IN (4762);
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES
(22, 1, 4762, 2, 0, 6, 0, 67, 0, 0, 0, 0, 0, "", "Area trigger 4762 sai Summon Marrah only for the horde");

