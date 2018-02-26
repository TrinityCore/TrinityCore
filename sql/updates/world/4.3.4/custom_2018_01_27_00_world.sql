-- Template Updates
UPDATE `creature_template` SET `Scriptname`= 'boss_forgemaster_throngus', `flags_extra`= `flags_extra`| 0x40000000,  `mechanic_immune_mask`= 617299839 WHERE `entry`= 40177;
UPDATE `creature_template` SET `flags_extra`= `flags_extra`| 0x40000000 | 1,  `mechanic_immune_mask`= 617299839, `minlevel`= 87, `maxlevel`= 87 WHERE `entry`= 48702;
-- Cave In Stalker
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 7, `unit_flags`= 34078720, `flags_extra`= 131, `ScriptName`= 'npc_throngus_cave_in' WHERE `entry`= 40228;
-- Fixate Stalker
UPDATE `creature_template` SET `minlevel`= 80, `maxlevel`= 80, `faction`= 35, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 40255;
-- Fire Patch
UPDATE `creature_template` SET `minlevel`= 80, `maxlevel`= 80, `faction`= 7, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 48711;

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (40228, 48711);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40228, '74990'),
(48711, '90752');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_throngus_mighty_stomp',
'spell_throngus_pick_weapon',
'spell_throngus_flame_arrow_barrage',
'spell_throngus_flaming_arrow',
'spell_throngus_personal_phalanx',
'spell_throngus_personal_phalanx_aoe',
'spell_throngus_fixate_effect',
'spell_throngus_burning_dual_blades',
'spell_throngus_disorienting_roar',
'spell_throngus_encumbered',
'spell_throngus_impaling_slam');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74984, 'spell_throngus_mighty_stomp'),
(75000, 'spell_throngus_pick_weapon'),
(74945, 'spell_throngus_flame_arrow_barrage'),
(74944, 'spell_throngus_flaming_arrow'),
(90810, 'spell_throngus_flaming_arrow'),
(74908, 'spell_throngus_personal_phalanx'),
(74914, 'spell_throngus_personal_phalanx_aoe'),
(75071, 'spell_throngus_fixate_effect'),
(74981, 'spell_throngus_burning_dual_blades'),
(90738, 'spell_throngus_burning_dual_blades'),
(74976, 'spell_throngus_disorienting_roar'),
(90737, 'spell_throngus_disorienting_roar'),
(75007, 'spell_throngus_encumbered'),
(90729, 'spell_throngus_encumbered'),
(75056, 'spell_throngus_impaling_slam'),
(90756, 'spell_throngus_impaling_slam');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 40177;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(40177, 0, 0, 'NO! Throngus get whipped again if he no finish!', 14, 0, 100, 0, 0, 18943, 47777, 'Forgemaster Throngus - Say Aggro'),
(40177, 1, 0, 'You not get through defenses!', 14, 0, 100, 0, 0, 18947, 47781, 'Forgemaster Throngus - Say Personal Phalanx'),
(40177, 2, 0, 'Oh, this gonna HURT!', 14, 0, 100, 53, 0, 18949, 47782, 'Forgemaster Throngus - Say Mace'),
(40177, 3, 0, 'Throngus SLICE you up!', 14, 0, 100, 0, 0, 18948, 47783, 'Forgemaster Throngus - Say Swords'),
(40177, 4, 0, '|TInterface\\Icons\\inv_shield_76.blp:20|t%s equips his |cFFFF0000Shield|r and gains |cFFFF0000|Hspell:74908|h[Personal Phalanx]|h|r!', 41, 0, 100, 0, 0, 0, 40747, 'Forgemaster Throngus - Announce Personal Phalanx'),
(40177, 5, 0, '|TInterface\\Icons\\inv_mace_15.blp:20|t%s equips his |cFFFF0000Mace|r and is |cFFFF0000|Hspell:75007|h[Encumbered]|h|r!', 41, 0, 100, 53, 0, 0, 40239, 'Forgemaster Throngus - Announce Mace'),
(40177, 6, 0, '|TInterface\\Icons\\ability_dualwield.blp:20|t%s equips his |cFFFF0000Swords|r and gains |cFFFF0000|Hspell:74981|h[Dual Blades]|h|r!', 41, 0, 100, 0, 0, 0, 40746, 'Forgemaster Throngus - Announce Swords'),
(40177, 7, 0, '$n is impaled!', 41, 0, 100, 0, 0, 0, 30718, 'Forgemaster Throngus - Announce Impaled'),
(40177, 8, 0, 'Throngus use your corpse on body. Somewhere...', 14, 0, 100, 0, 0, 18944, 47778, 'Forgemaster Throngus - Slay 1'),
(40177, 8, 1, 'You break easy!', 14, 0, 100, 0, 0, 18945, 47779, 'Forgemaster Throngus - Slay 2'),
(40177, 9, 0, 'Death... Good choice. Not best choice maybe, but better than fail and live.', 14, 0, 100, 0, 0, 18946, 47780, 'Forgemaster Throngus to Player');


-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (74945, 75071) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 74945, 0, 0, 31, 0, 3, 40197, 0, 0, 0, '', 'Flame Arrow Barrage - Target Twilight Archer'),
(13, 1, 75071, 0, 0, 31, 0, 3, 40255, 0, 0, 0, '', 'Fixate Effect - Target Fixate Stalker');

-- Proc Entries
DELETE FROM `spell_proc` WHERE `SpellId` IN (74981, 90738, 74976, 90737, 90759);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(74981, 0x00000004, 1, 0, 8400),
(90738, 0x00000004, 1, 0, 8400),
(90759, 0x00000004, 1, 0, 2000);

INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(74976, 1|2|4|8|16|32|64, 0x00015510, 7, 1, 0),
(90737, 1|2|4|8|16|32|64, 0x00015510, 7, 1, 0);

DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (40177, 48702);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(40177, 395, 3500),
(48702, 395, 7000);

UPDATE `creature_template` SET  `lootid`= 40177 WHERE `entry`= 40177;
UPDATE `creature_template` SET `lootid`= 48702 WHERE `entry`= 48702;
DELETE FROM creature_loot_template WHERE entry IN (40177, 48702);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40177, 56119, 0, 1, 1, 1, 1),
(40177, 56118, 0, 1, 1, 1, 1),
(40177, 56120, 0, 1, 1, 1, 1),
(40177, 56121, 0, 1, 1, 1, 1),
(40177, 56122, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48702, 56448, 0, 1, 1, 1, 1),
(48702, 56447, 0, 1, 1, 1, 1),
(48702, 56445, 0, 1, 1, 1, 1),
(48702, 56449, 0, 1, 1, 1, 1),
(48702, 56446, 0, 1, 1, 1, 1);
