REVOKE ALL PRIVILEGES ON * . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `world` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `world` . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `auth` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `auth` . * FROM 'trinity'@'localhost';

DROP USER 'trinity'@'localhost';

DROP DATABASE IF EXISTS `world`;

DROP DATABASE IF EXISTS `characters`;

DROP DATABASE IF EXISTS `auth`;
