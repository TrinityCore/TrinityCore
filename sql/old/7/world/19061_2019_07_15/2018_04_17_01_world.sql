-- 
UPDATE `creature` SET `position_x`=-8693.42, `position_y`=843.6111, `position_z`=98.79181, `orientation`= 2.68316 WHERE `guid`=313860;
DELETE FROM `creature` WHERE `guid` IN (252243,313862,452751,452752,452753,452754,452755,452756,452757,452758,452759,452760,452761,452762,452763,452765,452766,452767,452768,452769,452770);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(452751, 113211, 0, 4922, 5470, 1, 169, 0, 0, 0, -8625.368, 935.8912, 99.41483, 0.8330327, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Officer Fairbanks (Area: Victor's Point - Difficulty: 0) (Auras: 221508 - The Imposter: Stormwind City Guard Stealth Detection Circle, 18950 - Invisibility and Stealth Detection)
(452752, 68980, 0, 4922, 5470, 1, 169, 0, 0, 0, -8702.382, 841.0364, 98.76855, 0.6576703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Voidbinder Sturzah (Area: Victor's Point - Difficulty: 0)
(452753, 93223, 0, 4922, 5470, 1, 169, 0, 0, 0, -8902.417, 995.1979, 120.7264, 3.602771, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Generic Stalker (Area: Victor's Point - Difficulty: 0) (Auras: 224469 - Fel Fire)
(452754, 85816, 0, 4922, 5470, 1, 169, 0, 0, 0, -8975.936, 888.1059, 106.2309, 0.8687152, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elizabeth (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452755, 84749, 0, 4922, 5470, 1, 169, 0, 0, 0, -8976.521, 889.1042, 106.125, 0.5294801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Jenna (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452756, 85817, 0, 4922, 5470, 1, 169, 0, 0, 0, -8974.41, 887.1719, 106.3247, 1.372927, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naomi (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452757, 85818, 0, 4922, 5470, 1, 169, 0, 0, 0, -8975.082, 887.5174, 106.3229, 1.165539, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Jeremy (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452758, 85819, 0, 4922, 5470, 1, 169, 0, 0, 0, -8973.306, 886.9375, 106.2905, 1.671063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Daniel (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452759, 82564, 0, 4922, 5470, 1, 169, 0, 0, 0, -8973.464, 891.0452, 106.0187, 4.033627, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Archmage Nakada (Area: Victor's Point - Difficulty: 0)
(452760, 84745, 0, 4922, 5470, 1, 169, 0, 0, 0, -8977.429, 890.0712, 105.9931, 0.182385, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sammy (Area: Victor's Point - Difficulty: 0) (Auras: 169394 - Wizard-in-Training Hat)
(452761, 84751, 0, 4922, 5470, 1, 169, 0, 0, 0, -8972.004, 890.2465, 105.9823, 3.651412, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Linda (Area: Victor's Point - Difficulty: 0)
(452762, 89174, 0, 4922, 5470, 1, 169, 0, 0, 0, -9001.127, 853.0364, 29.704, 0.7040998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Laluu (Area: Victor's Point - Difficulty: 0)
(452763, 85307, 0, 4922, 5470, 1, 169, 0, 0, 0, -9005.278, 872.2049, 129.7755, 4.13496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sparkbright (Area: Victor's Point - Difficulty: 0)
(452765, 112912, 0, 4922, 5470, 1, 169, 0, 0, 0, -8779.915, 641.6667, 97.23317, 1.847362, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Martin Ocejo (Area: Victor's Point - Difficulty: 0)
(452766, 61834, 0, 4922, 5470, 1, 169, 0, 0, 0, -8797.476, 597.993, 97.94926, 1.22841, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Alyn Black (Area: Victor's Point - Difficulty: 0) (Auras: 79849 - Molten Armor)
(452767, 61836, 0, 4922, 5470, 1, 169, 0, 0, 0, -8797.326, 599.467, 97.8295, 4.605575, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Moni Widdlesprock (Area: Victor's Point - Difficulty: 0) (Auras: 79849 - Molten Armor)
(452768, 61838, 0, 4922, 5470, 1, 169, 0, 0, 0, -8743.879, 581.7416, 97.64633, 5.109339, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gavin Marlsbury (Area: Victor's Point - Difficulty: 0) (Auras: 86603 - Stealth)
(452769, 71526, 0, 4922, 5470, 1, 169, 0, 0, 0, -8573.392, 687.3098, 97.11234, 2.230452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elizabeth Birdsong (Area: Victor's Point - Difficulty: 0)
(452770, 61841, 0, 4922, 5470, 1, 169, 0, 0, 0, -8555.899, 476.2014, 104.742, 3.419646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Brunn Goldenmug (Area: Victor's Point - Difficulty: 0)
(252243, 29712, 0, 4922, 5470, 1, 169, 0, 0, 0, -8641.44433, 951.4826, 98.2429, 4.897644, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Stormwind Harbor Guard (Area: Victor's Point - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` IN (252243,313862,452751,452752,452753,452754,452755,452756,452757,452758,452759,452760,452761,452762,452763,452765,452766,452767,452768,452769,452770);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(452751, 0, 0, 0, 257, 0, '221508 18950'), -- Officer Fairbanks - 221508 - The Imposter: Stormwind City Guard Stealth Detection Circle, 18950 - Invisibility and Stealth Detection
(452752, 0, 0, 0, 1, 0, ''), -- Voidbinder Sturzah
(452753, 0, 0, 0, 1, 0, '224469'), -- Generic Stalker - 224469 - Fel Fire
(452754, 0, 0, 0, 1, 0, '169394'), -- Elizabeth - 169394 - Wizard-in-Training Hat
(452755, 0, 0, 0, 1, 0, '169394'), -- Jenna - 169394 - Wizard-in-Training Hat
(452756, 0, 0, 0, 1, 0, '169394'), -- Naomi - 169394 - Wizard-in-Training Hat
(452757, 0, 0, 0, 1, 0, '169394'), -- Jeremy - 169394 - Wizard-in-Training Hat
(452758, 0, 0, 0, 1, 0, '169394'), -- Daniel - 169394 - Wizard-in-Training Hat
(452759, 0, 0, 0, 257, 0, ''), -- Archmage Nakada
(452760, 0, 0, 0, 1, 0, '169394'), -- Sammy - 169394 - Wizard-in-Training Hat
(452761, 0, 0, 0, 257, 0, ''), -- Linda
(452762, 0, 0, 0, 257, 0, ''), -- Laluu
(452763, 0, 0, 0, 1, 0, ''), -- Sparkbright
(452765, 0, 0, 0, 256, 0, ''), -- Martin Ocejo
(452766, 0, 0, 0, 257, 0, '79849'), -- Alyn Black - 79849 - Molten Armor
(452767, 0, 0, 0, 257, 0, '79849'), -- Moni Widdlesprock - 79849 - Molten Armor
(452768, 0, 0, 0, 257, 0, '86603'), -- Gavin Marlsbury - 86603 - Stealth
(452769, 0, 0, 0, 1, 0, ''), -- Elizabeth Birdsong
(452770, 0, 0, 3, 257, 0, ''), -- Brunn Goldenmug
(252243, 0, 0, 0, 257, 0, ''); -- Stormwind Harbor Guard
