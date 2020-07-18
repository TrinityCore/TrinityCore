-- Algalon
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_algalon_arcane_barrage',
'spell_algalon_phase_constellation',
'spell_algalon_black_hole_phase_shifts');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65508,'spell_algalon_phase_constellation'),
(62168,'spell_algalon_black_hole_phase_shifts'),
(65250,'spell_algalon_black_hole_phase_shifts'),
(64417,'spell_algalon_black_hole_phase_shifts');

UPDATE `creature_template` SET `ScriptName`='npc_black_hole' WHERE `entry`=32953;
UPDATE `creature` SET `spawntimesecs`=15 WHERE `id`=33089; -- Dark Matters should respawn faster  (is always full present in each black hole travel)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=34131; -- Stalker Asteroid Target 2 (25 man)
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(34131,0,0,1,0);

-- Living Constellation immune mask
UPDATE `creature_template` SET `mechanic_immune_mask` = 
1|          -- charm
2|          -- disorient
4|          -- disarm
16|         -- fear
512|        -- sleep
2048|		-- stun
4096|       -- freeze
8192|       -- knockout
65536|      -- polymorph
131072|     -- banish
524288|     -- shackle
1048576|    -- mount
4194304|    -- turn
8388608|    -- horror
536870912   -- sapped
WHERE `entry` IN (33052,33116);

-- Brann Bronzebeard
UPDATE `creature_text` SET `Emote`=19 WHERE `CreatureID`=34064 AND `GroupID`=1 AND `ID`=0;

-- Movement stuffs

-- Before Door (Intro)
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34064 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34064, 1, 0, 4584, 3641),
(34064, 1, 1, 1881, 1234),
(34064, 1, 2, 1279, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34064 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34064, 1, 0, 0, 1677.3630, -162.35140, 427.33200),
(34064, 1, 0, 1, 1680.0880, -162.26590, 427.33260),
(34064, 1, 0, 2, 1679.0880, -162.26590, 427.33260),
(34064, 1, 0, 3, 1663.3630, -163.04570, 427.32710),
(34064, 1, 0, 4, 1660.9440, -163.16570, 427.27290),
(34064, 1, 0, 5, 1656.7000, -163.37610, 427.27290),
(34064, 1, 0, 6, 1653.5710, -163.53130, 427.34070),
(34064, 1, 0, 7, 1642.4820, -164.08120, 427.26020),
(34064, 1, 0, 8, 1642.4820, -164.08120, 427.26020),
(34064, 1, 1, 0, 1648.2720, -163.79410, 427.30220),
(34064, 1, 1, 1, 1642.3860, -164.15430, 427.52730),
(34064, 1, 1, 2, 1635.0000, -169.51450, 427.25230),
(34064, 1, 2, 0, 1639.2800, -166.40650, 427.25680),
(34064, 1, 2, 1, 1635.2970, -169.42000, 427.50950),
(34064, 1, 2, 2, 1633.2970, -172.92000, 427.50950),
(34064, 1, 2, 3, 1632.8140, -173.93340, 427.26210);

-- Algalon Room (Intro)
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34064 AND `chainId`=2;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34064, 2, 0, 21837, 20656),
(34064, 2, 1, 20274, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34064 AND `chainId`=2;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34064, 2, 0, 0, 1632.8140, -173.93340, 427.26210),
(34064, 2, 0, 1, 1632.8260, -175.36180, 427.54690),
(34064, 2, 0, 2, 1632.8260, -176.36180, 427.54690),
(34064, 2, 0, 3, 1632.5760, -178.11180, 427.54690),
(34064, 2, 0, 4, 1632.5760, -186.86180, 427.54690),
(34064, 2, 0, 5, 1632.3260, -191.11180, 427.54690),
(34064, 2, 0, 6, 1632.0760, -211.36180, 419.79690),
(34064, 2, 0, 7, 1632.0760, -213.61180, 418.79690),
(34064, 2, 0, 8, 1631.8260, -219.86180, 418.79690),
(34064, 2, 0, 9, 1631.5760, -222.86180, 418.79690),
(34064, 2, 0, 10, 1631.5760, -226.11180, 418.79690),
(34064, 2, 0, 11, 1631.3390, -226.79030, 418.33180),
(34064, 2, 1, 0, 1631.4220, -223.79560, 418.40920),
(34064, 2, 1, 1, 1631.4580, -226.29390, 418.61520),
(34064, 2, 1, 2, 1631.4580, -226.79390, 418.61520),
(34064, 2, 1, 3, 1631.9580, -227.79390, 418.36520),
(34064, 2, 1, 4, 1631.9580, -229.79390, 417.86520),
(34064, 2, 1, 5, 1631.7080, -232.04390, 417.86520),
(34064, 2, 1, 6, 1631.7080, -234.04390, 417.86520),
(34064, 2, 1, 7, 1637.2080, -266.79390, 417.61520),
(34064, 2, 1, 8, 1630.4940, -267.29210, 417.32110);

