-- Fix several quest gameobjects in Coldridge Valley
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry` IN (201608,201609,201610,201611,201704,201705,201706);

-- Scripts
UPDATE `creature_template` SET `ScriptName`= 'npc_wounded_coldridge_mountaineer' WHERE `entry`=37080;
UPDATE `creature_template` SET `ScriptName`= 'npc_wounded_milita' WHERE `entry`=44405;
UPDATE `creature_template` SET `ScriptName`= 'npc_milos_gyro' WHERE `entry`=37198;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_a_trip_to_ironforge_quest_complete',
'spell_follow_that_gyrocopter_quest_start',
'spell_low_health');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70046, 'spell_a_trip_to_ironforge_quest_complete'),
(70047, 'spell_follow_that_gyrocopter_quest_start'),
(76143, 'spell_low_health');
