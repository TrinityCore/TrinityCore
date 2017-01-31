DELETE FROM `trinity_string` WHERE `entry` IN (290,296,289);
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 2000 AND 2016;
INSERT INTO trinity_string (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(2000, '|cff00ff00New ticket from|r|cffff00ff %s.|r |cff00ff00Ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2001, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00edited his/her ticket:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2002, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00abandoned ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2003, '|cffff00ff %s|r |cff00ff00closed ticket|r |cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2004, 'Ticket %d permanently deleted by %s.', '', '', '', '', '', '', '', ''),
(2005, 'Ticket not found.', '', '', '', '', '', '', '', ''),
(2007, 'Please close ticket before deleting it permanently.', '', '', '', '', '', '', '', ''),
(2008, 'Ticket %d is already assigned to GM %s.', '', '', '', '', '', '', '', ''),
(2009, '%u Tickets succesfully reloaded from the database.', '', '', '', '', '', '', '', ''),
(2010, 'Showing list of open tickets.', '', '', '', '', '', '', '', ''),
(2011, 'Showing list of open tickets whose creator is online.', '', '', '', '', '', '', '', ''),
(2012, 'Invalid name specified. Name should be that of an online Gamemaster.', '', '', '', '', '', '', '', ''),
(2013, 'This ticket is already assigned to yourself. To unassign use .ticket unassign %d and then reassign.', '', '', '', '', '', '', '', ''),
(2014, 'Ticket %d is not assigned, you cannot unassign it.', '', '', '', '', '', '', '', ''),
(2015, 'You cannot unassign tickets from staffmembers with a higher security level than yourself.', '', '', '', '', '', '', '', ''),
(2016, 'Cannot close ticket %d, it is assigned to another GM.', '', '', '', '', '', '', '', '');
DELETE FROM `command` WHERE (`name` LIKE '%ticket%');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('ticket list','1','Displays a list of open GM tickets.'),
('ticket onlinelist','1','Displays a list of open GM tickets whose owner is online.'),
('ticket viewname','1','Usage: .ticket viewname $creatorname. \r\nReturns details about specified ticket. Ticket must be open and not deleted.'),
('ticket viewid','1','Usage: .ticket viewid $ticketid.\r\nReturns details about specified ticket. Ticket must be open and not deleted.'),
('ticket close','2','Usage: .ticket close $ticketid.\r\nCloses the specified ticket. Does not delete permanently.'),
('ticket delete','3','Usage: .ticket delete $ticketid.\r\nDeletes the specified ticket permanently. Ticket must be closed first.'),
('ticket assign','3','Usage: .ticket assign $ticketid $gmname.\r\nAssigns the specified ticket to the specified Game Master.'),
('ticket unassign','3','Usage: .ticket unassign $ticketid.\r\nUnassigns the specified ticket from the current assigned Game Master.'),
('ticket comment','2','Usage: .ticket comment $ticketid $comment.\r\nAllows the adding or modifying of a comment to the specified ticket.'),
('reload tickets','4','Usage: .reload tickets.\r\nReloads GM Tickets from the database and re-caches them into memory.');
