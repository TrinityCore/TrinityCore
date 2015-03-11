ALTER TABLE pool_template ADD COLUMN min_limit int(10) unsigned NOT NULL DEFAULT 0 AFTER entry;
DELETE FROM trinity_string WHERE entry=20078;
INSERT INTO trinity_string VALUES (20078, 'Pool ID: %u. Template: Minimum: %u, Maximum: %u. Current alive in pool: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
