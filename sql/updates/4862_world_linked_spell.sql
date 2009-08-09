DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (19574,34471);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) 
VALUES
( 19574, 24395, 2, 'Beast Within'),
( 19574, 24396, 2, 'Beast Within'),
( 19574, 24397, 2, 'Beast Within'),
( 19574, 26592, 2, 'Beast Within'),
( 34471, 24395, 2, 'Beast Within'),
( 34471, 24396, 2, 'Beast Within'),
( 34471, 24397, 2, 'Beast Within'),
( 34471, 26592, 2, 'Beast Within');