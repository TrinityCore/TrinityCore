UPDATE `gameobject_template` SET `ScriptName`='go_altar_of_the_keepers' WHERE `entry`=130511;
UPDATE `gameobject_template` SET `ScriptName`='go_altar_of_archaedas' WHERE `entry`=133234;

UPDATE `instance_template` SET `script`='instance_uldaman' WHERE `map`=70;

-- Archaedas
UPDATE `creature_template` SET `ScriptName`='boss_archaedas' WHERE `entry`=2748;

-- Archaedas' minions
UPDATE `creature_template` SET `ScriptName`='mob_archaedas_minions' WHERE `entry` IN ('7309', '7077', '7076', '10120');

-- Stone keepers
UPDATE `creature_template` SET `ScriptName`='mob_stonekeepers' WHERE `entry`=4857;

