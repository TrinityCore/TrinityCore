DELETE FROM `command` WHERE `name` IN
("deserter instance add",
"deserter instance remove",
"deserter bg add",
"deserter bg remove");

INSERT INTO `command` (`name`, `security`, `help`) VALUES
("deserter instance add", 3, "Syntax: .deserter instance add $time \n\n Adds the instance deserter debuff to your target with $time duration."),
("deserter instance remove", 3, "Syntax: .deserter instance remove \n\n Removes the instance deserter debuff from your target."),
("deserter bg add", 3, "Syntax: .deserter bg add $time \n\n Adds the bg deserter debuff to your target with $time duration."),
("deserter bg remove", 3, "Syntax: .deserter bg remove \n\n Removes the bg deserter debuff from your target.");
