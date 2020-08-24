UPDATE `creature_template_movement` SET `Ground`= 1, `Flight`= 0 WHERE `CreatureId` IN (37955, 38434, 38435, 38436);
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (37955, 38434, 38435, 38436);
