-- Update Barak Kodobane
DELETE FROM `creature_template_difficulty` WHERE `entry` = 3394 AND `DifficultyID` = 0 AND `ContentTuningID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0, `ContentTuningID`=3, `StaticFlags1`=0x0, `VerifiedBuild`=56819 WHERE (`Entry`=3394 AND `DifficultyID`=1); -- 3394 (Barak Kodobane) - 
