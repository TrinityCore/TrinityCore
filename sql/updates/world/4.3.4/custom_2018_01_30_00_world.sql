-- Template Updates
-- Drahga Shadowburner
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `ScriptName`= 'boss_drahga_shadowburner' WHERE `entry`= 40319;
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `minlevel`= 87, `maxlevel`= 87, `flags_extra`= 1 WHERE `entry`= 48784;
-- Invocation of Flame Stalker
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 40355;
-- Valiona
UPDATE `creature_template` SET `InhabitType`= 5, `mechanic_immune_mask`= 667893759, `VehicleId`= 737, `flags_extra`= `flags_extra`|0x00000200, `scriptname`= 'npc_drahga_valiona' WHERE `entry`= 40320;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `InhabitType`= 7, `mechanic_immune_mask`= 667893759, `VehicleId`= 737, `flags_extra`= `flags_extra`|0x00000200 WHERE `entry`= 48801;
-- Seeping Twilight
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 40365;
-- Devouring Flames
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 131 WHERE `entry`= 48798;
-- Invoked Flaming Spirit
UPDATE `creature_template` SET `scriptname`= 'npc_drahga_invoked_flaming_spirit', `flags_extra`= `flags_extra`|0x00000100|0x00000040|0x40000000, `mechanic_immune_mask`= 1|2|4|16|32|64|128|256|512|1024|2048|4096|8192|65536|8388608, `DamageModifier`= 1  WHERE `entry`= 40357;
UPDATE `creature_template` SET  `minlevel`= 85, `maxlevel`= 85, `flags_extra`= `flags_extra`|0x00000100|0x00000040|0x40000000, `mechanic_immune_mask`= 1|2|4|16|32|64|128|256|512|1024|2048|4096|8192|65536|8388608, `DamageModifier`= 1   WHERE `entry`= 48785;

-- Correct Drahga's position from own sniff
UPDATE `creature` SET `position_x`= -436.9, `position_y`= -699.6, `position_z`= 268.767, `orientation`= 3.401 WHERE `guid`= 340123;

-- Cleanup
DELETE FROM `creature` WHERE `guid`= 340307;
DELETE FROM `creature_addon` WHERE `guid`= 340307;

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (40355, 40365, 40357, 48785);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40355, '75222 75232'),
(40365, '75318 75274'),
(40357, '75235'),
(48785, '75235');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (40320, 40319);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Valiona
(40320, 0, 0, 'If they do not kill you, I will do it myself!', 14, 0, 100, 0, 0, 18523, 47769, 'Valiona - Summoned'),
(40320, 1, 0, '|TInterface\\Icons\\spell_fire_twilightflamebreath.blp:20|t%s begins to cast |cFFFF0000|Hspell:90949|h[Devouring Flames]|h|r!', 41, 0, 100, 0, 0, 0, 48982, 'Valiona - Announce Devouring Flames'),
(40320, 2, 0, 'I will not die for you, Drahga.', 14, 0, 100, 0, 0, 18524, 47768, 'Valiona - Flee'),
-- Drahga
(40319, 1, 0, 'I will burn you from the inside out!', 14, 0, 100, 0, 0, 18610, 47760, 'Drahga Shadowburner - Aggro'),
(40319, 2, 0, '|TInterface\\Icons\\spell_fire_elemental_totem.blp:20|t%s Summons an |cFFFF6F00|Hspell:75218|h[Invocation of Flame]|h|r!', 41, 0, 100, 0, 0, 0, 40465, 'Drahga Shadowburner - Announce Invocation'),
(40319, 3, 0, 'BY FIRE BE... BURNED!', 14, 0, 100, 0, 0, 18619, 47766, 'Drahga Shadowburner - Invocation 1'),
(40319, 3, 1, 'INCINERATE THEM, MINIONS!', 14, 0, 100, 0, 0, 18616, 47765, 'Drahga Shadowburner - Invocation 2'),
(40319, 4, 0, 'Dragon, you will do as I command! Catch me!', 14, 0, 100, 22, 0, 18621, 47767, 'Drahga Shadowburner - Valiona Intro'),
(40319, 5, 0, 'You should have come better prepared!', 14, 0, 100, 0, 0, 18612, 47762, 'Drahga Shadowburner - Slay 1'),
(40319, 5, 1, 'An easy kill!', 14, 0, 100, 0, 0, 18611, 47761, 'Drahga Shadowburner - Slay 2'),
(40319, 6, 0, 'Valiona, finish them! Avenge me!', 14, 0, 100, 0, 0, 18614, 47764, 'Drahga Shadowburner - Death');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 90950;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 1, 90950, 0, 0, 31, 0, 3, 48798, 0, 0, 0, '', 'Devouring Flames - Target Devouring Flames Stalker');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_drahga_burning_shadowbolt',
'spell_drahga_devouring_flames_aoe');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75245, 'spell_drahga_burning_shadowbolt'),
(90915, 'spell_drahga_burning_shadowbolt'),
(90945, 'spell_drahga_devouring_flames_aoe');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (40319, 48784);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(40319, 395, 3500),
(48784, 395, 7000);

UPDATE `creature_template` SET `lootid`= 40319 WHERE `entry`= 40319;
UPDATE `creature_template` SET `lootid`= 48784 WHERE `entry`= 48784;
DELETE FROM `creature_loot_template` WHERE `Entry` IN (40319, 48784);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40319, 56126, 0, 1, 1, 1, 1),
(40319, 56125, 0, 1, 1, 1, 1),
(40319, 56123, 0, 1, 1, 1, 1),
(40319, 56124, 0, 1, 1, 1, 1),
(40319, 56127, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48784, 56450, 0, 1, 1, 1, 1),
(48784, 56453, 0, 1, 1, 1, 1),
(48784, 56451, 0, 1, 1, 1, 1),
(48784, 56452, 0, 1, 1, 1, 1),
(48784, 56454, 0, 1, 1, 1, 1);
