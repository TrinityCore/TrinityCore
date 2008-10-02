REVOKE ALL PRIVILEGES ON * . * FROM 'mangos'@'localhost';

REVOKE ALL PRIVILEGES ON `mangos` . * FROM 'mangos'@'localhost';

REVOKE GRANT OPTION ON `mangos` . * FROM 'mangos'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'mangos'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'mangos'@'localhost';

REVOKE ALL PRIVILEGES ON `realmd` . * FROM 'mangos'@'localhost';

REVOKE GRANT OPTION ON `realmd` . * FROM 'mangos'@'localhost';

DELETE FROM `user` WHERE CONVERT( User USING utf8 ) = CONVERT( 'mangos' USING utf8 ) AND CONVERT( Host USING utf8 ) = CONVERT( 'localhost' USING utf8 ) ;

DROP DATABASE IF EXISTS `mangos` ;

DROP DATABASE IF EXISTS `characters` ;

DROP DATABASE IF EXISTS `realmd` ;
