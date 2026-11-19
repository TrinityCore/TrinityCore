--
UPDATE `gameobject_template` SET `ScriptName` = '' WHERE `entry` = 186649;

UPDATE `conditions` SET `SourceGroup` = 7 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 50218;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -43351;

DELETE FROM `spell_script_names` WHERE
(`spell_id` = 43365 AND `ScriptName` = 'spell_the_cleansing_shrine_cast') OR
(`spell_id` = 43351 AND `ScriptName` = 'spell_the_cleansing_cleansing_soul') OR
(`spell_id` = 50217 AND `ScriptName` = 'spell_the_cleansing_mirror_image_script_effect') OR
(`spell_id` = 50238 AND `ScriptName` = 'spell_the_cleansing_on_death_cast_on_master') OR
(`spell_id` = 39823 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 39825 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40201 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40203 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40204 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40205 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40206 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40207 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40208 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40210 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40213 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40217 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40218 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40233 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40252 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 40352 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50014 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50023 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50219 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50221 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50222 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 50223 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 53374 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 60807 AND `ScriptName` = 'spell_gen_whisper_to_controller') OR
(`spell_id` = 60811 AND `ScriptName` = 'spell_gen_whisper_to_controller');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(43365,'spell_the_cleansing_shrine_cast'),
(43351,'spell_the_cleansing_cleansing_soul'),
(50217,'spell_the_cleansing_mirror_image_script_effect'),
(50238,'spell_the_cleansing_on_death_cast_on_master'),
(39823,'spell_gen_whisper_to_controller'),
(39825,'spell_gen_whisper_to_controller'),
(40201,'spell_gen_whisper_to_controller'),
(40203,'spell_gen_whisper_to_controller'),
(40204,'spell_gen_whisper_to_controller'),
(40205,'spell_gen_whisper_to_controller'),
(40206,'spell_gen_whisper_to_controller'),
(40207,'spell_gen_whisper_to_controller'),
(40208,'spell_gen_whisper_to_controller'),
(40210,'spell_gen_whisper_to_controller'),
(40213,'spell_gen_whisper_to_controller'),
(40217,'spell_gen_whisper_to_controller'),
(40218,'spell_gen_whisper_to_controller'),
(40233,'spell_gen_whisper_to_controller'),
(40252,'spell_gen_whisper_to_controller'),
(40352,'spell_gen_whisper_to_controller'),
(50014,'spell_gen_whisper_to_controller'),
(50023,'spell_gen_whisper_to_controller'),
(50219,'spell_gen_whisper_to_controller'),
(50221,'spell_gen_whisper_to_controller'),
(50222,'spell_gen_whisper_to_controller'),
(50223,'spell_gen_whisper_to_controller'),
(53374,'spell_gen_whisper_to_controller'),
(60807,'spell_gen_whisper_to_controller'),
(60811,'spell_gen_whisper_to_controller');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27959 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2795900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27959,0,0,0,37,0,100,0,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On AI Initialize - Set Corpse Delay"),
(27959,0,1,0,11,0,100,0,0,0,0,0,0,80,2795900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Spawn - Run Script"),
(27959,0,2,0,2,0,100,1,0,50,0,0,0,11,50222,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - Between 0-50% Health - Cast 'The Cleansing: Your Inner Turmoil's Whisper to Controller - On Health 50%' (No Repeat)"),
(27959,0,3,0,6,0,100,0,0,0,0,0,0,11,50223,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Death - Cast 'The Cleansing: Your Inner Turmoil's Whisper to Controller - On Death'"),
(27959,0,4,0,6,0,100,0,0,0,0,0,0,11,50238,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Death - Cast 'The Cleansing: Your Inner Turmoil's On Death Cast on Master'"),
-- It has SPELL_ATTR3_DEATH_PERSISTENT but actually is removed after death, maybe not manually
-- Kinda odd because it makes creature invisible, but Copy Weapon auras are not removed, so only weapons are visible without body
(27959,0,5,0,6,0,100,0,0,0,0,0,0,28,50218,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Death - Remove Aura 'The Cleansing: Your Inner Turmoil's Mirror Image Aura'"),

(2795900,9,0,0,0,0,100,0,0,0,0,0,0,11,50217,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Cast 'The Cleansing: Script Effect Player Cast Mirror Image'"),
(2795900,9,1,0,0,0,100,0,0,0,0,0,0,11,41408,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Cast 'Shadowform'"),
(2795900,9,2,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Set Orientation Summoner"),
(2795900,9,3,0,0,0,100,0,0,0,0,0,0,11,50219,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Cast 'The Cleansing: Your Inner Turmoil's Whisper to Controller - Spawn 01'"),
(2795900,9,4,0,0,0,100,0,0,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Play Emote 1"),
(2795900,9,5,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Set Orientation Summoner"),
(2795900,9,6,0,0,0,100,0,0,0,0,0,0,11,50221,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Cast 'The Cleansing: Your Inner Turmoil's Whisper to Controller - Spawn 02'"),
(2795900,9,7,0,0,0,100,0,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Play Emote 25"),
-- Yes, again
(2795900,9,8,0,0,0,100,0,6000,6000,0,0,0,11,50217,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Cast 'The Cleansing: Script Effect Player Cast Mirror Image'"),
(2795900,9,9,0,0,0,100,0,0,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Set ImmunePC Off"),
(2795900,9,10,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Your Inner Turmoil - On Script - Start Attack Summoner");

DELETE FROM `creature_text` WHERE `CreatureID` = 27959;
