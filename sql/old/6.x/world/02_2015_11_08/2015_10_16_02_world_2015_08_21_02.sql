DELETE FROM `spell_script_names` WHERE `spell_id` = 35941 AND `ScriptName` = 'spell_kael_gravity_lapse';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (35941, 'spell_kael_gravity_lapse');

UPDATE `gameobject_template` SET `flags` = `flags`|33 WHERE `entry` = 184069;

UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `guid` IN (12567, 12568, 12569, 12570);

DELETE FROM `creature_text` WHERE `entry` = 19622 AND `groupid` = 14;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19622, 14, 0, '%s begins to cast Pyroblast!', 41, 0, 100, 0, 0, 0, 20775, 0, 'kaelthas EMOTE_PYROBLAST');
