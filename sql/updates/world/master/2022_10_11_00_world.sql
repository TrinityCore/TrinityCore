 --
 --
 -- Silverpine Forest
 
SET @CGUID := 395674;
SET @OGUID := 239587;

--
-- Forsaken Rear Guard

-- Detect: Quest Invis Zone 5
DELETE FROM `spell_area` WHERE `spell`=84241 AND `area`=5386 AND `quest_start`=27065 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84241, 5386, 27065, 27098, 0, 0, 2, 3, 74, 1);

-- Dreadguard
UPDATE `creature` SET `position_x`=1070.115, `position_y`=1506.748, `position_z`=31.02911, `MovementType`=2 WHERE `guid`=322043;
UPDATE `creature` SET `position_x`=1070.115, `position_y`=1506.748, `position_z`=31.02911 WHERE `guid`=322042;

DELETE FROM `creature_addon` WHERE `guid` = 322043;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(322043, 3220430, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950');

DELETE FROM `waypoint_data` WHERE `id` = 3220430;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3220430, 1, 1070.11500, 1506.748, 31.02911, NULL, 0, 0, 0, 0, 0),
(3220430, 2, 1092.72000, 1511.68, 29.87494, NULL, 0, 0, 0, 0, 0),
(3220430, 3, 1109.26000, 1513.38, 32.26623, NULL, 0, 0, 0, 0, 0),
(3220430, 4, 1122.57000, 1517.24, 34.48486, NULL, 0, 0, 0, 0, 0),
(3220430, 5, 1125.36000, 1537.25, 31.45801, NULL, 0, 0, 0, 0, 0),
(3220430, 6, 1124.48000, 1559.41, 30.35254, NULL, 0, 0, 0, 0, 0),
(3220430, 7, 1123.99000, 1587.8, 29.22581, NULL, 0, 0, 0, 0, 0),
(3220430, 8, 1120.64000, 1614.32, 29.03091, NULL, 0, 0, 0, 0, 0),
(3220430, 9, 1120.64000, 1614.32, 29.03091, NULL, 0, 0, 0, 0, 0),
(3220430, 10, 1092.70000, 1618.21, 27.43043, NULL, 0, 0, 0, 0, 0),
(3220430, 11, 1064.64000, 1619.24, 28.03432, NULL, 0, 0, 0, 0, 0),
(3220430, 12, 1022.61000, 1615.55, 23.80789, NULL, 0, 0, 0, 0, 0),
(3220430, 13, 1010.27000, 1608.76, 24.62271, NULL, 0, 0, 0, 0, 0),
(3220430, 14, 1010.56000, 1592.86, 25.89364, NULL, 0, 0, 0, 0, 0),
(3220430, 15, 1005.36000, 1575.49, 28.67892, NULL, 0, 0, 0, 0, 0),
(3220430, 16, 1003.64000, 1555.16, 28.84166, NULL, 0, 0, 0, 0, 0),
(3220430, 17, 1004.17000, 1535.15, 32.03062, NULL, 0, 0, 0, 0, 0),
(3220430, 18, 1010.66000, 1527.75, 33.21204, NULL, 0, 0, 0, 0, 0),
(3220430, 19, 1037.60100, 1528.172, 31.5291, NULL, 0, 0, 0, 0, 0),
(3220430, 20, 1048.53300, 1509.726, 32.8853, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `memberGUID` IN (322043, 322042);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(322043, 322043, 0, 0, 515, 0, 0),
(322043, 322042, 3.5, 270, 515, 0, 0);

-- Franny Mertz
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=50463; 

-- Commander Hickley
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `gossip_menu_id`=12025 WHERE `entry` =45496;

DELETE FROM `gossip_menu` WHERE `MenuID`=12025 AND `TextID`=16851;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(12025, 16851, 45745);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=2822 WHERE `MenuID`=12025 AND `OptionID`=0;

DELETE FROM `npc_vendor` WHERE `entry`=45496;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(45496, 11, 5048, 0, 0, 1, 0, 0, 45745), -- Blue Ribboned Wrapping Paper
(45496, 10, 4542, 0, 0, 1, 0, 0, 45745), -- Moist Cornbread
(45496, 9, 1205, 0, 0, 1, 0, 0, 45745), -- Melon Juice
(45496, 8, 5042, 0, 0, 1, 0, 0, 45745), -- Red Ribboned Wrapping Paper
(45496, 7, 4470, 0, 0, 1, 0, 0, 45745), -- Simple Wood
(45496, 6, 4498, 0, 0, 1, 0, 0, 45745), -- Brown Leather Satchel
(45496, 5, 4496, 0, 0, 1, 0, 0, 45745), -- Small Brown Pouch
(45496, 4, 4541, 0, 0, 1, 0, 0, 45745), -- Freshly Baked Bread
(45496, 3, 4540, 0, 0, 1, 0, 0, 45745), -- Tough Hunk of Bread
(45496, 2, 1179, 0, 0, 1, 0, 0, 45745), -- Ice Cold Milk
(45496, 1, 159, 0, 0, 1, 0, 0, 45745); -- Refreshing Spring Water

SET @ENTRY := 45496;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 2000, 65000, 75000, 80, 32192200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 65 - 75 seconds (1 - 2s initially) (OOC) - Self: Start timed action list id #32192200 (update out of combat)");

SET @ENTRY := 32192200;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.2617994, "After 1 seconds - Self: Set orientation to 0.2617994"),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "After 2 seconds - Self: Play emote ONESHOT_NO(DNR) (274)"),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 20000, 25000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.2463124, "After 20 - 25 seconds - Self: Set orientation to 3.2463124");

 -- "Salty" Rocka
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `ScriptName` = 'npc_silverpine_salty_rocka'  WHERE `entry` = 45498;

