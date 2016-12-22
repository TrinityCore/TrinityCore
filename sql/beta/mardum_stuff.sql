DELETE FROM `graveyard_zone` WHERE `GhostZone` = 7705;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES 
(5082, 7705, 0, '7.0 DH-Mardum - (01) Start'),
(5083, 7705, 0, '7.0 DH-Mardum - (03) Seat of Command'),
(5119, 7705, 0, '7.0 DH-Mardum - (04) Illidari Foothold'),
(5140, 7705, 0, '7.0 DH-Mardum - (05) Volcano'),
(5188, 7705, 0, '7.0 DH-Mardum - (06) The Fel Hammer'),
(5284, 7705, 0, '7.0 DH-Mardum - (02) Molten Shore');

DELETE FROM `scene_template` WHERE `SceneId` IN (1106, 1116, 1053, 1077, 1061, 1078, 1094, 1095, 1079, 1142);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `ScriptName`) VALUES 
(1106, 20, 1487, 'scene_demon_hunter_start'),
(1116, 27, 1493, 'scene_the_invasion_begins_banner'),
(1053, 20, 1451, 'scene_enter_the_illidari_ashtongue'),
(1077, 20, 1468, ''),
(1061, 26, 1460, 'scene_meeting_with_the_queen'),
(1078, 20, 1469, ''),
(1094, 20, 1479, ''),
(1095, 20, 1480, ''),
(1079, 20, 1470, ''),
(1142, 20, 1512, '');

DELETE FROM `phase_area` WHERE `AreaID` IN (7705, 7741, 7740, 7742, 7712, 7754, 7713, 7749, 7912);
-- Zone 7705
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5114, 'Mardum - Zone 7705 Soul Engine Devastator'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5115, 'Mardum - Zone 7705 Doom Fortress Devastator'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5116, 'Mardum - Zone 7705 Forge of Corruption Devastator'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 4899, 'Mardum - Not Aura 193525 & After Quest 40076');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5094, 'Mardum - Zone 7705 Inquisitor Baleful Elemental');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5095, 'Mardum - Zone 7705 Doom Commander Spires and Jace');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5324, 'Mardum - Zone 7705 Necessary Perma Spawns');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5837, 'Mardum - Zone 7705 Misc Spawns');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 5056, 'Mardum - Zone 7705 Mountain Devastators');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 4881, 'Mardum - Area 7742 Battlelord Gaardoun Camp'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 4883, 'Mardum - Area 7742 Lady S\'theno Camp'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7705, 4884, 'Mardum - Area 7742 Matron Mother Malevolence Camp'); -- Missing Condition
-- Area 7741
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5305, 'Mardum - Area 7741 Alari Kayn');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5310, 'Mardum - Area 7741 Demons Alive');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5463, 'Mardum - Area 7741 Sevis at Ashtongue Gate');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5595, 'Mardum - Area 7741 Sevis at Cave');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 5658, 'Mardum - Area 7741 Felsaber');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7741, 169, 'Mardum - Area 7741 Demons Dead');
-- Area 7740
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 4925, 'Mardum - Area 7740 Cyana Nightglaive Cage');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 4927, 'Mardum - Area 7740 Mannethrel Darkstar Cage');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 4931, 'Mardum - Area 7740 Belath Dawnblade Cage');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 4932, 'Mardum - Area 7740 Izal Whitemoon Cage');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 5461, 'Mardum - Area 7740 Living Mythic to sacrifice');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7740, 5464, 'Mardum - Area 7740 Sevis at Coilskargate');
-- Area 7742
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7742, 5161, 'Mardum - Area 7742');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7742, 5462, 'Mardum - Area 7742 Sevis Brightflame who wants to be sacrificed');
-- Area 7712
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5086, 'Mardum - Area 7712 Jace Darkweaver Cave');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5113, 'Mardum - Area 7712 Soul Engine Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5117, 'Mardum - Area 7712 Forge of Corruption Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5120, 'Mardum - Area 7712 Doom Fortress Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5160, 'Mardum - Area 7712 Cyana Allari Kayn Camp'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5203, 'Mardum - Area 7712');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5343, 'Mardum - Area 7712 Kor\'vas Bloodthorn Camp');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5357, 'Mardum - Area 7712 Mannethrel Camp living');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5381, 'Mardum - Area 7712 Izal, Falara and Belath Camp');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5465, 'Mardum - Area 7712 Sevis alive'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5533, 'Mardum - Area 7712 Injured Ashtonge and Mythic Camp');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 5534, 'Mardum - Area 7712 Injured Naga and Healer Camp');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7712, 6303, 'Mardum - Area 7712 Sevis Brightflame as Ghost');
-- Area 7754
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7754, 5077, 'Mardum - Area 7754');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7754, 5084, 'Mardum - Area 7754');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7754, 5086, 'Mardum - Area 7754 Jace Darkweaver Cave');
-- Area 7713
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7713, 5113, 'Mardum - Area 7713 Soul Engine Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7713, 5117, 'Mardum - Area 7713 Forge of Corruption Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7713, 5120, 'Mardum - Area 7713 Doom Fortress Devastator Banner'); -- Missing Condition
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7713, 5203, 'Mardum - Area 7713');
-- Area 7912
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7912, 5344, 'Mardum - Area 7912 Kor\'vas Bloodthorn Foul');
-- Area 7749
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7749, 5257, 'Mardum - Area 7749');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7749, 5322, 'Mardum - Area 7749');
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (7749, 5466, 'Mardum - Area 7749');

