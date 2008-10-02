UPDATE `command` SET `help` = 'Syntax: .learn all_myclass\r\n\r\nLearn all spells and talents available for his class.' WHERE `name` = 'learn all_myclass';
INSERT INTO `command` ( `name` , `security` , `help` ) VALUES 
('learn all_myspells',3,'Syntax: .learn all_myspells\r\n\r\nLearn all spells (except talents and spells with first rank learned as talent) available for his class.'),
('learn all_mytalents',3,'Syntax: .learn all_mytalents\r\n\r\nLearn all talents (and spells with first rank learned as talent) available for his class.');

