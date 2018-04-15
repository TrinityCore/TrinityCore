UPDATE `creature_template` SET `ScriptName`='npc_aeranas' WHERE `entry`=17085;
UPDATE `gameobject_template` SET `ScriptName`='go_haaleshi_altar' WHERE `entry`=181606;

DELETE FROM `script_texts` WHERE `entry` IN (-1000138,-1000139);
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1000138, 'Avruu\'s magic... it still controls me. You must fight me, mortal. It\'s the only way to break the spell!', 0, 0, 0, 'aeranas SAY_SUMMON'),
(-1000139, 'Avruu\'s magic is broken! I\'m free once again!', 0, 0, 0, 'aeranas SAY_FREE');