-- Phase Conditiom
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceEntry` IN (7705, 7741, 7740, 7742, 7712, 7754, 7713, 7749, 7912);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 4899, 7705, 0, 1, 8, 0, 40076, 0, 0, 0, 0, 0, '', 'If no aura 193525 & quest 40076 rewarded & quest 40077 not taken complete rewarded'), 
(26, 4899, 7705, 0, 1, 1, 0, 193525, 0, 0, 1, 0, 0, '', 'If no aura 193525 & quest 40076 rewarded & quest 40077 not taken complete rewarded'),
(26, 4899, 7705, 0, 1, 14, 0, 40077, 0, 0, 0, 0, 0, '', 'If no aura 193525 & quest 40076 rewarded & quest 40077 not taken complete rewarded'),
(26, 5094, 7705, 0, 1, 8, 0, 39049, 0, 0, 1, 0, 0, '', 'If quest 39049 not rewarded'),
(26, 5094, 7705, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 5095, 7705, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 5095, 7705, 0, 1, 8, 0, 38765, 0, 0, 1, 0, 0, '', 'If quest 38765 not rewarded'),
(26, 5095, 7705, 0, 1, 8, 0, 38766, 0, 0, 1, 0, 0, '', 'If quest 38766 not rewarded'),
(26, 4881, 7705, 0, 1, 8, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 rewarded'),
(26, 4883, 7705, 0, 1, 8, 0, 40379, 0, 0, 0, 0, 0, '', 'If quest 40379 rewarded'), 
(26, 4884, 7705, 0, 1, 8, 0, 38765, 0, 0, 0, 0, 0, '', 'If quest 38765 rewarded'),
(26, 4884, 7705, 0, 2, 48, 0, 38765, 278937, 0, 0, 0, 0, '', 'If Objective 278937 complete'),
(26, 5463, 7741, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 5463, 7741, 0, 1, 48, 0, 40378, 280768, 0, 1, 0, 0, '', 'If quest 40378 Objective 278929 incomplete'),
(26, 5463, 7741, 0, 1, 8, 0, 40378, 0, 0, 1, 0, 0, '', 'If quest 40378 not rewarded'),
(26, 5310, 7741, 0, 1, 8, 0, 40077, 0, 0, 1, 0, 0, '', 'If quest 40077 complete rewarded'), 
(26, 5310, 7741, 0, 1, 28, 0, 40077, 0, 0, 1, 0, 0, '', 'If quest 40077 complete rewarded'),
(26, 169, 7741, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 complete OR rewarded'), 
(26, 169, 7741, 0, 2, 28, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 complete OR rewarded'),
(26, 5305, 7741, 0, 1, 28, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 complete OR rewarded'),
(26, 5305, 7741, 0, 2, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 complete OR rewarded'), 
(26, 5305, 7741, 0, 2, 14, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 not taken complete rewarded'),
(26, 5658, 7741, 0, 1, 48, 0, 40378, 281158, 0, 0, 0, 0, '', 'If quest 40378 Objective 281158 complete'),
(26, 5658, 7741, 0, 1, 48, 0, 40378, 281156, 0, 1, 0, 0, '', 'If quest 40378 Objective 281156 incomplete'),
(26, 5658, 7741, 0, 1, 8, 0, 40378, 0, 0, 1, 0, 0, '', 'If quest 40378 not complete'),
(26, 5658, 7741, 0, 1, 28, 0, 40378, 0, 0, 1, 0, 0, '', 'If quest 40378 not rewarded'),
(26, 5595, 7741, 0, 1, 48, 0, 40378, 281156, 0, 0, 0, 0, '', 'If quest 40378 Objective 281156 complete'),
(26, 5595, 7741, 0, 1, 14, 0, 40379, 0, 0, 0, 0, 0, '', 'If 40379 not taken complete rewarded'),
(26, 5595, 7741, 0, 2, 8, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 complete'),
(26, 5595, 7741, 0, 2, 14, 0, 40379, 0, 0, 0, 0, 0, '', 'If 40379 not taken complete rewarded'),
(26, 5595, 7741, 0, 3, 28, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 rewarded'),
(26, 5595, 7741, 0, 3, 14, 0, 40379, 0, 0, 0, 0, 0, '', 'If 40379 not taken complete rewarded'),
(26, 4925, 7740, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 4925, 7740, 0, 1, 48, 0, 38759, 280293, 0, 1, 0, 0, '', 'If quest 38759 Objective 280293 incomplete'),
(26, 4925, 7740, 0, 1, 8, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not complete'),
(26, 4925, 7740, 0, 1, 28, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not rewarded'),
(26, 4927, 7740, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 4927, 7740, 0, 1, 48, 0, 38759, 278413, 0, 1, 0, 0, '', 'If quest 38759 Objective 278413 incomplete'),
(26, 4927, 7740, 0, 1, 8, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not complete'),
(26, 4927, 7740, 0, 1, 28, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not rewarded'),
(26, 4931, 7740, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 4931, 7740, 0, 1, 48, 0, 38759, 278928, 0, 1, 0, 0, '', 'If quest 38759 Objective 278928 incomplete'),
(26, 4931, 7740, 0, 1, 8, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not complete'),
(26, 4931, 7740, 0, 1, 28, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not rewarded'),
(26, 4932, 7740, 0, 1, 8, 0, 40077, 0, 0, 0, 0, 0, '', 'If quest 40077 rewarded'),
(26, 4932, 7740, 0, 1, 48, 0, 38759, 278929, 0, 1, 0, 0, '', 'If quest 38759 Objective 278929 incomplete'),
(26, 4932, 7740, 0, 1, 8, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not complete'),
(26, 4932, 7740, 0, 1, 28, 0, 38759, 0, 0, 1, 0, 0, '', 'If quest 38759 not rewarded'),
(26, 5464, 7740, 0, 1, 9, 0, 40379, 0, 0, 0, 0, 0, '', 'If quest 40379 taken'),
(26, 5464, 7740, 0, 1, 48, 0, 40379, 280771, 0, 1, 0, 0, '', 'If quest 40379 Objective 280771 incomplete'),
(26, 5461, 7740, 0, 1, 9, 0, 40379, 0, 0, 0, 0, 0, '', 'If quest 40379 taken'),
(26, 5461, 7740, 0, 1, 8, 0, 40379, 0, 0, 1, 0, 0, '', 'If quest 40379 not complete'),
(26, 5461, 7740, 0, 1, 28, 0, 40379, 0, 0, 1, 0, 0, '', 'If quest 40379 not rewarded'),
(26, 5461, 7740, 0, 1, 48, 0, 40379, 280770, 0, 1, 0, 0, '', 'If quest 40379 Objective 280770 incomplete'),
(26, 5462, 7742, 0, 1, 48,0, 38765, 280772, 0, 1, 0, 0, '','if Objective Incomplete AND 38765 unrewarded'),
(26, 5462, 7742, 0, 1, 8, 0, 38765, 0, 0, 1, 0, 0, '','if Objective Incomplete AND 38765 unrewarded'),
(26, 5462, 7742, 0, 1, 9, 0, 38765, 0, 0, 0, 0, 0, '','if Objective Incomplete AND 38765 unrewarded'),
(26, 6303, 7712, 0, 1, 8, 0, 40087, 0, 0, 0, 0, 0, '','If quest 40087 rewarded'),
(26, 5533, 7712, 0, 1, 8, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 complete OR rewarded'), 
(26, 5533, 7712, 0, 2, 28, 0, 40378, 0, 0, 0, 0, 0, '', 'If quest 40378 complete OR rewarded'),
(26, 5534, 7712, 0, 1, 8, 0, 40379, 0, 0, 0, 0, 0, '', 'If quest 40379 complete OR rewarded'), 
(26, 5534, 7712, 0, 2, 28, 0, 40379, 0, 0, 0, 0, 0, '', 'If quest 40379 complete OR rewarded'),
(26, 5357, 7712, 0, 1, 48, 0, 38759, 278413, 0, 0, 0, 0, '', 'If quest 38759 Objective 278413 complete'),
(26, 5357, 7712, 0, 2, 8, 0, 38759, 0, 0, 0, 0, 0, '', 'If quest 38759 complete'),
(26, 5357, 7712, 0, 3, 28, 0, 38759, 0, 0, 0, 0, 0, '', 'If quest 38759 rewarded'),
(26, 5381, 7712, 0, 1, 48, 0, 38759, 278929, 0, 0, 0, 0, '', 'If quest 38759 Objective 278929 complete'),
(26, 5381, 7712, 0, 2, 8, 0, 38759, 0, 0, 0, 0, 0, '', 'If quest 38759 complete'),
(26, 5381, 7712, 0, 3, 28, 0, 38759, 0, 0, 0, 0, 0, '', 'If quest 38759 rewarded'),
(26, 5343, 7712, 0, 1, 9, 0, 40222, 0, 0, 0, 0, 0, '', 'If quest 40222 taken'),
(26, 5343, 7712, 0, 2, 8, 0, 40222, 0, 0, 0, 0, 0, '', 'If quest 40222 complete'),
(26, 5343, 7712, 0, 3, 28, 0, 40222, 0, 0, 0, 0, 0, '', 'If quest 40222 rewarded'),
(26, 5086, 7712, 0, 1, 8, 0, 38765, 0, 0, 0, 0, 0, '', 'If quest 38765 rewarded'),
(26, 5086, 7712, 0, 1, 8, 0, 38766, 0, 0, 0, 0, 0, '', 'If quest 38766 rewarded'),
(26, 5465, 7712, 0, 1, 8, 0, 38765, 0, 0, 0, 0, 0, '', 'If quest 38765 rewarded'),
(26, 5465, 7712, 0, 1, 8, 0, 40087, 0, 0, 1, 0, 0, '', 'If quest 40087 not rewarded'),
(26, 5465, 7712, 0, 2, 48, 0, 38765, 278937, 0, 0, 0, 0, '', 'If Objective 278937 complete'),
(26, 5465, 7712, 0, 2, 8, 0, 40087, 0, 0, 1, 0, 0, '', 'If quest 40087 not rewarded'),
(26, 5086, 7754, 0, 1, 8, 0, 38765, 0, 0, 0, 0, 0, '', 'If quest 38765 rewarded'),
(26, 5086, 7754, 0, 1, 8, 0, 38766, 0, 0, 0, 0, 0, '', 'If quest 38766 rewarded'),
(26, 5344, 7912, 0, 1, 14, 0, 40222, 0, 0, 0, 0, 0, '', 'If quest 40222 not taken complete rewarded');


-- Spell Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 196724;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 196724, 0, 0, 31, 0, 3, 99914, 0, 0, 0, 0, '', 'Sacrificing Mystic\'s Soul');

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger` = -193525 AND `spell_effect` = 82238) OR (`spell_trigger` = 184561 AND `spell_effect` = 189261) OR (`spell_trigger` = 184562 AND `spell_effect` = 190793) OR (`spell_trigger` = -196030 AND `spell_effect` = 193525) OR (`spell_trigger` = 198253 AND `spell_effect` = 189767) OR (`spell_trigger` = -200255 AND `spell_effect` = 82238) OR (`spell_trigger` = 184563 AND `spell_effect` = 190851);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES 
(-193525, 82238, 'Update Phase'),
(184561, 189261, ''),
(184562, 190793, ''),
(-196030, 193525, ''),
(198253, 189767, ''),
(-200255, 82238, 'Update Phase'),
(184563, 190851 , '');

