-- 
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=30645;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30645  AND `source_type` = 0;
UPDATE `creature_template_addon` SET `auras`=57664 WHERE `entry`=30645;
