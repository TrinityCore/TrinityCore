REVOKE ALL PRIVILEGES ON * . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `world_434` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `world_434` . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `characters_434` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `characters_434` . * FROM 'trinity'@'localhost';

REVOKE ALL PRIVILEGES ON `auth_434` . * FROM 'trinity'@'localhost';

REVOKE GRANT OPTION ON `auth_434` . * FROM 'trinity'@'localhost';

DROP USER 'trinity'@'localhost';

DROP DATABASE IF EXISTS `world_434`;

DROP DATABASE IF EXISTS `characters_434`;

DROP DATABASE IF EXISTS `auth_434`;
