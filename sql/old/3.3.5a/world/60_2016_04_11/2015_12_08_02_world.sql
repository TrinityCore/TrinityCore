-- maexxna cleanup
DELETE FROM `creature_text` WHERE `entry`=15952;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15952,0,0,"Spiderlings appear on the web!",41,100,32305,3,"Maexxna EMOTE_SPIDERS"),
(15952,1,0,"%s spins her web into a cocoon!",41,100,32303,3,"Maexxna EMOTE_WEB_WRAP"),
(15952,2,0,"%s sprays strands of web everywhere!",41,100,32304,3,"Maexxna EMOTE_WEB_SPRAY");
