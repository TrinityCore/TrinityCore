--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_brewfest_botm_the_beast_within','spell_brewfest_botm_gassy','spell_brewfest_botm_jungle_madness');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50098,'spell_brewfest_botm_the_beast_within'),
(49864,'spell_brewfest_botm_gassy'),
(49962,'spell_brewfest_botm_jungle_madness');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27908;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27908 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2790800,2790801) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27908,0,0,0,11,0,100,0,0,0,0,0,0,80,2790800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Spawn - Run Script"),
(27908,0,1,0,34,0,100,0,8,1,0,0,0,80,2790801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Reached Point 1 - Run Script"),

(2790800,9,0,0,0,0,100,0,0,0,0,0,0,11,50008,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Cast 'BOTM - Jungle Brew - Jungle Invisibility Aura'"),
(2790800,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Set Orientation Summoner"),
(2790800,9,2,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,3,0,0,23,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Move To Summoner"),

(2790801,9,0,0,0,0,100,0,1000,1000,0,0,0,11,49965,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Cast 'BOTM - Jungle Brew - Jungle Madness Scared'"),
(2790801,9,1,0,0,0,100,0,3000,3000,0,0,0,11,50048,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Cast 'BOTM - Jungle Brew - Jungle Gnome Vanish Aura'"),
(2790801,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Angry Jungle Gnome - On Script - Despawn");
