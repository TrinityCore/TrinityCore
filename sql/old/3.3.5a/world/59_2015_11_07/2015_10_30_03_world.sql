--
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0 WHERE `DisplayID` IN (16046, 3258, 14533);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (22434,22435,22447,22383);
