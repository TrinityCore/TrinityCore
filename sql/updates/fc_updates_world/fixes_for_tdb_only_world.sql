--
-- Fixes only for TDB
--

-- Right loot for Argent Crusade Tribute Chest in Trial of The Crusader
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (195665,195666,195667,195668,195669,195670,195671,195672);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(195665, 47242, 100, 1, 0, 2, 2),
(195665, 47556, 100, 1, 0, 1, 1),
(195666, 47242, 100, 1, 0, 2, 2),
(195666, 47556, 100, 1, 0, 1, 1),
(195666, 48693, 0, 1, 2, 1, 1),
(195666, 48695, 0, 1, 2, 1, 1),
(195666, 48697, 0, 1, 2, 1, 1),
(195666, 48699, 0, 1, 2, 1, 1),
(195666, 48701, 0, 1, 2, 1, 1),
(195666, 48703, 0, 1, 2, 1, 1),
(195666, 48705, 0, 1, 2, 1, 1),
(195666, 48708, 0, 1, 1, 1, 1),
(195666, 48709, 0, 1, 1, 1, 1),
(195666, 48710, 0, 1, 1, 1, 1),
(195666, 48711, 0, 1, 1, 1, 1),
(195666, 48712, 0, 1, 1, 1, 1),
(195666, 48713, 0, 1, 1, 1, 1),
(195666, 48714, 0, 1, 1, 1, 1),
(195667, 47242, 100, 1, 0, 4, 4),
(195667, 47556, 100, 1, 0, 1, 1),
(195667, 48693, 0, 1, 2, 1, 1),
(195667, 48695, 0, 1, 2, 1, 1),
(195667, 48697, 0, 1, 2, 1, 1),
(195667, 48699, 0, 1, 2, 1, 1),
(195667, 48701, 0, 1, 2, 1, 1),
(195667, 48703, 0, 1, 2, 1, 1),
(195667, 48705, 0, 1, 2, 1, 1),
(195667, 48708, 0, 1, 1, 1, 1),
(195667, 48709, 0, 1, 1, 1, 1),
(195667, 48710, 0, 1, 1, 1, 1),
(195667, 48711, 0, 1, 1, 1, 1),
(195667, 48712, 0, 1, 1, 1, 1),
(195667, 48713, 0, 1, 1, 1, 1),
(195667, 48714, 0, 1, 1, 1, 1),
(195668, 47242, 100, 1, 0, 4, 4),
(195668, 47556, 100, 1, 0, 1, 1),
(195668, 48666, 0, 1, 4, 1, 1),
(195668, 48667, 0, 1, 4, 1, 1),
(195668, 48668, 0, 1, 4, 1, 1),
(195668, 48669, 0, 1, 4, 1, 1),
(195668, 48670, 0, 1, 4, 1, 1),
(195668, 48671, 0, 1, 3, 1, 1),
(195668, 48672, 0, 1, 3, 1, 1),
(195668, 48673, 0, 1, 3, 1, 1),
(195668, 48674, 0, 1, 3, 1, 1),
(195668, 48675, 0, 1, 3, 1, 1),
(195668, 48693, 0, 1, 2, 1, 1),
(195668, 48695, 0, 1, 2, 1, 1),
(195668, 48697, 0, 1, 2, 1, 1),
(195668, 48699, 0, 1, 2, 1, 1),
(195668, 48701, 0, 1, 2, 1, 1),
(195668, 48703, 0, 1, 2, 1, 1),
(195668, 48705, 0, 1, 2, 1, 1),
(195668, 48708, 0, 1, 1, 1, 1),
(195668, 48709, 0, 1, 1, 1, 1),
(195668, 48710, 0, 1, 1, 1, 1),
(195668, 48711, 0, 1, 1, 1, 1),
(195668, 48712, 0, 1, 1, 1, 1),
(195668, 48713, 0, 1, 1, 1, 1),
(195668, 48714, 0, 1, 1, 1, 1),
(195668, 49044, 100, 1, 0, 1, 1),
(195668, 49046, 100, 1, 0, 1, 1),
(195669, 47557, 100, 1, 0, -47557, 2),
(195670, 47506, 0, 1, 1, 1, 1),
(195670, 47513, 0, 1, 2, 1, 1),
(195670, 47515, 0, 1, 1, 1, 1),
(195670, 47516, 0, 1, 2, 1, 1),
(195670, 47517, 0, 1, 1, 1, 1),
(195670, 47518, 0, 1, 2, 1, 1),
(195670, 47519, 0, 1, 1, 1, 1),
(195670, 47520, 0, 1, 2, 1, 1),
(195670, 47521, 0, 1, 1, 1, 1),
(195670, 47523, 0, 1, 2, 1, 1),
(195670, 47524, 0, 1, 1, 1, 1),
(195670, 47525, 0, 1, 2, 1, 1),
(195670, 47526, 0, 1, 1, 1, 1),
(195670, 47528, 0, 1, 2, 1, 1),
(195670, 47557, 100, 1, 0, -47557, 2),
(195671, 47506, 0, 1, 1, 1, 1),
(195671, 47513, 0, 1, 2, 1, 1),
(195671, 47515, 0, 1, 1, 1, 1),
(195671, 47516, 0, 1, 2, 1, 1),
(195671, 47517, 0, 1, 1, 1, 1),
(195671, 47518, 0, 1, 2, 1, 1),
(195671, 47519, 0, 1, 1, 1, 1),
(195671, 47520, 0, 1, 2, 1, 1),
(195671, 47521, 0, 1, 1, 1, 1),
(195671, 47523, 0, 1, 2, 1, 1),
(195671, 47524, 0, 1, 1, 1, 1),
(195671, 47525, 0, 1, 2, 1, 1),
(195671, 47526, 0, 1, 1, 1, 1),
(195671, 47528, 0, 1, 2, 1, 1),
(195671, 47557, 100, 1, 0, -47557, 4),
(195672, 47506, 0, 1, 1, 1, 1),
(195672, 47513, 0, 1, 2, 1, 1),
(195672, 47515, 0, 1, 1, 1, 1),
(195672, 47516, 0, 1, 2, 1, 1),
(195672, 47517, 0, 1, 1, 1, 1),
(195672, 47518, 0, 1, 2, 1, 1),
(195672, 47519, 0, 1, 1, 1, 1),
(195672, 47520, 0, 1, 2, 1, 1),
(195672, 47521, 0, 1, 1, 1, 1),
(195672, 47523, 0, 1, 2, 1, 1),
(195672, 47524, 0, 1, 1, 1, 1),
(195672, 47525, 0, 1, 2, 1, 1),
(195672, 47526, 0, 1, 1, 1, 1),
(195672, 47528, 0, 1, 2, 1, 1),
(195672, 47545, 0, 1, 3, 1, 1),
(195672, 47546, 0, 1, 4, 1, 1),
(195672, 47547, 0, 1, 3, 1, 1),
(195672, 47548, 0, 1, 4, 1, 1),
(195672, 47549, 0, 1, 3, 1, 1),
(195672, 47550, 0, 1, 4, 1, 1),
(195672, 47551, 0, 1, 4, 1, 1),
(195672, 47552, 0, 1, 3, 1, 1),
(195672, 47553, 0, 1, 3, 1, 1),
(195672, 47554, 0, 1, 4, 1, 1),
(195672, 47557, 100, 1, 0, -47557, 4);

