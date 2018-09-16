-- Template Updates
-- Bloodlord Mandokir
UPDATE `creature_template` SET `ScriptName`= 'boss_bloodlord_mandokir' WHERE `ScriptName`= 'boss_mandokir';
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839, `mingold`= 20000, `maxgold`= 21000, `lootid`= 52151 WHERE `entry`= 52151;
-- Ohgan
UPDATE `creature_template` SET `ScriptName`= 'npc_mandokir_ohgan' WHERE `ScriptName`= 'npc_ohgan';
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839 WHERE `entry`= 52157;
-- Chained Spirit
UPDATE `creature_template` SET `ScriptName`= 'npc_mandokir_chained_spirit' WHERE `ScriptName`= 'npc_chained_spirit';

-- Template Addons
UPDATE `creature_template_addon` SET `mount`= 34408 WHERE `entry`= 52151;

-- Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 52151;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(52151, 395, 7000);

DELETE FROM `creature_loot_template` WHERE `Entry`= 52151;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(52151, 521510, 100, 1, 521510, 1);

DELETE FROM `reference_loot_template` WHERE `Entry`= 521510;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(521510, 69609, 0, 1, 1, 1, 1),
(521510, 69607, 0, 1, 1, 1, 1),
(521510, 69605, 0, 1, 1, 1, 1),
(521510, 69606, 0, 1, 1, 1, 1),
(521510, 69608, 0, 1, 1, 1, 1);