DELETE FROM `creature_template_addon` WHERE `entry`=45498;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(45498, 0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '83829');

DELETE FROM `creature_text` WHERE `CreatureID` = 45498;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(45498, 0, 0, 'Hey over there! Hey! Hey! Over there! How\'sh everything going Gororgararar?', 14, 1, 100, 5, 0, 0, 0, 45623, 0, 'Rocka 00'),
(45498, 1, 0, 'HA! Shows how much you know. I left the critter back on the third ship!', 14, 1, 100, 5, 0, 0, 0, 45634, 0, 'Rocka 01'),
(45498, 2, 0, 'Yoo hoo! "Shmaltzy!" Hey, why come your shupplies... Whe... Oh... Um... You got lots of boxes to keep track of...', 14, 1, 100, 5, 0, 0, 0, 45624, 0, 'Rocka 10'),
(45498, 3, 0, 'I didn\'t like that pet anyways. Beshides... people stop by all the time and give me their pets. If I lost one, it doesn\'t matter. I\'ve got dozens more to lose!', 14, 1, 100, 5, 0, 0, 0, 45637, 0, 'Rocka 11'),
(45498, 4, 0, 'Hey over there! Hey! Hey! Over there! How\'sh everything going Gororgararar?', 14, 1, 100, 5, 0, 0, 0, 45623, 0, 'Rocka 20'),
(45498, 5, 0, 'My pet! Oh no! Uh... I am shure that pet is around here somewhere...', 14, 1, 100, 5, 0, 0, 0, 45633, 0, 'Rocka 21'),
(45498, 6, 0, 'Hey "Salty" when are you going to get a new name? Thish town ain\'t big \'nough for two of ussh...', 14, 1, 100, 5, 0, 0, 0, 45621, 0, 'Rocka 30'),
(45498, 7, 0, 'Wait... whee is my pet? It\'s gone! No need to panic... Just need a quick drink and I can figure out where he went to.', 14, 1, 100, 5, 0, 0, 0, 45636, 0, 'Rocka 31'),
(45498, 8, 0, '"Malty!" Hey, "Malty!" I thought you were going to get us shome more booze! What\'sh the hold up?', 14, 1, 100, 5, 0, 0, 0, 45626, 0, 'Rocka 40'),
(45498, 9, 0, 'I didn\'t like that pet anyways. Beshides... people stop by all the time and give me their pets. If I lost one, it doesn\'t matter. I\'ve got dozens more to lose!', 14, 1, 100, 5, 0, 0, 0, 45637, 0, 'Rocka 41');

