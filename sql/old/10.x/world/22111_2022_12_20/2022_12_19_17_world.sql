SET @CGUID := 396635;
SET @OGUID := 251378;
SET @EVENT := 2;

-- Areatrigger templates
DELETE FROM `areatrigger_template` WHERE (`Id`=12198 AND `IsServerSide`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(12198, 0, 0, 4, 15, 15, 0, 0, 0, 0, 0, 0, 47187);

-- DELETE FROM `areatrigger_create_properties` WHERE `Id`=x;
-- INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
-- (x, 12198, 0, 0, 0, 0, -1, 0, 48, 0, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 47187), -- SpellId : 0

-- Creature templates
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=1365; -- Goli Krumn
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=13433; -- Wulmort Jinglepocket
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=13434; -- Macey Jinglepocket
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=13444; -- Greatfather Winter
UPDATE `creature_template` SET `gossip_menu_id`=6813, `minlevel`=70, `maxlevel`=70, `faction`=774, `speed_walk`=1, `npcflag`=1, `unit_flags`=32768 WHERE `entry` IN (15782, 15783); -- Dwarf Winter Reveler
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=110441; -- Snowglobe Stalker
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=123745; -- Snowglobe Stalker 2
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=16777216 WHERE `entry`=158558; -- Red-Nosed Reindeer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=16777216 WHERE `entry`=158559; -- Great Reindeer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=16777217 WHERE `entry`=158560; -- Great Reindeer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=16777216, `unit_flags3`=16777217 WHERE `entry`=158561; -- Greatfather Winter's Sleigh

DELETE FROM `creature_template_addon` WHERE `entry` IN (1365, 13433, 13434, 13444, 110441, 123745, 128156, 158558, 158559, 158560, 158561);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(1365, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 1365 (Goli Krumn)
(13433, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 13433 (Wulmort Jinglepocket)
(13434, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 13434 (Macey Jinglepocket)
(13444, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 13444 (Greatfather Winter)
(110441, 0, 0, 0, 1, 0, 0, 0, 0, 0, '219624'), -- 110441 (Snowglobe Stalker) - Snowglobe
(123745, 0, 0, 0, 1, 0, 0, 0, 0, 0, '246235'), -- 123745 (Snowglobe Stalker 2) - Snowglobe
(128156, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 128156 (Globe Yeti)
(158558, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 158558 (Red-Nosed Reindeer)
(158559, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 158559 (Great Reindeer)
(158560, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''), -- 158560 (Great Reindeer)
(158561, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- 158561 (Greatfather Winter's Sleigh)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (110441, 123745, 158558, 158559, 158560, 158561);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(110441, 0, 0, 1, 1, 0, 0, NULL),
(123745, 0, 0, 1, 1, 0, 0, NULL),
(158558, 0, 0, 1, 0, 0, 0, NULL),
(158559, 0, 0, 1, 0, 0, 0, NULL),
(158560, 0, 0, 1, 0, 0, 0, NULL),
(158561, 0, 0, 1, 0, 0, 0, NULL);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (158558, 158559, 158560, 158561);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(158558, 93970, 1, 1),
(158559, 93970, 1, 1),
(158560, 93970, 1, 1);
-- (158561, 93970, 1, 1); (InteractSpellID - Cannot be added because it prevents the accessory from mounting)

-- Vehicle data
DELETE FROM `vehicle_template_accessory` WHERE `entry`=158561;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(158561, 158558, 1, 1, 'Greatfather Winter''s Sleigh - Red-Nosed Reindeer', 8, 0), -- Greatfather Winter's Sleigh - Red-Nosed Reindeer
(158561, 158559, 2, 1, 'Greatfather Winter''s Sleigh - Great Reindeer', 8, 0), -- Greatfather Winter's Sleigh - Great Reindeer
(158561, 158560, 3, 1, 'Greatfather Winter''s Sleigh - Great Reindeer', 8, 0), -- Greatfather Winter's Sleigh - Great Reindeer
(158561, 158559, 4, 1, 'Greatfather Winter''s Sleigh - Great Reindeer', 8, 0), -- Greatfather Winter's Sleigh - Great Reindeer
(158561, 158560, 5, 1, 'Greatfather Winter''s Sleigh - Great Reindeer', 8, 0); -- Greatfather Winter's Sleigh - Great Reindeer

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=158561 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(158561, 46598, 0, 0);

-- Gossips
UPDATE `gossip_menu` SET `VerifiedBuild`=47187 WHERE (`TextID`=6250 AND `MenuID`=5232) OR (`TextID`=6194 AND `MenuID` IN (5181,6769));

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=6769 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(31757, 6769, 0, 1, 'Let me browse your seasonal fare.', 8786, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47187); -- OptionBroadcastTextID: 8786 - 98021

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `Entry` IN (1365, 13433, 13434, 13444, 110441) AND `DifficultyID`=0;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(1365, 0, 0, 0, 868, 47187),
(13433, 0, 0, 0, 417, 47187),
(13434, 0, 0, 0, 417, 47187),
(13444, 0, 0, 0, 417, 47187),
(110441, 0, 0, 0, 417, 47187);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=47187 WHERE (`DifficultyID`=0 AND `Entry` IN (175412,175411,175410,175403,158561,158560,158559,158558,153285,132969,128156,123745,122323,121541,118889,97762,96490,89830,62822,62821,62425,61325,61317,53568,53544,52586,52584,52335,52321,51978,51976,51596,51495,51383,50732,50729,50723,50720,50717,50716,50309,50308,49748,48972,48935,47582,42928,42152,42147,42146,42131,42129,39718,35073,35007,34991,34281,32639,32638,31146,30733,30717,29141,27478,24110,23127,19172,19148,16070,16069,16013,15760,15732,15730,15186,15119,14365,14183,13843,11406,11146,11145,11065,11029,11028,10456,10455,10277,10276,10090,9984,9859,9616,9099,8879,8720,8681,8671,8517,8507,8256,7978,7976,7950,7944,7936,7312,7298,7292,6826,6569,6382,6294,6291,6181,6179,6178,6175,6169,6120,6114,6031,5637,5605,5595,5570,5569,5387,5178,5177,5175,5174,5173,5172,5171,5170,5169,5167,5166,5165,5163,5162,5161,5160,5159,5158,5157,5156,5155,5154,5153,5152,5151,5150,5149,5148,5147,5146,5145,5144,5143,5142,5141,5140,5138,5137,5133,5132,5130,5129,5128,5127,5126,5125,5124,5123,5122,5121,5120,5119,5117,5116,5115,5114,5113,5112,5111,5110,5108,5107,5106,5103,5102,5101,5100,5099,5049,4259,4258,4256,4254,4081,3979,3842,2943,2918,2916,2790,2786,2737,2695,2489,2461,2460,2092,1959,1901,1703,1573,1466,1356,1274,1246));

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=13433 AND `item`=17344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=13434 AND `item`=21215 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=13433 AND `item`=188680 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=13433 AND `item`=70923 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(13434, 1, 21215, 0, 0, 1, 0, 0, 47187), -- Graccu's Mince Meat Fruitcake
(13433, 8, 188680, 0, 0, 1, 0, 0, 47187), -- Winter Veil Chorus Book
(13433, 7, 70923, 0, 0, 1, 0, 0, 47187); -- Gaudy Winter Veil Sweater

UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17402 AND `ExtendedCost`=0 AND `type`=1); -- Greatfather's Winter Ale
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17403 AND `ExtendedCost`=0 AND `type`=1); -- Steamwheedle Fizzy Spirits
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=34410 AND `ExtendedCost`=0 AND `type`=1); -- Honeyed Holiday Ham
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17408 AND `ExtendedCost`=0 AND `type`=1); -- Spicy Beefstick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17407 AND `ExtendedCost`=0 AND `type`=1); -- Graccu's Homemade Meat Pie
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17406 AND `ExtendedCost`=0 AND `type`=1); -- Holiday Cheesewheel
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=34412 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Apple Cider
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17405 AND `ExtendedCost`=0 AND `type`=1); -- Green Garden Tea
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=47187 WHERE (`entry`=13434 AND `item`=17404 AND `ExtendedCost`=0 AND `type`=1); -- Blended Bean Brew
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=34413 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Hot Apple Cider
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=34262 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Winter Boots
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=34319 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Red Winter Clothes
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17201 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Winter Veil Egg Nog
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17200 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Gingerbread Cookie
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17196 AND `ExtendedCost`=0 AND `type`=1); -- Holiday Spirits
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17194 AND `ExtendedCost`=0 AND `type`=1); -- Holiday Spices
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17307 AND `ExtendedCost`=0 AND `type`=1); -- Purple Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17304 AND `ExtendedCost`=0 AND `type`=1); -- Green Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17303 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=47187 WHERE (`entry`=13433 AND `item`=17202 AND `ExtendedCost`=0 AND `type`=1); -- Snowball

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=47187 WHERE (`QuestID`=7063 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=7063 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=7043 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=7043 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=7043 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=7043 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=7062 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=7062 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=7062 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=7025 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=7025 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=47187 WHERE (`QuestID`=7045 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=7045 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=7063 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=7063 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=7043 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=7043 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=7043 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=7043 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=7062 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=7062 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=7062 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=7025 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=7025 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=7045;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7045, 2, 1, 1, 0, 0, 0, 0, 0, 47187); -- A Smokywood Pastures' Thank You!

UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=47187 WHERE `ID`=7063; -- The Feast of Winter Veil
UPDATE `quest_details` SET `VerifiedBuild`=47187 WHERE `ID` IN (7025, 7043, 7062);

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7025; -- Treats for Greatfather Winter
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='$n - our Feast of Winter Veil will be ruined without those treats to restock!  Graccu himself will miss out on sharing his delicious meat pies with all the good boys and girls this season...' WHERE `ID`=7043; -- You're a Mean One...
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=7043; -- You're a Mean One...

UPDATE `quest_offer_reward` SET `VerifiedBuild`=47187 WHERE `ID` IN (7063, 7062, 7023);

DELETE FROM `creature_queststarter` WHERE (`id`=2916 AND `quest`=7063) OR (`id`=13444 AND `quest`=7025) OR (`id`=13433 AND `quest`=7043) OR (`id`=13433 AND `quest`=7045) OR (`id`=1365 AND `quest`=7062);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(1365, 7062, 47187), -- The Reason for the Season offered Goli Krumn
(2916, 7063, 47187), -- The Feast of Winter Veil offered Historian Karnik
(13433, 7043, 47187), -- You're a Mean One... offered Wulmort Jinglepocket
(13433, 7045, 47187), -- A Smokywood Pastures' Thank You! offered Wulmort Jinglepocket
(13444, 7025, 47187); -- Treats for Greatfather Winter offered Greatfather Winter

DELETE FROM `game_event_creature_quest` WHERE (`id`=2916 AND `quest`=7063) OR (`id`=13444 AND `quest`=7025) OR (`id`=13433 AND `quest`=7043) OR (`id`=13433 AND `quest`=7045) OR (`id`=1365 AND `quest`=7062);

UPDATE `creature_questender` SET `VerifiedBuild`=47187 WHERE (`id`=13444 AND `quest`=7045) AND (`id`=42928 AND `quest`=7063) OR (`id`=13444 AND `quest` IN (7025,7023)) OR (`id`=2916 AND `quest`=7062) OR (`id`=13433 AND `quest`=7043);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (78303, 78304);
DELETE FROM `game_event_creature` WHERE `guid` IN (78303, 78304);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 1365, 0, 1537, 5719, '0', 0, 0, 0, 0, -4882.52294921875, -952.79559326171875, 501.546630859375, 3.281219005584716796, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Goli Krumn (Area: The Commons - Difficulty: 0)
(@CGUID+1, 13433, 0, 1537, 5719, '0', 0, 0, 0, 0, -4927.62353515625, -979.13543701171875, 501.56268310546875, 1.413716673851013183, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47187), -- Wulmort Jinglepocket (Area: The Commons - Difficulty: 0) (Auras: )
(@CGUID+2, 13434, 0, 1537, 5719, '0', 0, 0, 0, 0, -4924.09716796875, -979.68231201171875, 501.55487060546875, 1.239183783531188964, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47187), -- Macey Jinglepocket (Area: The Commons - Difficulty: 0) (Auras: )
(@CGUID+3, 13444, 0, 1537, 5719, '0', 0, 0, 0, 1, -4914.36181640625, -976.1102294921875, 501.452850341796875, 1.937312245368957519, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47187), -- Greatfather Winter (Area: The Commons - Difficulty: 0)
(@CGUID+4, 15730, 0, 1537, 0, '0', 0, 0, 0, 0, -5049.26025390625, -818.5426025390625, 495.375274658203125, 0, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47187), -- Pat's Snowcloud Guy (Area: 0 - Difficulty: 0)
(@CGUID+5, 15730, 0, 1537, 0, '0', 0, 0, 0, 0, -5049.29296875, -818.534423828125, 495.37847900390625, 0, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 47187), -- Pat's Snowcloud Guy (Area: 0 - Difficulty: 0)
(@CGUID+6, 15732, 0, 1537, 0, '0', 0, 0, 0, 0, -5046.501953125, -816.26043701171875, 495.219512939453125, 2.111848354339599609, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47187), -- Wonderform Operator (Area: 0 - Difficulty: 0)
(@CGUID+7, 15760, 0, 1537, 5719, '0', 0, 0, 0, 1, -4852.92236328125, -872.190185546875, 501.9971923828125, 1.692969322204589843, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Winter Reveler (Area: The Commons - Difficulty: 0) (Auras: )
(@CGUID+8, 15760, 0, 1537, 5719, '0', 0, 0, 0, 1, -4853.1416015625, -870.29742431640625, 501.9971923828125, 4.817108631134033203, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Winter Reveler (Area: The Commons - Difficulty: 0) (Auras: )
(@CGUID+9, 110441, 0, 1537, 5719, '0', 0, 0, 0, 0, -4899.4443359375, -940.7586669921875, 501.555572509765625, 3.675961732864379882, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Snowglobe Stalker (Area: The Commons - Difficulty: 0) (Auras: 219624 - Snowglobe)
(@CGUID+10, 123745, 0, 1537, 5719, '0', 0, 0, 0, 0, -4899.4443359375, -940.7586669921875, 501.555572509765625, 3.675961732864379882, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Snowglobe Stalker 2 (Area: The Commons - Difficulty: 0) (Auras: 246235 - Snowglobe)
(@CGUID+11, 128156, 0, 1537, 5719, '0', 0, 0, 0, 0, -4899.52783203125, -940.42535400390625, 501.555450439453125, 2.225762605667114257, 300, 0, 0, 27, 0, 2, 0, 0, 0, 47187), -- Globe Yeti (Area: The Commons - Difficulty: 0)
(@CGUID+12, 158561, 0, 1537, 5719, '0', 0, 0, 0, 0, -4951.566, -976.00696, 502.8215, 0.69850904, 120, 0, 0, 112919, 0, 2, 0, 0, 0, 47187); -- Greatfather Winter's Sleigh (Area: The Commons - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+7, @CGUID+8, @CGUID+11, @CGUID+12);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+7, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26241'), -- 15760 (Winter Reveler)
(@CGUID+8, 0, 0, 0, 257, 0, 0, 0, 0, 0, '26242'), -- 15760 (Winter Reveler)
(@CGUID+11, (@CGUID+11)*10, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 128156 (Globe Yeti)
(@CGUID+12, (@CGUID+12)*10, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- 158561 (Greatfather Winter's Sleigh)

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+11)*10, (@CGUID+12)*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
((@CGUID+11)*10, 0, -4905.619, -932.4947, 501.5698, NULL, 0, 1),
((@CGUID+11)*10, 1, -4898.227, -930.5103, 501.579, NULL, 0, 1),
((@CGUID+11)*10, 2, -4891.597, -934.33405, 501.51343, NULL, 0, 1),
((@CGUID+11)*10, 3, -4889.613, -941.72595, 501.45526, NULL, 0, 1),
((@CGUID+11)*10, 4, -4893.4365, -948.356, 501.45767, NULL, 0, 1),
((@CGUID+11)*10, 5, -4900.8286, -950.3404, 501.45648, NULL, 0, 1),
((@CGUID+11)*10, 6, -4907.4585, -946.51666, 501.50534, NULL, 0, 1),
((@CGUID+11)*10, 7, -4909.443, -939.12476, 501.54178, NULL, 0, 1),
((@CGUID+12)*10, 0, -4937.4863, -954.8889, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 1, -4919.271, -927.92017, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 2, -4885.3022, -905.5156, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 3, -4850.422, -894.92706, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 4, -4813.0454, -892.5018, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 5, -4774.672, -896.1719, 510.9396, NULL, 0, 1),
((@CGUID+12)*10, 6, -4717.0244, -918.69794, 514.96173, NULL, 0, 1),
((@CGUID+12)*10, 7, -4668.538, -927.7292, 516.6375, NULL, 0, 1),
((@CGUID+12)*10, 8, -4661.658, -956.375, 518.054, NULL, 0, 1),
((@CGUID+12)*10, 9, -4695.7134, -976.6893, 514.76715, NULL, 0, 1),
((@CGUID+12)*10, 10, -4721.3267, -984.283, 512.64575, NULL, 0, 1),
((@CGUID+12)*10, 11, -4747.25, -985.5573, 508.48926, NULL, 0, 1),
((@CGUID+12)*10, 12, -4764.8193, -1007.6198, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 13, -4791.3975, -1033.099, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 14, -4814.4204, -1074.5, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 15, -4832.8423, -1109.0695, 520.4476, NULL, 0, 1),
((@CGUID+12)*10, 16, -4876.809, -1117.5938, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 17, -4911.0938, -1123.4948, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 18, -4931.936, -1169.4948, 514.82355, NULL, 0, 1),
((@CGUID+12)*10, 19, -4956.4097, -1208.9288, 513.6513, NULL, 0, 1),
((@CGUID+12)*10, 20, -4987.4565, -1198.6216, 511.10825, NULL, 0, 1),
((@CGUID+12)*10, 21, -4993.8613, -1163.4635, 514.56244, NULL, 0, 1),
((@CGUID+12)*10, 22, -5004.8423, -1107.993, 514.56244, NULL, 0, 1),
((@CGUID+12)*10, 23, -5002.1875, -1047.2084, 511.56702, NULL, 0, 1),
((@CGUID+12)*10, 24, -4979.2397, -996.92883, 506.2216, NULL, 0, 1),
((@CGUID+12)*10, 25, -4951.566, -976.00696, 502.8215, NULL, 30000, 1);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+242;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 178425, 0, 1537, 5341, '0', 0, 0, -4673.740234375, -1255.40966796875, 501.992584228515625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- Christmas Tree (Large) (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+1, 178428, 0, 1537, 5719, '0', 0, 0, -4880.91796875, -1003.48272705078125, 504.65625, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+2, 178428, 0, 1537, 5719, '0', 0, 0, -4840.07861328125, -1029.6300048828125, 502.189788818359375, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+3, 178428, 0, 1537, 5719, '0', 0, 0, -4917.060546875, -982.2939453125, 501.45062255859375, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+4, 178428, 0, 1537, 5719, '0', 0, 0, -4840.90185546875, -1030.3392333984375, 502.189788818359375, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+5, 178428, 0, 1537, 5719, '0', 0, 0, -4879.5595703125, -1002.359375, 504.65625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+6, 178428, 0, 1537, 5719, '0', 0, 0, -4927.71435546875, -981.2393798828125, 501.46929931640625, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+7, 178428, 0, 1537, 5719, '0', 0, 0, -4913.5703125, -978.1729736328125, 501.44683837890625, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+8, 178428, 0, 1537, 5719, '0', 0, 0, -4839.916015625, -1027.4185791015625, 502.620330810546875, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+9, 178428, 0, 1537, 5719, '0', 0, 0, -4920.0322265625, -981.5810546875, 501.4599609375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+10, 178428, 0, 1537, 5719, '0', 0, 0, -4916.791015625, -981.15020751953125, 501.446990966796875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+11, 178428, 0, 1537, 5719, '0', 0, 0, -4915.00732421875, -981.6033935546875, 501.44183349609375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+12, 178428, 0, 1537, 5719, '0', 0, 0, -4881.34814453125, -1005.91387939453125, 504.65625, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+13, 178428, 0, 1537, 5719, '0', 0, 0, -4924.64501953125, -982.0128173828125, 503.64154052734375, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 47187), -- XMasGift01 (Area: The Commons - Difficulty: 0)
(@OGUID+14, 178428, 0, 1537, 5344, '0', 0, 0, -4625.0361328125, -907.7452392578125, 501.0703125, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 47187), -- XMasGift01 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+15, 178428, 0, 1537, 5344, '0', 0, 0, -4623.1630859375, -907.936767578125, 501.070709228515625, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 47187), -- XMasGift01 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+16, 178428, 0, 1537, 5342, '0', 0, 0, -5039.71875, -1255.8297119140625, 505.300018310546875, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 47187), -- XMasGift01 (Area: The Great Forge - Difficulty: 0)
(@OGUID+17, 178428, 0, 1537, 5342, '0', 0, 0, -5039.2734375, -1257.9954833984375, 505.300018310546875, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 47187), -- XMasGift01 (Area: The Great Forge - Difficulty: 0)
(@OGUID+18, 178428, 0, 1537, 5342, '0', 0, 0, -5037.8603515625, -1255.9322509765625, 505.300018310546875, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 47187), -- XMasGift01 (Area: The Great Forge - Difficulty: 0)
(@OGUID+19, 178428, 0, 1537, 5341, '0', 0, 0, -4675.51171875, -1255.5703125, 502.325897216796875, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 47187), -- XMasGift01 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+20, 178428, 0, 1537, 5341, '0', 0, 0, -4674.09130859375, -1256.936767578125, 502.3189697265625, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 47187), -- XMasGift01 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+21, 178428, 0, 1537, 5341, '0', 0, 0, -4673.158203125, -1254.5106201171875, 501.992584228515625, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 47187), -- XMasGift01 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+22, 178428, 0, 1537, 5341, '0', 0, 0, -4672.490234375, -1256.2276611328125, 501.992584228515625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 47187), -- XMasGift01 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+23, 178429, 0, 1537, 5719, '0', 0, 0, -4920.2724609375, -982.373291015625, 501.458892822265625, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+24, 178429, 0, 1537, 5719, '0', 0, 0, -4837.47021484375, -1028.802490234375, 502.189788818359375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+25, 178429, 0, 1537, 5719, '0', 0, 0, -4880.44140625, -1005.6063232421875, 504.65625, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+26, 178429, 0, 1537, 5719, '0', 0, 0, -4882.5234375, -1004.4041748046875, 504.65625, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+27, 178429, 0, 1537, 5719, '0', 0, 0, -4927.89306640625, -982.2850341796875, 501.467620849609375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+28, 178429, 0, 1537, 5719, '0', 0, 0, -4913.87109375, -980.34112548828125, 501.442535400390625, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+29, 178429, 0, 1537, 5719, '0', 0, 0, -4839.07470703125, -1030.0006103515625, 502.189788818359375, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+30, 178429, 0, 1537, 5719, '0', 0, 0, -4916.3916015625, -983.41583251953125, 501.449432373046875, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+31, 178429, 0, 1537, 5719, '0', 0, 0, -4839.078125, -1028.2545166015625, 502.189788818359375, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+32, 178429, 0, 1537, 5719, '0', 0, 0, -4912.431640625, -977.84051513671875, 501.445465087890625, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+33, 178429, 0, 1537, 5719, '0', 0, 0, -4878.4013671875, -1003.239013671875, 504.65625, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 47187), -- XMasGift02 (Area: The Commons - Difficulty: 0)
(@OGUID+34, 178429, 0, 1537, 5344, '0', 0, 0, -4624.83642578125, -905.597900390625, 501.07086181640625, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- XMasGift02 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+35, 178429, 0, 1537, 5344, '0', 0, 0, -4624.2763671875, -908.4239501953125, 501.070220947265625, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 47187), -- XMasGift02 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+36, 178429, 0, 1537, 5342, '0', 0, 0, -5039.95556640625, -1258.3388671875, 505.300018310546875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 47187), -- XMasGift02 (Area: The Great Forge - Difficulty: 0)
(@OGUID+37, 178429, 0, 1537, 5342, '0', 0, 0, -5038.896484375, -1256.365234375, 505.300018310546875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 47187), -- XMasGift02 (Area: The Great Forge - Difficulty: 0)
(@OGUID+38, 178429, 0, 1537, 5341, '0', 0, 0, -4674.64501953125, -1257.7349853515625, 501.992584228515625, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- XMasGift02 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+39, 178429, 0, 1537, 5341, '0', 0, 0, -4674.52490234375, -1255.9107666015625, 501.992584228515625, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 47187), -- XMasGift02 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+40, 178429, 0, 1537, 5341, '0', 0, 0, -4673.99560546875, -1254.3111572265625, 501.992584228515625, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 47187), -- XMasGift02 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+41, 178429, 0, 1537, 5341, '0', 0, 0, -4672.2451171875, -1254.0965576171875, 501.992584228515625, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 47187), -- XMasGift02 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+42, 178430, 0, 1537, 5719, '0', 0, 0, -4837.88232421875, -1030.592529296875, 502.189788818359375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+43, 178430, 0, 1537, 5719, '0', 0, 0, -4882.0068359375, -1005.45391845703125, 505.06597900390625, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+44, 178430, 0, 1537, 5719, '0', 0, 0, -4919.06640625, -982.77410888671875, 501.455780029296875, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+45, 178430, 0, 1537, 5719, '0', 0, 0, -4925.64404296875, -981.863525390625, 503.63958740234375, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+46, 178430, 0, 1537, 5719, '0', 0, 0, -4929.53271484375, -981.16448974609375, 501.779510498046875, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+47, 178430, 0, 1537, 5719, '0', 0, 0, -4916.119140625, -982.09222412109375, 501.445953369140625, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+48, 178430, 0, 1537, 5719, '0', 0, 0, -4914.39306640625, -979.31475830078125, 501.44580078125, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+49, 178430, 0, 1537, 5719, '0', 0, 0, -4840.06689453125, -1030.2379150390625, 502.6064453125, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+50, 178430, 0, 1537, 5719, '0', 0, 0, -4840.88623046875, -1028.6063232421875, 502.189788818359375, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+51, 178430, 0, 1537, 5719, '0', 0, 0, -4914.32275390625, -984.67315673828125, 501.443023681640625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+52, 178430, 0, 1537, 5719, '0', 0, 0, -4879.78662109375, -1004.3135986328125, 504.65625, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+53, 178430, 0, 1537, 5719, '0', 0, 0, -4879.67626953125, -1001.39788818359375, 504.65625, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+54, 178430, 0, 1537, 5719, '0', 0, 0, -4929.57470703125, -981.41265869140625, 501.47357177734375, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+55, 178430, 0, 1537, 5719, '0', 0, 0, -4916.53955078125, -984.5263671875, 501.447540283203125, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+56, 178430, 0, 1537, 5719, '0', 0, 0, -4928.3251953125, -983.35382080078125, 501.466522216796875, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 47187), -- XMasGift03 (Area: The Commons - Difficulty: 0)
(@OGUID+57, 178430, 0, 1537, 5344, '0', 0, 0, -4625.54541015625, -907.8350830078125, 501.479888916015625, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 47187), -- XMasGift03 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+58, 178430, 0, 1537, 5344, '0', 0, 0, -4623.119140625, -906.70391845703125, 501.0712890625, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 47187), -- XMasGift03 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+59, 178430, 0, 1537, 5342, '0', 0, 0, -5038.31982421875, -1257.048828125, 505.300018310546875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 47187), -- XMasGift03 (Area: The Great Forge - Difficulty: 0)
(@OGUID+60, 178430, 0, 1537, 5342, '0', 0, 0, -5040.27490234375, -1256.0279541015625, 505.716705322265625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 47187), -- XMasGift03 (Area: The Great Forge - Difficulty: 0)
(@OGUID+61, 178430, 0, 1537, 5342, '0', 0, 0, -5039.8720703125, -1254.85986328125, 505.300018310546875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- XMasGift03 (Area: The Great Forge - Difficulty: 0)
(@OGUID+62, 178430, 0, 1537, 5341, '0', 0, 0, -4675.50830078125, -1255.4127197265625, 501.992584228515625, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 47187), -- XMasGift03 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+63, 178430, 0, 1537, 5341, '0', 0, 0, -4674.11669921875, -1252.9244384765625, 501.992584228515625, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 120, 255, 1, 47187), -- XMasGift03 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+64, 178430, 0, 1537, 5341, '0', 0, 0, -4672.93359375, -1254.969970703125, 502.40924072265625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 47187), -- XMasGift03 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+65, 178430, 0, 1537, 5341, '0', 0, 0, -4673.57470703125, -1257.0308837890625, 501.992584228515625, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 47187), -- XMasGift03 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+66, 178431, 0, 1537, 5719, '0', 0, 0, -4923.8564453125, -982.2020263671875, 503.639556884765625, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+67, 178431, 0, 1537, 5719, '0', 0, 0, -4839.92333984375, -1030.647705078125, 502.189788818359375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+68, 178431, 0, 1537, 5719, '0', 0, 0, -4914.4833984375, -980.95147705078125, 501.44232177734375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+69, 178431, 0, 1537, 5719, '0', 0, 0, -4881.43359375, -1004.9044189453125, 504.65625, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+70, 178431, 0, 1537, 5719, '0', 0, 0, -4878.84912109375, -1004.294677734375, 504.65625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+71, 178431, 0, 1537, 5719, '0', 0, 0, -4918.24462890625, -983.6259765625, 501.452545166015625, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+72, 178431, 0, 1537, 5719, '0', 0, 0, -4839.56884765625, -1027.3961181640625, 502.189788818359375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+73, 178431, 0, 1537, 5719, '0', 0, 0, -4918.29052734375, -982.11761474609375, 501.45562744140625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+74, 178431, 0, 1537, 5719, '0', 0, 0, -4915.3115234375, -982.6075439453125, 501.4434814453125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+75, 178431, 0, 1537, 5719, '0', 0, 0, -4928.46826171875, -980.8653564453125, 501.471954345703125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+76, 178431, 0, 1537, 5719, '0', 0, 0, -4929.2373046875, -982.54766845703125, 501.470428466796875, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+77, 178431, 0, 1537, 5719, '0', 0, 0, -4915.61865234375, -980.77789306640625, 501.4449462890625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+78, 178431, 0, 1537, 5719, '0', 0, 0, -4913.81201171875, -977.99273681640625, 501.85736083984375, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+79, 178431, 0, 1537, 5719, '0', 0, 0, -4880.60986328125, -1002.59747314453125, 504.65625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+80, 178431, 0, 1537, 5719, '0', 0, 0, -4913.14892578125, -977.190673828125, 501.4482421875, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+81, 178431, 0, 1537, 5719, '0', 0, 0, -4915.36865234375, -984.427734375, 501.445526123046875, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 47187), -- XMasGift04 (Area: The Commons - Difficulty: 0)
(@OGUID+82, 178431, 0, 1537, 5344, '0', 0, 0, -4626.205078125, -907.46051025390625, 501.069976806640625, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 47187), -- XMasGift04 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+83, 178431, 0, 1537, 5344, '0', 0, 0, -4623.98876953125, -907.562744140625, 501.070709228515625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 47187), -- XMasGift04 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+84, 178431, 0, 1537, 5342, '0', 0, 0, -5038.72998046875, -1258.953125, 505.300018310546875, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 47187), -- XMasGift04 (Area: The Great Forge - Difficulty: 0)
(@OGUID+85, 178431, 0, 1537, 5342, '0', 0, 0, -5040.21484375, -1255.8104248046875, 506.0430908203125, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 47187), -- XMasGift04 (Area: The Great Forge - Difficulty: 0)
(@OGUID+86, 178431, 0, 1537, 5342, '0', 0, 0, -5040.3662109375, -1256.45361328125, 505.300018310546875, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 47187), -- XMasGift04 (Area: The Great Forge - Difficulty: 0)
(@OGUID+87, 178431, 0, 1537, 5341, '0', 0, 0, -4676.06298828125, -1256.2813720703125, 501.992584228515625, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 47187), -- XMasGift04 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+88, 178431, 0, 1537, 5341, '0', 0, 0, -4674.79150390625, -1255.064697265625, 502.40228271484375, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 47187), -- XMasGift04 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+89, 178431, 0, 1537, 5341, '0', 0, 0, -4673.048828125, -1255.5257568359375, 501.992584228515625, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 47187), -- XMasGift04 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+90, 178431, 0, 1537, 5341, '0', 0, 0, -4673.2275390625, -1253.5224609375, 501.992584228515625, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 47187), -- XMasGift04 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+91, 178432, 0, 1537, 5719, '0', 0, 0, -4919.01806640625, -981.644775390625, 501.45794677734375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+92, 178432, 0, 1537, 5719, '0', 0, 0, -4881.935546875, -1006.7020263671875, 504.65625, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+93, 178432, 0, 1537, 5719, '0', 0, 0, -4917.296875, -984.0106201171875, 501.449981689453125, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+94, 178432, 0, 1537, 5719, '0', 0, 0, -4911.57275390625, -978.4736328125, 501.4425048828125, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+95, 178432, 0, 1537, 5719, '0', 0, 0, -4839.9853515625, -1028.5654296875, 502.189788818359375, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+96, 178432, 0, 1537, 5719, '0', 0, 0, -4838.34033203125, -1029.229736328125, 502.189788818359375, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+97, 178432, 0, 1537, 5719, '0', 0, 0, -4914.36328125, -979.15362548828125, 501.7724609375, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+98, 178432, 0, 1537, 5719, '0', 0, 0, -4878.27734375, -1002.27886962890625, 504.65625, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+99, 178432, 0, 1537, 5719, '0', 0, 0, -4838.23291015625, -1031.646240234375, 502.189788818359375, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+100, 178432, 0, 1537, 5719, '0', 0, 0, -4915.39111328125, -983.51214599609375, 501.44573974609375, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+101, 178432, 0, 1537, 5719, '0', 0, 0, -4928.82763671875, -981.7940673828125, 501.470916748046875, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+102, 178432, 0, 1537, 5719, '0', 0, 0, -4880.7880859375, -1004.38702392578125, 504.65625, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 47187), -- XMasGift05 (Area: The Commons - Difficulty: 0)
(@OGUID+103, 178432, 0, 1537, 5344, '0', 0, 0, -4626.01171875, -908.8045654296875, 501.069610595703125, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 47187), -- XMasGift05 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+104, 178432, 0, 1537, 5344, '0', 0, 0, -4625.69384765625, -906.6395263671875, 501.0703125, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 47187), -- XMasGift05 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+105, 178432, 0, 1537, 5344, '0', 0, 0, -4623.044921875, -905.58465576171875, 501.071624755859375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 47187), -- XMasGift05 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+106, 178432, 0, 1537, 5342, '0', 0, 0, -5039.3349609375, -1259.8218994140625, 505.300018310546875, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 47187), -- XMasGift05 (Area: The Great Forge - Difficulty: 0)
(@OGUID+107, 178432, 0, 1537, 5342, '0', 0, 0, -5038.66064453125, -1255.288818359375, 505.300018310546875, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 47187), -- XMasGift05 (Area: The Great Forge - Difficulty: 0)
(@OGUID+108, 178432, 0, 1537, 5342, '0', 0, 0, -5040.27197265625, -1257.4962158203125, 505.300018310546875, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 47187), -- XMasGift05 (Area: The Great Forge - Difficulty: 0)
(@OGUID+109, 178432, 0, 1537, 5341, '0', 0, 0, -4671.4267578125, -1255.932861328125, 501.992584228515625, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 47187), -- XMasGift05 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+110, 178432, 0, 1537, 5341, '0', 0, 0, -4674.97509765625, -1253.8765869140625, 501.992584228515625, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 47187), -- XMasGift05 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+111, 178432, 0, 1537, 5341, '0', 0, 0, -4673.583984375, -1256.216552734375, 501.992584228515625, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 47187), -- XMasGift05 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+112, 178433, 0, 1537, 5719, '0', 0, 0, -4929.32666015625, -983.410400390625, 501.468170166015625, 1.256635904312133789, 0, 0, 0.587784767150878906, 0.809017360210418701, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+113, 178433, 0, 1537, 5719, '0', 0, 0, -4841.5205078125, -1029.5494384765625, 502.189788818359375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+114, 178433, 0, 1537, 5719, '0', 0, 0, -4914.4892578125, -983.48272705078125, 501.441619873046875, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+115, 178433, 0, 1537, 5719, '0', 0, 0, -4840.70654296875, -1027.318603515625, 502.189788818359375, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+116, 178433, 0, 1537, 5719, '0', 0, 0, -4882.515625, -1005.59027099609375, 504.65625, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+117, 178433, 0, 1537, 5719, '0', 0, 0, -4879.74072265625, -1004.03570556640625, 504.982635498046875, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+118, 178433, 0, 1537, 5719, '0', 0, 0, -4914.1796875, -977.76910400390625, 501.4488525390625, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+119, 178433, 0, 1537, 5719, '0', 0, 0, -4839.013671875, -1031.1103515625, 502.189788818359375, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+120, 178433, 0, 1537, 5719, '0', 0, 0, -4917.67431640625, -981.4971923828125, 501.45172119140625, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+121, 178433, 0, 1537, 5719, '0', 0, 0, -4838.234375, -1027.78173828125, 502.189788818359375, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+122, 178433, 0, 1537, 5719, '0', 0, 0, -4914.7578125, -981.18817138671875, 501.85894775390625, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+123, 178433, 0, 1537, 5719, '0', 0, 0, -4928.111328125, -981.10894775390625, 501.880279541015625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+124, 178433, 0, 1537, 5719, '0', 0, 0, -4879.14794921875, -1003.2852783203125, 504.65625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+125, 178433, 0, 1537, 5719, '0', 0, 0, -4915.05322265625, -985.42718505859375, 501.44293212890625, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, 47187), -- XMasGift06 (Area: The Commons - Difficulty: 0)
(@OGUID+126, 178433, 0, 1537, 5344, '0', 0, 0, -4625.1748046875, -908.70062255859375, 501.06988525390625, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 47187), -- XMasGift06 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+127, 178433, 0, 1537, 5344, '0', 0, 0, -4624.0009765625, -907.019775390625, 501.487579345703125, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 47187), -- XMasGift06 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+128, 178433, 0, 1537, 5344, '0', 0, 0, -4623.89892578125, -906.373291015625, 501.071136474609375, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 120, 255, 1, 47187), -- XMasGift06 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+129, 178433, 0, 1537, 5342, '0', 0, 0, -5040.68505859375, -1255.6063232421875, 505.300018310546875, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 47187), -- XMasGift06 (Area: The Great Forge - Difficulty: 0)
(@OGUID+130, 178433, 0, 1537, 5342, '0', 0, 0, -5038.64501953125, -1254.3072509765625, 505.300018310546875, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 47187), -- XMasGift06 (Area: The Great Forge - Difficulty: 0)
(@OGUID+131, 178433, 0, 1537, 5342, '0', 0, 0, -5038.57470703125, -1257.135986328125, 505.640289306640625, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 47187), -- XMasGift06 (Area: The Great Forge - Difficulty: 0)
(@OGUID+132, 178433, 0, 1537, 5341, '0', 0, 0, -4674.9814453125, -1256.699462890625, 501.992584228515625, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 47187), -- XMasGift06 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+133, 178433, 0, 1537, 5341, '0', 0, 0, -4676.01318359375, -1254.17236328125, 501.992584228515625, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 47187), -- XMasGift06 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+134, 178433, 0, 1537, 5341, '0', 0, 0, -4674.74169921875, -1254.84033203125, 501.992584228515625, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 47187), -- XMasGift06 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+135, 178433, 0, 1537, 5341, '0', 0, 0, -4672.2783203125, -1255.14697265625, 501.992584228515625, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 47187), -- XMasGift06 (Area: Hall of Explorers - Difficulty: 0)
(@OGUID+136, 178434, 0, 1537, 5719, '0', 0, 0, -4885.41845703125, -1005.30126953125, 506.572601318359375, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 47187), -- XMasStocking01 (Area: The Commons - Difficulty: 0)
(@OGUID+137, 178434, 0, 1537, 5719, '0', 0, 0, -4844.22265625, -855.45703125, 504.832672119140625, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 47187), -- XMasStocking01 (Area: The Commons - Difficulty: 0)
(@OGUID+138, 178434, 0, 1537, 5719, '0', 0, 0, -4837.92724609375, -854.683837890625, 504.830474853515625, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 47187), -- XMasStocking01 (Area: The Commons - Difficulty: 0)
(@OGUID+139, 178434, 0, 1537, 0, '0', 0, 0, -5050.43798828125, -815.00750732421875, 500.520843505859375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 47187), -- XMasStocking01 (Area: 0 - Difficulty: 0)
(@OGUID+140, 178435, 0, 1537, 5719, '0', 0, 0, -4843.46337890625, -855.36383056640625, 504.85540771484375, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 47187), -- XMasStocking02 (Area: The Commons - Difficulty: 0)
(@OGUID+141, 178435, 0, 1537, 5719, '0', 0, 0, -4876.90087890625, -998.27996826171875, 506.61761474609375, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 47187), -- XMasStocking02 (Area: The Commons - Difficulty: 0)
(@OGUID+142, 178435, 0, 1537, 5719, '0', 0, 0, -4839.65380859375, -854.89581298828125, 504.847320556640625, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 47187), -- XMasStocking02 (Area: The Commons - Difficulty: 0)
(@OGUID+143, 178435, 0, 1537, 5719, '0', 0, 0, -4886.52490234375, -1006.21319580078125, 506.5679931640625, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 47187), -- XMasStocking02 (Area: The Commons - Difficulty: 0)
(@OGUID+144, 178435, 0, 1537, 0, '0', 0, 0, -5048.177734375, -815.39337158203125, 500.650543212890625, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 47187), -- XMasStocking02 (Area: 0 - Difficulty: 0)
(@OGUID+145, 178436, 0, 1537, 5719, '0', 0, 0, -4842.6318359375, -855.26171875, 504.828338623046875, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 47187), -- XMasStocking03 (Area: The Commons - Difficulty: 0)
(@OGUID+146, 178436, 0, 1537, 5719, '0', 0, 0, -4877.86474609375, -999.07464599609375, 506.55218505859375, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- XMasStocking03 (Area: The Commons - Difficulty: 0)
(@OGUID+147, 178436, 0, 1537, 5719, '0', 0, 0, -4838.75537109375, -854.78546142578125, 504.81939697265625, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 47187), -- XMasStocking03 (Area: The Commons - Difficulty: 0)
(@OGUID+148, 178437, 0, 1537, 5719, '0', 0, 0, -4901.76806640625, -978.97100830078125, 513.42535400390625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- Wreath (Area: The Commons - Difficulty: 0)
(@OGUID+149, 178437, 0, 1537, 5344, '0', 0, 0, -4637.87744140625, -935.4434814453125, 521.7840576171875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 47187), -- Wreath (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+150, 178437, 0, 1537, 5342, '0', 0, 0, -5003.65966796875, -1237.5758056640625, 517.0130615234375, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 47187), -- Wreath (Area: The Great Forge - Difficulty: 0)
(@OGUID+151, 178438, 0, 1537, 5719, '0', 0, 0, -4922.47998046875, -984.03741455078125, 504.452850341796875, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+152, 178438, 0, 1537, 5719, '0', 0, 0, -4944.60595703125, -919.5711669921875, 510.7408447265625, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+153, 178438, 0, 1537, 5719, '0', 0, 0, -4952.3681640625, -926.1788330078125, 510.53948974609375, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+154, 178438, 0, 1537, 5719, '0', 0, 0, -4955.12841796875, -928.47222900390625, 510.47216796875, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+155, 178438, 0, 1537, 5719, '0', 0, 0, -4949.66748046875, -923.86749267578125, 510.668792724609375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+156, 178438, 0, 1537, 5719, '0', 0, 0, -4863.66845703125, -880.4930419921875, 517.64349365234375, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+157, 178438, 0, 1537, 5719, '0', 0, 0, -4927.59619140625, -982.41766357421875, 504.369354248046875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+158, 178438, 0, 1537, 5719, '0', 0, 0, -4939.38525390625, -915.25518798828125, 510.80084228515625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+159, 178438, 0, 1537, 5719, '0', 0, 0, -4947.25, -921.7100830078125, 510.724395751953125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+160, 178438, 0, 1537, 5719, '0', 0, 0, -4867.3662109375, -881.1632080078125, 517.56805419921875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+161, 178438, 0, 1537, 5719, '0', 0, 0, -4960.6767578125, -933.0205078125, 510.504058837890625, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+162, 178438, 0, 1537, 5719, '0', 0, 0, -4936.736328125, -913.11456298828125, 510.865936279296875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+163, 178438, 0, 1537, 5719, '0', 0, 0, -4870.798828125, -882.01043701171875, 517.74261474609375, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+164, 178438, 0, 1537, 5719, '0', 0, 0, -4957.96533203125, -930.8367919921875, 510.45208740234375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+165, 178438, 0, 1537, 5719, '0', 0, 0, -4923.73974609375, -979.21258544921875, 503.94390869140625, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+166, 178438, 0, 1537, 5719, '0', 0, 0, -4942.02783203125, -917.4375, 510.791168212890625, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+167, 178438, 0, 1537, 5719, '0', 0, 0, -4925.54931640625, -984.65313720703125, 504.5263671875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+168, 178438, 0, 1537, 5719, '0', 0, 0, -4934.17529296875, -911.015625, 510.92388916015625, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+169, 178438, 0, 1537, 5719, '0', 0, 0, -4860.1337890625, -879.78472900390625, 517.72808837890625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+170, 178438, 0, 1537, 5719, '0', 0, 0, -4972.767578125, -1008.64239501953125, 520.15478515625, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+171, 178438, 0, 1537, 5719, '0', 0, 0, -4971.41845703125, -1005.39239501953125, 520.1387939453125, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+172, 178438, 0, 1537, 5719, '0', 0, 0, -4974.15625, -1011.93048095703125, 520.0267333984375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 47187), -- Lights (Area: The Commons - Difficulty: 0)
(@OGUID+173, 178438, 0, 1537, 5344, '0', 0, 0, -4676.533203125, -885.7274169921875, 520.2188720703125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- Lights (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+174, 178438, 0, 1537, 5342, '0', 0, 0, -4723.41455078125, -1101.906982421875, 520.96954345703125, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+175, 178438, 0, 1537, 5342, '0', 0, 0, -4723.79052734375, -1105.02734375, 520.9151611328125, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+176, 178438, 0, 1537, 5342, '0', 0, 0, -4724.23291015625, -1108.40283203125, 520.7218017578125, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+177, 178438, 0, 1537, 5342, '0', 0, 0, -4724.77783203125, -1111.6007080078125, 520.82757568359375, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+178, 178438, 0, 1537, 5342, '0', 0, 0, -4725.3740234375, -1114.8397216796875, 520.90655517578125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+179, 178438, 0, 1537, 5342, '0', 0, 0, -4726.95849609375, -1124.51220703125, 520.96685791015625, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+180, 178438, 0, 1537, 5342, '0', 0, 0, -4725.93408203125, -1118.111083984375, 520.86895751953125, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+181, 178438, 0, 1537, 5342, '0', 0, 0, -4726.39892578125, -1121.2969970703125, 521.0274658203125, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+182, 178438, 0, 1537, 5342, '0', 0, 0, -4799.392578125, -1179.9375, 516.353515625, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+183, 178438, 0, 1537, 5342, '0', 0, 0, -4810.58154296875, -1179.8712158203125, 516.28607177734375, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+184, 178438, 0, 1537, 5342, '0', 0, 0, -4806.919921875, -1179.826416015625, 516.32598876953125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+185, 178438, 0, 1537, 5342, '0', 0, 0, -4803.0380859375, -1179.85595703125, 516.320556640625, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 47187), -- Lights (Area: The Great Forge - Difficulty: 0)
(@OGUID+186, 178438, 0, 1537, 5343, '0', 0, 0, -4975.6630859375, -1015.4271240234375, 520.06939697265625, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 47187), -- Lights (Area: The Military Ward - Difficulty: 0)
(@OGUID+187, 178438, 0, 1537, 5343, '0', 0, 0, -4978.9130859375, -1022.39410400390625, 520.18487548828125, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 47187), -- Lights (Area: The Military Ward - Difficulty: 0)
(@OGUID+188, 178438, 0, 1537, 5343, '0', 0, 0, -4977.3212890625, -1019.036376953125, 520.13348388671875, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 47187), -- Lights (Area: The Military Ward - Difficulty: 0)
(@OGUID+189, 178554, 0, 1537, 5719, '0', 0, 0, -4950.74609375, -919.2803955078125, 509.249847412109375, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 47187), -- Mistletoe (Area: The Commons - Difficulty: 0)
(@OGUID+190, 178554, 0, 1537, 5719, '0', 0, 0, -4865.806640625, -878.2908935546875, 506.852386474609375, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 47187), -- Mistletoe (Area: The Commons - Difficulty: 0)
(@OGUID+191, 178554, 0, 1537, 5719, '0', 0, 0, -4898.45751953125, -983.00531005859375, 507.421783447265625, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 47187), -- Mistletoe (Area: The Commons - Difficulty: 0)
(@OGUID+192, 178556, 0, 1537, 5719, '0', 0, 0, -4869.01025390625, -1018.84600830078125, 518.94805908203125, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 47187), -- Wreath scale 1.20 (Area: The Commons - Difficulty: 0)
(@OGUID+193, 178556, 0, 1537, 5342, '0', 0, 0, -4832.98681640625, -1062.68896484375, 528.27801513671875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 47187), -- Wreath scale 1.20 (Area: The Great Forge - Difficulty: 0)
(@OGUID+194, 178556, 0, 1537, 0, '0', 0, 0, -5021.13720703125, -834.2562255859375, 524.0322265625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 47187), -- Wreath scale 1.20 (Area: 0 - Difficulty: 0)
(@OGUID+195, 178557, 0, 1537, 5719, '0', 0, 0, -4839.2314453125, -1029.2138671875, 502.189788818359375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 47187), -- Christmas Tree (Medium) (Area: The Commons - Difficulty: 0)
(@OGUID+196, 178557, 0, 1537, 5344, '0', 0, 0, -4624.720703125, -906.8634033203125, 501.070709228515625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 47187), -- Christmas Tree (Medium) (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+197, 178557, 0, 1537, 5342, '0', 0, 0, -5039.568359375, -1256.928955078125, 505.300018310546875, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 47187), -- Christmas Tree (Medium) (Area: The Great Forge - Difficulty: 0)
(@OGUID+198, 178645, 0, 1537, 5719, '0', 0, 0, -4765.3291015625, -912.12969970703125, 507.817657470703125, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 47187), -- Lights x3 (Area: The Commons - Difficulty: 0)
(@OGUID+199, 178645, 0, 1537, 5344, '0', 0, 0, -4691.3388671875, -874.26153564453125, 520.23614501953125, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- Lights x3 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+200, 178645, 0, 1537, 5344, '0', 0, 0, -4682.48388671875, -881.14801025390625, 520.2335205078125, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 47187), -- Lights x3 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+201, 178645, 0, 1537, 5344, '0', 0, 0, -4749.11279296875, -1043.6868896484375, 520.83880615234375, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- Lights x3 (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+202, 178645, 0, 1537, 5342, '0', 0, 0, -4757.8427734375, -1036.9024658203125, 520.8275146484375, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47187), -- Lights x3 (Area: The Great Forge - Difficulty: 0)
(@OGUID+203, 178645, 0, 1537, 5342, '0', 0, 0, -4867.88720703125, -1144.3040771484375, 510.1231689453125, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 47187), -- Lights x3 (Area: The Great Forge - Difficulty: 0)
(@OGUID+204, 178645, 0, 1537, 5342, '0', 0, 0, -4847.67333984375, -1163.0767822265625, 508.427154541015625, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 47187), -- Lights x3 (Area: The Great Forge - Difficulty: 0)
(@OGUID+205, 178645, 0, 1537, 5342, '0', 0, 0, -5016.3369140625, -1125.1396484375, 509.606109619140625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 47187), -- Lights x3 (Area: The Great Forge - Difficulty: 0)
(@OGUID+206, 178645, 0, 1537, 5343, '0', 0, 0, -5019.259765625, -1046.804443359375, 522.747802734375, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 47187), -- Lights x3 (Area: The Military Ward - Difficulty: 0)
(@OGUID+207, 178649, 0, 1537, 5719, '0', 0, 0, -4849.69384765625, -879.541259765625, 511.44622802734375, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 47187), -- Wreath scale 0.75 (Area: The Commons - Difficulty: 0)
(@OGUID+208, 178666, 0, 1537, 5719, '0', 0, 0, -4924.6943359375, -983.04644775390625, 501.4610595703125, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 47187), -- Travelers Wagon (Area: The Commons - Difficulty: 0)
(@OGUID+209, 178667, 0, 1537, 0, '0', 0, 0, -5054.73583984375, -817.06353759765625, 495.690704345703125, 0, 0, 0, 0, 1, 120, 255, 1, 47187), -- Christmas Tree (Medium) (Area: 0 - Difficulty: 0)
(@OGUID+210, 178671, 0, 1537, 5719, '0', 0, 0, -4914.36181640625, -976.1102294921875, 501.452850341796875, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 47187), -- Greatfather Winter's Chair (Area: The Commons - Difficulty: 0)
(@OGUID+211, 178746, 0, 1537, 5719, '0', 0, 0, -4925.46435546875, -978.47198486328125, 501.476409912109375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 47187), -- Smokywood Pastures (Area: The Commons - Difficulty: 0)
(@OGUID+212, 178746, 0, 1537, 0, '0', 0, 0, -5045.873046875, -817.19708251953125, 495.13177490234375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 120, 255, 1, 47187), -- Smokywood Pastures (Area: 0 - Difficulty: 0)
(@OGUID+213, 178764, 0, 1537, 5719, '0', 0, 0, -4914.31689453125, -969.7490234375, 501.466949462890625, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+214, 178764, 0, 1537, 5719, '0', 0, 0, -4915.3115234375, -967.1434326171875, 501.47454833984375, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+215, 178764, 0, 1537, 5719, '0', 0, 0, -4922.1279296875, -972.53399658203125, 501.476959228515625, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+216, 178764, 0, 1537, 5719, '0', 0, 0, -4923.08837890625, -969.91839599609375, 501.484649658203125, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+217, 178764, 0, 1537, 5719, '0', 0, 0, -4918.9052734375, -965.48199462890625, 501.48486328125, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+218, 178764, 0, 1537, 5719, '0', 0, 0, -4916.27099609375, -964.49664306640625, 501.482208251953125, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+219, 178764, 0, 1537, 5719, '0', 0, 0, -4911.2529296875, -977.67425537109375, 501.443695068359375, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+220, 178764, 0, 1537, 5719, '0', 0, 0, -4918.62890625, -974.24786376953125, 501.465545654296875, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+221, 178764, 0, 1537, 5719, '0', 0, 0, -4913.3388671875, -972.4051513671875, 501.459259033203125, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+222, 178764, 0, 1537, 5719, '0', 0, 0, -4912.283203125, -975.0438232421875, 501.451446533203125, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+223, 178764, 0, 1537, 5719, '0', 0, 0, -4921.57958984375, -966.4464111328125, 501.48870849609375, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+224, 178764, 0, 1537, 5719, '0', 0, 0, -4924.03662109375, -967.21954345703125, 501.492523193359375, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+225, 178764, 0, 1537, 5719, '0', 0, 0, -4916.01123046875, -973.2606201171875, 501.462249755859375, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+226, 178764, 0, 1537, 5719, '0', 0, 0, -4920.4345703125, -969.16339111328125, 501.480377197265625, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+227, 178764, 0, 1537, 5719, '0', 0, 0, -4921.30126953125, -975.2080078125, 501.469390869140625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+228, 178764, 0, 1537, 5719, '0', 0, 0, -4916.884765625, -970.794189453125, 501.4693603515625, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 47187), -- Rope Line (Area: The Commons - Difficulty: 0)
(@OGUID+229, 178765, 0, 1537, 5719, '0', 0, 0, -4919.544921875, -971.7509765625, 501.472869873046875, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 47187), -- Rope Line Pole (Area: The Commons - Difficulty: 0)
(@OGUID+230, 178765, 0, 1537, 5719, '0', 0, 0, -4917.80712890625, -968.16656494140625, 501.476898193359375, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 47187), -- Rope Line Pole (Area: The Commons - Difficulty: 0)
(@OGUID+231, 178805, 0, 1537, 5719, '0', 0, 0, -4917.84228515625, -982.903564453125, 501.4532470703125, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 47187), -- Christmas Tree (Medium) (Area: The Commons - Difficulty: 0)
(@OGUID+232, 180715, 0, 1537, 5719, '0', 0, 0, -4939.55322265625, -1009.330322265625, 501.440277099609375, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 120, 255, 1, 47187), -- Holly Preserver (Area: The Commons - Difficulty: 0)
(@OGUID+233, 180796, 0, 1537, 0, '0', 0, 0, -5049.59716796875, -817.2021484375, 495.232208251953125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 47187), -- PX-238 Winter Wondervolt (Area: 0 - Difficulty: 0)
(@OGUID+234, 180797, 0, 1537, 0, '0', 0, 0, -5049.30078125, -818.47723388671875, 495.291778564453125, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 47187), -- PX-238 Winter Wondervolt TRAP (Area: 0 - Difficulty: 0)
(@OGUID+235, 180798, 0, 1537, 0, '0', 0, 0, -5051.24853515625, -815.18255615234375, 495.197540283203125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 47187), -- Present BIG (Area: 0 - Difficulty: 0)
(@OGUID+236, 180799, 0, 1537, 0, '0', 0, 0, -5051.873046875, -815.90179443359375, 495.318084716796875, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 47187), -- Present BIG (Area: 0 - Difficulty: 0)
(@OGUID+237, 180844, 0, 1537, 5719, '0', 0, 0, -4852.9619140625, -871.33135986328125, 509.2520751953125, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 47187), -- Mistletoe (Area: The Commons - Difficulty: 0)
(@OGUID+238, 187235, 0, 1537, 5344, '0', 0, 0, -4618.0244140625, -925.11968994140625, 501.0621337890625, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+239, 187235, 0, 1537, 5344, '0', 0, 0, -4623.98583984375, -917.63336181640625, 501.06304931640625, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+240, 187235, 0, 1537, 5344, '0', 0, 0, -4609.134765625, -905.39166259765625, 501.067718505859375, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+241, 187235, 0, 1537, 5344, '0', 0, 0, -4602.83056640625, -912.78594970703125, 501.066070556640625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 47187), -- Standing, Exterior, Medium - Xmas (Area: The Mystic Ward - Difficulty: 0)
(@OGUID+242, 341827, 0, 1537, 5719, '0', 0, 0, -4929.04541015625, -981.88714599609375, 506.72955322265625, 2.895223140716552734, 0.044568061828613281, -0.03045845031738281, 0.990828514099121093, 0.123874366283416748, 120, 255, 0, 47187); -- Greatfeather Pepe (Area: The Commons - Difficulty: 0)

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=13444; -- Greatfather Winter

DELETE FROM `smart_scripts` WHERE `entryorguid`=13444 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(13444,0,0,0,11,0,100,0,0,0,0,0,0,'',147,5,0,0,0,0,0,15,178671,5,0,0,0,0,0,0,'Greatfather Winter - On spawn - Activate gameobject (Disturb)');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=158561; -- Greatfather Winter's Sleigh

DELETE FROM `smart_scripts` WHERE `entryorguid`=158561 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(158561,0,0,0,11,0,100,0,0,0,0,0,0,'',136,1,12,1,0,0,0,1,0,0,0,0,0,0,0,0,'Greatfather Winter''s Sleigh - On spawn - Set run speed');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3),
(@EVENT, @CGUID+4),
(@EVENT, @CGUID+5),
(@EVENT, @CGUID+6),
(@EVENT, @CGUID+7),
(@EVENT, @CGUID+8),
(@EVENT, @CGUID+9),
(@EVENT, @CGUID+10),
(@EVENT, @CGUID+11),
(@EVENT, @CGUID+12);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+242;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42),
(@EVENT, @OGUID+43),
(@EVENT, @OGUID+44),
(@EVENT, @OGUID+45),
(@EVENT, @OGUID+46),
(@EVENT, @OGUID+47),
(@EVENT, @OGUID+48),
(@EVENT, @OGUID+49),
(@EVENT, @OGUID+50),
(@EVENT, @OGUID+51),
(@EVENT, @OGUID+52),
(@EVENT, @OGUID+53),
(@EVENT, @OGUID+54),
(@EVENT, @OGUID+55),
(@EVENT, @OGUID+56),
(@EVENT, @OGUID+57),
(@EVENT, @OGUID+58),
(@EVENT, @OGUID+59),
(@EVENT, @OGUID+60),
(@EVENT, @OGUID+61),
(@EVENT, @OGUID+62),
(@EVENT, @OGUID+63),
(@EVENT, @OGUID+64),
(@EVENT, @OGUID+65),
(@EVENT, @OGUID+66),
(@EVENT, @OGUID+67),
(@EVENT, @OGUID+68),
(@EVENT, @OGUID+69),
(@EVENT, @OGUID+70),
(@EVENT, @OGUID+71),
(@EVENT, @OGUID+72),
(@EVENT, @OGUID+73),
(@EVENT, @OGUID+74),
(@EVENT, @OGUID+75),
(@EVENT, @OGUID+76),
(@EVENT, @OGUID+77),
(@EVENT, @OGUID+78),
(@EVENT, @OGUID+79),
(@EVENT, @OGUID+80),
(@EVENT, @OGUID+81),
(@EVENT, @OGUID+82),
(@EVENT, @OGUID+83),
(@EVENT, @OGUID+84),
(@EVENT, @OGUID+85),
(@EVENT, @OGUID+86),
(@EVENT, @OGUID+87),
(@EVENT, @OGUID+88),
(@EVENT, @OGUID+89),
(@EVENT, @OGUID+90),
(@EVENT, @OGUID+91),
(@EVENT, @OGUID+92),
(@EVENT, @OGUID+93),
(@EVENT, @OGUID+94),
(@EVENT, @OGUID+95),
(@EVENT, @OGUID+96),
(@EVENT, @OGUID+97),
(@EVENT, @OGUID+98),
(@EVENT, @OGUID+99),
(@EVENT, @OGUID+100),
(@EVENT, @OGUID+101),
(@EVENT, @OGUID+102),
(@EVENT, @OGUID+103),
(@EVENT, @OGUID+104),
(@EVENT, @OGUID+105),
(@EVENT, @OGUID+106),
(@EVENT, @OGUID+107),
(@EVENT, @OGUID+108),
(@EVENT, @OGUID+109),
(@EVENT, @OGUID+110),
(@EVENT, @OGUID+111),
(@EVENT, @OGUID+112),
(@EVENT, @OGUID+113),
(@EVENT, @OGUID+114),
(@EVENT, @OGUID+115),
(@EVENT, @OGUID+116),
(@EVENT, @OGUID+117),
(@EVENT, @OGUID+118),
(@EVENT, @OGUID+119),
(@EVENT, @OGUID+120),
(@EVENT, @OGUID+121),
(@EVENT, @OGUID+122),
(@EVENT, @OGUID+123),
(@EVENT, @OGUID+124),
(@EVENT, @OGUID+125),
(@EVENT, @OGUID+126),
(@EVENT, @OGUID+127),
(@EVENT, @OGUID+128),
(@EVENT, @OGUID+129),
(@EVENT, @OGUID+130),
(@EVENT, @OGUID+131),
(@EVENT, @OGUID+132),
(@EVENT, @OGUID+133),
(@EVENT, @OGUID+134),
(@EVENT, @OGUID+135),
(@EVENT, @OGUID+136),
(@EVENT, @OGUID+137),
(@EVENT, @OGUID+138),
(@EVENT, @OGUID+139),
(@EVENT, @OGUID+140),
(@EVENT, @OGUID+141),
(@EVENT, @OGUID+142),
(@EVENT, @OGUID+143),
(@EVENT, @OGUID+144),
(@EVENT, @OGUID+145),
(@EVENT, @OGUID+146),
(@EVENT, @OGUID+147),
(@EVENT, @OGUID+148),
(@EVENT, @OGUID+149),
(@EVENT, @OGUID+150),
(@EVENT, @OGUID+151),
(@EVENT, @OGUID+152),
(@EVENT, @OGUID+153),
(@EVENT, @OGUID+154),
(@EVENT, @OGUID+155),
(@EVENT, @OGUID+156),
(@EVENT, @OGUID+157),
(@EVENT, @OGUID+158),
(@EVENT, @OGUID+159),
(@EVENT, @OGUID+160),
(@EVENT, @OGUID+161),
(@EVENT, @OGUID+162),
(@EVENT, @OGUID+163),
(@EVENT, @OGUID+164),
(@EVENT, @OGUID+165),
(@EVENT, @OGUID+166),
(@EVENT, @OGUID+167),
(@EVENT, @OGUID+168),
(@EVENT, @OGUID+169),
(@EVENT, @OGUID+170),
(@EVENT, @OGUID+171),
(@EVENT, @OGUID+172),
(@EVENT, @OGUID+173),
(@EVENT, @OGUID+174),
(@EVENT, @OGUID+175),
(@EVENT, @OGUID+176),
(@EVENT, @OGUID+177),
(@EVENT, @OGUID+178),
(@EVENT, @OGUID+179),
(@EVENT, @OGUID+180),
(@EVENT, @OGUID+181),
(@EVENT, @OGUID+182),
(@EVENT, @OGUID+183),
(@EVENT, @OGUID+184),
(@EVENT, @OGUID+185),
(@EVENT, @OGUID+186),
(@EVENT, @OGUID+187),
(@EVENT, @OGUID+188),
(@EVENT, @OGUID+189),
(@EVENT, @OGUID+190),
(@EVENT, @OGUID+191),
(@EVENT, @OGUID+192),
(@EVENT, @OGUID+193),
(@EVENT, @OGUID+194),
(@EVENT, @OGUID+195),
(@EVENT, @OGUID+196),
(@EVENT, @OGUID+197),
(@EVENT, @OGUID+198),
(@EVENT, @OGUID+199),
(@EVENT, @OGUID+200),
(@EVENT, @OGUID+201),
(@EVENT, @OGUID+202),
(@EVENT, @OGUID+203),
(@EVENT, @OGUID+204),
(@EVENT, @OGUID+205),
(@EVENT, @OGUID+206),
(@EVENT, @OGUID+207),
(@EVENT, @OGUID+208),
(@EVENT, @OGUID+209),
(@EVENT, @OGUID+210),
(@EVENT, @OGUID+211),
(@EVENT, @OGUID+212),
(@EVENT, @OGUID+213),
(@EVENT, @OGUID+214),
(@EVENT, @OGUID+215),
(@EVENT, @OGUID+216),
(@EVENT, @OGUID+217),
(@EVENT, @OGUID+218),
(@EVENT, @OGUID+219),
(@EVENT, @OGUID+220),
(@EVENT, @OGUID+221),
(@EVENT, @OGUID+222),
(@EVENT, @OGUID+223),
(@EVENT, @OGUID+224),
(@EVENT, @OGUID+225),
(@EVENT, @OGUID+226),
(@EVENT, @OGUID+227),
(@EVENT, @OGUID+228),
(@EVENT, @OGUID+229),
(@EVENT, @OGUID+230),
(@EVENT, @OGUID+231),
(@EVENT, @OGUID+232),
(@EVENT, @OGUID+233),
(@EVENT, @OGUID+234),
(@EVENT, @OGUID+235),
(@EVENT, @OGUID+236),
(@EVENT, @OGUID+237),
(@EVENT, @OGUID+238),
(@EVENT, @OGUID+239),
(@EVENT, @OGUID+240),
(@EVENT, @OGUID+241),
(@EVENT, @OGUID+242);
