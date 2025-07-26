-- they only have one gender and it seems DisplayID_Other_Gender will be dropped in the future
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0 WHERE `DisplayID` IN (18566,18567,18568,18569);
