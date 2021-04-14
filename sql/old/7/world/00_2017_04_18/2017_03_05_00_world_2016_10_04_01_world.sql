--
DELETE FROM `pool_template` WHERE `entry` BETWEEN 5707 AND 5710;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(5707, 1, "Wintergrasp weekly quests (Alliance, attackers)"),
(5708, 1, "Wintergrasp weekly quests (Alliance, defenders)"),
(5709, 1, "Wintergrasp weekly quests (Horde, attackers)"),
(5710, 1, "Wintergrasp weekly quests (Horde, defenders)");

DELETE FROM `pool_quest` WHERE `pool_entry` BETWEEN 5707 AND 5710;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(13195, 5707, "A Rare Herb (Alliance, attackers)"),
(13196, 5707, "Bones and Arrows (Alliance, attackers)"),
(13197, 5707, "Fueling the Demolishers (Alliance, attackers)"),
(13198, 5707, "Warding the Warriors (Alliance, attackers)"),

(13156, 5708, "A Rare Herb (Alliance, defenders)"),
(13154, 5708, "Bones and Arrows (Alliance, defenders)"),
(236, 5708, "Fueling the Demolishers (Alliance, defenders)"),
(13153, 5708, "Warding the Warriors (Alliance, defenders)"),

(13201, 5709, "A Rare Herb (Horde, attackers)"),
(13199, 5709, "Bones and Arrows (Horde, attackers)"),
(13200, 5709, "Fueling the Demolishers (Horde, attackers)"),
(13202, 5709, "Jinxing the Walls (Horde, attackers)"),

(13194, 5710, "Healing with Roses (Horde, defenders)"),
(13193, 5710, "Bones and Arrows (Horde, defenders)"),
(13191, 5710, "Fueling the Demolishers (Horde, defenders)"),
(13192, 5710, "Warding the Walls (Horde, defenders)");
