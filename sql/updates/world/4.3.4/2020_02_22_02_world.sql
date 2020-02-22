-- Interrogator Vishas
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x800 WHERE `entry`= 3983;
UPDATE `creature_template_addon` SET `auras`= '8981' WHERE `entry`= 3983;