-- Outro 1
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34064 AND `chainId`=3;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34064, 3, 0, 13940, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34064 AND `chainId`=3;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34064, 3, 0, 0, 1631.9890, -221.54390, 418.40910),
(34064, 3, 0, 1, 1631.9910, -222.44830, 418.40910),
(34064, 3, 0, 2, 1632.0610, -269.03790, 417.32100),
(34064, 3, 0, 3, 1631.9860, -297.78310, 417.32100),
(34064, 3, 0, 4, 1631.9860, -297.78310, 417.32100);

-- Outro 2
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34064 AND `chainId`=4;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34064, 4, 0, 26675, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34064 AND `chainId`=4;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34064, 4, 0, 0, 1631.9860, -297.78310, 417.32100),
(34064, 4, 0, 1, 1632.5820, -289.54480, 417.79630),
(34064, 4, 0, 2, 1633.0820, -267.29480, 417.79630),
(34064, 4, 0, 3, 1631.8320, -227.29480, 418.54630),
(34064, 4, 0, 4, 1632.5820, -217.79480, 418.79630),
(34064, 4, 0, 5, 1632.3320, -203.04480, 423.04630),
(34064, 4, 0, 6, 1633.0820, -188.79480, 427.54630),
(34064, 4, 0, 7, 1631.5820, -164.04480, 427.29630),
(34064, 4, 0, 8, 1656.8320, -164.79480, 427.54630),
(34064, 4, 0, 9, 1681.3320, -164.29480, 427.54630),
(34064, 4, 0, 10, 1682.3320, -154.54480, 427.54630),
(34064, 4, 0, 11, 1683.1770, -136.30650, 427.27150);

-- Despawn Point Intro
DELETE FROM `script_spline_chain_meta` WHERE `entry`=34064 AND `chainId`=5;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(34064, 5, 0, 29711, 28875),
(34064, 5, 1, 12977, 12141),
(34064, 5, 2, 7479, 6437),
(34064, 5, 3, 5117, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=34064 AND `chainId`=5;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(34064, 5, 0, 0, 1630.4940, -267.29210, 417.32110),
(34064, 5, 0, 1, 1637.0400, -266.68800, 417.84810),
(34064, 5, 0, 2, 1634.5400, -233.93800, 417.84810),
(34064, 5, 0, 3, 1634.2900, -231.68800, 417.84810),
(34064, 5, 0, 4, 1634.2900, -229.93800, 417.84810),
(34064, 5, 0, 5, 1632.0400, -227.68800, 418.59810),
(34064, 5, 0, 6, 1632.0400, -226.18800, 418.84810),
(34064, 5, 0, 7, 1632.0400, -223.18800, 418.84810),
(34064, 5, 0, 8, 1632.0400, -220.18800, 418.84810),
(34064, 5, 0, 9, 1632.0400, -213.68800, 418.84810),
(34064, 5, 0, 10, 1632.0400, -211.68800, 419.84810),
(34064, 5, 0, 11, 1632.0850, -201.58390, 423.37500),
(34064, 5, 1, 0, 1632.0770, -203.61940, 422.59170),
(34064, 5, 1, 1, 1632.1190, -201.36540, 423.66990),
(34064, 5, 1, 2, 1631.6190, -190.86540, 427.66990),
(34064, 5, 1, 3, 1631.3690, -186.86540, 427.41990),
(34064, 5, 1, 4, 1631.1190, -178.11540, 427.41990),
(34064, 5, 1, 5, 1631.1190, -176.36540, 427.41990),
(34064, 5, 1, 6, 1631.1190, -175.36540, 427.41990),
(34064, 5, 1, 7, 1630.8690, -173.11540, 427.41990),
(34064, 5, 1, 8, 1630.6600, -172.11150, 427.24800),
(34064, 5, 2, 0, 1630.7620, -174.22000, 427.26550),
(34064, 5, 2, 1, 1630.8760, -173.00420, 427.51350),
(34064, 5, 2, 2, 1630.8760, -171.75420, 427.51350),
(34064, 5, 2, 3, 1645.9900, -165.78850, 427.26160),
(34064, 5, 3, 0, 1642.4200, -167.26120, 427.25840),
(34064, 5, 3, 1, 1646.1510, -165.89170, 427.54380),
(34064, 5, 3, 2, 1654.4010, -165.14170, 427.54380),
(34064, 5, 3, 3, 1654.8810, -165.02210, 427.32920);
