-- set some target entrys
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (59465,56312,60342);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) 
VALUES
(13, 59465, 18, 1, 30178),
(13, 56312, 18, 1, 29310),
(13, 60342, 18, 1, 29310);

-- remove mini by potent fungus
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (57055, 56648);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) 
VALUES
(57055, -56648, 1, 'Amanitar: Remove Potent Fungus'),
(56648, -57055, 1, 'Amanitar: Remove Mini');

-- mushroom scale
UPDATE `creature_template` SET `scale` = 1 WHERE `entry` IN (31461, 31462);

-- boss melee dmg
UPDATE `creature_template` SET `dmg_multiplier` = 20, `flags_extra` = `flags_extra`|1 WHERE `entry` IN (31456,31463,31464,31465,31469);

-- player clones melee dmg
UPDATE `creature_template` SET `dmg_multiplier` = 0.75 WHERE `entry` = 30625;
UPDATE `creature_template` SET `dmg_multiplier` = 1.5 WHERE `entry` = 31480;

-- triumph marken zu heldentum
UPDATE `creature_loot_template` SET `item` = 40752 WHERE `entry` IN (31456,31463,31464,31465,31469) AND `item` = 47241;

-- imunnitys
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|4|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (29308,29309,29310,29311,30385,30114,31456,31463,31464,31465,31469,31474,31473);

-- jedoga disarmable
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` &~ 4 WHERE `entry` IN (29310,31465);

UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=29308;
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=31469;
