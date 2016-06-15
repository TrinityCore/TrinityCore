DROP TABLE IF EXISTS `ai_playerbot_custom_strategy`;

CREATE TABLE `ai_playerbot_custom_strategy` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `action_line` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- say

INSERT INTO `ai_playerbot_custom_strategy` VALUES
(NULL, 'say', 'critical health>say::critical health|99'),
(NULL, 'say', 'low health>say::low health|99'),
(NULL, 'say', 'low mana>say::low mana|99'),
(NULL, 'say', 'tank aoe>say::taunt|99'),
(NULL, 'say', 'medium aoe>say::aoe|99'),
(NULL, 'say', 'can loot>say::loot|99');