-- Right spellid0 for Steelbreaker ability. Fix bug with Elegant Dress item.
-- The TC and TDB developers are so confident in his infallibility, that not even fix his mistake.
UPDATE `spelldifficulty_dbc` SET `spellid0`= 61890 WHERE `id`= 3251 AND `spellid1`= 63498;

-- Scriptnames
UPDATE `creature_template` SET `ScriptName` = 'npc_coren_direbrew' WHERE `entry` = 23872;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (42992, 42993, 42994, 43310, 43332);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42992, 'spell_brewfest_speed'),
(42993, 'spell_brewfest_speed'),
(42994, 'spell_brewfest_speed'),
(43310, 'spell_brewfest_speed'),
(43332, 'spell_brewfest_speed');
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_apple_trigger' WHERE `entry` = 24337;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_keg_thrower' WHERE `entry` = 24364;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_keg_thrower' WHERE `entry` = 24527;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_keg_receiver' WHERE `entry` = 24468;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_keg_receiver' WHERE `entry` = 24510;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_ram_master' WHERE `entry` = 23558;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewfest_ram_master' WHERE `entry` = 24497;
UPDATE `creature_template` SET `ScriptName` = 'npc_dark_iron_guzzler' WHERE `entry` = 23709;
UPDATE `creature_template` SET `ScriptName` = 'npc_coren_direbrew' WHERE `entry` = 23872;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewmaiden' WHERE `entry` = 26764;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewmaiden' WHERE `entry` = 26822;
UPDATE `gameobject_template` SET `ScriptName` = 'go_mole_machine_console' WHERE `entry` = 188498;
UPDATE `item_template` SET `ScriptName` = 'item_brewfest_ChugAndChuck' WHERE `entry` = 33096;
UPDATE `item_template` SET `ScriptName` = 'item_brewfest_ram_reins' WHERE `entry` = 33306;


-- startup errors fixes
UPDATE `quest_template` SET `ZoneOrSort` = 1 WHERE  `Id` =384;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35491;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(35491, 47020, 1, 0);
