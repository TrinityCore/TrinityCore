-- **** Fix quest 14386 "Leader of the Pack" ****

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q14386_call_attack_mastiffs';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(68682, 'spell_q14386_call_attack_mastiffs');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup` IN (1,4) AND `SourceEntry` IN (68682) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 68682, 0, 0, 31, 0, 3, 36312, 0, 0, 0, 0, '', 'Call Attack Mastiffs Effect 0 will hit Dark Ranger Thyala'),
(13, 4, 68682, 0, 0, 31, 1, 3, 36198, 0, 0, 0, 0, '', 'Call Attack Mastiffs Effect 2 will hit Generic Trigger LAB - Multiphase (Ground)');

UPDATE `creature` SET `spawntimesecs`=120 WHERE id=36312;
UPDATE `creature_template` SET `mingold`=4,`maxgold`=10 WHERE `entry` IN (36312);

-- Dark Ranger Thyala SAI
SET @ENTRY := 36312;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Thyala - On Aggro - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,10000,10000,0,11,68683,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Thyala - On Range 0-5 - Cast 'Knockback'"),
(@ENTRY,0,2,0,8,0,100,0,68682,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Ranger Thyala - On Spellhit - Attack Start Invoker");

-- Attack Mastiff SAI
SET @ENTRY := 36405;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,50,1,8,25,0,0,0,11,68687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Attack Mastiff - Combat - Cast 'Leap' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,10000,10000,0,11,26281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Attack Mastiff - Combat - Cast 'Taunt'"),
(@ENTRY,0,2,0,9,0,50,0,0,3,15000,15000,0,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Attack Mastiff - On Range 0-5 - Cast 'Demoralizing Roar'"),
(@ENTRY,0,4,0,60,0,100,1,200,200,0,0,0,49,0,0,0,0,0,0,10,255706,36312,0,0,0,0,0,"Attack Mastiff - Update Event - Attack Dark Ranger Thyala (No Repeat)");

-- Attack Mastiff SAI
SET @ENTRY := 36409;
UPDATE `creature_template` SET `AIName`="SmartAI", `faction`=2203 WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,50,1,8,25,0,0,0,11,68687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Attack Mastiff - Combat - Cast 'Leap' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,10000,10000,0,11,26281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Attack Mastiff - Combat - Cast 'Taunt'"),
(@ENTRY,0,2,0,9,0,50,0,0,3,15000,15000,0,11,15971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Attack Mastiff - On Range 0-5 - Cast 'Demoralizing Roar'"),
(@ENTRY,0,3,0,1,0,100,1,0,0,0,0,0,49,0,0,0,0,0,0,10,255706,36312,0,0,0,0,0,"Attack Mastiff - OOC - Attack Dark Ranger Thyala (No Repeat)");

-- Lord Godfrey SAI
SET @ENTRY := 36290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3629000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,14386,0,0,0,0,80,3629000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Godfrey - quest complete - Run Script"),
(3629000,9,0,0,0,0,100,0,0,0,0,0,0,85,68483,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lord Godfrey - Script - Cast 'Phase - Quest Zone-Specific 08'"),
(3629000,9,1,0,0,0,100,0,0,0,0,0,0,28,68482,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lord Godfrey - Script - Unaura 'Phase - Quest Zone-Specific 07'"),
(3629000,9,2,0,0,0,100,0,500,500,0,0,0,85,69027,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lord Godfrey - Script - Cast 'Forcecast Cataclysm I'"),
(3629000,9,3,0,0,0,100,0,100,100,0,0,0,1,0,1,0,0,0,0,10,255676,36291,0,0,0,0,0,"Lord Godfrey - Script - Melinda Hammond Say 0"),
(3629000,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lord Godfrey - Script - Say 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (36290,36291);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(36290, 0, 0, 'Hold your positions, men!', 14, 0, 100, 0, 0, 0, 36632, 'Lord Godfrey'),
(36291, 0, 0, 'What''s happening?!', 12, 0, 100, 0, 0, 0, 36633, 'Melinda Hammond');

-- 471 Phases 182,183
UPDATE `creature` SET `PhaseId`=0, `PhaseGroup`=471 WHERE `guid` IN
(255676,255677,255678,255679,255680,255681);
