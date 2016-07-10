DROP TABLE IF EXISTS `ai_playerbot_custom_strategy`;

CREATE TABLE `ai_playerbot_custom_strategy` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `action_line` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_playerbot_custom_strategy`;

-- say

INSERT INTO `ai_playerbot_custom_strategy` VALUES
(NULL, 'say', 'critical health>emote::helpme|99,say::critical health|98'),
(NULL, 'say', 'low health>emote::healme|99,say::low health|98'),
(NULL, 'say', 'low mana>emote::oom|99,say::low mana|98'),
(NULL, 'say', 'tank aoe>charge|99,say::taunt|98'),
(NULL, 'say', 'medium aoe>say::aoe|99'),
(NULL, 'say', 'can loot>say::loot|99')
;