DELETE FROM `spell_area` WHERE `spell` = 196030 AND `area` = 7705;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(196030, 7705, 0, 40076, 0, 0, 2, 1, 64, 1);

DELETE FROM `creature_text` WHERE `entry` IN (99916, 94410, 99917, 93105, 99915);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(99916, 0, 0, 'Plenty of souls were sacrificed here. The activator is powered.', 12, 0, 100, 273, 0, 55344, '101656', 'Sevis Brightflame to Player'),
(94410, 0, 0, '$n, over here.', 12, 0, 100, 0, 0, 55011, 96441, 'Allari the Souleater to Player'),
(99917, 0, 0, '$n, hurry! You don''t have much time.', 12, 0, 100, 3, 0, 55345, '101658', 'Sevis Brightflame to Player'),
(99917, 1, 0, 'Sevis looks down at the dying broken mystic.', 16, 0, 100, 0, 0, 0, '101659', 'Sevis Brightflame to Player'),
(93105, 0, 0, 'I can see your secrets...', 12, 0, 100, 0, 0, 55222, 94930, 'Inquisitor Baleful to Player'),
(93105, 1, 0, 'My eyes... My eyes!', 14, 0, 100, 0, 0, 55223, 96010, 'Inquisitor Baleful to Player'),
(93105, 2, 0, 'Enough! My colossal infernal will crush you.', 14, 0, 100, 0, 0, 55224, 99554, 'Inquisitor Baleful to Player'),
(99915, 0, 0, '$n, we have a huge problem here.', 12, 0, 100, 0, 0, 55342, '101663', 'Sevis Brightflame to Player');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (196724, 196735, 223315);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('196724', 'spell_sacrificing_mystics_soul'),
('196735', 'spell_sevis_sacrifice_me'),
('223315', 'spell_enter_the_illidari_shivarra_sacrificing_sevis');

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=98986 AND `Idx`=0) OR (`CreatureEntry`=93802 AND `Idx`=0) OR (`CreatureEntry`=95226 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(98986, 0, 129957, 22908), -- 98986
(93802, 0, 124672, 22908), -- 93802
(95226, 0, 128227, 22908); -- 95226

DELETE FROM `npc_text` WHERE `ID` IN (27307, 27421, 27624, 28106, 27622, 27623, 26129, 26832, 26676, 26592, 28000, 27999, 27770, 27954, 27998, 26813, 27773, 27768, 27772, 27545, 27283, 27471, 28886, 27771, 27206, 27769);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27307, 1, 0, 0, 0, 0, 0, 0, 0, 99020, 0, 0, 0, 0, 0, 0, 0, 22908),
(27421, 1, 0, 0, 0, 0, 0, 0, 0, 99834, 0, 0, 0, 0, 0, 0, 0, 22908),
(27624, 1, 0, 0, 0, 0, 0, 0, 0, 100749, 0, 0, 0, 0, 0, 0, 0, 22908),
(28106, 1, 0, 0, 0, 0, 0, 0, 0, 103959, 0, 0, 0, 0, 0, 0, 0, 22908),
(27622, 1, 0, 0, 0, 0, 0, 0, 0, 100733, 0, 0, 0, 0, 0, 0, 0, 22908),
(27623, 1, 0, 0, 0, 0, 0, 0, 0, 100737, 0, 0, 0, 0, 0, 0, 0, 22908),
(26129, 1, 0, 0, 0, 0, 0, 0, 0, 92162, 0, 0, 0, 0, 0, 0, 0, 22908),
(26832, 1, 0, 0, 0, 0, 0, 0, 0, 96307, 0, 0, 0, 0, 0, 0, 0, 22908),
(26676, 1, 0, 0, 0, 0, 0, 0, 0, 95397, 0, 0, 0, 0, 0, 0, 0, 22908),
(26592, 1, 0, 0, 0, 0, 0, 0, 0, 94951, 0, 0, 0, 0, 0, 0, 0, 22908),
(28000, 1, 0, 0, 0, 0, 0, 0, 0, 103337, 0, 0, 0, 0, 0, 0, 0, 22908),
(27999, 1, 0, 0, 0, 0, 0, 0, 0, 103328, 0, 0, 0, 0, 0, 0, 0, 22908),
(27770, 1, 0, 0, 0, 0, 0, 0, 0, 101650, 0, 0, 0, 0, 0, 0, 0, 22908),
(27954, 1, 0, 0, 0, 0, 0, 0, 0, 103080, 0, 0, 0, 0, 0, 0, 0, 22908),
(27998, 1, 0, 0, 0, 0, 0, 0, 0, 103324, 0, 0, 0, 0, 0, 0, 0, 22908),
(26813, 1, 0, 0, 0, 0, 0, 0, 0, 96144, 0, 0, 0, 0, 0, 0, 0, 22908),
(27773, 1, 0, 0, 0, 0, 0, 0, 0, 101661, 0, 0, 0, 0, 0, 0, 0, 22908),
(27768, 1, 0, 0, 0, 0, 0, 0, 0, 101647, 0, 0, 0, 0, 0, 0, 0, 22908),
(27772, 1, 0, 0, 0, 0, 0, 0, 0, 101660, 0, 0, 0, 0, 0, 0, 0, 22908),
(27545, 1, 0, 0, 0, 0, 0, 0, 0, 100342, 0, 0, 0, 0, 0, 0, 0, 22908),
(27283, 1, 0, 0, 0, 0, 0, 0, 0, 98960, 0, 0, 0, 0, 0, 0, 0, 22908),
(27471, 1, 0, 0, 0, 0, 0, 0, 0, 100024, 0, 0, 0, 0, 0, 0, 0, 22908),
(28886, 1, 0, 0, 0, 0, 0, 0, 0, 108864, 0, 0, 0, 0, 0, 0, 0, 22995),
(27771, 1, 0, 0, 0, 0, 0, 0, 0, 101654, 0, 0, 0, 0, 0, 0, 0, 22995),
(27206, 1, 0, 0, 0, 0, 0, 0, 0, 98578, 0, 0, 0, 0, 0, 0, 0, 22995),
(27769, 1, 0, 0, 0, 0, 0, 0, 0, 101649, 0, 0, 0, 0, 0, 0, 0, 22995);

