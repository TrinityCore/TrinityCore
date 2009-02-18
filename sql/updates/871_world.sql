DELETE FROM `trinity_string` WHERE `entry` BETWEEN '288' AND '295';
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '2000' AND '2029';
INSERT INTO trinity_string (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES 
(2000, '|cff00ff00New ticket from|r|cffff00ff %s.|r |cff00ff00Ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2001, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00edited his/her ticket:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2002, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00abandoned ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2003, '|cff00ff00Closed by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2004, '|cff00ff00Deleted by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2005, 'Ticket not found.', '', '', '', '', '', '', '', ''),
(2006, 'Please close ticket before deleting it permanently.', '', '', '', '', '', '', '', ''),
(2007, 'Ticket %d is already assigned.', '', '', '', '', '', '', '', ''),
(2008, '%u Tickets succesfully reloaded from the database.', '', '', '', '', '', '', '', ''),
(2009, 'Showing list of open tickets.', '', '', '', '', '', '', '', ''),
(2010, 'Showing list of open tickets whose creator is online.', '', '', '', '', '', '', '', ''),
(2011, 'Showing list of closed tickets.', '', '', '', '', '', '', '', ''),
(2012, 'Invalid name specified. Name should be that of an online Gamemaster.', '', '', '', '', '', '', '', ''),
(2013, 'This ticket is already assigned to yourself. To unassign use .ticket unassign %d and then reassign.', '', '', '', '', '', '', '', ''),
(2014, 'Ticket %d is not assigned, you cannot unassign it.', '', '', '', '', '', '', '', ''),
(2015, 'You cannot unassign tickets from staffmembers with a higher security level than yourself.', '', '', '', '', '', '', '', ''),
(2016, 'Cannot close ticket %d, it is assigned to another GM.', '', '', '', '', '', '', '', ''),
(2017, '|cff00ff00Ticket|r:|cff00ccff %d.|r ', '', '', '', '', '', '', '', ''),
(2018, '|cff00ff00Created by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2019, '|cff00ff00Last change|r:|cff00ccff %s ago|r ', '', '', '', '', '', '', '', ''),
(2020, '|cff00ff00Assigned to|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2021, '|cff00ff00Unassigned by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2022, '\n|cff00ff00Message|r: \"%s\"|r ', '', '', '', '', '', '', '', ''),
(2023, '\n|cff00ff00Comment|r: \"%s\"|r ', '', '', '', '', '', '', '', ''),
(2024, '\n|cff00ccff%s|r |cff00ff00Added comment|r: \"%s\"|r ', '', '', '', '', '', '', '', '');

DELETE FROM `command` WHERE (`name` LIKE '%ticket closedlist%');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('.ticket closedlist','1','Displays a list of closed GM tickets.');

