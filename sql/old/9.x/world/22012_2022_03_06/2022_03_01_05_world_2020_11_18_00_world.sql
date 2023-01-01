-- 
DELETE FROM `command` WHERE (`name` LIKE 'learn%') OR (`name` = 'unlearn');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 383 AND 394;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(383, '### USAGE: .learn <spell> [all]
Teaches the specified spell.
If \'all\' is specified, teaches all ranks of the spell instead.'),
(384, '### USAGE: .unlearn <spell> [all]
Removes the specified spell from the target\'s spellbook.
If \'all\' is specified, removes all ranks of the spell instead.'),
(385, '### USAGE: .learn my quests
Teaches you any spells your class can obtain through class quests.'),
(386, '### USAGE: .learn my trainer
Teaches you any spells you could currently train at your class trainer.'),
(387, '### USAGE: .learn all blizzard
Teaches you all available Blizzard internal spells.'),
(388, '### USAGE: .learn all debug
Teaches you a set of spells useful for testing raid encounters.
You shouldn\'t be using GM commands during testing - they can cause weird behavior on their own!'),
(389, '### USAGE: .learn all crafts [<player>]
Teaches the specified player, or target/self, all available professions and recipes'),
(390, '### USAGE: .learn all default [<player>]
Teaches the specified player, or target/self, all default spells for their race/class, as well as any quests they have unlocked through quests.'),
(391, '### USAGE: .learn all languages
Teaches all available languages.'),
(392, '### USAGE: .learn all recipes <profession>
Teaches all recipes for the given profession.'),
(393, '### USAGE: .learn all talents
Unlocks all talents for the player\'s class.'),
(394, '### USAGE: .learn all pettalents
Unlocks all talents for the player\'s pet.');
