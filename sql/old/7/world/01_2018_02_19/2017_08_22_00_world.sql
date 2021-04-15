-- Baleroc
DELETE FROM `creature` WHERE `guid` IN (339184, 339185); -- Remove sniff spawn of Riplimb and Rageface in Baleroc encounter area
UPDATE `creature` SET `equipment_id`=1, `position_x`=95.15452, `position_y`=-63.20313, `position_z`=54.9362, `orientation`=3.16296, `spawntimesecs`=604800 WHERE `guid`=338782;

DELETE FROM `creature_equip_template` WHERE `CreatureID`=53494 AND ID IN (2, 3);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(53494, 2, 71138, 0, 0, 0),
(53494, 3, 71082, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (339198,339284);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339198, 339198, 0, 0, 2, 0, 0),
(339198, 317657, 0, 0, 2, 0, 0),
(339284, 339284, 0, 0, 2, 0, 0),
(339284, 339285, 0, 0, 2, 0, 0);

-- Baleroc (10-man Normal)
DELETE FROM `creature_loot_template` WHERE `Entry`=53494;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53494, 69815,     0, 100, 1, 1, 1, 18, 23, 'Baleroc 10N - Seething Cinder'),
(53494, 71141,     0,  80, 1, 1, 1,  1,  1, 'Baleroc 10N - Eternal Ember'),
(53494,     1, 34385, 100, 0, 1, 1,  2,  2, 'Baleroc 10N - Gear');
-- Baleroc (25-man Normal)
DELETE FROM `creature_loot_template` WHERE `Entry`=53587;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53587, 69815,     0, 100, 1, 1, 1, 48, 55, 'Baleroc 25N - Seeting Cinder'),
(53587, 71141,     0, 100, 1, 1, 1,  1,  3, 'Baleroc 25N - Eternal Ember'),
(53587,     1, 34385, 100, 0, 1, 1,  5,  5, 'Baleroc 25N - Gear');
-- Baleroc (10-man Heroic)
DELETE FROM `creature_loot_template` WHERE `Entry`=53588;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53588, 69815,     0, 100, 1, 1, 1, 23, 26, 'Baleroc 10H - Seething Cinder'),
(53588, 71141,     0,  80, 1, 1, 1,  1,  1, 'Baleroc 10H - Eternal Ember'),
(53588,     1, 34386, 100, 0, 1, 1,  2,  2, 'Baleroc 10H - Gear'),
(53588,     2, 34387, 100, 0, 1, 1,  1,  1, 'Baleroc 10H - Token');
-- Baleroc (25-man Heroic)
DELETE FROM `creature_loot_template` WHERE `Entry`=53589;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(53589, 69815,     0, 100, 1, 1, 1, 55, 66, 'Baleroc 25H - Seething Cinder'),
(53589, 71141,     0, 100, 1, 1, 1,  1,  3, 'Baleroc 25H - Eternal Ember'),
(53589,     1, 34386, 100, 0, 1, 1,  5,  5, 'Baleroc 25H - Gear'),
(53589,     2, 34387, 100, 0, 1, 1,  3,  3, 'Baleroc 25H - Tokens');

