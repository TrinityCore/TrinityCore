-- Replaces MATRON with PATRON title on MALE char.
UPDATE characters SET knownTitles = CONCAT(
SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 1), ' ', -1), ' ',
SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 2), ' ', -1), ' ',
SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 3), ' ', -1), ' ',
(SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 4), ' ', -1) | 512) &~256, ' ',
SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 5), ' ', -1), ' ',
SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 6), ' ', -1))
WHERE SUBSTRING_INDEX(SUBSTRING_INDEX(knownTitles, ' ', 4), ' ', -1) & 256 AND gender = 0;
