-- warden settings
DELETE FROM `warden_action` WHERE `wardenID` IN (786, 209);
INSERT INTO `warden_action` (`wardenId`, `action`) VALUES ('786', '2');
INSERT INTO `warden_action` (`wardenId`, `action`) VALUES ('209', '2');

-- make "name" column in characters caseinsensitive
ALTER TABLE characters CHANGE name name VARCHAR(12);
