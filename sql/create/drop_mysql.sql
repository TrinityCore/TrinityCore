REVOKE ALL PRIVILEGES ON * . * FROM 'Kitron'@'localhost';

REVOKE ALL PRIVILEGES ON `world` . * FROM 'Kitron'@'localhost';

REVOKE GRANT OPTION ON `world` . * FROM 'Kitron'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'Kitron'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'Kitron'@'localhost';

REVOKE ALL PRIVILEGES ON `auth` . * FROM 'Kitron'@'localhost';

REVOKE GRANT OPTION ON `auth` . * FROM 'Kitron'@'localhost';

DROP USER 'Kitron'@'localhost';

DROP DATABASE IF EXISTS `world`;

DROP DATABASE IF EXISTS `characters`;

DROP DATABASE IF EXISTS `auth`;