-- "Salty" Gorgar
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` = 45497;

DELETE FROM `creature_template_addon` WHERE `entry`=45497;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(45497, 0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '83829');

DELETE FROM `creature_text` WHERE `CreatureID` = 45497;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(45497, 0, 0, 'Hey, shtop bothering me. You\'re a dishgrace to us all. You can\'t even hold onto your own petsh!', 14, 1, 100, 5, 0, 0, 0, 45631, 0, 'Gorgar 00'),
(45497, 1, 0, 'Maybe you should worry about your pet and not me! I\'m taking care of my bishinesh jusht fine!', 14, 1, 100, 5, 0, 0, 0, 45628, 0, 'Gorgar 10'),
(45497, 2, 0, 'Hey, shtop bothering me. You\'re a dishgrace to us all. You can\'t even hold onto your own petsh!', 14, 1, 100, 5, 0, 0, 0, 45631, 0, 'Gorgar 20'), 
(45497, 3, 0, 'It\'s "Salty!" I got here firsht! I got off the boat and onto land firsht! I called the name "Salty." Hey... Where\'s your pet at?', 14, 1, 100, 5, 0, 0, 0, 45627, 0, 'Gorgar 30'),
(45497, 4, 0, '"Shalty." That\'s my name! Your name should be "I can\'t hold onto petsh." I can\'t believe anyone would trusht you with a beasht.', 14, 1, 100, 5, 0, 0, 0, 45629, 0, 'Gorgar 40');

DELETE FROM `npc_vendor` WHERE `entry`=45497;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(45497, 29, 20815, 0, 0, 1, 0, 0, 45745), -- Jeweler's Kit
(45497, 28, 39354, 0, 0, 1, 0, 0, 45745), -- Light Parchment
(45497, 27, 2324, 0, 0, 1, 0, 0, 45745), -- Bleach
(45497, 26, 2604, 0, 0, 1, 0, 0, 45745), -- Red Dye
(45497, 25, 6260, 0, 0, 1, 0, 0, 45745), -- Blue Dye
(45497, 24, 2605, 0, 0, 1, 0, 0, 45745), -- Green Dye
(45497, 23, 6530, 0, 0, 1, 0, 0, 45745), -- Nightcrawlers
(45497, 22, 6529, 0, 0, 1, 0, 0, 45745), -- Shiny Bauble
(45497, 21, 4289, 0, 0, 1, 0, 0, 45745), -- Salt
(45497, 20, 2880, 0, 0, 1, 0, 0, 45745), -- Weak Flux
(45497, 19, 2678, 0, 0, 1, 0, 0, 45745), -- Mild Spices
(45497, 18, 2321, 0, 0, 1, 0, 0, 45745), -- Fine Thread
(45497, 17, 2320, 0, 0, 1, 0, 0, 45745), -- Coarse Thread
(45497, 16, 3371, 0, 0, 1, 0, 0, 45745), -- Crystal Vial
(45497, 15, 6217, 0, 0, 1, 0, 0, 45745), -- Copper Rod
(45497, 14, 6256, 0, 0, 1, 0, 0, 45745), -- Fishing Pole
(45497, 13, 39505, 0, 0, 1, 0, 0, 45745), -- Virtuoso Inking Set
(45497, 12, 5956, 0, 0, 1, 0, 0, 45745), -- Blacksmith Hammer
(45497, 11, 2901, 0, 0, 1, 0, 0, 45745), -- Mining Pick
(45497, 10, 85663, 0, 0, 1, 0, 0, 45745), -- Herbalist's Spade
(45497, 9, 7005, 0, 0, 1, 0, 0, 45745), -- Skinning Knife
(45497, 8, 5042, 0, 0, 1, 0, 0, 45745), -- Red Ribboned Wrapping Paper
(45497, 7, 4470, 0, 0, 1, 0, 0, 45745), -- Simple Wood
(45497, 6, 4498, 0, 0, 1, 0, 0, 45745), -- Brown Leather Satchel
(45497, 5, 4496, 0, 0, 1, 0, 0, 45745), -- Small Brown Pouch
(45497, 4, 4541, 0, 0, 1, 0, 0, 45745), -- Freshly Baked Bread
(45497, 3, 4540, 0, 0, 1, 0, 0, 45745), -- Tough Hunk of Bread
(45497, 2, 1179, 0, 0, 1, 0, 0, 45745), -- Ice Cold Milk
(45497, 1, 159, 0, 0, 1, 0, 0, 45745); -- Refreshing Spring Water

-- AreaTrigger - 6222 (Forsaken Rear Guard)
DELETE FROM `areatrigger_scripts` WHERE `entry` = 6222;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(6222, 'at_silverpine_forsaken_rear_guard');

-- Admiral Hatchet
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `ScriptName` = 'npc_silverpine_admiral_hatchet' WHERE `entry` = 44916;

DELETE FROM `gossip_menu` WHERE `MenuID`=11901 AND `TextID`=16702;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(11901, 16702, 45745);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11901 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(11901, 0, 0, 'I seem to have misplaced my sea pup, admiral. Do you have another that you could lend to me?', 45023, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11901;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11901, 0, 0, 1, 9, 0, 27069, 0, 0, 0, 0, 0, '', 'Show gossip option if player has quest 27069');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11897 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=1 AND `ConditionTarget`=0 AND `ConditionValue1`=83839  AND `ConditionValue2`=1 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11901, 0, 0, 1, 1, 0, 83839, 1, 0, 1, 0, 0, '', 'Show gossip option if player doesn\'t have aura 83839');

DELETE FROM `creature_text` WHERE `CreatureID`= 44916;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44916, 0, 0, 'Who\'s not drunk, Torok?', 12, 0, 100, 0, 0, 0, 0, 45018, 0, 'Admiral Hatchet to Player'),
(44916, 1, 0, 'Yes.', 12, 0, 100, 0, 0, 0, 0, 45020, 0, 'Admiral Hatchet to Player');

-- Warlord Torok
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` = 44917;

DELETE FROM `creature_text` WHERE `CreatureID` = 44917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44917, 0, 0, 'Including me?', 12, 0, 100, 0, 0, 0, 0, 45019, 0, 'Warlord Torok to Player'),
(44917, 1, 0, '<hic!> Well... Let\'s see... By my count, nobody. The whole crew\'s drunk out of their gourds, admiral... \'cept the sea pups... <hic!>', 12, 0, 100, 0, 0, 0, 0, 45021, 0, 'Warlord Torok to Player');

-- Apothecary Wormcrud
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `ScriptName` = 'npc_silverpine_apothecary_wormcrud'  WHERE `entry` = 44912;

DELETE FROM `creature_text` WHERE `CreatureID` = 44912;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44912, 0, 0, 'Touch my chicken and I will kill you in your sleep. Am I understood?', 12, 1, 100, 1, 0, 0, 0, 45069, 0, '');

-- Orc Sea Dog (44913)
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` = 44913;

UPDATE `creature` SET `orientation`=1.58 WHERE `guid`=321872;
UPDATE `creature` SET `ScriptName`='npc_silverpine_orc_sea_dog_not_sick' WHERE `guid` IN (321875, 321872, 321925, 321930, 321930, 321927, 321871, 321915, 321870, 321874, 321911, 321869, 321933);
UPDATE `creature` SET `ScriptName`='npc_silverpine_orc_sea_dog_sick' WHERE `guid` IN (321878, 321934, 321924, 321863);

DELETE FROM `creature_addon` WHERE `guid` IN (321916, 321918, 321919, 321921);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321916, 0, 0, 0, 0, 1, 0, 868, 0, 0, 0, '83829'),
(321918, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83829'),
(321919, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83829'),
(321921, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83829');

DELETE FROM `creature_text` WHERE `CreatureID` = 44913;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44913, 0, 0, 'What\'sh with the huuuuge bush chick-a-doodle?', 12, 1, 100, 1, 0, 0, 0, 45061, 0, ''),
(44913, 1, 0, 'It\'sh makin\' me hungry... why\'s it shooo big? You shome kind of idiot or shomething? Makin\' a chicken so big... Who doesh that?', 12, 1, 100, 1, 0, 0, 0, 45062, 0, ''),
(44913, 2, 0, 'Forshaken do... that\'sh who... It\'sh sho big... Look at it\'sh big stupid neck. I jusht want to choke it to death!', 12, 1, 100, 1, 0, 0, 0, 45063, 0, '');

--
-- North Tide's Beachhead

-- Rabid Dog
DELETE FROM `creature_loot_template` WHERE `Entry`=1766 AND `Item`=60793;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1766, 60793, 0, 40, 1, 1, 0, 1, 1, 'Item for questId 27082');

-- Giant Rabid Bear
DELETE FROM `creature_loot_template` WHERE `Entry`=1797 AND `Item`=60793;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1797, 60793, 0, 40, 1, 1, 0, 1, 1, 'Item for questId 27082');

-- Reef Frenzy
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` = 2173;

UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='5888' WHERE `entry`=2173;

DELETE FROM `creature_template_scaling` WHERE (`Entry`=2173 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(2173, 0, 0, 0, 7, 45745);

-- Forest Ettin
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `AIName` = '', `ScriptName` = 'npc_silverpine_forest_ettin'  WHERE `entry` = 44367;

UPDATE `creature` SET `position_x`=859.461, `position_y`=1608.500, `position_z`=30.4501, `MovementType`=2 WHERE `guid`= 321474;

DELETE FROM `creature_addon` WHERE `guid` = 321474;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(321474, 3214740, 0, 0, 0, 1, 0, 0, 0, 0, 4, '');

DELETE FROM `waypoint_data` WHERE `id`= 3214740;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3214740, 1, 860.453, 1547.99, 33.56122, NULL, 0, 0, 0, 0, 0),
(3214740, 2, 863.394, 1511.96, 37.08387, NULL, 0, 0, 0, 0, 0),
(3214740, 3, 894.108, 1503.59, 36.82511, NULL, 0, 0, 0, 0, 0),
(3214740, 4, 936.399, 1485.24, 39.62898, NULL, 0, 0, 0, 0, 0),
(3214740, 5, 952, 1464.76, 42.62051, NULL, 0, 0, 0, 0, 0),
(3214740, 6, 949.054, 1449.93, 44.44144, NULL, 0, 0, 0, 0, 0),
(3214740, 7, 946.674, 1406.7, 43.81255, NULL, 0, 0, 0, 0, 0),
(3214740, 8, 941.361, 1382.5, 45.44262, NULL, 0, 0, 0, 0, 0),
(3214740, 9, 968.085, 1368.38, 47.35212, NULL, 0, 0, 0, 0, 0),
(3214740, 10, 994.679, 1365.31, 46.46651, NULL, 0, 0, 0, 0, 0),
(3214740, 11, 1022.17, 1371.79, 43.73402, NULL, 0, 0, 0, 0, 0),
(3214740, 12, 1044.97, 1385.64, 40.32015, NULL, 0, 0, 0, 0, 0),
(3214740, 13, 1075.88, 1403.13, 38.78938, NULL, 0, 0, 0, 0, 0),
(3214740, 14, 1107.28, 1417.12, 38.96357, NULL, 0, 0, 0, 0, 0),
(3214740, 15, 1126.86, 1437.76, 40.30442, NULL, 0, 0, 0, 0, 0),
(3214740, 16, 1143.65, 1465.56, 36.97102, NULL, 0, 0, 0, 0, 0),
(3214740, 17, 1164.7, 1494.21, 36.14241, NULL, 0, 0, 0, 0, 0),
(3214740, 18, 1183.27, 1526.79, 34.55787, NULL, 0, 0, 0, 0, 0),
(3214740, 19, 1191.77, 1562.13, 30.12153, NULL, 0, 0, 0, 0, 0),
(3214740, 20, 1187.24, 1596.82, 25.16793, NULL, 0, 0, 0, 0, 0),
(3214740, 21, 1180.39, 1624.58, 25.20637, NULL, 0, 0, 0, 0, 0),
(3214740, 22, 1172.26, 1657.86, 22.88879, NULL, 0, 0, 0, 0, 0),
(3214740, 23, 1179.45, 1696.03, 16.91406, NULL, 0, 0, 0, 0, 0),
(3214740, 24, 1175.39, 1733.19, 13.28851, NULL, 0, 0, 0, 0, 0),
(3214740, 25, 1174.906, 1766.189, 14.37276, NULL, 0, 0, 0, 0, 0),
(3214740, 26, 1195.94, 1792.24, 17.68075, NULL, 0, 0, 0, 0, 0),
(3214740, 27, 1218.25, 1816.79, 12.99665, NULL, 0, 0, 0, 0, 0),
(3214740, 28, 1225.25, 1859.57, 11.28443, NULL, 0, 0, 0, 0, 0),
(3214740, 29, 1213.59, 1900.01, 11.36619, NULL, 0, 0, 0, 0, 0),
(3214740, 30, 1186.21, 1915.47, 10.18469, NULL, 0, 0, 0, 0, 0),
(3214740, 31, 1152.19, 1941.21, 11.13721, NULL, 0, 0, 0, 0, 0),
(3214740, 32, 1118.33, 1922.58, 16.06248, NULL, 0, 0, 0, 0, 0),
(3214740, 33, 1101.97, 1912.06, 18.04515, NULL, 0, 0, 0, 0, 0),
(3214740, 34, 1084.54, 1921.85, 15.57126, NULL, 0, 0, 0, 0, 0),
(3214740, 35, 1058.26, 1901.42, 9.566391, NULL, 0, 0, 0, 0, 0),
(3214740, 36, 1026.38, 1889.16, 8.246282, NULL, 0, 0, 0, 0, 0),
(3214740, 37, 977.4756, 1886.241, 9.116446, NULL, 0, 0, 0, 0, 0),
(3214740, 38, 928.488, 1887.07, 2.633808, NULL, 0, 0, 0, 0, 0),
(3214740, 39, 893.6934, 1883.174, 3.139614, NULL, 0, 0, 0, 0, 0),
(3214740, 40, 885.464, 1851.93, 4.246497, NULL, 0, 0, 0, 0, 0),
(3214740, 41, 903.932, 1809.15, 8.933544, NULL, 0, 0, 0, 0, 0),
(3214740, 42, 854.278, 1803.49, 7.936779, NULL, 0, 0, 0, 0, 0),
(3214740, 43, 861.115, 1762.9, 13.06791, NULL, 0, 0, 0, 0, 0),
(3214740, 44, 833.828, 1714.58, 20.25066, NULL, 0, 0, 0, 0, 0),
(3214740, 45, 835.399, 1669.13, 24.05216, NULL, 0, 0, 0, 0, 0),
(3214740, 46, 847.825, 1630.31, 26.21234, NULL, 0, 0, 0, 0, 0);

