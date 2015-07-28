UPDATE `command` SET
    `help` = 'Syntax: .server idlerestart #delay [#exit_code] [reason]\n\nRestart the server after #delay seconds if no active connections are present (no players). Use #exit_code or 2 as program exit code.'
WHERE
    `name` = 'server idlerestart';
    
UPDATE `command` SET
    `help` = 'Syntax: .server idleshutdown #delay [#exit_code] [reason]\n\nShut the server down after #delay seconds if no active connections are present (no players). Use #exit_code or 0 as program exist code.'
WHERE
    `name` = 'server idleshutdown';

UPDATE `command` SET
    `help` = 'Syntax: .server restart #delay [#exit_code] [reason]\n\nRestart the server after #delay seconds. Use #exit_code or 2 as program exist code.'
WHERE
    `name` = 'server restart';

UPDATE `command` SET
    `help` = 'Syntax: .server shutdown #delay [#exit_code] [reason]\n\nShut the server down after #delay seconds. Use #exit_code or 0 as program exit code.'
WHERE
    `name` = 'server shutdown';
