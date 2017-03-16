-- Randolph Moloch
UPDATE `creature_template` set `ScriptName` = 'boss_randolph_moloch' WHERE `entry` = 46383;
DELETE FROM `creature_text` WHERE entry = 46383;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46383, 0, 0, 'Allow me to introduce myself. I am Randolph Moloch and I will be killing you all today.', 14, 0, 100, 0, 0, 0, 0, 3, 'Randolph Moloch - Stockades - SAY_PULL'),
(46383, 1, 0, '%s vanishes!', 41, 0, 100, 0, 0, 0, 0, 3, 'Randolph Moloch - Stockades - SAY_VANISH'),
(46383, 2, 0, 'My epic schemes, my great plans! Gone!', 14, 0, 100, 0, 0, 0, 0, 3, 'Randolph Moloch - Stockades - SAY_DEATH');

-- Mortimer Moloch
UPDATE `creature_template` set `ScriptName` = 'npc_mortimer_moloch' WHERE `entry` = 46482;
DELETE FROM `creature_text` WHERE entry = 46482;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46482, 0, 0, '%s collapses from a heart attack!', 16, 0, 100, 0, 0, 0, 0, 3, 'MORTIMER MOLOCH - Stockades - MORTIMER_MOLOCH_EMOTE'),
(46482, 1, 0, 'Egad! My sophisticated heart!', 14, 0, 100, 0, 0, 0, 0, 3, 'MORTIMER MOLOCH - Stockades - MORTIMER_MOLOCH_EMOTE');
