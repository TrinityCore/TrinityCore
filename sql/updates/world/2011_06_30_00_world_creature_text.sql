DELETE FROM `script_texts` WHERE `npc_entry`=14507;
INSERT INTO `creature_text` (`entry`,`groupid`,`text`,`type`,`sound`,`comment`) VALUES
(14507,1,'Let the coils of hate unfurl!',14,8421,'venoxis SAY_VENOXIS_TRANSFORM'),
(14507,2,'Ssserenity..at lassst!',14,0,'venoxis SAY_VENOXIS_DEATH');
