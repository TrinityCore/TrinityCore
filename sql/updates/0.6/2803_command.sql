DELETE FROM `command` WHERE `name` = 'setskill';

INSERT INTO command (name, security, help) VALUES ('setskill', 3,'Syntax: .setskill #skill #level [#max]\r\n\r\nSet a skill of id #skill with a current skill value of #level and a maximum value of #max (or equal current maximum if not provide) for the selected character. If no character is selected, you learn the skill.');

DELETE FROM `command` WHERE `name` = 'learnsk';

INSERT INTO command (name, security, help) VALUES ('learnskill', 3,'Syntax: .learnskill #skillId [#level [#max]]\r\n\r\nLearn a skill of id #skill with a current skill value of #level (or 1 if not provide) and a maximum value of #max (or equal #level or 1 if not provide) for the selected character. If no character is selected, you learn the skill.');

DELETE FROM `command` WHERE `name` = 'unlearnsk';

INSERT INTO command (name, security, help) VALUES ('unlearnskill',3,'Syntax: .unlearnskill #skill\r\n\r\nUnlearn a skill of id #skill for the selected character. If no character is selected, you unlearn the skill.');
