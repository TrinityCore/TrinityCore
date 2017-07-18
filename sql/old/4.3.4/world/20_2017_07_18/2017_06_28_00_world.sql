-- 
UPDATE `command` SET `name`="debug combat", `help`="Syntax: .debug combat
Lists the target's (or own) combat references." WHERE `name` IN ("debug hostil","debug combat");
UPDATE `command` SET `help`="Syntax: .debug threat
Lists the units threatened by target (or self). If target has a threat list, lists that threat list, too." WHERE `name`="debug threat";

DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_warr_vigilance_redirect_threat";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (59665,"spell_warr_vigilance_redirect_threat");
