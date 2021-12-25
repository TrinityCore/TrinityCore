-- 
UPDATE `creature` SET `equipment_id`=1 WHERE `equipment_id`=0 AND `id` IN (SELECT `CreatureID` FROM `creature_equip_template`);
UPDATE `creature` SET `equipment_id`=0 WHERE `id` IN (19169, 794, 20102, 19171, 23784, 29519, 29520, 29565, 29566, 29567);
UPDATE `creature` SET `equipment_id`=-1 WHERE `id`=24484;
