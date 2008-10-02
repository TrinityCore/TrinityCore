DELETE FROM `command` WHERE `name`='learn';
INSERT INTO `command` VALUES 
('learn',3,'Syntax: .learn #parameter\r\n\r\nSelected character learn a spell of id #parameter.'),
('learn all',3,'Syntax: .learn all\r\n\r\nLearn all big set different spell maybe useful for Administaror.'),
('learn all_crafts',2,'Syntax: .learn crafts\r\n\r\nLearn all professions and recipes.'),
('learn all_gm',2,'Syntax: .learn all_gm\r\n\r\nLearn all default spells for Game Masters.'),
('learn all_lang',1,'Syntax: .learn all_lang\r\n\r\nLearn all languages'),
('learn all_myclass',3,'Syntax: .learn all_myclass\r\n\r\nLearn all spells available for his class.');
