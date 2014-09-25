DELETE FROM `creature_text` WHERE `entry`=28012;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28012,0,0,'The trickster Mage-Lord Urom protects the third ring. He will appear alone and defenseless, but do not be fooled by appearences! Urom is a powerful conjurer who commands a menagerie of Phantasmal creatures. Seek him out above.',12,0,0,0,0,0,''),
(28012,1,1,'Your greatest challenge lies ahead. Ley-Guardian Eregos is a Blue dragon of immense power. You will find him flying above the uppermost ring.',12,0,0,0,0,0,'');

UPDATE `creature_template` SET `ScriptName`='npc_image_belgaristrasz' WHERE `entry`=28012;