DELETE FROM `creature_text` WHERE `entry`=32273;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32273, 0, 0, 'How dare you interfere with our work!', 14, 0, 100, 0, 0, 0, 'Infinite Corruptor - SAY_AGGRO'),
(32273, 1, 0, 'My time... has run out...', 14, 0, 100, 0, 0, 0, 'Infinite Corruptor - SAY_DEATH'),
(32273, 2, 0, 'The process is finally complete! My work here is done.', 14, 0, 100, 0, 0, 0, 'Infinite Corruptor - SAY_FAIL');
