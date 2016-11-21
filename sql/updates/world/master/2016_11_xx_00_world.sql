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

UPDATE `creature_template` SET `difficulty_entry_1`=54162, `speed_walk`=0.714286, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824, `ScriptName`='npc_firelands_flame_archon' WHERE `entry`=54161;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.714286, `speed_run`=1.42857, `unit_flags`=32832, `unit_flags2`=`unit_flags2`|2097152, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824 WHERE `entry`=54162;
UPDATE `creature_template` SET `difficulty_entry_1`=54196, `speed_walk`=0.277777, `speed_run`=1.71429, `mechanic_immune_mask`=617561687, `ScriptName`='npc_firelands_molten_flamefather' WHERE `entry`=54143;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.277777, `speed_run`=1.71429, `unit_flags`=32832, `unit_flags2`=`unit_flags2`|4194304, `mechanic_immune_mask`=617561687 WHERE `entry`=54196;
UPDATE `creature_template` SET `speed_walk`=0.277777, `speed_run`=1.71429, `unit_flags`=64, `unit_flags2`=32768, `mechanic_immune_mask`=617561727, `flags_extra`=1073741824, `AIName`='PassiveAI' WHERE `entry`=54145;
UPDATE `creature_template` SET `difficulty_entry_1`=54204, `unit_flags2`=`unit_flags2`|2097152, `ScriptName`='npc_firelands_magmakin' WHERE `entry`=54144;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction`=16, `speed_walk`=0.555556, `speed_run`=1.71429, `unit_flags2`=2099200 WHERE `entry`=54204;
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction`=14, `speed_walk`=1.14286, `speed_run`=2, `unit_flags`=32768, `unit_flags2`=2099200, `type_flags2`=128, `mechanic_immune_mask`=617562103, `flags_extra`=1073741825 WHERE `entry` IN (53587, 53588, 53589);
UPDATE `creature_template` SET `difficulty_entry_1`=53587, `difficulty_entry_2`=53588, `difficulty_entry_3`=53589, `speed_walk`=1.14286, `mechanic_immune_mask`=617562103, `flags_extra`=`flags_extra`|1073741824, `ScriptName`='boss_baleroc' WHERE `entry`=53494;
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
(53494, 8, 0, '|TInterface\Icons\spell_shadow_curse.blp:20|t%s readies his |cFF7A0080|Hspell:99352|h[Decimation Blade]|h|r!', 41, 0, 100, 0, 0, 0, 52889, 3, 'Baleroc - Decimation Blade (Emote)'),
(53494, 9, 0, '|TInterface\Icons\inv_sword_09.blp:20|t%s readies his |cFFFF0000|Hspell:99350|h[Inferno Blade]|h|r!', 41, 0, 100, 0, 0, 0, 52890, 3, 'Baleroc - Inferno Blade (Emote)');

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
