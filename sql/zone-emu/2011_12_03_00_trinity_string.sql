DELETE FROM `trinity_string` WHERE `entry` BETWEEN 11010 AND 11029;

INSERT INTO `trinity_string` (`entry`,`content_loc2`) VALUES
(11010,"Joueur"),
(11011,"Modérateur"),
(11012,"Mj"),
(11013,"Admin"),
(11014,"Système"),
(11015,"Serveur"),
(11016,"|cFF00FEA1Joueur|r"),
(11017,"|cFF43BC10Modérateur|r"),
(11018,"|cFF9085F9Mj|r"),
(11019,"|cFFA51488Admin|r"),
(11020,"|cFFFEC301Systeme|r"),
(11021,"|cFFFE0000Serveur|r"),
(11022,"<%s> %s est en ligne"),
(11023,"<%s> %s est hors ligne"),
(11024,"[%s] Le joueur %s a été mute par %s pour %d minutes. %s%s"),
(11025,"[%s] %s a été déconnecté du serveur par %s"),
(11026,"[%s] %s a été déconnecté du serveur par %s. %s%s"),
(11027,"[%s] %s a été banni du serveur par %s pour %s. %s%s"),
(11028,"[%s] %s a été banni a vie par %s. %s%s"),
(11029,"Raison : ");
