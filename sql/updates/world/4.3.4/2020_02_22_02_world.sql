-- Interrogator Vishas
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x800;
UPDATE `creature_template_addon` SET `auras`= '8981' WHERE `entry`= 3983;

-- Bloodmage Thalnos
UPDATE `creature_template` SET `flags_extra`= 0 WHERE `entry`= 4543;
