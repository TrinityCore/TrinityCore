-- 
UPDATE `creature_template` SET `gossip_menu_id`=10244 WHERE `entry`=19169; -- Blood Elf
UPDATE `creature_template` SET `gossip_menu_id`=10245 WHERE `entry`=19171; -- Draenei 
UPDATE `creature_template` SET `gossip_menu_id`=10246 WHERE `entry`=19148; -- Dwarf 
UPDATE `creature_template` SET `gossip_menu_id`=10247 WHERE `entry`=19172; -- Gnome 
UPDATE `creature_template` SET `gossip_menu_id`=10248 WHERE `entry`=20102; -- Goblin
UPDATE `creature_template` SET `gossip_menu_id`=10249 WHERE `entry`=18927; -- Human
UPDATE `creature_template` SET `gossip_menu_id`=10250 WHERE `entry`=19173; -- Night Elf
UPDATE `creature_template` SET `gossip_menu_id`=10251 WHERE `entry`=19175; -- Orc
UPDATE `creature_template` SET `gossip_menu_id`=10252 WHERE `entry`=19176; -- Tauren 
UPDATE `creature_template` SET `gossip_menu_id`=10253 WHERE `entry`=19177; -- Troll 
UPDATE `creature_template` SET `gossip_menu_id`=10254 WHERE `entry`=19178; -- Forsaken

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19169,19171,19148,19172,20102,18927,19173,19175,19176,19177,19178) AND `source_type`=0 AND `id` IN (9,10,11,12);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (10244, 10245, 10246, 10247, 10248, 10249, 10250, 10251, 10252, 10253, 10254);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
-- Blood Elf
(10244, 9680), -- Midsummer
(10244, 9698), -- Winter Veil
(10244, 9696), -- lunar festival
(10244, 9700), -- lunar festival Silvermoon
(10244, 11956), -- Hallow
(10244, 12134), -- Brewfest
(10244, 13044), -- Pirates
(10244, 14227), -- Noblegarden
(10244, 14544), -- Dod
(10244, 14635), -- Pilgrim
-- Draenei 
(10245, 9680), -- Midsummer
(10245, 9690), -- Winter Veil
(10245, 9696), -- lunar festival
(10245, 11957), -- Hallow
(10245, 12134), -- Brewfest
(10245, 13044), -- Pirates
(10245, 14228), -- Noblegarden
(10245, 14544), -- Dod
(10245, 14636), -- Pilgrim
-- Dwarf 
(10246, 9680), -- Midsummer
(10246, 9686), -- Winter Veil
(10246, 9688), -- lunar festival
(10246, 11958), -- Hallow
(10246, 12134), -- Brewfest
(10246, 13044), -- Pirates
(10246, 14229), -- Noblegarden
(10246, 14544), -- Dod
(10246, 14637), -- Pilgrim
-- Gnome 
(10247, 9680), -- Midsummer
(10247, 9717), -- Winter Veil
(10247, 9715), -- lunar festival
(10247, 11959), -- Hallow
(10247, 12134), -- Brewfest
(10247, 13044), -- Pirates
(10247, 14230), -- Noblegarden
(10247, 14544), -- Dod
(10247, 14638), -- Pilgrim
-- Goblin
(10248, 9680), -- Midsummer
(10248, 8139), -- Winter Veil
(10248, 9964), -- lunar festival
(10248, 11960), -- Hallow
(10248, 12134), -- Brewfest
(10248, 13044), -- Pirates
(10248, 14231), -- Noblegarden
(10248, 14544), -- Dod
(10248, 14639), -- Pilgrim
-- Human
(10249, 9680), -- Midsummer
(10249, 9626), -- Winter Veil
(10249, 9696), -- lunar festival
(10249, 9662), -- lunar festival stormwind
(10249, 11961), -- Hallow
(10249, 12134), -- Brewfest
(10249, 13044), -- Pirates
(10249, 14232), -- Noblegarden
(10249, 14544), -- Dod
(10249, 14640), -- Pilgrim
-- Night Elf
(10250, 9680), -- Midsummer
(10250, 9694), -- Winter Veil
(10250, 9692), -- lunar festival
(10250, 11962), -- Hallow
(10250, 12134), -- Brewfest
(10250, 13044), -- Pirates
(10250, 14233), -- Noblegarden
(10250, 14544), -- Dod
(10250, 14641), -- Pilgrim
-- Orc
(10251, 9680), -- Midsummer
(10251, 9702), -- Winter Veil
(10251, 9704), -- lunar festival
(10251, 11963), -- Hallow
(10251, 12134), -- Brewfest
(10251, 13044), -- Pirates
(10251, 14234), -- Noblegarden
(10251, 14544), -- Dod
(10251, 14642), -- Pilgrim
-- Tauren
(10252, 9680), -- Midsummer
(10252, 9706), -- Winter Veil
(10252, 9708), -- lunar festival
(10252, 11964), -- Hallow
(10252, 12134), -- Brewfest
(10252, 13044), -- Pirates
(10252, 14235), -- Noblegarden
(10252, 14544), -- Dod
(10252, 14643), -- Pilgrim
-- Troll 
(10253, 9680), -- Midsummer
(10253, 9718), -- Winter Veil
(10253, 9716), -- lunar festival
(10253, 11965), -- Hallow
(10253, 12134), -- Brewfest
(10253, 13044), -- Pirates
(10253, 14236), -- Noblegarden
(10253, 14544), -- Dod
(10253, 14644), -- Pilgrim
-- Forsaken
(10254, 9680), -- Midsummer
(10254, 9710), -- Winter Veil
(10254, 9712), -- lunar festival
(10254, 11966), -- Hallow
(10254, 12134), -- Brewfest
(10254, 13044), -- Pirates
(10254, 14237), -- Noblegarden
(10254, 14544), -- Dod
(10254, 14645); -- Pilgrim

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup` IN (10244, 10245, 10246, 10247, 10248, 10249, 10250, 10251, 10252, 10253, 10254);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Blood Elf
(14,10244,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active'),
(14,10244,9698,0,12,0,2,0,0,0,'','Show gossip text if he event is active'),
(14,10244,9696,0,12,0,7,0,0,0,'','Show gossip text if he event is active'),
(14,10244,9696,0,22,1,571,0,0,0,'','Show gossip text if he event is active'),
(14,10244,9700,0,12,0,7,0,0,0,'','Show gossip text if he event is active'),
(14,10244,9700,0,22,1,530,0,0,0,'','Show gossip text if he event is active'),
(14,10244,11956,0,12,0,12,0,0,0,'','Show gossip text if he event is active'),
(14,10244,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active'),
(14,10244,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active'),
(14,10244,14227,0,12,0,9,0,0,0,'','Show gossip text if he event is active'),
(14,10244,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active'),
(14,10244,14635,0,12,0,26,0,0,0,'','Show gossip text if he event is active'),
-- Draenei 
(14,10245,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10245,9690,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10245,9696,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10245,11957,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10245,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10245,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10245,14228,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10245,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10245,14636,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Dwarf
(14,10246,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10246,9686,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10246,9688,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10246,11958,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10246,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10246,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10246,14229,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10246,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10246,14637,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Gnome
(14,10247,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10247,9717,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10247,9715,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10247,11959,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10247,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10247,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10247,14230,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10247,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10247,14638,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Goblin
(14,10248,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10248,8139,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10248,9964,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10248,11960,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10248,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10248,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10248,14231,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10248,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10248,14639,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Human
(14,10249,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10249,9626,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10249,9696,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10249,9696,0,22,1,571,0,0,0,'','Show gossip text if in map 571'),
(14,10249,9662,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10249,9662,0,22,1,530,0,0,0,'','Show gossip text if in map 530'),
(14,10249,11961,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10249,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10249,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10249,14232,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10249,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10249,14640,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Night Elf
(14,10250,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10250,9694,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10250,9692,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10250,11962,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10250,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10250,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10250,14233,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10250,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10250,14641,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Orc
(14,10251,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10251,9702,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10251,9704,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10251,11963,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10251,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10251,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10251,14234,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10251,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10251,14642,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Tauren
(14,10252,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10252,9706,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10252,9708,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10252,11964,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10252,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10252,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10252,14235,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10252,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10252,14643,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Troll
(14,10253,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10253,9718,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10253,9716,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10253,11965,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10253,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10253,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10253,14236,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10253,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10253,14644,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26'),
-- Forsaken
(14,10254,9680,0,12,0,1,0,0,0,'','Show gossip text if he event is active 1'),
(14,10254,9710,0,12,0,2,0,0,0,'','Show gossip text if he event is active 2'),
(14,10254,9712,0,12,0,7,0,0,0,'','Show gossip text if he event is active 7'),
(14,10254,11966,0,12,0,12,0,0,0,'','Show gossip text if he event is active 12'),
(14,10254,12134,0,12,0,24,0,0,0,'','Show gossip text if he event is active 24'),
(14,10254,13044,0,12,0,50,0,0,0,'','Show gossip text if he event is active 50'),
(14,10254,14237,0,12,0,9,0,0,0,'','Show gossip text if he event is active 9'),
(14,10254,14544,0,12,0,51,0,0,0,'','Show gossip text if he event is active 51'),
(14,10254,14645,0,12,0,26,0,0,0,'','Show gossip text if he event is active 26');
-- 
UPDATE `npc_text` SET `text0_0`="Why do we celebrate Pilgrim's Bounty...? Who can say. Habit, I suppose. I certainly can't taste any of it.$B$BPumpkin pie, virulent plagues... Does it really matter WHAT we're cooking up?", `text0_1`="Why do we celebrate Pilgrim's Bounty...? Who can say. Habit, I suppose. I certainly can't taste any of it.$B$BPumpkin pie, virulent plagues... Does it really matter WHAT we're cooking up?", `BroadcastTextID0`=35101 WHERE `ID`=14645;
UPDATE `npc_text` SET `text0_0`="The celebration of the natural processes of the world is silly; it's going to happen whether we celebrate or not! But it's a great excuse for sugar!", `text0_1`="The celebration of the natural processes of the world is silly; it's going to happen whether we celebrate or not! But it's a great excuse for sugar!", `BroadcastTextID0`=33121 WHERE `ID`=14230;
DELETE FROM `npc_text` WHERE `ID` IN (9680);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `Probability0`, `BroadcastTextID0`, `text1_0`, `text1_1`, `lang1`, `Probability1`, `BroadcastTextID1`, `text2_0`, `text2_1`, `lang2`, `Probability2`, `BroadcastTextID2`, `text3_0`, `text3_1`, `lang3`, `Probability3`, `BroadcastTextID3`, `text4_0`, `text4_1`, `lang4`, `Probability4`, `BroadcastTextID4`) VALUES
(9680, "Enjoying the Midsummer Fire Festival, $c?", "Enjoying the Midsummer Fire Festival, $c?", 0, 1, 49959, "Festive Midsummer, $c!", "Festive Midsummer, $c!", 0, 1, 49960, "Midsummer Fire Festival is a great time to adventure, but it's also a great time to shop!", "Midsummer Fire Festival is a great time to adventure, but it's also a great time to shop!", 0, 1, 49961, "Midsummer Fire Festival is a great time to celebrate the summer!", "Midsummer Fire Festival is a great time to celebrate the summer!", 0, 1, 24535, "I love the firework show at the end of Midsummer Firefestival.", "I love the firework show at the end of Midsummer Firefestival.", 0, 1, 24536);