DELETE FROM `gossip_menu` WHERE (`entry`=18435 AND `text_id`=26592) OR (`entry`=19175 AND `text_id`=28106) OR (`entry`=19544 AND `text_id`=28886) OR (`entry`=19016 AND `text_id`=27771) OR (`entry`=19133 AND `text_id`=28000) OR (`entry`=19016 AND `text_id`=27770) OR (`entry`=19132 AND `text_id`=27999) OR (`entry`=18438 AND `text_id`=26813) OR (`entry`=18720 AND `text_id`=27206) OR (`entry`=18776 AND `text_id`=27307) OR (`entry`=19015 AND `text_id`=27769) OR (`entry`=19017 AND `text_id`=27773) OR (`entry`=19015 AND `text_id`=27768) OR (`entry`=19017 AND `text_id`=27772) OR (`entry`=18899 AND `text_id`=27545) OR (`entry`=18864 AND `text_id`=27471);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(18435, 26592), -- 93127
(19175, 28106), -- 96436
(19544, 28886), -- 105945
(19016, 27771), -- 99915
(19133, 28000), -- 99915
(19016, 27770), -- 99915
(19132, 27999), -- 99915
(18438, 26813), -- 93759
(18720, 27206), -- 96650
(18776, 27307), -- 96653
(19015, 27769), -- 99914
(19017, 27773), -- 99917
(19015, 27768), -- 99914
(19017, 27772), -- 99917
(18899, 27545), -- 94410
(18864, 27471); -- 98229

