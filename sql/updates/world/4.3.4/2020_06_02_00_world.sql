UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (39294, 44828, 44829, 44826, 44653);
UPDATE `creature_template_movement` SET `Flight`= 0, `Ground`= 1 WHERE `CreatureId` IN (39294, 44828, 44829, 44826, 44653);

UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (46221, 46218, 46212, 46215);
UPDATE `creature_template_movement` SET `Flight`= 0, `Ground`= 1 WHERE `CreatureId` IN (46221, 46218, 46212, 46215);

UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (46222, 46219, 46213, 46216);
UPDATE `creature_template_movement` SET `Flight`= 0, `Ground`= 1 WHERE `CreatureId` IN (46222, 46219, 46213, 46216);

UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (46223, 46220, 46214, 46217);
UPDATE `creature_template_movement` SET `Flight`= 0, `Ground`= 1 WHERE `CreatureId` IN (46223, 46220, 46214, 46217);