UPDATE `creature_template` SET `difficulty_entry_1`=54162, `HealthScalingExpansion`=3, `speed_walk`=0.714286, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824, `ScriptName`='npc_firelands_flame_archon' WHERE `entry`=54161;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.714286, `speed_run`=1.42857, `unit_flags`=32832, `unit_flags2`=`unit_flags2`|2097152, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824 WHERE `entry`=54162;
UPDATE `creature_template` SET `difficulty_entry_1`=54196, `speed_walk`=0.277777, `speed_run`=1.71429, `mechanic_immune_mask`=617561687, `ScriptName`='npc_firelands_molten_flamefather' WHERE `entry`=54143;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `HealthScalingExpansion`=3, `faction`=16, `speed_walk`=0.277777, `speed_run`=1.71429, `unit_flags`=32832, `unit_flags2`=`unit_flags2`|4194304, `mechanic_immune_mask`=617561687 WHERE `entry`=54196;
UPDATE `creature_template` SET `speed_walk`=0.277777, `speed_run`=1.71429, `unit_flags`=64, `unit_flags2`=32768, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824, `AIName`='PassiveAI' WHERE `entry`=54145;
UPDATE `creature_template` SET `difficulty_entry_1`=54204, `unit_flags2`=`unit_flags2`|2097152, `ScriptName`='npc_firelands_magmakin' WHERE `entry`=54144;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `HealthScalingExpansion`=3, `faction`=16, `speed_walk`=0.555556, `speed_run`=1.71429, `unit_flags2`=2099200 WHERE `entry`=54204;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `HealthScalingExpansion`=3, `faction`=14, `speed_walk`=1.14286, `speed_run`=2, `unit_flags`=32768, `unit_flags2`=2099200, `type_flags2`=128, `mechanic_immune_mask`=617561975, `flags_extra`=1073741825 WHERE `entry` IN (53587, 53588, 53589);
UPDATE `creature_template` SET `difficulty_entry_1`=53587, `difficulty_entry_2`=53588, `difficulty_entry_3`=53589, `speed_walk`=1.14286, `mechanic_immune_mask`=617561975, `flags_extra`=`flags_extra`|1073741824, `ScriptName`='boss_baleroc' WHERE `entry`=53494;
UPDATE `creature_template` SET `lootid`=53587 WHERE `entry`=53587;
UPDATE `creature_template` SET `lootid`=53588 WHERE `entry`=53588;
UPDATE `creature_template` SET `lootid`=53589 WHERE `entry`=53589;
UPDATE `creature_template` SET `speed_walk`=0.357142, `speed_run`=1.14286, `unit_flags`=33554432, `flags_extra`=128, `ScriptName`='npc_shard_of_torment' WHERE `entry`=53495;

DELETE FROM `creature_text` WHERE `entry`=53494;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53494, 0, 0, 'You are forbidden from my master''s domain, mortals.', 14, 0, 100, 0, 0, 24441, 52180, 3, 'Baleroc - Enter Combat'),
(53494, 1, 0, 'Fool mortals. Hurl yourselves into your own demise!', 14, 0, 100, 0, 0, 24446, 52185, 3, 'Baleroc - Shards of Torment'),
(53494, 2, 0, 'Burn beneath my molten fury!', 14, 0, 100, 0, 0, 24459, 52181, 3, 'Baleroc - Inferno Blade'),
(53494, 3, 0, 'By the Firelord''s command, you, too, shall perish!', 14, 0, 100, 0, 0, 24447, 52182, 3, 'Baleroc - Decimation Blade'),
(53494, 4, 0, 'You have been judged.', 14, 0, 100, 0, 0, 24449, 52177, 3, 'Baleroc - Kill Player (1)'),
(53494, 4, 1, 'Behold your weakness.', 14, 0, 100, 0, 0, 24451, 52178, 3, 'Baleroc - Kill Player (2)'),
(53494, 4, 2, 'None shall pass!', 14, 0, 100, 0, 0, 24452, 52179, 3, 'Baleroc - Kill Player (3)'),
(53494, 5, 0, 'Mortal filth... the master''s keep is forbidden....', 14, 0, 100, 0, 0, 24444, 52650, 3, 'Baleroc - Death'),
(53494, 6, 0, 'Your flesh is forfeit to the fires of this realm.', 14, 0, 100, 0, 0, 24450, 52183, 3, 'Baleroc - Berserk'),
(53494, 7, 0, '%s goes into a berserker rage!', 41, 0, 100, 0, 0, 0, 4428, 3, 'Baleroc - Berserk (Emote)'),
(53494, 8, 0, '|TInterface\\Icons\\spell_shadow_curse.blp:20|t%s readies his |cFF7A0080|Hspell:99352|h[Decimation Blade]|h|r!', 41, 0, 100, 0, 0, 0, 52889, 3, 'Baleroc - Decimation Blade (Emote)'),
(53494, 9, 0, '|TInterface\\Icons\\inv_sword_09.blp:20|t%s readies his |cFFFF0000|Hspell:99350|h[Inferno Blade]|h|r!', 41, 0, 100, 0, 0, 0, 52890, 3, 'Baleroc - Inferno Blade (Emote)');

