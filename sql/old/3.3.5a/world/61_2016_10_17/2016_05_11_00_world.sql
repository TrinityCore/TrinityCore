--
DELETE FROM `command` WHERE `name` IN ('server shutdown force','server restart force');
INSERT INTO `command` (`name`,`permission`) VALUES ('server shutdown force', 839),('server restart force', 840);
UPDATE `command` SET `help`="Syntax: .server shutdown [force] #delay [#exit_code] [reason]

Shut the server down after #delay seconds. Use #exit_code or 0 as program exit code. Specify 'force' to allow short-term shutdown despite other players being connected." WHERE `name` IN ('server shutdown','server shutdown force');
UPDATE `command` SET `help`="Syntax: .server restart [force] #delay [#exit_code] [reason]

Restart the server after #delay seconds. Use #exit_code or 2 as program exit code. Specify 'force' to allow short-term shutdown despite other players being connected." WHERE `name` IN ('server restart','server restart force');


DELETE FROM `command` WHERE `permission` IN (571,575);
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
("npc add", 571, "Syntax: .npc add #entry
  Spawn a creature using template #entry and save it to the database.
  If you want a temporary spawn that is not saved to the database, use .npc add temp instead."),
("npc add temp", 575, "Syntax: .npc add temp [loot/noloot] #entry
Adds temporary NPC, not saved to database.
  Specify 'loot' to have the NPC's corpse stick around for some time after death, allowing it to be looted.
  Specify 'noloot' to have the corpse disappear immediately.");

DELETE FROM `command` WHERE `permission`=837;
INSERT INTO `command` (`name`,`permission`,`help`) VALUES ("npc evade",837,"Syntax: .npc evade [reason] [force]
Makes the targeted NPC enter evade mode.\nDefaults to specifying EVADE_REASON_OTHER, override this by providing the reason string (ex.: .npc evade EVADE_REASON_BOUNDARY).\nSpecify 'force' to clear any pre-existing evade state before evading - this may cause weirdness, use at your own risk.");

DELETE FROM `command` WHERE `permission`=838;
INSERT INTO `command` (`name`,`permission`,`help`) VALUES ("pet level",838,"Syntax: .pet level #dLevel
Increases/decreases the pet's level by #dLevel. Pet's level cannot exceed the owner's level.");

DELETE FROM `trinity_string` WHERE `entry` IN (11015,11016);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(11015,"This creature does not have an active CreatureAI assigned to it."),
(11016,"Select a player or player pet.");
