UPDATE `creature_template` SET `ScriptName`= 'npc_barim_phoenix_summoner', `AIName`='' WHERE `entry` IN (48904, 43926);
UPDATE `creature_template` SET `speed_run`= 0.42857, `RegenHealth`= 0 WHERE `entry` IN (43934, 48954);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (48904, 43926) AND `source_type`= 0;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_barim_repentance_stun');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81947, 'spell_barim_repentance_stun');
