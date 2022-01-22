--
DELETE FROM `spell_script_names` WHERE `spell_id` = 47304 AND `ScriptName` = 'spell_warsong_battle_standard';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47304,'spell_warsong_battle_standard');

UPDATE `creature_template` SET `maxlevel` = 70, `speed_run` = 1, `unit_flags` = 256, `unit_flags2` = 0 WHERE `entry` = 26678;
DELETE FROM `creature_text` WHERE `CreatureID` = 26678 AND `GroupID` = 1;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26678 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2667800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26678,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On AI Initialize - Set Reactstate Passive"),
(26678,0,1,0,11,0,100,0,0,0,0,0,0,80,2667800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Spawn - Run Script"),
(26678,0,2,0,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Death - Say Line 0"),
(26678,0,3,0,6,0,100,0,0,0,0,0,0,6,12053,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Death - Fail Quest 'The Might of the Horde'"),

(2667800,9,0,0,0,0,100,0,0,0,0,0,0,11,23235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Battle Standard Spawn'"),
(2667800,9,1,0,0,0,100,0,2000,2000,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,2,0,0,0,100,0,15000,15000,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,3,0,0,0,100,0,15000,15000,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,4,0,0,0,100,0,0,0,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,5,0,0,0,100,0,25000,25000,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,6,0,0,0,100,0,15000,15000,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,7,0,0,0,100,0,0,0,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,8,0,0,0,100,0,0,0,0,0,0,11,47303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Cast 'Summon Anub'ar Invader'"),
(2667800,9,9,0,0,0,100,0,20000,20000,0,0,0,15,12053,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Quest Credit 'The Might of the Horde'"),
(2667800,9,10,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warsong Battle Standard - On Script - Despawn");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26676 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26676,0,0,0,37,0,100,0,0,0,0,0,0,116,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anub'ar Invader - On AI Initialize - Set Corpse Delay"),
(26676,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Anub'ar Invader - On Spawn - Start Attack Summoner"),
(26676,0,2,0,11,0,50,0,0,0,0,0,0,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,0,"Anub'ar Invader - On Spawn - Say Line 0"),
(26676,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anub'ar Invader - On Evade - Despawn");
