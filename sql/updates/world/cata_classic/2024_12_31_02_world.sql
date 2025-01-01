DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (232527,232053,232051,232050,232025,229834));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(232527, 0, 0, 1, 1, 0, 0x0, 0), -- Reven
(232053, 0, 3, 1, 1, 0, 0x0, 0), -- Chaos-Born Gryphon
(232051, 0, 3, 1, 1, 0, 0x0, 0), -- Chaos-Born Hippogryph
(232050, 0, 3, 1, 1, 0, 0x0, 0), -- Chaos-Born Wind Rider
(232025, 0, 3, 1, 1, 0, 0x0, 0), -- Chaos-Born Dreadwing
(229834, 0, 3, 1, 1, 0, 0x0, 0); -- Lava Drake
