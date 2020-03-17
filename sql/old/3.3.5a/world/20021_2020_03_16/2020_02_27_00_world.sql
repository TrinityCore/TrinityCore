-- 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` IN (29519, 29520, 29565, 29566, 29567);
DELETE FROM `creature_addon`  WHERE `guid` IN (128740);