UPDATE `creature` SET `position_x` = 818.707, `position_y` = 1677.33, `position_z` = 25.49682, `MovementType` = 2 WHERE `guid` = 321304;

DELETE FROM `creature_addon` WHERE `guid` = 321304;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(321304, 3213040, 0, 0, 0, 1, 0, 0, 0, 0, 3, '');

DELETE FROM `waypoint_data` WHERE `id`= 3213040;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3213040, 1, 818.707, 1677.33, 25.49682, NULL,0, 0, 0, 0, 0),
(3213040, 2, 790.498, 1643.38, 28.69943, NULL, 0, 0, 0, 0, 0),
(3213040, 3, 818.707, 1677.33, 25.49682, NULL, 0, 0, 0, 0, 0),
(3213040, 4, 820.25, 1719.55, 24.42554, NULL, 0, 0, 0, 0, 0),
(3213040, 5, 818.189, 1748.84, 20.39416, NULL, 0, 0, 0, 0, 0),
(3213040, 6, 792.821, 1781.75, 15.09375, NULL, 0, 0, 0, 0, 0),
(3213040, 7, 818.189, 1748.84, 20.39416, NULL, 0, 0, 0, 0, 0),
(3213040, 8, 820.25, 1719.55, 24.42554, NULL, 0, 0, 0, 0, 0),
(3213040, 9, 818.707, 1677.33, 25.49682, NULL, 0, 0, 0, 0, 0),
(3213040, 10, 790.498, 1643.38, 28.69943, NULL, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 83904 AND `ScriptName` = 'spell_gen_reverse_cast_target_to_caster_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83904, 'spell_gen_reverse_cast_target_to_caster_triggered');

-- Orc Sea Pup (44914)
UPDATE `creature_template` SET `unit_flags` = 33288, `VehicleId` = 1060, `ScriptName` = 'npc_silverpine_orc_sea_pup' WHERE `entry` = 44914;

DELETE FROM `creature_text` WHERE `CreatureID`=44914;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44914, 0, 0, 'Where to going, captain?', 12, 1, 100, 66, 0, 0, 0, 44990, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 1, 0, 'OOF! Maybe trow little softer, captain?', 12, 1, 100, 0, 0, 0, 0, 44992, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 2, 0, 'Heavy... no can see notin.', 12, 1, 100, 0, 0, 0, 0, 44993, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 3, 0, 'Captain, pup need help!', 12, 1, 100, 0, 0, 0, 0, 44996, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 4, 0, 'Please, captain, I can put box down?', 12, 1, 100, 0, 0, 0, 0, 44999, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 5, 0, 'NO MORE! DIS IS MAXI... MAXIMO... ME... DIS TOO MUCH!', 12, 1, 100, 0, 0, 0, 0, 45003, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 6, 0, 'Where to put? Dey falling! HELP!', 12, 1, 100, 0, 0, 0, 0, 45025, 5, 'Orc Sea Pup to Orc Crate'),
(44914, 7, 0, 'OOF!', 12, 1, 100, 0, 0, 0, 0, 45024, 5, 'Orc Sea Pup to Orc Crate');

DELETE FROM `conditions` WHERE `SourceEntry`= 83838 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 83838, 0, 0, 31, 0, 3, 44914, 0, 0, 0, '', 'Pick Up Orc Crate - Target Orc Sea Pup');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83865 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44914 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 83865, 0, 0, 31, 0, 3, 44914, 0, 0, 0, 0, '', 'Sea Pup Trigger - Target Orc Sea Pup');

-- Despawn All Summons
DELETE FROM `spell_script_names` WHERE `spell_id` = 83840 AND `ScriptName` = 'spell_silverpine_despawn_all_summons_steel_thunder';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83840, 'spell_silverpine_despawn_all_summons_steel_thunder');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83840 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44914 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83840, 0, 1, 31, 0, 3, 44914, 0, 0, 0, 0, '', 'Despawn All Summons - Target Orc Sea Dog');

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (8421, 8422, 8423, 8424, 8425);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES 
(8421, 0, 3.8, 2.0, 0, 0, 1),
(8422, 0, -2.3, 2.1, 0, 0, 1),
(8423, 0, 3.3, -1.2, 0, 0, 1),
(8424, 0, -2.8, -2.2, 0, 0, 1),
(8425, 0, 4.1, -2.7, 0, 0, 1);

