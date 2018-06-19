DELETE FROM command WHERE name = "list quests";
INSERT INTO command VALUES ("list quests", 2003, "Syntax: .list quests
List of all active quests for targeted character.");

DELETE FROM trinity_string WHERE entry IN (11022, 11023);
INSERT INTO `trinity_string` (entry, content_default) VALUES
(11022, "Target have %u active quests"),
(11023, "QuestId %u - Status %s");
