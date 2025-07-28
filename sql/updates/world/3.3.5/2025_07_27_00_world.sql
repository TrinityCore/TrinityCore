-- Misc
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22104 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_fathomlord_karathress_cyclone' WHERE `entry` = 22104;

DELETE FROM `creature_formations` WHERE `leaderGUID` = 93766;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(93766,93766,0,0,3,0,0),
(93766,93765,0,0,3,0,0),
(93766,82975,0,0,3,0,0),
(93766,82976,0,0,3,0,0);

-- Pets
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_fathomlord_karathress_the_beast_within';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38373, 'spell_fathomlord_karathress_the_beast_within');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 38371;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,38371,0,0,31,0,3,22119,0,0,0,0,"","Group 0: Spell 'Bestial Wrath' (Effect 0, 1, 2) targets creature 'Fathom Lurker'"),
(13,7,38371,0,1,31,0,3,22120,0,0,0,0,"","Group 1: Spell 'Bestial Wrath' (Effect 0, 1, 2) targets creature 'Fathom Sporebat'");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22119,22120) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22119,0,0,0,37,0,100,0,0,0,0,0,0,116,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Lurker - On AI Initialize - Set Corpse Delay"),
(22119,0,1,0,11,0,100,0,0,0,0,0,0,11,39795,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Lurker - On Spawn - Cast 'Spawn with Stun (2.0s)'"),
(22119,0,2,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Lurker - On Spawn - Set In Combat With Zone"),
(22119,0,3,0,0,0,100,0,5000,10000,10000,20000,0,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fathom Lurker - In Combat - Cast 'Knock Away'"),
(22119,0,4,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Lurker - On Evade - Despawn"),

(22120,0,0,0,37,0,100,0,0,0,0,0,0,116,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Sporebat - On AI Initialize - Set Corpse Delay"),
(22120,0,1,0,11,0,100,0,0,0,0,0,0,11,39795,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Sporebat - On Spawn - Cast 'Spawn with Stun (2.0s)'"),
(22120,0,2,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Sporebat - On Spawn - Set In Combat With Zone"),
(22120,0,3,0,0,0,100,0,5000,10000,10000,20000,0,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fathom Sporebat - In Combat - Cast 'Knock Away'"),
(22120,0,4,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fathom Sporebat - On Evade - Despawn");

-- Totems
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (22487,22091);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22487,22486,22091) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22487,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Greater Poison Cleansing Totem - On AI Initialize - Set Reactstate Passive"),
(22487,0,1,0,11,0,100,0,0,0,0,0,0,11,32187,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Greater Poison Cleansing Totem - On Spawn - Cast 'Water Totem Transform'"),

(22486,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Greater Earthbind Totem - On AI Initialize - Set Reactstate Passive"),
(22486,0,1,0,11,0,100,0,0,0,0,0,0,11,32184,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Greater Earthbind Totem - On Spawn - Cast 'Earth Totem Transform'"),
(22486,0,2,0,11,0,100,0,0,0,0,0,0,11,6474,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Greater Earthbind Totem - On Spawn - Cast 'Earthbind Totem Passive'"),

(22091,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spitfire Totem - On AI Initialize - Set Reactstate Passive"),
(22091,0,1,0,11,0,100,0,0,0,0,0,0,11,32186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spitfire Totem - On Spawn - Cast 'Fire Totem Transform'"),
(22091,0,2,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spitfire Totem - On Spawn - Set In Combat With Zone"),
(22091,0,3,0,0,0,100,0,10000,15000,2000,7000,0,11,38296,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spitfire Totem - In Combat - Cast 'Attack'");

-- Seer Olum
DELETE FROM `creature` WHERE `guid` = 40193 AND `id` = 22820;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(40193,22820,548,0,0,1,1,0,0,451.099,-544.984,-7.46327,0.174533,300,0,0,0,0,0,0,0,0,'',NULL,0);
