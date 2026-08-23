DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (26231,18168,17547,19525,17546,11502,31243,17543,18412,17535));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(26231, 0, 2, 0.970000028610229492, 0.980000019073486328, 0, 0x0, 0), -- Saragosa
(18168, 0, 1, 17.5, 15, 0, 0x800006C, 128), -- The Crone
(17547, 0, 1, 10.5, 1, 0, 0x8000068, 128), -- Tinhead
(19525, 0, 0, 1.35000002384185791, 1, 0, 0x8000000, 0), -- Stage Spotlight
(17546, 0, 1, 10.5, 1, 0, 0x800006C, 128), -- Roar
(11502, 0, 0, 330, 1, 0, 0x800006C, 128), -- Ragnaros
(31243, 0, 2, 10, 1, 0, 0x0, 0), -- Warsong Cannon
(17543, 0, 1, 10.5, 1, 0, 0x8000068, 128), -- Strawman
(18412, 0, 1, 0.699999988079071044, 1, 0, 0x8000004, 0), -- Cyclone (The Crone)
(17535, 0, 1, 17.5, 15, 0, 0x800006C, 128); -- Dorothee

UPDATE `creature_template_difficulty` SET `MinLevel`= 73, `MaxLevel`= 73 WHERE `Entry`= 26231;
UPDATE `creature_template_difficulty` SET `MinLevel`= 73, `MaxLevel`= 73 WHERE `Entry`= 18168;
UPDATE `creature_template_difficulty` SET `MinLevel`= 72, `MaxLevel`= 72 WHERE `Entry`= 17547;
UPDATE `creature_template_difficulty` SET `MinLevel`= 60, `MaxLevel`= 60 WHERE `Entry`= 19525;
UPDATE `creature_template_difficulty` SET `MinLevel`= 72, `MaxLevel`= 72 WHERE `Entry`= 17546;
UPDATE `creature_template_difficulty` SET `MinLevel`= 63, `MaxLevel`= 63 WHERE `Entry`= 11502;
UPDATE `creature_template_difficulty` SET `MinLevel`= 80, `MaxLevel`= 80 WHERE `Entry`= 31243;
UPDATE `creature_template_difficulty` SET `MinLevel`= 72, `MaxLevel`= 72 WHERE `Entry`= 17543;
UPDATE `creature_template_difficulty` SET `MinLevel`= 73, `MaxLevel`= 73 WHERE `Entry`= 18412;
UPDATE `creature_template_difficulty` SET `MinLevel`= 73, `MaxLevel`= 73 WHERE `Entry`= 17535;
