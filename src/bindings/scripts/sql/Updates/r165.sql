
-- the steam vault
UPDATE `instance_template` SET `script` = 'instance_steam_vault' WHERE `map` = 545;

-- right old hillsbrad foothills bosses script name
UPDATE `creature_template` SET `ScriptName` = 'boss_lieutenant_drake' WHERE `entry` = 17848;
UPDATE `creature_template` SET `ScriptName` = 'boss_epoch_hunter' WHERE `entry` = 18096;

