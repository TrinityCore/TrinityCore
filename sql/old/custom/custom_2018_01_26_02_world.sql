-- Drop SAI and assign scriptname
UPDATE `creature_template` SET `AIName`="", `Scriptname`= 'npc_umbriss_skardyn' WHERE `entry` IN (39984, 45467);
DELETE FROM `smart_scripts` WHERE `entryorguid`=39984 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=45467 AND `source_type`=0;

-- Spell scriptnames
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_umbriss_modguds_malice';

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 48337;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(48337, 395, 7000);

-- Loot
-- General Umbriss
UPDATE `creature_template` SET `lootid` = 39625 WHERE `entry` = 39625;
UPDATE `creature_template` SET `lootid` = 48337 WHERE `entry` = 48337;
DELETE FROM `creature_loot_template` WHERE `entry` IN (39625, 48337);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39625, 56113, 0, 1, 1, 1, 1),
(39625, 56112, 0, 1, 1, 1, 1),
(39625, 56114, 0, 1, 1, 1, 1),
(39625, 56115, 0, 1, 1, 1, 1),
(39625, 56116, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48337, 56442, 0, 1, 1, 1, 1),
(48337, 56443, 0, 1, 1, 1, 1),
(48337, 56444, 0, 1, 1, 1, 1),
(48337, 56440, 0, 1, 1, 1, 1),
(48337, 56441, 0, 1, 1, 1, 1);
