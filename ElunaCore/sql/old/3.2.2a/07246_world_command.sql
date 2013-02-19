-- delete unused command loadscripts
DELETE FROM `command` WHERE `name` = 'loadscripts';
-- Change the default scurity level for some commands
UPDATE `command` SET `security`=2 WHERE `name` IN ('playall','npc setlink','reload creature_linked_respawn'); -- DB devs command
UPDATE `command` SET `security`=1 WHERE `name` IN ('freeze','listfreeze','unfreeze'); -- Players can be anoying when talking a mod
UPDATE `command` SET `security`=1 WHERE `name` IN ('gmannounce','gmnameannounce','gmnotify'); -- even mods needs to notify things when a higher range staft is not online
UPDATE `command` SET `security`=1 WHERE `name` IN ('ticket assign','ticket close','ticket comment','ticket unassign'); -- Dirty work for slaves
UPDATE `command` SET `security`=1 WHERE `name`='account addon'; -- Server admins uses addon to close northrend
