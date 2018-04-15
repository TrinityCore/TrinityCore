UPDATE `creature_text` SET `type`=14 WHERE `type`=1; -- 9 rows changed
UPDATE `creature_text` SET `type`=16 WHERE `type`=2; -- 1 row changed

-- Fix unrelated DB errors
UPDATE `creature_template` SET `unit_class`=8 WHERE `entry`=40418;
DELETE FROM `creature_addon` WHERE `guid`=136607;
