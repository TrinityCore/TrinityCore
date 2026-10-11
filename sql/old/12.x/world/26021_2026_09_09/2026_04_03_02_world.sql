DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID` IN (1, 2) AND `Entry` IN (209791,209603, 208745));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(209791, 1, 10, 1, 1, 240104, 0x200068, 128, 0), -- Wax Chunk
(209603, 1, 10, 1, 1, 239912, 0x200068, 128, 0), -- Wax Statue
(208745, 1, 10, 35, 1, 237981, 0x200068, 128, 0), -- The Candle King
(209791, 2, 10, 1, 1, 240104, 0x200068, 128, 0), -- Wax Chunk
(209603, 2, 10, 1, 1, 239912, 0x200068, 128, 0), -- Wax Statue
(208745, 2, 10, 35, 1, 237981, 0x200068, 128, 0); -- The Candle King

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=66709 WHERE (`Entry`=209791 AND `DifficultyID`=1); -- 209791 (Wax Chunk) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=66709 WHERE (`Entry`=209603 AND `DifficultyID`=1); -- 209603 (Wax Statue) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=66709 WHERE (`Entry`=208745 AND `DifficultyID`=1); -- 208745 (The Candle King) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2720, `VerifiedBuild`=66709 WHERE (`Entry`=209791 AND `DifficultyID`=2); -- 209791 (Wax Chunk) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2720, `VerifiedBuild`=66709 WHERE (`Entry`=209603 AND `DifficultyID`=2); -- 209603 (Wax Statue) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2720, `VerifiedBuild`=66709 WHERE (`Entry`=208745 AND `DifficultyID`=2); -- 208745 (The Candle King) - 
