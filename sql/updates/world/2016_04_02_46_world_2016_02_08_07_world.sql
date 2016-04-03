-- 
-- DB/Quest: King of the Foulweald
DELETE FROM `spell_script_names` WHERE `spell_id`=20783;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(20783, 'spell_destroy_karangs_banner');

-- remove this stuff - eventscripts will be running even without gameobject
DELETE FROM `event_scripts` where id=6721;

-- Karang's Banner SAI
SET @ENTRY := 178205;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,1,0,100,1,5000,5000,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Karang's Banner - Out of Combat - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 17820500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2237.48,-1524.45,89.7827,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2202.16,-1544.48,87.796,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,2,0,0,0,100,0,20000,20000,0,0,12,3750,3,180000,0,0,0,8,0,0,0,2208.93,-1567.59,87.2283,0,"On Script - Summon Creature 'Foulweald Totemic'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2235.44,-1578.43,86.4944,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2260.9,-1547.91,89.1733,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,5,0,0,0,100,0,30000,30000,0,0,12,3750,3,180000,0,0,0,8,0,0,0,2237.48,-1524.45,89.7827,0,"On Script - Summon Creature 'Foulweald Totemic'"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2202.16,-1544.48,87.796,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,7,0,0,0,100,0,20000,20000,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2208.93,-1567.59,87.2283,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,12,3750,3,180000,0,0,0,8,0,0,0,2235.44,-1578.43,86.4944,0,"On Script - Summon Creature 'Foulweald Totemic'"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2260.9,-1547.91,89.1733,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2237.48,-1524.45,89.7827,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,12,3750,3,180000,0,0,0,8,0,0,0,2202.16,-1544.48,87.796,0,"On Script - Summon Creature 'Foulweald Totemic'"),
(@ENTRY,9,12,0,0,0,100,0,20000,20000,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2208.93,-1567.59,87.2283,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2235.44,-1578.43,86.4944,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,14,0,0,0,100,0,0,0,0,0,12,3750,3,180000,0,0,0,8,0,0,0,2260.9,-1547.91,89.1733,0,"On Script - Summon Creature 'Foulweald Totemic'"),
(@ENTRY,9,15,0,0,0,100,0,30000,30000,0,0,12,3749,3,180000,0,0,0,8,0,0,0,2237.48,-1524.45,89.7827,0,"On Script - Summon Creature 'Foulweald Ursa'"),
(@ENTRY,9,16,0,0,0,100,0,0,0,0,0,12,3743,3,180000,0,0,0,8,0,0,0,2202.16,-1544.48,87.796,0,"On Script - Summon Creature 'Foulweald Warrior'"),
(@ENTRY,9,17,0,0,0,100,0,25000,25000,0,0,12,12918,3,180000,0,0,0,8,0,0,0,2208.93,-1567.59,87.2283,0,"On Script - Summon Creature 'Chief Murgut'");

-- Foulweald Ursa SAI
SET @ENTRY := 3749;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,0,2000,2000,20000,20000,69,1,0,0,0,0,0,20,178205,100,0,0,0,0,0,"Foulweald Ursa - Out of Combat - Move To Position"),
(@ENTRY,0,5,0,34,0,100,0,8,1,0,0,11,20786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Ursa - On Reached Point 1 - Cast 'Destroy Karang's Banner'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=5 AND `SourceEntry`=3749;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,3749,0,0,30,1,178205,35,0,0,"","Foulweald SAI - ONLY near Banner");

-- Foulweald Warrior SAI
SET @ENTRY := 3743;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,1,0,100,0,2000,2000,20000,20000,69,1,0,0,0,0,0,20,178205,100,0,0,0,0,0,"Foulweald Warrior - Out of Combat - Move To Closest Gameobject 'Karang's Banner' (Phase 1)"),
(@ENTRY,0,3,0,34,0,100,0,8,1,0,0,11,20786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Warrior - On Reached Point 1 - Cast 'Destroy Karang's Banner'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=3743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,3743,0,0,30,1,178205,35,0,0,"","Foulweald SAI - ONLY near Banner");

-- Foulweald Totemic SAI
SET @ENTRY := 3750;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,0,2000,2000,20000,20000,69,1,0,0,0,0,0,20,178205,100,0,0,0,0,0,"Foulweald Totemic - Out of Combat - Move To Closest Gameobject 'Karang's Banner' (Phase 1)"),
(@ENTRY,0,5,0,34,0,100,0,8,1,0,0,11,20786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Totemic - On Reached Point 1 - Cast 'Destroy Karang's Banner'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=5 AND `SourceEntry`=3750;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,3750,0,0,30,1,178205,35,0,0,"","Foulweald SAI - ONLY near Banner");

-- Chief Murgut SAI
SET @ENTRY := 12918;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,0,2000,2000,20000,20000,69,1,0,0,0,0,0,20,178205,100,0,0,0,0,0,"Chief Murgut - Out of Combat - Move To Closest Gameobject 'Karang's Banner' (Phase 1)"),
(@ENTRY,0,5,0,34,0,100,0,8,1,0,0,11,20786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Reached Point 1 - Cast 'Destroy Karang's Banner'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=5 AND `SourceEntry`=12918;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,12918,0,0,30,1,178205,35,0,0,"","Foulweald SAI - ONLY near Banner");
