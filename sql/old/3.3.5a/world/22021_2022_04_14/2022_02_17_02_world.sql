--
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 134, `EffectImplicitTargetA1` = 25, `EffectMiscValue1` = 27394 WHERE `Id` = 48607;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_high_executor_branding_iron';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48603,'spell_high_executor_branding_iron');

DELETE FROM `creature_text` WHERE `CreatureID` = 27209 AND `GroupID` > 5;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27209,6,0,"I TOLD YOU... I don't know... anything... else!",15,0,100,0,0,0,26496,0,"Torturer LeCraft"),
(27209,6,1,"Please... stop. I'll do... anything....",15,0,100,0,0,0,26498,0,"Torturer LeCraft"),
(27209,6,2,"Just... end it.",15,0,100,0,0,0,26499,0,"Torturer LeCraft"),
(27209,6,3,"They all... begged... for their... lives!",15,0,100,0,0,0,26501,0,"Torturer LeCraft"),
(27209,6,4,"I beg you... no more.",15,0,100,0,0,0,26504,0,"Torturer LeCraft"),
(27209,6,5,"THIS IS TORTURE!",15,0,100,0,0,0,26505,0,"Torturer LeCraft"),
(27209,6,6,"You won't get... anything else... out of me!",15,0,100,0,0,0,26506,0,"Torturer LeCraft"),
(27209,6,7,"OWWWWWWWW!",15,0,100,0,0,0,26507,0,"Torturer LeCraft");

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 27209;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27209 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27209,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Torturer LeCraft - On Aggro - Say Line 0"),
(27209,0,1,0,0,0,100,0,0,5000,3000,10000,0,11,30478,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Torturer LeCraft - In Combat - Cast 'Hemorrhage'"),
(27209,0,2,0,0,0,100,0,10000,15000,20000,20000,0,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Torturer LeCraft - In Combat - Cast 'Kidney Shot'");
