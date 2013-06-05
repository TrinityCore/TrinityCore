-- Grunt Ounda should only have a female model
UPDATE `creature_model_info` SET
 `modelid_other_gender` = 0
WHERE `modelid` = 4260;
