DELETE FROM `command` WHERE `name` = "honor flushkills";

DELETE FROM `command` WHERE `name` = "honor";
INSERT INTO `command` VALUES
("honor", 2, "Syntax: .honor $command [$value] Various honor related commands. Use .help honor $command to get help on specific parameter usage. Supported parameters include add, addkill, update");