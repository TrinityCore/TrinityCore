UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=187886; -- Burblegobble's Bauble
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=189970; -- Scourge Discombobulater
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=147439; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=147437; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=147435; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=147444; -- Bench
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=182063; -- Basin of Holy Water
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=1587; -- Turkey Leg
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=195664; -- [DND] Collision Thanksgiving Table Size
UPDATE `gameobject_template` SET `WDBVerified`=13329 WHERE `entry`=180323; -- Gates of Zul'Gurub

DELETE FROM `gameobject_template` WHERE `entry` IN (206350, 206364, 206349, 206362, 206363, 206365, 206348, 206347, 206345, 206346, 206569, 204918, 203396, 203197, 203198, 203207, 204225, 204220, 204223, 207576, 207575, 204221, 203091, 204224, 203818, 206880, 205383, 203606);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(206350, 8, 197, 'Brazier', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.08, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206364, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206349, 8, 197, 'Brazier', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206362, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206363, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206365, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206348, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206347, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206345, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206346, 7, 7420, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206569, 2, 7011, 'Eye of Twilight', '', '', '', 0, 15873, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.4, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204918, 8, 8062, 'Campfire', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.16, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203396, 3, 9487, 'Nazgrim''s Flare Gun', '', 'Collecting', '', 1691, 29667, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 56249, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203197, 3, 7041, 'Twilight Armor Plate', '', 'Collecting', '', 43, 29580, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.8, 55809, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203198, 3, 454, 'Twilight Armor Plate', '', 'Collecting', '', 43, 29580, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.45, 55809, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203207, 2, 470, 'Codex of Shadows', '', '', '', 0, 15132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204225, 8, 9432, 'Brazier', '', '', '', 4, 10, 179900, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.96493, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204220, 8, 9432, 'Brazier', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1976, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204223, 8, 9684, 'Forge', '', '', '', 3, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.41, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(207576, 8, 9432, 'Brazier', '', '', '', 0, 10, 179900, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.150414, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(207575, 8, 9432, 'Brazier', '', '', '', 0, 10, 179900, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.760294, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204221, 8, 9432, 'Brazier', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.35493, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203091, 8, 3332, 'Ogre Outhouse', '', '', '', 1659, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(204224, 8, 9685, 'Anvil', '', '', '', 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203818, 8, 9653, 'Burning Debris', '', '', '', 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.17, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(206880, 8, 192, 'Campfire', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.89, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(205383, 8, 192, 'Campfire', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329), -- -Unknown-
(203606, 8, 197, 'Doodad_DwarvenBrazier200', '', '', '', 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 13329); -- -Unknown-

DELETE FROM `npc_text` WHERE `ID` IN (16868, 16879);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(16868, '', 'Do you need to return to Vashj''ir?', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 13329), -- 16868
(16879, 'Yo. Up for a little target practice?', 'Yo. Up for a little target practice?', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 13329); -- 16879

UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=13329 WHERE `ID`=4859; -- 4859
UPDATE `npc_text` SET `em0_0`=113, `em0_1`=0, `WDBVerified`=13329 WHERE `ID`=15607; -- 15607
UPDATE `npc_text` SET `WDBVerified`=13329 WHERE `ID`=14178; -- 14178
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=13329 WHERE `ID`=12904; -- 12904
UPDATE `npc_text` SET `WDBVerified`=13596 WHERE `ID`=7956; -- 7956
UPDATE `npc_text` SET `WDBVerified`=13596 WHERE `ID`=11492; -- 11492
UPDATE `npc_text` SET `text0_1`='From this dock, The Bravery travels back and forth between Stormwind and Rut''theran Village.', `WDBVerified`=13596 WHERE `ID`=13321; -- 13321
UPDATE `npc_text` SET `WDBVerified`=13596 WHERE `ID`=15212; -- 15212
UPDATE `npc_text` SET `em0_0`=1, `em0_1`=0, `WDBVerified`=13596 WHERE `ID`=15170; -- 15170
UPDATE `npc_text` SET `WDBVerified`=13329 WHERE `ID`=14204; -- 14204
