DELETE FROM `trinity_string` WHERE `entry` = 1190;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES (1190, 'Ticket system is disabled. You can\'t change its status.');

UPDATE `command` SET `name`='reload support', `help`='Syntax: .reload support\r\nReload support system tables.' WHERE  `name`='reload gm_tickets';

DELETE FROM `command` WHERE `name` IN ('ticket bug assign', 'ticket bug close', 'ticket bug closedlist', 'ticket bug comment', 'ticket bug delete', 'ticket bug list', 'ticket bug unassign', 'ticket bug view', 'ticket complaint assign', 'ticket complaint close', 'ticket complaint closedlist', 'ticket complaint comment', 'ticket complaint delete', 'ticket complaint list', 'ticket complaint unassign', 'ticket complaint view', 'ticket suggestion assign', 'ticket suggestion close', 'ticket suggestion closedlist', 'ticket suggestion comment', 'ticket suggestion delete', 'ticket suggestion list', 'ticket suggestion unassign', 'ticket suggestion view', 'ticket reset all', 'ticket reset gm', 'ticket reset bug', 'ticket reset complaint', 'ticket reset suggestion');
INSERT INTO `command` (`name`, `permission`, `help`) VALUES 
('ticket bug assign', 805, 'Usage: .ticket bug assign $ticketid $gmname.\r\nAssigns the specified ticket to the specified Game Master.'),
('ticket bug close', 806, 'Usage: .ticket bug close $ticketid.\r\nCloses the specified ticket. Does not delete permanently.'),
('ticket bug closedlist', 807, 'Usage: Displays a list of closed bug tickets.'),
('ticket bug comment', 808, 'Usage: .ticket bug comment $ticketid $comment.\r\nAllows the adding or modifying of a comment to the specified ticket.'),
('ticket bug delete', 809, 'Usage: .ticket bug delete $ticketid.\r\nDeletes the specified ticket permanently. Ticket must be closed first.'),
('ticket bug list', 810, 'Usage: Displays a list of open bug tickets.'),
('ticket bug unassign', 811, 'Usage: .ticket bug unassign $ticketid.\r\nUnassigns the specified ticket from the current assigned Game Master.'),
('ticket bug view', 812, 'Usage: .ticket bug view $ticketid.\r\nReturns details about specified ticket. Ticket must be open and not deleted.'),
('ticket complaint assign', 813, 'Usage: .ticket complaint assign $ticketid $gmname.\r\nAssigns the specified ticket to the specified Game Master.'),
('ticket complaint close', 814, 'Usage: .ticket complaint close $ticketid.\r\nCloses the specified ticket. Does not delete permanently.'),
('ticket complaint closedlist', 815, 'Usage: Displays a list of closed complaint tickets.'),
('ticket complaint comment', 816, 'Usage: .ticket complaint comment $ticketid $comment.\r\nAllows the adding or modifying of a comment to the specified ticket.'),
('ticket complaint delete', 817, 'Usage: .ticket complaint delete $ticketid.\r\nDeletes the specified ticket permanently. Ticket must be closed first.'),
('ticket complaint list', 818, 'Usage: Displays a list of open complaint tickets.'),
('ticket complaint unassign', 819, 'Usage: .ticket complaint unassign $ticketid.\r\nUnassigns the specified ticket from the current assigned Game Master.'),
('ticket complaint view', 820, 'Usage: .ticket complaint view $ticketid.\r\nReturns details about specified ticket. Ticket must be open and not deleted.'),
('ticket suggestion assign', 821, 'Usage: .ticket suggestion assign $ticketid $gmname.Assigns the specified ticket to the specified Game Master.'),
('ticket suggestion close', 822, 'Usage: .ticket suggestion close $ticketid.\r\nCloses the specified ticket. Does not delete permanently.'),
('ticket suggestion closedlist', 823, 'Usage: Displays a list of closed suggestion tickets.'),
('ticket suggestion comment', 824, 'Usage: .ticket suggestion comment $ticketid $comment.\r\nAllows the adding or modifying of a comment to the specified ticket.'),
('ticket suggestion delete', 825, 'Usage: .ticket suggestion delete $ticketid.\r\nDeletes the specified ticket permanently. Ticket must be closed first.'),
('ticket suggestion list', 826, 'Usage: Displays a list of open suggestion tickets.'),
('ticket suggestion unassign', 827, 'Usage: .ticket suggestion unassign $ticketid.\r\nUnassigns the specified ticket from the current assigned Game Master.'),
('ticket suggestion view', 828, 'Usage: .ticket suggestion view $ticketid.\r\nReturns details about specified ticket. Ticket must be open and not deleted.'),
('ticket reset all', 829, 'Usage: Removes all closed tickets and resets the counter, if no pending open tickets exist.'),
('ticket reset gm', 830, 'Usage: Removes all closed GM tickets and resets the counter, if no pending open tickets exist.'),
('ticket reset bug', 831, 'Usage: Removes all closed bug tickets and resets the counter, if no pending open tickets exist.'),
('ticket reset complaint', 832, 'Usage: Removes all closed complaint tickets and resets the counter, if no pending open tickets exist.'),
('ticket reset suggestion', 833, 'Usage: Removes all closed suggestion tickets and resets the counter, if no pending open tickets exist.');
