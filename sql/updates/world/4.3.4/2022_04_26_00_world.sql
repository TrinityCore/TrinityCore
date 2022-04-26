UPDATE `gameobject_template` SET `ScriptName`= 'go_end_time_time_transit_device' WHERE `entry` IN (209441, 209442);
UPDATE `gameobject_template` SET `ScriptName`= 'go_end_time_fragment_of_jainas_staff' WHERE `entry`= 209318;

UPDATE `gossip_menu_option` SET `OptionType`= 1 WHERE `MenuId`= 13321;

UPDATE `creature_template` SET `unit_flags`= 33587968, `unit_flags2`= 2099200, `AIName`= 'NullCreatureAI' WHERE `entry`= 54641;
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= `flags_extra` | 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 54639;
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= `flags_extra` | 128, `ScriptName`= 'npc_echo_of_jaina_blink_target' WHERE `entry`= 54542;
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 34816, `flags_extra`= `flags_extra` | 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 54446;

DELETE FROM `spawn_group_template` WHERE `groupId`= 460;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(460, 'End Time - Echo of Jaina - Jaina', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 460;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(460, 0, 341769);

UPDATE `creature_template` SET `unit_flags`= 33088, `unit_flags2`= 2099200, `ScriptName`= 'boss_echo_of_jaina' WHERE `entry`= 54445;
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 54494;

DELETE FROM `creature_text` WHERE `CreatureID`= 54445;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(54445, 0, 0, 'I don\'t know who you are, but I\'ll defend this shrine with my life. Leave, now, before we come to blows.', 12, 0, 100, 0, 0, 25920, 56573, 'Echo of Jaina - Intro'),
(54445, 1, 0, 'You asked for it.', 14, 0, 100, 0, 0, 25917, 53040, 'Echo of Jaina - Aggro'),
(54445, 2, 0, 'Why won\'t you give up?!', 14, 0, 100, 0, 0, 25926, 56580, 'Echo of Jaina - Blink 1'),
(54445, 2, 1, 'Perhaps this will cool your heads...', 14, 0, 100, 0, 0, 25924, 56578, 'Echo of Jaina - Blink 2'),
(54445, 2, 2, 'A little ice ought to quench the fire in your hearts...', 14, 0, 100, 0, 0, 25925, 56579, 'Echo of Jaina - Blink 3'),
(54445, 3, 0, 'I understand, now. Farewell, and good luck.', 12, 0, 100, 0, 0, 25919, 56574, 'Echo of Jaina - Death'),
(54445, 4, 0, 'You forced my hand.', 14, 0, 100, 0, 0, 25921, 56575, 'Echo of Jaina - Slay 1'),
(54445, 4, 1, 'I didn\'t want to do that.', 14, 0, 100, 0, 0, 25922, 56576, 'Echo of Jaina - Slay 2'),
(54445, 4, 2, 'I wish you\'d surrendered.', 14, 0, 100, 0, 0, 25923, 56577, 'Echo of Jaina - Slay 3');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_echo_of_jaina_face_highest_threat_target',
'spell_echo_of_jaina_frost_blade',
'spell_echo_of_jaina_disable_stalker_search',
'spell_echo_of_jaina_blink',
'spell_echo_of_jaina_flarecore',
'spell_echo_of_jaina_flarecore_triggered',
'spell_echo_of_jaina_flarecore_periodic');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(107897, 'spell_echo_of_jaina_face_highest_threat_target'),
(101337, 'spell_echo_of_jaina_frost_blade'),
(101540, 'spell_echo_of_jaina_disable_stalker_search'),
(101812, 'spell_echo_of_jaina_blink'),
(101944, 'spell_echo_of_jaina_flarecore'),
(101616, 'spell_echo_of_jaina_flarecore_triggered'),
(101588, 'spell_echo_of_jaina_flarecore_periodic');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (54494, 54446);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(54494, 0, 0, 2, 0),
(54446, 0, 0, 2, 1);

DELETE FROM `conditions` WHERE `SourceEntry` IN (101812, 101540) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 101812, 0, 0, 31, 0, 3, 54542, 0, 0, 0, '', 'Blink - Target Blink Target'),
(13, 2, 101540, 0, 0, 31, 0, 3, 54445, 0, 0, 0, '', 'Disable Stalker Search - Target Echo of Jaina');

DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 54445;
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`, `CurrencyId1`, `CurrencyCount1`) VALUES
(54445, 1162, 7, 0, 250, 0, 395, 7000);

UPDATE `creature_template`SET `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= 54445;
DELETE FROM `creature_loot_template` WHERE `Entry`= 54445;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(54445, 0, 72808, 20, 1, 1, 1, 1),
(54445, 0, 72809, 15, 1, 1, 1, 1),
(54445, 0, 72805, 5, 1, 1, 1, 1),
(54445, 0, 72801, 5, 1, 1, 1, 1),
(54445, 0, 72804, 5, 1, 1, 1, 1),
(54445, 0, 72802, 5, 1, 1, 1, 1),
(54445, 0, 72799, 5, 1, 1, 1, 1),
(54445, 0, 72803, 5, 1, 1, 1, 1),
(54445, 0, 72806, 5, 1, 1, 1, 1),
(54445, 0, 72798, 5, 1, 1, 1, 1),
(54445, 0, 72800, 5, 1, 1, 1, 1),
(54445, 0, 72807, 5, 1, 1, 1, 1);
