-- 
UPDATE `creature_template_movement` SET `Ground`=1, `Swim`=0, `Flight`=0, `Rooted`=1 WHERE `CreatureId`=29747;
UPDATE `creature_template_movement` SET `Rooted`=0 WHERE `CreatureId` IN (14697, 18695, 30475, 31424);
