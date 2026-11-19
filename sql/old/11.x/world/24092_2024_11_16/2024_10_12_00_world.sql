-- Update Kreenig Snarlsnout
DELETE FROM `creature_template_difficulty` WHERE `entry` = 3438 AND `DifficultyID` = 0 AND `ContentTuningID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0, `ContentTuningID`=3, `StaticFlags1`=0x0, `VerifiedBuild`=56819 WHERE (`Entry`=3438 AND `DifficultyID`=1); -- 3438 (Kreenig Snarlsnout) - 

-- Update Razormane Defender
DELETE FROM `creature_template_difficulty` WHERE `entry` = 3266 AND `DifficultyID` = 0 AND `ContentTuningID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0, `ContentTuningID`=3, `StaticFlags1`=0x0, `VerifiedBuild`=56819 WHERE (`Entry`=3266 AND `DifficultyID`=1); -- 3266 (Razormane Defender) - 

-- Update Razormane Thornweaver
DELETE FROM `creature_template_difficulty` WHERE `entry` = 3268 AND `DifficultyID` = 0 AND `ContentTuningID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0, `ContentTuningID`=3, `StaticFlags1`=0x0, `VerifiedBuild`=56819 WHERE (`Entry`=3268 AND `DifficultyID`=1); -- 3268 (Razormane Thornweaver) - 
