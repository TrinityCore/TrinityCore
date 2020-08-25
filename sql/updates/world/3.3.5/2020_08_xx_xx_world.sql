-- Disable movement flag updates for Grauf and let script handle them
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry`=26893;
-- Disable movement flag updates for Blood-Queen Lana'thel
UPDATE `creature_template_movement` SET `Ground`= 1, `Flight`= 0 WHERE `CreatureId` IN (37955, 38434, 38435, 38436);
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 513 WHERE `entry` IN (37955, 38434, 38435, 38436);
-- Disable movement flag updates for Malygos
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 513 WHERE `entry` IN (28859, 31734);
