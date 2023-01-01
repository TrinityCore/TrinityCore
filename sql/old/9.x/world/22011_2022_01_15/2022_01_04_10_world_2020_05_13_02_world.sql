--
UPDATE `creature_addon` SET `auras` = "45769 18950 18943" WHERE `guid` IN (48394,48400);
UPDATE `creature_template_addon` SET `auras` = "45769 18950 10255 18943" WHERE `entry` = 25507;
UPDATE `creature_addon` SET `auras` = "18950 45769 42459" WHERE `guid` IN (48160,48162,48360,48372);
UPDATE `creature_template_addon` SET `auras` = "18950 45769 42459" WHERE `entry` = 25372;

-- Sunblade Protector SAI (Source: https://www.youtube.com/watch?v=3rVG_zheFEs https://www.youtube.com/watch?v=TciohYfbK10 https://www.youtube.com/watch?v=QiTyksAlS5A)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25507;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-45571,-45570,-45537,-54994,-54996,-54999,-55062,-55064,-55065,-48394,-48400) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Text 0 should be used only by creatures without paths including the one after Kalecgos
(-45571,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-45571,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-45571,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-45571,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-45571,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-45570,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-45570,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-45570,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-45570,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-45570,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-45537,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-45537,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-45537,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-45537,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-45537,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-54994,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-54994,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-54994,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-54994,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-54994,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-54996,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-54996,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-54996,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-54996,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-54996,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-55062,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-55062,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-55062,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-55062,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-55062,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-55064,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-55064,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-55064,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-55064,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-55064,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
(-55065,0,0,0,4,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,12,2,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Set Data 0 1 (Stored Target)"),
(-55065,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-55065,0,2,3,8,0,100,0,46476,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Protector - On Spellhit 'Sunblade Protector Activated' - Set In Combat With Zone"),
(-55065,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Link - Say Line 1"),
(-55065,0,4,0,21,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Reached Home - Say Line 0"),
-- Text 2 should be used only by creatures with paths
-- Protector after Kalecgos should remove the 'Stoned' aura
-- and start path after Kalecgos encounter is finished. Unsupported
(-54999,0,0,0,4,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Say Line 2"),
(-54999,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-48394,0,0,0,4,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Say Line 2"),
(-48394,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'"),
(-48400,0,0,0,4,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Protector - On Aggro - Say Line 2"),
(-48400,0,1,0,0,0,100,0,3000,6000,2500,7500,0,11,46480,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sunblade Protector - In Combat - Cast 'Fel Lightning'");

DELETE FROM `creature_text` WHERE `CreatureID` = 25507;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25507,0,0,"Unit entering energy conservation mode.",14,0,100,0,0,0,25200,0,'Sunblade Protector'),
(25507,1,0,"Local proximity threat detected. Exiting energy conservation mode.",14,0,100,0,0,0,25201,0,'Sunblade Protector'),
(25507,1,1,"Unit is now operational and attacking targets.",14,0,100,0,0,0,25206,0,'Sunblade Protector'),
(25507,2,0,"Enemy presence detected.",14,0,100,0,0,0,25203,0,'Sunblade Protector');

-- Sunblade Scout SAI (Source: https://www.youtube.com/watch?v=3rVG_zheFEs https://www.youtube.com/watch?v=TciohYfbK10 https://www.youtube.com/watch?v=QiTyksAlS5A)
SET @ENTRY := 25372;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Aggro - Set Reactstate Passive"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,19,25507,100,0,0,0,0,0,0,"Sunblade Scout - On Link - Store Targetlist Closest Creature 'Sunblade Protector'"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,0,64,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Store Targetlist Self"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,0,100,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Send Target 2"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Pause Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,0,69,1,0,0,20,0,0,12,1,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Move To Stored Target"),
(@ENTRY,0,7,0,0,0,100,0,5000,7000,6000,9000,0,11,46558,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sunblade Scout - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,8,0,34,0,100,0,8,1,0,0,0,11,46475,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Movement Inform - Cast 'Activate Sunblade Protector'"),
(@ENTRY,0,9,0,31,0,100,0,46476,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Spellhit Target - Set Reactstate Aggressive"),
(@ENTRY,0,10,11,38,0,100,0,0,1,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Data Set 0 1 - Set Reactstate Aggressive"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Link - Interrupt Spell"),
(@ENTRY,0,12,0,7,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunblade Scout - On Evade - Set Reactstate Aggressive");

DELETE FROM `creature_text` WHERE `CreatureID` = 25372;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25372,0,0,"Enemies spotted! Attack while I try to activate a Protector!",14,0,100,0,0,0,25202,0,'Sunblade Scout');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = 25372;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,25372,0,0,29,1,25507,100,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature Sunblade Protector is near");