-- Sea Dog Crate
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 205165, 0, 130, 928, '0', 0, 0, 871.46502685546875, 1811.1199951171875, 8.559800148010253906, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Sea Dog Crate (Area: North Tide's Beachhead - Difficulty: 0)
(@OGUID+1, 205165, 0, 130, 928, '0', 0, 0, 916.91998291015625, 1762.8900146484375, 15.93459987640380859, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Sea Dog Crate (Area: North Tide's Beachhead - Difficulty: 0)
(@OGUID+2, 205165, 0, 130, 928, '0', 0, 0, 875.010009765625, 1889.3599853515625, 1.283589959144592285, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Sea Dog Crate (Area: North Tide's Beachhead - Difficulty: 0)
(@OGUID+3, 205165, 0, 130, 928, '0', 0, 0, 966.99298095703125, 1792.3599853515625, 14.43109989166259765, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, 45745), -- Sea Dog Crate (Area: North Tide's Beachhead - Difficulty: 0)
(@OGUID+4, 205165, 0, 130, 928, '0', '0', 0, 890.1199951171875, 1817.199951171875, 8.806759834289550781, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 45745); -- Sea Dog Crate (Area: North Tide's Beachhead - Difficulty: 0)

-- Orc Crate
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_orc_crate' WHERE `entry` = 44915;

DELETE FROM `spell_script_names` WHERE `spell_id` = 83838 AND `ScriptName` = 'spell_silverpine_pick_up_orc_crate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83838, 'spell_silverpine_pick_up_orc_crate');

-- North Tide's Invisible Stalker
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags3`=16777217 WHERE `entry`=44920; -- North Tide's Invisible Stalker

SET @ENTRY := 44920;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 83860, 0, 0, 0, 11, 83859, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Toss Torch (83860) hit - Self: Cast spell North Tide's Fire (83859) on random 1 Self");

-- North Tide's Invisible Stalker (Large)
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags3`=16777217 WHERE `entry`=44923; -- North Tide's Invisible Stalker (Large)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 857.04498291015625, 1988.510009765625, 33.87583160400390625, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+1, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 758.46197509765625, 1980.030029296875, 20.40123367309570312, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+2, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 854.37298583984375, 1978.0799560546875, 13.43593311309814453, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+3, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 762.86102294921875, 2005.3199462890625, 17.35703468322753906, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+4, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 872.2080078125, 2013.8199462890625, 7.5128936767578125, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+5, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 755.88702392578125, 1980.81005859375, 39.68003082275390625, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+6, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 897.33197021484375, 2001.800048828125, 22.52033424377441406, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+7, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 854.9310302734375, 1996.1199951171875, 23.16783332824707031, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+8, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 767.8330078125, 2012.5, 14.70353317260742187, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+9, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 771.29901123046875, 1986.25, 10.92123317718505859, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+10, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 770.8060302734375, 1971.1199951171875, 18.53173446655273437, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+11, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 894.36798095703125, 1999.25, 36.635833740234375, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+12, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 749.27801513671875, 1982.0699462890625, 28.21743392944335937, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+13, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 767.65301513671875, 2006.8499755859375, 43.02943038940429687, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+14, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 884.2550048828125, 2000.6800537109375, 20.49443435668945312, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+15, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 868.49700927734375, 1969.4000244140625, 13.43403339385986328, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+16, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 742.177001953125, 2012.43994140625, 15.46923255920410156, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+17, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 777.81097412109375, 1966.75, 14.30103302001953125, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+18, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 858.28997802734375, 1988.22998046875, 21.47653388977050781, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+19, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 853.24798583984375, 1963.1300048828125, 15.85483264923095703, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0)
(@CGUID+20, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 854.50897216796875, 1971.530029296875, 16.14943313598632812, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+21, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 769.34002685546875, 2010.5400390625, 30.17073440551757812, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)
(@CGUID+22, 44923, 0, 130, 928, '0', 169, 0, 0, 0, 883.5830078125, 1999.6099853515625, 30.94133377075195312, 0, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745); -- North Tide's Invisible Stalker (Large) (Area: North Tide's Beachhead - Difficulty: 0) (Auras: 83859 - North Tide's Fire)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'), -- North Tide's Invisible Stalker - 83859 - North Tide's Fire
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, 0, '83859'); -- North Tide's Invisible Stalker - 83859 - North Tide's Fire

SET @ENTRY := 44923;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 55000, 60000, 11, 83859, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 55 - 60 seconds (0 - 0s initially) (OOC) - Self: Cast spell 83859 on Self (limit to 1 target)');

-- Bloodfang Scavenger
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry` IN (44547, 44549);

UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 10 WHERE `id` IN (44547, 44549);

UPDATE `creature` SET `wander_distance`= 0, `position_x` = 909.885, `position_y` = 1812.9, `position_z` = 8.608471, `MovementType`= 2 WHERE `guid` = 321893;

DELETE FROM `creature_addon` WHERE `guid` = 321893;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(321893, 3218930, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `waypoint_data` WHERE `id` = 3218930;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3218930, 1, 909.88500, 1812.9, 8.608471, NULL, 0, 0, 0, 0, 0),
(3218930, 2, 919.51400, 1792.47, 11.27575, NULL, 0, 0, 0, 0, 0),
(3218930, 3, 943.59000, 1770.39, 12.75151, NULL, 0, 0, 0, 0, 0),
(3218930, 4, 909.88500, 1812.9, 8.608471, NULL, 0, 0, 0, 0, 0),
(3218930, 5, 894.66500, 1842.63, 4.458411, NULL, 0, 0, 0, 0, 0),
(3218930, 6, 877.19400, 1868.39, 3.245327, NULL, 0, 0, 0, 0, 0),
(3218930, 7, 877.23340, 1868.347, 3.264614, NULL, 0, 0, 0, 0, 0),
(3218930, 8, 894.64060, 1842.675, 4.564612, NULL, 0, 0, 0, 0, 0);

UPDATE `creature` SET `MovementType` = 2, `wander_distance`= 0 WHERE `guid` = 321729;

DELETE FROM `creature_addon` WHERE `guid` = 321729;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(321729, 3217290, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `waypoint_data` WHERE `id` = 3217290;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(3217290, 1, 885.007, 1731.87, 15.9815, NULL, 0, 0, 0, 0, 0),
(3217290, 2, 877.171, 1737.25, 15.2819, NULL, 0, 0, 0, 0, 0),
(3217290, 3, 865.628, 1758.11, 13.3475, NULL, 0, 0, 0, 0, 0),
(3217290, 4, 864.333, 1768.15, 12.6892, NULL, 0, 0, 0, 0, 0),
(3217290, 5, 857.621, 1776.82, 11.6192, NULL, 0, 0, 0, 0, 0),
(3217290, 6, 847.002, 1790.71, 9.27837, NULL, 0, 0, 0, 0, 0),
(3217290, 7, 843.96, 1805.72, 6.38237, NULL, 0, 0, 0, 0, 0),
(3217290, 8, 837.155, 1828.31, 3.93294, NULL, 0, 0, 0, 0, 0),
(3217290, 9, 830.699, 1846.04, 2.36316, NULL, 0, 0, 0, 0, 0),
(3217290, 10, 837.155, 1828.31, 3.93294, NULL, 0, 0, 0, 0, 0),
(3217290, 11, 843.96, 1805.72, 6.38237, NULL, 0, 0, 0, 0, 0),
(3217290, 12, 847.002, 1790.71, 9.27837, NULL, 0, 0, 0, 0, 0),
(3217290, 13, 857.621, 1776.82, 11.6192, NULL, 0, 0, 0, 0, 0),
(3217290, 14, 864.333, 1768.15, 12.6892, NULL, 0, 0, 0, 0, 0),
(3217290, 15, 865.628, 1758.11, 13.3475, NULL, 0, 0, 0, 0, 0),
(3217290, 16, 877.171, 1737.25, 15.2819, NULL, 0, 0, 0, 0, 0);

SET @ENTRY := 44547;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 25000, 30000, 11, 84308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 30 seconds (4 - 6s initially) (IC) - Self: Cast spell 84308 on Self'),
(@ENTRY, 0, 1, 0, 9, 0, 100, 0, 0, 30, 14000, 15000, 11, 78509, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 30 yards (cooldown 14000 - 15000 ms) - Self: Cast spell 78509 on Victim'),
(@ENTRY, 0, 2, 3, 1, 0, 50, 0, 4000, 14000, 25000, 55000, 127, 0, 5500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Self: Pause movement for 5.5sec on movement slot 0'),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[1] in 500 - 500 ms // -meta_wait'),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 67, 2, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[2] in 1500 - 1500 ms // -meta_wait'),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 3, 4000, 4000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[3] in 4000 - 4000 ms // -meta_wait'),
(@ENTRY, 0, 6, 0, 59, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 44920, 20, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Look at Creature North Tide\'s Invisible Stalker (44920) in 20 yd'),
(@ENTRY, 0, 7, 8, 59, 0, 100, 0, 2, 0, 0, 0, 11, 83860, 0, 0, 1, 0, 0, 9, 44920, 0, 20, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Cast spell 83860 on Creature North Tide\'s Invisible Stalker (44920) in 0 - 20 yards (limit to 1 target)'),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 83860, 0, 0, 1, 0, 0, 9, 44923, 0, 20, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Cast spell 83860 on Creature North Tide\'s Invisible Stalker (Large) (44923) in 0 - 20 yards (limit to 1 target)'),
(@ENTRY, 0, 9, 0, 59, 0, 100, 0, 3, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[3] triggered - Self: Play emote 15'),
(@ENTRY, 0, 10, 0, 83, 0, 30, 0, 83860, 30000, 40000, 0, 4, 17671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell 83860 cast (wait 30000 - 40000 ms before next trigger) - Self: Play direct sound 17671 to every player in visibility range of Self');

SET @ENTRY := 44549;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 25000, 30000, 11, 84308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 30 seconds (4 - 6s initially) (IC) - Self: Cast spell 84308 on Self'),
(@ENTRY, 0, 1, 0, 9, 0, 100, 0, 0, 30, 14000, 15000, 11, 78509, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 30 yards (cooldown 14000 - 15000 ms) - Self: Cast spell 78509 on Victim'),
(@ENTRY, 0, 2, 3, 1, 0, 50, 0, 4000, 14000, 25000, 55000, 127, 0, 5500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Self: Pause movement for 5.5sec on movement slot 0'),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[1] in 500 - 500 ms // -meta_wait'),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 67, 2, 1500, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[2] in 1500 - 1500 ms // -meta_wait'),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 3, 4000, 4000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 25 - 55 seconds (4 - 14s initially) (OOC) - Trigger timed event timedEvent[3] in 4000 - 4000 ms // -meta_wait'),
(@ENTRY, 0, 6, 0, 59, 0, 100, 0, 1, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 44920, 20, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Look at Creature North Tide\'s Invisible Stalker (44920) in 20 yd'),
(@ENTRY, 0, 7, 8, 59, 0, 100, 0, 2, 0, 0, 0, 11, 83860, 0, 0, 1, 0, 0, 9, 44920, 0, 20, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Cast spell 83860 on Creature North Tide\'s Invisible Stalker (44920) in 0 - 20 yards (limit to 1 target)'),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 83860, 0, 0, 1, 0, 0, 9, 44923, 0, 20, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Cast spell 83860 on Creature North Tide\'s Invisible Stalker (Large) (44923) in 0 - 20 yards (limit to 1 target)'),
(@ENTRY, 0, 9, 0, 59, 0, 100, 0, 3, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[3] triggered - Self: Play emote 15'),
(@ENTRY, 0, 10, 0, 83, 0, 30, 0, 83860, 30000, 40000, 0, 4, 17671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell 83860 cast (wait 30000 - 40000 ms before next trigger) - Self: Play direct sound 17671 to every player in visibility range of Self');

-- Mutant Bush Chicken
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_mutant_bush_chicken'  WHERE `entry` = 44935;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44935;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44935, 1, 1, 0, 0, 0, 0, NULL);

-- Release Diseased Mutant Bush Chicken
DELETE FROM `spell_script_names` WHERE `spell_id` = 83902 AND `ScriptName` = 'spell_silverpine_release_diseased_mutant_bush_chicken';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83902, 'spell_silverpine_release_diseased_mutant_bush_chicken');

--
-- The Skittering Dark

-- Orc Sea Dog (44942)
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_orc_sea_dog' WHERE `entry` = 44942;

DELETE FROM `creature_text` WHERE `CreatureID` = 44942;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44942, 0, 0, 'We gotta find the matriarch of this operation and end her!', 12, 1, 100, 5, 0, 0, 0, 45079, 5, 'Orc Sea Dog to Player'),
(44942, 0, 1, 'Thank you, friend. Let\'s kill us some overgrown... spiders. Sounded better in my head.', 12, 1, 100, 5, 0, 0, 0, 45078, 5, 'Orc Sea Dog to Player'),
(44942, 0, 2, 'I need a drink!', 12, 1, 100, 5, 0, 0, 0, 45080, 5, 'Orc Sea Dog to Player'),
(44942, 0, 3, 'Welcome to the party, $g pal:lady;!', 12, 1, 100, 5, 0, 0, 0, 45077, 5, 'Orc Sea Dog to Player');

-- Despawn All Summons
DELETE FROM `spell_script_names` WHERE `spell_id` = 83935 AND `ScriptName` = 'spell_gen_despawn_all_summons_owned_by_caster';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83935, 'spell_gen_despawn_all_summons_owned_by_caster');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83935 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44942 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 83935, 0, 1, 31, 0, 3, 44942, 0, 0, 0, 0, '', 'Despawn All Summons - Target Orc Sea Dog');

-- Skitterweb Lurker
UPDATE `creature` SET `wander_distance`= 10, `MovementType`= 1 WHERE `id` = 1781;

SET @ENTRY := 1781;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 0, 0, 100, 0, 6000, 9000, 18000, 24000, 85, 82715, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 18 - 24 seconds (6 - 9s initially) (IC) - Self: Cast spell 82715 on self'),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 1000, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 18 - 24 seconds (6 - 9s initially) (IC) - Trigger timed event timedEvent[1] in 1000 - 1000 ms // -meta_wait'),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 1, 0, 0, 0, 85, 82717, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Cast spell 82717 with flags triggered on self');

-- Skitterweb Striker
SET @ENTRY := 1780;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 9, 0, 100, 0, 0, 5, 12000, 14000, 11, 87081, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 5 yards (cooldown 12000 - 14000 ms) - Self: Cast spell 87081 on Victim');

-- Krethis the Shadowspinner
SET @ENTRY := 12433;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 1784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 1784 on Self'),
(@ENTRY, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 1784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 1784 on Self'),
(@ENTRY, 0, 2, 0, 9, 0, 100, 0, 0, 30, 12000, 14500, 11, 12023, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 30 yards (cooldown 12000 - 14500 ms) - Self: Cast spell 12023 on Victim');

-- Skitterweb Matriarch
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_skitterweb_matriarch', `AIName` = '', `flags_extra` = 512 WHERE `entry` = 44906;

DELETE FROM `creature_template_scaling` WHERE (`Entry`=44906 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(44906, 0, 0, 0, 7, 45745);

DELETE FROM `conditions` WHERE `SourceEntry`= 83827 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 83827, 0, 0, 31, 0, 3, 44908, 0, 0, 0, '', 'Skitterweb Web - Target Skitterweb Stalker');

-- Skitterweb Invisible Stalker
DELETE FROM `creature_template_movement` WHERE `CreatureId`=44908;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44908, NULL, NULL, 1, NULL, NULL, NULL, NULL);

-- Webbed Victim
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_webbed_victim' WHERE `entry` = 44941;

DELETE FROM `creature` WHERE `guid` IN (@CGUID+23, @CGUID+24, @CGUID+25, @CGUID+26, @CGUID+27, @CGUID+28, @CGUID+29, @CGUID+30, @CGUID+31);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+23, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1285.29, 1866.04, 24.8907, 2.51675, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+24, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1252.66, 1857.56, 14.3729, 3.42388, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+25, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1260.92, 1848.44, 16.6487, 4.18964, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+26, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1280.06, 1818.83, 20.8724, 3.49063, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+27, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1372.55, 1954.99, 13.8267, 1.93161, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+28, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1379.09, 1977.50, 14.1315, 4.51165, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+29, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1398.48, 1972.15, 18.3701, 2.79556, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+30, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1422.53, 1930.36, 9.9526, 1.84131, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+31, 44941, 0, 130, 226, 0, 0, 169, 0, -1, 0, 0, 1417.66, 1941.61, 9.8029, 0.46687, 300, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `spell_script_names` WHERE `spell_id` = 83919 AND `ScriptName` = 'spell_silverpine_free_webbed_victim_random';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83919, 'spell_silverpine_free_webbed_victim_random');
