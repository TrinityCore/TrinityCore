DELETE FROM trinity_string WHERE entry IN (1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026);
INSERT INTO trinity_string VALUES
(1016, '| GUID       | Name                 | Account                      | Delete Date         |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1017, '| %10u | %20s | %15s (%10u) | %19s |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1018, '==========================================================================================', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1019, 'No characters found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1020, 'Restoring the following characters:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1021, 'Deleting the following characters:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1022, 'ERROR: You can only assign a new name if you have only selected a single character!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1023, 'Character ''%s'' (GUID: %u Account %u) can''t be restored: account not exist!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1024, 'Character ''%s'' (GUID: %u Account %u) can''t be restored: account character list full!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1025, 'Character ''%s'' (GUID: %u Account %u) can''t be restored: new name already used!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1026, 'GUID: %u Name: %s Account: %s (%u) Date: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
