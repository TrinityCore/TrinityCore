-- 
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0 WHERE `DisplayID` IN (6485, 12829, 16389);
UPDATE `creature` SET `modelid`=0 WHERE `id`=7780;
