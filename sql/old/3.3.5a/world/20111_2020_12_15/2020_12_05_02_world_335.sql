-- https://www.youtube.com/watch?v=gZyx81kIXG4 https://www.youtube.com/watch?v=4jh2olbVGV0 https://www.youtube.com/watch?v=HhAniJKPkfM
-- Options are available even if items are in inventory
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 524 AND `ConditionTypeOrReference` = 2;
-- Messed up
UPDATE `gossip_menu_option` SET `OptionText` = "Press the yellow button labeled 'Thieves' Tools.'", `OptionBroadcastTextID` = 3149 WHERE `MenuID` = 524 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `OptionText` = "Press the red button labeled 'E.C.A.C.'", `OptionBroadcastTextID` = 3166 WHERE `MenuID` = 524 AND `OptionID` = 1;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 7166 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7166,0,0,2,62,0,100,0,524,0,0,0,0,11,9949,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wrenix's Gizmotronic Apparatus - On Gossip Option 0 Selected - Cast 'Thieves' Tool Rack Conjure'"),
(7166,0,1,2,62,0,100,0,524,1,0,0,0,11,9977,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wrenix's Gizmotronic Apparatus - On Gossip Option 0 Selected - Cast 'Conjure E.C.A.C'"),
(7166,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wrenix's Gizmotronic Apparatus - On Link - Close Gossip");

-- Wrenix the Wretched SAI
SET @ID := 7161;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,2381,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Quest 'Plundering the Plunderers' Taken - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,7166,10,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Set Orientation Closest Creature 'Wrenix's Gizmotronic Apparatus'"),
(@ID*100+0,9,1,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,1500,1500,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Say Line 1"),
(@ID*100+0,9,3,0,0,0,100,0,1500,1500,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Set Orientation Home Position"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,7166,10,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Say Line 0 (Wrenix's Gizmotronic Apparatus)"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,86,6668,0,19,7166,10,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Cross Cast 'Red Firework' (Wrenix's Gizmotronic Apparatus)"),
(@ID*100+0,9,6,0,0,0,100,0,2000,2000,0,0,0,86,6668,0,19,7166,10,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Cross Cast 'Red Firework' (Wrenix's Gizmotronic Apparatus)"),
(@ID*100+0,9,7,0,0,0,100,0,2000,2000,0,0,0,86,6668,0,19,7166,10,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Cross Cast 'Red Firework' (Wrenix's Gizmotronic Apparatus)"),
(@ID*100+0,9,8,0,0,0,100,0,2000,2000,0,0,0,86,6668,0,19,7166,10,0,1,0,0,0,0,0,0,0,0,"Wrenix the Wretched - On Script - Cross Cast 'Red Firework' (Wrenix's Gizmotronic Apparatus)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (7161,7166);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(7161,0,0,"Make sure to visit the Gizmotronic Apparatus to grab a lockpick and an E.C.A.C. You will definitely need both to complete your mission!",12,0,100,0,0,0,3171,0,"Wrenix the Wretched"),
(7161,1,0,"%s points you to the Gizmotronic Apparatus.",16,0,100,0,0,0,3203,0,"Wrenix the Wretched"),
(7166,0,0,"%s explodes, lighting the sky up in a brilliant fireworks display! It seems to be beckoning to you, rogue.",16,0,100,0,0,0,3204,0,"Wrenix's Gizmotronic Apparatus");

-- Polly
UPDATE `creature_template` SET `minlevel` = 50, `maxlevel` = 50, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `lootid` = 0 WHERE `entry` = 7167;
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `lootid` = 7168, `AIName` = "SmartAI" WHERE `entry` = 7168;
UPDATE `creature_loot_template` SET `Entry` = 7168 WHERE `entry` = 7167;

UPDATE `event_scripts` SET `delay` = 1, `datalong2` = 300000, `x` = -1463.676, `y` = -3924.07, `z` = 0.24124, `o` = 4.6273, `Comment` = "Event (Object 'The Jewel of the Southsea' (123462)) - On Event - Summon Creature 'Polly'" WHERE `id` = 2153;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 9976 AND `ElseGroup` IN (1,2);

-- Polly SAI
SET @ID := 7167;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Just Created - Say Line 0"),
(@ID,0,1,0,8,0,100,0,9976,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Spellhit 'Polly Eats the E.C.A.C.' - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Disable Evade"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Say Line 1"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Set Faction 35"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Combat Stop"),
(@ID*100+0,9,4,0,0,0,100,0,2000,2000,0,0,0,11,9998,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Cast 'Summon Polly Jr.'"),
(@ID*100+0,9,5,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Script - Despawn Instant");

-- Polly SAI
SET @ID := 7168;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Polly - On Just Created - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (7167,7168);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(7167,0,0,"SQUAWK!!!",14,0,100,0,0,0,3170,0,"Polly"),
(7167,1,0,"MmmmmMmmmm... Enormous chemically altered cracker....",12,0,100,0,0,0,3167,0,"Polly"),
(7168,0,0,"What the squawk??? Squawk squawk, squawk? SQUAWK!",12,0,100,0,0,0,3165,0,"Polly");
