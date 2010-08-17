DELETE FROM `command` WHERE `name` IN ('summon', 'appear', 'groupsummon');
UPDATE `command` SET `name`='summon' WHERE `name`='namego';
UPDATE `command` SET `name`='appear' WHERE `name`='goname';
UPDATE `command` SET `name`='groupsummon' WHERE `name`='groupgo';
