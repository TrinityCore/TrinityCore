-- Clean Up
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (32941,33333,33332,32950,33331,32946,32948,33330,32938));
DELETE FROM `creature` WHERE `id` IN (32941,33333,33332,32950,33331,32946,32948,33330,32938);

-- Factions
UPDATE `creature_template` SET `faction_A`=1665, `faction_H`=1665, `unit_flags`=32768 WHERE `entry` IN (33325,32901,33328,32901,32893,33327,32897,33326,32941,33333,33332,32950,33331,32946,32948,33330);
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN (33352,33353);

-- Unit Flags
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=32941;
UPDATE `creature_template` SET `unit_flags`=33686016, `flags_extra`=2 WHERE `entry`=30298;
UPDATE `creature_template` SET `unit_flags`=33817094 WHERE `entry`=33174;
UPDATE `creature_template` SET `unit_flags`=393220 WHERE `entry`=32938;
UPDATE `creature_template` SET `unit_flags`=33948166 WHERE `entry`=33174;
UPDATE `creature_template` SET `unit_flags`=393220 WHERE `entry` IN (33352,33353);

-- Immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=612597599 WHERE `entry` IN (32938,32926,33352,33353);
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=32845;

-- Miscelaneous
UPDATE `creature_template` SET `difficulty_entry_1`=33352, `flags_extra`=0 WHERE `entry`=32926;
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry` IN (32938,33352,33353);

-- GameObjects
UPDATE `gameobject_template` SET `flags`=4 WHERE `entry`=194173;

-- Spell Linked Spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (61990,61969,65280);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`)
VALUES
(61990,-62457,2,'Hodir - Ice Shards Immunity'),
(61990,-65370,2,'Hodir - Ice Shards Immunity'),
(65280,-62469,2,'Toasty fire - Freeze imunity'),
(65280,-62039,2,'Toasty fire - Biting cold imunity'),
(61969,7940,2,'Hodir - Flash Freeze immunity'),
(61990,7940,2,'Hodir - Flash Freeze immunity');
