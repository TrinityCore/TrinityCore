--
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 34879;

DELETE FROM `creature_template_addon` WHERE `entry` = 34888;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(34888,0,0,0,0,1,0,0,'37119 66419');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34852,34888) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3485200,3488800,3488801) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34852,0,0,0,8,0,100,0,66390,0,0,0,0,80,3485200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slain Tualiq Villager - On Spellhit 'Read Last Rites' - Run Script"),

(3485200,9,0,0,0,0,100,0,0,0,0,0,0,33,34852,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Slain Tualiq Villager - On Script - Quest Credit 'The Light's Mercy'"),
(3485200,9,1,0,0,0,100,0,0,0,0,0,0,11,66411,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slain Tualiq Villager - On Script - Cast 'Summon Tualiq Proxy'"),
(3485200,9,2,0,0,0,100,0,1000,1000,0,0,0,11,66412,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slain Tualiq Villager - On Script - Cast 'Summon Tualiq Spirit'"),
(3485200,9,3,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Slain Tualiq Villager - On Script - Despawn"),

/* Something weird happens here
Position: X: 10100.81 Y: 1227.5642 Z: 79.187256 Summoner
Position: X: 10100.81 Y: 1227.5642 Z: 109.27059 Proxy (30.083334 from summoner)
Position: X: 10100.81 Y: 1227.5642 Z: 80.27059  Spirit hover to (1.083334 from summoner)
Waypoint: X: 10100.81 Y: 1227.5642 Z: 105.27059 Spirit move to (25 from hover to, 4 from proxy)
Position: X: 10100.8125 Y: 1227.564 Z: 104.06733 Spirit stops */

(34888,0,0,0,11,0,100,0,0,0,0,0,0,80,3488800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tualiq Spirit - On Spawn - Run Script"),
(34888,0,1,0,34,0,100,0,8,0,0,0,0,80,3488801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tualiq Spirit - On Reached Point 0 - Run Script"),

(3488800,9,0,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tualiq Spirit - On Script - Set Run Off"),
(3488800,9,1,0,0,0,100,0,1000,1000,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,0,0,25,0,"Tualiq Spirit - On Script - Rise Up"),

(3488801,9,0,0,0,0,100,0,1000,1000,0,0,0,11,57771,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tualiq Spirit - On Script - Cast 'Holy Nova'"),
(3488801,9,1,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tualiq Spirit - On Script - Despawn");

DELETE FROM `spell_script_names` WHERE `spell_id` = 66411 AND `ScriptName` = 'spell_summon_tualiq_proxy';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(66411,'spell_summon_tualiq_proxy');
