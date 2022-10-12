UPDATE `creature_template` SET `flags_extra` = 128, `ScriptName` = 'npc_blood_wave_stalker' WHERE entry = 132398;
UPDATE `creature_template` SET `ScriptName` = 'npc_blood_effigy' WHERE entry = 134701;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=138740 AND `ID`=1) OR (`CreatureID`=134284 AND `ID`=1) OR (`CreatureID`=133836 AND `ID`=1) OR (`CreatureID`=131318 AND `ID`=1) OR (`CreatureID`=133663 AND `ID`=1) OR (`CreatureID`=131492 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(138740, 1, 3366, 0, 0, 0, 0, 0, 0, 0, 0), -- 138740
(134284, 1, 156985, 0, 0, 0, 0, 0, 0, 0, 0), -- 134284
(133836, 1, 156942, 0, 0, 0, 0, 0, 0, 0, 0), -- 133836
(131318, 1, 159652, 0, 0, 0, 0, 0, 0, 0, 0), -- 131318
(133663, 1, 153589, 0, 0, 0, 0, 0, 0, 0, 0), -- 133663
(131492, 1, 154977, 0, 0, 0, 0, 0, 0, 0, 0); -- 131492

DELETE FROM `spell_script_names` WHERE `spell_id` IN (264603, 260879, 261498);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(264603, 'spell_blood_mirror'),
(261498, 'spell_creeping_rot'),
(260879, 'spell_blood_bolt');

DELETE FROM `creature_text` WHERE `CreatureID` = 131318;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(131318, 0, 0, 'For de glory of G\'huun!', 14, 0, 100, 0, 0, 101028, 148173, 0, 'Elder Leaxa'),
(131318, 1, 0, 'Rot and wither!', 14, 0, 100, 0, 0, 101026, 148211, 0, 'Elder Leaxa'),
(131318, 2, 0, 'G\'huun be everywhere!', 14, 0, 100, 0, 0, 101025, 148212, 0, 'Elder Leaxa'),
(131318, 2, 1, 'G\'huun\'s power take you!', 14, 0, 100, 0, 0, 101027, 148180, 0, 'Elder Leaxa'),
(131318, 2, 2, 'Praise be G\'huun!', 14, 0, 100, 0, 0, 101032, 148177, 0, 'Elder Leaxa'),
(131318, 3, 0, '|TINTERFACE\\ICONS\\INV_TikiMan2_Bloodtroll.blp:20|t Elder Leaxa begins to cast |cFFF00000|Hspell:264603|h[Blood Mirror]|h|r!', 41, 0, 100, 0, 0, 101025, 157334, 0, 'Elder Leaxa'),
(131318, 4, 0, 'My blood for G\'huun...', 14, 0, 100, 0, 0, 101030, 148175, 0, 'Elder Leaxa'),
(131318, 5, 0, 'Time for de sacrifice!', 14, 0, 100, 0, 0, 101029, 148174, 0, 'Elder Leaxa'),
(131318, 5, 1, 'G\'huun, accept dis offering of flesh and bone.', 14, 0, 100, 0, 0, 101032, 148179, 0, 'Elder Leaxa'),
(131318, 6, 0, 'My power grows!', 14, 0, 100, 0, 0, 101031, 148176, 0, 'Elder Leaxa');