DELETE FROM `gossip_menu_option` WHERE  `menu_id` IN (19015, 19016, 19133, 19132);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(19015, 0, 0, 'Mystic, thank you for your sacrifice.', 101648, 1, 1, 0, 0, 0, 0, '', 0),
(19016, 1, 0, 'I want you to sacrifice me in order to power the gateway.', 101652, 1, 1, 19132, 0, 0, 0, '', 0),
(19016, 0, 0, 'Sevis, I need to sacrifice you in order to power the final gateway.', 101651, 1, 1, 19133, 0, 0, 0, '', 0),
(19133, 1, 0, 'Hold a moment, Sevis. I''m reconsidering.', 103336, 1, 1, 19016, 0, 0, 0, '', 0),
(19133, 0, 0, 'I''m certain, Sevis. I need to sacrifice you to power the gateway.', 103338, 1, 1, 0, 0, 0, 0, '', 0),
(19132, 1, 0, 'Hold a moment, Sevis. I''m reconsidering.', 103336, 1, 1, 19016, 0, 0, 0, '', 0),
(19132, 0, 0, 'I''ve made up my mind. Sacrifice me, Sevis, and power the gateway.', 103332, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `npc_spellclick_spells` WHERE (`npc_entry` = 101518 AND `spell_id` = 200255) OR (`npc_entry` = 97142 AND `spell_id` = 191827) OR (`npc_entry` = 100549 AND `spell_id` = 192262) OR (`npc_entry` = 100543 AND `spell_id` = 192262) OR (`npc_entry` = 100548 AND `spell_id` = 192262) OR (`npc_entry` = 100545 AND `spell_id` = 192262);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(101518, 200255, 3, 1),
(97142, 191827, 1, 0),
(100549, 192262, 1, 1),
(100543, 192262, 1, 1),
(100548, 192262, 1, 1),
(100545, 192262, 1, 1);

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=97069 AND `ID`=1) OR (`CreatureID`=96847 AND `ID`=1) OR (`CreatureID`=92718 AND `ID`=1) OR (`CreatureID`=98713 AND `ID`=1) OR (`CreatureID`=98714 AND `ID`=1) OR (`CreatureID`=97303 AND `ID`=1) OR (`CreatureID`=97965 AND `ID`=1) OR (`CreatureID`=97964 AND `ID`=1) OR (`CreatureID`=97244 AND `ID`=1) OR (`CreatureID`=97962 AND `ID`=1) OR (`CreatureID`=97959 AND `ID`=1) OR (`CreatureID`=98712 AND `ID`=1) OR (`CreatureID`=97297 AND `ID`=1) OR (`CreatureID`=97971 AND `ID`=1) OR (`CreatureID`=99045 AND `ID`=1) OR (`CreatureID`=97459 AND `ID`=1) OR (`CreatureID`=99787 AND `ID`=1) OR (`CreatureID`=96562 AND `ID`=1) OR (`CreatureID`=98165 AND `ID`=1) OR (`CreatureID`=98160 AND `ID`=1) OR (`CreatureID`=108409 AND `ID`=1) OR (`CreatureID`=108408 AND `ID`=1) OR (`CreatureID`=98158 AND `ID`=1) OR (`CreatureID`=96277 AND `ID`=1) OR (`CreatureID`=96402 AND `ID`=1) OR (`CreatureID`=103432 AND `ID`=1) OR (`CreatureID`=97057 AND `ID`=1) OR (`CreatureID`=98711 AND `ID`=1) OR (`CreatureID`=99423 AND `ID`=1) OR (`CreatureID`=99419 AND `ID`=1) OR (`CreatureID`=100545 AND `ID`=1) OR (`CreatureID`=100548 AND `ID`=1) OR (`CreatureID`=97881 AND `ID`=1) OR (`CreatureID`=100543 AND `ID`=1) OR (`CreatureID`=97058 AND `ID`=1) OR (`CreatureID`=97676 AND `ID`=1) OR (`CreatureID`=97770 AND `ID`=1) OR (`CreatureID`=97771 AND `ID`=1) OR (`CreatureID`=101597 AND `ID`=1) OR (`CreatureID`=96561 AND `ID`=1) OR (`CreatureID`=100549 AND `ID`=1) OR (`CreatureID`=97014 AND `ID`=1) OR (`CreatureID`=101317 AND `ID`=1) OR (`CreatureID`=96499 AND `ID`=1) OR (`CreatureID`=97601 AND `ID`=1) OR (`CreatureID`=96473 AND `ID`=1) OR (`CreatureID`=97597 AND `ID`=1) OR (`CreatureID`=102726 AND `ID`=1) OR (`CreatureID`=96494 AND `ID`=1) OR (`CreatureID`=96441 AND `ID`=1) OR (`CreatureID`=97598 AND `ID`=1) OR (`CreatureID`=96493 AND `ID`=1) OR (`CreatureID`=101397 AND `ID`=1) OR (`CreatureID`=101788 AND `ID`=1) OR (`CreatureID`=101790 AND `ID`=1) OR (`CreatureID`=96504 AND `ID`=1) OR (`CreatureID`=96502 AND `ID`=1) OR (`CreatureID`=101789 AND `ID`=1) OR (`CreatureID`=101787 AND `ID`=1) OR (`CreatureID`=96501 AND `ID`=1) OR (`CreatureID`=96500 AND `ID`=1) OR (`CreatureID`=96436 AND `ID`=1) OR (`CreatureID`=98157 AND `ID`=1) OR (`CreatureID`=97034 AND `ID`=1) OR (`CreatureID`=102906 AND `ID`=1) OR (`CreatureID`=96653 AND `ID`=1) OR (`CreatureID`=90247 AND `ID`=1) OR (`CreatureID`=102905 AND `ID`=1) OR (`CreatureID`=102907 AND `ID`=1) OR (`CreatureID`=95450 AND `ID`=1) OR (`CreatureID`=97599 AND `ID`=1) OR (`CreatureID`=95449 AND `ID`=1) OR (`CreatureID`=95447 AND `ID`=1) OR (`CreatureID`=99920 AND `ID`=1) OR (`CreatureID`=96650 AND `ID`=1) OR (`CreatureID`=96253 AND `ID`=1) OR (`CreatureID`=93127 AND `ID`=1) OR (`CreatureID`=96655 AND `ID`=1) OR (`CreatureID`=96420 AND `ID`=1) OR (`CreatureID`=97600 AND `ID`=1) OR (`CreatureID`=96652 AND `ID`=1) OR (`CreatureID`=113924 AND `ID`=1) OR (`CreatureID`=113927 AND `ID`=1) OR (`CreatureID`=102910 AND `ID`=1) OR (`CreatureID`=96654 AND `ID`=1) OR (`CreatureID`=96230 AND `ID`=1) OR (`CreatureID`=93693 AND `ID`=1) OR (`CreatureID`=96231 AND `ID`=1) OR (`CreatureID`=102724 AND `ID`=1) OR (`CreatureID`=97604 AND `ID`=1) OR (`CreatureID`=96931 AND `ID`=1) OR (`CreatureID`=96930 AND `ID`=1) OR (`CreatureID`=97603 AND `ID`=1) OR (`CreatureID`=93716 AND `ID`=1) OR (`CreatureID`=99915 AND `ID`=1) OR (`CreatureID`=98611 AND `ID`=1) OR (`CreatureID`=93221 AND `ID`=1) OR (`CreatureID`=102714 AND `ID`=1) OR (`CreatureID`=95046 AND `ID`=1) OR (`CreatureID`=94654 AND `ID`=1) OR (`CreatureID`=93759 AND `ID`=1) OR (`CreatureID`=99917 AND `ID`=1) OR (`CreatureID`=93105 AND `ID`=1) OR (`CreatureID`=96400 AND `ID`=1) OR (`CreatureID`=93112 AND `ID`=2) OR (`CreatureID`=94705 AND `ID`=1) OR (`CreatureID`=94704 AND `ID`=1) OR (`CreatureID`=100982 AND `ID`=1) OR (`CreatureID`=93112 AND `ID`=1) OR (`CreatureID`=97592 AND `ID`=1) OR (`CreatureID`=94410 AND `ID`=1) OR (`CreatureID`=99916 AND `ID`=1) OR (`CreatureID`=98229 AND `ID`=1) OR (`CreatureID`=98354 AND `ID`=1) OR (`CreatureID`=98622 AND `ID`=1) OR (`CreatureID`=98456 AND `ID`=1) OR (`CreatureID`=98460 AND `ID`=1) OR (`CreatureID`=99919 AND `ID`=1) OR (`CreatureID`=98458 AND `ID`=1) OR (`CreatureID`=98484 AND `ID`=1) OR (`CreatureID`=98486 AND `ID`=1) OR (`CreatureID`=93011 AND `ID`=1) OR (`CreatureID`=98228 AND `ID`=1) OR (`CreatureID`=98227 AND `ID`=1) OR (`CreatureID`=99918 AND `ID`=1) OR (`CreatureID`=98292 AND `ID`=1) OR (`CreatureID`=98290 AND `ID`=1) OR (`CreatureID`=97712 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(97069, 1, 124026, 0, 0), -- Wrath-Lord Lekos
(96847, 1, 97129, 0, 95791), -- Drelanim Whisperwind
(92718, 1, 32425, 0, 0), -- Maiev Shadowsong
(98713, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(98714, 1, 128359, 0, 128371), -- Cyana Nightglaive
(97303, 1, 128359, 0, 128371), -- Kayn Sunfury
(97965, 1, 122430, 0, 0), -- Allari the Souleater
(97964, 1, 128360, 0, 128370), -- Jace Darkweaver
(97244, 1, 128359, 0, 128371), -- Kayn Sunfury
(97962, 1, 122430, 0, 0), -- Allari the Souleater
(97959, 1, 128360, 0, 128370), -- Jace Darkweaver
(98712, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(97297, 1, 128359, 0, 128371), -- Cyana Nightglaive
(97971, 1, 128360, 0, 128370), -- Jace Darkweaver Clone
(99045, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(97459, 1, 17383, 0, 0), -- Battlelord Gaardoun
(99787, 1, 128358, 0, 128372), -- Marius Felbane
(96562, 1, 31669, 0, 31669), -- Ashtongue Stalker
(98165, 1, 128359, 0, 128371), -- Cassiel Nightthorn
(98160, 1, 128361, 0, 128369), -- Sirius Ebonwing
(108409, 1, 127651, 0, 127651), -- Fury Champion
(108408, 1, 128360, 0, 128370), -- Ariana Fireheart
(98158, 1, 128359, 0, 128371), -- Asha Ravensong
(96277, 1, 126276, 0, 0), -- Queen's Centurion
(96402, 1, 128519, 0, 0), -- Hulking Forgefiend
(103432, 1, 126276, 0, 0), -- Queen's Centurion
(97057, 1, 138740, 0, 0), -- Overseer Brutarg
(98711, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(99423, 1, 128361, 0, 128369), -- Zaria Shadowheart
(99419, 1, 128361, 0, 128369), -- Baric Stormrunner
(100545, 1, 128358, 0, 128372), -- Demon Hunter
(100548, 1, 128358, 0, 128372), -- Demon Hunter
(97881, 1, 14535, 0, 0), -- Male Naga (scale 2.00)
(100543, 1, 128358, 0, 128372), -- Demon Hunter
(97058, 1, 138757, 0, 0), -- Count Nefarious
(97676, 1, 120477, 0, 0), -- Lady S'theno
(97770, 1, 14535, 0, 0), -- Coilskar Harpooner
(97771, 1, 28965, 0, 0), -- Coilskar Myrmidon
(101597, 1, 128358, 0, 128372), -- Tirathon Saltheril
(96561, 1, 14535, 0, 0), -- Coilskar Harpooner
(100549, 1, 128358, 0, 128372), -- Demon Hunter
(97014, 1, 138747, 0, 0), -- Vile Soulmaster
(101317, 1, 128360, 0, 128370), -- Illysanna Ravencrest
(96499, 1, 128360, 0, 128370), -- Jace Darkweaver
(97601, 1, 28133, 0, 28133), -- Shivarra Destroyer
(96473, 1, 138749, 0, 0), -- Eredar Sorcerer
(97597, 1, 138749, 0, 0), -- Eredar Sorcerer
(102726, 1, 138749, 0, 0), -- Eredar Sorcerer
(96494, 1, 124360, 0, 0), -- Felguard Butcher
(96441, 1, 124524, 0, 0), -- Fel Lord Caza
(97598, 1, 124360, 0, 0), -- Felguard Butcher
(96493, 1, 124360, 0, 0), -- Felguard Butcher
(101397, 1, 128359, 0, 128371), -- Cailyn Paledoom
(101788, 1, 128358, 0, 128372), -- Demon Hunter
(101790, 1, 128358, 0, 128372), -- Demon Hunter
(96504, 1, 28133, 0, 28133), -- Shivarra Destroyer
(96502, 1, 28965, 0, 0), -- Coilskar Myrmidon
(101789, 1, 128358, 0, 128372), -- Demon Hunter
(101787, 1, 128358, 0, 128372), -- Demon Hunter
(96501, 1, 29685, 0, 0), -- Ashtongue Mystic
(96500, 1, 17383, 0, 0), -- Ashtongue Warrior
(96436, 1, 128360, 0, 128370), -- Jace Darkweaver
(98157, 1, 128359, 0, 128371), -- Lyana Darksorrow
(97034, 1, 127651, 0, 127651), -- Fury Champion
(102906, 1, 31669, 0, 31669), -- Ashtongue Stalker
(96653, 1, 128358, 0, 128372), -- Izal Whitemoon
(90247, 1, 17383, 0, 0), -- Battlelord Gaardoun
(102905, 1, 29685, 0, 0), -- Ashtongue Mystic
(102907, 1, 17383, 0, 0), -- Ashtongue Warrior
(95450, 1, 31669, 0, 31669), -- Ashtongue Stalker
(97599, 1, 128358, 0, 128372), -- Demon Hunter
(95449, 1, 29685, 0, 0), -- Ashtongue Mystic
(95447, 1, 17383, 0, 0), -- Ashtongue Warrior
(99920, 1, 128361, 0, 128369), -- Sevis Brightflame
(96650, 1, 128361, 0, 128369), -- Falara Nightsong
(96253, 1, 28133, 0, 28133), -- Shivarra Destroyer
(93127, 1, 128359, 0, 128371), -- Kayn Sunfury
(96655, 1, 122430, 0, 0), -- Allari the Souleater
(96420, 1, 128359, 0, 128371), -- Cyana Nightglaive
(97600, 1, 128358, 0, 128372), -- Demon Hunter
(96652, 1, 128361, 0, 128369), -- Mannethrel Darkstar
(113924, 1, 128358, 0, 128372), -- Illidari Starr
(113927, 1, 128358, 0, 128372), -- Illidari Kilbride
(102910, 1, 28965, 0, 0), -- Coilskar Myrmidon
(96654, 1, 128361, 0, 128369), -- Belath Dawnblade
(96230, 1, 28965, 0, 0), -- Coilskar Myrmidon
(93693, 1, 120477, 0, 0), -- Lady S'theno
(96231, 1, 14535, 0, 0), -- Coilskar Harpooner
(102724, 1, 138747, 0, 0), -- Vile Soulmaster
(97604, 1, 126276, 0, 0), -- Queen's Centurion
(96931, 1, 128358, 0, 128372), -- Demon Hunter
(96930, 1, 128358, 0, 128372), -- Demon Hunter
(97603, 1, 138751, 0, 138751), -- Doom Slayer
(93716, 1, 138751, 0, 138751), -- Doom Slayer
(99915, 1, 128361, 0, 128369), -- Sevis Brightflame
(98611, 1, 50043, 0, 0), -- Doomguard Eradicator
(93221, 1, 138481, 0, 0), -- Doom Commander Beliash
(102714, 1, 138749, 0, 0), -- Eredar Summoner
(95046, 1, 138749, 0, 0), -- Eredar Summoner
(94654, 1, 138754, 0, 0), -- Doomguard Eradicator
(93759, 1, 128360, 0, 128370), -- Jace Darkweaver
(99917, 1, 128361, 0, 128369), -- Sevis Brightflame
(93105, 1, 128093, 0, 0), -- Inquisitor Baleful
(96400, 1, 128521, 0, 0), -- Mo'arg Brute
(93112, 2, 136805, 0, 0), -- Felguard Sentry
(94705, 1, 128358, 0, 128372), -- Demon Hunter
(94704, 1, 128358, 0, 128372), -- Demon Hunter
(100982, 1, 128369, 0, 128369), -- Sevis Brightflame
(93112, 1, 136788, 0, 0), -- Felguard Sentry
(97592, 1, 136788, 0, 0), -- Felguard Sentry
(94410, 1, 122430, 0, 0), -- Allari the Souleater
(99916, 1, 128361, 0, 128369), -- Sevis Brightflame
(98229, 1, 128359, 0, 128371), -- Kayn Sunfury
(98354, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(98622, 1, 128521, 0, 0), -- Mo'arg Brute
(98456, 1, 122430, 0, 0), -- Allari the Souleater
(98460, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(99919, 1, 128361, 0, 128369), -- Sevis Brightflame
(98458, 1, 128360, 0, 128370), -- Jace Darkweaver
(98484, 1, 128521, 0, 0), -- Mo'arg Brute
(98486, 1, 127651, 0, 0), -- Wrath Warrior
(93011, 1, 128359, 0, 128371), -- Kayn Sunfury
(98228, 1, 128360, 0, 128370), -- Jace Darkweaver
(98227, 1, 122430, 0, 0), -- Allari the Souleater
(99918, 1, 128361, 0, 128369), -- Sevis Brightflame
(98292, 1, 128359, 0, 128371), -- Kor'vas Bloodthorn
(98290, 1, 128359, 0, 128371), -- Cyana Nightglaive
(97712, 1, 127651, 0, 0); -- Wrath Warrior

UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2500, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=97069; -- Wrath-Lord Lekos
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=2643, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=96847; -- Drelanim Whisperwind
UPDATE `creature_template` SET `faction`=31, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags2`=2048 WHERE `entry`=101648; -- Vault Roach
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=100168; -- Ward of the Hunters
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=103658; -- Kayn's Cell
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=103655; -- Altruis's Cell
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=190, `npcflag`=3, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=92718; -- Maiev Shadowsong
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98714; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98713; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97965; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97964; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=97303; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100333; -- Skittering Broodling
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100334; -- Tyranna's Spawn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=97297; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=98712; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100243; -- Wicked Crawler
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=536904448, `unit_flags2`=2049 WHERE `entry`=100244; -- Aranasi Maiden
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=101760; -- "The Keystone" Make Your Way Downstairs Quest Kill Credit
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=97962; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=97244; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=99045; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=96768; -- Broken
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=100703; -- Leeching Spider
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200 WHERE `entry`=100717; -- Spider Egg
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2804, `npcflag`=16777216, `speed_walk`=1.2, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=97459; -- Battlelord Gaardoun
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=99787; -- Marius Felbane
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=18432 WHERE `entry`=101947; -- Doom Fortress Stabilizer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_walk`=1.111112, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2097152, `HoverHeight`=12.5 WHERE `entry`=97059; -- King Voras
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=536904448, `unit_flags2`=33556481 WHERE `entry`=96562; -- Ashtongue Stalker
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=101781; -- Spider Scene Stalker Controller
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97607; -- Priestess of Dementia
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97606; -- Priestess of Delight
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_walk`=1.111112, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480, `HoverHeight`=5 WHERE `entry`=97706; -- Fel Weaver
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96563; -- Priestess of Delight
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=97959; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98165; -- Cassiel Nightthorn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_walk`=0.6, `speed_run`=0.2142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555216, `unit_flags2`=67110912 WHERE `entry`=101321; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98160; -- Sirius Ebonwing
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=108409; -- Fury Champion
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=108408; -- Ariana Fireheart
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96564; -- Priestess of Dementia
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=93764; -- Shivan
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67143680 WHERE `entry`=101320; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_walk`=0.6, `speed_run`=0.2142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554944, `unit_flags2`=67110912 WHERE `entry`=101318; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98158; -- Asha Ravensong
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96277; -- Queen's Centurion
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16384, `unit_flags2`=33556480 WHERE `entry`=96402; -- Hulking Forgefiend
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103432; -- Queen's Centurion
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200 WHERE `entry`=100257; -- Fel Geyser
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=90, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98986; -- Prolifica
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16448, `unit_flags2`=4196352 WHERE `entry`=97057; -- Overseer Brutarg
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98711; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=103429; -- "The Imp Mother's Tome" Cave Entrance POI Quest Kill Credit
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=99735; -- Horned Minion
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=768, `unit_flags2`=2099200 WHERE `entry`=100504; -- Aranasi Maiden
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=99423; -- Zaria Shadowheart
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=99419; -- Baric Stormrunner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=295424, `unit_flags2`=33556480 WHERE `entry`=100545; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=97704; -- Well of Souls
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=295424, `unit_flags2`=33556480 WHERE `entry`=100548; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=14, `speed_walk`=0.888, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97769; -- Mardum Executioner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=295424, `unit_flags2`=33556480 WHERE `entry`=100543; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97772; -- Coilskar Sea-Caller
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=97058; -- Count Nefarious
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=97881; -- Male Naga (scale 2.00)
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_walk`=1.2, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=97370; -- General Volroth
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97770; -- Coilskar Harpooner
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=14, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=67160064 WHERE `entry`=97382; -- Soul Harvester
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=96767; -- Female Naga (scale 1.75)
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97771; -- Coilskar Myrmidon
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101597; -- Tirathon Saltheril
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96561; -- Coilskar Harpooner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=295424, `unit_flags2`=33556480 WHERE `entry`=100549; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96280; -- Volatile Minion
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_walk`=0.888, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=33556480, `VehicleId`=4318 WHERE `entry`=96279; -- Mardum Executioner
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67143680 WHERE `entry`=93280; -- Caged Soul
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101317; -- Illysanna Ravencrest
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=97014; -- Vile Soulmaster
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33280, `unit_flags2`=33556480 WHERE `entry`=97425; -- Matron Mother Malevolence
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2804, `speed_run`=0.9920629, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=97676; -- Lady S'theno
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97601; -- Shivarra Destroyer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96499; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200 WHERE `entry`=100061; -- Axe Throw Stalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96473; -- Eredar Sorcerer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97597; -- Eredar Sorcerer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=102726; -- Eredar Sorcerer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96494; -- Felguard Butcher
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=96441; -- Fel Lord Caza
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97598; -- Felguard Butcher
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96493; -- Felguard Butcher
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101397; -- Cailyn Paledoom
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101790; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101788; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96503; -- Coilskar Sea-Caller
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101789; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101787; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96504; -- Shivarra Destroyer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96502; -- Coilskar Myrmidon
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96501; -- Ashtongue Mystic
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2804, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96500; -- Ashtongue Warrior
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=96436; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98157; -- Lyana Darksorrow
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=99759; -- Fiendish Creeper
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=2099200 WHERE `entry`=96276; -- Legion Razorwing
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=97034; -- Fury Champion
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=97971; -- Jace Darkweaver Clone
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=102906; -- Ashtongue Stalker
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=96653; -- Izal Whitemoon
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=102907; -- Ashtongue Warrior
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102905; -- Ashtongue Mystic
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=95447; -- Ashtongue Warrior
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=35, `npcflag`=1, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=90247; -- Battlelord Gaardoun
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=95449; -- Ashtongue Mystic
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=95450; -- Ashtongue Stalker
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=4225, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=96650; -- Falara Nightsong
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=99920; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=71370752, `VehicleId`=4454 WHERE `entry`=96732; -- Legion Devastator
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96253; -- Shivarra Destroyer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96252; -- Priestess of Delight
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=94435; -- Matron Mother Malevolence
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1.031746, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=93707; -- Priestess of Dementia
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=32768 WHERE `entry`=96652; -- Mannethrel Darkstar
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=96655; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768 WHERE `entry`=96420; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=97600; -- Demon Hunter
UPDATE `creature_template` SET `faction`=35, `speed_run`=8.571428, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352 WHERE `entry`=99352; -- Legion Devastator Missile
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=97599; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=102910; -- Coilskar Myrmidon
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=113927; -- Illidari Kilbride
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=113924; -- Illidari Starr
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=96654; -- Belath Dawnblade
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102908; -- Coilskar Sea-Caller
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97602; -- Burning Soulstalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96231; -- Coilskar Harpooner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96230; -- Coilskar Myrmidon
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=35, `npcflag`=1, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=93693; -- Lady S'theno
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=102724; -- Vile Soulmaster
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97604; -- Queen's Centurion
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96278; -- Burning Soulstalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=96228; -- Coilskar Sea-Caller
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `speed_run`=1, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96931; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=96930; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97603; -- Doom Slayer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=93716; -- Doom Slayer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=4497 WHERE `entry`=93802; -- Brood Queen Tyranna
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=99915; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=98611; -- Doomguard Eradicator
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_walk`=0.6, `speed_run`=0.2142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=97634; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_walk`=0.6, `speed_run`=0.2142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=97629; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=67143680 WHERE `entry`=97624; -- Spire of Woe
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=95048; -- Brood Queen Tyranna
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102714; -- Eredar Summoner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=95046; -- Eredar Summoner
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=94654; -- Doomguard Eradicator
UPDATE `creature_template` SET `AIName`='', `flags_extra`=0 WHERE `entry`=23837; -- ELM General Purpose Bunny
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2131968 WHERE `entry`=93759; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2804, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2099200 WHERE `entry`=95049; -- Demon Ward
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=32768 WHERE `entry`=93117; -- Izal Whitemoon
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=32768 WHERE `entry`=93230; -- Mannethrel Darkstar
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=94651; -- Hellish Imp
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048, `ScriptName`='' WHERE `entry`=99917; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `npcflag`=1, `speed_run`=0.9920629, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags2`=34816 WHERE `entry`=99914; -- Ashtongue Mystic
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=93105; -- Inquisitor Baleful
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=32768 WHERE `entry`=94400; -- Belath Dawnblade
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=96400; -- Mo'arg Brute
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=1140918272, `VehicleId`=4453 WHERE `entry`=96731; -- Legion Devastator
UPDATE `creature_template` SET `faction`=35, `speed_run`=8.571428, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=1073743872 WHERE `entry`=99351; -- Legion Devastator Missile
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=32768 WHERE `entry`=94377; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=94705; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=94704; -- Demon Hunter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=99, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101288; -- Abyssal Basilisk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=954, `speed_walk`=4, `speed_run`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33570880, `unit_flags2`=1073743872 WHERE `entry`=96159; -- Colossal Infernal
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `speed_walk`=0.888, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=95226; -- Anguish Jailer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=100982; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=320, `unit_flags2`=2048 WHERE `entry`=105316; -- Questioner Arev'naal
UPDATE `creature_template` SET `AIName`='', `flags_extra`=0 WHERE `entry`=24021; -- ELM General Purpose Bunny (scale x0.01)
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=93112; -- Felguard Sentry
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97592; -- Felguard Sentry
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=93127; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `npcflag`=16777216, `speed_walk`=0.2, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=18432 WHERE `entry`=97142; -- Fel Spreader
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=93221; -- Doom Commander Beliash
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2792, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=93115; -- Foul Felstalker
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2131968, `ScriptName`='' WHERE `entry`=94410; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags2`=2048 WHERE `entry`=101518; -- Felsaber
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=1107298304 WHERE `entry`=100510; -- The Fel Hammer
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=1140918272, `VehicleId`=4443 WHERE `entry`=93762; -- Legion Devastator
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048, `ScriptName`='' WHERE `entry`=99916; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=98621; -- Imp Mother
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=69208064, `HoverHeight`=4 WHERE `entry`=101704; -- Empowered Fel Crystal
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=35653632 WHERE `entry`=101748; -- Fel Geyser
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=98618; -- Hellish Imp
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98354; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98229; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=98622; -- Mo'arg Brute
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98456; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98460; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=99919; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2843, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=98458; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98483; -- Hellish Imp
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=90, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=37750784 WHERE `entry`=98497; -- Imp Mother
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16384, `unit_flags2`=35653632 WHERE `entry`=98484; -- Mo'arg Brute
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=1786, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98486; -- Wrath Warrior
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=2792, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98482; -- Foul Felstalker
UPDATE `creature_template` SET `faction`=35, `speed_run`=8.571428, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=1073743872 WHERE `entry`=99218; -- Legion Devastator Missile
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=99918; -- Sevis Brightflame
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=98292; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98290; -- Cyana Nightglaive
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98228; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=98227; -- Allari the Souleater
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=93011; -- Kayn Sunfury
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97712; -- Wrath Warrior
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=536871680, `unit_flags2`=2049 WHERE `entry`=97594; -- Foul Felstalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=2099200 WHERE `entry`=94744; -- Dread Felbat
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=512, `unit_flags2`=1174407168 WHERE `entry`=100161; -- Legion Devastator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=954, `speed_walk`=4, `speed_run`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16448, `unit_flags2`=1073743872 WHERE `entry`=94492; -- Colossal Infernal
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=1107298304 WHERE `entry`=98191; -- Legion Command Center
UPDATE `creature_template` SET `faction`=31, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags2`=2048 WHERE `entry`=94655; -- Soul Leech
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=99656; -- Red Broodling
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=99650; -- Thornclaw Broodling
UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2838, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33600, `unit_flags2`=2048, `VerifiedBuild`=22995 WHERE `entry`=105945; -- Sevis Brightflame

-- Custom edit due to bug fixings
UPDATE `creature_template` SET `unit_flags` = 33555200 , `flags_extra` = 130 WHERE `entry` = 101748;
UPDATE `creature_template` SET `gossip_menu_id` = 19015 WHERE `entry` = 99914;
UPDATE `creature_template` SET `gossip_menu_id` = 19017 WHERE `entry` = 99917;
UPDATE `creature_template` SET `gossip_menu_id` = 19016 WHERE `entry` = 99915; 
UPDATE `gameobject_template` SET `Data10` = 191677 WHERE `entry` = 250560; 

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14 AND `SourceGroup` IN (19015, 19017, 19016)) OR (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (19015, 19016));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,19015,27768,0,1,48,0,40379,280770,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 27768 if Objective Incomplete AND 40379 unrewarded'),
(14,19015,27768,0,1,8,0,40379,0,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 27768 if Objective Incomplete AND 40379 unrewarded'),
(14,19015,27769,0,1,48,0,40379,280770,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27769 if Objective complete OR 40379 complete/rewarded'),
(14,19015,27769,0,2,28,0,40379,0,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27769 if Objective complete OR 40379 complete/rewarded'),
(14,19015,27769,0,3,8,0,40379,0,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27769 if Objective complete OR 40379 complete/rewarded'),
(14,19017,27772,0,1,48,0,40379,280770,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 27772 if Objective Incomplete AND 40379 unrewarded'),
(14,19017,27772,0,1,8,0,40379,0,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 27772 if Objective Incomplete AND 40379 unrewarded'),
(14,19017,27773,0,1,48,0,40379,280770,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27773 if Objective complete OR 40379 complete/rewarded'),
(14,19017,27773,0,2,28,0,40379,0,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27773 if Objective complete OR 40379 complete/rewarded'),
(14,19017,27773,0,3,8,0,40379,0,0,0,0,0,'','Ashtongue Mystic to Sacrifice - Show 27773 if Objective complete OR 40379 complete/rewarded'),
(15,19015,0,0,1,48,0,40379,280770,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded'),
(15,19015,0,0,1,8,0,40379,0,0,1,0,0,'','Ashtongue Mystic to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded'),
(14,19016,27770,0,1,48,0,38765,280772,0,1,0,0,'','Sevis to Sacrifice - Show 27770 if Objective Incomplete AND 38765 unrewarded AND 40087 unrewarded'),
(14,19016,27770,0,1,8,0,38765,0,0,1,0,0,'','Sevis to Sacrifice - Show 27770 if Objective Incomplete AND 38765 unrewarded AND 40087 unrewarded'),
(14,19016,27770,0,1,8,0,40087,0,0,1,0,0,'','Sevis to Sacrifice - Show 27768 if Objective Incomplete AND 38765 unrewarded AND 40087 unrewarded'),
(14,19016,27771,0,1,28,0,40087,0,0,0,0,0,'','Sevis to Sacrifice - Show 27771 if 40379 complete/rewarded'),
(14,19016,27771,0,2,8,0,40087,0,0,0,0,0,'','Sevis to Sacrifice - Show 27771 if 40379 complete/rewarded'),
(15,19016,0,0,1,48,0,38765,280772,0,1,0,0,'','Sevis to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded'),
(15,19016,0,0,1,8,0,38765,0,0,1,0,0,'','Sevis to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded'),
(15,19016,1,0,1,48,0,38765,280772,0,1,0,0,'','Sevis to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded'),
(15,19016,1,0,1,8,0,38765,0,0,1,0,0,'','Sevis to Sacrifice - Show 19015 option if Objective Incomplete AND 40379 unrewarded');

UPDATE `creature_template` SET `ScriptName` = 'npc_allari_the_souleater_1' WHERE  `entry` = 94410;
UPDATE `creature_template` SET `ScriptName` = 'npc_sevis_brightflame_1' WHERE  `entry` = 99916;
UPDATE `creature_template` SET `ScriptName` = 'npc_sevis_brightflame_2' WHERE  `entry` = 99917;
UPDATE `creature_template` SET `ScriptName` = 'npc_sevis_brightflame_3' WHERE  `entry` = 99915;
UPDATE `creature_template` SET `ScriptName` = 'npc_ashtongue_mystic_sacrifice' WHERE `entry` = 99914;
UPDATE `creature_template` SET `ScriptName` = 'npc_inquisitor_baleful' WHERE  `entry` = 93105;
UPDATE `creature_template` SET `ScriptName` = 'npc_doom_commander_beliash' WHERE `entry` = 93221; 
UPDATE `creature_template` SET `InhabitType`='5' WHERE  `entry`=94744;

-- Quest related stuff
DELETE FROM `creature_queststarter` WHERE (`id` = 93011 AND `quest` = 40077) OR (`id` = 98229 AND `quest` = 40378) OR (`id` = 94410 AND `quest` = 39049) OR (`id` = 94410 AND `quest` = 38759) OR (`id` = 100982 AND `quest` = 40379);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
(93011, 40077),
(98229, 40378),
(94410, 39049),
(94410, 38759),
(100982, 40379);
DELETE FROM `creature_queststarter` WHERE `id` = 93759;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES 
(93759, 39050),
(93759, 38765),
(93759, 38766);

DELETE FROM `quest_template_addon` WHERE `ID` IN (38759, 39049, 40379);
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, `ExclusiveGroup`) VALUES 
(38759, 39050, -38759),
(39049, 39050, -38759),
(40379, 39050, -38759);

INSERT INTO `quest_template_addon` (`ID`) VALUES (39050);
