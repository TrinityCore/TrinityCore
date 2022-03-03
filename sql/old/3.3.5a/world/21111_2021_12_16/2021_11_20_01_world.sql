-- Set proper modelid
UPDATE `creature_template` SET `modelid1`=31248, `modelid2`=31007 WHERE `entry`=38545; -- Invincible
UPDATE `creature_template` SET `modelid1`=31957, `modelid2`=31958 WHERE `entry`=40625; -- Celestial Steed
-- Invincible wrong otherGender displayID
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0 WHERE `DisplayID` IN (31007,31248);
