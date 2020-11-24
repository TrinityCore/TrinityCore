UPDATE `creature_template` SET `ScriptName`= 'boss_majordomo_staghelm' WHERE `entry`= 52571;
UPDATE `creature_template` SET `mingold`= 2500000, `maxgold`= 2500000 WHERE `entry` IN (52571, 53857);
UPDATE `creature_template` SET `mingold`= 6250000, `maxgold`= 6250000 WHERE `entry` IN (53856, 53858);
UPDATE `creature_template` SET `mechanic_immune_mask`= 650854271, `lootid`= `entry` WHERE `entry` IN (52571, 53857, 53856, 53858);
UPDATE `creature_template` SET `DamageModifier`= 240, `BaseVariance`= 0.665 WHERE `entry` IN (53857, 53858);
UPDATE `creature_template` SET `DamageModifier`= 200, `BaseVariance`= 0.665 WHERE `entry` IN (52571, 53856);
UPDATE `creature_template` SET `mechanic_immune_mask`= 650854271 WHERE `entry` IN (52593, 53859, 53860, 53861);
UPDATE `creature_template` SET `DamageModifier`= 240, `BaseVariance`= 0.665 WHERE `entry` IN (53859, 53861);
UPDATE `creature_template` SET `DamageModifier`= 200, `BaseVariance`= 0.665 WHERE `entry` IN (52593, 53860);
UPDATE `creature_template` SET `AIName`= 'NullCreatureAI', `RegenHealth`= 0, `mechanic_immune_mask`= 650854271, `flags_extra`= 0x100 | 0x40000000 WHERE `entry`= 53216;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_majordomo_staghelm_form_controller',
'spell_majordomo_staghelm_clump_check',
'spell_majordomo_staghelm_leaping_flames_targeting',
'spell_majordomo_staghelm_leaping_flames',
'spell_majordomo_staghelm_searing_seeds',
'spell_majordomo_staghelm_concentration',
'spell_majordomo_staghelm_burning_orbs');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(98386, 'spell_majordomo_staghelm_form_controller'),
(98399, 'spell_majordomo_staghelm_clump_check'),
(100943, 'spell_majordomo_staghelm_clump_check'),
(101165, 'spell_majordomo_staghelm_leaping_flames_targeting'),
(98476, 'spell_majordomo_staghelm_leaping_flames'),
(98450, 'spell_majordomo_staghelm_searing_seeds'),
(98229, 'spell_majordomo_staghelm_concentration'),
(98451, 'spell_majordomo_staghelm_burning_orbs');

DELETE FROM `spell_proc` WHERE `SpellId`= 98229;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `AttributesMask`) VALUES
(98229, 1 | 4, 0x2);

DELETE FROM `creature_text` WHERE `CreatureID`= 52571;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52571, 0, 0, 'Very well. Witness the raw power of my new Lord!', 14, 0, 100, 0, 0, 24464, 52195, 'Majordomo Staghelm - Intro'),
(52571, 1, 0, 'The master\'s power takes on many forms...', 14, 0, 100, 0, 0, 24483, 52430, 'Majordomo Staghelm - Scorpion Form'),
(52571, 2, 0, '|TInterface\\Icons\\inv_mount_hordescorpiong.blp:20|t%s transforms into a |c0087CEFA|Hspell:98379|h[Scorpion]|h|r!', 41, 0, 100, 0, 0, 0, 52646, 'Majordomo Staghelm - Announce Scorpion Form'),
(52571, 3, 0, 'Behold the rage of the Firelands!', 14, 0, 100, 0, 0, 24485, 52431, 'Majordomo Staghelm - Cat Form'),
(52571, 4, 0, '|TInterface\\Icons\\ability_druid_tigersroar.blp:20|t%s transforms into a |c0087CEFA|Hspell:98374|h[Cat]|h|r!', 41, 0, 100, 0, 0, 0, 52645, 'Majordomo Staghelm - Announce Cat Form'),
(52571, 5, 0, 'Blaze of Glory!', 14, 0, 100, 0, 0, 24472, 52427, 'Majordomo Staghelm - Searing Seeds'),
(52571, 6, 0, '|c00FF0000Searing Seeds begin to grow!|r', 41, 0, 100, 0, 0, 0, 52491, 'Majordomo Staghelm - Announce Searing Seeds'),
(52571, 7, 0, 'Nothing but ash!', 14, 0, 100, 0, 0, 24478, 52422, 'Majordomo Staghelm - Burning Orbs'),
(52571, 8, 0, '|c00FF0000%s summons Burning Orbs!|r', 41, 0, 100, 0, 0, 0, 52484, 'Majordomo Staghelm - Announce Burning Orbs'),
(52571, 9, 0, 'Burn.', 14, 0, 100, 0, 0, 24477, 52418, 'Majordomo Staghelm - Slay'),
(52571, 9, 1, 'Soon ALL of Azeroth will burn!', 14, 0, 100, 0, 0, 24479, 52419, 'Majordomo Staghelm - Slay'),
(52571, 9, 2, 'So much power!', 14, 0, 100, 0, 0, 24480, 52420, 'Majordomo Staghelm - Slay'),
(52571, 9, 3, 'You stood in the fire!', 14, 0, 100, 0, 0, 24481, 52421, 'Majordomo Staghelm - Slay'),
(52571, 10, 0, 'My studies... had only just begun...', 14, 0, 100, 0, 0, 24471, 52432, 'Majordomo Staghelm to Player'),
(52571, 11, 0, 'Well, well. I admire your tenacity. Baleroc stood guard over this keep for a thousand mortal lifetimes.', 14, 0, 100, 0, 0, 24473, 52415, 'Majordomo Staghelm - Baleroc Outro 1'),
(52571, 12, 0, 'But none may enter the Firelord\'s abode!', 14, 0, 100, 0, 0, 24474, 52416, 'Majordomo Staghelm - Baleroc Outro'),
(52571, 13, 0, 'Beg for mercy now, and I may yet allow you to live. Well, \"heroes?\" What is your answer?', 14, 0, 100, 0, 0, 24475, 52417, 'Majordomo Staghelm - Baleroc Outro');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 52571 AND `GroupID` IN (0, 11, 12, 13);

UPDATE `creature_model_info` SET `BoundingRadius`= 1.75, `CombatReach`= 7 WHERE `DisplayID`= 38208;
UPDATE `creature_model_info` SET `BoundingRadius`= 2, `CombatReach`= 4 WHERE `DisplayID`= 38174;
UPDATE `creature_model_info` SET `BoundingRadius`= 1.75, `CombatReach`= 7 WHERE `DisplayID`= 38747;

UPDATE `creature_template_addon` SET `auras`= '98583' WHERE `entry`= 53216;
DELETE FROM `creature` WHERE `guid`= 338806;
DELETE FROM `creature_addon` WHERE `guid`= 338806;

DELETE FROM `spell_custom_attr` WHERE `entry` IN (98474, 100212, 100213, 100214);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(98474, 0x8),
(100212, 0x8),
(100213, 0x8),
(100214, 0x8);
