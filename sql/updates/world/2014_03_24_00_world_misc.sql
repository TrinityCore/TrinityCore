UPDATE `creature_template` SET `faction_A`=83,`faction_H`=83 WHERE `entry`=37833; -- Sky-Reaver Korm Blackscar
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry` IN (201812,201811,201581,201580);
UPDATE `achievement_criteria_data` SET `value1`=1 WHERE `criteria_id`=12947 AND `type`=12;-- Storming the Citadel (25 player)
DELETE FROM `gameobject` WHERE `id`=201880;
