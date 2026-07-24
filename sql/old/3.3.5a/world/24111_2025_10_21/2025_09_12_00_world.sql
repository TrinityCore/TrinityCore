--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (25790,25792);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,25790,0,0,31,0,3,15511,0,0,0,0,"","Group 0: Spell 'Vengeance' (Effect 0, 1, 2) targets creature 'Lord Kri'"),
(13,7,25790,0,1,31,0,3,15543,0,0,0,0,"","Group 1: Spell 'Vengeance' (Effect 0, 1, 2) targets creature 'Princess Yauj'"),
(13,7,25790,0,2,31,0,3,15544,0,0,0,0,"","Group 2: Spell 'Vengeance' (Effect 0, 1, 2) targets creature 'Vem'"),
(13,1,25792,0,0,31,0,3,15621,0,0,0,0,"","Group 0: Spell 'Despawn Brood' (Effect 0) targets creature 'Yauj Brood'");

DELETE FROM `creature_formations` WHERE `leaderGUID` = 87603;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(87603,87603,0,0,3,0,0),
(87603,87601,0,0,3,0,0),
(87603,87602,0,0,3,0,0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (15621,15933);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15621,15933) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15621,0,0,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Yauj Brood - On Spawn - Set In Combat With Zone"),
(15621,0,1,0,8,0,100,0,25792,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Yauj Brood - On Spellhit 'Despawn Brood' - Despawn"),

(15933,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Poison Cloud - On AI Initialize - Set Reactstate Passive"),
(15933,0,1,0,11,0,100,0,0,0,0,0,0,11,25786,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Poison Cloud - On Spawn - Cast 'Toxic Vapors'"),
(15933,0,2,0,11,0,100,0,0,0,0,0,0,11,26575,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Poison Cloud - On Spawn - Cast 'Toxin'");
