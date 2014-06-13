/* add rbac permissions to new commands */
DELETE FROM `rbac_permissions` WHERE `id` IN (1002,1003,1004,1005,1006,1007,1008,1009,1010, 1011);
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(1002,'Command: qc'),
(1003,'Command: qc status'),
(1004,'Command: qc add'),
(1005,'Command: qc del'),
(1006,'Command: online'),
(1007,'Command: online account'),
(1008,'Command: online character'),
(1009,'Command: instance setdata'),
(1010,'Command: instance getdata'),
(1011,'Command: qc complete');
 
/* adds qc to players */
DELETE FROM `rbac_linked_permissions` WHERE `id` IN (1002,1003,1004,1005,1006,1007,1008,1009,1010,1011);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(195, 1002),
/* adds qc status to players */
(195, 1003), 
/* adds qc add to GMs */
(193, 1004),
/* adds qc del to GMs */
(193, 1005),
/* adds online to mods+ */
(195, 1006), 
/* adds online account to mods+ */
(194, 1007), 
/* adds online character to mods+ */
(194, 1008), 
/* adds instance setdata to GMs */
(193, 1009), 
/* adds instance getdata to GMs */
(193, 1010),
/* adds qc complete to players */
(195, 1011);
