UPDATE creature_template SET `flags_extra`=512 WHERE entry IN(33670,34109);
UPDATE `creature_template` SET `AIName`='PassiveAI' WHERE `entry`=34071;
UPDATE `creature_template` SET `unit_flags`=33555200, `ScriptName`='npc_mimiron_magnetic_core' WHERE `entry`=34068;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mimiron_magnetic_core_summon';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64444,'spell_mimiron_magnetic_core_summon');
