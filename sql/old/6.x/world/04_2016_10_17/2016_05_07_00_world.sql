RENAME TABLE `achievement_criteria_data` TO `criteria_data`;
UPDATE `command` SET `name`='disable add criteria', `help`='Syntax: .disable add criteria $entry $flag $comment' WHERE `name`='disable add achievement_criteria';
UPDATE `command` SET `name`='disable remove criteria', `help`='Syntax: .disable remove criteria $entry' WHERE `name`='disable remove achievement_criteria';
UPDATE `command` SET `name`='reload criteria_data', `help`='Syntax: .reload criteria_data\nReload criteria_data table.' WHERE `name`='reload achievement_criteria_data';
