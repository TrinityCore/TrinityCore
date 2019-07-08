UPDATE `creature_template` SET `unit_flags`= 0, `IconName`= 'vehichleCursor', `ScriptName`= 'npc_grim_batol_battered_red_drake' WHERE `entry`= 39294;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 39294;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(39294, 80343, 1, 1);

DELETE FROM `creature` WHERE `guid` IN (339899, 340384, 340108, 339892, 339905);
DELETE FROM `creature_addon` WHERE `guid` IN (339899, 340384, 340108, 339892, 339905);

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 670 AND `summonerType`= 2;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(670, 2, 0, 39294, -440.7257, -335.5625, 268.8163, 3.124139, 8, 0),
(670, 2, 0, 39294, -443.1285, -350.7656, 267.6065, 2.583087, 8, 0),
(670, 2, 0, 39294, -436.0382, -371.0208, 269.048, 2.600541, 8, 0),
(670, 2, 0, 39294, -450.401, -387.3906, 268.959, 1.151917, 8, 0),
(670, 2, 0, 39294, -435.717, -387.1146, 267.7955, 1.937315, 8, 0);

DELETE FROM `creature_text` WHERE `CreatureID`= 39294;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39294, 0, 0, 'Welcome, friend.  Let\'s ride through Grim Batol and strike a blow against Deathwing that he won\'t soon forget!', 15, 0, 100, 0, 0, 0, 39638, 'Battered Red Drake'),
(39294, 1, 0, '|TInterface\\Icons\\ability_mage_firestarter.blp:20|tUse |cFFFF0000|Hspell:74040|h[Engulfing Flames]|h|r to destroy the Twilight\'s Hammer!', 42, 0, 100, 0, 0, 0, 49153, 'Battered Red Drake');

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`= 39294;
INSERT INTO `script_spline_chain_waypoints` (`entry`, `chainId`, `splineId`, `wpId`, `x`, `y`, `z`) VALUES
-- 1
(39294, 1, 0, 0, -440.7257, -335.5625, 268.7344),
(39294, 1, 0, 1, -442.3385, -345.099, 277.725),
(39294, 1, 0, 2, -470.4236, -328.9063, 297.9019),
(39294, 1, 0, 3, -534.6597, -322.5816, 301.79),
(39294, 1, 0, 4, -626.283, -381.1163, 288.429),
(39294, 1, 0, 5, -674.8021, -396.4879, 322.5092),
(39294, 1, 0, 6, -722.1858, -463.8368, 306.454),
(39294, 1, 0, 7, -714.2639, -588.7604, 331.7317),
(39294, 1, 0, 8, -684.1719, -676.0486, 301.2165),
(39294, 1, 0, 9, -635.1007, -714.7153, 302.4538),
(39294, 1, 0, 10, -533.9254, -731.7726, 291.2872),
(39294, 1, 0, 11, -462.1371, -724.3055, 288.4538),
(39294, 1, 0, 12, -399.845, -697.885, 292.704),
(39294, 1, 0, 13, -389.738, -662.714, 301.537),
(39294, 1, 0, 14, -441.842, -673.3004, 293.8704),
(39294, 1, 0, 15, -533.5643, -720.9549, 297.9536),
(39294, 1, 0, 16, -626.3611, -689.4618, 311.9816),
(39294, 1, 0, 17, -678.4479, -646.75, 322.6483),
(39294, 1, 0, 18, -699.4375, -607.6424, 314.0928),
(39294, 1, 0, 19, -723.5938, -524.5643, 308.8705),
(39294, 1, 0, 20, -687.9358, -424.9115, 291.3428),
(39294, 1, 0, 21, -538.7361, -318.3976, 292.5929),
(39294, 1, 0, 22, -452.2274, -357.5938, 276.204),
-- 2
(39294, 2, 0, 0, -452.2274, -357.5938, 276.204),
(39294, 2, 0, 1, -443.7083, -350.4722, 285.9457),
(39294, 2, 0, 2, -477.875, -344.184, 318.846),
(39294, 2, 0, 3, -532.6545, -296.8021, 356.0412),
(39294, 2, 0, 4, -534.6094, -281.1754, 356.0412);


DELETE FROM `script_spline_chain_meta` WHERE `entry`= 39294;
INSERT INTo `script_spline_chain_meta` (`entry`, `chainId`, `splineId`, `expectedDuration`, `msUntilNext`, `velocity`) VALUES
(39294, 1, 0, 89126, 0, 13.0),
(39294, 2, 0, 5328, 0, 13.0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_grim_batol_engulfing_flames',
'spell_gen_vehicle_scaling_trigger');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_vehicle_scaling' AND `spell_id` IN (91401, 91405);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74040, 'spell_grim_batol_engulfing_flames'),
(90904, 'spell_grim_batol_engulfing_flames'),
(73917, 'spell_gen_vehicle_scaling_trigger'),
(91401, 'spell_gen_vehicle_scaling'),
(91405, 'spell_gen_vehicle_scaling');
