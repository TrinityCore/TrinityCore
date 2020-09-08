-- Disable movement flag updates for Grauf and let script handle them
UPDATE `creature_template` SET `flags_extra` = `flags_extra`| 0x200 WHERE `entry`=26893;
-- Disable movement flag updates for Blood-Queen Lana'thel
UPDATE `creature_template_movement` SET `Ground`= 1, `Flight`= 0 WHERE `CreatureId` IN (37955, 38434, 38435, 38436);
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (37955, 38434, 38435, 38436);
-- Disable movement flag updates for Malygos
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (28859, 31734);
-- Disable movement flag updates for Razorscale
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (33186, 33724);
UPDATE `creature_template_movement` SET `Ground`= 1 WHERE `CreatureId` IN (33186, 33724);
-- Disable movement flag updates for Enslaved Proto-Drake
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (24083, 31669);
UPDATE `creature_template_movement` SET `Ground`= 1 WHERE `CreatureId` IN (24083, 31669);
-- Disable movement flag updates for Enslaved Netherwing Drake
UPDATE `creature_template` SET `flags_extra` = `flags_extra`| 0x200 WHERE `entry`=21722;
