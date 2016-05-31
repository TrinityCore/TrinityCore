UPDATE `creature_template` SET `unit_flags`=33685504, `rangeattacktime`=2000, `spell1`=0 WHERE `entry` IN (16363,29379);

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=14, `faction_H`=14, `unit_flags`=33947648, `baseattacktime`=2000, `rangeattacktime`=2000, `spell1`=0, `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (17662,18602);
UPDATE `creature_template` SET `ScriptName`='npc_broggok_poison_cloud' WHERE `entry`=17662;

DELETE FROM `spelldifficulty_dbc` WHERE `spellid0` IN (28157,28158,30913,30917,30914);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(28157,28157,54364,0,0),
(28158,28158,54362,0,0),
(30913,30913,38458,0,0),
(30917,30917,38459,0,0),
(30914,30914,38462,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (28169,28158,54362,30914,38462);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28169,'spell_grobbulus_mutating_injection'),
(28158,'spell_grobbulus_poison_cloud'),
(54362,'spell_grobbulus_poison_cloud'),
(30914,'spell_broggok_poison_cloud'),
(38462,'spell_broggok_poison_cloud');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-28169;
