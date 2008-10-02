

DELETE FROM command WHERE name IN ('lookupitem','lookupitemset','lookupcreature','lookupobject','lookupquest','lookupskill','lookupspell','lookuptele');


INSERT INTO `command` VALUES 
 ('lookup creature',3,'Syntax: .lookup creature $namepart\r\n\r\nLooks up a creature by $namepart, and returns all matches with their creature ID\'s.'),
 ('lookup item',3,'Syntax: .lookup item $itemname\r\n\r\nLooks up an item by $itemname, and returns all matches with their Item ID\'s.'),
 ('lookup itemset',3,'Syntax: .lookup itemset $itemname\r\n\r\nLooks up an item set by $itemname, and returns all matches with their Item set ID\'s.'),
 ('lookup object',3,'Syntax: .lookup object $objname\r\n\r\nLooks up an gameobject by $objname, and returns all matches with their Gameobject ID\'s.'),
 ('lookup quest',3,'Syntax: .lookup quest $namepart\r\n\r\nLooks up a quest by $namepart, and returns all matches with their quest ID\'s.'),
 ('lookup skill',3,'Syntax: .lookup skill $$namepart\r\n\r\nLooks up a skill by $namepart, and returns all matches with their skill ID\'s.'),
 ('lookup spell',3,'Syntax: .lookup spell $namepart\r\n\r\nLooks up a spell by $namepart, and returns all matches with their spell ID\'s.'),
 ('lookup tele',1,'Syntax: .lookup tele $substring\r\n\r\nSearch and output all .tele command locations with provide $substring in name.');

