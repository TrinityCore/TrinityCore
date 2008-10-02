insert into command values('maxskill','3','Usage: .maxskill\r\nSets all skills of the targeted player to their maximum values for its current level.');
UPDATE `command` SET `help` = 'Usage:\r\n.reset stats\r\n  Resets all stats of the targeted player to their original values at level 1.\r\n  Please unequip all items and debuff all auras from the player before using.\r\n.reset talents\r\n  Removes all talents of the targeted player.' WHERE `name` = 'reset';

