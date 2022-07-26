-- 12943 Shadow Vault Decree
DELETE FROM `spell_script_names` WHERE `spell_id` = 31696 AND `ScriptName` = 'spell_gen_player_say';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(31696,'spell_gen_player_say');

DELETE FROM `creature_text` WHERE `CreatureID` = 29919 AND `GroupID` = 1;

-- 13048 Where Time Went Wrong
DELETE FROM `spell_script_names` WHERE (
`spell_id` = 56796 AND `ScriptName` = 'spell_gen_player_say' OR
`spell_id` = 56797 AND `ScriptName` = 'spell_gen_player_say');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56796,'spell_gen_player_say'),
(56797,'spell_gen_player_say');

-- 11993, 12058 The Runic Prophecies
DELETE FROM `spell_script_names` WHERE (
`spell_id` = 47062 AND `ScriptName` = 'spell_gen_player_say' OR
`spell_id` = 47063 AND `ScriptName` = 'spell_gen_player_say' OR
`spell_id` = 47064 AND `ScriptName` = 'spell_gen_player_say');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47062,'spell_gen_player_say'),
(47063,'spell_gen_player_say'),
(47064,'spell_gen_player_say');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26445 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 26445;
DELETE FROM `creature_text` WHERE `CreatureID` = 26445;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (188264,188288,188289) AND `source_type` = 1;
UPDATE `gameobject_template` SET `AIName` = '' WHERE `entry` IN (188264,188288,188289);

-- 12645 The Taste Test
DELETE FROM `spell_script_names` WHERE `spell_id` = 51962 AND `ScriptName` = 'spell_gen_player_say';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51962,'spell_gen_player_say');

-- 12550 Dreadsaber Mastery: Stalking the Prey
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_player_say' WHERE `spell_id` = 52160 AND `ScriptName` = 'spell_shango_tracks';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_player_say' WHERE `spell_id` = 52163 AND `ScriptName` = 'spell_shango_tracks';

-- 12920 Catching up with Brann
DELETE FROM `spell_script_names` WHERE (
`spell_id` = 55589 AND `ScriptName` = 'spell_gen_player_say' OR
`spell_id` = 55590 AND `ScriptName` = 'spell_gen_player_say');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(55589,'spell_gen_player_say'),
(55590,'spell_gen_player_say');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 2957900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2957900,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 0"),
(2957900,9,1,0,0,0,100,0,3000,3000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Play Emote 25"),
(2957900,9,2,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 1"),
(2957900,9,3,0,0,0,100,0,6000,6000,0,0,0,11,55589,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Cast 'Brann: Force player to speak 1'"),
(2957900,9,4,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 3"),
(2957900,9,5,0,0,0,100,0,7000,7000,0,0,0,11,55590,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Cast 'Brann: Force player to speak 2'"),
(2957900,9,6,0,0,0,100,0,6000,6000,0,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 5"),
(2957900,9,7,0,0,0,100,0,7000,7000,0,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 6"),
(2957900,9,8,0,0,0,100,0,7000,7000,0,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 7"),
(2957900,9,9,0,0,0,100,0,7000,7000,0,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 8"),
(2957900,9,10,0,0,0,100,0,7000,7000,0,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Say Line 9"),
(2957900,9,11,0,0,0,100,0,7000,7000,0,0,0,33,29579,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brann Bronzebeard - On Script - Quest Credit 'Catching up with Brann'");

DELETE FROM `creature_text` WHERE `CreatureID` = 29579 AND `GroupID` IN (2,4);

-- Not player talk / just talk
UPDATE `smart_scripts` SET `action_type` = 1, `target_type` = 1, `target_param1` = 0 WHERE `entryorguid` = 13716 AND `source_type` = 0 AND `action_type` = 84;
UPDATE `smart_scripts` SET `action_type` = 1 WHERE `entryorguid` = 330100 AND `source_type` = 9 AND `action_type` = 84;
UPDATE `smart_scripts` SET `action_type` = 1 WHERE `entryorguid` = 28665 AND `source_type` = 0 AND `action_type` = 84;
