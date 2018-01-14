UPDATE `creature_template` SET `flags_extra` = 128 WHERE (entry = 100404);
DELETE FROM creature WHERE id IN (100403, 107638);

DELETE FROM areatrigger WHERE guid = 45;
INSERT INTO areatrigger VALUES
(45, 100009, 1466, 8388870, 2929.62, 1967.83, 189.70, "at_archdruid_glaidalis_event");
