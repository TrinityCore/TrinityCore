-- 
DELETE FROM `command` WHERE `name`='pdump copy';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('pdump copy',880,'Syntax: .pdump copy $playerNameOrGUID $account [$newname] [$newguid]
Copy character with name/guid $playerNameOrGUID into character list of $account with $newname, with first free or $newguid guid.');
