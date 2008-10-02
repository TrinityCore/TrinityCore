-- Fishing net
UPDATE item_template SET ScriptName = 'draenei_fishing_net' WHERE entry = 23654;

-- Auchenai Crypts
UPDATE `creature_template` set `scriptname` = 'boss_shirrak_the_dead_watcher' where `entry` = '18371';
UPDATE `creature_template` set `scriptname` = 'boss_shirrak_the_dead_watcher' where `entry` = '20318';

-- Old Hillsbrad
UPDATE `creature_template` set `scriptname` = 'mob_lieutenant_drake' where `entry` = '17848';
UPDATE `creature_template` set `scriptname` = 'mob_epoch_hunter' where `entry` = '18096';
UPDATE `creature_template` SET `ScriptName` = 'boss_captain_skarloc' WHERE `entry`=17862;

-- The Black Morass
UPDATE `creature_template` set `ScriptName` = 'boss_chrono_lord_deja' where `entry` = '17879';
UPDATE `creature_template` SET `ScriptName` = 'boss_aeonus' WHERE `entry`=17881;
UPDATE `creature_template` set `ScriptName` = 'boss_temporus' where `entry` = '17880';

-- Deadmines
UPDATE `creature_template` SET `ScriptName` = 'boss_deadmines' WHERE `entry`=645;
UPDATE `creature_template` SET `ScriptName` = 'boss_deadmines' WHERE `entry`=1763;
UPDATE `creature_template` SET `ScriptName` = 'boss_deadmines' WHERE `entry`=599;
UPDATE `creature_template` SET `ScriptName` = 'boss_deadmines' WHERE `entry`=3586;

-- Wailing Caverns
UPDATE `creature_template` SET `ScriptName` = 'boss_wailing_caverns' WHERE `entry`=3654;

-- Gruul's Lair
UPDATE `creature_template` SET `ScriptName` = 'boss_high_king_maulgar' WHERE `entry`=18831;
UPDATE `creature_template` SET `ScriptName` = 'boss_kiggler_the_crazed' WHERE `entry`=18835;
UPDATE `creature_template` SET `ScriptName` = 'boss_blindeye_the_seer' WHERE `entry`=18836;
UPDATE `creature_template` SET `ScriptName` = 'boss_olm_the_summoner' WHERE `entry`=18834;
UPDATE `creature_template` SET `ScriptName` = 'boss_krosh_firehand' WHERE `entry`=18832;
UPDATE `instance_template` SET `script`="instance_gruuls_lair" WHERE `map`=565;