-- Arcane Fiend & Amani Bear Mount are summoned
DELETE FROM `creature` WHERE `id` = 18429 AND `guid` IN (91245,91246);
DELETE FROM `creature` WHERE `id` = 24217 AND `guid` IN (89266,89267,89272,89275);
DELETE FROM `linked_respawn` WHERE `guid` IN (91245,91246,89266,89267,89272,89275);
