-- Crusader Grimtong SAI
SET @ENTRY := 37688;
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=`flags_extra`|2 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,35000,35000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Grimtong - Out of Combat - Run Script"),

(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Grimtong - On Script - EMOTESTATE 233"),
(@ENTRY*100,9,1,0,0,0,100,0,28000,28000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Grimtong - On Script - EMOTESTATE 0");

-- Crusader Halford Equipment and SAI
SET @ENTRY :=  37696;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@ENTRY AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`ItemID1`,`ItemID2`,`ItemID3`,`VerifiedBuild`) VALUES (@ENTRY,2,5532,0,0,12340);
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=`flags_extra`|2 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,50000,50000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - Out of Combat - Run Script"),

(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP template 1"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - EMOTESTATE 233"),
(@ENTRY*100,9,2,0,0,0,100,0,25000,25000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - EMOTESTATE 0"),
(@ENTRY*100,9,3,0,0,0,100,0,9000,9000,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP template 2"),
(@ENTRY*100,9,4,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - MOVE SPEED WALK"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,-61.71354,2228.632,27.90253,0,"Crusader Halford - OOC - MOVE TO POINT 1"),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.90438,"Crusader Halford - OOC - SET FACING"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP nothing"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - EMOTESTATE 69"),
(@ENTRY*100,9,9,0,0,0,100,0,2000,2000,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP template 2"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - EMOTESTATE 0"),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - MOVE SPEED WALK"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,69,2,0,0,0,0,0,8,0,0,0,-62,2232.8003,27.90253,0,"Crusader Halford - OOC - MOVE TO POINT 2"),
(@ENTRY*100,9,13,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.16937,"Crusader Halford - OOC - SET FACING"),
(@ENTRY*100,9,14,0,0,0,100,0,1000,1000,0,0,11,46400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - CAST 'Steam Weapon' SELF"),
(@ENTRY*100,9,15,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP nothing"),
(@ENTRY*100,9,16,0,0,0,100,0,4000,4000,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - SMART_ACTION_EQUIP template 2"),
(@ENTRY*100,9,17,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Halford - OOC - MOVE SPEED WALK"),
(@ENTRY*100,9,18,0,0,0,100,0,0,0,0,0,69,3,0,0,0,0,0,8,0,0,0,-61.336807,2231.4514,27.90253,0,"Crusader Halford - OOC - MOVE TO POINT 3"),
(@ENTRY*100,9,19,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.93412,"Crusader Halford - OOC - SET FACING");

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (46400) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 46400, 0, 0, 31, 0, 3, 26043, 0, 0, 0, 0, '', 'Spell Steam Weapon (effect 0) will hit the potential target of the spell if target is unit Steam Burst.');

-- SAI Steam Burst should not hav SAI. Spell 46400 is cast on unit by other npcs
DELETE FROM `smart_scripts` WHERE `entryorguid`=26043 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=26043;

-- Ormus the Penitent
DELETE FROM `creature_template_addon` WHERE `entry`=38316;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`MountCreatureID`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(38316,0,0,0,0,1,233,0,'');
