-- Add missing fields for new titles field
UPDATE `characters` SET knownTitles = CONCAT(knownTitles, '0 0 ') WHERE (LENGTH(knownTitles) - LENGTH(REPLACE(knownTitles, ' ', ''))) = 6;
