--
DELETE FROM `creature` WHERE `guid` =250021;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(250021, 53494, 720, 15, 89.9669, -62.8343, 54.9484, 3.16296, 7200);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 17577;
INSERT INTO `achievement_criteria_data` VALUES (17577, 11, 0, 0, 'achievement_share_the_pain');

UPDATE `creature_template` SET `ScriptName`='boss_baleroc' WHERE `entry`=53494;
UPDATE `creature_template` SET `ScriptName`='npc_shard_of_torment' WHERE `entry`=53495;

DELETE FROM `creature_text` WHERE `entry`=53494;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53494, 4, 2, 'Behold your weakness.', 14, 0, 100, 0, 0, 24451, 0, 0, 'Baleroc'),
(53494, 0, 0, 'You are forbidden from my master\'s domain, mortals.', 14, 0, 100, 0, 0, 24441, 0, 0, 'Baleroc'),
(53494, 1, 0, 'Fool mortals. Hurl yourselves into your own demise!', 14, 0, 100, 0, 0, 24446, 0, 0, 'Baleroc'),
(53494, 2, 0, 'Burn beneath my molten fury!', 14, 0, 100, 0, 0, 24459, 0, 0, 'Baleroc'),
(53494, 3, 0, 'By the Firelord\'s command, you, too, shall perish!', 14, 0, 100, 0, 0, 24447, 0, 0, 'Baleroc'),
(53494, 4, 0, 'None shall pass!', 14, 0, 100, 0, 0, 24452, 0, 0, 'Baleroc'),
(53494, 4, 1, 'You have been judged.', 14, 0, 100, 0, 0, 24449, 0, 0, 'Baleroc'),
(53494, 5, 0, 'Your flesh is forfeit to the fires of this realm.', 14, 0, 100, 0, 0, 24450, 0, 0, 'Baleroc'),
(53494, 7, 0, 'Mortal filth... the master\'s keep is forbidden...', 14, 0, 100, 0, 0, 24444, 0, 0, 'Baleroc'),
(53494, 6, 0, '%s goes into a berserker rage!', 16, 0, 100, 0, 0, 0, 0, 0, 'Baleroc'),
(53494, 8, 0, '|TInterface\\Icons\\inv_sword_09.blp:20|t%s readies his |cFFFF0000Inferno Blade|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Baleroc'),
(53494, 9, 0, '|TInterface\\Icons\\spell_shadow_curse:20|t%s readies his |cFF551A8BDecimation Blade|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Baleroc');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (99253,99256,99259,99353,99489,99515,99516,99517,100230,100231,100232);
INSERT INTO `spell_script_names` VALUES
(99253, 'spell_baleroc_torment'),
(99256, 'spell_baleroc_tormented'),
(99259, 'spell_shards_of_torment'),
(99353, 'spell_decimating_strike'),
(99489, 'spell_baleroc_tormented_heroic'),
(99515, 'spell_countdown_p1'),
(99516, 'spell_countdown_p2'),
(99517, 'spell_countdown_p3'),
(100230, 'spell_baleroc_tormented'),
(100231, 'spell_baleroc_tormented'),
(100232, 'spell_baleroc_tormented');
