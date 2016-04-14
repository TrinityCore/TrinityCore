-- 
UPDATE `creature_template` SET `npcflag`=32771, `AIName`='' WHERE `entry`=8888;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8888  AND `source_type` = 0;
UPDATE `creature_template_addon` SET `auras`=10848 WHERE `entry` IN (8888);
