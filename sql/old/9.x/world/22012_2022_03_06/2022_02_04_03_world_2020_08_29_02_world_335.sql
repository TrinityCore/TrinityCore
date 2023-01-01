-- (Source: https://www.youtube.com/watch?v=S9lrdq0AeoM)
-- It's unclear can they enter in combat or not and what exactly should happen with action lists in combat
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4781 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (478100,478101) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4781,0,0,1,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Just Summoned - Say Line 0"),
(4781,0,1,2,61,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Link - Set Event Phase 1"),
(4781,0,2,0,61,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Link - Set Reactstate Passive"),
(4781,0,3,0,8,1,100,0,8283,0,0,0,0,80,478100,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Spellhit 'Snufflenose Command' - Run Script (Phase 1)"),
(4781,0,4,0,34,0,100,0,8,1,0,0,0,80,478101,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Reached Point 1 - Run Script"),

(478100,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Say Line 1"),
(478100,9,1,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Set Event Phase 2"),
(478100,9,2,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Set Run Off"),
(478100,9,3,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Move To Self"),
(478100,9,4,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Say Line 2"),
(478100,9,5,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,1,0,0,20,20919,30,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Move to Closest Gameobject 'Tuber Node'"),

(478101,9,0,0,0,0,100,0,3000,3000,0,0,0,11,6900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Cast 'Create Tuber'"),
(478101,9,1,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,20919,5,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Despawn Closest Gameobject 'Tuber Node'"),
(478101,9,2,0,0,0,100,0,2000,2000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Set Event Phase 1"),
(478101,9,3,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Set Run On"),
(478101,9,4,0,0,0,100,0,0,0,0,0,0,29,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Snufflenose Gopher - On Script - Start Follow Owner");

-- It's unclear what should happen if there's no tubers nearby
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4781 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,4,4781,0,0,30,0,20919,30,0,0,0,0,"","Group 0: Execute SAI (Action 3) if gameobject 'Tuber Node' is near");