DELETE FROM `criteria_data` WHERE `criteria_id`=17577;
INSERT INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES (17577, 11, 0, 0, 'achievement_share_the_pain');

DELETE FROM `linked_respawn` WHERE `guid` IN (317642,317652,317657,339198,339284,339285); -- guid is unique, not linkedGuid
INSERT INTO `linked_respawn` (`guid`, `linkedGuid`, `linkType`) VALUES
(317642, 338782, 0),
(317652, 338782, 0),
(317657, 338782, 0),
(339198, 338782, 0),
(339284, 338782, 0),
(339285, 338782, 0);

-- Normal shared items
DELETE FROM `reference_loot_template` WHERE `Entry`=34380;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34380, 71782, 0,     16, 0, 1, 1, 1, 1, 'Normal - Shatterskull Bonecrusher'),
(34380, 71775, 0,     16, 0, 1, 1, 1, 1, 'Normal - Smoldering Censer of Purity'),
(34380, 71776, 0,     16, 0, 1, 1, 1, 1, 'Normal - Eye of Purification'),
(34380, 71780, 0,     13, 0, 1, 1, 1, 1, 'Normal - Zoid''s Firelit Greatsword'),
(34380, 71779, 0,     11, 0, 1, 1, 1, 1, 'Normal - Avool''s Incendiary Shanker'),
(34380, 71787, 0,     11, 0, 1, 1, 1, 1, 'Normal - Entrail Disgorger'),
(34380, 71785, 0,     17, 0, 1, 1, 1, 1, 'Normal - Firethorn Mindslicer');
-- Heroic shared items
DELETE FROM `reference_loot_template` WHERE `Entry`=34381;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34381, 71783, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Shatterskull Bonecrusher'),
(34381, 71774, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Smoldering Censer of Purity'),
(34381, 71777, 0,     15, 0, 1, 1, 1, 1, 'Heroic - Eye of Purification'),
(34381, 71781, 0,     12, 0, 1, 1, 1, 1, 'Heroic - Zoid''s Firelit Greatsword'),
(34381, 71778, 0,     11, 0, 1, 1, 1, 1, 'Heroic - Avool''s Incendiary Shanker'),
(34381, 71786, 0,     11, 0, 1, 1, 1, 1, 'Heroic - Entrail Disgorger'),
(34381, 71784, 0,     16, 0, 1, 1, 1, 1, 'Heroic - Firethorn Mindslicer'),
(34381, 71617, 0,      5, 0, 1, 1, 1, 1, 'Heroic - Crystallized Firestone');
-- Baleroc normal
DELETE FROM `reference_loot_template` WHERE `Entry`=34385;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34385, 68982,     0, 12, 0, 1, 1, 1, 1, 'Normal - Necromantic Focus'),
(34385, 71343,     0, 10, 0, 1, 1, 1, 1, 'Normal - Mantle of Closed Doors'),
(34385, 70917,     0,  8, 0, 1, 1, 1, 1, 'Normal - Flickering Handguards'),
(34385, 71323,     0,  8, 0, 1, 1, 1, 1, 'Normal - Molten Scream'),
(34385, 71315,     0,  7, 0, 1, 1, 1, 1, 'Normal - Decimation Treads'),
(34385, 71345,     0,  7, 0, 1, 1, 1, 1, 'Normal - Shoulderpads of the Forgotten Gate'),
(34385, 71314,     0,  7, 0, 1, 1, 1, 1, 'Normal - Breastplate of the Incendiary Soul'),
(34385, 71312,     0,  7, 0, 1, 1, 1, 1, 'Normal - Gatecrasher'),
(34385, 71342,     0,  6, 0, 1, 1, 1, 1, 'Normal - Casque of Flame'),
(34385, 71340,     0,  6, 0, 1, 1, 1, 1, 'Normal - Gatekeeper''s Embrace'),
(34385, 71341,     0,  6, 0, 1, 1, 1, 1, 'Normal - Glowing Wing Bracers'),
(34385, 70915,     0,  6, 0, 1, 1, 1, 1, 'Normal - Shard of Torment'),
(34385, 70916,     0,  5, 0, 1, 1, 1, 1, 'Normal - Helm of Blazing Glory'),
(34385,     1, 34380,  5, 0, 1, 0, 1, 1, 'Normal - Shared loot table');
-- Baleroc heroic
DELETE FROM `reference_loot_template` WHERE `Entry`=34386;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34386, 69139,     0, 12, 0, 1, 1, 1, 1, 'Heroic - Necromantic Focus'),
(34386, 71461,     0, 10, 0, 1, 1, 1, 1, 'Heroic - Mantle of Closed Doors'),
(34386, 71458,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Flickering Handguards'),
(34386, 71462,     0,  8, 0, 1, 1, 1, 1, 'Heroic - Molten Scream'),
(34386, 71457,     0,  7, 0, 1, 1, 1, 1, 'Heroic - Decimation Treads'),
(34386, 71456,     0,  7, 0, 1, 1, 1, 1, 'Heroic - Shoulderpads of the Forgotten Gate'),
(34386, 71455,     0,  7, 0, 1, 1, 1, 1, 'Heroic - Breastplate of the Incendiary Soul'),
(34386, 71454,     0,  7, 0, 1, 1, 1, 1, 'Heroic - Gatecrasher'),
(34386, 71465,     0,  6, 0, 1, 1, 1, 1, 'Heroic - Casque of Flame'),
(34386, 71464,     0,  6, 0, 1, 1, 1, 1, 'Heroic - Gatekeeper''s Embrace'),
(34386, 71463,     0,  6, 0, 1, 1, 1, 1, 'Heroic - Glowing Wing Bracers'),
(34386, 71460,     0,  6, 0, 1, 1, 1, 1, 'Heroic - Shard of Torment'),
(34386, 71459,     0,  5, 0, 1, 1, 1, 1, 'Heroic - Helm of Blazing Glory'),
(34386,     1, 34381,  5, 0, 1, 0, 1, 1, 'Heroic - Shared loot table');
-- Baleroc heroic tokens
DELETE FROM `reference_loot_template` WHERE `Entry`=34387;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34387, 71669,     0, 40, 0, 1, 1, 1, 1, 'Heroic - Gauntlets of the Fiery Vanquisher'),
(34387, 71676,     0, 30, 0, 1, 1, 1, 1, 'Heroic - Gauntlets of the Fiery Conqueror'),
(34387, 71683,     0, 30, 0, 1, 1, 1, 1, 'Heroic - Gauntlets of the Fiery Protector');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (100799,99342,99350,99352,99353,99515,99516,99517,99259,99253,99256,99257,99489,99263,99262);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(100799, 'spell_firelands_fiery_torment'),
(99342, 'spell_baleroc_blades_of_baleroc'),
(99350, 'spell_baleroc_inferno_blade'),
(99352, 'spell_baleroc_decimation_blade'),
(99353, 'spell_baleroc_decimating_strike'),
(99515, 'spell_baleroc_countdown_aoe_dummy'),
(99516, 'spell_baleroc_countdown'),
(99517, 'spell_baleroc_countdown_proximity_check'),
(99259, 'spell_baleroc_shards_of_torment_target_search'),
(99253, 'spell_baleroc_torment_target_search'),
(99256, 'spell_baleroc_torment'),
(99257, 'spell_baleroc_tormented'),
(99489, 'spell_baleroc_tormented_spread'),
(99263, 'spell_baleroc_vital_flame'),
(99262, 'spell_baleroc_vital_spark');

-- Firelands Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (101089,101092,101093);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(101089, 'spell_firelands_smouldering'),
(101092, 'spell_firelands_smouldering'),
(101093, 'spell_firelands_smouldering_aura');

DELETE FROM `spell_proc` WHERE `SpellId`=99262;
INSERT INTO `spell_proc` (`SpellId`,`SpellTypeMask`,`SpellPhaseMask`) VALUES
(99262,2,2);
