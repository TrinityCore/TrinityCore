DELETE FROM `trinity_string` WHERE `entry` IN (2000, 2001, 2002, 2008, 2010, 2019, 2026, 2029, 2030);

DELETE FROM `command` WHERE `name` IN (
'go ticket',
'ticket assign',
'ticket close',
'ticket closedlist',
'ticket comment',
'ticket delete',
'ticket escalate',
'ticket escalatedlist',
'ticket list',
'ticket onlinelist',
'ticket reset gm',
'ticket response',
'ticket response append',
'ticket response appendln',
'ticket unassign',
'ticket viewid',
'ticket viewname'
);
