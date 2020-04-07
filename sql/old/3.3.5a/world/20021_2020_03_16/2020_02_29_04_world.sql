-- Lithe Stalker SAI
SET @ENTRY := 30894;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,1,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - On health pct - Say text"),
(@ENTRY,0,1,0,8,0,100,513,58151,0,0,0,11,43979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - On Spellhit 'CSA Dummy Effect (25 yards)' - Cast full heal"),
(@ENTRY,0,2,0,34,0,100,513,8,1,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - On movement informer - Despawn"),
(@ENTRY,0,3,0,8,0,100,513,58178,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - On Spellhit 'CSA Dummy Effect (25 yards)' - Action list"),
(@ENTRY*100,9,0,0,0,0,100,512,0,0,0,0,11,58190,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Cast 'Geist Return Kill Credit'"),
(@ENTRY*100,9,1,0,0,0,100,512,0,0,0,0,28,58151,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Remove aura"),
(@ENTRY*100,9,2,0,0,0,100,512,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Set unit flag"),
(@ENTRY*100,9,3,0,0,0,100,512,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Set passif"),
(@ENTRY*100,9,4,0,0,0,100,512,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Set faction"),
(@ENTRY*100,9,5,0,0,0,100,512,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lithe Stalker - Action list - Disable Evade"),
(@ENTRY*100,9,6,0,0,0,100,512,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,6463.089, 2039.219, 570.721985,0,"Lithe Stalker - Action list' - Move to pos");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ENTRY);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY, 0, 0, "The Lithe Stalker is weakened by the assault.", 16, 0, 100, 0, 0, 0, 31580, 0, "Lithe Stalker");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (30894);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (58151);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 58151, 0, 0, 38, 1, 25, 4, 0, 0, 0, 0, '', 'Subdued Lithe Stalker - 25% health or less'),
(17, 0, 58151, 0, 0, 31, 1, 3, 30894, 0, 0, 12, 0, '', 'Subdued Lithe Stalker - only for Lithe Stalker'),
(22, 4, 30894, 0, 0, 1, 1, 58151, 0, 0, 0, 0, 0, '', 'Only run AI if Lithe Stalker has Aura (Subdued Lithe Stalker)');
