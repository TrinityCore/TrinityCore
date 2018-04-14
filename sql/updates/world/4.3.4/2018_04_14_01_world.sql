-- 
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`= 45848;
DELETE FROM `creature_addon` WHERE `guid` IN (254173,254245,254264,254319,254320);
UPDATE `gameobject` SET `id`=214611 WHERE `id`=214441 AND `guid`=211082;
