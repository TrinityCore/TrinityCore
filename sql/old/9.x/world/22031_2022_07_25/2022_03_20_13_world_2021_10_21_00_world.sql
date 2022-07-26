--
UPDATE `creature_template` SET `unit_flags` = 32768, `AIName` = 'SmartAI' WHERE `entry` IN (27166,27169,36021,36024);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (27166,27169,36021,36024);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(27166,1,1,1,1,0,0),
(27169,1,1,1,1,0,0),
(36021,1,1,1,1,0,0),
(36024,1,1,1,1,0,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (27166,27169,36021,36024);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27166,27169,36021,36024) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- The chance to play the emote may be not 100
-- There are few spells which may be related to how brew is tossed(search for Brewmaiden), but haven't seen in sniffs any of them
-- Maybe brew is tossed only to owner, no idea
(27166,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Say Line 0"),
(27166,0,1,0,11,0,100,0,0,0,0,0,0,11,48186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'Brewmaiden Despawn Control Aura'"),
(27166,0,2,0,11,0,100,0,0,0,0,0,0,11,48032,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'Brewmaiden Spotlight'"),
(27166,0,3,0,11,0,100,0,0,0,0,0,0,11,51847,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'The Brewmaiden's Blessing'"),
(27166,0,4,0,22,0,100,0,101,0,0,0,0,11,48249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Brewmaiden - On Received Emote 'Wave' - Cast 'Brewfest Brew Toss'"),
(27166,0,5,0,1,0,100,0,0,0,7000,7000,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Brewmaiden - Out of Combat - Set Orientation Owner"),

(36021,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Say Line 0"),
(36021,0,1,0,11,0,100,0,0,0,0,0,0,11,48186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'Brewmaiden Despawn Control Aura'"),
(36021,0,2,0,11,0,100,0,0,0,0,0,0,11,48032,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'Brewmaiden Spotlight'"),
(36021,0,3,0,11,0,100,0,0,0,0,0,0,11,68269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Brewmaiden - On Spawn - Cast 'The Brewmaiden's Blessing'"),
(36021,0,4,0,22,0,100,0,101,0,0,0,0,11,48249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Brewmaiden - On Received Emote 'Wave' - Cast 'Brewfest Brew Toss'"),
(36021,0,5,0,1,0,100,0,0,0,7000,7000,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Brewmaiden - Out of Combat - Set Orientation Owner"),

(27169,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Say Line 0"),
(27169,0,1,0,11,0,100,0,0,0,0,0,0,11,48186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Cast 'Brewmaiden Despawn Control Aura'"),
(27169,0,2,0,11,0,100,0,0,0,0,0,0,11,48033,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Cast 'Black Brewmaiden Spotlight'"),
(27169,0,3,0,22,0,100,0,101,0,0,0,0,11,48249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Received Emote 'Wave' - Cast 'Brewfest Brew Toss'"),
(27169,0,4,0,1,0,100,0,0,0,7000,7000,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Black Brewmaiden - Out of Combat - Set Orientation Owner"),
(27169,0,5,0,0,0,100,0,0,0,5000,5000,0,11,48208,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Black Brewmaiden - In Combat - Cast 'Bitter Brew'"),

(36024,0,0,0,11,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Say Line 0"),
(36024,0,1,0,11,0,100,0,0,0,0,0,0,11,48186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Cast 'Brewmaiden Despawn Control Aura'"),
(36024,0,2,0,11,0,100,0,0,0,0,0,0,11,48033,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Spawn - Cast 'Black Brewmaiden Spotlight'"),
(36024,0,3,0,22,0,100,0,101,0,0,0,0,11,48249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Black Brewmaiden - On Received Emote 'Wave' - Cast 'Brewfest Brew Toss'"),
(36024,0,4,0,1,0,100,0,0,0,7000,7000,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"The Black Brewmaiden - Out of Combat - Set Orientation Owner"),
(36024,0,5,0,0,0,100,0,0,0,5000,5000,0,11,68272,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Black Brewmaiden - In Combat - Cast 'Bitter Brew'");

DELETE FROM `creature_text` WHERE `CreatureID` IN (27166,27169,36021,36024);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27166,0,0,"Do ye want ta live forever?",12,0,100,0,0,0,26303,0,"The Brewmaiden"),
(36021,0,0,"Do ye want ta live forever?",12,0,100,0,0,0,26303,0,"The Brewmaiden"),
(27169,0,0,"Do ye want ta live forever?",12,0,100,0,0,0,26303,0,"The Black Brewmaiden"),
(36024,0,0,"Do ye want ta live forever?",12,0,100,0,0,0,26303,0,"The Black Brewmaiden");

DELETE FROM `spell_script_names` WHERE `spell_id` = 48186 AND `ScriptName` = 'spell_gen_despawn_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48186,'spell_gen_despawn_aura');
