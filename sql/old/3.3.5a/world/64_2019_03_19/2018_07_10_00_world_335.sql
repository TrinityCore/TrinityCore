-- Frostmane Novice
DELETE FROM `smart_scripts` WHERE `entryorguid`=946 AND `source_type`=0 AND `ID`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(946,0,1,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Novice - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=946;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(946,0,0,"My weapon be thirsty!",12,0,100,0,0,0,1908,0,"Frostmane Novice"),
(946,0,1,"Killing you be easy.",12,0,100,0,0,0,1909,0,"Frostmane Novice"),
(946,0,2,"You be dead soon!",12,0,100,0,0,0,10434,0,"Frostmane Novice"),
(946,0,3,"I gonna make you into mojo!",12,0,100,0,0,0,10435,0,"Frostmane Novice");

-- Burly Rockjaw Trogg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=724;
DELETE FROM `smart_scripts` WHERE `entryorguid`=724 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(724,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burly Rockjaw Trogg - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=724;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(724,0,0,"Crush!",12,0,100,0,0,0,1913,0,"Burly Rockjaw Trogg"),
(724,0,1,"Kill!",12,0,100,0,0,0,1914,0,"Burly Rockjaw Trogg"),
(724,0,2,"Destroy!",12,0,100,0,0,0,1915,0,"Burly Rockjaw Trogg");

-- Rockjaw Trogg
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=707;
DELETE FROM `smart_scripts` WHERE `entryorguid`=707 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(707,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Trogg - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=707;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(707,0,0,"Crush!",12,0,100,0,0,0,1913,0,"Rockjaw Trogg"),
(707,0,1,"Kill!",12,0,100,0,0,0,1914,0,"Rockjaw Trogg"),
(707,0,2,"Destroy!",12,0,100,0,0,0,1915,0,"Rockjaw Trogg");

-- Rockjaw Raider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1718 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1718,0,0,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Raider - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1718;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1718,0,0,"Crush!",12,0,100,0,0,0,1913,0,"Rockjaw Raider"),
(1718,0,1,"Kill!",12,0,100,0,0,0,1914,0,"Rockjaw Raider"),
(1718,0,2,"Destroy!",12,0,100,0,0,0,1915,0,"Rockjaw Raider");

-- Crag Boar
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid` IN (1125,1126,1127,1689) AND `source_type`=0 AND `id`=0;

-- Ice Claw Bear
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=7000, `event_param3`=15000, `event_param4`=19000, `action_param2`=2 WHERE `entryorguid`=1196 AND `source_type`=0 AND `id`=0;

-- Frostmane Headhunter
UPDATE `smart_scripts` SET `event_chance`=20 WHERE `entryorguid`=1123 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=1123 AND `ID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1123,0,3,"My weapon be thirsty!",12,0,100,0,0,0,1908,0,"Frostmane Headhunter");

-- Frostmane Troll
DELETE FROM `smart_scripts` WHERE `entryorguid`=1120 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1120,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Frostmane Troll - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=1120 AND `ID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1120,0,3,"My weapon be thirsty!",12,0,100,0,0,0,1908,0,"Frostmane Troll");

-- Frostmane Snowstrider
DELETE FROM `smart_scripts` WHERE `entryorguid`=1121 AND `source_type`=0 AND `ID`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1121,0,3,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Snowstrider - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1121;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1121,0,0,"My weapon be thirsty!",12,0,100,0,0,0,1908,0,"Frostmane Snowstrider"),
(1121,0,1,"Killing you be easy.",12,0,100,0,0,0,1909,0,"Frostmane Snowstrider"),
(1121,0,2,"You be dead soon!",12,0,100,0,0,0,10434,0,"Frostmane Snowstrider"),
(1121,0,3,"I gonna make you into mojo!",12,0,100,0,0,0,10435,0,"Frostmane Snowstrider");

-- Frostmane Shadowcaster
UPDATE `smart_scripts` SET `event_chance`=30 WHERE `entryorguid`=1124 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1124 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1124,0,3,0,0,0,100,0,3000,6000,12000,15000,0,11,11980,32,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Shadowcaster - In Combat - Cast 'Curse of Weakness'");

DELETE FROM `creature_text` WHERE `CreatureID`=1124;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1124,0,0,"Have a taste of Frostmane magics.",12,14,100,0,0,0,1910,0,"Frostmane Shadowcaster"),
(1124,0,1,"All you $R want is my weed.",12,14,100,0,0,0,1911,0,"Frostmane Shadowcaster");

-- Frostmane Hideskinner
DELETE FROM `smart_scripts` WHERE `entryorguid`=1122 AND `source_type`=0 AND `ID`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1122,0,2,0,4,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Hideskinner - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1122;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1122,0,0,"My weapon be thirsty!",12,0,100,0,0,0,1908,0,"Frostmane Hideskinner"),
(1122,0,1,"Killing you be easy.",12,0,100,0,0,0,1909,0,"Frostmane Hideskinner"),
(1122,0,2,"You be dead soon!",12,0,100,0,0,0,10434,0,"Frostmane Hideskinner"),
(1122,0,3,"I gonna make you into mojo!",12,0,100,0,0,0,10435,0,"Frostmane Hideskinner");

-- Great Father Arctikus
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=1260 AND `source_type`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=1260;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1260,0,0,"You dare defile Frostmane Hold, $R. Prepare to die!",12,14,100,0,0,0,1918,0,"Great Father Arctikus"),
(1260,0,1,"Oh, we are going to get along just fine, $n.",12,14,100,0,0,0,1919,0,"Great Father Arctikus");

-- Edan the Howler
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=11000, `event_param3`=8000, `event_param4`=12000 WHERE `entryorguid`=1137 AND `source_type`=0 AND `id`=0;

-- Old Icebeard
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=6000, `event_param3`=17000, `event_param4`=23000 WHERE `entryorguid`=1271 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=11000, `event_param2`=16000, `event_param3`=30000, `event_param4`=40000 WHERE `entryorguid`=1271 AND `source_type`=0 AND `id`=1;

-- Leper Gnome
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=9000, `event_param3`=14000, `event_param4`=18000 WHERE `entryorguid`=1211 AND `source_type`=0 AND `id`=1;

-- Frostmane Seer
UPDATE `smart_scripts` SET `event_chance`=20 WHERE `entryorguid`=1397 AND `source_type`=0 AND `id`=0;

-- Vagash
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=9000, `event_param3`=14000, `event_param4`=17000 WHERE `entryorguid`=1388 AND `source_type`=0 AND `id`=0;

-- Bjarn
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=7000, `event_param3`=15000, `event_param4`=19000, `action_param2`=2 WHERE `entryorguid`=1130 AND `source_type`=0 AND `id`=0;

-- Rockjaw Bonesnapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1117 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1117,0,0,0,0,0,100,0,5000,9000,19000,27000,0,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Bonesnapper - In Combat - Cast 'Knockdown'"),
(1117,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Bonesnapper - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1117;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1117,0,0,"Crush!",12,0,100,0,0,0,1913,0,"Rockjaw Bonesnapper"),
(1117,0,1,"Kill!",12,0,100,0,0,0,1914,0,"Rockjaw Bonesnapper"),
(1117,0,2,"Destroy!",12,0,100,0,0,0,1915,0,"Rockjaw Bonesnapper");

-- Rockjaw Backbreaker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1118 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1118,0,2,0,4,0,15,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Backbreaker - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=1118 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1118,1,0,"Crush!",12,0,100,0,0,0,1913,0,"Rockjaw Backbreaker"),
(1118,1,1,"Kill!",12,0,100,0,0,0,1914,0,"Rockjaw Backbreaker"),
(1118,1,2,"Destroy!",12,0,100,0,0,0,1915,0,"Rockjaw Backbreaker");

-- Dark Iron Spy
DELETE FROM `smart_scripts` WHERE `entryorguid`=6123 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6123,0,1,0,4,0,20,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Spy - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=6123;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6123,0,0,"Never cross a Dark Iron, $C.",12,0,100,0,0,0,1934,0,"Dark Iron Spy"),
(6123,0,1,"Time to die, $C.",12,0,100,0,0,0,1935,0,"Dark Iron Spy"),
(6123,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,1936,0,"Dark Iron Spy");

-- Captain Beld
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6124;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6124 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6124,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Beld - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=6124;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6124,0,0,"Never cross a Dark Iron, $C.",12,0,100,0,0,0,1934,0,"Captain Beld"),
(6124,0,1,"Time to die, $C.",12,0,100,0,0,0,1935,0,"Captain Beld"),
(6124,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,1936,0,"Captain Beld");

-- Mangeclaw
UPDATE `smart_scripts` SET `event_param1`=4000, `event_param2`=6000, `event_param3`=11000, `event_param4`=13000 WHERE `entryorguid`=1961 AND `source_type`=0 AND `id`=0;

-- Fix movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `id` IN (1689,1127);

-- Fix some texts
UPDATE `creature_text` SET `BroadcastTextId`=1914 WHERE `CreatureID` IN (1115,1116,1161,1162,1163,1165,1166,1167,1197,1393) AND `GroupID`=0 AND `ID`=1;
UPDATE `creature_text` SET `Language`=0 WHERE `BroadcastTextId` IN (1913,1915);
