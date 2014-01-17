UPDATE `gameobject` SET `state`=1 WHERE `guid` IN (56162,56163); -- correct?
DELETE FROM `linked_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
