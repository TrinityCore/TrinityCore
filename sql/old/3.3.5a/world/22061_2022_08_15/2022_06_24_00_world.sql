-- Copied from 35153 by them
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 28, `EffectDieSides1` = 1, `EffectImplicitTargetA1` = 73, `EffectRadiusIndex1` = 37, `EffectMiscValue1` = 28166, `EffectMiscValueB1` = 64, `DmgMultiplier1` = 1, `DmgMultiplier2` = 1 WHERE `Id` = 50754;

-- Same, from 35148
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 23, `EffectAmplitude1` = 2000, `EffectTriggerSpell1` = 50757, `DmgMultiplier1` = 1, `DmgMultiplier2` = 1 WHERE `Id` = 50755;

-- While at it, update both of them
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 0x00002000 WHERE `entry` IN (20405,21534);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 28166;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20405,28166) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2040500,2816600) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20405,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On AI Initialize - Set Reactstate Passive"),
(20405,0,1,0,11,0,100,0,0,0,0,0,0,80,2040500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Spawn - Run Script"),

(2040500,9,0,0,0,0,100,0,0,0,0,0,0,11,35150,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Cast 'Nether Charge Passive'"),
(2040500,9,1,0,0,0,100,0,0,0,0,0,0,11,37670,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Cast 'Nether Charge Timer'"),
(2040500,9,2,0,0,0,100,0,0,0,0,0,0,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Start Random Movement"),
(2040500,9,3,0,0,0,100,0,8500,8500,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Stop Random Movement"),
(2040500,9,4,0,0,0,100,0,0,0,0,0,0,11,35148,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Cast 'Nether Charge Countdown'"),
(2040500,9,5,0,0,0,100,0,9500,9500,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Charge - On Script - Despawn"),

(28166,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On AI Initialize - Set Reactstate Passive"),
(28166,0,1,0,11,0,100,0,0,0,0,0,0,80,2816600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Spawn - Run Script"),

(2816600,9,0,0,0,0,100,0,1000,1000,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Cast 'Teleport Visual Only'"),
(2816600,9,1,0,0,0,100,0,0,0,0,0,0,11,50756,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Cast 'Unstable Sphere Passive'"),
(2816600,9,2,0,0,0,100,0,0,0,0,0,0,11,50758,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Cast 'Unstable Sphere Timer'"),
(2816600,9,3,0,0,0,100,0,0,0,0,0,0,89,40,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Start Random Movement"),
(2816600,9,4,0,0,0,100,0,8000,8000,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Stop Random Movement"),
(2816600,9,5,0,0,0,100,0,0,0,0,0,0,11,50755,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Cast 'Unstable Sphere Countdown'"),
(2816600,9,6,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unstable Sphere - On Script - Despawn");

DELETE FROM `spell_scripts` WHERE `id` = 51336;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_drakos_magic_pull';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51336,'spell_drakos_magic_pull');

DELETE FROM `creature_text` WHERE `CreatureID` = 27654 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(27654,5,0,"%s begins to cast Magic Pull!",41,0,100,0,0,0,27550,0,"drakos EMOTE_PULL");
