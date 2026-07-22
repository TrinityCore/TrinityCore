--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_moam_summon_mana_fiends',
'spell_moam_energize',
'spell_moam_drain_mana',
'spell_moam_drain_mana_effect',
'spell_gen_zero_mana_full_health');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(25684, 'spell_moam_summon_mana_fiends'),
(25685, 'spell_moam_energize'),
(25676, 'spell_moam_drain_mana'),
(25671, 'spell_moam_drain_mana_effect'),
(25755, 'spell_moam_drain_mana_effect'),
(23777, 'spell_gen_zero_mana_full_health');

DELETE FROM `creature_text` WHERE `CreatureID` = 15340 AND `GroupID` = 2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15340,2,0,"%s drains your mana and turns to stone.",16,0,100,0,0,0,11474,0,"moam EMOTE_ENERGIZE");

UPDATE `creature_template` SET `AIName` = 'SmartAI', `flags_extra` = `flags_extra`&~2 WHERE `entry` = 15527;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15527 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15527,0,0,0,37,0,100,0,0,0,0,0,0,116,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mana Fiend - On AI Initialize - Set Corpse Delay"),
(15527,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mana Fiend - On Spawn - Set In Combat With Zone"),
(15527,0,2,0,0,0,100,0,5000,7000,5000,7000,0,11,25679,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mana Fiend - In Combat - Cast 'Arcane Explosion'"),
(15527,0,3,0,13,0,100,0,10000,20000,0,0,0,11,15122,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Mana Fiend - Target Casting - Cast 'Counterspell'");
