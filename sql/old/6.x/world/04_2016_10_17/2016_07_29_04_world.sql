-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28563;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28563, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Fathom Eel Swarm contains Loot item Tome of Polymorph: Turtle'),
(28563, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Fathom Eel Swarm contains Loot item Sea Turtle'),
(28563, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Fathom Eel Swarm contains Loot item Volatile Water'),
(28563, 53070, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Fathom Eel Swarm contains Loot item Fathom Eel');
