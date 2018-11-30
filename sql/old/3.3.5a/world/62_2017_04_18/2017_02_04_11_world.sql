-- [NPC][WotlK] Garm Watcher and Snowblind Devotee, missing paths/emotes, wrong spawns
-- Remove Snowblind Devotee
DELETE FROM `creature` WHERE `guid` IN (202437, 202439, 152097, 202440, 202434, 202433, 202431, 209161, 209160, 209159, 209158, 209157, 209156, 209155, 209154, 209153);

-- emotes
-- Snowblind Devotee SAI
SET @ENTRY := -152077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'"),
(@ENTRY,0,1,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51");

-- Snowblind Devotee SAI
SET @ENTRY := -152072;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'"),
(@ENTRY,0,1,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51");

-- Snowblind Devotee SAI
SET @ENTRY := -152079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'"),
(@ENTRY,0,1,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51");

-- Snowblind Devotee SAI
SET @ENTRY := -152073;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 'Blind Faith'"),
(@ENTRY,0,1,0,1,0,100,0,2000,3000,2000,3000,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Out of Combat - Play Emote 51");

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 202417;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6429.416,`position_y`=-1671.991,`position_z`=471.3815 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6429.416,-1671.991,471.3815,0,0,0,0,100,0),
(@PATH,2,6433.916,-1674.241,471.1315,0,0,0,0,100,0),
(@PATH,3,6436.416,-1675.491,470.8815,0,0,0,0,100,0),
(@PATH,4,6425.828,-1670.409,471.5186,0,0,0,0,100,0);
-- 0x203CD047601CB7C0000C1D000009E712 .go 6429.416 -1671.991 471.3815

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 202430;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6539.085,`position_y`=-1654.911,`position_z`=454.2229 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6539.085,-1654.911,454.2229,0,0,0,0,100,0),
(@PATH,2,6537.335,-1655.161,454.4729,0,0,0,0,100,0),
(@PATH,3,6534.835,-1655.411,454.7229,0,0,0,0,100,0),
(@PATH,4,6531.585,-1655.911,454.9729,0,0,0,0,100,0),
(@PATH,5,6541.625,-1654.475,453.6616,0,0,0,0,100,0);
-- 0x203CD047601CB7C0000C1D000009E73D .go 6539.085 -1654.911 454.2229

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 202432;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6477.967,`position_y`=-1633.098,`position_z`=465.0029 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6477.967,-1633.098,465.0029,0,0,0,0,100,0),
(@PATH,2,6479.967,-1634.098,465.0029,0,0,0,0,100,0),
(@PATH,3,6489.643,-1638.752,464.643,0,0,0,0,100,0),
(@PATH,4,6495.25,-1641.642,463.2806,0,0,0,0,100,0),
(@PATH,5,6489.268,-1638.592,464.5939,0,0,0,0,100,0),
(@PATH,6,6485.768,-1637.092,464.8439,0,0,0,0,100,0),
(@PATH,7,6480.018,-1634.092,464.8439,0,0,0,0,100,0),
(@PATH,8,6478.018,-1633.092,465.0939,0,0,0,0,100,0),
(@PATH,9,6474.365,-1630.056,464.7512,0,0,0,0,100,0);
-- 0x203CD047601CB7C0000C1D00000B24A4 .go 6477.967 -1633.098 465.0029

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 152074;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6459.794,`position_y`=-1659.635,`position_z`=434.6493 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6459.794,-1659.635,434.6493,0,0,0,0,100,0),
(@PATH,2,6458.044,-1662.135,434.8993,0,0,0,0,100,0),
(@PATH,3,6455.794,-1664.885,435.8993,0,0,0,0,100,0),
(@PATH,4,6452.044,-1670.385,436.1493,0,0,0,0,100,0),
(@PATH,5,6455.4,-1665.414,436.0869,0,0,0,0,100,0),
(@PATH,6,6458.139,-1661.692,435.0327,0,0,0,0,100,0),
(@PATH,7,6459.889,-1659.442,434.5327,0,0,0,0,100,0),
(@PATH,8,6467.139,-1653.692,431.7827,0,0,0,0,100,0),
(@PATH,9,6471.639,-1649.692,430.5327,0,0,0,0,100,0),
(@PATH,10,6474.926,-1647.037,429.5704,0,0,0,0,100,0),
(@PATH,11,6481.676,-1645.287,428.8204,0,0,0,0,100,0),
(@PATH,12,6494.047,-1640.135,428.3722,0,0,0,0,100,0),
(@PATH,13,6497.047,-1638.635,427.8722,0,0,0,0,100,0),
(@PATH,14,6501.297,-1636.135,427.8722,0,0,0,0,100,0),
(@PATH,15,6503.534,-1636.759,427.1362,0,0,0,0,100,0),
(@PATH,16,6506.754,-1638.539,426.7677,0,0,0,0,100,0),
(@PATH,17,6503.504,-1636.539,427.2677,0,0,0,0,100,0),
(@PATH,18,6502.297,-1636.094,427.6441,0,0,0,0,100,0),
(@PATH,19,6497.047,-1638.594,427.8941,0,0,0,0,100,0),
(@PATH,20,6495.047,-1639.844,428.3941,0,0,0,0,100,0),
(@PATH,21,6492.071,-1641.567,428.893,0,0,0,0,100,0),
(@PATH,22,6488.321,-1643.317,428.893,0,0,0,0,100,0),
(@PATH,23,6486.071,-1644.067,428.893,0,0,0,0,100,0),
(@PATH,24,6482.071,-1645.067,428.893,0,0,0,0,100,0),
(@PATH,25,6476.821,-1646.567,429.393,0,0,0,0,100,0),
(@PATH,26,6474.66,-1647.438,429.754,0,0,0,0,100,0),
(@PATH,27,6471.66,-1649.688,430.504,0,0,0,0,100,0),
(@PATH,28,6467.41,-1653.438,431.754,0,0,0,0,100,0),
(@PATH,29,6464.91,-1655.188,432.754,0,0,0,0,100,0);
-- 0x203CD047601CB7C0000C1D00000B2C9E .go 6459.794 -1659.635 434.6493

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 152096;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6431.137,`position_y`=-1730.818,`position_z`=479.774 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6431.137,-1730.818,479.774,0,0,0,0,100,0),
(@PATH,2,6434.387,-1720.568,479.024,0,0,0,0,100,0),
(@PATH,3,6436.137,-1715.318,478.024,0,0,0,0,100,0),
(@PATH,4,6438.637,-1707.568,476.774,0,0,0,0,100,0),
(@PATH,5,6429.063,-1736.248,479.3528,0,0,0,0,100,0);
-- 0x203CD047601CB840000C1D000009E765 .go 6431.137 -1730.818 479.774

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 202415;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6447.658,`position_y`=-1721.894,`position_z`=435.5058 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6447.658,-1721.894,435.5058,0,0,0,0,100,0),
(@PATH,2,6448.908,-1723.394,435.5058,0,0,0,0,100,0),
(@PATH,3,6455.908,-1731.394,435.5058,0,0,0,0,100,0),
(@PATH,4,6457.908,-1733.894,435.5058,0,0,0,0,100,0),
(@PATH,5,6461.158,-1737.644,435.0058,0,0,0,0,100,0),
(@PATH,6,6472.362,-1744.42,435.086,0,0,0,0,100,0),
(@PATH,7,6478.607,-1747.979,435.1784,0,0,0,0,100,0),
(@PATH,8,6483.357,-1747.979,435.4284,0,0,0,0,100,0),
(@PATH,9,6485.357,-1748.229,435.4284,0,0,0,0,100,0),
(@PATH,10,6493.107,-1748.729,435.4284,0,0,0,0,100,0),
(@PATH,11,6493.591,-1748.761,435.6377,0,0,0,0,100,0),
(@PATH,12,6494.841,-1749.011,435.6377,0,0,0,0,100,0),
(@PATH,13,6501.591,-1746.261,435.8877,0,0,0,0,100,0),
(@PATH,14,6503.341,-1745.261,435.8877,0,0,0,0,100,0),
(@PATH,15,6512.091,-1742.011,436.1377,0,0,0,0,100,0),
(@PATH,16,6512.313,-1741.629,436.1915,0,0,0,0,100,0),
(@PATH,17,6513.313,-1741.379,436.1915,0,0,0,0,100,0),
(@PATH,18,6517.063,-1738.629,436.1915,0,0,0,0,100,0),
(@PATH,19,6519.665,-1737.017,436.2415,0,0,0,0,100,0),
(@PATH,20,6517.165,-1738.517,436.2415,0,0,0,0,100,0),
(@PATH,21,6512.962,-1741.599,436.0323,0,0,0,0,100,0),
(@PATH,22,6503.462,-1745.349,435.7823,0,0,0,0,100,0),
(@PATH,23,6502.212,-1745.849,435.7823,0,0,0,0,100,0),
(@PATH,24,6493.193,-1748.818,435.5165,0,0,0,0,100,0),
(@PATH,25,6485.443,-1748.318,435.5165,0,0,0,0,100,0),
(@PATH,26,6483.193,-1748.068,435.5165,0,0,0,0,100,0),
(@PATH,27,6478.14,-1747.834,435.2448,0,0,0,0,100,0),
(@PATH,28,6472.39,-1744.334,434.9948,0,0,0,0,100,0),
(@PATH,29,6469.89,-1743.084,434.9948,0,0,0,0,100,0),
(@PATH,30,6462.061,-1738.573,435.0483,0,0,0,0,100,0),
(@PATH,31,6461.061,-1737.573,435.0483,0,0,0,0,100,0),
(@PATH,32,6458.061,-1733.823,435.5483,0,0,0,0,100,0),
(@PATH,33,6455.811,-1731.323,435.5483,0,0,0,0,100,0),
(@PATH,34,6449.061,-1723.323,435.5483,0,0,0,0,100,0);
-- 0x203CD047601CB840000C1D00000B24B0 .go 6447.658 -1721.894 435.5058

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 152090;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6420.789,`position_y`=-1645.256,`position_z`=420.897 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6420.789,-1645.256,420.897,0,0,0,0,100,0),
(@PATH,2,6437.539,-1641.756,418.897,0,0,0,0,100,0),
(@PATH,3,6441.789,-1640.756,418.897,0,0,0,0,100,0),
(@PATH,4,6457.039,-1637.506,422.397,0,0,0,0,100,0),
(@PATH,5,6457.35,-1637.388,422.4939,0,0,0,0,100,0),
(@PATH,6,6464.6,-1636.888,425.4939,0,0,0,0,100,0),
(@PATH,7,6487.011,-1636.828,428.6188,0,0,0,0,100,0),
(@PATH,8,6491.761,-1632.578,428.3688,0,0,0,0,100,0),
(@PATH,9,6495.511,-1629.078,428.1188,0,0,0,0,100,0),
(@PATH,10,6500.011,-1624.828,427.8688,0,0,0,0,100,0),
(@PATH,11,6502.87,-1622.128,427.6573,3.944444,10000,0,0,100,0),
(@PATH,12,6497.644,-1624.168,428.2245,0,0,0,0,100,0),
(@PATH,13,6491.394,-1626.418,428.4745,0,0,0,0,100,0),
(@PATH,14,6483.894,-1628.918,428.2245,0,0,0,0,100,0),
(@PATH,15,6475.894,-1631.918,426.9745,0,0,0,0,100,0),
(@PATH,16,6468.144,-1634.668,426.2245,0,0,0,0,100,0),
(@PATH,17,6462.88,-1636.609,425.0425,0,0,0,0,100,0),
(@PATH,18,6459.88,-1637.609,424.2925,0,0,0,0,100,0),
(@PATH,19,6457.38,-1638.359,423.0425,0,0,0,0,100,0),
(@PATH,20,6451.88,-1639.859,420.7925,0,0,0,0,100,0),
(@PATH,21,6449.88,-1640.609,419.7925,0,0,0,0,100,0),
(@PATH,22,6446.223,-1641.555,418.8697,0,0,0,0,100,0),
(@PATH,23,6441.973,-1641.055,418.8697,0,0,0,0,100,0),
(@PATH,24,6435.973,-1640.305,418.8697,0,0,0,0,100,0),
(@PATH,25,6425.122,-1639.171,419.3436,0,0,0,0,100,0),
(@PATH,26,6418.622,-1644.421,420.5936,0,0,0,0,100,0),
(@PATH,27,6416.008,-1646.506,420.4008,3.647738,10000,0,0,100,0);
-- 0x203CD047601CB840000C1D00000B2C81 .go 6420.789 -1645.256 420.897

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 117614;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6382.385,`position_y`=-1647.289,`position_z`=420.4568 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6382.385,-1647.289,420.4568,0,0,0,0,100,0),
(@PATH,2,6385.135,-1644.289,420.2068,0,0,0,0,100,0),
(@PATH,3,6389.135,-1639.539,419.7068,0,0,0,0,100,0),
(@PATH,4,6392.885,-1635.289,418.9568,0,0,0,0,100,0),
(@PATH,5,6395.885,-1632.289,418.9568,0,0,0,0,100,0),
(@PATH,6,6397.885,-1630.039,418.7068,0,0,0,0,100,0),
(@PATH,7,6399.885,-1627.539,418.7068,0,0,0,0,100,0),
(@PATH,8,6403.635,-1623.289,418.7068,0,0,0,0,100,0),
(@PATH,9,6405.635,-1621.289,418.9568,0,0,0,0,100,0),
(@PATH,10,6405.938,-1621.021,419.002,0,0,0,0,100,0),
(@PATH,11,6407.688,-1619.021,419.752,0,0,0,0,100,0),
(@PATH,12,6414.688,-1617.021,421.002,0,0,0,0,100,0),
(@PATH,13,6419.688,-1615.521,422.252,0,0,0,0,100,0),
(@PATH,14,6424.866,-1613.928,422.0816,3.228859,10000,0,0,100,0),
(@PATH,15,6420.416,-1615.935,422.207,0,0,0,0,100,0),
(@PATH,16,6414.166,-1618.685,420.457,0,0,0,0,100,0),
(@PATH,17,6407.166,-1621.435,418.957,0,0,0,0,100,0),
(@PATH,18,6403.416,-1623.185,418.707,0,0,0,0,100,0),
(@PATH,19,6398.416,-1625.372,418.7291,0,0,0,0,100,0),
(@PATH,20,6395.666,-1629.122,418.7291,0,0,0,0,100,0),
(@PATH,21,6393.666,-1631.872,418.9791,0,0,0,0,100,0),
(@PATH,22,6391.416,-1635.122,418.9791,0,0,0,0,100,0),
(@PATH,23,6388.416,-1638.872,419.7291,0,0,0,0,100,0),
(@PATH,24,6384.666,-1644.122,420.2291,0,0,0,0,100,0),
(@PATH,25,6382.416,-1646.872,420.4791,0,0,0,0,100,0),
(@PATH,26,6381.318,-1648.284,420.0666,1.169371,10000,0,0,100,0);
-- 0x203CD047601CB840000C1D00000B2CA7 .go 6382.385 -1647.289 420.4568
