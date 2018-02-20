UPDATE `creature_template` SET `ScriptName`='boss_hogger' WHERE `entry`=46254;
DELETE from `creature_text` WHERE `entry`=46254;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46254, 0, 0, 'Forest just setback!', 14, 0, 100, 0, 0, 0, 46474, 3, 'Hogger - Stockades - SAY_PULL'),
(46254, 1, 0, '%s Enrages!', 41, 0, 100, 0, 0, 0, 46631, 3, 'Hogger - Stockades - SAY_ENRAGE'),
(46254, 2, 0, 'Yiiipe!', 14, 0, 100, 0, 0, 0, 46476, 3, 'Hogger - Stockades - SAY_DEATH');

UPDATE `creature_template` Set `ScriptName`='npc_warden_thelwater' WHERE `entry`=46409;
DELETE FROM `creature_text` WHERE `entry`=46409;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46409, 0, 0, 'This ends here, Hogger!', 14, 0, 100, 0, 0, 0, 46571, 3, 'Hogger - Stockades - Warden - EVENT_SAY_WARDEN_1'),
(46409, 1, 0, 'He\'s...he\'s dead?', 12, 0, 100, 0, 0, 0, 46572, 3, 'Hogger - Stockades - Warden - EVENT_SAY_WARDEN_2'),
(46409, 2, 0, 'It\'s simply too good to be true. You couldn\'t have killed him so easily!', 12, 0, 100, 0, 0, 0, 46573, 3, 'Hogger - Stockades - Warden - EVENT_SAY_WARDEN_3');

UPDATE `creature_template` set `ScriptName`='boss_randolph_moloch' WHERE `entry`=46383;
DELETE FROM `creature_text` WHERE `entry`=46383;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46383, 0, 0, 'Allow me to introduce myself. I am Randolph Moloch, and I will be killing you all today.', 14, 0, 100, 0, 0, 0, 46495, 3, 'Randolph Moloch - Stockades - SAY_PULL'),
(46383, 1, 0, '%s vanishes!', 41, 0, 100, 0, 0, 0, 46630, 3, 'Randolph Moloch - Stockades - SAY_VANISH'),
(46383, 2, 0, 'My epic schemes, my great plans! Gone!', 14, 0, 100, 0, 0, 0, 46497, 3, 'Randolph Moloch - Stockades - SAY_DEATH');

UPDATE `creature_template` set `ScriptName`='npc_mortimer_moloch' WHERE `entry`=46482;
DELETE FROM `creature_text` WHERE `entry`=46482;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46482, 0, 0, '%s collapses from a heart attack!', 16, 0, 100, 0, 0, 0, 46561, 3, 'MORTIMER MOLOCH - Stockades - MORTIMER_MOLOCH_DEATH'),
(46482, 1, 0, 'Egad! My sophisticated heart!', 14, 0, 100, 0, 0, 0, 46559, 3, 'MORTIMER MOLOCH - Stockades - MORTIMER_MOLOCH_EMOTE');

UPDATE `creature_template` set `ScriptName`='boss_lord_overheat' WHERE `entry`=46264;
DELETE FROM `creature_text` WHERE `entry`=46264;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46264, 0, 0, 'ALL MUST BURN!', 14, 0, 100, 0, 0, 0, 46487, 3, 'TheStockade: Lord Overheat - SAY_PULL'),
(46264, 1, 0, 'FIRE... EXTINGUISHED!', 14, 0, 100, 0, 0, 0, 46489, 3, 'TheStockade: Lord Overheat - SAY_DEATH');
